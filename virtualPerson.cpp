//AJ
#include <iostream>
#include <vector>
class Person{

private: 
std::string fName;
std::string lName;
std::string sAddress;
int zip;
long int number;
public:
std::string getFName(){return fName;};
std::string getLName(){return lName;};
std::string getAddress(){return sAddress;};
void setfName(std::string fn){
    fName = fn;};
void setlName(std::string ln){
    lName = ln;
};
void setAddress(std::string ad){
    sAddress = ad;
};
void setZip(int z){
    zip = z;
};
void setNumber(long int n){
    number = n;
}

int getZip(){return zip;};
long int getNumber(){return number;};
virtual void display(){std::cout<<"Name: "<<fName<<" "<<lName<<" Address: "<< sAddress<< ", "<<zip<<" Number: "<<number;}

};

class Employee: public Person{
    private:
    long int ssn;
    std::string deptName;
    public:
    void setssn(long int ssnNumber){
        ssn = ssnNumber;
    }
    void setDeptName(std::string dept){
        deptName= dept;
    }
virtual void display(){std::cout<<"Name: "<<getFName()<<" "<<getLName()<<" Address: "<< getAddress()<< ", "<<getZip()<<" Number: "<<getNumber()<<" SSN: "<<ssn<<" Department: "<< deptName;}

};

class Customer: public Person{
    private:
    float discountPercentage;
    std::string email;
    public:
    std::string getEmail(){
        return email;
    }
    float getDiscount(){return discountPercentage;}
    void setEmail(std::string email){
        this->email = email;
    }
    void setDis(float d){
        discountPercentage = d;
    }

virtual void display(){std::cout<<"Name: "<<getFName()<<" "<<getLName()<<" Address: "<< getAddress()<< ", "<<getZip()<<" Number: "<<getNumber()<<" Discount: "<<discountPercentage<<" Email: "<< email;}
};
void displayPerson(Person&  aPerson);
int main() {
    std::vector<Person*> allPerson;
    int choice;
     do{
    std::cout<<"Press 1 for Employee and 2 for Customer or 0 to quit:\t";
    std::cin>>choice;

  while  (std::cin.fail() || choice>2 || choice <0)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 0-2\n";
           std::cin >> choice;}
          
            std::string fName, lName, sAddress, email,deptName;
            float discountPercentage; 
            int zip;
            long int ssn,number;
            if (choice ==1 || choice ==2){
            std::cout<<"\nInput First Name: ";
            fflush(stdin);
            getline(std::cin, fName);
            std::cout<<"\nInput Last Name: ";
            fflush(stdin);
            getline(std::cin, lName);
            std::cout<<"\nInput Street Address: ";
            fflush(stdin);
            getline(std::cin, sAddress);
            std::cout<<"\nInput Zip: ";
            std::cin>>zip;
            std::cout<<"\nInput Number: ";
            std::cin>>number;
           }
    if (choice ==1){
            std::cout<<"\nInput SSN: ";
            std::cin>>ssn;
            std::cout<<"\nInput Department Name: ";
            fflush(stdin);
            getline(std::cin, deptName);
             Employee* aEmployee = new Employee();
            aEmployee->setfName(fName);
            aEmployee->setlName(lName);
            aEmployee->setAddress(sAddress);
            aEmployee->setZip(zip);
            aEmployee->setDeptName(deptName);
            aEmployee->setssn(ssn);
            aEmployee->setNumber(number);

            allPerson.push_back(aEmployee);



    }
    else if (choice == 2){
            std::cout<<"\nInput Discount Percentage: ";
            std::cin>>discountPercentage;
            std::cout<<"\nInput Email: ";
            fflush(stdin);
            getline(std::cin, email);
//    Customer aCustomer; wont work
            Customer* aCustomer = new Customer();
            aCustomer->setfName(fName);
            aCustomer->setlName(lName);
            aCustomer->setAddress(sAddress);
            aCustomer->setZip(zip);
            aCustomer->setDis(discountPercentage);
            aCustomer->setEmail(email);
            aCustomer->setNumber(number);

            allPerson.push_back(aCustomer);

    }

           }while(choice != 0);
    for (Person* aPerson : allPerson){
        displayPerson(*aPerson);
    }
//would add delete later 
    return 0;
}



void displayPerson(Person&  aPerson){
    aPerson.display();
}