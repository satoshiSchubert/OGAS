#include "integrator.h"

class SamplerIntegrator : public OGAS::Integrator {
public:

	SamplerIntegrator(std::shared_ptr<OGAS::Sampler> sampler,
		std::shared_ptr<const OGAS::Camera> camera, int maxDepth)
		:camera(camera), sampler(sampler), maxDepth(maxDepth) {}

	void Render(const OGAS::Scene& scene);

private:
	std::shared_ptr<OGAS::Sampler> sampler;
	std::shared_ptr<const OGAS::Camera> camera;
	const int maxDepth;
};
