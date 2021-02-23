#pragma once

#include <variant>
#include <iostream>

template<class Item>
class Deque {
private:
    struct Node {
        Item data;
        Node* next;
        Node* prev;
        Node(Item &data): data(data), next(nullptr), prev(nullptr) {}
    };

    struct Iterator {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;

        Iterator(Node* ptr) : m_ptr(ptr) {}

        Item& operator*() const { return m_ptr->data; }
        Node* operator->() { return m_ptr; }
        
        // ++i
        Iterator& operator++() { m_ptr = m_ptr->next; return *this; }
        // i++
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (Iterator const& a, Iterator const& b) { return a.m_ptr == b.m_ptr; }
        friend bool operator!= (Iterator const& a, Iterator const& b) { return a.m_ptr != b.m_ptr; }
    private:
        Node* m_ptr;
    };

    Node* head;
    Node* tail;
    int m_size;
public:
    Deque() : head(nullptr), tail(nullptr), m_size(0){}
    ~Deque()
    {
        auto p = head;
        while(p != nullptr)
        {
            auto temp = p;
            p = p->next;
            std::cout << "deleting: " << temp->data << std::endl;
            delete temp;
        }
    }
    bool isEmpty()
    {
        return m_size == 0;
    }
    int size(){
        return m_size;
    }

    void pushFront(Item item)
    {
		auto temp = new Node(item); 
        if (isEmpty())
        {
            head = temp;
            tail = head;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        m_size++;

    }

    void pushBack(Item item)
    {
        auto temp = new Node(item); 
        if (isEmpty())
        {
            head = temp;
            tail = head;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = tail->next;
        }
        m_size++;
    }

    void popFront()
    {
		// check it's not empty!
        if (isEmpty()) return;
        auto temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
	}

    void popBack()
    {
        // check it's not empty!
        if (isEmpty()) return;
        auto temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};