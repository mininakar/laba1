#include	<iostream>
#include	<gl/freeglut.h>
#include	<gl/glu.h>
#include	<gl/glut.h>


 void RenderSceneCB() //������� ��������� ������ �.� �� �������� � ������� �������
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char** argv) {

	
	glutInit(&argc, argv); //������������� GLUT
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA);// �������� ����� ����������� ������� RGBA-��� �������� ������
	glutInitWindowPosition(100, 100); //������������� �������� ������ ���� ���� 
	glutInitWindowSize(1024, 1024);//������������� ������� ���� 
	glutCreateWindow("Lesson #1"); // ������� ����

	glutDisplayFunc(RenderSceneCB); //������������� �������� ����� ������� ��� �������� ����.

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();// �������� ���� GLUT
	
	return 1;
}