//Abdulaziz jamaleddin
//Kim M
//Monday 1/22/24
#include <iostream>

int main(){

        std::string  name;
        char initial;

        int num1 = 54, num2=9;
        float answer = num1/num2; //=0

        answer = static_cast<float>(num1)/num2; //c++ way
        answer = (float)num1 / num2;

        std::cout<<answer<<std::endl;

        std::cout<<"\n char cast...."<<(char)num1;

        std::string first = "Abdul", last = "Jamal";
        name = first + " "+last+"\n";
        std::cout<< name;



        std::cout<<"Enter Name: ";
        // std::cin>>name; //Bad idea to use this for string as space messes it up. 
        std::getline(std::cin,name); 
        std::cout<<"Enter First Initial: ";
        std::cin>>initial;
        std::cout<<"Your name is: " <<name<<" and your first initial is: "<<initial;

        // std::cin>>num1>>num2;
        int age = 22;
        if (age>=18){
            std::cout<<"\nAdult\n";
        }else{
            std::cout<<"\nNot Adult\n";

        }

        std::cout<<((age >= 18) ? "\nAdult" : "\nChild"); //() for presedence
        






    return 0;
}