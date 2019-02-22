#pragma once
#include <iostream>
struct Point
{
	Point(int x, int y):m_x(x),m_y(y){}
	friend std::ostream& operator<<(std::ostream& os, const Point& p){
		os<<p.m_x<<", "<<p.m_y<<std::endl;
		return os;
	}
	double m_x;
	double m_y;
};

template<typename ... Ts>
void move(double x, double y, Ts&... args){
	(helper(x,y,args),...);
	return;
}

void helper(double x, double y, Point& p){
	p.m_x += x;
	p.m_y += y;
	return;
}

template<typename ... Ts>
void print(Ts... args){
	(std::cout<< ... << args ) << std::endl;
}