#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int DataMatrix[8][8]={0};
int KeyMatrix[8][8]={0};
int IPLocationsMatrix[8][8]={0};
int IPDataMatrix[8][8]={0};
int IPDataArray[64]={0};
int PC1LocationMatrix[8][7]={0};
int PC2LocationMatrix[8][6]={0};
int PC1KeyMatrix[8][7]={0};
int DataMatrixArray[64]={0};
int KeyArray[64]        ={0,0,0,1,0,0,1,1,
                          0,0,1,1,0,1,0,0,
                          0,1,0,1,0,1,1,1,
                          0,1,1,1,1,0,0,1,
                          1,0,0,1,1,0,1,1,
                          1,0,1,1,1,1,0,0,
                          1,1,0,1,1,1,1,1,
                          1,1,1,1,0,0,0,1};

int IPLocations[64]     ={58,50,42,34,26,18,10,2,
                          60,52,44,36,28,20,12,4,
                          62,54,46,38,30,22,14,6,
                          64,56,48,40,32,24,16,8,
                          57,49,41,33,25,17,9,1,
                          59,51,43,35,27,19,11,3,
                          61,53,45,37,29,21,13,5,
                          63,55,47,39,31,23,15,7};

int InverseIPLocations[64]={40,8,48,16,56,24,64,32,
                            39,7,47,15,55,23,63,31,
                            38,6,46,14,54,22,62,30,
                            37,5,45,13,53,21,61,29,
                            36,4,44,12,52,20,60,28,
                            35,3,43,11,51,19,59,27,
                            34,2,42,10,50,18,58,26,
                            33,1,41,9,49,17,57,25};

int PC1LocationArray[56] ={56,48,40,32,24,16,8,
                           0,57,49,41,33,25,17,
                           9,1,58,50,42,34,26,
                           18,10,2,59,51,43,35,
                           62,54,46,38,30,22,14,
                           6,61,53,45,37,29,21,
                           13,5,60,52,44,36,28,
                           20,12,4,27,19,11,3};

int PC2LocationArray[48]={13,16,10,23,0,4,
                          2,27,14,5,20,9,
                          22,18,11,3,25,7,
                          15,6,26,19,12,1,
                          40,51,30,36,46,54,
                          29,39,50,44,32,47,
                          43,48,38,55,33,52,
                          45,41,49,35,28,31};

int C[17][28]={0};
int D[17][28]={0};
int CDKey56Bit[17][56]={0};
int CDKey48Bit[17][48]={0};
int L[17][32]={0};
int R[17][32]={0};
int ExpandedR[17][48]={0};
int EXORed48Bit[17][48]={0};
int RpostSBoxing[17][32]={0};
int PermutatedR[17][32]={0};
vector<int> Rvector[17];
int ExpansionArray[48]={31,0,1,2,3,4,
                        3,4,5,6,7,8,
                        7,8,9,10,11,12,
                        11,12,13,14,15,16,
                        15,16,17,18,19,20,
                        19,20,21,22,23,24,
                        23,24,25,26,27,28,
                        27,28,29,30,31,0};

int PermutationArray[32]={15,6,19,20,
                          28,11,27,16,
                          0,14,22,25,
                          4,17,30,9,
                          1,7,23,13,
                          31,26,2,8,
                          18,12,29,5,
                          21,10,3,24};

int SBox[8][4][16]={{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7}, //s1 Box
                     {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                     {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                     {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
                    {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10}, //s2 Box
                     {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                     {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                     {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
                    {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8}, //s3 Box
                     {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                     {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                     {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
                    {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15}, //s4 Box
                     {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                     {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                     {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
                    {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9}, //s5 box
                     {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                     {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                     {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
                    {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11}, //s6 box
                     {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                     {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                     {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
                    {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1}, //s7 box
                     {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                     {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                     {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
                    {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7}, //s8 box
                     {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                     {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                     {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}};
int R16L16[64]={0};
int AfterInversePermutation[64]={0};

vector<int> pushMatrix;
string EncryptedAnswer="";
void ConvertToBinary(char in){
//M = 0123456789ABCDEF
        std::vector<int> inp;
        switch(in) {
        case '0': {
                int matrixpushArr[4] ={0,0,0,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '1': {
                int matrixpushArr[4] ={0,0,0,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '2': {
                int matrixpushArr[4] ={0,0,1,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '3': {
                int matrixpushArr[4] ={0,0,1,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '4': {
                int matrixpushArr[4] ={0,1,0,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '5': {
                int matrixpushArr[4] ={0,1,0,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '6': {
                int matrixpushArr[4] ={0,1,1,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '7': {
                int matrixpushArr[4] ={0,1,1,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '8': {
                int matrixpushArr[4] ={1,0,0,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case '9': {
                int matrixpushArr[4] ={1,0,0,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case 'A': {
                int matrixpushArr[4] ={1,0,1,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case 'B': {
                int matrixpushArr[4] ={1,0,1,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case 'C': {
                int matrixpushArr[4] ={1,1,0,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case 'D': {
                int matrixpushArr[4] ={1,1,0,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case 'E': {
                int matrixpushArr[4] ={1,1,1,0};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        case 'F': {
                int matrixpushArr[4] ={1,1,1,1};
                for(int i=0; i<4; i++) {
                        pushMatrix.push_back(matrixpushArr[i]);
                }
        } break;
        default: { cout<<"\n Unknown Input \n"; }
        }

}

/*void ConvertToBinary(int in){
        std::vector<int> inp;
        //M = 0123456789ABCDEF
        int matrixpushArr[8]={0};
        int j=7;
        while(in>0) {
                int temp=in%2;
                matrixpushArr[j]=temp;
                j=j-1;
                in=in/2;
        }
        for(int i=0; i<8; i++) {
                pushMatrix.push_back(matrixpushArr[i]);
        }
   }
 */
void populateDataMatrix(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                        DataMatrix[i][j]=pushMatrix[k];
                        k+=1;
                }
        }
}
void populateDataMatrixArray(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                        DataMatrixArray[k]=DataMatrix[i][j];
                        k+=1;
                }
        }
}

void populateKeyMatrix(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                        KeyMatrix[i][j]=KeyArray[k];
                        k+=1;
                }
        }
}
void populateIPDataMatrix(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                        IPDataMatrix[i][j]=DataMatrixArray[IPLocations[k]-1];
                        k+=1;
                }
        }
}
void populateIPDataArray(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                        IPDataArray[k]=IPDataMatrix[i][j];
                        k+=1;
                }
        }
}
void populateIPLocationsMatrix(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                        IPLocationsMatrix[i][j]=IPLocations[k]-1;
                        k+=1;
                }
        }
}
void populatePC1LocationMatrix(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<7; j++) {
                        PC1LocationMatrix[i][j]=PC1LocationArray[k];
                        k+=1;
                }
        }
}
void populatePC2LocationMatrix(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<6; j++) {
                        PC2LocationMatrix[i][j]=PC2LocationArray[k];
                        k+=1;
                }
        }
}
void populatePC1KeyMatrix(){
        int k=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<7; j++) {
                        PC1KeyMatrix[i][j]=KeyArray[PC1LocationArray[k]];
                        k+=1;
                }
        }
}
void printDataMatrix(){
        cout<<"Data Matrix";
        for(int i=0; i<8; i++) {
                cout<<endl<<"\t \t";
                for(int j=0; j<8; j++) {
                        cout<<" "<<DataMatrix[i][j];

                }
        }
        cout<<endl;

}
void printKeyMatrix(){
        cout<<"Key Matrix";
        for(int i=0; i<8; i++) {
                cout<<endl<<"\t \t";
                for(int j=0; j<8; j++) {
                        cout<<" "<<KeyMatrix[i][j];

                }
        }
        cout<<endl;

}
void printIPLocationsMatrix(){
        cout<<"IP Locations Matrix";
        for(int i=0; i<8; i++) {
                cout<<endl<<"\t \t";
                for(int j=0; j<8; j++) {
                        cout<<" "<<IPLocationsMatrix[i][j];

                }
        }
        cout<<endl;
}
void printIPDataMatrix(){
        cout<<"IP Data Matrix";
        for(int i=0; i<8; i++) {
                cout<<endl<<"\t \t";
                for(int j=0; j<8; j++) {
                        cout<<" "<<IPDataMatrix[i][j];

                }
        }
        cout<<endl;

}
void printPC1LocationMatrix(){
        cout<<"PC1 Location Matrix";
        for(int i=0; i<8; i++) {
                cout<<endl<<"\t \t";
                for(int j=0; j<7; j++) {
                        cout<<" "<<PC1LocationMatrix[i][j];

                }
        }
        cout<<endl;

}

void printPC2LocationMatrix(){
        cout<<endl;
        cout<<endl;
        cout<<"PC2 Location Matrix";
        for(int i=0; i<8; i++) {
                cout<<endl<<"\t \t";
                for(int j=0; j<6; j++) {
                        cout<<" "<<PC2LocationMatrix[i][j];

                }
        }
        cout<<endl;

}

void printPC1KeyMatrix(){
        cout<<"PC1 Key Matrix";
        for(int i=0; i<8; i++) {
                cout<<endl<<"\t \t";
                for(int j=0; j<7; j++) {
                        cout<<" "<<PC1KeyMatrix[i][j];

                }
        }
        cout<<endl;

}

void fillC0D0(){
        int k=0,l=0;
        for(int i=0; i<8; i++) {
                for(int j=0; j<7; j++) {
                        if(k<=27) {
                                C[0][k]=PC1KeyMatrix[i][j];
                                k+=1;
                        }
                        else if(k>27) {
                                D[0][l]=PC1KeyMatrix[i][j];
                                l+=1;
                                k+=1;
                        }
                }
        }

}

void printC0D0(){
        cout<<endl;
        cout<<endl;
        cout<<"C0 ->";
        for(int i=0; i<28; i++) {
                cout<<""<<C[0][i];
        }
        cout<<endl;
        cout<<"D0 ->";
        for(int i=0; i<28; i++) {
                cout<<""<<D[0][i];
        }
}

void createAllCD(){
        for(int i=1; i<17; i++) {
                if(i==1 || i==2 || i==9 || i==16) {
                        int temp1=C[i-1][0];
                        int temp2=D[i-1][0];
                        for(int j=0; j<28; j++) {
                                if(j==27) {
                                        C[i][j]=temp1;
                                        D[i][j]=temp2;
                                }
                                else{
                                        C[i][j]=C[i-1][j+1];
                                        D[i][j]=D[i-1][j+1];
                                }
                        }
                }
                else{
                        int temp1=C[i-1][0];
                        int temp2=C[i-1][1];
                        int temp3=D[i-1][0];
                        int temp4=D[i-1][1];
                        for(int j=0; j<28; j++) {
                                if(j==26) {
                                        C[i][j]=temp1;
                                        D[i][j]=temp3;
                                }
                                else if(j==27) {
                                        C[i][j]=temp2;
                                        D[i][j]=temp4;
                                }
                                else{
                                        C[i][j]=C[i-1][j+2];
                                        D[i][j]=D[i-1][j+2];
                                }
                        }

                }
        }
}

void printAllCD(){
        for(int i=1; i<17; i++) {
                cout<<endl;
                cout<<endl;
                cout<<"C"<<i<<" ->";
                for(int j=0; j<28; j++) {
                        cout<<""<<C[i][j];
                }
                cout<<endl;
                cout<<"D"<<i<<" ->";
                for(int j=0; j<28; j++) {
                        cout<<""<<D[i][j];
                }
        }
}

void create56BitCDKey(){
        int k=0,l=0;
        for(int i=0; i<17; i++) {
                for(int j=0; j<56; j++) {
                        if(k<=27) {
                                CDKey56Bit[i][j]=C[i][k];
                                k+=1;
                        }
                        else if(k>27) {
                                CDKey56Bit[i][j]=D[i][l];
                                k+=1;
                                l+=1;
                        }
                        if(j==55) {
                                k=0;
                                l=0;
                        }
                }
        }
}

void printAll56BitCDKeys(){
        for(int i=1; i<17; i++) {
                cout<<endl;
                cout<<endl;
                cout<<"Key"<<i<<": ";
                for(int j=0; j<56; j++) {
                        cout<<CDKey56Bit[i][j];
                }
        }
}

void create48BitCDKeys(){
        int k=0;
        for(int i=0; i<17; i++) {
                for(int j=0; j<48; j++) {
                        CDKey48Bit[i][j]=CDKey56Bit[i][PC2LocationArray[k]];
                        k+=1;
                        if(j==47) {
                                k=0;
                        }
                }
        }
}

void printAll48BitCDKeys(){
        for(int i=1; i<17; i++) {
                cout<<endl;
                cout<<endl;
                cout<<"Key"<<i<<": ";
                for(int j=0; j<48; j++) {
                        cout<<CDKey48Bit[i][j];
                }
        }
}

void createL0R0(){
        for(int i=0; i<32; i++) {
                L[0][i]=IPDataArray[i];
        }
        int k=0;
        for(int i=32; i<64; i++) {
                R[0][k]=IPDataArray[i];
                k+=1;
        }
}

void printL0R0(){
        cout<<endl;
        cout<<endl;
        cout<<"L0 ->";
        for(int i=0; i<32; i++) {
                cout<<L[0][i];

        }
        cout<<endl;
        cout<<"R0 ->";
        for(int i=0; i<32; i++) {
                cout<<R[0][i];

        }
}

void ExpandR(int R[][32],int i){
        int k=0;
        for(int j=0; j<48; j++) {
                ExpandedR[i][j]=R[i][ExpansionArray[k]];
                k+=1;
        }

}
void EXoR(int CDKey48Bit[][48],int ExpandedR[][48],int i){
        for(int j=0; j<48; j++) {
                EXORed48Bit[i][j]=CDKey48Bit[i][j] ^ ExpandedR[i-1][j];
        }
}
void FillRpostSBoxingVector(int Boxno,int EXORed48Bit[][48],int i,int startIndex,int EndIndex){
        /*cout<<"\n"<<EXORed48Bit[i][startIndex];
           cout<<"\n"<<8*EXORed48Bit[i][startIndex+1];
           cout<<"\n"<<4*EXORed48Bit[i][startIndex+2];
           cout<<"\n"<<2*EXORed48Bit[i][startIndex+3];
           cout<<"\n"<<1*EXORed48Bit[i][startIndex+4];
           cout<<"\n"<<EXORed48Bit[i][EndIndex];

           cout<<endl;
           cout<<"\n Box no"<<Boxno<<" ";
           for(int j=startIndex; j<=EndIndex; j++) {
                cout<<EXORed48Bit[i][j];
           }*/
        //cout<<endl;
        int BoxRowNo;
        int BoxColNo;
        BoxRowNo=(2*EXORed48Bit[i][startIndex])+(1*EXORed48Bit[i][EndIndex]);
        BoxColNo=(8*EXORed48Bit[i][startIndex+1])+ (4*EXORed48Bit[i][startIndex+2])
                  +(2*EXORed48Bit[i][startIndex+3])+ 1*(EXORed48Bit[i][startIndex+4]);
        //cout<<"\nBoxRowNo "<<BoxRowNo;
        //cout<<"\nBoxColNo"<<BoxColNo;
        //cout<<"\nBoxNo "<<Boxno;
        int ValueFromSBox=SBox[Boxno][BoxRowNo][BoxColNo];
        //cout<<"\n"<<ValueFromSBox;
        int vectorpushArr[4]={0};
        int j=3;
        //cout<<endl;
        while(ValueFromSBox>0) {
                int temp=ValueFromSBox%2;
                vectorpushArr[j]=temp;
                j=j-1;
                ValueFromSBox=ValueFromSBox/2;
        }
        //cout<<endl;
        for(int l=0; l<4; l++) {
                //cout<<"\n i "<<i;
                //cout<<"\n Val "<<vectorpushArr[l];
                //cout<<"\n I am here\n";
                //cout<<" "<<vectorpushArr[l];
                Rvector[i].push_back(vectorpushArr[l]); //error
        }
}

void FillRpostSBoxing(int i){
        for(int j=0; j<32; j++) {
                RpostSBoxing[i][j]=Rvector[i][j];
        }
}

void CalculateSBox(int EXORed48Bit[][48],int i){
        int k=0;
        for(int j=0; j<48; j+=6) {
                FillRpostSBoxingVector(k,EXORed48Bit,i,j,j+5);
                k+=1;
        }
        FillRpostSBoxing(i);
}
void createPermutatedR(int RpostSBoxing[][32],int i){
        int k=0;
        //cout<<endl;
        //cout<<"i val "<<i;
        //cout<<endl;
        for(int j=0; j<32; j++) {
                //cout<<RpostSBoxing[i][PermutationArray[k]];
                int temp=RpostSBoxing[i][PermutationArray[k]];
                PermutatedR[i][j]=temp;
                //cout<<PermutatedR[i][j];
                k+=1;
        }

}
void createAllLR(){
        for(int i=1; i<17; i++) {
                for(int j=0; j<32; j++) {
                        L[i][j]=R[i-1][j];
                }
                ExpandR(R,i-1);
                EXoR(CDKey48Bit,ExpandedR,i);
                CalculateSBox(EXORed48Bit,i);
                createPermutatedR(RpostSBoxing,i);
                for(int n=0; n<32; n++) {
                        R[i][n]=L[i-1][n]^PermutatedR[i][n];
                }
        }
}
void printAllLR(){
        for(int i=1; i<17; i++) {
                cout<<endl;
                cout<<endl;
                cout<<"L"<<i<<" ->";
                for(int j=0; j<32; j++) {
                        cout<<""<<L[i][j];
                }
                cout<<endl;
                cout<<"R"<<i<<" ->";
                for(int j=0; j<32; j++) {
                        cout<<""<<R[i][j];
                }
        }
}
void fillR16L16(){
        for(int i=0; i<32; i++) {
                R16L16[i]=R[16][i];
        }
        int k=0;
        for(int i=32; i<64; i++) {
                R16L16[i]=L[16][k];
                k+=1;
        }
}
void InverseR16L16(){
        int k=0;
        for(int i=0; i<64; i++) {
                AfterInversePermutation[i]=R16L16[InverseIPLocations[k]-1];
                k+=1;
        }
}
void printR16L16(){
        cout<<endl;
        cout<<endl;
        cout<<"R16L16                  ";
        for(int i=0; i<64; i++) {
                cout<<R16L16[i];
        }
        cout<<endl;
}
void printInverseR16L16(){

        cout<<endl;
        cout<<"Inverse Permuted R16L16 ";
        for(int i=0; i<64; i++) {
                cout<<AfterInversePermutation[i];
        }
        cout<<endl;

}
void StringFinalAnswer(int AfterInversePermutation[64],int startIndex,int EndIndex){
        int val=(8*AfterInversePermutation[startIndex])+ (4*AfterInversePermutation[startIndex+1])
                 +(2*AfterInversePermutation[startIndex+2])+ 1*(AfterInversePermutation[EndIndex]);
        switch (val) {
        case 0: {
                EncryptedAnswer+='0';
        } break;
        case 1: {
                EncryptedAnswer+='1';
        } break;
        case 2: {
                EncryptedAnswer+='2';
        } break;
        case 3: {
                EncryptedAnswer+='3';
        } break;
        case 4: {
                EncryptedAnswer+='4';
        } break;
        case 5: {
                EncryptedAnswer+='5';
        } break;
        case 6: {
                EncryptedAnswer+='6';
        } break;
        case 7: {
                EncryptedAnswer+='7';
        } break;
        case 8: {
                EncryptedAnswer+='8';
        } break;
        case 9: {
                EncryptedAnswer+='9';
        } break;
        case 10: {
                EncryptedAnswer+='A';
        } break;
        case 11: {
                EncryptedAnswer+='B';
        } break;
        case 12: {
                EncryptedAnswer+='C';
        } break;
        case 13: {
                EncryptedAnswer+='D';
        } break;
        case 14: {
                EncryptedAnswer+='E';
        } break;
        case 15: {
                EncryptedAnswer+='F';
        } break;
        default: {
                cout<<endl;
                cout<<"\n Suprise mother fucker";
                cout<<endl;
        }
        }

}
void CreateFinalAnswer(){
        for(int i=0; i<64; i+=4) {
                StringFinalAnswer(AfterInversePermutation,i,i+3);
        }
}


int main(){
/* Input via Array
        int arr[8]={0};
        cout<<"\n Enter 8 values seperated by spaces \n";
        for(int i=0; i<8; i++) {
                cin>>arr[i];
        }
        for(int i=0; i<8; i++) {
                ConvertToBinary(arr[i]);
        }
        cout<<endl;
 */
        string s1="";
        cout<<"\n Enter the Message Either nums or Capital Alphabets \n";
        cin>>s1;
        for(unsigned int i=0; i<s1.length(); i++) {
                ConvertToBinary(s1[i]);
        }
/*int j=0;
          Vector Check
          for(int i=0; i<pushMatrix.size(); i++) {
               cout<<" "<<pushMatrix[i];
               j=j+1;
               if(j==8) {
                       cout<<endl;
                       j=0;
               }
          }*/
        populateDataMatrix();
        populateDataMatrixArray();
        populateKeyMatrix();
        populateIPLocationsMatrix();
        populateIPDataMatrix();
        populateIPDataArray();
        printDataMatrix();
        printKeyMatrix();
        printIPLocationsMatrix();
        printIPDataMatrix();
        populatePC1LocationMatrix();
        printPC1LocationMatrix();
        populatePC1KeyMatrix();
        printPC1KeyMatrix();
        fillC0D0();
        printC0D0();
        createAllCD();
        printAllCD();
        create56BitCDKey();
        cout<<"\n\n56Bit Keys-->";
        printAll56BitCDKeys();
        populatePC2LocationMatrix();
        printPC2LocationMatrix();
        create48BitCDKeys();
        cout<<"\n\n48Bit Keys-->";
        printAll48BitCDKeys();
        createL0R0();
        printL0R0();
        createAllLR();
        //for(int i=0; i<32; i++) {
        //      cout<<RpostSBoxing[1][i];
        //}
        //cout<<endl;
        //cout<<endl;
/* Print R PermutationArray
        for(int i=0; i<32; i++) {
                if((i)%4==0) {cout<<"\n"; }
                cout<<" "<<PermutationArray[i];
        }*/
        //cout<<endl;
        //for(int i=0; i<32; i++) {
        //cout<<PermutatedR[1][i];
        //}
        printAllLR();
        fillR16L16();
        InverseR16L16();
        printR16L16();
        printInverseR16L16();
        CreateFinalAnswer();
        cout<<endl;
        cout<<"Encrypted Answer :"<<EncryptedAnswer;
}
