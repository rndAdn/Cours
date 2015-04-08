#ifndef ASSOCIATIVE_TABLE_H

# include <stdlib.h>
# include "index.h"
# include "chunk.h"

typedef void* associative_table_t;

associative_table_t table_create ();

index_t fresh_table (associative_table_t table);

chunk_t table_assoc (associative_table_t table, index_t i, size_t s, uint8_t* data);

maybe_chunk_t table_lookup (associative_table_t table, index_t i);

void table_remove_assoc (associative_table_t table, index_t i);

#endif /* ! ASSOCIATIVE_TABLE_H */
