#include "MenuInt.h"
#include <stdlib.h>

void MenuInt::random_int(int count, List<int>* list) {
    int res;
    for (int i = 0; i < count; i++) {
        srand(time(nullptr) + i);
        res = rand() % 100;
        list->add(res);
    }
}

void  MenuInt::work_with_int_list(List<int>* list) {
    menu_for_int(list);
    while (true) {
        std::cout << std::endl;
        std::cout << "[1] Return to the menu\n"
            "[0] Exit" << std::endl;
        int command;
        scanf("%d", &command);
        switch (command) {
        case 1:
            menu_for_int(list);
            break;
        case 0:
            exit(0);
        default:
            std::cout << "What do you want?" << std::endl;
            break;
        }
    }
}
void MenuInt::command_random(List<int>* list) {
    int alpha;
    std::cout << "Enter count of random objects you want to add:" << std::endl;
    scanf("%d", &alpha);

    random_int(alpha, list);
}
void MenuInt::command_add(List<int>* list) {
    int alpha;
    int beta;
    std::cout << "Enter the object:" << std::endl;
    scanf("%d", &alpha);

    std::cout << "Enter an index of this object(-1 -> push to end):" << std::endl;
    scanf("%d", &beta);

    list->add(alpha, beta);
    std::cout << "The object successfully added" << std::endl;
}



void MenuInt::command_find(List<int>* list) {
    int alpha;
    std::cout << "Enter the object with index you want:" << std::endl;
    scanf("%d", &alpha);

    std::cout << "index: " << list->find(alpha) << std::endl;
}



void MenuInt::menu_for_int(List<int>* list) {

    switch (text_of_menu()) {
        
    case 1:
        command_random(list);
        break;

    case 2:
        command_add(list);
        break;

    case 3:
        
        command_remove(list);
        break;

    case 4:
        
        command_get(list);
        break;

    case 5:
        command_find(list);
        break;
    case 6:
        
        command_clear(list);
        break;

    case 7:
        command_sort(list);
        break;

    case 8:
        command_print(list);
        break;

    default:
        std::cout << "Wrong command!" << std::endl;
        break;
    }
    
}

void MenuInt::start_with_int_list() {
    List<int>* list;
    switch (list_type()) {
    case 1:
        list = new ArrayList<int>;
        std::cout << "Array list is created" << std::endl;
        break;
    case 2:
        list = new LinkedList<int>;
        std::cout << "Linked list is created" << std::endl;
        break;
    default:
        list = new ArrayList<int>;
        std::cout << "Array list is created" << std::endl;
    }
    std::cout << std::endl;

    work_with_int_list(list);

}
