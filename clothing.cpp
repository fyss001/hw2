#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "clothing.h"
#include "util.h"


std::set<std::string> Clothing::keywords() const{
    std::set<std::string> temp=parseStringToWords(name_);
    std::set<std::string> temp_brand = parseStringToWords(brand_);
    std::set<std::string> ans = setUnion(temp,temp_brand);
    return ans;
}

std::string Clothing::displayString() const{
    std::string s;
    s=name_+"\n"+"Size: "+size_+" Brand: "+brand_+"\n"+std::to_string(price_)+" "+std::to_string(qty_)+" left.";
    return s;
}

void Clothing::dump(std::ostream& os) const{
    Product::dump(os);
    os<<size_<<std::endl<<brand_<<std::endl;
}