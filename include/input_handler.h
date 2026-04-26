#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

// ============================================================
// input_handler.h
// Header untuk modul Input Handler
//
// Berisi deklarasi fungsi-fungsi untuk menerima input dari
// pengguna melalui terminal secara terstruktur dan aman.
// ============================================================

#include <vector>

using namespace std;

// Tipe data utama: matriks 2D berisi angka desimal
typedef vector<vector<double>> Matrix;

// ------------------------------------------------------------
// Fungsi: inputN
// Tujuan: Meminta pengguna memasukkan ukuran sistem (n)
//         dengan validasi (harus bilangan bulat positif)
// Return: nilai n yang valid
// ------------------------------------------------------------
int inputN();

// ------------------------------------------------------------
// Fungsi: inputMatriksA
// Tujuan: Meminta pengguna memasukkan matriks koefisien A
//         berukuran n x n, elemen per elemen
// Parameter:
//   - n : ukuran matriks
// Return: matriks A (n x n)
// ------------------------------------------------------------
Matrix inputMatriksA(int n);

// ------------------------------------------------------------
// Fungsi: inputVektorB
// Tujuan: Meminta pengguna memasukkan vektor hasil b
//         berukuran n x 1 (sisi kanan persamaan)
// Parameter:
//   - n : jumlah elemen
// Return: vektor b (panjang n)
// ------------------------------------------------------------
vector<double> inputVektorB(int n);

#endif // INPUT_HANDLER_H
