/* Função usada para indexação do trie.
 * Por exemplo trieIndex( 'c' ) == 2 == 'c' - 'a'.
 *
 * Letras serão numeradas em ordem crescente (ignorando caixa), 
 * após números, então hifen, underscore e ponto.*/
  
#ifndef TRIE_INDEX_H
#define TRIE_INDEX_H

int trieIndex( char c );

#define TRIE_SIZE 39 //Quantidade de elementos armazenados pelo trie.

#endif // TRIE_INDEX_H
