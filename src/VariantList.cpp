#include "../include/VariantList.hpp"

VariantList::VariantList() : head(NULL), tail(NULL) {}

VariantList::~VariantList() {
    VariantNode* current = head;
    while (current != NULL) {
        VariantNode* nextNode = current->next;
        delete current; 
        current = nextNode;
    }
}

void VariantList::addVariant(std::string name, std::string engine, int hp, int torque, double price) {
    VariantNode* newNode = new VariantNode(name, engine, hp, torque, price);
    
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void VariantList::displayAllVariants() const {
    VariantNode* temp = head;
    std::cout << "\n--- Available Trims ---\n";
    while (temp != NULL) {
        std::cout << "[" << temp->trimName << "] -> ";
        temp = temp->next;
    }
    std::cout << "END\n";
}

void VariantList::compareNext(VariantNode* current) const {
    if (current != NULL && current->next != NULL) {
        VariantNode* upgrade = current->next;
        std::cout << "\nUpgrading from " << current->trimName << " to " << upgrade->trimName << ":\n";
        std::cout << "Price Delta: +Rs " << (upgrade->priceLakhs - current->priceLakhs) << " Lakhs\n";
        std::cout << "Power Delta: +" << (upgrade->horsepower - current->horsepower) << " HP\n";
    } else {
        std::cout << "\nThis is the top-spec trim. No upgrades available.\n";
    }
}

void VariantList::comparePrev(VariantNode* current) const {
    if (current != NULL && current->prev != NULL) {
        VariantNode* downgrade = current->prev;
        std::cout << "\nDowngrading from " << current->trimName << " to " << downgrade->trimName << ":\n";
        std::cout << "Money Saved: Rs " << (current->priceLakhs - downgrade->priceLakhs) << " Lakhs\n";
        std::cout << "Power Lost: -" << (current->horsepower - downgrade->horsepower) << " HP\n";
    } else {
        std::cout << "\nThis is the base-spec trim. No downgrades available.\n";
    }
}