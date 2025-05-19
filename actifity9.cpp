#include <iostream>
using namespace std;

class Mahasiswa{
    private:
        static int totalMahasiswa;
    public:
        string nama;
        string status;
        int umur;
        
        Mahasiswa(string pNama, int pUmur) {
            nama = pNama;
            umur = pUmur;
            status = "Mahasiswa Baru";
            ++totalMahasiswa;
            cout << nama << " Dibuat " << " Status " << status << endl;
            cout << endl;
        }

        ~Mahasiswa(){ //"~" syarat destruktor
            cout << nama << " Dihancurkan " << endl;
            --totalMahasiswa;
            cout << endl;
        }

        static int getSeluruhMahasiswa(){
            return totalMahasiswa;
        }

        static void setMahasiswaTotal(int a)
        {
            totalMahasiswa = a;
        }
};


int Mahasiswa::totalMahasiswa = 0;

int main(){

    cout << "Total Mahasiswa adalah = " << 
    Mahasiswa::getSeluruhMahasiswa() << endl;

    Mahasiswa st1("Maman", 40);
    Mahasiswa st2("Agus", 34);

    Mahasiswa::setMahasiswaTotal(100);
    cout << "Total Mahasiswa adalah = " << 
    Mahasiswa::getSeluruhMahasiswa() << endl;
    {
        Mahasiswa st3("Budi", 19);
        Mahasiswa st4("Caca", 21);
        cout << "Total Mahasiswa adalah = " << 
        Mahasiswa::getSeluruhMahasiswa() << endl;
    }


    cout << "Total Mahasiswa adalah = " << 
    Mahasiswa::getSeluruhMahasiswa() << endl;

    return 0;    
}