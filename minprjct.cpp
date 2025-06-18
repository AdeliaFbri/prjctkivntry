#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Item {
    string nama;
    int stok;
    int harga;
};

struct Pelanggan {
    string nama;
    int topUp;
};

vector<Item> inventory;
vector<Pelanggan> pelanggan;

void inisialisasiData() {
    inventory = {
        {"Diamond FF", 70, 9000},
        {"UC PUBG", 60, 14000},
        {"Diamond ML", 59, 15500}
    };

    pelanggan = {
        {"Arin", 155000},
        {"Adel", 140000},
        {"Aulia", 90000}
    };
}
void menampilkanInventory() {
    system("cls");
    cout << "Daftar Inventory:\n";
    cout << left << setw(5) << "No" << setw(15) << "Nama" << setw(10) << "Stok" << setw(10) << "Harga\n";
    for (int i = 0; i < inventory.size(); i++)
        cout << left << setw(5) << i << setw(15) << inventory[i].nama
             << setw(10) << inventory[i].stok << setw(10) << inventory[i].harga << endl;
    getch();
}
void menampilkanDataPelanggan() {
    system("cls");
    cout << "Data Pelanggan Top Up:\n";
    for (auto& p : pelanggan)
        cout << "- " << p.nama << " (Top Up: Rp " << p.topUp << ")\n";
    getch();
}
void jumlahData() {
    system("cls");
    int totalStok = 0, totalTopup = 0;
    for (auto& i : inventory) {
        totalStok += i.stok;
    }
    for (auto& p : pelanggan) {
        totalTopup += p.topUp;
    }

    cout << "Total stok seluruh item: " << totalStok << endl;
    cout << "Total nilai top up pelanggan: Rp " << totalTopup << endl;
    getch();
}

void dMenu() {
    system("cls");
    cout << "=== Aplikasi Inventory & Pelanggan Top Up ===\n";
    cout << "1. Inisialisasi Data\n";
    cout << "2. Tampilkan Inventory\n";
    cout << "3. Tampilkan Data Pelanggan\n";
    cout << "4. Total Semua Data\n";
    cout << "5. Exit\n";
    cout << "Masukkan angka: ";
}

int main() {
    char pilih;
    do {
        dMenu();
        pilih = getch();
        switch (pilih) {
            case '1': inisialisasiData(); 
            break;

            case '2': menampilkanInventory(); 
            break;

            case '3': menampilkanDataPelanggan(); 
            break;

            case '4': jumlahData(); 
            break;

            case '5': 
            break;
            
            default:
                system("cls");
                cout << "Pilihan tidak tersedia!";
                getch();
                break;
        }
 } while (pilih != '8');

    return 0;
}