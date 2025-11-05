#include <iostream>
#include "name.hpp"
using namespace std;


int main() {
    string name = getUserName();
    cout << "Hello, " << name << "!" << endl;
    return 0;
}