#include <iostream>
#include <string.h>

using namespace std;

char Original[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char Cipher[]  ={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
string result  ="";
int findlocOriginal(char c){
								for(int i=0; i<26; i++) {
																if(Original[i]==c) {
																								return i;
																}
								}
}
int findlocCipher(char c){
								for(int i=0; i<26; i++) {
																if(Cipher[i]==c) { return i; }
								}
}
void MonoEncryption() {
								cout<<"\n Enter the plain text  ";
								string input;
								cin>>input;
								for(int i=0; i<input.length(); i++) {
																int loc=findlocOriginal(input[i]);
																result+=Cipher[loc];

								}
								cout<<"\n Encrypted text  "<<result;
								result="";
}

void MonoDecryption(){
								cout<<"\n Enter the Cipher text  ";
								string input;
								cin>>input;
								for(int i=0; i<input.length(); i++) {
																int loc=findlocCipher(input[i]);
																result+=Original[loc];
								}
								cout<<"\n Decrypted text  "<<result;
								result="";
}
int main(){
								cout<<"\t \t \t \t \t \t"<<"MonoAlphabetic Cipher";
								while(1) {
																cout<<"\n";
																cout<<"\n 1.Encryption";
																cout<<"\n 2.Decryption";
																cout<<"\n 3.Exit \n";
																int n;
																cin>>n;
																switch(n) {
																case 1: {
																								MonoEncryption();
																								break;
																}
																case 2: {
																								MonoDecryption();
																								break;
																}

																case 3: {
																								return 0;
																}
																default: {
																								cout<<"\n Invalid Entry";
																}
																}
								}
}
