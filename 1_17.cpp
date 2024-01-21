#include <iostream>
#include <iomanip>
//using namespace std; //general Namespace // not good usage

//for c <cstdio>
//AJ
int main(){
    int num1 = 10,num2 =  20; 
    std::cout <<"Num 1 is "<< num1<<std::endl<<"Num 2 is "<< num2<<std::endl;

    bool isHungry = true;
    std::cout<<"Am I hungry? "<<isHungry<<std::endl;
int a, b , c , d;
a=b=c=d=0;
std::cout<<a<<std::endl;
std::cout<<b<<std::endl;
std::cout<<c<<std::endl;
std::cout<<d<<std::endl;

float number = 22.224332F; //adding f makes it a string literal float
std::cout<<std::setprecision(1)<<std::fixed;
std::cout<<number;
{
    int a = 99;

}
std::string greeting;

// char oldString[10];
greeting = "Hey!";
int age = 12;
if (age >=18 )
{
    std::cout<< "Adult";

}else{
    std::cout<<"Child";
}
std::cout<<((age>=18) ? "\nAdult":"\nChild");




    return 0; 
}