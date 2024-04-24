//AJ
#include <iostream>
#include <vector>

class Student {
    friend std::ostream& operator<<(std::ostream& out, const Student& aJob);
private:
std::string fName;
std::string lName;
int grade;
float totalFees;
public:
Student(std::string first, std::string last, int grade){
    fName = first;
    lName = last;
    this->grade = grade;
    totalFees = 0;
}
// Student(int grade) : grade(grade);

void operator+=(float fee){
totalFees +=fee;
}
bool operator==(std::string lName){
    return this->lName == lName;
}
bool operator==(int grade){
        return this->grade == grade;
}


};

class Athlete{
    friend std::ostream& operator<<(std::ostream& out, const Athlete& aAthlete);

    private:
        std::string fName;
        std::string lName;
        std::string sportName;
        static float athleteFee;
    public:
    Athlete(std::string first, std::string last, std::string sport){
        fName = first;
        lName = last;
        sportName = sport;

    }
    bool operator==(std::string sport){
        return sportName==sport;
    }
    static float getFee(){return athleteFee;}
};
float Athlete::athleteFee = 125.5;
void displayMenu();
void addStudent(std::vector<Student>& allStudent, std::vector<Athlete>& allAthlete);
void displayStudents(std::vector<Student> allStudents);
void displayOneStudent(std::vector<Student> allStudents);
void displayAthletes(std::vector<Athlete> allAthletes);
void displayStudentByGrade(std::vector<Student> allStudents);
void displayStudentBySport(std::vector<Athlete> allAthlete);



int main(){
std::vector<Athlete> allAthletes;
std::vector<Student> allStudents;
int choice;

do{
    displayMenu();
std::cin>>choice;
  while  (std::cin.fail() || choice>7 || choice <1)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 1-7\n";
           std::cin >> choice;}

        switch (choice)
        {
        case 1:
        addStudent(allStudents,allAthletes);
            break;
        
        case 2:
            displayStudents(allStudents);
            break;
        
        case 3:
            displayOneStudent(allStudents);
            break;
        
        case 4:
            displayAthletes(allAthletes);
            break;
        
        case 5:
            displayStudentByGrade(allStudents);
            break;
        
        case 6:
            displayStudentBySport(allAthletes);
            break;
        
        case 7:
           std::cout<<"Bye Bye\n";
            break;
        
       
        };
}while(choice !=7);
 return 0;

    
}
void displayMenu(){
    std::cout<<"Please choose from the following menu\n";
    std::cout<<"1: Add student\n";
    std::cout<<"2: Print a list of enrolled students\n";
    std::cout<<"3: Print a list of students by last name\n";
    std::cout<<"4: Print a list of students who play sports\n";
    std::cout<<"5: Print a list of students by grade\n";
    std::cout<<"6: Print a list of students by sport\n";
    std::cout<<"7: Exit program \n";
}

std::ostream& operator<<(std::ostream& out, const Student& aStudent){
    out<<"Grade: "<<aStudent.grade<<" Student Name: "<<aStudent.fName <<" "<< aStudent.lName<< " Total Fees: $"<<aStudent.totalFees<<std::endl;
    return out;
}
std::ostream& operator<<(std::ostream& out, const Athlete& aAthlete){
    out<<"Sport: "<<aAthlete.sportName<<" Athlete Name: "<<aAthlete.fName <<" "<< aAthlete.lName<< std::endl;
    return out;
}

void addStudent(std::vector<Student>& allStudent, std::vector<Athlete>& allAthlete){

std::string firstName, lastName;
char sport;
int choice;
fflush(stdin);

std::cout<<"\nWhat is your first name: ";
std::getline(std::cin, firstName);
fflush(stdin);

std::cout<<"\nWhat is your last name: ";
std::getline(std::cin, lastName);

std::cout<<"\nWhat is your grade level: ";
std::cin>>choice;

  while  (std::cin.fail() || choice>12 || choice <9)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 9-12\n";
           std::cin >> choice;}
           std::string sportChoice;
std::cout<<"\nDo you play a sport?\t";
std::cin>>sport;
while (sport!= 'n' && sport != 'y' ){
    std::cin.clear();

    fflush(stdin);

     std::cout << "\nPlease use y/n!!\n";
    std::cin >> sport;}
char moreChoice;
int fee = 0;
fflush(stdin);

if (sport == 'y'){
    
    do{
        
    std::cout<<"What sport do you play?\n";
    std::getline(std::cin, sportChoice);
    fflush(stdin);
Athlete aAthlete(firstName, lastName, sportChoice);
    allAthlete.push_back(aAthlete);
    // fee += Athlete::athleteFee;
    fee += aAthlete.getFee();
    
    std::cout<<"\nAdd another sport?\n";
        std::cin >> moreChoice;
        while (moreChoice!= 'n' && moreChoice != 'y' ){
    std::cin.clear();

    fflush(stdin);
     std::cout << "\nPlease use y/n!!\n";
    std::cin >> moreChoice;}

    }while (moreChoice != 'N' && moreChoice != 'n');
    
    
}
Student aStudent(firstName,lastName,choice);
aStudent+=fee;
fee = 0;
allStudent.push_back(aStudent);


}

void displayStudents(std::vector<Student> allStudents){
    for (Student aStudent : allStudents){
        std::cout<<aStudent;
    }

}
void displayOneStudent(std::vector<Student> allStudents){
    std::string inputedLastName;
    fflush(stdin);
    std::getline(std::cin, inputedLastName);
for (Student aStudent : allStudents){
    if (aStudent == inputedLastName){
        std::cout<<aStudent;
    }

    }
}

void displayAthletes(std::vector<Athlete> allAthletes){
    for (Athlete aAthlete : allAthletes){
        std::cout<<aAthlete;
    }

}

void displayStudentByGrade(std::vector<Student> allStudents){
    int gradeChoice;
    std::cout<<"What grade do you want to be displayed?\t";
    std::cin>>gradeChoice;
    for (Student aStudent : allStudents){
    if (aStudent == gradeChoice){
        std::cout<<aStudent;
    }

    }
}


void displayStudentBySport(std::vector<Athlete> allAthlete){
    std::string sportChoice;
     fflush(stdin);
    std::getline(std::cin, sportChoice);
    for (Athlete aAthlete : allAthlete){
    if (aAthlete == sportChoice){
        std::cout<<aAthlete;
    }

    }
}