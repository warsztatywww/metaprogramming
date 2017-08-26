# nim c macro1.nim
# nim js --out:a.js -d:nodejs macro1.nim
import macros

macro hello(): untyped =
  echo "hello world!"
  return parseStmt("""
echo "hello runtime world!"
""")

hello()
