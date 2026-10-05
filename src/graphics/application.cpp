#define GLFW_INCLUDE_NONE

#include "graphics/application.h"

#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <iostream>

Application::Application(int width, int height, const std::string& title)
{
  // Initialize GLFW
  if (!glfwInit()) {
    return;
  }

  float xscale, yscale;
  glfwGetMonitorContentScale(glfwGetPrimaryMonitor(), &xscale, &yscale);

  m_window =
      glfwCreateWindow(width / xscale, height / yscale, title.c_str(), 0, 0);

  if (!m_window) {
    std::cerr << "Failed to create window!" << '\n';
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(m_window);

  // Initialize glad
  if (!gladLoadGL(glfwGetProcAddress)) {
    std::cerr << "Failed to initialize glad!" << '\n';
    return;
  }

  int x, y;
  glfwGetFramebufferSize(m_window, &x, &y);
  glViewport(0, 0, x, y);
}

Application::~Application() { glfwTerminate(); }

void Application::run()
{
  while (!glfwWindowShouldClose(m_window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(m_window);

    glfwPollEvents();
  }
}
