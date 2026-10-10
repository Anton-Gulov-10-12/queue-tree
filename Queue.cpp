#include "Queue.h"

void Queue::clear() {
    while (front) {
        Node* temp = front;
        front = front->right;
        delete temp;
    }
    back = nullptr;
    sz = 0;
}

void Queue::copy(const Queue& other) {
    front = back = nullptr;
    sz = 0;
    Node* cur = other.front;
    while (cur) {
        *this << cur->value;  
        cur = cur->right;
    }
}

Queue::Queue() : front(nullptr), back(nullptr), sz(0) {}

Queue::Queue(const Queue& other) {
    copy(other);
}

Queue::~Queue() {
    clear();
}

Queue& Queue::operator=(const Queue& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

Queue& Queue::operator<<(int value) {
    Node* node = new Node(value);
    if (empty()) {
        front = back = node;
    } else {
        back->right = node;
        back = node;
    }
    ++sz;
    return *this;
}

Queue& Queue::operator>>(int& value) {
    if (empty()) {
        return *this;
    }
    value = front->value;
    Node* temp = front;
    front = front->right;
    if (!front) back = nullptr;
    delete temp;
    --sz;
    return *this;
}

Queue Queue::operator+(const Queue& other) const {
    Queue result = *this;
    result += other;
    return result;
}

Queue& Queue::operator+=(const Queue& other) {
    Node* cur = other.front;
    while (cur) {
        *this << cur->value;
        cur = cur->right;
    }
    return *this;
}

bool Queue::operator==(const Queue& other) const {
    if (sz != other.sz) return false;
    Node* a = front;
    Node* b = other.front;
    while (a) {
        if (a->value != b->value) return false;
        a = a->right;
        b = b->right;
    }
    return true;
}

bool Queue::operator!=(const Queue& other) const {
    return !(*this == other);
}

bool Queue::operator<(const Queue& other) const {
    Node* a = front;
    Node* b = other.front;
    while (a && b) {
        if (a->value < b->value) return true;
        if (a->value > b->value) return false;
        a = a->right;
        b = b->right;
    }

    return (a == nullptr && b != nullptr);
}

bool Queue::operator<=(const Queue& other) const {
    return !(*this > other);
}

bool Queue::operator>(const Queue& other) const {
    return other < *this;
}

bool Queue::operator>=(const Queue& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Queue& q) {
    os << "[ ";
    Queue::Node* cur = q.front;
    while (cur) {
        os << cur->value;
        if (cur->right) os << " ";
        cur = cur->right;
    }
    os << " ]";
    return os;
}

std::istream& operator>>(std::istream& is, Queue& q) {
    q.clear();
    int x;
    while (is >> x) {
        q << x;
    }
    return is;
}
