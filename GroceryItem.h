#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>

using namespace std;

class GroceryItem {
private:
    string itemName;
    int quantity;

public:
    GroceryItem();
    GroceryItem(string name);

    string GetName() const;
    int GetQuantity() const;

    void IncrementQuantity();
};

#endif
