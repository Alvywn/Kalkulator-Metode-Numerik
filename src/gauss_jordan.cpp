// ============================================================
// gauss_jordan.cpp
// Implementasi algoritma Gauss-Jordan Elimination
//
// Proses:
//   1. Bentuk matriks augmented [A|b]
//   2. Forward elimination (pivot di diagonal)
//   3. Backward substitution (sudah terintegrasi di Gauss-Jordan)
//   4. Normalisasi baris pivot
//   5. Eliminasi semua baris lain (bukan hanya bawah pivot)
// ============================================================

#include "../include/gauss_jordan.h"
#include <iostream>
#include <iomanip>   // setw, setprecision, fixed
#include <cmath>     // fabs (nilai absolut)

using namespace std;

// Konstanta toleransi untuk deteksi nilai nol
// (menghindari masalah floating point)
const double EPSILON = 1e-9;

// ============================================================
// bentukAugmented: Gabungkan A dan b menjadi [A|b]
// ============================================================
Matrix bentukAugmented(const Matrix& A, const vector<double>& b) {
    int n = A.size();
    Matrix M(n, vector<double>(n + 1)); // n baris, n+1 kolom

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = A[i][j]; // salin koefisien
        }
        M[i][n] = b[i]; // kolom terakhir = vektor b
    }
    return M;
}

// ============================================================
// tampilkanMatriks: Cetak matriks ke layar dengan format rapi
// ============================================================
void tampilkanMatriks(const Matrix& M, const string& label) {
    int n = M.size();
    int cols = M[0].size();

    cout << "\n" << label << "\n";
    cout << string(50, '-') << "\n";

    for (int i = 0; i < n; i++) {
        cout << "| ";
        for (int j = 0; j < cols; j++) {
            // Jika ini kolom pemisah (sebelum kolom terakhir augmented)
            if (j == cols - 1) {
                cout << "| "; // garis pemisah augmented
            }
            // Cetak angka: lebar 10, 4 desimal, rata kanan
            cout << fixed << setprecision(4) << setw(10) << M[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << string(50, '-') << "\n";
}

// ============================================================
// tukarBaris: Tukar dua baris dalam matriks
// ============================================================
void tukarBaris(Matrix& M, int r1, int r2) {
    swap(M[r1], M[r2]); // fungsi swap dari STL
}

// ============================================================
// gaussJordan: Lakukan eliminasi Gauss-Jordan
// Mengembalikan true jika solusi unik, false jika tidak
// ============================================================
bool gaussJordan(Matrix& M) {
    int n = M.size();
    int tahap = 1; // penomoran tahap untuk tampilan

    for (int col = 0; col < n; col++) {
        // ---- LANGKAH 1: Cari pivot (elemen non-nol di kolom col) ----
        int pivotBaris = -1;
        for (int row = col; row < n; row++) {
            if (fabs(M[row][col]) > EPSILON) {
                pivotBaris = row;
                break;
            }
        }

        // Jika tidak ada pivot: sistem tidak memiliki solusi unik
        if (pivotBaris == -1) {
            cout << "\n[!] Kolom " << col + 1 << " tidak memiliki pivot!\n";
            cout << "    Sistem tidak memiliki solusi unik.\n";
            return false;
        }

        // ---- LANGKAH 2: Tukar baris jika pivot bukan di baris saat ini ----
        if (pivotBaris != col) {
            cout << "\n>>> Tahap " << tahap++ << ": Tukar baris "
                 << col + 1 << " dengan baris " << pivotBaris + 1 << "\n";
            tukarBaris(M, col, pivotBaris);
            tampilkanMatriks(M, "Setelah penukaran baris:");
        }

        // ---- LANGKAH 3: Normalisasi baris pivot (bagi dengan nilai pivot) ----
        double pivot = M[col][col];
        cout << "\n>>> Tahap " << tahap++ << ": Normalisasi baris " << col + 1
             << " (bagi dengan " << fixed << setprecision(4) << pivot << ")\n";

        for (int j = 0; j <= n; j++) {
            M[col][j] /= pivot; // setiap elemen dibagi nilai pivot
        }
        tampilkanMatriks(M, "Setelah normalisasi:");

        // ---- LANGKAH 4: Eliminasi semua baris lain di kolom ini ----
        for (int row = 0; row < n; row++) {
            if (row == col) continue; // lewati baris pivot itu sendiri

            double faktor = M[row][col]; // faktor pengali

            // Hanya proses jika elemen belum nol
            if (fabs(faktor) > EPSILON) {
                cout << "\n>>> Tahap " << tahap++ << ": Eliminasi baris " << row + 1
                     << " (kurangi dengan " << fixed << setprecision(4)
                     << faktor << " x baris " << col + 1 << ")\n";

                for (int j = 0; j <= n; j++) {
                    M[row][j] -= faktor * M[col][j];
                }
                tampilkanMatriks(M, "Setelah eliminasi:");
            }
        }
    }

    return true; // berhasil, solusi unik
}

// ============================================================
// tampilkanSolusi: Baca dan cetak solusi dari matriks RREF
// ============================================================
void tampilkanSolusi(const Matrix& M) {
    int n = M.size();

    cout << "\n";
    cout << string(50, '=') << "\n";
    cout << "              SOLUSI AKHIR\n";
    cout << string(50, '=') << "\n";

    for (int i = 0; i < n; i++) {
        // Solusi xi ada di kolom terakhir (indeks n)
        cout << "  x" << i + 1 << " = "
             << fixed << setprecision(6) << M[i][n] << "\n";
    }

    cout << string(50, '=') << "\n";
}
