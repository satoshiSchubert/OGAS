#pragma once
#include <corecrt_math_defines.h>
#include <memory>
#include <vector>
#include <assert.h>
#include <chrono>
#include <iostream>
#include "../ext/glm/glm/glm.hpp"
#include "../core/material.h"




const float PI = M_PI;
const float InvPI = M_1_PI;
const float EPSILON = std::numeric_limits<float>::epsilon();
const float INF = std::numeric_limits<float>::infinity();

const glm::vec3 C_BLACK = glm::vec3(0.0, 0.0, 0.0);
const glm::vec3 C_WHITE = glm::vec3(1.0, 1.0, 1.0);

// utils func
namespace utils {

	float toRadius(float alpha) {
		return alpha / 180.f * M_PI;
	}

	float toDegree(float alpha) {
		return alpha * 180.f * InvPI;
	}


}

struct Timer {
public:
	Timer() {
		start_ = std::chrono::system_clock::now();
		end_ = std::chrono::system_clock::now();
	}

	~Timer() = default;

	void StartTimer(const std::string& start_msg) {
		std::cout << start_msg << "..." << std::endl;
		start_ = std::chrono::system_clock::now();
	}

	void StopTimer(const std::string& stop_msg) {
		end_ = std::chrono::system_clock::now();
		std::cout << stop_msg << ", " << GetTime() << " seconds used." << std::endl;
	}

	float GetTime() {
		return float(std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count()) / 1000.f;
	}

private:
	std::chrono::time_point<std::chrono::system_clock> start_, end_;

};

struct Film {
public:
	Film() {}

	~Film() {
		//Clean up
	}
public:
	std::vector<glm::vec3> fragment_buffer_;
};


struct Isect {
public:
	Isect() {}

	~Isect() {}

public:

	glm::vec3 pos;
	Material material;

};


struct Ray {
	glm::vec3 origin;
	glm::vec3 direction;
	float t_min;
	float t_max;
	float pdf;
	Ray(glm::vec3 origin, glm::vec3 direction):origin(origin),direction(direction) {
		t_min = EPSILON;
		t_max = INF;
	}
	auto getPos(float t) const { return origin + t * direction; }
	// same func as getPos()
	auto operator()(float t)const { return origin + t * direction; }
	bool Update(float t) {
		if (t > t_min && t < t_max) {
			t_max = t;
			return true;
		}
		return false;
	}
};
	
	



