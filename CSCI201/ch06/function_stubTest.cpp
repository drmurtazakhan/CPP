// compile with: g++ function_stubTest.cpp -o function_stubTest.exe
// run: ./function_stubTest.exe
#include <iostream>
using namespace std;

// --- FUNCTION PROTOTYPES ---
double calculateTax(double price);
double calculateTotal(double price);

// This entire main() block acts as a DRIVER PROGRAM
int main()
{
    cout << "--- DRIVER PROGRAM START ---" << endl;

    double testPrice = 100.0;

    // Testing calculateTotal, which internally calls our stub function
    double finalTotal = calculateTotal(testPrice);

    cout << "Test Price: $" << testPrice << endl;
    cout << "Calculated Total: $" << finalTotal << endl;

    cout << "--- DRIVER PROGRAM END ---" << endl;
    return 0;
}

// --- FUNCTION DEFINITIONS ---

// This function is fully coded, but it DEPENDS on calculateTax()
double calculateTotal(double price)
{
    // It calls calculateTax() and needs its result to proceed
    double tax = calculateTax(price);
    return price + tax;
}

// This is a FUNCTION STUB
// It is not fully coded yet, but it returns a placeholder value (5.0)
// so the compiler doesn't error out and calculateTotal() can be tested.
double calculateTax(double price)
{
    // TODO: Write actual tax calculation logic based on state laws later
    cout << "[STUB WARNING: calculateTax() is a placeholder returning a fixed $5.0 tax]" << endl;
    return 5.0;
}