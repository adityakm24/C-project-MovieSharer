//
// Created by anish on 25-06-2022.
//

#ifndef NETFLIXALT_STRUCTS_H
#define NETFLIXALT_STRUCTS_H

typedef struct user {
    int uid;
    char uname[255];
    char passwd[255];
} User;

typedef struct movie {
    int mid;
    char mTtile[255];
    char Genre[255];
    double rating;
} Movie;

typedef struct frie {
    int uid;
    int friendCount;
    int fid[255];
} Friend;

typedef struct usermovie {
    int uid;
    int movieCount;
    int mid[255];
} Usermovie;

int UserCount = 5;
int MovieCount = 5;
int log_user;

#endif //NETFLIXALT_STRUCTS_H
