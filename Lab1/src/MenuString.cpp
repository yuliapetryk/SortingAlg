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

void MenuString::command_random(List<std::string>* list) {
    int alpha;
    std::cout << "Enter count of random objects you want to add:" << std::endl;
    scanf("%d", &alpha);
    random_string(alpha, list);
}

void MenuString::command_add(List<std::string>* list) {
    int alpha;
    char beta[20];
    std::cout << "Enter the object:" << std::endl;

    scanf("%s", beta);
    std::cout << "Enter an index of this object(-1 -> push to end):" << std::endl;
    scanf("%d", &alpha);

    list->add(beta, alpha);
    std::cout << "The object successfully added" << std::endl;
}


void MenuString::command_find(List<std::string>* list) {
    char beta[20];
    std::cout << "Enter the object with index you want:" << std::endl;
    scanf("%s", beta);

    std::cout << "index: " << list->find(beta) << std::endl;
}

void MenuString::menu_for_string(List<std::string>* list) {
    
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

