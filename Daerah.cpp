#include "Daerah.h"
#include "Relasi.h"


///Memasukan Data Kedalam List Dari Depan
void InsertFirst_Daerah(List_Daerah &L , adrDaerah P){
    if(First(L) == NULL){
        ///jika dia tidak berisi
        Last(L) = P;
    }else{
        ///jika dia berisi
        Next(P) = First(L);
        Prev(First(L)) = P;

    }
    First(L) = P;
}

///Memasukan Data Kedalam List Dari Belakang
void InsertLast_Daerah(List_Daerah &L , adrDaerah P){
    if(First(L)== NULL && Last(L)==NULL ){
        ///jika dia kosong
        First(L)=P;
        Last(L)=P;
    }else{
        ///jika dia berisi
        Prev(P)= Last(L);
        Next(Last(L)) = P;
        Last(L) = P;
    }

}

void DealocateDaerah(adrDaerah &P){
    Prev(P) = NULL;
    Next(P) = NULL;
    delete(P);
    P = NULL;
}

void PrintDaerah(List_Daerah L){
    if (First(L) == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        adrDaerah p = First(L);
        while (p != NULL){
            cout<<Info(p).Nama;
            cout<<Info(p).JumlahPenduduk;
            cout<<Info(p).Provinsi;
            p = Next(p);
        }
    }
}

///Menghapus Data P di List L
void Delete_Daerah(List_Daerah &L1 , List_Relasi &L2, adrDaerah &P){

    if(P == NULL)
            return;


    /// P Pasti Ada dalam List
    DeleteDaerahInList(L2 , P);
    adrDaerah R;
    R = First(L1);

    while(R != P){
        ///Looping tidak infinity karena P pasti ada di dalam List
        R = Next(R);
    }

    if(Next(R) == NULL){
        ///jika data yg dihapus adalah elm terakhir
        adrDaerah S;
        S = Prev(R);
        if(R != First(L1)){
            ///jika dia di urutan terakhir z!= NULL
            Next(S) = NULL;
        }else{
            ///jika dia 1 elm
            First(L1) = NULL;
        }
        Last(L1) = S;
    }else{
        ///jika dia elm bukan di akhir
        if(R == First(L1)){
            ///jika dia elm pertama
            First(L1) = Next(R);
            Prev(First(L1)) = NULL;
        }else{
            ///jika dia bukan elm pertama
            adrDaerah S = Prev(R);
            Next(S) = Next(R);
        }
    }

    R = NULL;
    DealocateDaerah(P);
}


///Mencari Address Berdasarkan Nama
adrDaerah FindDaerah(List_Daerah L , string Nama){
    adrDaerah P;
    P = First(L);
    while(P!=NULL && Info(P).Nama != Nama){
        P = Next(P);
    }

    return P;

}
