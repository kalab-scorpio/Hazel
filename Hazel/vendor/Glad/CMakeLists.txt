project(Glad)

file(GLOB Glad_SOURCE_FILES "${CMAKE_SOURCE_DIR}/Hazel/vendor/Glad/src/*.c")
file(GLOB Glad_HEADER_FILES "${CMAKE_SOURCE_DIR}/Hazel/vendor/Glad/include/glad/*.h" "${CMAKE_SOURCE_DIR}/Hazel/vendor/Glad/include/KHR/*.h")

# set(BUILD_SHARED_LIBS YES)

add_library(${PROJECT_NAME} ${Glad_SOURCE_FILES} ${Glad_HEADER_FILES})