#include <iostream>
#include <utility>
using namespace std;

// Inisialisasi Array Global
int arr[] = {29, 10, 14, 37, 13};
int n = sizeof(arr) / sizeof(arr[0]);

void selectionSort(int arr[], int n) {
    // Loop luar untuk memindahkan batas sub-array yang belum urut
    for (int i = 0; i < n - 1; i++) {
        // Anggap elemen pertama dari bagian belum urut sebagai yang terkecil
        int indeksMin = i;

        // Loop dalam untuk mencari elemen terkecil di sisa array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indeksMin]) {
                indeksMin = j; // Simpan indeks elemen yang lebih kecil
            }
        }

        // Tukar elemen terkecil yang ditemukan dengan elemen di posisi i
        if (indeksMin != i) {
            swap(arr[i], arr[indeksMin]);
        }
    }
}

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Sebelum Selection Sort: ";
    tampilkanArray(arr, n);
    selectionSort(arr, n);
    cout << "Sesudah Selection Sort : ";
    tampilkanArray(arr, n);
    return 0;
}