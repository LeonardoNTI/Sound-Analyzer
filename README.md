Sound Analyzer

Beskrivning
Sound Analyzer är en Arduino-baserad ljudanalysator som använder en mikrofon för att sampla ljudsignalen och sedan utföra en snabb Fourier-transform (FFT) för att bestämma de dominerande frekvenserna. Det visar sedan den dominerande frekvensen och dess motsvarande not på en OLED-skärm. Dessutom kan känslighetsfaktorn för ljudanalysen justeras med hjälp av en potentiometer.

Funktioner
Utför ljudanalys med en mikrofon och en potentiometer för att justera känsligheten.
Använder FFT för att bestämma dominerande frekvenser i ljudsignalen.
Visar den dominerande frekvensen och dess motsvarande not på en OLED-skärm.
Justerbar känslighetsfaktor för att anpassa ljudanalysen för olika ljudmiljöer.
Komponenter
Arduino-kort (kompatibelt med SPI och I2C).
Mikrofon.
Potentiometer.
OLED-skärm (SSD1306-kompatibel).
Nödvändiga komponenter och anslutningskablar.
Användning
Anslut mikrofonen och potentiometern till de analoga ingångarna på Arduino-kortet.
Anslut OLED-skärmen till de korrekta pinnarna på Arduino enligt beskrivningen i koden.
Ladda upp koden till Arduino-kortet.
Justera känslighetsfaktorn med potentiometern.
Observera den dominerande frekvensen och dess motsvarande not på OLED-skärmen.
Installation
Klona detta GitHub-repositorium till din lokala maskin.
Anslut Arduino-kortet till din dator och öppna Arduino IDE.
Öppna den nedladdade koden i Arduino IDE.
Kontrollera att du har de nödvändiga biblioteken installerade. Du kan installera dem via "Sketch > Include Library > Manage Libraries" i Arduino IDE.
Ladda upp koden till Arduino-kortet och övervaka seriell utgång för debugging om det behövs.
Bidrag
Bidrag är välkomna! Om du har förslag till förbättringar eller nya funktioner, var god öppna en GitHub-issue eller skicka en pull-förfrågan.
