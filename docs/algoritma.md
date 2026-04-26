# Dokumentasi Algoritma Gauss-Jordan

## 1. Pengertian

**Gauss-Jordan Elimination** adalah metode aljabar linier untuk menyelesaikan sistem persamaan linier (SPL) berbentuk **Ax = b**, di mana:

- **A** = matriks koefisien (n × n)
- **x** = vektor variabel yang dicari (n × 1)
- **b** = vektor hasil / sisi kanan (n × 1)

Metode ini merupakan perluasan dari eliminasi Gauss, dengan tambahan langkah eliminasi ke arah atas sehingga menghasilkan **matriks identitas** pada sisi kiri.

---

## 2. Langkah-Langkah Algoritma

### Langkah 0 – Bentuk Matriks Augmented

Gabungkan matriks A dan vektor b menjadi satu matriks augmented **[A|b]**:

```
[ a11  a12  a13 | b1 ]
[ a21  a22  a23 | b2 ]
[ a31  a32  a33 | b3 ]
```

### Langkah 1 – Pilih Pivot

Untuk setiap kolom `col` (dari kiri ke kanan):
- Cari baris dengan elemen non-nol di kolom tersebut (mulai dari baris `col`)
- Jika tidak ada pivot → sistem **tidak memiliki solusi unik**

### Langkah 2 – Tukar Baris (jika perlu)

Jika elemen pivot bukan pada baris `col`, tukar baris:
```
Baris[col] ↔ Baris[pivotBaris]
```

### Langkah 3 – Normalisasi Baris Pivot

Bagi seluruh elemen di baris pivot dengan nilai pivot:
```
Baris[col] = Baris[col] / M[col][col]
```
Sehingga elemen pivot menjadi **1**.

### Langkah 4 – Eliminasi Semua Baris Lain

Untuk setiap baris lain (bukan baris pivot):
```
faktor = M[row][col]
Baris[row] = Baris[row] - faktor × Baris[col]
```
Sehingga semua elemen di kolom `col` (selain pivot) menjadi **0**.

### Langkah 5 – Ulangi

Ulangi Langkah 1–4 untuk semua kolom. Setelah selesai, matriks kiri menjadi **matriks identitas**, dan kolom kanan berisi **solusi x**.

---

## 3. Kondisi Khusus

| Kondisi | Keterangan |
|--------|-----------|
| Pivot = 0 (bisa ditukar) | Tukar dengan baris di bawahnya |
| Tidak ada pivot di kolom | Sistem tidak memiliki solusi unik |
| Sistem konsisten + rank penuh | Solusi unik |
| Sistem konsisten + rank tidak penuh | Infinitely many solutions |
| Sistem tidak konsisten | No solution |

---

## 4. Contoh Manual (3×3)

### Soal
```
 2x1 +  x2 -  x3 =  8
-3x1 -  x2 + 2x3 = -11
-2x1 +  x2 + 2x3 = -3
```

### Matriks Augmented Awal
```
[  2   1  -1 |   8 ]
[ -3  -1   2 | -11 ]
[ -2   1   2 |  -3 ]
```

### Setelah Normalisasi Baris 1 (÷2)
```
[  1  0.5 -0.5 |  4 ]
[ -3  -1    2  | -11]
[ -2   1    2  | -3 ]
```

### Setelah Eliminasi Kolom 1
```
[  1  0.5  -0.5 |  4  ]
[  0  0.5   0.5 |  1  ]
[  0  2     1   |  5  ]
```

### (dst...)

### Solusi Akhir
```
x1 = 2,  x2 = 3,  x3 = -1
```

---

## 5. Kompleksitas Algoritma

- **Waktu**: O(n³) — loop tiga tingkat (kolom, baris, elemen)
- **Ruang**: O(n²) — matriks augmented berukuran n × (n+1)

---

## 6. Referensi

- Golub, G.H., Van Loan, C.F. *Matrix Computations*, 4th ed.
- Chapra, S.C. *Numerical Methods for Engineers*, 7th ed.
- Lay, D.C. *Linear Algebra and Its Applications*, 5th ed.
