#include	<iostream>
#include	<gl/freeglut.h>
#include	<gl/glu.h>
#include	<gl/glut.h>


 void RenderSceneCB() //функция обратного вызова т.к мы работаем в оконной системе
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char** argv) {

	
	glutInit(&argc, argv); //Инициализация GLUT
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA);// выбираем режим отображения дисплея RGBA-для цветного вывода
	glutInitWindowPosition(100, 100); //инициализация верхнего левого угла окна 
	glutInitWindowSize(1024, 1024);//инициализация размера окна 
	glutCreateWindow("Lesson #1"); // создаст окно

	glutDisplayFunc(RenderSceneCB); //устанавливает обратный вызов дисплея для текущего окна.

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();// Основной цикл GLUT
	
	return 1;
}