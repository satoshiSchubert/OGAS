#include "commons/RTCommon.h"
#include "primitives.h"
#include "light.h"
#include "spectrum.h"
#include "material.h"
#include "integrator.h"
#include "sampler.h"
#include "camera.h"
#include "accelerator.h"

namespace OGAS {

	class Scene {
	public:
		Scene() {}

		void Construct() {}

		~Scene() {
			//Clean up
		}
	public:
		std::shared_ptr<Primitive> primitive;
		std::shared_ptr<Light> light;
		std::shared_ptr<Material> mat;
		// ÓÃ integrator = std::make_shared<SamplerIntegrator>()ÊµÀý»¯
		std::shared_ptr<Integrator> integrator;
		std::shared_ptr<Film> film;
		std::shared_ptr<Camera> camera;
		std::shared_ptr<Accel> accel;

		int spp;

	};





}
