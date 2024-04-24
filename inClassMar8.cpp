#include <iostream>

class Parent{
    private:
        int num1;
    public:
    Parent(int x = 2){
        num1 = x;
    }

    virtual int getNum(){return num1;};
    virtual void twistIt(){
        num1 *=3;
    }
    int getTwist(){
        twistIt();
        return getNum();
    }
};
class Child: public Parent{
    private:
    int num2;
    public:
    Child(int x=5){
        num2=x;
    }
int getNum(){return num2;}
 virtual void twistIt(){
        num2 *=10;
    }




};

int main(){

Parent kim;
Child judy;
std::cout<<"\nParent: "<<kim.getNum();
std::cout<<"\nChild: "<<judy.getNum();
std::cout<<"\nChild: "<<judy.Parent::getNum();
std::cout<<"\nChild: "<<judy.Parent::getNum();

std::cout<<"\nChild: "<<judy.getTwist();





    return 0;

}

// void displayNumber(Parent& x);