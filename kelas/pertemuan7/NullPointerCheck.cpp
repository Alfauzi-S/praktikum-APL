#include <iostream>
#include <stdexcept>
using namespace std;

void cekData(int *ptr) {
    if (ptr == nullptr) { // Fixed: == instead of =
        throw runtime_error("Error: Pointer bernilai NULL!");
    }
    cout << "Nilai dalam pointer: " << *ptr << endl;
}

int main() {
    try {
        int *dataKosong = nullptr;
        int dataAda = 100;

        cekData(&dataAda);

        cout << "Mencoba akses pointer kosong." << endl;
        cekData(dataKosong);
    }
    catch (const runtime_error &e) {
        cout << "Exception ditangkap: " << e.what() << endl;
    }

    return 0;
}