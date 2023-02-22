#include <iostream>

#include "..\Lab1\ArrayList.h"
#include "..\Lab1\List.h"
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\LinkedList.h"
#include "..\Lab1\BubbleSort.h"
#include "..\Lab1\InsertionSort.h"
#include "..\Lab1\MergeSort.h"
#include "..\Lab1\QuickSort.h"

void random_int(int count, List<int>* list) {
    int res;

    for (int i = 0; i < count; i++) {
        srand(time(nullptr) + i);
        res = rand() % 100;

        list->add(res);
    }
}

void start() {

    List<int>* list;

    int list_type;
    std::cout << "Choose type of List\n"
        "[1] ArrayList\n"
        "[2] LinkedList" << std::endl;
    scanf_s("%d", &list_type);

    switch (list_type) {
    case 1:
        list = new ArrayList<int>;
        break;
    case 2:
        list = new LinkedList<int>;
        break;
    default:
        list = new ArrayList<int>;
    }
    int command;

    while (true) {
        int alpha;
        int beta;

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
        scanf_s("%d", &command);

        switch (command) {
        case 1:
            std::cout << "Enter count of random objects you want to add:" << std::endl;
            scanf_s("%d", &alpha);

            random_int(alpha, list);
            break;

        case 2:
            std::cout << "Enter the object:" << std::endl;
            scanf_s("%d", &alpha);

            std::cout << "Enter an index of this object(-1 -> push to end):" << std::endl;
            scanf_s("%d", &beta);

            list->add(alpha, beta);
            break;

        case 3:
            std::cout << "Enter the index of object(-1 -> remove last):" << std::endl;
            scanf_s("%d", &alpha);

            list->remove(alpha);
            break;

        case 4:
            std::cout << "Enter the index of object you want(-1 -> the last):" << std::endl;
            scanf_s("%d", &alpha);

            std::cout << "obj: " << list->get(alpha) << std::endl;
            break;

        case 5:
            std::cout << "Enter the object with index you want:" << std::endl;
            scanf_s("%d", &alpha);

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
            scanf_s("%d", &alpha);

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
            break;

        case 8:
            std::cout << "Your list:" << std::endl << *list << std::endl;
            break;

        default:
            return;
        }
    }
}


int main() {
    start();
    return 0;
   
}
