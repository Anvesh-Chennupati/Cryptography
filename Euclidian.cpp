#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
vector<long int> q;
vector<long int> r1;
vector<long int> r2;
vector<long int> r;
long int num1,num2;
void calculateGCD(long int num1,long int num2){
        r1.push_back(num1);
        r2.push_back(num2);
        //r2.back();
        while(r2.back()!=0) {
                long int qu =r1.back()/r2.back();
                long int rem=r1.back()%r2.back();
                q.push_back(qu);
                r.push_back(rem);
                r1.push_back(r2.back());
                r2.push_back(r.back());

        }
        r1.push_back(r2.back());
        r2.push_back(r.back());


}
void printGCD(){
        if(r2.back()==0) {
                cout<<endl;
                cout<<" q "<<"\t"<<" r1 "<<"\t"<<" r2 "<<"\t"<<" r ";
                cout<<endl;
                for(unsigned long int i=0; i<r2.size()-2; i++) {
                        cout<<" "<<q[i]<<"\t"<<" "<<r1[i]<<"\t"<<" "<<r2[i]<<"\t"<<" "<<r[i];
                        cout<<endl;
                }
                cout<<" "<<" "<<"\t"<<" "<<r1[r1.size()-2]<<"\t"<<" "<<r2.back()<<"\t"<<" "<<" ";
                cout<<endl;
                cout<<"\nGCD of "<<num1<<" and "<<num2<<" is "<<r1[r1.size()-2];
        }
}
int main(){

        cout<<"\nEnter 2 numbers ->";
        cin>>num1>>num2;
        calculateGCD(num1,num2);
        printGCD();
}
