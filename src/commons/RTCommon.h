#pragma once
#include <math.h>
#include <memory>
#include <vector>
#include <assert.h>

#include "glm/glm.hpp"



namespace OGAS {

	const float PI = M_PI;
	const float InvPI = M_1_PI;
	const float EPSILON = std::numeric_limits<float>::epsilon();
	const float INF = std::numeric_limits<float>::infinity();

	const glm::vec3 C_BLACK = glm::vec3(0.0, 0.0, 0.0);
	const glm::vec3 C_WHITE = glm::vec3(1.0, 1.0, 1.0);


	struct Film {
	public:
		Film() {}

		~Film() {
			//Clean up
		}
	public:
		std::vector<glm::vec3> fragment_buffer_;
	};


	struct Isect {
	public:
		Isect() {}

		~Isect() {}

	private:

		glm::vec3 pos;

	};


	struct Ray {
		glm::vec3 origin;
		glm::vec3 direction;
		float t_min;
		float t_max;
		float pdf;
		Ray(glm::vec3 origin, glm::vec3 direction):origin(origin),direction(direction) {
			t_min = EPSILON;
			t_max = INF;
		}
		auto getPos(float t) const { return origin + t * direction; }
		// same func as getPos()
		auto operator()(float t)const { return origin + t * direction; }
		bool Update(float t) {
			if (t > t_min && t < t_max) {
				t_max = t;
				return true;
			}
			return false;
		}
	};
	
	

	

}


