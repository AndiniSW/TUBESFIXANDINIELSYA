//elsya putri sutomo 1301164201
#ifndef APLIKASI_H_INCLUDED
#define APLIKASI_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
// #include <conio.h>
#include "child.h"
#include "parent.h"
#include "relasi.h"

using namespace std;

void menu(ListP Lp, ListC L, ListR Lr);
void insert_parent(ListP &L);
void insert_child(ListC &L);
void insert_relasi(ListR &R, ListP P, ListC C);
void view_parent(ListP L);
void view_child(ListC L);
void search_parent(ListP P);
void search_child(ListC P);
void view_relasi(ListR L);
void search_relasi(ListR R, ListP P, ListC C);
void putus_relasi(ListR &R, ListP P, ListC C);
void delete_parent(ListP &L, ListR &Lr);
void delete_child(ListC &L, ListR &Lr);
void sort_relasi(ListR &L);
void exit();


#endif // APLIKASI_H_INCLUDED
