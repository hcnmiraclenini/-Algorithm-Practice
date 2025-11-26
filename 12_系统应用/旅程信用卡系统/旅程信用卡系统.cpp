#include <iostream>
using namespace std;
class CPoint
{
private:
	int x;
	int y;
public:
	CPoint(int x_, int y_);
	int getX();
	int getY();

};
CPoint::CPoint(int x_ , int y_ )
{
	x = x_;
	y = y_;
}
int CPoint::getX()
{
	return x;
}
int CPoint::getY()
{
	return y;
}
/*矩形类*/
class CRectangle
{
private:
	CPoint leftPoint;// 左上角坐标
	CPoint rightPoint;//右下角坐标
public:
	CRectangle(int x1, int y1, int x2, int y2) :leftPoint(x1, y1), rightPoint(x2, y2) {}
	bool operator>(CPoint& c);
	bool operator>(CRectangle& c);//要求该函数调用重载>运算符函数实现
	bool operator==(CRectangle& c);
	bool operator*(CRectangle& c);
    operator int();//计算矩形的面积并返回
	friend ostream& operator<<(ostream& stream,CRectangle& C);
};
/*根据函数写起来的难度排，先易后难*/
ostream& operator<<(ostream& stream, CRectangle& C)
{
	stream << C.leftPoint.getX()<<" "<<C.leftPoint.getY()<<" ";
	stream << C.rightPoint.getX() << " " << C.rightPoint.getY();
	return stream;
}
bool CRectangle::operator==(CRectangle& c)
{
    if ((this->leftPoint.getX() == c.leftPoint.getX()) && (this->leftPoint.getY() == c.leftPoint.getY()) && (this->rightPoint.getX() == c.rightPoint.getX()) && (this->rightPoint.getY() && c.rightPoint.getY()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CRectangle::operator>(CPoint& c)
{
    if ((c.getX() >= this->leftPoint.getX()) &&( c.getX()<=this->rightPoint.getX())&&(c.getY() <= this->leftPoint.getY())&&(c.getY()>=this->rightPoint.getY()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CRectangle::operator>(CRectangle& c)
{
    if ((this->operator>(c.leftPoint))&& (this->operator>(c.rightPoint)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

CRectangle::operator int()
{
    int sum=((leftPoint.getY() - rightPoint.getY()) * (rightPoint.getX() - leftPoint.getX()));
    if (sum < 0)
    {
        return -sum;
    }
    else
    {
        return sum;
    }
}
bool CRectangle::operator*(CRectangle& c)//是否重叠
{
    int x1_ = this->leftPoint.getX();
    int y1_ = this->leftPoint.getY();
    int x2_ = this->rightPoint.getX();
    int y2_ = this->rightPoint.getY();
    int x1 = c.leftPoint.getX();
    int y1 = c.leftPoint.getY();
    int x2 = c.rightPoint.getX();
    int y2 = c.rightPoint.getY();
    
    
    if (x2 < x1_)
    {
       // cout << "&";
         return false;
    }
    if (x1> x2_)
    {
        //cout << "*";
        return false;
    }
    if (y1<y2_)
    {
        //cout << "%";
        return false;
    }
    if (y2 >y1_ )
    {
        //cout << "$";
        return false;
    }
    else
    {
        //cout << "#";
        return true;
    }
}







/*主函数*/
int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        // 矩形1的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        // 矩形2的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        // 输出矩形1的坐标及面积
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        // 输出矩形2的坐标及面积
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}





