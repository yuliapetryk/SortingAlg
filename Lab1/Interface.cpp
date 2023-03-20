
#include "Interface.h"

void Interface::random_int(int count, List<int>* list) {
    int res;

    for (int i = 0; i < count; i++) {
        srand(time(nullptr) + i);
        res = rand() % 100;

        list->add(res);
    }
}



void Interface::random_string(int count, List<std::string>* list) {
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





void Interface::work_with_string_list() {
    List<std::string>* list;

    int list_type;
    std::cout << "Choose type of List\n"
        "[1] Array List\n"
        "[2] Linked List" << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
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
    int command;

    while (true) {
        int alpha;
        char beta[20];
        int menu;
        std::cout << std::endl;
        std::cout << "[1] Return to the menu\n"
            "[0] Exit" << std::endl;

        scanf("%d", &menu);
        std::cout << std::endl;
        switch (menu) {
        case 1:
            std::cout << "Choose what you want \n"

                "[1] Generate random objects\n"
                "[2] Add object\n"
                "[3] Remove object\n"
                "[4] Get object by index\n"
                "[5] Get index of object(find object)\n"
                "[6] Clear the list\n"
                "[7] Sort list\n"
                "[8] Print the list\n"
                "[-1] Exit" << std::endl;
            scanf("%d", &command);

            switch (command) {
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
                return;
            }
            break;
        default:
            return;
        }
    }



}
void  Interface::work_with_int_list() {

    List<int>* list;

    int list_type;
    std::cout << "Choose type of List\n"
        "[1] Array List\n"
        "[2] Linked List" << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
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
    int command;

    while (true) {
        int alpha;
        int beta;
        int menu;
        std::cout << std::endl;
        std::cout << "[1] Return to the menu\n"
            "[0] Exit" << std::endl;

        scanf("%d", &menu);
        std::cout << std::endl;
        switch (menu) {
        case 1:
            std::cout << "Choose what you want \n"

                "[1] Generate random objects\n"
                "[2] Add object\n"
                "[3] Remove object\n"
                "[4] Get object by index\n"
                "[5] Get index of object(find object)\n"
                "[6] Clear the list\n"
                "[7] Sort list\n"
                "[8] Print the list\n"
                "[-1] Exit" << std::endl;
            scanf("%d", &command);

            switch (command) {
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
            break;
        default:
            return;
        }
    }
}

void Interface::start() {
    int type_in_list;
    std::cout << "---Choose type in List...\n"
        "[1] int\n"
        "[2] string\n" << std::endl;
    scanf("%d", &type_in_list);
    switch (type_in_list) {
    case 1:
        work_with_int_list();
        break;
    case 2:
        work_with_string_list();
        break;
    default:
        work_with_int_list();
    }

}