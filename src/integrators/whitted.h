#pragma once
#include "../commons/RTCommon.h"
#include "../core/integrator.h"



class WhittedIntegrator : public Integrator {
public:

	WhittedIntegrator(std::shared_ptr<Sampler> sampler,
		std::shared_ptr<const Camera> camera, int maxDepth)
		:camera(camera), sampler(sampler), maxDepth(maxDepth) {}

	virtual void Render(const std::shared_ptr<Scene> scene) {}

	virtual glm::vec3 Li(const Ray& ray, const std::shared_ptr<Scene> scene,
		std::shared_ptr<Sampler> sampler, int depth) const {
		return glm::vec3(0.0);
	}

private:
	std::shared_ptr<Sampler> sampler;
	std::shared_ptr<const Camera> camera;
	const int maxDepth;
};
