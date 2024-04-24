#include <sstream>
#include <iostream>
int main(){
    // allVariables[static_cast<std::string> (aVar)] 
    int f = 5;
        std::ostringstream ocs;
ocs << &f;  

std::cout<<ocs.str();
std::cout<<&f;





    return 0 ;
}