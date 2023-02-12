
#include "../commons/RTCommon.h"
#include <random>


namespace RndSampler {
    namespace {
        std::random_device rd_;
        std::default_random_engine random_engine_(rd_());
        std::uniform_real_distribution<float> uniform_distribution_(0.f, 1.f);
        std::normal_distribution<float> normal_distribution_(0.f, 0.5f);
    }

    float UniformRnd();

    float NormalRnd();

    glm::dvec2 SampleDisk();

}







