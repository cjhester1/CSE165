#include <iostream>
#include <cmath>
#include <vector>
#include "Tools.h"
#include "Position.h"
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

/*
 
 my personal tutor Jaime Arrocha <jarrocha27@gmail.com> from varsitytutors.com assisted me with this lab
 
 */

// Store the width and height of the window
int width = 640, height = 640;

float redval = 0.0; // set the red value on RGB global color wheel
float gval = 0.0; // set the green value on RGB global color wheel
float bval = 0.0; // set the blue value on RGB global color wheel

Tool tool = none; //initialize tool selected to none.. when user starts app no tool is selected
Color color = NONE;//initialize color selected to none.. when user starts app no color is selected as well

std::vector<Position> coord;
std::vector<Tools> layout;

void Ichooseyou() {
    
    /*
     
     Here is basically just setting the colors ..I wanted to use alot of colors in mine
     I googled each color's RGB value but I adjusted some of the values because I like the bright colors
     
     
     */

	switch (color) {
		case BLACK:
			redval = 0.0; gval = 0.0; bval = 0.0;
			break;
		case WHITE:
			redval = 1.0; gval = 1.0; bval = 1.0;
			break;
		case GRAY:
			redval = 0.5; gval = 0.5; bval = 0.5;
			break;
		case MAGENTA:
			redval = 0.9; gval = 0.1; bval = 0.9;
			break;
		case ORANGE:
			redval = 1.0; gval = 0.5; bval = 0.0;
			break;
		case RED:
			redval = 1.0; gval = 0.0; bval = 0.0;
			break;
		case BROWN:
			redval = 0.39; gval = 0.26; bval = 0.13;
			break;
		case YELLOW:
			redval = 1.0; gval = 1.0; bval = 0.0;
			break;
		case CYAN:
			redval = 0.5; gval = 1.0; bval = 1.0;
			break;
		case GREEN:
			redval = 0.0; gval = 1.0; bval = 0.0;
			break;
		case PURPLE:
			redval = 0.5; gval = 0.0; bval = 0.5;
			break;
		case BLUE:
			redval = 0.0; gval = 0.0; bval = 1.0;
			break;
		case LILAC:
			redval = 0.78; gval = 0.63; bval = 0.78;
			break;
		case GOLD:
			redval = 0.83; gval = 0.68; bval = 0.21;
			break;
		case TEAL:
			redval = 0.31; gval = 0.84; bval = 0.72;
			break;
		case DESERT:
			redval = 1.0; gval = 0.698; bval = 0.427;
			break;
		default:
			break;
	}

	return;
}

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {

	
	glClearColor(0.3, 0.3, 0.3, 1.0);

	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
    glMatrixMode(GL_MODELVIEW); //Applies subsequent matrix operations to the modelview matrix stack.
	glLoadIdentity();// glLoadIdentity replaces the current matrix with the identity matrix.

	for (std::vector<Tools>::iterator it = layout.begin(); it != layout.end(); ++it) {//based on what tool is selected
		it->display();
	}

	glPointSize(5);

	glBegin(GL_POINTS);

	for (std::vector<Position>::iterator it = coord.begin(); it != coord.end(); ++it) {//now that the tool is selected, get the position
		glColor3f(it->getredval(), it->getgval(), it->getbval());//get RGB color value from redval gval and bval
		glVertex2f(it->getMx(), it->getMy());//get value where mouse is clicked
	}

	glEnd();

	
	glFlush();
	glutSwapBuffers();  //this allows us to see what we've been drawing..have been drawing in buffer that isnt seen

	return;
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments:
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {

	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));

	return;
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s    - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {

	
	width = w;
	height = h;

	glViewport(0, 0, width, height);// setting the window
	glOrtho(0, width, 0, height, -1.0, 1.0);//the glOrtho command produces an "Oblique" projection that you see in the bottom row. No matter how far away vertexes are in the z direction, they will not recede into the distance. ....  https://stackoverflow.com/questions/2571402/how-to-use-glortho-in-opengl
	glMatrixMode(GL_PROJECTION);//Applies subsequent matrix operations to the projection matrix stack.
	glLoadIdentity();// glLoadIdentity replaces the current matrix with the identity matrix.

	return;
}


//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s    - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {

	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	if (b == 0 && s == 0) {
	for (std::vector<Tools>::iterator it = layout.begin(); it != layout.end() - 1; ++it) {
			if (it->getTool() == eraser && it->contains(mx, my)) { //if tool is eraser we use the color white since backgorund is white
				tool = eraser;
				color = WHITE;
				Ichooseyou();
			} else if (it->getTool() == pencil && it->contains(mx, my)) {//if pencil set default color to black
				tool = pencil;
				color = BLACK;
				Ichooseyou();
			} else if (it->getTool() == brush && it->contains(mx, my)) {//if brush set default color to black
				tool = brush;
				color = BLACK;
				Ichooseyou();
			} else if (it->getTool() == blank && it->contains(mx, my)) {
				tool = blank;
				color = BLACK;
				Ichooseyou();
                
                /*
                 
                 these else if statements handle if each color is chosen and uses that color to draw
                 */
			} else if (it->getColor() == BLACK && it->contains(mx, my)) {
				color = BLACK;
			} else if (it->getColor() == WHITE && it->contains(mx, my)) {
				color = WHITE;
			} else if (it->getColor() == GRAY && it->contains(mx, my)) {
				color = GRAY;
			} else if (it->getColor() == MAGENTA && it->contains(mx, my)) {
				color = MAGENTA;
			} else if (it->getColor() == ORANGE && it->contains(mx, my)) {
				color = ORANGE;
			} else if (it->getColor() == RED && it->contains(mx, my)) {
				color = RED;
			} else if (it->getColor() == BROWN && it->contains(mx, my)) {
				color = BROWN;
			} else if (it->getColor() == YELLOW && it->contains(mx, my)) {
				color = YELLOW;
			} else if (it->getColor() == CYAN && it->contains(mx, my)) {
				color = CYAN;
			} else if (it->getColor() == GREEN && it->contains(mx, my)) {
				color = GREEN;
			} else if (it->getColor() == PURPLE && it->contains(mx, my)) {
				color = PURPLE;
			} else if (it->getColor() == BLUE && it->contains(mx, my)) {
				color = BLUE;
			} else if (it->getColor() == LILAC && it->contains(mx, my)) {
				color = LILAC;
			} else if (it->getColor() == GOLD && it->contains(mx, my)) {
				color = GOLD;
			} else if (it->getColor() == TEAL && it->contains(mx, my)) {
				color = TEAL;
			} else if (it->getColor() == DESERT && it->contains(mx, my)) {
				color = DESERT;
			}

			Ichooseyou();
		}
	}

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();

	return;
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments:
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {

	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	for (std::vector<Tools>::iterator it = layout.begin(); it != layout.end(); ++it) {
			if (it->getWrite() && it->contains(mx + 0.025, my + 0.025) && it->contains(mx - 0.025, my - 0.025) && tool == eraser) {//handles dragging of the eraser want eraser to be thicker than the pencil
				color = WHITE; //white because the background is white
				Ichooseyou();//the color we are working with
				for (float i = 0.001; i <= 0.02; i += 0.001) {
					coord.push_back(Position(mx - i, my + i, redval, gval, bval));//coord.push_back function which adds an entry to the end of the vector
					coord.push_back(Position(mx + i, my + i, redval, gval, bval));//get position of clicking and add more coverage (for loop) since its an eraser
					coord.push_back(Position(mx - i, my - i, redval, gval, bval));
					coord.push_back(Position(mx + i, my - i, redval, gval, bval));
				}
			} else if (it->getWrite() && it->contains(mx, my) && tool == pencil) {
				coord.push_back(Position(mx, my, redval, gval, bval));
			} else if (it->getWrite() && it->contains(mx + 0.015, my + 0.015) && it->contains(mx - 0.015, my - 0.015) && tool == brush) {//handles the dragging of the brush
				for (float i = 0.001; i <= 0.01; i += 0.001) {//want the brush to be thicker than the pencil
					coord.push_back(Position(mx - i, my + i, redval, gval, bval));
					coord.push_back(Position(mx + i, my + i, redval, gval, bval));
					coord.push_back(Position(mx - i, my - i, redval, gval, bval));
					coord.push_back(Position(mx + i, my - i, redval, gval, bval));
				}
			}
	}

	// Again, we redraw the scene
	glutPostRedisplay();

	return;
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments:
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {
	
	switch (key) {
		case 27:
			exit(0);
			break;
		default:
			break;
	}

	// After all the state changes, redraw the scene
	glutPostRedisplay();

	return;
}

void idle() {

	return;
}


int main(int argc, char** argv) {

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CJ's Paint Program");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	// Tools position
	layout.push_back(Tools(-0.95, 0.95, 0.25, 0.22, false, NONE, pencil));
	layout.push_back(Tools(-0.95, 0.71, 0.25, 0.22, false, NONE, brush));
	layout.push_back(Tools(-0.95, 0.47, 0.25, 0.22, false, NONE, eraser));
	
	// Colors position
	layout.push_back(Tools(-0.95, -0.49, 0.22, 0.22, false, TEAL, none));
	layout.push_back(Tools(-0.95, -0.73, 0.22, 0.22, false, DESERT, none));

	layout.push_back(Tools(-0.71, -0.49, 0.22, 0.22, false, WHITE, none));
	layout.push_back(Tools(-0.71, -0.73, 0.22, 0.22, false, BLACK, none));

	layout.push_back(Tools(-0.47, -0.49, 0.22, 0.22, false, MAGENTA, none));
	layout.push_back(Tools(-0.47, -0.73, 0.22, 0.22, false, GRAY, none));

	layout.push_back(Tools(-0.23, -0.49, 0.22, 0.22, false, RED, none));
	layout.push_back(Tools(-0.23, -0.73, 0.22, 0.22, false, ORANGE, none));

	layout.push_back(Tools(0.01, -0.49, 0.22, 0.22, false, YELLOW, none));
	layout.push_back(Tools(0.01, -0.73, 0.22, 0.22, false, BROWN, none));

	layout.push_back(Tools(0.25, -0.49, 0.22, 0.22, false, GREEN, none));
	layout.push_back(Tools(0.25, -0.73, 0.22, 0.22, false, CYAN, none));

	layout.push_back(Tools(0.49, -0.49, 0.22, 0.22, false, BLUE, none));
	layout.push_back(Tools(0.49, -0.73, 0.22, 0.22, false, PURPLE, none));

	layout.push_back(Tools(0.73, -0.49, 0.22, 0.22, false, LILAC, none));
	layout.push_back(Tools(0.73, -0.73, 0.22, 0.22, false, GOLD, none));

	// Window
	layout.push_back(Tools(-0.67, 0.95, 1.65, 1.40, true, WHITE, none));

	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);

	glutIdleFunc(idle);

	// Start the main loop
	glutMainLoop();

	return 0;
}

