#include <iostream>
#include <NTL/ZZ.h>
#include "Vigenere_Cipher/Vigenere_Cipher.hpp"
#include "Hill_Cipher/Hill_Cipher.hpp" 
#include "Shift_Cipher/Shift_Cipher.hpp"
#include "OTP/OneTimePad.hpp"
#include "Diffie_Hellman/Diffie_Hellman.hpp"
#include "El-Gamal/El_Gamal.hpp"
#include "Eliptic_Curve/Eliptic_Curve.hpp"
#include "Int_Fact/RSA.hpp"
#include "R-adding_walk/R-adding.hpp"
 
using namespace std;
using namespace NTL;

int main() 
{
    // cout << "hello World";
    // string ans = "Cryptography";
    // string ans2 = "cississc";
    // string ans3 = "";
    // cout << "\n" << ans;

    // // Shift Cipher
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

    // // Vigenere Cipher
    // cout << "\n\n --- Vigenere Cipher --- ";
    // Vigenere_Cipher v;
    // cout << "\nORG - " << ans;
    // ans3 = v.Encryption(ans, ans2);
    // cout << "\nENC - " << ans3;
    // ans3 = v.Decryption(ans3, ans2);
    // cout << "\nDEC - " << ans3;

    // // Hill Cipher
    // cout << "\n\n --- Hill Cipher ---";
    // HillCipher hc;
    // hc.GenerateRandomKey();
    // cout << "\nORG - " << ans;
    // ans3 = hc.Encryption(ans);
    // cout << "\nENC - " << ans3;
    // ans3 = hc.Decryption(ans3);
    // cout << "\nDEC - " << ans3;

    // // One Time Pad
    // cout << "\n\n --- One Time Pad ---";
    // OneTimePad otp;
    // string key = otp.generateKey(ans.size());
    // cout << "\nORG - " << ans;
    // ans3 = otp.encrypt(ans);
    // cout << "\nENC - " << ans3;
    // ans3 = otp.decrypt(ans3);
    // cout << "\nDEC - " << ans3;


    // // Diffie Hellman
    // DiffieHellman dh(13);
    // cout << "\n\n --- Diffie Hellman ---";
    // dh.generateValues();
    // dh.computePublicKeys();
    // dh.computeSharedKeys();
    // dh.display();



    // // El-Gamal
    // cout << "\n--- El-Gamal ---\n";
    // ElGamal elg(257); 

    // elg.generateKeys();
    // elg.showKeys();

    // // Encrypt/decrypt number
    // ZZ_p m = conv<ZZ_p>(15);     
    // ZZ_p c1, c2;    
    // elg.encrypt(m, c1, c2);
    // ZZ_p dec = elg.decrypt(c1, c2);
    // cout << "\nOriginal m = " << m << ", Decrypted m = " << dec << "\n";

    // // Encrypt/decrypt string
    // string msg = "Hello World";
    // vector<ZZ_p> c1s, c2s;
    // elg.encryptString(msg, c1s, c2s);
    // string decMsg = elg.decryptString(c1s, c2s);
    // cout << "Original msg = " << msg << ", Decrypted msg = " << decMsg << "\n";

    // // Signing and verification
    // ZZ mHash = conv<ZZ>(2);
    // ZZ_p r, s;
    // elg.signMessage(mHash, r, s);
    // cout << "\nSignature: r = " << r << ", s = " << s << "\n";

    // bool ok = elg.verifyMessage(mHash, r, s);
    // cout << "Verify: " << (ok ? "valid ✅" : "invalid ❌") << "\n";




// cout << "\n\n------------------------- Elliptic Curve -------------------------\n";

    // ZZ p = conv<ZZ>(97); // prime modulus
    // ZZ aEC = conv<ZZ>(2);
    // ZZ bEC = conv<ZZ>(3);

    // // Create elliptic curve and initialize ZZ_p field
    // ELCurve curve(p, aEC, bEC);

    // // Define points using ZZ_p type
    // ZZ_p Px = to_ZZ_p(3);
    // ZZ_p Py = to_ZZ_p(6);
    // ZZ_p Qx = to_ZZ_p(80);
    // ZZ_p Qy = to_ZZ_p(10);

    // ECPoint P(Px, Py);
    // ECPoint Q(Qx, Qy);

    // // Point At Curve or Not [ Validation ]
    // cout << "\nChecking points validity:\n";
    // cout << "P is " << (curve.isValidPoint(P) ? "valid" : "invalid") << endl;
    // cout << "Q is " << (curve.isValidPoint(Q) ? "valid" : "invalid") << endl;

    // // P + Q  Point Addition
    // ECPoint R = curve.pointAdd(P, Q);
    // cout << "\nR = P + Q" << endl;
    // if (R.infinity)
    //     cout << "R is point at infinity\n";
    // else
    //     cout << "R = (" << rep(R.x) << ", " << rep(R.y) << ")\n";

    // // 2P Point Doubling
    // ECPoint D = curve.pointDouble(P);
    // cout << "\nD = 2P" << endl;
    // if (D.infinity)
    //     cout << "D is point at infinity\n";
    // else
    //     cout << "D = (" << rep(D.x) << ", " << rep(D.y) << ")\n";

    // // scalar multiplication
    // ECPoint SR = curve.scalarMultiply(P, bEC);
    // cout << "\nSR.x = " << SR.x << ", SR.y = " << SR.y << endl;



    // cout << "\n---------------- ElGamal over Elliptic Curve ----------------\n";

    // ZZ p = conv<ZZ>(97);
    // ZZ_p::init(p);

    // ZZ_p a = conv<ZZ_p>(2);
    // ZZ_p b = conv<ZZ_p>(3);

    // ELCurve curve(a, b);
    // ECPoint G(conv<ZZ_p>(2), conv<ZZ_p>(7));
    // ZZ n = conv<ZZ>(5);

    // // --- Key Generation ---
    // ZZ priv = conv<ZZ>(4);  // private key
    // ECPoint pub = curve.generatePublicKey(G, priv);

    // cout << "Private key: " << priv << "\n";
    // cout << "Public key: (" << pub.x << ", " << pub.y << ")\n";

    // // --- Encryption ---
    // ECPoint M(conv<ZZ_p>(3), conv<ZZ_p>(6));
    // ZZ k = conv<ZZ>(3);               // select y
    // auto cipher = curve.encrypt(M, G, pub, k);  

    // cout << "\nCiphertext:\nC1 = (" << cipher.first.x << ", " << cipher.first.y << ")\n";
    // cout << "C2 = (" << cipher.second.x << ", " << cipher.second.y << ")\n";

    // // --- Decryption ---
    // ECPoint dec = curve.decrypt(cipher, priv);
    // cout << "\nDecrypted Message: (" << dec.x << ", " << dec.y << ")\n";

    // // --- Digital Signature ---
    // ZZ msgHash = conv<ZZ>(25);
    // auto sig = curve.sign(msgHash, priv, G, n); // 25, 4, (2,7), 5
    // cout << "\nSignature: (r=" << sig.first << ", s=" << sig.second << ")\n";

    // bool valid = curve.verify(msgHash, sig, G, pub, n);
    // cout << "Signature verification: " << (valid ? "VALID" : "INVALID") << endl;




    cout << "\n---------------- RSA----------------\n";

    unsigned int bits = 32;
    ZZ e = ZZ(65537);           // RSA public exponent


    RSAKey key = RSA_GenerateKeys(bits, e); 


    ZZ message = ZZ(12345);
    cout << "Plain: " << message << endl;


    ZZ cipher = RSA_Encrypt(message, key);
    cout << "Cipher: " << cipher << endl;


    ZZ decrypted = RSA_Decrypt(cipher, key);
    cout << "Decrypted: " << decrypted << endl;





    cout << "\n---------------- R-adding walk----------------\n";


    ZZ p = ZZ(197);
    ZZ g = ZZ(123);
    ZZ h = ZZ(111);
    long r = 5; 

    RAddingPollard solver(p, g, h, r);

    vector<ZZ> delta = {ZZ(1), ZZ(7), ZZ(4), ZZ(8), ZZ(8)};
    vector<ZZ> tau   = {ZZ(4), ZZ(5), ZZ(2), ZZ(5), ZZ(2)};
    solver.setTable(delta, tau);

    ZZ x = solver.solve();

    cout << "\nFinal solution x = " << x << "\n";








    
    return 0;
}


  






// g++ AppliedCrypto.cpp Eliptic_Curve/Eliptic_Curve.cpp -lntl -lgmp -o Myexe
// ./Myexe

//g++ AppliedCrypto.cpp Int_Fact/RSA.cpp -lntl -lgmp -o Myexe

// g++ AppliedCrypto.cpp R-adding_walk/R-adding.cpp -lntl -lgmp -o Myexe
