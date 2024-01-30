#include <string>
#include <set>
#include <vector>
#include "mydatastore.h"
#include "util.h"

MyDataStore::MyDataStore(){
}

MyDataStore::~MyDataStore(){
    for(size_t i=0;i<productList_.size();i++){
        delete productList_[i];
    }
    for(size_t i=0;i<userList_.size();i++){
        delete userList_[i];
    }
}

void MyDataStore::addProduct(Product* p){
    productList_.push_back(p);
}

void MyDataStore::addUser(User* u){
    userList_.push_back(u);
}

User* MyDataStore::getUserByName(std::string name){
    name = convToLower(name);
    for(size_t i=0;i<userList_.size();i++){
        if(convToLower(userList_[i]->getName())==name){
            return userList_[i];
        }
    }
    return nullptr;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::vector<Product*> result;
    for(size_t i=0;i<productList_.size();i++){
        std::set<std::string> temp=productList_[i]->keywords();
        if(!type){
            bool flag=1;
            for(size_t j=0;j<terms.size();j++){
                if(!temp.count(terms[j])){
                    flag=0;
                    break;
                }
            }
            if(flag){
                result.push_back(productList_[i]);
            }
        }else{
            bool flag=0;
            for(size_t j=0;j<terms.size();j++){
                if(temp.count(terms[j])){
                    flag=1;
                    break;
                }
            }
            if(flag){
                result.push_back(productList_[i]);
            }
        }
    }
    return result;
}


void MyDataStore::dump(std::ostream& ofile){
    ofile<<"<products>\n";
    for(size_t i=0;i<productList_.size();i++){
        productList_[i]->dump(ofile);
    }
    ofile<<"</products>\n";
    ofile<<"<users>\n";
    for(size_t i=0;i<userList_.size();i++){
        userList_[i]->dump(ofile);
    }
    ofile<<"</users>\n";
}