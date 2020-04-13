#pragma once
#include <memory>


	template <typename T>
	struct Point
	{
        static Point<T> Zero;


		////////////////////////////////////////////////////////////
		T x = { default(T) };
		T y = { default(T) };


		////////////////////////////////////////////////////////////
		Point(const T& value)
			:
			x(value),
			y(value)
		{
		}


		////////////////////////////////////////////////////////////
		Point(const T& X, const T& Y)
			:
			x(X),
			y(Y)
		{
		}

	};
	////////////////////////////////////////////////////////////






	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T> operator -(const Point<T>& right)
	{
		return Point<T>(-right.x, -right.y);
	}
	

	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T>& operator +=(Point<T>& left, const Point<T>& right)
	{
		left.x += right.x;
		left.y += right.y;

		return left;
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T>& operator -=(Point<T>& left, const Point<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;

		return left;
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T> operator +(const Point<T>& left, const Point<T>& right)
	{
		return Point<T>(left.x + right.x, left.y + right.y);
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T> operator -(const Point<T>& left, const Point<T>& right)
	{
		return Point<T>(left.x - right.x, left.y - right.y);
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T> operator *(const Point<T>& left, T right)
	{
		return Point<T>(left.x * right, left.y * right);
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T> operator *(T left, const Point<T>& right)
	{
		return Point<T>(right.x * left, right.y * left);
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T>& operator *=(Point<T>& left, T right)
	{
		left.x *= right;
		left.y *= right;

		return left;
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T> operator /(const Point<T>& left, T right)
	{
		return Point<T>(left.x / right, left.y / right);
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline Point<T>& operator /=(Point<T>& left, T right)
	{
		left.x /= right;
		left.y /= right;

		return left;
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline bool operator ==(const Point<T>& left, const Point<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}


	////////////////////////////////////////////////////////////
	template <typename T>
	inline bool operator !=(const Point<T>& left, const Point<T>& right)
	{
		return (left.x != right.x) || (left.y != right.y);
	}




using TPoint	= Point<int>;
using TPointF	= Point<float>;


/*
constexpr TPoint::Zero = TPoint(0,0);
constexpr TPointF::Zero = TPointF(0,0);
*/