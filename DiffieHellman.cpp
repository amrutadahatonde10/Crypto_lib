#include "DiffieHellman.hpp"

NTL::ZZ DiffieHellman::modExp(const NTL::ZZ& base, const NTL::ZZ& exp, const NTL::ZZ& mod) const {
    NTL::ZZ result = NTL::to_ZZ(1);
    NTL::ZZ b = base % mod;
    NTL::ZZ e = exp;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % mod;
        }
        b = (b * b) % mod;
        e /= 2;
    }
    return result;
}

DiffieHellman::DiffieHellman(const NTL::ZZ& prime, const NTL::ZZ& generator)
    : p(prime), g(generator), privateKey(NTL::to_ZZ(0)), publicKey(NTL::to_ZZ(0)) {}

void DiffieHellman::setPrivateKey(const NTL::ZZ& priv) {
    privateKey = priv;
    publicKey = modExp(g, privateKey, p);
}

NTL::ZZ DiffieHellman::getPublicKey() const {
    return publicKey;
}

NTL::ZZ DiffieHellman::getSharedSecret(const NTL::ZZ& otherPublic) const {
    return modExp(otherPublic, privateKey, p);
}
