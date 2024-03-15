
#include <iostream>
class Job{
    friend int operator+(int x, Job j);
    friend std::ostream& operator<<(std::ostream& out, const Job& aJob);
    friend std::istream&  operator>>(std::istream& in,  Job& aJob);
    private: 
    int jobNum;
    int jobTime;
    double hourlyRate;
    public:
    Job(int jobNum, int jobTime, double hourlyRate){
        this->jobNum = jobNum;
        this->jobTime = jobTime;
        this->hourlyRate = hourlyRate;
    }
    int operator+(Job j){
        int totalTime = jobTime + j.jobTime;
        return totalTime;
    }

    Job operator+(int a){
        jobTime += a;
        // return job
        return *this;
        // return Job(jobNum,jobTime,hourlyRate);
    }
    int operator-(Job j){
        int totalTime = jobTime - j.jobTime;
        return abs(totalTime);
    }
    void operator++(){
      hourlyRate++;
}    
    void operator++(int x){
      hourlyRate++;
}    
    bool operator==(Job j){
        return (jobNum == j.jobNum);
    }
    int getTime(){return jobTime;}
};
int main(){

Job jobA(100,10,10.50);
Job jobB(200,20,20.50);
Job jobC(300,30,30.50);
Job jobD(0,0,0);
std::cout<<"Total Time: "<< (jobA+jobB)<<std::endl;
std::cout<<"ALT: Total Time: "<< (jobA.operator+(jobB))<<std::endl;
std::cout<<"Difference in Time: "<< (jobA-jobB)<<std::endl;
jobA = (jobA + 10);
std::cout<<"Job A Time: "<< (jobA.getTime())<<std::endl;
std::cout<<"Total Time: "<< (jobA+jobB+5)<<std::endl;
std::cout<<"Total Time: "<< (jobA+jobB+5+jobC)<<std::endl;
std::cout<<jobC;
std::cin>>jobD;
std::cout<<jobD<<std::endl;
++jobD;
jobD++;
std::cout<<jobD;
if (jobA==jobB){
    std::cout<<"\nEqual\n";
}
else{
    std::cout<<"\nNot Equal";
}
    return 0;
}
int operator+(int x, Job j){
    return x + j.jobTime;
}

std::ostream& operator<<(std::ostream& out, const Job& aJob){
    out<<"Job Number: "<<aJob.jobNum<<" Job Time: "<<aJob.jobTime<< " Hourly Rate: "<<aJob.hourlyRate<<std::endl;
    return out;
}
std::istream&  operator>>(std::istream& in,  Job& aJob){
    // in<<"Job Number: "<<aJob.jobNum<<" Job Time: "<<aJob.jobTime<< " Hourly Rate: "<<aJob.hourlyRate<<std::endl;
    int jobNum, jobTime;
    double hourly;

    in>>aJob.jobNum;
    in>>aJob.jobTime;
    in>>aJob.hourlyRate;
    // return aJob(jobNum,jobTime,hourly);
    return in;
}