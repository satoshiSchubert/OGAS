#include "../core/camera.h"

// pinhole
class ProjectCamera : public Camera {

public:
    ProjectCamera(glm::vec3& camPos, const glm::vec3& lookAt, const glm::vec3& up,
        float fov_y, int width, int height);

    ~ProjectCamera() override = default;

    Ray GenerateRay(int x, int y, bool AA) const override;

};




