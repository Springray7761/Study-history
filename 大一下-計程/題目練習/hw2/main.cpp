#include <iostream>
using namespace std;
const char *vowels_upper ="AEIOU",*vowels_lower ="aeiou";
void show_result(const int* counter){
    cout<<*(counter+5)<<" sentences"<<endl<<"Average "<<*(counter+6)/(*(counter+5))<<" words per sentence"<<endl;     
    for(int i=0;i<5;(*(counter+i))?(cout<<vowels_lower[i]<<' '<<*(counter+i)<<endl):(cout<<'\0'),i++);
}
void analyzeText(const char* paragraph){
    int counter[7]={0};//In counter [0]~[4]counts vowels,[5]count number of sentences,[6] for words
    for(int i=0;*(paragraph+i);(*(paragraph+i)=='?'||*(paragraph+i)=='!'||*(paragraph+i)=='.')?(counter[5]++,counter[6]++):1,(*(paragraph+i)==' '||*(paragraph+i)==',')?(counter[6]++):1,i++)
        for(int j=0;j<5;(*(paragraph+i)==vowels_upper[j]||*(paragraph+i)==vowels_lower[j])?counter[j]++:1,j++);/*becaues you can't let it be blank right after the ?: statment */
    show_result(counter);   /*So I putted a 1,which makes it do nothing but have expression at the same time*/
}
int main() {
    const char *paragraph1 = "Hello, world! I am learning C++. Isn't it exciting?",*paragraph2 = "Faker!What was that?";
    analyzeText(paragraph1);
    cout << "-----------------------------------\n";
    analyzeText(paragraph2);
    return 0;
}
