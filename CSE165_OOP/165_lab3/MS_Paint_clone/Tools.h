#ifndef TOOLS_H
#define TOOLS_H

// Step 1
enum Color {NONE, BLACK, WHITE, GRAY, MAGENTA, ORANGE, RED, BROWN, YELLOW,
			CYAN, GREEN, PURPLE, BLUE, LILAC, GOLD, TEAL, DESERT};

enum Tool {none, eraser, pencil, brush, blank};

class Tools {

private:

	float x;
	float y;
	float w;
	float h;

	bool write;

	Color color;
	Tool tool;

public:

	Tools();

	Tools(float x, float y, float w, float h, bool write, Color color, Tool tool);

	void setWrite(bool write);

	bool getWrite();

	void setColor(Color color);

	Color getColor();

	void setTool(Tool tool);

	Tool getTool();

	bool contains(float mx, float my);

	void display();
};

#endif /* Tools.h */

