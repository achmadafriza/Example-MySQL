#include <bits/stdc++.h>

int main()
{
	int a[] = {5, 4, 6, 1, 4, 6, 10, 9, 123, 12, 7, 532, 23};

	std::sort(a, a+sizeof(a));
	std::cout << sizeof(a) << std::endl;

	for(int i = 0; i < sizeof(a); i++)
		std::cout << a[i] << " ";

	return 0;
}