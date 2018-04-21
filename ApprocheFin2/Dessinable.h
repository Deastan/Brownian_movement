/**
 * \file Dessinable.h
 * \brief est la super-classe avec une méthode dessine qui permet d'avoir une spécialisation pour chaque type d'objet
 * \author Emma Geoffray et Jonathan Burkhard
 * \version 1.0
 * \date avril 2014
 */

#ifndef PRJ_DESSINABLE_H
#define PRJ_DESSINABLE_H

class Dessinable
{
	public :
	///une méthode virtuelle pure car on veut qu'elle soit redéfinie dans toutes les sous-classes
	virtual void dessine() const = 0;
};

#endif // PRJ_DESSINABLE_H
