#pragma once
class FSM {
public:
	static int u, n, s, t, a, b, l, e, y, o,
		one, two, three, four, five, six, other, up, down , seven;
	static int transition[36][20];
	bool attenuation, stable;
	int select;
	int state;
	float factor;
	FSM() : attenuation(false), stable(false), select(1), state(0) , factor(0.0005){}
	int nextState(char ch);
};



