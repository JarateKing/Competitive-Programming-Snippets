#define ll long long
#define ull unsigned long long
#define u128 unsigned __int128

string u128tos(u128 n) {
    if (n == 0) return "0";
    string v = "";
    while (n > 0) {
        v = (char)(n % 10 + '0') + v;
        n /= 10;
    }
    return v;
}

typedef pair<int, int> ii;
