/* 01 =====================
 * Predicado: primeiro(L,P)
 * Definição: L é uma lista e P é o primeiro dado de L.
 */

primeiro([P|_],P).

/* 02 ====================
 * Predicado: segundo(L,S)
 * Definição: L é uma lista e S é o segundo dado de L.
 */

segundo( [_, S | _], S ).

/* 03 ===================
 * Predicado: ultimo(L,U)
 * Definição: L é uma lista e U é o último dado de L.
 */

ultimo( [X], X ).
ultimo( [_ | Y], X ) :- ultimo( Y, X ).

/* 04 ======================
 * Predicado: penultimo(L,P)
 * Definição: L é uma lista e P é o penúltimo de L.
 */
penultimo( [X, _] , X ).
penultimo( [_ | Y], X ) :- penultimo( Y, X ).

/* 05 ====================
 * Predicado: tamanho(L,T)
 * Definição: L é uma lista e T é o número de dados de L.
 */
tamanho( [], 0 ).
tamanho( [_ | T], X ) :- tamanho( T, Y ), X is Y + 1.

/* 06 =====================
 * Predicado: pertence(D,L)
 * Definição: L é uma lista e D é um dos dados de L
 */
pertence( D, [D|_] ).
pertence( D, [_|L] ) :- pertence( D, L ).

/* 07 ========================
 * Predicado: posicao(D,L,Pos)
 * Definição: L é uma lista e Pos é a posição (iniciando com 1)
 * do dado D na lista L. Pos = 0 caso dado não esteja em L.
 */
posicaoG( D, [D|_], 1 ). %posiçãoGambiarrizada
posicaoG( D, [_| L], X ) :- posicaoG( D, L, Y ), X is Y + 1.
posicao( D, L, X ) :- pertence( D, L ), posicaoG( D, L, X ).
posicao( D, L, 0 ) :- \+ pertence( D, L ).

/* 08 ==============================
 * Predicado: removidoPrimeiro(L,LR)
 * Definição: L é uma lista e LR é uma lista com os mesmos dados de L
 * menos o primeiro.
 */
removidoPrimeiro( [_|L], L ).

/* 09 ============================
 * Predicado: removidoUltimo(L,LR)
 * Definição: L é uma lista e LR é uma lista com os mesmos dados de L
 * menos o último.
 */
removidoUltimo( [_ | []], [] ).
removidoUltimo( [X | L], [X | LR] ) :- removidoUltimo( L, LR ).

/* 10 =================================
 * Predicado: substituidoUltimo(D,L,LM)
 * Definição: L é uma lista e LM é uma lista com os mesmos dados de L
 * com exceção do último que é D.
 */
substituidoUltimo( D, [_], [D] ).
substituidoUltimo( D, [X | L], [X | LM] ) :-
        substituidoUltimo( D, L, LM ).

/* 11 ==================================
 * Predicado: inseridoNoInicio(D, L, LM)
 * Definição: D é um dado, L é uma lista e LM é a lista L mais o dado D no início.
 */
inseridoNoInicio( D, L, [D| L] ).

/* 12 =================================
 * Predicado: inseridoNoFinal(D, L, LM)
 * Definição: D é um dado, L é uma lista e LM é a lista L mais o dado D no final.
 */
inseridoNoFinal( D, [], [D] ).
inseridoNoFinal( D, [X | L], [X | LM] ) :- inseridoNoFinal( D, L, LM ).

/* 13 ====================================
 * Predicado: inseridoNaPos(D, Pos, L, LM)
 * Definição: D é um dado, Pos é a posição onde D deve ser inserido na lista L
 * e LM é a lista L mais o dado D na posição Pos.
 */

inseridoNaPos( D, 0, L, [D | L] ).
inseridoNaPos( D, N, [X | L], [X | LM] ) :- inseridoNaPos( D, M, L, LM ), N is M + 1.

/* 14 =====================================
 * Predicado: removidoDaPos(L, Pos, D, LM)
 * Definição: L é uma lista, Pos é a posição do dado a ser removido,
 * D é o dado removido e LM é a lista L sem o dado removido.
 */

removidoDaPos( [D | L], 0, D, L ).
removidoDaPos( [X | L], N, D, [X | LM] ) :- removidoDaPos( L, M, D, LM ), N is M + 1.
