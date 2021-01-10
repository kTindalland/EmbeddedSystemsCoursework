#ifndef BUTTONSINTERFACE_H
#define	BUTTONSINTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

    // Check the 8 buttons. Return as one byte with all eight values in.
    unsigned char CheckButtons(void);
    
    // Check the matrix buttons and put the results into an array.
    void CheckMatrixButtons(unsigned char[4][4]);


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONSINTERFACE_H */

