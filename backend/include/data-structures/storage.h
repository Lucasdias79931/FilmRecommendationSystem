#pragma once
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <nlohmann/json.hpp>
#include <fstream>
#include "linked_list.h"
#include "structs.h"
#include "enums.h"
#include "utils.h"

using json = nlohmann::json;

class Storage {
private:
    std::shared_mutex file_mutex;
    const std::string db_path;

    Movie parse_movie(const nlohmann::json& item);

    nlohmann::json to_json(const Movie& m);

    bool match(const Filters& f, const Movie& m);

    public:
    
    Storage(const std::string& path) : db_path(path) {}

    void addMovie(Movie& movie);

    Linked_list<Movie> getMovies(Filters& filters);

    Linked_list<Movie> getMovies();

    void updateMovie(std::string id, const Movie& updated);

    void deleteMovie(std::string id);
};