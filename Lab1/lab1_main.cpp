#include "..\Lab1\doctest.h"

#include <iostream>
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\List.h"
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\LinkedList.h"
#include "..\Lab1\BubbleSort.h"
#include "..\Lab1\InsertionSort.h"
#include "..\Lab1\MergeSort.h"
#include "..\Lab1\QuickSort.h"

using namespace std;

namespace lab {
    void random_int(int count, List<int>* list) {
        int res;

        for (int i = 0; i < count; i++) {
            srand(time(nullptr) + i);
            res = rand() % 100;

            list->add(res);
        }
    }



    void random_string(int count, List<string>* list) {
        string res;
        const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        for (int i = 0; i < count; i++) {
            srand(time(nullptr) + i);
            res = "";
            for (int j = 0; j < 10; j++) {
                res += alphabet[rand() % alphabet.length()];
            }
            list->add(res);
        }
    }





    void work_with_string_list() {
        List<string>* list;

        int list_type;
        cout << "Choose type of List\n"
            "[1] Array List\n"
            "[2] Linked List" << endl;
        scanf("%d", &list_type);

        switch (list_type) {
        case 1:
            list = new ArrayList<string>;
            cout << "Array list is created" << endl;
            break;
        case 2:
            list = new LinkedList<string>;
            cout << "Linked list is created" << endl;
            break;
        default:
            list = new ArrayList<string>;
            cout << "Array list is created" << endl;
        }
        int command;

        while (true) {
            int alpha;
            char beta[20];
            int menu;
            cout << endl;
            cout << "[1] Return to the menu\n"
                "[0] Exit" << endl;

            scanf("%d", &menu);
            cout << endl;
            switch (menu) {
            case 1:
                cout << "Choose what you want \n"

                    "[1] Generate random objects\n"
                    "[2] Add object\n"
                    "[3] Remove object\n"
                    "[4] Get object by index\n"
                    "[5] Get index of object(find object)\n"
                    "[6] Clear the list\n"
                    "[7] Sort list\n"
                    "[8] Print the list\n"
                    "[-1] Exit" << endl;
                scanf("%d", &command);

                switch (command) {
                case 1:
                    cout << "Enter count of random objects you want to add:" << endl;
                    scanf("%d", &alpha);
                    random_string(alpha, list);
                    break;

                case 2:
                    cout << "Enter the object:" << endl;

                    scanf("%s", beta);
                    cout << "Enter an index of this object(-1 -> push to end):" << endl;
                    scanf("%d", &alpha);

                    list->add(beta, alpha);
                    cout << "The object successfully added" << endl;
                    break;

                case 3:
                    cout << "Enter the index of object(-1 -> remove last):" << endl;
                    scanf("%d", &alpha);

                    list->remove(alpha);
                    break;

                case 4:
                    cout << "Enter the index of object you want(-1 -> the last):" << endl;
                    scanf("%d", &alpha);

                    cout << "obj: " << list->get(alpha) << endl;
                    break;

                case 5:
                    cout << "Enter the object with index you want:" << endl;
                    scanf("%s", beta);

                    cout << "index: " << list->find(beta) << endl;
                    break;

                case 6:
                    cout << "Now List is empty." << endl;

                    list->clear();
                    break;

                case 7:
                    Sort<string> *sort;

                    cout << "Choose sort\n"
                        "[1] BubbleSort\n"
                        "[2] InsertionSort\n"
                        "[3] MergeSort\n"
                        "[4] QuickSort" << endl;
                    scanf("%d", &alpha);

                    switch (alpha) {
                    case 1:
                        sort = new BubbleSort<string>;
                        break;
                    case 2:
                        sort = new InsertionSort<string>;
                        break;
                    case 3:
                        sort = new MergeSort<string>;
                        break;
                    default:
                        sort = new QuickSort<string>;
                    }



                    list->sort(sort);
                    cout << "The list successfully sorted" << endl;
                    break;

                case 8:
                    cout << "Your list:" << endl << *list << endl;
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
    void  work_with_int_list() {

        List<int>* list;

        int list_type;
        cout << "Choose type of List\n"
            "[1] Array List\n"
            "[2] Linked List" << endl;
        scanf("%d", &list_type);

        switch (list_type) {
        case 1:
            list = new ArrayList<int>;
            cout << "Array list is created" << endl;

            break;
        case 2:
            list = new LinkedList<int>;
            cout << "Linked list is created" << endl;

            break;
        default:
            list = new ArrayList<int>;
            cout << "Array list is created" << endl;

        }
        int command;

        while (true) {
            int alpha;
            int beta;
            int menu;
            cout << endl;
            cout << "[1] Return to the menu\n"
                "[0] Exit" << endl;

            scanf("%d", &menu);
            cout << endl;
            switch (menu) {
            case 1:
                cout << "Choose what you want \n"

                    "[1] Generate random objects\n"
                    "[2] Add object\n"
                    "[3] Remove object\n"
                    "[4] Get object by index\n"
                    "[5] Get index of object(find object)\n"
                    "[6] Clear the list\n"
                    "[7] Sort list\n"
                    "[8] Print the list\n"
                    "[-1] Exit" << endl;
                scanf("%d", &command);

                switch (command) {
                case 1:
                    cout << "Enter count of random objects you want to add:" << endl;
                    scanf("%d", &alpha);

                    random_int(alpha, list);
                    break;

                case 2:
                    cout << "Enter the object:" << endl;
                    scanf("%d", &alpha);

                    cout << "Enter an index of this object(-1 -> push to end):" << endl;
                    scanf("%d", &beta);

                    list->add(alpha, beta);
                    cout << "The object successfully added" << endl;
                    break;

                case 3:
                    cout << "Enter the index of object(-1 -> remove last):" << endl;
                    scanf("%d", &alpha);

                    list->remove(alpha);
                    break;

                case 4:
                    cout << "Enter the index of object you want(-1 -> the last):" << endl;
                    scanf("%d", &alpha);

                    cout << "obj: " << list->get(alpha) << endl;
                    break;

                case 5:
                    cout << "Enter the object with index you want:" << endl;
                    scanf("%d", &alpha);

                    cout << "index: " << list->find(alpha) << endl;
                    break;

                case 6:
                    cout << "Now List is empty." << endl;

                    list->clear();
                    break;

                case 7:
                    Sort<int> *sort;

                    cout << "Choose sort\n"
                        "[1] BubbleSort\n"
                        "[2] InsertionSort\n"
                        "[3] MergeSort\n"
                        "[4] QuickSort" << endl;
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
                    cout << "The list successfully sorted" << endl;
                    break;

                case 8:
                    cout << "Your list:" << endl << *list << endl;
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

    void start() {
        int type_in_list;
        cout << "---Choose type in List...\n"
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
    int doctest() {
        doctest::Context context;
        return context.run();
    }
    int main() {

        start();
        return 0;

    }
}
