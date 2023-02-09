

#include "ProjectCamera.h"


ProjectCamera::ProjectCamera(glm::vec3& camPos, const glm::vec3& lookAt, const glm::vec3& up,
    float fov_y, int width, int height) : Camera(camPos, lookAt, up, fov_y, width, height) {}

Ray ProjectCamera::GenerateRay(int x, int y, bool antialiasing) const {
    auto uv = SampleFilm(x, y, antialiasing);
    glm::dvec3 dir = float(uv.x) * right_ + float(uv.y) * up_ + lookAt_;
    return { camPos_, glm::normalize(dir)};
}


