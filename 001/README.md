
# DoubleVal Expression Templates  

*A minimal C++20 expression‑template library that wraps `double` in a `DoubleVal` type and supports compile‑time construction of addition expressions.*

---  

## Table of Contents  

- [Overview](#overview)  
- [Features](#features)  
- [Requirements](#requirements)  
- [Installation & Build](#installation--build)  
- [Usage Example](#usage-example)  
- [API Reference](#api-reference)  
- [License](#license)  

---  

## Overview  

`DoubleVal` is a thin wrapper around a plain `double`.  
Using **expression templates**, the library builds an expression tree for chained `+` operations at compile time, eliminating intermediate temporaries.  
Evaluation is performed lazily by calling `eval()` on the resulting expression object.

The implementation is intentionally tiny (≈150 LOC) and serves as a clean starting point for more sophisticated numeric DSLs.

---  

## Features  

- **C++20 only** – takes advantage of concepts, `constexpr` and perfect forwarding.  
- **Single operation support** – addition (`+`).  
- **Zero runtime overhead** – expression trees are built at compile time; only one actual addition occurs when `eval()` is invoked.  
- **Implicit conversion** – `DoubleVal` can be used wherever a plain `double` is expected.  
- **Extensible** – add `MulExpr`, `SubExpr`, etc., and overload the corresponding operators to grow the DSL.

---  

## Requirements  

| Tool | Minimum Version |
|------|-----------------|
| C++ compiler | Supports **C++20** (e.g., GCC 10+, Clang 12+, MSVC 19.28+) |
| CMake | 3.15 (optional, for the provided CMakeLists.txt) |
| Git | any recent version |

---  

## Installation & Build  

### 1. Clone the repository  

```bash
git clone https://github.com/yourusername/doubleval-expr-templates.git
cd doubleval-expr-templates
```

### 2. Build with CMake (recommended)  

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

The executable `expr_demo` will be generated in the `build` directory.

### 3. Build without CMake (single file)  

```bash
g++ -std=c++20 -O2 -Wall -Wextra expression_template.cpp -o expr_demo
```

---  

## Usage Example  

```cpp
#include "expression_template.hpp"   // (or just the single .cpp file)

int main() {
    DoubleVal a{1.5};
    DoubleVal b{2.0};
    DoubleVal c{3.0};

    // Build the expression tree: (a + b) + c
    auto expr = a + b + c;

    // Evaluate once – only one real addition happens at runtime
    DoubleVal result = expr.eval();

    std::cout << "Result = " << static_cast<double>(result) << '\n';
    // Output: Result = 6.5
}
```

**Explanation**

1. `a + b + c` does **not** create temporary `DoubleVal` objects.  
2. Each `+` produces an `AddExpr` node; the whole tree is known at compile time.  
3. Calling `expr.eval()` recursively evaluates the tree, performing a single addition for each node.

---  

## API Reference  

| Symbol | Description |
|--------|-------------|
| `class DoubleVal` | Wrapper around `double`. Provides `get()`, implicit conversion to `double`, and a constexpr constructor. |
| `template<class Derived> class Expr` | CRTP base class offering `constexpr DoubleVal eval() const`. All expression nodes inherit from this. |
| `template<class LHS, class RHS> class AddExpr` | Represents `LHS + RHS`. Stores the left/right sub‑expressions and implements `eval_impl()`. |
| `operator+` | Overloaded for `DoubleVal` and any `Expr` type; returns an `AddExpr`. |
| `eval()` | Member of any `Expr` that triggers the actual calculation and returns a `DoubleVal`. |

---  

## License  

This software is released under the **BSD 2‑Clause License** (also known as the “Simplified BSD License”).  

```
Copyright (c) <YEAR>, <YOUR NAME OR ORGANIZATION>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

Replace `<YEAR>` and `<YOUR NAME OR ORGANIZATION>` with the appropriate values.

---  

*Happy hacking!*
