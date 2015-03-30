/* index.c
 *
 * This module provides a data structure that denotes an index
 * which are morally 64 bits unsigned integers. Each index vale is related
 * to a descriptor using a hash table. A counter in the descriptor denotes
 * the number of refrences to it.
 *
 * For the moment, this descriptor is composed of a boolean which can
 * be used to globally invalidate an index during a computation.
 *
 */

#include "index.h"
#include "xboolean.h"
#include "xmalloc.h"
#include "cast.h"
#include "hashtable.h"

typedef struct index_descriptor_s {
  boolean_t     valid;
  unsigned int  ref_count;
} index_descriptor_t;

typedef struct index_implementation_s {
  index_descriptor_t* descriptor;
  uint64_t            value;
} index_implementation_t;

unsigned int index_hash (void* key) {
  DECLARE_AS (index_implementation_t*, idx, key);
  /* Here, we assume that [sizeof(unsigned int) = 4]. */
  return ((idx->value >> 32) + idx->value);
}

int index_compare (index_t lhs, index_t rhs) {
  DECLARE_AS (index_implementation_t*, idx_lhs, lhs);
  DECLARE_AS (index_implementation_t*, idx_rhs, rhs);
  if (idx_lhs->value == idx_rhs->value)
    return (0);
  else if (idx_lhs->value < idx_rhs->value)
    return (1);
  return (-1);
}

int index_equality (void* key1, void* key2) {
  return (index_compare (key1, key2) == 0);
}

static struct hashtable* descriptors;

void init_index_module () {
  descriptors = create_hashtable (16, index_hash, index_equality);
}

/* Allocate a data structure to hold a index stored using 64 bits.
  A unique descriptor [d] is associated to the integer [value]. If this
  is the first time the integer is requested, a new descriptor is allocated.
Otherwise, the previously descriptor is used.
 */

index_t index_create (uint64_t value) {
  /* Look for an associated descriptor, if it exists. */
  DECLARE_AS(index_descriptor_t*, descriptor, NULL);
  index_implementation_t* idx = xmalloc (index_implementation_t);
  idx->value = value;
  descriptor = hashtable_search (descriptors, idx);
  if (descriptor == NULL) {
    /* The boolean does not exist, create it. */
    descriptor = xmalloc (index_descriptor_t);
    descriptor->valid = TRUE;
    descriptor->ref_count = 1;
    hashtable_insert (descriptors, idx, descriptor);
  }
  idx->descriptor = descriptor;
  return (idx);
}

uint64_t index_value (index_t i) {
  DECLARE_AS (index_implementation_t*, idx, i);
  return (idx->value);
}

void index_release (index_t i) {
  DECLARE_AS (index_implementation_t*, idx, i);
  DECLARE_AS (index_descriptor_t*, descriptor,
              hashtable_search (descriptors, idx));
  /* At this point, [descriptor] cannot be NULL. */
  descriptor->ref_count--;
  if (descriptor->ref_count == 0) {
    hashtable_remove (descriptors, idx);
    free (descriptor);
  }
  free (idx);
}

boolean_t index_valid (index_t i) {
  DECLARE_AS (index_implementation_t*, idx, i);
  DECLARE_AS (index_descriptor_t*, descriptor,
              hashtable_search (descriptors, idx));
  /* At this point, [descriptor] cannot be NULL. */
  return (descriptor->valid);
}

void index_invalidate (index_t i) {
  DECLARE_A (index_implementation_t*, idx, i);
  DECLARE_AS (index_descriptor_t*, descriptor,
              hashtable_search (descriptors, idx));
  /* At this point, [descriptor] cannot be NULL. */
  descriptor->valid = FALSE;
}

void index_validate (index_t i) {
  DECLARE_AS (index_implementation_t*, idx, i);
  DECLARE_AS (index_descriptor_t*, descriptor,
              hashtable_search (descriptors, idx));
  /* At this point, [descriptor] cannot be NULL. */
  descriptor->valid = TRUE;
}
