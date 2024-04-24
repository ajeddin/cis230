#include <iostream>
#include <map>
#include <sstream> 

int main(){
    // std::map<int, int> myMap  { {1,2},{3,23},{34,43}};
    

    // for (std::map<int, int>::iterator it = myMap.begin(); it!=myMap.end();++it)
    // {
    //     std::cout<<"\n "<<it->first<<" - "<<it->second;
    // }

    std::map<std::string, int> myMapString;
    myMapString["first"] = 1;
    myMapString["second"] = 2;
    myMapString["third"] = 3;
    myMapString["four"] = 4;
    
    for (std::map<std::string, int>::iterator it = myMapString.begin(); it!=myMapString.end();++it)
    {
        std::cout<<"\n "<<it->first<<" - "<<it->second;
    }
    // myMapString["second"] = 20;
    std::cout<<"\n\n\n\nReverse\n";
    for (std::map<std::string, int>::iterator it = myMapString.end(); it!=myMapString.begin();)
    {
        it--;
        std::cout<<"\n "<<it->first<<" - "<<it->second;
    }

std::cout<<"\n\n\n";

    

    std::map<int,std::string> myMapThird {{1, "Journey"},{23, "Def Leppard"}, {3, "Queen"}};
    std::cout<<myMapThird[23];
    myMapThird.at(1)= "Aha";
    myMapThird[2]= "Beatles";

  

    try {
        myMapThird.at(12) = "hello";    }
        catch(std::exception &e)
        {
            std::cout<<"\n\n\n\nerror found";
            std::cout<<"\n"<<e.what();
        }
    std::map<int,std::string> myMapThirdMore (myMapThird.begin(),myMapThird.end());
      for (std::map<int,std::string>::iterator it = myMapThirdMore.begin(); it!=myMapThirdMore.end();++it)
    {
        std::cout<<"\n "<<it->first<<" - "<<it->second;
    }
std::map<int,std::string>::iterator x,y;
x = myMapThird.find(1);
y = myMapThird.find(2);
    std::map<int,std::string> anotherOne;
    anotherOne.insert(x,y);
    std::cout<<"\n\n\n\nhere";
  for (std::map<int,std::string>::iterator it = anotherOne.begin(); it!=anotherOne.end();++it)
    {
        std::cout<<"\n "<<it->first<<" - "<<it->second;
    }


    return 0;
    
}