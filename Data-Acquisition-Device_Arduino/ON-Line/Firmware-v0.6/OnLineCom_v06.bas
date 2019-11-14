'--------------------------------------------------------------------------+
'| ON LINE KOMUNIKACIJA je vedno sestavljena iz 2 Bytov. Za veèino funkcij  |
'| je to dovolj, le funkcijo "Set_Register" je potrebno izvesti v dveh      |
'| korakih (z dvema ukazoma):                                               |
'|  - najprej izvedete Set_Data kjer pošljete podatek, ki se bo vpisal v    |
'|    register,                                                             |
'|  - nato še Set_Register, ki ta podatek vpiše v register...               |
'| ATmega328 ima v enoti UART le dva Byta prostora za pomnenje prihajajoèih |
'| podatkov, kar je premalo za nemoteno delovanje. Zato smo prihajajoèe     |
'| podatke vezali na prekinitveno zastavico in jih shranjujemo v SRAM. Od   |
'| tam pa jih nato beremo in izvršujemo, ko za to najdemo èas. V SRAMu smo  |
'| za to proceduro namenili 256 Bytov prostora, kar zadostuje za 128 ukazov.|
'| Èe upoštevamo, da nekatere funkcije potrebujejo 2 ukaza, bo shranjenih   |
'| funkcij nekoliko manj, vendar še vedno dovolj za kratke, hitre operacije.|
'| Komunikacija poteka s hitrostjo 115200 bitov/s, kar pomeni, da prenos    |
'| enega funkcije (=2 byta) traja cca 175us. Izvršitev le-tega pa se zgodi  |
'| v cca 8us.                                                               |
'|                                                                          |
'| OPIS KOMUNIKACIJE:                                                       |
'| 1. Byte                                                                  |
'|      Je sestavljen iz 4-h bitov za ukaz in 4-h bitov za številko bita v  |
'|      registru, ki ga bomo nastavljali.                                   |
'|                                                                          |
'|      &B_kkkk_xbit                                                        |
'|          ^    ^                                                          |
'|          |    |                                                          |
'|          |    +---- številka bita = {0..7}                               |
'|          +--------- Kommand                                              |
'|                                                                          |
'| 2. Byte                                                                  |
'|      Je addressa registra ali vrednost registra                          |
'|                                                                          |
'| OPIS FUNKCIJ:                                                            |
'|                                                                          |
'| ukaz:                                                                    |
'| 0x0b 0xAA      - Skok v Program                                          |
'| 0x1b 0xAA      - Branje I/O registra                                     |
'|                  Ukaz prebere vrednost v I/O registru z naslovom [ AA]   |
'|                  in jo pošlje po UARTU. Ukaz sicer ne potrebuje zadnjega |
'|                  Byta a ga moramo vseeno poslati, zaradi konsistentnosti |
'|                  komunikacije.                                           |
'| 0x20 0xAA      - Vpis podatkov v r16 v register z Addreso AA             |
'| 0x3b 0xAA      - Nastavitev bita v registru z naslovom [AA] na           |
'|                  logièno "1". [b] je številka bita in je lahko od 0-7.   |
'|                  V nasprotnem primeru (ko je številka veèja) se izbira   |
'|                  bita nadaljuje, vkljuèno s carry bitom - torej številka |
'|                  9 na tem mestu, bi pomenila bit 0; številka 10 pa bit 1.|
'| 0x4b 0xAA      - Nastavljanje [b]-tega bita v I/O registru z naslovom    |
'|                  [AAA] na logièno "0"                                    |
'| 0x5b 0xAA      - Branje vrednosti pina [b] v I/O registru z naslovom     |
'|                  [AAA]. Rezultat funkcije je 1 ali 0. Ta podatek pošlemo |
'|                  preko UARTa.                                            |
'| 0x6b 0xAA      - Wait until bit in register is set                       |
'|                                                                          |
'|                                                                          |
'| 0x7b 0xAA      - Wait until bit in register is cleard                    |
'|                                                                          |
'|                                                                          |
'| 0x80 0xAA      - Read 16 bit value from register address AAA and AAA+1   |
'|                                                                          |
'|                                                                          |
'| 0x9A 0xAA      - Read 16 bit value from register address AAA and AAA-1   |
'|                                                                          |
'| 0xA0 0xDD      - Repeat last DD commands in CMD buffer. (do-loop can be  |
'|                  created).                                               |
'|                                                                          |
'| 0xB0 0xDD      - Nastavitev Podatkov [DD] v DATA register r16. Ti podatki|
'|                  bodo v naslednjem koraku zapisani v nek register...     |
'|                                                                          |
'|                                                                          |
'|                                                                          |
'|                                                                          |
'|.........to do............................................................|
'+--------------------------------------------------------------------------+
$regfile = "m328pdef.dat"
$crystal = 16000000                                         '16Mhz
$baud = 115200
'konèno s temi nastavitvami dela tudi originalni ARDUINO UNO r03
Ucsr0a = &B_0000_0010                                       ' transm. speed 2x (zaradi manjšega err)
Ucsr0b = &B_1001_1000                                       ' RxCi(en),Rx(en), Tx(en)
Ucsr0c = &B_00_00_0_11_0
Ubrr0h = 0                                                  ' baud =
Ubrr0l = 16                                                 ' 115200 , err = 2.1%
On Urxc Store_uart_data Nosave
Config Portb = Output
Config Portd = &B0000_0010
Config Portc = Input
'to do?!?! najbrž bi moral T0 šteti hitreje, saj sedaj perioda traja 16ms,
'ukaz (2 Byta) pa se prenaša najveè cca 170us -> 10x hitreje...
Config Timer0 = Timer , Prescale = 1024
On Timer0 Uart_data_not_recieved
'On Timer0 Process_reset
Enable Ovf0
Tccr0b = 0
Timer0 = 0
Enable Interrupts
'Dim Uart_buffer(256) As Byte At &H0100
'Dim Test As Byte
'Dim I As Byte
Process_reset:
Printbin 6
   ldi r16, &H00                                            'DATA = verzija 6
   ldi r17, &H00                                            'za CMD
   ldi r18, &H00                                            'tmp register - tko za sprot..
   ldi r19, &H00                                            'za xbit
   ldi r20, &H00                                            'Regiter je v rabi le v prekinitvah ! je zelo pomembeno, da se mu vrednost med izvajanjem ne spremeni
   Ldi r21, &Hff                                            'addressa za UART_buffer_ADDED_Last_CMD
   Ldi r22, &Hff                                            'addressa za UART_buffer_READED_Last_CMD
   ldi r23, &Hff                                            'kopija od R21, za vsak sluèaj, še se ravno med IFi zgodi Interrupt
   ldI xh, &H00                                             'r26 - register za I/O addresse
   ldi xl, &H00                                             'r27 - register za I/O addresse
   'trenutno se yH ne nastavlja veè
   'èe pa bo potrebno pisati v Sram na veè mest pa bo potrebno
   'popravljati tudi yH v Store_uart_data in Read_next_cmd (dodati yH=&H01)
   ldI yh, &H01                                             'r30 - register za SRAM addresse
   ldi yl, &H00                                             'r31 - register za SRAM addresse
   ldI zh, &H00                                             'r30 - register za PC addresse
   ldi zl, &H00                                             'r31 - register za PC addresse
   'Portb.5 = Not Portb.5
   'Waitms 200
$asm
Waiting_new_cmd:
   'brati gremo le èe je r21 obtièal na lihi številki r21 = 1,3,5,7....
   'takrat smo shranili oba byta
   cli
   mov r23,r21                                              'kopram r21 v r23, èe se v naslednjih vrsticah zgodi interrupt,
   sei                                                      'vrednost r23 ostane izsta èeprav smo prejeli nov Uart DATA -> r21+
   SBrs r23,0                                               'if r23.0=1 -> preskoèi, èe je liho - torej je vse ok, saj smo prejeli tudi 2.byte
   rjmp Waiting_new_cmd                                     'èe ne - štopamo, ali ga dolgo ne bo. T0 smo že vklopili v rutini "Store_uart_data"
   CPSE r22,r23                                             'if r22=r23 -> preskoèi branje shranjenih ukazov - vse poslane ukaze smo že prebrali
   rjmp Read_next_cmd
   rjmp Waiting_new_cmd
'-------------------------------------------------------------------------------
Store_uart_data:
   inc r21                                                  'to je mesto zadnjega vpisanega UART podatka
   In r20 , UDR0
   MOV yl,r21
   ST y, r20
   'èe je r21 sodo = 0,2,4,6.. gre za prvi byte komunikacoje
   'in naslednji mora biti poslan v zelo kratkem èasu.
   'drugaèe je nejk narobe...
   'pogledamo, èe je zadnji bit=1=liho -> takrat smo dobili oba byte 0in1.. 2in3
   SBrs r21,0                                               'preskoèi, èe je liho - torej je vse ok, saj smo prejeli tudi 2.byte
   rjmp Expecting_uart_byte_soon                            'èe ne - štopamo, ali ga dolgo ne bo
   'Vse je OK - ugasni in resetiraj Timer0
   Second_byte_recived:
      ldi r20, &H00
      Out Tccr0b , R20                                      'Stop Timer0
      Out Tcnt0 , R20                                       'Timer0=0
      sei
   ret
   'Èakamo naslednji byte - vkljuèimo timer0
   Expecting_uart_byte_soon:
      Ldi r20, &H05                                         'Start Timer0
      Out Tccr0b , R20
      sei
   ret
'-------------------------------------------------------------------------------
Uart_data_not_recieved:
'ker nismo dobili oba Byta je zadnji ukaz nepopoln in bomo r21 zmanjšali,ker èakamo naslednji ukaz
'Tu je potrebno premisliti, mogoèe bi kar resetirali ARDUINO... in bi imeli še
'reset funkcijo.. mislim, da je SUPER
      dec r21
      ldi r20, &H00
      Out Tccr0b , R20                                      'Stop Timer0
      Out Tcnt0 , R20                                       'Timer0=0
      sei                                                   'Set global interrupt
      jmp &H00                                              'reset
      ret
'-------------------------------------------------------------------------------
Read_next_cmd:
   inc r22
   MOV yl,r22
   ld r19, y+                                               'r19 = CMD_+_xbit (preberi naslednjo shranjeno CMD)
   inc r22
   ld xl,y                                                  'Xl = Addr_lo (preberi naslednji shranjen DATA/ADDR)
rjmp if_cmds
'+--------------------------------------------------------------------------+
'|    IF stavki glede na to katero komando smo prejeli -> r17               |
'+--------------------------------------------------------------------------+
If_cmds:
   ldI r18, &B_1111_0000                                    'maska za branje zgornjih 4 bitov
   MOV r17,r19                                              'v r17 izlušèimo komando ta je le v prvih 4ih bitih prvega Byta
   And r17, r18                                             'r17 = CMD_+_xbit
   lsR r17                                                  'CMD premaknemo -> iz CMD+xbit
   lsR r17                                                  ' = 0000_CMD
   lsR r17
   lsR r17                                                  'Tako CMD imamo v r17
   ldI r18, &B_0000_1111                                    'Preostali del r19 maskiramo tako,da pripravimo
   And r19, r18                                             'podatke za bit value in številko bita = 0000_xBit
   CLC
   RCall Next                                               '(3CLK) ker je internal mem acc
   Next:
   POP zh                                                   '(2CLK) Z_hi <- PC_hi
   pop zl                                                   '(2CLK) Z_lo <- PC_lo
   LDI r18,9                                                '(1CLK) Od Recall NEXT do IJMP je 9 CLKjev!
   ADD r18, r17                                             '(1CLK)
   ADC r30,r18                                              '(1CLK)
      BRCC Do_not_add_carrier                               '(1/2CLK)
      inc r31                                               '(1CKL)
      Do_not_add_carrier:
      NOP
   ICALL                                                    ' PC skok za število mest v registru Z
   RJMP Proces_reset                                        '0
   RJMP Read_register                                       '1
   RJMP Set_register                                        '2
   RJMP Set_register_bit                                    '3
   RJMP Clr_register_bit                                    '4
   RJMP Read_register_bit                                   '5
   RJMP Wait_unitl_bit_is_set                               '6
   RJMP Wait_unitl_bit_is_cleard                            '7
   RJMP Read_16_bit_register_incr_addr                      '8
   RJMP Read_16_bit_register_decr_addr                      '9
   RJMP Repeat_last_CMD_buffer_number                       'A
   RJMP Set_data                                            'B
   RJMP Process_reset                                       'C
   RJMP Process_reset                                       'D
   RJMP Process_reset                                       'E
   RJMP Process_reset                                       'F
'+--Konec IF stavkov--------------------------------------------------------+
'+----------------------------------------------------------+
'|    Pogoste Funkcije                                      |
'+----------------------------------------------------------+
Send_out_r16:                                               'Preverimo katera USART naprava je vkljuèena za pošiljanje                                      '
   sBIS UCSR0A,UDRE0                                        '1- Transmit is redy , 0- Transmit is busy
   rjmp Send_out_r16                                        'poèakaj, da je register za pošiljanje sprosti
   Out Udr0 , R16                                           '
ret
'...........................................................'
Set_bit_mask:                                               '!! v r18 MORA biti nastavljena Maska za druge bite (&HFF ali &H00)
   LDI r17,&HFF                                             'in nastavljen mora biti CARRIER bit na vrednost kakršno želimo da je naš
   Find_bit:                                                'bit v MASKI !!!!!
      inc r17                                               'r17 je ŠTEVEC bitov
      ROL r18                                               'r18 -> Bit value MASK (za bir 3 -> 0000_1000)
      CPSE r17, r19                                         'Compare, Skip if equal!! v r19 MORA shranjena le številka bita
      Rjmp Find_bit                                         'Poveèujemo številko bita dokler ne dosežemo pravega
   ret                                                      'Ko nastavimo masko bita, se vrnemo v program                                                         '
'...........................................................'
'+----------------------------------------------------------+
'|    Nabor funkcij                                         |
'+----------------------------------------------------------+
Proces_reset:                                               '0
   pop r18
   pop r18
   rjmp Process_reset
Read_register:                                              '1
   pop r18
   pop r18
   LD r16, x                                                '
   Rcall Send_out_r16
   rjmp Waiting_new_cmd
Set_data:                                                   'B
   pop r18
   pop r18
   MOV r16, xl
   RJMP Waiting_new_cmd
Set_register:                                               '2
   pop r18
   pop r18
   ST x, r16                                                '
   rjmp Waiting_new_cmd                                     '
'CMD=3, r19 0000_xbit , xl -> reg_addr
Set_register_bit:                                           '3
   pop r18
   pop r18
   LDI r18,&H00                                             '
   SEc                                                      '
   Rcall Set_bit_mask
   LD r17, x                                                '
   OR r17, r18                                              '
   ST x, r17                                                '
   rjmp Waiting_new_cmd                                     '
Clr_register_bit:                                           '4                                            '
   pop r18
   pop r18
   LDI r18,&HFF                                             '
   Clc                                                      '
   Rcall Set_bit_mask                                       '
   LD r17, x                                                '
   AND r17, r18                                             '
   ST x, r17                                                '
   rjmp Waiting_new_cmd                                     '
Read_register_bit:                                          '                                             '
   pop r18
   pop r18
   LDI r18,&H00                                             '
   SEc                                                      '
   Rcall Set_bit_mask                                       'MASK (za bir 3 -> 0000_1000)
   ld r16, x                                                'load Xaddr value in r16
   and r16,r18                                              '
   CPSE r16, r18                                            'Compare, Skip if equal!
   rjmp Bit_is_0                                            '
      ldi r16, 1                                            '
      Rcall Send_out_r16
      Rjmp Waiting_new_cmd                                  '
   Bit_is_0:                                                '
      LDI r16,0                                             '
      Rcall Send_out_r16
      Rjmp Waiting_new_cmd
Wait_unitl_bit_is_set:                                      '6
   pop r18
   pop r18
   LDI r18,&H00                                             '
   SEc                                                      '
   Rcall Set_bit_mask                                       'MASK (za bir 3 -> 0000_1000)
   Load_sr16:
      ld r16, x                                             'load Xaddr value in r16
      and r16,r18                                           '
      CPSE r16, r18                                         'IF x08=x18 -> Skip if equal!
      RJMP Load_sr16                                        '
   'SBi Tifr0,0                                              'resetiramo timerE0 interrupt
   RJMP Waiting_new_cmd
Wait_unitl_bit_is_cleard:                                   '
   pop r18
   pop r18
   LDI r18,&H00                                             '
   SEc                                                      '
   Rcall Set_bit_mask                                       'MASK (za bir 3 -> 0000_1000)
   Load_cr16:
      ld r16, x                                             'load Xaddr value in r16
      and r16,r18                                           '
      CPSE r16, r18                                         'IF x08=x18 -> Skip if equal!
         RJMP Exit_and_New_cmd                              '
   RJMP Load_cr16
   Exit_and_new_cmd:
   'SBi Tifr0,0                                              'resetiramo timerE0 interrupt
   RJMP Waiting_new_cmd
Read_16_bit_register_incr_addr:                             '
   pop r18
   pop r18
   LD r16, x+                                               '
   Rcall Send_out_r16
   LD r16, x
   Rcall Send_out_r16
   Rjmp Waiting_new_cmd
Read_16_bit_register_decr_addr:                             '
   pop r18
   pop r18
   LD r16, x                                                '
   Rcall Send_out_r16
   LD r16, -x
   Rcall Send_out_r16
   Rjmp Waiting_new_cmd
Repeat_last_cmd_buffer_number:
   pop r18
   pop r18
   'odštej število ukazov od r22
   Sub R22 , Xl
   ' in še -2 ukaza
   SUBI r22, &h02
   Rjmp Waiting_new_cmd
$end Asm
Goto Process_reset
End