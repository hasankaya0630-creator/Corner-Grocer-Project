#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

// Main program entry point
int main() {
    GroceryTracker tracker;
    int choice;
    string itemName;

    // Load grocery data and create backup file
    tracker.LoadFile("CS210_Project_Three_Input_File.txt");
    tracker.CreateBackupFile();

    do {
        tracker.DisplayMenu();
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number from 1 to 4: ";
            cin >> choice;
        }

        // Process user menu selection
        switch (choice) {
        case 1:
            cout << "Enter the item name: ";
            cin >> itemName;

            cout << itemName << " appears "
                << tracker.SearchItem(itemName)
                << " time(s)." << endl;
            break;

        case 2:
            tracker.PrintAllItems();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
