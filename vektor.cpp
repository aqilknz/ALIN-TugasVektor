#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Fungsi untuk menginput
void inputVektor(vector<int>& vektor, const string& vektorName){
    cout << "Masukkan elemen " << vektorName << ":" << endl;
    for (size_t i = 0; i < vektor.size(); ++i){
        cout << "Elemen " << i + 1 << ": ";
        cin >> vektor[i];
    }
}

// Fungsi untuk menampilakan
void tampilkan_vektor(const vector<int>& vektor, const string& pesan) {
    cout << pesan << ": ";
    for (const auto& elem : vektor) {
        cout << elem << " ";
    }
    cout << endl;
}

// Fungsi untuk pertambahan dua vektor
vector<int> tambahVektor(const vector<int>& vektor1, const vector<int>& vektor2){
    vector<int> hasil;
    for (size_t i = 0; i < vektor1.size(); ++i){
        hasil.push_back(vektor1[i] + vektor2[i]);
    }
    return hasil;
}

// Fungsi untuk pengurangan dua vektor
vector<int> kurangVektor(const vector<int>& vektor1, const vector<int>& vektor2){
    vector<int> hasil;
    for (size_t i = 0; i < vektor1.size(); ++i){
        hasil.push_back(vektor1[i] - vektor2[i]);
    }
    return hasil;
}

// Fungsi untuk perkalian dua vektor
vector<int> perkalianVektor(const vector<int>& vektor1, const vector<int>& vektor2){
    vector<int> hasil;
    for (size_t i = 0; i < vektor1.size(); ++i){
        hasil.push_back(vektor1[i] * vektor2[i]);
    }
    return hasil;
}

// Fungsi untuk dot product dua vektor
int dot_product(const vector<int>& vektor1, const vector<int>& vektor2) {

    int hasil = 0;
    for (size_t i = 0; i < vektor1.size(); ++i) {
        hasil += vektor1[i] * vektor2[i];
    }

    return hasil;
}

// Fungsi untuk transformasi elementer menggunakan skalar vektor
vector<int> transformasi_elemen(const vector<int>& vektor, function<int(int)> fungsi) {
    vector<int> hasil;
    for (const auto& elem : vektor) {
        hasil.push_back(fungsi(elem));
    }
    return hasil;
}

int main() {

    do {
        int pilihan;

        //menu
        cout << "Pilih operasi:\n";
        cout << "1. Penjumlahan Vektor\n";
        cout << "2. Pengurangan Vektor\n";
        cout << "3. Perkalian Vektor\n";
        cout << "4. Dot Product Vektor\n";
        cout << "5. Transformasi Elementer Vektor\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        int panjang;
        cout << "Masukkan panjang elemen: ";
        cin >> panjang;
        vector<int> vektor1(panjang);
        vector<int> vektor2(panjang);

        switch (pilihan){
            case 1:
                inputVektor(vektor1, "Vektor A");
                inputVektor(vektor2, "Vektor B");
                tampilkan_vektor(vektor1, "Vektor A");
                tampilkan_vektor(vektor2, "Vektor B");
                {
                    vector<int> hasil = tambahVektor(vektor1,vektor2);
                    tampilkan_vektor(hasil, "Hasil Penjumlahan Vektor");
                }
                break;
            case 2:
                inputVektor(vektor1, "Vektor A");
                inputVektor(vektor2, "Vektor B");
                tampilkan_vektor(vektor1, "Vektor A");
                tampilkan_vektor(vektor2, "Vektor B");
                {
                    vector<int> hasil = kurangVektor(vektor1,vektor2);
                    tampilkan_vektor(hasil, "Hasil Pengurangan Vektor");
                }
                break;
            case 3:
                inputVektor(vektor1, "Vektor A");
                inputVektor(vektor2, "Vektor B");
                tampilkan_vektor(vektor1, "Vektor A");
                tampilkan_vektor(vektor2, "Vektor B");
                {
                    vector<int> hasil = perkalianVektor(vektor1,vektor2);
                    tampilkan_vektor(hasil, "Hasil Perkalian Vektor");
                }
                break;
            case 4:
                inputVektor(vektor1, "Vektor A");
                inputVektor(vektor2, "Vektor B");
                tampilkan_vektor(vektor1, "Vektor A");
                tampilkan_vektor(vektor2, "Vektor B");
                {
                    int hasil = dot_product(vektor1,vektor2);
                    cout << "Hasil Dot Product: " << hasil << endl;
                }
                break;
            case 5:
                inputVektor(vektor1, "Vektor A");
                tampilkan_vektor(vektor1, "Vektor A");
                {
                    int skalar;
                    cout << "Masukkan skalar untuk transformasi elementer: ";
                    cin >> skalar;
                    auto fungsiTransformasi = [skalar](int elem) {return elem * skalar;};
                    vector<int> hasil = transformasi_elemen(vektor1,fungsiTransformasi);
                    tampilkan_vektor(hasil, "Hasil Penjumlahan Vektor");
                }
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        } char lanjut;
        cout << "Ingin menghitung lagi (Y/N)?: ";
        cin >> lanjut;
        if (lanjut != 'y' && lanjut != 'Y'){
            break;
        }
    } while (true);
    return 0;
}
