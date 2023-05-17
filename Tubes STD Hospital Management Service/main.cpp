#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include "ListParent.h"
#include "ListRelasi.h"

void clearScreen() {
    system("cls");
}

void pressEnter() {
    cout<<"\nTekan ENTER . . .";
    cin.ignore(256, '\n');
    cin.get();
}

void mainMenu() {
    cout<<"================================================="<<endl;
    cout<<"==                                             =="<<endl;
    cout<<"==   Selamat Datang di aplikasi Data Berobat   =="<<endl;
    cout<<"==                                             =="<<endl;
    cout<<"================================================="<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"========================================================="<<endl;
    cout<<"==                                                     =="<<endl;
    cout<<"==        1) Data Pasien                               =="<<endl;
    cout<<"==        2) Data Riwayat Penyakit Pasien              =="<<endl;
    cout<<"==        3) Data Pasien Beserta Riwayat Penyakit      =="<<endl;
    cout<<"==        4) Cari data penyakit pasien                 =="<<endl;
    cout<<"==        5) Tukar data penyakit                       =="<<endl;
    cout<<"==        6) Keluar                                    =="<<endl;
    cout<<"==                                                     =="<<endl;
    cout<<"========================================================="<<endl;
    cout<<endl;
    cout<<"Masukkan pilihan : ";
}

int main(){
    List_parent LP;
    List_relasi LR;

    createList(LP);
    createList(LR);

    address_parent P;
    address_relasi R;

    string pasien,NamaPasien,i,penyakit;

    int numOut=1; //    just initial number
    int numPasien,numPenyakit,numUser,numPasiendanPenyakit;

    mainMenu();
    while (numOut!=999) {
        cin>>numUser;
        clearScreen();
        if (numUser == 1) {
            while (numOut!=999){
                cout<<"===== DATA PASIEN =====\n\n";
                cout<<"1. Tambah Nama pasien \n2. Lihat Pasien \n3. Perbarui Nama Pasien \n4. Hapus Nama Pasien \n5. Kembali"<<endl<<endl;
                cout<<"Masukkan Pilihan : ";
                cin>>numPasien;
                cout<<endl;
                if (numPasien == 1){
                    cout<<"Nama Pasien : ";
                    cin.ignore(256, '\n');
                    getline(cin,NamaPasien);
                    P=alokasi_parent(NamaPasien);
                    addPasien(LP,P);
                    cout<<"\n|| Penambahan Pasien Selesai ||"<<endl;
                    cout<<"\nPress Enter. . . ";
                    cin.get();
                    cout<<endl;
                } else if (numPasien ==2) {
                    cout<<endl;
                    cout<<"Daftar Pasien : "<<endl;
                    printInfoPasien(LP);
                    pressEnter();
                    cout<<endl;
                } else if (numPasien==3){ // update nama pasien
                    cout<<endl;
                    cout<<"Daftar Pasien : "<<endl;
                    printInfoPasien(LP);
                    cout<<"Masukkan Nama Pasien yang Akan Diperbarui : ";
                    cin.ignore(256, '\n');
                    getline(cin,pasien);
                    P=findPasien(LP,pasien);
                    cout<<"Nama Pasien yang Telah Diupdate : ";
                    getline(cin,pasien);
                    info(P).NamaPasien=pasien;
                    cout<<"\n|| Pembaruan Nama Pasien Selesai ||"<<endl;
                    cout<<"\nPress Enter. . . ";
                    cin.get();
                } else if (numPasien==4) {
                    cout<<endl;
                    cout<<"Daftar Pasien : "<<endl;
                    printInfoPasien(LP);
                    cout<<"Masukkan Nama Pasien yang Ingin Dihapus : ";
                    cin.ignore(256, '\n');
                    getline(cin,pasien);
                    deletePasien(LP,pasien,P);
                } else {
                    numOut=999;
                }
                clearScreen();
            }
            numOut=1;
        } else if (numUser == 2) {
            while (numOut!=999) {
                cout<<"===== DATA RIWAYAT PENYAKIT PASIEN =====\n\n";
                cout<<"1. Tambah Riwayat Penyakit Pasien \n2. Perbarui Riwayat Penyakit Pasien \n3. Hapus Riwayat Penyakit Pasien \n4. Pasien Yang Telah Diinput Riwayat Penyakitnya \n5. Pasien Yang Belum Diinput Riwayat Penyakitnya \n6. Kembali"<<endl<<endl;
                cout<<"Masukkan Pilihan : ";
                cin>>numPenyakit;
                if (numPenyakit==1) {
                    cout<<"Nama Pasien : "<<endl;
                    printInfoPasien(LP);
                        if (first(LP)!=NULL) {
                            cout<<"Masukkan Nama Pasien : ";
                            cin.ignore(256, '\n');
                            getline(cin,pasien);
                            P=findPasien(LP,pasien);
                            cout<<"Masukkan Riwayat Penyakit Pasien : ";
                            getline(cin,penyakit);
                            R=alokasi_relasi(P,penyakit);
                            addRelasi(LR,R);
                            info(P).jumPenyakit+=1;
                            cout<<"\n|| Penambahan Riwayat Penyakit Selesai ||"<<endl;
                            cout<<"\nPress Enter. . . ";
                            cin.get();
                            cout<<endl;
                        } else {
                            cout<<"Pasien belum ditambahkan"<<endl<<endl;
                        }
                } else if(numPenyakit==2) { // update riwayat penyakit pasien
                    cout<<endl;
                    R=first(LR);
                    while (R!=NULL) {
                        if (parent(R)==P) {
                            cout<<"### "<<info(parent(R)).NamaPasien<<endl;
                            cout<<"    "<<penyakit(R)<<endl;
                        }
                    R=next(R);
                    }
                    cout<<"\nMasukkan Nama Pasien yang Ingin diubah Riwayat Penyakitnya : ";

                    cin.ignore(256, '\n');
                    getline(cin,pasien);
                    P=findPasien(LP,pasien);
                    R=findPenyakit2(LR,P);
                    deleteRelasi(LR,penyakit(R),R);

                    cout<<"Masukkan Riwayat Penyakit yang Baru : ";


                    getline(cin,penyakit);
                    R=alokasi_relasi(P,penyakit);
                    addRelasi(LR,R);
                    info(P).jumPenyakit+=1;

                    cout<<"|| Pembaruan Riwayat Penyakit Selesai ||"<<endl;
                    cout<<"\nPress Enter. . . ";
                    cin.get();
                    cout<<endl;
                } else if (numPenyakit==3) {
                    cout<<endl;
                    cout<<"Nama Pasien : "<<endl;
                    printInfoPasien(LP);
                    cout<<"Ingin Hapus Riwayat Penyakit Pasien Siapa? ";
                    cin.ignore(256, '\n');
                    getline(cin,pasien);
                    P=findPasien(LP,pasien);
                    R=findPenyakit2(LR,P);
                    deleteRelasi(LR,penyakit(R),R);
                    cout<<"\n|| Riwayat Penyakit "<<pasien<<" Telah Dihapus ||"<<endl;
                    cout<<"\nPress Enter. . . ";
                    cin.get();
                    cout<<endl;
                } else if (numPenyakit==4) {

                    cout<<endl;

                    R=first(LR);
                    while (R!=NULL) {
                        if (parent(R)==P) {
                            cout<<"### "<<info(parent(R)).NamaPasien<<endl;
                            cout<<"    "<<penyakit(R)<<endl;
                        }
                        R=next(R);
                    }
                    pressEnter();
                } else if (numPenyakit==5) {
                    cout<<endl;
                    P=first(LP);
                    R=first(LR);
                    while (P!=NULL) {
                        while (R!=NULL) {
                            if  (parent(R)==P) {
                                break;
                            }
                            R=next(R);
                        }
                        if (R==NULL){
                            cout<<info(P).NamaPasien<<endl;
                        }
                        R=first(LR);
                        P=next(P);
                    }
                    pressEnter();
                }else {
                    numOut=999;
                }
                clearScreen();
            }
            numOut=1;
        } else if (numUser == 3) { // show data from parent and child
            cout<<"===== DATA PASIEN BESERTA RIWAYAT PENYAKIT =====\n\n";
            cout<<"1. Lihat Riwayat Penyakit Berdasarkan Pasien \n2. Lihat Pasien dan Riwayat Penyakit Berdasarkan Jumlah Riwayat Penyakitnya"<<endl<<endl;
            cout<<"Masukkan Pilihan : ";
            cin>>numPasiendanPenyakit;
            clearScreen();
            if (numPasiendanPenyakit == 1){
                cout<<endl;
                printPenyakitByPasien(LR,LP);
                pressEnter();
            } else if (numPasiendanPenyakit == 2) {
                PrintPenyakitByNumber(LR,LP);
                pressEnter();
            }
        } else if(numUser == 4) {
            cout << "\nMasukkan Nama Pasien yang Ingin dicari Penyakitnya : ";
            cin.ignore(256, '\n');
            getline(cin,pasien);
            P=findPasien(LP,pasien);
            cout<<"\nMasukkan Penyakit yang Ingin dicari : ";
            cin >> penyakit;
            R=findPenyakit3(LR,P,penyakit);
            cout<<info(P).NamaPasien<<" => "<<penyakit(R)<<endl;
            pressEnter();
        } else if (numUser == 5) {
            cout << "\nMasukkan Nama Pasien Pertama yang Ingin dipindahkan Riwayat Penyakitnya : ";
            string pasien1, pasien2;
            address_parent Q;
            cin.ignore(256, '\n');
            getline(cin,pasien1);
            P=findPasien(LP,pasien1);
            cout << "\nMasukkan Nama Pasien Kedua : ";
            cin >> pasien2;
            Q=findPasien(LP,pasien2);
            cout << "1" << endl;
            pindahRelasi(LR,P,Q);
            pressEnter();
        } else if (numUser == 6) {
            cout<<"Kamu telah keluar dari aplikasi Data Berobat"<<endl;
            pressEnter();
            numOut=999;
        } else {
            cout<<"OOPPSS!! Salah Memasukkan Angka"<<endl;
            pressEnter();
            cin.get();
        }
        clearScreen();
        mainMenu();
    }
    clearScreen();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t   ======== [[[[[ TERIMA KASIH  ]]]]] ========"<<endl<<endl;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    return 0;
}
