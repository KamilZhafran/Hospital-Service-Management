#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct infotype_parent{
    string NamaPasien;
    int jumPenyakit;
};
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;

};

struct List_parent {
    address_parent first;
};

void createList(List_parent &L);
void addPasien(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deletePasien(List_parent &L, string x, address_parent &P);
void printInfoPasien(List_parent L);
address_parent alokasi_parent(string x);
address_parent findPasien(List_parent L, string x);

#endif // LISTPARENT_H_INCLUDED
