#include "../include/ModelList.hpp"

ModelList::ModelList() : head(NULL) {}

ModelList::~ModelList() {
    ModelNode* current = head;
    while (current != NULL) {
        ModelNode* nextNode = current->next;
        delete current; 
        current = nextNode;
    }
}

void ModelList::addModel(std::string name, std::string make) {
    ModelNode* newNode = new ModelNode(name, make); 
    
    if (head == NULL) {
        head = newNode;
    } else {
        ModelNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

ModelNode* ModelList::findModel(std::string name) const {
    ModelNode* current = head;
    while (current != NULL) {
        if (current->modelName == name) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

void ModelList::displayAllModels() const {
    if (head == NULL) {
        std::cout << "No models available in this segment.\n";
        return;
    }

    ModelNode* current = head;
    std::cout << "\n--- Available Models ---\n";
    while (current != NULL) {
        std::cout << "-> " << current->manufacturer << " " << current->modelName << "\n";
        current = current->next;
    }
}