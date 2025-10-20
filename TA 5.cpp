#include <iostream>
#include <string>
using namespace std;
struct Node {
    string nama;
    string nomor;
    Node *left, *right;
    Node(string n, string no) : nama(n), nomor(no), left(nullptr), right(nullptr) {}
};
Node* insertKontak(Node* root, string nama, string nomor) {
    if (!root)
        return new Node(nama, nomor);
    if (nama < root->nama)
        root->left = insertKontak(root->left, nama, nomor);
    else if (nama > root->nama)
        root->right = insertKontak(root->right, nama, nomor);
    else
        cout << "Kontak dengan nama tersebut sudah ada!\n";
    return root;
}
Node* searchKontak(Node* root, string nama) {
    if (!root || root->nama == nama)
        return root;
    if (nama < root->nama)
        return searchKontak(root->left, nama);
    else
        return searchKontak(root->right, nama);
}
void displayKontakInorder(Node* root) {
    if (!root)
        return;
    displayKontakInorder(root->left);
    cout << "Nama: " << root->nama << " | Nomor: " << root->nomor << endl;
    displayKontakInorder(root->right);
}
int countKontak(Node* root) {
    if (!root)
        return 0;
    return 1 + countKontak(root->left) + countKontak(root->right);
}
int main() {
    Node* root = nullptr;
    int pilih;
    string nama, nomor;
    do {
        cout << "\n=== DAFTAR KONTAK TELEPON ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Cari Kontak\n";
        cout << "3. Tampilkan Semua Kontak (Urut Alfabet)\n";
        cout << "4. Hitung Jumlah Kontak\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();
        if (pilih == 1) {
            cout << "Masukkan Nama  : ";
            getline(cin, nama);
            cout << "Masukkan Nomor : ";
            getline(cin, nomor);
            root = insertKontak(root, nama, nomor);
        } 
        else if (pilih == 2) {
            cout << "Masukkan Nama yang dicari: ";
            getline(cin, nama);
            Node* hasil = searchKontak(root, nama);
            if (hasil)
                cout << "Ditemukan! Nomor: " << hasil->nomor << endl;
            else
                cout << "Kontak tidak ditemukan.\n";
        } 
        else if (pilih == 3) {
            cout << "\nDaftar Kontak (Urut Alfabet):\n";
            displayKontakInorder(root);
        } 
        else if (pilih == 4) {
            cout << "Jumlah total kontak: " << countKontak(root) << endl;
        }
        else if (pilih == 5) {
            cout << "Keluar dari program...\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
    return 0;
}
