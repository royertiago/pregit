% Notação: f( X, Y ) <=> f(Y) = X, para f proposição de uma só letra.

igual( X, X ).
diferente( X, Y ) :- not(igual( X, Y )).

a( zero, um ). % zero é o antecessor de um
a( um, dois ).
a( dois, tres ).
a( tres, quatro ).
a( quatro, cinco ).
a( cinco, seis ).
a( seis, sete ).
a( sete, oito ).
a( oito, nove ).
a( nove, dez ).

a( dez, onze ).
a( onze, doze ).
a( doze, treze ).
a( treze, catorze ).
a( catorze, quinze ).
a( quinze, dezesseis ).
a( dezesseis, dezessete ).
a( dezessete, dezoito ).
a( dezoito, dezenove ).
a( dezenove, vinte ).

a( vinte, vinte_um ).
a( vinte_um, vinte_dois ).
a( vinte_dois, vinte_tres ).
a( vinte_tres, vinte_quatro ).
a( vinte_quatro, vinte_cinco ).
a( vinte_cinco, vinte_seis ).
a( vinte_seis, vinte_sete ).
a( vinte_sete, vinte_oito ).
a( vinte_oito, vinte_nove ).
a( vinte_nove, trinta ).

a( trinta, trinta_um ).
a( trinta_um, trinta_dois ).
a( trinta_dois, trinta_tres ).
a( trinta_tres, trinta_quatro ).
a( trinta_quatro, trinta_cinco ).
a( trinta_cinco, trinta_seis ).
a( trinta_seis, trinta_sete ).
a( trinta_sete, trinta_oito ).
a( trinta_oito, trinta_nove ).
a( trinta_nove, quarenta ).

a( quarenta, quarenta_um ).
a( quarenta_um, quarenta_dois ).
a( quarenta_dois, quarenta_tres ).
a( quarenta_tres, quarenta_quatro ).
a( quarenta_quatro, quarenta_cinco ).
a( quarenta_cinco, quarenta_seis ).
a( quarenta_seis, quarenta_sete ).
a( quarenta_sete, quarenta_oito ).
a( quarenta_oito, quarenta_nove ).
a( quarenta_nove, cinquenta ).

a( cinquenta, cinquenta_um ).
a( cinquenta_um, cinquenta_dois ).
a( cinquenta_dois, cinquenta_tres ).
a( cinquenta_tres, cinquenta_quatro ).
a( cinquenta_quatro, cinquenta_cinco ).
a( cinquenta_cinco, cinquenta_seis ).
a( cinquenta_seis, cinquenta_sete ).
a( cinquenta_sete, cinquenta_oito ).
a( cinquenta_oito, cinquenta_nove ).
a( cinquenta_nove, sessenta ).

a( sessenta, sessenta_um ).
a( sessenta_um, sessenta_dois ).
a( sessenta_dois, sessenta_tres ).
a( sessenta_tres, sessenta_quatro ).
a( sessenta_quatro, sessenta_cinco ).
a( sessenta_cinco, sessenta_seis ).
a( sessenta_seis, sessenta_sete ).
a( sessenta_sete, sessenta_oito ).
a( sessenta_oito, sessenta_nove ).
a( sessenta_nove, setenta ).

a( setenta, setenta_um ).
a( setenta_um, setenta_dois ).
a( setenta_dois, setenta_tres ).
a( setenta_tres, setenta_quatro ).
a( setenta_quatro, setenta_cinco ).
a( setenta_cinco, setenta_seis ).
a( setenta_seis, setenta_sete ).
a( setenta_sete, setenta_oito ).
a( setenta_oito, setenta_nove ).
a( setenta_nove, oitenta ).

a( oitenta, oitenta_um ).
a( oitenta_um, oitenta_dois ).
a( oitenta_dois, oitenta_tres ).
a( oitenta_tres, oitenta_quatro ).
a( oitenta_quatro, oitenta_cinco ).
a( oitenta_cinco, oitenta_seis ).
a( oitenta_seis, oitenta_sete ).
a( oitenta_sete, oitenta_oito ).
a( oitenta_oito, oitenta_nove ).
a( oitenta_nove, noventa ).

a( noventa, noventa_um ).
a( noventa_um, noventa_dois ).
a( noventa_dois, noventa_tres ).
a( noventa_tres, noventa_quatro ).
a( noventa_quatro, noventa_cinco ).
a( noventa_cinco, noventa_seis ).
a( noventa_seis, noventa_sete ).
a( noventa_sete, noventa_oito ).
a( noventa_oito, noventa_nove ).

suc( X, Y ) :- a( Y, X ).

menor( X, Y ) :- a( X, Y ).
menor( X, Z ) :- a( Y, Z ), menor( X, Y ).
maior( X, Y ) :- suc( X, Y ).
maior( X, Z ) :- suc( Y, Z ), maior( X, Y ).

menorI( X, Y ) :- igual(X, Y); menor( X, Y ).
maior2( X, Y ) :- not( menorI(X, Y) ).
maior3( X, Y ) :- \+ menorI( X, Y ).

max( X, X, X ).
max( X, X, Y ) :- maior( X, Y ).
max( Y, X, Y ) :- maior( Y, X ).

max2( X, X, X ).
max2( X, X, Y ) :- maior2( X, Y ).
max2( Y, X, Y ) :- maior2( Y, X ).

menor2( X, Y ) :- a( X, Y ), !.
menor2( X, Z ) :- menor2( X, Y ), !, menor2( Y, Z ).

%plus( X + Y, X, Y )
plus( X, X, zero ). % soma; +( X, zero ) = X + zero = X.
% +( X, s(Y) ) = s( +(X, Y) ).
%    suc(Y) = Z, +(X, Y) = W, suc(+(X,Y)) = K [suc(W) = K]
plus( K, X, Z ) :- suc( Z, Y ), plus( W, X, Y ), suc( K, W ).

minus( K, Y, Z ) :- plus( Y, Z, K ). % K = Y - Z <=> Y = K + Z.


times( zero, _, zero ). % produto; t( X, zero ) = zero.
% t( X, suc(Y) ) = t(X, Y) + X = K;
% t(X, Y) = W, K = W + Y, suc(Y) = Z
times( K, X, Z ) :- suc( Z, Y ), times( W, X, Y ), plus( K, W, X ).

composto( X ) :- times( X, Y, Z ), diferente(Y, um), diferente(Z, um).
primo( X ) :- not( composto( X ) ), diferente(X, um).

pow( um, _, zero ). % potência; pow( X, zero ) = um.
% pow( X, suc(Y) ) = t( X, pow(X, Y) ).
% suc( Y ) = Z, pow(X, Y) = W, K = X * X^Y = X*W, K = t( X, W ).
pow( K, X, Z ) :- suc( Z, Y ), pow( W, X, Y ), times( K, W, X ).

sqrt( K, X ) :- pow( X, K, dois ).
cbrt( K, X ) :- pow( X, K, tres ).
logb( K, X ) :- pow( X, dois, K ). %binary log

%Integer definitions
%sqrt(Y) = K, X <= Y < Z, sqrt(X) + 1 = sqrt(Z), K = sqrt(X).
zsqrt( K, Y ) :- menorI(X, Y), menor(Y, Z), 
                 sqrt( K, X ), sqrt( RZ, Z ), suc( RZ, K ).
zcbrt( K, Y ) :- menorI(X, Y), menor(Y, Z), 
                 cbrt( K, X ), cbrt( RZ, Z ), suc( RZ, K ).
zlogb( K, Y ) :- menorI(X, Y), menor(Y, Z), 
                 logb( K, X ), logb( RZ, Z ), suc( RZ, K ).

%Tamanho da representação binária de X é Y.
binarySize( Y, X ) :- suc( Y, K ), zlogb( K, X ).

fat( um, zero ) :- !.
fat( X, Y ) :- a( Z, Y ), fat( K, Z ), times( X, K, Y ).


% Soma de pares:
% (10a + b) + (10c + d) = 10(a + c + l) + (c + d - 10l),
%        0 <= c + d -10l < dez, 0 <= l <= 1, 0 <= c, d < dez
% Primeiro, soma sem carry:
plus( pair( F, G ), pair( A, B ), pair( C, D ) ) :- 
    menor( B, dez ), menor( D, dez ), plus( G, B, D ), 
    menor( G, dez ), plus( F, A, C ), menor( F, dez ).
% Agora, soma com carry. B + D = K, K - 10 = G. F = A + C + 1.
plus( pair( F, G ), pair( A, B ), pair( C, D ) ) :- 
    menor( B, dez ), menor( D, dez ), plus( K, B, D ),
    minus( G, K, dez),
    menor( G, dez ), plus( L, A, C ), suc( F, L ), menor( F, dez ).

% Defina c( X, Y ) como Y o dado e X o carry.
% Existem dois tipos de dados: cru e lista.
% suc( X, Y ) <=> X é o sucessor de Y.
suc( c( zero, X ), c( zero, Y ) ) :- a( Y, X ), menor( X, dez ).
suc( c( um, zero ), c( zero, nove ) ).

suc( c( Xc, [X]), c( Yc, [Y] ) ) :- suc( c( Xc, X ), c( Yc, Y ) ).
suc( c(zero, [X | XL]), c( zero, [Y | YL] ) ) :- 
    suc( c( Xc, XL ), c( zero, YL ) ), plus( X, Y, Xc ), 
    menor( X, dez ).
suc( c(zero, [um, zero | XL]), c( zero, [nove | YL] ) ) :- 
    suc( c( um, XL ), c( zero, YL ) ).
suc( X, Y ) :- suc( c(zero, X), c( zero, Y ) ).
