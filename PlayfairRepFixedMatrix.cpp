#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<char> temp1;
vector<char> alpha;
vector<char>::iterator iter;

int arr[26] ={0};

char keyMatrix[5][5];

string remRep(string s){
        string ret="";
        int i;
        for(i=0; i<s.length(); i++) {
                if(arr[int(s[i]-'a')]==0) {
                        arr[int(s[i]-'a')]+=1;
                }
        }
        for(i=0; i<26; i++) {
                if(arr[i]==1) {
                        ret+=char(i+97);
                }
        }
        return ret;
}

string maintainOrder(string org,string uno) {
        string ordered="";
        if(org.length()==uno.length()) {
                return org;
        }
        else{
                for(int i=0; i<org.length(); i++) {
                        for(int j=0; j<uno.length(); j++) {
                                if(org[i]==uno[j]) {
                                        ordered+=org[i];
                                        uno[j]='*';
                                }
                        }
                }
                return ordered;
        }

}
void printMatrix(){
        for(int i=0; i<5; i++) {
                cout<<"\n";
                for(int j=0; j<5; j++) {
                        cout<<" "<<keyMatrix[i][j];
                }
        }
}

string modifyPlainText(string pt){
        string tempAns="";
        int j=0;
        for(int i=0; i<pt.length(); i++) {
                if(tempAns.length()==0) {
                        tempAns+=pt[i];
                        continue;
                }
                else{
                        if(tempAns[j]==pt[i]) {
                                tempAns+='x';
                                j+=1;
                        }
                        if(tempAns[j]!=pt[i]) {
                                tempAns+=pt[i];
                                j+=1;
                        }

                }
        }
        if(tempAns.length()%2!=0) {tempAns+='x'; }
        return tempAns;

}

int main(){
        cout<<"\n Enter the Key ";
        string key;
        cin>>key;
        string temp;
        for(int i=0; i<key.length(); i++) {
                if(key[i]=='i') key[i]='j';
        }
        temp=remRep(key);
        key=maintainOrder(key,temp);
        int i,j,k=0,l=0,u=0,keylen=key.length();
        for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                        keyMatrix[i][j]=key[k];
                        k++;
                        if(k==keylen) break;
                }
        }
        for(i=97; i<=122; i++) {
                if(i==105) continue;
                char ab=char(i);
                alpha.push_back(ab);
        }
        // To remove a value from the vector
        for(int i=0; i<key.length(); i++) {

                for(iter = alpha.begin(); iter != alpha.end(); ++iter )
                {
                        if( *iter == key[i] )
                        {
                                alpha.erase( iter );
                                break;
                        }
                }
        }
        for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                        l++;
                        if(l<=keylen) continue;
                        else keyMatrix[i][j]=alpha[u];
                        u++;
                }


        }
        cout<<"\n Enter the Plain text ";
        string pt,modifiedpt;
        cin>>pt;
        modifiedpt=modifyPlainText(pt);
        cout<<"\n length "<<modifiedpt.length();
        cout<<"\n PlayFair Matrix \t";
        printMatrix();
        cout<<"\n Modified Plain text "<<modifiedpt;


}
