#include <iostream>
class Employee{
    private:
    std::string name; 
    int idNumber;
    long int hireDate;//yyyymmdd


    public:
    Employee(std::string name, int idNumber, long int hireDate){
        std::cout<<"\nCreating an employee!\n";
        this->name = name;
        this-> idNumber = idNumber;
        this->hireDate = hireDate;
    }
    void displayData(){

        std::cout<<"Worker Name: "<<name<<" ID Number: "<< idNumber<< " Hire Date: "<<hireDate;
    }



};
class ProductionWorker: public Employee{
    private: 
        int shift;
        float hourlyRate;
    public:
        ProductionWorker(std::string name, int idNumber, long int hireDate, int shift, float hourlyRate):Employee(name,idNumber,hireDate){
            std::cout<<"\nCreating a production Worker\n";
            this->shift = shift;
            this->hourlyRate = hourlyRate;
        }
        void displayData(){
         std::cout<<"\nProduction Worker\n";

            Employee::displayData();
            std::cout<<" Shift: "<<shift<<" Hourly Rate: "<<hourlyRate;
        }

};
class ShiftSupervisor: public Employee{
private:
float salary;
float bonus;
public:
    ShiftSupervisor(std::string name, int idNumber, long int hireDate, float salary, float bonus):Employee(name,idNumber,hireDate){
                    std::cout<<"\nCreating a Shift Supervisor!\n";
                    this->salary= salary;
                    this->bonus= bonus;

    }
     void displayData(){
            std::cout<<"\nShift Supervisor\n";

            Employee::displayData();
            std::cout<<" Salary: "<<salary<<" Bonus: "<<bonus<<"\n";
        }
};
class TeamLead : public ProductionWorker{
    private: 
        int requiredHours;
        float bonus;
    public:
    TeamLead(std::string name, int idNumber, long int hireDate, int shift, float hourlyRate, int requiredHours, float bonus):ProductionWorker(name, idNumber, hireDate, shift, hourlyRate){
        std::cout<<"\nCreating a Team Lead!\n";

        this->requiredHours = requiredHours;
        this->bonus = bonus;
    }
    void displayData(){
            std::cout<<"\nTeam Lead\n";
            ProductionWorker::displayData();
            std::cout<<" Required Hours: "<<requiredHours<<" Bonus: "<<bonus<<"\n";
        }
};


int main(){
ProductionWorker aPerson("Joe", 23212, 20230313, 2, 32.3);
ShiftSupervisor aSupervisor("Jacob", 32342, 20240313, 2392.9,0);
TeamLead aTeamLead("Joey", 32424,23329889, 3, 54.4, 50, 43943.3);
aPerson.displayData();
aSupervisor.displayData();
aTeamLead.displayData();







    return 0;
}