#include "matrix.h"
#include<cmath>

Vector::Vector() : x(0) , y(0) , z(0)
{
}

Vector::Vector(float _x, float _y, float _z) : x(_x) , y(_y) , z(_z)
{
}

Vector::Vector(const Vector& V) : x(V.x) , y(V.y) , z(V.z)
{
}

float Vector::X() const
{
	return x;
}

float Vector::Y() const
{
	return y;
}

float Vector::Z() const
{ 
	return z;
}

void Vector::clear()
{
	x = y = z = 0;
}

Vector& Vector::operator=(const Vector& V)
{
	// TODO: 在此处插入 return 语句
	x = V.x;
	y = V.y;
	z = V.z;
	return *this;
}

Vector Vector::operator^(const Vector& V)
{
	return Vector(y * V.z - z * V.y , z * V.x - x * V.z , x * V.y - y * V.x);
}

float Vector::operator*(const Vector& V) const
{
	return x * V.x + y * V.y + z * V.z;
}

Vector Vector::operator-(const Vector& V) const
{
	return Vector(x - V.x , y - V.y ,z - V.z);
}

Vector Vector::operator+(const Vector& V) const
{
	return Vector(x + V.x , y + V.y , z + V.z);
}

Vector& Vector::operator+=(const Vector& V)
{
	// TODO: 在此处插入 return 语句
	x += V.x;
	y += V.y;
	z += V.z;
	return *this;
}

Vector Vector::operator*(float power) const
{
	return Vector(x * power , y * power , z * power);
}

Vector& Vector::operator*=(float power)
{
	// TODO: 在此处插入 return 语句
	x *= power;
	y *= power;
	z *= power;
	return *this;
}

Status Vector::Rotate(const Vector& n, float angle)
{
	float siday;
	if (n.R() > accuracy || n.R() < -accuracy)
		siday = std :: acos(n.Z() / n.R());
	else
		siday = 0;
	float sidaz;
	if (n.R() > accuracy || n.R() < -accuracy)
		sidaz = std :: atan2(n.Y(), n.X());
	else
		sidaz = 0;
	RMatrix temp1 = RMatrix('Y', siday), temp2 = RMatrix( 'Z', sidaz);
	RMatrix rotatetoaxis = temp2 * temp1;//从(0 , 0 , 1)的方向旋转至n的方向

	temp1 = RMatrix('Y', -siday), temp2 = RMatrix('Z', -sidaz);
	RMatrix rotatetoz = temp1 * temp2;

	RMatrix rotateself = RMatrix( 'Z', angle);
	*this = (rotatetoaxis * rotateself * rotatetoz) * (*this);
	return Status(1);
}

Status Vector::Translate(float dx, float dy, float dz)
{
	x += dx;
	y += dy;
	z += dz;
	return 1;
}

Status Vector::Normalize()
{
	float r = R();
	x /= r;
	y /= r;
	z /= r;
	return 1;
}

float Vector::Angle(Vector _r) const
{
	return std :: acos(((*this) * _r) / (R() * _r.R()));
}

float Vector::R() const
{
	return std::sqrt(std :: pow(x, 2) + std :: pow(y, 2) + std :: pow(z, 2));
}

RMatrix::RMatrix() : row(3) , col(3)
{
	base[0] = 1., base[1] = 0., base[2] = 0.;
	base[3] = 0., base[4] = 1., base[5] = 0.;
	base[6] = 0., base[7] = 0., base[8] = 1.;
}

RMatrix::RMatrix(char axis, float sita) : row(3), col(3)
{
	float cossita = std :: cos(sita), sinsita = std :: sin(sita);
	if (axis == 'X') {
		base[0] = 1., base[1] = 0., base[2] = 0.;
		base[3] = 0., base[4] = cossita, base[5] = sinsita;
		base[6] = 0., base[7] = -1 * sinsita, base[8] = cossita;
	}
	else if (axis == 'Y') {
		base[0] = cossita, base[1] = 0., base[2] = -1. * sinsita;
		base[3] = 0, base[4] = 1., base[5] = 0.;
		base[6] = sinsita, base[7] = 0., base[8] = cossita;
	}
	else if (axis == 'Z') {
		base[0] = cossita, base[1] = sinsita, base[2] = 0.;
		base[3] = -1. * sinsita, base[4] = cossita, base[5] = 0.;
		base[6] = 0., base[7] = 0., base[8] = 1.;
	}
}
/*
RMatrix::RMatrix(const RMatrix& obj)
{
	int i;
	for (i = 0; i < 9; i++)
		base[i] = obj.base[i];
}
*/
RMatrix RMatrix::operator*(const RMatrix& other)
{
	RMatrix temp(*this);
	temp *= other;
	return temp;
}

RMatrix& RMatrix::operator*=(const RMatrix& other)
{
	// TODO: 在此处插入 return 语句
	RMatrix temp(*this);
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			base[i * col + j] = temp.base[i * col + 0] * other.base[0 * col + j] + temp.base[i * col + 1] * other.base[1 * col + j] 
			+ temp.base[i * col + 2] * other.base[2 * col + j];
	return *this;
}

Vector RMatrix::operator*(const Vector& v)
{
	float x = base[0] * v.x + base[1] * v.y + base[2] * v.z,
		y = base[3] * v.x + base[4] * v.y + base[5] * v.z,
		z = base[6] * v.x + base[7] * v.y + base[8] * v.z;
	return Vector(x , y , z);
}

std::ostream& operator<<(std::ostream& out, const Vector& V)
{
	// TODO: 在此处插入 return 语句
	out << '(' << V.x << ',' << V.y << ',' << V.z << ')';
	return out;
}
