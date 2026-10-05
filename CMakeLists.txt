cmake_minimum_required(VERSION 4.4.4)

project(3D-Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#--------------------------------------------------------------------
# Setup libraries
#--------------------------------------------------------------------

# Setup GLFW
include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 # 3.4
)

# Specify glfw settings
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

FetchContent_MakeAvailable(glfw)
#--------------------------------------------------------------------

# Setup Glad
FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG 73db193f853e2ee079bf3ca8a64aa2eaf6459043 # v2.0.8
  SOURCE_SUBDIR cmake
)

FetchContent_MakeAvailable(glad)

# Specify glad settings
glad_add_library(glad_gl_core_46 REPRODUCIBLE API gl:core=4.6)
#--------------------------------------------------------------------

set(base "src/base/application.cpp")

add_executable(3D-Tetris "src/main.cpp" ${base})
target_link_libraries(3D-Tetris PRIVATE glfw glad_gl_core_46)
target_include_directories(3D-Tetris PRIVATE "src")
