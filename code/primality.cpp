#define ull unsigned long long

// requires modular math for mult and mpow
bool isPrime(ull n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	ull s = n - 1;
	while (s % 2 == 0) s /= 2;

	for (int i = 0; i < 10; i++) {
		ull temp = s;
		ull a = rand() % (n - 1) + 1;
		ull mod = mpow(a, temp, n);
		while (temp != n - 1 && mod != 1 && mod != n - 1) {
			mod = mult(mod, mod, n);
			temp *= 2;
		}
		if (mod != n - 1 && temp % 2 == 0) return false;
	}
	return true;
}

// useful for constant time lookups / summing
// call genSieve once, and querySieve the rest
bitset<100000001> sieve;
void genSieve(int n) {
	sieve[0] = sieve[1] = 1;
	for (ull i = 3; i * i < n; i += 2)
		if (!sieve[i])
			for (ull j = i * 3; j <= n; j += i * 2)
				sieve[j] = 1;
}
bool querySieve(int n) {
	return n == 2 || (n % 2 != 0 && !sieve[n]);
}
