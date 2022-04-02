#include	<iostream>
#include	<GL/glew.h>
#include	<gl/freeglut.h>
#include	<gl/glu.h>
#include	<gl/glut.h>
#include <glm/glm.hpp>
#include <glm/vector_relational.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

GLuint VBO;
//#include	"math_3d.h"




void RenderSceneCB() //������� ��������� ������ �.� �� �������� � ������� �������
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//������� �����

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

	glutSwapBuffers();//������������� ����� �� �����
}

	

int main(int argc, char** argv) {

	
	glutInit(&argc, argv); //������������� GLUT
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA);// �������� ����� ����������� ������� RGBA-��� �������� ������
	glutInitWindowPosition(100, 100); //������������� �������� ������ ���� ���� 
	glutInitWindowSize(1024, 1024);//������������� ������� ���� 
	glutCreateWindow("Lesson #2"); // ������� ����

	glutDisplayFunc(RenderSceneCB); //������������� �������� ����� ������� ��� �������� ����.

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	glm::vec3 Vertices[3];
	Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);
	Vertices[1] = glm::vec3(5.0f, 0.0f, 0.0f);
	Vertices[2] = glm::vec3(1.0f, -1.0f, 0.0f);
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glutMainLoop();// �������� ���� GLUT

	

	return 1;
}