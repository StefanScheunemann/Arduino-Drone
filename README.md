# Arduino-Drone
Eine Anleitung für den Bau eines Quadrocopters

##Inhalt
[1. Vorwort](#Vorw)  
[2. Teileliste](#Teil)  
[3. Zusammenbau](#Zusa)  
[4. Code](#Code)  
[5. PID-Kalibrierung](#PID)  
[6. Erster Start](#Erst)  
[7. Fehlercodes](#Fehler)
[8. Quellen](#Quel)
  
  
###1. Vorwort<a name="Vorw"></a>
Dieser Quadrocopter ist im Rahmen eines Schulprojekts entstanden.  
Es handelt sich nicht um ein professionelles, komplett ausgereiftes Industrieprodukt und Fehler im Code sind zu erwarten. Im Umgang mit der Drohne rate ich zu großer Vorsicht. Es können durch den Quadrocopter ernsthafte Verletzungen und Schäden zugefügt werden, [hier eine realistische Einschätzung zu den Gefahren](http://www.technik-consulting.eu/Analyse/Gef%C3%A4hrdung_Drohne.html). Diese Anleitung beinhaltet Alles, was man wissen muss, um einen Quadrocopter zu bauen. Fehler oder Ungenauigkeiten können aber enthalten sein. In den Quellen können genaue Angaben gefunden werden, von welchen Stellen Code und Rahmen übernommen wurden.  
  
  
###2. Teileliste<a name="Teil"></a>
In meinem Fall ist das gesamte Drohnengestell mithilfe eines 3D Druckers entstanden.  
Die dafür nötigen 3D Modelle sind repository enthalten und können frei verwendet werden. Wer keinen 3D Drucker zur Verfügung hat, kann ein fertiges Gestell kaufen, oder aus anderen Materialien selber eins bauen. Zu diesem Thema gibt es im Internet eine reichhaltige Menge an Informationen, die jederzeit abrufbar sind.  
  
Die Hardware, die benötigt wird:  
* [Arduino Uno](https://www.arduino.cc/en/Main/arduinoBoardUno)
* [Gyroscope](http://www.dx.com/p/gy-521-mpu6050-3-axis-acceleration-gyroscope-6dof-module-blue-154602?Utm_rid=78761898&Utm_source=affiliate#.WDmRYVxhN-4)
* [Brushless Motor + ESC combo](http://eud.dx.com/product/a2212-1000kv-brushless-motor-w-30a-brushless-esc-1045-propeller-dji-f450-550-844413446)
* [Lithium Akku](http://eud.dx.com/product/11-1v-2200mah-30c-li-polymer-battery-pack-for-450-helicopter-dji-phantom-1-450-quadcopter-844366131)
* [Akku Ladegerät](http://www.dx.com/p/b3ac-2s-3s-lipo-balance-charger-black-ac-100-240v-103589?Utm_rid=78761898&Utm_source=affiliate#.WDmRYlxhN-4)
* [Fernsteuerung + Empfänger](http://eud.dx.com/product/flysky-fs-t6-2-4ghz-6-ch-2-9-lcd-tx-transmitter-rx-receiver-radio-control-system-black-8-x-aa-844178448)
* Widerstände: [330](https://www.conrad.de/de/metallschicht-widerstand-330-axial-bedrahtet-0207-06-w-yageo-mf0207fte52-330r-1-st-1417595.html), [1k](https://www.conrad.de/de/metallschicht-widerstand-1-k-axial-bedrahtet-0207-06-w-yageo-mf0207fte52-1k-1-st-1417606.html), [1,5k](https://www.conrad.de/de/metallschicht-widerstand-15-k-axial-bedrahtet-0207-06-w-1-st-423386.html)
* [Schrumpfschlauch](https://www.amazon.de/ChiliTec-12000058-Chilitec-Schrumpfschlauch-Sortiment-100-teilig/dp/B003H9CJ1Y/ref=pd_lpo_60_bs_lp_t_2?_encoding=UTF8&psc=1&refRID=713FAHSKXA3QCSARH8TW) (nicht zwingend nötig, hilft aber beim Isolieren)
  
  
###3. Zusammenbau<a name="Zusa"><a/>
Zuerst wird der Rahmen des Quadrocopters zusammengebaut.  
Jeder Rahmen ist unterschiedlich aufgebaut. Im Fall des beigelegten Rahmens ist der Aufbau leicht verständlich. Es ist sinnvoll, die untere Platte vorerst nicht zu befestigen, da es dann einfacher ist, die Elektronik einzubauen.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0005.JPG)  
Sobald der Rahmen zusammengesetzt ist, kann die Hardware verbaut werden.
Der Quadrocopter kann mit den Teilen aus der [Teileliste](#Teil) gebaut werden, aber auch äquivalente Bauteile sollten funktionieren.  
Bei der Verkabelung ist darauf zu achten, dass die schematics beachtet werden, da es sonst später zu Fehlfunktionen kommen kann.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Teilliste%20%2B%20Schematics/Schematics.jpg)  
Es ist am einfachsten, mit den ESCs zu beginnen.
Diese sollten möglichst weit vom Zentrum entfernt sein, da sie sonst später das Gyroskop stören könnten.
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0007.JPG)  
Sobald die ESCs befestigt sind, dreht man den Rahmen um und befestigt nur das Gyroskop und den Empfänger. Doppelseitiges Klebeband ist für diesen Zweck geeignet. Die Kabel an diesen Teilen sollten schon vor dem Befestigen am Rahmen festgelötet werden, da dies anderenfalls schwierig werden könnte.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0003_16.JPG)  
Im nächsten Schritt wird das Arduino befestigt. Wie genau das Arduino am Rahmen befestigt werden kann, muss jeder an seinem eigenen Rahmen überprüfen. Wenn der Rahmen aus den 3D Modellen verwendet wird, ist eine spezielle Platte für diesen Zweck enthalten.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0002.JPG)  
Als Letztes werden die Motoren befestigt. Dabei muss auf die Rotationsrichtung geachtet werden. Brushless Motoren besitzen drei Ausgänge, ein rotes Kabel, welches den Pluspol darstellt, ein schwarzes Kabel, welches den Minuspol darstellt und ein drittes Kabel als Erdung, häufig gelb. Uns interessieren das Plus- und das Minuskabel. Wenn man Positiv mit Positiv am ESC verbindet und Negativ mit Negativ, dreht sich der Motor im Uhrzeigersinn. Wenn Positiv mit Negativ und Negativ mit Positiv verbunden wird, dreht sich der Motor  gegen den Uhrzeigersinn. In allen Fällen muss auch das dritte Kabel angeschlossen werden. Dies sollte immer an sein Äquivalent des ESCs angeschlossen werden.  
Es muss darauf geachtet werden, dass die Richtungen der Motoren stimmen, da der Quadrocopter später sonst nicht fliegen kann. 
  
| Motor         | Bezeichnung | Richtung            |
|---------------|:-----------:|:-------------------:|
| vorne rechts  | Motor 1     | Uhrzeigersinn       |
| hinten rechts | Motor 2     | gegen Uhrzeigersinn |
| hinten links  | Motor 3     | Uhrzeigersinn       |
| vorne links   | Motor 4     | gegen Uhrzeigersinn |  
  
In der Praxis sieht es wie auf den folgenden Bildern aus.  
Uhrzeigersinn  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0020_5.JPG)  
Gegen Uhrzeigersinn  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0019_5.JPG)  
  
Jetzt ist die gesamte Hardware verbaut. Im nächsten Schritt wird diese verkabelt.  
Ich empfehle, alle Verbindungen zu löten, da so eine feste Verbindung entsteht. Aber auch z.B. Kabelhülsen funktionieren. In jedem Fall muss sich streng an die schematics gehalten werden!  
Zum besseren Verständis der Verbindungen  
Verbindung der ESCs, falls der Rahmen kein PDB (power distribuition board) enthält  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0005_11.JPG)  
Kabel am Arduino  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0021_5.JPG)  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0027_5.JPG)
  
Abschließend ist es von Vorteil, über das Arduino einen Schutz anzubringen, damit es nicht ungeschützt beim Transport bzw. Flug ist. Bei den 3D Modellen liegt ein derartiger Schutz bei, ob man diesen verwendet oder selber etwas anderes baut, spielt keine große Rolle, solange es gegen Einwirkungen von außen schützt.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0032_5.JPG)  
  
  
###4. Code<a name="Code"><a/>
Um die Drohne verwenden zu können, werden drei Arduino Sketches benötigt.  
[1. Setup](#Setup)  
[2. Calibration](#Calib)  
[3. Flight Controller](#Flight)  
  
Der erste Sketch ist ein Setup, in dem alle Bauteile der Drohne überprüft werden und sowohl die Fernbedienung, als auch das Gyroskop für das Arduino kalibiriert werden. Die Ergebnisse der Kalibrierungen werden im EEPROM, dem Speicher des Arduinos, gespeichert. Das Programm läuft über den seriellen Monitor des Arduinos.    
Der zweite Sketch wird verwendet, um die Ergebnisse der Kalibrierung zu testen. Im seriellen Monitor können durch bestimmte Befehle unterschiedliche Daten aufgerufen werden. Darauf gehe ich aber erst im letzten Teil dieser Anleitung ein, da dies sonst zu umfangreich wird: [Der erste Start](#Erst).  
Der dritte Sketch ist der flight controller. Mit diesem wird die Drohne letztlich gesteuert. Es ist eine Sicherungsfunktion enthalten. Aber trotzdem sollte beim Start immer ein Sicherheitsabstand eingehalten werden.  
Alle diese drei Sketches müssen vom Ersten bis zum Dritten auf den Arduino geladen werden, ausgeführt werden und nur wenn keine Fehler während der Prgrammabläufe auftauchen, darf das Nächste installiert werden. Bei Nichtbeachtung der Reihenfolge kann es zu schweren Fehlern kommen.  
  
Zum Grundverständnis erkläre ich an dieser Stelle erstmal, wie der Quadrocopter seine Position und die Befehle der Fernbedienung "versteht". Im folgenden Text wird häufig von einem Puls zwischen 1000 und 2000 gesprochen. Dieser Puls bedeutet eigentlich nur, dass die Fernbedienung die Befehle mit einer Frequenz von 1000 bis 2000 Hertz an den Empfänger sendet. Das Arduino rechnet auch mit dieser Frequenz. Es wäre auch möglich, dies in ein kleineres Format im Arduino für die Rechnungen umzuwandeln. Das Ergebnis wäre aber dasselbe und würde innerhalb des Codes zu Verwirrung führen. Während des Setups wird auch an die ESCs diese Frequenzreichweite übertragen, da diese auch mit Pulsen arbeiten. Wenn eine Reichweite von 1000 mögliche Pulsen existiert, ist auch eine sehr genaue Bestimmung der Werte möglich und sehr genaue Ergebnisse können innerhalb des Codes produziert werden.  
Die Werte 1000 bis 2000 sind also nicht frei erfunden und nur als Variablen festgelegt, sondern durch die Fernbedienung definiert und müssen so verwendet werden.  
  
Der gesamte Code kann eingesehen und modifiziert werden. Der Code ist durch viele Kommentare verständlich gemacht. Inwiefern Modifikationen sinnvoll sind und wo diese vorgenommen werden sollten, wird im späteren Verlauf dieser Dokumentation aufgegriffen.  
Direkte Weiterleitungen zum Code:  
  
[Setup](https://github.com/StefanScheunemann/Arduino-Drone/tree/master/Code/Setup)  
[Calibration](https://github.com/StefanScheunemann/Arduino-Drone/tree/master/Code/Calibrate)  
[Flight controller](https://github.com/StefanScheunemann/Arduino-Drone/tree/master/Code/Flight_controller)  
  
####Setup<a name="Setup"><a/>
Im Setup wird die gesamte Hardware für das Arduino kalibriert. Um dies zu tun, muss der Setup-Sketch auf den Arduino geladen werden und am PC im Arduino-Programm der serielle Monitor geöffnet werden. Im seriellen Monitor muss die Baudrate auf 57600 eingestellt werden für diesen Vorgang.  
Falls während des Setups Fehler auftreten, wird ein Fehlercode angezeigt. Jeder Fehler ist dokumentiert und mit Lösungen versehen. Diese Lösungen werden im späteren Verlauf dieser Anleitung dokumentiert. [Abkürzung zu Fehlercodes](#Fehler)  
Nun wird ein Programm Ablauf gezeigt, dem man als Nutzer nur folgen und die Befehle befolgen muss.  
Zuerst werden die Endposition der Fernbedienung kalibriert. Dabei ist zu beachten, dass "nose down" auf dem rechten Steuerknüppel "nach unten" bedeutet. Wenn der Quadrocopter seine Nase hoch zieht, bewegt der Quadrocopter sich nach hinten.  
Sobald die Kalibrierung der Fernbedienung abgeschlossen ist, beginnt die Kalibrierung des Gyroskops. Zu diesem Zweck wird das Programm den Nutzer dazu auffordern, den Quadrocopter in bestimmte Positionen zu bewegen. Dabei muss darauf geachtet werden, dass die richtigen Seiten bewegt werden, da es sonst später zu Fehlern kommen kann.  
Der letzte Schritt ist die Kontrolle der Status-LED. Diese sollte aufleuchten, wenn der Befehl dazu im seriellen Monitor angezeigt wird. Prinzipiell ist die LED nicht nötig. Falls aber später Probleme auftreten, kann an der Blinkfrequenz erkannt werden, um welchen Fehler es sich handelt. Die LED erfüllt somit eine wichtige Rolle.  
  
Nun sollte das Programm anzeigen, dass der Vorgang beendet ist und der serielle Monitor kann geschlossen werden.  
An dieser Stelle ist das Setup abgeschlossen. Es kann zum nächsten Schritt übergegangen werden.  
Wer aber noch daran interessiert ist, wie der Code aufgebaut ist und wie die Informationen im EEPROM gespeichert werden, kann den Code frei verwenden und modifizieren, alle Informationen sind Open Source und es darf daran alles verändert werden. Doch macht es in diesem Sketch wenig Sinn, etwas zu modifizieren.  
Im späteren Verlauf wird das Modifizieren noch wichtiger.  
Der Code ist zum besseren Verständis mit Kommentaren versehen. Es sollte nicht nötig sein, sich aufwändig einlesen zu müssen, um den Inhalt zu verstehen.  
  
#####Calibration<a name="Calib"><a/>
Das zweite Programm, welches installiert werden muss, ist die Kablibrierung.  
Dieser Sketch unterscheidet sich stark vom Setup. Es wird nichts auf dem EEPROM verändert.  
Sobald der Sketch auf den Arduino geladen ist, muss wieder der serielle Monitor geöffnet werden. Es wird weiterhin die Baudrate 57600 verwendet.  
Nun gibt es mehrere Befehle, die ausgeführt werden können, zum Überprüfen der Funktionen des Gyroskops, der Fernbedienung und der Schwingungen der Motoren.  
Wenn in den seriellen Monitor **a** eingegeben wird, zeigt der serielle Monitor die Position des Gyroskops. Zu beachten ist, dass Yaw bedeutet, inwieweit der Quadrocopter auf dem Boden gedreht wurde. Sobald die Drehung beendet ist, setzt der Wert für Yaw sich selbstständig auf 0 zurück. Es sollte eine perfekte Nullstellung erreicht werden, da der Quadrocopter sonst nie ruhig in der Luft stehen kann.  
  
Als nächstes wird in den seriellen Monitor **r** eingegeben. Mit diesem Befehl werden die Daten der Fernbedienung aufgerufen. Im seriellen Monitor werden nun vier unterschiedliche Daten angezeigt.  
  
Die Werte sollten sich zwischen 1000 und 2000 befinden, der Anstieg/Abfall der Werte sollte gleichmäßig sein und nicht springen, da es sonst später zu Problemen kommen kann. Minimale Abweichungen sind unproblematisch. Es sollten nur keine großen Abweichungen sein.  
  
Mit den Befehlen **1-5** kann entwededer von jedem Motor einzeln die verursachte Vibration überprüft werden. Zu diesem Zweck sollte auf den Motoren ein Propeller befestigt werden. Im Idealfall liegt die Vibration unter 50. Dies ist kein Referenzwert, der mit anderen Werten verglichen werden kann. Der Test sollte bei 50 % Beschleunigung ablaufen. In dieser Position sollte der Quadrocopter knapp nicht abheben und es werden gute Ergebnisse erzeugt. Bei diesem Test ist größte Vorsicht geboten, der Quadrocopter kann schwere Verletzungen zufügen und es sollten mindestens **fünf Meter** Sicherheitsabstand eingehalten werden; ideal sind **zehn Meter**.
  
| Motor	    | Command |
|-----------|:-------:|
| Motor 1	  | 1       |
| Motor 2   | 2       |
| Motor 3	  | 3       |
| Motor 4	  | 4       |
| Motor 1-4 | 5       |
  
####Flight Controller<a name="Flight"><a/>
Das dritte Programm ist das, dass letztendlich für das Fliegen verwendet wird. Dieser Sketch greift auf die Daten, die im EEPROM abgelegt wurden, zurück und verwendet sie als Grundlage der Berechnungen für die Stabilität. Die vorherigen Schritte müssen genau befolgt werden, da sonst Fehler beim Flug entstehen können.  
  
Das Gyroskop gleicht beim Flug permanent den Quadrocopter aus, sodass zu keinem Zeitpunkt, wenn kein Befehl, abgesehen von der senkrechten Beschleunigung, übertragen wird, der Quadrocopter in eine nicht horizontale Position gerät.  
Der Ablauf im Sketch hinter dieser Mechanik ist, dass das Gyroskop permanent die Position des Quadrocopters überprüft. Im Sketch ist festgelegt, dass in der Nullstellung des Gyroskops und der Fernbedienung ein Puls von 1500 an die ESCs gesendet wird. Nullstellung bedeutet, dass der Quadrocopter senkrecht zum Boden ausgerichtet ist. Die ESCs sind auf die Frequenz von 1000 bis 2000 kalibiriert.  
Wenn nun der Winkel, in dem sich der Quadrocopter relativ zum Boden befindet, verändert wird, rechnet das Arduino eine definierte Antisteigung aus; also die aktuelle Position abgezogen von der Standardposition und ermittelt einen Gegenimpuls, der an die ESCs geschickt wird.   
Im Sketch ist festgelegt, dass wenn die senkrechte Beschleunigung, also der linke Steuerknüppel, in der untersten Position ist, der Quadrocopter 0 % Motor-Output aufbringt. Der Output steigt linear bis auf 100 % in Maximal-Stellung an. Wichtig ist dabei zu wissen, dass bei 50 % der Quadrocopter stabil in der Luft steht und weder steigt noch sinkt. Bei unter 50 % wird ein Absinken und bei über 50 % ein Ansteigen zu beobachten sein. Falls dies nicht richtig funktioniert, müssen die Fernbedienung und der Quadrocopter neu kalibriert werden. Das Kalibrieren des Quadrocopters muss erneut über das Setup durchgeführt werden und sollte nicht übersprungen werden.   
  
Wenn der Quadrocopter sich also in der Ausgangslage befindet, wird ein Puls von 1500 an den PID-controller gesendet (dieser wird im [nächten Teil](#PID) genauer erklärt) und es wird keine Veränderung vorgenommen. Wenn nun aber auf der Fernbedienung der Befehl Roll gegeben wird mit halber Beschleunigung, also der rechte Steuerknüppel 50 % nach rechts gedrückt wird, so wird der Wert auf 1750 erhöht. Nun kippt der Quadrocopter kontinuierlich nach rechts. Das Gyroskop nimmt diese Veränderung der Lage wahr und rechnet seine eigene Rechnung dagegen. Im Code ist festgelegt, das für jeden 1°, den der Quadrocopter gekippt ist, ein Puls von 15 gegengerechnet wird. Wenn beim Rollen nun also 5° erreicht sind, wird gegen die 1750, die von der Fernbedienung ausgegeben werden und vom Arduino verwendet werden, ein Wert von 75 gegengerechnet. Der interne Wert für die Position ist nun also 1675. Das Rollen wird soweit weitergeführt, bis der Wert von 1500 erreicht und und der Quadrocopter damit seine Zielposition, die er immer erreichen möchte, erreicht hat. Dieser Fall tritt in diesem Fall bei 16,7° ein. Wenn man also den Befehl fürs Rollen mit 50 % Leistung gibt, wird der Quadrocopter bis auf 16,7° kippen und in dieser Position bleiben, bis ein neuer Befehl von der Fernbedienung gegeben wird. Maximal möglich sind 33,3°. Dieser Wert wird als allgemein sicher anerkannt und führt zu guter Beschleunigung und gut kontrollierbarem Flugverhalten. Weiteres Rollen würde zu höherer Beschleunigung führen, aber auch die Gefahr eines Überschlags erhöht sich. Diese Werte gelten genauso für Pitch und Yaw, nur die senkrechte Beschleunigung ist nicht von dieser Berechnung betroffen.  
  
Wenn der Maximalwinkel größer/kleiner sein soll, muss am Code eine Veränderung vorgenommen werden. Dies ist in Zeile 14 und 22 des flight controllers möglich. Wenn der Wert erhöht wird, steigt der maximale Winkel. Wenn der Wert verkleinert wird, sinkt der maximale Winkel. Es kann sinnvoll sein, den Winkel zu verkleinern, wenn die Drohne dem Nutzer zu aggressiv reagiert.  
Auch der Standardwert von α=1°=15 kann verändert werden. An diesem Wert zu modifizieren ist eher nicht empfehlenswert, da der Quadrocopter selbst bei kleinen Veränderungen sehr aggressiv reagieren kann. Wenn der Maximalwinkel verändert werden soll, ist es sinnvoller, die vorherige Methode zu verwenden.  
  
Falls der Quadrocopter anders reagiert, als man es erwarten würde und das Problem mit dem Gyroskop in Verbindung stehen könnte, kann die gesamte auto level Funktion deaktiviert werden. Dies ist in Zeile 24 möglich. Es ist wichtig zu bedenken, dass mit dieser Einstellung auf false keine Flugunterstützung mehr existiert. Es muss manuell gegengelenkt werden. Im Allgemeinen rate ich von einem Flug ohne auto level-Funktion ab.  
  
Im flight controller ist noch eine weitere Funktion eingebaut, die die LED verwendet.  
Die LED zeigt einen niedrigen Akkustand an, indem sie beginnt, durchgehend zu leuchten. Die Funtion dafür befindet sich in Zeile 250.   Wenn die output-Spannung des Akkus zu niedrig wird, um die Motoren mit ausreichend Energie versorgen zu können, beginnt die LED permanent zu leuchten. Diese Warnung bedeutet nicht, dass der Quadrocopter nicht mehr fliegen kann. Er sollte aber in absehbarer Zeit gelandet werden.  

Darüber befindet sich eine Funktion, die es für den Arduino einfacher macht, durch einen komplementären noise filter den Akkustand zu errechnen. Mit diesem treten weniger Ungenauigkeiten beim Errechnen der Spannung des Akkus auf und die LED zeigt nicht schon zu früh einen niedrigen Akkustand an.  
  
Falls noch weitere Unklarheiten bezüglich des flight controllers existieren kann jede Einzelheit [hier](https://github.com/StefanScheunemann/Arduino-Drone/tree/master/Code/Flight_controller) im Code nachgelesen werden. Der gesamte Code ist mit Kommentaren zum besseren Veständnis gefüllt.  
  
  
##5. PID Kalibrierung<a name="PID"><a/>
Die PID Werte sind das Erste, was man sehen wird, sollte man den Code des flight controllers öffnen.  
Diese PID Werte sind essentiell für die auto level-Funktion des Quadrocpters, die das Besondere an diesem gesamten Projekt ist. Zum Verständis ist es als erstes sinnvoll zu verstehen, wofür PID steht. Wer schnell zu dem Teil springen möchte, in dem erklärt wird, wo und wie man diese Werte anpassen sollte, wird [hier](#PIDmod) weitergeleitet.  
  
####Theoretische Erklärung der PID-Werte  
  
**P** steht für proportinal, an dieser Stelle wird **Output des Gyroskops - Output des receivers * P(gain)** gerechnet, oder auch  
(gyro - receiver) * P (gain). Wenn sich nun der Quadrocopter in einer 10°-Lage gekippt zum Boden befindet und 1°=15 => 10*15=150. Nehmen wir nun an, von der Fernbedienung wird kein Befehl gesendet, der eine solche Veränderung der Lage herbeiführt, so wird der Quadrocopter nun versuchen, in die Standardposition von 1500 zurück zu kehren. Aus der Rechnung ergibt sich also, dass der aktuelle Wert 1650 entspricht, aber 1500 angepeilt werden. Theoretisch sollte diese Funktion ausreichen, um den Quadrocopter in eine stabile Position zu bringen. Wenn man aber nur diese Funktion verwendet, so wird man feststellen, dass der Quadrocopter anfängt, gleichmäßig zu schwingen. Bei jeder Korrektur wird der Quadrocopter von selbst übersteuern und nie in eine ruhige Position kommen. Um dieses Problem zu lösen werden weitere Funktionen eingebracht, die auf einer anderen Basis den Quadrocopter stabilisieren.  
  
**I** steht für Intergral, in dieser Funktion wird  
I(output) + ((gyro - receiver) * I(gain). Wenn man nun also wieder von 10° relativer Steigung Nullpunkt ausgeht, dann wird bei einem Wert von I = 1 die Rechnung I(output), jetzt noch 0 + ((150 - 0), da von der Fernbedienung kein Befehl gesendet wird, * I(gain), was als 1 definiert wurde, gerechnet und es kommt ein Ergebnis von 150 raus, was der Korrketur entspricht, die ausgeführt werden muss.  
In der nächsten Rechnung wird 150(der output der letzten Rechnung) + ((150 - 0) * I(gain, was als 1 definiert bleibt), gerechnet.  
Im Ergebnis bedeutet dies, dass selbst wenn die Steigung konstant ist und der Winkel nicht verändert wird, die Korrektur immer stärker wird, bis wieder der Nullpunkt erreicht ist, an der der errechnete Wert wieder auf 0 zurücksetzt wird, da sobald der Winkel = 0° ist und von der Fernbedienung kein Befehl gesendet wird, das Ergebnis der Rechnung gleich 0 ist.  
Wenn nur diese Rechnung verwendet wird, kann wieder festgestellt werden, dass der Quadrocopter überkompensiert und somit immer noch keine stabile Haltung in der Luft erreicht werden kann. Der Quadrocopter wird mit nur dieser Funktion, ähnlich wie bei der ersten von einer Seite zur anderen schwingen. Doch dies passiert deutlich langsamer. Um nun eine stabile Position zu erreichen, ist eine weitere Funktion nötig, die das Überkompensieren verhindert.  
  
**D** steht für Derivative, diese Funktion unterscheidet sich von den vorherigen, als dass sie nur auf eine Veränderung eine einmalige Korrektur ausgibt und nicht, wie die anderen Funktionen, konstant gegen die Steigung gegenarbeitet.  
(gyro - receiver - gyro(prev) - receiver(prev)) * D(gain). Wenn man nun wieder davon ausgeht, dass D = 1 definiert ist, dann ergibt sich bei einer Steigung von 10° im Intervall davor eine Steigung von 0°
(150 - 0 - 0 - 0) * 1, das Ergebnis wäre eine Korrektur von 150. Wenn man nun aber im nächsten Messintervall weiterhin die Position von 10° verwendet, dann ergibt sich  
(150 - 0 - 150 - 0) * 1, das Ergebnis dieser Rechnung wäre 0. Diese Funktion verursacht also nur eine Korrektur, wenn die Position zwischen zwei Intervallen sich verändert, ansonsten ist das Ergebnis immer 0.  
Wenn nun durch die anderen beiden Funktionen eine Überkompensation stattfindet, dann sendet diese Funktion eine einzelne Korrektur, die den Quadrocopter wieder ausgleicht und in die waagerechte Position regelt.  
  
Um es anschaulicher zu machen habe ich eine Google-Tabelle mit den Rechnungen erstellt. Die Diagramme zeigen die Korrekturbefehle, die von den Funktionen gesendet werden. Auch kann das Dokument heruntergeladen werden und mit den PID-Werten experimentiert werden, wie diese sich verändern, wenn die gain-Werte verändert werden. In dem Dokument liegen zwischen jedem Messungsinvtervall 4 Millisekunden. Mit diesem Wert arbeitet auch das Arduino im flight controller. Die Rechnungen des PID controllers finden im flight controller in Zeile 424 statt, das Verändern der PID-Werte wird aber in Zeile 9 - 11 durchgeführt.  
  
**[Link zur Tabelle](https://docs.google.com/spreadsheets/d/1bJNEvERLeVwe6B2JFlEnVjHe6nW1A6QOTmVpb9kBsjY/edit?usp=sharing)**  
  
Praktische Anwendung der PID Werte<a name="PIDmod"><a/a>  
  
Wenn man nun weiss, wie der PID controller funktioniert, kann man beginnen, die gain-Werte zu modifizieren.  
Jeder Quadrocopter hat eine andere Struktur und reagiert anders auf die Korrekturen. 
Deswegen **müssen** die PID-Werte manuell angepasst werden und nach jedem Umbau oder größerer Reperatur muss die Kalibrierung neu erfolgen.  
Die im Programm angegebenen PID-Werte sind nicht allgemein gültig. Mein Quadrocopter funktioniert mit diesen aber am besten.  
  
Für die folgende Prozedur empfehle ich, im ersten Teilschritt bei der Kalibrierung des D-Wertes Sicherheitshandschuhe anzuziehen, um Verletzungen zu vermeiden.  
  
Um die Kalibrierung zu beginnen, müssen im flight controller die PID-Werte für roll, Zeile 9 bis 11) auf 0 gesetzt werden. Die Kalibrierung verläuft am besten, wenn man mit dem D-Wert beginnt. Dies tut man, indem in Zeile 11 der Wert für D nun von 0 auf 3 erhöht wird. Mit dieser Veränderung wird der Sketch auf den Quadrocopter übetragen. Nun greift man den Quadrocopter fest in der Mitte und beginnt den Schub zu erhöhen. Der Schub wird solange erhöht, bis der Punkt erreicht ist, an dem der Quadrocopter **fast** vom Boden abhebt. Jetzt muss der Quadrocopter in alle Richtungen geneigt werden, der Quadrocopter sollte sich stabil anfühlen und nicht ruhelos. Nun erhöht man den D-Wert immer weiter in Schritten von 1 und testet jedes Mal, bis der Quadrocopter sich unruhig anfühlt und beginnt, sich ungleichmäßig zu verhalten. Die Unruhe sollte bei +-20 einsetzen. Wenn dieser Punkt erreicht ist, zieht man vom D-Wert 25 % wieder ab und erhält einen Wert, bei dem der Quadrocopter sich ruhig verhält.  
  
Als nächstes wird dieser Vorgang für den P-Wert wiederholt. Statt einer Erhöhung von 1 pro Versuch, sollte diesmal eine Steigerung von 0.2 verwendet werden. An diesem Punkt muss der Quadrocopter auch nicht mehr in der Hand gehalten werden. Auf einer Grasfläche kann vorsichtig geflogen werden. Wenn wieder der Punkt erreicht ist, an dem der Quadrocopter sich unruhig verhält, wird der Wert um 50 % reduziert und erhält somit einen stabilen P-Wert.  
  
Im letzten Schritt wird der I-Wert erhöht. Dies findet in Schritten von 0.01 statt. Man wird feststellen, dass der Quadrocopter immer stabiler fliegt. Wieder wird der Quadrocopter ab einem bestimmten Wert sich unruhig verhalten. An diesem Punkt wird der I-Wert wieder um 50 % reduziert.  
  
Wenn diese Kalibrierung abgeschlossen ist, erhält man einen stabil fliegenden Quadrocopter. Es darf aber nicht vergessen werden, dass nach jedem Umbau und jeder Reparatur diese Prozedur wiederholt werden sollte.  
  
  
##6. Erster Start<a name="Erst"><a/>
Sobald der Sketch auf dem Arduino gespeichert ist, ist die Drohne flugbereit. Beim Start gilt es bestimmte Dinge zu beachten:  
1. Um den Quadrocopter zu starten, muss an der Fernbedienung der throttle stick in die untere, linke Ecke bewegt werden. Erst ab diesem Moment ist Sicherung deaktiviert.  
2. Um den Quadrocopter auszuschalten, muss der throttle stick in die untere, rechte Ecke bewegt werden. Dies löst die Sicherung aus und keine weiteren Befehle werden umgesetzt.  
3. Sobald die Sicherung deaktiviert ist, muss der Quadrocopter gestartet werden. Die ersten Sekunden ist der Ausgleich durch das Gyroskop deaktiviert, sodass die Drohne senkrecht starten kann. Sie gleicht sich erst in der Luft aus. Auch sollte insofern zügig gestartet werden, damit ein schnelles Abheben auf mindestens 20 Centimeter gewährleistet ist und die Drohne sich nicht am Boden verfangen kann.
4. Vor und während des Fluges ist ein Sicherheitsabstand einzuhalten. Ein Start aus der Hand ist zwingend zu vermeiden, da durch Windstöße oder Fehler des Programms die Drohne aggressiv reagieren kann und somit den Nutzer schwer verletzen kann.  
5. Es ist durchaus damit zu rechnen, dass erste Flugversuche fehlschlagen. Es sollte von Beginn an eingeplant werden, dass einige Propeller kaputt gehen. Die gegebenen PID-Werte sollten einen stabilen Flug gewährleisten, es können aber dennoch Probleme auftreten. Um diese Probleme zu beheben, müssen die PID-Werte angepasst werden. Wie dies möglich ist, wurde im [vorherigen Teil](#) erklärt.  
6. Die eingebaute LED hat zwei Funktionen. Wenn die LED permanent leuchtet, bedeutet dies, dass der Akku unter 25 % Leistung gefallen ist. Wenn die LED schnell blinkt, konnte keine Verbindung hergestellt werden. In diesem Fall sollte einige Sekunden gewartet werden.  
  
Wenn der erste Flug erfolgreich verlaufen ist, sollten alle Teile des Quadrocopter überprüft werden. Selbst bei einem erfolgreichen Flug können Schäden entstehen. Der Rahmen sollte besonders genau betrachtet werden, da durch die Motoren starke Kräfte auf diesen ausgeübt werden. Falls Risse oder ähnliche Schäden auftreten, müssen diese behoben werden. Es darf nicht mit defekten Teilen geflogen werden.  
  
Ein derartiger Riss kann zum Beispiel so aussehen  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Bilder/DSC_0031_5.JPG)  
  
  
##7. Fehlercodes<a name="Fehler"><a/>
Die Fehlercodes beziehen sich auf das Setup und die Kalibrierung. Jeder mögliche Fehler ist in dieser Sektion dokumentiert.  
  
####Error 1: No valid receiver signals found  
Der Empfänger sendet ungültige Signale. Akzeptiert werden Signale mit einem Puls zwischen 900 und 2100.  
Um das Problem zu lösen, muss überprüft werden, ob der Empfänger richtig mit dem Arduino verbunden ist. Die Channel 1 bis 4 müssen mit den Pins 8 bis 12 verbunden werden. Die Reihenfolge spielt dabei keine Rolle.  
  
####Error 2: No stick movement detected in the last 30 seconds  
Das Arduino registriert keine gültigen Signale von der Fernbedienung.  
Die Fernbedienung sollte aus- und wieder angeschaltet werden und die Steuerknüppel dürfen nicht zu ruckartig bewegt werden.  
  
####Error 3: No gyro device found  
Das Gyroskop kann nicht vom Arduino identifiziert werden.  
Der Sketch funktioniert mit dem MPU 6050. Andere Gyroskope sind nicht getestet. Falls ein anderes Gyroskop verwendet wird, das nicht mit 5 Volt, sondern mit 3,3 Volt kompatibel ist, muss die Stromzufuhr verändert werden.
Falls der Fehler mit dem MPU 6050 auftaucht, muss die Verkabelung an diesem überprüft werden. Diese sollte so aussehen  
  
| Arduino	  | Gyro    |
|-----------|:-------:|
| GND       | GND     |
| 5V        | Vin/Vss |
| SDA/A4    | SDA     |
| SCL/A5    | SCL     |
  
####Error 4: No angular motion is detected in the last 10 seconds  
Wenn der Quadrocopter beim Setup nicht mindestens 30° in die richtige Richtung gekippt wird, entsteht diese Fehlermeldung.  
Innerhalb von 10 Sekunden muss der Quadrocopter auf der angegebenen Seite um 45° gekippt werden. Zu diesem Zweck darf der Quadrocopter nicht bewegt, sondern nur gekippt werden, da die Werte sonst ungültig sind.  
  
####Error 5: EEPROM verification failed  
Sobald das Setup abgeschlossen ist, werden alle gemessenen Daten im internen Speicher des Arduino Uno, dem EEPROM, gespeichert. Sollte dabei ein Fehler auftreten, erscheint diese Meldung.  
Es sollte überprüft werden, ob eine stabile Stromversorgung mit 5 V gewärleistet ist, da es sonst zu Fehlern beim Speichern kommen kann. Wenn der Fehler weiterhin besteht, ist der Speicher des Arduino corrupted und sollte formatiert werden.  
  
####Error 6: Receiver channel verification failed  
Dieser Fehler tritt auf, falls ein Steuerknüppel für mehrere Funktoinen definiert ist.  
Es sollte beim Setup darauf geachtetet werden, dass immer nur ein Steuerknüppel bewegt wird und nicht mehrere gleichzeitig. Sollte das Problem weiter bestehen, muss die Fernbedienung neu kalibriert werden.  
  
####Error 7: Gyro exes verification failed  
Wenn beim Überprüfen der Achsen des Gyroskops an einer Stelle mehrere Achsen gleichzeitg erkannt werden, entsteht dieser Fehler.  
Um diesen Fehler zu vermeiden, sollte beim Setup darauf geachtet werden, dass wenn der Quadrocopter in eine bestimmte Richtung gekippt werden soll, immer nur in genau diese Richtung gekippt wird und nicht in mehrere gleichzeitig.  
  
  
<h2>8. Quellen<a name="Quel"></a></h2>
Der Code stammt von Herrn Brooking, eine Erklärung zu diesem und der Download können auf seiner [Website](http://www.brokking.net/ymfc-al_main.html) gefunden werden. Der Code ist nicht mein Gedankengut, alle Rechte gehören Herrn Brooking. Auch die schematic für den Schaltkreis in der Drohne stammt nicht von mir und kann auf der angegebenen Webstite gefunden werden.  
Das verwendete 3D-Modell für den Rahmen des Quadrocopters kann auf Thingiverse [hier](http://www.thingiverse.com/thing:264955/#files) gefunden werden, es ist für jeden frei verfügbar. Das Modell wurde nicht von mir erstellt.
