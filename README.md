# C-DSALib

## Introduction

C-DSALib is a lightweight and efficient C library providing a variety of commonly used data structures and algorithms. It is designed to be flexible, modular, and easy to use, with an object-oriented programming model in C. The library is well-suited for low-level system programming, embedded systems, and performance-critical applications.

### Key Features

- **Modular Design**: Use only the data structures and algorithms you need.
- **OOP-like Interface**: Encapsulated structures and method binding for better code organization.
- **Highly Efficient**: Written in pure C with minimal overhead.
- **Flexible Integration**: Easy to include and link with any C project.

## Installation

To use C-DSALib in your project, follow these steps:

### Clone the Repository

```bash
git clone https://github.com/duyphuongnguyen1999/C-DSALib.git
cd C-DSALib
```

### Build the Library

To build the library, simply run make:

```bash
make
```

### Integration

To integrate C-DSALib into your own project, include the header files and link the static library:

```c
#include "cdsalib.h"  // Single header for the entire library
```

In your Makefile, link against the static library:

```makefile
LDFLAGS = -Lpath_to_C-DSALib/lib -lC-DSALib
```
