#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/Timer0/Timer0_Interface.h"
#include "Timer/Timer0_Cfg.h"
#include "DIO/DIO_Inteface.h"

void (*p2f_ov)()=NULL_PTR;
void (*p2f_cmp)()=NULL_PTR;

void Timer0_init(void)
{
#if Timer0_mode==Normal_mode  //mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#elif Timer0_mode==PWM_mode
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#elif Timer0_mode==CTC_mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#elif Timer0_mode==Fast_PWM_mode

	#if Timer0_modeofcmp==Non_Inverting  //cmp_mode
		TCCR0|=(Non_Inverting<<4);

	#elif Timer0_modeofcmp==Inverting
		TCCR0|=(Inverting<<4);

	#endif

	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#endif
	return;
}

void Timer0_start(void)
{
	TCCR0 &= 0xf8;
	TCCR0 |=Timer0_Prescaler;
	return;
}

void Timer0_stop(void)
{
	TCCR0&=0xf8;
	return;
}

void Timer0_set_int_value(u8 value)
{
	TCNT0=value;
	return ;
}

void Timer0_set_cmp_value(u8 value)
{
	OCR0=value;
	return ;
}

void Timer0_PWM_set_cmp(u8 duty)
{
	#if Timer0_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR0=(duty*resoultion/100)-1;

	return ;
}

void Timer0_PWM_set_cmp_PC (u8 duty)
{
	#if Timer0_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR0 = ((duty*resoultion/50)-1);
	return ;
}

void Timer0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,0);
}
void Timer0_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,0);
}
void Timer0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,1);
}
void Timer0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,1);
}

void Timer0_OV_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_ov=p2f_var;
	}
}

void Timer0_OC_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_cmp=p2f_var;
	}
}

ISR(TIMER0_OVF_vect)
{
	p2f_ov();
}

ISR(TIMER0_COMP_vect)
{
	p2f_cmp();
}


