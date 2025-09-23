#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> teman;
    int pilih;
    string nama;

    do {
        cout << "\n=== Menu Daftar Teman ===\n";
        cout << "1. Tambah Teman\n";
        cout << "2. Lihat Daftar Teman\n";
        cout << "3. Hapus Teman Terakhir\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
        case 1:
            cout << "Masukkan nama teman: ";
            getline(cin, nama);
            teman.push_back(nama);
            cout << nama << " berhasil ditambahkan!\n";
            break;
        case 2:
            if (teman.empty()) {
                cout << "Daftar teman kosong!\n";
            } else {
                cout << "\n=== Daftar Teman ===\n";
                for (int i = 0; i < teman.size(); i++) {
                    cout << i + 1 << ". " << teman[i] << endl;
                }
            }
            break;
        case 3:
            if (!teman.empty()) {
                cout << teman.back() << " dihapus dari daftar teman.\n";
                teman.pop_back();
            } else {
                cout << "Tidak ada teman untuk dihapus!\n";
            }
            break;
        case 4:
            cout << "Keluar dari program. Bye!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 4);

    return 0;
}
