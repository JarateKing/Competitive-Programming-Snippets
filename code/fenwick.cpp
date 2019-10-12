#define ll long long

struct Fenwick {
	int n;
	ll* tree;
	
	update(int i, int val) {
		++i;
		while (i <= n) {
			tree[i] += val;
			i += i & (-i);
		}
	}
	
	Fenwick(int* arr, int size) {
		n = size;
		tree = new ll[n+1];
		for (int i = 1; i <= n; i++)
			tree[i] = 0;
		
		for (int i = 0; i < n; i++)
			update(i, arr[i]);
	}
	
	~Fenwick() {
		delete[] tree;
	}
	
	ll operator[](int i) {
		if (i < 0 || i > n) return 0;
		ll sum = 0;
		++i;
		while (i>0) {
			sum += tree[i];
			i -= i & (-i);
		}
		return sum;
	}
	
	ll getRange(int a, int b) {
		return operator[](b) - operator[](a-1);
	}
};