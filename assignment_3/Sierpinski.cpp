/*
 * File: Sierpinski.cpp
 * --------------------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Sierpinski problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gwindow.h"
#include "simpio.h"
#include <cmath>
using namespace std;

/* Initializing constants for angles in degrees */
const int TURN_ONCE = 120;

/* This method draws Sierpinski triangle recursively */
void drawSierpinski(int length, int order, double xCo, double yCo, GWindow gw) {
	if(order == 0) { 
		GPoint p1 = gw.drawPolarLine(xCo, yCo, length, 0);
		GPoint p2 = gw.drawPolarLine(p1, length, TURN_ONCE);
		GPoint p3 = gw.drawPolarLine(p2, length, TURN_ONCE*2);
	} else {
		GPoint p1(xCo+length/2, yCo);
		GPoint p2(xCo+length/4, yCo - double(pow(3,0.5))*length/4);
		drawSierpinski(length/2, order-1, xCo, yCo, gw);
		drawSierpinski(length/2, order-1, p1.getX(), p1.getY(), gw);
		drawSierpinski(length/2, order-1, p2.getX(), p2.getY(), gw);
	}
}

/* Initializing inputs and drawing Sierpinski triangle */
int main() {
	GWindow gw;
	double width = gw.getWidth();
	double height = gw.getHeight();
	int length = getInteger("Enter the length of the side of a triangle: ");
	int order = getInteger("Enter the Sierpinski order: ");
	double initialX = (width-length)/2;
	double initialY = (height+length)/2;
	drawSierpinski(length, order, initialX, initialY, gw);
    return 0;
}
