#ifndef POSITION_H
#define POSITION_H

class Position {

private:

	float mx;
	float my;

	float redval;
	float gval;
	float bval;

public:
	Position();

	Position(float mx, float my, float redval, float gval, float bval);

	void setMx(float mx);

	float getMx();//get mx value from position

	void setMy(float my);

	float getMy();//get my value from position

	void setredval(float redval);

	float getredval();//get red value

	void setgval(float gval);

	float getgval();//get green value

	void setbval(float bval);

	float getbval();//get blue value
};

#endif /* Position.h */

