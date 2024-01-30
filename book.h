#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
class Book : public Product{
    public:
        Book(std::string category,std::string name, double price, int qty, std::string author, std::string isbn) : Product(category, name, price, qty){
            isbn_=isbn;
            author_=author;
        }
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;

    private:
        std::string author_, isbn_;
};


#endif