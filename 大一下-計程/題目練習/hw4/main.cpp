#include <iostream>
#include <iomanip>
using namespace std;
const int DIRECTORY_SIZE = 5;
void printDirectory(const char* names[], char* const phoneNumbers[], int directorySize){
    for(int i=0;i<directorySize;cout<<"The user:"<<setw(8)<<*(names+i)<<" The phone number: "<<*(phoneNumbers+i)<<endl,i++);
}
void updatePhoneNumber(const char* names[], char* phoneNumbers[], int directorySize, const char* name, const char* newNumber){
    for(int i=0;i<directorySize;i++){
        int j;
        for(j=0;names[i][j]!='\0'&&*(name+j)!='\0';j++)
            if(name[j]!=names[i][j]) break;
        if(names[i][j]=='\0'&&*(name+j)=='\0'){
            delete [] phoneNumbers[i];
            *(phoneNumbers+i) = new char[12];
            int k = 0;
            while(*(newNumber+k) != '\0'){
                phoneNumbers[i][k] = *(newNumber+k);
                k++;
            }
            phoneNumbers[i][k] = '\0';
            return;
        }
    }
    cout<<"No corresponding name found."<<endl;
}
void initializeDirectory(const char* names[], char* phoneNumbers[], int directorySize){
    for(int i = 0; i < directorySize; ++i) {
        *(phoneNumbers+i) = new char[12];
        for(int j = 0; j < 11; ++j)
            phoneNumbers[i][j] = '0';
        phoneNumbers[i][10] ='0'+i;
    }
}
void cleanUp(char* phoneNumbers[], int directorySize){
    for(int i = 0; i < directorySize;i++) 
        delete [] phoneNumbers[i];
}
int main() {
    char* phoneNumbers[DIRECTORY_SIZE];
    const char* names[DIRECTORY_SIZE] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    initializeDirectory(names,phoneNumbers,DIRECTORY_SIZE);
    int mode=0;
    while(1){
        cout<<"Please enter the mode(0 for quit,1 for print,2 for update):";
        cin>>mode;
        switch(mode){
            case 0:
                cleanUp(phoneNumbers,DIRECTORY_SIZE);
                return 0;
            case 1:
                printDirectory(names,phoneNumbers,DIRECTORY_SIZE);
                break;
            case 2:
                char nametoupdate[10],Phonenumbertoupdate[50];
                cout<<"Enter the name to update:";
                cin>>nametoupdate;
                cout<<"Enter the phone number to update:";
                cin>>Phonenumbertoupdate;
                updatePhoneNumber(names,phoneNumbers,DIRECTORY_SIZE,nametoupdate,Phonenumbertoupdate);
                break;
        }
    }
}

