//Abdulaziz Jamaleddin
//KIM M
//IN CLASS Friends Activity 

#include <iostream>
class SalesPerson;
class Sale {
    friend void displayAgain(Sale aSale, SalesPerson aPerson);

    private: 
    int month; 
    int day; 
    int year; 
    double amount; 
    int idNum;
    public:
    Sale(int month, int day, int year, double amount, int idNum){
        this->month = month;
        this->day = day;
        this->year = year;
        this->amount = amount;
        this->idNum = idNum;
    }
    std::string displaySale(){
        return std::to_string(month) + "/" + std::to_string(day) +"/"+ std::to_string(year)+ "\n$" + std::to_string(amount) +"\t ID: " + std::to_string(idNum);
    }
};


class SalesPerson

{
    friend void displayAgain(Sale aSale, SalesPerson aPerson);

private:
    int idNum;
    std::string name;
public:
SalesPerson(int idNum, std::string name){
    this->idNum = idNum;
    this->name = name;
}
 std::string displaySale(){
        return "Name: " + name +"\t ID: " + std::to_string(idNum);
    }

};
void displayAgain(Sale aSale, SalesPerson aPerson);
void display(Sale aSale, SalesPerson aPerson);

int main(){

Sale aSale(2, 20, 2024, 657.87, 1234);
// std::cout<<aSale.displaySale()<<std::endl;
SalesPerson aPerson(1234,"Kanye");
// std::cout<<aPerson.displaySale()<<std::endl;
// display(aSale, aPerson);
displayAgain(aSale, aPerson);

    return 0; 
}

void display(Sale aSale, SalesPerson aPerson){
std::cout<<aSale.displaySale()<<"\n"<<aPerson.displaySale()<<std::endl;

}
void displayAgain(Sale aSale, SalesPerson aPerson){
// std::cout<<aSale.displaySale()<<"\n"<<aPerson.displaySale()<<std::endl;
std::cout<<aSale.month<<"/"<<aSale.day<<"/"<<aSale.year;
std::cout<<"$"<<aSale.idNum << "\t$: " << aSale.amount;
std::cout<<"\n " <<aPerson.name;

}