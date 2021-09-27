// Implementasi Affine Cipher di CPP

#include <iostream>

using namespace std;

// fungsi untuk mengenkripsi teks pengguna
// pesan string, int alfa, dan int beta adalah parameter yang dibawa dalam fungsi enkripsi dan dekripsi
string encryption(string message, int alpha, int beta)
{
   string encryptedtext = "";

     for(int r = 0; r < message.length(); r++)
     {
// rumus enkripsi diterapkan
       if(message[r] != ' ')
          encryptedtext = encryptedtext + (char) ((((alpha * (message[r] - 'A')) + beta) % 26) + 'A');
       else
          encryptedtext += message[r];

     }
// program mengembalikan teks terenkripsi untuk output
   return encryptedtext;

}

// fungsi mendekripsi teks pengguna kembali ke pesan aslinya
string decryption(string message, int alpha, int beta)
{
   string decryptedtext = "";

     for(int s = 0; s < message.length(); s++)
     {

// rumus dekripsi diterapkan
       if(message[s] != ' ')
         decryptedtext = decryptedtext + (char) ((((alpha * (message[s] - 'A')) - beta) % 26 ) + 'A');
       else
         message += decryptedtext[s];
     }

  return message;
}

int main()
{
   string message;
   char i;
   int key1, key2;

// memasukkan string dengan huruf kapital semua (spasi diperbolehkan)
   while(message[i] < 'A' || message[i] > 'Z')
   {
      cout << "Masukkan huruf A - Z : ";
      getline(cin, message);
   }
// memasukkan nilai numerik untuk alfa dengan kondisi yang diberikan
   while(key1 <= 0 || key1 >= 26)
   {
      cout << "Masukkan Nilai 1-25 untuk key 1  :";
      cin >> key1;
   }

// memasukkan nilai numerik untuk beta dengan kondisi yang diberikan
   while(key2 <= 0 || key2 >= 26)
   {
      cout << "Masukkan Nilai 0-25 untuk key 2 :";
      cin >> key2;
   }

// Program mengembalikan pesan pengguna, enkripsi pesan, dan dekripsi pesan

   cout << "Your message is: " << message << endl;
   cout << "Your encrypted message is: " << encryption(message, key1, key2) << endl;
   cout << "The decrypted message is: " << decryption(message, key1, key2) << endl;
}
