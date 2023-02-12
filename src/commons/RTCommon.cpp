#include "RTCommon.h"

// utils func

float utils::toRadius(float alpha) {
	return alpha / 180.f * M_PI;
}

float utils::toDegree(float alpha) {
	return alpha * 180.f * InvPI;
}





Timer::Timer() {
	start_ = std::chrono::system_clock::now();
	end_ = std::chrono::system_clock::now();
}

~Timer::Timer() {};

void Timer::StartTimer(const std::string& start_msg) {
	std::cout << start_msg << "..." << std::endl;
	start_ = std::chrono::system_clock::now();
}

void Timer::StopTimer(const std::string& stop_msg) {
	end_ = std::chrono::system_clock::now();
	std::cout << stop_msg << ", " << GetTime() << " seconds used." << std::endl;
}

float Timer::GetTime() {
	return float(std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count()) / 1000.f;
}





Film::Film() {}

// clean up
~Film::Film() {}




Isect::Isect() {}

~Isect::Isect() {}




Ray::Ray(glm::vec3 origin, glm::vec3 direction):origin(origin),direction(direction) {
	t_min = EPSILON;
	t_max = INF;
}
auto Ray::getPos(float t) const { return origin + t * direction; }
// same func as getPos()
auto Ray::operator()(float t) const { return origin + t * direction; }
bool Ray::Update(float t) {
	if (t > t_min && t < t_max) {
		t_max = t;
		return true;
	}
	return false;
}

	
	



