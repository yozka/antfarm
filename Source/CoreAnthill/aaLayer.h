#pragma once
#include <memory>
#include <vector>

#include "aaPoint.h"

namespace Anthill
{


	
	template <class T>
	class ALayer
	{
	public:

		ALayer(const TPoint &size)
			:
			mSize(size)
		{
			mData.resize(size.x * size.y);
		}

		virtual ~ALayer()
		{

		}


	public:


		int width()		const { return mSize.x; };
		int height()	const { return mSize.y; };

		const T& data(const int x, const int y) const
		{
			return mData[x + y * mSize.x];
		};


		T& data(const int x, const int y)
		{
			return mData[x + y * mSize.x];
		}


		T& operator ()(const int x, const int y)
		{
			return mData[x + y * mSize.x];
		}

        const T& operator ()(const int x, const int y) const
        {
            return mData[x + y * mSize.x];
        }


		const T& data(const TPoint &pt) const
		{
			return mData[pt.x + pt.y * mSize.x];
		};


		T& data(const TPoint &pt)
		{
			return mData[pt.x + pt.y * mSize.x];
		}


		T& operator ()(const TPoint &pt)
		{
			return mData[pt.x + pt.y * mSize.x];
		}

        const T& operator ()(const TPoint &pt) const
        {
            return mData[pt.x + pt.y * mSize.x];
        }


	private:


		const TPoint mSize;

		std::vector<T> mData;

	};



}
