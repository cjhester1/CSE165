#include "Position.h"

Position::Position() {

	mx = 0.0;
	my = 0.0;

	redval = 0.0;
	gval = 0.0;
	bval = 0.0;
}

Position::Position(float mx, float my, float redval, float gval, float bval) {

	this->mx = mx;
	this->my = my;

	this->redval = redval;
	this->gval = gval;
	this->bval = bval;
}

void Position::setMx(float mx) {

	this->mx = mx;

	return;
}

float Position::getMx() {

	return this->mx;
}

void Position::setMy(float my) {

	this->my = my;

	return;
}

float Position::getMy() {

	return this->my;
}

void Position::setredval(float redval) {

	this->redval = redval;

	return;
}

float Position::getredval() {

	return this->redval;
}

void Position::setgval(float gval) {

	this->gval = gval;

	return;
}

float Position::getgval() {

	return this->gval;
}

void Position::setbval(float bval) {

	this->bval = bval;

	return;
}

float Position::getbval() {

	return this->bval;
}

