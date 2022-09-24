#include<bits/stdc++.h>
using namespace std;

char* setMatrix(string key) {
   static char playfair[5][5];
   int i, k;
   string letters="ABCDEFGHIJKLMNOPQRSTUVWXY";
   for (k=0, i=0; i<key.length(); ++i, ++k) {
      key[i]=toupper(key[i]);
      if (key.find(key[i])==i) playfair[k/5][k%5]=key[i];
      else k--;
   }
   for (int j=0; k<25; ++j) {
      if (key.find(letters[j])!=string::npos) continue;
      playfair[k/5][k%5]=letters[j];
      k++;
   }
   return &playfair[0][0];
}

string playfair(char* ptr, char a, char b) {
   int posA, posB;
   for (int i=0; i<25; ++i) {
      if (ptr[i]==a) posA=i;
      else if (ptr[i]==b) posB=i;
   }
   int row0=(posA/5)+1, row1=(posB/5)+1, col0=(posA%5)+1, col1=(posB%5)+1;
   char repa, repb;
   if (row0==row1) {
      repa = ptr[abs(((row0-1)*5)+col0%5)];
      repb = ptr[abs(((row1-1)*5)+col1%5)];
   }
   else if (col0==col1) {
      repa = ptr[abs((row0*5)+col0-1)%25];
      repb = ptr[abs((row1*5)+col1-1)%25];
   }
   else {
      repa = ptr[abs((row0-1)*5)+col1-1];
      repb = ptr[abs((row1-1)*5)+col0-1];
   }
   string str="";
   str+=repa; str+=repb;
   return str;
}

int main()
{
   string key, plaintext, ciphertext="";
   cout<<"\nBogus Letter: X [PlainText] (Replaces Same Character at Second Occurence in PlainText)\nSecond Bogus Letter: Y [PlainText] (Replaces 2 xs/Xs)\nOmmited Letter: Z (Replaced by Bogus Letter in PlainText)";
   cout<<"\n\nEnter Key: ";
   cin>>key;
   char* ptr = setMatrix(key);
   cout<<"\n";
   for (int i=0; i<25; i++) {
      cout<<ptr[i]<<" ";
      if (i%4==(i/4)-1) cout<<"\n";
   }
   cout<<"\n\nEnter PlainText: ";
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   getline(cin, plaintext);
   for (int i=0; i<plaintext.length(); i+=2) {
      char letter1=plaintext[i];
      
      if (letter1==' ') {
         i--; continue;
      }

      letter1=toupper(letter1);

      if ((i+1)>=plaintext.length()) {
         if (letter1!='X') ciphertext+=playfair(ptr, letter1, 'X');
         else ciphertext+=playfair(ptr, letter1, 'Y');
         continue;
      }
      char letter2=plaintext[i+1];
      if (letter2==' ') {
         while (letter2==' ') {
            i++;
            letter2=plaintext[i+1];
         }
      }
      letter2=toupper(letter2);

      if (letter1=='Z' && letter2=='Z') {
         ciphertext+="ZZ";
         continue;
      }
      if (letter1=='Z') {
         ciphertext+='Z';
         i--;
         continue;
      }
      if (letter2=='Z') {
         ciphertext+='Z';
         while (letter2=='Z') {
            i++;
            letter2=plaintext[i+1];
         }
      }

      else if (letter1==' ' && letter2==' ') {
         ciphertext+=playfair(ptr, 'X', 'Y');
      }
      else if (letter1==letter2) {
         if (letter1!='X') ciphertext+=playfair(ptr, letter1, 'X');
         else ciphertext+=playfair(ptr, letter1, 'Y');
         i-=1;
      }
      else { 
         ciphertext+=playfair(ptr, letter1, letter2);
      }
   }
   cout<<"\nCipherText: "<<ciphertext<<"\n";

   return 0;
}
