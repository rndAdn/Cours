#include <stdlib.h>
#include <string.h>
#include "associative_table.h"
#include "xmalloc.h"
#include "hashtable.h"
#include "cast.h"

typedef struct associative_table_implementation_s {
  uint32_t              identifier;
  struct hashtable*     data;
} associative_table_implementation_t;

associative_table_t table_create () {
  associative_table_implementation_t* table =
    xmalloc (associative_table_implementation_t);
  table->identifier = random () << 32;
  table->data = create_hashtable (16, index_hash, index_equality);
  return (table);
}

maybe_chunk_t table_lookup (associative_table_t t, index_t idx) {
  declare_as (associative_table_implementation_t*, table, t);
  chunk_t chunk = hashtable_search (table->data, idx);
  if (chunk == NULL) {
    return (chunk_none ());
  }
  return (chunk);
}

index_t fresh_table (associative_table_t t) {
  declare_as (associative_table_implementation_t*, table, t);
  index_t fresh_index = index_create ((uint32_t) random () + table->identifier);
  if (lookup (t, fresh_index) != chunk_none ())
    return (fresh (t));
  return (fresh_index);
}

chunk_t table_assoc (associative_table_t t, index_t i, size_t s, uint8_t* data) {
  declare_as (associative_table_implementation_t*, table, t);
  chunk_t chunk = chunk_create (s, i);
  memcpy (chunk_data (chunk), data, s);
  hashtable_insert (table->data, i, chunk);
  return (chunk);
}

void table_remove_assoc (associative_table_t t, index_t i) {
  declare_as (associative_table_implementation_t*, table, t);
  hashtable_remove (table->data, i);
}
