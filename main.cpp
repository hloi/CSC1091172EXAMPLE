#include <iostream>
#include <vector>
#include <string>
using namespace std;

const unsigned int MAX_ITEMS_IN_SHOPPING_BAG = 3;

class Item {
public:
    string itemName;
    int priceDollars;
};

// sum of the bag
int sumBag(vector<Item> bag) {
    int sum = 0;
    for (size_t i = 0; i<bag.size(); i++) {
        sum += bag.at(i).priceDollars;
    }
    return sum;
}

// update the bag with the new bag
void updateBag(vector<Item>& curBag, vector<Item>& newBag) {
    for (size_t i = 0; i<curBag.size(); i++) {
        newBag.at(i).itemName = curBag.at(i).itemName;
        newBag.at(i).priceDollars = curBag.at(i).priceDollars;
    }
}

// modify the ShoppingBagCombination to return the lowest and highest values of the items.
void ShoppingBagCombination(vector<Item> currBag, vector<Item> remainingItem, vector<Item>& minBag) {
    int bagValue;
    Item tmpGroceryItem;
    unsigned int i;

    if (currBag.size() == MAX_ITEMS_IN_SHOPPING_BAG) {
        bagValue = 0;
        int sum1 = sumBag(currBag);
        int sum2 = sumBag(minBag);
        if (sum1 < sum2) {
            updateBag(currBag, minBag);
        }
        for (i=0; i<currBag.size(); i++) {
            bagValue += currBag.at(i).priceDollars;
            cout << currBag.at(i).itemName << " ";
        }
        cout << "= $" << bagValue << endl;
    }
    else {
        for (i=0; i<remainingItem.size(); i++) {
            tmpGroceryItem = remainingItem.at(i);
            remainingItem.erase(remainingItem.begin()+i);
            currBag.push_back(tmpGroceryItem);
            ShoppingBagCombination(currBag, remainingItem, minBag);
            remainingItem.insert(remainingItem.begin()+i, tmpGroceryItem);
            currBag.pop_back();

        }
    }



}




int main() {
    vector<Item> possibleItems(0);
    vector<Item> shoppingBag(0);
    vector<Item> minBag(0);  // minBag
    Item tmpGroceryItem;
    tmpGroceryItem.itemName = "Milk";
    tmpGroceryItem.priceDollars = 2;
    possibleItems.push_back(tmpGroceryItem);
    minBag.push_back(tmpGroceryItem);

    tmpGroceryItem.itemName = "Belt";
    tmpGroceryItem.priceDollars = 24;
    possibleItems.push_back(tmpGroceryItem);
    minBag.push_back(tmpGroceryItem);

    tmpGroceryItem.itemName = "Toys";
    tmpGroceryItem.priceDollars = 19;
    possibleItems.push_back(tmpGroceryItem);
    minBag.push_back(tmpGroceryItem);

    tmpGroceryItem.itemName = "Cups";
    tmpGroceryItem.priceDollars = 12;
    possibleItems.push_back(tmpGroceryItem);

    ShoppingBagCombination(shoppingBag, possibleItems, minBag);

    cout << "least value bag: " << endl;
    int bagValue = 0;
    for (size_t i=0; i<minBag.size(); i++) {
        bagValue += minBag.at(i).priceDollars;
        cout << minBag.at(i).itemName << " ";
    }
    cout << " $" << bagValue << endl;
    cout << endl;
    return 0;
}
