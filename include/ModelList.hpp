#ifndef MODELLIST_HPP
#define MODELLIST_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include "VariantList.hpp" 

struct ModelNode 
{
    std::string modelName;
    std::string manufacturer;
    VariantList variants; 
    ModelNode* next; 

    ModelNode(std::string name, std::string make)
        : modelName(name), manufacturer(make), next(NULL) {}
};

class ModelList 
{
private:
    ModelNode* head;

public:
    ModelList();
    ~ModelList(); 

    void addModel(std::string name, std::string make);
    ModelNode* findModel(std::string name) const;
    void displayAllModels() const;
};

#endif