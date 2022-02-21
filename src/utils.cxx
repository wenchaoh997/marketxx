
#include "../include/utils.h"

void show_table_head(int table_id){
    char buf[512];
    FILE *fp = nullptr;
    if ( table_id == ITEM_HEAD)
        fp = fopen("../src/img/item_head", "r");
    else if ( table_id == USER_HEAD)
        fp = fopen("../src/img/user_head", "r");
    else if ( table_id == ORDER_HEAD)
        fp = fopen("../src/img/user_head", "r");
    else
        return ;

    if (fp == nullptr){
        std::perror("Table Error ");
        exit(1);
    }
    while (fgets(buf, 512, fp) != NULL){
        std::cout << ("%s\n", buf);
    }
    fclose(fp);
}

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
    getValue(col, src, a, SPLIT);
}

// void getValue(int col, char *src, char *a, const char splitc){
//     getValue(col, src, a, const_cast<char>(splitc));
// }

void getValue(int col, char *src, char *a, char splitc){
    int currCol = 0, i = 0;
    while ((currCol < col) && (src[i] != '\0') && (src[i] != '\n')){
        if (src[i] == splitc){
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

void popValue(int col, char *src, char *a){
    popValue(col, src, a, SPLIT);
}

void popValue(int col, char *src, char *a, char splitc){
    int i = 0, idx = 0;
    getValue(col, src, a, splitc);
    while ((src[i] != '\0') && (src[i] != splitc)) i++;
    if (src[i] == '\0'){
        src[0] = '\0';
        return ;
    }
    i++;
    while (src[i] != '\0'){
        src[idx] = src[i];
        idx++; i++;
    }
    src[idx] = '\0';
}

bool checkUniq(INFO *info, int col, char *a){
    // add new user, or
    // check id is unique or not
    bool flag = true;
    char buf[512], curr[40];
    FILE *fp = nullptr;
    if (info->_page < 100)
        fp = fopen("../src/dataset/user", "r");
    else if (info->_page == CREATE_ITEM)
        fp = fopen("../src/dataset/item", "r");
    else if (info->_page == CREATE_ORDER)
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

int loadCommand(INFO *info){
    /**Meaning
     * 1 : down | DOWN
     * 2 : view | VIEW
     * 3 : post | POST
     * 4 : modify | MODIFY
     * 5 : buy (new order) | BUY
     * 6 : favorite | FAVORITE
     */
    int ret = 0;
    int i = 0, idx = 0;
    char head[10];
    while (info->command[i] == ' ') i++;
    while ((info->command[i] != '\0') && (info->command[i] != ' ')){
        head[idx] = info->command[i];
        idx++; i++;
    }
    if (chareq(head, "down") || chareq(head, "DOWN"))
        ret = 1;
    else if (chareq(head, "view") || chareq(head, "VIEW"))
        ret = 2;
    else if (chareq(head, "post") || chareq(head, "POST"))
        ret = 3;
    else if (chareq(head, "modify") || chareq(head, "MODIFY"))
        ret = 4;
    else if (chareq(head, "buy") || chareq(head, "BUY"))
        ret = 5;
    else if (chareq(head, "favorite") || chareq(head, "FAVORITE"))
        ret = 6;
    else{
        // std::cout << "[error] |Unexpected command.\n";
        return ret;
    }
    // reorganize the args
    // del ' 's in the front
    idx = 0;
    bool previous = true;
    while (info->command[i] != '\0'){
        if ((info->command[i] == ' ') && (previous)){
            i++;
            continue;
        }
        else if (info->command[i] == ','){
            info->command[idx] = '\t';
            previous = true;
        }
        else{
            info->command[idx] = info->command[i];
            previous = false;
        }
        idx++; i++;
    }
    info->command[idx] = '\0';
    return ret;
}

bool isPosFloat(char *s){
    bool numBefore = false, numBehind = false, point = false;
    int count = 0;
    int idx = 0;
    for (; *s != '\0'; s++, idx++){
        switch (*s){
            case '.':
                if (!point) point = true;
                else return false;
                break;
            case '0':case '1':case '2':case '3':case '4':case '5':
            case '6':case '7':case '8':case '9':
                if (point && (count >= 2)) return false;
                else if (point) count++;
                break;
            default: return false;
        }
    }
    return true;
}