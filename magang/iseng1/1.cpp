#include <bits/stdc++.h>

int segitiga(int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int k = 1; k <= i; k++)
			std::cout << "*";

		std::cout << std::endl;
	}
}

int segitiga_kebalik(int n)
{
	for(int i = n; i >= 1; i--)
	{
		for(int k = 1; k <= i; k++)
			std::cout << "*";

		std::cout << std::endl;
	}
}

int sieve(int n)
{
	bool prime[100100];
	std::memset(prime, 1, sizeof(prime));
	prime[0] = 0;
	prime[1] = 0;

	int co = 0;
	for(int i = 2; co <= 20; i++)
	{
		if(prime[i])
			for(int p = 2*i; p < 100100; p += i)
				prime[p] = 0;

		co++;
	}

	int k = 2;
	for(int i = 1; i <= co; k++)
	{
		if(prime[k])
		{
			std::cout << k << " ";
			i++;
		}
	}

	std::cout << std::endl;
}

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	segitiga(a);
	segitiga_kebalik(b);
	sieve(c);

	return 0;
}