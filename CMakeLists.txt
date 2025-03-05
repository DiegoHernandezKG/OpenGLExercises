cmake_minimum_required(VERSION 3.20)
project(Exercise CXX C)

find_package(OpenGL REQUIRED)
add_subdirectory(libs/glfw)
add_subdirectory(libs/assimp)
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

set(IMGUI_SOURCES
    ${PROJECT_SOURCE_DIR}/libs/imgui/imgui_demo.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui/imgui_tables.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui/imgui_draw.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui/imgui_widgets.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui/imgui.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui/backends/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui/backends/imgui_impl_opengl3.cpp
)

# add_executable(app src/*.cpp src/*.c src/)
add_executable(${PROJECT_NAME} ${SOURCES} ${IMGUI_SOURCES})
#set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/bin")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
# Include Paths
target_include_directories(${PROJECT_NAME} PRIVATE include libs/glfw/include libs/assimp/include libs/glm libs/imgui libs/imgui/backends)

# Link Libraries
if(WIN32)
    message(STATUS "Building for windows")    
    target_link_libraries(${PROJECT_NAME} glfw opengl32 gdi32)
elseif(UNIX)
    message(STATUS "Building for Linux")
    target_link_libraries(${PROJECT_NAME} GL glfw3 pthread dl X11)
endif()