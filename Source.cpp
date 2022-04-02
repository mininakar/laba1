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

	
	glutInit(&argc, argv); //Инициализация GLUT
	glutInitDisplayMode( GLUT_RGBA);// выбираем mode дисплея RGBA-для цветного вывода
	glutInitWindowSize(1024, 50);//инициализация размера окна
	glutInitWindowPosition(100, 100); //инициализация окна приложений
	glutCreateWindow("Lesson #1"); // создаст окно

	glutDisplayFunc(RenderSceneCB);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	

	return 1;
}