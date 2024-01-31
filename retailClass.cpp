//Abdulaziz Jamaleddin
//Kim M
//Retail Class Assignment

#include <iostream>
#include <iomanip>


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
int getReOrdQuant(){return reorderQuantity;}








};



int main(){
    int menuChoice;

    std::cout<<"1) Add an item to inventory\n2) Display all items in inventory\n3) Check to see if an item is in inventory.\n4) Display only those items that need to be re-ordered\n5) Update an item in inventory";
    std::cin>>menuChoice;
    while  (std::cin.fail() || menuChoice<1 || menuChoice>5 )
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




    return 0;
}