//  ItemToPurchase.cpp
//  Prep labs

#include <string>
#include "ItemToPurchase.h"

using namespace std;

/***************************************************** default constructor ************************************/
ItemToPurchase::ItemToPurchase(){
    itemName = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
    
    return;
}

/***************************************************** Set functions ************************************/
void ItemToPurchase::SetName(string nameSet){
    itemName = nameSet;
    
    return;
}

void ItemToPurchase::SetPrice(double priceSet){
    itemPrice = priceSet;
    
    return;
}

void ItemToPurchase::SetQuantity(int quantitySet){
    itemQuantity = quantitySet;
    
    return;
}

/***************************************************** Get functions ************************************/

string ItemToPurchase::GetName() const{
    
    return itemName;
}

double ItemToPurchase::GetPrice() const{
    
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const{
    
    return itemQuantity;
}



