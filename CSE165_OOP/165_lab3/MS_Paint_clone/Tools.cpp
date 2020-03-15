#include "Tools.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Tools::Tools() {

	x = -0.5;
	y = 0.5;
	w = 0.5;
	h = 0.5;

	write = false;

	color = NONE;
	tool = none;
}

Tools::Tools(float x, float y, float w, float h, bool write, Color color, Tool tool) {

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->write = write;

	this->color = color;
	this->tool = tool;
}

void Tools::setWrite(bool write) {

	this->write = write;

	return;
}

bool Tools::getWrite() {

	return this->write;
}

void Tools::setColor(Color color) {

	this->color = color;

	return;
}

Color Tools::getColor() {

	return this->color;
}

void Tools::setTool(Tool tool) {

	this->tool = tool;

	return;
}

Tool Tools::getTool() {

	return this->tool;
}

bool Tools::contains(float mx, float my) {

	if ((mx > x) && (mx < x + w) && (my < y) && (my > y - h)) {
		return true;
	}

	return false;
}

void Tools::display() {

	float redval = 0.0;
	float gval = 0.0;
	float bval = 0.0;

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

	glColor3f(redval, gval, bval);

	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);

	glEnd();

	if (tool == eraser) {
		const char *str = "Eraser";

		glColor3f(1.0, 1.0, 1.0);

		glRasterPos2f(x + 0.06, y - 0.12);

		for (int i = 0; str[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
		}
	} else if (tool == pencil) {
		const char *str = "Pencil";

		glColor3f(1.0, 1.0, 1.0);

		glRasterPos2f(x + 0.06, y - 0.12);

		for (int i = 0; str[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
		}
	} else if (tool == brush) {
		const char *str = "Brush";

		glColor3f(1.0, 1.0, 1.0);

		glRasterPos2f(x + 0.06, y - 0.12);

		for (int i = 0; str[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
		}
	} else if (tool == blank) {
		const char *str = "Blank";

		glColor3f(1.0, 1.0, 1.0);

		glRasterPos2f(x + 0.06, y - 0.12);

		for (int i = 0; str[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
		}
	}

	return;
}

