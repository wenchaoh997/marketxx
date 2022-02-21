
#include "../include/item.h"
#include<ctime>

bool checkUniqItemName(INFO *info, char *a){
    // add new Item
    bool flag = true;
    char buf[512], curr[40];
    FILE *fp = nullptr;
    fp = fopen("../src/dataset/item", "r");

    while (fgets(buf, 512, fp) != NULL){
        getValue(1, buf, curr);
        if (chareq(a, curr)){
            flag = false;
            break;
        }
    }
    fclose(fp);
    return flag;
}

void modify_itemStatus(INFO *info);

void show_itemValue(INFO *info){
    char curr[40];
    // todo:
    // empty : show all
    // multi elements : show them
    // one element : show detail
    // info->command example: M00001\tM00003\0
    char buf[512];
    FILE *fp = nullptr;
    if ((info->command[0] == '\0') || chareq(info->command, "all") || chareq(info->command, "ALL")){
        fp = fopen("../src/dataset/item", "r");

        if (fp == nullptr){
            std::perror("Menu Error ");
            exit(1);
        }
        show_table_head(ITEM_HEAD);
        while (fgets(buf, 512, fp) != NULL){
            std::cout << ("%s\n", buf);
        }
    }
    else
        std::cout << "Testing view all..\n";

    // end
    std::cout << "********************************************************\n**End\n";
}

void post_item(INFO *info){
    char name[40], description[256], date[10];
    char pricec[10];
    std::cout << "# Post New Item #\nItem Name: ";
    std::cin.getline(name, 40);
    std::cin.clear();

    int i = 0;
    char prev = '\0';
    while (name[i] != '\0'){
        prev = name[i];
        i++;
    }

    if (prev == ' '){
        std::cout << "\n[warning] |The item name ought to be without space at the beginning or end. \n";
    }
    if (!checkUniqItemName(info, name)){
        std::cout << "\n[info] |The item name is already exist in your list. \n";
        return ;
    }

    std::cout << "Price: ";
    std::cin.getline(pricec, 10);
    std::cin.clear();
    if (!isPosFloat(pricec)){
        std::cout << "\n[error] |The price should be float type with two decimal places at most.\n";
        return ;
    }

    std::cout << "Description:\n";
    std::cin.getline(description, 256);
    std::cin.clear();
    // save the item info
    // ITEM_ID    NAME    PRICE    DATE    SALER_ID    STATUS
    FILE *fp = nullptr;
    fp = fopen("../src/dataset/item", "ab");
    char retChar[512];
    // id
    retChar[0] = 'M';
    randID(retChar, 1, 6);
    while (!checkUniq(info, 0, retChar))
        randID(retChar, 1, 6);
    retChar[6] = SPLIT;
    // name
    i = 7;
    int idx = 0;
    while (name[idx] != '\0'){
        retChar[i] = name[idx];
        i++;idx++;
    }
    retChar[i++] = SPLIT;
    // price
    idx = 0;
    while (pricec[idx] != '\0'){
        retChar[i] = pricec[idx];
        i++;idx++;
    }
    retChar[i++] = SPLIT;
    // date
    idx = 0;
    time_t now = time(0);
    char* dt = ctime(&now);
    while (dt[idx] != '\0'){
        retChar[i] = dt[idx];
        i++; idx++;
    }
    i -= 2; // a \n at the end of dt !!!
    retChar[i++] = SPLIT;
    // SALER_ID
    idx = 0;
    while (info->id[idx] != '\0'){
        retChar[i] = info->id[idx];
        i++;idx++;
    }
    retChar[i++] = SPLIT;
    // Status
    retChar[i++] = '2';
    retChar[i] = '\0';

    fputs(retChar, fp);
    fputs("\n", fp);
    fclose(fp);
    // description
    fp = fopen("../src/dataset/item_desc", "ab");
    i = 7;idx = 0;
    while (description[idx] != '\0'){
        retChar[i] = description[idx];
        i++;idx++;
    }
    retChar[i] = '\0';
    fputs(retChar, fp);
    fputs("\n", fp);
    fclose(fp);

    std::cout << "\n[info] |The item has been posted.\n";
    std::cout << "****Succeed****\n";
}

void modify_itemValue(INFO *info);