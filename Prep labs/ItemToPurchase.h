//  ItemToPurchase.h
//  Prep labs

#ifndef ItemToPurchase_h
#define ItemToPurchase_h

#include <stdio.h>
#include <string>

using namespace std;

class ItemToPurchase{
public:
    
    ItemToPurchase();
    
    void SetName(string newName);
    void SetPrice(double newPrice);
    void SetQuantity(int newQuantity);
    
    string GetName() const;
    double GetPrice() const;
    int GetQuantity() const;
    
    
    
    
private:
    string itemName;
    double itemPrice;
    int itemQuantity;
};


#endif  /*ItemToPurchase_h */
