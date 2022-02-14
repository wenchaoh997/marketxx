
#include "../include/utils.h"

void randID(char *c, int start, int last){
    int i;
    for (i = start; i < last; i++){
        switch ((rand() % 3))
        {
            case 1: c[i] = 'A' + rand() % 26; break;
            case 2: c[i] = 'a' + rand() % 26; break;
            default: c[i] = '0' + rand() % 10; break;
        }
    }
}

bool chareq(char *a, const char *b)
{ return chareq(a, const_cast<char *>(b)); }

bool chareq(const char *a, char *b)
{ return chareq(const_cast<char *>(a), b); }

bool chareq(char *a, char *b){
    int i = 0;
    while ((a[i] != '\0') && (b[i] != '\0')){
        if (a[i] != b[i])
            return false;
        i++;
    }
    if ((a[i] == '\0') && (b[i] == '\0'))
        return true;
    return false;
}

bool contains(char *a, const char *b){
    int i = 0;
    while (a[i] != '\0'){
        if (a[i] == *(b)) return true;
        i++;
    }
    return false;
}

void getValue(int col, char *src, char *a){
    int currCol = 0, i = 0;
    while ((currCol < col) && (src[i] != '\0') && (src[i] != '\n')){
        if (src[i] == SPLIT){
            currCol++;
            // std::cout << "get SPLIT" << std::endl;
        }
        i++;
    }
    int idx = 0;
    while ((src[i] != '\0') && (src[i] != SPLIT) && (src[i] != '\n')){
        a[idx] = src[i];
        i++;idx++;
    }
    a[idx] = '\0';
}

bool checkUniq(INFO *info, int col, char *a){
    // add new element (register or item or order)
    // check id is unique or not
    bool flag = true;
    char buf[512], curr[40];
    FILE *fp = nullptr;
    if (info->_page < 100)
        fp = fopen("../src/dataset/user", "r");
    else if (info->_page == 131)
        fp = fopen("../src/dataset/item", "r");
    else if (info->_page == 112)
        fp = fopen("../src/dataset/order", "r");
    while (fgets(buf, 512, fp) != NULL){
        getValue(col, buf, curr);
        if (chareq(a, curr)){
            flag = false;
            break;
        }
    }
    fclose(fp);
    return flag;
}