//
// Created by Pearce Packman on 4/22/24.
//

#include "Book.h"
#include <iostream>
using namespace std;

//Constructor
Book::Book(string book_title, string book_author, int book_ID, bool book_checked_out, double book_cost, int book_total_pages)
{
    title = book_title;
    author = book_author;
    ID = generate_id();
    checked_out = book_checked_out;
    cost = book_cost;
    total_pages = book_total_pages;
}

//Generates random number with 5/6 digits for ID
int Book::generate_id()
{
    int random_ID = (rand() % (999999 - 99999 + 1)) + 99999;
    return random_ID;
}

//Checkout and checkin methods
//Sets checked_out to either true or false
bool Book::checkout()
{
    checked_out = true;
    return checked_out;
}

bool Book::checkin()
{
    checked_out = false;
    return checked_out;
}

//View function to list all details of book
void Book::view()
{
    cout << "----------------------------------------" << endl;
    cout << "Book Information: " << endl;
    cout << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ID: " << ID << endl;
    cout << "Checked Out: " << checked_out << endl;
    cout << "Price: $" << cost << endl;
    cout << "Total Pages: " << total_pages << endl;
    cout << "----------------------------------------" << endl;
}
