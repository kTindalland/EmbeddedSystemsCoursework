/* 
 * File:   buttons.h
 * Author: kaiti
 *
 * Created on 02 November 2020, 10:25
 */

#ifndef BUTTONS_H
#define	BUTTONS_H
#define RIGHT_SIDE_HIGH 1

#ifdef	__cplusplus
extern "C" {
#endif

    
    void initialiseButtons(void);
    unsigned char checkButtons();
    
    void initialiseMatrixButtons();
    void checkMatrixButtons(int results[4][4]);
    
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */
