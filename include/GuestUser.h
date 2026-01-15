#ifndef GUESTUSER_H
#define GUESTUSER_H
#include"LibraryUser.h"
class GuestUser:public LibraryUser{
    public:
    GuestUser(int id, const string& name);
    string roleName() const override;
    int maxBorrow()const override;
    double lateFeePerDay() const override;
    int loanDayFor(ItemType type)const override;
    bool canBorrowType(ItemType type)const override;
};
#endif