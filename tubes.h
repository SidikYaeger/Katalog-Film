#include <iostream>
#include "tubes.h"
using namespace std;

int main()
{
    //kamus----------------------
    tree t;
    createTree(t);
    adrNode root;
    film inputFilm;
    string n = "y";
    adrNode cari;
    adrNode findjudul = nullptr;
    insertDummyData(t);

    int pilihan = -1;
    //---------------------------
    while (pilihan != 0) {
        menu();
        cin >> pilihan;
        clearScreen();
        switch (pilihan) {
            {
                if (t.root == nullptr) {
                    cout << "Tree kosong." << endl;
                } else {
                    string judulTarget, genreTarget;
                    cout << "\n--- Hapus Genre Film ---" << endl;
                    cout << "Masukkan Judul Film: ";
                    cin >> judulTarget;
                    cout << "Masukkan Genre yang akan dihapus: ";
                    cin >> genreTarget;
                    hapusGenreFilm(t.root, judulTarget, genreTarget);
                }
            }
            break;
        case 1:
            {string pilihOpsi = "y";
            while (pilihOpsi == "y") {
                cout << "\n==================== INPUT DATA ====================\n";
                cout << "Judul Film    : ";
                cin >> inputFilm.judul;
                cari = cek(t.root, inputFilm.judul);

                if (cari != nullptr){
                    cout << "Judul Film Harus Unik" << endl;
                } else {
                    cout << "Tahun Rilis   : ";
                    cin >> inputFilm.tahun;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nHarap Input angka!\n";
                        cout << "\nTekan Enter 2 kali untuk melanjutkan"; cin.ignore(); cin.get();
                        clearScreen();
                        cout << "Judul Film    : " << inputFilm.judul << endl;
                        cout << "Tahun Rilis   : ";
                        cin >> inputFilm.tahun;
                    }
                    cout << "Rating (1-10) : ";
                    cin >> inputFilm.rating;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nHarap Input angka!\n";
                        cout << "\nTekan Enter 2 kali untuk melanjutkan"; cin.ignore(); cin.get();
                        clearScreen();
                        cout << "Judul Film    : " << inputFilm.judul << endl;
                        cout << "Tahun Rilis   : " << inputFilm.tahun << endl;
                        cout << "Rating (1-10)  : ";
                        cin >> inputFilm.rating;
                    }
                    cout << "Jumlah Genre  : ";
                    cin >> inputFilm.genreCount;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\nHarap Input angka!\n";
                        cout << "\nTekan Enter 2 kali untuk melanjutkan"; cin.ignore(); cin.get();
                        clearScreen();
                        cout << "Judul Film    : " << inputFilm.judul << endl;
                        cout << "Tahun Rilis   : " << inputFilm.tahun << endl;
                        cout << "Rating (1-0)  : " << inputFilm.rating << endl;
                        cout << "Jumlah Genre  : ";
                        cin >> inputFilm.genreCount;
                    }

                    for (int i = 0; i < inputFilm.genreCount; i++){
                        cout << "Genre " << i + 1 << ": ";
                        cin >> inputFilm.genre[i];
                    }
                    insertNode(t.root, inputFilm);
                    cout << "Sukses menyimpan data" << endl;

                    cout << "Ingin menginput data lagi (y/n)? ";
                    cin >> pilihOpsi;
                    clearScreen();
                }
            }
            break;
            }
        case 2:
            if (t.root == nullptr){
                cout << "Data masih kosong" << endl;
            } else {
                int judul;
                cout << "===============================\n";
                cout << "1. Cari berdasarkan judul\n";
                cout << "2. Cari berdasarkan genre\n";
                cout << "3. Cari berdasarkan tahun\n";
                cout << "4. Cari berdasarkan rating\n";
                cout << "===============================\n";
                cout << "Pilih: ";
                cin >> judul;
                clearScreen();
                if (judul == 1) {
                    searchJudul(t.root);
                } else if (judul == 2) {
                    string genreSearch;
                    cout << "Masukkan genre yang ingin dicari: ";
                    cin >> genreSearch;
                    cout << "\n--- Film Dengan Genre " << genreSearch << " ---" << endl;
                    searchGenre(t.root, genreSearch);
                    cout << "\n===============================\n";
                    cout << "Tekan Enter untuk melanjutkan"; cin.ignore(); cin.get();
                    clearScreen();
                } else if (judul == 3) {
                    int tahunSearch;
                    cout << "Masukkan tahun yang ingin dicari: ";
                    cin >> tahunSearch;
                    cout << "\n--- Film Tahun " << tahunSearch << " ---" << endl;
                    searchTahun(t.root, tahunSearch);
                    cout << "\n===============================\n";
                    cout << "Tekan Enter untuk melanjutkan"; cin.ignore(); cin.get();
                    clearScreen();
                } else if (judul == 4) {
                    float ratingSearch;
                    cout << "Masukkan rating yang ingin dicari: ";
                    cin >> ratingSearch;
                    searchByRating(t.root, ratingSearch);
                    cout << "\n===============================\n";
                    cout << "Tekan Enter untuk melanjutkan"; cin.ignore(); cin.get();
                    clearScreen();
                }
            }
            break;
        case 3:
            if (t.root == nullptr){
                cout << "Data masih kosong." << endl;
                cout << "Tekan Enter untuk melanjutkan"; cin.ignore(); cin.get();
            } else {
                int display;
                cout << "Tampilkan berdasarkan: \n";
                cout << "1. In-Order (A-Z)\n";
                cout << "2. Post-Order\n";
                cout << "3. Pre-Order\n";
                cout << "Pilih: ";
                cin >> display;

                clearScreen();
                cout << "\n=== DAFTAR SEMUA FILM ===\n";
                switch (display) {
                case 1:
                    printInOrder(t.root);
                    break;
                case 2:
                    printPostOrder(t.root);
                    break;
                case 3:
                    printPreOrder(t.root);
                    break;
                }
                opsiLanjutan(t);
            }
            break;
        }
    }
}
