#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "..\Lab1\List.h"

template<class T>
class LinkedList : public List<T> {
private:
    
    class Node {
    public:
        T obj;                 
        Node* next = nullptr;  

        Node(T& obj) {
            this->obj = obj;
        }

    };

    int size = 0;               
    Node* head = nullptr;      
    Node* tail = nullptr;       

public:
    
    ~LinkedList() {
        if (size > 0) {
            tail = head->next;
            for (int i = 0; i < size - 1; i++) {
                delete head;
                head = tail;
                tail = tail->next;
            }
            delete head;
            delete tail;
        }
    }

   
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("your index " + std::to_string(index) + " is greater then the size");

        if (index == 0) {
            if (size == 0) {
                head = new Node(obj);
                tail = head;
            }
            else {
                Node* n = new Node(obj);
                n->next = head;
                head = n;
            }
        }
        else if (index < size) {
            Node* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            Node* new_node = new Node(obj);
            new_node->next = temp->next;
            temp->next = new_node;
        }
        else if (index == size) {
            tail->next = new Node(obj);
            tail = tail->next;
        }
        size++;
    }

    
    void remove(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");
        else if (index < 0)
            index = size - 1;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* temp = head;
            while (index != 1) {
                temp = temp->next;
                index--;
            }
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }

    
    T& get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");
        else if (index < 0)
            index = size - 1;

        if (index == 0) {
            return head->obj;
        }
        else {
            Node* temp = head;
            while (index != 0) {
                temp = temp->next;
                index--;
            }
            return temp->obj;
        }
    }

    
    int find(T obj) override {
        int res = -1;

        Node* temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->obj == obj) {
                res = i;
                break;
            }
            temp = temp->next;
        }
        return res;
    }

   
    void clear() override {
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            if (head->next != nullptr) temp = head->next;
            delete head;
            head = temp;
        }
        head = nullptr;
        size = 0;
    }

    void sort(Sort<T>* sort) override {
        T* arr = new T[size];

        tail = head;
        for (int i = 0; i < size; i++) {
            arr[i] = tail->obj;
            tail = tail->next;
        }

        sort->sort(arr, size);
        
        tail = head;
        for (int i = 0; i < size; i++) {
            tail->obj = arr[i];
            tail = tail->next;
        }

        delete[] arr;
    }

   
    int get_size() override {
        return size;
    }

    
    std::string to_string() override {
        std::stringstream ss;

        ss << '[';
        tail = head;
        if (size != 0) {
            for (int i = 0; i < size - 1; i++) {
                ss << tail->obj << ", ";
                tail = tail->next;
            }
            ss << tail->obj;
        }
        ss << ']';

        return ss.str();
    }
};

#endif