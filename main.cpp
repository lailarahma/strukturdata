#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

int datake = 1;
int maks =4;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[4];

/***************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void tambahdata()
{

    if(datake <= maks){
        gotoxy(1,9);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[datake].jenis_brg;
        gotoxy(1,10);cout<<"Inputkan Berat           :";
        cin>>kirim[datake].berat;
        gotoxy(1,11);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[datake].kota;
        datake++;
    }
    else{
        gotoxy(22,7);cout << "Data Penuh" << endl;
    }
    gotoxy(1,15);cout<<"Press Any Key";
    getch();
}

void tampildata(int a=1)
{
    gotoxy(1,8);cout<<"Daftar Kiriman Paket"<<endl;
    if(a < datake){
    for(int a=1; a<datake; a++)
    {
        gotoxy(1,15-a);
        cout<<a<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }
    }
    else {
        gotoxy(1,9);cout<< "Data kosong"<<endl;
    }
    gotoxy(1,20);
    cout<<"Press Any Key...";
    getch();

}

void hapusdata()
{
    if(datake>1){
        gotoxy(1,9);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(1,10);cout<<kirim[datake-1].jenis_brg<<" ";
        cout<<kirim[datake-1].berat<<" Kg ";
        cout<<kirim[datake-1].kota<<endl<<endl;
        datake--;
    }
    else{
    gotoxy(22,7);cout << "Data kosong" << endl;
    }
    gotoxy(1,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            {
                tambahdata();
            }
        if(pilih==2)
            {
                hapusdata();
            }
        if(pilih==3)
            tampildata();

    }
    while(pilih!=9);
    return 0;
}
