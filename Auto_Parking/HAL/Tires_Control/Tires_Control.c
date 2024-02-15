#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "Timer/Timer2/Timer2_Interface.h"
#include "Tires_Control_Interface.h"
#include "Tires_Control/Tires_Control_Cfg.h"

move_state_t state=FW;

void CarCon_Vinit(void)
{
    DIO_WritePin(MOTOR_FORWARD_PIN,LOW);
    DIO_WritePin(MOTOR_BACKWARD_PIN,LOW);
    DIO_WritePin(MOTOR_RIGHT_PIN,LOW);
    DIO_WritePin(MOTOR_LEFT_PIN,LOW);
    Timer2_init();
}

void CarCon_VMoveForward(u8 duty)
{
    Timer2_PWM_set_cmp(duty);
	Timer2_start();
    DIO_WritePin(MOTOR_FORWARD_PIN , HIGH);
    DIO_WritePin(MOTOR_BACKWARD_PIN , LOW);
    state=FW;
}

void CarCon_VMoveBackward(u8 duty)
{
    Timer2_PWM_set_cmp(duty);
	Timer2_start();
    DIO_WritePin(MOTOR_FORWARD_PIN , LOW);
    DIO_WritePin(MOTOR_BACKWARD_PIN , HIGH);
    state=BW;
}

void CarCon_VTurnRight(void)
{
	DIO_WritePin(MOTOR_RIGHT_PIN,LOW);
    DIO_WritePin(MOTOR_LEFT_PIN,HIGH);
    DIO_WritePin(MOTOR_RIGHT_PIN,HIGH);
    DIO_WritePin(MOTOR_LEFT_PIN,LOW);
}

void CarCon_VTurnRight_withAngle(u8 angle)
{
    if (angle > 0) {
        DIO_WritePin(MOTOR_LEFT_PIN,LOW);
        u8 delay_Time = angle * Time_Angle;
        DIO_WritePin(MOTOR_RIGHT_PIN,HIGH);
        _delay_ms(delay_Time);
        DIO_WritePin(MOTOR_RIGHT_PIN,LOW);
    }
    else{

    }
}

void CarCon_VTurnLeft(void)
{
	DIO_WritePin(MOTOR_RIGHT_PIN,HIGH);
    DIO_WritePin(MOTOR_LEFT_PIN,LOW);
    DIO_WritePin(MOTOR_RIGHT_PIN,LOW);
    DIO_WritePin(MOTOR_LEFT_PIN,HIGH);
}

void CarCon_VTurnLeft_withAngle(u8 angle)
{
    if (angle > 0) {
        DIO_WritePin(MOTOR_RIGHT_PIN,LOW);
        u8 delay_Time = angle * Time_Angle;
        DIO_WritePin(MOTOR_LEFT_PIN,HIGH);
       //_delay_ms(delay_Time);
       //DIO_WritePin(MOTOR_LEFT_PIN,LOW);
    }
    else{

    }
}

void CarCon_VStop_Move(void)
{
    DIO_WritePin(MOTOR_FORWARD_PIN,LOW);
    DIO_WritePin(MOTOR_BACKWARD_PIN,LOW);
    Timer2_stop();
}

void CarCon_VStop_Move_duty(void)
{
	if(state==FW)
	{
		CarCon_VMoveBackward(75);
	}
	else if(state==BW)
	{
		CarCon_VMoveForward(50);
	}
	_delay_ms(500);
    DIO_WritePin(MOTOR_FORWARD_PIN,LOW);
    DIO_WritePin(MOTOR_BACKWARD_PIN,LOW);
    Timer2_stop();
}

void CarCon_VStop_Rotate(void)
{
    DIO_WritePin(MOTOR_RIGHT_PIN,LOW);
    DIO_WritePin(MOTOR_LEFT_PIN,LOW);
}

