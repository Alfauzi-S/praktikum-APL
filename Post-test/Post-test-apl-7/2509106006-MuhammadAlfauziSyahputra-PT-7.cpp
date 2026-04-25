#include <iostream>
#include <iomanip>
#include <tabulate/table.hpp>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include "error_handling.h"

using namespace std;
using namespace tabulate;

struct alamat {
    string jalan;
    string kota;
    string provinsi;
};

struct pengguna {
    string nama;
    string password;
    string email;
    long long saldo;
    alamat alamat;
};

struct dataAdmin {
    string nama;
    string password;
};

struct material {
    string idMaterial;
    string namaMaterial;
    string jenisMaterial;
};

struct produk {
    int idProduk;
    string namaProduk;
    string jenisProduk;
    long long stock;
    long long harga;
    material material;
};

#define maxadmin 3
#define maxuser 100
#define maxproduk 25

int adminIndex = 3;
int userIndex = 2;
int mabelIndex = 5;

dataAdmin admin[maxadmin];
pengguna user[maxuser];
produk mabel[maxproduk];

void tampilkanHeader(const string& judul) {
    const int lebarTotal = 38;
    const int lebarIsi = lebarTotal - 4;
    
    cout << "\n";
    cout << string(lebarTotal, '=') << endl;
    
    string judulDipotong = judul;
    if (judul.length() > lebarIsi) {
        judulDipotong = judul.substr(0, lebarIsi - 3) + "...";
    }
    
    int panjangJudul = judulDipotong.length();
    int paddingKiri = (lebarIsi - panjangJudul) / 2;
    int paddingKanan = lebarIsi - panjangJudul - paddingKiri;
    
    cout << "||" << string(paddingKiri, ' ') 
         << judulDipotong 
         << string(paddingKanan, ' ') << "||" << endl;
    
    cout << string(lebarTotal, '=') << endl;
}

void tampilkanMabel() {
    if (mabelIndex == 0) {
        cout << "Tidak ada data produk." << endl;
    } else {
        Table table;
        table.add_row({"ID Produk", "Nama Produk", "Jenis Produk", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});
        for (int i = 0; i < mabelIndex; i++) {
            table.add_row({
                to_string(mabel[i].idProduk),
                mabel[i].namaProduk,
                mabel[i].jenisProduk,
                to_string(mabel[i].stock),
                to_string(mabel[i].harga),
                mabel[i].material.idMaterial,
                mabel[i].material.namaMaterial,
                mabel[i].material.jenisMaterial});
        }
        cout << table << endl;
    }
}

void bubbleSortIdProdukAscending(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].idProduk > arr[j + 1].idProduk) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int binarySearchById(produk* arr, int n, int targetId) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].idProduk == targetId) {
            return mid;
        } else if (arr[mid].idProduk < targetId) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int linearSearchByNama(produk* arr, int n, const string& targetName) {
    for (int i = 0; i < n; i++) {
        if (arr[i].namaProduk == targetName) {
            return i;
        }
    }
    return -1;
}

void menuSearchProduk() {
    string pilihan;
    while (true) {
        system("cls");
        tampilkanHeader("MENU SEARCH PRODUK");
        cout << "1. Cari Produk Berdasarkan ID (Binary Search)" << endl;
        cout << "2. Cari Produk Berdasarkan Nama (Linear Search)" << endl;
        cout << "0. Kembali ke Menu Sebelumnya" << endl;
        cout << "Masukkan Pilihan: ";
        getline(cin, pilihan);

        if (pilihan == "1") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk dicari." << endl;
                system("pause");
            } else {
                system("cls");
                tampilkanHeader("CARI PRODUK BERDASARKAN ID");
                int targetId = getInputInteger("Masukkan ID Produk yang dicari: ");

                bubbleSortIdProdukAscending(mabel, mabelIndex);
                cout << "\nArray produk diurutkan berdasarkan ID terlebih dahulu untuk Binary Search." << endl;

                int resultIndex = binarySearchById(mabel, mabelIndex, targetId);

                if (resultIndex != -1) {
                    cout << "\nProduk ditemukan pada indeks ke-" << resultIndex << ":" << endl;
                    Table table;
                    table.add_row({"ID Produk", "Nama Produk", "Jenis Produk", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});
                    table.add_row({
                        to_string(mabel[resultIndex].idProduk),
                        mabel[resultIndex].namaProduk,
                        mabel[resultIndex].jenisProduk,
                        to_string(mabel[resultIndex].stock),
                        to_string(mabel[resultIndex].harga),
                        mabel[resultIndex].material.idMaterial,
                        mabel[resultIndex].material.namaMaterial,
                        mabel[resultIndex].material.jenisMaterial});
                    cout << table << endl;
                } else {
                    cout << "\nProduk dengan ID " << targetId << " tidak ditemukan." << endl;
                }
                system("pause");
            }
        } else if (pilihan == "2") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk dicari." << endl;
                system("pause");
            } else {
                system("cls");
                tampilkanHeader("CARI PRODUK BERDASARKAN NAMA");
                string targetName = getInputString("Masukkan Nama Produk yang dicari: ");

                int resultIndex = linearSearchByNama(mabel, mabelIndex, targetName);

                if (resultIndex != -1) {
                    cout << "\nProduk ditemukan pada indeks ke-" << resultIndex << ":" << endl;
                    Table table;
                    table.add_row({"ID Produk", "Nama Produk", "Jenis Produk", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});
                    table.add_row({
                        to_string(mabel[resultIndex].idProduk),
                        mabel[resultIndex].namaProduk,
                        mabel[resultIndex].jenisProduk,
                        to_string(mabel[resultIndex].stock),
                        to_string(mabel[resultIndex].harga),
                        mabel[resultIndex].material.idMaterial,
                        mabel[resultIndex].material.namaMaterial,
                        mabel[resultIndex].material.jenisMaterial});
                    cout << table << endl;
                } else {
                    cout << "\nProduk dengan Nama '" << targetName << "' tidak ditemukan." << endl;
                }
                system("pause");
            }
        } else if (pilihan == "0") {
            break;
        } else {
            system("cls");
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            system("pause");
        }
    }
}

void bubbleSortNamaProdukDescending(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].namaProduk < arr[j + 1].namaProduk) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void selectionSortHargaAscending(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga < arr[min_idx].harga) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

void insertionSortStockAscending(produk arr[], int n) {
    for (int i = 1; i < n; i++) {
        produk key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].stock > key.stock) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void menuSortProduk() {
    string pilihan;
    while (true) {
        system("cls");
        tampilkanHeader("MENU SORT PRODUK");
        cout << "1. Urutkan Nama Produk (Z-A)" << endl;
        cout << "2. Urutkan Harga (Murah-Mahal)" << endl;
        cout << "3. Urutkan Stock (Rendah-Tinggi)" << endl;
        cout << "4. Urutkan ID Produk (Ascending)" << endl;
        cout << "0. Kembali ke Menu Sebelumnya" << endl;
        cout << "Masukkan Pilihan: ";
        getline(cin, pilihan);

        if (pilihan == "1") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk diurutkan." << endl;
                system("pause");
            } else {
                system("cls");
                tampilkanHeader("SORT NAMA PRODUK (Z-A)");
                cout << "\nDaftar Produk Sebelum Sorting (Nama Produk - Descending):\n";
                tampilkanMabel();
                bubbleSortNamaProdukDescending(mabel, mabelIndex);
                cout << "\nDaftar Produk Setelah Sorting (Nama Produk - Descending):\n";
                tampilkanMabel();
                displayMessage("\nProduk berhasil diurutkan berdasarkan Nama Produk (Z-A)!");
                system("pause");
            }
        } else if (pilihan == "2") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk diurutkan." << endl;
                system("pause");
            } else {
                system("cls");
                tampilkanHeader("SORT HARGA (MURAH-MAHAL)");
                cout << "\nDaftar Produk Sebelum Sorting (Harga - Ascending):\n";
                tampilkanMabel();
                selectionSortHargaAscending(mabel, mabelIndex);
                cout << "\nDaftar Produk Setelah Sorting (Harga - Ascending):\n";
                tampilkanMabel();
                displayMessage("\nProduk berhasil diurutkan berdasarkan Harga (Murah-Mahal)!");
                system("pause");
            }
        } else if (pilihan == "3") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk diurutkan." << endl;
                system("pause");
            } else {
                system("cls");
                tampilkanHeader("SORT STOCK (RENDAH-TINGGI)");
                cout << "\nDaftar Produk Sebelum Sorting (Stock - Ascending):\n";
                tampilkanMabel();
                insertionSortStockAscending(mabel, mabelIndex);
                cout << "\nDaftar Produk Setelah Sorting (Stock - Ascending):\n";
                tampilkanMabel();
                displayMessage("\nProduk berhasil diurutkan berdasarkan Stock (Rendah-Tinggi)!");
                system("pause");
            }
        } else if (pilihan == "4") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk diurutkan." << endl;
                system("pause");
            } else {
                system("cls");
                tampilkanHeader("SORT ID PRODUK (ASCENDING)");
                cout << "\nDaftar Produk Sebelum Sorting (ID Produk - Ascending):\n";
                tampilkanMabel();
                bubbleSortIdProdukAscending(mabel, mabelIndex);
                cout << "\nDaftar Produk Setelah Sorting (ID Produk - Ascending):\n";
                tampilkanMabel();
                displayMessage("\nProduk berhasil diurutkan berdasarkan ID Produk (Ascending)!");
                system("pause");
            }
        } else if (pilihan == "0") {
            break;
        } else {
            system("cls");
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            system("pause");
        }
    }
}

void tampilkanMenuUtama() {
    tampilkanHeader("MENU UTAMA");
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuAdmin() {
    tampilkanHeader("MENU ADMIN");
    cout << "1. Read Produk" << endl;
    cout << "2. Update Produk" << endl;
    cout << "3. Create Produk" << endl;
    cout << "4. Delete Produk" << endl;
    cout << "5. Sort Produk" << endl;
    cout << "6. Search Produk" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuUser() {
    tampilkanHeader("MENU USER");
    cout << "1. Read Data Saya" << endl;
    cout << "2. Read Produk dan Beli" << endl;
    cout << "3. Top Up" << endl;
    cout << "4. Search Produk" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

bool login(bool &isAdmin, string &currentUser) {
    int kesempatan = 3;
    string inNama, inPassword;
    tampilkanHeader("LOGIN");
    while (kesempatan > 0) {
        cout << "\nMasukkan Nama: ";
        getline(cin, inNama);
        cout << "Masukkan Password: ";
        getline(cin, inPassword);

        for (int i = 0; i < adminIndex; i++) {
            if (admin[i].nama == inNama && admin[i].password == inPassword) {
                cout << "\nLogin Admin Berhasil! Selamat Datang, " << inNama << endl;
                isAdmin = true;
                currentUser = admin[i].nama;
                return true;
            }
        }

        for (int i = 0; i < userIndex; i++) {
            if (user[i].nama == inNama && user[i].password == inPassword) {
                cout << "\nLogin User Berhasil! Selamat Datang, " << inNama << endl;
                isAdmin = false;
                currentUser = user[i].nama;
                return true;
            }
        }

        kesempatan--;
        if (kesempatan > 0) {
            cout << "\nLogin Gagal! Sisa percobaan: " << kesempatan << endl;
        } else {
            cout << "\nLogin Gagal! Anda telah mencapai batas percobaan maksimal." << endl;
            cout << "Program akan keluar..." << endl;
            return false;
        }
    }
    return false;
}

void registerUser(int *pUserIndex) {
    try {
        tampilkanHeader("REGISTER USER");
        
        if (*pUserIndex >= maxuser) {
            throw PenggunaException("Jumlah user maksimum (" + to_string(maxuser) + ") telah tercapai.");
        }

        string inNama = getInputString("Masukkan Nama (minimal 3 karakter): ", 3);

        bool isDuplicate = false;
        for (int i = 0; i < *pUserIndex; i++) {
            if (user[i].nama == inNama) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) {
            throw PenggunaException("Nama sudah digunakan. Silakan coba nama lain.");
        }

        user[*pUserIndex].nama = inNama;
        user[*pUserIndex].password = getInputString("Masukkan Password (minimal 6 karakter): ", 6);
        user[*pUserIndex].email = getInputString("Masukkan Email: ", 3, 50);
        user[*pUserIndex].saldo = 0;
        user[*pUserIndex].alamat.jalan = getInputString("Masukkan Alamat Jalan: ", 3);
        user[*pUserIndex].alamat.kota = getInputString("Masukkan kota: ", 2);
        user[*pUserIndex].alamat.provinsi = getInputString("Masukkan Provinsi: ", 2);
        
        displayMessage("\nRegistrasi berhasil! Akun untuk '" + user[*pUserIndex].nama + "' telah dibuat.");
        
        (*pUserIndex)++;
        cout << "Jumlah user saat ini: " << *pUserIndex << endl;
        system("pause");
    } catch (const PenggunaException& e) {
        cerr << "Error: " << e.what() << endl;
        system("pause");
    } catch (const ValidationException& e) {
        cerr << "Error Validasi: " << e.what() << endl;
        system("pause");
    }
}

void updateFieldProduk(produk *pProduk) {
    cout << "Pilih kolom yang ingin diubah:\n";
    cout << "1. ID Produk\n2. Nama Produk\n3. Jenis Produk\n4. Stock\n5. Harga\n6. ID Material\n7. Nama Material\n8. Jenis Material\nPilihan: ";
    string updatePilihan;
    getline(cin, updatePilihan);

    try {
        if (updatePilihan == "1") {
            pProduk->idProduk = getInputInteger("Masukkan ID Produk Baru (angka): ");
        } else if (updatePilihan == "2") {
            pProduk->namaProduk = getInputString("Masukkan Nama Produk Baru: ", 3);
        } else if (updatePilihan == "3") {
            pProduk->jenisProduk = getInputString("Masukkan Jenis Produk Baru: ", 2);
        } else if (updatePilihan == "4") {
            pProduk->stock = getInputLongLong("Masukkan Stock Baru: ", 0);
        } else if (updatePilihan == "5") {
            pProduk->harga = getInputLongLong("Masukkan Harga Baru: ", 0);
        } else if (updatePilihan == "6") {
            pProduk->material.idMaterial = getInputString("Masukkan ID Material Baru: ", 3);
        } else if (updatePilihan == "7") {
            pProduk->material.namaMaterial = getInputString("Masukkan Nama Material Baru: ", 3);
        } else if (updatePilihan == "8") {
            pProduk->material.jenisMaterial = getInputString("Masukkan Jenis Material Baru: ", 3);
        } else {
            throw ValidationException("Pilihan tidak valid.");
        }
    } catch (const ValidationException& e) {
        cerr << "Error: " << e.what() << endl;
        system("pause");
    }
}

void updateProduk() {
    tampilkanHeader("UPDATE PRODUK");
    tampilkanMabel();

    string updateIdStr;
    int updateId;

    try {
        updateId = getInputInteger("Masukkan ID Produk yang ingin diupdate: ");
        
        int index = -1;
        for (int i = 0; i < mabelIndex; i++) {
            if (mabel[i].idProduk == updateId) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            throw ProdukException("ID Produk tidak ditemukan.");
        } else {
            cout << "Produk ditemukan: " << mabel[index].namaProduk << endl;
            produk *pProdukDipilih = &mabel[index];
            updateFieldProduk(pProdukDipilih);
            displayMessage("Produk berhasil diupdate.");
        }
    } catch (const ProdukException& e) {
        cerr << "Error: " << e.what() << endl;
        system("pause");
    } catch (const ValidationException& e) {
        cerr << "Error Validasi: " << e.what() << endl;
        system("pause");
    }
}

void createProduk(int *pMabelIndex) {
    try {
        tampilkanHeader("CREATE PRODUK");
        
        if (*pMabelIndex >= maxproduk) {
            throw ProdukException("Jumlah produk maksimum (" + to_string(maxproduk) + ") telah tercapai.");
        }

        int idBaru = getInputInteger("Masukkan ID Produk (angka): ");

        for (int i = 0; i < *pMabelIndex; i++) {
            if (mabel[i].idProduk == idBaru) {
                throw ProdukException("ID Produk sudah digunakan. Silakan coba ID lain.");
            }
        }

        produk *pProdukBaru = &mabel[*pMabelIndex];
        pProdukBaru->idProduk = idBaru;
        pProdukBaru->namaProduk = getInputString("Masukkan Nama Produk: ", 3);
        pProdukBaru->jenisProduk = getInputString("Masukkan Jenis Produk: ", 2);
        pProdukBaru->stock = getInputLongLong("Masukkan Stock Baru: ", 0);
        pProdukBaru->harga = getInputLongLong("Masukkan Harga Baru: ", 0);
        pProdukBaru->material.idMaterial = getInputString("Masukkan ID Material: ", 3);
        pProdukBaru->material.namaMaterial = getInputString("Masukkan Nama Material: ", 3);
        pProdukBaru->material.jenisMaterial = getInputString("Masukkan Jenis Material: ", 3);
        
        (*pMabelIndex)++;
        displayMessage("Produk berhasil ditambahkan.");
        system("pause");
    } catch (const ProdukException& e) {
        cerr << "Error: " << e.what() << endl;
        system("pause");
    } catch (const ValidationException& e) {
        cerr << "Error Validasi: " << e.what() << endl;
        system("pause");
    }
}

void deleteProduk() {
    tampilkanHeader("DELETE PRODUK");
    tampilkanMabel();
    
    try {
        int deleteId = getInputInteger("\nMasukkan ID Produk yang ingin dihapus: ");
        
        int indexDelete = -1;
        for (int i = 0; i < mabelIndex; i++) {
            if (mabel[i].idProduk == deleteId) {
                indexDelete = i;
                break;
            }
        }
        
        if (indexDelete == -1) {
            throw ProdukException("ID Produk tidak ditemukan.");
        }
        
        cout << "Yakin hapus produk '" << mabel[indexDelete].namaProduk << "'? (y/n): ";
        string konfirmasi;
        getline(cin, konfirmasi);

        if (konfirmasi != "y") {
            displayMessage("Penghapusan dibatalkan.");
            system("pause");
            return;
        }

        for (int i = indexDelete; i < mabelIndex - 1; i++) {
            mabel[i] = mabel[i + 1];
        }
        mabelIndex--;
        displayMessage("Produk berhasil dihapus.");
    } catch (const ProdukException& e) {
        cerr << "Error: " << e.what() << endl;
        system("pause");
    } catch (const ValidationException& e) {
        cerr << "Error Validasi: " << e.what() << endl;
        system("pause");
    }
}

void tampilkanDataUser(string currentUser) {
    tampilkanHeader("DATA PROFIL SAYA");
    bool userFound = false;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == currentUser) {
            Table table;
            table.add_row({"Nama", "Password", "Email", "Saldo", "Alamat Jalan", "Kota", "Provinsi"});
            table.add_row({
                user[i].nama,
                user[i].password,
                user[i].email,
                to_string(user[i].saldo),
                user[i].alamat.jalan,
                user[i].alamat.kota,
                user[i].alamat.provinsi});
            cout << table << endl;
            userFound = true;
            break;
        }
    }
    if (!userFound) {
        cout << "Data user tidak ditemukan. Silakan login ulang." << endl;
    }
}

pengguna* cariPointerUser(string currentUser) {
    for (int i = 0; i < userIndex; i++) {
        if (currentUser == user[i].nama) {
            return &user[i];
        }
    }
    return nullptr;
}

void topup(string currentUser) {
    try {
        tampilkanHeader("TOP UP");
        
        pengguna *pUserDipilih = cariPointerUser(currentUser);
        if (pUserDipilih == nullptr) {
            throw PenggunaException("User tidak ditemukan!");
        }

        cout << "Saldo anda: " << pUserDipilih->saldo << endl;
        long long jumlah = getInputLongLong("Masukkan jumlah topup: ", 1);
        
        pUserDipilih->saldo += jumlah;
        displayMessage("Topup berhasil.\nSaldo sekarang: " + to_string(pUserDipilih->saldo));
        system("pause");
    } catch (const PenggunaException& e) {
        cerr << "Error: " << e.what() << endl;
        system("pause");
    } catch (const ValidationException& e) {
        cerr << "Error Validasi: " << e.what() << endl;
        system("pause");
    }
}

long long jumlahBeli() {
    long long jumlah;
    cout << "Masukkan jumlah yang ingin dibeli: ";
    if (!(cin >> jumlah)) {
        cout << "Input bukan angka. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return jumlahBeli();
    }
    if (jumlah <= 0) {
        cout << "Jumlah harus positif dan tidak boleh 0! ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return jumlahBeli();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return jumlah;
}

long long total(long long jumlah, long long harga) {
    return jumlah * harga;
}

double total(double jumlah, double harga) {
    return jumlah * harga;
}

void beli(string currentUser) {
    try {
        tampilkanHeader("DAFTAR PRODUK");
        tampilkanMabel();

        int beliId = getInputInteger("\nMasukkan ID Produk yang ingin dibeli: ");
        
        produk *pProdukDibeli = nullptr;
        for (int i = 0; i < mabelIndex; i++) {
            if (mabel[i].idProduk == beliId) {
                pProdukDibeli = &mabel[i];
                break;
            }
        }

        if (pProdukDibeli == nullptr) {
            throw ProdukException("ID Produk tidak ditemukan.");
        }

        cout << "Produk ditemukan: " << pProdukDibeli->namaProduk << ", Stock: " << pProdukDibeli->stock << endl;
        long long jumlahBeliProduk = getInputLongLong("Masukkan jumlah yang ingin dibeli: ", 1);
        
        if (jumlahBeliProduk > pProdukDibeli->stock) {
            throw TransaksiException("Stok tidak mencukupi. Stok tersedia: " + to_string(pProdukDibeli->stock));
        }

        cout << "Total Pembelian dalam bilangan bulat: " << total(jumlahBeliProduk, pProdukDibeli->harga) << endl;

        double jumlahDouble = jumlahBeliProduk - 0.5;
        double hargaDouble = (double)pProdukDibeli->harga - 0.75;
        cout << fixed << setprecision(2);
        cout << "Total Pembelian dalam bilangan desimal: " << total(jumlahDouble, hargaDouble) << endl;
        cout << defaultfloat;

        pengguna *pUserPembeli = cariPointerUser(currentUser);
        if (pUserPembeli == nullptr) {
            throw PenggunaException("User tidak ditemukan!");
        }
        
        long long totalBeli = total(jumlahBeliProduk, pProdukDibeli->harga);
        if (pUserPembeli->saldo < totalBeli) {
            throw TransaksiException("Saldo tidak cukup!\nSaldo anda: " + to_string(pUserPembeli->saldo) + 
                                 "\nTotal pembelian: " + to_string(totalBeli));
        }

        pUserPembeli->saldo -= totalBeli;
        pProdukDibeli->stock -= jumlahBeliProduk;

        displayMessage("Pembelian berhasil!");
        cout << "Sisa stock " << pProdukDibeli->namaProduk << ": " << pProdukDibeli->stock << endl;
        cout << "Sisa saldo: " << pUserPembeli->saldo << endl;
        system("pause");
    } catch (const ProdukException& e) {
        cerr << "Error Produk: " << e.what() << endl;
        system("pause");
    } catch (const PenggunaException& e) {
        cerr << "Error Pengguna: " << e.what() << endl;
        system("pause");
    } catch (const TransaksiException& e) {
        cerr << "Error Transaksi: " << e.what() << endl;
        system("pause");
    } catch (const ValidationException& e) {
        cerr << "Error Validasi: " << e.what() << endl;
        system("pause");
    }
}

int main() {
    try {
        mabel[0].idProduk = 101;
        mabel[0].namaProduk = "Daun Pintu Kayu Jati";
        mabel[0].jenisProduk = "Pintu";
        mabel[0].stock = 15;
        mabel[0].harga = 2500000;
        mabel[0].material.idMaterial = "MAT001";
        mabel[0].material.namaMaterial = "Kayu Jati";
        mabel[0].material.jenisMaterial = "Kayu Solid";

        mabel[1].idProduk = 102;
        mabel[1].namaProduk = "Daun Pintu HPL";
        mabel[1].jenisProduk = "Pintu";
        mabel[1].stock = 30;
        mabel[1].harga = 350000;
        mabel[1].material.idMaterial = "MAT002";
        mabel[1].material.namaMaterial = "HPL Abu-Abu";
        mabel[1].material.jenisMaterial = "Pelapis";

        mabel[2].idProduk = 103;
        mabel[2].namaProduk = "Jendela Kaca Geser";
        mabel[2].jenisProduk = "Jendela";
        mabel[2].stock = 8;
        mabel[2].harga = 1800000;
        mabel[2].material.idMaterial = "MAT003";
        mabel[2].material.namaMaterial = "Kayu Meranti";
        mabel[2].material.jenisMaterial = "Kayu Solid";

        mabel[3].idProduk = 104;
        mabel[3].namaProduk = "Meja Makan Minimalis";
        mabel[3].jenisProduk = "Meja";
        mabel[3].stock = 12;
        mabel[3].harga = 4500000;
        mabel[3].material.idMaterial = "MAT004";
        mabel[3].material.namaMaterial = "Plywood Biru";
        mabel[3].material.jenisMaterial = "Papan";

        mabel[4].idProduk = 105;
        mabel[4].namaProduk = "Kursi Tamu Kayu";
        mabel[4].jenisProduk = "Kursi";
        mabel[4].stock = 20;
        mabel[4].harga = 1200000;
        mabel[4].material.idMaterial = "MAT001";
        mabel[4].material.namaMaterial = "Kayu Jati";
        mabel[4].material.jenisMaterial = "Kayu Solid";

        user[0].nama = "Muhammad Alfauzi Syahputra";
        user[0].password = "2509106006";
        user[0].email = "muhammad.alfauzi256@gmail.com";
        user[0].saldo = 850000000;
        user[0].alamat.jalan = "JL. Ery Suparjan";
        user[0].alamat.kota = "Samarinda";
        user[0].alamat.provinsi = "Kalimantan Timur";

        user[1].nama = "user";
        user[1].password = "123";
        user[1].email = "user@gmail.com";
        user[1].saldo = 150000000;
        user[1].alamat.jalan = "JL. User";
        user[1].alamat.kota = "Kota User";
        user[1].alamat.provinsi = "Provinsi User";

        admin[0].nama = "Alfauzi";
        admin[0].password = "006";
        admin[1].nama = "admin";
        admin[1].password = "123";
        admin[2].nama = "ceoAsli";
        admin[2].password = "000";

        string pilihan;
        string currentUser;
        while (true) {
            system("cls");
            tampilkanMenuUtama();
            getline(cin, pilihan);
            if (pilihan == "1") {
                system("cls");
                bool isAdmin = false;
                bool loginSukses = login(isAdmin, currentUser);
                if (loginSukses) {
                    if (isAdmin) {
                        while (loginSukses && isAdmin) {
                            system("cls");
                            tampilkanMenuAdmin();
                            getline(cin, pilihan);
                            if (pilihan == "1") {
                                system("cls");
                                tampilkanHeader("DAFTAR PRODUK");
                                tampilkanMabel();
                                system("pause");
                            } else if (pilihan == "2") {
                                system("cls");
                                updateProduk();
                                system("pause");
                            } else if (pilihan == "3") {
                                system("cls");
                                createProduk(&mabelIndex);
                            } else if (pilihan == "4") {
                                system("cls");
                                deleteProduk();
                                system("pause");
                            } else if (pilihan == "5") {
                                menuSortProduk();
                            } else if (pilihan == "6") {
                                menuSearchProduk();
                            } else if (pilihan == "0") {
                                displayMessage("\nLogout dari akun admin...");
                                loginSukses = false;
                                isAdmin = false;
                                system("pause");
                                break;
                            } else {
                                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                                system("pause");
                            }
                        }
                    } else {
                        while (loginSukses && !isAdmin) {
                            system("cls");
                            tampilkanMenuUser();
                            getline(cin, pilihan);
                            if (pilihan == "1") {
                                system("cls");
                                tampilkanDataUser(currentUser);
                                system("pause");
                            } else if (pilihan == "2") {
                                system("cls");
                                beli(currentUser);
                            } else if (pilihan == "3") {
                                system("cls");
                                topup(currentUser);
                            } else if (pilihan == "4") {
                                menuSearchProduk();
                            } else if (pilihan == "0") {
                                displayMessage("\nLogout dari akun user...");
                                loginSukses = false;
                                isAdmin = false;
                                system("pause");
                                break;
                            } else {
                                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                                system("pause");
                            }
                        }
                    }
                } else {
                    cout << "Login gagal, program berhenti." << endl;
                    return 0;
                }
            } else if (pilihan == "2") {
                system("cls");
                registerUser(&userIndex);
            } else if (pilihan == "0") {
                displayMessage("\nKeluar dari program...");
                break;
            } else {
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                system("pause");
            }
        }
        return 0;
    } catch (const std::exception& e) {
        cerr << "\nError Fatal: " << e.what() << endl;
        customErrorHandler("Program terhenti karena error fatal", __FILE__, __LINE__, __FUNCTION__);
        return 1;
    } catch (...) {
        cerr << "\nError Tak Terduga: Terjadi kesalahan yang tidak dapat diproses" << endl;
        customErrorHandler("Program terhenti karena error tak terduga", __FILE__, __LINE__, __FUNCTION__);
        return 2;
    }
}