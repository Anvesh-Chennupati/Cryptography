#include <iostream>
#include <string.h>

using namespace std;
string cipher="";
void Venc(){
								cout<<"\n Enter the plain text \n \n";
								string s1;
								cin>>s1;
								cout<<"\n Enter the Key \n \n";
								string k;
								cin>>k;
								cipher+=k;
								int n,m,i,j=0;
								n=s1.length();
								m=k.length();
								for(int i=m; i<n; i++) {
																cipher+=s1[i];
								}
								cout<<"\nCipher Key: \t"<<cipher;
								for(i=0; i<n; i++) {
																s1[i]=s1[i]-'a';
								}
								for(i=0; i<n; i++) {
																cipher[i]=cipher[i]-'a';
								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]+cipher[i];
								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]%26;
																s1[i]=s1[i]+'a';
								}
								cout<<"\n"<<"Encrypted Text: "<<s1<<"\n";
}

void Vdec(){
								cout<<"\n Enter the Cipher text \n";
								string s1;
								cin>>s1;
								for(int i=0; i<s1.length(); i++) {
																cipher[i]=cipher[i]+'a';
								}
								int n,m,i,j=0;
								n=s1.length();
								for(i=0; i<n; i++) {
																s1[i]=s1[i]-'a';
								}
								for(i=0; i<n; i++) {
																cipher[i]=cipher[i]-'a';
								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]-cipher[i];
																if(int(s1[i])<0) {s1[i]+=26; }

								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]%26;
																s1[i]=s1[i]+'a';
								}
								cout<<"\n"<<"Decrypted Text \t"<<s1<<"\n";
								cipher="";
}


int main() {

								cout<<"\n \t \t \t \t AutoKey Cipher";
								while(1) {
																cout<<"\n 1. Encryption";
																cout<<"\n 2. Decryption";
																cout<<"\n 3. Exit \n \n";
																cout<<"\n>>>";
																int n;
																cin >>n;

																switch(n) {
																case 1: {
																								Venc();
																								break;
																}
																case 2: {
																								Vdec();
																								break;
																}
																case 3: {
																								return 0;
																								break;
																}
																default: {
																								cout<<"\n Invalid Entry";
																}
																}
								}
}
