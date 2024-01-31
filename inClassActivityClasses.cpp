//Abdulaziz Jamaleddin - Jacob Simpson
//Kim M
//In-Class Activity Classes Refresher 1-29-24
#include <iostream>
#include <chrono>
#include <thread>

// #include <cconio>

class Car{

    private:
        int year;
        std::string make;
        std::string model;
        float speed;
        float gallons;
        bool isOn;


    public:
        Car(int year, std::string make, std::string model)
        {
            this->year = year;
            this->make = make;
            this->model = model;
            this->speed = 0;
            this->gallons = 10;
            this->isOn = false;


        }

    
    int getYear(){ return year; }
    std::string getMake(){ return make;}
    std::string getModel(){ return model;} 
    float getSpeed(){ return speed; }
    float getGallons(){ return gallons; }
    bool getStatus(){ return isOn; }

    //mutator functions
    void accelerate(){
        
        if (gallons >= .5  )

        {
            if(isOn){
            speed += 5;
            gallons -=.5;
            }
            else{
                std::cout<<"Car OFF";
            }
        }
        else{
            if(gallons<.2){
            speed = gallons = 0;
            isOn = false;
            std::cout<<"\nCar OFF";
            }
            std::cout<<"\nYou do not have enough gas";
        }
            

    }
    void brake()
    {
        if(gallons >= .2)
        if(isOn){
        {
            if (speed <= 5)
            {
                speed=0;
            
            }
            else{

                speed -= 5;
            }
            gallons -= .2;
        }   }
         else{
                std::cout<<"Car OFF";
            }

        else{
            std::cout<<"\nNot enough gallons in car\nCar off";
            speed = gallons = 0;
            isOn = false;
        }


    }
    void decGallons(){
        if (gallons<.5 && isOn){
gallons-=.5;
        }
        else{
            isOn = false;
            std::cout<<"Car off";
        }
    }

    void fillUp()
    {
        if (isOn == true)
        {
            std::cout<<"Please turn off the car";
        }
        else{

            if(gallons >= 17)
            {
                std::cout<<"\nOVERFILL\n";
                gallons = 22;

            }
            else
                gallons += 5;


        }


    }

    void startCar()
    {

        if(gallons == 0)
        {
            std::cout<<"Fill up your car";
        }
        else
        {
            isOn = true;
           
   

        }




    }
    void shutOff()
    {
        if(speed != 0)
        {
            std::cout<<"Come tot a stop before shutting off car";

        }
        else 
        {
                isOn = false;

        }}
     void consumeGas() {
        while (true) {
            // Sleep for 1000 milliseconds
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            if (isOn) {
                // Decrease gas by 0.05 every second
                gallons -= 0.05;

                // If gas is less than 0.05, turn off the car
                if (gallons < 0.05) {
                    isOn = false;
                    speed = 0;
                    std::cout << "Out of gas. Car turned off.\n";
                    break;
                }
            }
        }
    }

};

int main(){

    int choice;

    Car myCar(2023, "Ford", "Explorer");
    // std::cout<<"My car model is "<<myCar.getModel()<<" by "<<myCar.getMake()<<" it was produced in "<<myCar.getYear();
    // std::cout<<"\nMy car current miles are "<<myCar.getGallons()<<" and current speed is "<<myCar.getSpeed();
    auto startTime = std::chrono::steady_clock::now();  // Use auto to deduce the type
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

    do{
    std::cout<<"\nMy car model is "<<myCar.getModel()<<" by "<<myCar.getMake()<<" it was produced in "<<myCar.getYear();
    std::cout<<"\nMy car current miles are "<<myCar.getGallons()<<" and current speed is "<<myCar.getSpeed()<<"\nThe car is "<<myCar.getStatus();
    
        std::cout<<"\n1. Start car\n2. Shut off car\n3. Accelerate car\n4. Brake car\n5. Fill up car\n0. Exit program\n";
        std::cin>>choice;
    
        switch (choice)
        {
            case 1:
               myCar.startCar();

                startTime = std::chrono::steady_clock::now();  // Update the start time after starting the car
                currentTime = std::chrono::steady_clock::now();
                elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

                if (elapsedTime >= 1) {
                    myCar.decGallons();
                }

                break;

    
                break;
            case 2:
                myCar.shutOff();
                break;
            case 3:
                myCar.accelerate();
                break;
            case 4:
                myCar.brake();
                break;
            case 5:
                myCar.fillUp();
                break;
            case 0:
                break;



        }
    }while(choice != 0);

    





    return 0;
}