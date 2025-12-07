#include <iostream>
#include <cstdlib>
int main() {
    std::cout << "USERNAME = " << (std::getenv("USERNAME") ? std::getenv("USERNAME") : "not set") << "\n";
    std::cout << "COMPANY = " << (std::getenv("COMPANY") ? std::getenv("COMPANY") : "not set") << "\n";
    std::cout << "ROLE = " << (std::getenv("ROLE") ? std::getenv("ROLE") : "not set") << "\n";
    return 0;
}
