# Coffee Shop Ordering System (C)

A simple command-line coffee shop ordering system built in C. This program demonstrates practical use of structures, arrays, functions, and conditional logic in C, while simulating a real-world coffee shop ordering experience.

## Features

- Display a menu with multiple coffee drinks  
- Choose drink sizes (Small, Regular, Large, X-Large) with price adjustments  
- Select quantity and confirm orders  
- Apply loyalty discounts based on a 4-digit loyalty number  
- Generate a detailed final bill including subtotal, discount, and total  

## How to Use

1. Compile the program using a C compiler:

   ```bash
   gcc coffee_shop.c -o coffee_shop

2. Run the program:

   ```bash
   ./coffee_shop

## Follow the on-screen instructions to:

- Choose an item by entering its code
- Select a size and quantity
- Confirm each order
- Enter a 4-digit loyalty number (optional) to get a discount
- Checkout and view your final bill

## Code Structure

- `struct Order` — Stores details for each order (item, size, quantity, price, total)  
- `displayMenu()` — Shows the coffee menu  
- `getItemDetails()` & `getSizeDetails()` — Fetch item names, prices, and size multipliers  
- `calculateDiscount()` — Computes discounts based on loyalty number  
- `printBill()` — Prints a detailed final bill

## Learning Points

- Using C structures and arrays
- Modular programming with functions
- Input validation and conditional logic
- Handling user input in a command-line interface

## Contact

Created by **Remoshan**  
- Email: [remoshanfrancis123@outlook.com](mailto:remoshanfrancis123@outlook.com)  
- GitHub: [github.com/remoshan](https://github.com/remoshan)  
- LinkedIn: [linkedin.com/in/francis-remoshan](https://www.linkedin.com/in/francis-remoshan)
