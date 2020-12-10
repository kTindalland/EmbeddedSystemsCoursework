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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
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
<<<<<<< Updated upstream
SOURCEFILES_QUOTED_IF_SPACED=SevenSeg.c Delay.c main.c ButtonDriver.c LCDPanelDriver.c RealTimeClockDriver.c ThermometerDriver.c SounderDriver.c ButtonInterface.c LCDPanelInterface.c RealTimeClockInterface.c SounderInterface.c ThermometerInterface.c HeaterConfigManager.c ModeRefreshes.c Mode.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/SevenSeg.p1 ${OBJECTDIR}/Delay.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/ButtonDriver.p1 ${OBJECTDIR}/LCDPanelDriver.p1 ${OBJECTDIR}/RealTimeClockDriver.p1 ${OBJECTDIR}/ThermometerDriver.p1 ${OBJECTDIR}/SounderDriver.p1 ${OBJECTDIR}/ButtonInterface.p1 ${OBJECTDIR}/LCDPanelInterface.p1 ${OBJECTDIR}/RealTimeClockInterface.p1 ${OBJECTDIR}/SounderInterface.p1 ${OBJECTDIR}/ThermometerInterface.p1 ${OBJECTDIR}/HeaterConfigManager.p1 ${OBJECTDIR}/ModeRefreshes.p1 ${OBJECTDIR}/Mode.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/SevenSeg.p1.d ${OBJECTDIR}/Delay.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/ButtonDriver.p1.d ${OBJECTDIR}/LCDPanelDriver.p1.d ${OBJECTDIR}/RealTimeClockDriver.p1.d ${OBJECTDIR}/ThermometerDriver.p1.d ${OBJECTDIR}/SounderDriver.p1.d ${OBJECTDIR}/ButtonInterface.p1.d ${OBJECTDIR}/LCDPanelInterface.p1.d ${OBJECTDIR}/RealTimeClockInterface.p1.d ${OBJECTDIR}/SounderInterface.p1.d ${OBJECTDIR}/ThermometerInterface.p1.d ${OBJECTDIR}/HeaterConfigManager.p1.d ${OBJECTDIR}/ModeRefreshes.p1.d ${OBJECTDIR}/Mode.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/SevenSeg.p1 ${OBJECTDIR}/Delay.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/ButtonDriver.p1 ${OBJECTDIR}/LCDPanelDriver.p1 ${OBJECTDIR}/RealTimeClockDriver.p1 ${OBJECTDIR}/ThermometerDriver.p1 ${OBJECTDIR}/SounderDriver.p1 ${OBJECTDIR}/ButtonInterface.p1 ${OBJECTDIR}/LCDPanelInterface.p1 ${OBJECTDIR}/RealTimeClockInterface.p1 ${OBJECTDIR}/SounderInterface.p1 ${OBJECTDIR}/ThermometerInterface.p1 ${OBJECTDIR}/HeaterConfigManager.p1 ${OBJECTDIR}/ModeRefreshes.p1 ${OBJECTDIR}/Mode.p1

# Source Files
SOURCEFILES=SevenSeg.c Delay.c main.c ButtonDriver.c LCDPanelDriver.c RealTimeClockDriver.c ThermometerDriver.c SounderDriver.c ButtonInterface.c LCDPanelInterface.c RealTimeClockInterface.c SounderInterface.c ThermometerInterface.c HeaterConfigManager.c ModeRefreshes.c Mode.c
=======
SOURCEFILES_QUOTED_IF_SPACED=SevenSeg.c LcdDisplay.c Delay.c main.c ButtonDriver.c ButtonInterface.c LCDPanelDriver.c LCDPanelInterface.c RealTimeClockDriver.c RealTimeClockInterface.c SounderDriver.c SounderInterface.c ThermometerDriver.c ThermometerInterface.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/SevenSeg.p1 ${OBJECTDIR}/LcdDisplay.p1 ${OBJECTDIR}/Delay.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/ButtonDriver.p1 ${OBJECTDIR}/ButtonInterface.p1 ${OBJECTDIR}/LCDPanelDriver.p1 ${OBJECTDIR}/LCDPanelInterface.p1 ${OBJECTDIR}/RealTimeClockDriver.p1 ${OBJECTDIR}/RealTimeClockInterface.p1 ${OBJECTDIR}/SounderDriver.p1 ${OBJECTDIR}/SounderInterface.p1 ${OBJECTDIR}/ThermometerDriver.p1 ${OBJECTDIR}/ThermometerInterface.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/SevenSeg.p1.d ${OBJECTDIR}/LcdDisplay.p1.d ${OBJECTDIR}/Delay.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/ButtonDriver.p1.d ${OBJECTDIR}/ButtonInterface.p1.d ${OBJECTDIR}/LCDPanelDriver.p1.d ${OBJECTDIR}/LCDPanelInterface.p1.d ${OBJECTDIR}/RealTimeClockDriver.p1.d ${OBJECTDIR}/RealTimeClockInterface.p1.d ${OBJECTDIR}/SounderDriver.p1.d ${OBJECTDIR}/SounderInterface.p1.d ${OBJECTDIR}/ThermometerDriver.p1.d ${OBJECTDIR}/ThermometerInterface.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/SevenSeg.p1 ${OBJECTDIR}/LcdDisplay.p1 ${OBJECTDIR}/Delay.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/ButtonDriver.p1 ${OBJECTDIR}/ButtonInterface.p1 ${OBJECTDIR}/LCDPanelDriver.p1 ${OBJECTDIR}/LCDPanelInterface.p1 ${OBJECTDIR}/RealTimeClockDriver.p1 ${OBJECTDIR}/RealTimeClockInterface.p1 ${OBJECTDIR}/SounderDriver.p1 ${OBJECTDIR}/SounderInterface.p1 ${OBJECTDIR}/ThermometerDriver.p1 ${OBJECTDIR}/ThermometerInterface.p1

# Source Files
SOURCEFILES=SevenSeg.c LcdDisplay.c Delay.c main.c ButtonDriver.c ButtonInterface.c LCDPanelDriver.c LCDPanelInterface.c RealTimeClockDriver.c RealTimeClockInterface.c SounderDriver.c SounderInterface.c ThermometerDriver.c ThermometerInterface.c
>>>>>>> Stashed changes



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F877A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/SevenSeg.p1: SevenSeg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SevenSeg.p1.d 
	@${RM} ${OBJECTDIR}/SevenSeg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SevenSeg.p1 SevenSeg.c 
	@-${MV} ${OBJECTDIR}/SevenSeg.d ${OBJECTDIR}/SevenSeg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SevenSeg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Delay.p1: Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Delay.p1.d 
	@${RM} ${OBJECTDIR}/Delay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Delay.p1 Delay.c 
	@-${MV} ${OBJECTDIR}/Delay.d ${OBJECTDIR}/Delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ButtonDriver.p1: ButtonDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ButtonDriver.p1.d 
	@${RM} ${OBJECTDIR}/ButtonDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ButtonDriver.p1 ButtonDriver.c 
	@-${MV} ${OBJECTDIR}/ButtonDriver.d ${OBJECTDIR}/ButtonDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ButtonDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ButtonInterface.p1: ButtonInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ButtonInterface.p1.d 
	@${RM} ${OBJECTDIR}/ButtonInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ButtonInterface.p1 ButtonInterface.c 
	@-${MV} ${OBJECTDIR}/ButtonInterface.d ${OBJECTDIR}/ButtonInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ButtonInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCDPanelDriver.p1: LCDPanelDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDPanelDriver.p1.d 
	@${RM} ${OBJECTDIR}/LCDPanelDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/LCDPanelDriver.p1 LCDPanelDriver.c 
	@-${MV} ${OBJECTDIR}/LCDPanelDriver.d ${OBJECTDIR}/LCDPanelDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LCDPanelDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCDPanelInterface.p1: LCDPanelInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDPanelInterface.p1.d 
	@${RM} ${OBJECTDIR}/LCDPanelInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/LCDPanelInterface.p1 LCDPanelInterface.c 
	@-${MV} ${OBJECTDIR}/LCDPanelInterface.d ${OBJECTDIR}/LCDPanelInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LCDPanelInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/RealTimeClockDriver.p1: RealTimeClockDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RealTimeClockDriver.p1.d 
	@${RM} ${OBJECTDIR}/RealTimeClockDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/RealTimeClockDriver.p1 RealTimeClockDriver.c 
	@-${MV} ${OBJECTDIR}/RealTimeClockDriver.d ${OBJECTDIR}/RealTimeClockDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/RealTimeClockDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/RealTimeClockInterface.p1: RealTimeClockInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RealTimeClockInterface.p1.d 
	@${RM} ${OBJECTDIR}/RealTimeClockInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/RealTimeClockInterface.p1 RealTimeClockInterface.c 
	@-${MV} ${OBJECTDIR}/RealTimeClockInterface.d ${OBJECTDIR}/RealTimeClockInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/RealTimeClockInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SounderDriver.p1: SounderDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SounderDriver.p1.d 
	@${RM} ${OBJECTDIR}/SounderDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SounderDriver.p1 SounderDriver.c 
	@-${MV} ${OBJECTDIR}/SounderDriver.d ${OBJECTDIR}/SounderDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SounderDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SounderInterface.p1: SounderInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SounderInterface.p1.d 
	@${RM} ${OBJECTDIR}/SounderInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SounderInterface.p1 SounderInterface.c 
	@-${MV} ${OBJECTDIR}/SounderInterface.d ${OBJECTDIR}/SounderInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SounderInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ThermometerDriver.p1: ThermometerDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ThermometerDriver.p1.d 
	@${RM} ${OBJECTDIR}/ThermometerDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ThermometerDriver.p1 ThermometerDriver.c 
	@-${MV} ${OBJECTDIR}/ThermometerDriver.d ${OBJECTDIR}/ThermometerDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ThermometerDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ThermometerInterface.p1: ThermometerInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ThermometerInterface.p1.d 
	@${RM} ${OBJECTDIR}/ThermometerInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ThermometerInterface.p1 ThermometerInterface.c 
	@-${MV} ${OBJECTDIR}/ThermometerInterface.d ${OBJECTDIR}/ThermometerInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ThermometerInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
<<<<<<< Updated upstream
${OBJECTDIR}/HeaterConfigManager.p1: HeaterConfigManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HeaterConfigManager.p1.d 
	@${RM} ${OBJECTDIR}/HeaterConfigManager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/HeaterConfigManager.p1 HeaterConfigManager.c 
	@-${MV} ${OBJECTDIR}/HeaterConfigManager.d ${OBJECTDIR}/HeaterConfigManager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HeaterConfigManager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ModeRefreshes.p1: ModeRefreshes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ModeRefreshes.p1.d 
	@${RM} ${OBJECTDIR}/ModeRefreshes.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ModeRefreshes.p1 ModeRefreshes.c 
	@-${MV} ${OBJECTDIR}/ModeRefreshes.d ${OBJECTDIR}/ModeRefreshes.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ModeRefreshes.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mode.p1: Mode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mode.p1.d 
	@${RM} ${OBJECTDIR}/Mode.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Mode.p1 Mode.c 
	@-${MV} ${OBJECTDIR}/Mode.d ${OBJECTDIR}/Mode.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mode.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
=======
>>>>>>> Stashed changes
else
${OBJECTDIR}/SevenSeg.p1: SevenSeg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SevenSeg.p1.d 
	@${RM} ${OBJECTDIR}/SevenSeg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SevenSeg.p1 SevenSeg.c 
	@-${MV} ${OBJECTDIR}/SevenSeg.d ${OBJECTDIR}/SevenSeg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SevenSeg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Delay.p1: Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Delay.p1.d 
	@${RM} ${OBJECTDIR}/Delay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Delay.p1 Delay.c 
	@-${MV} ${OBJECTDIR}/Delay.d ${OBJECTDIR}/Delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ButtonDriver.p1: ButtonDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ButtonDriver.p1.d 
	@${RM} ${OBJECTDIR}/ButtonDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ButtonDriver.p1 ButtonDriver.c 
	@-${MV} ${OBJECTDIR}/ButtonDriver.d ${OBJECTDIR}/ButtonDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ButtonDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ButtonInterface.p1: ButtonInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ButtonInterface.p1.d 
	@${RM} ${OBJECTDIR}/ButtonInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ButtonInterface.p1 ButtonInterface.c 
	@-${MV} ${OBJECTDIR}/ButtonInterface.d ${OBJECTDIR}/ButtonInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ButtonInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCDPanelDriver.p1: LCDPanelDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDPanelDriver.p1.d 
	@${RM} ${OBJECTDIR}/LCDPanelDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/LCDPanelDriver.p1 LCDPanelDriver.c 
	@-${MV} ${OBJECTDIR}/LCDPanelDriver.d ${OBJECTDIR}/LCDPanelDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LCDPanelDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCDPanelInterface.p1: LCDPanelInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDPanelInterface.p1.d 
	@${RM} ${OBJECTDIR}/LCDPanelInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/LCDPanelInterface.p1 LCDPanelInterface.c 
	@-${MV} ${OBJECTDIR}/LCDPanelInterface.d ${OBJECTDIR}/LCDPanelInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LCDPanelInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/RealTimeClockDriver.p1: RealTimeClockDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RealTimeClockDriver.p1.d 
	@${RM} ${OBJECTDIR}/RealTimeClockDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/RealTimeClockDriver.p1 RealTimeClockDriver.c 
	@-${MV} ${OBJECTDIR}/RealTimeClockDriver.d ${OBJECTDIR}/RealTimeClockDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/RealTimeClockDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/RealTimeClockInterface.p1: RealTimeClockInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RealTimeClockInterface.p1.d 
	@${RM} ${OBJECTDIR}/RealTimeClockInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/RealTimeClockInterface.p1 RealTimeClockInterface.c 
	@-${MV} ${OBJECTDIR}/RealTimeClockInterface.d ${OBJECTDIR}/RealTimeClockInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/RealTimeClockInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SounderDriver.p1: SounderDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SounderDriver.p1.d 
	@${RM} ${OBJECTDIR}/SounderDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SounderDriver.p1 SounderDriver.c 
	@-${MV} ${OBJECTDIR}/SounderDriver.d ${OBJECTDIR}/SounderDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SounderDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SounderInterface.p1: SounderInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SounderInterface.p1.d 
	@${RM} ${OBJECTDIR}/SounderInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SounderInterface.p1 SounderInterface.c 
	@-${MV} ${OBJECTDIR}/SounderInterface.d ${OBJECTDIR}/SounderInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SounderInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ThermometerDriver.p1: ThermometerDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ThermometerDriver.p1.d 
	@${RM} ${OBJECTDIR}/ThermometerDriver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ThermometerDriver.p1 ThermometerDriver.c 
	@-${MV} ${OBJECTDIR}/ThermometerDriver.d ${OBJECTDIR}/ThermometerDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ThermometerDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ThermometerInterface.p1: ThermometerInterface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ThermometerInterface.p1.d 
	@${RM} ${OBJECTDIR}/ThermometerInterface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ThermometerInterface.p1 ThermometerInterface.c 
	@-${MV} ${OBJECTDIR}/ThermometerInterface.d ${OBJECTDIR}/ThermometerInterface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ThermometerInterface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
<<<<<<< Updated upstream
${OBJECTDIR}/HeaterConfigManager.p1: HeaterConfigManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HeaterConfigManager.p1.d 
	@${RM} ${OBJECTDIR}/HeaterConfigManager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/HeaterConfigManager.p1 HeaterConfigManager.c 
	@-${MV} ${OBJECTDIR}/HeaterConfigManager.d ${OBJECTDIR}/HeaterConfigManager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HeaterConfigManager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ModeRefreshes.p1: ModeRefreshes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ModeRefreshes.p1.d 
	@${RM} ${OBJECTDIR}/ModeRefreshes.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ModeRefreshes.p1 ModeRefreshes.c 
	@-${MV} ${OBJECTDIR}/ModeRefreshes.d ${OBJECTDIR}/ModeRefreshes.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ModeRefreshes.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mode.p1: Mode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mode.p1.d 
	@${RM} ${OBJECTDIR}/Mode.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Mode.p1 Mode.c 
	@-${MV} ${OBJECTDIR}/Mode.d ${OBJECTDIR}/Mode.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mode.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
=======
>>>>>>> Stashed changes
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=${DFP_DIR}/xc8  -fshort-double -fshort-float -O1 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_Project.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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
