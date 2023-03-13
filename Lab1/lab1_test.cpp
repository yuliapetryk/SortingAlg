#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Sort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include"QuickSort.h"
#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
using namespace std;

template <class T>
string to_list_string(T* a,
    T* b = nullptr,
    T* c = nullptr,
    T* d = nullptr,
    T* e = nullptr ) {
   stringstream ss;
    ss << '[' << *a;
    if (b != 0) ss << ", " << *b;
    if (c != 0) ss << ", " << *c;
    if (d != 0) ss << ", " << *d;
    ss << ']';
    return ss.str();
}

TEST_CASE("testing Sorting for Array list") {
    int a = 1, b = 2, c = 3, d = 4;
    //create Array list
    List<int>* array_list;
    array_list = new ArrayList<int>;
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);

    
    // create Linked list
    List<int>* linked_list;
    linked_list = new LinkedList<int>;
    linked_list->add(c);
    linked_list->add(b);
    linked_list->add(a);
    linked_list->add(d);
  

    //testing Bubble sort
    SUBCASE("Testing Bubble Sort") {
        Sort<int>* sort_bubble;
        sort_bubble = new BubbleSort<int>;
        linked_list->sort(sort_bubble);
        array_list->sort(sort_bubble);
        for (int i = 0; i < 3; i++) {
            CHECK(linked_list->to_string() == to_list_string(&a, &b, &c, &d)); 
        }
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    //testing Merge Sort
    SUBCASE("Testing Merge Sort") {
        Sort<int>* sort_merge;
        sort_merge = new MergeSort<int>;
        linked_list->sort(sort_merge);
        array_list->sort(sort_merge);
        for (int i = 0; i < 3; i++) {
            CHECK(linked_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    //testing Quick Sort
    SUBCASE("Testing Quick Sort") {
        Sort<int>* sort_quick;
        sort_quick = new QuickSort<int>;
        linked_list->sort(sort_quick);
        array_list->sort(sort_quick);
        for (int i = 0; i < 3; i++) {
            CHECK(linked_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    //testing Insertion Sort
    SUBCASE("Testing Insertion Sort") {
        Sort<int>* sort_insertion;
        sort_insertion = new InsertionSort<int>;
        linked_list->sort(sort_insertion);
        array_list->sort(sort_insertion);
        for (int i = 0; i < 3; i++) {
            CHECK(linked_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }
}

TEST_CASE("Operations") {
    int a = 1, b = 2, c = 3, d = 4;
    //create Array list
    List<int>* array_list;
    array_list = new ArrayList<int>;
    array_list->add(a);
    array_list->add(b);
    array_list->add(c);
    // create Linked list
    List<int>* linked_list;
    linked_list = new LinkedList<int>;

    linked_list->add(a);
    linked_list->add(b);
    linked_list->add(c);

    SUBCASE("Add") {

        array_list->add(a);
        CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &a));

        linked_list->add(b);
        CHECK(linked_list->to_string() == to_list_string(&a, &b, &c, &b));
    }
    SUBCASE("Remove") {

        array_list->remove(0);
       CHECK(array_list->to_string() == to_list_string( &b, &c));

        linked_list->remove(1);
        CHECK(linked_list->to_string() == to_list_string(&a, &c));
    }
}




