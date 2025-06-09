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
    int ID;
    int total_pages;
    float cost;
    bool checked_out;
    string title;
    string author;

public:
    //Constructor
    Book(string title, string author, bool checked_out, float cost, int total_pages);

    //Default constructor
    /*Book()
    {
        title = "N/A";
        author = "N/A";
        ID = 00000;
        checked_out = false;
        cost = 0.00;
        total_pages = 0;
    }*/

    //Copy constructor, initializes all the same things but with a new ID
    Book(const Book & b)
    {
        total_pages = b.total_pages;
        cost = b.cost;
        checked_out = b.checked_out;
        title = b.title;
        author = b.author;
        ID = Book::generateBookId();
    }

    //Destructor, not creating anything new on the heap, not used yet, good to have
    ~Book()
    {
    }

    //Getters for the book class
    const string& get_title() const {return title;}

    const string& get_author() const {return author;}

    int get_id() const {return ID;}

    bool get_checked_out() const {return checked_out;}

    double get_cost() const {return cost;}

    int get_total_pages() const {return total_pages;}

    //Methods going in the Book.cpp
    static int generateBookId();
    void viewBookInfo();
    bool checkoutBook();
    bool checkinBook();
};
