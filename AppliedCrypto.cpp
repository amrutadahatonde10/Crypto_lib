#include <iostream>
using namespace std;

#include "Vigenere_Cipher.hpp"
#include "Hill_Cipher.hpp"
#include "Shift_Cipher.hpp"
#include "OneTimePad.hpp"
#include "DiffieHellman.hpp"

int main()
{
    string ans = "Cryptography";
    string ans3 = "";
    cout << "\n" << ans;

    // Shift Cipher
    // cout << "\n\n --- Shift Cipher --- ";
    // Shift_Cipher sc;
    // char AD = char(69);
    // string a = "";
    // a += AD;
    // cout << "\nORG - " << ans;
    // ans3 = sc.Encryption(ans, a);
    // cout << "\nENC - " << ans3;
    // ans = sc.Decryption(ans3, a);
    // cout << "\nDEC - " << ans;

    // Vigenere Cipher
    // cout << "\n\n --- Vigenere Cipher --- ";
    // Vigenere_Cipher v;
    // cout << "\nORG - " << ans;
    // ans3 = v.Encryption(ans, "ISSC");
    // cout << "\nENC - " << ans3;
    // ans3 = v.Decryption(ans3, "ISSC");
    // cout << "\nDEC - " << ans3;

    // Hill Cipher
    // cout << "\n\n --- Hill Cipher ---";
    // HillCipher hc;
    // hc.GenerateRandomKey();
    // cout << "\nORG - " << ans;
    // ans3 = hc.Encryption(ans);
    // cout << "\nENC - " << ans3;
    // ans3 = hc.Decryption(ans3);
    // cout << "\nDEC - " << ans3;






    // One Time Pad
    cout << "\n\n --- One Time Pad ---";
    OneTimePad otp;
    string key = otp.generateKey(ans.size());
    cout << "\nORG - " << ans;
    ans3 = otp.encrypt(ans);
    cout << "\nENC - " << ans3;  
    ans3 = otp.decrypt(ans3);
    cout << "\nDEC - " << ans3;

    // Diffie-Hellman Key Exchange
    cout << "\n\n --- Diffie-Hellman Key Exchange ---\n";
    ZZ p = to_ZZ("13");
    ZZ g = to_ZZ("2");

    // Alice
    DiffieHellman Alice(p, g);
    Alice.setPrivateKey(to_ZZ("11")); // Alice's private key
    ZZ pubAlice = Alice.getPublicKey();

    // Bob
    DiffieHellman Bob(p, g);
    Bob.setPrivateKey(to_ZZ("9"));  // Bob's private key
    ZZ pubBob = Bob.getPublicKey();

    cout << "Prime (p): " << p << endl;
    cout << "Generator (g): " << g << endl;
    cout << "Alice's Public Key: " << pubAlice << endl;
    cout << "Bob's Public Key: " << pubBob << endl;

    // Compute shared secret
    ZZ secretAlice = Alice.getSharedSecret(pubBob);
    ZZ secretBob = Bob.getSharedSecret(pubAlice);

    cout << "Shared Secret at Alice: " << secretAlice << endl;
    cout << "Shared Secret at Bob: " << secretBob << endl;


    return 0;
}




// g++ AppliedCrypto.cpp OneTimePad.cpp DiffieHellman.cpp -o Myexe -lntl -lgmp
// ./Myexe
