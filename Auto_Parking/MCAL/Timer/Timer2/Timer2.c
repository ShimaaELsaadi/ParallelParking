#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Timer/Timer2/Timer2_Interface.h"
#include "Timer/Timer2_Cfg.h"

static void (*p2f_ov)()=NULL_PTR;
static void (*p2f_cmp)()=NULL_PTR;

void Timer2_init(void)
{
#if Timer2_mode==Normal_mode  //mode
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#elif Timer2_mode==PWM_mode
	SET_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#elif Timer2_mode==CTC_mode
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#elif Timer2_mode==Fast_PWM_mode

	#if Timer2_modeofcmp==Non_Inverting  //cmp_mode
		TCCR2|=(Non_Inverting<<4);

	#elif Timer2_modeofcmp==Inverting
		TCCR2|=(Inverting<<4);

	#endif

	SET_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#endif
	return;
}

void Timer2_start(void)
{
	TCCR2 &= 0xf8;
	TCCR2 |=Timer2_Prescaler;
	return;
}

void Timer2_stop(void)
{
	TCCR2&=0xf8;
	return;
}

void Timer2_set_int_value(u8 value)
{
	TCNT2=value;
	return ;
}

void Timer2_set_cmp_value(u8 value)
{
	OCR2=value;
	return ;
}

void Timer2_PWM_set_cmp(u8 duty)
{
	#if Timer2_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR2=(duty*resoultion/100)-1;

	return ;
}

void Timer2_PWM_set_cmp_PC (u8 duty)
{
	#if Timer2_modeofcmp==Inverting
		duty=100-duty;
	#endif

	OCR2 = ((duty*resoultion/50)-1);
	return ;
}

void Timer2_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,6);
}
void Timer2_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,6);
}
void Timer2_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,7);
}
void Timer2_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,7);
}

void Timer2_OV_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_ov=p2f_var;
	}
}

void Timer2_OC_set_callbck(void (*p2f_var)(void))
{
	if(p2f_var!=NULL_PTR)
	{
		p2f_cmp=p2f_var;
	}
}

ISR(TIMER2_OVF_vect)
{
	p2f_ov();
}

ISR(TIMER2_COMP_vect)
{
	p2f_cmp();
}
