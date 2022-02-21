#include<iostream>
#include "../include/menu.h"

void show_menu(INFO *info){
    char buf[512];
    FILE *fp = nullptr;
    if ( (info->_page) == WELCOME)
        fp = fopen("../src/img/welcome", "r");
    else if ( (info->_page) == MAIN_MENU)
        fp = fopen("../src/img/main_menu", "r");
    else if ( (info->_page) == USER_MENU)
        fp = fopen("../src/img/user", "r");
    else if ( (info->_page) == ADMIN_MENU)
        fp = fopen("../src/img/admin", "r");
    // else if ( (info->_page) == ITEM_HEAD)
    //     fp = fopen("../src/img/item_head", "r");
    // else if ( (info->_page) == USER_HEAD)
    //     fp = fopen("../src/img/user_head", "r");
    // else if ( (info->_page) == ORDER_HEAD)
    //     fp = fopen("../src/img/user_head", "r");
    else
        return ;

    if (fp == nullptr){
        std::perror("Menu Error ");
        exit(1);
    }
    while (fgets(buf, 512, fp) != NULL){
        std::cout << ("%s\n", buf);
    }
    fclose(fp);
}
