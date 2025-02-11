#pragma once
#include "types.h"

PACK(struct TEntry {
    U64 key;
    Score score;
    Move move;
    uint8_t depth;
    Flag flag;
});

extern TEntry *TTable;
extern U64 TT_SIZE;

/// @brief store an entry in the TT
/// @param depth
/// @param bestvalue
/// @param b Type of bound
/// @param key Position hash
/// @param move
void storeEntry(int depth, Score bestvalue, Flag b, U64 key, Move move);

/// @brief probe the TT for an entry
/// @param tte
/// @param ttHit
/// @param key Position hash
void probeTT(TEntry &tte, bool &ttHit, Move &ttmove, U64 key);

/// @brief calculates the TT index of key
/// @param key
/// @return
uint32_t ttIndex(U64 key);