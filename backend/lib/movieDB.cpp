#include "MovieDB.h"
#include <fstream>
#include <iostream>

nlohmann::json MovieDB::db;

void MovieDB::load(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error in try load file: " << path << std::endl;
        return;
    }

    file >> db;
}

const nlohmann::json& MovieDB::get() {
    return db;
}