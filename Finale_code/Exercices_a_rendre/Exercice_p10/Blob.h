#ifndef PRJ_BLOB_H
#define PRJ_BLOB_H

#include <vector>
#include <memory>
#include "Dessinable.h"
#include "Machin.h"


class Blob : public Dessinable
{
	public:
/*================================================================================
 * Prototyopes des constructeurs et destructeur
 *================================================================================*/
	Blob();
	~Blob();
	
/*================================================================================
 * Prototypes des methodes
 *================================================================================*/
 	void evolue(double dt);
	virtual void dessine() const;
	
/*================================================================================
 * Definition des attributs
 *================================================================================*/
	private:
	std::vector<Machin*>  collectionMachins;
};
#endif 
