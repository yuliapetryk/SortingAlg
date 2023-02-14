#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <iostream>
#include "..\Lab1\List.h"
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\LinkedList.h"
#include "..\Lab1\VectorList.h"


#include "..\Lab1\BubbleSort.h"
#include "..\Lab1\InsertionSort.h"
#include "..\Lab1\MergeSort.h"
#include "..\Lab1\QuickSort.h"
#include "..\Lab1\ReverseComparator.h"

///Class for demonstrating the Lists` functional.
class TerminalUI {
private:
    ///Generator for generate random object.
   // ListGenerator generator;

    //-----\/--texts-for-communication-with-user--\/-----//
   
    
    const char* msg_list_type = "---Choose type of List---\n"
        "(List *list = new ...)\n"
        "[1] ArrayList\n"
        "[2] LinkedList\n"
        "[3] VectorList";

    const char* msg_what_you_want = "---Choose what you want---\n"
        "(list...())\n"
        "[1] Generate random objects\n"
        "[2] Add object\n"
        "[3] Remove object\n"
        "[4] Get object by index\n"
        "[5] Get index of object(find object)\n"
        "[6] Clear the list\n"
        "[7] Sort list\n"
        "[8] Print the list\n"
        "[-1] Exit";

    const char* msg_sorts = "---Choose sort---\n"
        "[1] BubbleSort\n"
        "[2] InsertionSort\n"
        "[3] MergeSort\n"
        "[4] QuickSort";

    const char* msg_comparators = "---Choose comparator---\n"
        "[1] Default\n"
        "[2] Reverse";

    const char* msg_count_of_random_objects = "Enter count of random objects you want to add:";

    const char* msg_add_object = "Enter the object:";

    const char* msg_add_object_index = "Enter an index of this object(-1 -> push to end):";

    const char* msg_remove = "Enter the index of object(-1 -> remove last):";

    const char* msg_get_object = "Enter the index of object you want(-1 -> the last):";

    const char* msg_find = "Enter the object witch index you want:";

    const char* msg_clear_the_list = "Now List is empty.";

    const char* msg_print = "Your list:";

    const char* msg_vector_size = "Enter the vector`s size:";

    const char* msg_vector_object = "Enter an int by index ";

    const char* msg_book_name = "Enter the name of this book:";

    const char* msg_book_pages = "Enter the count of pages of this book:";

    const char* msg_character_name = "Enter the name of this character:";
    //-----/\--texts-for-communication-with-user--/\-----//

   

  
  
public:
    ///Start the demonstration.
    void start();
};


#endif
