# Laboratorio per il corso di Algoritmi e Strutture Dati: specifica per studenti e studentesse di anni precedenti il 2024/2025 (esercizi in C e in Java)

Questo documento descrive la variante del progetto di laboratorio con due esercizi in C e due esercizi in Java, che possono seguire **solo gli studenti e studentesse iscritti/e al secondo anno in un anno accademico fino al 2023/2024.**
Per tutto ciò che non è indicato qui vale quanto riportato nel documento [README.md](README.md).

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

## Esercizio 3 - PriorityQueue

### Linguaggio richiesto: Java

### Testo

Si implementi la struttura dati *coda con priorità (PriorityQueue)*.

La struttura dati deve gestire tipi generici e consentire un numero qualunque e non noto a priori di elementi, implementando la seguente interfaccia (con requisiti minimi di complessità):

```
public interface AbstractQueue<E> {
  public boolean empty(); // controlla se la coda è vuota -- O(1)
  public boolean push(E e); // aggiunge un elemento alla coda -- O(logN)
  public boolean contains(E e); // controlla se un elemento è in coda -- O(1)
  public E top(); // accede all'elemento in cima alla coda -- O(1)
  public void pop(); // rimuove l'elemento in cima alla coda -- O(logN)
  public boolean remove(E e); // rimuove un elemento se presente in coda -- O(logN)
};
```

*Suggerimento*: per implementare i metodi `contains` e `remove` potrebbe essere necessario usare una struttura dati di appoggio oltre allo heap (è ammesso usare strutture dati dalla libreria standard di Java se necessario).

La classe concreta `PriorityQueue<E>` che implementa l'interfaccia dovrebbe avere almeno un costruttore che crea una coda vuota e prende come argomento un `Comparator<E>` da usare per confrontare gli elementi:

```
PriorityQueue(Comparator<E> comparator)
```

_Nota_: `Comparator` è un'[interfaccia base](https://docs.oracle.com/en/java/javase/20/docs/api/java.base/java/util/Comparator.html) di Java.

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex3-4` all'interno del repository, che conterrà tutte le classi relative a questo esercizio e al seguente, compresi i file di progetto relativi all'IDE Java che avete utilizzato.
- Includete nella consegna anche un `Makefile` che con il comando `make all` produca i file `.class` eseguibili relativi a tutte le classi implementate. Includete anche tutti i file `.jar` (come junit) necessari alla compilazione.

## Esercizio 4 - Grafi sparsi e foreste ricoprenti minime

### Linguaggio richiesto: Java

### Testo

Si implementi una libreria che realizza la struttura dati *Grafo* in modo che sia ottimale per dati sparsi
(**attenzione**: le scelte implementative che farete dovranno essere giustificate in relazione alle nozioni presentate
durante le lezioni in aula).

L'implementazione deve essere generica sia per quanto riguarda il tipo dei nodi, sia per quanto riguarda le etichette
degli archi, implementando la seguente interfaccia (con requisiti minimi di complessità; dove _N_ può indicare il numero di nodi o il numero di archi, a seconda del contesto):

```
public interface AbstractGraph<V,L> {
  public boolean isDirected(); // dice se il grafo è diretto o meno -- O(1)
  public boolean isLabelled(); // dice se il grafo è etichettato o meno -- O(1)
  public boolean addNode(V a); // aggiunge un nodo -- O(1)
  public boolean addEdge(V a, V b, L l); // aggiunge un arco dati estremi ed etichetta -- O(1) (*)
  public boolean containsNode(V a); // controlla se un nodo è nel grafo -- O(1)
  public boolean containsEdge(V a, V b); // controlla se un arco è nel grafo -- O(1) (*)
  public boolean removeNode(V a); // rimuove un nodo dal grafo -- O(N)
  public boolean removeEdge(V a, V b); // rimuove un arco dal grafo -- O(1) (*)
  public int numNodes(); // numero di nodi -- O(1)
  public int numEdges(); // numero di archi -- O(N)
  public Collection<V> getNodes(); // recupero dei nodi del grafo -- O(N)
  public Collection<? extends AbstractEdge<V,L>> getEdges(); // recupero degli archi del grafo -- O(N)
  public Collection<V> getNeighbours(V a); // recupero dei nodi adiacenti ad un dato nodo -- O(1) (*)
  public L getLabel(V a, V b); // recupero dell'etichetta di un arco -- O(1) (*)
};
```

_(*)_ quando il grafo è veramente sparso, assumendo che l'operazione venga effettuata su un nodo la cui lista di adiacenza ha una lunghezza in O(1).

_Nota_: `AbstractCollection` è un'[interfaccia base](https://docs.oracle.com/en/java/javase/20/docs/api/java.base/java/util/AbstractCollection.html) di Java.

L'interfaccia `AbstractGraph` si basa sulla seguente interfaccia per la rappresentazione di un arco:

```
public interface AbstractEdge<V,L> {
  public V getStart(); // il nodo di partenza dell'arco
  public V getEnd(); // il nodo di arrivo dell'arco
  public L getLabel(); // l'etichetta dell'arco
};
```

La classe concreta `Graph<V,L>` che implementa l'interfaccia `AbstractGraph` dovrebbe avere almeno un costruttore che crea un grafo vuoto in complessità O(1) e prende come argomenti due valori booleani per impostare se il grafo è da considerarsi diretto o meno, e se è da considerarsi etichettato o meno:

```
Graph(boolean directed, boolean labelled)
```

A seconda del valore di questi due parametri, cambierà il comportamento dei metodi per gestire gli archi per tutte le operazioni successive.

*Suggerimento*:  un grafo non diretto può essere rappresentato usando un'implementazione per grafi diretti modificata
per garantire che, per ogni arco *(a,b)* etichettato *w*, presente nel grafo, sia presente nel grafo anche l'arco *(b,a)*
etichettato *w*. Ovviamente, il grafo dovrà mantenere l'informazione che specifica se esso è un grafo diretto o non diretto.
Similmente, un grafo non etichettato può essere rappresentato usando l'implementazione per grafi etichettati modificata per garantire
che le etichette siano sempre `null` (che invece non devono mai essere `null` per i grafi etichettati).

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso della libreria che implementa la struttura dati Grafo

Si implementi l'algoritmo di Prim per la determinazione della minima foresta ricoprente di un grafo, secondo il seguente template:

```
public class Prim {
  public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
    // calcola la minima foresta ricoprente con l'algoritmo di Prim
    // restituisce la collezione degli archi che formano la foresta
  }
  public static void main(String[] args) {
    // leggi i dati CSV del grafo dal percorso in args[1]
    // calcola la minima foresta ricoprente con minimumSpanningForest
    // scrivi su standard output solo la descrizione della foresta calcolata come CSV con formato analogo a quello in input
    // su standard error si possono scrivere ulteriori informazioni, come il numero di nodi e archi nella foresta calcolata,
    // o il peso totale della foresta
  }
}
```

L'implementazione dell'algoritmo di Prim dovrà utilizzare la struttura dati *PriorityQueue* implementata nell'esercizio precedente e la struttura dati grafo appena implementata.
La struttura dati e l'algoritmo di Prim dovranno poi essere utilizzati con i dati contenuti nel file `italian_dist_graph.csv`, che potete recuperare all'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY](https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY)

Tale file contiene le distanze in metri tra varie località italiane e una frazione delle località a loro più vicine. Il formato è un CSV standard: i campi sono separati da virgole; i record sono separati dal carattere di fine riga (`\n`).

Ogni record contiene i seguenti dati:

- `place1`: (tipo stringa) nome della località "sorgente" (la stringa può contenere spazi ma non può contenere virgole);
- `place2`: (tipo stringa) nome della località "destinazione" (la stringa può contenere spazi ma non può contenere virgole);
- `distance`: (tipo float) distanza in metri tra le due località.

**Note:**

- Nel caso in cui il grafo sia costituito da una sola componente connessa, l'algoritmo restituirà un albero. Nel caso in cui, invece, vi siano più componenti connesse, l'algoritmo restituirà una foresta costituita dai minimi alberi ricoprenti di ciascuna componente connessa.
- Potete intrepretare le informazioni presenti nelle righe del file come archi **non diretti** (per cui probabilmente vorrete inserire nel vostro grafo sia l'arco di andata che quello di ritorno a fronte di ogni riga letta).
- Il file è stato creato a partire da un dataset poco accurato. I dati riportati contengono inesattezze e imprecisioni.
- Un'implementazione corretta dell'algoritmo di Prim, eseguita sui dati contenuti nel file `italian_dist_graph.csv`, dovrebbe determinare una minima foresta ricoprente con 18.640 nodi, 18.637 archi (non orientati) e di peso complessivo di circa 89.939,913 Km.

**Si ricorda che il file `italian_dist_graph.csv` (e i file compilati) NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex3-4` all'interno del repository, che conterrà tutte le classi relative a questo esercizio e al precedente, compresi i file di progetto relativi all'IDE Java che avete utilizzato.
- Includete nella consegna anche un `Makefile` che con il comando `make all` produca i file `.class` eseguibili relativi a tutte le classi implementate. Includete anche tutti i file `.jar` (come junit) necessari alla compilazione.
