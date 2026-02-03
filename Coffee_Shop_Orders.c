#include <stdio.h>
#include <string.h>

struct Order
{
    int itemCode;
    char itemName[20];
    char size[15];
    int quantity;
    float price;
    float total;
};

struct Order orders[100];
int orderCount = 0;

void displayMenu()
{
    printf("\n===== Coffee Shop Menu =====\n");
    printf("Code\tName\t\tPrice\n");
    printf("1\tCappuccino\t$3.65\n");
    printf("2\tAmericano\t$2.65\n");
    printf("3\tEspresso\t$1.65\n");
    printf("4\tMacchiato\t$3.65\n");
    printf("5\tMocha\t\t$2.85\n");
    printf("6\tLatte\t\t$2.95\n");
    printf("0\tCheckout\n");
}

int isValidItem(int code)
{
    return code >= 1 && code <= 6;
}

int isValidSize(int code)
{
    return code >= 1 && code <= 4;
}

int isValidLoyalty(int number)
{
    return number >= 1000 && number <= 9999;
}

void getItemDetails(int code, char name[], float *price)
{
    switch (code)
    {
    case 1:
        strcpy(name, "Cappuccino");
        *price = 3.65;
        break;
    case 2:
        strcpy(name, "Americano");
        *price = 2.65;
        break;
    case 3:
        strcpy(name, "Espresso");
        *price = 1.65;
        break;
    case 4:
        strcpy(name, "Macchiato");
        *price = 3.65;
        break;
    case 5:
        strcpy(name, "Mocha");
        *price = 2.85;
        break;
    case 6:
        strcpy(name, "Latte");
        *price = 2.95;
        break;
    }
}

void getSizeDetails(int code, char sizeName[], float *multiplier)
{
    switch (code)
    {
    case 1:
        strcpy(sizeName, "Small");
        *multiplier = 0.9;
        break; // 10% decrease
    case 2:
        strcpy(sizeName, "Regular");
        *multiplier = 1.0;
        break; // No change
    case 3:
        strcpy(sizeName, "Large");
        *multiplier = 1.1;
        break; // 10% increase
    case 4:
        strcpy(sizeName, "X-Large");
        *multiplier = 1.25;
        break; // 25% increase
    }
}

float calculateDiscount(float total, int loyaltyNumber)
{
    if (total <= 10.0)
        return 0.0; // No discount if total <= $10

    int lastDigit = loyaltyNumber % 10; // Get last digit

    if (lastDigit == 1 || lastDigit == 2)
        return total * 0.05; // 5% discount
    if (lastDigit == 3 || lastDigit == 4)
        return total * 0.07; // 7% discount
    if (lastDigit == 5 || lastDigit == 6)
        return total * 0.08; // 8% discount
    if (lastDigit >= 7 && lastDigit <= 9)
        return total * 0.10; // 10% discount

    return 0.0; // No discount for other digits
}

void printBill(int loyaltyNumber)
{
    float grandTotal = 0.0;

    printf("\n===== Final Bill =====\n");
    for (int i = 0; i < orderCount; i++)
    {
        printf("%d. %s (%s) x %d = $%.2f\n",
               i + 1,
               orders[i].itemName,
               orders[i].size,
               orders[i].quantity,
               orders[i].total);

        grandTotal += orders[i].total;
    }

    printf("\nSubtotal: $%.2f\n", grandTotal);

    float discount = 0.0;
    if (isValidLoyalty(loyaltyNumber))
    {
        discount = calculateDiscount(grandTotal, loyaltyNumber);
        printf("Loyalty Discount: -$%.2f\n", discount);
    }
    else
    {
        printf("No loyalty discount applied.\n");
    }

    float finalTotal = grandTotal - discount;
    printf("Final Total: $%.2f\n", finalTotal);
    printf("=======================\n");
    printf("Thank you for your order!\n");
}

int main()
{
    int choice, sizeCode, quantity, confirm;
    float price;
    char itemName[20], sizeName[15];

    printf("Welcome to the Coffee Shop!\n");

    do
    {
        displayMenu();
        printf("\nEnter item code (0 to checkout): ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        if (!isValidItem(choice))
        {
            printf("Invalid item code! Please try again.\n");
            continue;
        }

        getItemDetails(choice, itemName, &price);

        printf("Size codes: 1 = Small, 2 = Regular, 3 = Large, 4 = Extra Large\n");
        printf("Enter size code: ");
        scanf("%d", &sizeCode);

        if (!isValidSize(sizeCode))
        {
            printf("Invalid size code! Please try again.\n");
            continue;
        }

        float sizeMultiplier;
        getSizeDetails(sizeCode, sizeName, &sizeMultiplier);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        float total = price * sizeMultiplier * quantity;

        printf("\nOrder Summary: \n");
        printf("Item: %s\n", itemName);
        printf("Size: %s\n", sizeName);
        printf("Quantity: %d\n", quantity);
        printf("Total: $%.2f\n", total);

        printf("Confirm order? (1 = Yes, 2 = No): ");
        scanf("%d", &confirm);

        if (confirm == 1)
        {
            orders[orderCount].itemCode = choice;
            strcpy(orders[orderCount].itemName, itemName);
            strcpy(orders[orderCount].size, sizeName);
            orders[orderCount].quantity = quantity;
            orders[orderCount].price = price;
            orders[orderCount].total = total;
            orderCount++;

            printf("Item added to your order!\n");
        }
        else
        {
            printf("Order cancelled.\n");
        }
    } while (1);

    if (orderCount > 0)
    {
        int loyaltyNumber;
        printf("Enter your 4 digit loyalty number (or 0 if none): ");
        scanf("%d", &loyaltyNumber);

        printBill(loyaltyNumber);
    }
    else
    {
        printf("No items ordered. Goodbye!\n");
    }

    return 0;
}