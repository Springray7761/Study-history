#include <iostream>
#include <string>
using namespace std;
// Assuming MAX_BOOKS is a constant defining the maximum number of books
const int MAX_BOOKS = 5;
// You need to define the Book class with its members, constructor, copy constructor, and methods
class Book{
private:
    string title, author;
    float price;
public:
    Book(){};
    Book(string a,string b,float c){
        title=a,author=b,price=c;
    }
    Book(const Book& b){
        title=b.title;
        author=b.author;
        price=b.price;
        cout<<"Book copied"<<endl;
    }
    Book &display(){
        cout<<"title:"<<title<<endl;
        cout<<"author:"<<author<<endl;
        cout<<"price:"<<price<<endl;
        return *this;
    }
    Book &sell(){
        totalSales++;
        return *this;
    }
    static int totalSales;
};
// You need to define the Bookstore class with its members, constructor, and methods
class Bookstore{
private:
    int Book_counter =0;
    Book* Book_list = new Book[MAX_BOOKS];  
public:
    Bookstore &addBook(Book a){
        Book_list[Book_counter++] = a;
        return *this;
    }
    Bookstore &displayBooks(){
        for(int i=1;i<=Book_counter;i++){
            cout<<"The "<<i<<"th Book:"<<endl;
            Book_list[i-1].display();
        }
        return *this;
    }
    Bookstore &sellBook(const int &index){
        Book* Book_list_temp=Book_list;
        for(int i=0;i<index-1;i++) Book_list[i]=Book_list_temp[i];
        Book_list[index-1].sell();
        Book_counter--;
        for(int i=index-1;i<Book_counter;i++) Book_list[i]=Book_list_temp[i+1];
        return *this;
    }
};
int Book::totalSales =0;
int main() {
Bookstore store;
// Adding books with chained calls
store.addBook(Book("1984", "George Orwell", 9.99))
.addBook(Book("Animal Farm", "George Orwell", 7.99))
.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 14.99))
.addBook(Book("A Brief History of Time", "Stephen Hawking", 15.99))
.addBook(Book("Sapiens", "Yuval Noah Harari", 18.99));
// Display all books and sell some books with chained calls
store.displayBooks()
.sellBook(1) // Sell "Animal Farm"
.sellBook(3); // Sell "A Brief History of Time"
// Display total sales
std::cout << "Total Books Sold: " << Book::totalSales << std::endl;
return 0;
}