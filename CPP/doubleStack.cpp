#include <iostream>
#include <conio.h>
#define n 7

using namespace std;

struct doubleStack{
    int top1,top2, data[n];
}tumpukan;

void Awal(){
    tumpukan.top1 = -1;
    tumpukan.top2 = n;
}

void Push1(){
    if(tumpukan.top2 - tumpukan.top1 > 1){
        tumpukan.top1++;
        cout<<"Masukan data : "; cin>>tumpukan.data[tumpukan.top1];
    } else {
        cout<<"Stack Penuh\n";
    }
}

void Pop1(){
    if(tumpukan.top1 > -1){
        cout<<"Data "<<tumpukan.data[tumpukan.top1]<<" sudah terambil\n";
        tumpukan.top1--;
    } else {
        cout<<"Stack Kosong\n";
    }
}

void Push2(){
    if(tumpukan.top2 - tumpukan.top1 > 1){
        tumpukan.top2--;
        cout<<"Masukan data : "; cin>>tumpukan.data[tumpukan.top2];
    } else {
        cout<<"Stack Penuh\n";
    }
}

void Pop2(){
    if(tumpukan.top2 < n){
        cout<<"Data "<<tumpukan.data[tumpukan.top2]<<" sudah terambil\n";
        tumpukan.top2++;
    } else {
        cout<<"Stack Kosong\n";
    }
}

void Cetak(){
    cout<<"\nTumpukan : ";
    if(tumpukan.top2 - tumpukan.top1 > 1){
        for (int i = 0; i <= tumpukan.top1; i++){
        cout<<tumpukan.data[i]<<" ";
        }
    }
    if(tumpukan.top2 - tumpukan.top1 > 1){
        for (int i = tumpukan.top2; i <= n-1; i++){
        cout<<tumpukan.data[i]<<" ";
        }
    }
}

int main(){
    int pilihan;
    system("cls");
    Awal();
    do{
        cout<<"\n\tDOUBLE STACK\n";
        cout<<"------------------------------";
        Cetak();
        cout<<"\n------------------------------";
        cout<<"\n\t1. Push Stack1"<<endl;
        cout<<"\t2. Pop Stack1"<<endl;
        cout<<"\t3. Push Stack2"<<endl;
        cout<<"\t4. Pop Stack2"<<endl;
        cout<<"\t5. Keluar"<<endl;
        cout<<"------------------------------\n";
        cout<<"Pilihan : "; cin>>pilihan;
        switch(pilihan){
            case 1:
                Push1();
                break;
            case 2:
                Pop1();
                break;
            case 3:
                Push2();
                break;
            case 4:
                Pop2();
                break;
            default:
                cout<<"Pilihan tidak tersedia!!!"<<endl;
                break;
        }
        // getch();
    } while(pilihan != 5);
}
