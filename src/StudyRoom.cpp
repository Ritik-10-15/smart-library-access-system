#include"Studyroom.h"
Studyroom::Studyroom(int id,const string& title):LibraryItem(id,title){}
ItemType Studyroom::type()const{
    return ItemType::Studyroom;
}