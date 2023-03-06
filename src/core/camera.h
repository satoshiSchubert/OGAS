#pragma once
#include "../samplers/RandomSampler.h"


class Camera {
public:

	Camera(glm::vec3& camPos, const glm::vec3& lookAt, const glm::vec3& up,
		float fov_y, int width, int height);

	virtual ~Camera();
		
	//! \param x: x,
	//! \param y: y,
	//! \param AA: antialiasing
	//! \return generated camera ray.
	virtual Ray GenerateRay(int x, int y, bool AA) const = 0;

	auto getHeight() -> int { return height_; }

	auto getWidth() -> int { return width_; }

	// get pixel index. x:width, y:height
	auto getIndex(int x, int y) -> int;

	glm::dvec2 SampleFilm(int x, int y, bool AA) const;

public:
	int height_, width_;
	float fov_y_;
	float aspect_; // width / height
	glm::vec3 camPos_, camDir_, lookAt_, up_, right_;

};

