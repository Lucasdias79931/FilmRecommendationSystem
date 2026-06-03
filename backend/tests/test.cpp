#include <iostream>
#include <string>
#include "data-structures/linked_list.h"
#include "data-structures/decisionTree.h"

void test_list() {
    Linked_list<int> numbers;

    std::cout << "Testing linked-list...\nInserting >> ";
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
        numbers.push_back(i);
    }

    std::cout << std::endl;

    const Linear_node<int>* current = numbers.getNode();

    std::cout << "list all element >> ";
    while (current) {
        std::cout << current->data << " "; 
        current = current->next;
    }

    std::cout << "\n";
}

void test_decision_tree(std::string& db_path){
    std::cout << "Testing decision tree";
    DecisionTree decision_tree(db_path);

    std::cout << "Filters" << std::endl;

    decision_tree.list_filters();
}



int main(int argc, char* argv[]) {
    test_list();

    std::string db_path;

    if (argc > 1) {
        db_path = argv[1];
    } else {
        std::cout << "Aviso: Caminho nao fornecido. Usando padrao: ../data/decision_tree.json\n";
        db_path = "../data/decision_tree.json";
    }

    try {
        test_decision_tree(db_path);
    } catch (const std::exception& e) {
        std::cerr << "Erro fatal: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}