#include	<iostream>
#include	<gl/freeglut.h>
#include	<gl/glu.h>
#include	<gl/glut.h>


 void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char** argv) {

	
	glutInit(&argc, argv); //������������� GLUT
	glutInitDisplayMode( GLUT_RGBA);// �������� mode ������� RGBA-��� �������� ������
	glutInitWindowSize(1024, 50);//������������� ������� ����
	glutInitWindowPosition(100, 100); //������������� ���� ����������
	glutCreateWindow("Lesson #1"); // ������� ����

	glutDisplayFunc(RenderSceneCB);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	

	return 1;
}