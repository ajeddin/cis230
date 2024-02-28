//Abdulaziz Jamaleddin
//Kim M
//Composition // Aggregation .. 
#include <iostream>


class Person{
    private:
    std::string firstName;
    std::string lastName;
    public:
    Person(std::string firstName, std::string lastName){
        this->firstName = firstName;
        this->lastName = lastName;
    }
    std::string showPerson(){
        return firstName + " " + lastName;
    }

}; //END PERSON CLASS
class InventoryItem{
    private:
        int stockNumber;
        float price;
    public:
        InventoryItem(int stockNumber, float price){
            this->stockNumber = stockNumber;
            this->price = price;
        }
        InventoryItem(int stockNumber, float price):stockNumber(stockNumber),price(price){} //initialization list way
    std::string showItem(){
        return "Stock #: " + std::to_string(stockNumber) + "\nPrice $" + std::to_string(price);
    }
};//END OF INVENTORYITEM
class Transaction{
    private:
    int transactionNumber;
    Person seller;
    InventoryItem item;
    public:
    Transaction(std::string firstName, std::string lastName, int stockNumber, float price, int transactionNumber): //initialization list
    seller(firstName,lastName),item(stockNumber,price) {
        this->transactionNumber = transactionNumber;
        // this-> seller = Person(firstName,lastName);
        // this-> item = 


    }
    void showTransaction(){
std::cout<<"\nTransaction Number: " << transactionNumber;
std::cout<<"\nSeller : " << seller.showPerson();
std::cout<<"\nItem : " << item.showItem();

    }






};

int main(){

Person salesPerson("Joe","King");
std::cout<<salesPerson.showPerson()<<std::endl;
InventoryItem wrench(290219, 20.4);
std::cout<<wrench.showItem();

Transaction oneTransaction("Joe","King",1232,23.2,323);
oneTransaction.showTransaction();

    return 0; 
}