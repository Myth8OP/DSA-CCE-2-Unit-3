#ifndef UINODE_HPP
#define UINODE_HPP

#include <string>

struct UINode 
{
    std::string component;
    UINode* left;
    UINode* right;

    UINode(std::string compName);
};

#endif