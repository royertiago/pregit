/* date.pl
 * Funcões para trabalhar com datas.
 * 
 * formatarData( -Data, +String ) :-
 * converte a data passada (um número) pruma string legível.
 */

%Formado de data: AAAAMMDD

/*dia( data( Dia, _, _ ), Dia ).
mes( data( _, Mes, _ ), Mes ).
ano( data( _, _, Ano ), Ano ).*/

%FormatarData1 recebe dia, mes e ano e retorna data.
formatarData1( Data, data(Dia, Mes, Ano) ) :- 
    Data is Dia + 12*Mes + 12*31*Ano.

%FormatarData2 recebe data e retorna dia, mes e ano.
formatarData2( Data, data(Dia, Mes, Ano) ) :-
    Dia is Data mod 31,
    Mes is (Data // 31) mod 12,
    Ano is Data // (12*31).

/* mes( Numero, Nome ). */
mes( 1, janeiro ).
mes( 2, fevereiro ).
mes( 3, marco ).
mes( 4, abril ).
mes( 5, maio ).
mes( 6, junho ).
mes( 7, julho ).
mes( 8, agosto ).
mes( 9, setembro ).
mes( 10, outubro ).
mes( 11, novembro ).
mes( 12, dezembro ).
