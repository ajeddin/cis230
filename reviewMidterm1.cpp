//AJ
//Kim M 
// Midterm 
 #include <iostream>
#include <cstdlib>
class AccountHolder{
private:
std::string name; 
std::string  address; 
std::string city; 
std::string  state; 
long int socialSecurity;
int creditScore; 
int zip; 
public:
AccountHolder(std::string name, std::string address, std::string city, std::string state, int zip , long int socialSecurity){
this->name = name;
this->address = address;
this->city = city;
this->state = state; 
this->zip = zip;
this->socialSecurity = socialSecurity;
creditScore = 0;
}
int getCreditScore(){
    creditScore =  rand() % 550 + 350;
    return creditScore;

}
std::string getNameAddress(){
    return "Name: " + name + " Address: " + address +", "+city +", "+state + ", " + std::to_string(zip); 
}

};

class Transaction{
    private:
    std::string date;
    std::string desc;
    int amount;
    public:
    Transaction(){};
    int getAmount(){
        return amount;
    }
    void inputTransation(){
        std::cout<<"\n Enter date";
        getline(std::cin,date );
        std::cout<<"\n Enter desc";
        getline(std::cin,desc );
        std::cout<<"\n Enter amount";
        std::cin>>amount;
    }
    std::string display(){

        std::cout<<date <<" "<<desc<<amount; 
    }
};
class CreditCard{
    
    private:
     long int accountNumber;
    AccountHolder accountHolder;
    double creditlimit;
    int balance;
    float interestPercentage; 
    std::vector<Transaction> monthlyTransactions;
    // int newAccountNumber;
    static long int newAccountNumber;
    public:

    CreditCard(std::string name, std::string address, std::string city, std::string state, int zip , long int socialSecurity):accountHolder(name, address, city, state, zip, socialSecurity)
    
    {
int creditScore = accountHolder.getCreditScore();
if(creditScore <580){
    std::cout<<"Denied Credit";
    accountNumber = 0;
}else{
    std::cout<<"Approved Credit";
    accountNumber = newAccountNumber;
    newAccountNumber++;
    if(creditScore){
        
    }
    if(creditScore){
        
    }
    if(creditScore){
        
    }

}
    }



};
long int CreditCard::newAccountNumber = 100200;

 int main(){

    AccountHolder aPerson("AJ","833 Robin", "Dearborn" , "Michigan", 68293, 3909399323);
    std::cout<<aPerson.getNameAddress();

    return 0;
 }