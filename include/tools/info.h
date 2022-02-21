
// #include "../../include/tools/string.h"

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
 *  - down | DOWN : 1
 *  - view | VIEW : 2
 *   - view [ITEM_ID | NAME] , ([ITEM_ID | NAME] , ...)
 *   - view all
 *  - post | POST : 3
 *  - modify | MODIFY : 4
 *   - modify [ITEM_ID | NAME]
 * - 102 all items
 *  - buy | BUY : 5
 *   - buy [ITEM_ID | NAME]
 *   - (then show the detail item info)
 *  - favorite | FAVORITE : 6
 *   - (then confirm)
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

typedef enum {WELCOME=0, MAIN_MENU=1, LOGIN=11, REGISTER=12, LOGOUT=13, EXIT=14, 
              USER_MENU=100, ADMIN_MENU=200,
              ITEM_HEAD, USER_HEAD, ORDER_HEAD,
              CREATE_ITEM=101, CREATE_ORDER=102} PageName;

struct INFO
{
    char id[7];
    int _page;
    char command[256];
};

#endif