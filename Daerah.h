#ifndef DAERAH_H_INCLUDED
#define DAERAH_H_INCLUDED
#include"DataDaerah.h"

void InsertFirst_Daerah(List_Daerah &L , adrDaerah P);
void InsertLast_Daerah(List_Daerah &L , adrRelasi P);
void DealocateDaerah(adrDaerah &P);
void Delete_Daerah(List_Daerah &L1 , List_Relasi &L2, adrDaerah &P);
adrDaerah FindDaerah(List_Daerah L , string Nama);



#endif // DAERAH_H_INCLUDED
