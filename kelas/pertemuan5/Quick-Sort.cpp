#include <iostream>
#include <utility>
using namespace std;

// Inisialisasi Array Global
int arr[] = {3, 4, 2, 9, 8, 6, 5, 7};
int n = sizeof(arr) / sizeof(arr[0]);

void quickSort(int arr[], int low, int high) {
    // Base case: jika pointer low melewati high, berhenti
    if (low >= high) return;

    // Menentukan data tengah sebagai pivot (Strategi yang lebih stabil)
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];

    int i = low, j = high;

    // Proses Partisi (Hoare Partition Scheme)
    while (i <= j) {
        // Cari elemen di kiri yang >= pivot
        while (arr[i] < pivot) {
            i++;
        }
        // Cari elemen di kanan yang <= pivot
        while (arr[j] > pivot) {
            j--;
        }
        // Tukar elemen jika ditemukan posisi yang salah
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Rekursi untuk sub-array bagian kiri (dari low sampai j)
    if (low < j) {
        quickSort(arr, low, j);
    }
    // Rekursi untuk sub-array bagian kanan (dari i sampai high)
    if (i < high) {
        quickSort(arr, i, high);
    }
}

int main() {
    cout << "Data Belum Terurut: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Memanggil fungsi Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Hasil Quick Sort : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}