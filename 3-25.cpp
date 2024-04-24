//MON MAR 25 2024
#include <iostream>
#include <cstdlib>
#include <ctime>

class Player{
private:
    std::string name;
    int number;
    int wins;
    int losses;
public:
    Player(std::string n){
        name = n;
        number = 0;
        wins =0;
        losses = 0;
    }
    int getNum(){return number;}
   void setNum(int x){number = x;}
   std::string getName() {return name;}
   virtual void chooseNumber()=0;
};
class Human :public Player{

    public:
    Human(std::string n):Player(n){}
    void chooseNumber(){
        int num;
        std::cout<<"Enter a number 1-100:\t";
        std::cin>>num;
        setNum(num);
        

    }
};


class Computer: public Player{
    public:
    Computer():Player("Joshua"){ }
    void chooseNumber(){
        srand(time(0));
        setNum((rand() % 100)+1);

    }
};

void playGame(Player& p1, Player& p2);


int main(){
    std::string name;
    char again;
    int players;

    std::cout<<"Shall we play a game? ";
    std::cin>>again;
    while (again == 'y' || again =='Y'){
        std::cout<<"\nHow many player 1 or 2? ";
        std::cin>>players;
        fflush(stdin);
        if (players ==1){
            std::cout<<"Enter you name: ";
            getline(std::cin, name);
            Human aHuman(name);
            Computer aComputer;
            playGame(aHuman,aComputer );
        }
        else{
            std::cout<<"Enter player 1 name: ";
            getline(std::cin, name);
            Human playerOneHuman(name);
            std::cout<<"Enter player 2 name: ";
            getline(std::cin, name);
            Human playerTwoHuman(name);
            playGame(playerOneHuman,playerTwoHuman);

        }

    }
//     std::cout<<"Enter you name: ";
//     getline(std::cin, name);
//     Human aHuman(name);
//    std::cout<<aHuman.getName()<<"\n";
//    std::cout<<aComputer.getName();
    
    return 0;
}

void playGame(Player& p1, Player& p2){
    p1.chooseNumber();
    p2.chooseNumber();
    std::cout<<p1.getName()<<p1.getNum()<<std::endl;
   std::cout<<p2.getName()<<p2.getNum()<<std::endl;
}