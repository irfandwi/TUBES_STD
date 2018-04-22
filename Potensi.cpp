#include "Potensi.h"

///Memasukan Data Kedalam List Dari Depan
void InsertFirst_Potensi(List_Potensi &L , adrPotensi P){
    if(First(L)==NULL){
        First(L) = P;
        Next(P) = P;
        Last(L) = P;
    }else{
        Next(P) = First(L);
        Next(Last(L)) = P;
        First(L) = P;
    }
}

///Memasukan Data Kedalam List Dari Belakang
void InsertLast_Potensi(List_Potensi &L , adrPotensi P){
    if(Last(L) == NULL){
        ///Jika List Kosong
        Next(P) = P;
        First(L) = P;
        Last(L) = P;
    }else{
        ///Jika dia Ada Isisnya
        Next(Last(L)) = P;
        Last(L) = P;
        Next(P) = First(L);
    }
}

///Menghapus Data Dari Memory
void DealocatePotensi(adrPotensi &P){
    Next(P) = NULL;
    delete(P);
    P = NULL;
}

void PrintPotensi(List_Potensi L){

    if(First(L) != NULL){
        adrPotensi p = First(L);

        do{

            cout<<" "<<endl;
            adrPotensi p = Next(p);
        }while(p != First(L));
            cout<<Info(P).SumberDaya<<endl;
            cout<<Info(P).Penghasilan<<endl;

    }

}

///Menghapus Data P di List L
void Delete_Potensi(List_Potensi &L1 , List_Relasi &L2 , adrPotensi &P){

    if(P == NULL){
            return;
    }

    /// P Pasti Ada dalam List
    DeletePotensiInList(L2 , P);

    adrPotensi R;
    adrPotensi S;
    S = First(L1);
    while(S != P){
        ///Tidak Mungkin Infinity loop karna P ada di List
        R = S;
        S = Next(S);
    }


    if(S == First(L1)){
        ///artinya P elm pertama
        if(Next(P) == P){
            ///List  1 elm
            First(L1) = NULL;
            Last(L1) = NULL;
        }else{
            ///list >1 elm
            First(L1) = Next(P);
            Next(Last(L1)) = First(L1);
        }
    }else if(S == Last(L1)){
        ///jika P == Last(L) maka z != NULL
        Next(R) = First(L1);
        Last(L1) = R;
    }else{
        ///P di tengah maka z != NULL
        Next(R) = Next(S);
    }
    S = NULL;
    DealocatePotensi(P);
}


///Mencari Address Berdasarkan Nama
adrPotensi FindPotensi(List_Potensi L , string SumberDaya){
    if(First(L)==NULL)
        return NULL;


    adrPotensi P;
    P = First(L);
    //cout<<"tes"<<endl;
    while(P!=Last(L) && Info(P).SumberDaya != SumberDaya){
        P = Next(P);
        //cout<<Info(P).Nama<<endl;
    }
    //cout<<P<<endl;
    if(Info(P).SumberDaya == SumberDaya){
        return P;
    }else{
        return NULL;
    }

}
