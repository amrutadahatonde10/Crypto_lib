#include <NTL/ZZ_p.h>
#include <iostream>
using namespace std;
using namespace NTL;

int main() {
    
    long prime;
    cout << "Enter prime modulus p: ";
    cin >> prime;

    ZZ_p::init(ZZ(prime)); 

    ZZ_p g;
    cout << "Enter generator g: ";
    cin >> g;

    long a, b;
    cout << "Enter Alice's private key a: ";
    cin >> a;
    cout << "Enter Bob's private key b: ";
    cin >> b;

    ZZ_p A = power(g, a);     //public keys
    ZZ_p B = power(g, b);     //public keys

    ZZ_p sharedAlice = power(B, a);
    ZZ_p sharedBob   = power(A, b);

    cout << "\n--- Diffie-Hellman Key Exchange ---\n";
    cout << "Prime modulus p = " << prime << "\n";
    cout << "Generator g = " << g << "\n";
    cout << "Alice private key a = " << a << "\n";
    cout << "Bob private key b = " << b << "\n";
    cout << "Alice public key A = g^a mod p = " << A << "\n";
    cout << "Bob public key B = g^b mod p = " << B << "\n";
    cout << "Alice shared key = B^a mod p = " << sharedAlice << "\n";
    cout << "Bob shared key = A^b mod p = " << sharedBob << "\n";

    return 0;
}


















// #include <NTL/ZZ_p.h>
// #include <iostream>

// using namespace std;
// using namespace NTL;

// int main() {
//     ZZ_p, g, a, b;

//     long prime;
//     cout << "Enter prime modulus p: ";
//     cin >> prime;
//     p = conv<ZZ>(prime);

//     long temp;
//     cout << "Enter generator g: ";
//     cin >> temp;
//     g = conv<ZZ>(temp);

//     cout << "Enter Alice's private key a: ";
//     cin >> temp;
//     a = conv<ZZ>(temp);

//     cout << "Enter Bob's private key b: ";
//     cin >> temp;
//     b = conv<ZZ>(temp);

//     // public keys
//     ZZ A = PowerMod(g, a, p); // Alice's public key
//     ZZ B = PowerMod(g, b, p); // Bob's public key

//     // shared secrets
//     ZZ sharedAlice = PowerMod(B, a, p);
//     ZZ sharedBob   = PowerMod(A, b, p);

//     cout << "\n--- Diffie-Hellman Key Exchange ---\n";
//     cout << "Prime modulus p = " << p << "\n";
//     cout << "Generator g = " << g << "\n";
//     cout << "Alice private a = " << a << "\n";
//     cout << "Bob private b = " << b << "\n";
//     cout << "Alice public A = " << A << "\n";
//     cout << "Bob public B = " << B << "\n";
//     cout << "Alice shared key = " << sharedAlice << "\n";
//     cout << "Bob shared key = " << sharedBob << "\n";

//     if (sharedAlice == sharedBob)
//         cout << "Shared secrets match!\n";
//     else
//         cout << "Shared secrets differ!\n";

//     return 0;
// }
