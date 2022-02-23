
#include "../include/item.h"
#include<ctime>

bool checkUniqItemName(INFO *info, char *a){
    // add new Item
    bool flag = true;
    char buf[512], curr[40], currID[7];
    FILE *fp = nullptr;
    fp = fopen("../src/dataset/item", "r");

    while (fgets(buf, 512, fp) != NULL){
        getValue(1, buf, curr);
        getValue(4, buf, currID);
        if (chareq(a, curr) && chareq(info->id, currID)){
            flag = false;
            break;
        }
    }
    fclose(fp);
    return flag;
}

void modify_itemStatus(INFO *info, const char *s){
    modify_itemStatus(info, const_cast<char *>(s));
}

void modify_itemStatus(INFO *info, char *s){
    // change the status in to s
    FILE *fp = nullptr;
    fp = fopen("../src/dataset/item", "rb+");
    if (fp == nullptr){
        std::perror("dataset Error ");
        exit(1);
    }
    bool flag = false;
    char buf[512], curr[40], currID[7];
    while (fgets(buf, 512, fp) != NULL){
        getValue(1, buf, curr);
        getValue(4, buf, currID);
        if (chareq(info->command, curr) && chareq(info->id, currID)){
            flag = true;
            break;
        }
    }
    // std::cout << "Position in item.cxx: " << ftell(fp) << std::endl;
    int fp_pos = ftell(fp);
    if (flag)
        modifyFeatValue(5, fp, fp_pos, buf, s);
    else
        std::cout << "[error] |The key word is not found. Please check and enter the full info.\n";

    // modifyFeatValue
}

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
            std::perror("dataset Error ");
            exit(1);
        }
        show_table_head(ITEM_HEAD);
        while (fgets(buf, 512, fp) != NULL){
            if (contains(buf, info->id))
                std::cout << ("%s\n", buf);
        }
    }
    else if (contains(info->command, "\t")){
        // more than one item
        fp = fopen("../src/dataset/item", "r");

        if (fp == nullptr){
            std::perror("dataset Error ");
            exit(1);
        }
        show_table_head(ITEM_HEAD);

        char currCommand[40], currName[40], currID[7];
        while (info->command[0] != '\0'){
            popValue(0, info->command, currCommand);

            while (fgets(buf, 512, fp) != NULL){
                getValue(4, buf, currID);
                getValue(1, buf, currName);
                if (chareq(currCommand, currID) || chareq(currCommand, currName))
                    std::cout << ("%s\n", buf);
            }
        }
    }
    else{
        // show only one item
        fp = fopen("../src/dataset/item", "r");

        if (fp == nullptr){
            std::perror("dataset Error ");
            exit(1);
        }
        char currName[40], currID[7], currUser[7], description[256];
        // general info
        while (fgets(buf, 512, fp) != NULL){
            getValue(0, buf, currID);
            getValue(1, buf, currName);
            getValue(4, buf, currUser);
            if (chareq(info->id, currUser) && (chareq(info->command, currID) || chareq(info->command, currName))){
                std::cout << "\n# " << info->command << " #\n";
                std::cout << "Name:   " << currName << std::endl;
                getValue(2, buf, description);
                std::cout << "Price:  " << description << std::endl;
                getValue(3, buf, description);
                std::cout << "Date:   " << description << std::endl;
                getValue(4, buf, description);
                std::cout << "Saler:  " << description << std::endl;
                getValue(5, buf, description);
                if (chareq(description, "1"))
                    std::cout << "Status: " << "sold out" << std::endl;
                else if (chareq(description, "2"))
                    std::cout << "Status: " << "saling" << std::endl;
                else if (chareq(description, "1"))
                    std::cout << "Status: " << "took down" << std::endl;
                else
                    std::cout << "Status: " << "Unknown..." << std::endl;
                getValue(0, currID, info->command);
            }
        }
        fclose(fp);
        // item description
        fp = fopen("../src/dataset/item_desc", "r");
        while (fgets(buf, 512, fp) != NULL){
            getValue(0, buf, currID);
            getValue(1, buf, currName);
            if (chareq(info->command, currID)){
                getValue(1, buf, description);
                std::cout << "Description:\n  " << description << std::endl;
            }
        }
    }
    // end
    fclose(fp);
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
    // todo : transform into "YYYY-MM-DD"
    idx = 0;
    time_t now = time(0);
    char* dt = ctime(&now);
    while (dt[idx] != '\0'){
        retChar[i] = dt[idx];
        i++; idx++;
    }
    i -= 1; // a \n at the end of dt !!!
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

void modify_itemInfo(INFO *info);