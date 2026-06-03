#include "json-comunicate/MovieDB.h"
#include <fstream>
#include <iostream>
#include <iostream>

nlohmann::json MovieDB::db;

void MovieDB::load(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Error in try load file");
        return;
    }

    file >> db;
}

const nlohmann::json& MovieDB::get() {
    return db;
}