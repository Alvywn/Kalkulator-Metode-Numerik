#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

// ============================================================
// gauss_jordan.h
// Header untuk modul Gauss-Jordan Elimination
//
// Berisi deklarasi fungsi-fungsi yang digunakan dalam proses:
//   - Membuat matriks augmented
//   - Menampilkan matriks (tiap tahap)
//   - Menukar baris (jika pivot = 0)
//   - Melakukan eliminasi Gauss-Jordan
//   - Membaca solusi akhir
// ============================================================

#include <vector>
#include <string>

using namespace std;

// Tipe data utama: matriks 2D berisi angka desimal
typedef vector<vector<double>> Matrix;

// ------------------------------------------------------------
// Fungsi: bentukAugmented
// Tujuan: Menggabungkan matriks A dan vektor b menjadi [A|b]
// Parameter:
//   - A : matriks koefisien (n x n)
//   - b : vektor hasil (n x 1)
// Return: matriks augmented (n x n+1)
// ------------------------------------------------------------
Matrix bentukAugmented(const Matrix& A, const vector<double>& b);

// ------------------------------------------------------------
// Fungsi: tampilkanMatriks
// Tujuan: Mencetak matriks augmented ke layar dengan rapi
// Parameter:
//   - M     : matriks yang akan ditampilkan
//   - label : judul/keterangan yang ditampilkan di atas matriks
// ------------------------------------------------------------
void tampilkanMatriks(const Matrix& M, const string& label);

// ------------------------------------------------------------
// Fungsi: tukarBaris
// Tujuan: Menukar dua baris dalam matriks (jika pivot = 0)
// Parameter:
//   - M  : matriks yang akan dimodifikasi
//   - r1 : indeks baris pertama
//   - r2 : indeks baris kedua
// ------------------------------------------------------------
void tukarBaris(Matrix& M, int r1, int r2);

// ------------------------------------------------------------
// Fungsi: gaussJordan
// Tujuan: Melakukan eliminasi Gauss-Jordan pada matriks augmented
//         Menampilkan proses tiap tahap ke layar
// Parameter:
//   - M : matriks augmented [A|b], akan dimodifikasi langsung
// Return:
//   - true  : jika sistem memiliki solusi unik
//   - false : jika sistem tidak memiliki solusi unik
//             (tak hingga solusi atau tidak konsisten)
// ------------------------------------------------------------
bool gaussJordan(Matrix& M);

// ------------------------------------------------------------
// Fungsi: tampilkanSolusi
// Tujuan: Membaca dan mencetak solusi akhir dari matriks
//         yang sudah dalam bentuk reduced row echelon form
// Parameter:
//   - M : matriks augmented setelah proses Gauss-Jordan
// ------------------------------------------------------------
void tampilkanSolusi(const Matrix& M);

#endif // GAUSS_JORDAN_H
