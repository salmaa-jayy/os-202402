# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi
**Semester**: Genap / Tahun Ajaran 2024–2025
**Nama**: `Salma Zaidah`
**NIM**: `240202884`
**Modul yang Dikerjakan**:
`Modul 5 – Audit dan Keamanan Sistem (xv6-public)`

---

## 📌 Deskripsi Singkat Tugas

Pada Modul 5 – Audit dan Keamanan Sistem, saya menambahkan mekanisme Audit Log pada kernel xv6 dengan fitur:

*Merekam semua system call yang dipanggil beserta pid, nomor syscall, dan tick.
*Menyediakan syscall get_audit_log() untuk membaca log, hanya dapat diakses oleh proses dengan PID 1.
*Melindungi struktur log di kernel agar tidak bisa diakses langsung oleh proses user.

---

## 🛠️ Rincian Implementasi

*Menambahkan struktur audit_entry dan array audit_log[] di syscall.c untuk menyimpan log.
*Memodifikasi fungsi syscall() di syscall.c untuk mencatat setiap pemanggilan system call yang valid.
*Membuat syscall baru get_audit_log() di sysproc.c yang menyalin isi log ke buffer user jika pid == 1.
*Menambahkan deklarasi dan nomor syscall di syscall.h, user.h, usys.S, dan mendaftarkannya di syscall.c.
*Menambahkan program uji audit.c untuk menampilkan log dari user-space.
*Memastikan akses ke get_audit_log() dibatasi hanya untuk PID 1 (init process).

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

*audit → mencoba membaca audit log kernel.

---

## 📷 Hasil Uji

Lampirkan hasil uji berupa screenshot atau output terminal. Contoh:

### 📍 Contoh Output `audit`:

```
=== Audit Log ===
[0] PID=1 SYSCALL=7 TICK=1
[1] PID=1 SYSCALL=15 TICK=2
[2] PID=1 SYSCALL=17 TICK=2
[3] PID=1 SYSCALL=15 TICK=2
[4] PID=1 SYSCALL=10 TICK=2
[5] PID=1 SYSCALL=10 TICK=2
[6] PID=1 SYSCALL=7 TICK=2
[7] PID=1 SYSCALL=28 TICK=3

```

Jika ada screenshot:

```
![hasil cowtest](./screenshots/cowtest_output.png)
```

---

## ⚠️ Kendala yang Dihadapi

*Validasi PID di syscall get_audit_log() agar hanya proses init yang dapat mengakses log
*Penanganan pointer user-space menggunakan argptr() dan memmove()
*Menjaga proses init tetap hidup (menggunakan sleep() terus-menerus) agar kernel tidak panic

---

## 📚 Referensi

*Buku xv6 MIT: https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf
*Repositori xv6-public: https://github.com/mit-pdos/xv6-public
*Diskusi praktikum, GitHub Issues, Stack Overflow

---

