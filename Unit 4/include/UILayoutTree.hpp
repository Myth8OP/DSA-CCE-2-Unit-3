#ifndef UILAYOUTTREE_HPP
#define UILAYOUTTREE_HPP

#include "UINode.hpp"

class UILayoutTree 
{
public:
    UILayoutTree();
    ~UILayoutTree();

    //Core Algorithms
    UINode* createMirror(UINode* root);
    bool areMirrors(UINode* root1, UINode* root2);
    
    //Visualization & Memory Management
    void print2DTree(UINode* root, int space);
    void destroyTree(UINode* root);
};

#endif