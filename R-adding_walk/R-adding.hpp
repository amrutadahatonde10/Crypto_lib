#ifndef ASSIGN_HPP
#define ASSIGN_HPP

#include <NTL/ZZ.h>
#include <vector>
using namespace NTL;
using std::vector;

class RAddingPollard {
public:
    struct State {
        ZZ x; // current value mod p
        ZZ a; // exponent of g (mod order)
        ZZ b; // exponent of h (mod order)
    };
 
    RAddingPollard(const ZZ& p, const ZZ& g, const ZZ& h, long r);

    void setTable(const vector<ZZ>& delta, const vector<ZZ>& tau);

    ZZ solve();

private:
    State f(const State& s); // single step of r-adding walk
    ZZ p_, g_, h_, order_;
    long r_;
    vector<ZZ> delta_, tau_; 

    // helper: compute M_u = g^{delta[u]} * h^{tau[u]} mod p
    ZZ computeM(long u) const;
};

#endif // ASSIGN_HPP