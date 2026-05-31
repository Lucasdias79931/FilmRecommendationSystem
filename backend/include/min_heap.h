#pragma once
#include "structs.h"
#include <vector>

class Min_heap {
private:
    std::vector<Movie> movies;
    size_t capacity; 
    size_t count;    

public:
    Min_heap(size_t k) : capacity(k), count(0) {
        movies.reserve(k); 
    }

    void heapifyDown(int index);
    void heapifyUp(int index);
    void insertTopK(const Movie& movie);
};