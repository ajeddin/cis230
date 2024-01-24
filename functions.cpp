//Abdulaziz Jamaleddin
//Kim M
#include <iostream>
int compute(int num1, int num2);
void computePointer(int num1, int num2,int *answer);
float compute(float num1, float num2);
int computeAgain(int x,int y,int z=1); //default values
void getData(int *num1, int *num2);
void getDataReferences(int &num1, int &num2);
int main(){

int num1 = 10,num2=5;
float num1F = 10.4, num2F=5.4;
int answer;
//getData(&num1,&num2);//using pointers
getDataReferences(num1,num2);//using references
answer = compute(num1,num2);
std::cout<<"\nThe first compute is: "<<answer<<std::endl;
computePointer(num1,num2,&answer);
std::cout<<"\nThe first compute using pointer is: "<<answer<<std::endl;
answer = compute(num1F,num2F);

std::cout<<"\nThe first compute using pointer is: "<<answer<<std::endl;
answer = computeAgain(num1,num2);

std::cout<<"\nThe Last compute using pointer is: "<<answer<<std::endl;







    return 0; 
}

void getData(int *num1, int *num2){

std::cout<<"Enter 2 Num";
std::cin>>*num1>>*num2;


}
void getDataReferences(int &num1, int &num2){

std::cout<<"Enter 2 Num";
std::cin>>num1>>num2;


}

int computeAgain(int x,int y,int z){
return x*y*z;
}

int compute(int num1, int num2){
    return num1*num2;
}
void computePointer(int num1, int num2,int *answer){
    *answer =  num1 * num2;
}
float compute(float num1, float num2){
    return num1*num2;
}