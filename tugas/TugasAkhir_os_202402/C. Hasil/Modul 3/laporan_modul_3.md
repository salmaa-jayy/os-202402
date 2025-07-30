# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi
**Semester**: Genap / Tahun Ajaran 2024–2025
**Nama**: `Salma Zaidah`
**NIM**: `240202884`
**Modul yang Dikerjakan**:
`Modul 3 – Manajemen Memori Tingkat Lanjut (xv6-public x86)`

---

## 📌 Deskripsi Singkat Tugas

Pada Modul 3 – Manajemen Memori Tingkat Lanjut, saya mengembangkan fitur Copy-on-Write Fork (CoW) dan Shared Memory ala System V pada kernel xv6-public.
1. Copy-on-Write (CoW)
*Fork tidak langsung menyalin semua memori.
*Halaman berbagi read-only dan disalin hanya jika ada proses yang melakukan write.
*Menggunakan reference count pada physical page.

2. Shared Memory
*Implementasi shmget(int key) dan shmrelease(int key) untuk berbagi halaman memori antar proses.
*Menggunakan reference count agar halaman dilepas hanya jika tidak ada proses yang menggunakan.

---

## 🛠️ Rincian Implementasi

*Menambahkan array ref_count[] pada vm.c untuk menghitung referensi tiap halaman fisik.
*Membuat flag PTE_COW di mmu.h untuk menandai halaman Copy-on-Write.
*Mengganti copyuvm() menjadi cowuvm() di vm.c agar fork menggunakan CoW.
*Memodifikasi trap() di trap.c untuk menangani page fault yang memerlukan penyalinan halaman.
*Menambahkan tabel shmtab[] untuk memetakan key ke halaman shared memory.
*Membuat syscall shmget() dan shmrelease() di sysproc.c, syscall.c, user.h, dan usys.S.
*Membuat dua program uji: cowtest.c dan shmtest.c untuk menguji fungsionalitas CoW dan Shared Memory.


---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

*cowtest → menguji Copy-on-Write pada fork().
*shmtest → menguji shared memory antar proses.

---

## 📷 Hasil Uji

Lampirkan hasil uji berupa screenshot atau output terminal. Contoh:

### 📍 Output `cowtest`:

```
Child sees: Y
Parent sees: X
```

### 📍 Output `shmtest`:

```
Child reads: A
Parent reads: B
```

Jika ada screenshot:

```
![hasil cowtest](./screenshots/cowtest_output.png)
```

---

## ⚠️ Kendala yang Dihadapi

*Pernah terjadi kernel panic karena salah mengatur reference count saat decref.
*Page fault tidak tertangani jika flag COW lupa ditambahkan → proses langsung mati.
*Shared memory tidak terlepas jika ada proses keluar tanpa memanggil shmrelease.

---

## 📚 Referensi

*Buku xv6 MIT: https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf
*Repositori xv6-public: https://github.com/mit-pdos/xv6-public
*Diskusi praktikum Sistem Operasi

---

