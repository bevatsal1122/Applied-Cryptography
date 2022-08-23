#include<bits/stdc++.h>
#include <cctype>
#include <cstring>
using namespace std;

string ccEncryptAlgorithm(string str, int key) {
   int strLength = str.length();
   string small  = "abcdefghijklmnopqrstuvwxyz", high  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", encrString = "";
   for (int i=0; i<strLength; ++i) {
      if (isupper(str[i])) {
         size_t letter = high.find(str[i]);
         encrString += high[(letter+key)%26];
      }
      else if (islower(str[i])) {
         size_t letter = small.find(str[i]);
         encrString += small[(letter+key)%26];
      }
      else encrString += " ";
   }
   return encrString;
}

string ccDecryptAlgorithm(string str, int key) {
   int strLength = str.length();
   string small  = "abcdefghijklmnopqrstuvwxyz", high  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", decrString = "";
   for (int i=0; i<strLength; ++i) {
      if (isupper(str[i])) {
         size_t letter = high.find(str[i]);
         decrString += high[(letter-key+26)%26];
      }
      else if (islower(str[i])) {
         size_t letter = small.find(str[i]);
         decrString += small[(letter-key+26)%26];
      }
      else decrString += " ";
   }
   return decrString;
}

int main()
{  
   string str, encrString, decrString;
   int key=3, choice;
   cout<<"Enter 1: To Encrypt a String,  2: Decrypt a String\n";
   cin>>choice;
   if (choice==1) {
      cout<<"Enter String to Encrypt: ";
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      getline(cin, str);
      encrString = ccEncryptAlgorithm(str, key);
      cout<<"Encrypted String is "<<encrString;
   }
   else if (choice==2) {
      cout<<"Enter String to Decrypt: ";
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      getline(cin, str);
      decrString = ccDecryptAlgorithm(str, key);
      cout<<"Decrypted String is "<<decrString;
   }
   else cout<<"Wrong Choice Entered!!";
   return 0;
}
