#include <iostream>
#include <string>
using namespace std;

const int MAX_SISWA = 50;
const int MAX_MAPEL = 20;

double hitungRataRata(double nilai[], int jumlahMapel) {
    double total = 0;
    for (int i = 0; i < jumlahMapel; i++) {
        total += nilai[i];
    }
    return total / jumlahMapel;
}

// Fungsi menentukan rangking berdasarkan rata-rata
void hitungRangking(double rata[], int rangking[], int jumlahSiswa) {
    for (int i = 0; i < jumlahSiswa; i++) {
        rangking[i] = 1;
        for (int j = 0; j < jumlahSiswa; j++) {
            if (rata[j] > rata[i]) {
                rangking[i]++;
            }
        }
    }
}

int main() {
    string namaKelas;
    int jumlahSiswa;
    string mapel[MAX_MAPEL];
    int jumlahMapel = 0;

    string namaSiswa[MAX_SISWA];
    double nilai[MAX_SISWA][MAX_MAPEL];
    double rata[MAX_SISWA];
    int rangking[MAX_SISWA];

    // 1. Display awal
    cout << "===============================" << endl;
    cout << "      Program Raport Siswa     " << endl;
    cout << "===============================" << endl;

    // 2. Input nama kelas
    cout << "Masukkan nama kelas: ";
    getline(cin, namaKelas);

    // 3. Input jumlah siswa
    cout << "Masukkan jumlah siswa: ";
    cin >> jumlahSiswa;
    cin.ignore();

   
    bool tambahMapel = true;
    while (tambahMapel) {
        cout << "Masukkan nama mapel ke-" << jumlahMapel + 1 << ": ";
        getline(cin, mapel[jumlahMapel]);
        jumlahMapel++;

        int pilihan;
        cout << "Tambah mapel lagi? (1 = ya, 0 = tidak): ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 0 || jumlahMapel == MAX_MAPEL) {
            tambahMapel = false;
        }
    }

    // 6 & 7. Looping siswa, input nama dan nilai tiap mapel
    for (int i = 0; i < jumlahSiswa; i++) {
        cout << "\n--- Siswa ke-" << i + 1 << " ---" << endl;
        cout << "Nama siswa: ";
        getline(cin, namaSiswa[i]);

        for (int j = 0; j < jumlahMapel; j++) {
            cout << "Nilai " << mapel[j] << ": ";
            cin >> nilai[i][j];

           
            while (nilai[i][j] < 0 || nilai[i][j] > 100) {
                cout << "Nilai tidak valid! Harus 0 - 100." << endl;
                cout << "Nilai " << mapel[j] << ": ";
                cin >> nilai[i][j];
            }
        }
        cin.ignore();

        
        rata[i] = hitungRataRata(nilai[i], jumlahMapel);
    }

    
    hitungRangking(rata, rangking, jumlahSiswa);

    
    cout << "\n===============================" << endl;
    cout << "Kelas: " << namaKelas << endl;
    cout << "===============================" << endl;

    for (int i = 0; i < jumlahSiswa; i++) {
        cout << "\nNama     : " << namaSiswa[i] << endl;
        for (int j = 0; j < jumlahMapel; j++) {
            cout << mapel[j] << " : " << nilai[i][j] << endl;
        }
        cout << "Rata-rata: " << rata[i] << endl;
        cout << "Rangking : " << rangking[i] << endl;
    }

    return 0;
}
