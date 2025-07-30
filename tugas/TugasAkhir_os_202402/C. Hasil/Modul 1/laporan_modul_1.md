# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi
**Semester**: Genap / Tahun Ajaran 2024–2025
**Nama**: `Salma Zaidah`
**NIM**: `240202884`
**Modul yang Dikerjakan**:
`(Contoh: Modul 1 – System Call dan Instrumentasi Kernel)`

---

## 📌 Deskripsi Singkat Tugas

Pada Modul 1 – System Call dan Instrumentasi Kernel, saya menambahkan dua system call baru pada kernel xv6-public:

*getpinfo(struct pinfo *ptable) → Mengembalikan informasi proses aktif (PID, size memory, dan nama proses).

*getReadCount() → Mengembalikan jumlah pemanggilan read() yang dilakukan sejak sistem boot.

---

## 🛠️ Rincian Implementasi
* Menambahkan dua system call baru di file sysproc.c dan syscall.c.
* Mengedit user.h, usys.S, dan syscall.h untuk mendaftarkan syscall.
* Menambahkan struktur struct pinfo pada proc.h untuk menyimpan data proses.
* Menambahkan variabel counter readcount di kernel untuk menghitung      pemanggilan read().
* Membuat dua program uji: ptest.c (untuk getpinfo) dan rtest.c (untuk getReadCount).
---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

*ptest → untuk menguji getpinfo()
*rtest → untuk menguji getReadCount()
*cowtest → untuk menguji fork dengan Copy-on-Write
*shmtest → untuk menguji shmget() dan shmrelease()
*chmodtest → untuk memastikan file read-only tidak dapat ditulis

---

## 📷 Hasil Uji

Lampirkan hasil uji berupa screenshot atau output terminal. Contoh:

### 📍 Contoh Output `ptest`:

```
PID     MEM     NAME
1       12288   init
2       16384   sh
3       12288   ptest
```

### 📍 Contoh Output `rtest`:

```
Read Count Sebelum: 12
hello
Read Count Setelah: 13
```

Jika ada screenshot:

```
![hasil cowtest](./screenshots/cowtest_output.png)
```

---

## ⚠️ Kendala yang Dihadapi

*Sempat terjadi invalid page fault karena kesalahan pemetaan pointer ke struct pinfo pada fungsi sys_getpinfo.
*Lupa menambahkan syscall baru di usys.S, sehingga terjadi error undefined reference.
*Salah mengunci (lock) ptable menyebabkan data proses tidak konsisten.

---

## 📚 Referensi

*Buku xv6 MIT: https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf
*Repositori xv6-public: https://github.com/mit-pdos/xv6-public
*Diskusi forum dan dokumentasi praktikum Sistem Operasi

---

