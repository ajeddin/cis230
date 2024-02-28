//Abdulaziz Jamaleddin
//Kim M
//Retail Class Assignment
#include <stdlib.h>  

#include <iostream>
#include <iomanip>
#include  <stdio.h>
const int MAX_ITEMS = 20;

class RetailItem{
private:
std::string description;
int unitsOnHand;
double price;
int reorderQuantity;
public:
RetailItem(){ //Default
    this->description="";
    this->unitsOnHand=0;
    this->price=0.00;
    this->reorderQuantity=0;
}
RetailItem(std::string description, int unitsOnHand, double price, int reOrderQuantity){
    this->description=description;
    this->unitsOnHand=unitsOnHand;
    this->price=price;
    this->reorderQuantity=reOrderQuantity;
}

//Setters
void setDesc(std::string description){this->description=description;}
void setUnits(int unitsOnHand){this->unitsOnHand=unitsOnHand;}
void setPrice(double price){this->price=price;}
void setReorderQuant(int reorderQuantity){this->reorderQuantity=reorderQuantity;}
//getters
std::string getDesc(){return description;}
int getUnits(){return unitsOnHand;}
double getPrice(){return price;}
int getReOrdQuant(){return reorderQuantity;}};








void addToInventory(RetailItem Inventroy[], int& itemsTotal);
void displayInventory(RetailItem Inventroy[], int& itemCount);
void checkItemInInventory(RetailItem Inventroy[], int& itemCount);
void checkIfItemNeedReOrder(RetailItem Inventroy[], int& itemCount);
void updateItemInInventory(RetailItem Inventroy[], int& itemCount);





int main(){
    int menuChoice,itemsTotal = 0; 

    RetailItem myItemsArray[MAX_ITEMS];
do{
    std::cout<<"1) Add an item to inventory\n2) Display all items in inventory\n3) Check to see if an item is in inventory.\n4) Display only those items that need to be re-ordered\n5) Update an item in inventory\n0) Exit Program\n";
    std::cin>>menuChoice;
    while  (std::cin.fail() || menuChoice<0 || menuChoice>5 )
    {
        if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> menuChoice;}
        if(menuChoice<1 || menuChoice>5){
        std::cout << "1-5 Only\n";
        std::cin >> menuChoice;

    }

    }
    switch (menuChoice)

{
    case 1: 
    addToInventory(myItemsArray, itemsTotal);
break;

    case 2:
    
displayInventory(myItemsArray,itemsTotal);

    break;
    case 3:
    checkItemInInventory(myItemsArray, itemsTotal);
break;
    case 4:
      checkIfItemNeedReOrder(myItemsArray, itemsTotal);
    break;
    case 5 : 
    updateItemInInventory(myItemsArray, itemsTotal);
    break;
    
}
// system("clear");
  
}while ((menuChoice !=0));


    return 0;
}


void addToInventory(RetailItem Inventroy[], int& itemsTotal){
    if (itemsTotal < MAX_ITEMS){
    int  unitsOnHand,reOrderQuantity;
    std::string description;
    double price;
    std::cout<<"Enter the Product's Description: ";
    fflush(stdin);
        std::getline(std::cin,description); 

    std::cout<<"Enter the Product's Price: ";
    std::cin>>price;

      while  (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> price;}
    std::cout<<"Enter the Product's Units On Hand: ";
    std::cin>>unitsOnHand;
          while  (std::cin.fail())
    {   
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> unitsOnHand;}
    std::cout<<"Enter the Product's ReOrder Quanity: ";
    std::cin>>reOrderQuantity;
    
          while  (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> reOrderQuantity;}
    RetailItem item(description, unitsOnHand, price, reOrderQuantity);
    Inventroy[itemsTotal] = item;
    itemsTotal++;
    }
    else{
        std::cout<<"Reached Max Inventory Capacity";
    }
}

void displayInventory(RetailItem Inventroy[], int& itemCount){
    for(int x = 0; x<itemCount; x++){
        std::cout<<"Product Name: " << Inventroy[x].getDesc()<<"\t" << Inventroy[x].getUnits()<<std::endl;        
    };
}

void checkItemInInventory(RetailItem Inventroy[], int& itemCount){
    std::string searchInput;
    std::cout<<"Please input what item you are looking for: (case-sensative)\t";
    std::cin>>searchInput;
    for(int x = 0; x<itemCount; x++){
        if( Inventroy[x].getDesc() == searchInput){
    std::cout<<"Match Found\nItem in inventory\n";

}else{
    std::cout<<"Match not Found\nItem not in inventory\n";


}
    }
}

void checkIfItemNeedReOrder(RetailItem Inventroy[], int& itemCount){
    int reOrder =0;
for(int x = 0; x<itemCount; x++)
{
    if(Inventroy[x].getReOrdQuant() > Inventroy[x].getUnits())
    {
    std::cout<<"\nItem: " << Inventroy[x].getDesc()<<"\t" << Inventroy[x].getUnits()<< " needs to be reordered\n";
    reOrder++;
    }
    
}
if(reOrder==0){
    std::cout<<"No Items need reorder\n";
}
}

void updateItemInInventory(RetailItem Inventroy[], int& itemCount){
  std::string searchInput;
  int choice; 
    std::cout<<"Please input what item you are looking to update: (case-sensative)\t";
fflush(stdin);
        std::getline(std::cin,searchInput); 
             int  unitsOnHand,reOrderQuantity;
    std::string description;
    double price;
    for(int x = 0; x<itemCount; x++){
        if( Inventroy[x].getDesc() == searchInput){
    
        std::cout<<"For Item: "<< Inventroy[x].getDesc()<<"\nWhat do you want to update:\n1)Descritpion\n2)Price\n3)Reorder Quantity\n4)Units\n";
        std::cin>>choice;
        switch (choice){
            case 1:
           std::cout<<"Update the Description " ;
fflush(stdin);
        std::getline(std::cin,description); 
        Inventroy[x].setDesc(description);
break;
            case 2:
            std::cout<<"Update the Price ";

        std::cin>>price;
                Inventroy[x].setPrice(price);

break;

            case 3:
            std::cout<<"Update the ReOrder Quantity ";
        std::cin>>reOrderQuantity;
                Inventroy[x].setReorderQuant(reOrderQuantity);

break;

            case 4:
            std::cout<<"Update the Units ";
        std::cin>>unitsOnHand;
        Inventroy[x].setUnits(unitsOnHand);
        break;


        }
}else{
    std::cout<<"Match not Found\nItem not in inventory\n";


}
    }

};