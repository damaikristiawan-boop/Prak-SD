#include <iostream>
#include <string>
using namespace std;

int main() {
    int jumlahKontak;
    int ditemukan = 0;
    string cariNama;

    cout << "=== PROGRAM MENCARI KONTAK DI HP ===" << endl;
    cout << "Masukkan jumlah kontak: ";
    cin >> jumlahKontak;
    cin.ignore();

    string kontak[jumlahKontak];

    cout << "\nMasukkan nama kontak:" << endl;
    for (int i = 0; i < jumlahKontak; i++) {
        cout << "Kontak ke-" << i + 1 << ": ";
        getline(cin, kontak[i]);
    }

    cout << "\nMasukkan nama yang ingin dicari: ";
    getline(cin, cariNama);

    for (int i = 0; i < jumlahKontak; i++) {
        if (kontak[i] == cariNama) {
            cout << "\nKontak \"" << cariNama << "\" ditemukan pada posisi ke-" << i + 1 << "." << endl;
            ditemukan = 1;
            break;
        }
    }

    if (ditemukan == 0) {
        cout << "\nKontak \"" << cariNama << "\" tidak ditemukan dalam daftar." << endl;
    }

    cout << "\n=== Pencarian selesai ===" << endl;
    return 0;
}
