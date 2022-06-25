//
// Created by anish on 25-06-2022.
//

#ifndef NETFLIXALT_FUNCTIONS_H
#define NETFLIXALT_FUNCTIONS_H

void downloadMovie(char []); // done
void sendMovie(char [], char []); // done
void getMovie(char [], char []); // done
void deleteMovie(char []); // done
void viewMovies(); // done
int hasMovie(int, char []);  // done
int friendSearch(char []); // done
//int movieListSearch(char []); // done


// Movie filter
void findMoviebygenre();

// Miscellaneous
void printWelcome();
void friendsCall();
void moviesCall();

// Friends functions
void viewinMovies(int);
void addfriend();
void removefriend();
void friendmovie();
void viewfriends();
void policy();

#endif //NETFLIXALT_FUNCTIONS_H
