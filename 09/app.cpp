#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::string path = "/home/filedir/text.txt";
    std::ifstream file(path);
    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    } else {
        std::cout << "File not found: " << path << "\n";
    }
    return 0;
}
