/**********************************************************************
 * The sample codes of overloading the input and output operator,******
 * pay attention to 3 points:                                   *******
 * ----input parameters: const, reference                       *******
 * ----return value:reference                                   *******
 * ----handling the exception in overloading input operator     *******
 * ----the overload function must be not the member function of *******
 *     class                                                    *******
 *********************************************************************/
class Point {
public:
	Point(int x, int y);
	friend ostream& operator<<(ostream& os, const Point& point);
	friend istream& operator>>(istream& is, Point& point);
private:
	int _x;
	int _y;
};

Point::Point(int x, int y) : _x(x), _y(y) { }

ostream& operator<<(ostream& os, const Point& point){
	os<<"point.x: "<<point._x<<endl;
	os<<"point.y: "<<point._y<<endl;

	return os;
}

istream& operator>>(istream& is, Point& point){
	int x, y;	

	is>>x>>y;

	if(is){
		point._x = x;
		point._y = y;
	}
		
	return is;
}
