/*Il programma simula il gioco del quadrato magico. Un quadrato magico si ottiene quando la somma
  di ogni riga, ogni colonna e ogni diagonale è sempre lo stesso numero.
  Il programma, date le dimensioni di un quadrato composto da numeri interi,
  verifica se la matrice rappresenta un quadrato magico, calcolando la percentuale di successo.*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void quadratoMagico(int*, int, int, int);
void fusione(int[], int, int[], int, int[]);
void trova_nUguali(int[], int, int*, int*);




int main()
{
    int i,n,m,n_col=100,cont=3;

    int a[100][100];

    for(i=0;i<3;i++){
        printf("Inserire il numero di righe\n");
        scanf("%d",&n);
        printf("\nInserire il numero di colonne\n");
        scanf("%d",&m);
        printf("\n");

        if(n != 1 && m != 1)                                /*Questo if esegue un controllo per verificare se l'utente immette con num. di righe (n) o di colonne (m) il valore 1.*/
            quadratoMagico(&a[0][0],n,m,n_col);             /*Se viene immesso il valore 1 bisogna inserire nuovamente il valore di  'n' e 'm'.*/
                                                            /*Questo viene fatto perché con 1 sola riga o colonna non si ha un quadrato.*/
        else if(cont == 0){
            printf("Fine tentativi");                       /*Se il numero di cicli del for è superiore a 'cont', quando cont arrivava a 0,*/
            break;}                                         /*per interrompere e evitare che il ciclo for continui fino al termine, viene usato il comando break.*/

        else{                                               /*In questo modo vengono sempre eseguiti 3 cicli (i<3) dove vengono generati dei quadrati magici.*/
            i=i-1;                                          /*Invece se inserisco 1 per 'n' o 'm' e cont arriva ==0 il break fa terminare l'eseczuione del ciclo.*/
            cont--;                                         /*In questo modo cont viene diminuito solo quando viene inserito un 1 come numero di riga 'n' o di colonna 'm'*/

            printf("\nReinserire grazie, numero di tentativi rimasti %d\n\n",cont);}
    }

    return 0;
}










/*La procedura fusione riceve in input due array di tipo intero con la loro dimensione,
  e restituisce in output un terzo array contenente i valori presenti nel primo e nel secondo array.*/


void fusione(int a[], int n_a, int b[], int n_b, int c[])
{
    int i_a=0, i_b=0, i_c=0;
    while(i_a < n_a && i_b < n_b){          /*Controllo per verificare se uno o entrambi gli array sono vuoti oppure no.*/
        if(a[i_a] < b[i_b]){                /*Se l'elemento dell'array 'a' (alla posizione i_a) è < dell'elemento dell'array 'b' (alla posizione i_b),*/
            c[i_c] = a[i_a++];              /*allora questo elemento sarà assegnarto al array 'c' alla posizione i_c.*/
        }                                   /*Successivamente l'indice dell'array 'a' viene incrementato per puntare al prossimo elemento.*/
        else{                               /*Se l'elemento dell'array 'a' NON è < dell'elemento dell'array 'b',*/
            c[i_c] = b[i_b++];              /*allora l'elemento dell'array 'b' sarà assegnarto al array 'c'.*/
        }                                   /*Successivamente l'indice dell'array 'b' viene incrementato per puntare al prossimo elemento.*/
        i_c++;                              /*Anche l'indice dell'array 'c' viene incrementato per puntare alla prossima posizione dove inserire il prossimo elemento.*/
    }
    while(i_a < n_a){                       /*Controllo per verificare sen nell'array 'a' ci sono ancora elementi.*/
        c[i_c++] = a[i_a++];                /*Se ci sono ancora elementi, vuol dire che invece nell'array 'b' NON ci sono più elementi,*/
    }                                       /*quindi i restanti elementi dell'array 'a' verranno assegnati all'array 'c'.*/
    while(i_b < n_b){                       /*Invece se ci sono ancora elementi nell'array 'b', vuol dire che nell'array 'a' non ci sono più elementi,*/
        c[i_c++] = b[i_b++];                /*quindi i restanti elementi dell'array 'b' verranno assegnati all'array 'c'.*/
    }
}




/*La procedura trova_nUguali riceve in input un'array 'a' con la sua dimensione 'n', e restituisce in output
  il numero che viene ripetuto maggiormente all'interno dell'array (numRipetuto) e quante volte questo numero si ripete (ripetiziioniMax).*/


void trova_nUguali(int a[], int n, int*ripetizioniMax, int*numRipetuto)
{
    *ripetizioniMax=0;                      /*Conterrà il numero di ripetizioni massime di un valore all'interno dell'array.*/
    *numRipetuto=0;                         /*Conterrà il valore che si ripete maggiormente all'interno dell'array.*/
    int i,j,volte;

    for(i=0;i<n;i++){
        volte=0;                            /*Quando termina il ciclo for interno, viene incrementato la 'i' del ciclo for esterno e
                                              viene resettato volte=0 per poter contare i numeri uguali trovati in questo ciclo.*/
        for(j=0;j<n;j++){                   /*Se 'volte' non viene resettato, al risultato di 'volte' del ciclo in corso viene sommato
                                              il numero di 'volte' del ciclo precedente alterando il funzionamento del programma.*/
            if(a[i]==a[j]){
                volte=volte+1;
            }
        }
        if(volte == *ripetizioniMax){
            if(a[i] > *numRipetuto)         /*Serve per indicare che se ho ad esempio una coppia di numeri uguali 12-12 e 16-16,
                                              devo considerare solo la coppia con numero più grande.*/
                *numRipetuto= a[i];         /*Se invece ho 12-12-12 e 16-16 anche se 16 è > di 12, il num. 12 si ripete per 3 volte
                                              rispetto al 16 che si ripete per 2 volte. Quindi viene considerato il valore 12.*/
        }
        if(volte > *ripetizioniMax){        /*Questo if serve ad indicare che se in un ciclo è stato trovato un maggior numero di ripetizioni
                                              di un numero rispetto al ciclo precedente allora, bisogna aggiornate ripetizioniMax e il numeroRipetuto.*/
            *ripetizioniMax= volte;
            *numRipetuto= a[i];
        }
    }
}




/*La procedura quadratoMagico riceve in input la matrice con il numero di righe (n), il numero di colonne (m) e n_col (numero di colonne) di tipo intero.
  La procedura genera i valori interi che costituiscono la matrice (n*m), e su questi valore esegue la somma di ogni riga, colonna e diagonale della matrice,
  salvando queste somme in degli array di tipo int.
  Il contenuto degli array vengono uniti, tramite la chiamate della procedura fusione (merge), in un unico array.
  Tramite la chiamata alla procedura trova_nUguali, si verifica se sono presenti dei valori uguali.
  In base al numero di valori uguali trovati viene calcolata la percentuale di successo.*/


void quadratoMagico(int*pa, int n, int m, int n_col){

    int k,i,j,a[100],b[100],c[100],d[100],v[100],y[100],x[100];
    int riga=0, colonna=0, diag=0, diag1=0, volte, nR;
    float percentuale;
    char simbolo= '%';


    srand(time(NULL));

    for(k=0;k<1000;k++){

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                *(pa+n_col*i+j)= 1 + rand()% 9;                 /*Genera valori pseudocasuali da 1 a 9 che costituiscono i valori interi della matrice.*/
                    printf("%d ",*(pa+n_col*i+j));
                }
            printf("\n");
            }



            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    riga=riga + *(pa+n_col*i+j);
                    }
                printf("\nLa somma della %d riga e': %d\n",i,riga);
                a[i]=riga;
                riga=0;
            }


            for(j=0;j<m;j++){
                for(i=0;i<n;i++){
                    colonna=colonna + *(pa+n_col*i+j);
                }
                printf("\nLa somma della %d colonna e': %d\n",j,colonna);
                b[j]=colonna;
                colonna=0;
            }


            for(i=0,j=m-1;i<n;i++,j--){
                diag=diag + *(pa+n_col*i+i);                    /*Diagonale principale*/  /*E' *i+i e NO *i+j perché sto calcolando la diagonale principale senza usare il secondo ciclo for innestato.*/
                                                                /*Es.: n,m=3; d.p.=(0,0)+(1,1)+(2,2);*/
                diag1=diag1 + *(pa+n_col*i+j);                  /*Diagonale secondaria*/
            }
            printf("\nLa somma della diagonale Principale e': %d\n",diag);
            c[0]=diag;
            diag=0;
            printf("\nLa somma della diagonale Secondaria e': %d\n",diag1);
            d[0]=diag1;
            diag1=0;


            fusione(a,n,b,m,v);
            fusione(c,1,d,1,y);                                 /*La dimensione è 1 perché gli array 'c' e 'd' contengono un solo elemento ovvero:
                                                                  l'array 'c' contiene la somma della digonale principale, mentre l'array 'd' contiene la diagonale secondaria.*/
            fusione(v,n+m,y,2,x);                               /*La dimensione dell'array 'y' è 2 perchè contiene solo due valori (diagonale principale e secondaria) */


            trova_nUguali(x,(n+m+2),&volte,&nR);                /* (n+m+2) : 'n' indica il numero di righe, 'm' indica il numero di colonne, +2 sono le due diagonali.*/

            if(volte == 1){                                     /* volte==1 vuol dire che non c'è nessun valore che si ripete, quindi assegno a 'nR' (numero ripetuto) e 'volte' il valore 0*/
                nR= 0;
                volte= 0;
                printf("\n\nCi sono %d valori che si ripetono\n",volte);
                percentuale= volte*100/(float)(n+m+2);
                printf("\nPercentuale: %.2f", percentuale);
                printf("%c\n\n",simbolo);
            }
            else{                                               /*Invece se volte è > 1 vuol dire che sono stati trovati almeno due numeri uguali*/
                percentuale= volte*100/(float)(n+m+2);
                printf("\n\nNumero ripetizioni: %d\n", volte);
                printf("\nValore che maggiormente si ripete: %d\n", nR);
                printf("\nPercentuale: %.2f", percentuale);
                printf("%c\n\n",simbolo);
            }
            percentuale=0;

            printf("\n");
        }
}
