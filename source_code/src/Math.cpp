#include<iostream>
#include<cstdio>
#include<time.h>
#include<algorithm>
typedef long long ll;
using namespace std;
long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	else return gcd(b, a % b);
}
bool isPrime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}
long long exGcd(long long a, long long b, long long &x, long long&y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	long long d = exGcd(b, a % b, x, y);
	long long temp = x;
	x = y, y = temp - (a / b) * y;
	return d;
}
long long invMod(long long a, long long m) {
	long long x, y;
	exGcd(a, m, x, y);
	return (x % m + m) % m;
}
long long ExpMod(long long a, long long n, long long m) {
	long long res = 1;
	while (n) {
		if (n & 1) res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}
void yeildPrime(long long &p,long long &q) {
	p = 0, q = 0;
	srand((unsigned)time(NULL));
	int cnt = rand()%100000;
	for (int i = 2; cnt; i++) {
		if (isPrime(i)) cnt--,p=i;
	}
	do {
		cnt = rand();
		for (int i = 2; cnt; i++) {
			if (isPrime(i)) cnt--, q = i;
		}
	} while (p == q);
}
long long yeildE(long long EulerN) {
	srand((unsigned)time(NULL));
	long long cnt = rand()%min(1000LL,EulerN),e=0;
	for (long long i = 2; cnt&&i<EulerN; i++) {
		if (gcd(i, EulerN) == 1) cnt--, e = i;
	}
	return e;
}
long long getD(long long e, long long mod) {
	return invMod(e, mod);
}
long long enCode(long long M, long long e, long long mod) {
	return ExpMod(M, e, mod);
}
long long deCode(long long C, long long d, long long mod) {
	return ExpMod(C, d, mod);
}