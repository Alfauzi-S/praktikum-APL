#include <iostream>
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
int userIndex = 1;
int mabelIndex = 5;

dataAdmin admin[maxadmin];
pengguna user[maxuser];
produk mabel[maxproduk];

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
    user[0].alamat.jalan = "JL. Ery Suparjan";
    user[0].alamat.kota = "Samarinda";
    user[0].alamat.provinsi = "Kalimantan Timur";

    admin[0].nama = "Alfauzi";
    admin[0].password = "006";
    admin[1].nama = "admin";
    admin[1].password = "123";
    admin[2].nama = "ceoAsli";
    admin[2].password = "000";

    string pilihan;
    string currentUser;
    bool berhasilLogin = false;
    bool isAdmin = false;

    while (true) {
        system("cls");
        cout << "\n=== MENU UTAMA ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit Program" << endl;
        cout << "Masukkan Pilihan: ";
        getline(cin, pilihan);

        if (pilihan == "1") { 
            system("cls");
            string inNama, inPassword;
            int kesempatan = 3;

            cout << "\n=== LOGIN ===" << endl;
            while (kesempatan > 0 && !berhasilLogin) {
                cout << "\nMasukkan Nama: ";
                getline(cin, inNama);
                cout << "Masukkan Password: ";
                getline(cin, inPassword);


                bool adminFound = false;
                for (int i = 0; i < adminIndex; i++) {
                    if (admin[i].nama == inNama && admin[i].password == inPassword) {
                        cout << "\nLogin Admin Berhasil! Selamat Datang, " << inNama << endl;
                        berhasilLogin = true;
                        isAdmin = true;
                        currentUser = admin[i].nama;
                        adminFound = true;
                        break;
                    }
                }
                if (adminFound) break;

                bool userFound = false;
                for (int i = 0; i < userIndex; i++) {
                    if (user[i].nama == inNama && user[i].password == inPassword) {
                        cout << "\nLogin User Berhasil! Selamat Datang, " << inNama << endl;
                        berhasilLogin = true;
                        isAdmin = false;
                        currentUser = user[i].nama;
                        userFound = true;
                        break;
                    }
                }
                if (userFound) break;

                if (!berhasilLogin) {
                    kesempatan--;
                    if (kesempatan > 0) {
                        cout << "\nLogin Gagal! Sisa percobaan: " << kesempatan << endl;
                        system("pause");
                    } else {
                        cout << "\nLogin Gagal! Anda telah mencapai batas percobaan maksimal." << endl;
                        cout << "Program akan keluar..." << endl;
                        return 0;
                    }
                }
            }
        } else if (pilihan == "2") {
            system("cls");
            cout << "\n=== REGISTER USER ===" << endl;

            if (userIndex >= maxuser) {
                cout << "Maaf, jumlah user maksimum (" << maxuser << ") telah tercapai." << endl;
                system("pause");
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
        } else if (pilihan == "0") {
            cout << "\nKeluar dari program..." << endl;
            break; 
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            system("pause");
        }

        if (berhasilLogin) {
            if (isAdmin) {
                while (berhasilLogin && isAdmin) {
                    system("cls");
                    cout << "\n=== MENU ADMIN ===" << endl;
                    cout << "1. Read Produk" << endl;
                    cout << "2. Update Produk" << endl;
                    cout << "3. Create Produk" << endl;
                    cout << "4. Delete Produk" << endl;
                    cout << "0. Logout" << endl;
                    cout << "Masukkan Pilihan: ";
                    getline(cin, pilihan);

                    if (pilihan == "1") {
                        system("cls");
                        cout << "\n=== DAFTAR PRODUK ===" << endl;
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
                        system("pause");
                    } else if (pilihan == "2") {
                        system("cls");
                        cout << "\n=== UPDATE PRODUK ===" << endl;
                        if (mabelIndex == 0) {
                            cout << "Tidak ada data produk untuk diupdate." << endl;
                            system("pause");
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
                                            cout << "Input tidak valid. Masukkan angka positif: ";
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
                                            cout << "Input tidak valid. Masukkan angka positif: ";
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
                    } else if (pilihan == "3") {
                        system("cls");
                        cout << "\n=== CREATE PRODUK ===" << endl;

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
                                        cout << "Input tidak valid. Masukkan angka positif: ";
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
                                        cout << "Input tidak valid. Masukkan angka positif: ";
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
                    } else if (pilihan == "4") {
                        system("cls");
                        cout << "\n=== DELETE PRODUK ===" << endl;

                        if (mabelIndex == 0) {
                            cout << "Tidak ada data produk untuk dihapus." << endl;
                            system("pause");
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
                                    mabel[i].material.jenisMaterial
                                });
                            }

                            cout << table << endl;

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
                    } else if (pilihan == "0") {
                        cout << "\nLogout dari akun admin..." << endl;
                        berhasilLogin = false;
                        isAdmin = false;
                        system("pause");
                        break;
                    } else {
                        cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                        system("pause");
                    }
                } 
            } else {
                while (berhasilLogin && !isAdmin) {
                    system("cls");
                    cout << "\n=== MENU USER ===" << endl;
                    cout << "1. Read Data Saya" << endl;
                    cout << "2. Read Produk dan Beli" << endl;
                    cout << "0. Logout" << endl;
                    cout << "Masukkan Pilihan: ";
                    getline(cin, pilihan);

                    if (pilihan == "1") {
                        system("cls");
                        cout << "\n=== DATA PROFIL SAYA ===" << endl;

                        bool userFound = false;
                        for (int i = 0; i < userIndex; i++) {
                            if (user[i].nama == currentUser) {
                                Table table;
                                table.add_row({"Nama", "Password (NIM)", "Email", "Alamat Jalan", "Kota", "Provinsi"});
                                table.add_row({
                                    user[i].nama, 
                                    user[i].password, 
                                    user[i].email,
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
                        system("pause");
                    } else if (pilihan == "2") {
                        system("cls");
                        cout << "\n=== DAFTAR PRODUK ===" << endl;
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
                                    mabel[i].material.jenisMaterial
                                });
                            }

                            cout << table << endl;

                            string beliId;
                            int jumlah;
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
                            
                                while (true) {
                                    cout << "Masukkan jumlah yang ingin dibeli: ";
                                    cin >> jumlah;
                                    cin.ignore();
                                    if(jumlah > 0) {
                                        break;
                                    } else {
                                        cout << "Input tidak valid. Masukkan angka positif: " << endl;
                                    }
                                }

                                if (jumlah > mabel[indexBeli].stock) {
                                    cout << "Stok tidak mencukupi. Stok tersedia: " << mabel[indexBeli].stock << endl;
                                } else {
                                    mabel[indexBeli].stock -= jumlah;
                                    cout << "Pembelian berhasil! Sisa stock " << mabel[indexBeli].namaProduk << ": " << mabel[indexBeli].stock << endl;
                                }
                            }
                        }
                        system("pause");
                    } else if (pilihan == "0") {
                        cout << "\nLogout dari akun user..." << endl;
                        berhasilLogin = false;
                        isAdmin = false;
                        system("pause");
                        break;
                    } else {
                        cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                        system("pause");
                    }
                }
            }
        }
    }
    cout << "\nProgram selesai." << endl;
    return 0;
}