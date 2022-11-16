#pragma once
#include <math.h>
#include <memory>
#include <vector>
#include <assert.h>

#include "primitives.h"
#include "light.h"
#include "spectrum.h"
#include "material.h"
#include "integrator.h"
#include "sampler.h"
#include "camera.h"
#include "glm/glm.hpp"



namespace OGAS {

	const float PI = M_PI;
	const float InvPI = M_1_PI;
	const float EPSILON = std::numeric_limits<float>::epsilon();
	const float INF = std::numeric_limits<float>::infinity();

	const glm::vec3 C_BLACK = glm::vec3(0.0, 0.0, 0.0);
	const glm::vec3 C_WHITE = glm::vec3(1.0, 1.0, 1.0);


	class Film {
	public:
		Film() {}

		~Film() {
			//Clean up
		}
	public:
		std::vector<glm::vec3> fragment_buffer_;
	};

	class Ray {
	public:
		Ray(glm::vec3 origin, glm::vec3 direction):origin_(origin),direction_(direction) {
			t_min_ = EPSILON;
			t_max_ = INF;
		}

		~Ray() = default;

		auto getOri() const { return origin_; }

		auto getDir() const { return direction_; }

		auto getTmin() const { return t_min_; }

		auto getTmax() const { return t_max_; }

		auto getPos(float t) const { return origin_ + t * direction_; }

		// same func as getPos()
		auto operator()(float t)const { return origin_ + t * direction_; }

		bool Update(float t) {
			if (t > t_min_ && t < t_max_) {
				t_max_ = t;
				return true;
			}
			return false;
		}

	private:
		glm::vec3 origin_, direction_;
		float t_min_, t_max_;

	};
	
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
		Film film;
		Camera camera;

		int spp;

	};

	

}


