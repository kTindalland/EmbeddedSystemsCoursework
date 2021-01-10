#ifndef BUTTONS_H
#define	BUTTONS_H
#define RIGHT_SIDE_HIGH 1

#ifdef	__cplusplus
extern "C" {
#endif

    
    
    // Check the 8 buttons. Return as one byte with all eight values in.
    unsigned char checkButtons(void);
    
    
    
    // Check the matrix buttons and put the results into an array.
    void checkMatrixButtons(unsigned char results[4][4]);
    
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */

