#ifndef Book_H
#define Book_H
#include<iostream>




class Book{

public:  
    std::string title;
    std::string author_name;
    std::string category;
    int pages;

    Book(std::string bookTitle, std::string authorName, std::string book_category){
         title = bookTitle;
         author_name = authorName;
        category = book_category;
        pages=0;
    }

    void getBookInfo()
    {
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cout<<"====== Book Info ======"<<std::endl;
        std::cout<<"Title: "<<title<<std::endl;
        std::cout<<"Author: "<<author_name<<std::endl;
        std::cout<<"Category: "<<category<<std::endl;
        std::cout<<"Pages: "<<pages<<std::endl;
        std::cout<<"==========================="<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
        
        
    }

};

#endif