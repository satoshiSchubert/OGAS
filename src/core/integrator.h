#pragma once
#include "../commons/RTCommon.h"
#include "scene.h"

class Scene;
class Sampler;
class Camera;

class Integrator {
public:
	// Integrator Interface
	virtual ~Integrator();
	virtual void Render(const std::shared_ptr<Scene> scene) = 0;
	virtual glm::vec3 Li(Ray &ray, std::shared_ptr<Scene> scene) = 0;
};


class SamplerIntegrator : public Integrator {
public:

	SamplerIntegrator(std::shared_ptr<Sampler> sampler,
		std::shared_ptr<const Camera> camera, int maxDepth)
		:camera(camera), sampler(sampler), maxDepth(maxDepth) {}

	virtual void Render(const std::shared_ptr<Scene> scene);
	virtual glm::vec3 Li(Ray& ray, std::shared_ptr<Scene> scene) {
		return glm::vec3(0.0);
	}


private:
	std::shared_ptr<Sampler> sampler;
	std::shared_ptr<const Camera> camera;
	const int maxDepth;
};

