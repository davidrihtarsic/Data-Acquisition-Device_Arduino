SET _Prog=eProDas-FTDI
SET _uK=m16
SET _speed=4800
SET maxFAQ=2
:zacetek
SET Key1=
SET Key2=
SET sKey=
SET Second_menu=0

:menu
@echo OFF
cls
@echo **************************************
@echo *        -= AVRdude TEST =-          *
@echo **************************************
@echo Nastavitve:
@echo  - Programator   [p]: %_Prog%
IF "%sKey%"=="p" (
set Second_menu=1
@echo                  [1]: eProDas-FTDI
@echo                  [2]: ft232r0
)
@echo  - Mikrokrmilnik [m]: %_uK%
IF "%sKey%"=="m" (
set Second_menu=1
@echo                  [1]: AT mega 16
@echo                  [2]: AT Tiny 261
)		
@echo  - Hitrost       [b]: %_speed%
IF "%sKey%"=="b" (
set Second_menu=1
@echo                  [1]: 600
@echo                  [2]: 1200
@echo                  [3]: 2400
@echo                  [4]: 4800
@echo                  [5]: 9600
@echo                  [6]: 19200
@echo                  [7]: 38400
@echo                  [8]: 57600
)
@echo **************************************
@echo Zazeni AVRdude   [r]
@echo Pomoc            [h]
@echo Koncaj testiranje[x]
@echo **************************************
@echo Izberi moznost in pritisni ENTER
@echo OFF
IF "%Second_menu%"=="0" ( set /p Key1= )
IF "%Second_menu%"=="1" ( 
	SET Second_menu=0
	set /p Key2=
)
SET sKey=%Key1%%Key2%

:Actons
IF "%sKey%"=="r" ( goto Run_avrdude )
IF "%sKey%"=="h" ( goto Help )
IF "%sKey%"=="x" ( goto Konec )  
:Set_Programator
IF "%sKey%"=="p1" ( SET _Prog=eProDas-FTDI )
IF "%sKey%"=="p2" ( SET _Prog=ft232r0 )
:Set_MicroController
IF "%sKey%"=="m1" ( SET _uK=m16 )
IF "%sKey%"=="m2" ( SET _uK=t261 )
:Set_Speed
IF "%sKey%"=="b1" ( SET _speed=600 )
IF "%sKey%"=="b2" ( SET _speed=1200 )
IF "%sKey%"=="b3" ( SET _speed=2400 )
IF "%sKey%"=="b4" ( SET _speed=4800 )
IF "%sKey%"=="b5" ( SET _speed=9600 )
IF "%sKey%"=="b6" ( SET _speed=19200 )
IF "%sKey%"=="b7" ( SET _speed=38400 )
IF "%sKey%"=="b8" ( SET _speed=57600 )

IF not %Key1%.==. (
	IF not %Key2%.==. (
		SET Key1=
		SET Key2=
	)
)
goto menu

:Run_avrdude
	@echo ON
	cls
	avrdude.exe -p %_uK% -P ft0 -c %_Prog% -B %_speed%
	@echo OFF
	set /p BtnNext= Pritisnite ENTER za izhod.
	goto menu
:Help
    cls
	@echo ON
	@echo **************************************
	@echo *    Pogosta vprasanja in odgovori   *
	@echo **************************************
	@echo [1/%maxFAQ%] Ne prepozna USB vmesnika in vrne napako "ft0 open faild"
	@echo ============================================================
	@echo - Morda se USB komunikacija se ni vzpostavila dokoncno. Poizkusite
	@echo   s povezavo cez nekaj sekund. Veckrat.
	@echo - Morda je USB komunikacija v "spanju" (sleep mode) ponovno izkljucite
	@echo   USB vmesnik in ga prikljucite. Poèakajte nekaj sekund in poizkusite
	@echo   ponovno vzpostaviti komunikacijo.
	@echo - Morda se niste namestili gonilnikov. Najlazje bo, ce racunalnik
	@echo   povezete z internetom, prikljucite USB vmesnik in prepustite naj
	@echo   program najde gonilnike v spletu.
	@echo ------------------------------------------------------------
	@echo OFF
	set /p BtnNext= [n]-Naslednji FAQ    [q]-Koncaj s pomocjo :
	IF "%BtnNext%"=="q" ( goto Konec_Helpa )
	cls
	@echo ON
	@echo **************************************
	@echo *    Pogosta vprasanja in odgovori   *
	@echo **************************************
	@echo [2/%maxFAQ%] Vmesnik USB se razpozna, vendar ne morem vzpostaviti
	@echo komunikacije z mikrokrmilnikom.
	@echo ============================================================
	@echo - Morda niste pravilno povezali USB vmesnika z mikrokrmilnikom.
	@echo   Se enkrat preverite povezave MISO, MOSI, SCK, RESET in GND.
	@echo - Morda je komunikacija USB vmesnika prehitra. Zmanjsajte hitrost
	@echo   na najmanjso mozno vrednost in jo nato postopoma povecujte.
	@echo   Hitrost nastavite s tipko [b] in nato izberite moznost [1].
	@echo - Preglejte napajanje mikrokrmilnika, ce ste ga pravilno prikljucili.
	@echo   Ne pozabite povezati GND prikljucek mikrokrmilnika z GND
	@echo   prikljuckom na USB vmesniku
	@echo ------------------------------------------------------------
	@echo OFF
	set /p BtnNext= [n]-Naslednji FAQ    [q]-Koncaj s pomocjo :
	IF "%BtnNext%"=="q" ( goto Konec_Helpa )
:Konec_Helpa	
	goto menu
:Konec