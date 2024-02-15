#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO/DIO_Inteface.h"
#include "Timer/Timer1/Timer1_Interface.h"
#include "UltraSonic_Interface.h"
#include "UltraSonic/UltraSonic_Cfg.h"

static u16 t1,t2,time;
static u8 ov,flag;

static void ICU_fun()
{
	if(flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if(flag==1)
	{
		t2=ICR1;
		Timer1_ICU_InterruptDisable();
		flag=2;
	}
}

static void ov_fun()
{
	ov++;
}

void US_init(void)
{
	Timer1_init();
	Timer1_ICU_set_callbck(ICU_fun);
	Timer1_OV_set_callbck(ov_fun);
	Timer1_OV_InterruptEnable();
}

void US_get_distance(US_t us,u8 *d)
{
	Timer1_start();
	Timer1_set_int_value(0);
	switch (us) {
		case US_1:
		{
			DIO_WritePin(US_1_PIN,HIGH);
			_delay_us(10);
			DIO_WritePin(US_1_PIN,LOW);
		}
		break;

		case US_2:
		{
			DIO_WritePin(US_2_PIN,HIGH);
			_delay_us(10);
			DIO_WritePin(US_2_PIN,LOW);
		}
		break;

		case US_3:
		{
			DIO_WritePin(US_3_PIN,HIGH);
			_delay_us(10);
			DIO_WritePin(US_3_PIN,LOW);
		}
		break;

		case US_4:
		{
			DIO_WritePin(US_4_PIN,HIGH);
			_delay_us(10);
			DIO_WritePin(US_4_PIN,LOW);
		}
		break;

		default:
			break;
	}
	flag=0;
	Timer1_ICU_InterruptEnable();
	Timer1_InputCaptureEdge(RISING);
	while(flag<2);
	time=(t2-t1)+(65536*ov);
	*d=time/58;
	Timer1_stop();
	_delay_ms(25);
}
