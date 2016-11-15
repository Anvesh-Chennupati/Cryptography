#include <iostream>
#include <string.h>

using namespace std;

void ceaserEncryption(){
        cout<<" Enter the Plain text \t";
        string s;
        string result="";
        cin>>s;
        for(int i=0; i<s.length(); i++) {
                result += char(int(s[i]+3-97)%26 +97);
        }
        cout<<"\n Encrypted Text \t"<<result;
}

void ceaserDecryption(){
        cout<<" Enter the Cipher text \t";
        string s;
        string result="";
        cin>>s;
        for(int i=0; i<s.length(); i++) {
                result += char(int(s[i]+23-97)%26 +97);
        }
        cout<<"\n Encrypted Text \t"<<result;


}

int main(){
        cout<<"\t \t \t \t \t \t"<<"Ceaser's Cipher";
        while(1) {
                cout<<"\n";
                cout<<"\n 1.Encryption";
                cout<<"\n 2.Decryption";
                cout<<"\n 3.Exit \n";
                int n;
                cin>>n;
                switch(n) {
                case 1: {
                        ceaserEncryption();
                        break;
                }
                case 2: {
                        ceaserDecryption();
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
