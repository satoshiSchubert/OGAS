#include "camera.h"

Camera::Camera(glm::vec3& camPos, const glm::vec3& lookAt, const glm::vec3& up,
	float fov_y, int width, int height) :
	camPos_(camPos), lookAt_(lookAt), up_(up), fov_y_(fov_y), width_(width), height_(height) {
	aspect_ = static_cast<float>(width) / static_cast<float>(height);
	camDir_ = glm::normalize(lookAt_ - camPos);
	right_ = glm::normalize(glm::cross(camDir_, up_));
	up_ = glm::normalize(glm::cross(right_, camDir_));
}

Camera::~Camera()
{
}

auto Camera::getIndex(int x, int y) -> int
{
	assert(x >= 0 && x < width_);
	assert(y >= 0 && y < height_);
	return x + width_ * (height_ - y - 1);//TODO:这里是因为考虑openGL的xy格式吗
}

glm::dvec2 Camera::SampleFilm(int x, int y, bool AA) const
{
	float tangent = std::tan(utils::toRadius(fov_y_) / 2.f);

	float xx = float(x) + 0.5f, yy = float(y) + 0.5f;
	if (AA) {
		xx += RndSampler::NormalRnd();
		yy += RndSampler::NormalRnd();
	}

	float xx_ = tangent * aspect_ * (xx - float(width_) / 2.f) / (float(width_) / 2.f);
	float yy_ = tangent * (yy - float(height_) / 2.f) / (float(height_) / 2.f);

	return glm::dvec2{ xx_, yy_ };
}
