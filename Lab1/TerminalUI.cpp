
#include "..\Lab1\TerminalUI.h"

void random_int(int count, List<int>* list) {
    int res;

    for (int i = 0; i < count; i++) {
        srand(time(nullptr) + i);
        res = rand() % 100;

        list->add(res);
    }
}

void TerminalUI::start() {
  
    List<int>* list;

    int list_type;
    std::cout << msg_list_type << std::endl;
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

        std::cout << msg_what_you_want << std::endl;
        scanf_s("%d", &command);

        switch (command) {
        case 1:
            std::cout << msg_count_of_random_objects << std::endl;
            scanf_s("%d", &alpha);

            random_int(alpha, list);
            break;

        case 2:
            std::cout << msg_add_object << std::endl;
            scanf_s("%d", &alpha);

            std::cout << msg_add_object_index << std::endl;
            scanf_s("%d", &beta);

            list->add(alpha, beta);
            break;

        case 3:
            std::cout << msg_remove << std::endl;
            scanf_s("%d", &alpha);

            list->remove(alpha);
            break;

        case 4:
            std::cout << msg_get_object << std::endl;
            scanf_s("%d", &alpha);

            std::cout << "obj: " << list->get(alpha) << std::endl;
            break;

        case 5:
            std::cout << msg_find << std::endl;
            scanf_s("%d", &alpha);

            std::cout << "index: " << list->find(alpha) << std::endl;
            break;

        case 6:
            std::cout << msg_clear_the_list << std::endl;

            list->clear();
            break;

        case 7:
            Sort<int> *sort;
            Comparator<int>* comparator;

            std::cout << msg_sorts << std::endl;
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

            std::cout << msg_comparators << std::endl;
            scanf_s("%d", &beta);

           
                comparator = new ReverseComparator<int>;
            

            list->sort(sort, comparator);
            break;

        case 8:
            std::cout << msg_print << std::endl << *list << std::endl;
            break;

        default:
            return;
        }
    }
}




