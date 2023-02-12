#pragma once
#include "../commons/RTCommon.h"


class Material {
public:
	// Integrator Interface
	virtual ~Material();

	bool hasEmitter();
};

