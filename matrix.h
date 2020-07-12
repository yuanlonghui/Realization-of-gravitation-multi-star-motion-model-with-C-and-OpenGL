/*
����һ��ͷ�ļ�
��������ת�����ͷ�ļ�
*/
#ifndef _MATRIX_
#define _MATRIX_
#include<ostream>

#define OK 1
#define ERROR 0
#define accuracy 1e-6
#define PI 3.14159265358979

typedef int Status; //��������״̬
class RMatrix;
class Vector;

class Vector {
private:
	float x, y, z;//��ά�ռ���������
	friend class RMatrix;

public:
	Vector();
	Vector(float _x, float _y, float _z);
	Vector(const Vector& V);//�������캯��
	float X() const;
	float Y() const;
	float Z() const;//�ֱ𷵻����������ֵ

	void clear();
	Vector& operator = (const Vector& V);//����

	Vector operator^ (const Vector& V); //���

	float operator * (const Vector& V) const;

	Vector operator-(const Vector& V) const;

	Vector operator + (const Vector& V) const;
	Vector& operator += (const Vector& V);

	Vector operator * (float power) const;
	Vector& operator *= (float power);

	Status Rotate(const Vector& n , float angle);//��ת������ת

	Status Translate(float dx, float dy, float dz);
	Status Normalize();//��λ��
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
	RMatrix(char axis, float sida);//������X��Y��Z�����ת����
//	RMatrix(const RMatrix& obj);
	RMatrix operator* (const RMatrix& other);
	RMatrix& operator*= (const RMatrix& other);
	Vector operator* (const Vector& v);


};



#endif //!_MATRIX_