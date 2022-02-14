
#include<iostream>
#include<process.h>
#include "../include/operation.h"

void menu_choice(INFO *info){
    // if (info->_page > 100) return ;
    std::cout << "\n_page = " << info->_page << "\n" << std::endl;
    std::cout << "Choose your operation: ";
    std::cin.getline(info->command, 256);
    std::cin.clear();

    if (info->_page == 1){
        if (chareq(info->command, "1") || chareq(info->command, "login")){
            info->_page = 11;
            login_page(info);
        }
        else if (chareq(info->command, "2") || chareq(info->command, "sign up")){
            info->_page = 12;
            register_page(info);
        }
        else if (chareq(info->command, "3") || chareq(info->command, "exit")){
            info->_page = 14;
            exit_page(info);
        }
        else
            std::cout << "\n[error] |Unexpected command, try again. \n";
    } /* Main Menu page */
    else if (info->_page == 100){
        if (chareq(info->command, "1") || chareq(info->command, "manage"))
            info->_page = 101;
        else if (chareq(info->command, "2") || chareq(info->command, "items"))
            info->_page = 102;
        else if (chareq(info->command, "3") || chareq(info->command, "search"))
            info->_page = 103;
        else if (chareq(info->command, "4") || chareq(info->command, "orders"))
            info->_page = 104;
        else if (chareq(info->command, "5") || chareq(info->command, "logout")){
            info->_page = 13;
            logout_page(info);
        }
        else if (chareq(info->command, "6") || chareq(info->command, "help"))
            info->_page = 106;
        else if (chareq(info->command, "7") || chareq(info->command, "account"))
            info->_page = 107;
        else
            std::cout << "\n[error] |Unexpected command, try again. \n";
    } /* User Menu */
    else if (info->_page == 200){
        if (chareq(info->command, "1") || chareq(info->command, "items"))
            info->_page = 201;
        else if (chareq(info->command, "2") || chareq(info->command, "orders"))
            info->_page = 202;
        else if (chareq(info->command, "3") || chareq(info->command, "users"))
            info->_page = 203;
        else if (chareq(info->command, "4") || chareq(info->command, "logout")){
            info->_page = 13;
            logout_page(info);
        }
        else
            std::cout << "\n[error] |Unexpected command, try again. \n";
    } /* Admin Menu */
    else
        std::cout << "\n[error] |Unexpected command, try again. \n";
} /* menu_choice */

void login_page(INFO *info){
    char name[40], passward[20];
    std::cout << "# Sign in #\nUser Name: ";
    std::cin.getline(name, 40);
    std::cin.clear();

    std::cout << "Passward: ";
    std::cin.getline(passward, 20);
    std::cin.clear();

    if (!userSign(info, name, passward)){
        std::cout << "\n[info] |Wrong user name or passward! Try again.\n";
        std::cout << "****Failed****\n";
        info->_page = 1;
    }
    else
        system("cls");
}

void register_page(INFO *info){
    char name[40], passward[20];
    std::cout << "# Sign Up #\nUser Name: ";
    std::cin.getline(name, 40);
    std::cin.clear();

    std::cout << "Passward: ";
    std::cin.getline(passward, 20);
    std::cin.clear();

    if ((contains(name, " ")) || (contains(passward, " ")) || (contains(name, "\t")) || (contains(passward, "\t"))){
        std::cout << "\n[warning] |Name and passward should not have space or tab.\n";
        std::cout << "****Failed****\n";
    }
    else if (!userSign(info, name, passward)){
        std::cout << "\n[info] |The user name is already exist. \n";
        std::cout << "****Failed****\n";
    }
    info->_page = 1;
}

void logout_page(INFO *info){
    char choice;
    std::cout << "\n[confirm] |Logout?(y/n): ";
    std::cin >> choice;
    std::cin.get();
    if (choice == 'y'){
        system("cls");
        info->_page = 1;
    }
}

void exit_page(INFO *info){
    char choice;
    std::cout << "\n[confirm] |Exit?(y/n): ";
    std::cin >> choice;
    std::cin.get();
    if (choice == 'y'){
        system("cls");
        std::exit(1);
    }
    else
        info->_page = 1;
}

void show_result(INFO *info);

// control all the operations
void _show(INFO *info);