#pragma once
#include <corecrt_math_defines.h>
#include <memory>
#include <vector>
#include <assert.h>
#include <chrono>
#include <iostream>
#include <string>
#include "../ext/glm/glm/glm.hpp"
#include "../core/material.h"


class Material;

const float PI = M_PI;
const float InvPI = M_1_PI;
const float EPSILON = std::numeric_limits<float>::epsilon();
const float INF = std::numeric_limits<float>::infinity();

const glm::vec3 C_BLACK = glm::vec3(0.0, 0.0, 0.0);
const glm::vec3 C_WHITE = glm::vec3(1.0, 1.0, 1.0);

// utils func
namespace utils {

	float toRadius(float alpha);

	float toDegree(float alpha);
}

enum EIntegratorType {
	Default,
	SamplerIntegrator,
	WhittedIntegrator,
};


struct Timer {
public:
	Timer();


	void StartTimer(const std::string& start_msg);

	void StopTimer(const std::string& stop_msg);

	float GetTime();

private:
	std::chrono::time_point<std::chrono::system_clock> start_, end_;

};

struct Film {
public:
	Film();

public:
	std::vector<glm::vec3> fragment_buffer_;
};


struct Isect {
public:
	Isect();


public:

	glm::vec3 pos;
	std::shared_ptr<Material> mat = nullptr;
};


struct Ray {
	glm::vec3 origin;
	glm::vec3 direction;
	float t_min;
	float t_max;
	float pdf;
	Ray(glm::vec3 origin, glm::vec3 direction);
	auto getPos(float t) const;
	// same func as getPos()
	auto operator()(float t)const;
	bool Update(float t);
};
	
	



