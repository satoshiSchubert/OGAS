#include "integrator.h"
#include "commons/RTCommon.h"



class WhittedIntegrator : public OGAS::SamplerIntegrator {
public:

	WhittedIntegrator(std::shared_ptr<OGAS::Sampler> sampler,
		std::shared_ptr<const OGAS::Camera> camera, int maxDepth)
		:camera(camera), sampler(sampler), maxDepth(maxDepth) {}

	glm::vec3 Li(const Ray& ray, const std::shared_ptr<OGAS::Scene> scene,
		std::shared_ptr<OGAS::Sampler> sampler, int depth) const;

private:
	std::shared_ptr<OGAS::Sampler> sampler;
	std::shared_ptr<const OGAS::Camera> camera;
	const int maxDepth;
};
