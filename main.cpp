//This project was made by Pearce Packman for CMSC-202 on April 22, 2024
//This project will be the start of the library management system and will use various classes

//Including basic stuff
#include <iostream>
#include "Customer.h"
#include <vector>
using namespace std;

//Prototypes for all functions below
void menu();
void add_customer();
void delete_customer();
void search_customer();
void add_book();
void delete_book();
void search_book();
void duplicate_book();
void book_check_out();
void book_check_in();

//Global variables are usually kind of bad but they work really well for this project I think
int choice;
vector <Customer> custvector;
vector <Book> bookvector;

int main()
{
    //Displays menu and uses a switch statement based off the choice the user selects
    cout << "------------------Pearce's Public Library Management System------------------" << endl;
    menu();
    while(choice != 0)
    {
        switch (choice)
        {
            //Every case has its own function basically, then goes back to menu to ask choice from user again
            case 1:
                add_customer();
                menu();
                break;

            case 2:
                delete_customer();
                menu();
                break;

            case 3:
                add_book();
                menu();
                break;

            case 4:
                delete_book();
                menu();
                break;

            case 5:
                duplicate_book();
                menu();
                break;

            case 6:
                search_customer();
                menu();
                break;

            case 7:
                search_book();
                menu();
                break;

            case 8:
                book_check_out();
                menu();
                break;

            case 9:
                book_check_in();
                menu();
                break;

            default:
                menu();
        }
    }
    cout << "Goodbye!" << endl;
}

//Probably could have made one function to display both vectors but this is good enough
void display_cust_vector(vector <Customer> &c)
{
    //Takes in customer vector and uses for loop to display all customers within
    for (int i = 0; i < c.size(); i++)
    {
        cout << "Customer #: " << i + 1 << endl;
        c[i].view();
    }
}

void display_book_vector(vector <Book> &b)
{
    //Takes in the book vector and uses for loop to display all books from within
    for (int i = 0; i < b.size(); i++)
    {
        cout << "Book #: " << i + 1 << endl;
        b[i].view();
    }
}

void menu()
{
    //Text based menu, choice is used as a global variable so it doesn't return anything
    cout << "---------------Menu---------------" << endl;
    cout << "1. Add a Customer" << endl;
    cout << "2. Delete a Customer" << endl;
    cout << "3. Add a Book" << endl;
    cout << "4. Delete a Book" << endl;
    cout << "5. Create a Duplicate Book" << endl;
    cout << "6. Search and Display a Customer" << endl;
    cout << "7. Search and Display a Book" << endl;
    cout << "8. Check Out Book" << endl;
    cout << "9. Check in a Book" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter Choice: ";
    cin >> choice;
    cout << endl;
}

void add_customer()
{
    //Makes default book for customer
    Book default_book;
    //User defines a bunch of stuff about the customer
    cout << "----------Add Customer----------" << endl;
    string customer_name, customer_address, customer_date_check_out;
    cout << "Customer name: ";
    getline(cin, customer_name);
    getline(cin, customer_name);
    cout << "Customer address: ";
    getline(cin, customer_address);
    cout << "Date Checked Out: ";
    getline(cin, customer_date_check_out);
    //Creates a temp customer based off of data entered, pushes it in vector
    Customer temp_customer(0, customer_name, customer_address, "N/A", default_book);
    custvector.push_back(temp_customer);
    cout << "Customer added!" << endl;

}

void delete_customer()
{
    //Displays the customer vector to user so they can make choice based on index of customer in vector
    display_cust_vector(custvector);
    int cust;
    cout << "What customer number would you like to delete?: " << endl;
    cin >> cust;
    //Erases the customer from the vector
    custvector.erase(custvector.begin() + cust-1);
    cout << "Customer Deleted!" << endl;
}

//Displays all customers, not really a great search tool
void search_customer()
{
    cout << "------------Customers:------------" << endl;
    display_cust_vector(custvector);
}

void add_book()
{
    //Initializes a bunch of stuff to make a book
    cout << "----------Add Book----------" << endl;
    string book_title, book_author;
    int book_pages;
    double book_cost;

    //Get info from user
    cout << "Book Title: ";
    cin >> book_title;
    cout << "Book Author: ";
    cin >> book_author;
    cout << "Total Book Pages: ";
    cin >> book_pages;
    cout << "Cost of Book (add cents): ";
    cin >> book_cost;

    //Make a temp book with information user entered and add it to a book vector
    Book temp_book(book_title, book_author, 0, false, book_cost, book_pages);
    bookvector.push_back(temp_book);
    cout << "Book added!" << endl;
}

void delete_book()
{
    //Displays the book vector to user so they can make choice based on index of book in vector
    display_book_vector(bookvector);
    int book;
    cout << "What book number would you like to delete?: " << endl;
    cin >> book;
    //Erases the customer from the vector
    bookvector.erase(bookvector.begin() + book-1);
    cout << "Book Deleted!" << endl;
}

//Functions the same as search_customer()
void search_book()
{
    cout << "------------Books:------------" << endl;
    display_book_vector(bookvector);
}

void duplicate_book()
{
    //Gets what book user would like to duplicate
    display_book_vector(bookvector);
    int book;
    cout << "What book number would you like to duplicate: " << endl;
    cin >> book;
    Book copy_book = bookvector[book-1];
    //Places the copy of the book in the vector
    bookvector.insert(bookvector.begin() + book + 1, copy_book);
    cout << "Book copied!" << endl;
}

void book_check_out()
{
    display_book_vector(bookvector);
    int book;
    cout << "What book number would you like to check out?: " << endl;
    cin >> book;
    //Vectors make things so nice and easy with objects and methods
    //Calls .checkout() for the book that's in the vector
    bookvector[book-1].checkout();
    cout << "Book checked out!" << endl;
}

void book_check_in()
{
    //Functions the same as the book_check_out() function
    display_book_vector(bookvector);
    int book;
    cout << "What book number would you like to check in?: " << endl;
    cin >> book;
    bookvector[book-1].checkin();
    cout << "Book checked in!" << endl;
}