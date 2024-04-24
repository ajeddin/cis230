#include <iostream>


class Pet {
    public:
    std::string name;
    virtual void print()
{
    std::cout<<"\nName ONLY: "<<name;
}


};






class Dog : public Pet {
    public:
 std::string breed;
 virtual void print(){

    std::cout<<"\nName:   " << name;
    std::cout<<"\tBreed:   " << breed;

 }




};


int main(){

    Dog vDog;
    Pet vPet;

    vDog.name = "Strider";
    vDog.breed = "Boarder Collie";
    vDog.print();
     
    vPet = vDog;
    vPet.print();


    Dog vDog2;

    // vDog2 = vPet; Not Alloweed
    // vDog2.print();
//When working with Inheritance and objects use poiners or refrences
Pet *myPet;
Dog *myDog;

    myDog = new Dog;
    myDog->name = "Cookie";
    myDog->breed = "Golden Retriever";
    myDog->print();

    myPet= myDog;
    myPet->print();


        std::cout<<"\n"<<myPet<<" - "<<myDog;
    return 0;
}