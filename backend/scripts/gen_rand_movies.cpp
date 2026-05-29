#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime> 

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "use: " << argv[0] << " <path.json>\n";
        return 1;
    }

    std::string path = argv[1];

    srand(time(nullptr));

    std::vector<std::string> categories = {
        "Romance","Action","Comedy","Drama","Horror",
        "SciFi","Documentary","Thriller","Animation"
    };

    std::vector<std::string> origins = {"National", "Foreign"};
    std::vector<std::string> styles = {"Realistic", "Fantasy"};
    std::vector<std::string> paces = {"Fast", "Slow"};

    std::ofstream file(path);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << path << "\n";
        return 1;
    }

    file << "{\n  \"movies\": [\n";

    for (int i = 0; i < 400; i++) {
        std::string name = "Movie_" + std::to_string(i + 1);

        std::string category = categories[rand() % categories.size()];
        std::string origin = origins[rand() % origins.size()];
        std::string style = styles[rand() % styles.size()];
        std::string pace = paces[rand() % paces.size()];
        int year = 1980 + rand() % 45;

        float rate = static_cast<float>(rand()) / RAND_MAX * 5.0f;

        file << "    {\n";
        file << "      \"name\": \"" << name << "\",\n";
        file << "      \"category\": \"" << category << "\",\n";
        file << "      \"origin\": \"" << origin << "\",\n";
        file << "      \"style\": \"" << style << "\",\n";
        file << "      \"pace\": \"" << pace << "\",\n";
        file << "      \"year\": " << year << ",\n";
        file << "      \"rate\": " << rate << "\n";
        file << "    }";

        if (i != 399) file << ",";
        file << "\n";
    }

    file << "  ]\n}";
    file.close();

    std::cout << "Arquivo JSON gerado em: " << path << "\n";

    return 0;
}