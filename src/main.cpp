#include<iostream>
#include"LibraryItem.h"
#include"Book.h"
using namespace std;
int main(){
    //create a book
    Book b(101,"clean code:");
    cout<<b.info()<<endl;
    return 0;
}