#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "movie.h"
#include "util.h"


std::set<std::string> Movie::keywords() const{
    std::set<std::string> temp=parseStringToWords(name_);
    temp.insert(convToLower(genre_));
    return temp;
}

std::string Movie::displayString() const{
    std::string s;
    s=name_+"\n"+"Genre: "+genre_+" Rating: "+rating_+"\n"+std::to_string(price_)+" "+std::to_string(qty_)+" left.";
    return s;
}

void Movie::dump(std::ostream& os) const{
    Product::dump(os);
    os<<genre_<<std::endl<<rating_<<std::endl;
}