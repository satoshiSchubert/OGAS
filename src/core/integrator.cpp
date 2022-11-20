#include "integrator.h"

using namespace OGAS;

void SamplerIntegrator::Render(std::shared_ptr<OGAS::Scene> scene) {
    // main process
    for (int y = 0; y < scene->camera->getHeight(); y++) {
        // std::future<Eigen::Vector3f> futures[camera_.width()][spp];
        for (int x = 0; x < scene->camera->getWidth(); x++) {
            for (int k = 0; k < scene->spp; k++) {
                // TODO: 这边应该是sampleray吧？
                Ray ray = scene->camera->generateRay(x, y, false);
                Isect isect;
                
                scene->film->fragment_buffer_[scene->camera->getIndex(x, y)] += scene->integrator->Li(ray, scene);
                

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
        //global::UpdateProgress(float(y) / camera_->height());
    }
    //global::UpdateProgress(1.f);

    for (auto& pixel : scene->film->fragment_buffer_) {
        pixel /= float(scene->spp);
    }



}