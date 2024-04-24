#include <iostream>



class Shoes{
    public:
    std::string color;
    std::string style;
    float shoeSize;
    float price;
    Shoes(std::string c, std::string st, float shoe, float p){
        color = c;
        style = st;
        shoeSize = shoe;
        price = p;
        std::cout<<"\nCreating a pair of shoes\n";
    }
    ~Shoes(){ //destrucotr
        std::cout<<"\nRemoving the "<<color<<" "<< style<<" shoes from memory\n";
    }
    void display  ()const{
        std::cout<<"\nColor: "<<color<<"\nStyle: "<<style<<"\nShoe Size: "<<shoeSize<<"\nPrice: $"<<price<<std::endl;
    }


};
void displayShoes(Shoes  const *  const shoes);
    typedef Shoes* shoesPtr;
    typedef int AJINTS;
int main(){
    AJINTS one = 10;
    
    shoesPtr myPtr;
    myPtr = new Shoes("green", "slides", 3, 44.99);
    myPtr->display();
    Shoes aShoe("White", "Tennis", 11.5, 323.3);
    Shoes aSmmhoe("Whitesas", "ennis", 11.5, 323.3);
    // aShoe.display();
    // {
    Shoes myShoes("red", "slides", 8, 23.3);
    displayShoes(&aShoe);
    displayShoes(&aSmmhoe);
    displayShoes(&myShoes);
    // myShoes.display();

    // }
    displayShoes(myPtr);
    delete myPtr;
    // displayShoes(myPtr);
    


    return 0;

}

void displayShoes(Shoes  const * const shoes){
shoes->display();
}