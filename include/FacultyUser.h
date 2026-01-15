#ifndef FACULTYUSER_H
#define FACULTYUSER_H
#include"LibraryUser.h"
class FacultyUser:public LibraryUser{
    public:
    FacultyUser(int id, const string& name);
    string roleName()const override;
    int maxBorrow() const override;
    double lateFeePerDay() const override;
    int loanDayFor(ItemType type)const override;
    bool canBorrowType(ItemType type)const override;
    
};
#endif