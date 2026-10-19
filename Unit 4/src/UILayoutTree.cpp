#include <iostream>
#include "../include/UILayoutTree.hpp"

UINode::UINode(std::string compName) 
{
    component = compName;
    left = NULL;
    right = NULL;
}

UILayoutTree::UILayoutTree() {}
UILayoutTree::~UILayoutTree() {}

//Recursively create a mirror image of the tree
UINode* UILayoutTree::createMirror(UINode* root) 
{
    if (root == NULL) 
    {
        return NULL;
    }

    //Allocate new mirrored node
    UINode* mirroredNode = new UINode(root->component);

    //Swap left and right subtrees via Post-Order Traversal
    mirroredNode->left = createMirror(root->right);
    mirroredNode->right = createMirror(root->left);

    return mirroredNode;
}

//Check if two trees are exact mirror images
bool UILayoutTree::areMirrors(UINode* root1, UINode* root2) 
{
    //Both nodes are NULL -> valid mirrors
    if (root1 == NULL && root2 == NULL) return true;
    
    //Only one node is NULL -> structure mismatch
    if (root1 == NULL || root2 == NULL) return false;
    
    // 1. Data must match
    // 2. Left subtree of Tree1 must mirror Right subtree of Tree2
    // 3. Right subtree of Tree1 must mirror Left subtree of Tree2
    return (root1->component == root2->component) &&
           areMirrors(root1->left, root2->right) &&
           areMirrors(root1->right, root2->left);
}

//Visually print the tree sideways on the console
void UILayoutTree::print2DTree(UINode* root, int space) 
{
    if (root == NULL) return;

    int COUNT = 12;
    space += COUNT;

    //Right child goes at the top of the screen
    print2DTree(root->right, space);

    std::cout << "\n";
    for (int i = COUNT; i < space; i++) 
    {
        std::cout << " ";
    }
    std::cout << "[" << root->component << "]\n";

    //Left child goes at the bottom
    print2DTree(root->left, space);
}

//Safely deallocate dynamic memory (Post-Order Deletion)
void UILayoutTree::destroyTree(UINode* root) 
{
    if (root != NULL) 
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}