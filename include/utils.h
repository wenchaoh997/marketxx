
#include<iostream>
#ifndef _UTILS_H_
#define _UTILS_H_

#include "tools/info.h"

#define SPLIT '\t'

void show_table_head(int table_id);

void randID(char *c, int start, int last);

bool chareq(char *a, const char *b);
bool chareq(const char *a, char *b);
bool chareq(char *a, char *b);

bool contains(char *a, const char *b);
bool contains(char *a, char *b);

void getValue(int col, char *src, char *a);
void getValue(int col, char *src, char *a, char splitc);

void popValue(int col, char *src, char *a);
void popValue(int col, char *src, char *a, char splitc);

bool checkUniq(INFO *info, int col, char *a);

int loadCommand(INFO *info);

bool isPosFloat(char *s);

#endif