# Smart Calculator (C++)

A command-line based smart calculator built using C++ that evaluates mathematical expressions using stack-based parsing, operator precedence, parentheses handling, and decimal support.

This project demonstrates core programming concepts such as data structures, expression evaluation, and structured program design.

---

## Features

* Supports arithmetic operations: +, -, *, /
* Evaluates full expressions with operator precedence (e.g., `2 + 3 * 4`)
* Supports parentheses for grouped evaluation (e.g., `2 * (3 + 4)`)
* Supports decimal (floating-point) calculations (e.g., `4.5 + 2.3`)
* Handles multi-digit numbers
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
* Floating-point number parsing
* String manipulation
* Exception handling
* STL containers (`vector`, `stack`, `string`)
* String streams (`ostringstream`)

---

## Current Limitations

* Unary operators (e.g., `-5`, `+3`) are not handled
* No support for advanced operations (power, trigonometry, etc.)

---

## Future Improvements

* Handle negative numbers and unary operations
* Add support for exponentiation (`^`)
* Improve input validation and error handling
* Build a GUI or web-based version

---

## Author

Mohit Joshi
