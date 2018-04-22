#include "Relasi.h"

//InsertFirst
void InsertFirst_Relasi(List_Relasi &L , adrRelasi P){
    Next(P) = First(L);
    First(L) = P;
}

//InsertLast
void InsertLast_Relasi(List_Relasi &L , adrRelasi P){
    adrRelasi  q;
    q = First(L);
    while(q != NULL && Next(q) != NULL){
        q = Next(q);
    }
    if(q != NULL){
        Next(q) = P;
    }else{
        First(L) = P;
    }

}

//InsertAfter
void InsertAfter_Relasi(List_Relasi &L , adrRelasi prec , adrRelasi P){
    if(prec == NULL){
        InsertLast_Relasi(L , P);
    }else{
        Next(P) = Next(prec);
        Next(prec) = P;
    }
}

//Dealokasi
void DealocateRelasi(adrRelasi &P){
    Next(P) = NULL;
    delete(P);
    P = NULL;
}

///Menghapus Data di List
void Delete_Relasi(List_Relasi &L , adrRelasi P){

    if(P != NULL){
        adrRelasi R;
        R = NULL;
        adrRelasi S;
        S = First(L);
        while(S != P){
            R = S;
            S = Next(S);
        }
        if(R != NULL){
            ///jika P elm terakhir maka next z akan bernilai null
            Next(R) = Next(P);
        }else{
            First(L) = Next(P);
        }
        DealocateRelasi(P);
    }else
        return;
}

//Searching Daerah
adrRelasi findRelasiPotensi(List_Relasi L, adrPotensi P){
    adrRelasi Q = First(L);
    while ((Q) != First(L)){
        if(Info(Rpotensi(Q)).SumberDaya == Info(P).SumberDaya){
            return Q;
        }
        Q = RNext(Q);
    }
    if(Info(Rpotensi(Q)).SumberDaya == Info(P).SumberDaya){
        return Q;
    }
}



//Menghapus Semua elm yang terdapat toko
void DeleteDaerahInList(List_Relasi &L , adrDaerah P ){
    adrRelasi R;
    R = First(L);
    while(R != NULL){
        if(Rdaerah(R) == P){
            adrRelasi S;
            S = R;
            R = Next(R);
            Delete_Relasi( L , S);
        }else{
            R = RNext(R);
        }
    }

}

///mengahpus semua elm yang terdapat barang
void DeletePotensiInList(List_Relasi &L , adrPotensi P ){
    adrRelasi R;
    R = First(L);
    while(R != NULL){
        if(Rpotensi(R) == P){
            adrRelasi S;
            S = R;
            R = RNext(R);
            Delete_Relasi( L , S);
        }else{
            R = RNext(R);
        }
    }

}
//BARU SAMPAI SINI!!!!!!!!!!!!!!!!!!!!__-------------------------------------------------------------------------



