// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#include <cstdint>

#include "glaze/core/opts.hpp"

namespace glz
{
   // Custom format id for FIX tag=value (custom ids are >= 65536, see glaze issue #1619).
   inline constexpr uint32_t FIX = 65536 + 9;

   // Options for the FIX tag=value format, used as glz::read<glz::fix_opts{}>(obj, msg).
   struct fix_opts : opts
   {
      uint32_t format = FIX;
      char soh = '\x01'; // field delimiter; tests may use '|' for readability
      bool validate_checksum = true; // tag 10 must equal the sum of all preceding bytes mod 256
      bool validate_body_length = true; // tag 9 must equal the byte count from after 9's SOH to before "10="
      bool error_on_unknown_tags = false; // top-level unknown tags are skipped by default
      bool validate_msg_type = true; // on read, tag 35 must equal glz::meta<T>::fix_msg_type when it is declared
   };
}

namespace glz::fix
{
   // fix_opts with '|' as the delimiter, for readable tests. GCC warns (-Wmissing-field-initializers)
   // on glz::fix_opts{.soh = '|'} because the glz::opts base cannot be designated.
   inline constexpr fix_opts pipe_opts = [] {
      fix_opts o{};
      o.soh = '|';
      return o;
   }();
}
