#include <iostream>
#include <string>
using namespace std;

// Struktur Data Buku
struct Buku {
    int idBuku;
    string judul;
};

// Fungsi Insertion Sort
void insertionSort(Buku rak[], int n) {
    // Loop luar: mengambil buku satu per satu mulai dari buku kedua
    for (int i = 1; i < n; i++) {
        Buku key = rak[i];
        int j = i - 1;

        /* Loop dalam: Membandingkan 'key' dengan buku di kirinya.
           Jika buku di kiri lebih besar, geser ke kanan. */
        while (j >= 0 && rak[j].idBuku > key.idBuku) {
            rak[j + 1] = rak[j];
            j = j - 1;
        }
        // Sisipkan buku 'key' di posisi yang benar
        rak[j + 1] = key;
    }
}

void tampilkanRak(Buku rak[], int n) {
    for (int i = 0; i < n; i++) {
        cout << rak[i].idBuku << " | " << rak[i].judul << endl;
    }
    cout << endl;
}

int main() {
    int n = 5;

    // SCENARIO 1: BEST CASE (O(n))
    // Data sudah urut, pustakawan hanya mengecek tanpa menggeser.
    Buku rakUrut[] = {
        {101, "Laskar Pelangi"},
        {102, "Bumi Manusia"},
        {103, "Negeri 5 Menara"},
        {104, "Filosofi Teras"},
        {105, "Hujan"}
    };

    cout << "=== BEST CASE (Data Terurut) ===" << endl;
    cout << "Sebelum sort:" << endl;
    tampilkanRak(rakUrut, n);
    insertionSort(rakUrut, n);
    cout << "Setelah sort:" << endl;
    tampilkanRak(rakUrut, n);

    // SCENARIO 2: WORST CASE (O(n^2))
    // Data terbalik, setiap buku harus digeser sampai ke ujung kiri.
    Buku rakTerbalik[] = {
        {105, "Hujan"},
        {104, "Filosofi Teras"},
        {103, "Negeri 5 Menara"},
        {102, "Bumi Manusia"},
        {101, "Laskar Pelangi"}
    };

    cout << "=== WORST CASE (Data Terbalik) ===" << endl;
    cout << "Sebelum sort:" << endl;
    tampilkanRak(rakTerbalik, n);
    insertionSort(rakTerbalik, n);
    cout << "Setelah sort:" << endl;
    tampilkanRak(rakTerbalik, n);

    return 0;
}