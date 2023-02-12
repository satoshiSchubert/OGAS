#include "whitted.h"



glm::vec3 Li(const Ray& ray, const std::shared_ptr<Scene> scene, std::shared_ptr<Sampler> sampler, int depth) {

	glm::vec3 radiance = C_BLACK;
	int MAXDEPTH = 10; // ÔÝ¶¨
	Isect isect;

	if (scene->accel->intersect(ray, isect)) {

		// DO SHADING HERE
		if (isect.mat->hasEmitter() && depth == 0) {
			return radiance;
		}

		if (depth >= MAXDEPTH) {
			return radiance;
		}

		//for (const auto& light : scene->lights) {
		//	glm::vec3 wi;
		//	float pdf;
		//	VisibilityTester visibility;
		//	Spectrum Li =
		//		light->Sample_Li(isect, sampler.Get2D(), &wi, &pdf, &visibility);
		//	if (Li.IsBlack() || pdf == 0) continue;
		//	Spectrum f = isect.bsdf->f(wo, wi);
		//	if (!f.IsBlack() && visibility.Unoccluded(scene))
		//		L += f * Li * AbsDot(wi, n) / pdf;
		//}
		//if (depth + 1 < maxDepth) {
		//	// Trace rays for specular reflection and refraction
		//	L += SpecularReflect(ray, isect, scene, sampler, arena, depth);
		//	L += SpecularTransmit(ray, isect, scene, sampler, arena, depth);
		//}

		return radiance;
	}

	// ²ÉÑù±³¾°
	// radiance = skybox£¿skybox->sample();
	return radiance;

}




