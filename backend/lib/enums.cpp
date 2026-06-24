#include "enums.h"

std::string toString(CategoryMovie category) {
    switch (category) {
        case CategoryMovie::Romance: return "Romance";
        case CategoryMovie::Action: return "Action";
        case CategoryMovie::Comedy: return "Comedy";
        case CategoryMovie::Drama: return "Drama";
        case CategoryMovie::Horror: return "Horror";
        case CategoryMovie::SciFi: return "SciFi";
        case CategoryMovie::Documentary: return "Documentary";
        case CategoryMovie::Thriller: return "Thriller";
        case CategoryMovie::Animation: return "Animation";
        default: return "Unknown";
    }
}


CategoryMovie stringToCategory(const std::string& str) {

    if (str.empty()) return CategoryMovie::UNKNOWN; // ✅ ESSENCIAL

    if (str == "Romance") return CategoryMovie::Romance;
    if (str == "Action") return CategoryMovie::Action;
    if (str == "Comedy") return CategoryMovie::Comedy;
    if (str == "Drama") return CategoryMovie::Drama;
    if (str == "Horror") return CategoryMovie::Horror;
    if (str == "SciFi") return CategoryMovie::SciFi;
    if (str == "Documentary") return CategoryMovie::Documentary;
    if (str == "Thriller") return CategoryMovie::Thriller;
    if (str == "Animation") return CategoryMovie::Animation;

    return CategoryMovie::UNKNOWN; 
}