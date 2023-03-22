#define DOCTEST_CONFIG_IMPLEMENT//_WITH_MAIN
#include "doctest.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include"QuickSort.h"
#include "ArrayList.h"
#include "LinkedList.h"


template <class T>
std::string to_list_string(T* a,
    T* b = nullptr,
    T* c = nullptr,
    T* d = nullptr,
    T* e = nullptr ,
    T* f = nullptr) {
    std::stringstream ss;
    ss << '[' << *a;
    if (b != 0) ss << ", " << *b;
    if (c != 0) ss << ", " << *c;
    if (d != 0) ss << ", " << *d;
    if (e != 0) ss << ", " << *e;
    if (f != 0) ss << ", " << *f;
    ss << ']';
    return ss.str();
}


TEST_CASE("Tests for int") {
        int a = 1, b = 2, c = 3, d = 4;
        //create Array list
        List<int>* array_list;
        array_list = new ArrayList<int>;

        // create Linked list
        List<int>* linked_list;
        linked_list = new LinkedList<int>;

        SUBCASE("Add") {
            array_list->add(a,-1);
            array_list->add(b);
            array_list->add(d, 1);
            CHECK(array_list->to_string() == to_list_string(&a, &d, &b));
            linked_list->add(b,-1);
            linked_list->add(c);
            linked_list->add(d, 0);
            CHECK(linked_list->to_string() == to_list_string(&d, &b, &c));
        }
        //Add function  works, so we can fill our lists
        array_list->add(c);
        array_list->add(b);
        array_list->add(a);
        array_list->add(d);

        linked_list->add(c);
        linked_list->add(b);
        linked_list->add(a);
        linked_list->add(d);
       

        SUBCASE("Remove") {
            array_list->remove(0);
            CHECK(array_list->to_string() == to_list_string(&b, &a, &d));
            linked_list->remove(1);
            CHECK(linked_list->to_string() == to_list_string(&c, &a, &d));
        }

        SUBCASE("Get") {
            CHECK_EQ(array_list->get(0), 3);
            CHECK_EQ(linked_list->get(2), 1);
        }

        SUBCASE("Find") {
            CHECK_EQ(array_list->find(4), 3);
            CHECK_EQ(linked_list->find(4), 3);
        }
        SUBCASE("Size") {
            CHECK_EQ(array_list->get_size(), 4);
            CHECK_EQ(linked_list->get_size(), 4);
        }
        SUBCASE("Clear") {
            array_list->clear();
            CHECK_EQ(array_list->get_size(), 0);
            linked_list->clear();
            CHECK_EQ(linked_list->get_size(), 0);
        }
       
        SUBCASE("Range") {
            CHECK_THROWS_AS(array_list->get(5), std::out_of_range);
            CHECK_THROWS_AS(linked_list->remove(10), std::out_of_range);
        }


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
            array_list->clear();
            CHECK_THROWS_AS(array_list->sort(sort_bubble), std::out_of_range);

            linked_list->clear();
            CHECK_THROWS_AS(linked_list->sort(sort_bubble), std::out_of_range);
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
            array_list->clear();
            CHECK_THROWS_AS(array_list->sort(sort_merge), std::out_of_range);

            linked_list->clear();
            CHECK_THROWS_AS(linked_list->sort(sort_merge), std::out_of_range);
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
            array_list->clear();
            CHECK_THROWS_AS(array_list->sort(sort_quick), std::out_of_range);

            linked_list->clear();
            CHECK_THROWS_AS(linked_list->sort(sort_quick), std::out_of_range);
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
            array_list->clear();
            CHECK_THROWS_AS(array_list->sort(sort_insertion), std::out_of_range);

            linked_list->clear();
            CHECK_THROWS_AS(linked_list->sort(sort_insertion), std::out_of_range);
        }   
    }

    TEST_CASE("Tests for string") {
        std::string a="apple", b ="banana", c = "cocktail", d = "dish";
        //create Array list
        List<std::string>* array_list;
        array_list = new ArrayList<std::string>;

        // create Linked list
        List<std::string>* linked_list;
        linked_list = new LinkedList<std::string>;

        SUBCASE("Add") {
            array_list->add(a);
            array_list->add(c);
            array_list->add(d, 1);
            CHECK(array_list->to_string() == to_list_string(&a, &d, &c));

            linked_list->add(b);
            linked_list->add(a);
            linked_list->add(d, 0);
            CHECK(linked_list->to_string() == to_list_string(&d,  &b, &a));
        }

        //Add function  works, so we can fill our lists
        array_list->add(c);
        array_list->add(b);
        array_list->add(a);
        array_list->add(d);

        linked_list->add(c);
        linked_list->add(b);
        linked_list->add(a);
        linked_list->add(d);

        //testing Bubble sort
        SUBCASE("Testing Bubble Sort") {
            Sort<std::string>* sort_bubble;
            sort_bubble = new BubbleSort<std::string>;
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
            Sort<std::string>* sort_merge;
            sort_merge = new MergeSort<std::string>;
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
            Sort<std::string>* sort_quick;
            sort_quick = new QuickSort<std::string>;
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
            Sort<std::string>* sort_insertion;
            sort_insertion = new InsertionSort<std::string>;
            linked_list->sort(sort_insertion);
            array_list->sort(sort_insertion);
            for (int i = 0; i < 3; i++) {
                CHECK(linked_list->to_string() == to_list_string(&a, &b, &c, &d));
            }
            for (int i = 0; i < 3; i++) {
                CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
            }
        }
        
        SUBCASE("Remove") {
            array_list->remove(0);
            CHECK(array_list->to_string() == to_list_string(&b, &a, &d));
            linked_list->remove(1);
            CHECK(linked_list->to_string() == to_list_string(&c, &a, &d));
        }
        
        SUBCASE("Get") {
            CHECK_EQ(array_list->get(0), "cocktail");
            CHECK_EQ(linked_list->get(2), "apple");
        }
        
        SUBCASE("Find") {
            CHECK_EQ(array_list->find("dish"), 3);
            CHECK_EQ(linked_list->find("dish"), 3);
        }
        SUBCASE("Size") {
            CHECK_EQ(array_list->get_size(), 4);
            CHECK_EQ(linked_list->get_size(), 4);
        }
        SUBCASE("Clear") {
            array_list->clear();
            CHECK_EQ(array_list->get_size(), 0);
            linked_list->clear();
            CHECK_EQ(linked_list->get_size(), 0);
        }
        SUBCASE("Range") {
            CHECK_THROWS_AS(array_list->get(5), std::out_of_range);
            CHECK_THROWS_AS(linked_list->remove(10), std::out_of_range);
        }
        

}



