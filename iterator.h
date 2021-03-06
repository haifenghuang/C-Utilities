#ifndef iterator_h
#define iterator_h

#include "types.h"

/***************
	ITERATOR
****************/
typedef void * iterator_ref;

// abstract class -- cannot be instantiated as there is not "create" method
object_ref iterator_next (iterator_ref); //virtual
bool iterator_has_next (iterator_ref); //virtual

// inherited from object
object_ref object_retain (object_ref);
void object_release (object_ref);
void object_dealloc (object_ref);
bool object_equals (object_ref, object_ref);
int object_hash (object_ref);


#endif