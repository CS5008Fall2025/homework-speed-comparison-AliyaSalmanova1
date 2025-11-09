/**
 * Contains functions for the sorted vector struct
 *
 * @author: Aliya Salmanova
 * @class: CS 5008
 * @term: Fall 2025
**/

#include "vector.h"
#include "movie.h"


/**
 * adds a movie to the sorted vector.
 * 
 * Based on the movie (compare_movies), it will find the correct index
 * using a linear search.
 * 
 * The moment it finds that the movie to add is greater than the
 * current movie, it will insert it at that next index calling vector_insert.
 * 
 * 
 * @param vector the vector to add the movie to
 * @param movie the movie to add
*/
void add_to_sorted_vector(SortedMovieVector * vector, Movie * movie) {

    if (vector == NULL || movie == NULL) return;

    int i = 0;
    while (i < vector->size && compare_movies(vector->movies[i], movie) < 0) i++;

    vector_insert(vector, movie, i);
}

/**
 * Finds a movie in the sorted vector based on the title only of the movie.
 *
 * strcasecmp is used to compare the titles, so the search is case insensitive.
 *
 * For example: int cmp = strcasecmp(title, movie->title);
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one. 
 *
 * @param vector the vector to search
 * @param title the title of the movie to find
 * @return the movie if found, NULL otherwise
 */

Movie * binarySearch(Movie **movies, const char *title, int left, int right){
    if (movies == NULL || title == NULL) return NULL;
    if (left >= right) return NULL;
    int mid = (left + right) / 2;
    int comparison = strcasecmp(movies[mid]->title, title);
    
    if (comparison == 0) return movies[mid];
    else if (comparison > 0){
        return binarySearch(movies, title, left, mid);
    }else {
        return binarySearch(movies, title, mid + 1, right);
    }    
}


Movie * find_in_sorted_vector(SortedMovieVector * vector, const char * title) {
    // STUDENT TODO: implement this function
    Movie * movie = binarySearch(vector->movies, title, 0, vector->size);
   
    // if the movie is not found, return NULL
    return movie;
}

/**
 * Checks if the sorted vector contains a movie with the given title.
 *
 * Very similar to find_in_sorted_vector, but instead of just finding
 * the movie will call vector_remove(vector, index) to remove the movie
 * returning the resulted removed movie.
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one.
 *
 * @param vector the vector to check
 * @param title the title to check for
 * @return the movie removed, NULL otherwise
 */

int binarySearchInt(Movie **movies, const char *title, int left, int right){
    int mid = (left + right) / 2;
    int comparison = strcasecmp(movies[mid]->title, title);
    if (left >= right) return -1;
    if (comparison == 0) return mid;
    else if (comparison > 0){
        return binarySearchInt(movies, title, left, mid);
    }else {
        return binarySearchInt(movies, title, mid + 1, right);
    }    
}
Movie* sorted_vector_remove(SortedMovieVector *vector, const char *title){
    // STUDENT TODO: implement this function
    if (vector == NULL) return NULL;

    int index = binarySearchInt(vector->movies, title, 0, vector->size);
    if (index == -1) return NULL;
    
    Movie * vector_to_remove = vector_remove(vector, index);

    return vector_to_remove;
}
