#ifndef RSA_HPP
#define RSA_HPP

#include <NTL/ZZ.h>
using namespace NTL;


struct RSAKey {
ZZ n;  // modulo
ZZ e;  // public exponent
ZZ d;  // private exponent
};


RSAKey RSA_GenerateKeys(unsigned int bitsPerPrime, const NTL::ZZ &publicE);
ZZ RSA_Encrypt(const ZZ &m, const RSAKey &key);
ZZ RSA_Decrypt(const ZZ &c, const RSAKey &key);


#endif