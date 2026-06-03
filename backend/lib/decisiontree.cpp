#include "data-structures/decisionTree.h"

#include <fstream>
#include <stdexcept>

DecisionTree::DecisionTree() : root(nullptr) {
    buildTree();
}

DecisionTree::~DecisionTree() {
    destroy(root);
}


void DecisionTree::buildTree() {
    std::ifstream file("/mnt/data/decision_tree.json");

    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir JSON da árvore");
    }

    json j;
    file >> j;

    root = buildNode(j);
}

DecisionTree::Node* DecisionTree::buildNode(const json& j) {
    Node* node = new Node();

    node->id = j.at("id").get<std::string>();

    if (j.contains("filters")) {
        node->isLeaf = true;

        const auto& f = j.at("filters");

        node->filters.category = stringToCategory(f.at("category").get<std::string>());
        node->filters.origin   = stringToOrigin(f.at("origin").get<std::string>());
        node->filters.style    = stringToStyle(f.at("style").get<std::string>());
        node->filters.pace     = stringToPace(f.at("pace").get<std::string>());

        node->yes = nullptr;
        node->no = nullptr;
    }
    else {
        node->isLeaf = false;
        node->question = j.at("question").get<std::string>();

        node->yes = buildNode(j.at("yes"));
        node->no  = buildNode(j.at("no"));
    }

    return node;
}


DecisionTree::Node* DecisionTree::findNode(Node* root, const std::string& id) {
    if (!root) return nullptr;

    if (root->id == id) return root;

    Node* left = findNode(root->yes, id);
    if (left) return left;

    return findNode(root->no, id);
}

DecisionTree::Node* DecisionTree::getNode(const std::string& id) {
    return findNode(root, id);
}

DecisionTree::Node* DecisionTree::nextNode(const std::string& id, bool answer) {
    Node* current = getNode(id);
    if (!current) return nullptr;

    return answer ? current->yes : current->no;
}


void DecisionTree::destroy(Node* node) {
    if (!node) return;

    destroy(node->yes);
    destroy(node->no);

    delete node;
}