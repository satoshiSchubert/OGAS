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

	// ����Ķ����ǻ�����Ѿ�������ȫ��
	Primitive primitive;
	std::vector<Light> lights;
	Material material;
	Film film;	

	// ����Ļ���û�ж�����ȫ���д����⺯���������Ҫ��ָ�룬��ʼ��ʱҪѡ��һ��ȷ��������
	//std::shared_ptr<Integrator> integrator = std::make_shared<SamplerIntegrator>();
	EIntegratorType IntegratorType = Default;
	std::shared_ptr<Camera> camera = nullptr;
	std::shared_ptr<Accel> accel = nullptr;

	int spp;

};
