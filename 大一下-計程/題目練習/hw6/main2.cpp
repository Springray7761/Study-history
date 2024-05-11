#include <iostream>
#include<iomanip>
using namespace std;
class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int=0,int=0,int=0);
    void setTime(int,int,int);
    void printUniversal();
    void printStandard();
    void tick();
};
Time::Time(int hr,int min,int sec){
    setTime(hr,min,sec);
}
void Time::setTime(int h,int m,int s){
    hour=(h>=0&&h<24)?h:0;
    minute=(m>=0&&m<60)?m:0;
    second=(s>=0&&s<60)?s:0;
}
void Time::printUniversal(){
    cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<minute<<":"<<setw(2)<<second;
}
void Time::printStandard(){
    cout<<((hour==0||hour==12)?12:hour%12)<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<(hour<12?" AM":" PM");
}
void Time::tick(){
    second=(second==59?0:second+1);
    minute=(second==0?(minute==59?0:minute+1):minute);
    hour=(second==0&&minute==0?(hour==23?0:hour+1):hour);
}
int main(){
    Time now(23,59,50);
    for(int i=0;i<50;i++){
        now.tick();
        now.printStandard();
        cout<<endl;
    }
    return 0;
}

