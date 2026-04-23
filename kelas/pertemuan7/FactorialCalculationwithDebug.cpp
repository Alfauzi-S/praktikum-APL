#include <iostream>
using namespace std;

int hitungFaktorial(int n) {
    int hasil = 1;
    cout << "[DEBUG] Memulai perhitungan untuk n = " << n << endl;
    
    for (int i = 1; i <= n; i++) { // Fixed: <= instead of =, i++ instead of i+
        hasil = hasil * i;
        cout << "[DEBUG] Iterasi ke-" << i << ", hasil sementara: " 
             << hasil << endl;
    }
    return hasil;
}

int main() {
    int angka = 5;
    cout << "Program Faktorial" << endl;

    int hasilAkhir = hitungFaktorial(angka);

    cout << "Hasil Akhir: " << hasilAkhir << endl;
    return 0;
}