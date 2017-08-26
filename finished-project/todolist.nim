
type
  TodoList* = object
    title*: string
    items*: seq[TodoItem]

  TodoItem* = object
    completed*: bool
    text*: string

const defaultList* = TodoList(
  title: "my list",
  items: @[
    TodoItem(text: "learn Nim"),
    TodoItem(text: "don't use Go", completed: true),
  ]
)
