//
// Created by anish on 25-06-2022.
//

#include "functions.h"
#include "structs.h"
#include <stdio.h>

extern User users[10];
extern Movie movies[10];
extern Friend friends[10];
extern Usermovie usermovies[10];

//extern int UserSearch(char []);

extern log_user;

void addfriend(){
    char name[255];
    printf("Enter Your Friends UserName: ");
    scanf("%s",name);
    int check = UserSearch(name);
    int doublecheck = friendSearch(name);
    if (check != -1 && doublecheck != -1) printf("Username does not exist in the database");
    else
    {
        friends[log_user].fid[friends[log_user].friendCount] = check;
        friends[log_user].friendCount++;
        printf("%s is added to your friend database",name);
    }
}
void removefriend(){
    char name[255];
    printf("Enter Your Friends Name");
    scanf("%s",name);
    int check= UserSearch(name);
    int doublecheck = friendSearch(name);
    if (check == -1)printf("Your friend does not exist in the database");
    else if(doublecheck ==-1)printf("You didn't allocate this user as your friend previously the database (mf)");
    else
    {
        for (int k = doublecheck; k <= friends[log_user].friendCount ; k++) {
            friends[log_user].fid[k]=friends[log_user].fid[k+1];
        }
        friends[log_user].friendCount--;
        printf("%s is removed from your friend database",name);
    }
}
void friendmovie() {
    printf("Which friend's movies list do you need to see\n");
    viewfriends();
    char buddy[255];
    printf("Enter Your Friends Name: ");
    scanf("%s", buddy);
    int check = UserSearch(buddy);
    viewinMovies(check);

}
void viewfriends(){
    printf("Your Friends\n");
    for(int i=0;i<friends[log_user].friendCount;i++){
        printf("<%d> %s\n",i,users[friends[log_user].fid[i]].uname);

    }
}

void viewinMovies(int n) {

    if (usermovies[n].movieCount == 0) {
        printf("Oops! Your friend doesnt have any movies in their storage.\n");

    }
    else  {
        printf("Movies in your friends storage: \n");
        for(int i = 0; i < usermovies[n].movieCount; i++) {
            printf(" %s\n", movies[usermovies[n].mid[i]].mTtile);
        }
    }

}