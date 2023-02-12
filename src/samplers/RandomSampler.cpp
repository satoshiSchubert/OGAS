#include "RandomSampler.h"


float RndSampler::UniformRnd() {
    return uniform_distribution_(random_engine_);
}

float RndSampler::NormalRnd() {
    return normal_distribution_(random_engine_);
}

glm::dvec2 RndSampler::SampleDisk() {
    return glm::dvec2(0.0);
}






