cmake_minimum_required(VERSION 3.16)
project(OGAS)

set(CMAKE_CXX_STANDARD 20)

# 查找必备的包
# find_package(OpenMP REQUIRED)

# 添加包里的代码
#add_library(tiny_obj_loader_lib third_party/tinyobjloader/tiny_obj_loader.cc)
#add_library(tiny_xml_lib third_party/tinyxml2/tinyxml2.cpp)

file(GLOB_RECURSE SRC src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(OGAS ${SRC})

# target_include_directories(path_tracer PUBLIC third_party)
# target_link_libraries(path_tracer Eigen3::Eigen OpenMP::OpenMP_CXX tiny_obj_loader_lib tiny_xml_lib tiny_exr_lib stb_lib)





#[[
FILE ( GLOB OGAS_SOURCE
  src/accelerators/*
  src/bxdfs/*
  src/cameras/*
  src/commons/*
  src/core/*
  src/ext/*
  src/filters/*
  src/integrators/*
  src/lights/*
  src/materials/*
  src/primitives/*
  src/samplers/*
  src/textures/*
  )

INCLUDE_DIRECTORIES ( src )
INCLUDE_DIRECTORIES ( src/core )
INCLUDE_DIRECTORIES ( src/ext/glm/ )

# Visual Studio source folders
SOURCE_GROUP (accelerators REGULAR_EXPRESSION src/accelerators/.*)
SOURCE_GROUP (bxdfs REGULAR_EXPRESSION src/bxdfs/.*)
SOURCE_GROUP (cameras REGULAR_EXPRESSION src/cameras/.*)
SOURCE_GROUP (commons REGULAR_EXPRESSION src/commons/.*)
SOURCE_GROUP (core REGULAR_EXPRESSION src/core/.*)
SOURCE_GROUP (ext REGULAR_EXPRESSION src/ext/.*)
SOURCE_GROUP (filters REGULAR_EXPRESSION src/filters/.*)
SOURCE_GROUP (integrators REGULAR_EXPRESSION src/integrators/.*)
SOURCE_GROUP (lights REGULAR_EXPRESSION src/lights/.*)
SOURCE_GROUP (main REGULAR_EXPRESSION src/main/.*)
SOURCE_GROUP (materials REGULAR_EXPRESSION src/materials/.*)
SOURCE_GROUP (primitives REGULAR_EXPRESSION src/primitives/.*)
SOURCE_GROUP (samplers REGULAR_EXPRESSION src/samplers/.*)
SOURCE_GROUP (textures REGULAR_EXPRESSION src/textures/.*)

###########################################################################
# ogas libraries and executables -->

add_library(ogas STATIC ${OGAS_SOURCE} )


# Need DEBUG
SET(ALL_OGAS_LIBS
  ogas
)

# Main Renderer
add_executable(ogas_exe src/main/OGAS.cpp)
SET_TARGET_PROPERTIES (ogas_exe PROPERTIES OUTPUT_NAME ogas)
target_link_libraries(ogas_exe ${ALL_OGAS_LIBS})


]]