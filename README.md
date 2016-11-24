# Arduino-Drone
Ein komplett selbstgebauter Arduino Uno Quadrocopter

##Inhalt
[1. Vorwort](#Vorw)  
[2. Teilliste](#Teil)  
[3. Zusammenbau](#Zusa)  
[4. Code](#Code)  
[5. PID-Kalibrierung](#PID)  
[6. Erster Start](#Erst)  
  
  
###1. Vorwort<a name="Vorw"></a>
Dieser Quadrocopter ist im Rahmen eines Schulprojekts entstanden.  
Es handelt sich nicht um ein professionelles, komplett ausgereiftes Industrieprodukt und Fehler im Code sind zu erwarten. Im Umgang mit der Drohne rate ich zu großer Vorsicht. Es können durch den Quadrocopter ernsthafte Verletzung zugefügt werden.(Link noch enzufügen)   Diese Anleitung beinhaltet alles, was man wissen muss, um einen Quadrocopter zu bauen. Fehler oder Ungenauigkeiten können aber enthalten sein.
  
  
###2. Teilliste<a name="Teil"></a>
In meinem Fall ist das gesamte Drohnengestell mithilfe eines 3D Druckers entstanden.  
Die dafür nötigen 3D Modelle sind repository enthalten und können frei verwendet werden. Wer keinen 3D Drucker zur Verfügung hat, kann ein fertiges Gestell kaufen, oder aus anderen Materialien selber eins bauen. Zu diesem Thema gibt es im Internet eine reichhaltige Menge an Informationen, die jederzeit abrufbar sind.  
  
Die Hardware die benötigt wird:  
* [Arduino Uno]()
* [Gyroscope]()
* [Brushless Motor]()
* [ESC]()
* [Lithium Akku]()
* [Fernsteuerung + Empfänger]()
* Wiederstände: [330](), [1k](), [1,5k]()
* [Schrumpfschlauch]() (nicht zwingend nötig, hilft aber sehr beim Isolieren)
  
  
###3. Zusammenbau<a name="Zusa"><a/>
Zuerst wird der Rahmen des Quqdrocopters zusemmengebaut.  
Jeder Rahmen ist unterschiedlich aufgebaut, im Fall des beigelegten Rahemns ist der Aufbau leicht verständlich. Es ist sinnvoll, die untere Platte vorerst nicht zu befestigen, da es dann einfacher ist, die Elektronik einzubauen.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0005.JPG)  
Sobald der Rahmen zusammengesetzt ist, kann die Hardware verbaut werden.
Der Quadrocopter kann mit den Teilen aus der [Teilliste](#Teil) gebaut werden, aber auch äquivalente Bauteile sollten funktionieren.  
Bei der Verkabelung ist darauf zu achten, das die Schematics beachtet werden, da es sonst später zu Fehlfunktionen kommen kann.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Schematics.jpg)  
Es ist am einfachsten, mit den ESCs zu beginnen.
Diese solltenmöglichst weit vom Zentrum entfernt sein, da sie sonst später das Gyroskop stören könnten.
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0007.JPG)  
Sobald die ESCs befestigt sind dreht man den Rahem um und befestigt nur das Gyroskop und den Empfänger, Doppelseitiges Klebeband ist für diesen Zweck geeignet. Die Kabel an diesen Teilen sollten schon vor dem Befestigen am Rahem festgelötet werden, da dies sonst schwierig werden könnte.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0003_16.JPG)  
Im nächsten Schritt wird das Arduino befestigt, wie genau das Arduino am Rahem befestigt werden kann muss jeder an seinem eigenen Rahem überprüfen, wenn der Rahmen aus den 3D Modellen verwendet wird ist eine spezielle Platte für diesen Zweck enthalten.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0002.JPG)  
Als letztes müssen die Motoren befestigt werden, dabei muss auf die Rotationsrichtung geachtet werden. Brushless Motoren besitzen drei Ausgänge, ein rotes Kabel, welches den Pluspol darstellt, ein schwarzes Kabel, welches den Minuspol darstellt und ein drittes Kabel, häufig gelb. Uns interessieren das Plus- und das Minuskabel, wenn man positiv mit positiv am ESC verbindet und negativ mit negativ dreht der Motor sich im Uhrzeigersinn, wenn positiv mit negativ und negativ mit positiv verbunden wird dreht der Motor sich gegen den Uhrzeigersinn. In allen Fällen muss auch das dritte Kabel angeschlossen werden, dies sollte immer an sein Äquivalent des ESCs angeschlossen werden.  
Es muss darauf das die Richtungen der Motoren beachtet werden, da der Quadrocopter später sonst nicht fliegen kann. 
  
| Motor         | Bezeichnung | Richtung            |
|---------------|:-----------:|:-------------------:|
| vorne rechts  | Motor 1     | Uhrzeigersinn       |
| hinten rechts | Motor 2     | gegen Uhrzeigersinn |
| hinten links  | Motor 3     | Uhrzeigersinn       |
| vorne links   | Motor 4     | gegen Uhrzeigersinn |  
  
In der Praxis sollte es so Aussehen  
Uhrzeigersinn  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0020_5.JPG)  
Gegen Uhrzeigersinn  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0019_5.JPG)  
  
Jetzt ist die gesamte Hardware verbaut, im nächsten Schritt muss diese verkabelt werden. Ich empfehle alle Verbindungen zu löten, da so eine feste Verbindung entsteht, aber auch z.B. Kabelhülsen sollten funktionieren. In jedem Fall muss sich streng an die Schematics gehalten werden!  
Zum besseren Verständis der Verbindungen  
Verbindung der ESCs falls der Rahmen kein PDB (power distribuition board) enthält  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0005_11.JPG)  
Kabel am Arduino  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0021_5.JPG)  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0027_5.JPG)
  
Als letztes kann über das Arduino ein Schutz angebracht werden, damit es nicht ungeschützt ist beim Transport/Flug. Bei den 3D Modellen liegt ein derartiger Schutz bei, ob man diesen verwendet oder selber etwas anderes baut spielt keine große Rolle solange es gegen Einschläge schützt.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0032_5.JPG)  
  
  
###4. Code<a name="Code"><a/>
Um die Drohne verwenden zukönnen werden drei Arduino Sketches benötigt.  
[1. Setup](#Setup)  
[2. Calibration](#Calib)  
[3. Flight Controller](#Flight)  
  
Der erste Sketch ist ein Setup, in dem alle Bauteile der Drohne überprüft werden und sowohl die Fernbedienung, als auch das Gyroskop für das Arduino kalibiriert werden. Die Ergebnisse der Kalibrierungen werden im EEPROM, dem Speicher des Arduinos, gespeichert. Das Programm läuft über den seriellen Monitor des Arduinos.    
Der zweite Sktech wird verwendet, um die Ergebnisse der Kalibrierung zu testen. Im seriellen Monitor können durch bestimmte Befehle unterschiedliche Daten aufgerufen werden, darauf gehe ich aber erst im letzten Teil dieser Anleitung ein, da dies sonst zu umfangreich wird: [Der erste Start](#Erst).  
Der dritte Sktech ist der flight controller, mit diesem wird die Drohne letztlich gesteuert. Es ist eine Sicherungsfunktion enthalten, aber trotzdem sollte beim Start immer ein Sicherheitsabstand eingehalten werden.  
Alle diese drei Sketches müssen vom ersten zum dritten auf den Arduino geladen werden, ausgeführt werden und nur wenn keine Fehler während den Prgrammen auftauchen darf das nächste installiert werden. Bei nicht Beachtung der Reihenfolge kann es zu schweren Fehlern kommen.  
  
Zum Grundverständnis erkläre ich an dieser Steller erstmal, wie der Quadrocopter seine Position und die Befehle der Fernbedienung "versteht". Im folgenden Text wird häufig von einem Puls zwischen 1000 und 2000 gesprochen. Dieser Puls bedeutet eigentlich nur, dass die Fernbedienung die Befehle mit einer Frequenz von 1000 bis 2000 Herz an den Empfänger sendet. Das Arduino rechnet auch mit dieser Frequenz und rechnet alle Positionen auch. Es wäre auch möglich dies in ein kleineres Format im Arduino für die Rechunungen umzuwandeln, dass Ergebnis wäre aber dasselbe und führt innerhalb des Codes zu Verwirrung. Während dem Setup wird auch an die ESCs diese Frequenzwreichweite übertragen, da diese auch mit Pulsen arbeiten. Wenn eine Reichweite von 1000 mögliche Pulsen existiert ist auch eine sehr genaue Bestimmung der Werte möglich und sehr genaue Ergebnisse können innerhalb des Codes produziert werden.  
Die Werte 1000 bis 2000 sind also nicht frei erfunden und nur als Variablen festgelegt, sondern durch die Fernbedienung definiert und müssen so verwendet werden.  
  
Der gesamte Code kann eingesehen und modifiziert werden. Der Code ist durch viele Kommentare verständlich gemacht und sollte verständlich sein. Inwiefern Modifikationen sinnvoll sind und wo diese vorgenommen werden sollten wird im später Verlauf dieser Dokumentation aufgegriffen.  
Direkte Weiterleitungen zum Code:  
[Setup](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Setup.ino)  
[Calibration](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Calibrate.ino)  
[Flight controller](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Flight%20controller.ino)  
  
####Setup<a name="Setup"><a/>
Im Setup wird die gesamte Hardware für das Arduino kalibriert. Um dies zu tun muss der Setup Sketch auf den Arduino geladen werden und am PC im Arduino Programm der serielle Monitor geöffnet werden. Im seriellen Monitor muss die Baudrate auf 57600 eingestellt werden für diesen Vorgang.  
Falls während dem Setup Fehler auftreten wird ein Fehlercode angezeigt, jeder Fehler ist dokumentiert und mit Lösungen versehen. Diese Lösungen werden im späteren Verlauf dieser Anleitung dokumentiert. [Abkürzung zu Fehlercodes](#Fehler)  
Nun wird ein Programm Ablauf gezeigt, dem man als Nutzer nur folgen und die Befehle befolgen muss.  
Zuerst werden die Endposition der Fernbedienung kalibriert. Dabei ist zu beachten das "nose down" auf dem rechten Steuerknüppel nach unten bedeutet. Wenn der Quadrocopter seine Nase hoch zieht bewegt der Quadrocopter sich nach hinten.  
Sobald die Kalibrierung der Fernbedienung abgeschlossen ist beginnt die Kalibrierung des Gyroskops. Zu diesem Zweck wird das Programm den Nutzer dazu auffordern, den Quadrocopter in bestimmte Positionen zu bewegen. Dabei muss darauf geachtet werden, das die Richtigen Seiten bewegt werden, da es sonst später zu Fehlern kommen kann.  
Der letzte Schritt ist die Kontrolle der Status LED, diese sollte aufleuchten, wenn der Befehl dazu im seriellen Monitor angezeigt wird. Prinzipiell ist die LED nicht nötig, falls aber später Probleme auftreten kann an der Blinkfrequenz erkannt werden, um welchen Fehler es isch handelt und erfüllt somit eine wichtige Rolle.  
  
Nun sollte das Programm anzeigen, dass der Vorgang abgeschlossen ist und der serielle Monitor kann geschlossen werden.  
An dieser Stelle ist das Setup abgeschlossen, es kann zum nächsten Schritt übergegangen werden.  
Wer aber noch daran interessiert ist, wie der Code aufgebaut ist und wie die Informationen im EEPROM gespeichert werden, kann an [dieser Stelle]() im Code lesen, alle Informationen sind Open Source und es darf daran alles verändert werden, doch macht es bei diesem Teil wenig Sinn etwas zu modifizieren, im späteren Verlauf wird dieser Schritt noch wichtiger.  
Der Code ist zum besseren Verständis mit Kommentaren versehen, es sollte nicht nötig sein, sich groß einlesen zu müssen, um den Inhalt zu verstehen.  
  
#####Calibration<a name="Calib"><a/>
Das zweite Programm, welches installiert werden muss, ist die Kablibrierung.  
Dieser Sketch unterscheidet sich stark vom Setup, es wird nichts auf dem EEPROM verändert.  
Sobald der Sketch auf den Arduino geladen ist muss wieder der serielle Monitor geöffnet werden, es wird weiterhin die baud rate 57600 verwendet.  
Nun gibt es mehrere Befehle, die ausgeführt werden können und zum überprüfen der Funktionen des Gyroskop, die Fernbedienung und die Schwingung der Motoren kann überprüft werden.  
Wenn in den seriellen Monitor **a** eingegeben wird, zeigt der serielle Monitor die Position des Gyroskops. Zu beachten ist, dass Yaw bedeutet, inwieweit der Quadrocopter auf dem Boden gedreht wurde und setzt sich selbstständig zurück in die Nullposition. Es sollte eine perfekte Nullstellung erreicht werden, da der Quadrocopter sonst nie ruhig in der Luft stehen kann.  
  
Als nächstes wird in den seriellen Monitor **r** eingegeben, mit diesem Befehl werden die Daten der Fernbedienung aufgerufen. Im seriellen Monitor werden nun vier unterschiedliche Daten angezeigt.  
In der Nullstellung aller Steuerknüppel sollten solche Ergebnisse gezeigt werden. 
![alt text]()  
Die Werte sollten sich zwischen 1000 und 2000 befinden, der Anstieg/Abfall der Werte sollte gleichmäßig sein und nicht springen, da es sonst später zu Problemen kommen. Minimale Abweichungen sind unproblematisch, es sollten nur keine Großen sein.  
  
Mit den Befehlen **1-5** kann entwededer von jedem Motor einzeln die verursachte Vibration überprüft werden, zu diesem Zweck sollte auf den Motoren Propeller befestigt werden. Im Idealfall liegt die Vibration unter 50, dies ist kein Referenzwert, der mit anderen Werten verglichen werden kann. Der Test sollte bei 50% Beschleunigung ablaufen, in dieser Position sollte der Quadrocopter knapp nicht abheben und es werden gute Ergebnisse erzeugt. Bei diesem Test ist größte Vorsicht geboten, der Quadrocopter kann schwere Verletzungen zufügen und es sollten mindestens **fünf Meter** Sicherheitsabstand gehalten werden, ideal sind **zehn Meter**. Die genaue Benennung der Rotoren ist, zur Erinnerung welcher Motor an welcher Stelle am Quadrocopter ist: [Motorenanordnung]().  
  
| Motor	    | Command |
|-----------|:-------:|
| Motor 1	  | 1       |   			
| Motor 2   | 2       |
| Motor 3	  | 3       |
| Motor 4	  | 4       |
| Motor 1-4 | 5       |
  
####Flight Controller<a name="Flight"><a/>
Das dritte Programm ist das, dass letztendlich für das Fliegen verwendet wird. Dieser Sketch greift auf die Daten, die im EEPROM abgelegt wurden, zurück und verwendet sie als Grundlage der Berechnungen für die Stabilität. Die vorherigen Schritte müssen genau befolgt werden, da sonst Fehler beim Flug entstehen können.  
  
Das Gyroskop gleicht beim Flug permanent den Quadrocopter aus, sodass zu keinem Zeitpunkt, wenn kein Befehl abgesehen von der senkrechten Beschleunigung übertragen wird, der Quadrocopter in eine nicht horizontale Position gerät.  
Der Ablauf im Sketch hinter dieser Mechanik ist, dass das Gyroskop permanent die Position des Quadrocopters überprüft. Im Sketch ist festgelegt, dass in der Nullstellung des Gyroskops und der Fernbedienung ein Puls von 1500 an die ESCs gesendet wird. Nullstellung bedeutet, dass der Quadrocopter senkrecht zum Boden ausgerichtet ist. Die ESCs sind auf die Frequenz von 1000 bis 2000 kalibiriert.  
Wenn nun der Winkel, in dem sich der Quadrocopter relativ zum Boden befindet, verändert wird, so rechnet das Arduino eine definierte Antisteigung, also die aktuelle Position abgezogen von der Standartpoition, aus und ermittelt einen Gegenimpuls, der an die ESCs geschickt wird.   
Im Sketch ist festgelegt, dass wenn die senkrechte Beschleunigung, also der linke Steuerknüppel, in der untersten Position ist der Quadrocopter 0% Motor-Output aufbringt. Der Output steigt linear bis auf 100% in maximal-Stellung an. Wichtig ist dabei zu wissen, dass bei 50% der Quadrocopter stabil in der Luft steht und weder steigt noch sinkt. Bei unter 50% wird ein Absinken und bei über 50% ein Ansteigen zu beobachten sein. Falls dies nicht richtig funktioniert müssen die Fernbedienung und der Quadrocopter neu kalibriert werden. Das kalibrieren des Quadrocopters muss erneut über das Setup durchgeführt werden und sollte nicht übersprungen werden.   
  
Wenn der Quadrocopter sich also in der Ausgangslage befindet, wird ein Puls von 1500 an den PID-controller gesendet (dieser wird im [nächten Teil](#PID) genauer erklärt) und es wird keine Veränderung vorgenommen. Wenn nun aber auf der Fernbedienung der Befehl Roll gegeben wird mit halber Beschleunigung, also der rechte Steuerknüppel 50% nach rechts gedrückt, so wird der Wert auf 1750 erhöht. Nun kippt der Quadrocopter kontinurilch nach rechts. Das Gyroskop nimmt diese Veränderung der Lage wahr und rechnet seine eigene Rechnung dagegen. Im Code ist festgelegt, das für jeden 1°, den der Quadrocopter gekippt ist, ein Puls von 15 gegengerechnet wird. Wenn beim Rollen nun also 5° erreicht sind wird gegen die 1750, die von der Fernbedienung ausgegeben werden und vom Arduino verwendet werden ein Wert von 75 gegengerechnet, der interne Wert für die Position ist nun also 1675. Das Rollen wird soweit weitergeführt, bis der Wert von 1500 erreicht und und der Quadrocopter damit seine Zielposition, die er immer erreichen möchte erreicht hat. Dieser Fall tritt in diesem Fall bei 16,7° ein. Wenn man also den Befehl fürs Rollen mit 50% Leistung gibt, wird der Quadrocopter bis auf 16,7° kippen und in dieser Position bleiben, bis ein neuer Befehl von der Fernbedienung gegeben wird. Maximal möglich sind 33,3°, dieser Wert wird als allgemein sicher anerkannt und führt zu guter Beschleunigung und gut kontrolliebarem Flugverhalten. Weiteres Rollen würde zu höherer Beschleunigung führen, aber auch die Gefahr eines Überschlags erhöht sich. Diese Werte gelten genauso für Pitch und Yaw, nur die senkrechte Beschleunigung ist nich von diesen berechnung betroffen.  
  
Wenn der Maximalwinkel größer/kleiner sein soll muss am Code eine Veränderung vorgenommen werden. Dies ist in Zeile 14 und 22 des flight controllers möglich. Wenn der Wert erhöht wird steigt der maximale Winkel, wenn der Wert verkleinert wird sinkt der maximale Winkel. Es kann sinnvoll sein den Winkel zu verkleinern wenn die Drohne dem Nutzer zu aggressiv reagiert.  
Auch der Standartwert von α=1°=15 kann verändert werden. An diesem Wert zu modifizieren ist eher nicht empfehlenswert, da der Quadrocopter selbst bei kleinen Veränderungen sehr aggressiv reagieren kann. Wenn der Maximalwinkel verändert werden soll ist es sinnvoller die vorherige Methode zu verwenden.  
  
Falls der Quadrocopter anders reagiert, als man erwarten würde und das Problem mit dem Gyroskop in verbindung stehen könnte kann die gesamte auto level Funktion deeaktiviert werden. Dies ist in Zeile 24 möglich. Es ist wichtig zu bedenken, dass mit dieser Einstellung auf false keine Flugunterstützung mehr existiert, es muss manuell gegengelenkt werden, im allgemeinen rate ich von einem Flug ohne auto level Funktion ab.  
  
Falls noch weitere Unklarheiten bezüglich des flight controllers existieren kann jede Einzelheit [hier](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Flight%20controller.ino) im Code nachgelsesen werden. Der gesamte Code ist mit Kommentaren zum besseren Veständnis gefüllt und es sollte keien Stelle unverstädnlich bleiben.  
  
  
5. PID Kalibrierung<a name="PID"><a/>
Die PID Werte sind das Erste, was man sehen wird, sollte man den Code des flight controllers öffnen.  
Diese PID Werte sind essentiell für die auto level Funktion des Quadrocpters, die das besondere an diesem gesamten Projekt ist. Zum Verständis ist es als erstes sinnvoll zu verstehen, wofür PID steht.  
* P steht für proportinal, an dieser Stelle wird **Output des Gyroskops - Output des receivers * P(gain)** gerechnet. Wenn nun der Quadrocopter in einer 10° Lage gekippt zum Boden sich befindet und 1°=15 => 10*15=150. Nehmen wir nun an, von der Fernbedienung wird kein Befehl gesendet, der eine solche Veränderung der Lage herbeiführt, so wird der Quadrocopter nun versuchen, in die Standartposition von 1500 zurückzukehren. Aus der Rechnung ergibt sich also, dass der aktuelle Wert 1650 entspricht, aber 1500 angepeilt werden. Theoretisch sollte diese Funktion ausreichen, um den Quadrocopter in eine stabile Position zu bringen. Wenn man aber nur diese Funktion verwendet, so wird man feststellen, dass der Quadrocopter anfängt gleichmäßig zu 
  













##6. Erster Start<a name="Erst"><a/>
Sobald der Sketch auf dem Arduino gespeichert ist, ist die Drohne flugbereit. Beim Start gilt es bestimmte Dinge zu beachten:  
1. Um den Quadrocopter zu starten muss an der Fernbedienung der throttle stick in die untere, linke Ecke bewegt werden. Erst ab diesem Moment ist Sicherung deaktiviert.  
2. Um den Quadrocopter auszuschalten muss der throttle sitck in die untere, rechte Ecke bewegt werden, dies löst die Sicherung aus und keine weiteren Befehle werden umgesetzt.  
3. Sobald die Sicherung deaktiviert ist muss der Quadrocopter gestartet werden. Die ersten Sekunden ist der Ausgleich durch das Gyroskop deaktiviert, sodass die Drohne senkrecht starten kann und erst in der Luft sich ausgleicht. Auch sollte insofern zügig gestartet werden, dass ein schnelles Abheben auf mindestens 20 Centimeter gewährleistet ist und die Drohne sich nicht am Boden verfangen kann.
4. Vor und während dem Flug ist Sicherheitsabstand einzuhalten. Ein Start aus der Hand ist zwingend zu vermeiden, da durch Windstöße oder Fehler des Programms die Drohne aggressiv reagieren kann und somit den Nutzer schwer verletzen kann.  
5. Es ist durchaus damit zu rechnen, dass erste Flugversuche fehlschlagen. Es sollte von Beginn an eingeplant werden, dass einige Propeller kaputt gehen. Die gegebenen PID Werte sollten einen stabilen Flugzu gewährleisten, es können aber dennoch Probleme auftreten. Um diese Probleme zu beheben müssen die PID Werte angepasst werden, wie dies möglich ist wurde im [vorherigen Teil](#) erklärt.  
  
Wenn der erste Flug erfolgreich verlaufen ist, sollten alle Teile des Quadrocopter überprüft werden. Selbst bei einem erfolgreichen Flug können Schäden entstehen, der Rahmen sollte besonders genau betrachtet werden, da durch die Motoren starke Kräfte auf diesen ausgewirkt werden. Falls Risse oder ähnliche Schäden auftreten müssen diese behoben werden, es darf nicht mit defekten Teilen geflogen werden.  
  
Ein derartiger Riss kann zum Beispiel so Aussehen  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0031_5.JPG)  
  
  
##7. Fehlerodes<a name="Fehler"><a/>
