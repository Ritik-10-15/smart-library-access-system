#include"Book.h"
Book::Book(int id, const string& ti)
:LibraryItem(id,ti){}
ItemType Book::type()const{
    return ItemType::Book;
    
}