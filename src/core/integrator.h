#pragma once
#include "commons/RTCommon.h"

namespace OGAS {
	class Integrator {
	public:
		// Integrator Interface
		virtual ~Integrator();
		virtual void Render(const Scene &scene) = 0;
	};
}
