#include <iostream>
//#include <string>
#include <iomanip>
#include <vector>

class Date{
private:
    int month;
    int day;
    int year;
public:
    Date(int month, int day, int year){
        this-> month = month;
        this-> day = day;
        this->year=year;
        
    }
    std::string displayDate(){
        return std::to_string(month) + "/"+std::to_string(day) +"/"+std::to_string(year);
    }
};
class Hotel{
private:
    std::string hotel;
    int  cost;
public:
    Hotel(){
        
    };
    Hotel(std::string hotel, int  cost){
        this->hotel = hotel;
        this->cost = cost;
        
    }
    std::string displayHotel(){
        return "$ "+ std::to_string(cost) +" (per night) " + hotel;
    }
    int getCost(){
        return cost;
    }
};
class Attraction{
private:
    std::string name;
    float cost;
public:
    Attraction(std::string name, float cost){
        this-> name = name;
        this-> cost = cost;
    }
    void displayAttraction(){
//        std::cout<<std::setprecision(2)<<std::fixed;

        std::cout<<"$ "<<std::setprecision(2)<<std::fixed<<cost<< "\t"<<name<<std::endl;
    }
    float getCost(){
        return cost;
    }
    
};
class Trip{
private:
    Date startDate;
    Date endDate;
    std::string destinationName;
    Hotel chosenHotel;
    std::vector<Attraction> allAttractions;
    float totalCost;
    int totalPeople;
public:
    Trip(std::string destinationName, int totalPeople, int startMonth, int startDay, int startYear, int endMonth, int endDay, int endYear):startDate(startMonth, startDay, startYear),endDate(endMonth, endDay, endYear){
        this->destinationName = destinationName;
        this->totalPeople = totalPeople;
    }
    void setHotel(Hotel aHotel){
        chosenHotel = aHotel;
    }
    void addAttraction(Attraction aAttraction){
        allAttractions.push_back(aAttraction);
    }
    void calculateCost(){
        int total =0;
        total +=chosenHotel.getCost()*5;
        2(Attraction aAttraction: allAttractions){
            total+=aAttraction.getCost()*float(totalPeople);
            
        }
        totalCost =total;
    }
    void displayTrip(){
        std::cout<<"Your trip to "<<destinationName<<" for "<<totalPeople<<"\n";
        std::cout<<"Date Leaving: "<<startDate.displayDate()<<std::endl;
        
        std::cout<<"Date Returning: "<<endDate.displayDate()<<std::endl;
        std::cout<<"Staying at "<< chosenHotel.displayHotel()<<std::endl;
;
        std::cout<<"Selected Attractions:\n";
        for(Attraction aAttraction: allAttractions){
            aAttraction.displayAttraction();
            std::cout<<"\n";
        }
        std::cout<<"Total cost of trip: $ "<<std::setprecision(2)<<std::fixed<<totalCost<<std::endl;


    }
};
std::string selectDestination();
Hotel selectHotel();
void selectAttractions(Trip &aTrip);






int main(){
    std::string destinationChoice;
    Hotel selectedHotel;
    destinationChoice = selectDestination();
    int startMonth, startDay, startYear, endMonth, endDay, endYear, totalPeople;
    
    std::cout<<"Enter date of arrival to "<<destinationChoice<<": MM DD YYYY ";
    std::cin>>startMonth>>startDay>>startYear;
    std::cout<<"\nEnter date of departure from "<<destinationChoice<<": MM DD YYYY ";
    std::cin>>endMonth>>endDay>>endYear;
    std::cout<<"\nHow many poeple are going on the trip: ";
    std::cin>>totalPeople;
    Trip aTrip(destinationChoice, totalPeople, startMonth, startDay, startYear, endMonth, endDay, endYear);
    selectedHotel = selectHotel();
    aTrip.setHotel(selectedHotel);
    selectAttractions(aTrip);
    aTrip.calculateCost();
    aTrip.displayTrip();
    return 0;
}








std::string selectDestination(){
    
    std::string selection;
    std::vector <std::string> destinationCities {"Mackinaw Island", "Holland", "Traverse City", "Houghton"};
    std::cout<<"Please choose a city:\n";
    for(int x =0;x<4;x++){
        std::cout<<destinationCities[x]<<"\n";
        
    }
    std::cout<<"------->  ";
    fflush(stdin);
    std::getline(std::cin,selection);
    return selection;
    
};

Hotel selectHotel(){
    Hotel allHotels[4] = { Hotel("Hilton Garden Inn",164),
     Hotel("Quality Inn and Suites",105),
     Hotel("Holiday Inn",139),
     Hotel("Marriott", 152)
                             };
    std::cout<<"Choose a hotel:\n";
    int choice;
    for(int x =0;x<4;x++){
        std::cout<<x+1 << ": "<< allHotels[x].displayHotel()<<std::endl;
           }
    std::cout<<"---------->  ";
    std::cin>>choice;
    while  (std::cin.fail() || choice>4 || choice <1)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 1-4\n";
           std::cin >> choice;}
    return allHotels[choice-1];
    

};
void selectAttractions(Trip &aTrip){
    char addMore;
    std::cout<<"Would you like to add an attraction? Y/N ";
    std::cin>>addMore;

    while(addMore != 'N' && addMore != 'n'){
        int choice;
        Attraction allAttractions[8] = {
            Attraction("Zoo",16.50),
            Attraction("Historical Museum",10.50),
            Attraction("Stadium",139.00),
            Attraction("River Boat", 152.00),
            Attraction("Theater", 131.22),
            Attraction("Science Center", 12.95),
            Attraction("Art Museum", 14.50),
            Attraction("Amusement Park", 52.75)
        };
        
        
        for (int x = 0;x<8;x++){
            std::cout<<x+1<<" : ";
            allAttractions[x].displayAttraction();
        }
        std::cin>>choice;
        aTrip.addAttraction(allAttractions[choice-1]);
        std::cout<<"Would you like to add another attraction? Y/N ";
        std::cin>>addMore;

    }
};


