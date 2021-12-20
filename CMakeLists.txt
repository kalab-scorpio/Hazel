cmake_minimum_required(VERSION "3.17")

set(CMAKE_CXX_STANDARD 11)

project(Hazel)

include_directories("${CMAKE_SOURCE_DIR}/Hazel/src/")
include_directories("${CMAKE_SOURCE_DIR}/Hazel/vendor/Glad/include/")
include_directories("${CMAKE_SOURCE_DIR}/Hazel/vendor/Glfw/include/")
include_directories("${CMAKE_SOURCE_DIR}/Hazel/vendor/imgui/")
include_directories("${CMAKE_SOURCE_DIR}/Hazel/vendor/spdlog/include/")

file(GLOB HAZEL_HEADER_FILES "${CMAKE_SOURCE_DIR}/Hazel/src/Hazel/ImGui/*.h" 
							 "${CMAKE_SOURCE_DIR}/Hazel/src/Hazel/*.h" 
							 "${CMAKE_SOURCE_DIR}/Hazel/src/*.h" 
							 "${CMAKE_SOURCE_DIR}/Hazel/src/Platform/Linux/*.h"
							 "${CMAKE_SOURCE_DIR}/Hazel/src/Platform/OpenGl/*.h")
file(GLOB HAZEL_SOURCE_FILES "${CMAKE_SOURCE_DIR}/Hazel/src/Hazel/ImGui/*.cpp" 
							 "${CMAKE_SOURCE_DIR}/Hazel/src/Hazel/*.cpp" 
							 "${CMAKE_SOURCE_DIR}/Hazel/src/Platform/Linux/*.cpp"
							 "${CMAKE_SOURCE_DIR}/Hazel/src/Platform/OpenGl/*.cpp")

set(BUILD_SHARED_LIBS YES)

add_library(${PROJECT_NAME} ${HAZEL_SOURCE_FILES} ${HAZEL_HEADER_FILES})
target_precompile_headers(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Hazel/src/hzpch.h")

add_subdirectory("${CMAKE_SOURCE_DIR}/Hazel/vendor/Glad/")

# project(glfw)

# add_subdirectory("${CMAKE_SOURCE_DIR}/Hazel/vendor/Glfw/")

add_subdirectory("${CMAKE_SOURCE_DIR}/Hazel/vendor/imgui/")

# set(Glfw "${CMAKE_SOURCE_DIR}/Hazel/vendor/glfw/libglfw.so")
add_compile_definitions(GLFW_INCLUDE_NONE)

project(Sandbox)

file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/Sandbox/src/*.cpp")
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/Sandbox/src/*.h")
# file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/stb_image/*.h")
	# "${CMAKE_SOURCE_DIR}/include" )

# file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION .)
# configure_file(res/shaders/Basic.shader ${CMAKE_SOURCE_DIR}/res/shaders/Basic.shader)
# file(COPY ${CMAKE_SOURCE_DIR}/src/vendor DESTINATION .)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# tell it to link the executable target against OpenCV
target_link_libraries(${PROJECT_NAME} Hazel glfw Glad Imgui)