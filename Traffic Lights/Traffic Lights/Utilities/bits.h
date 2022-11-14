//
// Created by George Welson on 18-Oct-22.
//

#ifndef UNTITLED10_BITS_H
#define UNTITLED10_BITS_H
#define SET_BIT(byte,nbit)   ((byte) |= (1<<(nbit)))
#define CLEAR_BIT(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define TOGGLE_BIT(byte,nbit)  ((byte) ^= (1<<(nbit)))
#define CHECK_BIT(byte,nbit) (((byte) & (1<<(nbit)))>>nbit)
#endif //UNTITLED10_BITS_H
