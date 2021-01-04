/* 
 * File:   ThermometerInterface.h
 * Author: kaiti
 *
 * Created on 14 December 2020, 11:11
 */

#ifndef THERMOMETERINTERFACE_H
#define	THERMOMETERINTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

    void IThermGetTemperature(signed char*, signed char*); // Return the current temperature from the thermometer.


#ifdef	__cplusplus
}
#endif

#endif	/* THERMOMETERINTERFACE_H */

