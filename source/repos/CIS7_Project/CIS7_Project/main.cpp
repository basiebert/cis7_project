#include <iostream>
#include <string>
using namespace std;

class VigenereCipher {
public:
     string encrypt(string plaintext, string key) {
          string ciphertext = ""; // initialize an empty string for the encrypted message
          int keyLength = key.length();

          for (int i = 0; i < plaintext.length(); ++i) { // loop through each plaintext character
               char plainChar = plaintext[i];
               char keyChar = key[i % keyLength];
               ciphertext += encryptChar(plainChar, keyChar); // add the encrypted character to the encrypted message string
          }
          return ciphertext;
     }

     string decrypt(string ciphertext, string key) {
          string plaintext = ""; // initialize an empty string for the decrypted message
          int keyLength = key.length();

          for (int i = 0; i < ciphertext.length(); ++i) { // loop through each ciphertext character
               char cipherChar = ciphertext[i];
               char keyChar = key[i % keyLength];
               plaintext += decryptChar(cipherChar, keyChar); // add the decrypted character to the decrypted message string
          }
          return plaintext;
     }

private:
     char encryptChar(char plainChar, char keyChar) { // use the Vigenere cipher to encrypt the plaintext string
          if (isalpha(plainChar)) {
               char base = isupper(plainChar) ? 'A' : 'a';
               char encryptedChar = ((toupper(plainChar) - 'A' + (toupper(keyChar) - 'A')) % 26) + 'A';
               return isupper(plainChar) ? encryptedChar : tolower(encryptedChar);
          }
          return plainChar;
     }

     char decryptChar(char cipherChar, char keyChar) { // use the Vigenere cipher to decrypt the ciphertext string
          if (isalpha(cipherChar)) {
               char base = isupper(cipherChar) ? 'A' : 'a';
               int offset = (toupper(cipherChar) - 'A' - (toupper(keyChar) - 'A') + 26) % 26;
               char decryptedChar = (offset + 'A');
               return isupper(cipherChar) ? decryptedChar : tolower(decryptedChar);
          }
          return cipherChar;
     }
};

void clearInputBuffer() {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
     VigenereCipher vigenere;

     char choice;

     do {
          cout << "Enter 'E' to encrypt or 'D' to decrypt: ";
          cin >> choice;

          string inputText, key;
          cout << "Enter the text: "; // User inputs text
          clearInputBuffer();
          getline(cin, inputText);

          cout << "Enter the key: "; // User inputs keyword
          cin >> key;

          if (toupper(choice) == 'E') {
               string ciphertext = vigenere.encrypt(inputText, key);
               cout << "Encrypted Text: " << ciphertext << endl; // display the encrypted message
          }
          else if (toupper(choice) == 'D') {
               string decryptedText = vigenere.decrypt(inputText, key);
               cout << "Decrypted Text: " << decryptedText << endl; // display the decrypted message
          }
          else {
               cout << "Invalid choice. Please enter 'E' to encrypt or 'D' to decrypt." << endl;
          }

          cout << "Do you want to encrypt or decrypt another message? (Y/N): ";
          cin >> choice;
     } while (toupper(choice) == 'Y');

     cout << "Program terminated." << endl;

     return 0;
}