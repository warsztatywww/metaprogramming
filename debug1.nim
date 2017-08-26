import macros, typetraits

macro debug1(x): untyped =
  echo x.repr, " ", x.type.name
  let v = "echo \"" & x.repr & " = \", " & x.repr
  echo v
  return parseStmt(v)

macro debug2(x): untyped =
  #echo x.repr, " ", x.type.name
  #let v = "echo \"" & x.repr & " = \", " & x.repr
  let varname = x.repr
  return quote do:
        echo `varname`, " = ", `x`

let x = 100
debug2(x + 1)
