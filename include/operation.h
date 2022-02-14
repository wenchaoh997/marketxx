
#ifndef _OPERATION_H_
#define _OPERATION_H_

#include "../include/utils.h"
#include "../include/user.h"
#include "../include/item.h"
#include "../include/order.h"

void menu_choice(INFO *info);

void login_page(INFO *info);

void register_page(INFO *info);

void logout_page(INFO *info);

void exit_page(INFO *info);

// show matched record in dataset
void show_result(INFO *info);

// control all the operations
void _show(INFO *info);

#endif
