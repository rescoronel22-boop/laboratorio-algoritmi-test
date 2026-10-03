# Unit Testing

I test automatici sono "oggetti" software che vengono scritti con l'obiettivo
di verificare che una porzione di una applicazione sia corretta (secondo qualche
criterio di corretteza definito nel test stesso). Quando gli oggetti testati
sono "piccoli" e autocontenuti, essi vengono chiamati "unit" e il test automatico
di essi è detto "unit testing". Cosa sia una unit non è definito con precisione,
in alcuni contesti può un piccolo modulo, ma
più spesso sono singole funzioni, procedure, ecc.

I test automatici in genere predispongono un input, invocano la unit e
verificano che l'output (o l'eventuale side-effect) sia corretto. La verifica
è fatta per mezzo di asserzioni che indicano quale sia il risultato atteso,
quando tali asserzioni falliscono viene interrotto il test e restituito un
messaggio d'errore appropriato.

I vantaggi dello unit testing sono molteplici:

- *debugging*: il testing indipendente di piccole unità di
  codice permette di isolare la porzione di codice in cui è presente il bug,
  semplificando così la soluzione del problema;

- *qualità del codice*: l'avere una test suite che automaticamente verifica la
  correttezza delle unit crea la serenità necessaria perché il codice venga
  mantenuto e ripulito con la dovuta frequenza. Supponiamo ad esempio di avere
  una funzione mal scritta, ma critica (ad esempio un suo problema potrebbe
  portare a danni per migliaia di euro). Sappiamo che la funzione è corretta (ha
  sempre funzionato perfettamente), ma è lunga, scritta male, e contiente tante
  parti che sarebbe bene astrarre in modo che possano essere riutilizzate dal
  resto dell'applicazione. Senza una suite di test affidabile difficilmente si
  procederà agli interventi necessari a risolvere la situazione. L'avere una
  suite di test non necessariamente garantisce di non introdurre bug, ne riduce
  però drasticamente la probabilità.

  Inoltre scrivere test è più semplice quando le unit sono piccole e ben
  focalizzate e questo incoraggia un miglior stile di programmazione;

- *documentazione*: i test di unità forniscono anche una (seppur limitata) fonte
  di documentazione per il codice. Essi mostrano come si intende che le unit
  vengano utilizzate e quale sia la relazione attesa tra input e output.

Affinché gli unit test possano essere efficaci è necessario che godano delle
seguenti proprietà:

- i test devono essere focalizzati: uno unit-test deve testare un singolo caso
  d'uso di una singola unit. Un test che prende in considerazione più unit o più
  casi d'uso è meno utile perché eventuali problemi sono più difficilmente
  ricollegabili a una porzione ristretta di codice.

  Esempi di test correttamente focalizzati:
    - test di una procedura di sort su un array vuoto
    - test di una procedura di sort su un array dato
    - test di una procedura di sort su un array con tutti elementi uguali

  Esempi di test non correttamente focalizzati:
    - test di una procedura di sort
    - test del funzionamento di più procedure/funzioni contemporaneamente

  In genere un test poco focalizzato si riconosce perché contiene più asserzioni.
  Prima di scrivere un test di  unità che contenente più asserzioni è bene
  verificare l'opportunità di procedere in questa direzione.

- i test devono essere indipendenti: l'ordine di esecuzione dei test non deve
  influire sul loro risultato.

  L'indipendenza dei test è importante perché in caso contrario un baco potrebbe
  essere nascosto dall'esecuzione di un test precedente. Inoltre il debugging
  dei problemi diventa più complicato perché è necessario prendere in
  considerazione tutto il contesto.

- i test non devono richiedere l'intervento umano: i test devono essere automatici,
  non devono richiedere che un essere umano ispezioni il valore di una variabile
  o ispezioni quanto stampato a video. Un test che passa non deve generare nessun
  output degno di attenzione, un test fallito deve permettere di risalire
  velocemente alla porzione di codice da esaminare.

  Non scrivere pertanto nulla su console durante un test.

Si noti che scrivere i test di unità è diverso dallo scrivere un programma di
prova per il proprio software. Gli unit test sono pensati per essere eseguiti
automaticamente e non richiedere attenzione da parte dell'utente.


## Unit testing in C

Purtroppo nel caso del C non c'è una libreria che possa essere definita
"standard" e in genere usare tali librerie richiede l'installazione di software
aggiuntivo. Date queste difficoltà è ammesso utilizzare un programma ad-hoc per
effettuare il test, a patto che si scrivano le funzioni di test prestando
attenzione ai punti indicati sopra. Chi volesse utilizzare qualche libreria è
libero di farlo, ma sarà sua responsabilità installare e utilizzare
correttamente la libreria. Una possibile libreria (che, tuttavia, non rappresenta
uno standard) è Unity. L'uso di Unity in questo
laboratorio è comunque facoltativo.

Esempio di programma di test in C:

```C
#include <assert.h>
#include <stdlib.h>
#include "my_sorter.h"

void test_sort_empty_array() {
  int a[] = {};
  assert( a == my_sorter(a, 0) );
}

void test_sort_null_array() {
  int* a = NULL;
  assert( NULL == my_sorter(a, 0) );
}

...

int main(int argc, char** argv) {
  test_sort_empty_array();
  test_sort_null_array();
  ...
}

```

Si noti che la funzione ```assert``` usata nell'esempio non è stata pensata per
fare unit testing in C e fornisce solo funzionalità molto limitate in questo
senso. Dati i vincoli e i problemi spiegati sopra, un'implementazione lungo
la linea mostrata sarà comunque considerata pienamente accettabile.

## Unit testing in Java

Questa sezione riguarda i soli esercizi svolti in Java secondo la specifica
descritta nel documento [README-coorti-precedenti.md](README-coorti-precedenti.md).

La libreria di unit testing più usata in ambito Java è JUnit. Nel seguito si fa
riferimento a JUnit 4; l'uso di versioni successive è ammesso.

Un test in JUnit è un metodo marcato con l'annotazione ```@Test```. Tali metodi
possono usare un certo numero di funzioni messe a disposizione dalla libreria
per verificare la correttezza del programma. Ad esempio:

```Java
import org.junit.Test;
import static org.junit.Assert.assertArrayEquals;

public class TestSorting {
  @Test
  public void testSortEmptyArray() {
    MySortingAlgorithm sorter = new MySortingAlgorithm();
    int[] a = {};
    assertArrayEquals( new int[]{}, sorter.sort(a) );
  }

  @Test
  public void testSortNullArray() {
    MySortingAlgorithm sorter = new MySortingAlgorithm();
    int[] a = null;
    assertArrayEquals( null, sorter.sort(a) );
  }
}
```

JUnit crea una nuova istanza della classe di test prima di eseguire ciascun
metodo di test e non garantisce l'ordine di esecuzione dei metodi. Nel caso in
questione ciò non influisce sul risultato. Le cose sarebbero diverse se la
classe di test memorizzasse dati in variabili di classe condivise fra i test.

### Compilazione ed esecuzione

Le librerie di JUnit 4 (`junit` e `hamcrest-core`) si possono scaricare dal sito
di JUnit 4 (https://junit.org/junit4/). Per compilare ed eseguire le classi di
test è necessario aggiungere le due librerie al classpath di Java.

Esempio, con i file `.jar` nella cartella `lib`, i sorgenti nella cartella `src`
e le classi compilate nella cartella `bin`:

```bash
javac -cp "lib/junit-4.13.2.jar:lib/hamcrest-core-1.3.jar" -d bin src/mypackage/*.java
java -cp "bin:lib/junit-4.13.2.jar:lib/hamcrest-core-1.3.jar" org.junit.runner.JUnitCore mypackage.TestSorting
```

L'argomento di `JUnitCore` è il nome della classe che contiene i test,
comprensivo del package.
