#include "El_Gamal.hpp"
#include <NTL/ZZ_p.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace NTL;

ElGamal::ElGamal(long prime)
{
    p = conv<ZZ>(prime);
    ZZ_p::init(p); // initialize modular field
    srand(static_cast<unsigned>(time(nullptr)));
}

void ElGamal::generateKeys()
{
    g = conv<ZZ_p>(2 + (rand() % (conv<long>(p) - 3)));
    x = conv<ZZ_p>(1 + (rand() % (conv<long>(p) - 2)));
    h = power(g, conv<ZZ>(rep(x))); // h = g^x
}

void ElGamal::showKeys() const
{
    cout << "Public key: p=" << p << ", g=" << g << ", h=" << h << "\n";
    cout << "Private key: x=" << x << "\n";
}

void ElGamal::encrypt(const ZZ_p &m, ZZ_p &c1, ZZ_p &c2)
{
    ZZ y = conv<ZZ>(1 + (rand() % (conv<long>(p) - 2)));
    c1 = power(g, y);
    ZZ_p s = power(h, y);
    c2 = m * s;
}

ZZ_p ElGamal::decrypt(const ZZ_p &c1, const ZZ_p &c2)
{
    ZZ_p s = power(c1, conv<ZZ>(rep(x)));
    return c2 * inv(s);
}

void ElGamal::encryptString(const string &msg,
                            vector<ZZ_p> &c1s,
                            vector<ZZ_p> &c2s)
{
    c1s.clear();
    c2s.clear();
    for (char ch : msg)
    {
        ZZ_p m = conv<ZZ_p>(static_cast<int>(ch));
        ZZ_p c1, c2;
        encrypt(m, c1, c2);
        c1s.push_back(c1);
        c2s.push_back(c2);
    }
}

string ElGamal::decryptString(const vector<ZZ_p> &c1s,
                              const vector<ZZ_p> &c2s)
{
    string result;
    for (size_t i = 0; i < c1s.size(); ++i)
    {
        ZZ_p m = decrypt(c1s[i], c2s[i]);
        long val = conv<long>(rep(m)) % 256;
        result.push_back(static_cast<char>(val));
    }
    return result;
}

void ElGamal::signMessage(const ZZ &m, ZZ_p &r, ZZ_p &s)
{
    ZZ p1 = p - 1;
    ZZ k;

    // random k coprime to p-1
    do
    {
        k = conv<ZZ>(1 + (rand() % (conv<long>(p1) - 1)));
    } while (GCD(k, p1) != 1);

    r = power(g, k);
    ZZ kInv = InvMod(k, p1);

    ZZ s_val = (kInv * (m - conv<ZZ>(rep(x)) * conv<ZZ>(rep(r)))) % p1;
    if (s_val < 0)
        s_val += p1;

    s = conv<ZZ_p>(s_val);
}

bool ElGamal::verifyMessage(const ZZ &m, const ZZ_p &r, const ZZ_p &s)
{
    ZZ_p left = power(h, conv<ZZ>(rep(r))) * power(r, conv<ZZ>(rep(s)));
    ZZ_p right = power(g, m);
    return left == right;
}
