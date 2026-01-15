#ifndef LAPTOP_H
#define LAPTOP_H
#include"LibraryItem.h"
class Laptop:public LibraryItem{
    public:
    Laptop(int id,const string& title);
    ItemType type() const override;

};
#endif
