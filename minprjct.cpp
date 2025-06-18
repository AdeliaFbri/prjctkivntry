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

void tampilkanInventory() {
    system("cls");
    cout << "Daftar Inventory:\n";
    cout << left << setw(5) << "No" 
         << setw(20) << "Nama" 
         << setw(10) << "Stok" 
         << setw(10) << "Harga" << "\n";

    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << setw(5) << (i + 1) 
             << setw(20) << inventory[i].nama 
             << setw(10) << inventory[i].stok 
             << setw(10) << inventory[i].harga << "\n";
    }
    getch();
}

void menampilkanDataPelanggan() {
    system("cls");
    cout << "Data Pelanggan Top Up:\n";
    for (auto& p : pelanggan)
        cout << "- " << p.nama << " (Top Up: Rp " << p.topUp << ")\n";
    getch();
}

void menambahkanItem() {
    system("cls");
    Item ESP;
    cout << "Tambah Item:\n";
    cout << "Nama: "; cin >> ws; getline(cin, ESP.nama);
    cout << "Stok: "; cin >> ESP.stok;
    cout << "Harga: "; cin >> ESP.harga;
    inventory.push_back(ESP);
    cout << "Item berhasil ditambahkan!";
    getch();

    tampilkanInventory();
}

void jumlahData() {
    system("cls");
    int totalStok = 0, totalTopup = 0;
    for (auto& i : inventory) totalStok += i.stok;
    for (auto& p : pelanggan) totalTopup += p.topUp;

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
    cout << "4. Tambah Item\n";
    cout << "5. Total Semua Data\n";
    cout << "6. Exit\n";
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

            case '2': tampilkanInventory(); 
            break;

            case '3': menampilkanDataPelanggan(); 
            break;

            case '4': menambahkanItem(); 
            break;

            case '5': jumlahData(); 
            break;

            case '6': 
            break;

            default:
                system("cls");
                cout << "Pilihan tidak tersedia!";
                getch();
                break;
        }
    } while (pilih != '6');

    return 0;
}