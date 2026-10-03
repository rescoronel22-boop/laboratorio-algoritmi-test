# Laboratorio per il corso di Algoritmi e Strutture Dati: regole d'esame, indicazioni generali e suggerimenti, consegne per gli esercizi

# Regole d'esame

## Studenti e studentesse di anni precedenti il 2024/2025

Gli studenti e le studentesse iscritti/e al secondo anno in un anno accademico precedente il 2024/2025 **possono** svolgere tutti gli esercizi di laboratorio interamente in C (come indicato nella presente specifica), oppure svolgere quattro esercizi, i primi due in C e gli ultimi due in Java, come indicato nel documento [README-coorti-precedenti.md](README-coorti-precedenti.md).

## Studenti e studentesse con Algoritmi non di 9 CFU

Gli studenti e le studentesse che hanno nel piano di studi l'insegnamento di Algoritmi con un numero di CFU **differente da 9** sono pregati di contattare il docente al più presto, al fine di concordare un programma d'esame commisurato ai CFU.

## Validità del progetto di laboratorio

Le specifiche per il progetto di laboratorio descritte in questo documento resteranno valide fino all'ultimo appello relativo al corrente anno accademico **(vale a dire, quello della sessione di settembre 2027)** e non oltre! Gli appelli delle sessioni successive a quella dovranno essere sostenuti sulla base delle specifiche che verranno descritte nella prossima edizione del laboratorio di algoritmi.

## Gruppi di laboratorio e turni

Il progetto di laboratorio può essere svolto individualmente o in gruppo (al più 3 persone). **I gruppi di laboratorio possono essere costituiti anche da studenti e studentesse appartenenti a turni diversi**.

In caso di necessità e compatibilmente con i posti disponibili nelle aule, è possibile seguire le lezioni di laboratorio in turni diversi dal proprio, ma **la prova orale deve essere sostenuta con il/la docente del proprio turno**. In caso di insufficienza di posti nelle aule, gli studenti che seguono le lezioni del proprio turno hanno la precedenza. A causa del possibile affollamento delle aule, nelle prime due o tre settimane resta comunque fortemente sconsigliato seguire lezioni di turni diversi dal proprio.

## Modalità d'esame

Come specificato nella descrizione ufficiale dell'insegnamento (https://laurea.informatica.unito.it/do/corsi.pl/Show?_id=iw3r), l'esame di _Algoritmi e Strutture Dati_ consiste in una prova scritta, somministrata mediante la piattaforma Esami, ed in una seguente discussione orale del progetto di laboratorio.

**Per poter sostenere la prova scritta**, tutti i membri di un gruppo di laboratorio devono, entro la data dello scritto che intendono sostenere:
- sottoporre il codice del progetto di laboratorio a tutti i correttori automatici messi a disposizione sulla pagina Moodle del Laboratorio di ASD, **superandone tutti i test.** Un laboratorio il cui codice non dovesse superare qualche test (anche solo uno per un unico esercizio) o che mancasse di qualche esercizio (anche se altri membri del gruppo l'avessero consegnato) non consente di sostenere lo scritto;
- consegnare l'intero progetto di laboratorio (completo e senza la necessità di ulteriori commit dopo la data della prova scritta) mediante GitLab (vedi sotto);
- compilare il questionario su Moodle (in cui indicare la composizione dei gruppi, l'URL del repository GitLab, ...).

**Per poter sostenere la prova orale**, ogni studente/studentessa deve:
- aver ottenuto la sufficienza nella prova scritta;
- essersi iscritto/a all'appello tramite il sistema di Ateneo Esse3;
- essersi prenotato/a (scegliendo data e ora tra quelle proposte) tramite un calendario messo a disposizione dal/la docente del proprio turno in un momento successivo alla pubblicazione degli esiti della prova scritta. [Si tenga presente che, per ogni appello, le prove orali possono iniziare soltanto dopo la pubblicazione degli esiti della prova scritta, pertanto **è possibile (e probabile) che esse non si tengano nella data e ora ufficiale specificate sul sistema di Ateneo Esse3 e, inoltre, che esse proseguano per più giornate**].

La prova orale deve essere sostenuta **nella medesima sessione della prova scritta superata** (si ricorda che le sessioni sono gennaio-febbraio 2027, giugno-luglio 2027, settembre 2027). Si noti che, per quelle sessioni per cui sono previsti due appelli, esisteranno due possibilità per sostenere la prova orale (primo o secondo appello della sessione); per le sessioni in cui è previsto un solo appello, la prova orale deve essere effettuata necessariamente in quell'appello. Nel caso in cui l'orale non venga superato entro i termini della sessione, lo scritto dovrà essere ripetuto.

In una sessione con due appelli, nel caso in cui la prova orale risulti insufficiente al primo appello, la prova scritta dovrà essere ripetuta, anche se si intende risostenere la prova orale nel secondo appello.

La prova orale è individuale. Studentesse/studenti appartenenti a uno stesso gruppo di laboratorio possono sostenere la prova orale in appelli diversi. Tuttavia, se membri di uno stesso gruppo sostengono la prova orale in uno stesso appello, è richiesto che essi si prenotino in fasce orarie consecutive.

Al progetto di laboratorio non sarà assegnato preventivamente un voto, ma esso costituirà la base per una discussione orale. In tale discussione la/il candidata/o dovrà dimostrare di conoscere sia gli aspetti teorici della materia, sia il codice consegnato.

Durante la prova orale, sarà facoltà del docente chiedere di eseguire gli algoritmi implementati su dati ulteriori, forniti dal docente stesso. Ugualmente, sarà facoltà del docente chiedere cambiamenti nel codice durante l'esame, per esempio per l'inclusione di ulteriori unit test o per la correzione di eventuali piccoli problemi di implementazione individuati durante la correzione.

Il **voto finale** sarà la media pesata dei voti ottenuti nelle due prove scritta ed orale [in base ai crediti associati alle parti di teoria (6 CFU) e di laboratorio (3 CFU), nella media lo scritto peserà 6 e l'orale 3], valutate in 30+1 esimi, essendo comunque necessario il raggiungimento della sufficienza in entrambe le prove.

# Indicazioni generali e suggerimenti

## Uso di GitLab

Durante la scrittura del codice è richiesto di usare in modo appropriato il sistema di versioning GitLab. Questa richiesta implica quanto segue:

- Il progetto di laboratorio va inizializzato "clonando" il repository del laboratorio come descritto nel file `Git.md`.
- Come è prassi nei moderni ambienti di sviluppo, è richiesto di effettuare commit frequenti, con un nome significativo. L'ideale è un commit per ogni blocco di lavoro terminato (es. creazione e test di una nuova funzione, soluzione di un baco, creazione di una nuova interfaccia, ...). Meglio ancora se si usano branch e merge per gestire sessioni di lavoro più ampie.
- Ogni membro del gruppo dovrebbe effettuare il commit delle modifiche che lo hanno visto come principale sviluppatore, partecipando quindi attivamente ai commit del repository in misura più o meno bilanciata.
- Al termine del lavoro si dovrà consegnare l'intero repository (dandone accesso al docente di riferimento del turno).

Il file `Git.md` contiene un esempio di come usare Git per lo sviluppo degli esercizi proposti per questo laboratorio.

---

**Nota importante**: Su GitLab dovrà essere caricato solamente il codice sorgente, in particolare nessun file dati dovrà essere oggetto di commit!

---

## Linguaggio in cui sviluppare il laboratorio

L'intera implementazione del laboratorio deve essere realizzata nel linguaggio C.

Come indicato sotto, alcuni esercizi chiedono di implementare **codice generico**. Con "codice generico" si intende codice che deve poter essere eseguito con tipi di dato non noti a tempo di compilazione.

**Suggerimento per la realizzazione di codice generico in C**: Nel caso del C, è necessario capire come meglio approssimare l'idea di codice generico utilizzando quanto permesso dal linguaggio. Un approccio comune è far sì che le funzioni e le procedure presenti nel codice prendano in input puntatori a `void` e utilizzino qualche funzione fornita dall'utente per accedere alle componenti necessarie (uso di puntatori a funzione).

## Uso di librerie esterne e/o native del linguaggio scelto

È vietato l'uso di strutture dati native del linguaggio scelto o offerte da librerie esterne, quando la loro realizzazione è richiesta da uno degli esercizi proposti.

È, invece, possibile l'uso di strutture dati native del linguaggio o offerte da librerie esterne, se la loro realizzazione non è richiesta da uno degli esercizi proposti.

**Esempio:** l'uso di una libreria C che implementa array dinamici è consentito, solo se nessun esercizio chiede la realizzazione di un array dinamico.

## Relazione sugli esercizi

La relazione, per quegli esercizi che la richiedono, deve essere inserita in formato _Markdown_ nel file README.md del progetto, divenendo così parte integrante della documentazione.

## Unit Testing

Come indicato esplicitamente nei testi degli esercizi, il progetto di laboratorio comprende obbligatoriamente la definizione di opportune suite di unit test.

È obbligatorio implementare unit test completi per tutte le funzioni di libreria sviluppate, escluse le funzioni dedicate all'interazione con l'utente e I/O su file, ma incluse le funzioni di utilità che si decidesse di aggiungere a quelle esplicitamente richieste dall'esercizio. Gli unit test rappresentano un'area in cui l'AI generativa può essere particolarmente utile per accelerare lo sviluppo e garantire una copertura esaustiva del codice.

Tuttavia, si rammenta che il focus del laboratorio rimane l'implementazione di strutture dati e algoritmi. Gli studenti dovranno dimostrare di aver compreso il senso degli unit test e di saper realizzare suite di test che coprano i casi più comuni e i casi limite.

## Qualità dell'implementazione

È parte del mandato degli esercizi la realizzazione di codice di buona qualità.

Per "buona qualità" intendiamo codice ben organizzato, ben modularizzato, ben commentato e ben testato.

**Alcuni suggerimenti:**

- **Importante**: Gli esercizi richiedono (fra le altre cose) di sviluppare codice generico. Nello sviluppare questa parte, si deve assumere di stare sviluppando una libreria generica intesa come fondamento di futuri programmi. Non è pertanto lecito fare assunzioni semplificative; in generale, l'implementazione della libreria generica deve restare separata e non deve essere influenzata in alcun modo dagli usi di essa eventualmente richiesti negli esercizi (ad esempio, se un esercizio dovesse richiedere l'implementazione della struttura dati grafo e quello stesso o un altro esercizio dovesse richiedere l'implementazione, a partire da tale struttura dati, di un algoritmo per il calcolo delle componenti connesse di un grafo, l'implementazione della struttura dati dovrebbe essere separata dall'algoritmo per il calcolo delle componenti connesse e *non* dovrebbe contenere elementi – variabili, procedure, funzioni, definizioni di tipo, ecc. – eventualmente utili a tale algoritmo, ma non essenziali alla struttura dati; analogamente, se un esercizio dovesse richiedere di operare su grafi con nodi di tipo stringa, l'implementazione della struttura dati grafo dovrebbe restare generica e non potrebbe quindi assumere per i nodi il solo tipo stringa).
- verificare che il codice sia suddiviso correttamente in moduli distinti;
- aggiungere un commento, prima di una definizione, che spieghi il funzionamento dell'oggetto definito, meglio se in formato [doxygen](https://www.doxygen.nl). Evitare quando possibile di commentare direttamente il codice interno alle funzioni/procedure implementate (se il codice è ben scritto, tali commenti in genere non servono);
- la lunghezza di una funzione/procedura è in genere un campanello di allarme: se essa cresce troppo, probabilmente è necessario rifattorizzare il codice spezzando la funzione in più parti. In linea di massima si può consigliare di intervenire quando la funzione cresce sopra le 30 righe (considerando anche commenti e spazi bianchi);
- sono accettabili commenti in italiano, sebbene siano preferibili in inglese;
- tutti i nomi (es., nomi di variabili, di funzioni, di tipi, ecc.) *devono* essere significativi e in inglese;
- il codice deve essere correttamente indentato; impostare l'indentazione a 2 o 4 caratteri e impostare l'editor in modo che inserisca "soft tabs" (cioè, deve inserire il numero corretto di spazi invece che un carattere di tabulazione);
- per dare i nomi agli identificatori, seguire le convenzioni in uso per il linguaggio C:
  - macro e costanti sono tutti in maiuscolo e in formato snake case (es. THE\_MACRO, THE\_CONSTANT); i nomi di tipo (e.g. struct, typedefs, enums, ...) iniziano con una lettera maiuscola e proseguono in camel case (e.g., TheType, TheStruct); i nomi di funzione iniziano con una lettera minuscola e proseguono in snake case (e.g., the\_function());
- i file vanno salvati in formato UTF-8.

# Consegne per gli esercizi

Come detto sopra, in sede di discussione d'esame, sarà facoltà del docente chiedere di eseguire gli algoritmi implementati su dati forniti dal docente stesso. Nel caso questi dati siano memorizzati su file, questi saranno della medesima struttura dei dataset forniti e descritti nel testo dell'esercizio. I codici sviluppati dovranno consentire un rapido e semplice adattamento agli input forniti: ad esempio, **una buona implementazione consentirà di inserire in input il nome del file su cui eseguire il test**, mentre una peggiore richiederà di modificare il codice sorgente e una successiva compilazione a fronte della sola modifica del nome del file contenente il dataset.

**Le consegne che non rispettano la complessità computazionale richiesta saranno considerate completamente invalide.**

## Esercizio 1 - Libreria per algoritmo di ordinamento ibrido QuickSort-SelectionSort

Implementare una libreria che offra un algoritmo di ordinamento **ibrido** che combini QuickSort e SelectionSort, in base alla dimensione dell'array da ordinare. L'algoritmo deve funzionare nel seguente modo:

- Per array di dimensione maggiore o uguale a una soglia `k`, utilizzare QuickSort.
- Per array di dimensione minore di `k`, utilizzare SelectionSort.

La ratio di una tale combinazione risiede nell'ipotesi che SelectionSort, pur avendo complessità O(n²), possa risultare più efficiente di QuickSort su array molto piccoli a causa del minor overhead nelle operazioni elementari.

### Ulteriori specifiche per l'implementazione:

1. La libreria deve essere generica, nel senso che essa deve supportare l'ordinamento di array di un numero qualsiasi di elementi di tipo non noto a priori, tramite una funzione di comparazione.
2. **QuickSort**: La strategia di partizionamento e la politica di scelta del pivot hanno un impatto significativo sulle prestazioni dell'algoritmo. La loro scelta è lasciata agli studenti, che dovranno saperla motivare.
3. **SelectionSort**: implementare la versione classica O(n²).
4. **Algoritmo ibrido**: L'algoritmo ibrido deve rispettare la soglia `k` in ogni fase della propria esecuzione e passare automaticamente da un algoritmo base all'altro durante la ricorsione.

La funzionalità offerta deve rispettare la seguente definizione:

```c
void hybridsort(void *base,
                size_t nitems,
                size_t size,
                size_t k,
                int (*compar)(const void *, const void *));
```

Interpretare i parametri della procedura `hybridsort` considerando la richiesta di realizzare una libreria generica.

### Unit Testing

Implementare gli unit test per la libreria secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

Gli unit test devono coprire, in particolare:
- Correttezza dell'ordinamento per tutti i tipi di dato;
- Correttezza di eventuali funzioni ausiliarie sviluppate;
- Comportamento con array vuoti e di dimensione piccola;
- Diversi valori della soglia `k`;
- Casi limite, ad esempio, array già ordinati, ordinati inversamente, con elementi duplicati.

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex1` all'interno del repository;
- La consegna deve obbligatoriamente contenere un `Makefile` che con il comando `make all` produca all'interno di `ex1/bin` un file eseguibile chiamato `test_ex1`;
- Se l'implementazione usa librerie esterne (come Unity per i test), includere anche queste per consentire la corretta compilazione;
- L'eseguibile `test_ex1` non deve richiedere parametri e deve eseguire tutti gli unit test automatizzati.

## Esercizio 2 - Libreria per Tavole hash (con concatenamento)

Implementare una libreria generica che realizza la struttura dati *tavola hash (con concatenamento)* in grado di ospitare un insieme di coppie {<chiave_1,valore_1>,...,<chiave_n,valore_n>}, senza chiavi ripetute.

### Ulteriori specifiche per l'implementazione:

1. La libreria deve essere generica, nel senso che deve consentire tavole hash con un numero qualsiasi di coppie <chiave,valore>, in cui i tipi di chiavi e valori non sono noti a priori (si tenga presente che tutte le chiavi devono avere uno stesso tipo, tutti i valori devono avere uno stesso tipo, ma chiavi e valori possono avere tipi fra loro differenti).

La struttura dati deve offrire almeno le seguenti funzionalità (ricavare il significato delle varie funzioni e procedure e dei loro parametri a partire dai loro prototipi e da quanto studiato nella parte di teoria del corso), per le quali è richiesta un'implementazione che rispetti le complessità computazionali tipiche di questo tipo di struttura dati:

```c
HashTable* hash_table_create(int (*f1)(const void*,const void*), unsigned long (*f2)(const void*));
void hash_table_put(HashTable*, const void*, const void*);
void* hash_table_get(const HashTable*, const void*);
int hash_table_contains_key(const HashTable*, const void*);
int hash_table_remove(HashTable*, const void*);
int hash_table_size(const HashTable*);
void** hash_table_keyset(const HashTable*);
void hash_table_free(HashTable*);
```

### Unit Testing

Implementare gli unit test per la libreria secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex2` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile`. Questo file con il comando `make all` deve produrre all'interno di `ex2/bin` un file eseguibile chiamato `test_ex2`.
- Se l'implementazione usa librerie esterne (come Unity), includere anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex2` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.

## Esercizio 3 - Libreria Union-Find-Set per la gestione di insiemi dinamici disgiunti

Implementare una libreria generica che realizza la struttura dati *Union-Find-Set* per la gestione di insiemi dinamici disgiunti.

### Ulteriori specifiche per l'implementazione:

1. La libreria deve essere generica, nel senso che essa deve supportare la gestione di un numero qualsiasi di insiemi disgiunti, ciascuno con un numero qualsiasi di elementi di tipo non noto a priori;
2. L'implementazione deve rappresentare la collezione di insiemi come una foresta di insiemi disgiunti;
3. L'implementazione deve adottare le due euristiche note come *unione per rango* e *compressione del cammino*, viste nella parte di teoria del corso;
4. Le eventuali tavole hash usate nell'implementazione devono essere realizzate con la libreria implementata nell'Esercizio 2;
5. L'implementazione deve essere computazionalmente efficiente (in particolare, le scelte implementative non devono vanificare l'apporto all'efficienza delle due euristiche citate sopra).

La struttura dati deve offrire almeno le seguenti funzionalità (ricavare il significato delle varie funzioni, procedure e dei loro parametri a partire dai loro prototipi e da quanto studiato nella parte di teoria del corso):

```c
UnionFindSet* ufs_create(int (*f1)(const void*,const void*), unsigned long (*f2)(const void*));
int ufs_make_set(UnionFindSet*,const void*);
void* ufs_find_set(const UnionFindSet*,const void*);
int ufs_union(UnionFindSet*,const void*,const void*);
void ufs_free(UnionFindSet*);
```

### Unit Testing

Implementare gli unit test per la libreria secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex3` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile`. Questo file con il comando `make all` deve produrre all'interno di `ex3/bin` un file eseguibile chiamato `test_ex3`.
- Se l'implementazione usa librerie esterne (come Unity), includere anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex3` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.

## Esercizio 4 - Libreria per Grafi sparsi e algoritmo di Kruskal

Implementare una libreria generica che realizza la struttura dati *Grafo* in modo che sia ottimale per dati sparsi
(**attenzione**: le scelte implementative che farete dovranno essere giustificate in relazione alle nozioni presentate
durante le lezioni in aula).

### Ulteriori specifiche per l'implementazione:

1. L'implementazione deve essere generica, nel senso che essa deve consentire la gestione di grafi (eventualmente etichettati) con un numero qualsiasi di nodi e di archi, in cui i tipi dei nodi e delle etichette degli archi non sono noti a priori;
2. L'implementazione deve sfruttare la Tavola Hash implementata nell'Esercizio 2.

La libreria deve offrire le funzionalità dichiarate nel seguente header file (con requisiti minimi di complessità; dove _N_ può indicare il numero di nodi o il numero di archi, a seconda del contesto):

### graph.h

#### Strutture Dati

```c
typedef struct graph *Graph;

typedef struct edge {
    void* source;   // nodo d'origine
    void* dest;     // nodo di destinazione
    void* label;    // etichetta dell'arco
} Edge;
```
---
#### Creazione e Configurazione

```c
Graph graph_create(int labelled,
                  int directed,
                  int (*compare)(const void*, const void*),
                  unsigned long (*hash)(const void*));
```
Crea un grafo vuoto, etichettato se `labelled == 1` e diretto se `directed == 1`. Le funzioni `compare` e `hash` sono necessarie per la costruzione della tavola hash che deve essere usata dalla libreria.  
**Complessità**: O(1)

```c
int graph_is_directed(const Graph gr);
```
Dice se il grafo è diretto o meno.  
**Complessità**: O(1)

```c
int graph_is_labelled(const Graph gr);
```
Dice se il grafo è etichettato o meno.  
**Complessità**: O(1)

---
#### Gestione Nodi

```c
int graph_add_node(Graph gr, const void* node);
```
Aggiunge un nodo al grafo.  
**Complessità**: O(1)

```c
int graph_contains_node(const Graph gr, const void* node);
```
Controlla se un nodo è presente nel grafo.  
**Complessità**: O(1)

```c
int graph_remove_node(Graph gr, const void* node);
```
Rimuove un nodo dal grafo.  
**Complessità**: O(N)

```c
int graph_num_nodes(const Graph gr);
```
Restituisce il numero di nodi nel grafo.  
**Complessità**: O(1)

```c
void** graph_get_nodes(const Graph gr);
```
Recupera tutti i nodi del grafo.  
**Complessità**: O(N)

---
#### Gestione Archi

```c
int graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label);
```
Aggiunge un arco dati gli estremi e l'etichetta.  
**Complessità**: O(1) (*)

```c
int graph_contains_edge(const Graph gr, const void* node1, const void* node2);
```
Controlla se un arco è presente nel grafo.  
**Complessità**: O(1) (*)

```c
int graph_remove_edge(Graph gr, const void* node1, const void* node2);
```
Rimuove un arco dal grafo.  
**Complessità**: O(1) (*)

```c
int graph_num_edges(const Graph gr);
```
Restituisce il numero di archi nel grafo.  
**Complessità**: O(N)

```c
Edge** graph_get_edges(const Graph gr);
```
Recupera tutti gli archi del grafo.  
**Complessità**: O(N)

```c
void* graph_get_label(const Graph gr, const void* node1, const void* node2);
```
Recupera l'etichetta di un arco.  
**Complessità**: O(1) (*)

---
#### Adiacenza

```c
void** graph_get_neighbours(const Graph gr, const void* node);
```
Recupera i nodi adiacenti a un dato nodo.  
**Complessità**: O(1) (*)

```c
int graph_num_neighbours(const Graph gr, const void* node);
```
Recupera il numero di nodi adiacenti a un dato nodo.  
**Complessità**: O(1)

---
#### Distruzione

```c
void graph_free(Graph gr);
```
Libera la memoria allocata per il grafo.

---

**Nota**: Le complessità contrassegnate con (*) assumono un'implementazione efficiente della tavola hash sottostante, e quando il grafo è veramente sparso, assumendo che l'operazione venga effettuata su un nodo la cui lista di adiacenza ha una lunghezza in O(1).

La struttura ```struct graph``` deve essere decisa prendendo in considerazione la richiesta di usare la Tavola Hash dell'Esercizio 2.

*Suggerimento*: un grafo non diretto può essere rappresentato usando un'implementazione per grafi diretti modificata
per garantire che, per ogni arco *(a,b)* etichettato *w*, presente nel grafo, sia presente nel grafo anche l'arco *(b,a)*
etichettato *w*. Ovviamente, il grafo dovrà mantenere l'informazione che specifica se esso è un grafo diretto o non diretto.
Similmente, un grafo non etichettato può essere rappresentato usando l'implementazione per grafi etichettati modificata per garantire
che le etichette siano sempre `NULL` (che invece non devono mai essere `NULL` per i grafi etichettati).

### Unit Testing

Implementare gli unit test per la libreria secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso della libreria che implementa la struttura dati Grafo

Si implementi l'*algoritmo di Kruskal* per il calcolo di una minima foresta ricoprente di un grafo non diretto e pesato (non necessariamente connesso), secondo il seguente prototipo di funzione:

```c
Graph kruskal(const Graph gr,
              int (*compare)(const void*, const void*),
              unsigned long (*hash)(const void*));
```

#### Ulteriori specifiche per l'implementazione:

1. L'algoritmo deve sfruttare la struttura dati Union-Find-Set implementata nell'Esercizio 3;
2. Come specificato dal prototipo, l'algoritmo deve restituire un tipo Graph, cioè il tipo della struttura dati implementata nella prima parte di questo esercizio (si ricordi che ogni foresta è un grafo).

#### Unit Testing

Implementare gli unit test per l'algoritmo secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex4` all'interno del repository, che conterrà i file relativi a questo esercizio.
- Includere nella consegna anche un `Makefile` che con il comando `make all` deve produrre all'interno di `ex4/bin` due file eseguibili chiamati `test_graph_ex4` e `test_kruskal_ex4`.
- Se l'implementazione usa librerie esterne (come Unity), includere anche queste per consentire la corretta compilazione.
- Gli eseguibili `test_graph_ex4` e `test_kruskal_ex4` non devono richiedere nessun parametro e devono eseguire tutti gli unit test automatizzati prodotti.

## Esercizio 5 - Pianificatore di percorsi tra località italiane

**Testo provvisorio**: la specifica di questo esercizio sarà aggiornata.
