/*
这是一个头文件
向量和旋转矩阵的头文件
*/
#ifndef _MATRIX_
#define _MATRIX_
#include<ostream>

#define OK 1
#define ERROR 0
#define accuracy 1e-6
#define PI 3.14159265358979

typedef int Status; //函数运行状态
class RMatrix;
class Vector;

class Vector {
private:
	float x, y, z;//三维空间向量坐标
	friend class RMatrix;

public:
	Vector();
	Vector(float _x, float _y, float _z);
	Vector(const Vector& V);//三个构造函数
	float X() const;
	float Y() const;
	float Z() const;//分别返回三个坐标的值

	void clear();
	Vector& operator = (const Vector& V);//多余

	Vector operator^ (const Vector& V); //叉乘

	float operator * (const Vector& V) const;

	Vector operator-(const Vector& V) const;

	Vector operator + (const Vector& V) const;
	Vector& operator += (const Vector& V);

	Vector operator * (float power) const;
	Vector& operator *= (float power);

	Status Rotate(const Vector& n , float angle);//旋转绕轴旋转

	Status Translate(float dx, float dy, float dz);
	Status Normalize();//单位化
	float Angle(Vector _r) const;

	float R() const;

	friend std::ostream& operator<< (std::ostream& out, const Vector& V);
};

std::ostream& operator<< (std::ostream& out, const Vector& V);

class RMatrix {
private:
	int row, col;
	float base[9];
	friend class Vector;
public:
	RMatrix();
	RMatrix(char axis, float sida);//构造绕X或Y或Z轴的旋转矩阵
//	RMatrix(const RMatrix& obj);
	RMatrix operator* (const RMatrix& other);
	RMatrix& operator*= (const RMatrix& other);
	Vector operator* (const Vector& v);


};



#endif //!_MATRIX_