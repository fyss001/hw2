#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "book.h"
#include "util.h"


std::set<std::string> Book::keywords() const{
    std::set<std::string> temp=parseStringToWords(name_);
    std::set<std::string> temp_author = parseStringToWords(author_);
    std::set<std::string> ans = setUnion(temp,temp_author);
    ans.insert(isbn_);
    return ans;
}

std::string Book::displayString() const{
    std::string s;
    s=name_+"\n"+"Author: "+author_+" ISBN: "+isbn_+"\n"+std::to_string(price_)+" "+std::to_string(qty_)+" left.";
    return s;
}

void Book::dump(std::ostream& os) const{
    Product::dump(os);
    os<<isbn_<<std::endl<<author_<<std::endl;
}