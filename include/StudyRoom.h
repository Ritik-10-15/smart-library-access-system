#ifndef STUDYROOM_H
#define STUDYROOM_H
#include"LibraryItem.h"
class Studyroom:public LibraryItem{
    public:
    Studyroom(int id,const string& title);
    ItemType type() const override;

};
#endif