#include <iostream>
#include <string>
#include "data-structures/linked_list.h"
#include "data-structures/decisionTree.h"
#include "data-structures/storage.h"
#include "structs.h"
#include "enums.h"


void test_add_storage(Storage& storage){
    Movie movie(
        "Os simpsons",
        CategoryMovie::Animation,
        "NACIONAL",
        "COMEDY",
        "Fantasy",
        2004,
        9.9
    );
    storage.addMovie(movie);
}

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

    std::string decision_tree_structured;
    std::string db_path;
    if (argc > 2) {
        decision_tree_structured = argv[1];
        db_path = argv[2];
    } else {
        std::cout << "Aviso: Caminho nao fornecido. Usando padrao: ../data/decision_tree.json\n";
        decision_tree_structured = "../data/decision_tree.json";
        db_path = "..data/db_path_test.json";
    }

    try {
        test_decision_tree(decision_tree_structured);
    } catch (const std::exception& e) {
        std::cerr << "Erro fatal: " << e.what() << std::endl;
        return 1;
    }


    Storage storage(db_path);
    std::cout << "Testing storage" << std::endl;

    try{
        std::cout <<"Testing add movie in storage "<< std::endl;
        test_add_storage(storage);
        std::cout <<"Movie added in storage "<< std::endl;
    } catch (const std::exception& e){
        std::cerr << "Erro fatal: " << e.what() << std::endl;
        return 1;
    }    
    
    Linked_list<Movie> movies;
    try{
        std::cout <<"Testing get all movies"<< std::endl;
        movies = storage.getMovies();
    } catch (const std::exception& e){
        std::cerr << "Erro fatal: " << e.what() << std::endl;
        return 1;
    }    


    return 0;
}