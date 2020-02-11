#pragma once
#include <memory>


template <typename T>
T minmaxBound(const T min, const T max, const T value)
{
	if (value < min)
	{
		return min;
	}
	if (value > max)
	{
		return max;
	}
	return value;
};



