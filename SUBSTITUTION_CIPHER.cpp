#include<bits/stdc++.h>
#include<cctype>
#include<cstring>

using namespace std;
int main()
{
   int choice;
   string letters="abcdefghijklmnopqrstuvwxyz";
   cout<<"\n1. Convert CipherText to PlainText\n2. Find Solution Key\n\nEnter Choice: ";
   cin>>choice;

   if (choice==1) {
      string rep, ciphertext, plaintext="";
      cout<<"\nEnter CipherText: \n\n";
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      getline(cin, ciphertext);
      cout<<"\nEnter Replacement Key: ";
      cin>>rep;
      for (int i=0; i<ciphertext.length(); i++)
      {
         if (isalpha(ciphertext[i])) plaintext += rep[letters.find(ciphertext[i])];
         else plaintext += ciphertext[i];
      }
      cout<<"\nPlainText: \n\n"<<plaintext;
   }

   else if (choice==2) {
      string encrypted, decrypted, key="";
      cout<<"\nEnter CipherText: \n\n";
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      getline(cin, encrypted);
      cout<<"\nEnter PlainText: \n\n";
      getline(cin, decrypted);
      for (char letter:letters) {
         size_t position=encrypted.find(letter);
         key+=position!=string::npos?decrypted[position]:('-');
      }
      cout<<"\nSolution Key: "<<key<<"\nMissed Entities: ";
      for (char letter:letters) {
         char todisplay=toupper(letter);
         size_t position=key.find(todisplay);
         if (position==string::npos) cout<<todisplay<<" ";
      }
   }
   cout<<"\n";

   return 0;
}
