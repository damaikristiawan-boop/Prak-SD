#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node{
    int noAbsen;
    string nama;
    Node *next;
};

void initTable(Node *table[]){
    for (int i = 0; i < SIZE; i++){
        table[i] = nullptr;
    }
}

int hashFunction(int noAbsen){
    return (noAbsen % SIZE + SIZE) % SIZE;
}

void insert(Node *table[], int noAbsen, string nama){
    int index = hashFunction(noAbsen);
    Node *cur = table[index];

    while (cur != nullptr){
        if (cur->noAbsen == noAbsen){
            cur->nama = nama;
            return;
        }
        cur = cur->next;
    }

    Node *baru = new Node;
    baru->noAbsen = noAbsen;
    baru->nama = nama;
    baru->next = table[index];
    table[index] = baru;
}

Node *search(Node *table[], int noAbsen){
    int index = hashFunction(noAbsen);
    Node *cur = table[index];
    while (cur != nullptr){
        if (cur->noAbsen == noAbsen)
            return cur;
        cur = cur->next;
    }
    return nullptr;
}

void removeKey(Node *table[], int noAbsen){
    int index = hashFunction(noAbsen);
    Node *cur = table[index];
    Node *prev = nullptr;

    while (cur != nullptr){
        if (cur->noAbsen == noAbsen){
            if (prev == nullptr)
                table[index] = cur->next;
            else
                prev->next = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void display(Node *table[]){
    cout << "\n=== Data Mahasiswa (Hash Map Separate Chaining) ===\n";
    for (int i = 0; i < SIZE; i++){
        cout << i << ": ";
        Node *tmp = table[i];
        while (tmp != nullptr){
            cout << "(" << tmp->noAbsen << ", " << tmp->nama << ") -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
}

int main(){
    Node *table[SIZE];
    initTable(table);

    insert(table, 10, "Damai Kristiawan");
    insert(table, 7, "Akhmad Faishal");
    insert(table, 15, "Angga Saputra");
    insert(table, 28, "Rio Gunawan");

    display(table);

    Node *hasil = search(table, 15);
    if (hasil != nullptr)
        cout << "\nMahasiswa dengan No Absen " << hasil->noAbsen << " ditemukan: " << hasil->nama << endl;
    else
        cout << "\nMahasiswa dengan No Absen tersebut tidak ditemukan.\n";

    removeKey(table, 10);
    cout << "\nSetelah menghapus No Absen 10:\n";
    display(table);

    return 0;
}
