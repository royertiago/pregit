int trieIndex( char c ) {
    if( c >= 'a' && c <= 'z' )
        return c - 'a';
    if ( c >= 'A' && c <= 'Z' )
        return c - 'A';
    if ( c >= '0' && c <= '9' )
        return c - '0' + 26;
    if ( c == '-' )
        return 36;
    if ( c == '_' )
        return 37;
    if ( c == '.' )
        return 38;
    
    return -1;
}
