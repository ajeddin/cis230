//Abdulaziz Jamaleddin



#include <iostream>
#include <vector>
class Person{
    private: 
    std::string name;
    int id;
    public:
    Person (std::string name, int id){
        this->name = name;
        this->id = id;
    }
    void display(){
        std::cout<<name<< "ID: "<< id;
    }
};




int main(){

// std::vector<int>temps;
// // temps[0] = 22;


// // std::cout<<temps[0];

// // for (int oneTemp : temps){
// //     std::cout<<oneTemp<< " ";

// // }
// std::cout<<"\n The size is : "<<temps.size();
// //temps[0] = 33
// int oneTemp;
// std::cout<<"Enter a temperature ";
// std::cin>>oneTemp;
// while (oneTemp != 999){
//     temps.push_back(oneTemp);
// std::cout<<"\n The size is : "<<temps.size()<<"and The capacity is   "<<temps.capacity();
// std::cout<<"Enter a temperature ";
// std::cin>>oneTemp;
// }
// // for (int oneTemp : temps){
// //     std::cout<<oneTemp<< " ";

// // }
// // temps.pop_back();
// for (int& oneTemp : temps){
//     oneTemp+=5;
//     std::cout<<oneTemp<< " ";

// } 
// for (int x = 0;x<10;x++){
//     std::cout<<"\n Element " <<x << temps[x];
// }



std::vector<Person> students;
Person studentA("Taylor" , 1111);
Person studentB("Taylor" , 1111);
students.push_back(studentA);
students.push_back(studentB);
for (Person onePerson : students){
    onePerson.display();
}


    return 0;
}