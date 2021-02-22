#pragma once

#include <memory>

template<class Item>
class Deque {
private:
    struct Node {
        Item data;
        Node* next;
        Node(Item data): data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int m_size;
public:
    Deque() : head(nullptr), tail(nullptr), m_size(0){}
    bool isEmpty()
    {
        return m_size == 0;
    }
    int size(){
        return m_size;
    }
    // void pushFront(Item item);
    void pushBack(Item item)
    {
        auto temp = new Node(item); 
        if (isEmpty())
        {
            head = std::move(temp);
            tail = head;
        }
        else
        {
            tail->next = std::move(temp);
            tail = tail->next;
        }
        m_size++;
    }
    // Item popFront();
    // Item popBack();
};