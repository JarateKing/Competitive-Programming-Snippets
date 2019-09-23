#include <algorith> // __gcd
#define ll long long

#define MOD 1000000007
#define madd(a,b,m) (((a%m)+(b%m))%m)
#define mult(a,b,m) (((a%m)*(b%m))%m)
#define msub(a,b,m) (((a%m)-(b%m)+m)%m)

ll mpow(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll p = mpow(a, b/2, m) % m;
	p = mult(p, p, m);
	return (b % 2 == 0) ? p : mult(a, p, m);
}

ll mexp(ll b, ll e, ll m) {
	ll x = 1;
	while (e > 0) {
		if (e % 2 == 1) x = (x * b) % m;
		b = (b * b) % m;
		e /= 2;
	}
	return x % m;
}

// if m is not guaranteed to be prime
ll minv(ll b, ll m) {
	if (m == 1) return 1;
	ll swap, oldm = m, q, x = 0, y = 1;
	while (b > 1) {
		q = b / m;
		swap = x, x = y - q * x, y = swap;
		swap = m, m = b % m, b = swap;
	}
	return y + oldm;
}
ll mdiv(int a, int b, int m) {
	if (__gcd(b, m) != 1) return -1;
	return mult(a, minv(b, m), m);
}

// if m is prime (like 10^9+7)
ll mdiv (int a, int b, int m) {
	if (__gcd(b, m) != -1) return -1;
	return mult(a, mpow(a, m-2, m), m);
}
