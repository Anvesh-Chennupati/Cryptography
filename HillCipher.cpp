#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;

int MatrixE[2][2];
int MatrixD[2][2];
string ciphert="";
string plaint ="";

int findinverse(int det){
        int i=1,j=1;
        while(j) {
                if((det*i)%26==1) {
                        j=-1;
                        break;
                }
                i=i+1;
        }
        return i;
}

void calculateCipher(char a,char b){
        int x1=int(a-'a');
        int x2=int(b-'a');
        int x3=((MatrixE[0][0]*x1) +(MatrixE[0][1]*x2));
        int x4=((MatrixE[1][0]*x1) +(MatrixE[1][1]*x2));
        ciphert+=char(int(x3%26)+'a');
        ciphert+=char(int(x4%26)+'a');
}
void calculateMatrix(){
        MatrixD[0][0]= MatrixE[1][1];
        MatrixD[0][1]=-MatrixE[0][1];
        MatrixD[1][0]=-MatrixE[1][0];
        MatrixD[1][1]= MatrixE[0][0];
        cout<<"\n \n Step 1 :";
        for(int i=0; i<2; i++) {
                cout<<"\n";
                for(int j=0; j<2; j++) {
                        cout<<"\t"<<MatrixD[i][j];
                }
        }
        cout<<"\n \n";

        for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {
                        if(MatrixD[i][j]<0) {
                                MatrixD[i][j]+=26;
                        }
                }
        }
        cout<<"\n \n Step 2 :";
        for(int i=0; i<2; i++) {
                cout<<"\n";
                for(int j=0; j<2; j++) {
                        cout<<"\t"<<MatrixD[i][j];
                }
        }
        cout<<"\n \n";

        int det=(MatrixE[0][0]*MatrixE[1][1]) - (MatrixE[0][1]*MatrixE[1][0]);
        if(det<0) {
                det+=26;
        }
        int inv;
        inv =findinverse(det);
        for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {

                        MatrixD[i][j]*=inv;

                }
        }

        cout<<"\n \n Step 3 :";
        for(int i=0; i<2; i++) {
                cout<<"\n";
                for(int j=0; j<2; j++) {
                        cout<<"\t"<<MatrixD[i][j];
                }
        }
        cout<<"\n \n";
        for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {
                        int temp;
                        temp=MatrixD[i][j]%26;
                        MatrixD[i][j]=temp;
                }
        }
        cout<<"\n Inverse Matrix \n";
        for(int i=0; i<2; i++) {
                cout<<"\n";
                for(int j=0; j<2; j++) {
                        cout<<"\t"<<MatrixD[i][j];
                }
        }
        cout<<"\n";

}
void calculatedecipher(char a,char b){
        int x1=int(a-'a');
        int x2=int(b-'a');
        int x3=((MatrixD[0][0]*x1) +(MatrixD[0][1]*x2));
        int x4=((MatrixD[1][0]*x1) +(MatrixD[1][1]*x2));
        plaint+=char(int(x3%26)+'a');
        plaint+=char(int(x4%26)+'a');
}

int main(){
        cout<<"\n Enter the elements in the key Matrix"<<endl;
        for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {
                        cin>>MatrixE[i][j];
                }
        }
        cout<<"\n Enter the string ";
        string s;
        cin>>s;
        if(s.length()%2!=0) {
                s+='x';
        }
        for(int i=1; i<=s.length(); i+=2) {
                calculateCipher(s[i-1],s[i]);
        }
        cout<<"\n key Matrix \n";
        for(int i=0; i<2; i++) {
                cout<<"\n";
                for(int j=0; j<2; j++) {
                        cout<<"\t"<<MatrixE[i][j];
                }
        }
        cout<<"\n";
        cout<<"\n Cipher Text :"<<ciphert<<endl;
        calculateMatrix();
        for(int i=1; i<=ciphert.length(); i+=2) {
                calculatedecipher(ciphert[i-1],ciphert[i]);
        }
        cout<<"\n Deciphered Plain Text  :"<<plaint<<endl;
}
