cmake_minimum_required(VERSION "3.17")

project(Imgui)

file(GLOB Imgui_SOURCE_FILES "${Imgui_SOURCE_DIR}/i*.cpp")
file(GLOB Imgui_HEADER_FILES "${Imgui_SOURCE_DIR}/imgui.h")

set(BUILD_SHARED_LIBS YES)

add_library(${PROJECT_NAME} ${Imgui_SOURCE_FILES} ${Imgui_HEADER_FILES})