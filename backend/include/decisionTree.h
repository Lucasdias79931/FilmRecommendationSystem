#pragma once

#include "structs.h"
#include "linked_list.h"
#include "enums.h"

#include <string>

class DecisionTree {
private:
    struct Node {
        std::string id;
        std::string question;

        Node* yes;
        Node* no;

        Linked_list<Movie>* movies;

        Node(const std::string& id, const std::string& question): id(id), question(question), yes(nullptr), no(nullptr), movies(nullptr) {}

        Node(const std::string& id): id(id), question(""), yes(nullptr), no(nullptr), movies(new Linked_list<Movie>()) {}

        bool isLeaf() const {
            return movies != nullptr;
        }
    };

    Node* root;
    size_t size;

    void buildTree();
    void destroy(Node* node);

    Node* findNode(Node* node, const std::string& id);

public:
    DecisionTree();
    ~DecisionTree();

    Node* getNode(const std::string& id);
    Node* nextNode(const std::string& id, bool answer);

    void insert(const Movie& movie);
};