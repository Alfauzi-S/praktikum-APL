
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