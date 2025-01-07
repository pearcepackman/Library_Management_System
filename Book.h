//
// Created by Pearce Packman on 4/22/24.
//

#include <iostream>
using namespace std;

//Creating class book
class Book
{
private:
    //Making the private attributes of Book Class
    int ID, total_pages;
    double cost;
    bool checked_out;
    string title, author;

public:
    //Constructor
    Book(string title, string author, int ID, bool checked_out, double cost, int total_pages);

    //Default constructor
    Book()
    {
        title = "N/A";
        author = "N/A";
        ID = 00000;
        checked_out = false;
        cost = 0.00;
        total_pages = 0;
    }

    //Copy constructor, initializes all the same things but with a new ID
    Book(const Book & b)
    {
        total_pages = b.total_pages;
        cost = b.cost;
        checked_out = b.checked_out;
        title = b.title;
        author = b.author;
        ID = Book::generate_id();
    }

    //Destructor, not creating anything new on the heap, not used yet, good to have
    ~Book()
    {
    }

    //Getters for the book class
    string get_title() {return title;}

    string get_author() {return author;}

    int get_id() {return ID;}

    bool get_checked_out() {return checked_out;}

    double get_cost() {return cost;}

    int get_total_pages() {return total_pages;}

    //Methods going in the Book.cpp
    static int generate_id();
    void view();
    bool checkout();
    bool checkin();
};
