
#include <iostream>
int main(){
int qty =10;
int *qPtr = &qty;
std::cout<<"\nQty: "<<qty;

 *qPtr = 22;
std::cout<<"\nQty: "<<qty<<std::endl;

float amt=1.99, price=2.99;
float  * const amtPtr = &amt;

std::cout<<"\nAmt: "<<amt<<std::endl;
// amtPtr=&amt;
std::cout<<"\nAmt: "<<*amtPtr<<std::endl;
// amtPtr= &price;
std::cout<<"\nAmt: "<<*amtPtr<<std::endl;
*amtPtr= 4.99;




return 0;
}