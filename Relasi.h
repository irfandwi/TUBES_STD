#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "DataDaerah.h"

void InsertFirst_Relasi(List_Relasi &L , adrRelasi P);
void InsertLast_Relasi(List_Relasi &L , adrRelasi P);
void InsertAfter_Relasi(List_Relasi &L , adrRelasi prec , adrRelasi P);
void DealocateRelasi(adrRelasi &P);
void Delete_Relasi(List_Relasi &L , adrRelasi P);


adrRelasi SearchDaerah(List_Relasi L , adrDaerah Dae);
adrRelasi SearchPotensi(List_Relasi L , adrPotensi Pot);
adrRelasi SearchDaerahPotensi(List_Relasi L , adrDaerah Dae , adrPotensi Pot);

void DeleteDaerahInList(List_Relasi &L , adrDaerah P );
void DeletePotensiInList(List_Relasi &L , adrPotensi P );

adrDaerah getTerkaya(List_Relasi L , List_Daerah D);
adrDaerah getTermiskin(List_Relasi L , List_Daerah D);
int getKekayaan(List_Relasi L , adrDaerah D);




#endif // RELASI_H_INCLUDED
