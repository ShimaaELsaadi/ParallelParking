#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/Timer1/Timer1_Interface.h"
#include "Timer/Timer1_Cfg.h"

static void (*p2f_OV)()=NULL_PTR;
static void (*p2f_OCA)()=NULL_PTR;
static void (*p2f_OCB)()=NULL_PTR;
static void (*p2f_ICU)()=NULL_PTR;

void Timer1_init(void)
{
#if Timer1_mode==Normal_mode  //mode
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

#elif Timer1_mode==PWM_mode
	SET_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

#elif Timer1_mode==CTC_mode
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

#elif Timer1_mode==Fast_PWM_mode

	#if Timer1_modeofcmp==Non_Inverting  //cmp_mode
		TCCR1A|=(Non_Inverting<<6);

	#elif Timer1_modeofcmp==Inverting
		TCCR1A|=(Inverting<<6);

	#endif

		CLR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);

#endif
	return;
}

void Timer1_start(void)
{
	TCCR1B &= 0xf8;
	TCCR1B |=Timer1_Prescaler;
	return;
}

void Timer1_stop(void)
{
	TCCR1B&=0xf8;
	return;
}

void Timer1_set_int_value(u16 value)
{
	TCNT1=value;
	return ;
}

void Timer1_set_cmp_value(u16 value)
{
	OCR1A=value;
	return ;
}

void Timer1_PWM_set_cmp(u8 duty,u32 freq)
{
	#if Timer1_Prescaler==_1_prescalar  //mode
		u16 ICR1_value=(8000000/(freq))-1;

	#elif Timer1_Prescaler==_8_prescalar
		u16 ICR1_value=(1000000/(freq))-1;

	#elif Timer1_Prescaler==_64_prescalar
		u16 ICR1_value=(1000000/(freq*8))-1;

	#elif Timer1_Prescaler==_256_prescalar
		u16 ICR1_value=(1000000/(freq*32))-1;

	#elif Timer1_Prescaler==_1024_prescalar
		u16 ICR1_value=(1000000/(freq*128))-1;

#endif

		ICR1=ICR1_value;

	#if Timer1_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR1A=(duty*ICR1_value/100);

	return ;
}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,6);

	else if(edge==FALLING)
	CLR_BIT(TCCR1B,6);
}

void Timer1_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,2);
}
void Timer1_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,2);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,4);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK,4);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,3);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK,3);
}
void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,5);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK,5);
}

void Timer1_OV_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_OV=p2f_var;
	}
}

void Timer1_OCA_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_OCA=p2f_var;
	}
}

void Timer1_OCB_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_OCB=p2f_var;
	}
}

void Timer1_ICU_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_ICU=p2f_var;
	}
}

ISR(TIMER1_OVF_vect)
{
	p2f_OV();
}

ISR(TIMER1_COMPA_vect)
{
	p2f_OCB();
}

ISR(TIMER1_COMPB_vect)
{
	p2f_OCB();
}

ISR(TIMER1_CAPT_vect)
{
	p2f_ICU();
}

