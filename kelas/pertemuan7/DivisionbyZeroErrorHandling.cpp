#include <iostream>
#include <stdexcept> // Required for runtime_error
using namespace std;

int main() {
    try {
        int a = 10;
        int b = 0;
        if (b == 0) { // Fixed: == instead of =
            throw runtime_error("Error pembagian dengan 0");
        }
        int c = a / b;
        cout << "Hasil: " << c << endl;
    }
    catch (const runtime_error &e) {
        cout << "Error ditangkap: " << e.what() << endl;
    }
    return 0;
}