#ifndef SPECSTACK_HPP
#define SPECSTACK_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include "VariantList.hpp"

struct StackNode 
{
    VariantNode* viewedTrim; 
    StackNode* next;

    StackNode(VariantNode* trim) : viewedTrim(trim), next(NULL) {}
};

class SpecStack 
{
private:
    StackNode* top;

public:
    SpecStack();
    ~SpecStack();

    void push(VariantNode* trim);
    void pop();
    void displayHistory() const;
};

#endif