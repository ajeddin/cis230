#include <iostream>
#include <string>
int sum(int x);
int main(){
 int num; 
 std::cout<<"Enter a Number: ";
 std::cin>>num;
 std::cout<<"sum of the number is "<<sum(num);


    return 0;

}

int sum(int x){
  
    if (x>0){
        return x + sum(x-1);
    }
    else{
        return 0;
    }
}