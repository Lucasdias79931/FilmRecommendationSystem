#pragma once
#include <string>
#include <stdexcept>



enum class CategoryMovie {
    Romance,
    Action,
    Comedy,
    Drama,
    Horror,
    SciFi,
    Documentary,
    Thriller,
    Animation,
    UNKNOWN
};





std::string toString(CategoryMovie category);


CategoryMovie stringToCategory(const std::string& str);

