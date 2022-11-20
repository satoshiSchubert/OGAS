###########################################################################
# Overall Settings -->

cmake_minimum_required(VERSION 3.16)
project(OGAS)

set(CMAKE_CXX_STANDARD 20)


###########################################################################
# On to OGAS -->

#SET ( GLOB OGAS_CORE_SOURCE
#  src/core/*.cpp
#  )

#SET ( GLOB OGAS_CORE_HEADERS
#  src/core/*.h
#  )

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
            #${OGAS_CORE_SOURCE}
            #${OGAS_CORE_HEADERS}


# Need DEBUG
SET(ALL_OGAS_LIBS
  ogas
)

# Main Renderer
add_executable(ogas_exe src/main/OGAS.cpp)
SET_TARGET_PROPERTIES (ogas_exe PROPERTIES OUTPUT_NAME ogas)
target_link_libraries(ogas_exe ${ALL_OGAS_LIBS})


# # Tools
# ADD_EXECUTABLE ( bsdftest src/tools/bsdftest.cpp )
# ADD_SANITIZERS ( bsdftest )
# TARGET_COMPILE_FEATURES ( bsdftest PRIVATE ${PBRT_CXX11_FEATURES} )
# TARGET_LINK_LIBRARIES ( bsdftest ${ALL_PBRT_LIBS} )

# ADD_EXECUTABLE ( imgtool src/tools/imgtool.cpp )
# ADD_SANITIZERS ( imgtool )
# TARGET_COMPILE_FEATURES ( imgtool PRIVATE ${PBRT_CXX11_FEATURES} )
# TARGET_LINK_LIBRARIES ( imgtool ${ALL_PBRT_LIBS} )

# ADD_EXECUTABLE ( obj2pbrt src/tools/obj2pbrt.cpp )
# TARGET_COMPILE_FEATURES ( obj2pbrt PRIVATE ${PBRT_CXX11_FEATURES} )
# ADD_SANITIZERS ( obj2pbrt )

# ADD_EXECUTABLE ( cyhair2pbrt src/tools/cyhair2pbrt.cpp )
# ADD_SANITIZERS ( cyhair2pbrt )

# # Unit test

# FILE ( GLOB PBRT_TEST_SOURCE
#   src/tests/*.cpp
#   src/tests/gtest/*.cc
#   )

# ADD_EXECUTABLE ( pbrt_test ${PBRT_TEST_SOURCE} )
# ADD_SANITIZERS ( pbrt_test )
# TARGET_COMPILE_FEATURES ( pbrt_test PRIVATE ${PBRT_CXX11_FEATURES} )
# TARGET_LINK_LIBRARIES ( pbrt_test ${ALL_PBRT_LIBS} )

# ADD_TEST ( pbrt_unit_test pbrt_test )


