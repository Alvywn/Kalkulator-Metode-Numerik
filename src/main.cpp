// ============================================================
// main.cpp
// Program utama: Kalkulator Sistem Persamaan Linier
//                menggunakan metode Gauss-Jordan
//
// Alur program:
//   1. Tampilkan header program
//   2. Terima input n, A, dan b dari pengguna
//   3. Tampilkan sistem persamaan yang dimasukkan
//   4. Bentuk matriks augmented [A|b]
//   5. Jalankan eliminasi Gauss-Jordan (tampilkan tiap tahap)
//   6. Tampilkan solusi akhir (atau pesan jika tidak ada solusi)
//   7. Tanya pengguna apakah ingin menghitung lagi
//
// Compile: g++ -o kalkulator src/main.cpp src/gauss_jordan.cpp
//                             src/input_handler.cpp -I include
// ============================================================

#include <iostream>
#include <iomanip>
#include "gauss_jordan.h"
#include "input_handler.h"

using namespace std;

// ============================================================
// tampilkanHeader: Cetak judul program ke layar
// ============================================================
void tampilkanHeader() {
    cout << "\n";
    cout << string(55, '=') << "\n";
    cout << "   KALKULATOR SISTEM PERSAMAAN LINIER\n";
    cout << "   Metode: Gauss-Jordan Elimination\n";
    cout << string(55, '=') << "\n";
}

// ============================================================
// tampilkanSistemPersamaan: Tampilkan ulang sistem Ax = b
// ============================================================
void tampilkanSistemPersamaan(const Matrix& A, const vector<double>& b, int n) {
    cout << "\n[INFO] Sistem persamaan yang dimasukkan:\n";
    cout << string(40, '-') << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Cetak koefisien dengan tanda + atau -
            if (j == 0) {
                cout << fixed << setprecision(2) << setw(7) << A[i][j];
            } else {
                // Tampilkan tanda + atau - sebelum koefisien
                if (A[i][j] >= 0)
                    cout << " + " << fixed << setprecision(2) << setw(6) << A[i][j];
                else
                    cout << " - " << fixed << setprecision(2) << setw(6) << -A[i][j];
            }
            cout << "*x" << j + 1;
        }
        cout << "  =  " << fixed << setprecision(2) << b[i] << "\n";
    }
    cout << string(40, '-') << "\n";
}

// ============================================================
// main: Fungsi utama program
// ============================================================
int main() {
    char ulang; // untuk tanya apakah mau hitung lagi

    do {
        tampilkanHeader();

        // ---- Langkah 1: Input dari pengguna ----
        int n = inputN();
        Matrix A = inputMatriksA(n);
        vector<double> b = inputVektorB(n);

        // ---- Langkah 2: Tampilkan sistem persamaan ----
        tampilkanSistemPersamaan(A, b, n);

        // ---- Langkah 3: Bentuk matriks augmented ----
        Matrix M = bentukAugmented(A, b);
        tampilkanMatriks(M, "[INFO] Matriks Augmented Awal [A|b]:");

        // ---- Langkah 4: Proses Gauss-Jordan ----
        cout << "\n\n";
        cout << string(55, '*') << "\n";
        cout << "        PROSES GAUSS-JORDAN ELIMINATION\n";
        cout << string(55, '*') << "\n";

        bool berhasil = gaussJordan(M);

        // ---- Langkah 5: Tampilkan hasil ----
        if (berhasil) {
            tampilkanSolusi(M);
        } else {
            cout << "\n";
            cout << string(50, '!') << "\n";
            cout << "  Sistem tidak memiliki solusi unik.\n";
            cout << "  Kemungkinan: infinitely many solutions\n";
            cout << "               atau no solution (inconsistent).\n";
            cout << string(50, '!') << "\n";
        }

        // ---- Tanya apakah ingin menghitung lagi ----
        cout << "\nHitung sistem lain? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih telah menggunakan program ini!\n\n";
    return 0;
}
