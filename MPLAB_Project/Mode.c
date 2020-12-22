#include "Mode.h"
#include "ModeRefreshes.h"
#include "LCDPanelInterface.h"

typedef void(*function_pointer_type)(void);

/*
// Refresh Functionality for All Modes
extern function_pointer_type ModeRefreshHome;
extern function_pointer_type ModeRefreshSetDate;
extern function_pointer_type ModeRefreshSetTime;
extern function_pointer_type ModeRefreshSetTrigTemp;
extern function_pointer_type ModeRefreshSetFakeTemp;
extern function_pointer_type ModeRefreshSetHotTimer;
extern function_pointer_type ModeRefreshSetColdTimer;
extern function_pointer_type ModeRefreshErrors;

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
extern function_pointer_type ModeSetFakeTempAux2;
extern function_pointer_type ModeSetFakeTempAux3;

//Set Hot Timer Button Functionality
extern function_pointer_type ModeSetHotTimerMode;
extern function_pointer_type ModeSetHotTimerSet;
extern function_pointer_type ModeSetHotTimerInc;
extern function_pointer_type ModeSetHotTimerDec;
extern function_pointer_type ModeSetHotTimerCancel;

//Set Cold Timer Button Functionality
extern function_pointer_type ModeSetColdTimerMode;
extern function_pointer_type ModeSetColdTimerSet;
extern function_pointer_type ModeSetColdTimerInc;
extern function_pointer_type ModeSetColdTimerDec;
extern function_pointer_type ModeSetColdTimerCancel;

//Set Errors Button Functionality
extern function_pointer_type ModeErrorsMode;
extern function_pointer_type ModeErrorsSet;

// Refresh Display of Each Mode
extern function_pointer_type ModeRefreshHome;
extern function_pointer_type ModeRefreshSetDate;
extern function_pointer_type ModeRefreshSetTime;
extern function_pointer_type ModeRefreshSetTrigTemp;
extern function_pointer_type ModeRefreshSetFakeTemp;
extern function_pointer_type ModeRefreshSetHotTimer;
extern function_pointer_type ModeRefreshSetColdTimer;
extern function_pointer_type ModeRefreshErrors;
 */

void InstantiateModes(Mode_t* modes)
{
    /*
    modes[HOME].refresh = ModeRefreshHome;
    modes[SETDATE].refresh = ModeRefreshSetDate;
    modes[SETTIME].refresh = ModeRefreshSetTime;
    modes[SETTRIGTEMP].refresh = ModeRefreshSetTrigTemp;
    modes[SETFAKETEMP].refresh = ModeRefreshSetFakeTemp;
    modes[SETHOTTIMER].refresh = ModeRefreshSetHotTimer;
    modes[SETCOLDTIMER].refresh = ModeRefreshSetColdTimer;
    modes[ERRORS].refresh = ModeRefreshErrors;
            
    modes[HOME].buttons->mode = ModeHomeMode;
    modes[HOME].buttons->set = ModeHomeSet;
    modes[HOME].buttons->increment = ModeHomeInc;
    modes[HOME].buttons->decrement = ModeHomeDec;
    modes[HOME].buttons->cancel = ModeHomeCancel;
    modes[HOME].buttons->aux1 = ModeHomeAux1;
    modes[HOME].buttons->aux2 = ModeHomeAux2;
    modes[HOME].buttons->aux3 = ModeHomeAux3;
    
    modes[SETDATE].buttons->mode = ModeSetDateMode;
    modes[SETDATE].buttons->set = ModeSetDateSet;
    modes[SETDATE].buttons->increment = ModeSetDateInc;
    modes[SETDATE].buttons->decrement = ModeSetDateDec;
    modes[SETDATE].buttons->cancel = ModeSetDateCancel;
    modes[SETDATE].buttons->aux1 = ModeSetDateAux1;
    modes[SETDATE].buttons->aux2 = ModeSetDateAux2;
    modes[SETDATE].buttons->aux3 = ModeSetDateAux3;
    
    modes[SETTIME].buttons->mode = ModeSetTimeMode;
    modes[SETTIME].buttons->set = ModeSetTimeSet;
    modes[SETTIME].buttons->increment = ModeSetTimeInc;
    modes[SETTIME].buttons->decrement = ModeSetTimeDec;
    modes[SETTIME].buttons->cancel = ModeSetTimeCancel;
    modes[SETTIME].buttons->aux1 = ModeSetTimeAux1;
    modes[SETTIME].buttons->aux2 = ModeSetTimeAux2;
    modes[SETTIME].buttons->aux3 = ModeSetTimeAux3;
    
    modes[SETTRIGTEMP].buttons->mode = ModeSetTrigTempMode;
    modes[SETTRIGTEMP].buttons->set = ModeSetTrigTempSet;
    modes[SETTRIGTEMP].buttons->increment = ModeSetTrigTempInc;
    modes[SETTRIGTEMP].buttons->decrement = ModeSetTrigTempDec;
    modes[SETTRIGTEMP].buttons->cancel = ModeSetTrigTempCancel;
    modes[SETTRIGTEMP].buttons->aux1 = ModeSetTrigTempAux1;
    modes[SETTRIGTEMP].buttons->aux2 = ModeSetTrigTempAux2;
    modes[SETTRIGTEMP].buttons->aux3 = ModeSetTrigTempAux3;
   
    modes[SETFAKETEMP].buttons->mode = ModeSetFakeTempMode;
    modes[SETFAKETEMP].buttons->set = ModeSetFakeTempSet;
    modes[SETFAKETEMP].buttons->increment = ModeSetFakeTempInc;
    modes[SETFAKETEMP].buttons->decrement = ModeSetFakeTempDec;
    modes[SETFAKETEMP].buttons->cancel = ModeSetFakeTempCancel;
    modes[SETFAKETEMP].buttons->aux2 = ModeSetFakeTempAux2;
    modes[SETFAKETEMP].buttons->aux3 = ModeSetFakeTempAux3;
    
    modes[SETHOTTIMER].buttons->mode = ModeSetHotTimerMode;
    modes[SETHOTTIMER].buttons->set = ModeSetHotTimerSet;
    modes[SETHOTTIMER].buttons->increment = ModeSetHotTimerInc;
    modes[SETHOTTIMER].buttons->decrement = ModeSetHotTimerDec;
    modes[SETHOTTIMER].buttons->cancel = ModeSetHotTimerCancel;
    
    modes[SETCOLDTIMER].buttons->mode = ModeSetColdTimerMode;
    modes[SETCOLDTIMER].buttons->set = ModeSetColdTimerSet;
    modes[SETCOLDTIMER].buttons->increment = ModeSetColdTimerInc;
    modes[SETCOLDTIMER].buttons->decrement = ModeSetColdTimerDec;
    modes[SETCOLDTIMER].buttons->cancel = ModeSetColdTimerCancel;
    
    modes[ERRORS].buttons->mode = ModeErrorsMode;
    modes[ERRORS].buttons->set = ModeErrorsSet;
    */
}

void ModeDisplay(Mode_t* mode)
{
    ILCDPanelSetCursor(0,0);
    ILCDPanelWrite(mode->firstLine);
    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(mode->secondLine);
}

void ModeCheckButtons(Mode_t* mode)
{
    /*
    char buttonStates[8]; 
    
    IButtonsCheckButtons(buttonStates);
    
    if(buttonStates[0]) { mode->buttons->mode(); }
    else if(buttonStates[1]) { mode->buttons->set(); }
    else if(buttonStates[2]) { mode->buttons->increment(); }
    else if(buttonStates[3]) { mode->buttons->decrement(); }
    else if(buttonStates[4]) { mode->buttons->cancel(); }
    else if(buttonStates[5]) { mode->buttons->aux1(); }
    else if(buttonStates[6]) { mode->buttons->aux2(); }
    else if(buttonStates[7]) { mode->buttons->aux3(); }
    
    */
}
