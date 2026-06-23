#include "data-structures/storage.h"


Movie Storage::parse_movie(const nlohmann::json& item) {
    Movie m(
        item.value("name", ""),
        stringToCategory(item.value("category", "UNKNOWN")),
        item.value("origin", ""),
        item.value("style", ""),
        item.value("pace", ""),
        item.value("year", 0),
        item.value("rate", 0.0f)
    );

    m.id = item.value("id", "");

    return m;
}

nlohmann::json Storage::to_json(const Movie& m) {
    return {
        {"id", m.id},
        {"name", m.name},
        {"category", toString(m.category)},
        {"origin", m.origin},
        {"style", m.style},
        {"pace", m.pace},
        {"year", m.year},
        {"rate", m.rate}
    };
}

bool Storage::match(const Filters& f, const Movie& m) {
    
    if (f.category != CategoryMovie::UNKNOWN && m.category != f.category)
        return false;

    if (!f.origin.empty() && m.origin != f.origin)
        return false;

    if (!f.style.empty() && m.style != f.style)
        return false;

    if (!f.pace.empty() && m.pace != f.pace)
        return false;

    return true;
}



void Storage::addMovie(Movie& movie) {
    std::unique_lock lock(file_mutex);

    if(movie.id.empty()){
        movie.id = generate_uuid();
    }
    std::ofstream file(db_path, std::ios::app);
    file << to_json(movie).dump() << "\n";
}

Linked_list<Movie> Storage::getMovies(Filters& filters) {
    std::shared_lock lock(file_mutex);

    std::ifstream file(db_path);
    Linked_list<Movie> result;

    std::string line;

    while (std::getline(file, line)) {
        json j = json::parse(line);
        Movie m = parse_movie(j);

        if (match(filters, m)) {
            result.push_back(m);
        }
    }

    return result;
}

Linked_list<Movie> Storage::getMovies() {
    std::shared_lock lock(file_mutex);

    std::ifstream file(db_path);
    Linked_list<Movie> result;

    std::string line;

    while (std::getline(file, line)) {
        json j = json::parse(line);
        Movie m = parse_movie(j);
    }

    return result;
}

void Storage::updateMovie(std::string id, const Movie& updated) {
    std::unique_lock lock(file_mutex);

    std::ifstream in(db_path);
    std::ofstream out("temp.jsonl");

    std::string line;

    while (std::getline(in, line)) {
        json j = json::parse(line);
        Movie m = parse_movie(j);

        if (m.id == id) {
            out << to_json(updated).dump() << "\n";
        } else {
            out << line << "\n";
        }
    }

    in.close();
    out.close();

    std::remove(db_path.c_str());
    std::rename("temp.jsonl", db_path.c_str());
}

void Storage::deleteMovie(std::string id) {
    std::unique_lock lock(file_mutex);

    std::ifstream in(db_path);
    std::ofstream out("temp.jsonl");

    std::string line;

    while (std::getline(in, line)) {
        json j = json::parse(line);
        Movie m = parse_movie(j);

        if (m.id != id) {
            out << line << "\n";
        }
    }

    in.close();
    out.close();

    std::remove(db_path.c_str());
    std::rename("temp.jsonl", db_path.c_str());
}