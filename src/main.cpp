#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int g_window_sizeX = 640;
int g_window_sizeY = 480;

void glfwWindowCallBack(GLFWwindow* pWindow, int windowSize, int windowHeight)
{
    g_window_sizeX = windowSize;
    g_window_sizeY = windowHeight;
    glViewport(0, 0, g_window_sizeX, g_window_sizeY);
}

void glfwKeyCallBack(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    GLFWwindow* pWindow;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    pWindow = glfwCreateWindow(g_window_sizeX, g_window_sizeY , "GAME", NULL, NULL);
    if (!pWindow)
    {
        std::cout << "Error: glfwCreateWindow failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowCallBack);
    glfwSetKeyCallback(pWindow, glfwKeyCallBack);
    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
	
	if (!gladLoadGL())
	{
		std::cout << "Error: Can't load GLAD" << std::endl;
		return -1;
	}
	
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	glClearColor(13, 50, 0, 1);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}