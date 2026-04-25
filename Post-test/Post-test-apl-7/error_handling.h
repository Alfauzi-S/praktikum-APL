#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <iostream>
#include <iomanip>
#include <tabulate/table.hpp>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
using namespace tabulate;

class MabelException : public exception {
protected:
    string message;
public:
    explicit MabelException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class ProdukException : public MabelException {
public:
    explicit ProdukException(const string& msg) : MabelException("Produk Error: " + msg) {}
};

class PenggunaException : public MabelException {
public:
    explicit PenggunaException(const string& msg) : MabelException("Pengguna Error: " + msg) {}
};

class ValidationException : public MabelException {
public:
    explicit ValidationException(const string& msg) : MabelException("Validasi Error: " + msg) {}
};

class TransaksiException : public MabelException {
public:
    explicit TransaksiException(const string& msg) : MabelException("Transaksi Error: " + msg) {}
};

void customErrorHandler(const string& pesan, const char* file, int baris, const char* fungsi) {
    cerr << "\n[CRITICAL ERROR DETECTED!]\n";
    cerr << "------------------\n";
    cerr << "Pesan : " << pesan << endl;
    cerr << "File  : " << file << endl;
    cerr << "Fungsi: " << fungsi << "()" << endl;
    cerr << "Baris : " << baris << endl;
    cerr << "------------------\n";
}

#define ASSERT(kondisi, pesan) \
    if (!(kondisi)) { \
        customErrorHandler(pesan, __FILE__, __LINE__, __FUNCTION__); \
        throw ValidationException(pesan); \

int getInputInteger(const string& prompt, int min = 0, int max = numeric_limits<int>::max()) {
    int value;
    while (true) {
        try {
            cout << prompt;
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw ValidationException("Input harus berupa angka");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (value < min) {
                throw ValidationException("Nilai tidak boleh kurang dari " + to_string(min));
            }
            if (value > max) {
                throw ValidationException("Nilai tidak boleh lebih dari " + to_string(max));
            }
            
            return value;
        } catch (const ValidationException& e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Silakan coba lagi." << endl;
        }
    }
}

long long getInputLongLong(const string& prompt, long long min = 0, long long max = numeric_limits<long long>::max()) {
    long long value;
    while (true) {
        try {
            cout << prompt;
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw ValidationException("Input harus berupa angka");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (value < min) {
                throw ValidationException("Nilai tidak boleh kurang dari " + to_string(min));
            }
            if (value > max) {
                throw ValidationException("Nilai tidak boleh lebih dari " + to_string(max));
            }
            
            return value;
        } catch (const ValidationException& e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Silakan coba lagi." << endl;
        }
    }
}

string getInputString(const string& prompt, int minLength = 1, int maxLength = 100) {
    string value;
    while (true) {
        try {
            cout << prompt;
            getline(cin, value);
            
            if (value.length() < minLength) {
                throw ValidationException("Input terlalu pendek (minimal " + to_string(minLength) + " karakter)");
            }
            if (value.length() > maxLength) {
                throw ValidationException("Input terlalu panjang (maksimal " + to_string(maxLength) + " karakter)");
            }
            
            return value;
        } catch (const ValidationException& e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Silakan coba lagi." << endl;
        }
    }
}

void displayMessage(const string& message, int delayMs = 500) {
    cout << ">> ";
    for (char c : message) {
        cout << c << flush;
        #ifdef _WIN32
        Sleep(delayMs / message.length());
        #else
        usleep((delayMs * 1000) / message.length());
        #endif
    }
    cout << endl;
}

#endif