/* stdio.pl - Funções de leitura formatada.
 *
 * Funções disponíveis:
 * scanf( -X ) - lê caracteres do teclado até o Enter e unifica 
 * o termo digitado com X. 
 */

scanf( X ) :- readData( L ), name( X, L ).

/* readData( -List ) :- Lê um caractere e transfere o controle
 * para readData. */
readData( List ) :- get0( C ), appendData( C, List ).

/* appendData( +Char, -List ) :- Se Char for uma quebra de linha,
 * List é unificado com a lista vazia. Caso contrário, o predicado
 * lê mais caracteres do teclado até encontrar uma quebra de linha,
 * unificando List com o conjunto de caracteres digitados.
 */
appendData( 10, List ) :- !, List = [].
appendData( C, List ) :- List = [C | ListaAlce], readData( ListaAlce ).
