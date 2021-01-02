#ifndef BUTTONS_H
#define	BUTTONS_H
#define RIGHT_SIDE_HIGH 1

#ifdef	__cplusplus
extern "C" {
#endif

    // Set tris values.
    void initialiseButtons(void);
    
    // Check the 8 buttons. Return as one byte with all eight values in.
    unsigned char checkButtons(void);
    
    // Set tris values for the matrix buttons
    void initialiseMatrixButtons(void);
    
    // Check the matrix buttons and put the results into an array.
    void checkMatrixButtons(unsigned char results[4][4]);
    
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */

