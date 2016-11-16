#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
vector<long int> q;
vector<long int> r1;
vector<long int> r2;
vector<long int> r;
vector<long int> s1;
vector<long int> s2;
vector<long int> s;
vector<long int> t1;
vector<long int> t2;
vector<long int> t;

long int num1,num2;
void calculateGCD(long int num1,long int num2){
        r1.push_back(num1);
        r2.push_back(num2);
        s1.push_back(1);
        s2.push_back(0);
        t1.push_back(0);
        t2.push_back(1);
        //r2.back();
        while(r2.back()!=0) {
                long int qu  =r1.back()/r2.back();
                long int rem =r1.back()%r2.back();
                long int sval=s1.back() - (qu*s2.back());
                long int tval=t1.back() - (qu*t2.back());
                q.push_back(qu);
                r.push_back(rem);
                r1.push_back(r2.back());
                r2.push_back(r.back());
                s.push_back(sval);
                t.push_back(tval);
                s1.push_back(s2.back());
                s2.push_back(s.back());
                t1.push_back(t2.back());
                t2.push_back(t.back());

        }

}
void printGCD(){
        if(r2.back()==0) {
                cout<<endl;
                cout<<" q "<<"\t"<<" r1 "<<"\t"<<" r2 "<<"\t"<<" r "<<"\t"<<" s1 "<<"\t"
                    <<" s2 "<<"\t"<<" s "<<"\t"<<" t1 "<<"\t"<<" t2 "<<"\t"<<" t ";
                cout<<endl;
                for(unsigned long int i=0; i<r2.size()-1; i++) {
                        cout<<" "<<q[i]<<"\t"<<" "<<r1[i]<<"\t"<<" "<<r2[i]<<"\t"<<" "<<r[i]
                            <<"\t"<<" "<<s1[i]<<"\t"<<" "<<s2[i]<<"\t"<<" "<<s[i]
                            <<"\t"<<" "<<t1[i]<<"\t"<<" "<<t2[i]<<"\t"<<" "<<t[i];
                        cout<<endl;
                }
                cout<<" "<<" "<<"\t"<<" "<<r1[r1.size()-1]<<"\t"<<" "<<r2[r2.size()-1]<<"\t"<<" "<<" "
                    <<"\t"<<" "<<s1[s1.size()-1]<<"\t"<<" "<<s2[s2.size()-1]<<"\t"<<" "<<" "
                    <<"\t"<<" "<<t1[t1.size()-1]<<"\t"<<" "<<t2[t2.size()-1]<<"\t"<<" "<<" ";
                cout<<endl;
                cout<<endl;
                if(r1.back()!=1) {
                        cout<<"\nGCD of "<<num1<<" and "<<num2<<" is "<<r1.back();
                        cout<<"\n\nMultiplicative Inverse doesn't exit ";
                }
                if(r1.back()==1) {
                        cout<<"\nGCD of "<<num1<<" and "<<num2<<" is "<<r1.back();
                        cout<<"\n\nMultiplicative Inverse is "<<t1.back();
                }
                cout<<endl;
        }
}
void verifyGCD(){
        long int sval=s2[s2.size()-2];
        //cout<<endl;
        //cout<<sval;
        //cout<<endl;
        long int tval=t2[t2.size()-2];
        //cout<<endl;
        //cout<<tval;
        //cout<<endl;
        long int finalAnswer=(sval*num1) + (tval*num2);
        if(r1.back()==finalAnswer) {
                cout<<"\nVerfied Answer";
                cout<<"\n" <<finalAnswer;
        }
        else{
                cout<<"\nSomething went wrong";
                cout<<"\n" <<finalAnswer;
        }
}
int main(){

        cout<<"\nEnter 2 numbers ->";
        cin>>num1>>num2;
        calculateGCD(num1,num2);
        printGCD();
        verifyGCD();

}
