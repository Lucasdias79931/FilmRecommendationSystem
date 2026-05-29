#pragma once

#include "structs.h"
#include "linked_list.h"
#include "enums.h"
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DecisionTree {
private:
    struct Node {
        std::string id;
        std::string question;

        Node* yes;
        Node* no;

        bool isLeaf;
        Filters filters;
    };

    Node* root;
    size_t size;

    void buildTree();
    Node* buildNode(const json& j); 

    void destroy(Node* node);

    Node* findNode(Node* node, const std::string& id);

public:
    DecisionTree();
    ~DecisionTree();

    Node* getNode(const std::string& id);
    Node* nextNode(const std::string& id, bool answer);

};