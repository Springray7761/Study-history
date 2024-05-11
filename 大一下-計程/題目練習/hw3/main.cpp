#include <iostream>
#include <iomanip>
using namespace std;
const int DIRECTORY_SIZE = 10;
const char *names[DIRECTORY_SIZE] = {"Kirito","Asuna","Yui","Sinon","Yuuki","Alice","Eugeo","Silica","Lisbeth","Klein"};
char const *phoneNumbers[DIRECTORY_SIZE] = {"0900000000","0900000001","0900000002","0900000003","0900000004","0900000005","0900000006","0900000007","0900000008","0900000009"};
void printDirectory(){
    for(int i=0;i<DIRECTORY_SIZE;cout<<"The user:"<<setw(8)<<*(names+i)<<" The phone number: "<<*(phoneNumbers+i)<<endl,i++);
}
void findPhoneNumber(const char *name){
    cout<<"For name: "<<name<<endl;
    for(int i=0;i<DIRECTORY_SIZE;i++){
        int j=0;
        for(j=0;*(name+j)!='\0';j++)
            if(name[j]!=names[i][j]) break;
        if(names[i][j]=='\0'&&name[j]=='\0'){
            cout<<"The corresponding phone number:"<<*(phoneNumbers+i)<<endl;
            return;
        }
    }
    cout<<"No corresponding phoneNumber found."<<endl;
}
void updatePhoneNumber(const char *name, const char *newNumber){
    for(int i=0;i<DIRECTORY_SIZE;i++){
        int j;
        for(j=0;*(name+j)!='\0';j++)
            if(name[j]!=names[i][j]) break;
        if(names[i][j]=='\0'&&name[j]=='\0'){
                phoneNumbers[i]=newNumber;
                cout<<"After update:"<<endl;
                printDirectory();
                return;
        }
    }
    cout<<"No corresponding name found."<<endl;
}
int main() {
    while(1){
        int fuction=0;
        cout<<"Enter the fuction to use(1 for print,2 for find_name,3 for update,0 to exit):";
        cin>>fuction;
        switch(fuction){
            case 1:
                printDirectory();
                break;
            case 2:
                char nametofind[10];
                cout<<"Enter the name to find:";
                cin>>nametofind;
                findPhoneNumber(nametofind);
                break;
            case 3:
                char nametoupdate[10],Phonenumbertoupdate[50];
                cout<<"Enter the name to update:";
                cin>>nametoupdate;
                cout<<"Enter the phone number to update:";
                cin>>Phonenumbertoupdate;
                updatePhoneNumber(nametoupdate,Phonenumbertoupdate);
                break;
            case 0:
                return 0;
        }
    }
}








