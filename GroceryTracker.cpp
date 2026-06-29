#include "GroceryTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

// Reads grocery items from the input file and tracks frequencies
void GroceryTracker::LoadFile(string fileName) {
    ifstream inputFile(fileName);
    string item;

    if (!inputFile) {
        cout << "Error: Could not open input file." << endl;
        return;
    }

    while (inputFile >> item) {
        bool found = false;

        // Check whether the item already exists in the collection
        for (unsigned int i = 0; i < groceryItems.size(); i++) {
            if (groceryItems[i].GetName() == item) {
                groceryItems[i].IncrementQuantity();
                found = true;
                break;
            }
        }

        // Add a new grocery item if it was not previously found
        if (!found) {
            GroceryItem newItem(item);
            groceryItems.push_back(newItem);
        }
    }

    inputFile.close();
}

// Creates frequency.dat backup file
void GroceryTracker::CreateBackupFile() {
    ofstream outputFile("frequency.dat");

    if (!outputFile) {
        cout << "Error: Could not create frequency.dat." << endl;
        return;
    }

    for (unsigned int i = 0; i < groceryItems.size(); i++) {
        outputFile << groceryItems[i].GetName()
            << " "
            << groceryItems[i].GetQuantity()
            << endl;
    }

    outputFile.close();
}

// Searches for a specific grocery item and returns its frequency
int GroceryTracker::SearchItem(string itemName) {
    for (unsigned int i = 0; i < groceryItems.size(); i++) {
        if (groceryItems[i].GetName() == itemName) {
            return groceryItems[i].GetQuantity();
        }
    }

    return 0;
}

// Displays all grocery items and their frequencies
void GroceryTracker::PrintAllItems() {
    for (unsigned int i = 0; i < groceryItems.size(); i++) {
        cout << groceryItems[i].GetName()
            << " "
            << groceryItems[i].GetQuantity()
            << endl;
    }
}

// Displays grocery frequencies as a text-based histogram
void GroceryTracker::PrintHistogram() {
    for (unsigned int i = 0; i < groceryItems.size(); i++) {
        cout << groceryItems[i].GetName() << " ";

        // Print one asterisk for each purchase
        for (int j = 0; j < groceryItems[i].GetQuantity(); j++) {
            cout << "*";
        }

        cout << endl;
    }
}

// Displays the program menu
void GroceryTracker::DisplayMenu() {
    cout << endl;
    cout << "Corner Grocer Menu" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print histogram" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice: ";
}