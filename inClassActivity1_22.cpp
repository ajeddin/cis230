//Abdulaziz Jamaleddin 1 Person Group
//Kim M. 
//In Class Activity
#include<iostream>
void getData(int choices[],int &windowShelves);
int calculateCost(int choices[],int windowShelves);
int calculateCost(int choices[]);

int main(){
int choices[3] ,windowShelves,total;

getData(choices,windowShelves);
if (choices[2]==1){
total = calculateCost(choices,windowShelves);
}
else{
total = calculateCost(choices);
}
std::cout<<"\nTotal is: "<<total;




    return 0;
}
int calculateCost(int choices[],int windowShelves){
    int total=0;
// std::cout<<"\n\n\n\n\n\n" <<choices[0]<<"\n";
switch (choices[0]){
    case 1:
total=230;
    break;

    case 2:
total=190;
    break;

    case 3:
total=150;
    break;

}
total += choices[1]*55;
total += windowShelves*45;
return total;
}
int calculateCost(int choices[]){

    int total=0;
    // std::cout<<"\n\n\n\n\n\n" <<choices[0]<<"\n\n\n\n\n\n";

switch (choices[0]){
    case 1:
total=230;
    break;

    case 2:
total=190;
    break;

    case 3:
total=150;
    break;

}
// std::cout<<total;
total += choices[1]*55;
return total;
}

void getData(int choices[],int &windowShelves){
    std::cout<<"What type of wood would you prefer\n 1.Mahogany\t2.Oak\t3.Pine"<<std::endl;
    std::cin>>choices[0];
        // std::cout<<"\n\n\n\n\n\n" <<choices[0]<<"\n";

    std::cout<<"How many shelves would you like? "<<std::endl;
    std::cin>>choices[1];
    std::cout<<"\nWould you like to have glass windowed doors\n1.Yes\t2.No"<<std::endl;
    std::cin>>choices[2];
    if (choices[2]==1){
    std::cout<<"\nHow many windowed doors would you like? \n"<<std::endl;
    std::cin>>windowShelves;
    while (windowShelves>choices[1]){
        std::cout<<"Invalid Input: Cannot have more doors than shelves\n";
        std::cin>>windowShelves;
    }

    }
    
}