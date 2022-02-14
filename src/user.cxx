
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
    else if (info->_page == 11){ // sign in
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
                    info->_page = 100;
                else if (_type == '2')
                    info->_page = 200;
                else
                    info->_page = 1;
            }
            break;
        }
    }
    else if (info->_page == 12){ // sign up
        // todo checkUniq
        if (!checkUniq(info, 1, name)){
            info->_page = 1;
            return false;
        }
        info->_page = 1;
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