//
// Created by anish on 25-06-2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "structs.h"

extern User users[10];
extern Movie movies[10];
extern Friend friends[10];
extern Usermovie usermovies[10];

int UserSearch(char Uname[255]) {
    for (int i = 0; i < UserCount; i++) {
        if(!strcmp(Uname, users[i].uname)) {
            return i;
        }
    }
    return -1;
}

int MovieSearch(char mName[255]) {
    for (int i = 0; i < MovieCount; i++) {
        if(!strcmp(mName, movies[i].mTtile)) {
            return i;
        }
    }
    return -1;
}

int friendSearch(char friend[255]) {
    for(int i = 0; i < friends[log_user].friendCount; i++) {
        if (!strcmp(friend, users[friends[log_user].fid[i]].uname)) {
            return i;
        }
    }
    return -1;
}

int hasMovie(int id, char movie[255]) {
    for(int i = 0; i < usermovies[id].movieCount; i++) {
        if(!strcmp(movies[usermovies[id].mid[i]].mTtile, movie)) {
            return i;
        }
    }
    return -1;
}

void login() {
    char uname[255];
    char passwd[255];
    printf("Enter Username: ");
    scanf("%s", uname);
    int id = UserSearch(uname);
    if(id != -1) {
        printf("Enter password:");
        scanf("%s", passwd);
        if(!strcmp(passwd, users[id].passwd)) {
            log_user = id;
            printWelcome();
            printf("Logged in as %s\n", uname);
        }
        else {
            printf("Wrong username or password!\n");
            exit(1);
        }
    }
    else {
        printf(("Username does not exist!\n"));
        exit(1);
    }
}

void SignUp() {
    char uname[255];
    char passwd[255];
    printf("Enter Username: ");
    scanf("%s", uname);
    int id = UserSearch(uname);
//    printf("%d\n", id);
    if (id == -1) {
        printf("Enter password: ");
        scanf(" %s", passwd);
        users[UserCount].uid = UserCount;
        strcpy(users[UserCount].uname, uname);
        strcpy(users[UserCount].passwd, passwd);
        friends[UserCount].uid = UserCount;
        friends[UserCount].friendCount = 0;
        usermovies[UserCount].uid = UserCount;
        usermovies[UserCount].movieCount = 0;
        log_user = UserCount;
        UserCount++;
        printWelcome();
        printf("Logged in as %s\n", uname);
    }
    else {
        printf("Username already taken!\n");
        exit(1);
    }

}

void printWelcome() {
    printf("=========================================================================================================\n");
    printf("|                                                                                                       |\n");
    printf("|      _/    _/    _/   _/_/_/_/_/   _/           _/_/_/_/_/   _/_/_/_/_/   _/_/_/_/_/_/_/   _/_/_/_/_/ |\n");
    printf("|     _/    _/    _/   _/           _/           _/           _/      _/   _/    _/    _/   _/          |\n");
    printf("|    _/    _/    _/   _/_/_/_/_/   _/           _/           _/      _/   _/    _/    _/   _/_/_/_/_/   |\n");
    printf("|   _/    _/    _/   _/           _/           _/           _/      _/   _/    _/    _/   _/            |\n");
    printf("|  _/_/_/_/_/_/_/   _/_/_/_/_/   _/_/_/_/_/   _/_/_/_/_/   _/_/_/_/_/   _/    _/    _/   _/_/_/_/_/     |\n");
    printf("|                                                                                                       |\n");
    printf("=========================================================================================================\n\n");
}