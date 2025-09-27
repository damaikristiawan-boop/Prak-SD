#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah kontak: ";
    cin >> n;

    string kontak[100];

    // Input nama kontak
    cout << "Masukkan nama kontak:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> kontak[i]; // sederhana: hanya 1 kata per nama
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (kontak[j] < kontak[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            string temp = kontak[i];
            kontak[i] = kontak[pos];
            kontak[pos] = temp;
        }
    }

    // Output hasil urutan
    cout << "\nDaftar kontak setelah diurutkan (A-Z):" << endl;
    for (int i = 0; i < n; i++) {
        cout << kontak[i] << endl;
    }

    return 0;
}
