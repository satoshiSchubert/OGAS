#include "OGAS.h"

std::string filename;

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