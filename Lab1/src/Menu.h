#ifndef MENU
#define MENU

///The class implements work with a user
class Menu {
protected:

    ///A method to find out what type of list the user wants to work 
    /// @returns Type of list
    int list_type() {
        std::cout << "Choose type of List\n"
            "[1] Array List\n"
            "[2] Linked List" << std::endl;
        int type;
        scanf("%d", &type);
        return type;
    }
    ///A method to find out exactly what the user wants to do with the list
    /// @returns A command
    int text_of_menu() {
        std::cout << "Choose what you want \n"

            "[1] Generate random objects\n"
            "[2] Add object\n"
            "[3] Remove object\n"
            "[4] Get object by index\n"
            "[5] Get index of object(find object)\n"
            "[6] Clear the list\n"
            "[7] Sort list\n"
            "[8] Print the list\n"
            "[0] Exit" << std::endl;
        int command;
        scanf("%d", &command);
        if (command == 0)
            exit(0);
        return command;
    }

    template<class T>
    
    /// A method to call a method to remove an element at the specified index
    /// @param list The list we work with
    void command_remove(List<T>* list) {
        int alpha;
        std::cout << "Enter the index of object(-1 -> remove last):" << std::endl;
        scanf("%d", &alpha);

        list->remove(alpha);
    }

    template<class T>
    /// A method to call a method to get an element with the specified index
    /// @param list The list we work with
    void command_get(List<T>* list) {
        int alpha;
        std::cout << "Enter the index of object you want(-1 -> the last):" << std::endl;
        scanf("%d", &alpha);

        std::cout << "obj: " << list->get(alpha) << std::endl;
    }

    template<class T>
    /// A method to call a method to clear the list
    /// @param list The list we work with
    void command_clear(List<T>* list) {
        std::cout << "Now List is empty." << std::endl;
        list->clear();
    }

    /// A method to call a method to sort the list
    /// @param list The list we work with
    template<class T>
    void command_sort(List<T>* list) {
        Sort<T>* sort;
        int alpha;
        std::cout << "Choose sort\n"
            "[1] BubbleSort\n"
            "[2] InsertionSort\n"
            "[3] MergeSort\n"
            "[4] QuickSort" << std::endl;
        scanf("%d", &alpha);

        switch (alpha) {
        case 1:
            sort = new BubbleSort<T>;
            break;
        case 2:
            sort = new InsertionSort<T>;
            break;
        case 3:
            sort = new MergeSort<T>;
            break;
        default:
            sort = new QuickSort<T>;
        }
        list->sort(sort);
        std::cout << "The list successfully sorted" << std::endl;
    }

    template<class T>
    /// A method to call a method to print the list
    /// @param list The list we work with
    void command_print(List<T>* list) {
        std::cout << "Your list:" << std::endl << *list << std::endl;
    }

    
    
};

#endif

