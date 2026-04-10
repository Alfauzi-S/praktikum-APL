#include <iostream>
using namespace std;

// Array Global agar mudah diakses oleh semua fungsi
int arr[] = {38, 27, 43, 3, 9, 82, 10, 55};
int n = sizeof(arr) / sizeof(arr[0]);

// Fungsi untuk menggabungkan dua sub-array yang sudah terbagi
void merge(int arr[], int l, int m, int r) {
    // Buat array temp dengan ukuran dinamis berdasarkan rentang
    int temp[r - l + 1];

    int i = l;      // Indeks awal sub-array kiri
    int j = m + 1;  // Indeks awal sub-array kanan
    int k = 0;      // Indeks awal array temp

    // Bandingkan elemen kiri dan kanan, masukkan yang terkecil ke temp
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Jika sub-array kiri masih ada sisa, masukkan ke temp
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Jika sub-array kanan masih ada sisa, masukkan ke temp
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Salin kembali data dari temp ke array asli (arr)
    for (int x = 0; x < k; x++) {
        arr[l + x] = temp[x];
    }
}

// Fungsi rekursif untuk membagi array (Divide)
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Cari titik tengah
        int m = l + (r - l) / 2;  // Mencegah overflow pada indeks besar

        // Bagi terus sisi kiri dan kanan
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Gabungkan kembali (Conquer & Combine)
        merge(arr, l, m, r);
    }
}

int main() {
    cout << "Sebelum sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Panggil fungsi merge sort
    mergeSort(arr, 0, n - 1);

    cout << "Sesudah sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}