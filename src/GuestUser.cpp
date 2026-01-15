#include"GuestUser.h"
GuestUser::GuestUser(int id, const string& name):LibraryUser(id,name){}
string GuestUser::roleName() const{
    return "GUEST";
}
int GuestUser::maxBorrow() const{
    return 1;
}
double GuestUser::lateFeePerDay()const{
    return 0.50;
}
int GuestUser::loanDayFor(ItemType type)const{
    //0 days means, not allowed in our design
    if(type==ItemType::Book) return 7;
    if(type==ItemType::Studyroom) return 1;
    if(type==ItemType::Laptop) return 0;
    return 0;
}
bool GuestUser::canBorrowType(ItemType type)const{
    return type!=ItemType::Laptop;//guests cannot borrow laptops
}