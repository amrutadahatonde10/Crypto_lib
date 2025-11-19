#include "R-adding.hpp"
#include <NTL/ZZ_p.h>
#include <iostream>

using namespace std;

RAddingPollard::RAddingPollard(const ZZ& p, const ZZ& g, const ZZ& h, long r)
    : p_(p), g_(g), h_(h), order_(p - 1), r_(r)
{
    delta_.assign(r_, ZZ(0));
    tau_.assign(r_, ZZ(0));

    for (long i = 0; i < r_; ++i) {
        delta_[i] = RandomBnd(order_); // random in [0, order-1]
        tau_[i]   = RandomBnd(order_);
    }
}

void RAddingPollard::setTable(const vector<ZZ>& delta, const vector<ZZ>& tau) {
    if ((long)delta.size() != r_ || (long)tau.size() != r_) {
        cerr << "setTable: wrong table size\n";
        return;
    }
    delta_ = delta;
    tau_ = tau;
}

ZZ RAddingPollard::computeM(long u) const {
    // M_u = g^{delta_u} * h^{tau_u} mod p
    ZZ part1 = PowerMod(g_, delta_[u], p_);
    ZZ part2 = PowerMod(h_, tau_[u], p_);
    return (part1 * part2) % p_;
}

RAddingPollard::State RAddingPollard::f(const State& s) {
    State next = s;
    long u = conv<long>(s.x % r_); // partition index (0..r-1)

    // update x by multiplying the precomputed M_u
    ZZ M = computeM(u);
    next.x = (s.x * M) % p_; // x1 find

    // update exponents modulo order
    next.a = (s.a + delta_[u]) % order_;
    next.b = (s.b + tau_[u]) % order_;

    return next;
}

ZZ RAddingPollard::solve() {
    while (true) {
        ZZ a0 = RandomBnd(order_);
        ZZ b0 = RandomBnd(order_);

        State slow, fast;
        slow.a = a0; slow.b = b0;
        slow.x = (PowerMod(g_, a0, p_) * PowerMod(h_, b0, p_)) % p_;
        fast = slow;

        cout << "Starting run: a0=" << a0 << " b0=" << b0 << " x0=" << slow.x << "\n";
        cout << "i\tslow.x\tslow.a\tslow.b\t|\tfast.x\tfast.a\tfast.b\n";

        long i = 0;
        // we will print initial state as i=0
        cout << i << "\t" << slow.x << "\t" << slow.a << "\t" << slow.b
             << "\t|\t" << fast.x << "\t" << fast.a << "\t" << fast.b << "\n";

        bool restart = false;
        // iterate until collision
        while (true) {
            ++i;
            // slow by 1
            slow = f(slow);

            // fast by 2
            fast = f(fast);
            fast = f(fast);

            cout << i << "\t" << slow.x << "\t" << slow.a << "\t" << slow.b
                 << "\t|\t" << fast.x << "\t" << fast.a << "\t" << fast.b << "\n";

            if (slow.x == fast.x) {
                cout << "\nCollision found at i = " << i << " : x = " << slow.x << "\n";
                break;
            }

            if (i > 10 * conv<long>(order_)) {
                cout << "Iteration limit reached for this run. Restarting...\n\n";
                restart = true;
                break;
            }
        } 

        if (restart) continue;

        // extract collision exponents
        ZZ a1 = slow.a;
        ZZ b1 = slow.b;
        ZZ a2 = fast.a;
        ZZ b2 = fast.b;

        // compute numerator and denominator modulo order
        ZZ num = (a1 - a2) % order_;
        if (num < 0) num += order_;
        ZZ den = (b2 - b1) % order_;
        if (den < 0) den += order_;

        cout << "a1=" << a1 << " b1=" << b1 << " | a2=" << a2 << " b2=" << b2 << "\n";
        cout << "num=" << num << " den=" << den << " (mod " << order_ << ")\n";

        // attempt inverse
        ZZ den_inv;
        if (InvModStatus(den_inv, den, order_) != 0) {
            cout << "No inverse exists for den. Useless collision. Retrying with new seed...\n\n";
            continue; 
        }

        // compute candidate x
        ZZ x = (num * den_inv) % order_;
        if (x < 0) x += order_;

        cout << "Candidate x = " << x << "\n";

        // verify solution
        if (PowerMod(g_, x, p_) == h_) {
            cout << "Verified: g^x mod p == h. Returning x.\n";
            return x;
        } else {
            cout << "Verification failed. Retrying with new seed...\n\n";
            continue;
        }
    } 
}