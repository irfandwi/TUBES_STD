#include"menu.h"



void menu(int &ans){
    system("CLS");
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                     APLIKASI DATA JALAN PERKOTAAN                                     |" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << " Main Menu : " <<endl;
    cout << " 1.  Tambah Kota" <<endl;
    cout << " 2.  Hapus Kota" <<endl;
    cout << " 3.  Tambah Jalan" <<endl;
    cout << " 4.  Hapus Jalan" <<endl;
    cout << " 5.  Sambungkan Potensi Ke Daerah" <<endl;
    cout << " 6.  Smabungkan Daerah Ke Potensi" <<endl;
    cout << " 7.  Tampilkan Seluruh Data Daerah Beserta Potensinya" <<endl;
    cout << " 8.  Tampilkan Data Daerah Dengan Potensi Tertentu" <<endl;
    cout << " 9.  Tampilkan Data Potensi Dengan Daerah Tertentu" <<endl;
    cout << " 10. Tampilkan Data Daerah Yang Paling Kaya Dan Miskin" <<endl;
    cout << " 11. Exit" <<endl;

    do{
        cout << " Pilih Menu : "; cin>>ans;
    }while(ans > 14 || ans <= 0);

}

//1.  Tambah Kota
void addDaerah(List_Daerah &K){
     string namaDaerah;
     char lagi='Y';
     cout << " Menu Tambah Daerah " <<endl;
    do{
        cout << " Masukan Nama Daerah : ";
        getline(cin, namaDaerah);
        adrDaerah P = FindDaerah(K, namaDaerah);
        if(P==NULL){  //data belum ada
            int jumlahPdk;
            string provinsi;
            cout<<" Masukkan Jumlah Penduduk Daerah "<<endl;
            cin>>jumlahPdk;
            cout<<" Masukkan Provinsi "<<endl;
            cin>>provinsi;
            P = Allocate_Daerah(namaDaerah , jumlahPdk , provinsi);
            InsertFirst_Daerah(K, P);
            cout << " Data Daerah berhasil dimasukan" <<endl;
        }else{
            cout << " Data sudah ada !"<<endl;
        }
        cout<<" Ingin Memasukan Data Daerah Lagi?[Y/T] : ";cin>>lagi;
        cout<<endl;
    }while(lagi == 'Y' || lagi == 'y');
}

//2.  Hapus Kota
void DeleteDaerah(List_Relasi &R,List_Daerah &K){
    cout<<" Menu Hapus Kota "<<endl;
    string lagi,tampil,namaDaerah;
    //mengeluarkan semua data barang
    if(First(K)!=NULL){
        cout<<" Ingin Menampilkan seluruh Data Daerah?[Y/T] : ";cin>>tampil;
        if(tampil == "Y" || tampil == "y"){
            PrintDaerah(K);
        }
        do{
            cout<<" Masukan Nama Daerah Yang Ingin Dihapus : ";cin>>namaDaerah;
            adrDaerah P = FindDaerah(K , namaDaerah);
            if(P!= NULL){
                DeleteDaerahInList(R , P);
                cout<<" Daerah Berhasil Dihapus"<<endl;
            }else{
                cout<<" Maaf Data Tidak Ada"<<endl;
            }
            cout<<endl;
            cout<<" Apakah Anda Ingin Menghapus kota Lagi?[Y/T] : ";cin>>lagi;
        }while(lagi == "Y" || lagi == "y");
    }else{
        cout<<" List masih kosong"<<endl;
    }
}

//3.  Tambah Jalan
void addPotensi(List_Potensi &L){
    string SumberDaya;
    int Penghasilan;
    char tambah='Y';
    cout<<" Menu Tambah Potensi"<<endl;
    do{
        cout<<" Masukan Sumberdaya Daerah : ";cin>>Sumberdaya;
        cout<<" Masukan Penghasilan Daerah : ";cin>>Penghasilan;
        adrPotensi P = FindPotensi(L , SumberDaya);
        if (P == NULL) {
            P = Allocate_Potensi(SumberDaya, Penghasilan);
            InsertLast_Potensi(L , P);
            cout<<" Anda telah Menambahkan Data Potensi "<<endl;
        }else {
            cout<<" Data Sudah Ada "<<endl;
        }
        cout<<" Apakah anda ingin menambah Data Potensi lagi ? [Y/T] : ";cin>>tambah;
        cout<<endl;
    }while (tambah == 'Y' || tambah == 'y');
}

//4. Hapus jalan
void DeletePotensi(List_Relasi &J,List_Potensi &R){
    cout<<" Hapus Potensi "<<endl;
    string lagi,tampil,SumberDaya;
    if(First(J)!=NULL){
        cout<<" Ingin Menampilkan seluruh Data Potensi?[Y/T] : ";cin>>tampil;
        if(tampil == "Y" || tampil == "y"){
            PrintPotensi(R);
        }
        do{
            cout<<endl<<" Masukan Nama Potensi Yang Ingin Dihapus : ";cin>>SumberDaya;
            adrPotensi P = FindPotensi(R , SumberDaya);
            if(P!= NULL){
                DeletePotensiInList(J , P);
                cout<<" Potensi Berhasil Dihapus"<<endl;
            }else{
                cout<<" Maaf Data Tidak Ada"<<endl;
            }
            cout<<endl;
            cout<<" Apakah Anda Ingin Menghapus Potensi Lagi?[Y/T] : ";cin>>lagi;
        }while(lagi == "Y" || lagi == "y");
    }else{
        cout<<" List masih kosong"<<endl;
    }
}
void menuOutputDaerah(List_Daerah K){
    if(First(K)!=NULL&&Last(K)!=NULL){
        PrintDaerah(K);
        cout<<endl;
    }else{
        cout<<" List Daerah masih kosong"<<endl;
    }
}
void menuOutputPotensi(List_Potensi J){
    if(First(J)!=NULL){
        PrintPotensi(J);
        cout<<endl;
    }else{
        cout<<" List Jalan masih kosong"<<endl;
    }
}


//tambah jalan ke kota menu 5
void menuSambungPotensiKeDaerah(List_Daerah K, List_Potensi J, List_Relasi &R){
    string SumberDaya;
    string namaDaerah;
    char tambah='Y';
    if(First(J) != NULL && First(K) != NULL){
        cout<<" Sambungkan Potensi Ke Daerah"<<endl;
        do{
            char tl;//tampil semua list
            cout<< " Tampilkan List jalan dan List Kota [Y/T] : ";cin>>tl;
            if(tl=='y'||tl=='Y'){
                cout<<endl<< " List Potensi : "<<endl;
                PrintPotensi(J);
                cout<<endl<<"--------------------------------------------------------------"<<endl;
                cout<< " List Daerah : "<<endl;
                PrintDaerah(K);
                cout<<endl;
            }
            cout<<" Masukan Nama Jalan : ";cin>>namajln;
            cout<<" Masukan Nama Kota : ";cin>>namakota;
            adrJalan P = findNamaJalan(J, namajln);
            adrKota Q = findNamaKota(K, namakota);
            if (P != NULL && Q != NULL) {
                adrRelasi A = allocateRelasi(Q,P);
                if(isExist(R,A)){
                    insertLastRelasi(R, A);
                    cout<<" Anda telah Merelasikan Jalan "<<namajln<< " Ke Kota "<<namakota<<endl;
                }else{
                    cout<<" List sudah ada"<<endl;
                }
            }else {
                cout<<" Data tidak ditemukan"<<endl;
            }
            cout<<" Apakah anda ingin menambah Jalan ke kota lagi [Y/T] : ";cin>>tambah;
            cout<<endl;
        }while (tambah == 'Y' || tambah == 'y');
    }else{
        cout<<" List kota atau list jalan masih kosong"<<endl;
    }
}

//tambah kora ke jalan menu 6
void menuTambahKotaKeJalan(doubleList K, singgleList J, circularList &R){
    string namajln;
    string namakota;
    char tambah='Y';
    if(isEmpty(J)==false&&isEmpty(K)==false){
        cout<<" Tambah kota ke jalan"<<endl;
        do{
            char tl;//tampil semua list
            cout<< " Tampilkan List jalan dan List Kota [Y/T] : ";cin>>tl;
            if(tl=='y'||tl=='Y'){
                cout<< " List Kota : "<<endl;
                printDataKota(K);
                cout<<endl<<"--------------------------------------------------------------"<<endl;
                cout<<endl<< " List Jalan : "<<endl;
                printDataJalan(J);
                cout<<endl;
            }
            cout<<" Masukan Nama Kota : ";cin>>namakota;
            cout<<" Masukan Nama Jalan : ";cin>>namajln;
            adrJalan P = findNamaJalan(J, namajln);
            adrKota Q = findNamaKota(K, namakota);
            if (P != NULL && Q != NULL) {
                adrRelasi A = allocateRelasi(Q,P);
                if(isExist(R,A)){
                    insertLastRelasi(R, A);
                    cout<<" Anda telah Merelasikan Kota "<<namakota<< " Ke Jalan "<<namajln<<endl;
                }else{
                    cout<<" List sudah ada"<<endl;
                }
            }else {
                cout<<" Data tidak ditemukan"<<endl;
            }
            cout<<" Apakah anda ingin menambah Kota ke Jalan lagi [Y/T] : ";cin>>tambah;
            cout<<endl;
        }while (tambah == 'Y' || tambah == 'y');
    }else{
        cout<<" List kota atau list jalan masih kosong"<<endl;
    }
}
//9.  Tampilkan Seluruh Data Jalan dan Kota(print relasi)
void menuAllTampil(List_Relasi L){
    Print_AllDaerahDanPotensi(L);
}
//10. Tampilkan Data Kota yang memiliki jalan(cari)
void menuTampilDaerahInPotensiTertentu(List_Potensi R, List_Relasi J){
    string SumberDaya;
    char lagi='Y';
    if(First(R) != NULL){
            cout<<" Masukan Nama Jalan : ";cin>>SumberDaya;
            adrPotensi P = FindPotensi(R , SumberDaya);
            if (P != NULL){
                cout<<endl<<" List Potensi yang berelasi dengan Daerah "<<SumberDaya<<endl;
                Print_PotensiInDaerah(J , P)
            } else {
                cout<<" Data tidak ditemukan" <<endl;
            }
            cout<<" Apakah anda ingin menampilkan relasi Jalan lainya [Y/T] : ";cin>>lagi;
        }while(lagi=='Y' || lagi=='y');
    }else{
        cout <<" Belum ada relasi"<<endl;
    }
}

//11. Tampilkan Data Jalan yang dimiliki Kota(cari)
void menuTampilDataJalanYangAdaDiKota(circularList R, doubleList K){
    string namakota;
    char lagi='Y';
    if(isEmpty(R)==false){
        cout<<" List Nama Kota"<<endl;
        printDataKota(K);
        do{
            cout<<" Masukan Nama Kota : ";cin>>namakota;
            adrKota P = findNamaKota(K, namakota);
            if (P != NULL){
                cout<<endl<<" List jalan yang berelasi dengan kota "<<namakota<<endl;
                printRelasikota(R, P);
            } else {
                cout<<" Data tidak ditemukan" <<endl;
            }
            cout<<" Apakah anda ingin menampilkan relasi kota lainya [Y/T] : ";cin>>lagi;
        }while(lagi=='Y' || lagi=='y');
    }else{
        cout <<" Belum ada relasi"<<endl;
    }
}
//12. Tampilkan Data kota dan nama jalan dengan tipe jalan tertentu
void tampilDataKotaDanJalanDenganTipeJalanTertentu(circularList R, doubleList K, singgleList J){
    string tipeJalan;
    char lagi='Y';
    if(isEmpty(R)==false){
        cout<<" List Tipe Jalan"<<endl;
        printDataTipeJalan(J);
        cout<<endl;
        do{
            cout<<" Masukan Tipe Jalan : ";cin>>tipeJalan;
            adrJalan P = findTipeJalan(J, tipeJalan);
            if (P != NULL){
                cout<<endl<<" List Kota dan Jalan yang bertipe jalan "<<tipeJalan<<endl;
                //print
                //printDataTipeJalan(J);
            } else {
                cout<<" tipe jalan tidak ditemukan" <<endl;
            }
            cout<<" Apakah anda ingin menampilkan Data kota dan jalan dengan tipe Jalan lainya [Y/T] : ";cin>>lagi;
        }while(lagi=='Y' || lagi=='y');
    }else{
        cout <<" Belum ada relasi"<<endl;
    }
}
void coba(){
    singgleList jalanL = createSinggleList(jalanL);
    doubleList kotaL = createDoubleList(kotaL);
    circularList relasiL = createCircularList(relasiL);
    string kota[]={"nganjuk","jakarta ","bandung","kediri","jogja"};
    string jalan[]={"a","b","c"};
    string tipe[]={"tol","makadam","kenangan"};
    //kota 0
    adrKota K0 = allocateDataKota(kota[0]);
    tambahDataKota(kotaL,K0);
    //jalan 0
    adrJalan J0 = allocateDataJalan(jalan[0],tipe[2]);
    tambahDataJalan(jalanL,J0);
    //kota 1
    adrKota K1 = allocateDataKota(kota[1]);
    tambahDataKota(kotaL,K1);
    //jalan 1
    adrJalan J1 = allocateDataJalan(jalan[2],tipe[0]);
    tambahDataJalan(jalanL,J1);
    //kota 2
    adrKota K2 = allocateDataKota(kota[2]);
    tambahDataKota(kotaL,K2);
    //jalan 2
    adrJalan J2 = allocateDataJalan(jalan[2],tipe[2]);
    tambahDataJalan(jalanL,J2);
    //kota 0
    adrKota K3 = allocateDataKota(kota[3]);
    tambahDataKota(kotaL,K3);
    //jalan 0
    adrJalan J3 = allocateDataJalan(jalan[1],tipe[1]);
    tambahDataJalan(jalanL,J3);
    //kota 0
    adrKota K4 = allocateDataKota(kota[4]);
    tambahDataKota(kotaL,K4);
    //jalan 0
    adrJalan J4 = allocateDataJalan(jalan[0],tipe[0]);
    tambahDataJalan(jalanL,J4);
    //print kota
    cout<< "print kota"<<endl;
    printDataKota(kotaL);
    //print jalan
    cout<< "print jalan"<<endl;
    printDataJalan(jalanL);
    //relasi kota ke banyak jalan
    adrRelasi R0 = allocateRelasi(K0,J0);
    adrRelasi R1 = allocateRelasi(K0,J1);
    adrRelasi R2 = allocateRelasi(K0,J2);
    insertLastRelasi(relasiL,R0);
    insertLastRelasi(relasiL,R1);
    insertLastRelasi(relasiL,R2);
    //relasi banyak ke n
    adrRelasi R3 = allocateRelasi(K1,J1);
    adrRelasi R4 = allocateRelasi(K2,J1);
    adrRelasi R5 = allocateRelasi(K3,J1);
    insertLastRelasi(relasiL,R3);
    insertLastRelasi(relasiL,R4);
    insertLastRelasi(relasiL,R5);
    //print relasi
    cout<<"Print relasi"<<endl;
    printRelasi(relasiL);

    cout<<"hapus jalan relasi"<<endl;
    adrJalan J =findNamaJalan(jalanL,jalan[0]);//a
    cout<< Info(J).namaJalan<<endl;
    adrRelasi F =findRelasiJalan(relasiL,J);
    hapusDataJalan(jalanL,J);
    //cout<< "print jalan"<<endl;
    deleteRelasi(relasiL,F);
    printDataJalan(jalanL);
    cout<<"print relasi"<<endl;
    printRelasi(relasiL);
    //RJalan(F)=NULL;
    //RKota(F)=NULL;
    //deleteRelasi(relasiL,F);
