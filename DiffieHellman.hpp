#ifndef DIFFIE_HELLMAN_HPP
#define DIFFIE_HELLMAN_HPP

#include <NTL/ZZ.h>

class DiffieHellman {
private:
    NTL::ZZ p;
    NTL::ZZ g;
    NTL::ZZ privateKey;
    NTL::ZZ publicKey;

    NTL::ZZ modExp(const NTL::ZZ& base, const NTL::ZZ& exp, const NTL::ZZ& mod) const;

public:
    DiffieHellman(const NTL::ZZ& prime, const NTL::ZZ& generator);

    void setPrivateKey(const NTL::ZZ& priv);
    NTL::ZZ getPublicKey() const;
    NTL::ZZ getSharedSecret(const NTL::ZZ& otherPublic) const;
};

#endif
