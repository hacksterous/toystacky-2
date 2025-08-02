################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/TS-core-fn1Param.c \
../Core/Src/TS-core-fnOrOp2Param.c \
../Core/Src/TS-core-fnOrOpMat1Param.c \
../Core/Src/TS-core-fnOrOpMat2Param.c \
../Core/Src/TS-core-fnOrOpVec1Param.c \
../Core/Src/TS-core-fnOrOpVec2Param.c \
../Core/Src/TS-core-ledger.c \
../Core/Src/TS-core-llist.c \
../Core/Src/TS-core-math.c \
../Core/Src/TS-core-numString.c \
../Core/Src/TS-core-process.c \
../Core/Src/TS-core-processDefaultPush.c \
../Core/Src/TS-core-processPop.c \
../Core/Src/TS-core-stack.c \
../Core/Src/TS-core-tokenize.c \
../Core/Src/bigint.c \
../Core/Src/day.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/ts2.c \
../Core/Src/yasML.c 

OBJS += \
./Core/Src/TS-core-fn1Param.o \
./Core/Src/TS-core-fnOrOp2Param.o \
./Core/Src/TS-core-fnOrOpMat1Param.o \
./Core/Src/TS-core-fnOrOpMat2Param.o \
./Core/Src/TS-core-fnOrOpVec1Param.o \
./Core/Src/TS-core-fnOrOpVec2Param.o \
./Core/Src/TS-core-ledger.o \
./Core/Src/TS-core-llist.o \
./Core/Src/TS-core-math.o \
./Core/Src/TS-core-numString.o \
./Core/Src/TS-core-process.o \
./Core/Src/TS-core-processDefaultPush.o \
./Core/Src/TS-core-processPop.o \
./Core/Src/TS-core-stack.o \
./Core/Src/TS-core-tokenize.o \
./Core/Src/bigint.o \
./Core/Src/day.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/ts2.o \
./Core/Src/yasML.o 

C_DEPS += \
./Core/Src/TS-core-fn1Param.d \
./Core/Src/TS-core-fnOrOp2Param.d \
./Core/Src/TS-core-fnOrOpMat1Param.d \
./Core/Src/TS-core-fnOrOpMat2Param.d \
./Core/Src/TS-core-fnOrOpVec1Param.d \
./Core/Src/TS-core-fnOrOpVec2Param.d \
./Core/Src/TS-core-ledger.d \
./Core/Src/TS-core-llist.d \
./Core/Src/TS-core-math.d \
./Core/Src/TS-core-numString.d \
./Core/Src/TS-core-process.d \
./Core/Src/TS-core-processDefaultPush.d \
./Core/Src/TS-core-processPop.d \
./Core/Src/TS-core-stack.d \
./Core/Src/TS-core-tokenize.d \
./Core/Src/bigint.d \
./Core/Src/day.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/ts2.d \
./Core/Src/yasML.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/TS-core-fn1Param.cyclo ./Core/Src/TS-core-fn1Param.d ./Core/Src/TS-core-fn1Param.o ./Core/Src/TS-core-fn1Param.su ./Core/Src/TS-core-fnOrOp2Param.cyclo ./Core/Src/TS-core-fnOrOp2Param.d ./Core/Src/TS-core-fnOrOp2Param.o ./Core/Src/TS-core-fnOrOp2Param.su ./Core/Src/TS-core-fnOrOpMat1Param.cyclo ./Core/Src/TS-core-fnOrOpMat1Param.d ./Core/Src/TS-core-fnOrOpMat1Param.o ./Core/Src/TS-core-fnOrOpMat1Param.su ./Core/Src/TS-core-fnOrOpMat2Param.cyclo ./Core/Src/TS-core-fnOrOpMat2Param.d ./Core/Src/TS-core-fnOrOpMat2Param.o ./Core/Src/TS-core-fnOrOpMat2Param.su ./Core/Src/TS-core-fnOrOpVec1Param.cyclo ./Core/Src/TS-core-fnOrOpVec1Param.d ./Core/Src/TS-core-fnOrOpVec1Param.o ./Core/Src/TS-core-fnOrOpVec1Param.su ./Core/Src/TS-core-fnOrOpVec2Param.cyclo ./Core/Src/TS-core-fnOrOpVec2Param.d ./Core/Src/TS-core-fnOrOpVec2Param.o ./Core/Src/TS-core-fnOrOpVec2Param.su ./Core/Src/TS-core-ledger.cyclo ./Core/Src/TS-core-ledger.d ./Core/Src/TS-core-ledger.o ./Core/Src/TS-core-ledger.su ./Core/Src/TS-core-llist.cyclo ./Core/Src/TS-core-llist.d ./Core/Src/TS-core-llist.o ./Core/Src/TS-core-llist.su ./Core/Src/TS-core-math.cyclo ./Core/Src/TS-core-math.d ./Core/Src/TS-core-math.o ./Core/Src/TS-core-math.su ./Core/Src/TS-core-numString.cyclo ./Core/Src/TS-core-numString.d ./Core/Src/TS-core-numString.o ./Core/Src/TS-core-numString.su ./Core/Src/TS-core-process.cyclo ./Core/Src/TS-core-process.d ./Core/Src/TS-core-process.o ./Core/Src/TS-core-process.su ./Core/Src/TS-core-processDefaultPush.cyclo ./Core/Src/TS-core-processDefaultPush.d ./Core/Src/TS-core-processDefaultPush.o ./Core/Src/TS-core-processDefaultPush.su ./Core/Src/TS-core-processPop.cyclo ./Core/Src/TS-core-processPop.d ./Core/Src/TS-core-processPop.o ./Core/Src/TS-core-processPop.su ./Core/Src/TS-core-stack.cyclo ./Core/Src/TS-core-stack.d ./Core/Src/TS-core-stack.o ./Core/Src/TS-core-stack.su ./Core/Src/TS-core-tokenize.cyclo ./Core/Src/TS-core-tokenize.d ./Core/Src/TS-core-tokenize.o ./Core/Src/TS-core-tokenize.su ./Core/Src/bigint.cyclo ./Core/Src/bigint.d ./Core/Src/bigint.o ./Core/Src/bigint.su ./Core/Src/day.cyclo ./Core/Src/day.d ./Core/Src/day.o ./Core/Src/day.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/ts2.cyclo ./Core/Src/ts2.d ./Core/Src/ts2.o ./Core/Src/ts2.su ./Core/Src/yasML.cyclo ./Core/Src/yasML.d ./Core/Src/yasML.o ./Core/Src/yasML.su

.PHONY: clean-Core-2f-Src

