# Smart Calculator (C++)

A command-line based smart calculator built using C++ that evaluates mathematical expressions using stack-based parsing, operator precedence, parentheses handling, decimal support, and unary operator handling.

This project demonstrates core programming concepts such as data structures, expression parsing, and expression evaluation similar to real interpreters.

---

## Features

* Supports arithmetic operations: +, -, *, /
* Evaluates full expressions with operator precedence (e.g., `2 + 3 * 4`)
* Supports parentheses for grouped evaluation (e.g., `2 * (3 + 4)`)
* Supports decimal (floating-point) calculations (e.g., `4.5 + 2.3`)
* Handles multi-digit numbers
* Supports unary operators (`+`, `-`) including chained unary expressions:

  * `-5`
  * `+3`
* Stack-based expression parsing (infix evaluation)
* Exception handling (division by zero, invalid operator)
* Interactive command-line interface
* History tracking with indexing
* Option to clear history

---

## Concepts Used

* Stack (LIFO) data structure
* Expression parsing and evaluation
* Operator precedence handling
* Parentheses-based control flow
* Unary operator handling
* Floating-point number parsing
* String manipulation
* Exception handling
* STL containers (`vector`, `stack`, `string`)
* String streams (`ostringstream`)

---

## Example

Input:

```
+2 * (-3 + 4.5)
```

Output:

```
15.00
```

---

## Current Limitations

* No support for advanced operators (e.g., exponent `^`)
* No support for mathematical functions (e.g., `sin`, `log`)
* Limited input validation for malformed expressions

---

## Future Improvements

* Add exponentiation operator (`^`)
* Support mathematical functions (sin, cos, log, etc.)
* Improve input validation and error handling
* Build a GUI or web-based version
* Add keyboard-friendly expression editing

---

## Author

Mohit Joshi
