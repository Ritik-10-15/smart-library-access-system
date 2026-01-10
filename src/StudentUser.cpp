#include"StudentUser.h"
StudentUser::StudentUser(int id,const string&name):LibraryUser(id,name){}
string StudentUser::roleName()const{
    return "STUDENT";
}
int StudentUser::maxBorrow()const{
    return 3;
}
double StudentUser::lateFeePerDay()const{
    return 0.25;
}
int StudentUser::loanDayFor(ItemType type)const{
    if(type==ItemType::Book)return 14;
    if(type==ItemType::Laptop)return 7;
    if(type==ItemType::Studyroom)return 1;
    return 0;
}
bool StudentUser::canBorrowType(ItemType)const{
    return true;
}