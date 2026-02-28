#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};

int main() {

    // Output dasar
    cout << "Hello World!" << endl;

    string nama = "Kei";
    int umur = 20;
    cout << "Halo, nama saya " << nama << " dan umur saya " << umur << " tahun\n";

    // Input dengan cin
    cout << "Masukkan nama kamu: ";
    cin >> nama;
    cout << "Halo, " << nama << endl;

    cin.ignore(); // membersihkan newline

    // Input dengan getline
    cout << "Masukkan nama lengkap kamu: ";
    getline(cin, nama);
    cout << "Halo, " << nama << endl;

    // Tipe data
    int sumbuY = -45;
    float berat_badan = 50.5;
    double tinggi_badan = 170.5;
    char jenis_kelamin = 'L';
    bool is_menikah = false;

    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of long: " << sizeof(long) << endl;

    // Array
    int angka[5] = {1, 2, 3, 4, 5};

    // Struct
    Mahasiswa mhs = {"Sipuwah", 20, 3.5};
    cout << "Mahasiswa: " << mhs.nama << " IPK: " << mhs.ipk << endl;

    // Operator aritmatika
    int a, b, hasil;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;

    hasil = a + b;
    cout << "Penjumlahan: " << hasil << endl;

    hasil = a - b;
    cout << "Pengurangan: " << hasil << endl;

    hasil = a * b;
    cout << "Perkalian: " << hasil << endl;

    if (b != 0) {
        cout << "Pembagian: " << a / b << endl;
        cout << "Modulus: " << a % b << endl;
    }

    // Operator perbandingan
    int apel, melon;
    cout << "\n=== Program Perbandingan Buah ===" << endl;
    cout << "Masukkan jumlah Apel: ";
    cin >> apel;
    cout << "Masukkan jumlah Melon: ";
    cin >> melon;

    cout << boolalpha;
    cout << "Apel == Melon: " << (apel == melon) << endl;
    cout << "Apel != Melon: " << (apel != melon) << endl;
    cout << "Apel > Melon: " << (apel > melon) << endl;

    if (apel > melon) {
        cout << "Jual Apel\n";
    } else if (melon > apel) {
        cout << "Jual Melon\n";
    } else {
        cout << "Jual semua\n";
    }

    // Operator logika
    cout << "a > 0 && b < 10 : " << (a > 0 && b < 10) << endl;
    cout << "a > 0 || b < 10 : " << (a > 0 || b < 10) << endl;
    cout << "!a : " << (!a) << endl;

    // Ternary
    bool hujan = false;
    string pesan = hujan ? "Bawa payung" : "Tidak perlu payung";
    cout << pesan << endl;

    // Increment
    int z = 1;
    cout << "Sebelum increment: " << z << endl;
    cout << "Prefix ++z: " << ++z << endl;
    cout << "Postfix z++: " << z++ << endl;
    cout << "Hasil akhir: " << z << endl;

    // If else umur
    int age = 18;
    if (age < 13) {
        cout << "Anak\n";
    } else if (age >= 13 && age <= 18) {
        cout << "Remaja\n";
    } else {
        cout << "Dewasa\n";
    }

    // Switch nilai
    int nilai;
    cout << "Masukkan nilai (0-100): ";
    cin >> nilai;

    if (nilai < 0 || nilai > 100) {
        cout << "Nilai harus 0-100\n";
        return 1;
    }

    switch (nilai / 10) {
        case 10:
        case 9:
            cout << "A\n";
            break;
        case 8:
            cout << "B\n";
            break;
        case 7:
            cout << "C\n";
            break;
        case 6:
            cout << "D\n";
            break;
        default:
            cout << "E\n";
    }

    // Nested if
    bool malas = true;
    bool mengantuk = true;

    if (malas) {
        if (mengantuk) {
            cout << "Saya tidur\n";
        }
    } else {
        cout << "Gak ngapa-ngapain\n";
    }

    // For loop
    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }

    // While loop
    int i = 0;
    while (i < 5) {
        cout << i << endl;
        i++;
    }

    // Range-based for
    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr) {
        cout << x << endl;
    }

    return 0;
}