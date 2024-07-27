#include <iostream>
#include <vector>
using namespace std;

class USER
{
protected:
    struct BOOK
    {
        string author, title, ISBN;
        bool issued = false;
    };
    int num, userID;
    string name, search;
    vector<BOOK> book;

public:
    void credentials()
    {
        cin.ignore();
        cout << "Name  : ";
        getline(cin, name);
        cout << "User ID : ";
        cin >> userID;
    }
    void Search_Book()
    { 
        cout << "Enter the title of the book to search for it : ";
        cin.ignore();
        getline(cin, search);
        bool found = false;
        for (int i = 0; i <  book.size(); i++)
        {
            if (search == book[i].title)
            {
                cout << "Book found!\n" << endl;
                cout << "Title : " << book[i].title << endl;
                cout << "Author : " << book[i].author << endl;
                cout << "ISBN : " << book[i].ISBN << endl;
                found = true;
                break;
            }
        }
        if (!found)
          cout << "Book not found!\n";
    }
};
class MEMBER : public USER
{
public:
    void select();
    void Book_issue();
    void Book_return();
    void display_Books(); 
};

void MEMBER::select()
{
    cout << "Enter Your choice : \n";
    do
    {
        cout << "1.Issuing Book" << endl
             << "2.Returning Book" << endl
             << "3.Search a book" << endl;
        cout << "4.Display all Books" << endl
             << "5.Exit" << endl;
        cin >> num;
        switch (num)
        {
        case 1:
            Book_issue();
            break;
        case 2:
            Book_return();
            break;
        case 3:
            // Search_Book();
            cout << "Searching section";
            break;
        case 4:
            display_Books();
            break;
        case 5:
            cout << "Exited successfully." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (num != 5);
}

void MEMBER::Book_issue()
{
    string borrow_book;
    cout << "Enter the title of book you want to borrow: ";
    cin.ignore();
    getline(cin, borrow_book);

    bool found = false;
    for (int i = 0; i < book.size(); i++)
    {
        if (borrow_book == book[i].title)
        {
            if (book[i].issued)
                cout << "\nThis book is already issued!" << endl;
            else
            {
                book[i].issued = true;
                cout << "\nBook issued successfully!" << endl;
            }
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nBook not available!" << endl;
}

void MEMBER::Book_return()
{
    string borrow_book;
    cout << "Enter the title of book you want to return: ";
    cin.ignore();
    getline(cin, borrow_book);

    bool found = false;
    for (int i = 0; i < book.size(); i++)
    {
        if (borrow_book == book[i].title)
        {
            if (book[i].issued)
            {
                book[i].issued = false; // Mark the book as available
                cout << "\nBook returned successfully!" << endl;
            }
            else
            {
                cout << "\nThis book was not issued!" << endl;
            }
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nBook not found!" << endl;
    }
}

void MEMBER::display_Books()
{
     cout << "All the books available are: \n";

    for (int i = 0; i < book.size(); i++)
    {
        cout << "\nBook " << i + 1 << " details: \n";
        cout << "Title : " << book[i].title << endl
             << "Author : " << book[i].author << endl
             << "ISBN : " << book[i].ISBN << endl << endl;
    }
}

int main()
{
    int num, semester;
    USER obj;
    // LIBRARIAN obj2;
    MEMBER obj3;
    cout << "***LIBRARY MANAGMENT SYSTEM***\n";
    cout << "Enter number according to the option:\n1.Staff \t 2.Member\nEnter choice here: ";
    cin >> num;
    if (num == 2)
    {
        obj.credentials();
        cout << "Semester : ";
        cin >> semester;
        obj3.select();
    }

    return 0;
}