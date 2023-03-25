#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"

template<class T>
///The class implements work with a linked list
class LinkedList : public List<T> {
private:
    /// Inner class which contains pointer on next Node.They contain our objects.
      
    class Node {
    public:
        T obj;                  ///< Object 
        Node* next = nullptr;   ///< Pointer on next Node.

        Node(T& obj) {        
            this->obj = obj;
        }

    };

    int size = 0;               ///< Value for saving count of elements.
    Node* head = nullptr;       ///< Pointer on first Node in LinkedList.
    Node* tail = nullptr;       ///< Pointer on last Node in LinkedList    
      

public:
    ///Destructor of LinkedList.Delete all Nodes.
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


    /// Adds element to list.
    ///
    ///Adds an element and puts it in a certain position.
    /// 
    /// If an item is not added to the end of the list, the item that belonged to that index(and all after it) moves forward.
    /// @note If the index is not specified or less than zero - adds an item to the end of the list.
    /// @param   obj     The element which we want to add to list.
    /// @param   index   The index on which we want to place the element.
    /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range.
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


    ///Removes element by index from list.
    ///
    /// If we remove element by index, all elements with bigger index moved.
    /// @note If index is less than 0, removed last element in list.
    /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range.
    /// @param   index   The index by which we want to delete the item.
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

    /// Gets element by index from list.
    /// @note If index is less than 0, removed last element from the list.
    /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range exeption.
    /// @param   index   The index of the element in the list we want to get.
    /// @return  The element from list by index.
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

    
    ///Finds the index of an element in the list.
    ///
    /// If the element is not contained in the list, method return -1.
    /// @note If the list contains great than 1 such element, method return tne first index.
    /// @param   obj     The element which index we want to know.
    /// @return   The index of the element in the list or -1 if element is not contained.
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


    /// Removes all elements of the list.  
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


    ///Sorts the list by certain sort.
   /// @param   sort  The pointer on Sort object which have one method - 'sort'. It sort list by certain type.
    void sort(Sort<T>* sort) override {
        T* array = new T[size];

        tail = head;
        for (int i = 0; i < size; i++) {
            array[i] = tail->obj;
            tail = tail->next;
        }

        sort->sort(array, size);
        
        tail = head;
        for (int i = 0; i < size; i++) {
            tail->obj = array[i];
            tail = tail->next;
        }

        delete[] array;
    }

    /// Returns the size of list.
    /// @return  size of list.
    int get_size() override {
        return size;
    }

    /// Writes the list as a string
    /// @return The string of this List.
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