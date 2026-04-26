// ============================================================
// input_handler.cpp
// Implementasi fungsi-fungsi untuk menerima input dari pengguna
//
// Semua input memiliki validasi sederhana:
//   - n harus bilangan bulat > 0
//   - Elemen matriks/vektor dibaca sebagai double
// ============================================================

#include "../include/input_handler.h"
#include <iostream>
#include <limits>    // numeric_limits (untuk membersihkan buffer)

using namespace std;

// ============================================================
// inputN: Minta pengguna memasukkan ukuran sistem persamaan
// ============================================================
int inputN() {
    int n;

    while (true) {
        cout << "Masukkan jumlah persamaan (n): ";
        cin >> n;

        // Cek apakah input valid dan n positif
        if (cin.fail() || n <= 0) {
            cin.clear(); // reset flag error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buang sisa input
            cout << "[Error] n harus bilangan bulat positif. Coba lagi.\n";
        } else {
            break; // input valid, keluar dari loop
        }
    }

    return n;
}

// ============================================================
// inputMatriksA: Minta pengguna memasukkan matriks koefisien A
// ============================================================
Matrix inputMatriksA(int n) {
    // Buat matriks kosong n x n, isi awal 0
    Matrix A(n, vector<double>(n, 0.0));

    cout << "\nMasukkan elemen matriks A (" << n << " x " << n << "):\n";
    cout << "(Masukkan baris per baris, pisahkan dengan spasi atau Enter)\n\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "  A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }

    return A;
}

// ============================================================
// inputVektorB: Minta pengguna memasukkan vektor hasil b
// ============================================================
vector<double> inputVektorB(int n) {
    vector<double> b(n, 0.0); // vektor kosong panjang n

    cout << "\nMasukkan elemen vektor b (sisi kanan persamaan):\n";

    for (int i = 0; i < n; i++) {
        cout << "  b[" << i + 1 << "] = ";
        cin >> b[i];
    }

    return b;
}
