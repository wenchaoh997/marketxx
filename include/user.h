
#ifndef _USER_H_
#define _USER_H_

#include "utils.h"
#include "item.h"
#include "order.h"

bool userSign(INFO *info, char *name, char *passward);

void manage_items(INFO *info);

void manage_orders(INFO *info);

void manage_users(INFO *info);

#endif