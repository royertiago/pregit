/* main.pl
 * Programa principal.
 */

include( X ) :- consult( X ). %TipoDePredicadoDix

main :- % A cláusula :-main está no fim do programa.
    include( 'sgbd.pl' ),
    include( 'stdio.pl' ),
    carregar,
    nl, write( 'Sistema de controle de atividade em um hospital' ), nl,
    menuPrincipal.

menuPrincipal :- repeat, nl,
    write( '    Escolha sua opção: ' ), nl,
    write( 'a - exibir alunos' ), nl,
    write( 'cc - cadastrar cirurgia' ), nl,
    write( 'ce - cadastrar exame' ), nl,
    write( 'cm - cadastrar novo médico' ), nl,
    write( 'cp - cadastrar novo paciente' ), nl,
    write( 'pc - procurar cirurgia' ), nl,
    write( 'pm - procurar médico' ), nl,
    write( 'pp - procurar paciente' ), nl,
    write( 'q - sair' ), nl,
    write( 't - carregar banco de dados de testes' ), nl,
    scanf( X ),
    once( opcao( X ) ),
    X = q, nl, !.
    
:- discontiguous opcao.

%exibir alunos
opcao( a ) :-
    write( 'Igor Henrique Grajefe Feitosa' ), nl,
    write( 'Tiago Royer' ), nl,
    write( 'Wagner Fernando Gascho' ), nl.

%cadastrar cirurgia
opcao( cc ) :-
    write( 'Digite o nome do médico responsável: ' ), nl,
    scanf( Medico ),
    write( 'Digite o nome do paciente: ' ), nl,
    scanf( Paciente ),
    write( 'Digite a hora da cirurgia: ' ), nl,
    scanf( Hora ),
    write( 'Digite a data da cirurgia: ' ), nl,
    scanf( Data ),
    write( 'Digite o tipo da cirurgia: ' ), nl,
    scanf( Tipo ),
    cadastrarCirurgia( Medico, Paciente, Data, Hora, Tipo ).

%cadastrar novo médico
opcao( cm ) :- 
    write( 'Digite o nome do novo médico:' ), nl,
    scanf( Nome ),
    cadastrarMedico( Nome ).

%Cadastrar novo paciente
opcao( cp ) :- 
    write( 'Digite o nome do novo paciente:' ), nl,
    scanf( Nome ),
    cadastrarPaciente( Nome ).

%Cadastrar novo exame
opcao( ce ) :-
    write( 'Digite o nome do médico: ' ), nl,
    scanf( Medico ),
    write( 'Digite o nome do paciente: ' ), nl,
    scanf( Paciente ),
    write( 'Digite o dia: ' ), nl,
    scanf( Data ),
    write( 'Digite o horário: ' ), nl,
    scanf( Hora ),
    write( 'Há um diagnóstico associado? [s/n]' ), nl,
    scanf( Resposta ),
    write( Data ), write( Hora ),
    continueLendo( Medico, Paciente, Data, Hora, Resposta ).

%GAMBIARRRRRRA
continueLendo( Medico, Paciente, Data, Hora, n ) :- !,
    cadastrarExame( Medico, Paciente, Data, Hora ).

continueLendo( Medico, Paciente, Data, Hora, _ ) :-
    write( Data ), write( Hora ),
    write( 'Digite o resultado do diagnóstico:' ), nl,
    readData( Resultado ),
    write( 'Digite o status do paciente [alta/baixa]: ' ),
    scanf( Status ),
    write( Data ), write( Hora ),
    cadastrarExameDiagnostico( Medico, Paciente,
        Data, Hora, Resultado, Status ).

%Procurar médico
opcao( pm ) :-
    write( 'Digite o nome do médico:' ), nl,
    scanf( Medico ),
    medico( ID, Medico ) -> write( 'Médico: ' ),
        write( Medico ), write( ' - ID: ' ), write( ID ) ;
    write( 'Médico não encontrado no banco de dados.' ).

%Procurar paciente - GAMBIARRA (deveria ter feito isso em sgbd.pl)
opcao( pp ) :-
    write( 'Digite o nome do paciente:' ), nl,
    scanf( Paciente ),
    paciente( IDP, Paciente ) -> write( 'Paciente: ' ),
        write( Paciente ), write( ' - ID: ' ), write( IDP ),
        (once( status(IDP, _,_,_, Status) ) -> write( ' - Status: ' ),
        write( Status )) ;
    write( 'Paciente não encontrado no banco de dados.' ).

%procurar cirurgia
opcao( pc ) :-
    write( 'Digite o nome do paciente:' ), nl,
    scanf( Paciente ),
    paciente( IDP, Paciente ),
    write( 'Digite o nome do médico:' ), nl,
    scanf( Medico ),
    medico( IDM, Medico ),
    once( cirurgia( _, IDM, IDP, Data, Hora, Tipo ) ),
    write( 'Última cirurgia foi em ' ), write( Data ),
    write( ' às ' ), write( Hora ), nl,
    write( 'Tipo: ' ), write( Tipo ).
%Dava para fazer um findall aqui, mas não dá tempo.

%Carregar banco de dados de teste.
opcao( t ) :- testarBD.

%Sair do programa.
opcao( q ) :- write( 'Salvando banco de dados...' ),
    salvar, write( 'Feito.' ), nl,
    write( 'Obrigado por usar o programa!' ), nl.

%Opção desconhecida.
opcao( X ) :- write( 'Opção não conhecida: ' ), write( X ), nl, nl.


:- main.
