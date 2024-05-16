# Sound Analyzer

![Demo](demo.gif)

## Beskrivning
Sound Analyzer är en Arduino-baserad ljudanalysator som använder en mikrofon för att sampla ljudsignalen och sedan utföra en snabb Fourier-transform (FFT) för att bestämma de dominerande frekvenserna. Det visar sedan den dominerande frekvensen och dess motsvarande not på en OLED-skärm. Dessutom kan känslighetsfaktorn för ljudanalysen justeras med hjälp av en potentiometer.

## Funktioner
- Utför ljudanalys med en mikrofon och en potentiometer för att justera känsligheten.
- Använder FFT för att bestämma dominerande frekvenser i ljudsignalen.
- Visar den dominerande frekvensen och dess motsvarande not på en OLED-skärm.
- Justerbar känslighetsfaktor för att anpassa ljudanalysen för olika ljudmiljöer.

## Komponenter
- Arduino-kort (kompatibelt med SPI och I2C).
- Mikrofon.
- Potentiometer.
- OLED-skärm (SSD1306-kompatibel).
- Nödvändiga komponenter och anslutningskablar.

## Användning
1. Anslut mikrofonen och potentiometern till de analoga ingångarna på Arduino-kortet.
2. Anslut OLED-skärmen till de korrekta pinnarna på Arduino enligt beskrivningen i koden.
3. Ladda upp koden till Arduino-kortet.
4. Justera känslighetsfaktorn med potentiometern.
5. Observera den dominerande frekvensen och dess motsvarande not på OLED-skärmen.

## Installation
1. Klona detta GitHub-repositorium till din lokala maskin.
2. Anslut Arduino-kortet till din dator och öppna Arduino IDE.
3. Öppna den nedladdade koden i Arduino IDE.
4. Kontrollera att du har de nödvändiga biblioteken installerade. Du kan installera dem via "Sketch > Include Library > Manage Libraries" i Arduino IDE.
5. Ladda upp koden till Arduino-kortet och övervaka seriell utgång för debugging om det behövs.

## Bidrag
Bidrag är välkomna! Om du har förslag till förbättringar eller nya funktioner, var god öppna en GitHub-issue eller skicka en pull-förfrågan.
