#include <iostream>
#include <iomanip> 
#include <tabulate/table.hpp>

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
    int saldo;
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
    int stock;
    int harga;
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

void tampilkanMenuUtama() { // prosedur
    cout << "=== MENU UTAMA ===" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuAdmin() { // prosedur
    cout << "=== MENU ADMIN ===" << endl;
    cout << "1. Read Produk" << endl;
    cout << "2. Update Produk" << endl;
    cout << "3. Create Produk" << endl;
    cout << "4. Delete Produk" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuUser() { // prosedur
    cout << "=== MENU USER ===" << endl;
    cout << "1. Read Data Saya" << endl;
    cout << "2. Read Produk dan Beli" << endl;
    cout << "3. Topup" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

bool login(bool &isAdmin, string &currentUser) { // fungsi
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

void registerUser() { // prosedur
    cout << "=== REGISTER USER ===" << endl;

    if (userIndex >= maxuser) {
        cout << "Maaf, jumlah user maksimum (" << maxuser << ") telah tercapai." << endl;
        system("pause");
        return;
    }

    string inNama;
    cout << "Masukkan Nama: ";
    getline(cin, inNama);

    bool isDuplicate = false;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == inNama) { 
            isDuplicate = true;
            break;
        }
    }

    if (isDuplicate) {
        cout << "Nama sudah digunakan. Silakan coba nama lain." << endl;
        system("pause");
    } else {
        user[userIndex].nama = inNama;
        cout << "Masukkan Password: ";
        getline(cin, user[userIndex].password);
        cout << "Masukkan Email: ";
        getline(cin, user[userIndex].email);
        user[userIndex].saldo = 0;
        cout << "Masukkan Alamat Jalan: ";
        getline(cin, user[userIndex].alamat.jalan);
        cout << "Masukan kota: ";
        getline(cin, user[userIndex].alamat.kota);
        cout << "Masukkan Provinsi: ";
        getline(cin, user[userIndex].alamat.provinsi);
        cout << "\nRegistrasi berhasil! Akun untuk '" << user[userIndex].nama << "' telah dibuat." << endl;

        userIndex++;
        cout << "Jumlah user saat ini: " << userIndex << endl;
        system("pause");
    }
}

void tampilkanMabel() { // prosedur
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

void updateProduk() { // prosedur
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
        cout << "Pilih kolom yang ingin diubah:\n";
        cout << "1. ID Produk\n2. Nama Produk\n3. Jenis Produk\n4. Stock\n5. Harga\n6. ID Material\n7. Nama Material\n8. Jenis Material\nPilihan: ";
        string updatePilihan;
        getline(cin, updatePilihan);
        if  (updatePilihan == "1") {
            cout << "Masukkan ID Produk Baru: ";
            getline(cin, mabel[index].idProduk);
        } else if  (updatePilihan == "2") {
            cout << "Masukkan Nama Produk Baru: ";
            getline(cin, mabel[index].namaProduk);
        } else if  (updatePilihan == "3") {
            cout << "Masukkan Jenis Produk Baru: ";
        getline(cin, mabel[index].jenisProduk);
        } else if  (updatePilihan == "4") {
            int updateStock;
            while (true) {
                cout << "Masukkan Stock Baru: ";
                cin >> updateStock;
                cin.ignore();
                if(updateStock >= 0) {
                    mabel[index].stock = updateStock;
                    break;
                } else {
                    cout << "\nInput tidak valid. Masukkan angka positif: \n";
                }
            }
        } else if  (updatePilihan == "5") {
            int updateHarga;
            while (true) {
                cout << "Masukkan Harga Baru: ";
                cin >> updateHarga;
                cin.ignore();
                if(updateHarga >= 0) {
                    mabel[index].harga = updateHarga;
                    break;
                } else {
                    cout << "\nInput tidak valid. Masukkan angka positif: \n";
                }
            }
        } else if  (updatePilihan == "6") {
            cout << "Masukkan ID Material Baru: ";
            getline(cin, mabel[index].material.idMaterial);
        } else if  (updatePilihan == "7") {
            cout << "Masukkan Nama Material Baru: ";
            getline(cin, mabel[index].material.namaMaterial);
        } else if  (updatePilihan == "8") {
            cout << "Masukkan Jenis Material Baru: ";
            getline(cin, mabel[index].material.jenisMaterial);
        } else {
            cout << "Pilihan tidak valid." << endl;
            system("pause");
        }
        cout << "Produk berhasil diupdate." << endl;
    }
    system("pause");
}

void createProduk() { // prosedur
    cout << "=== CREATE PRODUK ===" << endl;
    if (mabelIndex >= maxproduk) {
        cout << "Maaf, jumlah produk maksimum (" << maxproduk << ") telah tercapai." << endl;
        system("pause");
    } else {
        string idBaru;
        cout << "Masukkan ID Produk: ";
        getline(cin, idBaru);
        bool duplikat = false;
        for (int i = 0; i < mabelIndex; i++) {
            if (mabel[i].idProduk == idBaru) {
                duplikat = true;
                break;
            }
        }
        if (duplikat) {
            cout << "ID Produk sudah digunakan. Silakan coba ID lain." << endl;
        } else {
            mabel[mabelIndex].idProduk = idBaru;
            cout << "Masukkan Nama Produk: ";
            getline(cin, mabel[mabelIndex].namaProduk);
            cout << "Masukkan Jenis Produk: ";
            getline(cin, mabel[mabelIndex].jenisProduk);
            int stockBaru;
            while (true) {
                cout << "Masukkan Stock Baru: ";
                cin >> stockBaru;
                cin.ignore();
                if(stockBaru >= 0) {
                    mabel[mabelIndex].stock = stockBaru;
                    break;
                } else {
                    cout << "\nInput tidak valid. Masukkan angka positif: \n";
                }
            }
            int hargaBaru;
            while (true) {
                cout << "Masukkan Harga Baru: ";
                cin >> hargaBaru;
                cin.ignore();
                if(hargaBaru >= 0) {
                    mabel[mabelIndex].harga = hargaBaru;
                    break;
                } else {
                    cout << "\nInput tidak valid. Masukkan angka positif: \n";
                }
            }
            cout << "Masukkan ID Material: ";
            getline(cin, mabel[mabelIndex].material.idMaterial);
            cout << "Masukkan Nama Material: ";
            getline(cin, mabel[mabelIndex].material.namaMaterial);
            cout << "Masukkan Jenis Material: ";
            getline(cin, mabel[mabelIndex].material.jenisMaterial);
            mabelIndex++;
            cout << "Produk berhasil ditambahkan." << endl;
        }
        system("pause");
    }
}

void deleteProduk() { // prosedur
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
        for (int i = indexDelete; i < mabelIndex - 1; i++) {
            mabel[i] = mabel[i + 1];
        }
        mabelIndex--;
        cout << "Produk berhasil dihapus." << endl;
    }
    system("pause");
}

void tampilkanDataUser(string currentUser) { // prosedur
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

int cariIndexUser(string currentUser) { // fungsi
    for(int i = 0; i < userIndex; i++) {
        if (currentUser == user[i].nama) {
            return i;
        }
    }
    return -1;
}

void topup(string currentuser) { // prosedur
    cout << "=== Top Up ===" << endl;
    int jumlah;
    int currentIndexUser = cariIndexUser(currentuser);
    cout << "Saldo anda: " << user[currentIndexUser].saldo << endl;

    while(true) {
        cout << "Masukkan jumlah topup: ";
        cin >> jumlah;
        cin.ignore();
    
        if(jumlah > 0){
            user[currentIndexUser].saldo += jumlah;
            cout<<"Topup berhasil.\nSaldo sekarang: "<<user[currentIndexUser].saldo<<endl;
            system("pause");
            break;
        } else {
            cout << "\nInput tidak valid. Masukkan angka positif: \n";
        }
    }
}

int jumlahBeli() { // rekursif
    int jumlah;
    cout << "Masukkan jumlah yang ingin dibeli: ";
    cin >> jumlah;
    cin.ignore();
    if (jumlah <= 0) {
        cout << "Jumlah harus positif dan tidak boleh 0!" << endl;
        return jumlahBeli();
    } else {
        return jumlah;
    }
}

int total(int jumlah, int harga) { // overloding
    return jumlah * harga;
}

double total(double jumlah, double harga) { // overloding
    return jumlah * harga;
}

void beli(string currentUser) { // prosedur
    cout << "=== DAFTAR PRODUK ===" << endl;
    tampilkanMabel();

    string beliId;
    cout << "\nMasukkan ID Produk yang ingin dibeli: ";
    getline(cin, beliId);

    int indexBeli = -1;
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == beliId) {
            indexBeli = i;
            break;
        }
    }

    if (indexBeli == -1) {
        cout << "ID Produk tidak ditemukan." << endl;
    } else {
        cout << "Produk ditemukan: " << mabel[indexBeli].namaProduk << ", Stock: " << mabel[indexBeli].stock << endl;
        int jumlahBeliProduk = jumlahBeli();
        if (jumlahBeliProduk > mabel[indexBeli].stock) {
            cout << "Stok tidak mencukupi. Stok tersedia: " << mabel[indexBeli].stock << endl;
        } else {
            cout << "Total Pembelian dalam bilangan bulat: " << total(jumlahBeliProduk, mabel[indexBeli].harga) << endl;

            double jumlahDouble = jumlahBeliProduk - 0.5; // hanya untuk tes overloding
            double hargaDouble = mabel[indexBeli].harga - 0.75; // hanya untuk tes overloading
            cout << fixed << setprecision(2);
            cout << "Total Pembelian dalam bilangan desimal: " << total(jumlahDouble, hargaDouble) << endl; // hanya untuk tes overloading
            cout << defaultfloat;

            int currentIndexUser = cariIndexUser(currentUser);
            int totalBeli = total(jumlahBeliProduk, mabel[indexBeli].harga);

            if(user[currentIndexUser].saldo < totalBeli) {
                cout << "Saldo tidak cukup!" << endl;
                cout << "Saldo anda: " << user[currentIndexUser].saldo << endl;
                cout << "Total pembelian: " << totalBeli << endl;
            }
            else {
                user[currentIndexUser].saldo -= totalBeli;
                mabel[indexBeli].stock -= jumlahBeliProduk;

                cout << "Pembelian berhasil!" << endl;
                cout << "Sisa stock " << mabel[indexBeli].namaProduk << ": " << mabel[indexBeli].stock << endl;
                cout << "Sisa saldo: " << user[currentIndexUser].saldo << endl;
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
                            createProduk();
                        } else if (pilihan == "4") {
                            system("cls");
                            deleteProduk();
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
                            system("cls");
                            topup(currentUser);
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
        } else if (pilihan == "2"){
            system("cls");
            registerUser();
        } else if (pilihan == "0"){
            cout << "\nKeluar dari program..." << endl;
            break; 
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            system("pause");
        }
    }
}