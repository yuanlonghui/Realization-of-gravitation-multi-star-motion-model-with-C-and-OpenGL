#include "FSM.h"
#include<iostream>
#define _DEBUG_
int FSM::nextState(char ch)
{
	int flag = 0;
	switch (ch) {
	case 'u': state = transition[state][u]; break;
	case 'n': state = transition[state][n]; break;
	case 's': state = transition[state][s]; break;
	case 't': state = transition[state][t]; break;
	case 'a': state = transition[state][a]; break;
	case 'b': state = transition[state][b]; break;
	case 'l': state = transition[state][l]; break;
	case 'e': state = transition[state][e]; break;
	case 'y': state = transition[state][y]; break;
	case 'o': state = transition[state][o]; break;
	case '1': state = transition[state][one]; break;
	case '2': state = transition[state][two]; break;
	case '3': state = transition[state][three]; break;
	case '4': state = transition[state][four]; break;
	case '5': state = transition[state][five]; break;
	case '6': state = transition[state][six]; break;
	case '7': state = transition[state][seven]; break;
	case '+': state = transition[state][up]; break;
	case '-': state = transition[state][down]; break;
	default: state = transition[state][other]; break;
	}
	switch (state) {
	case 20: {
		flag = 1;
		stable = false;
		select = 1;
		state = 0;
		break;
	}
	case 21: {
		flag = 1;
		stable = false;
		select = 2;
		state = 0;
		break;
	}
	case 22: {
		flag = 1;
		stable = false;
		select = 3;
		state = 0;
		break;
	}
	case 23: {
		flag = 1;
		stable = false;
		select = 4;
		state = 0;
		break;
	}
	case 24: {
		flag = 1;
		stable = false;
		select = 5;
		state = 0;
		break;
	}
	case 25: {
		flag = 1;
		stable = false;
		select = 6;
		state = 0;
		break;
	}
	case 34: {
		flag = 1;
		stable = false;
		select = 7;
		state = 0;
		break;
	}
	case 26: {
		flag = 1;
		stable = true;
		select = 1;
		state = 0;
		break;
	}
	case 27: {
		flag = 1;
		stable = true;
		select = 2;
		state = 0;
		break;
	}
	case 28: {
		flag = 1;
		stable = true;
		select = 3;
		state = 0;
		break;
	}
	case 29: {
		flag = 1;
		stable = true;
		select = 4;
		state = 0;
		break;
	}
	case 30: {
		flag = 1;
		stable = true;
		select = 5;
		state = 0;
		break;
	}
	case 31: {
		flag = 1;
		stable = true;
		select = 6;
		state = 0;
		break;
	}
	case 35: {
		flag = 1;
		stable = true;
		select = 7;
		state = 0;
		break;
	}
	case 17: {
		attenuation = true;
		state = 0;
		break;
	}
	case 19: {
		attenuation = false;
		state = 0;
		break;
	}
	case 32: {
		factor /= 1.5;
		state = 0;
		break;
	}
	case 33: {
		factor *= 1.5;
		state = 0;
		break;
	}
	default: break;
	}
#ifndef _DEBUG_
	std::cout << "state : " << state << " attenuation : " << attenuation << " stable : " << stable << " select : " << select << " factor : " << factor << std::endl;
#endif
	return flag;
}

int FSM::u = 0;
int FSM::n = 1;
int FSM::s = 2;
int FSM::t = 3;
int FSM::a = 4;
int FSM::b = 5;
int FSM::l = 6;
int FSM::e = 7;
int FSM::y = 8;
int FSM::o = 9;
int FSM::one = 10;
int FSM::two = 11;
int FSM::three = 12;
int FSM::four = 13;
int FSM::five = 14;
int FSM::six = 15;
int FSM::other = 16;
int FSM::up = 17;
int FSM::down = 18;
int FSM::seven = 19;
int FSM::transition[36][20] = {
	1 , 18 , 9 , 0 , 0 , 0 , 0 , 0 , 15 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 32 , 33 , 0 ,
	0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 7 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 20 , 21 , 22 , 23 , 24 , 25 , 0, 0 , 0 , 34 ,
	0 , 0 , 0 , 10 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 11 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 12 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 13 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 14 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 26 , 27 , 28 , 29 , 30 , 31 , 0, 0 , 0 , 35 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 17 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 19 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 ,
	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 , 0 , 0 
};