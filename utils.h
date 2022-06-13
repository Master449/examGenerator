#ifndef UTILS_H
#define UTILS_H

void clearConsole(){
    if(getenv("HOME") != NULL)
        system("clear");
    else
        system("cls");
}

#endif /* UTILS_H */ 