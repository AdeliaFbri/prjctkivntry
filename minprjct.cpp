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
