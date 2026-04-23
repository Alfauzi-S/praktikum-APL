#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept> // Required for runtime_error
using namespace std;

void laporError(const string &pesan, const char *file, int baris,
                const char *fungsi) {
    stringstream ss;
    ss << "\n[CRITICAL ERROR DETECTED!]\n";
    ss << "---------------------------\n";
    ss << "Pesan : " << pesan << endl;
    ss << "File : " << file << endl;
    ss << "Fungsi : " << fungsi << "()" << endl;
    ss << "Baris : " << baris << endl;
    ss << "---------------------------\n";

    throw runtime_error(ss.str());
}

// Fixed macro definitions (proper syntax)
#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            laporError(message, __FILE__, __LINE__, __FUNCTION__); \
        } \
    } while(0)

void prosesData(int index, int pembagi) {
    cout << "Sedang memproses data." << endl;

    if (pembagi == 0) { // Fixed: comparison instead of assignment
        throw runtime_error("Dilarang membagi dengan nol!");
    }

    if (index > 9) { // Fixed: proper comparison for bounds check
        throw runtime_error("Akses index melebihi batas array (Out of Range)!");
    }

    int hasil = 100 / pembagi;
    cout << "Hasil proses: " << hasil << endl;
}

int main() {
    cout << "===== PROGRAM PENDETEKSI KESALAHAN OTOMATIS =====" << endl;

    try {
        // Skenario 1: Normal
        prosesData(5, 2);

        // Skenario 2: Error
        cout << "\nMencoba skenario berbahaya." << endl;
        prosesData(15, 5); // This will trigger bounds error
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}