#include "GroceryItem.h"

// Default constructor
GroceryItem::GroceryItem() {
    itemName = "";
    quantity = 0;
}

// Constructor that initializes a grocery item
GroceryItem::GroceryItem(string name) {
    itemName = name;
    quantity = 1;
}

// Returns the item name
string GroceryItem::GetName() const {
    return itemName;
}

// Returns the quantity purchased
int GroceryItem::GetQuantity() const {
    return quantity;
}

// Increases the quantity by one
void GroceryItem::IncrementQuantity() {
    quantity++;
}