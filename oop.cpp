#include <iostream>
#include "./Book.h"


int main()
{
    Book book1("Atomic Habit", "James Clear", "Non-Fiction");
    book1.pages=235;
    book1.getBookInfo();
    
    Book book2("Eat that frog", "JBrain Tracey", "Non-Fiction");
    book2.pages=200;
    book2.getBookInfo();

    Book book3("40 Lows of Power", "Robert Green", "Non-Fiction");
    book3.pages=324;
    book3.getBookInfo();
    return 0;
}