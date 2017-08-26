import macros, strutils

type
  ModuloInt[p: static[int]] = distinct int

proc isPrime(v: int): bool =
  for j in 2..<v:
    if v mod j == 0:
      return false

  return true

# f(a, b, c)
# a.f(b, c)
# f1(f2(f3(x))) x.f3.f2.f1

proc invert[p: static[int]](m: ModuloInt[p]): ModuloInt[p] =
  static:
    if not isPrime(p):
      error("attempting to invert a number modulo not-prime ($1)!" % [$p])
  return ModuloInt[p](0) # dummy

let v = ModuloInt[12](5)
discard v.invert()
