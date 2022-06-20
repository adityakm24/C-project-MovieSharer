#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct users {
    int uid;
    char uname[255];
    char passwd[255];
} User;

typedef struct Movies {
    int mid;
    char mTtile[255];
    char Genere[255];
    double rating;
} Movie;


int UserCount = 5;
int MovieCount = 5;
int log_user;

User users[10] = {
        {0, "Anish", "12345"},
        {1, "Aditya", "12345"},
        {2, "Allen", "12345"},
        {3, "Ashiq", "12345"},
        {4, "Gokul", "12345"},
};

Movie movies[10] = {
        {0, "Anish", "12345"},
        {1, "Aditya", "12345"},
        {2, "Allen", "12345"},
        {3, "Ashiq", "12345"},
        {4, "Gokul", "12345"},
};


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
            printf("Login Succesfull!");
        }
        else {
            printf("Wrong username or password!");
        }
    }
    else {
        printf(("Username does not exist!"));
    }
}

void SignUp() {
    char uname[255];
    char passwd[255];
    printf("Enter Username: ");
    scanf("%s", uname);
    if (UserSearch(uname) != -1) {
        printf("Enter password");
        scanf(" %s", passwd);
        users[UserCount].uid = UserCount;
        strcpy(users[UserCount].uname, uname);
        strcpy(users[UserCount].passwd, passwd);
        log_user = UserCount;
        UserCount++;
    }
    else {
        printf("Username already taken");
    }

};
int main() {
    int ch;
    printf("Welcome \n 1. Login \n 2. SignUp");
    scanf("%d", &ch);
    if (ch == 1) {
        login();
    }
    else if (ch == 2) {
        SignUp();
    }
    else {
        printf("Please enter a correct choice");
    }

    exit(0);


    return 0;
}
