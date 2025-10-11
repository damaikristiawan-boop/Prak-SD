#include <iostream>
using namespace std;

struct Node {
    string judul;
    Node* next;
};
Node* topPtr = nullptr;

bool isEmpty() {
    return topPtr == nullptr;
}
void push(string namaBuku) {
    Node* n = new Node{namaBuku, topPtr};
    topPtr = n;
    cout << "Buku \"" << namaBuku << "\" berhasil ditambahkan ke tumpukan.\n";
}
void pop() {
    if (isEmpty()) {
        cout << "Tumpukan kosong!\n";
        return;
    }
    Node* temp = topPtr;
    cout << "Buku \"" << temp->judul << "\" diambil dari tumpukan.\n";
    topPtr = topPtr->next;
    delete temp;
}
void peek() {
    if (isEmpty()) {
        cout << "Tumpukan kosong!\n";
        return;
    }
    cout << "Buku teratas: \"" << topPtr->judul << "\"\n";
}
void display() {
    if (isEmpty()) {
        cout << "Tumpukan kosong!\n";
        return;
    }
    cout << "Isi tumpukan buku (atas ke bawah):\n";
    for (Node* cur = topPtr; cur != nullptr; cur = cur->next) {
        cout << "- " << cur->judul << endl;
    }
}
int main() {
    int pilih;
    string namaBuku;
    do {
        cout << "\n=== TUMPUKAN BUKU ===\n";
        cout << "1. Tambahkan Buku\n";
        cout << "2. Ambil Buku Teratas\n";
        cout << "3. Lihat Buku Teratas\n";
        cout << "4. Tampilkan Semua Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan nama buku: ";
            getline(cin, namaBuku);
            push(namaBuku);
        } 
        else if (pilih == 2) pop();
        else if (pilih == 3) peek();
        else if (pilih == 4) display();
        else if (pilih == 5) cout << "Program selesai. Terima kasih!\n";
        else cout << "Pilihan tidak valid!\n";

    } while (pilih != 5);
    while (!isEmpty()) pop();

    return 0;
}
