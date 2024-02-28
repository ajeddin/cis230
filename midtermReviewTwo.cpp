//Abdulaziz Jamaleddin
//Kim M
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// •    Contains private data for movie name, the rating (e.g., PG, PG-13), and a vector to hold the show times (as strings).
// •    Include both a default constructor; and a non-default constructor that accepts all data as parameters and assigns appropriately.
// •    A display movie function that will display a movies name and rating.
// •    A display show times function that will use a range based for loop to display all of the available show times.
// •    An accessor function that will return the movie name.

class Movie{
    private:
    std::string name;
    std::string rating;
    std::vector<std::string> times;
    public:
    Movie(){}
    Movie(std::string name, std::string rating, std::vector<std::string> times){
        this->name = name;
        this->rating = rating;
        this->times = times;
    }
    void display(){std::cout<<"Movie Name: "<<name<<" Rating: "<<rating<<std::endl;}
    std::string getName(){return name;}
    void displayTimes(){
        for (std::string oneTime :times){
            std::cout<<oneTime<<std::endl;
        }
    }

};
class Ticket{
    private:
    int age;
    float price;
    Movie selectedMovie;
    std::string time;
    bool matinee;
    public:
    Ticket(Movie selectedMovie, std::string time)
    
    {
        this->selectedMovie = selectedMovie;
        this-> time = time;
        price = 0;
        matinee = false;
    }
    void setAge(int age){this->age = age; }
    std::string getTime(){return time;}
    std::string getName(){return selectedMovie.getName();}
    float getPrice(){return price;}
    void calcPrice(){
        char timeHour = time.at(0);
        if (timeHour < '5'){
            matinee = 1;
            price = 5.5;
        }
        else{
            if (12<age || age>= 65){
                price = 7.0;
            }
            else{
                price = 10.50;
            }
        }

    }

    
};

class Order{

    private:
    float totalDue;
    std::vector<Ticket> tickets;
    public:
    Order(std::vector<Ticket> tickets){
        this->tickets = tickets;
        totalDue = 0;

    }
    float getTotalDue(){return totalDue;}
    void calcPrice(){
        for(Ticket oneTicket: tickets){
            totalDue += oneTicket.getPrice();
        }

    }
    void display(){
        std::cout<<"You have selected "<<tickets.size()<< " tickets to see "<<tickets.at(0).getName() << " with a start time of " <<tickets.at(0).getTime() <<std::endl;
    }
};

void loadMovieChoice(std::vector<Movie> &movies);
int selectMovie(std::vector<Movie> movies);
std::string startTimeChoice(Movie aMovie);
Ticket purchaseTicket(Movie aMovie, std::string selectedTime, int counter);


int main (){
std::setprecision(5);
char userChoice;
float totalDue=0;
int totalTickets= 0;
do{
std::vector<Movie> allMovies;
std::vector<Ticket> allTickets;
int choice, ticketAmount;
std::string selectedTime;

loadMovieChoice(allMovies);
std::cout<<"Welcome to Meet Me at the Movies Theater!\n";
choice = selectMovie(allMovies);
selectedTime = startTimeChoice(allMovies.at(choice));
std::cout<<"How many tickets would you like to order: ";
std::cin>>ticketAmount;
for (int x = 0; x<ticketAmount;x++){
    allTickets.push_back( purchaseTicket(allMovies.at(choice), selectedTime, x+1));


}
totalTickets += allTickets.size();

Order oneOrder(allTickets);
oneOrder.display();
oneOrder.calcPrice();
totalDue += oneOrder.getTotalDue();
std::cout<<"Total Ticket Price: $"<<oneOrder.getTotalDue();
std::cout<<"\nIs there another customer? Y/N\t";
std::cin>>userChoice;

}while(userChoice!='N');
std::cout<<"Daily Sales Summary: \nTotal Tickets Sold:\t"<<totalTickets<<"\n"<<"Total Sales Amount:\t$"<<totalDue;



    return 0;
}


void loadMovieChoice(std::vector<Movie> &movies){
    std::vector<std::string> pgTimes({"12:00 PM","2:30 PM","4:00 PM","6:30 PM","8:00 PM" });
    std::vector<std::string> pgThirteen{"1:30 PM","3:00 PM","5:30 PM","7:00 PM","9:30 PM"};
    std::vector<std::string> moviesNames{"Ant-Man and the Wasp","80 for Brady","MEGAN","Avatar: The way of water","Lego Movie","Space Jam"};
    std::vector<std::string> ratings{"(PG-13)","(PG-13)","(PG-13)","(PG-13)","(PG)","(PG)"};
    for (int x = 0; x<6;x++){
        if(ratings.at(x)=="(PG-13)"){
        movies.push_back(Movie(moviesNames.at(x), ratings.at(x), pgThirteen));

        }
        else{
        movies.push_back(Movie(moviesNames.at(x), ratings.at(x), pgTimes));

        }}
}
int selectMovie(std::vector<Movie> movies){
    
    int counter = 1,choice;
    std::cout<<"Please choose what movie you would like to see: \n";
//    std::cout<<movies.size();
    for(Movie oneMovie: movies){
        //NUMBER BASE
        std::cout<<counter++<<": ";
        oneMovie.display();

    }
    std::cin>>choice;
    while (0>choice || choice>6){
        std::cout<<"Invalid Input\n Try Again: ";
        std::cin>>choice;

    }
    return choice-1;
}
std::string startTimeChoice(Movie aMovie){
    std::string selectedTime;
    std::cout<<"Please select time:\n";
    aMovie.displayTimes();
    fflush(stdin);

    std::getline(std::cin, selectedTime);
    return selectedTime;
}
Ticket purchaseTicket(Movie aMovie, std::string selectedTime, int counter){
    int age;
    std::cout<<"Enter the age for ticket" << counter<<": ";
    std::cin>>age;
    
     Ticket aTicket(aMovie, selectedTime);
     aTicket.setAge(age);
    aTicket.calcPrice();
    return aTicket;
}
