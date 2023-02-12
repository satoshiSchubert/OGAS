#pragma once
#include "../commons/RTCommon.h"
#include "primitives.h"
#include "light.h"
#include "spectrum.h"
#include "material.h"
#include "integrator.h"
#include "sampler.h"
#include "camera.h"
#include "accelerator.h"
#include "../accelerators/BVH.h"


class Scene {
public:
	Scene() {
	}

	void Construct() {}

	~Scene() {
		//Clean up
	}
public:

	// 下面的对象都是基类就已经定义完全的
	Primitive primitive;
	std::vector<Light> lights;
	Material material;
	Film film;	

	// 下面的基类没有定义完全，有纯虚拟函数，因此需要用指针，初始化时要选择一个确定的子类
	//std::shared_ptr<Integrator> integrator = std::make_shared<SamplerIntegrator>();
	EIntegratorType IntegratorType = Default;
	std::shared_ptr<Camera> camera = nullptr;
	std::shared_ptr<Accel> accel = nullptr;

	int spp;

};
