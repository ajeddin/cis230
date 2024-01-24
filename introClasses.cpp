//Abdulaziz Jamaleddin
//Kim M


#include <iostream>
// #include <cstring> 
// struct Pet
// {
//     std::string name; 
//     std::string type; 
//     int birthMonth;
//     int birthDay;
//     int birthYear;
// };
class Pet
{
    private:
    std::string name; 
    std::string type; 
    int birthMonth;
    int birthDay;
    int birthYear;

    public:
    //Constructor
Pet(std::string name){ //non default constructor
    std::cout<<"made pet with data";
    this->name = name;

}
//default constuctor
Pet(){
    std::cout<<"made pet without data";
    this->name = "Unknown";
    this->type = "Unknown";
    this->birthMonth = 0;
    this->birthDay = 0;
    this->birthYear = 0;
}



    //Mutators (set functions)
     void setName(std::string n){ name = n; } // only using same name for both
     void setType(std::string type){ this ->type = type; }
     void setBirthMonth(int birthMonth){ this ->birthMonth = birthMonth; }
     void setBirthDay(int birthDay){this -> birthDay = birthDay; }
     void setBirthYear(int birthYear){ this ->birthYear = birthYear; }
    // Accesssors (get functions)
    std::string getName(){return name;}
    std::string getType(){return type;}    
    int getBirthMonth(){return birthMonth;}
    int getBirthDay(){ return birthDay;}
    int getBirthYear(){ return birthYear;}

    //Utility Functions
    void displayPetFunction(){
std::cout<<"My pet's name is "<<name<<"\n";
std::cout<<"My pet's is a "<<type<<"\n";
std::cout<<"\n"<<"My pet is born on  "<<birthMonth<<"/"<<birthDay<<"/"<<birthYear;
    }

    std::string getString(){
        return "\n My pet's name is " +name+ "\n" + "\n" + std::to_string(birthDay) ;
    }
};//END OF PET CLASS


int main(){

/////               STRUCT WAY

//  struct Pet myPet;
//  myPet.name = "Crunch";
//  myPet.type = "Cat";
//  myPet.birthMonth = 9;
//  myPet.birthDay = 11;
//  myPet.birthYear = 2004;
// std::cout<<"My "<<myPet.type<<"'s name is "<<myPet.name<<std::endl;

/////               CLASS WAY

  Pet myPet;
  Pet yourPet("Dozer");


//  myPet.setName("Crunch");
//  yourPet.setName("Sesame");
 yourPet.setType("Cat");
 yourPet.setBirthMonth(9);
 yourPet.setBirthDay(11);
 yourPet.setBirthYear(2004);
 yourPet.displayPetFunction();
 std::string returnedString;
 returnedString = yourPet.getString();
 std::cout<<returnedString;
// yourPet.printName();
// std::cout<<"My pet's name is "<<yourPet.getName()<<"\n";
// std::cout<<"My pet's is a "<<yourPet.getType()<<"\n";
// std::cout<<"\n"<<"My pet is born on  "<<yourPet.getBirthMonth()<<"/"<<yourPet.getBirthDay()<<"/"<<yourPet.getBirthYear();
// std::cout<<"\n"<<"My pet is born on  "<<myPet.getBirthMonth()<<"/"<<myPet.getBirthDay()<<"/"<<myPet.getBirthYear();

Pet allPets[3];
allPets[0]=yourPet;
allPets[1]=myPet;
for (int x;x<3;x++){
    allPets[x].displayPetFunction();
};
std::cout<<"\nDIVIDER"<<std::endl;


for(Pet onePet : allPets){
    onePet.displayPetFunction();
};



    return 0;
}