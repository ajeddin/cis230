//Abdulaziz Jamaleddin
//Kim M
//Pizza Program
#include <iostream>
class Pizza{
private:
std::string type;
std::string size;
int toppings;
public:
Pizza(std::string typeChoice,std::string sizeChoice, int toppings){
type = typeChoice;
size= sizeChoice;
this->toppings = toppings;
}
void setType(std::string typeChoice){type = typeChoice;}
void setSize(std::string sizeChoice){size= sizeChoice;}
void setToppings(int toppings){this->toppings = toppings;}
std::string getType(){return type;}
std::string getSize(){return size;}
int getToppings(){return toppings;}
void getDesc(){std::cout<<size<<" "<<type<<" pizza with "<< toppings<<  " toppings"<<std::endl;}
int calcPrice(){
    float total =0;
    total += (toppings*2);
    if (size == "small"){total += 10;}
    else if (size == "medium"){total += 14;}
    else{total += 17;}
    // std::cout<<total;
    return total;
}};
class Order{
    private:
    std::vector<Pizza> allPizza;
    std::string customerName;
    long int phoneNumber;
    public:
    Order(std::string customerName, long int phoneNumber){
        this->customerName = customerName;
        this->phoneNumber = phoneNumber;
    }
    void addPizza(Pizza aPizza){
        allPizza.push_back(aPizza);
    }
    void outPutFullOrder(){
        int total=0; 
        std::cout<<"Customer Name: "<<customerName<< " Number: " << phoneNumber<<std::endl; 
        for (Pizza onePizza: allPizza){
            onePizza.getDesc();
            std::cout<<"Price: "<<onePizza.calcPrice()<<std::endl;

            total += onePizza.calcPrice();

        }
        std::cout<<"Total Price: "<<total;
    }
};




int main(){
    std::string typePizza[3]= {"deep dish", "hand tossed", "pan"};
    std::string sizePizza[3]= {"small", "medium", "large"};
        std::cout<<"Welcome to AJ Pizza\n";
    char continueChoice;
    do{
        std::string name;
        long int number;
        int typeChoice,sizeChoice,toppings;
        std::cout<<"Please input your name: ";
        fflush(stdin);
        std::getline(std::cin, name);
        fflush(stdin);
        std::cout<<"\nPlease input your number: ";
        std::cin>>number;
               while  (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> number;}
        Order aPizza(name, number);
        char donePizza;
        do{

        std::cout<<"\nWhat type of pizza do you want\n1)Deep Dish\n2)Hand Tossed\n3)Pan \n";
        std::cin>>typeChoice;
           while  (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> typeChoice;}
        std::cout<<"\nWhat size of pizza do you want\n1)Small\n2)Medium\n3)Large\n";
        std::cin>>sizeChoice;
           while  (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> sizeChoice;}
        std::cout<<"\nHow many toppings would you like to add: ";
        std::cin>>toppings;
           while  (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input, Please use number characters\n";
        std::cin >> toppings;}
        aPizza.addPizza(Pizza(typePizza[typeChoice-1],sizePizza[sizeChoice-1],toppings));
        std::cout<<"\nAdd pizza to order: (Y/N)\t";
        std::cin>>donePizza;
        std::cout<<donePizza;
        }while(donePizza!='N' && donePizza!='n');
        aPizza.outPutFullOrder();

        std::cout<<"\nWould you like to start another order: (Y/N)\t";
        std::cin>>continueChoice;

    }
    while(continueChoice!='N' && continueChoice!='n');
    std::cout<<"Thanks for visiting AJ Pizza"<<std::endl;

    return 0;
}
