# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi
**Semester**: Genap / Tahun Ajaran 2024–2025
**Nama**: `Salma Zaidah`
**NIM**: `240202884`
**Modul yang Dikerjakan**:
`(Contoh: Modul 1 – System Call dan Instrumentasi Kernel)`

---

## 📌 Deskripsi Singkat Tugas

Pada Modul 2 – Penjadwalan CPU Lanjutan, saya mengubah algoritma penjadwalan proses pada kernel xv6-public dari Round Robin menjadi Non-Preemptive Priority Scheduling, dengan:

*Menambahkan field priority pada setiap proses di kernel
*Menambahkan syscall set_priority(int) untuk mengubah prioritas proses
*Memodifikasi scheduler agar selalu memilih proses RUNNABLE dengan prioritas tertinggi (angka prioritas paling kecil) 

---

## 🛠️ Rincian Implementasi

*Menambahkan field priority pada struct proc di proc.h
*Menginisialisasi priority default di fungsi allocproc() pada proc.c
*Membuat syscall set_priority(int) yang bisa dipanggil proses user:
-Tambahan di syscall.h, sysproc.c, syscall.c, user.h, usys.S
*Memodifikasi fungsi scheduler() di proc.c agar selalu memilih proses dengan prioritas paling tinggi
*Membuat program pengujian ptest.c untuk memvalidasi hasil

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:
*ptest → menguji penjadwalan berdasarkan prioritas
*Proses dengan prioritas angka kecil akan dieksekusi lebih dahulu
*Scheduler menjadi non-preemptive (tidak menginterupsi proses yang sedang berjalan)

---

## 📷 Hasil Uji

Lampirkan hasil uji berupa screenshot atau output terminal. Contoh:

### 📍 Contoh Output `ptest`:

```
Child 2 selesai
Child 1 selesai
Parent selesai
```
Jika ada screenshot:

```
![hasil cowtest](./screenshots/cowtest_output.png)
```

## ⚠️ Kendala yang Dihadapi

*Awalnya scheduler tetap menggunakan pola Round Robin karena lupa menghapus bagian perulangan for default xv6
*Proses dengan prioritas sama tidak memiliki mekanisme fair-sharing → perlu pengaturan manual
*Harus memastikan scheduler tetap non-preemptive, sehingga yield() tidak memotong proses

---

## 📚 Referensi

*Buku xv6 MIT: https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf
*Repositori xv6-public: https://github.com/mit-pdos/xv6-public
*Diskusi forum Sistem Operasi

---

