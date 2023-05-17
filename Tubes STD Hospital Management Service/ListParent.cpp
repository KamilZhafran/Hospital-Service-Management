#include "ListParent.h"

void createList(List_parent &L){
    first(L) = NULL;
};

void addPasien(List_parent &L, address_parent P){ //insert parent
    if (first(L)==NULL) {
        first(L)=P;
    } else {
        address_parent Q=first(L);
        while (next(Q)!=NULL){
            Q=next(Q);
        }
        next(Q)=P;
    }
};

void deleteFirst(List_parent &L, address_parent &P){ //delete parent
    if (first(L)==NULL) {
        cout<<"List is Empty"<<endl;
    } else {
        P=first(L);
        if (next(first(L))==NULL) {
            first(L)=NULL;
        } else {
            first(L)=next(P);
            next(P)=NULL;
        }
    }
};

void deleteLast(List_parent &L, address_parent &P){ //delete parent
    if (first(L)==NULL) {
        cout<<"List is Empty"<<endl;
    } else {
        if (next(first(L))==NULL){
            P=first(L);
            first(L)=NULL;
        } else {
            address_parent Q=first(L);
            while (next(next(Q))!=NULL) {
                Q=next(Q);
            }
            P=next(Q);
            next(Q)=NULL;
        }
    }
};

void deletePasien(List_parent &L, string x, address_parent &P){ //delete parent
    address_parent Q=first(L);
    if (Q!=NULL) { //checking list is empty or not
        if (info(Q).NamaPasien==x){
            deleteFirst(L,P);
        } else {
            while (next(Q)!=NULL&&info(next(Q)).NamaPasien!=x) {
                Q=next(Q);
            }
            if (next(Q)==NULL){
                cout<<"Data not Found"<<endl;
            } else {
                if (next(next(Q))==NULL){
                    deleteLast(L,P);
                } else if (info(next(Q)).NamaPasien==x) {
                    P=next(Q);
                    next(Q)=next(P);
                    next(P)=NULL;
                }
            }
        }
    } else {
        cout<<"List is Empty"<<endl;
    }
};

void printInfoPasien(List_parent L){ //show parent
    address_parent Q = first(L);
    if (first(L)==NULL) {
        cout<<"List is Empty";
    } else {
        while (Q!=NULL) {
            cout<<info(Q).NamaPasien<<endl;
            Q=next(Q);
        }
    }
    cout<<endl;
};

address_parent alokasi_parent(string x){ // membuat elemen baru
    address_parent P;
    P = new elmlist_parent;
    info(P).NamaPasien = x;
    info(P).jumPenyakit=0;
    next(P) = NULL;
    return P;
};

address_parent findPasien(List_parent L, string x){ // find parent
    address_parent Q=first(L);
    while (Q!=NULL&&info(Q).NamaPasien!=x) {
        Q=next(Q);
    }
    if (Q==NULL){
        cout<<"Not Found"<<endl;
    } else {
        return Q;
    }
};
