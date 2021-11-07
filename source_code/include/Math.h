#pragma once
#ifndef MATH_CODE
#define MATH_CODE

long long gcd(long long a, long long b);
bool isPrime(int x);
long long invMod(long long a, long long m);
long long ExpMod(long long a, long long n, long long m);
void yeildPrime(long long &p, long long &q);
long long yeildE(long long EulerN);
long long getD(long long e, long long mod);
long long enCode(long long M, long long e, long long mod);
long long deCode(long long C, long long d, long long mod);

#endif // !MATH_CODE
