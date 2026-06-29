#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <vector>
#include <string>
#include "GroceryItem.h"

using namespace std;

class GroceryTracker {
private:
    vector<GroceryItem> groceryItems;

public:
    void LoadFile(string fileName);

    void CreateBackupFile();

    int SearchItem(string itemName);

    void PrintAllItems();

    void PrintHistogram();

    void DisplayMenu();
};

#endif
