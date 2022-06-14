/*
   Patient Management System
   
   Simple C program, to add, remove, delete and edit up to 20 patients.

   Created by Arthur Ruckdeschel

   last edited by Arthur Ruckdeschel
   on 14.06.2022

*/

#include <stdio.h>      
#include <string.h>     
#include <stdlib.h>
#define MAXARRAY 20     // Arrays werden hiermit auf 20 Eintraege limitiert
#define MAXSTR 20       // Strings werden hiermit auf 20 Zeichen limitiert

const int count = 0;    // globale Zaehlervariable
int i;                  // globale Zaehlervariable
int p;                  // globale Zaehlervariable
int e;                  // globale Zaehlervariable
int t = 0;

struct Patient {   
    int patient_nr;                 // einzigartige Patientennummer
    char name[MAXSTR];              // erstellt die Struktur mit dem Namen "name" und limitiert es auf 20 Zeichen 
    char surname[MAXSTR];           // erstellt die Struktur mit dem Namen "surname" und limitiert es auf 20 Zeichen
    int upper_measurement_value;    // Variablen für die beiden Messwerte
    int lower_measurement_value;
} 

patient_database [MAXARRAY];        // Array von der Struktur, erfasst 20 Datensaetze 

int main (int argc, char* argv[]) { // Hauptfunktion - ist Beginn des Programms und Hauptauswahl

    int auswahl;                    // Definieren der ganzzahligen Auswahlvariablen 

    do {                            // Auswahl mit allen Hauptoptionen
        printf("\n\n1: Neuer Patient\n"); 
        printf("2: Einzelnen Patienten ausgeben/bearbeiten\n");
        printf("3: Alle Patienten ausgeben\n");
        printf("4: Datei aller Patienten erstellen\n");
        printf("5: Patientenverwaltung einlesen\n");
        printf("6: Letzten Patienten entfernen\n");
        printf("7: Alle Patientendaten entfernen\n");
        printf("8: Programm beenden\n\n");
        printf("Was soll getan werden?: ");
        scanf("%d",&auswahl);       // Erwartet Eingabe des Nutzers und schreibt den eingegebenen Wert auf "auswahl"
        getchar();                  // liest genau ein Zeichen der Tastatur

        switch (auswahl) {          // alle Auswahloptionen werden hier abgedeckt
            case 1: input(i++, patient_database);   // Aufrufen der Funktion "input" zur Eingabe eines Patienten, globale Variable "x"  und Struktur "patient_database" vom Typ "struct Patient" uebergeben. Nach dem Ausfuehren der Funktion wird der Wert von "x" inkrementiert.
                    break;                          // verhindert, dass folgende Befehle automatisch ausgefuehrt werden, indem es den "switch"-Loop vorzeitig beendet
            case 2: single_patient (patient_database, i);   // Aufrufen der Funktion "single_patient" 
                    break;
            case 3: output_all(patient_database, i); // Aufrufen der Funktion "output_all" 
                    break;
            case 4: write_data(patient_database, i); // Aufrufen der Funktion "write_data" 
                    break;
            case 5: read_data(patient_database, i); // Aufrufen der Funktion "read_data"
                    break;
            case 6: delete_last(patient_database, i); // Aufrufen der Funktion "delete_last()" 
                    break;          
            case 7: delete_all(patient_database, i); // Aufrufen der Funktion "delete_all()" 
                    break;      
            case 8: printf("Programm beendet.\n");  // Programm zeigt an, dass es beendet ist und beendet sich dann von selbst
                    exit(0);                        // Beendet das Programm und schliesst das Programmfenster
                    break;
            default: printf("Bitte entscheiden Sie zwischen 1 und 8.\n"); // Sollte die Auswahl nicht zwischen 1 und 8 liegen, wird das Programm auf den Punkt vor der Auswahl gesetzt und der Anwender kann erneut eine Auswahl treffen.
                     main(patient_database, i);
        }
    }

   while (auswahl < 8); // Solange der Auswahlwert unter 8 liegt wird die Funktion ausgefuehrt 
   return 0;
}

// case 1 von main
void input (int amount_patients, struct Patient neu[]) {     // Funktion zur Eingabe der Patientendaten, "amount_patients" beginnt bei 0 und wird in case 1 (int main) um 1 inkrementiert
    
    if (amount_patients < MAXARRAY) {                        // ueberprueft, ob bereits 20 Patienten vorhanen sind und wird nur ausgefuehrt, wenn dies nicht so ist
        printf("\n\nPatient:  %d\n\n", amount_patients+1);   // Patientennummern werden immer dynamisch berechnet, indem "amount_patients" immer um 1 erhoet und dann ausgegeben wird. Damit ist es leichter einen einzelnen Patienten zu entfernen und alle anderen dann aufrutschen zu lassen.

        printf("Patientennummer: ");
        do {
            scanf("%d",&neu[amount_patients].patient_nr);   // ganzzahlige patient_nr wird won Anwendereingabe eingelesen
        }

        while(getchar()!= '\n');                            // die nachfolgede Funktion wird solange durchgefuehrt, bis ein int Wert eingelesen wurde und mit der Entertaste ein Zeilenumbruch generiert wird
      
        printf("Vorname: "); 
        fgets(neu[amount_patients].name, MAXSTR, stdin);    // liest den name, welchen der Anwender eingibt ein (begrenzte Zeichenkette)

        printf("Nachname: ");
        fgets(neu[amount_patients].surname, MAXSTR, stdin); // liest den surname, welchen der Anwender eingibt ein (begrenzte Zeichenkette)
  
        printf("oberer Messwert: ");
        do {
            scanf("%d",&neu[amount_patients].upper_measurement_value);  // liest den upper_measurement_value, welchen der Anwender eingibt ein
        }

        while(getchar()!= '\n'); 

        printf("unterer Messwert: ");
        do {
            scanf("%d",&neu[amount_patients].lower_measurement_value);  // liest den lower_measurement_value, welchen der Anwender eingibt ein
        }
        
        while(getchar()!= '\n'); 
        printf("Patient efolgreich erstellt!");
    }

    else { // sollte das Array voll sein (20 Datensaetze vorhanden) wird ausgegeben, dass der Speicher voll ist und man wird zurueck nach "int main" geschoben
        
        printf("\n\nEs sind bereits 20 Patienten eingetragen! Bitte entfernen Sie alte Patienten, um neue Patienten anzulegen!\n\n");
        --i; // zuruecksetzen der Zaehlvariable auf Zustand vor der Ausgabe
    } 
}

// case 2 von main
void single_patient (struct Patient list_all[], int amount_patients) { // Funktion, um aus allen Patienten einen einzelnen heruaszusuchen

    int auswahl;

    if (amount_patients != 0) { // Wenn "amount_patients" ungleich Null ist, dann wird die if-Schleife ausgefuehrt

        for (i = 0; i < amount_patients; i++) { // Startwert der Zaehlvariable i = 0, Durchlauf solange, wie i < amount_Patients, d.h. so viele Patienten, wie im Array eingegeben wurden
            printf("\n\nPatient:  %d\n", i + 1); // Patienten werden mit fortlaufender Nummer versehen, indem i inkrementiert wird, Start bei 1, da i = 0 und i + 1 = 1
            printf("Patientennummer     : %d\n",list_all[i].patient_nr);    // Um weniger Daten anzuzeigen, wird nur Pat.nr. und Nachname ausgegeben
            printf("Nachname            : %s\n",list_all[i].surname);
        }

        printf ("\nWelcher Patient?: ");
        scanf("%d",&auswahl); // Eingabe der Auswahl
        getchar();

        if (auswahl >= 1 && auswahl <= amount_patients) {   // Schleife, um Patienten unter 0 und Patienten, welche nicht angelegt sind nicht anpassbar zu machen
            p = auswahl - 1;                            // da "auswahl" bei 1 beginnt, die Patienten aber digital ab 0 gezaehlt werden, muss hier -1 gerechnet werden
            printf("\n\nPatient:  %d\n\n", auswahl);    // Patienten werden mit fortlaufender Nummer versehen, indem i inkrementiert wird, Start bei 1, da i = 0 und i+ = 1
            printf("Patientennummer     : %d\n",list_all[p].patient_nr);    // die Patientendaten an der Stelle p (auswahl-1) wird angezeigt
            printf("Vorname             : %s\n",list_all[p].name);
            printf("Nachname            : %s\n",list_all[p].surname);
            printf("oberer Messwert     : %d\n",list_all[p].upper_measurement_value);
            printf("unterer Messwert    : %d\n\n",list_all[p].lower_measurement_value);
               
        
            printf("1. Patient anpassen\n");
            printf("2. Patient entfernen\n");
            printf("3. Vorherige Optionen\n\n");
            printf("Was soll getan werden?: ");
            scanf("%d", &auswahl);
            getchar();
        
            switch (auswahl) {
                case 1: patient_edit(p, patient_database);
                        break;
                case 2: patient_delete_single(p, patient_database);
                        break;
                case 3: main(auswahl, patient_database);
                        break;
                default:printf("\nBitte entscheiden Sie zwischen 1 und 2!\n");
                        break;
            }
        }

        else {
            printf("\nAuswahl muss ein existierender Patient sein!\n\n");
            single_patient;
        }
    }

    else { // Funktion wird ausgefuehrt, wenn "x" = 0 und somit auch "amount_patients" = 0 
        printf("\n\nEs sind noch keine Patienten gespeichert!\n\n");
    }
}

// case 1 von single_patient
void patient_edit (int patient_database, struct Patient edit[]) {      // Zwischenfunktion fuer "edit_name" und "edit_value"

    int auswahl;
    printf("\n\n1. Vorname\n");
    printf("2. Nachname\n");
    printf("3. Unterer Messwert\n");
    printf("4. Oberer Messwert\n");
    printf("5. Vorherige Optionen");
    printf("\n\nWas soll angepasst werden?: ");
    scanf("%d", &auswahl);                      // Anwendereingabe wird eingelesen und dann auf "auswahl" geschrieben
    getchar();
                    // hier werden if/else-Schleifen verwendet, da es dadurch in den unterfunktionen leichter ist zwischen den einzelnen Eingaben zu unterscheiden.
    if (auswahl == 1 || auswahl == 2) {          // Schleife wird ausgefuehrt, wenn "auswahl" 1 oder 2 ist
        edit_name(auswahl, patient_database);   // "edit_name" wird aufgerufen und "auswahl" und "patient_database" werden uebergeben
    }

    else if (auswahl == 3 || auswahl == 4) {     // Schleife wird ausgefuehrt, wenn "auswahl" 3 oder 4 ist
        edit_value(auswahl, patient_database);  // "edit_value" wird aufgerufen und "auswahl" und "patient_database" werden uebergeben
    }

    else if (auswahl == 5) {
        single_patient(auswahl, patient_database);
    }

    else {                                       // Failsafe, falls der Anwender eine andere Zahl auswaehlt
        printf("\n\nBitte entscheiden Sie zwischen 1 und 5.\n\n");
    }
}

// Unterfunktion von patient_edit
void edit_name (int auswahl, struct Patient edit_name[]) {    // Funktion, um einen einzelnen Namen zu editieren (wird in "patient_edit" aufgerufen)

    if (auswahl == 1) {                                      // ueberprueft, ob die Auswahl aus "patient_edit" 1 ist und führt dann aus
    printf("\n\nWie lautet der neue Vorname?: ");
    scanf("%s", &edit_name[p].name);                        // scannt nach Anwendereingabe und aendert den Namen dann an der Stelle "p" (wird in "single_patient" definiert)
    printf("\n\nVorname erfolgreich angepasst.\n");
    i--;
    }

    else {                                                  // da hier die "auswahl" nur 1 oder 2 sein kann, wird hier nur aufgerufen, wenn 2 ausgewaehlt wurde
        printf("\n\nWie lautet der neue Nachname?: ");
        scanf("%s", &edit_name[p].surname, "\n");           // siehe oben
        printf("\n\nNachname erfolgreich angepasst.\n");
        i--;
    }
}

// Unterfunktion von patient_edit
void edit_value (int auswahl, struct Patient edit_value[]) {         // Funktion, um einzelne Messwerte anpassen zu koennen

    if (auswahl == 3) {                                              // siehe "edit_name"
        printf("\n\nWie lautet der korrigierte/neue Messwert?\n");
        scanf("%d", &edit_value[p].lower_measurement_value, "\n");
        printf("\n\n Messwert erfolgreich angepasst.\n");
        i--;
    }    

    else {
        printf("\n\nWie lautet der korrigierte/neue Messwert?\n");
        scanf("%d", &edit_value[p].upper_measurement_value, "\n");
        printf("\n\n Messwert erfolgreich angepasst.\n");
        i--;
    }
}

// case 2 von single_patient
void patient_delete_single (int p, struct Patient delete_single[]) { // Funktion, um einen einzelnen Patienten zu loeschen

        for (p; p < MAXARRAY; p++) {
            delete_single[p].patient_nr = delete_single[p+1].patient_nr;     // int-Werte des Patienten "p" werden mit dem Wert "0" ueberschrieben
            delete_single[p].name[0] = delete_single[p+1].name[0]; // surname und name werden ueberschrieben.
            delete_single[p].surname[0] =  delete_single[p+1].surname[0]; 
            delete_single[p].upper_measurement_value = delete_single[p+1].upper_measurement_value; 
            delete_single[p].lower_measurement_value = delete_single[p+1].lower_measurement_value;
        }

        i--;
        printf("\n\nPatienten erfolgreich entfernt.\n\n");
}

// case 3 von main
void output_all (struct Patient all[],int amount_patients) { // Ausgabefunktion aller Patientendaten in der patient_database

    if (amount_patients != 0) {                              // wird nur ausgefuehrt, wenn Patienten existieren (amount_patients darf nicht gleich null sein)

        for (i = 0; i < amount_patients; i++) {               // Zaehlvariable wird auf i = 0 gesetzt, Durchlauf solange, wie i < amount_Patients
            printf("\n\nPatient:  %d\n\n", i + 1);              // Patienten werden dynamisch mit fortlaufender Nummer versehen, indem i erhoeht wird, Start bei 1, da i = 0 und i++ = i + 1
            printf("Patientennummer     : %d\n",all[i].patient_nr);  // nachfolgend werden alle Daten jedes Patienten ausgegeben, mit "all[i]" wird definiert welcher Patient und mit ".patient_nr" (etc) welche Stelle des Arrays ausgegeben werden soll
            printf("Vorname             : %s",all[i].name);
            printf("Nachname            : %s",all[i].surname);
            printf("oberer Messwert     : %d\n",all[i].upper_measurement_value);
            printf("unterer Messwert    : %d\n",all[i].lower_measurement_value);
        }
    }

    else {                                                   // wird ausgefuehrt, wenn kein Patient gespeichert ist ("amount_patients" = 0)
        printf("\n\nEs sind noch keine Patienten gespeichert!\n\n");
    }
    
}

// case 4 von main
void write_data (struct Patient write_all[], int amount_patients) {   // Schreiben der Patientendaten aus der patient_database in eine Datei

    if (amount_patients != 0) {
        FILE *write_data;
        write_data = fopen("Patientendaten.txt", "w+");          // in Datei wird geschrieben (w), falls nicht vorhanden, wird sie erzeugt (w+)

        for (i = 0; i < amount_patients; i++) { // selbe for-Schleife, wie in "output_all", nur dass hier alles in die Datei geschrieben wird
            fprintf(write_data, "\nPatient  %d\n\n", i+1); 
            fprintf(write_data,"Patientennummer     : %d\n",write_all[i].patient_nr);
            fprintf(write_data,"Vorname             : %s",write_all[i].name);
            fprintf(write_data,"Nachname            : %s",write_all[i].surname);
            fprintf(write_data,"oberer Messwert     : %d\n",write_all[i].upper_measurement_value);
            fprintf(write_data,"unterer Messwert    : %d\n\n",write_all[i].lower_measurement_value);
        }

        fclose(write_data); // Datei wird geschlossen 
        printf("Datei erfolgreich erstellt!");
    }

    else {
        printf("Es sind noch keine Patienten gespeichert.");
        main(i, patient_database); // Loop auf main, damit das Programm hier nicht einfach endet
    }
}

// case 5 von main
void read_data () {               // Funktion zum Lesen einer Datei, Datei muss sich im gleichen Ordner wie c-Datei befinden, damit sie eingelesen werden kann.

    FILE *read_data;
    read_data = fopen("Patientendaten.txt", "r"); // Datei mit dem Namen "Patientenverwaltung.txt" wird geoeffnent
    
    if (read_data == NULL) {       // ueberpruefung, ob die "read_data" leer ist (existiert nicht, oder hat falschen Namen). Wenn die "read_data" Null ist, wird der Benutzer darauf hingewiesen.
        printf("Diese Datei konnte nicht gefunden werden\nBitte kontrollieren Sie den Namen und Speicherort der Datei!");
        main(i, patient_database);
    }

    else { // ist die "read_data" nicht null, werden die Daten daraus eingelesen 
        char zeichen;
        while ((zeichen = fgetc(read_data)) != EOF) {   // "fgetc"  liest immer das erste Zeichen der Datei / die Schleife laeuft, bis alle Zeichen der Datei eingelesen sind (EOF= End of File, unsichtbare -1)
            printf("%c", zeichen);  
        }   
    }
}

// case 6 von main
void delete_last (struct Patient delete_last[], int amount_patients) { // Loeschfunktion fuer den letzten Patienten in der patient_database

    if (amount_patients != 0) {
        delete_last[amount_patients-1].patient_nr= 0;       // int-Werte werden mit Wert "0" ueberschrieben - praktisch geloescht
        delete_last[amount_patients-1].name[0] = '\0';   // name und surname werden ebenfalls ueberschrieben
        delete_last[amount_patients-1].surname[0] = '\0';
        delete_last[amount_patients-1].upper_measurement_value = 0; 
        delete_last[amount_patients-1].lower_measurement_value = 0;
        printf("\n\nPatient erfolgreich entfernt!\n");
        i--;                                                // Zaehler um 1 verringern  
        main(i, amount_patients);
    }

    else {
        printf("Es sind keine Patienten gespeichert.");
        main(i ,amount_patients);
    }
} 

// case 7 von main
void delete_all (struct Patient delete_all[],int amount_patients) { // Funktion zum Entfernen aller Patienten in der patient_database

    if (amount_patients != 0) {
        for (i = 0; i < amount_patients; i++) {   // siehe "output_all"
            delete_all[i].patient_nr= 0;        // int-Werte werden mit dem Wert "0" ueberschrieben
            delete_all[i].name[0] = '\0';    // name und surname werden ebenfalls ueberschrieben.
            delete_all[i].surname[0] = '\0';
            delete_all[i].upper_measurement_value = 0; 
            delete_all[i].lower_measurement_value = 0;
        } 

        printf("\n\nDaten erfolgreich entfernt!\n");
        i = 0;                                  // zuruecksetzen des Zaehlers
        main(i, amount_patients);
    }
    
    else {
        printf("Es sind keine Patienten gespeichert.");
        main(i, amount_patients);
    }
} 