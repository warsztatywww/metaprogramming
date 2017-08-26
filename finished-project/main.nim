import jester, asyncdispatch, strutils, cgi
import htmlify, todolist, macroutils

var myTodoList = defaultList

# WARSZTATY (metaprogramowanie)

proc changeValue(obj: var bool, path: seq[string], value: string) =
  echo "not supported"

proc changeValue(obj: var string, path: seq[string], value: string) =
  obj = value

proc changeValue[T](obj: var seq[T], path: seq[string], value: string) =
  let index = parseInt(path[0])
  changeValue(obj[index], path[1..<path.len], value)

proc changeValue(obj: var object, path: seq[string], value: string) =
  let path = path
  let value = value
  echo "change ", path, " to ", value

  proc eachField[T](key: string, keyval: var T) =
    echo "try ", key, " ", path[0]
    if key != path[0]: return

    changeValue(keyval, path[1..<path.len], value)

  iterateFields obj

routes:
  get "/":
    var s = "<pre>$1</pre>" % printTree(myTodoList)
    s &= """<input type="text" name="title" class=auto placeholder="hello">"""

    s &= """<script src=jquery.js></script><script src=script.js></script>"""
    resp s

  post "/apply":
    let id = @"id"
    let value = @"value"

    changeValue(myTodoList, id.strip(chars={'/'}).split("/"), value)
    resp "ok"

runForever()
