APC – Arbitrary Precision Calculator
Author: Om Bidikar
Batch: 25017_172
Date: 14 Nov 2025
About the Project

This project implements a Big Integer Calculator that performs arithmetic operations on very large integers (numbers bigger than what int or long long can store).

To achieve this, each digit is stored inside a Doubly Linked List, allowing numbers of unlimited size.

The project supports:

➕ Addition

➖ Subtraction

✖ Multiplication

➗ Division

Conversion of input digits into linked list

Utility functions (insert, compare, free, print)

All functions are modular and separated into their own .c files.

## 📁 Project Structure

Apc_projectt/

Source Files:
- main.c
- addition.c
- subtraction.c
- multiplication.c
- division.c
- digit_to_list.c
- list_utils.c

Header File:
- apc.h

Build:
- Makefile

Documentation:
- README.md

⚙️ How to Compile

In the terminal, run:

make


This will create an executable:

calc.out

▶️ How to Run

Use the format:

./calc.out <num1> <operator> <num2>

Example:
./calc.out 12345 + 6789


Output:

Result (Addition): 19134

🧪 Examples
➕ Addition
./calc.out 98765 + 555
Result (Addition): 99320

➖ Subtraction
./calc.out 5000 - 345
Result (Subtraction): 4655

✖ Multiplication
./calc.out 123 * 456
Result (Multiplication): 56088

➗ Division
./calc.out 100 / 5
Result (Division): 20

💡 Key Data Structure: Doubly Linked List

Example node:

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} Dlist;


Each digit of a number is stored as one node in the list.

✨ Features

✔ Handles very large numbers
✔ Memory efficient
✔ Modular design
✔ Uses linked lists instead of arrays
✔ Works like a real big integer calculator

🧹 How to Clean Build Files
make clean


This removes .o files and the executable.

📘 License

This project is open-source. You may modify, distribute, or use it for learning.
