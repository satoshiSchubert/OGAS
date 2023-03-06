#pragma once
#include <iostream>
#include <fstream>
#include "../commons/RTCommon.h"
#include "../cameras/ProjectCamera.h"
#include "../ext/inih/INIReader.h"
#include "scene.h"



class Parser {
public:
	Parser() {}

	/*!
	*
	*/
	void parse(std::string filename, std::shared_ptr<Scene> scene);

	~Parser() = default;

private:

};

