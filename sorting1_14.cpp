#include <iostream>
const int MAXARRAY= 5;
class Stack{
    private: 
    // std::vector<int> number;
    int arr[MAXARRAY];
    int counter;
    public:
    Stack(){
        this->counter = 0;
    }
    void push(int number){
        if (counter >= MAXARRAY){
            std::cout<<"Reached Max\n";
        }
        else{
            arr[counter]= number;
            std::cout<<"Added Number\n";
            counter++;

        };
    }
    void pop(){
        std::cout<<"\n Cleared\n";
        arr[counter] = 0;
        counter--;
    }
    void getArr(){
        for (int x = 0;x<counter;x++){
            std::cout<<arr[x]<<"\n";
        }
    }

};




int main(){
Stack myStack;
myStack.push(5);
myStack.push(6);
myStack.push(6);
myStack.push(6);
myStack.push(6);
myStack.push(6);
myStack.getArr();
myStack.pop();
myStack.getArr();



    return 0;
}