#include"LibraryItem.h"
#include<sstream>
using namespace std;
//convert enum to string for display
string itemTypeTostring(ItemType t){
    switch(t){
        case ItemType::Book: return "Book";
        case ItemType::Laptop: return "Laptop";
        case ItemType::Studyroom:return "studyroom";
        default:return "Unknown";
    }
}
//construnctor sets default valid state
LibraryItem::LibraryItem(int id, const string& ti)
:itemId(id),title(ti),available(true),borrowedByUserId(-1),dueDay(-1){}
//getters
int LibraryItem::getId() const{return itemId;}
string LibraryItem::getTitle() const{return title;}
bool LibraryItem::isAvailable() const{return available;}
int LibraryItem::getBorrowedBy() const{return borrowedByUserId;}
int LibraryItem::getDueDay() const{ return dueDay;}
//mark item as borrowed
void LibraryItem::markBorrowed( int userId, int due){
    available=false;
    borrowedByUserId=userId;
    dueDay=due;
}
//mark item as returned
void LibraryItem::markReturned(){
    available=true;
    borrowedByUserId=-1;
    dueDay=-1;
}
//default info output(can be overridden)
string LibraryItem::info() const{
    ostringstream oss;
    oss<<"["<<itemTypeTostring(type())<<"]"
    <<"ID="<<itemId<<"|"
    <<title<<"|"
    <<(available?"Available":"Borrowed");
    return oss.str();
}