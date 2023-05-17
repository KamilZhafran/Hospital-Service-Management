#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED

#include "ListParent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define parent(P) P->parent
#define penyakit(P) P->penyakit

typedef struct elmlist_relasi *address_relasi;


struct elmlist_relasi{
    address_relasi next;
    address_parent parent;
    string penyakit;
};

struct List_relasi{
    address_relasi first;
};

void createList(List_relasi &L);
void addRelasi(List_relasi &L, address_relasi R);
void deleteFirst(List_relasi &L, address_relasi &R);
void deleteLast(List_relasi &L, address_relasi &R);
void deleteRelasi(List_relasi &L, string x, address_relasi &R);
void pindahRelasi(List_relasi &LR, address_parent P, address_parent Q);
void printInfoRelation(List_relasi L);
void PrintPenyakitByNumber(List_relasi LR,List_parent LP);
void printPenyakit(List_relasi L);
void printPenyakitByPasien(List_relasi LR,List_parent LP);
address_relasi alokasi_relasi(address_parent P, string x);
address_relasi findPenyakit(List_relasi LR, string x);
address_relasi findPenyakit2(List_relasi LR, address_parent P); // untuk menghapus ulasan
address_relasi findPenyakit3(List_relasi LR, address_parent P, string penyakit); // untuk menghapus ulasan


#endif // LISTRELASI_H_INCLUDED
