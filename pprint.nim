import macros

type Foobar = object
  a: int
  b: string

macro printType(obj: typed): typed =
  echo obj.treeRepr
  var t = getType(obj)
  echo t.treeRepr
  if t.kind != nnkObjectTy:
    error("smutno")

  var node = newNimNode(nnkStmtList)

  let symList = t[2]
  for sym in symList:
    echo sym.repr
    let name = sym.repr
    node.add quote do:
      echo `name`, " = ", `obj`.`sym`

  echo(node.repr)
  return node

static:
  staticRead("pprint.nim").parseStmt.treeRepr.echo

var x: Foobar
x.a = 5
#printType(x)
