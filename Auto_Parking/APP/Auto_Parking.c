#include "StdTypes.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "Timer/Timer0/Timer0_Interface.h"
#include "GI/GI_Interface.h"
#include "UltraSonic/UltraSonic_Interface.h"
#include "Tires_Control/Tires_Control_Interface.h"
#include "Auto_Parking.h"

u8 us_rf,us_rb,us_f,us_b;
u8 State = STATE_0;
u8 Spot = SPOT_NOTFOUND;
static volatile u32 c;

void Auto_Parking_init(void)
{
	DIO_Init();
	GIE_Enable();
	Find_Slot_init();
}

void Auto_Parking_Runnable(void)
{
	if(Spot==SPOT_NOTFOUND)
	{
		Find_Slot_Runnable();
	}
	else if(Spot==SPOT_FOUND)
	{
		Parking_Runnable();
	}
	else if(Spot==Car_Parked)
	{

	}
}

void fun1(void)
{
	c++;
}

void Find_Slot_init(void)
{
	Timer0_init();
	Timer0_OC_InterruptEnable();
	Timer0_OC_set_callbck(fun1);
	Timer0_set_cmp_value(250);
	US_init();
	CarCon_Vinit();
	while(DIO_ReadPin(BUTTON_PIN)==1);
}

void Car_Adjust(void)
{
	US_get_distance(US_1,&us_rf);
	if(us_rf>Adjust_Distance)
	{
		CarCon_VTurnLeft();
		CarCon_VMoveForward(50);
	}
	while(us_rf>Adjust_Distance)
	{
		US_get_distance(US_1,&us_rf);
	}

	US_get_distance(US_2,&us_rb);
	if(us_rb>(Adjust_Distance+2))
	{
		CarCon_VTurnRight();
	}
	while(us_rb>(Adjust_Distance+2))
	{
		US_get_distance(US_2,&us_rb);
	}
	CarCon_VStop_Move();
	CarCon_VStop_Rotate();
}

void Find_Slot_Runnable(void)
{
	switch (State) {
		case STATE_0:
		{
			Car_Adjust();
			State=STATE_1;
			CarCon_VMoveForward(65);
		}
		break;

		case STATE_1:
		{
			US_get_distance(US_1,&us_rf);
			if(us_rf>MIN_DISTANCE)
			{
				State=STATE_2;
			}
		}
		break;

		case STATE_2:
		{
			Timer0_start();
			while(c<2000)
			{
				if(c%400==0)
				{
					US_get_distance(US_1,&us_rf);
					if(us_rf<=MIN_DISTANCE)
						{
							State=STATE_1;
							break;
						}
				}
			}
			Timer0_stop();
			c=0;
			if(State!=STATE_1)
			{
				Spot = SPOT_FOUND;
			}
		}
		break;

		default:
		break;
	}
}

void fun2(void)
{
	c++;
	if((c%3000)==0)
	{
		DIO_TogglePin(LED_PIN);
	}
}

void Park_Finish(void)
{
	do{
		{
			US_get_distance(US_1,&us_rf);
			if(us_rf>Park_Distance)
			{
				CarCon_VTurnLeft();
				CarCon_VMoveForward(65);
			}

			do{
				US_get_distance(US_3,&us_f);
				US_get_distance(US_1,&us_rf);
				}while((us_f>Front_Distance)&&(us_rf>Park_Distance));

			US_get_distance(US_2,&us_rb);
			if(us_rb>Park_Distance)
			{
				CarCon_VTurnRight();
			}

			do{
				US_get_distance(US_3,&us_f);
				US_get_distance(US_2,&us_rb);
				}while((us_f>Front_Min)&&(us_rb>Park_Distance+1));

			CarCon_VMoveBackward(65);
			_delay_ms(100);
			CarCon_VStop_Move();
		}

		{
			US_get_distance(US_2,&us_rb);
			if(us_rb>Park_Distance)
			{
				CarCon_VTurnLeft();
				CarCon_VMoveBackward(65);
			}

			do{
				US_get_distance(US_4,&us_b);
				US_get_distance(US_2,&us_rb);
				}while((us_b>Front_Distance)&&(us_rb>Park_Distance));

			US_get_distance(US_1,&us_rf);
			if(us_rf>Park_Distance)
			{
				CarCon_VTurnRight();
			}

			do{
				US_get_distance(US_4,&us_b);
				US_get_distance(US_1,&us_rf);
				}while((us_b>Front_Min)&&(us_rf>Park_Distance+1));

			CarCon_VMoveBackward(65);
			_delay_ms(100);
			CarCon_VStop_Move();

			US_get_distance(US_1,&us_rf);
			US_get_distance(US_2,&us_rb);
			}
		}while((us_rf>Park_Distance)||(us_rb>Park_Distance)||(((us_rf-us_rb)>=6)&&((us_rb-us_rf)>=6)));

	CarCon_VStop_Rotate();
	if(us_rb>Adjust_Distance)
	{
		CarCon_VMoveBackward(55);
	}
	while(us_b>12)
	{
		US_get_distance(US_4,&us_b);
	}
	CarCon_VStop_Move();
}

void Parking_Runnable(void)
{
	Timer0_start();
	c=0;
	do{
		US_get_distance(US_2,&us_rb);
		}while((us_rb>10)&&(c<1000));
	Timer0_stop();
	c=0;

	CarCon_VStop_Move_duty();
	_delay_ms(30);
	CarCon_VTurnRight();
	_delay_ms(50);
	CarCon_VTurnLeft();
	c=0;
	Timer0_OC_set_callbck(fun2);
	Timer0_start();
	DIO_WritePin(LED_PIN,HIGH);

	CarCon_VMoveBackward(65);
	do{
		US_get_distance(US_4,&us_b);
	}while (us_b > 35 );

	CarCon_VTurnRight();
	do{
		US_get_distance(US_4,&us_b);
	}while (us_b > 7);

	CarCon_VMoveForward(50);
	_delay_ms(20);
	CarCon_VStop_Move();
	CarCon_VStop_Rotate();

	Park_Finish();

	Spot=Car_Parked;

	DIO_WritePin(LED_PIN,LOW);
	Timer0_stop();
	DIO_WritePin(BUZZER_PIN,HIGH);
	_delay_ms(200);
	DIO_WritePin(BUZZER_PIN,LOW);
	_delay_ms(100);
	DIO_WritePin(BUZZER_PIN,HIGH);
	_delay_ms(200);
	DIO_WritePin(BUZZER_PIN,LOW);
}
