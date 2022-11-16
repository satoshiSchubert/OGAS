#pragma once
#include "commons/RTCommon.h"

namespace OGAS {
	class Camera {
	public:

		Camera(glm::vec3& camPos, const glm::vec3& lookAt, const glm::vec3& up,
			float fov_y, int width, int height) :
			camPos_(camPos), lookAt_(lookAt), up_(up), fov_y_(fov_y), width_(width), height_(height) {
			aspect_ = static_cast<float>(width) / static_cast<float>(height);
			camDir_ = glm::normalize(lookAt_ - camPos);
			right_ = glm::normalize(glm::cross(camDir_, up_));
			up_ = glm::normalize(glm::cross(right_, camDir_));
		}

		virtual ~Camera();
		
		//! \param x: x,
		//! \param y: y,
		//! \param AA: antialiasing
		//! \return generated camera ray.
		virtual Ray generateRay(int x, int y, bool AA) const = 0;

		auto getHeight() { return height_; }

		auto getWidth() { return width_; }

		// get pixel index. x:width, y:height
		auto getIndex(int x, int y) {
			assert(x >= 0 && x < width_);
			assert(y >= 0 && y < height_);
			return x + width_ * (height_ - y - 1);//TODO:这里是因为考虑openGL的xy格式吗
		}




	public:
		int height_, width_;
		float fov_y_;
		float aspect_;
		glm::vec3 camPos_, camDir_, lookAt_, up_, right_;

	};
}
