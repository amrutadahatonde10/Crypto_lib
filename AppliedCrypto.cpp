#include<iostream>
using namespace std;

#include "Vigenere_Cipher.hpp"
#include "Hill_Cipher.hpp"
#include "Shift_Cipher.hpp"

int main()
{
    string ans = "THIS";
    string ans2 = "ISSC";
    string ans3 = "";
    cout<<"\n"<<ans;

    // Vigenere Cipher
    Vigenere_Cipher v;
    ans3 = v.Encryption(ans,ans2);
    cout<<"\n"<<ans3;
    ans3 = v.Decryption(ans3,ans2);
    cout<<"\n"<<ans3 <<"\n";

    // Shift Cipher 
    cout<<"\n"<<ans;
    Shift_Cipher sc;
    ans3 = sc.Encryption(ans,5);
    cout<<"\n"<<ans3;
    ans = sc.Decryption(ans3,5);
    cout<<"\n"<<ans;








    // //Hill Cipher
    // HillCipher hc;
    // hc.KeyForm();
    // ans3 = hc.Encryption(ans);
    // cout<<"\n"<<ans3;
    // ans = hc.Decryption(ans3);
    // cout<<"\n"<<ans;



    return 0;
}

















// g++ AppliedCrypto.cpp Shift_Cipher.cpp Vigenere_Cipher.cpp -o Myexe
// Myexe




// g++ AppliedCrypto.cpp Hill_Cipher.cpp Shift_Cipher.cpp Vigenere_Cipher.cpp -o Myexe
// Myexe