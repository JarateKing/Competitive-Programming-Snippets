#include <string>
#include <cmath> // max
#define ull unsigned long long

// O(m*n) - "banana", "ban" >> 3 (ban, ba..n, b..an)
int subsequences(string body, string subsequence) {
	int m = subsequence.length(), n = body.length();
	if (m > n)
		return 0;
	
	ull** arr = new ull*[m+1];
	for (int i = 0; i <= m; i++)
		arr[i] = new ull[n+1];
	
	for (int i = 1; i <= m; i++)
		arr[i][0] = 0;
	for (int i = 0; i <= n; i++)
		arr[0][i] = 1;
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (body[j-1] != subsequence[i-1])
				arr[i][j] = arr[i][j-1];
			else
				arr[i][j] = arr[i][j-1] + arr[i-1][j-1];
		}
	}
	
	ull value = arr[m][n];
	
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	
	return value;
}

string lcs(string a, string b) {
	int m = a.length();
	int n = b.length();
	
	// build matrix / L[m][n] contains length of lcs
	int L[m+1][n+1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) L[i][j] = 0;
			else if (a[i-1] == b[j-1]) L[i][j] = L[i-1][j-1]+1;
			else L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	
	// obtain string
	string out = "";
	int i = m - 1, j = n - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] == b[j]) {
			out = a[i--] + out;
			j--;
		}
		else if (L[i][j+1] > L[i+1][j]) i--;
		else j--;
	}
	
	return out;
}