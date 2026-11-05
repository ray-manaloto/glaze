#!/usr/bin/env python3
"""Generate a deterministic synthetic FIX 4.4 corpus (fixed seed).

All values are random/synthetic; nothing is copied from any real feed.
Output: data/corpus.fix -- SOH-delimited messages, concatenated, no separators.
"""
import random, sys, os

SOH = "\x01"
SEED = 20261105
N = 10000

def num(x):
    s = repr(float(x))
    return s[:-2] if s.endswith(".0") else s

def build(msg_type, fields):
    body = f"35={msg_type}{SOH}" + "".join(f"{t}={v}{SOH}" for t, v in fields)
    head = f"8=FIX.4.4{SOH}9={len(body)}{SOH}"
    msg = head + body
    cs = sum(msg.encode()) % 256
    return msg + f"10={cs:03d}{SOH}"

SYMS = ["AAPL", "MSFT", "GOOG", "AMZN", "TSLA", "NVDA", "META", "IBM", "ORCL", "INTC"]

def ts(r):
    return f"20261105-{r.randrange(24):02d}:{r.randrange(60):02d}:{r.randrange(60):02d}.{r.randrange(1000):03d}"

def px(r):
    return num(round(r.uniform(10, 500), 2))

def hdr(r, seq):
    return [("49", "SENDER"), ("56", "TARGET"), ("34", seq), ("52", ts(r))]

def nos(r, seq):
    f = hdr(r, seq) + [("11", f"ORD{r.randrange(10**9)}"), ("55", r.choice(SYMS)), ("54", r.choice("12")),
                       ("60", ts(r)), ("38", r.randrange(1, 10000)), ("40", "2"), ("44", px(r))]
    return build("D", f)

def er(r, seq):
    qty = r.randrange(100, 10000)
    cum = r.randrange(0, qty + 1)
    f = hdr(r, seq) + [("37", f"X{r.randrange(10**9)}"), ("11", f"ORD{r.randrange(10**9)}"),
                       ("17", f"E{r.randrange(10**12)}"), ("150", r.choice("0F4")), ("39", r.choice("012")),
                       ("55", r.choice(SYMS)), ("54", r.choice("12")), ("38", qty), ("44", px(r)),
                       ("32", r.randrange(0, 1000)), ("31", px(r)), ("151", qty - cum), ("14", cum),
                       ("6", px(r)), ("60", ts(r))]
    return build("8", f)

def mdx(r, seq):
    n = r.randrange(1, 9)
    f = hdr(r, seq) + [("262", f"MD{r.randrange(10**6)}"), ("268", n)]
    for _ in range(n):
        f += [("279", r.choice("012")), ("269", r.choice("01")), ("55", r.choice(SYMS)),
              ("270", px(r)), ("271", r.randrange(1, 100000))]
    return build("X", f)

def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(__file__), "data", "corpus.fix")
    r = random.Random(SEED)
    gens = [nos, er, mdx]
    with open(out, "w", newline="") as fh:
        for i in range(N):
            fh.write(gens[i % 3](r, i + 1))

if __name__ == "__main__":
    main()
