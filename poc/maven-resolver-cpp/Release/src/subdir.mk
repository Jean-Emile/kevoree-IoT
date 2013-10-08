################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MavenArtefact.cpp \
../src/MavenResolver.cpp \
../src/MavenVersionResolver.cpp \
../src/MavenVersionResult.cpp \
../src/test.cpp 

OBJS += \
./src/MavenArtefact.o \
./src/MavenResolver.o \
./src/MavenVersionResolver.o \
./src/MavenVersionResult.o \
./src/test.o 

CPP_DEPS += \
./src/MavenArtefact.d \
./src/MavenResolver.d \
./src/MavenVersionResolver.d \
./src/MavenVersionResult.d \
./src/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	msp430-g++ -O3 -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


