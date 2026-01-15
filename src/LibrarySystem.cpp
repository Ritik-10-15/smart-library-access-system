#include"LibrarySystem.h"
using namespace std;
//constructor
LibrarySystem::LibrarySystem():currentDay(0){}
//Get current day
int LibrarySystem::getCurrentDay()const{
    return currentDay;
}
//Advance time in the system
void LibrarySystem::advanceDays(int days){
    if(days<0)return;
    currentDay+=days;
}
// Add a user
void LibrarySystem::addUser(unique_ptr<LibraryUser>user){
    users.push_back(move(user));
}
//Add an item
void LibrarySystem::addItem(unique_ptr<LibraryItem>item){
    items.push_back(move(item));
}
//Find user by ID
LibraryUser* LibrarySystem::findUserId(int userId){
    for(auto& u:users){
        if(u->getId()==userId) return u.get();

    }
    return nullptr;
}
// Find item by ID
LibraryItem* LibrarySystem::findItemId(int itemId){
    for(auto& it:items){
        if(it->getId()==itemId)return it.get();
    }
    return nullptr;
}
//list all users
void LibrarySystem::listUsers() const{
    cout<<"\n----USERS----\n";
    for(const auto& u:users){
        cout<<u->info()<<"\n";
    }
}
//list all items
void LibrarySystem::listItems()const{
    cout<<"\n-----ITEMS---\n";
    for(const auto& it:items){
        cout<<it->info();
        //show extra borrow info if borrowed
        if(!it->isAvailable()){
            cout<<"| BorrowedBy="<<it->getBorrowedBy()
            <<"|DueDay="<<it->getDueDay();
        }
        cout<<"\n";
    }
}
//Borrow an item
bool LibrarySystem::borrowItem(int userId,int itemId){
    LibraryUser* user=findUserId(userId);
    if(!user){
        cout<<"Borrow failed:User"<<userId<<"not found.\n";
        return false;
    }
    LibraryItem* item=findItemId(itemId);
    if(!item){
        cout<<"Borrow failed:Item"<<itemId<<"not found.\n";
        return false;
    }
    if(!item->isAvailable()){
        cout<<"Borrow failed:Item is already borrowed.\n";
        return false;
    }
    //limit
    if(user->maxLimit()){
        cout<<"Borrow failed:Borrow limit reached for"<<user->roleName()<<".\n";
        return false;
    }
    //permission by item type
    ItemType t=item->type();
    if(!user->canBorrowType(t)){
        cout<<"Borrow failed:"<<user->roleName()
            <<"cannot borrow"<<itemTypeToString(t)<<".\n";
        return false;
    }
    //due day based on user rules
    int loanDays=user->loanDayFor(t);
    if(loanDays<=0){
        cout<<"Borrow failed: Loan days rule returned 0(not allowed).\n";
        return false;
    }
    int due=currentDay+loanDays;
    //update both sides
    item->markBorrowed(userId,due);
    user->addBorrowedItem(itemId);
    cout<<"Borrow success:"<<user->getName()
        <<"borrowed\""<<item->getTitle()
        <<"\"until day"<<due<<".\n";
        return true;
}
// return an item and apply late fees if needed
bool LibrarySystem::returnItem(int userId,int itemId){
    LibraryUser* user=findUserId(userId);
    if(!user){
        cout<<"Return failed:user"<<userId<<"not found.\n";
        return false;
    }
    LibraryItem* item=findItemId(itemId);
    if(!item){
        cout<<"Return failed:Item"<<itemId<<"not found.\n";
        return false;
    }
    if(item->isAvailable()){
        cout<<"Return failed:Item is already available(not borrowed).\n";
        return false;
    }
    if(item->getBorrowedBy()!=userId){
        cout<<"Return failed:Item was borrowed by another user(user"
        <<item->getBorrowedBy()<<").\n";
        return false;
    }
    // late fee calculation
    int due=item->getDueDay();
    int lateDays=currentDay-due;
    if(lateDays>0){
        double fine=lateDays* user->lateFeePerDay();
        user->addFine(fine);
        cout<<"Item returned late by"<<lateDays<<"day(s)."
            <<"Fine added:$"<<fine<<"\n";
    }
    else{
        cout<<"Item returned on time.\n";
    }
    //update both sides
    item->markReturned();
    user->removeBorrowedItem(itemId);
    cout<<"Return success:\""<<item->getTitle()<<"\"returned.\n";
    return true;
}