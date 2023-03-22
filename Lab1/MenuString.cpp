#include "MenuString.h"
#include "MenuInt.h"
#include <stdlib.h>





void MenuString::random_string(int count, List<std::string>* list) {
    std::string res;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < count; i++) {
        srand(time(nullptr) + i);
        res = "";
        for (int j = 0; j < 10; j++) {
            res += alphabet[rand() % alphabet.length()];
        }
        list->add(res);
    }
}


void MenuString::work_with_string_list(List<std::string>* list) {
    menu_for_string(list);
    while (true) {
        
        std::cout << std::endl;
        std::cout << "[1] Return to the menu\n"
            "[0] Exit" << std::endl;
        int command;
        scanf("%d", &command);
        switch (command) {
        case 1:
            menu_for_string(list);
            break;
        case 0:
            exit(0);
        default:
            std::cout << "What do you want?" << std::endl;
            break;
        }
    }
}




void MenuString::menu_for_string(List<std::string>* list) {
    
        switch (text_of_menu()) {
            int alpha;
            char beta[20];
        case 1:
            std::cout << "Enter count of random objects you want to add:" << std::endl;
            scanf("%d", &alpha);
            random_string(alpha, list);
            break;

        case 2:
            std::cout << "Enter the object:" << std::endl;

            scanf("%s", beta);
            std::cout << "Enter an index of this object(-1 -> push to end):" << std::endl;
            scanf("%d", &alpha);

            list->add(beta, alpha);
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
            scanf("%s", beta);

            std::cout << "index: " << list->find(beta) << std::endl;
            break;

        case 6:
            std::cout << "Now List is empty." << std::endl;
            list->clear();

            break;

        case 7:
            Sort<std::string> *sort;

            std::cout << "Choose sort\n"
                "[1] BubbleSort\n"
                "[2] InsertionSort\n"
                "[3] MergeSort\n"
                "[4] QuickSort" << std::endl;
            scanf("%d", &alpha);

            switch (alpha) {
            case 1:
                sort = new BubbleSort<std::string>;
                break;
            case 2:
                sort = new InsertionSort<std::string>;
                break;
            case 3:
                sort = new MergeSort<std::string>;
                break;
            default:
                sort = new QuickSort<std::string>;
            }



            list->sort(sort);
            std::cout << "The list successfully sorted" << std::endl;
            break;

        case 8:
            std::cout << "Your list:" << std::endl << *list << std::endl;
            break;

        default:
            std::cout << "Wrong command!" << std::endl;    
            break;
        }
      
}




void MenuString::start_with_string_list() {

    List<std::string>* list;

    switch (list_type()) {
    case 1:
        list = new ArrayList<std::string>;
        std::cout << "Array list is created" << std::endl;
        break;
    case 2:
        list = new LinkedList<std::string>;
        std::cout << "Linked list is created" << std::endl;
        break;
    default:
        list = new ArrayList<std::string>;
        std::cout << "Array list is created" << std::endl;
    }
    std::cout << std::endl;
    work_with_string_list(list);

}

