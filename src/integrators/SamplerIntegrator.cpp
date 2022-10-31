#include "SamplerIntegrator.h"

void SamplerIntegrator::Render(const OGAS::Scene& scene) {
	// main process
    for (int y = 0; y < camera_->height(); y++) {
        // std::future<Eigen::Vector3f> futures[camera_.width()][spp];
        for (int x = 0; x < camera_->width(); x++) {
            for (int k = 0; k < spp; k++) {
                Ray ray = camera_->GenerateRay(x, y, antialiasing);
                scene.film.fragment_buffer_[camera_->GetIndex(x, y)] += scene_->Trace(&ray, shading_type);
                // futures[x][k] = pool.enqueue([&]() {
                //     return scene_.Trace(&ray);
                // });
            }
        }
        // for (int x = 0; x < camera_.width(); x++) {
        //     for (int k = 0; k < spp; k++) {
        //         fragment_buffer_[camera_.GetIndex(x, y)] += futures[x][k].get() / spp;
        //     }
        // }
        global::UpdateProgress(float(y) / camera_->height());
    }
    global::UpdateProgress(1.f);

    for (auto& pixel : scene.film.fragment_buffer_) {
        pixel /= float(spp);
    }



}