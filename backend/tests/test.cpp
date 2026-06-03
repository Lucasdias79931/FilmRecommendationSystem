#include <iostream>
#include "data-structures/linked_list.h"

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


int main() {
    test_list();
    return 0;
}