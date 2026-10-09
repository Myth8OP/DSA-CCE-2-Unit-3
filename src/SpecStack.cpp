#include "../include/SpecStack.hpp"

SpecStack::SpecStack() : top(NULL) {}

SpecStack::~SpecStack() {
    while (top != NULL) {
        pop();
    }
}

void SpecStack::push(VariantNode* trim) {
    if (trim == NULL) return;
    
    StackNode* newNode = new StackNode(trim);
    newNode->next = top;
    top = newNode;
}

void SpecStack::pop() {
    if (top == NULL) {
        std::cout << "Viewing history is empty.\n";
        return;
    }
    StackNode* temp = top;
    top = top->next;
    delete temp; 
}

void SpecStack::displayHistory() const {
    if (top == NULL) {
        std::cout << "\nNo recently viewed trims.\n";
        return;
    }

    StackNode* current = top;
    std::cout << "\n--- Recently Viewed (Newest First) ---\n";
    while (current != NULL) {
        std::cout << "-> " << current->viewedTrim->trimName 
                  << " (Rs " << current->viewedTrim->priceLakhs << " Lakhs)\n";
        current = current->next;
    }
}