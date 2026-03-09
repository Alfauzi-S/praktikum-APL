#include <iostream>
#include <tabulate/table.hpp>

using namespace std; 
using namespace tabulate;

struct alamat {
    string jalan;
    string kota;
    string provinsi;
};

struct pembeli {
    string nama;
    string password;
    string email;
    alamat alamat;
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

# define maxuser 100
# define maxproduk 100
int userIndex = 0;
int mabelIndex = 5;
pembeli user[maxuser];
produk mabel[maxproduk];

string namaAdmin = "Alfauzi";
string passwordAdmin ="006";

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

    string pilihan, currentUser;
    bool loginSuccess = false;
    bool admin = false;

    while (true) {
        system("cls");
        cout << "\n1. Login\n";
        cout << "2. Register\n";
        cout << "0. Exit\n";
        cout << "\nMasukan Pilihan: ";
        cin >> pilihan; 
        cin.ignore();

        if (pilihan == "1") {
            system("cls");
            string innama, inpassword;
            int kesempatanLogin = 3;
            while (kesempatanLogin > 0 && !loginSuccess) {
                cout << "\nMasukan Nama: ";
                getline(cin, innama);
                cout << "\nMasukan Password: ";
                getline(cin, inpassword);

                if(innama == namaAdmin && inpassword == passwordAdmin) {
                    cout << "\nLogin Berhasil, selamat datang admin " << innama << "\n";
                    loginSuccess = true;
                    admin = true;
                    currentUser = innama;
                    system("pause");
                } else {
                    for(int i = 0; i < userIndex; i++) {
                        if(user[i].nama == innama && user[i].password == inpassword) {
                            cout << "\nLogin Berhasil, selamat datang " << innama << "\n";
                            loginSuccess = true;
                            currentUser = innama;
                            system("pause");
                            break;

                        }
                    }
                }

                if (!loginSuccess) {
                    kesempatanLogin--;
                    if(kesempatanLogin > 0) {
                        cout << "\nLogin Gagal. Tersisa " << kesempatanLogin << " kesempatan.\n";
                        system("pause");
                    } else {
                        cout << "\nLogin Gagal. Anda telah mencapai batas percobaan maksimal (3 kali).\n";
                        cout << "Program Berhenti\n";
                        return 0;
                    }
                }
            }

        } else if (pilihan == "2") {
            system("cls");
            if (userIndex >= maxuser) {
                cout << "\nMaaf, Jumlah user sudah mencapai batas maksimum.\n";
                system("pause");
            } else {
                string tempInnama;
                cout << "\nMasukan Nama: ";
                getline(cin, tempInnama);

                bool duplikat = false;
                for(int i = 0; i < userIndex; i++) {
                    if(user[i].nama == tempInnama) {
                        duplikat = true;
                        break;
                    }
                }

                if (duplikat) {
                    cout << "\nNama sudah digunakan.\n";
                    cout << "Kembali ke menu.\n";
                    system("pause");
                } else {
                    user[userIndex].nama = tempInnama;
                    cout << "\nMasukan Password: ";
                    getline(cin, user[userIndex].password);
                    cout << "\nMasukan Email: ";
                    getline(cin, user[userIndex].email);
                    cout << "\nMasukan Alamat Jalan: ";
                    getline(cin, user[userIndex].alamat.jalan);
                    cout << "\nMasukan Alamat Kota: ";
                    getline(cin, user[userIndex].alamat.kota);
                    cout << "\nMasukan Alamat Provinsi: ";
                    getline(cin, user[userIndex].alamat.provinsi);
                    userIndex++;
                    cout << "\nRegistrasi berhasil! Akun untuk '" << user[userIndex - 1].nama << "' telah dibuat." << endl;
                    cout << "Jumlah user saat ini: " << userIndex << endl;
                    system("pause");
                }
            }

        } else if (pilihan == "0") {
            cout << "\nKeluar dari Program\n";
            return 0;
        } else {
            cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
            system("pause");
        }

        if(loginSuccess) {
            if(admin) {
                system("cls");
                string adminPilihan;
                while(true) {
                    system("cls");
                    cout << "\n1. Tampilkan Produk Mabel\n";
                    cout << "2. Update Produk Mabel\n";
                    cout << "3. Buat Produk Mabel\n";
                    cout << "4. Hapus Produk Mabel\n";
                    cout << "0. Logout\n";
                    cout << "\nMasukan Pilihan: ";
                    cin >> adminPilihan; 
                    cin.ignore();

                    if(adminPilihan == "1") {
                        system("cls");
                        if(mabelIndex == 0) {
                            cout << "\nTidak ada Data\n";
                        } else {
                            Table tablemabel;

                            tablemabel.add_row({"ID Mabel", "Nama Mabel", "Jenis Mabel", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});

                            for(int i = 0; i < mabelIndex; i++) {
                                tablemabel.add_row({
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

                            cout << "\n" << tablemabel << "\n";
                            system("pause");
                        }
                    } else if(adminPilihan == "2") {
                        system("cls");
                        if(mabelIndex == 0) {
                            cout << "\nTidak ada Data\n";
                        } else {
                            Table tablemabel;

                            tablemabel.add_row({"ID Mabel", "Nama Mabel", "Jenis Mabel", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});

                            for(int i = 0; i < mabelIndex; i++) {
                                tablemabel.add_row({
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

                            cout << "\n" << tablemabel << "\n";
                        }

                        string inID, inKolom, simpan;
                        string tempID, tempNama, tempJenis, tempIDmat, tempNamamat, tempjenismat;
                        int tempStock, tempHarga;
                        bool idFind = false;

                        cout << "\nMasukan ID Mabel yang mau di ubah: ";
                        cin >> inID;
                        cin.ignore();

                        for(int i = 0; i < mabelIndex; i++) {
                            if(inID == mabel[i].idProduk) {
                                cout << "\nID Mabel di temukan.\n";
                                idFind = true;
                                cout << "\n1) ID Mabel\n"  << "2) Nama Mabel\n" << "3) Jenis Mabel\n"  << "4) Stock\n" << "5) Harga\n" << "6) ID Material\n" << "7) Nama Material\n" << "8) Jenis Material\n";
                                while(true) {
                                    cout << "\nMasukan kolom apa yang mau di ubah (1/2/3/4/5/6/7/8): ";
                                    cin >> inKolom;
                                    cin.ignore();

                                    if(inKolom == "1") {
                                        cout << "\nKolom ID Mabel " << i + 1 << " : " << mabel[i].idProduk;
                                        cout << "\n\nMasukan ID Mabel Baru: ";
                                        getline(cin, tempID);

                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].idProduk = tempID;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else if(inKolom == "2") {
                                        cout << "\nKolom Nama Mabel " << i + 1 << " : " << mabel[i].namaProduk;
                                        cout << "\n\nMasukan Nama Mabel Baru: ";
                                        getline(cin, tempNama);

                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].namaProduk = tempNama;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else if(inKolom == "3") {
                                        cout << "\nKolom Jenis Mabel " << i + 1 << " : " << mabel[i].jenisProduk;
                                        cout << "\n\nMasukan Jenis Mabel Baru: ";
                                        getline(cin, tempJenis);

                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].jenisProduk = tempJenis;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else if(inKolom == "4") {
                                        cout << "\nKolom Stock " << i + 1 << " : " << mabel[i].stock;
                                        cout << "\n\nMasukan Stock Baru: ";
                                        cin >> tempStock;
                                        cin.ignore();

                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].stock = tempStock;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else if(inKolom == "5") {
                                        cout << "\nKolom Harga " << i + 1 << " : " << mabel[i].harga;
                                        cout << "\n\nMasukan Harga Baru: ";
                                        cin >> tempHarga;
                                        cin.ignore();
                                        
                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].harga = tempHarga;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else if(inKolom == "6") {
                                        cout << "\nKolom ID Material " << i + 1 << " : " << mabel[i].material.idMaterial;
                                        cout << "\n\nMasukan ID Material Baru: ";
                                        getline(cin, tempIDmat);
                                        
                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].material.idMaterial = tempIDmat;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else if(inKolom == "7") {
                                        cout << "\nKolom Nama Material " << i + 1 << " : " << mabel[i].material.namaMaterial;
                                        cout << "\n\nMasukan Nama Material Baru: ";
                                        getline(cin, tempNamamat);
                                        
                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].material.namaMaterial = tempNamamat;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else if(inKolom == "8") {
                                        cout << "\nKolom Jenis Material " << i + 1 << " : " << mabel[i].material.jenisMaterial;
                                        cout << "\n\nMasukan Jenis Material Baru: ";
                                        getline(cin, tempjenismat);
                                        
                                        while(true) {
                                            cout << "\nSimpan (y/n)? ";
                                            cin >> simpan;
                                            cin.ignore();

                                            if(simpan == "y") {
                                                mabel[i].material.jenisMaterial = tempjenismat;
                                                cout << "\nBerhasil di simpan\n";
                                                system("pause");
                                                break;
                                            } else if(simpan == "n") {
                                                cout << "\nGagal di simpan\n";
                                                system("pause");
                                                break;
                                            } else {
                                                cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                            }
                                        }
                                        break;
                                    } else {
                                        cout << "\nPilihan tidak valid, silahkan coba lagi.\n";
                                        system("pause");
                                    }
                                }
                                break;
                            } 
                        }

                        if(!idFind) {
                            cout << "\nID Mabel tidak di temukan.\n";
                            system("pause");
                        }

                    } else if(adminPilihan == "3") {
                        system("cls");
                        string tempIDproduk;
                        if(mabelIndex >= maxproduk) {
                            cout << "\nMaaf, Jumlah Produk sudah mencapai batas maksimum.\n";
                            system("pause");
                        } else {
                            cout << "\nMasukan ID Produk: ";
                            getline(cin, tempIDproduk);

                            bool duplikat = false;
                            for(int i = 0; i < mabelIndex; i++) {
                                if(mabel[i].idProduk == tempIDproduk) {
                                    duplikat = true;
                                    break;
                                }
                            }

                            if(duplikat) {
                                cout << "\nID sudah digunakan.\n";
                                cout << "Kembali ke menu.\n";
                                system("pause");
                            } else {
                                mabel[mabelIndex].idProduk = tempIDproduk;
                                cout << "\nMasukan Nama Produk: ";
                                getline(cin, mabel[mabelIndex].namaProduk);
                                cout << "\nMasukan Jenis Produk: ";
                                getline(cin, mabel[mabelIndex].jenisProduk);
                                cout << "\nMasukan ID Material: ";
                                getline(cin, mabel[mabelIndex].material.idMaterial);
                                cout << "\nMAsukan Nama Material: ";
                                getline(cin, mabel[mabelIndex].material.namaMaterial);
                                cout << "\nMasukan Jenis Material: ";
                                getline(cin, mabel[mabelIndex].material.jenisMaterial);
                                cout << "\nBerhasil Membuat Produk Mabel\n";
                                mabelIndex++;
                                system("pause");
                            }
                        }
                    } else if(adminPilihan == "4") {
                        system("cls");
                        if(mabelIndex == 0) {
                            cout << "\nTidak ada Data\n";
                        } else {
                            Table tablemabel;

                            tablemabel.add_row({"ID Mabel", "Nama Mabel", "Jenis Mabel", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});

                            for(int i = 0; i < mabelIndex; i++) {
                                tablemabel.add_row({
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

                            cout << "\n" << tablemabel << "\n";

                            string inID;
                            bool idFind = false;
                            cout << "\nMasukan ID Mabel yang mau di hapus: ";
                            cin >> inID;
                            cin.ignore();

                            for(int i = 0; i < mabelIndex; i++) {
                                if(inID == mabel[i].idProduk) {
                                    cout << "\nID Mabel di temukan.\n";
                                    int index = i;
                                    idFind = true;

                                    for(int j = index; j < mabelIndex - 1; j++) {
                                        mabel[j] = mabel[j + 1];
                                    }
                                    mabelIndex--;
                                    cout << "\nBerhasil Menghapus Produk Mabel\n";
                                    system("pause");
                                    break;
                                }
                            }

                            if(!idFind) {
                                cout << "\nID Mabel tidak di temukan.\n";
                                system("pause");
                            }
                        }
                    } else if(adminPilihan == "0") {
                        cout << "\nAnda Telah Logout\n";
                        system("pause");
                        break;
                    } else {
                        cout << "\nPilihan tidak valid, silahkan coba lagi.";
                        system("pause");
                    }
                }
            } else {
                string userPilihan;
                while(true) {
                    system("cls");
                    cout << "\n1. Lihat Data User\n";
                    cout << "2. Beli Produk\n";
                    cout << "0. Logout\n";
                    cout << "\nMasukan Pilihan: ";
                    cin >> userPilihan; 
                    cin.ignore();

                    if(userPilihan == "1") {
                        system("cls");
                        if(userIndex == 0) {
                            cout << "\nTidak ada Data\n";
                        } else {
                            bool userDitemukan = false;

                            for(int i = 0; i < userIndex; i++) {
                                if(user[i].nama == currentUser) {
                                    Table tableUser;
                                    tableUser.add_row({"Nama", "Password", "Email", "Jalan", "Kota", "Provinsi"});
                                    
                                    tableUser.add_row({
                                        user[i].nama,
                                        user[i].password,
                                        user[i].email,
                                        user[i].alamat.jalan,
                                        user[i].alamat.kota,
                                        user[i].alamat.provinsi
                                    });

                                    cout << "\n" << tableUser << "\n";
                                    userDitemukan = true;
                                    break;
                                }
                            }

                            if(!userDitemukan) {
                                cout << "\nUser tidak ditemukan.\n";
                            }
                            system("pause");
                        }
                    } else if(userPilihan == "2") {
                        system("cls");
                        if(mabelIndex == 0) {
                            cout << "\nTidak ada Data\n";
                        } else {
                            Table tablemabel;

                            tablemabel.add_row({"ID Mabel", "Nama Mabel", "Jenis Mabel", "Stock", "Harga", "ID Material", "Nama Material", "Jenis Material"});

                            for(int i = 0; i < mabelIndex; i++) {
                                tablemabel.add_row({
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

                            cout << "\n" << tablemabel << "\n";

                            string inID;
                            bool idFind= false;
                            int jumlah;
                            cout << "\nMasukan ID Mabel yang mau di beli: ";
                            getline(cin, inID);
                                
                            for(int i = 0; i < mabelIndex; i++) {
                                if(inID == mabel[i].idProduk) {
                                    cout << "\nID Mabel ditemukan.\n";
                                    idFind = true;
                                        
                                    cout << "\nMasukan Jumlah Beli: ";
                                    cin >> jumlah;
                                    cin.ignore();
                                    
                                    if(jumlah <= mabel[i].stock && jumlah > 0) {
                                        mabel[i].stock -= jumlah;
                                        cout << "Berhasil Membeli Produk (hanya sebuah demo yang dimana hanya menggurangi stock)\n";
                                        cout << "Sisa Stock: " << mabel[i].stock << endl;
                                        system("pause");
                                        break;
                                    } else {
                                        cout << "Stok tidak mencukupi atau jumlah tidak valid.\n";
                                        cout << "Stok Tersedia: " << mabel[i].stock << endl;
                                        system("pause");
                                    }
                                }
                                break;
                            }
                            
                            if(!idFind) {
                                cout << "\nID Mabel tidak ditemukan.\n";
                                system("pause");
                            }
                        }
                    } else if(userPilihan == "0") {
                        cout << "\nAnda Telah Logout\n";
                        system("pause");
                        break;
                    } else {
                        cout << "\nPilihan tidak valid, silahkan coba lagi.";
                        system("pause");
                    }
                }
            }
        }
    }
}