#include <iostream>
using namespace std;


class Buku {
private:
    string judul;
    string penulis;
    bool statusDipinjam;

public:
    Buku(string j = "", string p = "") : judul(j), penulis(p), statusDipinjam(false) {}

    // methodc setter chain function
    Buku& setJudul(const string& j) 
    {
        judul = j;
        return *this;
    }

    Buku& setPenulis(const string& p)
    {
        penulis = p;
        return *this;
    }

    void tampilkanInfo() const
    {
        cout << "Judul: " << judul << ", Penulis: " << penulis << ", Status: ";
        cout << (statusDipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    friend class Petugas;
    friend void lihatStatusBuku(const Buku& b);
};

class Peminjam {
private:
    string nama;
    int id;
    int totalDipinjam;

public:
    Peminjam(string n = "", int i = 0) : nama(n), id(i), totalDipinjam(0){}
    
    Peminjam& setNama(const string& n)
    {
        nama = n;
        return *this;
    }

    Peminjam& setId(int i)
    {
        id = i;
        return *this;
    }

    void tampilkanInfo() const
    {
        cout << "Nama: " << nama << ", ID: " << id << ", Total Dipinjam: " << totalDipinjam << endl;
    }

    friend class Petugas;
    friend void lihatStatusPeminjam(const Peminjam& p);
};

class Petugas {
private:
    string nama;
    int id;
    string levelAkses;

public:
    Petugas(string n = "", int i = 0, string level = "") : nama(n), id(i), levelAkses(level) {}
    
    Petugas& setNama(const string& n)
    {
        nama = n;
        return *this;
    }

    Petugas& setId(int i)
    {
        id = i;
        return *this;
    }

    Petugas& setLevelAkses(const string& level)
    {
        levelAkses = level;
        return *this;
    }

    void prosesPeminjaman(Buku& b, Peminjam& p)
    {
        if (!b.statusDipinjam)
        {
            b.statusDipinjam = true;
            p.totalDipinjam++;
            cout << "Petugas: Buku berhasil di pinjam." << endl;
        }
        else
        {
            cout << "Petugas: Buku sedang dipinjam." << endl;
        }
    }

    

    friend class Admin;
};

class Admin{
public:
    void ubahLevelAkses(Petugas& p, const string& aksesBaru)
    {
        p.levelAkses = aksesBaru;
        cout << "[Admin]: level akses diubah menjadi: " << aksesBaru << endl;
    }

    void lihatStatistik(const Buku& b, const Peminjam& p) const
    {
        lihatStatusBuku(b);
        lihatStatusPeminjam(p);
    }
};

//Friend Function
void lihatStatusBuku(const Buku& b){
cout << "[Admin]: Status Buku: " << (b.statusDipinjam ? "Dipinjam" : "Tersedia") << endl;
}


void lihatStatusPeminjam(const Peminjam& p){
    cout << "[Admin]: Total Buku Dipinjam oleh Peminjam: " << p.totalDipinjam << endl;
}

int main() {
    Buku* buku1 = new Buku();
    buku1->setJudul("Ilmu Sosial").setPenulis("Dani Ramadhan");

    Peminjam* siswa1 = new Peminjam();
    siswa1->setNama("Rendra").setId(220);

    Petugas* petugas1 = new Petugas();
    petugas1->setNama("Nico").setId(10).setLevelAkses("Biasa");

    Admin admin;

    cout << "===Sebelum Peminjaman===" << endl;
    buku1->tampilkanInfo();
    siswa1->tampilkanInfo();

    petugas1->prosesPeminjaman(*buku1, *siswa1);

    cout << "\n===Setelah Peminjaman===" << endl;
    buku1->tampilkanInfo();
    siswa1->tampilkanInfo();

    admin.lihatStatistik(*buku1, *siswa1);

    petugas1->prosesPengembalian(*buku1, *siswa1);

    admin.ubahLevelAkses(*petugas1, "Koordinator");
    
    return 0;
}