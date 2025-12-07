#include <iostream>
#include <fstream>
int main() {
    std::ifstream src("/home/filedir/text.txt", std::ios::binary);
    std::ofstream dst("/home/otherfiledir/text.txt", std::ios::binary);
    dst << src.rdbuf();
    std::cout << "File copied\n";
    return 0;
}
