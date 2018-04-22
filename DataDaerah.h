#ifndef DATADAERAH_H_INCLUDED
#define DATADAERAH_H_INCLUDED

#define Info(B) B->Info
#define Next(B) B->Next
#define Prev(B) B->Prev

//#define Potensi(P) P->Potensi
//#define

#define Rdaerah(A) A->Daerah //relasi kota
#define Rpotensi(A) A->Potensi //relasi jalan
#define RNext(A) A->Next //next relasi

#define First(A) A.First
#define Last(A) A.Last

#include <iostream>

using namespace std;

typedef struct Daerah *adrDaerah;
typedef struct DataPotensi *adrPotensi;
typedef struct Relasi *adrRelasi;




struct InfoDaerah{
    string Nama;
    int JumlahPenduduk;
    string Provinsi;
};

struct InfoPotensi{
    string SumberDaya;
    int Penghasilan;
};


//DoubleList
struct Daerah{
    adrDaerah Next;
    adrDaerah Prev;
    InfoDaerah Info;
};

//SinggleList
struct Relasi{
    adrDaerah Daerah;
    adrPotensi Potensi;
    adrRelasi Next;
};

//SingleCircular+Last
struct DataPotensi{
    InfoPotensi Info;
    adrPotensi Next;
};

//singleCircular + last
struct List_Potensi{
    adrPotensi First;
    adrPotensi Last;
};

//Double List
struct List_Daerah{
    adrDaerah First;
    adrDaerah Last;
};

//siingle list
struct List_Relasi{
    adrRelasi First;
};




void Allocate_Daerah(adrDaerah &P , string Nama , int JumlahPenduduk, string Provinsi);
void Allocate_Potensi(adrPotensi &P , string SumberDaya , int Penghasilan);
void Allocate_Relasi(adrRelasi &P , adrDaerah Dae , adrPotensi Pot);
adrDaerah Allocate_Daerah(string Nama , int JumlahPenduduk, string Provinsi);
adrPotensi Allocate_Potensi(string SumberDaya , int Penghasilan);
adrRelasi Allocate_Relasi(adrDaerah Dae , adrPotensi Pot);
List_Daerah CreateList_Daerah();
List_Potensi CreateList_Potensi();
List_Relasi CreateList_Relasi();
void Print_AllDaerahDanPotensi(List_Daerah L1 , List_Potensi L2);
void Print_DaerahInPotensi(List_Relasi L , adrDaerah p);
void Print_PotensiInDaerah(List_Relasi L , adrPotensi p);
void Print_DaerahKayaMiskin(List_Potensi L , List_Relasi L2);



#endif // DATADAERAH_H_INCLUDED
