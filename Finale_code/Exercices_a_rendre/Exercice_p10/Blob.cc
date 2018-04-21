#include <iostream>
#include "Blob.h"
#include "Moucheron.h"
#include "H2O.h"


using namespace std;

/*================================================================================
 * Definition des constructeurs et destructeur
 *================================================================================*/
Blob::Blob()
{
	collectionMachins.push_back(new H2O());
	collectionMachins.push_back(new Moucheron(6.));
}

Blob::~Blob()
{

	for(size_t i(0);i<collectionMachins.size();i++)
	{
		//collectionMachins[i].reset();
		delete collectionMachins[i] ;
	}
}

void Blob::evolue(double dt)
{
	for(size_t i(0);i<collectionMachins.size();i++)
	{
		collectionMachins[i]->evolue(dt);
	}
}
	
void Blob::dessine() const
{   
	for(size_t i(0);i<collectionMachins.size();i++)
	{
		collectionMachins[i]->dessine();
	}
}
