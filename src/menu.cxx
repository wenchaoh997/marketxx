#include<iostream>
#include "../include/menu.h"
// #include "../include/tools/info.h"

void show_menu(INFO *info){
    char buf[512];
    FILE *fp = nullptr;
    if ( (info->_page) == 0)
        fp = fopen("../src/img/welcome", "r");
    else if ( (info->_page) == 1)
        fp = fopen("../src/img/main_menu", "r");
    else if ( (info->_page) == 100)
        fp = fopen("../src/img/user", "r");
    else if ( (info->_page) == 200)
        fp = fopen("../src/img/admin", "r");

    if (fp == nullptr){
        std::perror("Menu Error ");
        exit(1);
    }
    while (fgets(buf, 512, fp) != NULL){
        std::cout << ("%s\n", buf);
    }
    fclose(fp);
}
