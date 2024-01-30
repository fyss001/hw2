#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "datastore.h"


class MyDataStore : public DataStore{
    public:
        MyDataStore();
        ~MyDataStore();
        void addProduct(Product* p);
        void addUser(User* u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);
        User* getUserByName(std::string name);


    private:
        void dumphelper(std::ostream& ofile, Product* p);
        void dumphelper2(std::ostream& ofile, User* u);
        std::vector<Product*> productList_;
        std::vector<User*> userList_;
};

#endif
