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

// Fungsi untuk menampilkan
void tampilkan_vektor(const vector<int>& vektor, const string& pesan) {
    cout << pesan << ": ";
    for (const auto& elem : vektor) {
        cout << elem << " ";
    }
    cout << endl;
}

// Fungsi untuk pertambahan dua vektor
vector<int> tambahVektor(const vector<int>& vektor1, const vector<int>& vektor2){
    /* A = [a1 a2]  ; B = [b1 b2] ; A + B = ?
    A + B = [a1+b1   a2+b2]
    A = [2  3]  ; B = [1  4]
    A + B = [2+1  3+4 ] = [3  7]
    */ 
    vector<int> hasil; 
    for (size_t i = 0; i < vektor1.size(); ++i){
        hasil.push_back(vektor1[i] + vektor2[i]);
    }
    return hasil;
}

// Fungsi untuk pengurangan dua vektor
vector<int> kurangVektor(const vector<int>& vektor1, const vector<int>& vektor2){
    /* A = [a1 a2]  ; B = [b1 b2] ; A - B = ?
    A - B = [a1-b1   a2-b2]
    A = [4  3]  ; B = [2  2]
    A - B = [4-2  3-2 ] = [2  1]
    */ 
    vector<int> hasil;
    for (size_t i = 0; i < vektor1.size(); ++i){
        hasil.push_back(vektor1[i] - vektor2[i]);
    }
    return hasil;
}

// Fungsi untuk perkalian dua vektor
vector<int> perkalianVektor(const vector<int>& vektor1, const vector<int>& vektor2){
    /* A = [a1 a2 a3]           | A = [1 2 2]
    B = [b1 b2 b3]              | B = [-3 -2 -1]
    A X B = C                   |
    C1 = [a2 * b3 - a3 * b2]    | C1 = [2 * (-1) - 2 * (-2)] 
    C2 = [a3 * b1 - a1 * b3]    | C2 = [2 * (-3) - 1 * (-1)]
    C3 = [a1 * b2 - a2 * b1]    | C3 = [1 * (-2) - 2 * (-3)]
    C  = [C1 C2 C3]             |  C = [ 2 -5 4]
    */
    vector<int> hasil;
    hasil.push_back(vektor1[1] * vektor2[2] - vektor1[2] * vektor2[1]);
    hasil.push_back(vektor1[2] * vektor2[0] - vektor1[0] * vektor2[2]);
    hasil.push_back(vektor1[0] * vektor2[1] - vektor1[1] * vektor2[0]);
    return hasil;

    return hasil;
}

// Fungsi untuk dot product dua vektor
int dot_product(const vector<int>& vektor1, const vector<int>& vektor2) {
    /* A = [a1 a2 a3]               | A = [1 2 3]
    B = [b1 b2 b3]                  | B = [4 5 6]
    A . B = a1*b1 + a2*b2 + a3*b3   | A . B = 1*4 + 2*5 + 3*6 = 32
    */
    int hasil = 0;
    for (size_t i = 0; i < vektor1.size(); ++i) {
        hasil += vektor1[i] * vektor2[i];
    }

    return hasil;
}

// Fungsi untuk transformasi elementer menggunakan skalar vektor
vector<int> transformasi_elemen(const vector<int>& vektor, function<int(int)> fungsi) {
    /* A = [a1 b1 c1]  ; skalar = k     | A = [2 3 1] ; k = 2
    Ak = [k*a1 k*a2 k*a3]               | Ak = [2*2 2*3 2*1] = [4 6 2]
    */ 
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
                    tampilkan_vektor(hasil, "Hasil Transformasi Elementer Vektor menggunakan skalar adalah ");
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
