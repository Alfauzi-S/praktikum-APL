#include<iostream>
using namespace std;

int main(){
    int data[] = {12, 45, 7, 23, 56, 10, 34};
    int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen

    int cari;
    bool found = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    // Proses Linear Search
    for(int i = 0; i < n; i++){
        if(data[i] == cari){
            cout << "Data ditemukan pada indeks ke-" << i << endl;
            found = true;
            break; // Berhenti jika sudah ketemu
        }
    }

    if(!found){
        cout << "Data tidak ditemukan dalam array." << endl;
    }

    return 0;
}