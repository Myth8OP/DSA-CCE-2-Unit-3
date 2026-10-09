#include "../include/SegmentList.hpp"

SegmentList::SegmentList() : head(NULL) {}

SegmentList::~SegmentList() {
    if (head == NULL) return;

    SegmentNode* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = NULL; 

    SegmentNode* current = head;
    while (current != NULL) {
        SegmentNode* nextNode = current->next;
        delete current; 
        current = nextNode;
    }
    head = NULL;
}

void SegmentList::addSegment(const std::string& name) {
    SegmentNode* newNode = new SegmentNode(name); 

    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    SegmentNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; 
}

SegmentNode* SegmentList::findSegment(const std::string& name) const {
    if (head == NULL) return NULL;

    SegmentNode* temp = head;
    do {
        if (temp->segmentName == name) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);

    return NULL;
}

void SegmentList::displaySegments() const {
    if (head == NULL) {
        std::cout << "No vehicle segments found.\n";
        return;
    }

    SegmentNode* temp = head;
    std::cout << "\n--- Vehicle Segment Carousel ---\n";
    do {
        std::cout << "[" << temp->segmentName << "] -> ";
        temp = temp->next;
    } while (temp != head);
    std::cout << "(Loops back to " << head->segmentName << ")\n";
}