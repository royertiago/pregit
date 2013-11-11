:- dynamic paciente/2.

paciente(4, vilain).
paciente(3, mariani).
paciente(2, jerusa).
paciente(1, cancian).

:- dynamic pacienteID/1.

pacienteID(5).

:- dynamic medico/2.

medico(2, ricardo).
medico(1, dovicchi).

:- dynamic medicoID/1.

medicoID(3).

exame(7, 2, 1, 20131112, 1000).
exame(6, 1, 4, 20131107, 1330).
exame(5, 1, 4, 20131105, 1510).
exame(4, 2, 1, 20131112, 1000).
exame(3, 1, 2, 20131105, 1150).
exame(2, 2, 3, 20131107, 1000).
exame(1, 2, 3, 20131104, 820).

exameID(8).

diagnostico(4, 7, [82, 101, 99, 117, 112, 101, 114, 97, 100, 111, 32, 100, 97, 32, 98, 105, 243, 112, 115, 105, 97]).
diagnostico(3, 4, [69, 110, 118, 105, 97, 100, 111, 32, 112, 97, 114, 97, 32, 98, 105, 243, 112, 115, 105, 97]).
diagnostico(2, 2, [71, 114, 105, 112, 101]).
diagnostico(1, 5, [69, 115, 113, 117, 105, 122, 111, 102, 114, 101, 110, 105, 97]).

diagnosticoID(5).

cirurgia(1, 2, 1, 20131106, 820, [66, 105, 243, 112, 115, 105, 97]).

cirurgiaID(2).

status(1, 7, 20131112, 1000, alta).
status(2, 2, 20131107, 1000, alta).
status(4, 1, 20131105, 1510, baixa).
status(1, 3, 20131105, 1000, baixa).

