#include "system.h"
#include "matrix.h"
#include <GL/freeglut.h>
#include<cmath>
#include<ostream>

GLfloat lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat lightDiffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat lightSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat EMISSION[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat Material[] = { 0.0f , 0.0f , 0.0f , 1.0f };

Ball::Ball() : o() , f() , v() , m(0) , r(1) , light(false) , material(Vector(1 , 1 , 1))
{
}

Ball::Ball(const Vector& _o, const Vector& _f, const Vector& _v, const Vector& _material, float _m, float _r , bool _light) : o(_o) ,
f(_f) , v(_v) , m(_m) , r(_r) , light(_light) , material(_material)
{
}

void Ball::Draw()
{
	if (light == true) {
		GLfloat lightPosition[] = { o.X() , o.Y() , o.Z() , 1 };
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		glPushMatrix();
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 5);
		glPopMatrix();

		glMaterialfv(GL_FRONT, GL_EMISSION, EMISSION);
	}
	Material[0] = material.X();
	Material[1] = material.Y();
	Material[2] = material.Z();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_SPECULAR, Material);
	glTranslatef(o.X(), o.Y(), o.Z());
	glutSolidSphere(r, 40, 32);
	glPopMatrix();
}

float Ball::distance(const Ball& b)
{
	return std :: sqrt(std::pow(o.X() - b.o.X() , 2) + std::pow(o.Y() - b.o.Y(), 2) + std::pow(o.Z() - b.o.Z(), 2));
}

Vector Ball::force(const Ball& b)
{
	Vector temp = b.o - o;
	temp *= K * m * b.m / (temp.R() * temp.R() * temp.R());
	return temp ;
}

void Ball::translateto(const Vector& _do)
{
	o = _do;
}

void Ball::clearforce()
{
	f = Vector();
}

void Ball::addforce(const Vector& _df)
{

	f += _df;
}

void Ball::addvelocity(const Vector& _dv)
{
	v += _dv;
}

void Ball::nextPosition(Vector& temppoistion, float dt)
{
	float ax = f.X() / m,
		ay = f.Y() / m,
		az = f.Z() / m;
	temppoistion = o + Vector(v.X() * dt + 0.5 * ax * dt * dt, v.Y() * dt
		+ 0.5 * ay * dt * dt, v.Z() * dt + 0.5 * az * dt * dt);

}

Vector Ball::O()
{
	return o;
}

Vector Ball::F()
{
	return f;
}

Vector Ball::V()
{
	return v;
}

float Ball::M()
{
	return m;
}

float Ball::R()
{
	return r;
}

bool Ball::L()
{
	return light;
}

System::System() :n(0) , balls(NULL)
{
}

System::System(int _n, const Ball* _balls) : n(_n) {
	balls = new Ball[n];
	for (int i = 0; i < n; i++)
		balls[i] = _balls[i];
}

System::System(const System& s) : n(s.n)
{
	balls = new Ball[n];
	for (int i = 0; i < n; i++)
		balls[i] = s.balls[i];
}

void System::simulate()
{
	float dt = 0.05;
	Vector* tempposition = new Vector[n];
	int i, j;
	for (i = 0; i < n; i++)
		balls[i].clearforce();
	for(i = 0 ; i < n ; i++)
		for (j = i + 1; j < n; j++) {
			Vector tempf = balls[i].force(balls[j]);
			balls[i].addforce(tempf);
			balls[j].addforce(tempf * -1.0);
		}
	for (i = 0; i < n; i++)
		balls[i].nextPosition(tempposition[i], dt);

	for (i = 0; i < n; i++)
		for (j = i + 1 ; j < n; j++) {
			Vector sub = tempposition[j] - tempposition[i];
			if (sub.R() < (balls[i].R() + balls[j].R()) * 0.99)
				recall(balls[i], tempposition[i], balls[j], tempposition[j], 0, dt, dt);
		}
	for (i = 0; i < n; i++) {
		float ax = balls[i].F().X() / balls[i].M();
		float ay = balls[i].F().Y() / balls[i].M();
		float az = balls[i].F().Z() / balls[i].M();
		balls[i].addvelocity(Vector(ax * dt, ay * dt, az * dt));
		balls[i].translateto(tempposition[i]);
	}
	delete[] tempposition;
}

System& System::operator=(const System& s)
{
	// TODO: 在此处插入 return 语句
	if (n != s.n) {
		n = s.n;
		delete[] balls;
		balls = new Ball[n];
	}
	int i;
	for (i = 0; i < n; i++)
		balls[i] = s.balls[i];
	return *this;
}

System::~System()
{
	delete[] balls;
}

void recall(Ball& bone, Vector& tpone, Ball& btwo, Vector& tptwo, float low, float high, float top)
{
	double mid = (low + high) / 2;
	double R;
	bone.nextPosition(tpone, mid);
	btwo.nextPosition(tptwo, mid);
	R = (tpone - tptwo).R();
	if (high - low < accuracy) {
		bone.translateto(tpone);
		btwo.translateto(tptwo);
		Vector temp = tptwo - tpone;
		float k = (temp * (bone.V() - btwo.V())) * 2 / (R * R * (bone.M() + btwo.M()));
		btwo.addvelocity(temp * (bone.M() * k));
		bone.addvelocity(temp * (btwo.M() * k * -1.0));
		bone.nextPosition(tpone, top - mid);
		btwo.nextPosition(tptwo, top - mid);
		return;
	}
	if (R > (bone.R() + btwo.R()) / 0.99) {
		recall(bone, tpone, btwo, tptwo, mid, high, top);
		return;
	}
	else if (R < (bone.R() + btwo.R()) * 0.99) {
		recall(bone, tpone, btwo, tptwo, low, mid, top);
		return;
	}
	else {
		bone.translateto(tpone);
		btwo.translateto(tptwo);
		Vector temp = tptwo - tpone;
		double k = (temp * (bone.V() - btwo.V())) * 2 / (R * R * (bone.M() + btwo.M()));
		btwo.addvelocity(temp * (bone.M() * k));
		bone.addvelocity(temp * (btwo.M() * k * -1.0));
		bone.nextPosition(tpone, top - mid);
		btwo.nextPosition(tptwo, top - mid);
		return;
	}
}

std::ostream& operator<<(std::ostream& out, const mycamera& c)
{
	// TODO: 在此处插入 return 语句
	out << "n ; " << c.n.X() << "   " << c.n.Y() << "   " << c.n.Z() << std :: endl
		<< "v ; " << c.v.X() << "   " << c.v.Y() << "   " << c.v.Z() ;
	return out;
}

mycamera::mycamera() : o() , n(Vector(0 , 0 , -1)) , v(Vector(0 , 1 , 0))
{
}

void mycamera::reset()
{
	o = Vector();
	n = Vector(0, 0, -1);
	v = Vector(0, 1, 0);
}

Vector mycamera::eye()
{
	return o;
}

Vector mycamera::center()
{
	return o + n ;
}

Vector mycamera::up()
{
	return v;
}

void mycamera::forward(float step)
{
	o += n * step;
}

void mycamera::nod(float sida)
{
	//sida为正时视角向上调
	Vector temp = n ^ v;
	n.Rotate(temp, sida);
	v.Rotate(temp, sida);
}

void mycamera::shade(float sida)
{
	//sida为正时，视角向左调
	n.Rotate(v, sida);
}


