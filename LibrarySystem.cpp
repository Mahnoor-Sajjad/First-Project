#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
    int num, userID, count;
    string name, search;
    vector<BOOK> book;

public:
    USER() { count = 0; }
    void credentials()
    {
        cout << "\nName  : ";
        getline(cin, name);
        cout << "User ID : ";
        cin >> userID;
    }
    void Search_Book()
    {
        ifstream infile("library_Data.txt", ios::in);
        cout << "Enter the title of the book to search for it : ";
        cin.ignore();
        getline(cin, search);
        bool found = false;
        string line;
        if (infile.is_open())
        {
            while (getline(infile, line))
            {
                istringstream linestream(line);
                string title, author, ISBN;
                bool issued;

                if (getline(linestream, title, ','))
                {
                    if (title == search)
                    {
                        cout << "Book found!\n";
                        getline(linestream, author, ',');
                        getline(linestream, ISBN, ',');
                        linestream >> issued;
                        cout << endl
                             << "Title : " << title << ", "
                             << "Author : " << author << ", "
                             << "ISBN : " << ISBN << ", ";
                        cout << "Issued : " << (issued ? "Yes" : "No") << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found)
                cout << "Book not found!\n";
            infile.close();
        }
        else
            cout << "\nUnable to open the file!" << endl;
    }

    void display_Books()
    {
        ifstream infile("library_Data.txt", ios::in);
        string line;
        if (infile.is_open())
        {
            cout << "All the books available are: \n";
            while (getline(infile, line))
            {
                istringstream iss(line);
                string title, author, ISBN;
                bool issued;

                getline(iss, title, ',');
                getline(iss, author, ',');
                getline(iss, ISBN, ',');
                iss >> issued;
                cout << endl
                     << "Title : " << title << ", "
                     << "Author : " << author << ", "
                     << "ISBN : " << ISBN << ", ";
                cout << (issued ? "Yes" : "No") << endl;
            }
            infile.close();
        }
        else
            cout << "\nCannot open the file!" << endl;
    }
};

class LIBRARIAN : public USER
{
public:
    void menu();
    void add_Book();
    void delete_Book();
    void Book_issue();
    void Book_return();
};

void LIBRARIAN::menu()
{
    do
    {
        cout << "1.Add a Book" << endl
             << "2.Delete a Book" << endl
             << "3.Search a Book" << endl
             << "4.Issue a Book" << endl
             << "5.Return a Book" << endl;
        cout << "6.Display all Books" << endl
             << "7.Exit" << endl;
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
            Book_return();
            break;
        case 6:
            display_Books();
            break;
        case 7:
            cout << "Exited successfully." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (num != 7);
}

void LIBRARIAN::add_Book()
{
    cout << "\nFor Adding a new book, enter the following details: ";
    BOOK book_obj;
    if (count >= 0)
    {
        cout << "\nTitle: ";
        cin.ignore();
        getline(cin, book_obj.title);
        cout << "Author: ";
        getline(cin, book_obj.author);
        cout << "ISBN: ";
        getline(cin, book_obj.ISBN);
        cout << "Book status (Press 1 for issued/0 for not issued): ";
        cin >> book_obj.issued;
    }

    ofstream outfile("library_Data.txt", ios::app);

    if (outfile.is_open())
    {
        outfile << book_obj.title << ", "
                << book_obj.author << ", "
                << book_obj.ISBN << ", "
                << book_obj.issued << endl;
        count++;
        cout << "\nBook added successfully!" << endl;
        outfile.close();
    }
    else
        cout << "\nFile not found!" << endl;
}

void LIBRARIAN::delete_Book()
{
    cout << "For deleting a book, enter title of the book : ";
    cin.ignore();
    getline(cin, search);

    ifstream infile("library_Data.txt", ios::in);
    ofstream outfile("temp_Data.txt", ios::out);

    bool found = false;
    string line;

    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "\nUnable to open the file(s)\n";
        return;
    }
    // Read from the original file and write to the temporary file
    while (getline(infile, line))
    {
        string title;
        istringstream linestream(line);

        if (getline(linestream, title, ','))
        {
            if (title != search)
                // Write line to temp file if it does not match
                outfile << line << endl;

            else
            {
                found = true;
            }
        }
        else
        {
            // Write the line to the temp file if it doesn't match expected format
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();
    if (found)
    {
        cout << "\nBook deleted successfully!" << endl;
    }
    else
    {
        cout << "\nBook not found!" << endl;
    }
   
    // Remove the original file
    if (remove("library_Data.txt") != 0)
    {
        cout << "Error deleting the original file.\n";
        return;
    }
     // Rename the temporary file to the original file name
     if (rename("temp_Data.txt", "library_Data.txt") != 0)
    {
        cout << "Error renaming the temporary file.\n";
        return;
    }
}

void LIBRARIAN::Book_issue()
{
    cout << "Enter the title of the book you want to issue : ";
    cin.ignore();
    getline(cin, search);

    bool found = false;
    string line;
    ifstream infile("library_Data.txt", ios::in);
    ofstream outfile("temp_Data.txt", ios::out);

    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "\nUnable to open the file(s)\n";
        return;
    }

    while (getline(infile, line))
    {
        string title, author, ISBN;
        bool issued = false;
        istringstream linestream(line);

        if (getline(linestream, title, ','))
        {
            getline(linestream, author, ',');
            getline(linestream, ISBN, ',');
            linestream >> issued;

            if (title == search)
            {
                if (issued)
                {
                    cout << "\nThis book is already issued!" << endl;
                }
                else
                {
                    issued = true; // Mark the book as issued
                    outfile << title << ", " << author << ", " << ISBN << ", " << issued << endl;
                    cout << "\nBook issued successfully!" << endl;
                }
                found = true;
            }
            else
            {
                // Write unchanged lines to temp file
                outfile << title << ", " << author << ", " << ISBN << ", " << issued << endl;
            }
        }
        else
        {
            // Handle the case where the line format is not as expected
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    if (!found)
    {
        cout << "\nBook not available!" << endl;
    }

    if (remove("library_Data.txt") != 0)
    {
        cout << "Error deleting the original file.\n";
        return;
    }
     if (rename("temp_Data.txt", "library_Data.txt") != 0)
    {
        cout << "Error renaming the temporary file.\n";
        return;
    }
}

void LIBRARIAN::Book_return()
{
   
   cout << "Enter the title of the book you want to return : ";
    cin.ignore();
    getline(cin, search);

    bool found = false;
    string line;
    ifstream infile("library_Data.txt", ios::in);
    ofstream outfile("temp_Data.txt", ios::out);

    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "\nUnable to open the file(s)\n";
        return;
    }

    while (getline(infile, line))
    {
        string title, author, ISBN;
        bool issued = false;
        istringstream linestream(line);

        if (getline(linestream, title, ','))
        {
            getline(linestream, author, ',');
            getline(linestream, ISBN, ',');
            linestream >> issued;

            if (title == search)
            {
                if (issued)
                {    
                    issued = false; // Mark the book as issued
                    outfile << title << ", " << author << ", " << ISBN << ", " << issued << endl;
                    cout << "\nBook returned successfully!" << endl;
                   
                }
                else
                {
                    cout << "\nThis book was not issued!" << endl;
                }
                found = true;
            }
            else
            {
                // Write unchanged lines to temp file
                outfile << title << ", " << author << ", " << ISBN << ", " << issued << endl;
            }
        }
        else
        {
            // Handle the case where the line format is not as expected
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    if (!found)
    {
        cout << "\nBook not available!" << endl;
    }

    if (remove("library_Data.txt") != 0)
    {
        cout << "Error deleting the original file.\n";
        return;
    }
     if (rename("temp_Data.txt", "library_Data.txt") != 0)
    {
        cout << "Error renaming the temporary file.\n";
        return;
    }
}


int main()
{
    int num, semester;
    char chr;
    LIBRARIAN obj;
    cout << "***LIBRARY MANAGMENT SYSTEM***";
    obj.credentials();
    obj.menu();

    return 0;
}