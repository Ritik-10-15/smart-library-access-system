#include<iostream>
#include<memory>
#include"LibrarySystem.h"
#include"StudentUser.h"
#include"FacultyUser.h"
#include"GuestUser.h"
#include"Book.h"
#include"Laptop.h"
#include"Studyroom.h"
using namespace std;
int main(){
    LibrarySystem sys;
    sys.addUser(make_unique<StudentUser>(1,"Ritik"));
    sys.addUser(make_unique<FacultyUser>(2,"Dr.smith"));
    sys.addUser(make_unique<GuestUser>(3,"visitor"));
    sys.addItem(make_unique<Book>(101,"clean code"));
    sys.addItem(make_unique<Laptop>(201,"Dell XPS"));
    sys.addItem(make_unique<Studyroom>(301,"Room A"));
    sys.listUsers();
    sys.listItems();
    sys.borrowItem(1,201);//student borrows laptop
    sys.borrowItem(3,201);//guest tries laptop
    sys.advanceDays(10);
    sys.returnItem(1,201);
    sys.listUsers();
    sys.listItems();
}

