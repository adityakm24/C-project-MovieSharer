#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "functions.h"
#include "friends.c"
#include "movies.c"
#include "misc.c"



User users[10] = {
        {0, "Anish", "12345"},
        {1, "Aditya", "12345"},
        {2, "Allen", "12345"},
        {3, "Ashiq", "12345"},
        {4, "Gokul", "12345"}
};

Movie movies[10] = {
        {0, "Interceptor", "Action", 4.4},
        {1, "Extraction", "Action", 6.7},
        {2, "Once Upon A Time In Hollywood", "Classic", 7.6},
        {3, "Titanic", "Romance", 7.9},
        {4, "Top Gun", "Action", 6.9}
};

Friend friends[10] = {
        {0, 3, {1, 3, 4}},
        {1, 1, {2}},
        {2, 4, {0, 1, 4, 3}},
        {3, 2, {0, 4}},
        {4, 0, {}}
};

Usermovie usermovies[10] = {
        {0, 1, {4}},
        {1, 3, {0, 1, 2}},
        {2, 2, {3, 0}},
        {3, 1, {0}},
        {4, 0, {}}
};

int main() {
    int ch, ch2;
    printf("Welcome \n 1. Login \n 2. SignUp\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    if (ch == 1) {
        login();
    }
    else if (ch == 2) {
        SignUp();
    }
    else {
        printf("Please enter a correct choice!");
    }

    while (1) {
        printf("Things you can do:\n");
        printf("1. Get movies by genre\n");
        printf("2. Download/send movies\n");
        printf("3. Interact with friends\n");
        printf("4. Exit the program\n");
        printf("Enter your choice[1-4]: ");
        scanf("%d", &ch2);
        fflush(stdin);

        switch (ch2) {
            case 1:
                findMoviebygenre();
                break;
            case 2:
                moviesCall();
                break;
            case 3:
                friendsCall();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Enter valid choice!\n");
        }
    }

    exit(0);

}





//int movieListSearch(char movie[255]) {
//    for(int i = 0; i < usermovies[log_user].movieCount; i++) {
//        if(!strcmp(movie, movies[usermovies[log_user].mid[i]].mTtile)) {
//            return i;
//        }
//    }
//    return -1;
//}

//void request(){
//    int enter;
//    printf("Friends section \n<1> for adding friend\n<2> for removing friend\n<3>viewing friends movie\n<4>view friends\n<5> for policy\n");
//    scanf("%d",&enter);
//    switch(enter)
//    {
//        case 1:addfriend();break;
//        case 2:removefriend();break;
//        case 3:friendmovie();break;
//        case 4:viewfriends();break;
//        case 5:policy();break;
//        default:printf("The given response is wrong!");
//    }
//}



void friendsCall() {
    int ch;

    while (1) {
        printf("\n\n");
        printf("You can do the following: \n");
        printf("1. Add friend\n");
        printf("2. Remove friend\n");
        printf("3. View a friend's movies\n");
        printf("4. View your friends\n");
        printf("5. Exit module\n");
        printf("Choose your poison[1-5]: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addfriend();
                break;
            case 2:
                removefriend();
                break;
            case 3:
                friendmovie();
                break;
            case 4:
                viewfriends();
                break;
            case 5:
                printf("Exiting, back to MAIN....\n\n");
                return;
                break;
            default:
                printf("Enter a valid option!\n");
        }
    }

}

void moviesCall() {
    int ch;
    printf("\n\n");
    char temp1[255], temp2[255];

    while (1) {
        printf("You can do the following: \n");
        printf("1. Download movie\n");
        printf("2. Delete movie from your storage\n");
        printf("3. View movies in your storage\n");
        printf("4. Get movie from friend\n");
        printf("5. Send Movie to friend\n");
        printf("6. Exit\n");
        printf("Choose your poison[1-6]: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch) {
            case 1:
                printf("Movie name: ");
                gets(temp1);
                downloadMovie(temp1);
                break;
            case 2:
                printf("Movie name: ");
                gets(temp1);
                deleteMovie(temp1);
                break;
            case 3:
                viewMovies();
                break;
            case 4:
                printf("Movie name: ");
                gets(temp1);
                printf("Friend name:");
                gets(temp2);
                getMovie(temp1, temp2);
                break;
            case 5:
                printf("Movie name: ");
                gets(temp1);
                printf("Friend name:");
                gets(temp2);
                sendMovie(temp1, temp2);
                break;
            case 6:
                printf("Exiting, back to MAIN....\n\n");
                return;
            default:
                printf("Enter a valid option!\n");
        }
    }
}

void findMoviebygenre()
{
    char name[255],genre[255];
    int arr[255];
    int n=0;
    printf("Enter the movie which you need to find of same genre: ");
    gets(name);
    int index=MovieSearch(name);


    if (index!=-1)
    {
        strcpy(genre,movies[index].Genre);
        for (int i=0;i<=MovieCount;i++)
        {
            if (i==index)
            {
                continue;
            }
            else
            {
                if (!strcmp(genre,movies[i].Genre))
                {
                    arr[n]=i;
                    n++;
                }
            }
        }
        printf("Movies similar to %s\n", name);
        for (int i=0;i<n;i++)
        {
            printf("%d. %s\n", i+ 1,  movies[arr[i]].mTtile);
        }
    }
    else
    {
        printf("\n NO MOVIES AVAILABLE..TRY AGAIN LATER!!!\n");
        return;
    }
}
