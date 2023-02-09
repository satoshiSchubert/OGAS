#pragma once
#include "../commons/RTCommon.h"
#include "scene.h"

class Scene;

namespace OGAS {
	class Integrator {
	public:
		// Integrator Interface
		virtual ~Integrator();
		virtual void Render(const std::shared_ptr<OGAS::Scene> scene) = 0;
		virtual glm::vec3 Li(Ray &ray, std::shared_ptr<OGAS::Scene> scene) = 0;
	};


	class SamplerIntegrator : public OGAS::Integrator {
	public:

		SamplerIntegrator(std::shared_ptr<OGAS::Sampler> sampler,
			std::shared_ptr<const OGAS::Camera> camera, int maxDepth)
			:camera(camera), sampler(sampler), maxDepth(maxDepth) {}

		void Render(const std::shared_ptr<OGAS::Scene> scene);

	private:
		std::shared_ptr<OGAS::Sampler> sampler;
		std::shared_ptr<const OGAS::Camera> camera;
		const int maxDepth;
	};

}
