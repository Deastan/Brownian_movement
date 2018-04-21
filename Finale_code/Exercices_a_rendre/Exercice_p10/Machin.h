#ifndef PRJ_MACHIN_H
#define PRJ_MACHIN_H

#include "Dessinable.h"


class Machin : public Dessinable
{
	public:
	virtual void evolue(double dt) = 0;
};

#endif 
