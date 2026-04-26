# Kalkulator Sistem Persamaan Linier
## Metode Gauss-Jordan Elimination

> Program C++ untuk menyelesaikan Sistem Persamaan Linier (SPL) menggunakan metode eliminasi Gauss-Jordan, lengkap dengan tampilan proses tiap tahap.

---

## Daftar Isi

1. [Deskripsi Program](#deskripsi-program)
2. [Struktur Folder](#struktur-folder)
3. [Cara Compile](#cara-compile)
4. [Cara Menjalankan](#cara-menjalankan)
5. [Contoh Input & Output](#contoh-input--output)
6. [Penjelasan Singkat Algoritma](#penjelasan-singkat-algoritma)
7. [Anggota Kelompok](#anggota-kelompok)

---

## Deskripsi Program

Program ini menyelesaikan sistem persamaan linier berbentuk **Ax = b** dengan:
- **Input**: ukuran sistem (n), matriks koefisien A, vektor hasil b
- **Proses**: eliminasi Gauss-Jordan dengan tampilan tahap demi tahap
- **Output**: solusi variabel x₁, x₂, ..., xₙ atau pesan jika sistem tidak memiliki solusi unik

### Fitur Utama
- Pengecekan dan penukaran baris otomatis jika pivot = 0
- Tampilan matriks augmented setiap tahap
- Deteksi sistem yang tidak memiliki solusi unik
- Format output yang rapi menggunakan `<iomanip>`

---

## Struktur Folder

```
gauss-jordan-calculator/
├── src/
│   ├── main.cpp           ← Program utama (alur program)
│   ├── gauss_jordan.cpp   ← Implementasi algoritma
│   └── input_handler.cpp  ← Fungsi input dari pengguna
├── include/
│   ├── gauss_jordan.h     ← Header deklarasi algoritma
│   └── input_handler.h    ← Header deklarasi input
├── data/
│   └── sample_input.txt   ← Contoh data input
├── docs/
│   ├── algoritma.md       ← Dokumentasi algoritma lengkap
│   └── flowchart.png      ← Diagram alur program
├── tests/
│   └── test_case_1.txt    ← Kasus uji beserta solusi
├── README.md              ← File ini
└── Makefile               ← Script untuk kompilasi
```

---

## Cara Compile

### Menggunakan Makefile (Disarankan)
```bash
# Masuk ke folder project
cd gauss-jordan-calculator

# Compile program
make

# Atau compile + langsung jalankan
make run

# Hapus file binary
make clean
```

### Menggunakan g++ Manual
```bash
g++ -Wall -std=c++11 -I include \
    src/main.cpp src/gauss_jordan.cpp src/input_handler.cpp \
    -o kalkulator
```

**Persyaratan**: compiler `g++` dengan dukungan C++11 atau lebih baru.

---

## Cara Menjalankan

```bash
./kalkulator
```

Program akan meminta input secara interaktif:
1. Masukkan nilai `n` (jumlah persamaan/variabel)
2. Masukkan elemen matriks A satu per satu
3. Masukkan elemen vektor b satu per satu
4. Program otomatis menampilkan proses dan solusi

---

## Contoh Input & Output

### Input
```
n = 3

Matriks A:
  A[1][1] = 2    A[1][2] = 1    A[1][3] = -1
  A[2][1] = -3   A[2][2] = -1   A[2][3] = 2
  A[3][1] = -2   A[3][2] = 1    A[3][3] = 2

Vektor b:
  b[1] = 8
  b[2] = -11
  b[3] = -3
```

### Output
```
=======================================================
KALKULATOR SISTEM PERSAMAAN LINIER
Metode: Gauss-Jordan Elimination
=======================================================

...

[INFO] Matriks Augmented Awal [A|b]:
--------------------------------------------------
|     2.0000      1.0000     -1.0000 |      8.0000 |
|    -3.0000     -1.0000      2.0000 |    -11.0000 |
|    -2.0000      1.0000      2.0000 |     -3.0000 |
--------------------------------------------------

...

==================================================
              SOLUSI AKHIR
==================================================
  x1 = 2.000000
  x2 = 3.000000
  x3 = -1.000000
==================================================
```

---

## Penjelasan Singkat Algoritma

1. **Bentuk matriks augmented** `[A|b]`
2. **Untuk setiap kolom** (dari kiri ke kanan):
   - Temukan baris pivot (elemen non-nol)
   - Tukar baris jika pivot bukan di posisi diagonal
   - Normalisasi baris pivot (bagi hingga pivot = 1)
   - Eliminasi semua baris lain di kolom tersebut
3. **Baca solusi** dari kolom terakhir matriks

Penjelasan lengkap ada di `docs/algoritma.md`.

---

## Anggota Kelompok

| No | Nama | NIM |
|----|------|-----|
| 1  | ...  | ... |
| 2  | ...  | ... |
| 3  | ...  | ... |

**Mata Kuliah**: Metode Numerik / Aljabar Linier  
**Semester**: ...  
**Dosen**: ...

---

*Dibuat sebagai tugas project akhir. Semua kode ditulis dan dipahami sendiri oleh kelompok.*
