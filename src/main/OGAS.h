#pragma once
#include "parser.h"


namespace OGAS {

	namespace SingleImpl {
		/*!
		* Simgle machine implementaion of OGAS
		*/
		void Impl(std::shared_ptr<OGAS::Scene> scene) {
			// do something
			scene->integrator->Render(scene);
		}


	}

}





