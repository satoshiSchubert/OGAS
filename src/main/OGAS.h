#pragma once
#include "commons/RTCommon.h"
#include "parser.h"

namespace OGAS {

	namespace SingleImpl {
		/*!
		* Simgle machine implementaion of OGAS
		*/
		void Impl(Scene& scene) {
			// do something
			scene.integrator->Render(scene);
		}


	}

}





