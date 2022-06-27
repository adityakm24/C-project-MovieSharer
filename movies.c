//
// Created by anish on 25-06-2022.
//

#include <stdio.h>
#include "functions.h"
#include "structs.h"

extern User users[10];
extern Movie movies[10];
extern Friend friends[10];
extern Usermovie usermovies[10];

//extern int UserSearch(char []);
//extern int MovieSearch(char []);

extern log_user;

void downloadMovie(char movie[255]) {
    int movie_id = MovieSearch(movie);
    if(movie_id == -1) {
        printf("Movie not found!\n");
        return;
    }

    if(hasMovie(log_user, movie) != -1) {
        printf("\'%s\' is already in your storage!\n", movie);
        return;
    }

    int count = 0, ch1;
    int friendHasMovie[255], friend_id;
    char friend_name[255];

    for(int i = 0; i < friends[log_user].friendCount; i++) {
        friend_id = friends[log_user].fid[i];
        if(hasMovie(friend_id, movie) != -1) {
            friendHasMovie[count] = friend_id;
            count++;
        }
    }

    if(count) {
        printf("%d of your friend(s) have the movie %s\n", count, movie);
        for(int i = 0; i < count; i++) {
            printf("%d. %s\n", i+1, users[friendHasMovie[i]].uname);
        }

        do {
            printf("Do you want to download from any of them(1 for yes, 2 for no)? ");
            scanf("%d", &ch1);
        } while(ch1 != 1 && ch1 != 2);

        if (ch1 == 1) {
            printf("Enter the name of friend you want to download from: ");
            scanf("%s", friend_name);
            getMovie(movie, friend_name);
//            usermovies[log_user].mid[usermovies[log_user].movieCount] = movie_id;
//            usermovies[log_user].movieCount++;
//            printf("%s has been been downloaded from %s\n", movie, friend_name);
            return;
        }
        usermovies[log_user].mid[usermovies[log_user].movieCount] = movie_id;
        usermovies[log_user].movieCount++;
        printf("%s has been downloaded from our repositories\n", movie);
    }
    else {
        usermovies[log_user].mid[usermovies[log_user].movieCount] = movie_id;
        usermovies[log_user].movieCount++;
        printf("%s has been downloaded from our repositories\n", movie);
    }

}

void deleteMovie(char movie[255]) {
    int id = MovieSearch(movie), n = usermovies[log_user].movieCount;
    int index = hasMovie(log_user, movie);
    if (id == -1) {
        printf("Enter valid movie name!\n");
        return;
    }
    if (index == -1) {
        printf("\'%s\' does not exist in your storage.\n", movie);
    }
    for(int i = index; i < n - 1; i++) {
        usermovies[log_user].mid[i] = usermovies[log_user].mid[i + 1];
    }
    usermovies[log_user].movieCount--;
    printf("%s deleted from your storage.\n", movie);
}

void viewMovies() {
    int n = usermovies[log_user].movieCount;
    if (n) {
        printf("Movies in your storage: \n");
        for(int i = 0; i < usermovies[log_user].movieCount; i++) {
            printf("%d. %s\n", i + 1, movies[usermovies[log_user].mid[i]].mTtile);
        }
    }
    else {
        printf("Oops! You don't have any movies in your storage.\n");
    }

}

void sendMovie(char movie[255], char friend[255]) {
    int movie_id = MovieSearch(movie);
    int friend_id = UserSearch(friend);
    int friend_index = friendSearch(friend);
    int movie_index = hasMovie(log_user, movie);
    if (movie_id == -1) {
        printf("Enter valid movie name!\n");
        return;
    }
    if (friend_id == -1) {
        printf("Enter valid user name!\n");
        return;
    }
    if (movie_index == -1) {
        printf("Movie \'%s\' does not exit in your storage.\n", movie);
        return;
    }
    if (friend_index == -1) {
        printf("User \'%s\' does not exit in your friends list.\n", friend);
        return;
    }
    usermovies[friend_id].mid[usermovies[friend_id].movieCount] = movie_id;
    usermovies[friend_id].movieCount++;
    printf("\'%s\' successfully sent to %s", movie, friend);
}

void getMovie(char movie[255], char friend[255]) {
    int movie_id = MovieSearch(movie);
    int friend_id = UserSearch(friend);
    int friend_index = friendSearch(friend);
    int movie_index = hasMovie(friend_id, movie);

    if (movie_id == -1) {
        printf("Enter valid movie name!\n");
        return;
    }
    if (friend_id == -1) {
        printf("Enter valid friend name!\n");
        return;
    }
    if (friend_index == -1) {
        printf("\'%s\' does not exist in your friends list!\n", friend);
        return;
    }
    if (movie_index == -1) {
        printf("%s does not have \'%s\'!\n", friend, movie);
        return;
    }
    usermovies[log_user].mid[usermovies[log_user].movieCount] = movie_id;
    usermovies[log_user].movieCount++;
    printf("You received \'%s\' from %s\n\n", movie, friend);

}
