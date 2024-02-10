#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 100

char namaMahasiswa[MAX_MAHASISWA][50];
char nimMahasiswa[MAX_MAHASISWA][15];
char semesterMahasiswa[MAX_MAHASISWA][20];
int usiaMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void tambahMahasiswa() {
    char nama[50];
    char nim[15];
    char semester[20];
    int usia;
    
    printf("Masukkan Nama Mahasiswa: ");
    scanf("%s", nama);
    
    printf("Masukkan NIM Mahasiswa: ");
    scanf("%s", nim);
    
    printf("Masukkan Usia Mahasiswa: ");
    scanf("%d", &usia);

    printf("Masukkan Semester Mahasiswa: ");
    scanf("%s", semester);
    
    strcpy(namaMahasiswa[jumlahMahasiswa], nama);
    strcpy(nimMahasiswa[jumlahMahasiswa], nim);
    strcpy(semesterMahasiswa[jumlahMahasiswa], semester);
    usiaMahasiswa[jumlahMahasiswa] = usia;
    
    jumlahMahasiswa++;
    
    printf("Mahasiswa berhasil ditambahkan!\n");
}

void tampilkanMahasiswa() {
    if (jumlahMahasiswa == 0) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }
    
    // Mengurutkan data mahasiswa berdasarkan NIM dan semester menggunakan bubble sort
    for (int i = 0; i < jumlahMahasiswa - 1; i++) {
        for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
            if (strcmp(nimMahasiswa[j], nimMahasiswa[j+1]) > 0) {
                // Tukar posisi data mahasiswa
                char temp[50];
                strcpy(temp, namaMahasiswa[j]);
                strcpy(namaMahasiswa[j], namaMahasiswa[j+1]);
                strcpy(namaMahasiswa[j+1], temp);
                
                strcpy(temp, nimMahasiswa[j]);
                strcpy(nimMahasiswa[j], nimMahasiswa[j+1]);
                strcpy(nimMahasiswa[j+1], temp);
                
                strcpy(temp, semesterMahasiswa[j]);
                strcpy(semesterMahasiswa[j], semesterMahasiswa[j+1]);
                strcpy(semesterMahasiswa[j+1], temp);
                
                int tempUsia = usiaMahasiswa[j];
                usiaMahasiswa[j] = usiaMahasiswa[j+1];
                usiaMahasiswa[j+1] = tempUsia;
            } else if (strcmp(nimMahasiswa[j], nimMahasiswa[j+1]) == 0) {
                if (strcmp(semesterMahasiswa[j], semesterMahasiswa[j+1]) > 0) {
                    // Tukar posisi data mahasiswa
                    char temp[50];
                    strcpy(temp, namaMahasiswa[j]);
                    strcpy(namaMahasiswa[j], namaMahasiswa[j+1]);
                    strcpy(namaMahasiswa[j+1], temp);
                
                    strcpy(temp, nimMahasiswa[j]);
                    strcpy(nimMahasiswa[j], nimMahasiswa[j+1]);
                    strcpy(nimMahasiswa[j+1], temp);
                
                    strcpy(temp, semesterMahasiswa[j]);
                    strcpy(semesterMahasiswa[j], semesterMahasiswa[j+1]);
                    strcpy(semesterMahasiswa[j+1], temp);
                
                    int tempUsia = usiaMahasiswa[j];
                    usiaMahasiswa[j] = usiaMahasiswa[j+1];
                    usiaMahasiswa[j+1] = tempUsia;
                }
            }
        }
    }
    
    printf("Data Mahasiswa:\n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("Nama: %s\n", namaMahasiswa[i]);
        printf("NIM: %s\n", nimMahasiswa[i]);
        printf("Usia: %d\n", usiaMahasiswa[i]);
        printf("Semester: %s\n", semesterMahasiswa[i]);
        printf("------------------------\n");
    }
}

int main() {
    int pilihan;
    
    do {
        printf("========== Sistem Pendataan Mahasiswa ==========\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("0. Keluar\n");
        printf("PilihanAnda: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                tampilkanMahasiswa();
                break;
            case 0:
                printf("Terima kasih, program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
        
        printf("\n");
    } while (pilihan != 0);
    
    return 0;
}