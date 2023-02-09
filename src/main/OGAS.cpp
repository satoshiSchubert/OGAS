#include "OGAS.h"

// 0210:Scene的构建，并由此穿出bvh等的构建

std::string filename = "scene.ini";

int main() {
	std::shared_ptr<OGAS::Scene> scene;
	Parser parser;
	parser.parse(filename, scene);
	OGAS::SingleImpl::Impl(scene);
	printf("sim done\n");
	//LS::GLWindow glWindow;
	//glWindow.init(innerParser.parseSceneFromRTParaList(sceneParaList), &result);

	//glWindow.run();

}