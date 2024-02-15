################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/DCM_Test/DCM.c 

OBJS += \
./APP/DCM_Test/DCM.o 

C_DEPS += \
./APP/DCM_Test/DCM.d 


# Each subdirectory must supply rules for building sources it contributes
APP/DCM_Test/%.o: ../APP/DCM_Test/%.c APP/DCM_Test/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\APP" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\CFG" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\HAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\MCAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\SERVICES" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


