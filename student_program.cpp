#include <stdio.h>
#include <stdlib.h>

void GetMatrix( int ***value , int *row , int *col ) ;
void PrintMatrix( int **value , int row , int col ) ;
void FreeMatrix( int **value , int row ) ;

int main() {

    int **matrix ;
    int m , n ;

    GetMatrix( &matrix , &m , &n ) ;
    PrintMatrix( matrix , m , n ) ;
    FreeMatrix( matrix , m ) ;

    return 0 ;
}

void GetMatrix( int ***value , int *row , int *col ) {

    scanf( "%d %d" , row , col ) ;

    *value = ( int ** ) malloc( *row * sizeof( int * ) ) ;

    if ( *value == NULL ) {
        printf( "Memory allocation failed!\n" ) ;
        exit(1) ;
    }

    for ( int i = 0 ; i < *row ; i++ ) {
        ( *value )[i] = ( int * ) malloc( *col * sizeof( int ) ) ;

        if ( ( *value )[i] == NULL ) {
            printf( "Memory allocation failed!\n" ) ;
            exit(1) ;
        }
    }

    for ( int i = 0 ; i < *row ; i++ ) {
        for ( int j = 0 ; j < *col ; j++ ) {
            scanf( "%d" , &( *value )[i][j] ) ;
        }
    }
}

void PrintMatrix( int **value , int row , int col ) {

    printf( "Matrix (%dx%d):\n" , row , col ) ;

    for ( int i = 0 ; i < row ; i++ ) {
        for ( int j = 0 ; j < col ; j++ ) {
            printf( "%d " , value[i][j] ) ;
        }
        printf( "\n" ) ;
    }
}

void FreeMatrix( int **value , int row ) {

    for ( int i = 0 ; i < row ; i++ ) {
        free( value[i] ) ;
    }
    free( value ) ;
}
