#include "parser.h"

void Parser::parse(std::string filename, std::shared_ptr<Scene> scene)
{
    Timer timer;
    INIReader reader("filename");
    if (reader.ParseError() != 0) {
        std::cout << "Can't load scene.ini\n";
        assert(false);
    }
    else {
        timer.StartTimer("Loading scene.ini");
    }

    std::string model_path = reader.Get("model", "model_path", "scene") + "/";
    std::string model_name = reader.Get("model", "model_name", "bedroom");

    int spp = int(reader.GetInteger("rendering", "spp", 1));

    bool antialiasing = reader.GetBoolean("rendering", "antialiasing", false);
    if (spp == 1) {
        antialiasing = false;
    }
    bool use_bvh = reader.GetBoolean("rendering", "use_bvh", true);

    std::string shading_type_name = reader.Get("rendering", "shading_type", "depth");

    std::string integrator_name = reader.Get("rendering", "integrator", "xxx");
    // 写个映射函数映射一下
    scene->IntegratorType = Default; // 后续integrator初始化时读取scene中的信息选择type


    //Scene::ShadingType shading_type = Scene::kDepth;
    //if (shading_type_name == "uv") {
    //    shading_type = Scene::kUv;
    //}
    //else if (shading_type_name == "albedo") {
    //    shading_type = Scene::kAlbedo;
    //}
    //else if (shading_type_name == "normal") {
    //    shading_type = Scene::kNormal;
    //}
    //else if (shading_type_name == "position") {
    //    shading_type = Scene::kPosition;
    //}
    //else if (shading_type_name == "depth") {
    //    shading_type = Scene::kDepth;
    //}
    //else if (shading_type_name == "light") {
    //    shading_type = Scene::kSampleLight;
    //}
    //else if (shading_type_name == "bsdf") {
    //    shading_type = Scene::kSampleBsdf;
    //}
    //else if (shading_type_name == "mis") {
    //    shading_type = Scene::kMis;
    //}
    timer.StopTimer("scene.ini loaded");

    timer.StartTimer("\nLoading scene");
}