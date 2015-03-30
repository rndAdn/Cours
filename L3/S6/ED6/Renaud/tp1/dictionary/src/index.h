#ifndef INDEX_H
# define INDEX_H

/* This module provides a type for [index] and operations over this type.
 *
 * An index is morally related to a very big integer.
 *
 * The data structure also implements a predicate called [valid]
 * over these integers.
 *
 * The user can invalidate or validate a particular index.
 *
 * In the following, we say that an index is [sound] if it has been
 * created by this module and that is has not been released.
 */

# include <stdint.h>
# include "xboolean.h"

typedef void* index_t;

/* Assuming that [idx] is sound, this function returns a boolean
 * that denotes the validity of the index. */
boolean_t index_valid (index_t idx);

/* If [idx] is sound, this function turns the predicate [valid] to false
 * for the value of [idx]. */
void index_invalidate (index_t idx);

/* If [idx] is sound, this function turns the predicate [valid] to true
 * for the value of [idx]. */
void index_validate (index_t idx);

/* Returns the unsigned 64-bits integer related to [idx].
 * This function expects the index to be sound. */
uint64_t index_value (index_t idx);

/* A hashing function over indexes.
 * The index is expected to be sound. */
unsigned int index_hash (index_t idx);

/* We can decide if two indexes are equal.
 * The index is expected to be sound. */
int index_equality (index_t lhs, index_t rhs);

/* Allocate a data structure to hold a index stored using 64 bits.
  A unique descriptor [d] is associated to the integer [value]. If this
  is the first time the integer is requested, a new descriptor is allocated.
  Otherwise, the previously descriptor is used.
 */
index_t index_create (uint64_t value);

void index_release (index_t i);

int index_compare (index_t lhs, index_t rhs);

#endif /* ! INDEX_H */
