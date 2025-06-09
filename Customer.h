//
// Created by Pearce Packman on 4/27/24.
//

#include <iostream>
#include "Book.h"
using namespace std;

class Customer
{
private:
    //Private attributes of Customer class
    int ID;
    string name, address; 
    time_t date_check_out;
    Book book;

public:
    //Constructor
    Customer(string name, string address, time_t date_check_out, Book book);

    //Default constructor
    //Initializes default customer with all this stuff
    /*Customer()
    {
        ID = 0000;
        name = "N/A";
        address = "N/A";
        date_check_out = "N/A";
        book = Book();
    }
        */

    //THIS SAVED MY PROJECT!!!!
    Customer(const Customer& c)
        : ID(c.ID),
        name(c.name),
        address(c.address),
        date_check_out(c.date_check_out),
        book(c.book)// this works because Book has a copy constructor
        {}


    //Destructor, similar to the one found in Book.h
    //Not creating anything on the heap, therefore does not need memory de-allocation
    ~Customer()
    {
    }

    //Getters
    int get_ID() {return ID;}

    string get_name() {return name;}

    string get_address() {return address;}

    time_t get_date_check_out() {return date_check_out;}

    Book get_book() {return book;}

    //Methods going in the Customer.cpp
    void view();
    string checkout();
    string checkin();
    int generate_id();

};
