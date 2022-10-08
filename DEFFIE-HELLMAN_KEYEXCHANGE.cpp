#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
   for (int i=2; i<=sqrt(n); ++i) {
      if (n%i==0) return 0;
   }
   return 1;
}

int round(int k, int l, int m) {
   long long value=pow(k, l);
   return value%m;
}

int main() {
   int g, p, a, b;
   cout<<"\nEnter g: ";
   cin>>g;
   cout<<"Enter p: ";
   cin>>p;
   while(!checkPrime(p)) {
      cout<<"p should be a Prime Number whearas Entered Value "<<p<<" is not a Prime Number.\nEnter p: ";
      cin>>p; 
   }
   cout<<"Enter a: ";
   cin>>a;
   while(a>=p) {
      cout<<"a should be less than p whearas Entered Value "<<a<<" is not less than "<<p<<".\nEnter a: ";
      cin>>a; 
   }
   cout<<"Enter b: ";
   cin>>b;
   while(b>=p) {
      cout<<"b should be less than p whearas Entered Value "<<a<<" is not less than "<<p<<".\nEnter b: ";
      cin>>b; 
   }
   long long X=round(g, a, p);
   long long Y=round(g, b, p);
   long long keyX=round(Y, a, p);
   long long keyY=round(X, b, p);
   cout<<"\nKey1: "<<keyX<<"\n"<<"Key2: "<<keyY<<"\n";
   return 0;
}
