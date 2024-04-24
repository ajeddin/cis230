#include <iostream>
namespace mySpace{
    void function(){
        std::cout<<"\n in my space";
    }
}

void function(int x);
int main(){
mySpace::function();
for (int x=0; x<5;x++){
    function(x);
}






    return 0;
}

void function(int x){
    static int num = 0;

    std::cout<<"\nNumber is "<<num+x;
    num++;
}