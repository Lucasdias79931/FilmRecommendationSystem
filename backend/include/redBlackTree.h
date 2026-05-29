#pragma once

#include "structs.h"      
#include "linked_list.h"  
#include "enums.h"        

class RedBlackTree {
private:
    struct Node {
        CategoryMovie key;          
        Linked_list<Movie> movies;  

        Node* left;
        Node* right;

        bool isRed;

        Node(CategoryMovie key, const Movie& movie):key(key), movies(movie){}
    };

    Node* root;
    size_t size;


    
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    void flipColors(Node* node);

    bool isRed(Node* node);

    void destroy(Node* node); 

    public:
        RedBlackTree();
        ~RedBlackTree();

        void insert(CategoryMovie key, const Movie& movie);
};