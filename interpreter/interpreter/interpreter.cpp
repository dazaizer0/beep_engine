#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::ifstream file("main.txt");
    std::vector<std::string> commands;

    if (!file.is_open()) {

        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string com;
    while (file >> com) {

        commands.push_back(com);
    }

    for (int i = 0; i < commands.size(); i++) {

        if (commands[i] == "out" && commands[i + 2] == "->") {

            std::cout << commands[i + 1];
        }
    }

    file.close();
    return 0;
}

/*
#include <bitset>

int main() {
    std::string text = "HelloWorld";
    
    for (char c : text) {
        std::bitset<8> binaryChar(c);
        std::cout << binaryChar << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}

int numerAscii = 65; // Przykład: 65 odpowiada literze 'A' w ASCII

char znak = static_cast<char>(numerAscii);

std::cout << "Znak o numerze ASCII " << numerAscii << " to: " << znak << std::endl;

*/