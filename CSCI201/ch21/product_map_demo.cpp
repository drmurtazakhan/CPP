// product_map_demo.cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to print the product inventory
void displayInventory(const string& message, const map<int, string>& inventory) {
    cout << "--- " << message << " ---" << endl;
    if (inventory.empty()) {
        cout << "[Inventory is Empty]" << endl;
    }
    
    // Using the range-based loop with structured bindings for clarity
    for (auto const& [pcode, description] : inventory) {
        cout << "Product Code: " << pcode << " | Description: " << description << endl;
    }
    cout << "------------------------------------------" << endl;
}

int main() {
    // 1. Create map with initial products (pcode and description)
    map<int, string> productMap = {
        {5001, "Wireless Mouse"},
        {2005, "Mechanical Keyboard"}
    };
    displayInventory("Initial Inventory", productMap);

    // 2. Insert two more products
    productMap[3002] = "USB-C Hub";            // Using subscript operator
    productMap.insert({1001, "Gaming Monitor"}); // Using insert function
    displayInventory("After Adding New Stock", productMap);

    // 3. Delete one product by its pcode
    int codeToRemove = 2005;
    cout << "Discontinuing Product Code: " << codeToRemove << "..." << endl;
    productMap.erase(codeToRemove);
    displayInventory("After Removing Keyboard", productMap);

    // 4. Search for a specific product
    int searchCode = 3002;
    cout << "Searching for Product Code " << searchCode << "..." << endl;
    
    auto it = productMap.find(searchCode);
    if (it != productMap.end()) {
        // it->first is the pcode, it->second is the description
        cout << "The product Code (key): " << it->first << endl;
        cout << "The product Description (value): " << it->second << endl;
    } else {
        cout << "Error: Product code not found in system." << endl;
    }

    return 0;
}