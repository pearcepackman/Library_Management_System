//
// Created by Pearce Packman on 4/27/24.
//

#include "Customer.h"
#include <iostream>
#include <ctime>
using namespace std;

//Creates the constructor with stuff
Customer::Customer(string customer_name, string customer_address, time_t customer_date_check_out, Book customer_book)
    : ID(generate_guid()),
      name(customer_name),
      address(customer_address),
      date_check_out(customer_date_check_out),
      book(customer_book) 
{}


//Generates a five/six digit ID number for customer
int Customer::generate_id()
{
    int random_ID = (rand() % (999999 - 99999 + 1)) + 99999;
    return random_ID;
}

//Checkout function finds the current time of the system, then sets customer date check out to that value, also returns it
string Customer::checkoutTime()
{
    book.checkoutBook();
    time_t now = time(0);
    date_check_out = now;
    return ctime(&date_check_out);
}

//Checkin() will set the customers book to the default book, also date_checked_out = N/A to show customer info
string Customer::checkinTime()
{
    book = Book("N/A", "N/A", false, 0.00, 0);
    time_t now = time(0);
    date_check_out = now;
    return ctime(&date_check_out);
}

//View with all the information about customer
void Customer::viewCustomer()
{
    cout << "----------------------------------------" << endl;
    cout << "Customer Information: " << endl;
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Address: " << address << endl;
    cout << "Date Checked Out: " << ctime(&date_check_out) << endl;
    cout << "Book Title: " << book.get_title() << endl;
    cout << "----------------------------------------" << endl;
}
