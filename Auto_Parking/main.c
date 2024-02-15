#include "Auto_Parking.h"

int main(void)
{
	Auto_Parking_init();

	while(1)
	{
		Auto_Parking_Runnable();
	}
}
