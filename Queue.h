#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
private:
    struct Node {
        int value;
        Node* left;   
        Node* right;  

        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* front;
    Node* back;
    int sz; 

    void copy(const Queue& other);
    void clear();

public:
    Queue();
    Queue(const Queue& other);
    ~Queue();

    Queue& operator=(const Queue& other);

    Queue& operator<<(int value);           // положить элемент
    Queue& operator>>(int& value);          // вытащить элемент

    // Объединение очередей
    Queue operator+(const Queue& other) const;
    Queue& operator+=(const Queue& other);

    // Сравнение
    bool operator==(const Queue& other) const;
    bool operator!=(const Queue& other) const;
    bool operator<(const Queue& other) const;
    bool operator<=(const Queue& other) const;
    bool operator>(const Queue& other) const;
    bool operator>=(const Queue& other) const;

    // Ввод / вывод всей очереди
    friend std::ostream& operator<<(std::ostream& os, const Queue& q);
    friend std::istream& operator>>(std::istream& is, Queue& q);

    bool empty() const { return front == nullptr; }
    int size() const { return sz; }
};

#endif