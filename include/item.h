
#ifndef _ITEM_H_
#define _ITEM_H_

#include "utils.h"

void modify_itemStatus(INFO *info, const char *s);
void modify_itemStatus(INFO *info, char *s);

void show_itemValue(INFO *info);

void post_item(INFO *info);

void modify_itemInfo(INFO *info);

#endif