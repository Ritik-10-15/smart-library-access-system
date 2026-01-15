#include"Laptop.h"
Laptop::Laptop(int id, const string& title):LibraryItem(id,title){}
ItemType Laptop::type()const{
    return ItemType::Laptop;
}