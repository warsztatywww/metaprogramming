import macros

proc symToExpr*(val: NimNode, depth=false): NimNode =
  if val.kind == nnkSym:
    if depth:
      return newIdentNode($val)
    else:
      return val
  elif val.kind in {nnkIntLit}:
    return val
  elif val.kind == nnkBracketExpr: # hacky
    result = newNimNode(nnkBracketExpr)
    for item in val:
      result.add symToExpr(item, true)
  else:
    return nil

proc `[]`*(node: NimNode, s: Slice): seq[NimNode] =
  result = @[]
  for i in s:
    result.add(node[i])

template compilesOr(obj, otherwise): untyped =
  when compiles(obj):
    obj
  else:
    otherwise

proc privateGuard(obj: NimNode): NimNode {.compiletime.} =
  return newCall(bindSym"compilesOr", obj, newStrLitNode("(private)"))

proc addField(obj: NimNode, k: string): NimNode {.compiletime.} =
  return newCall(newIdentNode("eachField"), newStrLitNode(k), privateGuard(newDotExpr(obj, newIdentNode(k))))

proc addFieldsBranch(obj: NimNode, typ: NimNode): NimNode {.compiletime.} =
  let body = newNimNode(nnkStmtList)
  for node in typ:
    if node.kind == nnkSym:
      let nameStr = $node
      body.add addField(obj, nameStr)
    elif node.kind == nnkRecCase:
      let recName = $node[0]
      body.add addField(obj, recName)
      for branch in node[1..^1]:
        let value = branch[0]
        let cond = newCall(newIdentNode("=="),
                           newDotExpr(obj, newIdentNode(recName)), value)
        let subbody = addFieldsBranch(obj, branch[1])
        let branchExpr = newNimNode(nnkIfStmt).add(newNimNode(nnkElifBranch).add(cond, subbody))
        body.add(branchExpr)
  return body

macro objFieldsAdd*(obj: typed): typed =
  var t = getType(obj)

  if t.kind == nnkSym:
    t = t.getType

  if t.kind == nnkBracketExpr:
    let typePrefix = $(t[0])
    if typePrefix != "ref" or t.len != 2:
      error("unknown type definition")
    t = t[1].getType

  if t.kind != nnkObjectTy or t[2].kind != nnkRecList:
    error("unknown type definition")

  let body = newNimNode(nnkStmtList)
  body.add(addFieldsBranch(obj, t[2]))

  return body

template iterateFields*(obj: untyped): untyped =
  objFieldsAdd(obj)

when isMainModule:
  type Foobar = object
    a: int
    b: string

  var f: Foobar

  proc eachField[T](key: string, value: T) =
    echo key, " -> ", value

  iterateFields f
