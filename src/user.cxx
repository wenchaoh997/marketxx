
#include "../include/user.h"

bool userSign(INFO *info, char *name, char *passward){
    bool flag = false;
    char buf[512];
    int i;
    FILE *fp = nullptr;
    fp = fopen("../src/dataset/user", "r");
    if (fp == nullptr){
        std::perror("Error ");
        std::exit(1);
    }
    else if (info->_page == LOGIN){ // sign in
        char nameFeat[40], passwardFeat[20], _type;
        while (fgets(buf, 512, fp) != NULL){
            getValue(1, buf, nameFeat);
            if (!chareq(nameFeat, name))
                continue;
            getValue(2, buf, passwardFeat);
            if (chareq(passwardFeat, passward)){
                flag = true;
                getValue(6, buf, &_type);
                if (_type == '1')
                    info->_page = USER_MENU;
                else if (_type == '2')
                    info->_page = ADMIN_MENU;
                else
                    info->_page = MAIN_MENU;
            }
            break;
        }
        for (int i = 0; i < 6; i++)
            info->id[i] = buf[i];
    }
    else if (info->_page == REGISTER){ // sign up
        // todo checkUniq
        if (!checkUniq(info, 1, name)){
            info->_page = MAIN_MENU;
            return false;
        }
        info->_page = MAIN_MENU;
        fclose(fp);
        fp = fopen("../src/dataset/user", "ab");
        char retChar[512];
        retChar[0] = 'U';
        randID(retChar, 1, 6);
        while (!checkUniq(info, 0, retChar))
            randID(retChar, 1, 6);
        retChar[6] = SPLIT;

        i = 7;
        int idx = 0;
        while (name[idx] != '\0'){
            retChar[i] = name[idx];
            i++;idx++;
        }
        retChar[i++] = SPLIT;
        idx = 0;
        while (passward[idx] != '\0'){
            retChar[i] = passward[idx];
            i++;idx++;
        }
        for (idx = 0; idx < 4; idx++, i++)
            retChar[i] = SPLIT;
        // default normal user
        retChar[i] = '1';
        fputs(retChar, fp);
        fputs("\n", fp);
        fclose(fp);
        std::cout << "\n[info] |The info has been stored.\n";
        std::cout << "****Succeed****\n";

        flag = true;
    }
    return flag;
}

void manage_items(INFO *info){
    /*
     * the common user can post or modify their items
     * the admin can only modify the STATUS of items
     */
    std::cout << "\nEnter your operation on Items:\n";
    std::cin.getline(info->command, 256);
    std::cin.clear();

    int commandType = loadCommand(info);

    std::cout << "\n################\ncommandType : " << commandType << std::endl;

    if (commandType == 1){ // down
        // modify feat_5

    }
    else if (commandType == 2){ // view
        show_itemValue(info);
    }
    else if (commandType == 3){ // post
        info->_page = CREATE_ITEM;
        post_item(info);
    }
    else if (commandType == 4){ // modify

    }
    else
        std::cout << "\n[error] |Unexpected command, try again. \n";
    if (info->_page < ADMIN_MENU) info->_page = USER_MENU;
    else info->_page = ADMIN_MENU;
}

void manage_orders(INFO *info){

    if (info->_page < ADMIN_MENU) info->_page = USER_MENU;
    else info->_page = ADMIN_MENU;
}

void manage_users(INFO *info){

    if (info->_page < ADMIN_MENU) info->_page = USER_MENU;
    else info->_page = ADMIN_MENU;
}