################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CFG/DIO/DIO_Cfg.c 

OBJS += \
./CFG/DIO/DIO_Cfg.o 

C_DEPS += \
./CFG/DIO/DIO_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
CFG/DIO/%.o: ../CFG/DIO/%.c CFG/DIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\APP" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\CFG" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\HAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\MCAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\SERVICES" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


