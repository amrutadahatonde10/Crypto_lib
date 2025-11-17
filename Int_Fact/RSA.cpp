#include "RSA.hpp"
#include <NTL/ZZ.h>
#include <iostream>

using namespace NTL;
using namespace std;

RSAKey RSA_GenerateKeys(unsigned int bitsPerPrime, const ZZ &publicE) {
RSAKey key;
ZZ p, q, e = publicE;


do {
do { p = RandomBits_ZZ(bitsPerPrime) | 1; } while (!ProbPrime(p));
do { q = RandomBits_ZZ(bitsPerPrime) | 1; } while (!ProbPrime(q) || p == q);
} while (p == q);


key.n = p * q;
ZZ phi = (p - 1) * (q - 1);   


if (GCD(e, phi) != 1) {
e = ZZ(3);
while (GCD(e, phi) != 1) e += 2;
}


key.e = e;               // public
key.d = InvMod(e, phi); //Private exponent d = e⁻¹ mod φ(n)
return key;
}


ZZ RSA_Encrypt(const ZZ &m, const RSAKey &key) {
return PowerMod(m, key.e, key.n);
}


ZZ RSA_Decrypt(const ZZ &c, const RSAKey &key) {
return PowerMod(c, key.d, key.n);
}