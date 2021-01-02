#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif

    // Normal delay, wait for n operations.
    void Delay(unsigned short n);
    
    // Thermometer specific delay, calculation used.
    void Therm_Delay(char, char);


#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

