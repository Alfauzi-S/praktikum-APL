#include <iostream>
using namespace std;

int main() {
    string innama, inpassword;
    string nama = "Alfauzi";
    string password = "006";
    int kesempatan = 3;

    bool login = false;
    cout << "====================================\n";
    cout << "                Login               \n";
    cout << "====================================";

    do {
        cout << "\nMasukan Nama: ";
        getline(cin, innama);

        cout << "Masukan Password: ";
        getline(cin, inpassword);

        if(innama == nama && inpassword == password) {
            cout << "\n------------Login Berhasil----------\n";
            login = true;
            break;
        } else {
            kesempatan--;
            cout << "Nama atau Password Salah " << "tersisa " << kesempatan << " kesempatan\n";
        }
    } while (kesempatan > 0);

    if (kesempatan == 0) {
        cout << "\n-----------Kesempatan Habis---------\n";
        return 0;
    }
    
    
    if (login) {
        cout << "\n====================================\n";
        cout << "          Program Konversi          \n";
        cout << "====================================\n";

        bool program_berjalan = true;
        while (program_berjalan) {
            cout << "1. Konversi Jam ke Menit dan Detik\n";
            cout << "2. Konversi Menit ke Jam dan Detik\n";
            cout << "3. Konversi Detik ke Jam dan Menit\n";
            cout << "4. Keluar\n";

            int pilihan;
            cout << "\nMasukan Pilihan: ";
            cin >> pilihan;
            cin.ignore();

            int jam, menit, detik;

            switch (pilihan) {
                case 1: 
                    cout << "\n----------------------------------\n";
                    cout << "\nMasukan Jam: ";
                    cin >> jam;
                    cin.ignore();
                    menit = jam * 60;
                    detik = jam * 3600;
                    cout << jam << " Jam" << " = " << menit << " Menit\n";
                    cout << jam << " Jam" << " = " << detik << " Detik\n";
                    cout << "\n----------------------------------\n\n";
                    break;

                case 2:
                    cout << "\n----------------------------------\n";
                    cout << "\nMasukan Menit: ";
                    cin >> menit;
                    cin.ignore();
                    jam = menit / 60 ;
                    detik = menit * 60;
                    cout << menit << " Menit" << " = " << jam << " Jam\n";
                    cout << menit << " Menit" << " = " << detik << " Detik\n";
                    cout << "\n----------------------------------\n\n";
                    break;

                case 3:
                    cout << "\n----------------------------------\n";
                    cout << "\nMasukan Detik: ";
                    cin >> detik;
                    cin.ignore(); 
                    jam = detik / 3600;
                    menit = detik / 60;
                    cout << detik << " Detik" << " = " << jam << " Jam\n";
                    cout << detik << " Detik" << " = " << menit << " Menit\n";
                    cout << "\n----------------------------------\n\n";
                    break;

                case 4:
                    cout << "\n--------keluar Dari Program-------\n";
                    cout << "Terima Kasih Telah Menggunakan Program Ini\n";
                    program_berjalan = false;
                    break;

                default:
                    cout << "\n--------Pilihan Tidak Valid-------\n\n";
                    break;
            }
        }
    }
    return 0;
}