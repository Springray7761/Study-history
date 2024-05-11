#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class HugeInterger{
private:
    int numbers[40];
    int size=0;
public:
    HugeInterger();
    HugeInterger(const char[]);
    void input();
    void output();
    void clear();
    HugeInterger add(const HugeInterger&,const HugeInterger&);
    HugeInterger subtract(const HugeInterger&,const HugeInterger&);
    bool isEqualTo(const HugeInterger&,const HugeInterger&);
    bool isNotEqualTo(const HugeInterger&,const HugeInterger&);
    bool isGreaterThan(const HugeInterger&,const HugeInterger&);
    bool isLessThan(const HugeInterger&,const HugeInterger&);
    bool isGreaterThanOrEqualTo(const HugeInterger&,const HugeInterger&);
    bool isLessThanOrEqualTo(const HugeInterger&,const HugeInterger&);
    bool isZero();
    bool isPostive();
    HugeInterger multipy(const HugeInterger&,const HugeInterger&);
    HugeInterger divide(const HugeInterger&,const HugeInterger&);
    HugeInterger modulus(const HugeInterger&,const HugeInterger&);
};
HugeInterger::HugeInterger(){
    for(int i=0;i<40;numbers[i]=0,i++,size=0);
}
HugeInterger::HugeInterger(const char value[] ){
    for(int i=1;value[i-1]!='\0';size=i++);
    for(int i=0;i<size;numbers[size-i-1]=value[i],i++);
}
void HugeInterger::input(){
    size=0;
	int i,j,temp;
	char input;
	for(i=0;i<=39;i++){
		input=getchar();
		if(input<'0'||input>'9') break;
		size++;
		numbers[i]=input-'0';
	}
	if(i<39)
		for (j=i;j<=39;numbers[j]=0,j++);
	for (i=0,j=size-1;i<j;i++,j--){
		temp=numbers[i];
		numbers[i]=numbers[j];
		numbers[j]=temp;
	}
}
void HugeInterger::output(){
    if(size==0) cout<<'0';
    else{
        for(int i=size-1;i>=0;i--){
            if(numbers[i]>=0)cout<<numbers[i];
            else cout<<'-'<<-numbers[i];
        }
    }
    cout<<endl;
}
void HugeInterger::clear(){
    for(int i=0;i<39;i++) numbers[i]=0;
    size=0;
}
HugeInterger HugeInterger::add(const HugeInterger &number1,const HugeInterger &number2){
    HugeInterger number3,temp1=number1,temp2=number2;
	int mod,div=0;
	if(!temp1.isPostive()&&temp2.isPostive()){
	    temp1.numbers[temp1.size-1]*=-1;
	    return temp2.subtract(temp2,temp1);
	}
	if(!temp2.isPostive()&&temp1.isPostive()){
	    temp2.numbers[temp2.size-1]*=-1;
	    return temp1.subtract(temp1,temp2);
	}
	for (int i=0;((i<temp1.size)||(i<temp2.size));i++){
		number3.numbers[i]=temp1.numbers[i]+temp2.numbers[i]+div;
		number3.size++;
		if(number3.numbers[i]>9)
		{   
		    if((i==temp1.size-1&&i>=temp2.size-1)||(i==temp2.size-1&&i>=temp1.size-1)){
		        number3.size++;
		        number3.numbers[i]=number3.numbers[i]%10;
		        number3.numbers[i+1]=1;
		    }
		    if(i==39){
		        cout<<"The addition is over 40 digits"<<endl;
		        break;
		    }
			mod=number3.numbers[i]%10;
			div=number3.numbers[i]/10;
			number3.numbers[i]=mod;
		}
		else
			div=0;
	}
	for(int i=0;i<number3.size-1;i++)
	    if(number3.numbers[i]<0){
	        number3.numbers[i]+=10;
	        number3.numbers[i+1]--;
	    }
	return number3;
}
HugeInterger HugeInterger::subtract(const HugeInterger &number1,const HugeInterger &number2){
    bool checker=isGreaterThanOrEqualTo(number1,number2);
    HugeInterger number3,temp1=(checker?number1:number2),temp2=(checker?number2:number1);
    int i,j,decrement=0;
	for (i=0;i<temp1.size;i++){
	    number3.size++;
		if(i==temp1.size-1){
		    number3.numbers[i]=temp1.numbers[i]-temp2.numbers[i]-decrement;
		    break;
		}
		if((temp1.numbers[i]-decrement)>=temp2.numbers[i]){
			number3.numbers[i]=temp1.numbers[i]-temp2.numbers[i]-decrement;
			decrement=0;
		}
		else{
			number3.numbers[i]=temp1.numbers[i]-temp2.numbers[i]-decrement+10;
			decrement=1;
		}
	}
	for(i=39;i>=1&&number3.numbers[i]==0;i--);
	number3.size=i+1;
	if((!checker)){
	    for(int i=number3.size-1;i>=0;i--){
	        if(number3.numbers[i]!=0){
	            number3.numbers[i]=-number3.numbers[i];
	            break;
	        }
	    }
	}
	return number3;
}
HugeInterger HugeInterger::multipy(const HugeInterger &number1,const HugeInterger &number2){
    HugeInterger number3,temp;
    int i;
    number3.size=40;
	for(int i=0;i<number2.size;i++){
	    temp=number1;
	    for(int j=number1.size-1;j>=0;j--)temp.numbers[i+j]=temp.numbers[j]*number2.numbers[i];
	    for(int j=0;j<i;j++) temp.numbers[j]=0;
	    number3=number3.add(number3,temp);
	}
	for(i=39;i>=1&&number3.numbers[i]==0;i--);
	number3.size=i+1;
	return number3;
}
HugeInterger HugeInterger::divide(const HugeInterger &number1,const HugeInterger &number2){
    HugeInterger number3,temp1=number1,temp2,temp4;
    number3.size=40;
    int i=number1.size-1;
    if(temp1.isLessThan(number1,number2))return number3;
    else{
        do{
            temp2=number2;
            if(temp1.numbers[i]/number2.numbers[number2.size-1]==0){
                i--;
                temp1.numbers[i]+=temp1.numbers[i+1]*10;
                temp1.numbers[i+1]=0;
            }
            number3.numbers[i-number2.size+1]=(temp1.numbers[i]/number2.numbers[number2.size-1]);
            if(temp1.numbers[i]>10){
                temp1.numbers[i+1]=temp1.numbers[i]/10;
                temp1.numbers[i]=temp1.numbers[i]%10;
            }
            temp4.size=i-number2.size+2;
            temp4.numbers[i-number2.size+1]=number3.numbers[i-number2.size+1];
            temp2=temp1.multipy(temp2,temp4);
            temp1=temp1.subtract(temp1,temp2);
            temp4.clear();
            while(!temp1.isPostive()){
                number3.numbers[i-number2.size+1]--;
                temp4.size=i-number2.size+2;
                temp4.numbers[i-number2.size+1]=1;
                temp4=temp4.multipy(number2,temp4);
                temp1=temp1.add(temp1,temp4);
                temp4.clear();
            }
            if(temp1.numbers[i]>0){
                temp1.numbers[i-1]+=temp1.numbers[i]*10;
                temp1.numbers[i]=0;
            }
            i--;
        }while(temp1.isGreaterThan(temp1,number2));
    }
    for(i=39;i>=1&&number3.numbers[i]==0;i--);
	number3.size=i+1;
    return number3;
}
HugeInterger HugeInterger::modulus(const HugeInterger &number1,const HugeInterger &number2){
    HugeInterger number3=number1,temp1;
    temp1=number3.divide(number1,number2);
    temp1=number3.multipy(number2,temp1);
    number3=number3.subtract(number3,temp1);
    return number3;
}
bool HugeInterger::isEqualTo(const HugeInterger &number1,const HugeInterger &number2){
    for(int i=0;i<40;i++) if(number1.numbers[i]!=number2.numbers[i]) return false;
    return true;
}
bool HugeInterger::isNotEqualTo(const HugeInterger &number1,const HugeInterger &number2){
    for(int i=0;i<40;i++) if(number1.numbers[i]!=number2.numbers[i]) return true;
    return false;
}
bool HugeInterger::isGreaterThan(const HugeInterger &number1,const HugeInterger &number2){
    if(number1.size<number2.size) return false;
    for(int i=number1.size-1;i>=0;i--){
        if(number1.numbers[i]>number2.numbers[i]) return true;
        else if(number1.numbers[i]<number2.numbers[i]) return false;
    }
    return false;
}
bool HugeInterger::isLessThan(const HugeInterger &number1,const HugeInterger &number2){
    if(number1.size>number2.size) return false;
    for(int i=number1.size-1;i>=0;i--){
        if(number1.numbers[i]<number2.numbers[i]) return true;
        else if(number1.numbers[i]>number2.numbers[i]) return false;
    }
    return false;
}
bool HugeInterger::isGreaterThanOrEqualTo(const HugeInterger &number1,const HugeInterger &number2){
    if(number1.size<number2.size) return false;
    for(int i=number1.size-1;i>=0;i--){
        if(number1.numbers[i]>number2.numbers[i]) return true;
        else if(number1.numbers[i]<number2.numbers[i]) return false;
    }
    return true;
}
bool HugeInterger::isLessThanOrEqualTo(const HugeInterger &number1,const HugeInterger &number2){
    if(number1.size>number2.size) return false;
    for(int i=number1.size-1;i>=0;i--){
        if(number1.numbers[i]<number2.numbers[i]) return true;
        else if(number1.numbers[i]>number2.numbers[i]) return false;
    }
    return true;
}
bool HugeInterger::isZero(){
    for(int i=0;i<40;i++) if(numbers[i]!=0) return false;
    return true;
}
bool HugeInterger::isPostive(){
    for(int i=0;i<40;i++) if(numbers[i]<0) return false;
    return true;
}
int main(){
    HugeInterger h,h1,h2,ha,hs,hm,hd,hmod;
	h1.input();
	h1.output();
	h2.input();
	h2.output();
	ha=h.add(h1,h2);
	ha.output();
	hs=h.subtract(h1,h2);
	hs.output();
	hm=h.multipy(h1,h2);
	hm.output();
	hd=h.divide(h1,h2);
	hd.output();
	hmod=h.modulus(h1,h2);
	hmod.output();
	cout<<h.isEqualTo(h1,h2)<<endl;
	cout<<h.isNotEqualTo(h1,h2)<<endl;
	cout<<h.isGreaterThan(h1,h2)<<endl;
	cout<<h.isLessThan(h1,h2)<<endl;
	cout<<h.isGreaterThanOrEqualTo(h1,h2)<<endl;
	cout<<h.isLessThanOrEqualTo(h1,h2)<<endl;
	cout<<h1.isZero()<<endl;
	cout<<h2.isZero()<<endl;
    return 0;
}









