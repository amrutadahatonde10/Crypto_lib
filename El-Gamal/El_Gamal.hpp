#ifndef ELGAMAL_HPP
#define ELGAMAL_HPP

#include <NTL/ZZ_p.h>
#include <vector>
#include <string>

class ElGamal
{
private:
    NTL::ZZ p;      // modulus
    NTL::ZZ_p g;    // generator
    NTL::ZZ_p x;    // private key
    NTL::ZZ_p h;    // public component (h = g^x)

public:
    ElGamal(long prime);

    void generateKeys();
    void showKeys() const;

    // Encryption & Decryption
    void encrypt(const NTL::ZZ_p &m, NTL::ZZ_p &c1, NTL::ZZ_p &c2);
    NTL::ZZ_p decrypt(const NTL::ZZ_p &c1, const NTL::ZZ_p &c2);

    // String encryption/decryption
    void encryptString(const std::string &msg,
                       std::vector<NTL::ZZ_p> &c1s,
                       std::vector<NTL::ZZ_p> &c2s);
    std::string decryptString(const std::vector<NTL::ZZ_p> &c1s,
                              const std::vector<NTL::ZZ_p> &c2s);

    // Signing & Verification
    void signMessage(const NTL::ZZ &m, NTL::ZZ_p &r, NTL::ZZ_p &s);
    bool verifyMessage(const NTL::ZZ &m, const NTL::ZZ_p &r, const NTL::ZZ_p &s);
};

#endif