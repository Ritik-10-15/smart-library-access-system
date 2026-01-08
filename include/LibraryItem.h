#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include<string>
using namespace std;
enum class ItemType{Book,Laptop,Studyroom};
//function to convert itemType to string
string itemTypeToString(ItemType t);
//Abstract base class for all library items 
class LibraryItem{
    protected:
    int itemId;
    std::string title;
    bool available;
    int borrowedByUserId;
    int dueDay;
public:
    //constructor
    LibraryItem(int id, const string& ti);
    //virtual destructor
    virtual ~LibraryItem()=default;
    //getters
    int getId()const;
    std::string getTitle()const;
    bool isAvailable()const;
    int getBorrowedBy()const;
    int getDueDay()const;
    //state-changing function(used by librarysystem)
    void markBorrowed(int userId,int dueDay);
    void markReturned();
    //pure virtua, derived classes must define it
    virtual ItemType type() const =0;
    //polymorphic description function
    virtual string info() const;
    

     
};
#endif