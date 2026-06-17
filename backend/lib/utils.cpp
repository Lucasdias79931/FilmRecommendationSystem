#include "utils.h"

std::string generate_uuid() {
    uuid_t id;
    uuid_generate_random(id);

    char str[37];
    uuid_unparse(id, str);

    return std::string(str);
}