#include <iostream>
#include <iomanip>
#include <tabulate/table.hpp>
#include <limits>

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
    string idProduk;
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

void tampilkanMabel() {
    if (mabelIndex == 0) {
        cout << "Tidak ada data produk." << endl;
    } else {
        Table table;
        table.add_row({"ID Produk", "Nama Produk", "Jenis Produk", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});
        for (int i = 0; i < mabelIndex; i++) {
            table.add_row({
                mabel[i].idProduk,
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

void merge(produk arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    produk *leftArr = new produk[n1];
    produk *rightArr = new produk[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].stock <= rightArr[j].stock) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSortStockAscending(produk arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortStockAscending(arr, left, mid);
        mergeSortStockAscending(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void menuSortProduk() {
    string pilihan;
    while (true) {
        system("cls");
        cout << "=== MENU SORT PRODUK ===" << endl;
        cout << "1. Urutkan Nama Produk (Z-A)" << endl;
        cout << "2. Urutkan Harga (Murah-Mahal)" << endl;
        cout << "3. Urutkan Stock (Rendah-Tinggi)" << endl;
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
                cout << "\nDaftar Produk Sebelum Sorting (Nama Produk - Descending):\n";
                tampilkanMabel();
                bubbleSortNamaProdukDescending(mabel, mabelIndex);
                cout << "\nDaftar Produk Setelah Sorting (Nama Produk - Descending):\n";
                tampilkanMabel();
                cout << "\nProduk berhasil diurutkan berdasarkan Nama Produk (Z-A)!" << endl;
                system("pause");
            }
        } else if (pilihan == "2") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk diurutkan." << endl;
                system("pause");
            } else {
                system("cls");
                cout << "\nDaftar Produk Sebelum Sorting (Harga - Ascending):\n";
                tampilkanMabel();
                selectionSortHargaAscending(mabel, mabelIndex);
                cout << "\nDaftar Produk Setelah Sorting (Harga - Ascending):\n";
                tampilkanMabel();
                cout << "\nProduk berhasil diurutkan berdasarkan Harga (Murah-Mahal)!" << endl;
                system("pause");
            }
        } else if (pilihan == "3") {
            if (mabelIndex == 0) {
                system("cls");
                cout << "\nTidak ada produk untuk diurutkan." << endl;
                system("pause");
            } else {
                system("cls");
                cout << "\nDaftar Produk Sebelum Sorting (Stock - Ascending):\n";
                tampilkanMabel();
                mergeSortStockAscending(mabel, 0, mabelIndex - 1);
                cout << "\nDaftar Produk Setelah Sorting (Stock - Ascending):\n";
                tampilkanMabel();
                cout << "\nProduk berhasil diurutkan berdasarkan Stock (Rendah-Tinggi)!" << endl;
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
    cout << "=== MENU UTAMA ===" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuAdmin() {
    cout << "=== MENU ADMIN ===" << endl;
    cout << "1. Read Produk" << endl;
    cout << "2. Update Produk" << endl;
    cout << "3. Create Produk" << endl;
    cout << "4. Delete Produk" << endl;
    cout << "5. Sort Produk" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuUser() {
    cout << "=== MENU USER ===" << endl;
    cout << "1. Read Data Saya" << endl;
    cout << "2. Read Produk dan Beli" << endl;
    cout << "3. Sort Produk" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

bool login(bool &isAdmin, string &currentUser) {
    int kesempatan = 3;
    string inNama, inPassword;
    cout << "=== LOGIN ===";
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
    cout << "=== REGISTER USER ===" << endl;

    if (*pUserIndex >= maxuser) {
        cout << "Maaf, jumlah user maksimum (" << maxuser << ") telah tercapai." << endl;
        system("pause");
        return;
    }

    string inNama;
    cout << "Masukkan Nama: ";
    getline(cin, inNama);

    bool isDuplicate = false;
    for (int i = 0; i < *pUserIndex; i++) {
        if (user[i].nama == inNama) {
            isDuplicate = true;
            break;
        }
    }

    if (isDuplicate) {
        cout << "Nama sudah digunakan. Silakan coba nama lain." << endl;
        system("pause");
    } else {
        user[*pUserIndex].nama = inNama;
        cout << "Masukkan Password: ";
        getline(cin, user[*pUserIndex].password);
        cout << "Masukkan Email: ";
        getline(cin, user[*pUserIndex].email);
        user[*pUserIndex].saldo = 0;
        cout << "Masukkan Alamat Jalan: ";
        getline(cin, user[*pUserIndex].alamat.jalan);
        cout << "Masukkan kota: ";
        getline(cin, user[*pUserIndex].alamat.kota);
        cout << "Masukkan Provinsi: ";
        getline(cin, user[*pUserIndex].alamat.provinsi);
        cout << "\nRegistrasi berhasil! Akun untuk '" << user[*pUserIndex].nama << "' telah dibuat." << endl;

        (*pUserIndex)++;
        cout << "Jumlah user saat ini: " << *pUserIndex << endl;
        system("pause");
    }
}

void updateFieldProduk(produk *pProduk) {
    cout << "Pilih kolom yang ingin diubah:\n";
    cout << "1. ID Produk\n2. Nama Produk\n3. Jenis Produk\n4. Stock\n5. Harga\n6. ID Material\n7. Nama Material\n8. Jenis Material\nPilihan: ";
    string updatePilihan;
    getline(cin, updatePilihan);

    if (updatePilihan == "1") {
        cout << "Masukkan ID Produk Baru: ";
        getline(cin, pProduk->idProduk);
    } else if (updatePilihan == "2") {
        cout << "Masukkan Nama Produk Baru: ";
        getline(cin, pProduk->namaProduk);
    } else if (updatePilihan == "3") {
        cout << "Masukkan Jenis Produk Baru: ";
        getline(cin, pProduk->jenisProduk);
    } else if (updatePilihan == "4") {
        long long updateStock;
        while (true) {
            cout << "Masukkan Stock Baru: ";
            if (!(cin >> updateStock)) {
                cout << "\nInput tidak valid. Harap masukkan angka: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (updateStock < 0) {
                cout << "\nStock tidak boleh negatif. Masukkan angka positif atau nol: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                pProduk->stock = updateStock;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
    } else if (updatePilihan == "5") {
        long long updateHarga;
        while (true) {
            cout << "Masukkan Harga Baru: ";
            if (!(cin >> updateHarga)) {
                cout << "\nInput tidak valid. Harap masukkan angka: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (updateHarga < 0) {
                cout << "\nHarga tidak boleh negatif. Masukkan angka positif atau nol: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                pProduk->harga = updateHarga;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
    } else if (updatePilihan == "6") {
        cout << "Masukkan ID Material Baru: ";
        getline(cin, pProduk->material.idMaterial);
    } else if (updatePilihan == "7") {
        cout << "Masukkan Nama Material Baru: ";
        getline(cin, pProduk->material.namaMaterial);
    } else if (updatePilihan == "8") {
        cout << "Masukkan Jenis Material Baru: ";
        getline(cin, pProduk->material.jenisMaterial);
    } else {
        cout << "Pilihan tidak valid." << endl;
        system("pause");
    }
}

void updateProduk() {
    cout << "=== UPDATE PRODUK ===" << endl;
    tampilkanMabel();

    string updateId;
    cout << "\nMasukkan ID Produk yang ingin diupdate: ";
    getline(cin, updateId);

    int index = -1;
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == updateId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "ID Produk tidak ditemukan." << endl;
    } else {
        cout << "Produk ditemukan: " << mabel[index].namaProduk << endl;
        produk *pProdukDipilih = &mabel[index];
        updateFieldProduk(pProdukDipilih);
        cout << "Produk berhasil diupdate." << endl;
    }
    system("pause");
}

void createProduk(int *pMabelIndex) {
    cout << "=== CREATE PRODUK ===" << endl;
    if (*pMabelIndex >= maxproduk) {
        cout << "Maaf, jumlah produk maksimum (" << maxproduk << ") telah tercapai." << endl;
        system("pause");
    } else {
        string idBaru;
        cout << "Masukkan ID Produk: ";
        getline(cin, idBaru);
        bool duplikat = false;
        for (int i = 0; i < *pMabelIndex; i++) {
            if (mabel[i].idProduk == idBaru) {
                duplikat = true;
                break;
            }
        }
        if (duplikat) {
            cout << "ID Produk sudah digunakan. Silakan coba ID lain." << endl;
        } else {
            produk *pProdukBaru = &mabel[*pMabelIndex];
            pProdukBaru->idProduk = idBaru;
            cout << "Masukkan Nama Produk: ";
            getline(cin, pProdukBaru->namaProduk);
            cout << "Masukkan Jenis Produk: ";
            getline(cin, pProdukBaru->jenisProduk);
            long long stockBaru;
            while (true) {
                cout << "Masukkan Stock Baru: ";
                if (!(cin >> stockBaru)) {
                    cout << "\nInput tidak valid. Harap masukkan angka: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (stockBaru < 0) {
                    cout << "\nStock tidak boleh negatif. Masukkan angka positif atau nol: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    pProdukBaru->stock = stockBaru;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            }
            long long hargaBaru;
            while (true) {
                cout << "Masukkan Harga Baru: ";
                if (!(cin >> hargaBaru)) {
                    cout << "\nInput tidak valid. Harap masukkan angka: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (hargaBaru < 0) {
                    cout << "\nHarga tidak boleh negatif. Masukkan angka positif atau nol: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    pProdukBaru->harga = hargaBaru;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            }
            cout << "Masukkan ID Material: ";
            getline(cin, pProdukBaru->material.idMaterial);
            cout << "Masukkan Nama Material: ";
            getline(cin, pProdukBaru->material.namaMaterial);
            cout << "Masukkan Jenis Material: ";
            getline(cin, pProdukBaru->material.jenisMaterial);
            (*pMabelIndex)++;
            cout << "Produk berhasil ditambahkan." << endl;
        }
        system("pause");
    }
}

void deleteProduk() {
    cout << "=== DELETE PRODUK ===" << endl;
    tampilkanMabel();
    string deleteId;
    cout << "\nMasukkan ID Produk yang ingin dihapus: ";
    getline(cin, deleteId);
    int indexDelete = -1;
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == deleteId) {
            indexDelete = i;
            break;
        }
    }
    if (indexDelete == -1) {
        cout << "ID Produk tidak ditemukan." << endl;
    } else {
        cout << "Yakin hapus produk '" << mabel[indexDelete].namaProduk << "'? (y/n): ";
        string konfirmasi;
        getline(cin, konfirmasi);

        if (konfirmasi != "y") {
            cout << "Penghapusan dibatalkan." << endl;
            system("pause");
            return;
        }

        for (int i = indexDelete; i < mabelIndex - 1; i++) {
            mabel[i] = mabel[i + 1];
        }
        mabelIndex--;
        cout << "Produk berhasil dihapus." << endl;
    }
    system("pause");
}

void tampilkanDataUser(string currentUser) {
    cout << "=== DATA PROFIL SAYA ===" << endl;
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
    cout << "=== Top Up ===" << endl;
    long long jumlah;

    pengguna *pUserDipilih = cariPointerUser(currentUser);

    if (pUserDipilih == nullptr) {
        cout << "User tidak ditemukan!" << endl;
        system("pause");
        return;
    }

    cout << "Saldo anda: " << pUserDipilih->saldo << endl;

    while (true) {
        cout << "Masukkan jumlah topup: ";
        if (!(cin >> jumlah)) {
            cout << "\nInput tidak valid. Harap masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (jumlah <= 0) {
            cout << "\nJumlah topup harus lebih dari 0. Masukkan angka positif: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            pUserDipilih->saldo += jumlah;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Topup berhasil.\nSaldo sekarang: " << pUserDipilih->saldo << endl;
            system("pause");
            break;
        }
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
    cout << "=== DAFTAR PRODUK ===" << endl;
    tampilkanMabel();

    string beliId;
    cout << "\nMasukkan ID Produk yang ingin dibeli: ";
    getline(cin, beliId);

    produk *pProdukDibeli = nullptr;
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == beliId) {
            pProdukDibeli = &mabel[i];
            break;
        }
    }

    if (pProdukDibeli == nullptr) {
        cout << "ID Produk tidak ditemukan." << endl;
    } else {
        cout << "Produk ditemukan: " << pProdukDibeli->namaProduk << ", Stock: " << pProdukDibeli->stock << endl;
        long long jumlahBeliProduk = jumlahBeli();
        if (jumlahBeliProduk > pProdukDibeli->stock) {
            cout << "Stok tidak mencukupi. Stok tersedia: " << pProdukDibeli->stock << endl;
        } else {
            cout << "Total Pembelian dalam bilangan bulat: " << total(jumlahBeliProduk, pProdukDibeli->harga) << endl;

            double jumlahDouble = jumlahBeliProduk - 0.5;
            double hargaDouble = (double)pProdukDibeli->harga - 0.75;
            cout << fixed << setprecision(2);
            cout << "Total Pembelian dalam bilangan desimal: " << total(jumlahDouble, hargaDouble) << endl;
            cout << defaultfloat;

            pengguna *pUserPembeli = cariPointerUser(currentUser);
            long long totalBeli = total(jumlahBeliProduk, pProdukDibeli->harga);

            if (pUserPembeli->saldo < totalBeli) {
                cout << "Saldo tidak cukup!" << endl;
                cout << "Saldo anda: " << pUserPembeli->saldo << endl;
                cout << "Total pembelian: " << totalBeli << endl;
            } else {
                pUserPembeli->saldo -= totalBeli;
                pProdukDibeli->stock -= jumlahBeliProduk;

                cout << "Pembelian berhasil!" << endl;
                cout << "Sisa stock " << pProdukDibeli->namaProduk << ": " << pProdukDibeli->stock << endl;
                cout << "Sisa saldo: " << pUserPembeli->saldo << endl;
            }
        }
    }
    system("pause");
}

int main() {
    mabel[0].idProduk = "PRD001";
    mabel[0].namaProduk = "Daun Pintu Kayu Jati";
    mabel[0].jenisProduk = "Pintu";
    mabel[0].stock = 15;
    mabel[0].harga = 2500000;
    mabel[0].material.idMaterial = "MAT001";
    mabel[0].material.namaMaterial = "Kayu Jati";
    mabel[0].material.jenisMaterial = "Kayu Solid";

    mabel[1].idProduk = "PRD002";
    mabel[1].namaProduk = "Daun Pintu HPL";
    mabel[1].jenisProduk = "Pintu";
    mabel[1].stock = 30;
    mabel[1].harga = 350000;
    mabel[1].material.idMaterial = "MAT002";
    mabel[1].material.namaMaterial = "HPL Abu-Abu";
    mabel[1].material.jenisMaterial = "Pelapis";

    mabel[2].idProduk = "PRD003";
    mabel[2].namaProduk = "Jendela Kaca Geser";
    mabel[2].jenisProduk = "Jendela";
    mabel[2].stock = 8;
    mabel[2].harga = 1800000;
    mabel[2].material.idMaterial = "MAT003";
    mabel[2].material.namaMaterial = "Kayu Meranti";
    mabel[2].material.jenisMaterial = "Kayu Solid";

    mabel[3].idProduk = "PRD004";
    mabel[3].namaProduk = "Meja Makan Minimalis";
    mabel[3].jenisProduk = "Meja";
    mabel[3].stock = 12;
    mabel[3].harga = 4500000;
    mabel[3].material.idMaterial = "MAT004";
    mabel[3].material.namaMaterial = "Plywood Biru";
    mabel[3].material.jenisMaterial = "Papan";

    mabel[4].idProduk = "PRD005";
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
                            cout << "=== DAFTAR PRODUK ===" << endl;
                            tampilkanMabel();
                            system("pause");
                        } else if (pilihan == "2") {
                            system("cls");
                            updateProduk();
                        } else if (pilihan == "3") {
                            system("cls");
                            createProduk(&mabelIndex);
                        } else if (pilihan == "4") {
                            system("cls");
                            deleteProduk();
                        } else if (pilihan == "5") {
                            menuSortProduk();
                        } else if (pilihan == "0") {
                            cout << "\nLogout dari akun admin..." << endl;
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
                            menuSortProduk();
                        } else if (pilihan == "0") {
                            cout << "\nLogout dari akun user..." << endl;
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
            cout << "\nKeluar dari program..." << endl;
            break;
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            system("pause");
        }
    }
    return 0;
}