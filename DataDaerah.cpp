#include "DataDaerah.h"
#include "Relasi.h"

//Alokasi Daerah
void Allocate_Daerah(adrDaerah &P , string Nama , int JumlahPenduduk, string Provinsi){
    P = new Daerah;
    Info(P).Nama = Nama;
    Info(P).JumlahPenduduk = JumlahPenduduk;
    Info(P).Provinsi = Provinsi;
    Next(P) = NULL;
    Prev(P) = NULL;
}

//Alokasi Potensi
void Allocate_Potensi(adrPotensi &P , string SumberDaya , int Penghasilan){
    P = new DataPotensi;
    Info(P).SumberDaya = SumberDaya;
    Info(P).Penghasilan = Penghasilan;
    Next(P) = NULL;
}


//Alokasi Relasi
void Allocate_Relasi(adrRelasi &P , adrDaerah Dae , adrPotensi Pot){
    P = new Relasi;
    Rdaerah(P) = Dae;
    Rpotensi(P) = Pot;
    Next(P) = NULL;
}


//Fungsi Alokasi Daerah
adrDaerah Allocate_Daerah(string Nama , int JumlahPenduduk, string Provinsi){
    adrDaerah  P;
    P = new Daerah;
    Info(P).Nama = Nama;
    Info(P).JumlahPenduduk = JumlahPenduduk;
    Info(P).Provinsi = Provinsi;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

//fungsi Alokasi Potensi
adrPotensi Allocate_Potensi(string SumberDaya , int Penghasilan){
    adrPotensi P;
    P = new DataPotensi;
    Info(P).SumberDaya = SumberDaya;
    Info(P).Penghasilan = Penghasilan;
    Next(P) = NULL;
    return P;
}

//Fungsi Alokasi Relasi
adrRelasi Allocate_Relasi(adrDaerah Dae , adrPotensi Pot){
    adrRelasi P;
    P = new Relasi;
    Rdaerah(P) = Dae;
    Rpotensi(P) = Pot;
    Next(P) = NULL;
    return P;
}




//Fungsi CreateList Daerah
List_Daerah CreateList_Daerah(){
    List_Daerah P;
    First(P) = NULL;
    Last(P) = NULL;
    return P;
}

//fungsi CreateList Potensi
List_Potensi CreateList_Potensi(){
    List_Potensi P;
    First(P) = NULL;
    Last(P) = NULL;
    return P;
}

//Fungsi CreateList Relasi
List_Relasi CreateList_Relasi(){
    List_Relasi P;
    First(P) = NULL;
    return P;
}

//Mengoutputkan Semua Daerah dan Potensinya
void Print_AllDaerahDanPotensi(List_Relasi L){
    adrRelasi P = First(L);
    int i = 1;
    while(P != NULL){
        cout<<i<<"."<<Info(Rdaerah(P)).Nama<<endl;
        cout<<"  "<<Info(Rdaerah(P)).JumlahPenduduk<<endl;
        cout<<"  "<<Info(Rdaerah(P)).Provinsi<<endl;
        cout<<"  "<<Info(Rpotensi(P)).SumberDaya<<endl;
        cout<<"  "<<Info(Rpotensi(P)).Penghasilan<<endl;
        P = RNext(P);
        i++;
    }
}




//megoutputkan semua daerah pada potensi tertentu
void Print_DaerahInPotensi(List_Relasi L , adrDaerah p){
    adrRelasi q = First(L);
    if (First(L) != NULL) {
            int i = 1;
        while(q != NULL){
            if(Rdaerah(q) == p)
                cout<<"Nama Daerah     : "<<Info(Rdaerah(q)).Nama<<endl;
                cout<<"Jumlah Penduduk : "<<Info(Rdaerah(q)).JumlahPenduduk<<endl;
                cout<<"Provinsi        : "<<Info(Rdaerah(q)).Provinsi<<endl;
                cout<<endl;
            i++;
            }
            q = RNext(q);
        }else{
        cout<<"Kosong"<<endl;
    }
}


//mengoutputkan potensi pada daerah tertentu
void Print_PotensiInDaerah(List_Relasi L , adrPotensi p){
    adrRelasi q = First(L);
    if (First(L) != NULL) {
            int i = 1;
        while(q != NULL)
            if(Rpotensi(q) == p){
                cout<<"Nama            : "<<Info(Rdaerah(q)).Nama<<endl;
                cout<<"Sumber Daya     : "<<Info(Rpotensi(q)).SumberDaya<<endl;
                cout<<"Penghasilan     : "<<Info(Rpotensi(q)).Penghasilan<<endl;
                cout<<endl;
            i++;
            }
            q = RNext(q);

    }else{
        cout<<"Kosong"<<endl;
    }
}

//BARU SAMPAI SINI!!!!!!!!!!-----------------------------------------------



