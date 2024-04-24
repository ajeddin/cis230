#include <iostream>
// int compare(double x, double y);
// int compare(std::string word1, std::string word2);
template<typename T> int compare(T x, T y);
template <class T> class Item{
    private:
    T value;
    public:
    Item(T n): value(n){}
    T getValue(){return value;};
    void display(){
        std::cout<<"\n"<<value<<"\n";
    }

};
int main(){
    double x=5.7, y=6.2;
    std::string word1= "horse", word2= "shoe";
    if (compare(x,y)>0){
        std::cout<<x<<" is great than "<<y;
    }
    else if (compare(x,y)<0){
        std::cout<<y<<" is great than "<<x;

    }
    else{
        std::cout<<"The equal";
    }
      if (compare(word1,word2)>0){
        std::cout<<word1<<" is great than "<<word2;
    }
    else if (compare(x,y)<0){
        std::cout<<word2<<" is great than "<<word1;

    }
    else{
        std::cout<<"The equal";
    }
Item<std::string> myItem("Food");
myItem.display();

}
// int compare(double x, double y){
//     if (x == y){
//         std::cout<<x;
//         return -1;
//     }
//     return x > y;
// }
// int compare(std::string word1, std::string word2){
//     if (word1 == word2){
//         return -1;
//     }
//     return word1 > word2;
// }

template<typename T> int compare(T x, T y) {
    if (x == y) {
        return 0;
    }
    return (x > y) ? 1 : -1;
}