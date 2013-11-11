/* sgbd.pl - conjunto de funções para trabalhar com o banco de dados
 * do trabalho do hospital. As funções que executam operações o fazem
 * no arquivo bd.pl e retornam true.
 *
 * Funções disponíveis:
 *
 *  carregar/0
 * Carrega o banco de dados do disco. Esta operação sobrescreve
 * testar/0.
 *
 *  testarBD/0
 * Carrega o banco de dados de testes. Esta opção sobrescreve
 * a operação carregar/0.
 *
 *  salvar/0
 * Salva as diretivas atuais do banco de dados. carregar/0 ou 
 * testarBD/0  devem ter sido executadas antes.
 *
 *  cadastrarPaciente( +Nome )
 * Cadastra um paciente com o nome passado no banco de dados.
 * Caso já exista um paciente com este nome, a mensagem de erro
 * especificada em erro( pacienteJaExiste ) é exibida.
 *
 *  cadastrarMedico( +Nome )
 * Cadastra um médico com o nome passado no banco de dados.
 * Caso já exista um paciente com este nome, a mensagem de erro
 * especificada em erro( medicoJaExiste ) é exibida.
 *
 *  cadastrarExame( +NomeMedico, +NomePaciente, +Data, +Hora )
 * Cadastra um exame de acordo com os parâmetros.
 * Não é associado nenhum diagnóstico à este exame.
 * Suporemos que o médico e paciente passados já existem.
 *
 *  cadastrarExameDiagnostico( +NomeMedico, +NomePaciente, +Data, 
 *      +Hora, +Resultado, +Status )
 * Cadastra um exame de acordo com os parâmetros, associa um
 * diagnóstico com o resultado passado e associa um status
 * ao diagnóstico criado.
 * Suporemos que o médico e paciente passados já existem.
 *
 *  cadastrarCirurgia( +NomeMedico, +NomePaciente, +Data, +Hora, +Tipo)
 * Cadastra uma cirurgia de acordo com os parâmetros.
 * Suporemos que o médico e paciente passados já existem.
 *
 *  erro( +Erro ) - função interna
 * Mostra a mensagem de erro correspondente.
 */


anunciarPredicadosDinamicos :- 
    dynamic paciente/2,  pacienteID/1, medico/2, medicoID/1, exame/5,
    exameID/1, diagnostico/3, diagnosticoID/1, cirurgia/6, 
    cirurgiaID/1, status/5.

listarPredicadosBancoDeDados :-
    listing( paciente/2 ), listing( pacienteID/1 ),
    listing( medico/2 ), listing( medicoID/1 ),
    listing( exame/5 ), listing( exameID/1 ),
    listing( diagnostico/3 ), listing( diagnosticoID/1 ),
    listing( cirurgia/6 ), listing( cirurgiaID/1 ),
    listing( status/5 ).

:- consult( 'counter.pl' ), anunciarPredicadosDinamicos.

%Funções de inicialização
carregar :- anunciarPredicadosDinamicos, consult( 'bd.pl' ).
testarBD :- anunciarPredicadosDinamicos, consult( 'bd.bak' ).
salvar :- tell( 'bd.pl' ), listarPredicadosBancoDeDados, told.

/* Funções de erro. Futuramente, posso dar ao usuário a possibilidade
 * de modificar as mensagens e adicionar "tratadores" para os erros. */
erro( pacienteJaExiste ) :- 
    write( 'Já existe um paciente com este nome.' ), nl.

erro( medicoJaExiste ) :-
    write( 'Já existe um médico com este nome.' ), nl.

% cadastrarPaciente( +Nome )
cadastrarPaciente( Nome ) :-
    paciente( _ID, Nome ), !, erro( pacienteJaExiste ).
cadastrarPaciente( Nome ) :-
    pacienteID( ID ), asserta( paciente( ID, Nome ) ), ++(pacienteID).

%cadastrarMedico( +Nome )
cadastrarMedico( Nome ) :- 
    medico( _ID, Nome ), !, erro( medicoJaExiste ).
cadastrarMedico( Nome ) :-
    medicoID( ID ), asserta( medico( ID, Nome ) ), ++(medicoID).

%cadastrarExame( +NomeMedico, +NomePaciente, +Data, +Hora )
cadastrarExame( NomeMedico, NomePaciente, Data, Hora ) :-
    medico( IDMedico, NomeMedico ),
    paciente( IDPaciente, NomePaciente ),
    exameID( ID ),
    asserta( exame( ID, IDMedico, IDPaciente, Data, Hora ) ),
    ++( exameID ).

/* cadastrarExameDiagnostico( +NomeMedico, +NomePaciente, +Data, 
 * +Hora, +Resultado, +Status ) */
cadastrarExameDiagnostico( NomeMedico, NomePaciente, Data, Hora, 
Resultado, Status ) :-
    medico( IDMedico, NomeMedico ),
    paciente( IDPaciente, NomePaciente ),
    exameID( IDExame ),
    diagnosticoID( IDDiagnostico ),
    write( Data ), write( Hora ),
    asserta( exame( IDExame, IDMedico, IDPaciente, Data, Hora ) ),
    asserta( diagnostico( IDDiagnostico, IDExame, Resultado ) ),
    asserta( status( IDPaciente, IDDiagnostico, Data, Hora, Status ) ),
    ++( exameID ), ++( diagnosticoID ).
 
%cadastrarCirurgia( +NomeMedico, +NomePaciente, +Data, +Hora, +Tipo )
cadastrarCirurgia( NomeMedico, NomePaciente, Data, Hora, Tipo ) :-
    medico( IDMedico, NomeMedico ),
    paciente( IDPaciente, NomePaciente ),
    cirurgiaID( ID ),
    asserta( cirurgia( ID, IDMedico, IDPaciente, Data, Hora, Tipo ) ),
    ++(cirurgiaID).
