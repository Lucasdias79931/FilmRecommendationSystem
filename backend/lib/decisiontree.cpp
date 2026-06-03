#include "data-structures/decisionTree.h"
#include "enums.h"
#include <fstream>
#include <stdexcept>



DecisionTree::DecisionTree() : root(nullptr), size(0){}
DecisionTree::DecisionTree(std::string& db_path) : root(nullptr), size(0) {
    buildTree(db_path);
}

DecisionTree::~DecisionTree() {
    destroy(root);
}


void DecisionTree::buildTree(std::string& db_path) {
    
    std::ifstream file(db_path);

    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir JSON da árvore");
    }

    json j;
    file >> j;

    root = buildNode(j);
}

DecisionTree::Node* DecisionTree::buildNode(const json& j) {
    Node* node = new Node();

    if (!j.contains("id")) {
        delete node;
        throw std::runtime_error("No do JSON sem campo 'id'");
    }
    
    node->id = j.at("id").get<std::string>();

    if (j.contains("filters")) {
        node->isLeaf = true;
        const auto& f = j.at("filters");

        node->filters.category = stringToCategory(f.value("category", "UNKNOWN"));
        node->filters.origin   = f.value("origin", "UNKNOWN");
        node->filters.style    = f.value("style", "UNKNOWN");
        node->filters.pace     = f.value("pace", "UNKNOWN");

        node->yes = nullptr;
        node->no = nullptr;
    } 
    else if (j.contains("yes") && j.contains("no")) {
        node->isLeaf = false;
        node->question = j.value("question", "");
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



void DecisionTree::_list_filters(Node *root){
    if(root == nullptr) return;

    _list_filters(root->yes);

    if(root->isLeaf){
        std::cout << "---- Leaf ----\n";
        std::cout << "Category: " << toString(root->filters.category) << "\n";
        std::cout << "Origin: "   << root->filters.origin   << "\n";
        std::cout << "Style: "    << root->filters.style    << "\n";
        std::cout << "Pace: "     << root->filters.pace     << "\n";
        std::cout << "--------------\n";
    }

    _list_filters(root->no);
}

void DecisionTree::list_filters(){
    this->_list_filters(this->root);
}