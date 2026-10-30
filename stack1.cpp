#include <iostream>
#include <stdexcept>

using namespace std;

class StackArray {
private:
    static constexpr int CAP = 5; // Kapasitas maksimum stack
    int a[CAP];                   // Array untuk menyimpan data
    int t = -1;                   // Indeks top, dimulai dari -1 (kosong)

public:
    // Mengecek apakah stack kosong
    bool empty() const { 
        return t == -1; 
    }

    // Menambahkan elemen ke atas stack (push)
    void push(int x) {
        if (t == CAP - 1) {
            throw overflow_error("Stack Overflow: Kapasitas stack penuh!");
        }
        a[++t] = x; // Increment t terlebih dahulu, lalu masukkan data
    }

    // Menghapus elemen teratas stack (pop)
    void pop() {
        if (empty()) {
            throw underflow_error("Stack Underflow: Stack kosong, tidak bisa pop!");
        }
        --t; // Turunkan indeks top
    }

    // Membaca elemen teratas stack tanpa menghapusnya (top)
    int top() const {
        if (empty()) {
            throw underflow_error("Stack kosong, tidak ada elemen di top!");
        }
        return a[t];
    }

    // Mengetahui jumlah elemen saat ini
    int size() const {
        return t + 1;
    }
};

int main() {
    try {
        StackArray s;

        cout << "Apakah stack kosong? " << (s.empty() ? "Ya" : "Tidak") << endl;

        // Melakukan push elemen
        s.push(10);
        s.push(20);

        cout << "Elemen teratas (top): " << s.top() << endl; // Output: 30
        cout << "Ukuran stack saat ini: " << s.size() << endl; // Output: 3

        // Melakukan pop elemen teratas
        s.pop();
        cout << "Setelah pop, elemen teratas baru: " << s.top() << endl; // Output: 20
        cout << "Ukuran stack sekarang: " << s.size() << endl; // Output: 2

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}