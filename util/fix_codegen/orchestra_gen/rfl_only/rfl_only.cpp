// reflect-cpp only: an Orchestra file read with rfl::xml::load<T>, the way reflect-cpp's docs show it
// (docs/content/supported_formats/xml.md:244-252). There is no pugixml walk, no prefix stripping and
// no logic of ours. reflect-cpp needs a C++ struct for each element, so the structs below are written
// by hand. Element names are given with their "fixr:" prefix, because reflect-cpp matches node names
// literally (include/rfl/xml/Reader.hpp:172). Output: rfl::json::write of the whole bound Repository,
// so the file this writes is exactly what reflect-cpp produced.
//
//   rfl_only ORCHESTRA.xml OUT.json
#include <rfl.hpp>
#include <rfl/json.hpp>
#include <rfl/xml.hpp>

#include <cstdio>
#include <fstream>
#include <optional>
#include <string>
#include <vector>

template <rfl::internal::StringLiteral N, class T> using R = rfl::Rename<N, T>;
template <rfl::internal::StringLiteral N, class T> using OptList = rfl::Rename<N, std::optional<std::vector<T>>>;
using A = rfl::Attribute<std::string>;
using OA = std::optional<rfl::Attribute<std::string>>;

struct Datatype { A name; OA baseType; };
struct Code { A name; A value; OA id; };
struct CodeSet { A id; A name; A type; OptList<"fixr:code", Code> code; };
struct Field { A id; A name; A type; OA unionDataType; OA lengthId; OA deprecated; };
struct Ref { A id; OA presence; };
// A message, component or group lists its refs as interleaved siblings; reflect-cpp's XML reader can
// only collect same-named siblings into one vector each, so the order between kinds is not kept.
struct Refs {
  OptList<"fixr:fieldRef", Ref> fieldRef;
  OptList<"fixr:componentRef", Ref> componentRef;
  OptList<"fixr:groupRef", Ref> groupRef;
};
struct Component {
  A id; A name;
  OptList<"fixr:fieldRef", Ref> fieldRef;
  OptList<"fixr:componentRef", Ref> componentRef;
  OptList<"fixr:groupRef", Ref> groupRef;
};
struct Group {
  A id; A name; OA implMaxOccurs;
  R<"fixr:numInGroup", Ref> numInGroup;
  OptList<"fixr:fieldRef", Ref> fieldRef;
  OptList<"fixr:componentRef", Ref> componentRef;
  OptList<"fixr:groupRef", Ref> groupRef;
};
struct Message { A id; A name; A msgType; R<"fixr:structure", Refs> structure; };

struct Datatypes { R<"fixr:datatype", std::vector<Datatype>> datatype; };
struct CodeSets { OptList<"fixr:codeSet", CodeSet> codeSet; };
struct Fields { R<"fixr:field", std::vector<Field>> field; };
struct Components { OptList<"fixr:component", Component> component; };
struct Groups { OptList<"fixr:group", Group> group; };
struct Messages { OptList<"fixr:message", Message> message; };
struct Repository {
  A name; A version;
  R<"fixr:datatypes", Datatypes> datatypes;
  R<"fixr:codeSets", CodeSets> codeSets;
  R<"fixr:fields", Fields> fields;
  R<"fixr:components", Components> components;
  R<"fixr:groups", Groups> groups;
  R<"fixr:messages", Messages> messages;
};

template <class T> std::size_t n(const T& o) { return o ? o->size() : 0; }

int main(int argc, char** argv) {
  if (argc != 3) { std::fprintf(stderr, "usage: rfl_only ORCHESTRA.xml OUT.json\n"); return 2; }
  const auto r = rfl::xml::load<Repository>(argv[1]);
  if (!r) { std::fprintf(stderr, "rfl::xml::load failed: %s\n", r.error().what().c_str()); return 1; }
  const auto& repo = *r;
  std::size_t codes = 0;
  if (const auto& cs = repo.codeSets.get().codeSet.get()) for (const auto& c : *cs) codes += n(c.code.get());
  std::printf("%s %s: reflect-cpp bound %zu datatypes, %zu codeSets, %zu codes, %zu fields, %zu components, %zu groups, %zu messages\n",
              repo.name.value().c_str(), repo.version.value().c_str(), repo.datatypes.get().datatype.get().size(),
              n(repo.codeSets.get().codeSet.get()), codes, repo.fields.get().field.get().size(),
              n(repo.components.get().component.get()), n(repo.groups.get().group.get()),
              n(repo.messages.get().message.get()));
  std::ofstream out(argv[2]);
  out << rfl::json::write(repo, rfl::json::pretty);
  out.close();
  if (!out) { std::fprintf(stderr, "cannot write %s\n", argv[2]); return 1; }
  return 0;
}
