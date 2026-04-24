# APC – Arbitrary Precision Calculator

## Author

Om Bidikar

---

## About the Project

This project implements a Big Integer Calculator capable of performing arithmetic operations on numbers larger than standard data types such as `int` or `long long`.

To achieve this, each digit of a number is stored in a **Doubly Linked List**, allowing the system to handle integers of virtually unlimited size.

---

## Features

* Addition of large integers
* Subtraction of large integers
* Multiplication of large integers
* Division of large integers
* Conversion of input numbers into linked list representation
* Utility functions (insert, compare, print, free memory)

---

## 📁 Project Structure

```
APC/
│
├── src/
│   ├── main.c
│   ├── addition.c
│   ├── subtraction.c
│   ├── multiplication.c
│   ├── division.c
│   ├── digit_to_list.c
│   ├── list_utils.c
│
├── include/
│   ├── apc.h
│
├── external_commands/
│   ├── Makefile
│
├── Screenshot/
│   ├── apc-output.png
│
└── README.md
```

---

## ⚙️ How to Compile

Run the following command:

```bash
make
```

This will generate the executable:

```bash
calc.out
```

---

## ▶️ How to Run

```bash
./calc.out <num1> <operator> <num2>
```

### Example:

```bash
./calc.out 12345 + 6789
```

**Output:**

```
Result (Addition): 19134
```

---

## 🧪 Examples

### ➕ Addition

```
./calc.out 98765 + 555
Result: 99320
```

### ➖ Subtraction

```
./calc.out 5000 - 345
Result: 4655
```

### ✖ Multiplication

```
./calc.out 123 * 456
Result: 56088
```

### ➗ Division

```
./calc.out 100 / 5
Result: 20
```

---

## 📸 Output Screenshot

The following screenshot demonstrates execution of all arithmetic operations:

![APC Output](Screenshot/apc-output.png)

---

## 💡 Key Data Structure: Doubly Linked List

```c
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} Dlist;
```

Each digit of a number is stored as a node in the list, enabling operations on very large integers.

---

## 🧠 Concepts Used

* Doubly Linked Lists
* Dynamic Memory Allocation
* Pointer Manipulation
* Modular Programming in C

---

## ⚠️ Limitations

* Supports only integer arithmetic
* No floating-point support
* Limited input validation

---

## 🧹 Clean Build

To remove object files and executable:

```bash
make clean
```

---

## 📘 License

This project is open-source and intended for learning purposes.
