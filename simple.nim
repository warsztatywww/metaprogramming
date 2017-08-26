import typetraits

proc splitByAndReverse*[T](s: seq[T], k: int): seq[seq[T]] =
  ## Podzielić ``s`` co ``k`` elementów i wrzucić wynik do result, i odwrócić wewnętrznie

  static:
    echo type([]).name
    echo type(@[]).name

  result = @[]

  template `...`(arr) =
    var seg = arr
    for i in 0 ..< (seg.len div 2):
      swap(seg[i], seg[seg.len - i - 1])
    result.add seg

  var index = 0
  while index + k <= s.len:
    ... s[index ..< index + k]
    index += k

  ... s[index ..< s.len]

echo splitByAndReverse[int](@[1, 2, 3, 4, 5], 2)
