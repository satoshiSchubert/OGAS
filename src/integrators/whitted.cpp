#include "whitted.h"

using namespace OGAS;

glm::vec3 Li(const Ray& ray, const std::shared_ptr<OGAS::Scene> scene, std::shared_ptr<OGAS::Sampler> sampler, int depth) {

	glm::vec3 radiance;

	Isect isect;

	if (scene->accel->intersect(ray, isect)) {

	}

	return radiance;

}




