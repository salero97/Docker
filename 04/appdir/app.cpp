#include <iostream>
#include <unistd.h>
int main() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    std::cout << "Lesson 4" << std::endl;
    std::cout << "Current Directory: " << cwd << std::endl;
    return 0;
}