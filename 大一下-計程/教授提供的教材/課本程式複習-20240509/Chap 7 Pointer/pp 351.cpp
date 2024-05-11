int main(){
char color [] = "blue";
char *sPtr;
const char * colorPtr = "blue";

cin >> sPtr;
cout<< sPtr;

char word[20];
cin >> word;

char sentence[80];
cin.getline(sentence, 80, '\n');
cin.getline(sentence, 80);

cout<< color << ' ' << colorPtr << endl;
cout<< word << endl;
cout<< sentence << endl;
}