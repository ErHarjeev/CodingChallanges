#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED

#define A_Input 100
#define B_Input 200
#define C_Input 300
#define D_Input 400
#define E_Input 500
#define F_Input 600

int current_state = 0;

void STATE_0();
void STATE_1();
void STATE_2();
void STATE_3();
int set_state(int inputSignal);



#endif // STATEMACHINE_H_INCLUDED
