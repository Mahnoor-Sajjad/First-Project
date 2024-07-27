#include <iostream>
#include <vector>
using namespace std;

class USER
{
protected:
    struct BOOK
    {
        string author, title, ISBN;
    };
    vector<BOOK> book;
    int num, userID, count;
    string name, search;

public:
    USER() { count = 0; }
    void credentials()
    {
        cin.ignore();
        cout << "Name  : ";
        getline(cin, name);
        cout << "User ID : ";
        cin >> userID;
    }
    void Search_Book()
    { // books should be sorted acc to the title so it's easy to search by name
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

class LIBRARIAN : public USER
{
public:
    void menu();
    void add_Book();
    void delete_Book();
    void Book_issue();
    void display_Books();
};
void LIBRARIAN::menu()
{
    do
    {
        cout << "1.Add a Book" << endl
             << "2.Delete a Book" << endl
             << "3.Search a Book" << endl
             << "4.Issue a Book" << endl;
        cout << "5.Display all Books" << endl
             << "6.Exit" << endl;
        cout << "Enter Your choice : ";
        cin >> num;
        switch (num)
        {
        case 1:
            add_Book();
            break;
        case 2:
            delete_Book();
            break;
        case 3:
            Search_Book();
            break;
        case 4:
            Book_issue();
            break;
        case 5:
            display_Books();
            break;
        case 6:
            cout << "Exited successfully." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (num != 6);
}

void LIBRARIAN::add_Book()
{
    cout << "\nFor Adding a new book, enter the following details: ";

    if (count >= 0)
    {
        BOOK book_obj;
        cout << "\nTitle: ";
        cin.ignore();
        getline(cin, book_obj.title);
        cout << "Author: ";
        getline(cin, book_obj.author);
        cout << "ISBN: ";
        getline(cin, book_obj.ISBN);

        book.push_back(book_obj);
        count++;
        cout << "\nBook added successfully!" << endl;
    }
}

void LIBRARIAN::delete_Book()
{
    cout << "For deleting a book, enter title of the book : ";
    cin.ignore();
    getline(cin, search);
    bool found = false;
    for (int i = 0; i < book.size(); i++)
    {
        if (search == book[i].title)
        {
            book.erase(book.begin()+i);
            cout << "\nBook deleted successfully!";
            found = true; break;
        }
    }   
        if  (!found)
            cout << "\nBook not found!" << endl; 
}

void LIBRARIAN::Book_issue()
{
    cout << "issuing book to student";
}

void LIBRARIAN::display_Books()
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

// class MEMBER : public USER
// {
// public:
//     void select();
//     void Book_issue();
//     void Book_return();
//     void display_Books(); // current and new members have almost all the features but
//                     //  the current member has a previous record which new members do not have. */
// };

// void MEMBER::select()
// {
//      cout << "Enter Your choice : \n";
//     do {
//     cout << "1.Issuing Book"<<endl<<"2.Returning Book"<<endl<<"3.Search a book"<<endl;
//     cout << "4.Display all Books" << endl <<"5.Exit"<<endl;
//     cin>>num;
//     switch (num)
//     {
//         case 1:
//          Book_issue();
//          break;
//         case 2:
//          Book_return();
//          break;
//         case 3:
//          //Search_Book();
//          cout <<"Searching section";
//          break;
//         case 4:
//           display_Books();
//           break;
//         case 5:
//             cout << "Exited successfully." << endl;
//             break;
//         default:
//             cout << "Invalid choice. Please try again." << endl;
//         }
//     } while (num != 5);
// }

// void MEMBER::Book_issue()
// {
//     cout << "issue book";
// }

// void MEMBER::Book_return()
// {
//     cout << "returning a book";
// }

// void MEMBER::display_Books()
// {
//     cout << "displaying";
// }

// void Search_Book() {}
int main()
{
    int num, semester;
    USER obj;
    LIBRARIAN obj2;
    // MEMBER obj3;
    cout << "***LIBRARY MANAGMENT SYSTEM***\n";
    cout << "Enter number according to the option:\n1.Staff \t 2.Member\nEnter choice here: ";
    cin >> num;
    if (num == 2)
    {
        obj.credentials();
        cout << "Semester : ";
        cin >> semester;
        // obj3.select();
    }
    else
    {
        obj.credentials();
        obj2.menu();
    }

    return 0;
}