#ifndef STUDENTUSER_H
#define STUDENTUSER_H
#include "LibraryUser.h"
class StudentUser:public LibraryUser{
    public:
    StudentUser(int id,const string& name);
    string roleName()const override;
    int maxBorrow()const override;
    double lateFeePerDay() const override;
    int loanDayFor(ItemType type)const override;
    bool canBorrowType(ItemType type)const override;
};
#endif