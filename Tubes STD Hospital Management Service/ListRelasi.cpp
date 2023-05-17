#include "ListRelasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi_relasi(address_parent P,string x) { //membuat relasi antara parent dan child
    address_relasi Q = new elmlist_relasi;
    parent(Q) = P; // yang membentuk/membuat relasi
    penyakit(Q)=x;
    next(Q) = NULL;
    return Q;
}

void addRelasi(List_relasi &L, address_relasi R) { // insert child of parent
    if (first(L)==NULL) {
        first(L)=R;
    } else {
        address_relasi Q=first(L);
        while (next(Q)!=NULL){
            Q=next(Q);
        }
        next(Q)=R;
    }
}

void printInfoRelation(List_relasi L) { // show child of parent x
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<penyakit(P)<<" => "<<info(parent(P)).NamaPasien<<endl;
        P = next(P);
    }
}

void printReview(List_relasi L){ // show semua riwayat penyakit
    address_relasi P=first(L);
    while (P!=NULL) {
        cout<<penyakit(P)<<endl;
        P=next(P);
    }
    cin.ignore(256,'\n');
    cin.get();
}

address_relasi findPenyakit(List_relasi LR, string x){ //find child of parent x (mencari riwayat penyakit menggunakan string)
    address_relasi Q=first(LR);
    while (Q!=NULL&&penyakit(Q)!=x){
        Q=next(Q);
    }
    if (Q==NULL) {
        cout<<"Not Found"<<endl;
        return Q;
    } else {
        return Q;
    }
}

address_relasi findPenyakit2(List_relasi LR, address_parent P){ //find child of parent x (mencari riwayat penyakit menggunakan pointer)
    address_relasi Q=first(LR);
    while (Q!=NULL && parent(Q)!=P) {
        Q=next(Q);
    }
    return Q;
}

address_relasi findPenyakit3(List_relasi LR, address_parent P, string penyakit) {
    address_relasi Q=first(LR);
    while (Q!=NULL && parent(Q)!=P && penyakit(Q)!=penyakit) {
        Q=next(Q);
    }
    return Q;
}

void deleteFirst(List_relasi &L, address_relasi &P){ //delete child of parent x
    if (first(L)==NULL) {
        cout<<"List is Empty"<<endl;
    } else {
        P=first(L);
        if (next(first(L))==NULL) {
            parent(first(L))=NULL;
            first(L)=NULL;
        } else {
            first(L)=next(P);
            parent(P)=NULL;
            next(P)=NULL;
        }
    }
}
void deleteLast(List_relasi &L, address_relasi &P){ //delete child of parent x
    if (first(L)==NULL) {
        cout<<"List is Empty"<<endl;
    } else {
        if (next(first(L))==NULL){
            P=first(L);
            parent(P)=NULL;
            first(L)=NULL;
        } else {
            address_relasi Q=first(L);
            while (next(next(Q))!=NULL) {
                Q=next(Q);
            }
            P=next(Q);
            parent(P)=NULL;
            next(Q)=NULL;
        }
    }
}
void deleteRelasi(List_relasi &L, string x, address_relasi &P){ //delete child of parent x dan menghapus relasi antara parent dan child
    address_relasi Q=first(L);
    if (Q!=NULL) { //checking list is empty or not
        if (penyakit(Q)==x){
            deleteFirst(L,P);
        } else {
            while (next(Q)!=NULL&&penyakit(next(Q))!=x) {
                Q=next(Q);
            }
            if (next(Q)==NULL){
                cout<<"Data not Found"<<endl;
            } else {
                if (next(next(Q))==NULL){
                    deleteLast(L,P);
                } else if (penyakit(next(Q))==x) {
                    P=next(Q);
                    next(Q)=next(P);
                    parent(P)=NULL;
                    next(P)=NULL;
                }
            }
        }
    } else {
        cout<<"List is Empty"<<endl;
    }
}

void pindahRelasi(List_relasi &LR, address_parent P, address_parent Q) {
    address_relasi R=first(LR);
    if (R!=NULL) { //checking list is empty or not
        while (R!=NULL) {
            if (parent(R)==P) {
                parent(R)=Q;
            }
            R=next(R);
        }
    } else {
        cout<<"List is Empty"<<endl;
    }
}

void printPenyakitByPasien(List_relasi LR, List_parent LP){ // show child of parent x (memunculkan apa saja penyakit yg diidap pasien)
    address_parent P=first(LP);
    address_relasi R=first(LR);
    int i = 1;
    while (P!=NULL) {
        cout<<i<<". "<<info(P).NamaPasien<<" : "<<endl;
        while (R!=NULL){
            if (parent(R)==P) {
                cout<<"   "<<penyakit(R)<<endl;
            }
            R=next(R);
        }
        R=first(LR);
        P=next(P);
        i++;
    }
}

void PrintPenyakitByNumber(List_relasi LR,List_parent LP){ // show child of parent x (riwayat penyakit yg sama yg dimiliki oleh pasien)
    address_parent P;
    address_relasi R;
    P=first(LP);
    int maxPenyakit=info(P).jumPenyakit;
    while (P!=NULL) { // mencari maxPenyakit sebgai batas dari perulangan
        if (maxPenyakit<info(P).jumPenyakit){
            maxPenyakit=info(P).jumPenyakit;
        }
        P=next(P);
    }
    P=first(LP);
    for (int i=maxPenyakit;i>=1;i--) {
        while (P!=NULL) {
            if (i==info(P).jumPenyakit) {
                cout<<"### "<<info(P).NamaPasien<<endl;
                R=first(LR);
                for (int j=1;R!=NULL; ) {
                    if (parent(R)==P) {
                        cout<<"  "<<j<<". "<<penyakit(R)<<endl;
                        j++;
                    }
                    R=next(R);
                }
                R=first(LR);
            }
            P=next(P);
        }
        P=first(LP);
    }
}

