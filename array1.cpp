
#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int data[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Menambahkan data (Push)
    void push(int nilai) {
        if (top == MAX - 1) {
            cout << "Stack penuh! Tidak bisa menambah data.\n";
        } else {
            top++;
            data[top] = nilai;
            cout << nilai << " berhasil ditambahkan.\n";
        }
    }

    // Menghapus data (Pop)
    void pop() {
        if (top == -1) {
            cout << "Stack kosong! Tidak ada data yang dihapus.\n";
        } else {
            cout << "Data yang dihapus: " << data[top] << endl;
            top--;
        }
    }

    // Melihat data paling atas (Top)
    void tampilTop() {
        if (top == -1) {
            cout << "Stack masih kosong.\n";
        } else {
            cout << "Data paling atas: " << data[top] << endl;
        }
    }

    // Menampilkan seluruh data
    void tampil() {
        if (top == -1) {
            cout << "Stack masih kosong.\n";
        } else {
            cout << "\nIsi Stack (TOP ke bawah):\n";

            for (int i = top; i >= 0; i--) {
                cout << data[i] << endl;
            }
        }
    }
};

int main() {
    Stack s;
    int pilihan, nilai;

    do {
        cout << "\n===== PROGRAM STACK ARRAY =====\n";
        cout << "1. Push (Tambah Data)\n";
        cout << "2. Pop (Hapus Data)\n";
        cout << "3. Tampilkan Stack\n";
        cout << "4. Lihat TOP\n";
        cout << "5. Keluar\n";

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                s.push(nilai);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.tampil();
                break;

            case 4:
                s.tampilTop();
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
