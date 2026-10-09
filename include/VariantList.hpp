#ifndef VARIANTLIST_HPP
#define VARIANTLIST_HPP

#include <iostream>
#include <string>
#include <cstddef> // Required for NULL in older compilers

struct VariantNode {
    std::string trimName;
    std::string engineType;
    int horsepower;
    int torqueNm;
    double priceLakhs;
    
    VariantNode* prev;
    VariantNode* next;

    VariantNode(std::string name, std::string engine, int hp, int torque, double price)
        : trimName(name), engineType(engine), horsepower(hp), torqueNm(torque), 
          priceLakhs(price), prev(NULL), next(NULL) {}
};

class VariantList {
private:
    VariantNode* head;
    VariantNode* tail;

public:
    VariantList();
    ~VariantList(); 

    void addVariant(std::string name, std::string engine, int hp, int torque, double price);
    void displayAllVariants() const;
    void compareNext(VariantNode* current) const; 
    void comparePrev(VariantNode* current) const; 
    
    VariantNode* getHead() const { return head; }
};

#endif