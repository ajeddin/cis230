#include <iostream>




class Animal {

public: 
 virtual std::string says(){
    return "????";
}

};
class Dog: public Animal {

public: 
std::string says(){
    return "woof woof";
}

};
class Cat: public Animal {

public: 
std::string says(){
    return "meow meow";
}

};

int main(){

    // Dog *d = new Dog();
    // std::cout<<d->says();

    Animal *a = new Dog();
    std::cout<<a->says();
    a = new Cat();
    // a=c;

    std::cout<<a->says();



    return 0;
}