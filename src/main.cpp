#include<iostream>
#include"LibraryUser.h"
#include"LibraryItem.h"
#include"Book.h"
#include"StudentUser.h"
using namespace std;
int main(){
    //create a book
    Book b(101,"clean code:");
    cout<<b.info()<<endl;
    //create a student
    StudentUser s(102,"Ritik");
    cout<<s.info()<<endl;
    return 0;
}