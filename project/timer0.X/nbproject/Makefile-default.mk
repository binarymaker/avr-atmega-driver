#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c ../../source/adc.c ../../source/delay.c ../../source/gpio.c ../../source/i2c.c ../../source/interrupt-manager.c ../../source/mcu.c ../../source/timer0.c ../../source/timer1.c ../../source/usart.c ../../config/adc-cfg.c ../../config/i2c-cfg.c ../../config/pin-manager-cfg.c ../../config/timer0-cfg.c ../../config/timer1-cfg.c ../../config/usart-cfg.c ../../config/config-printf/print-cfg.c ../../library/printf/source/print.c ../../source/systimer.c ../../config/systimer-cfg.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/870914629/adc.o ${OBJECTDIR}/_ext/870914629/delay.o ${OBJECTDIR}/_ext/870914629/gpio.o ${OBJECTDIR}/_ext/870914629/i2c.o ${OBJECTDIR}/_ext/870914629/interrupt-manager.o ${OBJECTDIR}/_ext/870914629/mcu.o ${OBJECTDIR}/_ext/870914629/timer0.o ${OBJECTDIR}/_ext/870914629/timer1.o ${OBJECTDIR}/_ext/870914629/usart.o ${OBJECTDIR}/_ext/1329200926/adc-cfg.o ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o ${OBJECTDIR}/_ext/1329200926/usart-cfg.o ${OBJECTDIR}/_ext/967151063/print-cfg.o ${OBJECTDIR}/_ext/1553189987/print.o ${OBJECTDIR}/_ext/870914629/systimer.o ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/_ext/870914629/adc.o.d ${OBJECTDIR}/_ext/870914629/delay.o.d ${OBJECTDIR}/_ext/870914629/gpio.o.d ${OBJECTDIR}/_ext/870914629/i2c.o.d ${OBJECTDIR}/_ext/870914629/interrupt-manager.o.d ${OBJECTDIR}/_ext/870914629/mcu.o.d ${OBJECTDIR}/_ext/870914629/timer0.o.d ${OBJECTDIR}/_ext/870914629/timer1.o.d ${OBJECTDIR}/_ext/870914629/usart.o.d ${OBJECTDIR}/_ext/1329200926/adc-cfg.o.d ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o.d ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o.d ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o.d ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o.d ${OBJECTDIR}/_ext/1329200926/usart-cfg.o.d ${OBJECTDIR}/_ext/967151063/print-cfg.o.d ${OBJECTDIR}/_ext/1553189987/print.o.d ${OBJECTDIR}/_ext/870914629/systimer.o.d ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/870914629/adc.o ${OBJECTDIR}/_ext/870914629/delay.o ${OBJECTDIR}/_ext/870914629/gpio.o ${OBJECTDIR}/_ext/870914629/i2c.o ${OBJECTDIR}/_ext/870914629/interrupt-manager.o ${OBJECTDIR}/_ext/870914629/mcu.o ${OBJECTDIR}/_ext/870914629/timer0.o ${OBJECTDIR}/_ext/870914629/timer1.o ${OBJECTDIR}/_ext/870914629/usart.o ${OBJECTDIR}/_ext/1329200926/adc-cfg.o ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o ${OBJECTDIR}/_ext/1329200926/usart-cfg.o ${OBJECTDIR}/_ext/967151063/print-cfg.o ${OBJECTDIR}/_ext/1553189987/print.o ${OBJECTDIR}/_ext/870914629/systimer.o ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o

# Source Files
SOURCEFILES=main.c ../../source/adc.c ../../source/delay.c ../../source/gpio.c ../../source/i2c.c ../../source/interrupt-manager.c ../../source/mcu.c ../../source/timer0.c ../../source/timer1.c ../../source/usart.c ../../config/adc-cfg.c ../../config/i2c-cfg.c ../../config/pin-manager-cfg.c ../../config/timer0-cfg.c ../../config/timer1-cfg.c ../../config/usart-cfg.c ../../config/config-printf/print-cfg.c ../../library/printf/source/print.c ../../source/systimer.c ../../config/systimer-cfg.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I ${DFP_DIR}\include
PACK_COMMON_OPTIONS=-B ${DFP_DIR}\gcc\dev\atmega328



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/adc.o: ../../source/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/adc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/adc.o.d" -MT "${OBJECTDIR}/_ext/870914629/adc.o.d" -MT ${OBJECTDIR}/_ext/870914629/adc.o  -o ${OBJECTDIR}/_ext/870914629/adc.o ../../source/adc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/delay.o: ../../source/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/delay.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/delay.o.d" -MT "${OBJECTDIR}/_ext/870914629/delay.o.d" -MT ${OBJECTDIR}/_ext/870914629/delay.o  -o ${OBJECTDIR}/_ext/870914629/delay.o ../../source/delay.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/gpio.o: ../../source/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/gpio.o.d" -MT "${OBJECTDIR}/_ext/870914629/gpio.o.d" -MT ${OBJECTDIR}/_ext/870914629/gpio.o  -o ${OBJECTDIR}/_ext/870914629/gpio.o ../../source/gpio.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/i2c.o: ../../source/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/i2c.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/i2c.o.d" -MT "${OBJECTDIR}/_ext/870914629/i2c.o.d" -MT ${OBJECTDIR}/_ext/870914629/i2c.o  -o ${OBJECTDIR}/_ext/870914629/i2c.o ../../source/i2c.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/interrupt-manager.o: ../../source/interrupt-manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/interrupt-manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/interrupt-manager.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/interrupt-manager.o.d" -MT "${OBJECTDIR}/_ext/870914629/interrupt-manager.o.d" -MT ${OBJECTDIR}/_ext/870914629/interrupt-manager.o  -o ${OBJECTDIR}/_ext/870914629/interrupt-manager.o ../../source/interrupt-manager.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/mcu.o: ../../source/mcu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/mcu.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/mcu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/mcu.o.d" -MT "${OBJECTDIR}/_ext/870914629/mcu.o.d" -MT ${OBJECTDIR}/_ext/870914629/mcu.o  -o ${OBJECTDIR}/_ext/870914629/mcu.o ../../source/mcu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/timer0.o: ../../source/timer0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer0.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/timer0.o.d" -MT "${OBJECTDIR}/_ext/870914629/timer0.o.d" -MT ${OBJECTDIR}/_ext/870914629/timer0.o  -o ${OBJECTDIR}/_ext/870914629/timer0.o ../../source/timer0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/timer1.o: ../../source/timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer1.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer1.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/timer1.o.d" -MT "${OBJECTDIR}/_ext/870914629/timer1.o.d" -MT ${OBJECTDIR}/_ext/870914629/timer1.o  -o ${OBJECTDIR}/_ext/870914629/timer1.o ../../source/timer1.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/usart.o: ../../source/usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/usart.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/usart.o.d" -MT "${OBJECTDIR}/_ext/870914629/usart.o.d" -MT ${OBJECTDIR}/_ext/870914629/usart.o  -o ${OBJECTDIR}/_ext/870914629/usart.o ../../source/usart.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/adc-cfg.o: ../../config/adc-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/adc-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/adc-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/adc-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/adc-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/adc-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/adc-cfg.o ../../config/adc-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/i2c-cfg.o: ../../config/i2c-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/i2c-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/i2c-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o ../../config/i2c-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o: ../../config/pin-manager-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o ../../config/pin-manager-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/timer0-cfg.o: ../../config/timer0-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/timer0-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/timer0-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o ../../config/timer0-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/timer1-cfg.o: ../../config/timer1-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/timer1-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/timer1-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o ../../config/timer1-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/usart-cfg.o: ../../config/usart-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/usart-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/usart-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/usart-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/usart-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/usart-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/usart-cfg.o ../../config/usart-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/967151063/print-cfg.o: ../../config/config-printf/print-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/967151063" 
	@${RM} ${OBJECTDIR}/_ext/967151063/print-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/967151063/print-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/967151063/print-cfg.o.d" -MT "${OBJECTDIR}/_ext/967151063/print-cfg.o.d" -MT ${OBJECTDIR}/_ext/967151063/print-cfg.o  -o ${OBJECTDIR}/_ext/967151063/print-cfg.o ../../config/config-printf/print-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1553189987/print.o: ../../library/printf/source/print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1553189987" 
	@${RM} ${OBJECTDIR}/_ext/1553189987/print.o.d 
	@${RM} ${OBJECTDIR}/_ext/1553189987/print.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1553189987/print.o.d" -MT "${OBJECTDIR}/_ext/1553189987/print.o.d" -MT ${OBJECTDIR}/_ext/1553189987/print.o  -o ${OBJECTDIR}/_ext/1553189987/print.o ../../library/printf/source/print.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/systimer.o: ../../source/systimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/systimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/systimer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/systimer.o.d" -MT "${OBJECTDIR}/_ext/870914629/systimer.o.d" -MT ${OBJECTDIR}/_ext/870914629/systimer.o  -o ${OBJECTDIR}/_ext/870914629/systimer.o ../../source/systimer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/systimer-cfg.o: ../../config/systimer-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/systimer-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/systimer-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o ../../config/systimer-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/adc.o: ../../source/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/adc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/adc.o.d" -MT "${OBJECTDIR}/_ext/870914629/adc.o.d" -MT ${OBJECTDIR}/_ext/870914629/adc.o  -o ${OBJECTDIR}/_ext/870914629/adc.o ../../source/adc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/delay.o: ../../source/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/delay.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/delay.o.d" -MT "${OBJECTDIR}/_ext/870914629/delay.o.d" -MT ${OBJECTDIR}/_ext/870914629/delay.o  -o ${OBJECTDIR}/_ext/870914629/delay.o ../../source/delay.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/gpio.o: ../../source/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/gpio.o.d" -MT "${OBJECTDIR}/_ext/870914629/gpio.o.d" -MT ${OBJECTDIR}/_ext/870914629/gpio.o  -o ${OBJECTDIR}/_ext/870914629/gpio.o ../../source/gpio.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/i2c.o: ../../source/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/i2c.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/i2c.o.d" -MT "${OBJECTDIR}/_ext/870914629/i2c.o.d" -MT ${OBJECTDIR}/_ext/870914629/i2c.o  -o ${OBJECTDIR}/_ext/870914629/i2c.o ../../source/i2c.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/interrupt-manager.o: ../../source/interrupt-manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/interrupt-manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/interrupt-manager.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/interrupt-manager.o.d" -MT "${OBJECTDIR}/_ext/870914629/interrupt-manager.o.d" -MT ${OBJECTDIR}/_ext/870914629/interrupt-manager.o  -o ${OBJECTDIR}/_ext/870914629/interrupt-manager.o ../../source/interrupt-manager.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/mcu.o: ../../source/mcu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/mcu.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/mcu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/mcu.o.d" -MT "${OBJECTDIR}/_ext/870914629/mcu.o.d" -MT ${OBJECTDIR}/_ext/870914629/mcu.o  -o ${OBJECTDIR}/_ext/870914629/mcu.o ../../source/mcu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/timer0.o: ../../source/timer0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer0.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/timer0.o.d" -MT "${OBJECTDIR}/_ext/870914629/timer0.o.d" -MT ${OBJECTDIR}/_ext/870914629/timer0.o  -o ${OBJECTDIR}/_ext/870914629/timer0.o ../../source/timer0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/timer1.o: ../../source/timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer1.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/timer1.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/timer1.o.d" -MT "${OBJECTDIR}/_ext/870914629/timer1.o.d" -MT ${OBJECTDIR}/_ext/870914629/timer1.o  -o ${OBJECTDIR}/_ext/870914629/timer1.o ../../source/timer1.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/usart.o: ../../source/usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/usart.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/usart.o.d" -MT "${OBJECTDIR}/_ext/870914629/usart.o.d" -MT ${OBJECTDIR}/_ext/870914629/usart.o  -o ${OBJECTDIR}/_ext/870914629/usart.o ../../source/usart.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/adc-cfg.o: ../../config/adc-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/adc-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/adc-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/adc-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/adc-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/adc-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/adc-cfg.o ../../config/adc-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/i2c-cfg.o: ../../config/i2c-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/i2c-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/i2c-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/i2c-cfg.o ../../config/i2c-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o: ../../config/pin-manager-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/pin-manager-cfg.o ../../config/pin-manager-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/timer0-cfg.o: ../../config/timer0-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/timer0-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/timer0-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/timer0-cfg.o ../../config/timer0-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/timer1-cfg.o: ../../config/timer1-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/timer1-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/timer1-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/timer1-cfg.o ../../config/timer1-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/usart-cfg.o: ../../config/usart-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/usart-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/usart-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/usart-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/usart-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/usart-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/usart-cfg.o ../../config/usart-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/967151063/print-cfg.o: ../../config/config-printf/print-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/967151063" 
	@${RM} ${OBJECTDIR}/_ext/967151063/print-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/967151063/print-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/967151063/print-cfg.o.d" -MT "${OBJECTDIR}/_ext/967151063/print-cfg.o.d" -MT ${OBJECTDIR}/_ext/967151063/print-cfg.o  -o ${OBJECTDIR}/_ext/967151063/print-cfg.o ../../config/config-printf/print-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1553189987/print.o: ../../library/printf/source/print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1553189987" 
	@${RM} ${OBJECTDIR}/_ext/1553189987/print.o.d 
	@${RM} ${OBJECTDIR}/_ext/1553189987/print.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1553189987/print.o.d" -MT "${OBJECTDIR}/_ext/1553189987/print.o.d" -MT ${OBJECTDIR}/_ext/1553189987/print.o  -o ${OBJECTDIR}/_ext/1553189987/print.o ../../library/printf/source/print.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/870914629/systimer.o: ../../source/systimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870914629" 
	@${RM} ${OBJECTDIR}/_ext/870914629/systimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/870914629/systimer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/870914629/systimer.o.d" -MT "${OBJECTDIR}/_ext/870914629/systimer.o.d" -MT ${OBJECTDIR}/_ext/870914629/systimer.o  -o ${OBJECTDIR}/_ext/870914629/systimer.o ../../source/systimer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1329200926/systimer-cfg.o: ../../config/systimer-cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329200926" 
	@${RM} ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../source" -I"../../config" -I"../../config/config-printf" -I"../../config/config-embclib" -I"../../library/emclib/source" -I"../../library/emclib/source/utils" -I"../../library/emclib/source/stdint" -I"../../library/printf/source" -I"../../config/config-embclib" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1329200926/systimer-cfg.o.d" -MT "${OBJECTDIR}/_ext/1329200926/systimer-cfg.o.d" -MT ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o  -o ${OBJECTDIR}/_ext/1329200926/systimer-cfg.o ../../config/systimer-cfg.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328 ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\timer0.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\timer0.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/timer0.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif