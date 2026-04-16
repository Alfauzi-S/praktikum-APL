#include<iostream>
#include<vector>
using namespace std;

int interpolationSearch(int arr[], int n, int x){
    int low = 0, high = n - 1;

    // Syarat: x harus berada di dalam rentang nilai array
    while(low <= high && x >= arr[low] && x <= arr[high]){
        // Kasus khusus jika elemen low dan high sama untuk menghindari pembagian dengan nol
        if(low == high){
            if(arr[low] == x) return low;
            return -1;
        }

        // Rumus estimasi posisi (Interpolasi)
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        // Jika target ditemukan
        if(arr[pos] == x){
            return pos;
        }

        // Jika target lebih besar, cari di sisi kanan
        if(arr[pos] < x){
            low = pos + 1;
        }
        // Jika target lebih kecil, cari di sisi kiri
        else{
            high = pos - 1;
        }
    }
    return -1;
}

int main(){
    // Data dari gambar: [1, 2, 8, 13, 27, 28, 35]
    int data[] = {1, 2, 8, 13, 27, 28, 35};
    int n = sizeof(data) / sizeof(data[0]);
    int cari = 28;

    int hasil = interpolationSearch(data, n, cari);

    if(hasil != -1){
        cout << "Data " << cari << " ditemukan pada indeks ke-" << hasil << endl;
    } else{
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}