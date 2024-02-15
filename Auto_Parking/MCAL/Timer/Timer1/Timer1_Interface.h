#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;

void Timer1_init(void);
void Timer1_start(void);
void Timer1_stop(void);

void Timer1_set_int_value(u16 value);
void Timer1_set_cmp_value(u16 value);

void Timer1_PWM_set_cmp(u8 duty,u32 freq);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);

void Timer1_OV_InterruptEnable(void);
void Timer1_OV_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);

void Timer1_OV_set_callbck(void (*p2f_var)(void));
void Timer1_OCA_set_callbck(void (*p2f_var)(void));
void Timer1_OCB_set_callbck(void (*p2f_var)(void));
void Timer1_ICU_set_callbck(void (*p2f_var)(void));

#endif /* TIMER1_INTERFACE_H_ */
