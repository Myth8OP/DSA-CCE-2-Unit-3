#include "../include/BookingQueue.hpp"

BookingQueue::BookingQueue() : front(NULL), rear(NULL) {}

BookingQueue::~BookingQueue() 
{
    while (front != NULL) 
    {
        dequeue();
    }
}

void BookingQueue::enqueue(std::string name, std::string car) 
{
    QueueNode* newNode = new QueueNode(name, car);
    
    if (rear == NULL) 
    {
        front = rear = newNode;
        std::cout << "Booking confirmed for " << name << ".\n";
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
    std::cout << "Booking added to waitlist for " << name << ".\n";
}

void BookingQueue::dequeue() 
{
    if (front == NULL) 
    {
        std::cout << "No pending test drive bookings.\n";
        return;
    }
    
    QueueNode* temp = front;
    std::cout << "Processing test drive for: " << temp->customerName 
              << " (" << temp->requestedCar << ")\n";
              
    front = front->next;
    
    if (front == NULL) 
    {
        rear = NULL; 
    }
    
    delete temp; 
}

void BookingQueue::displayQueue() const 
{
    if (front == NULL)
    {
        std::cout << "\nTest drive queue is currently empty.\n";
        return;
    }

    QueueNode* current = front;
    int position = 1;
    std::cout << "\n--- Pending Test Drives ---\n";
    while (current != NULL) 
    {
        std::cout << position++ << ". " << current->customerName 
                  << " - " << current->requestedCar << "\n";
        current = current->next;
    }
}