#include "canvas.h"
#include <iostream>
#include <cstdarg>

Canvas::Canvas(int lines,int column)
{
	this->lines = lines;
	this->columns = column;
	clear();
}

void Canvas::set_pixel(int x, int y, char value)
{
	if (x < 0 || y < 0 || x>this->lines || y>this->columns)
		return;
	this->matrix[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
	va_list va;
	int sum = 0;
	va_start(va, count*3);
	for (int i = 0; i < count; i++) {
		int x= va_arg(va, int);
		int y = va_arg(va, int);
		char val = va_arg(va, char);
		set_pixel(x, y, val);
	}
	va_end(va);
}

void Canvas::clear()
{
	this->matrix = new char* [lines];
	for (int i = 0; i < this->lines; i++)
		this->matrix[i] = new char[this->columns];
	for (int i = 0; i < this->lines; i++)
		for (int q = 0; q < this->columns; q++)
			this->matrix[i][q] = ' ';
}
void Canvas::print() const{
	for (int i = 0; i < this->lines; i++) {
		for (int q = 0; q < this->columns; q++){
			std::cout << this->matrix[i][q];
		}
		std::cout << std::endl;
	}
}