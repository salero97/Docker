#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    cout << "C++ контейнер запущен!" << endl;
    
    while (true) {
        cout << "C++ приложение работает..." << endl;
        this_thread::sleep_for(chrono::seconds(10));
    }
    
    return 0;
}