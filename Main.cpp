
// Dark GDK - The Game Creators - www.thegamecreators.com

// the wizard has created a very simple 2D project that uses Dark GDK
// it can be used as a starting point in making your own 2D games

// whenever using Dark GDK you must ensure you include the header file
#include "DarkGDK.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// the main entry point for the application is this function




struct PAIR
{
	int ID;
	int Im;

	void setIdIm(int iID,int iIm){ID=iID;Im=iIm;}
	int getID(){return ID;}
	int getIm(){return Im;}

};

typedef PAIR coordenada;

void MoverSprite(int iX,int iY);
void borrarSprite(int iX,int iY);

vector<coordenada> Coords; 
coordenada C;
int i=2; // Numero de Sprite

void incI()
{
	i++;

}

void GenerarMapa()
{
	int j=0;
	int x,y;
	ofstream FileWorld("Mundo1.txt", ios::out);
	string TipoObjeto;
	for(; j< (int) Coords.size() ; j++)
	{
		x=dbSpriteX(Coords.at(j).getID())-dbSpriteWidth(Coords.at(j).getID())/2;
		y=dbSpriteY(Coords.at(j).getID())-dbSpriteHeight(Coords.at(j).getID())/2;
		if (Coords.at(j).getIm()==2)
		{
			TipoObjeto="Pollo";
		}
		if (Coords.at(j).getIm()==3)
		{
			TipoObjeto="Alcon";
		}
		if (Coords.at(j).getIm()==4)
		{

			TipoObjeto="Ornitorrinco";
		}
		if (Coords.at(j).getIm()==5 || Coords.at(j).getIm()==6)
		{
			
			TipoObjeto="Obstaculo";
		}
		if (Coords.at(j).getIm()==7)
		{
			
			TipoObjeto="Huevo";
		}

		
		FileWorld << Coords.at(j).getID() << " " << Coords.at(j).getIm() << " " << x <<  " " << y << " " << TipoObjeto;
		FileWorld << endl;
	}  	  
	 
} 

void LeerMapa()
{

	int posx;
	int posy;
	int IDSprite;
	int IDImage;
	ifstream Map("PorFin.txt");

	while(!Map.eof())
	{
		Map >> IDSprite >> IDImage >> posx >> posy;
		dbSprite(IDSprite,posx,posy,IDImage);

	}
	

	Map.close();


}

void DarkGDK ( void )
{
	dbSyncOn   ( );
	dbSyncRate (0);
	dbDisableEscapeKey ( );
	dbSetDisplayMode(1300,628,32);
	dbLoadImage ( "World.bmp",1);

	/* Elementos del Mundo  */

	dbLoadImage ( "PolloVolador2.bmp",2);
	dbLoadImage ( "alcon.bmp",3);
	dbLoadImage ( "ornitorrinco.bmp",4);
	dbLoadImage	( "obstaculoMadera.bmp",5);
	dbLoadImage ( "obstaculoMaderaAcostado.bmp",6);
	dbLoadImage ( "Huevo.bmp",7);
	
	dbSprite ( 1, 0, 0, 1 );
	
	dbSetImageColorKey ( 255, 0, 255 );

	
	
	int Semaphore=0;
	
	while ( LoopGDK ( ) )
	{
		if (i-2 > 0)
		{
			char string[200];
			int IM=Coords.at(i-3).getIm();
			int ID=Coords.at(i-3).getID();
			sprintf ( string, "i= %d , ID = %d , Ima = %d Size Vector = %d", i, ID ,IM,(int) Coords.size() );
			dbText (650,300, string );
		}
		
		/* Generar El Mundo Undiendo la tecla R  */

		if (dbUpKey()==1)
		{
			while (dbUpKey()==1 && Semaphore==0);
			Semaphore=1;
		}


		if (dbUpKey()==0 && Semaphore==1)
		{
			GenerarMapa();
			Semaphore=0;
		}

		/* Pintar el mundo con las Coordenadas Generadas  */
		if (dbDownKey()==1)
		{
			while (dbDownKey()==1 && Semaphore==0);
			Semaphore=1;
		}


		if (dbDownKey()==0 && Semaphore==1)
		{
			LeerMapa();
			Semaphore=0;
		}
		/*    ------     */

		if (dbKeyState(20)==1)
		{
			dbSprite(i,100,100,5);
			while (dbKeyState(20)==1 && Semaphore==0);
			C.setIdIm(i,5);
			Coords.push_back(C);
			Semaphore=1;
		}
		
		if (dbKeyState(21)==1)
		{
			dbSprite(i,200,100,6);
			while (dbKeyState(21)==1 && Semaphore==0);
			C.setIdIm(i,6);
			Coords.push_back(C);
			Semaphore=1;
			//i++;
		}

		if (dbKeyState(22)==1)
		{
			dbSprite(i,300,100,4);
			while (dbKeyState(22)==1 && Semaphore==0);
			C.setIdIm(i,4);
			Coords.push_back(C);
			Semaphore=1;
		}

		if (dbKeyState(23)==1)
		{
			dbSprite(i,400,100,2);
			while (dbKeyState(23)==1 && Semaphore==0);
			C.setIdIm(i,2);
			Coords.push_back(C);
			Semaphore=1;
		}

		if (dbKeyState(24)==1)
		{
			dbSprite(i,500,100,3);
			while (dbKeyState(24)==1 && Semaphore==0);
			C.setIdIm(i,3);
			Coords.push_back(C);
			Semaphore=1;
		}

		if (dbKeyState(25)==1)
		{
			dbSprite(i,600,100,7);
			while (dbKeyState(25)==1 && Semaphore==0);
			C.setIdIm(i,7);
			Coords.push_back(C);
			Semaphore=1;
		}
		
		// Sumar de uno en uno i
		if (dbKeyState(20)==0 && Semaphore==1 )
		{
			
			incI();
			Semaphore=0;
			//GenerarMapa();
			
		}
		
		if (dbKeyState(21)==0 && Semaphore==1)
		{
			
			incI();
			Semaphore=0;
		}

		if (dbKeyState(22)==0 && Semaphore==1)
		{
			incI();
			Semaphore=0;
		}

		if (dbKeyState(23)==0 && Semaphore==1)
		{
			incI();
			Semaphore=0;
		}

		if (dbKeyState(24)==0 && Semaphore==1)
		{
			incI();
			Semaphore=0;
		}

		if (dbKeyState(25)==0 && Semaphore==1)
		{
			incI();
			Semaphore=0;
		}
		
		if (dbMouseClick()==1)
		{
			int xm,ym;
			xm=dbMouseX();
			ym=dbMouseY();
			MoverSprite(xm,ym);
			
		}
		if (dbMouseClick()==2) //Eliminar un Sprite con Clic derecho
		{
			
			int xm,ym;
			xm=dbMouseX();
			ym=dbMouseY();
			//borrarSprite(xm,ym);
			
			//GenerarMapa();
		}
		
		if ( dbEscapeKey ( ) )
			break;

		dbSync ( );
	}

	
	for ( int j = 1; j <= i; j++ )
	{	
		dbDeleteSprite	( j );
		dbDeleteImage	( j );

	}
	return;
}

void MoverSprite(int iX,int iY)
{

	//Pareja en el vector First = Num Sprite Second = Num Image
	int Tmp=0;
	int ux,uy,lx,ly;
	for(;Tmp< (int) Coords.size();Tmp++)
	{
		ux = dbSpriteX(Coords.at(Tmp).getID())-dbSpriteOffsetX(Coords.at(Tmp).getID());
		uy = dbSpriteY(Coords.at(Tmp).getID())-dbSpriteOffsetY(Coords.at(Tmp).getID());
		lx = ux+dbSpriteWidth (Coords.at(Tmp).getID());
		ly = uy+dbSpriteHeight(Coords.at(Tmp).getID());
		dbOffsetSprite(Coords.at(Tmp).getID(),dbSpriteWidth (Coords.at(Tmp).getID())/2,dbSpriteHeight(Coords.at(Tmp).getID())/2);
		if (iX>=ux && iY >=uy       //Verifica si el mouse esta tocando la figura 
				&& iX <=lx && iY <=ly)
		{
			dbSprite(Coords.at(Tmp).getID(),iX,iY,Coords.at(Tmp).getIm());
			return;
		}
	}

}

void borrarSprite(int iX,int iY)
{
	int Tmp=0;
	int ux,uy,lx,ly;
	for(;Tmp< (int) Coords.size();Tmp++)
	{
		ux = dbSpriteX(Coords.at(Tmp).getID())-dbSpriteOffsetX(Coords.at(Tmp).getID());
		uy = dbSpriteY(Coords.at(Tmp).getID())-dbSpriteOffsetY(Coords.at(Tmp).getID());
		lx = ux+dbSpriteWidth (Coords.at(Tmp).getID());
		ly = uy+dbSpriteHeight(Coords.at(Tmp).getID());
		//dbOffsetSprite(Coords.at(Tmp).getID(),dbSpriteWidth (Coords.at(Tmp).getID())/2,dbSpriteHeight(Coords.at(Tmp).getID())/2);
		if (iX>=ux && iY >=uy       //Verifica si el mouse esta tocando la figura 
				&& iX <=lx && iY <=ly)
		{
			dbDeleteSprite(Coords.at(Tmp).getID());
			Coords.erase(Coords.begin()+Tmp);
			Coords.resize((int) Coords.size()-Tmp+1);
			return;
		}
	}

}

