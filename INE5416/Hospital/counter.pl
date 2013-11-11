/* counter.pl - provê funcões para atualizar contadores.
 * Um contador é um predicado da forma
 *  counter( [numero] )
 * em que [numero] é um valor inteiro. Esta deve ser a única ocorrência
 * do predicado 'counter' em todo o programa.
 *
 * Para obter o valor do contador, utilize
 *  counter( X ).
 * X será unificado com o valor do contador.
 *
 * Funções disponíveis:
 *
 *  startCounter( +Counter )
 * cria o contador e o seta para zero. Sempre retorna true.
 *
 *  setCounter( +Counter, +Value )
 * altera o valor do contador passado.
 *
 *  ++( +Counter )
 * incrementa o valor do contador em uma unidade.
 */

startCounter( Counter ) :- 
    CounterPredicate =.. [Counter, 0],
    asserta( CounterPredicate ).

setCounter( Counter, Value ) :-
    CounterPredicate =.. [Counter, _OriginalValue],
    CounterPredicate, %Unificar OriginalValue com o valor atual
    abolish( Counter, 1 ),
    NewCounterPredicate =.. [Counter, Value],
    asserta( NewCounterPredicate ).

++( Counter ) :-
    OriginalCounterPredicate =.. [Counter, OriginalValue],
    OriginalCounterPredicate,
    abolish( Counter, 1 ),
    NewValue is OriginalValue + 1,
    NewCounterPredicate =.. [Counter, NewValue],
    asserta( NewCounterPredicate ).

