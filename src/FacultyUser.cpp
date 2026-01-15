#include"FacultyUser.h"
FacultyUser::FacultyUser( int id, const string& name):LibraryUser(id, name){}
string FacultyUser::roleName()const{
    return "FACULTY";
}
int FacultyUser::maxBorrow() const{
    return 10;
}
double FacultyUser::lateFeePerDay() const{
    return 0.10;
}
int FacultyUser::loanDayFor(ItemType type)const{
    if(type==ItemType::Book)return 30;
    if(type==ItemType::Laptop)return 14;
    if(type==ItemType::Studyroom)return 2;
    return 0;
}
bool FacultyUser::canBorrowType(ItemType)const{
    return true;//faculty can borrow all item types
}