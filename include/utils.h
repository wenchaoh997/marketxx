
#include<iostream>
#ifndef _UTILS_H_
#define _UTILS_H_

#include "tools/info.h"

#define SPLIT '\t'

void randID(char *c, int start, int last);

bool chareq(char *a, const char *b);
bool chareq(const char *a, char *b);
bool chareq(char *a, char *b);

bool contains(char *a, const char *b);

void getValue(int col, char *src, char *a);

bool checkUniq(INFO *info, int col, char *a);

#endif