#include<iostream>
#include<process.h>
// #include "../include/tools/color.h"
#include "../include/menu.h"
#include "../include/operation.h"

const char *hello = "Hello,. winterCode!\n";

int main(){
    system("cls");
    // printf("%s%s%s\n", TWINKLING, hello, RESET);

    // init
    INFO app;
    for (int i = 0; i < 6; i++)
        app.id[i] = '0';
    app._page = WELCOME;
    show_menu(&app);
    app._page = MAIN_MENU;

    bool flag = false;
    while (true){
        // operations
        show_menu(&app);
        menu_choice(&app);
        std::cout << "\n";
    }
    
    // system("pause");
    return 0;
}