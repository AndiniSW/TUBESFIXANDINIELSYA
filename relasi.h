#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "parent.h"
#include "child.h"
#include<iostream>
using namespace std;

#define firstR(L) L.first
#define nextR(P) P->nextR
#define lastR(L) L.last
#define prevR(P) P->prevR

typedef struct elmListR *addressR;
struct elmListR{
    addressR nextR;
    addressR prevR;
    addressP P;
    addressC Q;
};

struct ListR{
    addressR first;
    addressR last;
};

void createListR(ListR &L);
addressR alokasi(addressP P, addressC C);
void dealokasiR(addressR &P);
void insertFirstR(ListR &L, addressR P);
void insertLastR(ListR &L, addressR P);
void insertAfterR(ListR &L, addressR P);
addressR findElmSosialdanMahasiswa(ListR L, addressP P, addressC C);
void deleteFirstR(ListR &L, addressR &P);
void deleteLastR(ListR &L, addressR &P);
void deleteAfterR(ListR &L, addressR &Prec, addressR &P);
void printInfoR(ListR L);

#endif // RELASI_H_INCLUDED
