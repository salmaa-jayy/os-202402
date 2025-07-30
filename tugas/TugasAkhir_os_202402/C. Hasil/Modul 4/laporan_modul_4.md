# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi
**Semester**: Genap / Tahun Ajaran 2024–2025
**Nama**: `Salma Zaidah`
**NIM**: `240202884`
**Modul yang Dikerjakan**:
`Modul 4 – Subsistem Kernel Alternatif (xv6-public)`

---

## 📌 Deskripsi Singkat Tugas

Pada Modul 4 – Subsistem Kernel Alternatif, saya menambahkan dua fitur baru pada kernel xv6-public:

1. System Call chmod(path, mode)
*Memungkinkan pengaturan mode file menjadi read-only atau read-write.
*Jika mode read-only diaktifkan, semua operasi tulis akan ditolak.
2. Pseudo-device /dev/random
*Menyediakan generator angka acak sederhana yang bisa dibaca oleh user melalui file device.


---

## 🛠️ Rincian Implementasi

*Menambahkan field mode pada struct inode di fs.h untuk menyimpan status mode file.
*Membuat syscall baru chmod(path, mode) di sysfile.c dan mendaftarkannya pada syscall.c, syscall.h, user.h, dan usys.S.
*Menambahkan validasi mode pada filewrite() di file.c agar file read-only tidak bisa ditulis.
*Membuat file baru random.c untuk driver pseudo-device /dev/random yang menghasilkan byte acak.
*Mendaftarkan device pada devsw[] di file.c dan membuat node /dev/random di init.c menggunakan mknod().
*Menambahkan dua program uji: chmodtest.c dan randomtest.c.

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

*chmodtest → menguji perlindungan file read-only.
*randomtest → membaca byte acak dari /dev/random.

---

## 📷 Hasil Uji

### 📍 Output `chmodtest`:

```
Write blocked as expected
```

### 📍 Output `randomtest`:

```
19 45 232 11 89 77 254 1
```

Jika ada screenshot:


<img width="540" height="318" alt="Modul 4" src="https://github.com/user-attachments/assets/44c1b4fa-7cc5-40bf-b14d-e4d0bb9d92c5" />


## ⚠️ Kendala yang Dihadapi

*Sempat salah menambahkan mode di inode sehingga bentrok dengan disk layout awal xv6. Akhirnya field hanya digunakan di memori.
*Lupa memanggil mknod("/dev/random") sehingga device tidak terdeteksi.

---

## 📚 Referensi

*Buku xv6 MIT: https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf

*Repositori xv6-public: https://github.com/mit-pdos/xv6-publicm

---

