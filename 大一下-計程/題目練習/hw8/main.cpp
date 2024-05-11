#include <iostream>
using namespace std;
class Book{
    private:
        string title,author,ISBN;
    public:
        Book(){}
        Book(const string &a,const string &b,const string &c){
            title=a;
            author=b;
            ISBN=c;
        }
        void displayBook(){
            cout<<"Book name: "<<title<<" Author name: "<<author<<" ISBN:"<<ISBN<<endl;}
};
class Library{
    private:
        string libraryName;
        Book* listOfBooks = new Book[10];
        int bookamount=0;
    public:
        Library(const string &a):libraryName(a){
            cout<<"Library:"<<libraryName<<" created."<<endl;
        };
        void addBook(const Book &a){
            if(bookamount<=9){
                listOfBooks[++bookamount-1]=a;
                cout<<"Added"<<endl;
                listOfBooks[bookamount-1].displayBook();
                cout<<"to the Library "<<libraryName<<endl;
            }
            else cout<<"Reached the 10 books limit";
        }
        void displayLibrary(){
            cout<<"Library:"<<libraryName<<endl<<"Book list:"<<endl;
            for(int i=0;i<bookamount;listOfBooks[i++].displayBook());
        }
};
int main() {
    Library myLibrary("NCKU Library");
    myLibrary.addBook(Book("C++ Programming", "Bjarne Stroustrup", "9780321563842"));
    myLibrary.addBook(Book("Data Structures", "Nicola Lacey", "9780131986190"));
    myLibrary.addBook(Book("Algorithm Design", "Jon Kleinberg", "9780321295354"));
    myLibrary.addBook(Book("Operating Systems", "Andrew S. Tanenbaum", "9780133591620"));
    myLibrary.addBook(Book("Computer Networks", "Andrew S. Tanenbaum", "9780132126953"));
    myLibrary.displayLibrary();
    return 0;
}










