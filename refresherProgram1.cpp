//RefresherProgram 1 - Parking Garage
//Abdulaziz Jamaleddin 
//Kim M. 
#include <iostream>
using namespace std;
#include <iomanip>

int main(){
    cout << "Welcome to Detroit Parking Meter\nUse this app to calculate the parking fee for one day\n";
            char choice;

    do {
    float totalTimeParked, parkingFee;
    cout << "How many hours did you park for?\n";
    cin >> totalTimeParked;
    while  (cin.fail())

    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Invalid Input, Please use number characters\n";
    cout << "How many hours did you park for?\n";
    cin >> totalTimeParked;

    }
    while (totalTimeParked>24 || totalTimeParked <=0){
        if (totalTimeParked>24){
    cout << "Car cannot be parked for more than 24 hours\n";}
      if (totalTimeParked<=0){
    cout << "Car cannot be parked for less than 0 hours\n";}
    
    cout << "How many hours did you park for?\n";
    cin >> totalTimeParked;
     while  (cin.fail())

    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Invalid Input, Please use number characters\n";
    cout << "How many hours did you park for?\n";
    cin >> totalTimeParked;

    }
    }
    if (totalTimeParked<=3){ 
        parkingFee = 2.50;

    }else{
        parkingFee = ((floor(totalTimeParked)-3)*1)+2.50;
        //  if (floor(totalTimeParked)==totalTimeParked){ //trying both ways i researched
         if (fmod(totalTimeParked, 1) != 0){
               
parkingFee+=1;

        }
if (parkingFee>20.0){
    parkingFee = 20.0;
}


}
std::cout<<std::setprecision(2)<<std::fixed;

   cout << "The parking fee is $" << parkingFee;
//    printf("%.2f", parkingFee);

cout << "\nWould you like to calculate another parking fee\n";
cin >> choice;
    
    }
    while (choice=='y'|| choice=='Y'); //will incorperate full validatioin for sentinal variables and will not use namespace for later project (or try to)


cout << "Thanks for using Detroit Parking Fee Program";






    return 0;
}
