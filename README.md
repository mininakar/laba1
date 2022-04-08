# laba1
BASIS:
OpenGL has:
10 main primitives from which all objects are built.
buffer - stores rendering data, which is understood as video memory.
target- has many meanings, but usually means a destination for something.
GLenum is the OpenGL type, means enumerator value. Bitdepth = 32


void RenderSceneCB()
function is used to call back display for continuous callback.further I describe what exactly happens and what each function is responsible for in RenderSceneCB.

{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
  Sets the bitplane area of the window to values previously selected. The void takes a single argument that is the bitwise OR of several values indicating which buffer is to be cleared.
	    GL_COLOR_BUFFER_BIT - Indicates the buffers currently enabled for color writing.
	    GL_DEPTH_BUFFER_BIT - Indicates the stencil buffer.

  glEnableVertexAttribArray(0)
  Enable the generic vertex attribute array specified by index (=0). The void uses currently bound vertex array object for the operation.

  glBindBuffer(GL_ARRAY_BUFFER, VBO)
  Bind a named buffer object. Takes two variables: first = target, second = buffer. Target specifies the target to which the buffer object is bound, and buffer specifies the name of a buffer object.
	    GL_ARRAY_BUFFER - buffer binding targets vertex attributes 
	    VBO - provides methods for offloading data to the video device for non-live rendering

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0)
  The void define an array of generic vertex attribute data. Takes 6 variables: index, size, type, normalized (boolean variable), stride and const void * pointer
	    index - specifies the index (=0) of the generic vertex attribute to be modified
	    size - specifies the number of components per generic vertex attribute
	    type - specifies the data type of each component in the array. Use initial value = GL_FLOAT.
	    normalized GL_FALSE - specifies whether fixed-point data values should be converted directly as fixed-point values when they are accessed
	    stride - specifies the byte offset between consecutive generic vertex attributes. Use the initial value = 0, thats mean the generic vertex attributes are understood to be tightly packed in the array.
	    pointer - specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer. Use the initial value = 0.

	 glDrawArrays(GL_TRIANGLES, 0, 3)
	Render primitives from array data. Takes 3 values: mode, first, count
		mode - specifies what kind of primitives to render. 
		first - specifies the starting index in the enabled arrays.
		count - specifies the number of indices to be rendered.

	glDisableVertexAttribArray(0)
		Disable a generic vertex attribute array.

	glutSwapBuffers()
}


MAIN:
glutInit(&argc, argv)
the void uses for initialization. initialize the GLUT library and negotiate a session with the window system. Takes 2 variables.
	&argc - pointer to the program's unmodified argc variable from main. Upon return, the value pointed to by argc will be updated.
	argv - the program's unmodified argv variable from main, the data for argv will be updated.

glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA)
Sets the initial display mode.
	GLUT_DOUBLE - bit mask to select a double buffered window
	GLUT_RGBA - bit mask to select an RGBA mode window

glutInitWindowPosition(100, 100)
set the initial window position. Takes 2 variables: x and y.
	x - windows X location in pixels.
	y - windows Y location in pixels.


glutInitWindowSize(1024, 1024)
set the size window. Takes 2 int variables: width and height (both in pixels).
 
glutCreateWindow("Lesson #2")
the void creates a window based on glutInitWindowPosition and glutInitWindowSize.

glutDisplayFunc(RenderSceneCB)
sets the display callback for the current window. Takes 1 variable func, thats means the new display callback function.

glClearColor(0.0f, 0.0f, 0.0f, 0.0f)
specifies the red, green, blue, and alpha values. Values specified by glClearColor are clamped to the range [0,1].


I call glewInit to initialize the entry points. Then I check if the variable res and GLEW_OK are not equal, if they not equal that mean thats initialization is not succeeded. and i output error-messege
GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}


I am using the glm library to create a vector. Then I initialize each vertex of the vector.
glm::vec3 Vertices[3];
	Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);
	Vertices[1] = glm::vec3(5.0f, 0.0f, 0.0f);
	Vertices[2] = glm::vec3(1.0f, -1.0f, 0.0f);
	

glGenBuffers(1, &VBO)
Generate buffer object names. Take 2 variables: n, *buffer.
	n - the number of buffer object names to be generated.
	*buffer - an array in which the generated buffer object names are stored.

glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW)
creates and initializes a buffer object's data store. Takes 4 variables: targer, size, data, uusage.
	target - Specifies the target to which the buffer object is bound for this void. GL_ARRAY_BUFFER means vertex attributes
	size - specifies the size in bytes of the buffer object's new data store. I pass the size of the vector Vertices to this variable. 
	data - Specifies a pointer to data that will be copied into the data store for initialization
	usage - Specifies the expected usage pattern of the data store. I use pattern GL_STATIC_DRAW thats means the data store contents will be modified once and used many times.

glutMainLoop()
window processing
