//AJ
#include <iostream>
#include <vector>
#include <iomanip>


// Overload the << operator to display the pizza ordered formatting two decimal places for the price.  


class Pizza{
          friend  std::ostream& operator<<(std::ostream& out,  Pizza& aPizza);

private:
    std::string size;
    std::string type;
    std::vector<std::string> toppings;
    double price;
    void calcPrice(){
        if (size == "Small"){price = 10;}
        else if(size == "Medium"){price = 14;}
        else{price = 17;}
        price += toppings.size()*2;
    }
    public:
    Pizza(std::string s, std::string t, std::vector<std::string> to){
        size = s;
        type = t;
        toppings = to;
        calcPrice();
    }
    std::string getSize(){return size;}
    std::string getType(){return type;}
    std::vector<std::string> getToppings(){return toppings;}
    double getPrice(){return price;}
    
};

class DeliveredPizza :public Pizza{
    friend         std::ostream& operator<<(std::ostream& out,  DeliveredPizza& aPizza);
  private:
  double deliveryFee;
  double totalPrice;
  std::string address;
  public:
  DeliveredPizza(std::string a,std::string s, std::string t, std::vector<std::string> to):Pizza(s, t, to){
    address = a;
    if (getPrice() > 20) {
        deliveryFee = 3.5;

    }
    else{
        deliveryFee = 5;
    }
    totalPrice = getPrice() + deliveryFee;
  }

};

int main(){
    std::string toppings[6]={  "Pepperoni", "Mushrooms", "Onions", "Green Pepper", "Tomatoes", "Jalapenos"}, size, type;
    std::vector<std::string> toppingsChoices;
    int choice;

    std::cout<<"What size pizza would you like to order?\n1- small\n2- medium\n3- large\n-------> ";
    std::cin>>choice;
    while  (std::cin.fail() || choice>3 || choice <1)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 1-3\n";
           std::cin >> choice;}
    switch(choice){

        case 1:
        size = "Small";
        break;
        case 2:
        size = "Medium";
        break;
        case 3:
        size = "Large";
        break;
        
    }
    std::cout<<"What type of crust would you like to order?\n1- classic\n2- deep dish\n3- thin crust\n-------> ";
    std::cin>>choice;
    while  (std::cin.fail() || choice>3 || choice <1)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 1-3\n";
           std::cin >> choice;}
    switch(choice){

        case 1:
        type = "Classic";
        break;
        case 2:
        type = "Deep Dish";
        break;
        case 3:
        type = "Thin Crust";
        break;
        
    }
    do{
    std::cout<<"Choose from the following toppings or 0 to quit\n1: Pepperoni\n2: Mushrooms\n3: Onions\n4: Green Pepper\n5: Tomatoes\n6: Jalapenos\n-------> ";
    std::cin>>choice;
    while  (std::cin.fail() || choice>6 || choice <0)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 0-6\n";
           std::cin >> choice;}
    if (choice!=0){
    toppingsChoices.push_back(toppings[choice-1]);
    }
    }while(choice != 0);
    std::cout<<"\nWould you like 1 - pick up or 2 - delivery?     ";
    std::cin>>choice;
    while  (std::cin.fail() || choice>2 || choice <1)
       {
           
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           std::cout << "Invalid Input, Please use number characters or number in range of 1-2\n";
           std::cin >> choice;}
    if (choice ==1){
        Pizza aPizza(size, type, toppingsChoices);
        std::cout<<aPizza;
    }
    else{
        std::string address;
        fflush(stdin);
        std::cout<<"Enter address: ";
        std::getline(std::cin, address);
        DeliveredPizza aPizza(address,size, type, toppingsChoices);
        std::cout<<aPizza<<"\nDelivered to: "<<address;
        
    }


    return 0;

}


        std::ostream& operator<<(std::ostream& out,  Pizza& aPizza){
    // out<<"You ordered a "<<aPizza.size<< " "<<aPizza.type<< " with "<<aPizza.getToppings()<<"\nPizza Price: $"<<aPizza.getPrice();
            std::string toppings = "";

    for (std::string oneTopping : aPizza.getToppings()){
        toppings += oneTopping;
        toppings += " ";
    }
            out << std::fixed << std::setprecision(2);

        out<<"You ordered a "<<aPizza.getSize()<< " "<<aPizza.getType()<< " with " << toppings << "\nPizza Price: $"<<aPizza.getPrice();


    return out;
}
        std::ostream& operator<<(std::ostream& out,  DeliveredPizza& aPizza){
    // out<<"You ordered a "<<aPizza.size<< " "<<aPizza.type<< " with "<<aPizza.getToppings()<<"\nPizza Price: $"<<aPizza.getPrice();
            std::string toppings = "";

    for (std::string oneTopping : aPizza.getToppings()){
        toppings += oneTopping;
        toppings += " ";
    }
            out << std::fixed << std::setprecision(2);
        out<<"You ordered a "<<aPizza.getSize()<< " "<<aPizza.getType()<< " with " << toppings << "\nPizza Price: $"<<aPizza.getPrice()<<"\nDelivery Fee: $"<<aPizza.deliveryFee<<"\n"<<"Total Price: $"<<aPizza.totalPrice;
        

    return out;
}

// std::ostream& operator<<(std::ostream& out,  DeliveredPizza& aPizza){
//     // out<<"You ordered a "<<aPizza.size<< " "<<aPizza.type<< " with "<<aPizza.getToppings()<<"\nPizza Price: $"<<aPizza.getPrice();
//         // out<<"You ordered a "<<aPizza.size<< " "<<aPizza.type<< " with \nPizza Price: $"<<aPizza.getPrice();

//     return out;
// }

