#define ull unsigned long long

ull mulmod(ull a, ull b, ull m) {
	ull x = 0;
	ull y = a % m;
	while (b > 0) {
		if (b % 2 == 1) x = (x + y) % m;
		y = (y * 2) % m;
		b /= 2;
	}
	return x % m;
}
ull expmod(ull base, ull e, ull m) {
	ull x = 1;
	ull y = base;
	while (e > 0) {
		if (e % 2 == 1) x = (x * y) % m;
		y = (y * y) % m;
		e /= 2;
	}
	return x % m;
}
bool isPrime(ull n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	ull s = n - 1;
	while (s % 2 == 0) s /= 2;

	for (int i = 0; i < 10; i++) {
		ull temp = s;
		ull a = rand() % (n - 1) + 1;
		ull mod = expmod(a, temp, n);
		while (temp != n - 1 && mod != 1 && mod != n - 1) {
			mod = mulmod(mod, mod, n);
			temp *= 2;
		}
		if (mod != n - 1 && temp % 2 == 0) return false;
	}
	return true;
}