#ifndef SEGMENTLIST_HPP
#define SEGMENTLIST_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include "ModelList.hpp" 

struct SegmentNode 
{
    std::string segmentName; 
    ModelList models;        
    SegmentNode* next;

    SegmentNode(std::string name)
        : segmentName(name), next(NULL) {}
};

class SegmentList 
{
private:
    SegmentNode* head;

public:
    SegmentList();
    ~SegmentList(); 

    void addSegment(const std::string& name);
    SegmentNode* findSegment(const std::string& name) const;
    void displaySegments() const;
    SegmentNode* getHead() const { return head; }
};

#endif