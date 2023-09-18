#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream plik("main.txt");

    if (!plik.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string slowo;

    while (plik >> slowo) {
        std::cout << slowo << std::endl;
    }

    plik.close();

    return 0;
}
