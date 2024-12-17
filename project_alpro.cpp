#include "bits/stdc++.h"
#include <ctime>
using namespace std;

int ay = 0;
const int maks_user = 2;
string user[maks_user];
string sandi[maks_user];
string nama[100];
string alamat[100];
string nomer[100];
string motor[100];
string nama_keluhan[100];
int hargakeluhann[100];
int peraturan = 0;
int peraturan_keluhan = 0;
char menu1, menu2, kembali;
bool program1 = true;
bool program2 = true;


//untuk halaman tampilan
void halaman_tampilan()
{
    cout << "||" << setfill('=') << setw(44) << "||" << endl;
    cout << "||" << setfill(' ') << setw(44) << "||" << endl;
    cout << "|| Selamat Datang di Aplikasi Service Motor ||" << endl;
    cout << "||" <<setfill(' ') << setw(44) << "||" << endl;
    cout << "||" << setfill('=') << setw(44) << "||" << endl;
    time_t a = time(0);
    cout << ctime(&a);
    cout << "Silahkan Pilih Menu :" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih Menu : ";
    cin >> menu1;
}

bool cek_registrasi(string username, string password)
{
        for (int i = 0; i < peraturan; i++)
        {
            if (username == user[i] || password == sandi[i])
            {
                return true;
            }
        }
        return false;
}

//fungsi untuk menu registrasi dan untuk mengecek duplikat username&password 
void Menu_Registrasi()
{
    string username, password;
    
    cout << "||===============||" << endl;
    cout << "||Menu registrasi||" << endl;
    cout << "||===============||" << endl;
    cin.ignore();
    cout << "Masukkan Username : ";
    getline(cin, username);
    cout << "Masukkan Password : ";
    getline(cin, password);

    if (cek_registrasi(username, password))
    {
        cout << "Registrasi gagal, username telah ada" << endl << endl;
        return;
    }

    if (peraturan < maks_user)
    {
        user[peraturan] = username;
        sandi[peraturan] = password;
        peraturan++;
        cout << "Registrasi Telah Berhasil" << endl;
    
    }else
    {
        cout << "Kapasitas user sudah penuh" << endl;
    }
}

bool cek_login(string username, string password)
{
    for (int i = 0; i < peraturan; i++)
    {
        if (username == user[i] && password == sandi[i])
        {
            return true;
        }
    }
    return false;
}

void Menu_Login()
{
    string username, password;

    cout << "||==========||" << endl;
    cout << "||Menu Login||" << endl;
    cout << "||==========||" << endl;
    bool data_login = true;
    cout << "Masukkan Username : ";
    cin >> username;
    cout << "Masukkan Password : ";
    cin >> password;

    if (cek_login(username, password))
    {
        cout << "Login berhasil" << endl;
        program1 = false;
        cin.ignore();
    }else
    {
        cout << "Username atau Password Salah" << endl;
    }
}

void halaman_tampilan_2()
{
    cout << "||============||" << endl;
    cout << "|| Menu Utama ||" << endl;
    cout << "||============||" << endl;
    time_t a = time(0);
    cout << ctime(&a);
    cout << "1. Isi data form service" << endl;
    cout << "2. Cari data service" << endl;
    cout << "3. Lihat Data service" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih Menu : ";
    cin >> menu2;
}

void menu_isi_data_form_service()
{
    bool masuk = true;
    string nama_pelanggan, alamat_pelanggan, nomer_pelanggan, motor_pelanggan, keluhan_pelanggan;
    int harga;

    cout << "||" << setfill('=') << setw(35) << "||" << endl;
    cout << "||Silahkan mengisi formulir service||" << endl;
    cout << "||" << setfill('=') << setw(35) << "||" << endl;
    cout << endl;
    cout << "||====================||" << endl;
    cout << "||Data Keluhan Service||" << endl;
    cout << "||====================||" << endl;
    cout << endl;
    cout << "||============================||=====================||" << endl;
    cout << "||        Nama Keluhan        ||        Harga        ||" << endl;
    cout << "||============================||=====================||" << endl;
    cout << "||1. Ganti Busi               ||25000                ||" << endl;
    cout << "||1. Ganti Ban Depan          ||200000               ||" << endl;
    cout << "||1. Ganti Ban Belakang       ||220000               ||" << endl;
    cout << "||1. Ganti Rantai             ||150000               ||" << endl;
    cout << "||1. Ganti Drive Belt         ||180000               ||" << endl;
    cout << "||1. Isi Coolant              ||50000                ||" << endl;
    cout << "||1. Ganti Kampas Rem         ||90000                ||" << endl;
    cout << "||1. Bersihkan Filter Udara   ||40000                ||" << endl;
    cout << "||1. Ganti Aki                ||400000               ||" << endl;
    cout << "||1. Ganti Lampu Depan        ||70000                ||" << endl;
    cout << "||1. Ganti Lampu Belakang     ||60000                ||" << endl;
    cout << "||1. Pembersihan CVT          ||120000               ||" << endl;
    cout << "||===================================================||" << endl;
    cout << endl;
    cout << "Nama : ";
    cin.ignore();
    getline(cin, nama_pelanggan);
    cout << "Alamat : ";
    cin >> alamat_pelanggan;
    cout << "No.hp : ";
    cin >> nomer_pelanggan;
    cout << "Masukkan varian motor : ";
    cin >> motor_pelanggan;
    cout << "Masukkan Nama keluhan : ";
    cin.ignore();
    // cin >> keluhan_pelanggan;
    getline(cin, keluhan_pelanggan);
    cout << "Masukkan Harga barang : ";
    cin >> harga;
    if(masuk){
        nama[ay] = nama_pelanggan;
        alamat[ay] = alamat_pelanggan;
        nomer[ay] = nomer_pelanggan;
        motor[ay] = motor_pelanggan;
        nama_keluhan[ay] = keluhan_pelanggan;
        hargakeluhann[ay] = harga;
        ay++;
        peraturan_keluhan++;
    }
}

void menu_cari_data_service()
{
    string cari;
    bool dapat = false;
    cin.ignore();
    cout << "Masukkan nama data yang ingin dicari : ";
    getline(cin, cari);
    system("cls");
    for (int i = 0; i < peraturan_keluhan; i++)
    {
        if(cari == nama[i])
        {
            cout << "Data Ditemukan!" << endl;
            cout << "Nama    : " << nama[i] << endl;
            cout << "Alamat   : " << alamat[i] << endl;
            cout << "No.hp    : " << nomer[i] << endl;
            cout << "Varian motor : " << motor[i] << endl;
            cout << "Keluhan : " << nama_keluhan[i] << endl;
            cout << "Harga : " << hargakeluhann[i] << endl;
            cout << "=============================" << endl;
            cout << endl;
        }
    }

    if (!dapat)
    {
        cout << "Data yang dicari tidak ditemukan." << endl;
    }
}

void menu_lihat_data_service()
{
    cout << "Daftar Service Motor" << endl;
    
    if (peraturan_keluhan == 0)
    {
        cout << "Tidak ada data service motor yang terdaftar." << endl;
        return;
    }
    
    for (int i = 0; i < peraturan_keluhan; i++)
    {
        cout << "Nama         : " << nama[i] << endl;
        cout << "Alamat       : " << alamat[i] << endl;
        cout << "No.hp        : " << nomer[i] << endl;
        cout << "Varian motor : " << motor[i] << endl;
        cout << "Keluhan      : " << nama_keluhan[i] << endl;
        cout << "Harga        : " << hargakeluhann[i] << endl;
        cout << "==================================" << endl;
        cout << endl;
    }
}

void menu_pembayaran_data_service(){
    string cari_nama;
    bool dapat = false;
    int total = 0;
    char konfirmasi;
    if (peraturan_keluhan == 0)
    {
        cout << "Tidak ada data pelanggan service yang terdaftar untuk pembayaran" << endl;
    }

    cout << "||===============||" << endl;
    cout << "||Menu Pembayaran||" << endl;
    cout << "||===============||" << endl;

    cout << "Masukkan nama pelanggan untuk melakukan pembayaran : ";
    cin.ignore();
    getline(cin, cari_nama);
    for (int i = 0; i < peraturan_keluhan; i++)
    {
        if(nama[i] == cari_nama)
        {
            dapat = true;
            cout << "   Nama Pelanggan : " << cari_nama << endl; 
        }

        for (int i = 0; i < peraturan_keluhan; i++)
        {
            if(nama[i] == cari_nama)
            {
                cout << i + 1 << ". Nama Keluhan   : " << nama_keluhan[i] << endl;
                cout << "   Harga          : " << hargakeluhann[i] << endl;
                total += hargakeluhann[i];
                cout << endl;
            }
        }
            cout << "Total Pembayaran : Rp " << total << endl;
            cout << "Konfirmasi Pembayaran : ";
            cin >> konfirmasi;
            if(konfirmasi == 'Y' || konfirmasi == 'y')
            {
                cout << "Pembayaran berhasil" << endl;
                cout << "Terima kasih telah melakukan pembayaran." << endl;
                
                //reset data pelanggan setelah membayar
                for (int i = 0; i < peraturan_keluhan; i++)
            {
                if(nama[i] == cari_nama)
                {
                    nama[i] = "";
                alamat[i] = "";
                nomer[i] = "";
                motor[i] = "";
                nama_keluhan[i] = "";
                hargakeluhann[i] = 0;
                }
            }
            
        }else{
            cout << "Pembayaran dibatalkan" << endl;
        }
        break;
    }
}
 
int main()
{
    while (program1)
    {
        system("cls");
        halaman_tampilan();
       
        switch (menu1)
        {
            case '1':
                system("cls");
                Menu_Registrasi();
                system("pause");
            break;
            case '2':
                system("cls");
                Menu_Login();
                system("pause");
            break;  
        }
    }

    while (program2)
    {
        system("cls");
        halaman_tampilan_2();

        switch (menu2)
        {
            case '1':
                system("cls");
                menu_isi_data_form_service();
                system("pause");
            break;
            case '2':
                system("cls");
                menu_cari_data_service();
                system("pause");
            break;
            case '3':
                system("cls");
                menu_lihat_data_service();
                system("pause");
            break;
            case '4':
                system("cls");
                menu_pembayaran_data_service();
                system("pause");
            break;
            default:
                cout << "Menu yang anda pilih salah. Silahkan coba lagi" << endl;
                system("pause");

        }   
    }
}    

