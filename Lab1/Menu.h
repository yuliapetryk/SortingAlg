#ifndef MENU
#define MENU

class Menu {
protected:
    int list_type() {
        std::cout << "Choose type of List\n"
            "[1] Array List\n"
            "[2] Linked List" << std::endl;
        int type;
        scanf("%d", &type);
        return type;
    }

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
   
};

#endif

