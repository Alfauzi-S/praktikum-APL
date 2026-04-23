#include <iostream>
#include <algorithm>
using namespace std;

struct Barang {
    int id;
    float berat;
    float nilai;
    float rasio;
};

bool bandingkanBarang(Barang a, Barang b) {
    return a.rasio > b.rasio;
}

int main() {
    Barang items[] = {
        {1, 10, 60, 0}, // Fixed: Removed invalid comments
        {2, 20, 100, 0}  // Fixed: Proper comma separation
    };
    int n = 2;
    float kapasitas = 15;
    float totalNilai = 0;
    
    for (int i = 0; i < n; i++) { // Fixed: i++ instead of i+
        items[i].rasio = items[i].nilai / items[i].berat;
    }
    
    sort(items, items + n, bandingkanBarang);
    
    cout << "===== FRACTIONAL KNAPSACK (GREEDY) =====" << endl; // Fixed: << operators
    cout << "Kapasitas Tas: " << kapasitas << " kg\n" << endl;
    
    for (int i = 0; i < n; i++) { // Fixed: i++ instead of i+
        if (kapasitas <= 0) break; // Fixed: <= instead of =
        
        if (items[i].berat <= kapasitas) { // Fixed: <= instead of =
            cout << "Ambil Barang " << items[i].id << " utuh (" 
                 << items[i].berat << " kg)" << endl;
            totalNilai += items[i].nilai;
            kapasitas -= items[i].berat;
        } else {
            float bagian = kapasitas / items[i].berat;
            cout << "Ambil Barang " << items[i].id << " sebagian (" 
                 << kapasitas << " kg dari " << items[i].berat << " kg)" << endl;
            totalNilai += items[i].nilai * bagian;
            kapasitas = 0;
        }
    }
    
    cout << "\nTotal Nilai Maksimum: " << totalNilai << endl;
    cout << "Sisa Kapasitas Tas: " << kapasitas << " kg" << endl;
    return 0;
}