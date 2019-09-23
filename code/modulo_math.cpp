#include <algorith> // __gcd
#define ll long long

#define MOD 1000000007
#define madd(a,b,m) (((a%m)+(b%m))%m)
#define mult(a,b,m) (((a%m)*(b%m))%m)
#define msub(a,b,m) (((a%m)-(b%m)+m)%m)

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
