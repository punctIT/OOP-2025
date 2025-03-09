#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int witdh, int height) {
	this->height = height;
	this->witdh = witdh;
	this->canvas = new char* [height];
	for (int i = 0; i < height; i++)
		canvas[i] = new char[witdh];
	for (int i = 0; i < height; i++)
		for (int q = 0; q < witdh; q++)
			this->canvas[i][q] = ' ';
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	if (left<0 || top<0 || right>this->witdh || bottom>this->height)
		return;
	for (int i = left; i <= right; i++)
		this->canvas[top][i] = this->canvas[bottom][i] = ch;
	for (int i = top; i <= bottom; i++)
		this->canvas[i][left] = this->canvas[i][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	if (left<0 || top<0 || right>this->witdh || bottom>this->height)
		return;
	for (int i = top; i <= bottom; i++){
		for (int q = left; q <= right; q++)
			this->canvas[i][q] = ch;
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x < 0 || y < 0 || x>this->witdh || y>this->height)
		return;
	this->canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1);
	int sx = (x1 < x2) ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = (y1 < y2) ? 1 : -1;
	int error = dx + dy;
	while (1) {
		this->canvas[x1][y1] = ch;

		if (x1 == x2 && y1 == y2) 
			break;

		int e2 = 2 * error;

		if (e2 >= dy) { 
			if (x1 == x2)
				break;
			error += dy;
			x1 += sx;
		}
		if (e2 <= dx) {  
			if (y1 == y2)
				break;
			error += dx;
			y1 += sy;
		}
	}
}


void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = -ray; i <= ray; i++) {
		for (int j = -ray; j <= ray; j++) {
			int distance = i * i + j * j;
			if (distance >= (ray - 1) * (ray - 1) && distance <= ray * ray) 
			{
				int newX = x + i;
				int newY = y + j;

				if (newX >= 0 && newY >= 0 && newX < this->witdh && newY < this->height) {
					this->canvas[newX][newY] = ch;
				}
			}
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = -ray; i <= ray; i++) {
		for (int j = -ray; j <= ray; j++) {
			if (i * i + j * j <= ray * ray) {
				int newX = x + i;
				int newY = y + j;

				if (newX >= 0 && newY >= 0 && newX < this->witdh && newY < this->height) {
					this->canvas[newX][newY] = ch;
				}
			}
		}
	}
}
void Canvas::Print() {
	for (int i = 0; i < this->height; i++) {
		for (int q = 0; q < this->witdh; q++)
			std::cout << this->canvas[i][q] << " ";
		std::cout << std::endl;
	}
	
}
void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int q = 0; q < this->witdh; q++)
			this->canvas[i][q] = ' ';
}