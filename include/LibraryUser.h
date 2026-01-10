#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H
#include<string>
#include<vector>
#include"LibraryItem.h"
class LibraryUser{
    protected:
    int userId;
    string name;
    vector<int>borrowedItemId;
    double totalFine;
    public:
    //constructor
    LibraryUser(int id,const string& name);
    virtual ~LibraryUser()=default;
    //getter
    int getId()const;
    string getName()const;
    double getTotalFine()const;
    const vector<int>& getBorrowedItem()const;
    //Borrow tracking
    void addBorrowedItem(int itemId);
    bool removeBorrowedItem(int itemId);
    //fine handling
    void addFine(double amount);
    //polymorphic 
    virtual string roleName()const=0;
    virtual int maxBorrow()const=0;
    virtual double lateFeePerDay()const=0;
    virtual int loanDayFor(ItemType type)const=0;
    virtual bool canBorrowType(ItemType type)const=0;
    
    bool maxLimit()const;
    //display info
    virtual string info() const;
};
#endif