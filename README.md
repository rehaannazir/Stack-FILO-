# Stack — Templated FILO Container in C++

A generic stack implemented from scratch with **class templates** and manual memory management, following the **Rule of Three**.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Templates](https://img.shields.io/badge/Templates_·_Rule_of_Three-6E4C9F?style=flat-square)

---

## Concept

A stack is **FILO** — First In, Last Out. The last element pushed is the first one popped.

```mermaid
flowchart TB
    subgraph Stack["Stack · top = 3"]
        direction TB
        C["data[2] = 30  ← top"]
        B["data[1] = 20"]
        A["data[0] = 10"]
    end
    P["push(40)"] -->|writes to data[top], top++| Stack
    Stack -->|returns top element, top--| Q["pop() → 30"]
```

Internally the container is a heap-allocated array `T* data`, with `capacity` fixed at construction and `top` tracking the next free slot.

---

## Interface

| Member | Signature | Purpose |
|---|---|---|
| **Constructor** | `Stack(int capacity)` | Allocates the backing array |
| **Copy constructor** | `Stack(const Stack&)` | Deep copy — allocates its own buffer |
| **Assignment** | `operator=(const Stack&)` | Self-assignment guarded, frees old buffer, deep copies |
| **Destructor** | `~Stack()` | Releases the array with `delete[]` |
| `push` | `void push(const T&)` | Adds an element when space remains |
| `pop` | `T pop()` | Removes and returns the top element |
| `stack_top` | `T stack_top()` | Reads the top element without removing it |
| `is_empty` | `bool is_empty()` | True when `top == 0` |
| `is_full` | `bool is_full()` | True when `top == capacity` |
| `get_top` | `int get_top()` | Current element count |

---

## The Rule of Three

Because the class manages a raw `new[]` allocation, the compiler-generated defaults would copy the *pointer* rather than the data — leaving two objects owning one buffer and double-freeing it. All three special members are therefore defined explicitly:

```cpp
Stack(const Stack &rhs);              // deep copy
Stack& operator=(const Stack &rhs);   // self-check, free, deep copy
~Stack();                             // delete[]
```

The assignment operator guards against self-assignment before releasing memory:

```cpp
if (this != &rhs) { delete[] data; /* ... reallocate and copy ... */ }
return *this;
```

This is the core lesson of the exercise: **owning a resource means owning its copy semantics.**

---

## Capacity

Capacity is set once, at construction, and does not grow. `is_full()` reports saturation, and `push` refuses to write past the end.

```cpp
Stack<int> s(5);   // holds at most 5 elements
```

---

## Build & Run

```bash
git clone https://github.com/rehaannazir/Stack-FILO-.git
cd Stack-FILO-

g++ main.cpp -o stack
./stack          # Windows: stack.exe
```

Expected output:

```
size      : 3
top       : 30
pop       : 30
pop       : 20
size now  : 1
is_empty  : false
word top  : world
word pop  : world
copy top  : hello
```

### A note on template linkage

The class template is declared in `stack.h` with its definitions in `stack.cpp`. Because templates are instantiated at compile time, those definitions must be visible to whichever translation unit uses them — which is why `main.cpp` includes both:

```cpp
#include "stack.h"
#include "stack.cpp"
```

The alternative is adding explicit instantiations at the bottom of `stack.cpp` for each type you need:

```cpp
template class Stack<int>;
template class Stack<std::string>;
```

---

## Files

| File | Contents |
|---|---|
| `stack.h` | Class template declaration with include guard |
| `stack.cpp` | Member definitions, each prefixed with `template <typename T>` |
| `main.cpp` | Runnable demo covering push/pop, `Stack<string>`, and deep copy |

---

## Concepts demonstrated

| Concept | Where |
|---|---|
| **Class templates** | `template <typename T> class Stack` |
| **Dynamic allocation** | `new T[capacity]` / `delete[] data` |
| **Rule of Three** | Copy constructor, assignment operator, destructor |
| **Self-assignment safety** | `if (this != &rhs)` before freeing |
| **Deep copy** | Element-wise loop rather than pointer assignment |
| **Encapsulation** | `data`, `capacity`, `top` all private |
| **Header guards** | `#ifndef` / `#define` / `#endif` |
