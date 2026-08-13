# Monitorizarea cantității de CO₂ dintr-un avion / Monitoring the Amount of CO₂ in an Aircraft

## 🇷🇴 Română

Acest proiect este un sistem de monitorizare a cantității de CO₂ dintr-un avion, realizat cu Arduino și simulat în Proteus.

Proiectul citește o valoare analogică de la intrarea A0, o afișează pe un LCD 16x2 și indică prin LED-uri stările normal, WARNING, ALARM și ERROR. În cazul unei alarme, este activată instalația de ventilație.

### Funcționalități

1. Valorile senzorilor sunt citite la intervale de o secundă.
2. Toate valorile citite trebuie să fie într-un interval predefinit. Valorile în afara intervalului sunt ignorate.
3. Când trei citiri succesive ale unui senzor generează valori în afara intervalului predefinit, LED-ul care corespunde senzorului respectiv își schimbă culoarea din verde în roșu și se generează **ERROR**.
4. În funcție de valorile citite se pot genera semnale **WARNING** sau **ALARM**.
5. Când un semnal **WARNING** este generat, un LED își schimbă culoarea din verde în roșu.
6. Un **WARNING** persistă până când este achitat de pilot sau dispar condițiile care l-au generat.
7. După achitare, un nou **WARNING** va fi generat doar dacă a existat cel puțin o citire pentru care nu s-a generat **WARNING** sau **ALARM**.
8. Când un semnal **ALARM** este generat, un LED își schimbă culoarea din verde în roșu.
9. Un **ALARM** persistă până când dispar condițiile care l-au generat.
10. Cantitatea de CO₂ este citită cu ajutorul unui senzor.
11. Cantitatea de CO₂ este afișată pe un ecran de tip ceas.
12. Atunci când cantitatea de CO₂ este mai mare decât **0,1%**, un semnal **WARNING** este generat.
13. Dacă semnalul **WARNING** este achitat, atunci se pornește instalația de ventilație.
14. Atunci când cantitatea de CO₂ este mai mare decât **0,3%**, un semnal **ALARM** este generat.
15. După apariția semnalului **ALARM** se pornește instalația de ventilație.
16. Instalația de ventilație se oprește dacă cantitatea de CO₂ este mai mică decât **0,05%**.

### Praguri CO₂

|   Condiție  | Valoare Comportament | Comportament |
|-------------|----------------------|--------------|
| CO₂ > 0,1%  |      0.10 – 0.30     | WARNING |
| CO₂ > 0,3%  |      0.30 – 1.00     | ALARM + pornirea ventilației |
| CO₂ < 0,05% |      0.00 – 0.05     | Oprirea ventilației |

în afara intervalului 0 – 1 Valoare considerată eronată 3 citiri eronate ERROR

Valorile sunt obținute din citirea analogică și sunt împărțite la 1000 pentru afișare.

### Componente / conexiuni principale

- Arduino Uno
- LCD 16x2 RGB
- intrare analogică `A0`
- LED-uri WARNING
- LED-uri ALARM
- LED-uri ERROR
- ieșire digitală `D7` pentru instalația de ventilație
- comunicație Serial la `9600 baud`

### Structura repository-ului

```text
Monitorizarea-cantitatii-de-CO2-dintr-un-avion/
├── README.md
├── Arduino/
│   └── Monitorizarea_cantitatii_de_CO2_dintr-un_avion.ino
├── Proteus/
│   └── Monitorizarea_cantitatii_de_CO2_dintr-un_avion.pdsprj
└── Tests/
    ├── Rezultate_simulare_proteus.pdf
    ├── Rezultate_simulare_proteus.docx
    ├── Teste_logice_cod.pdf
    └── Teste_logice_cod.docx
```

### Simulare

Fișierul din directorul `Proteus` conține proiectul de simulare Proteus. Codul Arduino este disponibil separat în directorul `Arduino`, într-o formă comentată pentru a fi mai ușor de urmărit.

### Testare

Au fost realizate teste în Proteus și teste ale logicii codului pentru verificarea comportamentului sistemului.

## 🇬🇧 English

This project is a system for monitoring the amount of CO₂ in an aircraft, implemented with Arduino and simulated in Proteus.

The project reads an analog value from input A0, displays it on a 16x2 LCD and indicates the normal, WARNING, ALARM and ERROR states using LEDs. When an alarm condition occurs, the ventilation output is activated.

### Features

1. Sensor values are read at one-second intervals.
2. All read values must be within a predefined range. Values outside the range are ignored.
3. When three consecutive readings from a sensor generate values outside the predefined range, the LED corresponding to that sensor changes from green to red and an **ERROR** is generated.
4. Depending on the read values, **WARNING** or **ALARM** signals can be generated.
5. When a **WARNING** signal is generated, an LED changes from green to red.
6. A **WARNING** persists until it is acknowledged by the pilot or the conditions that generated it disappear.
7. After acknowledgement, a new **WARNING** is generated only if there has been at least one reading for which neither **WARNING** nor **ALARM** was generated.
8. When an **ALARM** signal is generated, an LED changes from green to red.
9. An **ALARM** persists until the conditions that generated it disappear.
10. The amount of CO₂ is read using a sensor.
11. The amount of CO₂ is displayed on a clock-type display.
12. When the amount of CO₂ is greater than **0.1%**, a **WARNING** signal is generated.
13. If the **WARNING** signal is acknowledged, the ventilation system is started.
14. When the amount of CO₂ is greater than **0.3%**, an **ALARM** signal is generated.
15. After the **ALARM** signal appears, the ventilation system is started.
16. The ventilation system is stopped if the amount of CO₂ is lower than **0.05%**.

### CO₂ Thresholds

|  Condition  | Value Behavior | Behavior |
|-------------|----------------|----------|
| CO₂ > 0.1%  |   0.10 – 0.30  | WARNING |
| CO₂ > 0.3%  |   0.30 – 1.00  | ALARM + ventilation starts |
| CO₂ < 0.05% |   0.00 – 0.05  | Ventilation stops |

outside 0 – 1 Value considered invalid 3 invalid readings ERROR

The values are obtained from the analog reading and divided by 1000 for display.

### Main components / connections

- Arduino Uno
- 16x2 RGB LCD
- analog input `A0`
- WARNING LEDs
- ALARM LEDs
- ERROR LEDs
- digital output `D7` for the ventilation system
- Serial communication at `9600 baud`

### Repository structure

```text
Monitorizarea-cantitatii-de-CO2-dintr-un-avion/
├── README.md
├── Arduino/
│   └── Monitorizarea_cantitatii_de_CO2_dintr-un_avion.ino
├── Proteus/
│   └── Monitorizarea_cantitatii_de_CO2_dintr-un_avion.pdsprj
└── Tests/
    ├── Rezultate_simulare_proteus.pdf
    ├── Rezultate_simulare_proteus.docx
    ├── Teste_logice_cod.pdf
    └── Teste_logice_cod.docx
```

### Simulation

The `Proteus` directory contains the Proteus simulation project. The Arduino source code is provided separately in the `Arduino` directory in a commented version for easier understanding.

### Testing

Tests were performed in Proteus as well as tests of the code logic to verify the system behavior.

---

## Autor / Author

**IonutD**
