#ifndef POTENSI_H_INCLUDED
#define POTENSI_H_INCLUDED
#include "DataDaerah.h"
#include "Relasi.h"
void InsertFirst_Potensi(List_Potensi &L , adrPotensi P);
void InsertLast_Potensi(List_Potensi &L , adrPotensi P);
void DealocatePotensi(adrPotensi &P);
void Delete_Potensi(List_Potensi &L1 , List_Relasi &L2 , adrPotensi &P);
adrPotensi FindPotensi(List_Potensi L , string SumberDaya);
void PrintPotensi(List_Potensi L);



#endif // POTENSI_H_INCLUDED
