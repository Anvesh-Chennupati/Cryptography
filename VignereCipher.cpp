#include <iostream>
#include <string.h>

using namespace std;

void Venc(){
								cout<<"\n Enter the plain text \n \n";
								string s1;
								cin>>s1;
								cout<<"\n Enter the Key \n \n";
								string k;
								cin>>k;
								int n,m,i,j=0;
								n=s1.length();
								m=k.length();
								for(i=0; i<n; i++) {
																s1[i]=s1[i]-'a';
								}
								for(i=0; i<m; i++) {
																k[i]=k[i]-'a';
								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]+k[j];
																j++;
																if(j==m) {j=0; }
								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]%26;
																s1[i]=s1[i]+'a';
								}
								cout<<"\n"<<"Encrypted Text \t"<<s1<<"\n";
}

void Vdec(){
								cout<<"\n Enter the Cipher text \n";
								string s1;
								cin>>s1;
								cout<<"\n Enter the Key \n";
								string k;
								cin>>k;
								int n,m,i,j=0;
								n=s1.length();
								m=k.length();
								for(i=0; i<n; i++) {
																s1[i]=s1[i]-'a';
								}
								for(i=0; i<m; i++) {
																k[i]=k[i]-'a';
								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]-k[j];
																if(int(s1[i])<0) {s1[i]+=26; }
																j++;
																if(j==m) {j=0; }
								}
								for(i=0; i<n; i++) {
																s1[i]=s1[i]%26;
																s1[i]=s1[i]+'a';
								}
								cout<<"\n"<<"Decrypted Text \t"<<s1<<"\n";
}


int main() {

								cout<<"\n \t \t \t \t Vignere Cipher";
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
