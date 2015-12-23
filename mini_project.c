void main() {
char kp;
char kd;
char ki;
EEPROM_Write(0x10,kp);
EEPROM_Write(0x11,kd);
EEPROM_Write(0x12,ki);
}
