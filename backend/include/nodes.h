#pragma once 

template <typename T>
class Linear_node{
    T data;
    Linear_node<T> *prev, *next;

    Linear_node(T data):data(data), prev(nullptr), next(nullptr){}
    Linear_node(): prev(nullptr), next(nullptr){}
};



template <typename T>
class Node_tree{
    T data;
    Node_tree<T> *left, *right;
    Node_tree(T data):data(data), left(nullptr), right(nullptr);
    Node_tree():left(nullptr), right(nullptr);
};