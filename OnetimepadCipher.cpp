#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

static string cipher;
static string pt,ct;


void Encryption(){
        cout<<"\n Enter the Plain text: \t";
        cin>>pt;
        int len=pt.length();
        for(int i=0; i<len; i++) {
                cipher+=char((rand()%26)+97);
        }
        cout<<" Cipher Key:      \t"<<cipher;
        for(int i=0; i<pt.length(); i++) {
                pt[i]=pt[i]-'a';
        }
        for(int i=0; i<cipher.length(); i++) {
                cipher[i]=cipher[i]-'a';
        }
        for(int i=0; i<pt.length(); i++) {
                pt[i]=pt[i]+cipher[i];
        }
        for(int i=0; i<pt.length(); i++) {
                pt[i]=pt[i]%26;
                pt[i]=pt[i]+'a';
        }
        ct=pt;
        cout<<"\n"<<" Encrypted Text: \t"<<pt<<"\n";
}

void Decryption(){
        for(int i=0; i<ct.length(); i++) {
                ct[i]=ct[i]-'a';
        }
        for(int i=0; i<ct.length(); i++) {
                ct[i]=ct[i]-cipher[i];
                if(int(ct[i])<0) {ct[i]+=26; }
        }
        for(int i=0; i<ct.length(); i++) {
                ct[i]=ct[i]%26;
                ct[i]=ct[i]+'a';
        }
        cout<<"\n"<<" Decrypted Text: \t"<<ct<<"\n";
        ct="";
        pt="";
        cipher="";

}

int main(){
        cout<<"\t \t \t \t AutoPad Cipher \n";
        while(1) {
                cout<<"\n 1.Encryption";
                cout<<"\n 2.Decryption";
                cout<<"\n 3.Exit\n";
                int n;
                cin>>n;
                switch (n) {
                case 1: {
                        Encryption();
                } break;
                case 2: {
                        Decryption();
                } break;
                case 3: {
                        return 0;
                } break;
                default: {
                        cout<<"\n Invalid Key";
                }
                }

        }
        return 0;
}
