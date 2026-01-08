#ifndef BOOK_H
#define BOOK_H
#include"LibraryItem.h"
using namespace std;
class Book:public LibraryItem{
    public:
    Book(int id, const string& ti);
    ItemType type() const override;
};
#endif