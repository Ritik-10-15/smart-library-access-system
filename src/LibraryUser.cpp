#include"LibraryUser.h"
#include<sstream>
using namespace std;
LibraryUser::LibraryUser(int id,const string& userName):
userId(id),name(userName),totalFine(0.0){}
int LibraryUser::getId()const{return userId;}
string LibraryUser::getName()const{ return name;}
double LibraryUser::getTotalFine()const{ return totalFine;}
const vector<int>& LibraryUser::getBorrowedItem()const{
    return borrowedItemId;
}
void LibraryUser::addBorrowedItem(int itemId){
    borrowedItemId.push_back(itemId);
}
bool LibraryUser::removeBorrowedItem(int itemId){
    for(size_t i=0;i<borrowedItemId.size();++i)
    {
        if(borrowedItemId[i]==itemId){
            borrowedItemId.erase(borrowedItemId.begin()+i);
            return true;
        }
    }
    return false;
    }
    void LibraryUser::addFine(double amount){
        if(amount>0){
            totalFine+=amount;
        }
    }
    bool LibraryUser::maxLimit()const{
        return borrowedItemId.size()>=static_cast<size_t>(maxBorrow());
    }
    string LibraryUser::info()const{
        ostringstream oss;
        oss<<"["<<roleName()<<"]"
        <<"Id="<<userId<<"|"
        <<name<<"|"
        <<"Borrowed="<<borrowedItemId.size()
        <<"/"<<maxBorrow()
        <<"| Fines="<<totalFine;
        return oss.str();
    }
