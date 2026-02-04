## coffee-shop-orders  
**A simple, fast command-line coffee ordering system in C**

> A lightweight CLI tool that simulates a coffee shop ordering flow — from menu selection to order summary — all in your terminal.

---

### Visuals

<!-- Hero image / screenshot placeholder -->

![Coffee Shop Orders Screenshot – Coming Soon](./docs/assets/hero-placeholder.png)

---

## Features

- **Interactive Menu**: Browse a predefined list of coffee drinks and sizes directly in your terminal.  
- **Automatic Total Calculation**: Calculates order totals based on selected items and quantities.  
- **Order Summary**: Displays a clear, human-readable breakdown of the final order.  
- **Configurable via Environment**: Adjust basic behavior (e.g., currency, locale) through environment variables.  
- **Simple, Testable Core Logic**: Core ordering logic is separated from I/O for easier testing and extension.  
- **Minimal Dependencies**: Written in pure C with standard library only.

---

## Getting Started

### Prerequisites

- **C Compiler** (e.g., `gcc`, `clang`, or MSVC)
- **Make** (optional but recommended, if a `Makefile` is provided)
- A terminal/command prompt

On Windows (using `gcc` with MinGW):

```bash
gcc --version
```

On macOS / Linux:

```bash
gcc --version
# or
clang --version
```

### Installation

Clone the repository and build the binary.

```bash
# 1. Clone the repository
git clone https://github.com/your-username/coffee-shop-orders.git
cd coffee-shop-orders

# 2. Build (using gcc as an example)
gcc -o coffee_shop_orders src/main.c src/order.c src/menu.c

# or, if a Makefile is available
make
```

This will produce an executable (e.g., `coffee_shop_orders` or `coffee_shop_orders.exe` on Windows) in the project directory or `bin/` folder, depending on your build setup.

---

## Usage

Run the program from your terminal and follow the prompts.

```bash
./coffee_shop_orders
```

Example interaction:

```text
=== Welcome to Coffee Shop Orders ===

Please choose a drink:
1) Espresso
2) Americano
3) Latte
4) Cappuccino
5) Mocha

Enter drink number: 3
Enter size (S/M/L): M
Enter quantity: 2

Add another item? (y/n): y

Enter drink number: 1
Enter size (S/M/L): S
Enter quantity: 1

Add another item? (y/n): n

------------------------------
Your Order:
- 2x Medium Latte      $7.00
- 1x Small Espresso    $2.00
------------------------------
Total:                 $9.00

Thank you for your order!
```

If you prefer, you can pipe predefined input (useful for testing):

```bash
printf "3\nM\n2\ny\n1\nS\n1\nn\n" | ./coffee_shop_orders
```

---

## Configuration

You can tweak the runtime behavior using environment variables.

| Variable            | Default | Description                                        |
|---------------------|---------|----------------------------------------------------|
| `CSO_CURRENCY`      | `USD`   | Currency code shown in the order summary.         |
| `CSO_LOCALE`        | `en_US` | Locale-style formatting for numbers/prices.       |
| `CSO_MAX_ITEMS`     | `10`    | Maximum number of items allowed per order.        |
| `CSO_DEBUG`         | `0`     | Set to `1` to enable additional debug logging.    |

Example (macOS / Linux):

```bash
export CSO_CURRENCY=EUR
export CSO_MAX_ITEMS=5
./coffee_shop_orders
```

Example (Windows PowerShell):

```powershell
$env:CSO_CURRENCY = "EUR"
$env:CSO_MAX_ITEMS = "5"
.\coffee_shop_orders.exe
```

---

## Contributing

Contributions are welcome! To propose changes:

1. **Fork** the repository on GitHub.  
2. **Create a feature branch** from `main` (e.g., `feature/add-discount-codes`).  
3. **Implement your changes** with clear, small commits.  
4. **Add or update tests** if applicable.  
5. **Open a Pull Request**:
   - Describe the problem and how your change solves it.
   - Include steps to reproduce and/or test the new behavior.
   - Reference any related issues (e.g., `Closes #123`).

Please keep code style consistent with the existing project and favor small, focused PRs.

---

## License

This project is licensed under the MIT License.  
See the `LICENSE` file for the full license text.
