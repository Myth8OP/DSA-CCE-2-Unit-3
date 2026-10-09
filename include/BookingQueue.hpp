#ifndef BOOKINGQUEUE_HPP
#define BOOKINGQUEUE_HPP

#include <iostream>
#include <string>
#include <cstddef>

struct QueueNode 
{
    std::string customerName;
    std::string requestedCar;
    QueueNode* next;

    QueueNode(std::string name, std::string car)
        : customerName(name), requestedCar(car), next(NULL) {}
};

class BookingQueue 
{
private:
    QueueNode* front;
    QueueNode* rear;

public:
    BookingQueue();
    ~BookingQueue();

    void enqueue(std::string name, std::string car);
    void dequeue();
    void displayQueue() const;
};

#endif