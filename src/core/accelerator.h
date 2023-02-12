#pragma once
#include "../commons/RTCommon.h"


class Accel {
public:
	virtual ~Accel();

	virtual bool intersect(const Ray& ray, Isect& isect, float* t = nullptr) const = 0;

};
