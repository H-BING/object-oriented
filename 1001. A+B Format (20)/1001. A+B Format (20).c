#include<stdio.h>
int main() {
	int a, b;
	int sum = 0;
	int y, z;
	scanf_s ("%d%d", &a, &b);
	sum = a + b;
	if (sum < 0) { printf("-"); sum = -sum; }
	
	z = sum % 1000; sum /= 1000;
	if (sum == 0) printf("%d\n", z);
	else {
		y = sum % 1000; sum /= 1000;
		if (sum == 0) printf("%d,%03d\n", y, z);
		else printf("%d,%03d,%03d\n", sum, y, z);
	}
	
	return 0;
}
