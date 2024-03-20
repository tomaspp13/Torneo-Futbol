/*   CAMPEONATO   */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <ctime>

using namespace std;

class JUGADOR {
		public :

			char NOM[20] ;
			JUGADOR * SIG ;
			JUGADOR(char *);
			~JUGADOR();
};

JUGADOR::JUGADOR(char * S)
{
		strcpy ( NOM , S ) ;
		SIG = NULL ;

}

JUGADOR::~JUGADOR()
{
		cout << "\n\n   MATANDO A ... " << NOM << "\n\n";

}


class EQUIPO {
		public :
			char NOM[20] ;
			int PUNTAJE;
			JUGADOR * PAJU ;
			EQUIPO * SIG ;
			EQUIPO ( char * , JUGADOR * ) ;
			~EQUIPO() ;
};


EQUIPO::EQUIPO ( char * S , JUGADOR * CAPI )
{
		strcpy ( NOM , S ) ;
		PAJU = CAPI ;
		PUNTAJE = rand()%20;
}

EQUIPO::~EQUIPO()
{
		cout << "\n\n FIN\n\n";

}


class CAMPEONATO {
		private :
			EQUIPO * INICIO ;
			EQUIPO * BUSCAR(char *);
		public :
			CAMPEONATO() ;
			~CAMPEONATO() ;
			void CARGAR(char *);
			void MIRAR();
			void TABLA();
			EQUIPO * MAXIMO();
			void ENLAZAR(EQUIPO *);
			void MIRAR_TABLA();
};

CAMPEONATO::CAMPEONATO()
{
		INICIO = NULL ;
}


CAMPEONATO::~CAMPEONATO()
{
		cout << "\n\n FIN DEL CAMPEONATO\n" ;


}

EQUIPO * CAMPEONATO::BUSCAR ( char * S )
{
		EQUIPO * P ;
		P = INICIO ;
		while ( P ) {
				if ( ! strcmp( S , P->NOM ) )
						return P ;
				P = P->SIG ;
		}
		return NULL ;
}



void CAMPEONATO::CARGAR( char * S )
{

		char * GENERAEQUIPO();

		char BUF[20] ;
		JUGADOR * PJ , * P ;
		EQUIPO * PEQUI ;

		PJ = new JUGADOR(S) ;
		strcpy( BUF , GENERAEQUIPO() ) ;


		PEQUI = BUSCAR(BUF);

		if ( PEQUI ) {

				P = PEQUI->PAJU ;
				while ( P->SIG ){

                        P = P->SIG;

				}
				P->SIG = PJ ;

				return ;
		}

		PEQUI = new EQUIPO ( BUF , PJ );
		PEQUI->SIG = INICIO ;
		INICIO = PEQUI ;
}

void CAMPEONATO::MIRAR()
{
		EQUIPO * PEQUI ;
		JUGADOR * PJ ;

		PEQUI = INICIO ;
		while ( PEQUI ) {

                printf("\n\t\t\t-------------\n");
				printf("\t\t\t %s\n" , PEQUI->NOM);

				printf("\t\t\t-------------\n\n");
				PJ = PEQUI->PAJU ;
				while ( PJ ) {
						printf("\t\t\t *%s\n" , PJ->NOM);
						PJ = PJ->SIG ;
				}

				PEQUI = PEQUI->SIG ;
		}
}

void CAMPEONATO :: TABLA(){

    EQUIPO * E,*MAX;

    MAX= NULL;

  while(INICIO){

       E = MAXIMO();
       ENLAZAR(E);
       E->SIG = MAX;
       MAX = E;

  }

  INICIO = MAX;
}

EQUIPO * CAMPEONATO :: MAXIMO(){

    EQUIPO * E,*MAX;

 MAX = E = INICIO;


    while(E){

        if(E->PUNTAJE < MAX->PUNTAJE){
            MAX = E;

        }

        E = E->SIG;
    }

    return MAX;

}
void CAMPEONATO :: ENLAZAR(EQUIPO * AUX){

    EQUIPO * E;

    E= INICIO;

    if(INICIO == AUX){

        INICIO = AUX->SIG;

        return;

    }

    while(E->SIG != AUX && E){
        E = E->SIG;

    }

    if(E){

        E->SIG = E->SIG->SIG;

    }

}
void CAMPEONATO::MIRAR_TABLA(){

    EQUIPO * E;

    E = INICIO;

    printf("\n       EQUIPOS  PUNTOS\n\n");

    while(E){

        printf("%13s  | %d\n",E->NOM,E->PUNTAJE);
        E=E->SIG;

    }

    E = INICIO;

    printf("\nGANADOR ES : %s\n",E->NOM);

}
char * GENERANOM();

int main()
{

        printf("\n\n\t\t\tTORNEO DE FUTBOL\n\n");

       srand(time(NULL));
		char BUF[20] ;
		CAMPEONATO G ;



		strcpy( BUF , GENERANOM() ) ;
		while ( strcmp (BUF,"FIN") ) {
				G.CARGAR(BUF) ;

				strcpy( BUF , GENERANOM() ) ;
		}

		G.MIRAR() ;

        G.TABLA();

        G.MIRAR_TABLA();



		return 0 ;
}


char * GENERANOM()
{
		static char NOM[][20] = {"MARADONA","RONALDO","MESSI",
						  "PELE","MESSI","LABRUNA",
						  "ORTEGA","RIQUELME","ROMA","CARRIZO",
						  "LORENZO","BOBBY MOORE","RONALDINHO","ARMANI",
						  "TARANTINI","RATTIN","ROSSI","ONEGA",
						  "ARTIME","VARACKA","GALLARDO","TEVEZ",
						  "MORETE","ERICO","LABRUNA","MORENO",
						  "PEDERNERA","LOUSTEAU","CAVENAGHI","NAVARRO",
						  "PAVONI","VERON","MESSI","RONALDO",
						  "PERFUMO","MATOSAS","PELE",
						  "CUBILLA","SANTORO","MALBERNAT","BECKENBAUER",
						  "EUSEBIO","PASTORIZA","JAIRZINHO","ROJAS",
						  "MADURGA","PIANETTI","ANDRADA","MARIN",
						  "ROMERO","ALONSO","FRANCESCOLI","DOMINGUEZ",
						  "MAYADA","MORA","MASCHERANO","KRANEVITER",
						  "SOLARI","MATURANA","BOBY MOORE",
						  "HIGUITA","BASILE","FRANCESCOLI",
						  "SARNARI","BILARDO","BATISTUTA","VALENTIM",
						  "CRISTIANO","ZAMORANO","SALAS","ARDILES",
						  "KEMPES","ZANABRIA","OLGUIN","PALACIOS",
						  "MESSI","VERON","FIN"};
		static int I = 0 ;
		return NOM[I++] ;
}


char * GENERAEQUIPO()
{
		static char NOM[][20] = {"BARCELONA","RIVER","BOCA","JUVENTUS",
						  		 "MILAN","REAL MADRID","DYNAMO",
								 "BOTAFOGO","COLO COLO","PEÑAROL",
								 "RACING","INDEPENDIENTE"  };
		return NOM[rand()%12] ;
}

