#include<iostream>
#include<GL/glew.h>//include/GL/glew.h
#include<GLFW/glfw3.h>//include/GLFW/glfw3.h
//����һ���궨�� ���õ�msvc����glewʱ����Ҫdll�����������õ��Ǿ�̬lib����Ԥ��������GLEW_STATIC;

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	std::cout << "Error!glew" << std::endl;
	//glewinitҪ��ָ��gl�����ĺ�//glew���ڽ�opengl1.1����ִ�openglʵ�ַ������͵���Ĵ����У�
	std::cout << glGetString(GL_VERSION) << std::endl;//��ʾ���õ��ִ�opengl�汾��
	/* Loop until the user closes the window */

	while (!glfwWindowShouldClose(window))//equals :glutmainloop()
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, 0);
		glVertex2f(0, 0.5);
		glVertex2f(0.5, 0);
		glEnd();
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}