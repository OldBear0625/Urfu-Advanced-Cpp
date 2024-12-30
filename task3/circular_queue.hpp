#pragma once

#include <cstddef>
#include <vector>

class CircularQueue {
private:
    std::vector<int> storage;          // Dynamic array to store elements
    size_t max_capacity;               // Maximum size of the queue
    size_t current_size;               // Current count of elements
    size_t head_index;                 // Index of the front element
    size_t tail_index;                 // Index of the rear element

public:
    CircularQueue(size_t size); // создать очередь с определенным размером буффера
    bool Push(int value); // добавить значение в конец очереди (false, если очередь заполнена)
    bool Pop(); // удалить значение из начала очереди (false, если очередь пустая)
    int Front() const; // получить значение из начала очереди (-1, если очередь пустая)
    int Back() const; // получить значение из конца очереди (-1, если очередь пустая)
    bool Empty() const; // проверить пустая ли очередь
    bool Full() const; // проверить заполнена ли очередь
    CircularQueue(size_t max_size);    // Constructor

    bool Push(int value);              // Add value to the end
    bool Pop();                        // Remove value from the front
    int Front() const;                 // Get front value
    int Back() const;                  // Get back value

    bool IsEmpty() const;              // Check if empty
    bool IsFull() const;               // Check if full
};
