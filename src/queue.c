#include "queue.h"
#include "_queue.h"
#include "list.h"
#include "utils.h"

queue_ref
queue_create (void) {
	struct queue *self = Calloc (1, sizeof (struct queue));
	queue_init (self);
	object_retain (self);
	return self;
}

void
queue_init (queue_ref _self) {
	struct queue *self = _self;
	object_init (self);
	((struct object *)self)->object_dealloc = _object_dealloc_queue;
	self->list = list_create ();
}

void _object_dealloc_queue (object_ref _self) {
	struct queue *self = _self;
	object_release (self->list);
}

void
queue_push (queue_ref _self, object_ref obj) {
	struct queue *self = _self;
	list_add (self->list, obj);
}

void
queue_pop (queue_ref _self) {
	struct queue *self = _self;
	assert (list_count (self->list) > 0);
	list_remove (self->list, 0);
}

object_ref
queue_front (queue_ref _self) {
	struct queue *self = _self;
	return list_get (self->list, 0);
}