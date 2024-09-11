#include <iostream>
#include <string>
using namespace std;

// Penggunaan prosedur agar penggunaan kode lebih reusability
// Kasih raw string pada print


int jmlPaket = 0;       // untuk logika input data2, data3, dst
int posisiPaket;

// menuUtama();
int pilih;

string data1[21], data2[21], data3[21], data4[21], data5[21], data6[21], data7[21], data8[21], data9[21], data10[21];
string *dataPaket[10] = { data1, data2, data3, data4, data5, data6, data7, data8, data9, data10 };


struct Data{
    string namaPengirim, alamatPengirim, noHpPengirim, kodePosPengirim, emailPengirim;
    string namaPenerima, alamatPenerima, noHpPenerima, kodePosPenerima, emailPenerima;
    string namaPaket, kategoriPaket, panjangPaket, lebarPaket, tinggiPaket, beratPaket;
    string namaKurir, noHpKurir, kendaraan, platNomorKendaraan, warnaKendaraan;

    Data *prev;
    Data *next;
};

Data *head, *tail, *cur, *next, *newNode, *afterNode, *del;


void formPengirim() {
    cout << "\t============================================================" << endl;
    cout << "\t                  FORMULIR DATA PENGIRIM                    " << endl;
    cout << "\t============================================================" << endl << endl;
}

void formPenerima() {
    cout << "\t============================================================" << endl;
    cout << "\t                  FORMULIR DATA PENERIMA                    " << endl;
    cout << "\t============================================================" << endl << endl;
}

void formPaket() {
    cout << "\t============================================================" << endl;
    cout << "\t                        DATA PAKET                          " << endl;
    cout << "\t============================================================" << endl << endl;
}

void formKurir() {
    cout << "\t============================================================" << endl;
    cout << "\t                        DATA KURIR                          " << endl;
    cout << "\t============================================================" << endl << endl;
}

string thanks = R"(
    ================\
    |----------||   \\   Gasss ngengg
    |____|_____||____\\_ ____
   <|  ___\    ||     | ___  |
   <| /   \|___||_____|/   \ |
   ||/  O  |__________/  O  |_\
      \___/            \___/


    Terima kasih telah menggunakan jasa pengiriman dari kami,
    paket dari anda akan segera kami kirim.

    [1] Kembali ke menu utama
    [2] Lihat data paket
    [3] Keluar
)";

string removePaketFirst = R"(
         _
     ___/ \___
    |---------|
     | | | | |
     | | | | |    PAKET FIRST TELAH DIHAPUS
     | | | | |
     | | | | |
     |_______|






     [1] Kembali ke menu utama
     [2] Keluar
)";



void kirimPaket(string data[21]) {
    head = new Data;
    head -> namaPengirim = data[0];
    head -> alamatPengirim = data[1];
    head -> noHpPengirim = data[2];
    head -> kodePosPengirim = data[3];
    head -> emailPengirim = data[4];
    head -> namaPenerima = data[5];
    head -> alamatPenerima = data[6];
    head -> noHpPenerima = data[7];
    head -> kodePosPenerima = data[8];
    head -> emailPenerima = data[9];
    head -> namaPaket = data[10];
    head -> kategoriPaket = data[11];
    head -> panjangPaket = data[12];
    head -> lebarPaket = data[13];
    head -> tinggiPaket = data[14];
    head -> beratPaket = data[15];
    head -> namaKurir = data[16];
    head -> noHpKurir = data[17];
    head -> kendaraan = data[18];
    head -> platNomorKendaraan = data[19];
    head -> warnaKendaraan = data[20];
    head -> next = NULL;
    head -> prev = NULL;
    tail = head;
}

void paketFirst(string data[21]) {
    newNode = new Data;
    newNode -> namaPengirim = data[0];
    newNode -> alamatPengirim = data[1];
    newNode -> noHpPengirim = data[2];
    newNode -> kodePosPengirim = data[3];
    newNode -> emailPengirim = data[4];
    newNode -> namaPenerima = data[5];
    newNode -> alamatPenerima = data[6];
    newNode -> noHpPenerima = data[7];
    newNode -> kodePosPenerima = data[8];
    newNode -> emailPenerima = data[9];
    newNode -> namaPaket = data[10];
    newNode -> kategoriPaket = data[11];
    newNode -> panjangPaket = data[12];
    newNode -> lebarPaket = data[13];
    newNode -> tinggiPaket = data[14];
    newNode -> beratPaket = data[15];
    newNode -> namaKurir = data[16];
    newNode -> noHpKurir = data[17];
    newNode -> kendaraan = data[18];
    newNode -> platNomorKendaraan = data[19];
    newNode -> warnaKendaraan = data[20];
    newNode -> next = head;
    newNode -> prev = NULL;
    head -> prev = newNode;
    head = newNode;
}

void paketLast(string data[21]) {
    newNode = new Data;
    newNode -> namaPengirim = data[0];
    newNode -> alamatPengirim = data[1];
    newNode -> noHpPengirim = data[2];
    newNode -> kodePosPengirim = data[3];
    newNode -> emailPengirim = data[4];
    newNode -> namaPenerima = data[5];
    newNode -> alamatPenerima = data[6];
    newNode -> noHpPenerima = data[7];
    newNode -> kodePosPenerima = data[8];
    newNode -> emailPenerima = data[9];
    newNode -> namaPaket = data[10];
    newNode -> kategoriPaket = data[11];
    newNode -> panjangPaket = data[12];
    newNode -> lebarPaket = data[13];
    newNode -> tinggiPaket = data[14];
    newNode -> beratPaket = data[15];
    newNode -> namaKurir = data[16];
    newNode -> noHpKurir = data[17];
    newNode -> kendaraan = data[18];
    newNode -> platNomorKendaraan = data[19];
    newNode -> warnaKendaraan = data[20];
    tail -> next = newNode;
    newNode -> next = NULL;
    newNode -> prev = tail;
    tail = newNode;
}


string removePaketLast = R"(
         _
     ___/ \___
    |---------|
     | | | | |
     | | | | |    PAKET LAST TELAH DIHAPUS
     | | | | |
     | | | | |
     |_______|






     [1] Kembali ke menu utama
     [2] Keluar
)";


string removePaketMiddle = R"(
         _
     ___/ \___
    |---------|
     | | | | |
     | | | | |    PAKET MIDDLE TELAH DIHAPUS
     | | | | |
     | | | | |
     |_______|






     [1] Kembali ke menu utama
     [2] Keluar
)";


void hapusPaketFirst() {
    del = head;
    head = del -> next;
    head -> prev = NULL;
    delete del;
}


void hapusPaketLast() {
    del = tail;
    tail = del -> prev;
    tail -> next = NULL;
    delete del;
}


void paketMiddle(string data[21], int pos) {
    newNode = new Data;
    newNode -> namaPengirim = data[0];
    newNode -> alamatPengirim = data[1];
    newNode -> noHpPengirim = data[2];
    newNode -> kodePosPengirim = data[3];
    newNode -> emailPengirim = data[4];
    newNode -> namaPenerima = data[5];
    newNode -> alamatPenerima = data[6];
    newNode -> noHpPenerima = data[7];
    newNode -> kodePosPenerima = data[8];
    newNode -> emailPenerima = data[9];
    newNode -> namaPaket = data[10];
    newNode -> kategoriPaket = data[11];
    newNode -> panjangPaket = data[12];
    newNode -> lebarPaket = data[13];
    newNode -> tinggiPaket = data[14];
    newNode -> beratPaket = data[15];
    newNode -> namaKurir = data[16];
    newNode -> noHpKurir = data[17];
    newNode -> kendaraan = data[18];
    newNode -> platNomorKendaraan = data[19];
    newNode -> warnaKendaraan = data[20];

    cur = head;
	int number = 1;

    while(number < pos - 1) {
		cur = cur -> next;
		number++;
	}

	afterNode = cur -> next;
	newNode -> next = afterNode;
	newNode -> prev = cur;
	cur -> next = newNode;
	afterNode -> prev = newNode;
}


void hapusPaketMiddle(int pos) {

    cur = head;
	int number = 1;

    while(number < pos - 1) {
		cur = cur -> next;
		number++;
	}

	del = cur -> next;
	afterNode = del -> next;
	cur -> next = afterNode;
	afterNode -> prev = cur;
	delete del;
}


void close() {
    system("cls");
    cout << "\t============================================================" << endl;
    cout << "\t                TERIMA KASIH SAMPAI JUMPA LAGI              " << endl;
    cout << "\t============================================================\n\n\n\n\n\n\n\n\n\n\n\n\n";
    exit(1);
}

void lihatDataTunggal() {
    cout << "\t============================================================" << endl;
    cout << "\t                        DATA PAKET " << jmlPaket <<      "                         " << endl;
    cout << "\t============================================================" << endl << endl;
    cout << "\tNama Pengirim : " << dataPaket[jmlPaket - 1][0] << endl;
    cout << "\tAlamat Pengirim : " << dataPaket[jmlPaket - 1][1] << endl;
    cout << "\tNo HP Pengirim : " << dataPaket[jmlPaket - 1][2] << endl;
    cout << "\tKode Pos Pengirim : " << dataPaket[jmlPaket - 1][3] << endl;
    cout << "\tEmail Pengirim : " << dataPaket[jmlPaket - 1][4] << endl;
    cout << "\tNama Penerima : " << dataPaket[jmlPaket - 1][5] << endl;
    cout << "\tAlamat Penerima : " << dataPaket[jmlPaket - 1][6] << endl;
    cout << "\tNo HP Penerima : " << dataPaket[jmlPaket - 1][7] << endl;
    cout << "\tKode Pos Penerima : " << dataPaket[jmlPaket - 1][8] << endl;
    cout << "\tEmail Penerima : " << dataPaket[jmlPaket - 1][9] << endl;
    cout << "\tNama Paket : " << dataPaket[jmlPaket - 1][10] << endl;
    cout << "\tKategori Paket : " << dataPaket[jmlPaket - 1][11] << endl;
    cout << "\tPanjang Paket : " << dataPaket[jmlPaket - 1][12] << endl;
    cout << "\tLebar Paket : " << dataPaket[jmlPaket - 1][13] << endl;
    cout << "\tTinggi Paket : " << dataPaket[jmlPaket - 1][14] << endl;
    cout << "\tBerat Paket : " << dataPaket[jmlPaket - 1][15] << endl;
    cout << "\tNama Kurir : " << dataPaket[jmlPaket - 1][16] << endl;
    cout << "\tNo HP Kurir : " << dataPaket[jmlPaket - 1][17] << endl;
    cout << "\tKendaraan : " << dataPaket[jmlPaket - 1][18] << endl;
    cout << "\tPlat Nomor Kendaraan : " << dataPaket[jmlPaket - 1][19] << endl;
    cout << "\tWarna Kendaraan : " << dataPaket[jmlPaket - 1][20] << endl << endl;
}



void print() {
    cur = head;
    int no = 1;

    while(cur != NULL) {
        cout << "\t----------------------------------------------" << endl << endl;
        cout << "\tData Paket : " << no << endl << endl;
        cout << "\tNama Pengirim : " << cur -> namaPengirim << endl;
        cout << "\tAlamat Pengirim : " << cur -> alamatPengirim << endl;
        cout << "\tNo HP Pengirim : " << cur -> noHpPengirim << endl;
        cout << "\tKode Pos Pengirim : " << cur -> kodePosPengirim << endl;
        cout << "\tEmail Pengirim : " << cur -> emailPengirim << endl << endl;
        cout << "\tNama Penerima : " << cur -> namaPenerima << endl;
        cout << "\tAlamat Penerima : " << cur -> alamatPenerima << endl;
        cout << "\tNo HP Penerima : " << cur -> noHpPenerima << endl;
        cout << "\tKode Pos Penerima : " << cur -> kodePosPenerima << endl;
        cout << "\tEmail Penerima : " << cur -> emailPenerima << endl << endl;
        cout << "\tNama Paket : " << cur ->  namaPaket << endl;
        cout << "\tKategori Paket : " << cur ->  kategoriPaket << endl;
        cout << "\tPanjang Paket : " << cur ->  panjangPaket << endl;
        cout << "\tLebar Paket : " << cur ->  lebarPaket << endl;
        cout << "\tTinggi Paket : " << cur ->  tinggiPaket << endl;
        cout << "\tBerat Paket : " << cur ->  beratPaket << endl << endl;
        cout << "\tNama Kurir : " << cur -> namaKurir << endl;
        cout << "\tNo Hp Kurir : " << cur -> noHpKurir << endl;
        cout << "\tKendaraan : " << cur -> kendaraan << endl;
        cout << "\tPlat Nomor Kendaraan : " << cur -> platNomorKendaraan << endl;
        cout << "\tWarna Kendaraan : " << cur -> warnaKendaraan << endl << endl;
        cout << "\t----------------------------------------------" << endl << endl;

        no++;
        cur = cur -> next;
    }
}


void inputData() {
    formPengirim();
    cout << "\tPaket ke : " << jmlPaket + 1 << endl << endl;
    // Input data pengirim
    cout << "\tNama Pengirim : ";
    cin.ignore();
    getline(cin, dataPaket[jmlPaket][0]);
    cout << "\tAlamat Pengirim : ";
    getline(cin, dataPaket[jmlPaket][1]);
    cout << "\tNo HP Pengirim : ";
    getline(cin, dataPaket[jmlPaket][2]);
    cout << "\tKode Pos Pengirim : ";
    getline(cin, dataPaket[jmlPaket][3]);
    cout << "\tEmail Pengirim : ";
    getline(cin, dataPaket[jmlPaket][4]);
    system("cls");

    // Input data penerima
    formPenerima();
    cout << "\tPaket ke : " << jmlPaket + 1 << endl << endl;
    cout << "\tNama Penerima : ";
    getline(cin, dataPaket[jmlPaket][5]);
    cout << "\tAlamat Penerima : ";
    getline(cin, dataPaket[jmlPaket][6]);
    cout << "\tNo HP Penerima : ";
    getline(cin, dataPaket[jmlPaket][7]);
    cout << "\tKode Pos Penerima : ";
    getline(cin, dataPaket[jmlPaket][8]);
    cout << "\tEmail Penerima : ";
    getline(cin, dataPaket[jmlPaket][9]);
    cin.ignore();
    system("cls");

    // Input data paket
    formPaket();
    cout << "\tPaket ke : " << jmlPaket + 1 << endl << endl;
    cout << "\tNama Paket : ";
    getline(cin, dataPaket[jmlPaket][10]);
    cout << "\tKategori Paket : ";
    getline(cin, dataPaket[jmlPaket][11]);
    cout << "\tPanjang Paket : ";
    getline(cin, dataPaket[jmlPaket][12]);
    cout << "\tLebar Paket : ";
    getline(cin, dataPaket[jmlPaket][13]);
    cout << "\tTinggi Paket : ";
    getline(cin, dataPaket[jmlPaket][14]);
    cout << "\tBerat Paket : ";
    getline(cin, dataPaket[jmlPaket][15]);
    system("cls");

    // Input data kurir
    formKurir();
    cout << "\tPaket ke : " << jmlPaket + 1 << endl << endl;
    cout << "\tNama Kurir : ";
    getline(cin, dataPaket[jmlPaket][16]);
    cout << "\tNo HP Kurir : ";
    getline(cin, dataPaket[jmlPaket][17]);
    cout << "\tKendaraan : ";
    getline(cin, dataPaket[jmlPaket][18]);
    cout << "\tPlat Nomor Kendaraan : ";
    getline(cin, dataPaket[jmlPaket][19]);
    cout << "\tWarna Kendaraan : ";
    getline(cin, dataPaket[jmlPaket][20]);

    system("cls");
}


void menuUtama() {
    system("cls");
    string home = R"(
    -------------------------------------------------------------------------------------
	 _  _ _      _                  _         _____
	| |/ (_)_ __(_)_ __ ___   __ _ (_) __ _  | ____|_  ___ __  _ __ ___  ___ ___
	| ' /| | '__| | '_ ` _ \ / _` || |/ _` | |  _| \ \/ / '_ \| '__/ _ \/ __/ __|
	| . \| | |  | | | | | | | (_| || | (_| | | |___ >  <| |_) | | |  __/\__ \__ \
	|_|\_\_|_|  |_|_| |_| |_|\__,_|/ |\__,_| |_____/_/\_\ .__/|_|  \___||___/___/
	                             |__/                   |_|
    -------------------------------------------------------------------------------------


	Selamat datang di aplikasi pengiriman barang Kirimaja Express

	[1] Kirim paket
	[2] Kirim paket first
	[3] Hapus paket first
	[4] Kirim paket last
	[5] Hapus paket last
	[6] Kirim paket middle
	[7] Hapus paket middle
	[8] Lihat daftar paket
	[9] Keluar
    )";

    cout << home;
    cout << "\n\tMasukkan pilihan anda [1/2/3/4/5/6/7/8/9] : ";
    cin >> pilih;
    if (pilih == 1) {
        system("cls");
        inputData();
        kirimPaket(dataPaket[jmlPaket]);
        jmlPaket++;
        cout << thanks;
        cout << "    Masukkan pilihan anda [1/2/3] : ";
        cin >> pilih;
        if (pilih == 1) {
            system("cls");
            menuUtama();
        } else if (pilih == 2) {
            system("cls");
            lihatDataTunggal();
            cout << "\t[1]Kembali ke menu utama\n";
            cout << "\t[2]Keluar\n";
            cout << "\tMasukkan pilihan anda [1/2] : ";
            cin >> pilih;
            if (pilih == 1) {
                menuUtama();
            } else {
                close();
            }
        } else if (pilih == 3) {
            close();
        } else {
            cout << "\tPilihan yang anda pilih tidak valid\n\n";
        }
    } else if(pilih == 2) {
        system("cls");
        inputData();
        paketFirst(dataPaket[jmlPaket]);
        jmlPaket++;
        cout << thanks;
        cout << "    Masukkan pilihan anda [1/2/3] : ";
        cin >> pilih;
        if (pilih == 1) {
            system("cls");
            menuUtama();
        } else if (pilih == 2) {
            system("cls");
            lihatDataTunggal();
            cout << "\t[1]Kembali ke menu utama\n";
            cout << "\t[2]Keluar\n";
            cout << "\tMasukkan pilihan anda [1/2] : ";
            cin >> pilih;
            if (pilih == 1) {
                menuUtama();
            } else {
                close();
            }
        } else if (pilih == 3) {
            close();
        } else {
            cout << "\tPilihan yang anda pilih tidak valid\n\n";
        }
    } else if (pilih == 3) {
        system("cls");
        hapusPaketFirst();
        cout << removePaketFirst << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilih;
        if (pilih == 1) {
            menuUtama();
        } else {
            close();
        }
    } else if (pilih == 4) {
        system("cls");
        inputData();
        paketLast(dataPaket[jmlPaket]);
        jmlPaket++;
        cout << thanks;
        cout << "    Masukkan pilihan anda [1/2/3] : ";
        cin >> pilih;
        if (pilih == 1) {
            menuUtama();
        } else if (pilih == 2) {
            system("cls");
            lihatDataTunggal();
            cout << "\t[1]Kembali ke menu utama\n";
            cout << "\t[2]Keluar\n";
            cout << "\tMasukkan pilihan anda [1/2] : ";
            cin >> pilih;
            if (pilih == 1) {
                menuUtama();
            } else {
                close();
            }
        } else if (pilih == 3) {
            close();
        } else {
            cout << "\tPilihan yang anda pilih tidak valid\n\n";
        }
    } else if(pilih == 5) {
        system("cls");
        hapusPaketLast();
        cout << removePaketLast << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilih;
        if (pilih == 1) {
            menuUtama();
        } else {
            close();
        }
    } else if(pilih == 6) {
        system("cls");
        cout << "\tIngin menambahkan paket ke posisi berapa : ";
        cin >> posisiPaket;
        inputData();
        paketMiddle(dataPaket[jmlPaket], posisiPaket);
        jmlPaket++;
        cout << thanks;
        cout << "    Masukkan pilihan anda [1/2/3] : ";
        cin >> pilih;
        if (pilih == 1) {
            system("cls");
            menuUtama();
        } else if (pilih == 2) {
            system("cls");
            lihatDataTunggal();
            cout << "\t[1]Kembali ke menu utama\n";
            cout << "\t[2]Keluar\n";
            cout << "\tMasukkan pilihan anda [1/2] : ";
            cin >> pilih;
            if (pilih == 1) {
                menuUtama();
            } else {
                close();
            }
        } else if (pilih == 3) {
            close();
        } else {
            cout << "\tPilihan yang anda pilih tidak valid\n\n";
        }
    } else if(pilih == 7) {
        system("cls");
        cout << "\tIngin menghapus paket ke posisi berapa : ";
        cin >> posisiPaket;
        hapusPaketMiddle(posisiPaket);
        cout << removePaketMiddle << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilih;
        if (pilih == 1) {
            menuUtama();
        } else {
            close();
        }
    } else if(pilih == 8) {
        system("cls");
        print();
        cout << "\t[1] Kembali ke menu utama\n";
        cout << "\t[2] Keluar\n";
        cout << "\tMasukkan pilihan anda : ";
        cin >> pilih;
        if (pilih == 1) {
            menuUtama();
        } else {
            close();
        }
    } else {
        close();
    }
}

int main() {
    menuUtama();

    return 0;
}









