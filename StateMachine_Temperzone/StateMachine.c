#include<stdio.h>
#include<conio.h>
#include"StateMachine.h"

void STATE_0 (){
    current_state = 0 ;
    printf("\nCurrent State 0 ");}

void STATE_1 (){
    current_state = 1 ;
    printf("\nCurrent State 1 ");

    }
void STATE_2 (){
    current_state = 2 ;
    printf("\nCurrent State 2 ");
    }

void STATE_3 (){
    current_state = 3 ;
    printf("\nCurrent State 3 ");
    }

int set_state(int inputSignal)
{  printf("\nPrevious State was %d",current_state);
    switch (current_state)
    {
    case 0: if ( (inputSignal>= B_Input) & (inputSignal< D_Input))
            STATE_1 ();
            else if ( (inputSignal>= D_Input) & (inputSignal< F_Input))
            STATE_2 ();
            else if (inputSignal>= F_Input)
            STATE_3 ();
            else
            printf("\nNO State Change");
            break;

    case 1: if ( (inputSignal>= D_Input)& (inputSignal< F_Input))
            STATE_2 ();
            else if ( inputSignal>= F_Input)
            STATE_3 ();
            else if ( inputSignal< A_Input)
            STATE_0 ();
            else
            printf("\nNO State Change");
            break;

    case 2: if ( inputSignal>= F_Input)
            STATE_3 ();
            else if ( (inputSignal < C_Input)& (inputSignal >= A_Input))
            STATE_1 ();
            else if ( inputSignal < A_Input)
            STATE_0 ();
            else
            printf("\nNO State Change");
            break;

    case 3: if ( (inputSignal < E_Input)& (inputSignal >= C_Input))
            STATE_2 ();
            else if ( (inputSignal < C_Input)& (inputSignal >= A_Input))
            STATE_1 ();
            else if ((inputSignal < A_Input))
            STATE_0 ();
            else
            printf("\nNO State Change");
            break;

    default:
        //error
        printf("\n Undefined Action %d",current_state);
        break;
    }
return current_state;
}

int main()
{
    int EnterInput = 0;
    while(1){
        printf("\nEnter a input range 0-1000: ");
        scanf("%d",&EnterInput);
        while (!((EnterInput <1000) & (EnterInput > 0))){
            printf("\nInvalid Input! Enter a input range 0-1000: ");
            scanf("%d",&EnterInput);
        }
        set_state(EnterInput);
    }
    return 0;
}
