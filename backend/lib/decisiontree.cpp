#include "decisionTree.h"

DecisionTree::Node* DecisionTree::findNode(Node* node, const std::string& id) {
    if (!node) return nullptr;

    if (node->id == id) return node;

    Node* left = findNode(node->yes, id);
    if (left) return left;

    return findNode(node->no, id);
}

DecisionTree::Node* DecisionTree::getNode(const std::string& id) {
    return findNode(root, id);
}