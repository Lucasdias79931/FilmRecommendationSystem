#pragma once 

template <typename T>
class Node_lists{
    T data;
    Node_lists<T> *prev, *next;

    Node_lists(T data):data(data), prev(nullptr), next(nullptr){}
    Node_lists(): prev(nullptr), next(nullptr){}
};



template <typename T>
class Node_tree{
    T data;
    Node_tree<T> *left, *right;
    Node_tree(T data):data(data), left(nullptr), right(nullptr);
    Node_tree():left(nullptr), right(nullptr);
};