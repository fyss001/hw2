#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
class Movie : public Product{
    public:
        Movie(std::string category,std::string name, double price, int qty, std::string genre, std::string rating) : Product(category, name, price, qty){
            genre_ = genre;
            rating_ = rating;
        }
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;

    private:
        std::string genre_, rating_;
};


#endif