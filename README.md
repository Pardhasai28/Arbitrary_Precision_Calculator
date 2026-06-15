# Arbitrary_Precision_Calculator
# Arbitrary Precision Calculator (APC)

## Overview

The Arbitrary Precision Calculator (APC) is a command-line application developed in C that performs arithmetic operations on integers of virtually unlimited size.

Unlike built-in data types such as `int`, `long`, or `long long`, which have fixed storage limits, this calculator can handle numbers containing hundreds or thousands of digits by storing and processing them dynamically.

The project demonstrates the implementation of fundamental data structures and algorithms required for large number arithmetic.

---

## Features

* Addition of large integers
* Subtraction of large integers
* Multiplication of large integers
* Division of large integers
* Modulus operation
* Supports positive and negative numbers
* Handles operands with thousands of digits
* Efficient memory utilization using dynamic data structures
* Command-line based user interface

---

## Motivation

Traditional data types in C have size limitations:

| Data Type   | Typical Size | Maximum Value             |
| ----------- | ------------ | ------------------------- |
| `int`       | 4 bytes      | 2,147,483,647             |
| `long long` | 8 bytes      | 9,223,372,036,854,775,807 |

For applications involving cryptography, scientific computing, financial systems, and large numerical computations, these limits are insufficient.

This project overcomes those limitations by implementing arbitrary precision arithmetic.

---

## Data Structure Used

Large numbers are represented using a linked list.

Each node stores a single digit of the number.

Example:

Number:

```text
9876543210
```

Representation:

```text
9 → 8 → 7 → 6 → 5 → 4 → 3 → 2 → 1 → 0
```

This approach allows dynamic growth of the number size without memory constraints imposed by primitive data types.

---

## Supported Operations

### Addition

Performs digit-by-digit addition while handling carry propagation.

### Subtraction

Performs subtraction with borrow handling.

### Multiplication

Implements multiplication using repeated partial products and carry management.

### Division

Computes quotient and remainder using long division logic.



---

## Technologies Used

* Programming Language: C
* Data Structure: Linked List
* Standard Libraries:

  * stdio.h
  * stdlib.h
  * string.h
  * ctype.h

---

## Project Structure

```text
.
├── main.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── list.c
├── apc.h
├── common.h
└── Makefile
```

---

## Build Instructions

Compile using GCC:

```bash
gcc *.c -o apc
```

Or use Makefile:

```bash
make
```

---

## Usage

Run the executable:

```bash
./apc
```

Example:

```text
Enter first number  : 123456789123456789123456789
Enter operator      : +
Enter second number : 987654321987654321987654321

Result:
1111111111111111111111111110
```

---

## Algorithm Workflow

1. Read input operands as strings.
2. Validate the input format.
3. Store digits in linked lists.
4. Perform the selected arithmetic operation.
5. Handle carries and borrows appropriately.
6. Display the final result.

---

## Concepts Covered

* Linked Lists
* Dynamic Memory Allocation
* String Manipulation
* Modular Programming
* Pointer Operations
* Large Number Arithmetic
* Algorithm Design
* Memory Management

---

## Applications

* Cryptography
* Scientific Computing
* Financial Calculations
* Competitive Programming
* Numerical Analysis

---

## Future Enhancements

* Support for floating-point numbers
* Exponentiation and square root operations
* Expression parsing with operator precedence
* Graphical User Interface (GUI)
* Support for hexadecimal and binary arithmetic

---

## Learning Outcomes

This project helped in understanding:

* Implementation of arbitrary precision arithmetic
* Efficient use of linked lists
* Dynamic memory management in C
* Handling very large numbers beyond native data type limits
* Designing scalable arithmetic algorithms

---

## Author

**Pardha Sai**

GitHub: https://github.com/Pardhasai28
