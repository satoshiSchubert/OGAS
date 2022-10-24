#pragma once
#include <math.h>
#include <memory>

#include "primitives.h"
#include "light.h"
#include "spectrum.h"
#include "material.h"
#include "integrator.h"
#include "sampler.h"
#include "camera.h"

namespace OGAS {
	class Scene {
	public:
		Scene() {}

		void Construct() {}

		~Scene() {
			//Clean up
		}
	public:
		Primitive primitive;
		Light light;
		Material mat;
		// ÓÃ integrator = std::make_shared<SamplerIntegrator>()ÊµÀý»¯
		std::shared_ptr<Integrator> integrator;
	};
}
