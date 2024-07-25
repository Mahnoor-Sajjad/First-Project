#include<iostream>
using namespace std;

class USER {
    public:
    void choose () {
        /* whether the user is staff or a member
           if he/she is a member then check the status: current member| new member*/
    }
};

class LIBRARIAN : public USER {
         /*librarian has to manage books record:
        Book issued, book that has to be returned , add book,
        delete book , display the issued books */
};

class MEMBER : public USER {
     /*current and new members have almost all the features but 
     the current member has a previous record which new members do not have. */
};






int main()
{
    cout << "LIBRARY MANAGMENT SYSTEM.";
    return 0;
}