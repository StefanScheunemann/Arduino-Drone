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
Dieser Quadrocopter ist im Rahmen eines Schulprojekts entstanden, es handelt sich nicht um ein professionelles,
komplett ausgereiftes Industrieprodukt und Fehler im Code sind zu erwarten. Im Umgang mit der Drohne rate ich zu großer Vorsicht,
es können durch diese ernsthafte Verletzung zugefügt werden.(Link noch enzufügen) Diese Anleitung beinhaltet alles, was man wissen
muss, um einen Quadrocopter zu bauen, Fehler oder Ungenauigkeiten können aber enthalten sein.

###2. Teilliste<a name="Teil"></a>
In meinem Fall ist das gesamte Drohnengestell mithilfe eines 3D Druckers entstanden, die dafür nötigen 3D Modelle sind repository
enthalten und können frei verwendet werden, wer keinen 3D Drucker zur Verfügung hat kann ein fertiges Gestell kaufen, oder aus 
anderen Materialien selber eins bauen. Zu diesem Thema gibt es im Internet eine große Menge an Informationen, weswegen ich nicht
genauer darauf eingehen werde.  
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
Zuerst muss der Rahmen des Auqdrocopters zusemmengebaut werden. Jeder Rahmen ist unterschiedlich aufgebaut, deswegen werde ich hier nicht weiter darauf eingehen. Es ist sinnvoll, die untere Platte erstmal nich zu befestigen um die Elektronik besser befestigen zu können.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0005.JPG)  
Sobald der Rahmen zusammengesetzt ist kann die Hardware verbaut werden.  
Der Quadrocopter kann mit den Teilen aus der [Teilliste](#Teil) gebaut werden, aber auch äquivalente Bauteile sollten funktionieren.  
Bei der Verkabelung ist darauf zu achten, das die Schematics beachtet werden, da es sonst später zu Fehlfunktionen kommen kann.  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Schematics.jpg)  
Es ist am einfachsten mit den ESCs zu beginnen, diese sollte möglichst weit vom Zentrum entfernt sein, da sie sonst später das Gyroskop stören könnten.  
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
![alt text]()  
Gegen Uhrzeigersinn  
![alt text]()  
  
Jetzt ist die gesamte Hardware verbaut, im nächsten Schritt muss diese verkabelt werden. Ich empfehle alle Verbindungen zu löten, da so eine feste Verbindung entsteht, aber auch z.B. Kabelhülsen sollten funktionieren. In jedem Fall muss sich streng an die Schematics gehalten werden!  
Zum besseren Verständis der Verbindungen  
Verbindung der ESCs falls der Rahmen kein PDB (power distribuition board) enthält  
![alt text](https://github.com/StefanScheunemann/Arduino-Drone/blob/master/Dokumentation/DSC_0005_11.JPG)  
Kabel am Arduino  
![alt text]()  
  
Als letztes kann über das Arduino ein Schutz angebracht werden, damit es nicht ungeschützt ist beim Transport/Flug. Bei den 3D Modellen liegt ein derartiger Schutz bei, ob man diesen verwendet oder selber etwas anderes baut spielt keine große Rolle solange es gegen Einschläge schützt.  
![alt text]()  
  
###4. Code<a name="Code"><a/>
Um die Drohne verwenden zukönnen werden drei Arduino Sketches benötigt.  
[1. Setup](#Setup)  
[2. Calibration](#Calib)  
[3. Flight Controller](#Flight)  
  
Der erste ist ein Setup, in dem alle Bauteile der Drohne überprüft werden und sowohl die Fernbedienung, als auch das Gyroskop für das Arduino kalibiriert werden. Die Ergebnisse der Kalibrierungen werden im EEPROM, dem Speicher des Arduinos, gespeichert. Das Programm läuft über dn seriellen Monitor des Arduinos.    
Der zweite Sktech wird verwendet, um die Ergebnisse der Kalibrierung zu testen. Im seriellen Monitor können durch bestimmte Befehle unterschiedliche Daten aufgerufen werden, darauf gehe ich aber erst im letzten Teil dieser Anleitung ein, da dies sonst zu umfangreich wird [6. Der erste Start](#Erst).  
Der dritte Sktech ist der flight controller, mit diesem wird die Drohne letztlich gesteuert. Es ist eine Sicherungsfunktion enthalten, aber trotzdem sollte beim Start immer ein Sicherheitsabstand eingehalten werden.  
Alle diese drei Sketches müssen vom ersten zum dritten auf den Arduino geladen werden, ausgeführt werden und nur wenn keine Fehler während den Prgrammen auftauchen darf das nächste installiert werden. Bei nich Beachtung der Reihenfolge kann es zu schweren Fehlern kommen.  
  
####Setup<a name="Setup"><a/>
Im Setup wird die gesamte Hardware für das Arduino kalibriert. Um dies zu tun muss der Setup Sketch auf den Arduino geladen werden und am PC im Arduino Programm der serielle Monitor geöffnet werden. Im seriellen Monitor muss die Baudrate auf 57600 eingestellt werden für diesen Vorgang.  
Falls während dem Setup Fehler auftreten wird ein Fehlercode angezeigt, jeder Fehler ist dokumentiert und mit Lösungen versehen. Diese Lösungen werden im späteren Verlauf dieser Anleitung dokumentiert. [Abkürzung zu Fehlercodes](#Fehler) 
Nun wird ein Programm Ablauf gezeigt, dem man als Nutzer nur folgen und die Befehle befolgen muss.  
Zuerst werden die Endposition der Fernbedienung kalibriert. Dabei ist zu beachten das "nose down" auf dem rechten Steuerknüppel nach unten bedeutet. Wenn der Quadrocopter seine Nase hoch zieht bewegt der Quadrocopter sich nach hinten.  
Sobald die Kalibrierung der Fernbedienung abgeschlossen ist beginnt die Kalibrierung des Gyroskops. Zu diesem Zweck wird das Programm den Nutzer dazu auffordern, den Quadrocopter in bestimmte Positionen zu bewegen. Dabei muss darauf geachtet werden, das die Richtigen Seiten bewegt werden, da es sonst später zu Fehlern kommen kann.  
Der letzte Schritt ist die Kontrolle der Status LED, diese sollte aufleuchten, wenn der Befehl dazu im seriellen Monitor angezeigt wird. Prinzipiell ist die LED nicht nötig, falls aber später Probleme auftreten kann an der Blinkfrequenz erkannt werden, um welchen Fehler es isch handelt und erfüllt somit eine wichtige Rolle.  
