#ifndef _SYSTEM_
#define _SYSTEM_
#include "matrix.h"
#include<ostream>

const float K = 1.0f;


class Ball {
private:
	Vector o,//球心
		f,//受力
		v,
		material;//速度
	float m, //质量
		r;//半径
	bool light;
public :
	Ball();
	Ball(const Vector& _o, const Vector& _f, const Vector& _v , const Vector& _material, float _m, float _r , bool _light); 
	void Draw();
	float distance(const Ball& b);
	Vector force(const Ball& b);
	void translateto(const Vector& _do);
	void clearforce();
	void addforce(const Vector& _df);
	void addvelocity(const Vector& _dv);
	void nextPosition(Vector& temppoistion, float dt);

	Vector O();
	Vector F();
	Vector V();
	float M();
	float R();
	bool L();
};


struct System {
	int n;
	Ball* balls;
	System();
	System(int _n, const Ball* _balls);
	System(const System& s);
	void simulate();
	System& operator= (const System& s);

	~System();
};

void recall(Ball& bone, Vector& tpone, Ball& btwo, Vector& tptwo, float low, float high, float top);

class mycamera {
private :
	Vector o, //位置
		n, //视线朝向
		v; //头朝向
public :
	mycamera();
	void reset();
	Vector eye();
	Vector center();
	Vector up();
	void forward(float step);
	void nod(float sida);
	void shade(float sida);
	friend std::ostream& operator << (std::ostream& out, const mycamera& c);
};

std::ostream& operator << (std::ostream& out, const mycamera& c);


const Ball unstable_balls1[1] = {
	Ball(
		Vector(-100 , 0 , -100),
		Vector(),
		Vector(0.5 , 0 , 0),
		Vector(1 , 0 , 0),
		1,
		5,
		false
) };
const Ball unstable_balls2[2] = {
	Ball(
		Vector(-20 , -10 , -50),
		Vector(),
		Vector(0 , 0 , 1),
		Vector(1 , 0.1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(20 , -10 , -50),
		Vector(),
		Vector(0 , 0 , -1),
		Vector(0.1 , 1 , 0.1),
		100,
		5,
		false
)
};
const Ball unstable_balls3[3] = {
	Ball(
		Vector(19.997,0,-19.997 - 80),
		Vector(),
		Vector(-0.353553,-0.5,-0.353553) * 2.5,
		Vector(1 , 0.1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(0,28.28,0 - 80),
		Vector(),
		Vector(0.707107,0,0) * 2.5,
		Vector(0.1 , 1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(19.997,0,19.997 - 80),
		Vector(),
		Vector(-0.353553,0.5,0.353553) * 2.5,
		Vector(0.1 , 0.1 , 1),
		100,
		5,
		false
)
};
const Ball unstable_balls4[4] = {
	Ball(
		Vector(-40 , 0 , 0 - 80),
		Vector(),
		Vector(0 , 0 , 1.25),
		Vector(1 , 0.1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(40 , 0 , 0 - 80),
		Vector(),
		Vector(0 , 0 , -1.25),
		Vector(0.1 , 1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(0 , 0 , 40 - 80),
		Vector(),
		Vector(0 , -1.25 , 0),
		Vector(0.1 , 0.1 , 1),
		100,
		5,
		false
),
	Ball(
		Vector(0 , 0 , -40 - 80),
		Vector(),
		Vector(0 , 1.25 , 0),
		Vector(0.5 , 0.5 , 0.5),
		100,
		5,
		false
)
};
const Ball unstable_balls5[5] = {
	Ball(
		Vector(-80 , 0 , 0 - 80),
		Vector(),
		Vector(0 , 0 , 2),
		Vector(1 , 0.1 , 0.1),
		10,
		4,
		false
),
	Ball(
		Vector(80 , 0 , 0 - 80),
		Vector(),
		Vector(0 , 0 , -2),
		Vector(0.1 , 1 , 0.1),
		30,
		4,
		false
),
	Ball(
		Vector(0 , 0 , 80 - 80),
		Vector(),
		Vector(0 , -2 , 0),
		Vector(0.1 , 0.1 , 1),
		30,
		4,
		false
),
	Ball(
		Vector(0 , 0 , -80 - 80),
		Vector(),
		Vector(0 , 2 , 0),
		Vector(1 , 1 , 1),
		30,
		4,
		false
),
	Ball(
		Vector(0 , 0 , 0 - 80),
		Vector(),
		Vector(0 , 0 , 0),
		Vector(0.3 , 0.4 , 0.5),
		800,
		10,
		false
)
};
const Ball unstable_balls6[6] = {
	Ball(
		Vector(20 + 20 , -20 , 0 - 200),
		Vector(),
		Vector(0 , 0 , 9),
		Vector(1 , 0.1 , 0.1),
		1,
		4,
		false
),
	Ball(
		Vector(-40 - 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , -9),
		Vector(0.1 , 1 , 0.1),
		3,
		4,
		false
),
	Ball(
		Vector(60 + 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , 6),
		Vector(0.1 , 0.1 , 1),
		3,
		4,
		false
),
	Ball(
		Vector(-80 - 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , -6),
		Vector(1 , 1 , 1),
		3,
		4,
		false
),
	Ball(
		Vector(100 + 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , 6),
		Vector(0.3 , 0.4 , 0.5),
		3,
		4,
		false
),
	Ball(
		Vector(0 , 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , 0),
		Vector(0.3 , 0.4 , 0.5),
		4000,
		10,
		false
)
};
const Ball unstable_balls7[7] = {
	Ball(
		Vector(20 + 20 , -20 , 0 - 200),
		Vector(),
		Vector(0 , 0 , 9),
		Vector(1 , 0.1 , 0.1),
		1,
		4,
		false
),
	Ball(
		Vector(120 + 20 , -20 , 0 - 200),
		Vector(),
		Vector(0 , 0 , 5),
		Vector(1 , 0.1 , 0.1),
		1,
		4,
		false
),
	Ball(
		Vector(-40 - 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , -9),
		Vector(0.1 , 1 , 0.1),
		3,
		4,
		false
),
	Ball(
		Vector(60 + 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , 6),
		Vector(0.1 , 0.1 , 1),
		3,
		4,
		false
),
	Ball(
		Vector(-80 - 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , -6),
		Vector(1 , 1 , 1),
		3,
		4,
		false
),
	Ball(
		Vector(100 + 20, 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , 6),
		Vector(0.3 , 0.4 , 0.5),
		3,
		4,
		false
),
	Ball(
		Vector(0 , 0 - 20, 0 - 200),
		Vector(),
		Vector(0 , 0 , 0),
		Vector(0.3 , 0.4 , 0.5),
		4000,
		10,
		false
)
};

const System unstable_S[7] = {
	System(1, unstable_balls1) , 
	System(2, unstable_balls2) , 
	System(3, unstable_balls3) , 
	System(4, unstable_balls4) , 
	System(5, unstable_balls5) ,
	System(6, unstable_balls6) ,
	System(7, unstable_balls7)
};

const Ball stable_balls1[1] = {
	Ball(
		Vector(0 , 0 , -50),
		Vector(),
		Vector(0 , 0 , 0),
		Vector(1 , 0 , 0),
		1,
		5,
		false
) };
const Ball stable_balls2[2] = {
	Ball(
		Vector(-20 , -10 , -50),
		Vector(),
		Vector(0 , 0 , 1),
		Vector(1 , 0.1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(20 , -10 , -50),
		Vector(),
		Vector(0 , 0 , -1),
		Vector(0.1 , 1 , 0.1),
		100,
		5,
		false
)
};
const Ball stable_balls3[3] = {
	Ball(
		Vector(0, 0-20, 23.1 * 3 -190),
		Vector(),
		Vector(1, 0, 0) * 2.0 ,
		Vector(1 , 0.1 , 0.1),
		400,
		15,
		false
),
	Ball(
		Vector(-20.0052 * 3,0-20,-11.55 * 3 - 190),
		Vector(),
		Vector(-0.5,0,0.866025) * 2.0,
		Vector(0.1 , 1 , 0.1),
		400,
		15,
		false
),
	Ball(
		Vector(20.0052 * 3,0-20,-11.55 * 3 -190),
		Vector(),
		Vector(-0.5,0,-0.866025) * 2.0,
		Vector(0.1 , 0.1 , 1),
		400,
		15,
		false
)
};
const Ball stable_balls4[4] = {
	Ball(
		Vector(-40 , 0 - 20 , 0 - 60),
		Vector(),
		Vector(0 , 0 , -1.25),
		Vector(1 , 0.1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(0 , 0 - 20 , -40 - 60),
		Vector(),
		Vector(1.25 , 0 , 0),
		Vector(0.1 , 1 , 0.1),
		100,
		5,
		false
),
	Ball(
		Vector(40 , 0-20 , 0 - 60),
		Vector(),
		Vector(0 , 0 , 1.25),
		Vector(0.1 , 0.1 , 1),
		100,
		5,
		false
),
	Ball(
		Vector(0 , 0 - 20 , 40 - 60),
		Vector(),
		Vector(-1.25 ,0 , 0),
		Vector(0.5 , 0.5 , 0.5),
		100,
		5,
		false
)
};
const Ball stable_balls5[5] = {
	Ball(
		Vector(0, 0-20, 23.1*2-100),
		Vector(),
		Vector(1, 0, 0),
		Vector(1 , 0.1 , 0.1),
		50,
		5,
		false
),
	Ball(
		Vector(-21.9694 * 2,0 - 20,7.13829 * 2 - 100),
		Vector(),
		Vector(0.309017,0,0.951057),
		Vector(0.1 , 1 , 0.1),
		50,
		5,
		false
),
	Ball(
		Vector(-13.5778 * 2,-0 - 20,-18.6883 * 2 - 100),
		Vector(),
		Vector(-0.809017,0,0.587785),
		Vector(0.1 , 0.1 , 1),
		50,
		5,
		false
),
	Ball(
		Vector(13.5778 * 2,-0 - 20,-18.6883 * 2 - 100),
		Vector(),
		Vector(-0.809017,0,-0.587785),
		Vector(1 , 1 , 1),
		50,
		5,
		false
),
	Ball(
		Vector(21.9694 * 2,-0 - 20,7.1383 * 2 - 100),
		Vector(),
		Vector(0.309017,-0,-0.951056),
		Vector(0.3 , 0.4 , 0.5),
		50,
		5,
		false
)
};
const Ball stable_balls6[6] = {
	Ball(
		Vector(40 * 2.5 , 0 , 0 - 180),
		Vector(),
		Vector(0 , 1 , 0) * 1.75,
		Vector(1 , 0.1 , 0.1),
		200,
		10,
		false
),
	Ball(
		Vector(0,0, -40 * 2.5 - 180),
		Vector(),
		Vector(-1 , 0 ,0) * 1.75,
		Vector(0.1 , 1 , 0.1),
		200,
		10,
		false
),
	Ball(
		Vector(-40 * 2.5, 0,0 - 180),
		Vector(),
		Vector(0 , -1 , 0) * 1.75,
		Vector(0.1 , 0.1 , 1),
		200,
		10,
		false
),
	Ball(
		Vector(0, 0, 40 * 2.5 - 180),
		Vector(),
		Vector(1 , 0 , 0) * 1.75,
		Vector(1 , 1 , 1),
		200,
		10,
		false
),
	Ball(
		Vector(0, 40 * 2.5, 0 - 180),
		Vector(),
		Vector(0 , 0 ,1) * 1.75,
		Vector(0.3 , 0.4 , 0.5),
		200,
		10,
		false
),
	Ball(
		Vector(0 ,-40 * 2.5, 0 - 180),
		Vector(),
		Vector(0 , 0 , -1) * 1.75,
		Vector(0.3 , 0.4 , 0.5),
		200,
		10,
		false
),
};
const Ball stable_balls7[7] = {
	Ball(
		Vector(40*3 , 0 , 0-180),
		Vector(),
		Vector(0 , 1 , 0)* 3.5,
		Vector(1 , 0.1 , 0.1),
		15,
		10,
		false
),
	Ball(
		Vector(0,0, -40 * 3 - 180),
		Vector(),
		Vector(-1 , 0 ,0) * 3.5,
		Vector(0.1 , 1 , 0.1),
		15,
		10,
		false
),
	Ball(
		Vector(-40 * 3, 0,0 - 180),
		Vector(),
		Vector(0 , -1 , 0) * 3.5,
		Vector(0.1 , 0.1 , 1),
		15,
		10,
		false
),
	Ball(
		Vector(0, 0, 40 * 3 - 180),
		Vector(),
		Vector(1 , 0 , 0) * 3.5,
		Vector(1 , 1 , 1),
		15,
		10,
		false
),
	Ball(
		Vector(0, 40 * 3, 0 - 180),
		Vector(),
		Vector(0 , 0 ,1) * 3.5,
		Vector(0.3 , 0.4 , 0.5),
		15,
		10,
		false
),
	Ball(
		Vector(0 ,-40 * 3, 0 - 180),
		Vector(),
		Vector(0 , 0 , -1) * 3.5,
		Vector(0.3 , 0.4 , 0.5),
		15,
		10,
		false
),
	Ball(
		Vector(0 ,0, 0 - 180),
		Vector(),
		Vector(0 , 0 , 0) ,
		Vector(0.3 , 0.4 , 0.5),
		2000,
		20,
		false
)
};

const System stable_S[7] = {
	System(1, stable_balls1) ,
	System(2, stable_balls2) ,
	System(3, stable_balls3) ,
	System(4, stable_balls4) ,
	System(5, stable_balls5) ,
	System(6, stable_balls6) ,
	System(7, stable_balls7)
};

#endif
