#pragma once
#include <memory>


template <typename T>
struct TTPoint
{
	T x = { default(T) };
	T y = { default(T) };

	TTPoint(const T& value)
		:
		x(value),
		y(value)
	{
	}

	TTPoint(const T& valueX, const T& valueY)
		:
		x(valueX),
		y(valueY)
	{
	}


	TTPoint operator * (const T& value)
	{
		x = x * value;
		y = y * value;
		return *this;
	}


};


using TPoint	= TTPoint<int>;
using TPointF	= TTPoint<float>;
