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

};



int main(){





    return 0; 
}