# Yet Another MPFR C++ Wrapper

A modern, educational, and high-performance C++20 wrapper for the [MPFR](https://www.mpfr.org/) library, designed to teach numerical expression evaluation using expression templates.

This project aims to strike a balance between **readability**, **performance**, and **learnability**, progressing step by step from a naive implementation to a nearly zero-overhead expression template engine comparable to raw MPFR code.

---

## ✨ Goals

- 📘 **Educational**: Teach how to write a wrapper around MPFR.
- ⚡ **Fast**: Approach raw MPFR performance using C++20 and expression templates.
- 🔧 **Flexible**: Expression templates can be disabled for debugging or clarity.
- 🧠 **Modern C++**: Use `constexpr`, `concepts`, and other C++20 features.
- 🧪 **Incremental Design**: Build in stages to understand trade-offs and performance.

---

## 🧱 Structure (Progressive Stages)

### 1. Minimal Wrapper

- Wraps `mpfr_t` with RAII.
- Implements constructors, assignment, copy/move semantics.
- Basic arithmetic: `+`, `-`, `*`, `/`.

```cpp
mpfr_class a("1.2345"), b("6.7890");
mpfr_class c = a + b;
````

### 2. Operator Overloading

* Overload arithmetic and comparison operators.
* Support mixed types (`mpfr_class + double`, etc).

### 3. Expression Templates (ET)

* Delay evaluation of expressions.
* Avoids temporaries: `c = a + b * d - e;` is optimized internally.

```cpp
// With ET enabled
mpfr_class c = a + b * d - e;  // Single evaluation pass
```

### 4. Disabling Expression Templates

* For debugging, clarity, or benchmarking.
* Controlled via `#define MPFR_WRAPPER_USE_ET 0`.

```cpp
#define MPFR_WRAPPER_USE_ET 0
#include "mpfr_wrapper.h"
```

### 5. Advanced Features

* Support for mathematical functions: `sqrt`, `log`, `exp`, etc.
* Precision and rounding mode control.
* Stream operators and formatting.
* Compatibility with `std::vector`, `std::ranges`, and parallel execution.

---

## 🛠 Requirements

* C++20-compatible compiler (tested with `g++-13`, `clang++-17`).
* MPFR library installed.
* CMake 3.20+ (optional but recommended).

---

## 🚀 Quick Start

```bash
git clone https://github.com/nakatamaho/mpfrxx
cd mpfrxx
make
./examples/demo
```

---

## 📊 Performance

We aim to approach or match the performance of raw MPFR calls:

| Implementation       | Performance vs Raw MPFR |
| -------------------- | ----------------------- |
| Naive Wrapper        | \~30–60%                |
| Expression Templates | \~90–100%               |
| Raw MPFR (baseline)  | 100%                    |

Benchmarks and assembly analysis are available under `benchmarks/`.

---

## 🧪 Examples

See the `examples/` directory for:

* Basic arithmetic
* Expression evaluation
* Precision control
* Performance tests

---

## 🔬 Design Philosophy

This project is ideal for:

* C++ developers interested in numerical computing.
* Learners studying expression templates.
* Researchers needing custom MPFR tooling with clearer syntax.

Design principles:

* Header-only.
* Clean separation of layers: wrapper vs ET vs math functions.
* Readable and self-documenting code.

---

## 📚 References

* [MPFR Library](https://www.mpfr.org/)
* [C++20 Features – cppreference](https://en.cppreference.com/w/cpp/20)
* "C++ Template Metaprogramming" – Abrahams & Gurtovoy
* "Modern C++ Design" – Alexandrescu

---

## 📄 License

2-clause BSD License (Simplified BSD License)

---

## 🙏 Acknowledgments

This wrapper builds on ideas from existing libraries such as:

* [gmpxx.h](https://gmplib.org/manual/C_002b_002b-Class-Interface)
* [mpreal](https://www.holoborodko.com/pavel/mpfr/)
* [Boost.Multiprecision](https://www.boost.org/doc/libs/release/libs/multiprecision/)

---

## 🗺️ Roadmap

* [x] Basic RAII wrapper
* [x] Operator overloading
* [x] Expression templates
* [x] Disable ET via macro
* [ ] Advanced math functions
* [ ] Interval arithmetic?
* [ ] MPFR/Boost interop
* [ ] Jupyter / Python bindings?

Contributions and feedback are welcome!
