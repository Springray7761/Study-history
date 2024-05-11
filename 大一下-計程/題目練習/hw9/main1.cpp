#include <iostream>
#include <iomanip>
using namespace std;
class Time{
private:
    int second;
public:
    Time(int=0,int=0,int=0);
    Time &setTime(int,int,int);
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void printUniversal() const;
    void printStandard() const;
};
Time::Time(int hr,int min,int sec){
    setTime(hr,min,sec);
}
Time &Time::setTime(int h,int m,int s){
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this;
}
Time &Time::setHour(int h){
    h =(h>=0&&h<24)?h:0;
    second = second %3600 + 3600*h;
    return *this;
}
Time &Time::setMinute(int m){
    m =(m>=0&&m<60)?m:0;
    second = second / 3600 * 3600 + second % 60 + m*60;
    return *this;
}
Time &Time::setSecond(int s){
    s =(s>=0&&s<60)?s:0;
    second = second /60 *60 + s;
    return *this;
}
int Time::getHour() const{
    return second / 3600;
}
int Time::getMinute() const{
    return second % 3600 / 60;
}
int Time::getSecond() const{
    return second % 60 ;
}

void Time::printUniversal() const{
    cout<<setfill('0')<<setw(2)<<getHour()<<":"<<setw(2)<<getMinute()<<":"<<setw(2)<<getSecond();
}
void Time::printStandard() const{
    cout<<((getHour()==0||getHour()==12)?12:getHour()%12)<<":"<<setfill('0')<<setw(2)<<getMinute()<<":"<<setw(2)<<getSecond()<<(getHour()<12?" AM":" PM");
}
int main(){
    Time t;
    t.setHour(18).setMinute(30).setSecond(22);
    cout<<"Universal time: ";
    t.printUniversal();
    cout<<"\nStandard time: ";
    t.printStandard();
    cout<<"\n\nNew Standard time: ";
    t.setTime(20,20,20).printStandard();
    cout<<endl;
    return 0;
}