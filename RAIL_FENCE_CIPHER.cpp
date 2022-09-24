// Code by bevatsal1122
// Trust God, Your Code Will Work

#include<bits/stdc++.h>
using namespace std;

string encryptRailFence(int height, string plaintext) {
   string ciphertext="";
   for (int i=0; i<height && ciphertext.length()<plaintext.length(); ++i) {
      int iter=i, down=((height-i-1)*2), up=i*2;
      bool checkDown=true;
      while (iter<plaintext.length()) {
         ciphertext+=plaintext[iter];
         if ((down && checkDown) || (!up && !checkDown)) iter+=down;
         else if ((up && !checkDown) || (!down && checkDown)) iter+=up;
         checkDown=!checkDown;
      }
   }
   return ciphertext;
}

string decryptRailFence(int height, string ciphertext) {
   string plaintext="";
   char data[height][ciphertext.length()];
   for (int i=0; i<height; ++i) {
      for (int j=0; j<ciphertext.length(); ++j) {
         data[i][j]='-';     
      }
   }
   int row=0, column=0;
   bool down;
   for (int i=0; i<ciphertext.length(); ++i) {
      if (row==0) down=true;
      if (row==height-1) down=false;
      data[row][column++]='*';
      if (down) row++;
      else row--;
   }
   for (int i=0, pos=0; i<height; ++i) {
      for (int j=0; j<ciphertext.length(); ++j) {
         if (data[i][j]=='*' && pos<ciphertext.length()) {
            data[i][j]=ciphertext[pos++];
         }
      }
   }
   row=0;
   column=0;
   for (int i=0; i<height; ++i) {
      for (int j=0; j<ciphertext.length() && plaintext.length()<ciphertext.length(); ++j) {
         if (row==0) down=true;
         if (row==height-1) down=false;
         plaintext+=data[row][column++];
         if (down) row++;
         else row--;
      }
   }
   return plaintext;
}

int main()
{
   int choice;
   cout<<"\nOptions-\n1. Encrypt -> Rail Fence Cipher\n2. Decrypt -> Rail Fence Cipher\n3. Exit\nEnter Choice: ";
   cin>>choice;
   while (choice!=3) {
      if (choice==1 || choice==2) {
         int height;
         cout<<"\nEnter Height: ";
         cin>>height;
         if (choice==1) {
            string plaintext;
            cout<<"Enter Plaintext: ";
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
            getline(cin, plaintext);
            cout<<"\nPlaintext: "<<plaintext;
            cout<<"\nCiphertext: "<<encryptRailFence(height, plaintext)<<"\n";
         }
         else if (choice==2) {
            string ciphertext;
            cout<<"Enter Ciphertext: ";
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
            getline(cin, ciphertext);
            cout<<"\nCiphertext: "<<ciphertext;
            cout<<"\nPlaintext: "<<decryptRailFence(height, ciphertext)<<"\n";
         }
      }
      else {
         cout<<"\nWrong Option!!\n";
      }
      cout<<"\nOptions-\n1. Encrypt -> Rail Fence Cipher\n2. Decrypt -> Rail Fence Cipher\n3. Exit\nEnter Choice: ";
      cin>>choice;
   }
   cout<<"Exiting...\n";

   return 0;
}
