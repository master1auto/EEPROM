BSF STATUS,RP1
BSF STATUS,RP0
BTFSC EECON,WR1  ; Wait for the previous write to complete
GOTO $-1         ;
BCF STATUS,RP0   ; Bank 2
MOVF 10,W   ; Move address to W
MOVWF EEADR      ; Write address
MOVF 'kp',W      ; Move data to W
MOVWF EEDATA     ; Write data
BSF STATUS,RP0   ; Bank 3
BCF EECON1,EEPGD ; Select EEPROM
BSF EECON1,WREN  ; Write to EEPROM enabled
BCF INCON,GIE    ; All interrupts disabled

BTFSC EECON,WR1  ; Wait for the previous write to complete
GOTO $-1         ;
BCF STATUS,RP0   ; Bank 2
MOVF 11,W   ; Move address to W
MOVWF EEADR      ; Write address
MOVF 'kd',W      ; Move data to W
MOVWF EEDATA     ; Write data
BSF STATUS,RP0   ; Bank 3
BCF EECON1,EEPGD ; Select EEPROM
BSF EECON1,WREN  ; Write to EEPROM enabled
BCF INCON,GIE    ; All interrupts disabled


BTFSC EECON,WR1  ; Wait for the previous write to complete
GOTO $-1         ;
BCF STATUS,RP0   ; Bank 2
MOVF 12,W   ; Move address to W
MOVWF EEADR      ; Write address
MOVF 'ki',W      ; Move data to W
MOVWF EEDATA     ; Write data
BSF STATUS,RP0   ; Bank 3
BCF EECON1,EEPGD ; Select EEPROM
BSF EECON1,WREN  ; Write to EEPROM enabled
BCF INCON,GIE    ; All interrupts disabled

;Required Sentence
MOVLW 55h
MOVWF EECON2
MOVLW AAh
MOVWF EECON2
BSF EECON1,WR

BSF INTCON,GIE   ; Interrupts enabled
BCF EECON1,WREN  ; Write to EEPROM disabled

