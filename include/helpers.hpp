#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void initializeGLFW();
ImGuiIO& initializeGUI();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* createWindow(int width, int height, const char* title);
void imguiBeginRender();
void imguiEndRender();
void imguiDestroy();
void TestWindow(ImGuiIO& io);

#endif