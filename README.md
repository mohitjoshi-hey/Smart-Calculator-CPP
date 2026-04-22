# Smart Calculator (C++)

A command-line based smart calculator built using C++ that evaluates mathematical expressions using stack-based parsing, operator precedence, parentheses, decimal handling, and advanced unary operator support.

This project implements a mini expression evaluation engine similar to the core logic used in interpreters and compilers.

---

## Features

* Supports arithmetic operations: +, -, *, /
* Evaluates full expressions with operator precedence
  Example: `2 + 3 * 4`
* Supports parentheses for grouped evaluation
  Example: `2 * (3 + 4)`
* Supports decimal (floating-point) calculations
  Example: `4.5 + 2.3`
* Handles multi-digit numbers
* Supports exponent calculations
  Example: `4.5 ^ 2.3 ^ 3`
* Supports unary operators (`+`, `-`)
* Supports chained unary expressions:

  * `-5`
  * `--5`
  * `+-3`
  * `+++5`
* Handles complex nested expressions with correct evaluation
* Stack-based expression parsing (infix evaluation)
* Exception handling:

  * Division by zero
  * Invalid operator detection
  * Root or non-integer power of a negative number
* Interactive command-line interface
* History tracking with indexing
* Option to clear history

---

## Concepts Used

* Stack (LIFO) data structure
* Expression parsing and evaluation
* Operator precedence handling
* Parentheses-based control flow
* Unary operator handling (single and chained)
* Floating-point number parsing
* String manipulation
* Exception handling
* STL containers:

  * `vector`
  * `stack`
  * `string`
* String streams (`ostringstream`)

---

## Example

Input:

```
+++4 - +++5 * -+-8 + (--4 * 3)
```

Output:

```
-24.00
```

---

## How It Works

The calculator processes expressions using two stacks:

* **Operand stack (`nums`)** for numbers
* **Operator stack (`optr`)** for operators

### Core Logic:

1. Parse the expression character by character
2. Handle numbers (including decimals)
3. Detect unary operators based on context
4. Apply operator precedence rules
5. Evaluate expressions using stack operations
6. Handle parentheses by controlled evaluation

---

## Current Limitations

* No support for mathematical functions (e.g., `sin`, `log`)
* Limited validation for malformed expressions
* No support for variables

---

## Future Improvements

* Support mathematical functions (sin, cos, log, etc.)
* Improve input validation and error handling
* Add support for variables and expressions
* Build a GUI or web-based version
* Add expression editing and better CLI UX

---

## Author

Mohit Joshi
