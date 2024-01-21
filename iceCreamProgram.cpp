#include <iostream>
#include <iomanip>
#include <cmath>
// #include <algorithm>
//Abdulaziz Jamaleddin
//Kim M
void iceCreamScoopInputter(int iceCreamScoops[], std::string iceCreamFlavors[]);
void iceCreamReport(int iceCreamScoops[],std::string iceCreamFlavors[]);

int main(){
    std::cout<<"Welcome to Ice Cream Seller Dashboard"<<std::endl;

    std::string iceCreamFlavors[5] = {"Vanilla", "Butter Pecan", "Superman", "Chocolate Fudge", "Strawberry"};
    int iceCreamScoopsSold[5] = {0};
    iceCreamScoopInputter(iceCreamScoopsSold,iceCreamFlavors);
    iceCreamReport(iceCreamScoopsSold,iceCreamFlavors);
    
    


    return 0;
}

void iceCreamReport(int iceCreamScoops[],std::string iceCreamFlavors[]){
        
        for (int i = 0;i<5;i++){
std::cout<<iceCreamFlavors[i] <<" has " << iceCreamScoops[i] << " scoops"<<std::endl;
        }
        int minOne, minTwo, maxOne, maxTwo;

    
    //could use max() but we need position
    //     int min = iceCreamScoops[0], max = iceCreamScoops[0];
    // for (int i; i<5;i++){
    //     for (int j =0;j<5;j++){

    //     }}
   
      //  int n = sizeof(iceCreamScoops) / sizeof(iceCreamScoops[0]); //turns out there is a much easier way

      //  std::sort(iceCreamScoops, iceCreamScoops + n); // this will mess the names array order so wont work 
      minOne=maxOne =0;
    //   minOne=minTwo = -INFINITY;
    //   maxOne=maxTwo = -INFINITY;
    
    for (int x = 0;x<5;x++){ 

    //   std::cout<<"tester\n";
        if (iceCreamScoops[minOne]>iceCreamScoops[x]){
            
            minOne = x;
        }
        if (iceCreamScoops[maxOne]<iceCreamScoops[x]){
    //   std::cout<<iceCreamScoops[x]<<"Scoops \n";
    //   std::cout<<maxOne<<"before \n";
            maxOne = x;
    //   std::cout<<maxOne<<"after \n";
        }
    }
    maxTwo = minOne;
    minTwo = maxOne;
    for (int x = 0;x<5;x++){

        if (iceCreamScoops[minTwo]>iceCreamScoops[x] && x !=minOne){
            minTwo = x;
        }
        if (iceCreamScoops[maxTwo]<iceCreamScoops[x]&& x !=maxOne){
            maxTwo = x;
        }
    }
    





        std::cout<<"The 2 worst selling are "<< iceCreamFlavors[minOne]<< " with " << iceCreamScoops[minOne] << " scoops and "<< iceCreamFlavors[minTwo]<< " with " << iceCreamScoops[minTwo]<<std::endl;
        std::cout<<"The 2 best selling are "<< iceCreamFlavors[maxOne]<< " with " << iceCreamScoops[maxOne] << " scoops and "<< iceCreamFlavors[maxTwo]<< " with " << iceCreamScoops[maxTwo]<<std::endl;


}

void iceCreamScoopInputter(int iceCreamScoops[], std::string iceCreamFlavors[]){
for (int i = 0;i<5;i++){
    std::cout<<"Enter the number of "<<iceCreamFlavors[i]<<" scoops sold this month"<<std::endl;
    std::cin>>iceCreamScoops[i];
while  (std::cin.fail())

    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Invalid Input, Please use numbers\n";
    std::cout<<"Enter the number of "<<iceCreamFlavors[i]<<" scoops sold this month"<<std::endl;
    std::cin>>iceCreamScoops[i];

    }

}
}