#include "user.h"
#include <vector>
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

std::vector<Product*> User::getCart() const
{
    return cart_;
}
void User::addCart(Product* p){
    cart_.push_back(p);
}
void User::buyCart()
{   
    std::vector<Product*> notBought;
    for(size_t i=0; i<cart_.size(); i++){
        Product* temp=cart_[i];
        if(temp->getQty()>0){
            double price = temp->getPrice();
            if(price<=balance_){
                balance_-=price;
                temp->subtractQty(1);
            }else{
                notBought.push_back(cart_[i]);
            }
        }else{
            notBought.push_back(cart_[i]);
        }
    }
    cart_=notBought;
}