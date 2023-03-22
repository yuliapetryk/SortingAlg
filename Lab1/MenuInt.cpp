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



void MenuInt::menu_for_int(List<int>* list) {

    switch (text_of_menu()) {
        int alpha;
        int beta;
    case 1:
        std::cout << "Enter count of random objects you want to add:" << std::endl;
        scanf("%d", &alpha);

        random_int(alpha, list);
        break;

    case 2:
        std::cout << "Enter the object:" << std::endl;
        scanf("%d", &alpha);

        std::cout << "Enter an index of this object(-1 -> push to end):" << std::endl;
        scanf("%d", &beta);

        list->add(alpha, beta);
        std::cout << "The object successfully added" << std::endl;
        break;

    case 3:
        std::cout << "Enter the index of object(-1 -> remove last):" << std::endl;
        scanf("%d", &alpha);

        list->remove(alpha);
        break;

    case 4:
        std::cout << "Enter the index of object you want(-1 -> the last):" << std::endl;
        scanf("%d", &alpha);

        std::cout << "obj: " << list->get(alpha) << std::endl;
        break;

    case 5:
        std::cout << "Enter the object with index you want:" << std::endl;
        scanf("%d", &alpha);

        std::cout << "index: " << list->find(alpha) << std::endl;
        break;

    case 6:

        std::cout << "Now List is empty." << std::endl;

        list->clear();
        break;

    case 7:
        Sort<int> *sort;

        std::cout << "Choose sort\n"
            "[1] BubbleSort\n"
            "[2] InsertionSort\n"
            "[3] MergeSort\n"
            "[4] QuickSort" << std::endl;
        scanf("%d", &alpha);

        switch (alpha) {
        case 1:
            sort = new BubbleSort<int>;
            break;
        case 2:
            sort = new InsertionSort<int>;
            break;
        case 3:
            sort = new MergeSort<int>;
            break;
        default:
            sort = new QuickSort<int>;
        }



        list->sort(sort);
        std::cout << "The list successfully sorted" << std::endl;
        break;

    case 8:
        std::cout << "Your list:" << std::endl << *list << std::endl;
        break;

    default:
        return;
    }
    
}

void MenuInt::start_with_int_list()  {
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
