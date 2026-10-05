#pragma once

#include <string>

class GLFWwindow;

class Application {
public:
  // Load all dependencies
  Application(int width, int height, const std::string& title);

  // Free up used memories
  ~Application();

  void run();

private:
  GLFWwindow* m_window;
};
