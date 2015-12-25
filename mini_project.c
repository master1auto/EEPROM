#include <stdio.h>
void writeEEPROM(unsigned char address, unsigned char data)
{
  EEADR=address;
  EEDAT=data;
  EECON1.EEPGD = 0; //Selecting EEPROM Data Memory
  EECON1.WREN = 1; //Enable writing of EEPROM
  INTCON=0; //Diables the interrupt
  EECON2=0x55; //Required sequence for write to internal EEPROM
  EECON2=0xAA; //Required sequence for write to internal EEPROM
  EECON1.WR = 1; //Initialise write cycle
  while(EECON1.WR==1)
  {
    asm nop (); // wait for write to complete
  }
  INTCON.GIE = 1;//Enables Interrupt
  EECON1.WREN = 0; //To disable write
}
//----------------------------------//
main()
{
  writeEEPROM(unsigned char 10, unsigned char kp)
  writeEEPROM(unsigned char 11, unsigned char kd)
  writeEEPROM(unsigned char 12, unsigned char ki)
  }
