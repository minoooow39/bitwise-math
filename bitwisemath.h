#pragma once

int add(int x, int y)
{
	unsigned carry{};
	while (y != 0)
	{
		carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
	return x;
}

int substract(int x, int y)
{
	unsigned borrow{};
	while (y != 0)
	{
		borrow = (~x) & y;
		x = x ^ y;
		y = borrow << 1;
	}
	return x;
}

int multiply(int x, int y)
{
	int result{};
	while (y != 0)
	{
		if (y & 1)
			result += x;
		x <<= 1;
		y >>= 1;
	}
	return result;
}

int divide(int x, int y)
{
	int result{};
	int shift = (sizeof(int) * 8) - 1;

	while (shift >= 0)
	{
		if ((x >> shift) >= y)
		{
			x = substract(x, y << shift);
			result |= 1 << shift;
		}
		--shift;
	}

	return result;
}

long long power(long long x, long long y)
{
	long long result{ 1 };
	while (y > 0)
	{
		if (y & 1)
			result = multiply(result, x);
		x = multiply(x, x);
		y >>= 1;
	}
	return result;
}

int negate(int x)
{
	return add(~x, 1);
}
