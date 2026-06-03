#pragma once

#include <string>
#include <nlohmann/json.hpp>

class MovieDB {
    public:
        static void load(const std::string& path);

        static const nlohmann::json& get();

    private:
        static nlohmann::json db;
};