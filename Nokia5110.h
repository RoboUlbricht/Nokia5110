/**
 * LCD Nokia 5110
 * v. 1.0
 * Copyright (C) 2014 Robert Ulbricht
 *
 * Library for LCD Nokia 5110
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/ 


#ifndef LCDnokia5110_h
#define LCDnokia5110_h

#include "Arduino.h"
#include "Print.h"

enum nstyle {nsNormal=0, nsBold, nsDouble};

class Nokia5110 : public Print
{
  nstyle algo;
  int PIN_SCE;
  int PIN_RESET;
  int PIN_DC;
  int PIN_SDIN;
  int PIN_SCLK;

  public:
    Nokia5110(int, int, int, int, int);
    void LcdClear();
    void LcdInitialise();
    void LcdWrite(byte, byte);
    void LcdWriteData(byte);
    void LcdString(char*);
    void LcdCharacter(char character);
    
    void setCursor(uint8_t, uint8_t);
    virtual size_t write(uint8_t);
    void setAlgo(nstyle a);
    
    int CharSpace; 
    		
  private:
    volatile uint8_t *dcport,*sceport,*mosiport, *clkport;
    uint8_t dcpinmask,scepinmask,mosipinmask, clkpinmask;
    
};

#endif
