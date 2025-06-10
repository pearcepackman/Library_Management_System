//
// Created by Pearce Packman on 4/27/24.
//

#include <iostream>
#include "Book.h"
#include "utils.h"
using namespace std;

class Customer
{
private:
    //Private attributes of Customer class
    string ID;
    string name; 
    string address; 
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
    const string& get_ID() const {return ID;}

    const string& get_name() const {return name;}

    const string& get_address() const {return address;}

    time_t get_date_check_out() const {return date_check_out;}

    Book get_book() const {return book;}

    //Methods going in the Customer.cpp
    void viewCustomer();
    string checkoutTime();
    string checkinTime();
    int generate_id();

};
