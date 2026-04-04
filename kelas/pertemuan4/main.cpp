
#include <iostream>
using namespace std;
struct Address
{
    string kota;
    string provinsi;
    string negara;
};

int main()
{

    Address address1, address2;

    address1.kota = "Samarinda";
    address1.provinsi = "Kalimantan Timur";
    address1.negara = "Indonesia";

    address2 = address1;

    address2.kota = "ikn";

    cout << address1.kota << endl;

    cout << address2.kota;

    string var = "Aku Variabel";
    string *varPtr = &var;
    cout << "Hasil dari varPtr: " << varPtr << endl;
    cout << "Hasil dari *varPtr: " << *varPtr << endl;
    cout << "Kesimpulannya varPtr isi nya alamatnyavar " << endl;
    cout << "*varPtr hasilnya value dari var" << endl;
    cout << "Jika masih bingung bisa amati output berikut" << endl;
    cout << endl;
    cout << "Hasil/value dari var " << var << endl;
    cout << "Hasil/value dari alamat var (&var) " << &var << endl;
    cout << "Hasil/value dari varPtr " << varPtr << endl;
    cout << "Hasil/value dari *varPtr " << var << endl;

    return 0;
}

// int main(){
//     string nama = "Rangga Aryawinata";
//     cout << &nama << " adalah alamatnya " << nama << endl;
//     return 0;
// }

// int main(){
//     cout << "Pointer yang menunjuk ke suatu array" << endl;
//     int a[5] = {1, 2, 3, 4, 5};
//     int (*aPtr)[5] = &a;
//     for(int i = 0; i < 5; i++){
//         cout << *aPtr << endl;
//     }

//     cout << "\nPointer yang menunjuk ke arah elemen array" << endl;
//     int b[5] = {1, 2, 3, 4, 5};
//     int *bPtr = b;
//     for(int i = 0; i < 5; i++){
//         cout << "Alamat: " << bPtr << " | Nilai: " << *bPtr << endl;
//         bPtr++;
//     }

// }

// int main(){
//     cout << "Pointer yang menunjuk ke suatu array" << endl;
//     int a[5] = {1, 2, 3, 4, 5};
//     int (*aPtr)[5] = &a;
//     for(int i = 0; i < 5; i++){
//         cout << *aPtr << endl;
//     }

//     cout << "\nPointer yang menunjuk ke arah elemen array" << endl;
//     int b[5] = {1, 2, 3, 4, 5};
//     int *bPtr = b;
//     for(int i = 0; i < 5; i++){
//         cout << "Alamat: " << bPtr << " | Nilai: " << *bPtr << endl;
//         bPtr++;
//     }

// }

// int main(){
//     cout << "Pointer yang menunjuk ke suatu array" << endl;
//     int a[5] = {1, 2, 3, 4, 5};
//     int (*aPtr)[5] = &a;
//     for(int i = 0; i < 5; i++){
//         cout << *aPtr << endl;  // Masih cetak alamat (seperti penjelasan sebelumnya)
//     }

//     cout << "\nPointer yang menunjuk ke arah elemen array" << endl;
//     int b[5] = {1, 2, 3, 4, 5};

//     // # int *bPtr = b;
//     // # for(int i = 0; i < 5; i++){
//     // #     cout << "Alamat: " << bPtr << " | Nilai: " << *bPtr << endl;
//     // #     bPtr++;
//     // # }

//     cout << "\nMengakses hanya elemen tertentu" << endl;
//     int *ptrB2 = &b[2];

//     cout << "Alamat elemen indeks-2 : " << ptrB2 << endl;
//     cout << "Nilai elemen indeks-2  : " << *ptrB2 << endl;

//     return 0;
// }

// int ubahNilai(int a, int b){
//     return a = b;
// }

// int main(){
//     int a, b;
//     a = 5;
//     b = 20;
//     ubahNilai(a, b);
//     cout << "Nilai a setelah fungsi: " << a << endl;
//     return 0;
// }

// Parameter 'a' adalah reference (&)
// int ubahNilai(int &a, int b){
//     return a = b;
// }

// int main () {
//     int a, b;
//     a = 5;
//     b = 20;

//     ubahNilai(a, b);

//     cout << a << endl;
//     return 0;
// }

// Parameter 'a' adalah pointer (*)
// int ubahNilai(int *a, int b){
//     return *a = b;
// }

// int main () {
//     int a, b;
//     a = 5;
//     b = 20;

//     ubahNilai(&a, b);

//     cout << "Nilai a setelah diubah (Pointer): " << a << endl;
//     return 0;
// }

// struct Menu{
//     string nama;
//     float harga;
// };

// int main(){
//     Menu nasgor;
//     Menu* nasgorPtr = &nasgor;

//     nasgor.nama = "Nasi Goreng Cumi Hitam Pak Kris";
//     nasgor.harga = 15000;
//     cout << nasgor.nama << " " << nasgor.harga << endl;

//     nasgorPtr->nama = "Nasi Goreng Mawut";
//     nasgorPtr->harga = 13000;

//     cout << nasgor.nama << " " << nasgor.harga << endl;
//     return 0;
// }