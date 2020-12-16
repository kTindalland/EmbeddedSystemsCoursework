/* 
 * File:   Mode.h
 * Author: linco
 *
 * Created on 07 December 2020, 15:15
 */

#ifndef MODE_H
#define	MODE_H

#ifdef	__cplusplus
extern "C" {
#endif

#define HOME 0
#define SETDATE 1
#define SETTIME 2
#define SETTRIGTEMP 3
#define SETFAKETEMP 4
#define SETHOTTIMER 5
#define SETCOLDTIMER 6
#define ERRORS 7
    
struct Buttons{
    void (*mode)(void);
    void (*set)(void);
    void (*increment)(void);
    void (*decrement)(void);
    void (*cancel)(void);
    void (*aux1)(void);
    void (*aux2)(void);
    void (*aux3)(void);
};

struct Mode{
    struct Buttons buttons;
    void (*refresh) (void);
    
    char firstLine[17];
    char secondLine[17];
};
typedef struct Mode Mode_t;

void InstantiateModes(Mode_t*);
void ModeDisplay(Mode_t* mode);
void ModeCheckButtons(Mode_t* mode);

#ifdef	__cplusplus
}
#endif

#endif	/* MODE_H */

