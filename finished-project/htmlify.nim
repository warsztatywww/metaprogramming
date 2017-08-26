import macros, todolist, macroutils, strutils, typetraits, cgi

# ktoś chce napisać json.from?

proc printTree*(obj: any, path=""): string

proc printItem*(obj: any, path=""): string =
  when obj is object:
    return type(obj).name & "\n" & indent(printTree(obj, path), 2)
  elif obj is seq:
    var s = ""
    for i, item in obj:
      s.add "\n" & indent(printItem(item, path=path & "/" & $i), 2)
    return s
  elif obj is string:
    return "<input class=auto name=\"$1\" value=\"$2\">\n" % [path, xmlEncode($obj)]
  else:
    return xmlEncode($obj) & "\n"

proc printTree(obj: any, path=""): string =
  var s = ""
  let path = path

  proc eachField[T](key: string, value: T) =
    s.add(key & " -> ")
    s.add printItem(value, path=path & "/" & key)

  iterateFields obj

  return s

when isMainModule:
  echo printTree(defaultList)
