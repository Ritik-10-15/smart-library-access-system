#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H
#include <vector>
#include<memory>
#include<string>
#include<iostream>
#include"LibraryUser.h"
#include"LibraryItem.h"
class LibrarySystem{
    private:
    int currentDay;
    //store polymorphic objects safely
    vector<unique_ptr<LibraryUser>> users;
    vector<unique_ptr<LibraryItem>> items;
    //helper finders(return raw pointer to object inside unique_ptr)
    LibraryUser* findUserId(int userId);
    LibraryItem* findItemId(int itemId);
    public:
    LibrarySystem();
    int getCurrentDay()const;
    void advanceDays(int days);
    //adding entities
    void addUser(unique_ptr<LibraryUser> user);
    void addItem(unique_ptr<LibraryItem> item);
    //Display helpers
    void listUsers()const;
    void listItems()const;
    //core features
    bool borrowItem(int userId,int itemId);
    bool returnItem(int userId, int itemId);


};
#endif