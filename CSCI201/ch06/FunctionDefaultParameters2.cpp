// compile with: g++ FunctionDefaultParameters2.cpp -o FunctionDefaultParameters2.exe
// run: ./FunctionDefaultParameters2.exe

#include <iostream>
using namespace std;

// --- RULE 3: Global variable and function used for defaults ---
int globalDefault = 100;

int getDefaultPrice()
{
    return 50;
}

// --- RULE 1 & 3: Default parameters are on the RIGHTMOST side ---
// 'quantity' defaults to a constant (1)
// 'tax' defaults to a global variable (globalDefault, which is 100)
// 'discount' defaults to a function call result (50)
void displayOrder(string itemName, int quantity = 1, int tax = globalDefault, int discount = getDefaultPrice())
{
    cout << "Item: " << itemName
         << " | Qty: " << quantity
         << " | Tax: " << tax
         << " | Discount: " << discount << endl;
}

// --- RULE 4: Reference parameters vs Constants ---
// ILLEGAL: void changeValue(int &num = 10) -> Compiler error! 10 has no memory address.
void changeValue(const int &num = 10)
{ // LEGAL: Adding 'const' allows literal defaults
    cout << "Reference value: " << num << endl;
}

int main()
{
    cout << "--- DEFAULT PARAMETER TEST ---" << endl;

    // 1. Pass everything explicitly
    displayOrder("Laptop", 2, 15, 20);

    // 2. Omit the last argument ('discount' will use its default function call)
    displayOrder("Phone", 3, 12);

    // 3. RULE 2: Omit 'tax'. Because we omitted 'tax',
    //    we MUST also omit 'discount' (everything to its right).
    displayOrder("Book");

    // Testing our const reference default
    changeValue();

    return 0;
}