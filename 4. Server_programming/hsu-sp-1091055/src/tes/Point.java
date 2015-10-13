package tes;

public class Point {
	static int num;
	int x,y;
	public Point() {
		x=0;
		y=0;
		num++;
	}
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
		num++;
	}
	public int getX() {
		return x;
	}
	public void setX(int xValue) {
		x = xValue;
	}
	public int getY() {
		return y;
	}
	public void setY(int yValue) {
		y = yValue;
	}
	public void move(int xValue, int yValue) {
		x += xValue;
		y += yValue;
	}
	public static int getInstanceNum() {
		return num;
	}
	
}
