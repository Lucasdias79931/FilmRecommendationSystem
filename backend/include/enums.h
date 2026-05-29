#pragma once

#include <string>

enum class CategoryMovie {
    Romance,
    Action,
    Comedy,
    Drama,
    Horror,
    SciFi,
    Documentary,
    Thriller,
    Animation
};

enum class Origin {
    National,
    Foreign
};

enum class Style {
    Realistic,
    Fantasy
};

enum class Pace {
    Fast,
    Slow
};

std::string categoryToString(CategoryMovie category);
CategoryMovie stringToCategory(const std::string& str);

Origin stringToOrigin(const std::string& str);
Style stringToStyle(const std::string& str);
Pace stringToPace(const std::string& str);