#include <iostream>
#include <set>
#include <vector>



int main(){
    std::set<std::string> setOfNumbers;
    setOfNumbers.insert("First");
    setOfNumbers.insert("Second");
    setOfNumbers.insert("Second");
    setOfNumbers.insert("Third");
    setOfNumbers.insert("Fourth");
    std::cout<<"\nThe size of my set is "<<setOfNumbers.size();
    // std::cout<<setOfNumbers;
    for (std::string aNumber : setOfNumbers){
        std::cout<<aNumber;
        std::cout<<"\n";
        }
    std::set<std::string>::iterator it;
    // std::vector<std::string>::iterator 
    for (it =setOfNumbers.begin(); it!=setOfNumbers.end();++it){
        std::cout<<*it;

    }


    return 0;
}