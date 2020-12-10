#include "Mode.h"

typedef void(*function_pointer_type)(void);
typedef void(*function_pointerparam_type)(void);

//Home Button Functionality
extern function_pointer_type ModeHomeMode;
extern function_pointer_type ModeHomeSet;
extern function_pointer_type ModeHomeInc;
extern function_pointer_type ModeHomeDec;
extern function_pointer_type ModeHomeCancel;
extern function_pointer_type ModeHomeAux1;
extern function_pointer_type ModeHomeAux2;
extern function_pointer_type ModeHomeAux3;

//Set Date Button Functionality
extern function_pointer_type ModeSetDateMode;
extern function_pointer_type ModeSetDateSet;
extern function_pointer_type ModeSetDateInc;
extern function_pointer_type ModeSetDateDec;
extern function_pointer_type ModeSetDateCancel;
extern function_pointer_type ModeSetDateAux1;
extern function_pointer_type ModeSetDateAux2;
extern function_pointer_type ModeSetDateAux3;

//Set Time Button Functionality
extern function_pointer_type ModeSetTimeMode;
extern function_pointer_type ModeSetTimeSet;
extern function_pointer_type ModeSetTimeInc;
extern function_pointer_type ModeSetTimeDec;
extern function_pointer_type ModeSetTimeCancel;
extern function_pointer_type ModeSetTimeAux1;
extern function_pointer_type ModeSetTimeAux2;
extern function_pointer_type ModeSetTimeAux3;

//Set Trigger Temperature Button Functionality
extern function_pointer_type ModeSetTrigTempMode;
extern function_pointer_type ModeSetTrigTempSet;
extern function_pointer_type ModeSetTrigTempInc;
extern function_pointer_type ModeSetTrigTempDec;
extern function_pointer_type ModeSetTrigTempCancel;
extern function_pointer_type ModeSetTrigTempAux1;
extern function_pointer_type ModeSetTrigTempAux2;
extern function_pointer_type ModeSetTrigTempAux3;

//Set Fake Temperature Button Functionality
extern function_pointer_type ModeSetFakeTempMode;
extern function_pointer_type ModeSetFakeTempSet;
extern function_pointer_type ModeSetFakeTempInc;
extern function_pointer_type ModeSetFakeTempDec;
extern function_pointer_type ModeSetFakeTempCancel;
extern function_pointer_type ModeSetFakeTempAux1;
extern function_pointer_type ModeSetFakeTempAux2;
extern function_pointer_type ModeSetFakeTempAux3;

//Set Hot Timer Button Functionality
extern function_pointer_type ModeSetHotTimerMode;
extern function_pointer_type ModeSetHotTimerSet;
extern function_pointer_type ModeSetHotTimerInc;
extern function_pointer_type ModeSetHotTimerDec;
extern function_pointer_type ModeSetHotTimerCancel;
extern function_pointer_type ModeSetHotTimerAux1;
extern function_pointer_type ModeSetHotTimerAux2;
extern function_pointer_type ModeSetHotTimerAux3;

//Set Cold Timer Button Functionality
extern function_pointer_type ModeSetColdTimerMode;
extern function_pointer_type ModeSetColdTimerSet;
extern function_pointer_type ModeSetColdTimerInc;
extern function_pointer_type ModeSetColdTimerDec;
extern function_pointer_type ModeSetColdTimerCancel;
extern function_pointer_type ModeSetColdTimerAux1;
extern function_pointer_type ModeSetColdTimerAux2;
extern function_pointer_type ModeSetColdTimerAux3;

//Set Errors Button Functionality
extern function_pointer_type ModeErrorsMode;
extern function_pointer_type ModeErrorsSet;
extern function_pointer_type ModeErrorsInc;
extern function_pointer_type ModeErrorsDec;
extern function_pointer_type ModeErrorsCancel;
extern function_pointer_type ModeErrorsAux1;
extern function_pointer_type ModeErrorsAux2;
extern function_pointer_type ModeErrorsAux3;

void InstantiateModes(Mode* modes)
{
    modes[HOME].buttons.mode = ModeHomeMode;
    modes[HOME].buttons.set = ModeHomeSet;
    modes[HOME].buttons.increment = ModeHomeInc;
    modes[HOME].buttons.decrement = ModeHomeDec;
    modes[HOME].buttons.cancel = ModeHomeCancel;
    modes[HOME].buttons.aux1 = ModeHomeAux1;
    modes[HOME].buttons.aux2 = ModeHomeAux2;
    modes[HOME].buttons.aux3 = ModeHomeAux3;
    
    modes[SETDATE].buttons.mode = ModeSetDateMode;
    modes[SETDATE].buttons.set = ModeSetDateSet;
    modes[SETDATE].buttons.increment = ModeSetDateInc;
    modes[SETDATE].buttons.decrement = ModeSetDateDec;
    modes[SETDATE].buttons.cancel = ModeSetDateCancel;
    modes[SETDATE].buttons.aux1 = ModeSetDateAux1;
    modes[SETDATE].buttons.aux2 = ModeSetDateAux2;
    modes[SETDATE].buttons.aux3 = ModeSetDateAux3;
    
    modes[SETTIME].buttons.mode = ModeSetTimeMode;
    modes[SETTIME].buttons.set = ModeSetTimeSet;
    modes[SETTIME].buttons.increment = ModeSetTimeInc;
    modes[SETTIME].buttons.decrement = ModeSetTimeDec;
    modes[SETTIME].buttons.cancel = ModeSetTimeCancel;
    modes[SETTIME].buttons.aux1 = ModeSetTimeAux1;
    modes[SETTIME].buttons.aux2 = ModeSetTimeAux2;
    modes[SETTIME].buttons.aux3 = ModeSetTimeAux3;
    
    modes[SETTRIGTEMP].buttons.mode = ModeSetTrigTempMode;
    modes[SETTRIGTEMP].buttons.set = ModeSetTrigTempSet;
    modes[SETTRIGTEMP].buttons.increment = ModeSetTrigTempInc;
    modes[SETTRIGTEMP].buttons.decrement = ModeSetTrigTempDec;
    modes[SETTRIGTEMP].buttons.cancel = ModeSetTrigTempCancel;
    modes[SETTRIGTEMP].buttons.aux1 = ModeSetTrigTempAux1;
    modes[SETTRIGTEMP].buttons.aux2 = ModeSetTrigTempAux2;
    modes[SETTRIGTEMP].buttons.aux3 = ModeSetTrigTempAux3;
   
    modes[SETFAKETEMP].buttons.mode = ModeSetFakeTempMode;
    modes[SETFAKETEMP].buttons.set = ModeSetFakeTempSet;
    modes[SETFAKETEMP].buttons.increment = ModeSetFakeTempInc;
    modes[SETFAKETEMP].buttons.decrement = ModeSetFakeTempDec;
    modes[SETFAKETEMP].buttons.cancel = ModeSetFakeTempCancel;
    modes[SETFAKETEMP].buttons.aux1 = ModeSetFakeTempAux1;
    modes[SETFAKETEMP].buttons.aux2 = ModeSetFakeTempAux2;
    modes[SETFAKETEMP].buttons.aux3 = ModeSetFakeTempAux3;
    
    modes[SETHOTTIMER].buttons.mode = ModeSetHotTimerMode;
    modes[SETHOTTIMER].buttons.set = ModeSetHotTimerSet;
    modes[SETHOTTIMER].buttons.increment = ModeSetHotTimerInc;
    modes[SETHOTTIMER].buttons.decrement = ModeSetHotTimerDec;
    modes[SETHOTTIMER].buttons.cancel = ModeSetHotTimerCancel;
    modes[SETHOTTIMER].buttons.aux1 = ModeSetHotTimerAux1;
    modes[SETHOTTIMER].buttons.aux2 = ModeSetHotTimerAux2;
    modes[SETHOTTIMER].buttons.aux3 = ModeSetHotTimerAux3;
    
    modes[SETCOLDTIMER].buttons.mode = ModeSetColdTimerMode;
    modes[SETCOLDTIMER].buttons.set = ModeSetColdTimerSet;
    modes[SETCOLDTIMER].buttons.increment = ModeSetColdTimerInc;
    modes[SETCOLDTIMER].buttons.decrement = ModeSetColdTimerDec;
    modes[SETCOLDTIMER].buttons.cancel = ModeSetColdTimerCancel;
    modes[SETCOLDTIMER].buttons.aux1 = ModeSetColdTimerAux1;
    modes[SETCOLDTIMER].buttons.aux2 = ModeSetColdTimerAux2;
    modes[SETCOLDTIMER].buttons.aux3 = ModeSetColdTimerAux3;
    
    modes[ERRORS].buttons.mode = ModeErrorsMode;
    modes[ERRORS].buttons.set = ModeErrorsSet;
    modes[ERRORS].buttons.increment = ModeErrorsInc;
    modes[ERRORS].buttons.decrement = ModeErrorsDec;
    modes[ERRORS].buttons.cancel = ModeErrorsCancel;
    modes[ERRORS].buttons.aux1 = ModeErrorsAux1;
    modes[ERRORS].buttons.aux2 = ModeErrorsAux2;
    modes[ERRORS].buttons.aux3 = ModeErrorsAux3;

}

void ModeDisplay(Mode mode)
{
    ILCDPanelSetCursor(0,0);
    ILCDPanelWrite(mode.firstLine);
    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(mode.secondLine);
}

void ModeCheckButtons(Mode mode)
{
    char buttonStates[8]; 
    
    IButtonsCheckButtons(buttonStates);
    
    if(buttonStates[0]) { mode.buttons.mode(); }
    else if(buttonStates[1]) { mode.buttons.set(); }
    else if(buttonStates[2]) { mode.buttons.increment(); }
    else if(buttonStates[3]) { mode.buttons.decrement(); }
    else if(buttonStates[4]) { mode.buttons.cancel(); }
    else if(buttonStates[5]) { mode.buttons.aux1(); }
    else if(buttonStates[6]) { mode.buttons.aux2(); }
    else if(buttonStates[7]) { mode.buttons.aux3(); }
}