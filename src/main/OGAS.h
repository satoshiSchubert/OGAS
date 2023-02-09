#pragma once
#include "../core/parser.h"
#include "../core/scene.h"
#include <string>
#include <memory>


namespace OGAS {

	namespace SingleImpl {
		/*!
		* Simgle thread implementaion of OGAS
		*/
		void Impl(std::shared_ptr<OGAS::Scene> scene) {
			// do something
			scene->integrator->Render(scene);
		}


	}

}





