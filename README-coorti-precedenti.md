# Laboratorio per il corso di Algoritmi e Strutture Dati: specifica per studenti e studentesse di anni precedenti il 2024/2025 (esercizi in C e in Java)

Questo documento descrive la variante del progetto di laboratorio con due esercizi in C e due esercizi in Java. Per tutto ciò che non è indicato qui vale quanto riportato nel documento [README.md](README.md).

# Regole d'esame

Valgono le regole d'esame, la validità del progetto di laboratorio e le regole su gruppi e turni riportate in [README.md](README.md), con le seguenti precisazioni:

- i correttori automatici messi a disposizione sulla pagina Moodle riguardano gli Esercizi 1 e 2: il superamento di tutti i loro test resta condizione per poter sostenere la prova scritta;
- gli Esercizi 3 e 4 devono essere consegnati mediante GitLab entro la data della prova scritta, come il resto del progetto, e sono verificati durante la prova orale;
- la presente specifica non prevede l'Esercizio 5.

# Indicazioni generali e suggerimenti

Valgono le indicazioni di [README.md](README.md) su uso di GitLab, relazione sugli esercizi, unit testing e qualità dell'implementazione, con le differenze riportate di seguito.

## Linguaggio in cui sviluppare il laboratorio

Gli esercizi vanno implementati nel linguaggio indicato:

- Esercizio 1: C
- Esercizio 2: C
- Esercizio 3: Java
- Esercizio 4: Java

**Suggerimento per la realizzazione di codice generico in Java**: la soluzione più in linea con l'uso moderno del linguaggio è la definizione di classi parametriche; tutte le scelte implementative (compresa la decisione di usare o meno classi parametriche) sono comunque lasciate agli studenti. È possibile, e consigliato, usare `ArrayList` al posto degli array nativi, al fine di semplificare la realizzazione di codice generico.

## Uso di librerie esterne e/o native del linguaggio scelto

La regola di [README.md](README.md) si applica separatamente a ciascun linguaggio: negli esercizi in Java è vietato l'uso di strutture dati native del linguaggio o offerte da librerie esterne, quando la loro realizzazione è richiesta da uno degli esercizi in Java; è possibile l'uso delle altre.

**Esempio:** negli Esercizi 3 e 4 è consentito l'uso di `java.util.ArrayList`, `java.util.HashMap` e `java.util.HashSet` e dei metodi di ordinamento della libreria standard (`List.sort`, `Collections.sort`), perché la tavola hash e l'algoritmo di ordinamento sono oggetto dei soli esercizi in C. Non è consentito l'uso di librerie che implementano insiemi disgiunti, grafi o algoritmi su grafi.

## Unit Testing

Gli unit test degli esercizi in Java vanno realizzati con JUnit, secondo le indicazioni della sezione "Unit testing in Java" del documento [Unit Testing](UnitTesting.md).

## Qualità dell'implementazione

Per il codice Java, in aggiunta ai suggerimenti di [README.md](README.md):

- verificare che il codice sia suddiviso correttamente in package;
- per dare i nomi agli identificatori, seguire le convenzioni in uso per il linguaggio Java: i nomi dei package sono tutti in minuscolo senza separazione fra le parole (es. thepackage); i nomi dei tipi (classi, interfacce, ecc.) iniziano con una lettera maiuscola e proseguono in camel case (es. TheClass); i nomi dei metodi e delle variabili iniziano con una lettera minuscola e proseguono in camel case (es. theMethod); i nomi delle costanti sono tutti in maiuscolo e in formato snake case (es. THE\_CONSTANT).

# Consegne per gli esercizi

Vale quanto riportato all'inizio della sezione "Consegne per gli esercizi" di [README.md](README.md), compresa la regola sulla complessità computazionale: **le consegne che non rispettano la complessità computazionale richiesta saranno considerate completamente invalide.**

## Esercizio 1 - Algoritmo di ordinamento ibrido QuickSort-SelectionSort

### Linguaggio richiesto: C

La libreria da implementare e i relativi unit test sono quelli descritti nell'Esercizio 1 di [README.md](README.md). In aggiunta, sono richiesti un programma principale che usa la libreria e un'analisi sperimentale, come descritto di seguito. Le condizioni per la consegna riportate qui sostituiscono quelle di [README.md](README.md).

### Uso della libreria di ordinamento implementata

#### Dataset

Il file `records.bin.gz` che potete trovare (compresso) all'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/3c9H8ZAFqQWEBcf](https://datacloud.di.unito.it/index.php/s/3c9H8ZAFqQWEBcf)

contiene 20 milioni di record da ordinare in formato binario compresso.

**Formato del file binario:**
Il file compresso deve essere estratto prima dell'uso. Una volta decompresso, `records.bin` è strutturato come una sequenza di record, ognuno dei quali occupa esattamente 36 bytes:
- **Byte 0-7**: `id` (intero senza segno a 64 bit, little-endian)  
- **Byte 8-11**: `field1` (float a 32 bit, IEEE 754, little-endian)
- **Byte 12-19**: `field2` (intero con segno a 64 bit, little-endian)
- **Byte 20-35**: `field3` (stringa di 16 caratteri, padding con '\0' se necessario)

Il campo `field3` contiene parole estratte dalla Divina Commedia (massimo 15 caratteri utili + terminatore). I campi sono generati per testare diversi scenari di ordinamento, inclusi casi che possono portare alcuni algoritmi di ordinamento al caso peggiore.

**Suggerimento:**  Per facilitare la manipolazione del file binario, si consiglia di implementare una libreria di supporto con funzioni come:

```c
int read_record(FILE *file, Record *record);
int write_record(FILE *file, const Record *record);
int load_records_from_file(FILE *file, Record **records, size_t *count);
int save_records_to_file(FILE *file, const Record *records, size_t count);
void print_record(const Record *record);
```

#### Programma principale

Usando l'algoritmo implementato precedentemente, si realizzi la seguente funzione per ordinare i *record* contenuti nel file `records.bin` in ordine non decrescente secondo i valori contenuti nei campi specificati.

```c
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t k);
```

**Parametri:**
- `infile`: il file binario contenente i record da ordinare.
- `outfile`: il file binario nel quale salvare i record ordinati (deve essere diverso da `infile`).
- `field`: può valere 1, 2, 3 o 4 e indica quale campo deve essere usato per ordinare i record:
  - `1`: ordina per `id` (intero senza segno a 64 bit);
  - `2`: ordina per `field1` (float);
  - `3`: ordina per `field2` (intero con segno a 64 bit);
  - `4`: ordina per `field3` (stringa, ordine lessicografico).
- `k`: soglia per l'algoritmo ibrido:
  - se `k=0`: l'intero array sarà ordinato solo con QuickSort;
  - se `k > numero_totale_record`: l'intero array sarà ordinato solo con SelectionSort;
  - altrimenti: usa QuickSort per sottoinsiemi ≥ k, SelectionSort per sottoinsiemi < k.

### Analisi sperimentale

Si misurino i tempi di risposta dell'algoritmo ibrido per ciascuno dei quattro campi che si possono usare come chiave di ordinamento, al variare di `k`.

**Valori di k da testare**: 0, 10, 50, 100, 500, 1000, 5000, 10000, 1000000

**Gestione della memoria**: L'implementazione deve gestire correttamente l'allocazione e la deallocazione della memoria, evitando memory leak e sprechi di memoria. Si consiglia di testare l'applicazione con strumenti come Valgrind.

Si produca una breve relazione (in formato Markdown nel file `README.md`) in cui si riportano:

1. **Tabelle dei tempi**: tempi di esecuzione per ogni combinazione di campo e valore di k.
2. **Analisi critica**:
   - I risultati corrispondono alle aspettative teoriche?
   - Esiste un valore ottimale di k? Se sì, quale e perché?
   - L'approccio ibrido offre vantaggi rispetto agli algoritmi puri?
   - Ci sono differenze significative tra i diversi tipi di campi?

**Vincoli temporali**: Nel caso l'ordinamento non finisca entro 5 minuti, interrompere l'esecuzione e riportare un fallimento dell'operazione nella relazione. Tempi di esecuzione eccessivi possono indicare che il valore di k è troppo elevato o che ci sono problemi nell'implementazione del QuickSort, ad esempio, degenerazione verso il caso peggiore O(n²). In quest'ultimo caso, riflettere sulla strategia di scelta del pivot per sistemare il problema.

**Si ricorda che i file `records.bin.gz`, `records.bin` (e i file compilati) NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex1` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile` che con il comando `make all` produca all'interno di `ex1/bin` due file eseguibili chiamati `main_ex1` e `test_ex1`.
- Se avete usato librerie esterne (come Unity per i test) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex1` non deve richiedere parametri e deve eseguire tutti gli unit test automatizzati.
- L'eseguibile `main_ex1` deve ricevere come parametri:

```bash
$ ./bin/main_ex1 <input_file> <output_file> <field> <k>
```

**Esempio di utilizzo:**
```bash
$ ./bin/main_ex1 records.bin sorted_output.bin 1 50
```

Questo comando ordinerà i record del file `records.bin` secondo il campo `id` (field=1) usando l'algoritmo ibrido con soglia k=50, salvando il risultato in `sorted_output.bin`.

## Esercizio 2 - Tavole hash (con concatenamento)

### Linguaggio richiesto: C

La libreria da implementare e i relativi unit test sono quelli descritti nell'Esercizio 2 di [README.md](README.md). In aggiunta, è richiesto un programma principale che usa la libreria, come descritto di seguito. Le condizioni per la consegna riportate qui sostituiscono quelle di [README.md](README.md).

### Uso delle funzioni implementate

All'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/Ti4Mz7j4Xtjn3Db](https://datacloud.di.unito.it/index.php/s/Ti4Mz7j4Xtjn3Db)

potete trovare un file (`iliade.txt`) contenente l'Iliade di Omero in inglese.

Scrivere un programma che utilizza la tavola hash implementata per calcolare la parola, di lunghezza almeno pari a un valore minimo dato, che sia più frequente nel file di testo dato.

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex2` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile`. Questo file con il comando `make all` deve produrre all'interno di `ex2/bin` due file eseguibili chiamati `main_ex2` e `test_ex2`. Se avete usato librerie esterne (come Unity) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex2` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.
- L'eseguibile `main_ex2` deve ricevere come parametri il percorso del file di testo da usare e la lunghezza minima delle parole da considerare. Per esempio:

```
$ ./main_ex2 /tmp/data/iliade.txt 6
```

## Esercizio 3 - Libreria Union-Find-Set per la gestione di insiemi dinamici disgiunti

### Linguaggio richiesto: Java

Implementare una libreria generica che realizza la struttura dati *Union-Find-Set* per la gestione di insiemi dinamici disgiunti.

### Ulteriori specifiche per l'implementazione:

1. La libreria deve essere generica, nel senso che essa deve supportare la gestione di un numero qualsiasi di insiemi disgiunti, ciascuno con un numero qualsiasi di elementi di tipo non noto a priori; la struttura dati non deve prevedere un insieme iniziale finito di elementi;
2. L'implementazione deve rappresentare la collezione di insiemi come una foresta di insiemi disgiunti;
3. L'implementazione deve adottare le due euristiche note come *unione per rango* e *compressione del cammino*, viste nella parte di teoria del corso;
4. Le eventuali tavole hash usate nell'implementazione possono essere quelle della libreria standard di Java (ad esempio `java.util.HashMap`);
5. L'implementazione deve essere computazionalmente efficiente (in particolare, le scelte implementative non devono vanificare l'apporto all'efficienza delle due euristiche citate sopra).

La struttura dati deve offrire almeno le seguenti operazioni (ricavarne il significato da quanto studiato nella parte di teoria del corso); nomi e firme dei metodi e organizzazione in classi sono lasciati agli studenti:

- creazione di una collezione vuota di insiemi disgiunti;
- *make-set*: creazione di un insieme contenente un solo elemento dato;
- *find-set*: determinazione del rappresentante dell'insieme che contiene un elemento dato;
- *union*: unione degli insiemi che contengono due elementi dati.

### Unit Testing

Implementare gli unit test per la libreria con JUnit, secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex3` all'interno del repository.
- La consegna deve consentire di compilare il codice e di eseguire tutti gli unit test da riga di comando, senza l'uso di un ambiente di sviluppo integrato. I comandi necessari, oppure un `Makefile` o uno script che li esegue, devono far parte della consegna.
- Se l'implementazione usa librerie esterne (come JUnit), includere anche i relativi file `.jar` per consentire la corretta compilazione.

## Esercizio 4 - Libreria per Grafi sparsi e algoritmo di Kruskal

### Linguaggio richiesto: Java

Implementare una libreria generica che realizza la struttura dati *Grafo* in modo che sia ottimale per dati sparsi (**attenzione**: le scelte implementative dovranno essere giustificate in relazione alle nozioni presentate durante le lezioni in aula).

### Ulteriori specifiche per l'implementazione:

1. L'implementazione deve essere generica, nel senso che essa deve consentire la gestione di grafi con un numero qualsiasi di nodi e di archi, in cui i tipi dei nodi e delle etichette degli archi non sono noti a priori;
2. La struttura dati deve consentire di rappresentare grafi diretti e grafi non diretti, etichettati e non etichettati;
3. Le eventuali tavole hash usate nell'implementazione possono essere quelle della libreria standard di Java (ad esempio `java.util.HashMap`).

La struttura dati deve offrire almeno le seguenti operazioni; accanto a ogni operazione è indicata la complessità richiesta, dove _N_ può indicare il numero di nodi o il numero di archi, a seconda del contesto. Nomi e firme dei metodi e organizzazione in classi sono lasciati agli studenti.

- Creazione di un grafo vuoto, diretto o non diretto, etichettato o non etichettato – O(1)
- Verifica se il grafo è diretto – O(1)
- Verifica se il grafo è etichettato – O(1)
- Aggiunta di un nodo – O(1)
- Verifica se il grafo contiene un dato nodo – O(1)
- Cancellazione di un nodo – O(N)
- Determinazione del numero di nodi – O(1)
- Recupero dei nodi del grafo – O(N)
- Aggiunta di un arco, dati gli estremi e l'etichetta – O(1) (*)
- Verifica se il grafo contiene un dato arco – O(1) (*)
- Cancellazione di un arco – O(1) (*)
- Determinazione del numero di archi – O(N)
- Recupero degli archi del grafo – O(N)
- Recupero dell'etichetta associata a una coppia di nodi – O(1) (*)
- Recupero dei nodi adiacenti a un dato nodo – O(1) (*)
- Determinazione del numero di nodi adiacenti a un dato nodo – O(1)

**Nota**: le complessità contrassegnate con (*) valgono quando il grafo è veramente sparso, assumendo che l'operazione venga effettuata su un nodo la cui lista di adiacenza ha una lunghezza in O(1).

*Suggerimento*: un grafo non diretto può essere rappresentato usando un'implementazione per grafi diretti modificata per garantire che, per ogni arco *(a,b)* etichettato *w* presente nel grafo, sia presente nel grafo anche l'arco *(b,a)* etichettato *w*. Il grafo dovrà mantenere l'informazione che specifica se esso è un grafo diretto o non diretto.

### Unit Testing

Implementare gli unit test per la libreria con JUnit, secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso della libreria che implementa la struttura dati Grafo

Si implementi l'*algoritmo di Kruskal* per il calcolo di una minima foresta ricoprente di un grafo non diretto e pesato (non necessariamente connesso).

#### Ulteriori specifiche per l'implementazione:

1. L'algoritmo deve sfruttare la struttura dati Union-Find-Set implementata nell'Esercizio 3;
2. L'algoritmo deve restituire un grafo, cioè un'istanza della struttura dati implementata nella prima parte di questo esercizio (si ricordi che ogni foresta è un grafo): un albero se il grafo dato è connesso, altrimenti una foresta costituita dai minimi alberi ricoprenti di ciascuna componente connessa.

#### Unit Testing

Implementare gli unit test per l'algoritmo con JUnit, secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso delle librerie che implementano la struttura dati Grafo e l'algoritmo di Kruskal

Si implementi un'applicazione che legge il file `italian_dist_graph.csv`, costruisce il grafo corrispondente, ne calcola una minima foresta ricoprente con l'algoritmo di Kruskal e stampa il numero di nodi, il numero di archi e il peso complessivo (in km) della foresta ottenuta.

Il file `italian_dist_graph.csv`, che potete recuperare (compresso) all'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY](https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY)

contiene le distanze in metri tra varie località italiane e una frazione delle località a loro più vicine. Il formato è un CSV standard: i campi sono separati da virgole; i record sono separati dal carattere di fine riga (`\n`).

Ogni record contiene i seguenti dati:

- `place1`: (tipo stringa) nome della località "sorgente" (la stringa può contenere spazi ma non può contenere virgole);
- `place2`: (tipo stringa) nome della località "destinazione" (la stringa può contenere spazi ma non può contenere virgole);
- `distance`: (tipo float) distanza in metri tra le due località.

**Note:**

- Le informazioni presenti nelle righe del file vanno interpretate come archi **non diretti**.
- Il file è stato creato a partire da un dataset poco accurato. I dati riportati contengono inesattezze e imprecisioni.

**Si ricorda che il file `italian_dist_graph.csv` (e i file compilati) NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

**Controlli**: un'implementazione corretta dell'algoritmo di Kruskal, eseguita sui dati contenuti nel file `italian_dist_graph.csv`, determina una minima foresta ricoprente con 18.640 nodi, 18.637 archi (non orientati) e di peso complessivo di circa 89.939,913 km.

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex4` all'interno del repository, che conterrà i file relativi a questo esercizio.
- La consegna deve consentire di compilare il codice, di eseguire tutti gli unit test e di eseguire l'applicazione da riga di comando, senza l'uso di un ambiente di sviluppo integrato. I comandi necessari, oppure un `Makefile` o uno script che li esegue, devono far parte della consegna.
- Se l'implementazione usa librerie esterne (come JUnit), includere anche i relativi file `.jar` per consentire la corretta compilazione.
- L'applicazione deve ricevere il percorso del file `italian_dist_graph.csv` come argomento da riga di comando; il nome del file non deve essere scritto nel codice.
