#pragma once
#include <memory>


namespace Formicarium
{


	class AInsect
	{
	public:

		AInsect();
		virtual ~AInsect();


	public:


		float width() const { return mWidth; }
		float height() const { return mHeight; }

		float positionX() const { return mPositionX; }
		float positionY() const { return mPositionY; }

		float angle()const { return mAngle; }

		void setPosition(const float x, const float y);

	private:

		float mWidth		= { 1.0f };
		float mHeight		= { 1.0f };

		float mPositionX	= { 0.0f };
		float mPositionY	= { 0.0f };

		float mAngle		= { 0.0f };

	};


	using PInsect = std::shared_ptr<AInsect>;


}
