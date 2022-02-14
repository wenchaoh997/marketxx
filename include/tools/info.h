
#include "../../include/tools/string.h"

#ifndef _INFO_H_
#define _INFO_H_

/*
 * _page
 * 
 * menus:
 * - 000 welcome
 * - 001 login
 * 
 * login (main_menu):
 * - 011 login
 * - 012 sign up
 * - (013 logout)
 * - 014 exit
 * 
 * user_menu
 * - 100 user_menu
 * - 200 admin_menu
 * 
 * user:
 * - 101 manage your items (create item or order)
 *  - 111 : down
 *  - 121 : view
 *  - 131 : post
 *  - 141 : modify
 * - 102 all items
 *  - 112 : add new order
 *  - 122 : favorite
 * - 103 search
 * - 104 orders
 * - 013 logout
 * - 106 help
 * - 107 account
 * 
 * admin:
 * - 201 manage items
 * - 202 manage orders
 * - 203 manage users
 *  - 213 : view
 *  - 223 : delete
 * - 013 logout
 * 
 */

struct INFO
{
    char id[7];
    int _page;
    char command[256];
};

#endif