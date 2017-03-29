//andini salimah 1301164080
#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include<iostream>
using namespace std;

#define firstC(L) L.first
#define nextC(P) P->next
#define lastC(L) L.last
#define prevC(P) P->prev
#define infoC(P) P->info

struct infotypeC{
    string id;
    string nama;
    string nim;
    string email;
    string alamat;
    string nomorhape;
};

typedef struct elmListC *addressC;
struct elmListC {
    infotypeC info;
    addressC next;
    addressC prev;
};

struct ListC{
    addressC first;
    addressC last;
};

void createListC(ListC &L);
addressC alokasi(infotypeC x);
void dealokasiC(addressC &P);

void insertFirstC(ListC &L, addressC P);
void insertAfterC(ListC &L, addressC Prec, addressC P);
void insertLastC(ListC &L, addressC P);

void deleteFirstC(ListC &L, addressC &P);
void deleteLastC(ListC &L, addressC &P);
void deleteAfterC(ListC &L, addressC Prec, addressC &P);

addressC findElm(ListC L, infotypeC x);
void printInfoC(ListC L);

#endif // CHILD_H_INCLUDED
