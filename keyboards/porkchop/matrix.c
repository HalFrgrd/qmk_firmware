/*
Copyright 2012 Jun Wako
Copyright 2014 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#if defined(__AVR__)
#include <avr/io.h>
#endif
#include "wait.h"
#include "print.h"
#include <print.h>
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "timer.h"


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

  #define BYTE_TO_BINARY_PATTERN32 "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
  #define BYTE_TO_BINARY32(byte32)  \
  (byte32 & 0x80000000 ? '1' : '0'), \
  (byte32 & 0x40000000 ? '1' : '0'), \
  (byte32 & 0x20000000 ? '1' : '0'), \
  (byte32 & 0x10000000 ? '1' : '0'), \
  (byte32 & 0x8000000 ? '1' : '0'), \
  (byte32 & 0x4000000 ? '1' : '0'), \
  (byte32 & 0x2000000 ? '1' : '0'), \
  (byte32 & 0x1000000 ? '1' : '0'), \
  (byte32 & 0x800000 ? '1' : '0'), \
  (byte32 & 0x400000 ? '1' : '0'), \
  (byte32 & 0x200000 ? '1' : '0'), \
  (byte32 & 0x100000 ? '1' : '0'), \
  (byte32 & 0x80000 ? '1' : '0'), \
  (byte32 & 0x40000 ? '1' : '0'), \
  (byte32 & 0x20000 ? '1' : '0'), \
  (byte32 & 0x10000 ? '1' : '0'), \
  (byte32 & 0x8000 ? '1' : '0'), \
  (byte32 & 0x4000 ? '1' : '0'), \
  (byte32 & 0x2000 ? '1' : '0'), \
  (byte32 & 0x1000 ? '1' : '0'), \
  (byte32 & 0x800 ? '1' : '0'), \
  (byte32 & 0x400 ? '1' : '0'), \
  (byte32 & 0x200 ? '1' : '0'), \
  (byte32 & 0x100 ? '1' : '0'), \
  (byte32 & 0x80 ? '1' : '0'), \
  (byte32 & 0x40 ? '1' : '0'), \
  (byte32 & 0x20 ? '1' : '0'), \
  (byte32 & 0x10 ? '1' : '0'), \
  (byte32 & 0x08 ? '1' : '0'), \
  (byte32 & 0x04 ? '1' : '0'), \
  (byte32 & 0x02 ? '1' : '0'), \
  (byte32 & 0x01 ? '1' : '0')

  #define BYTE_TO_BINARY_PATTERN16 "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
  #define BYTE_TO_BINARY16(byte16)  \
  (byte16 & 0x8000 ? '1' : '0'), \
  (byte16 & 0x4000 ? '1' : '0'), \
  (byte16 & 0x2000 ? '1' : '0'), \
  (byte16 & 0x1000 ? '1' : '0'), \
  (byte16 & 0x800 ? '1' : '0'), \
  (byte16 & 0x400 ? '1' : '0'), \
  (byte16 & 0x200 ? '1' : '0'), \
  (byte16 & 0x100 ? '1' : '0'), \
  (byte16 & 0x80 ? '1' : '0'), \
  (byte16 & 0x40 ? '1' : '0'), \
  (byte16 & 0x20 ? '1' : '0'), \
  (byte16 & 0x10 ? '1' : '0'), \
  (byte16 & 0x08 ? '1' : '0'), \
  (byte16 & 0x04 ? '1' : '0'), \
  (byte16 & 0x02 ? '1' : '0'), \
  (byte16 & 0x01 ? '1' : '0')

#if (MATRIX_COLS <= 8)
#    define print_matrix_header()  print("\nr/c 01234567\n")
#    define print_matrix_row(row)  print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop32(matrix[i])
#    define ROW_SHIFTER  ((uint32_t)1)
#endif

struct PinMap {
    uint8_t pin;
    uint8_t row;
    uint8_t col;
};

//pin 13 maps to position 0,1 in the matrix

/*
struct PinMap kb_1_mappings[19] = { {9,0,0},\
        {13,0,1},\
        {17,0,2},\
        {18,0,3},\
        {19,0,4},\
        {23,1,0},\
        {21,1,1},\
        {22,1,2},\
        {28,1,3},\
        {30,1,4},\
        {1,2,0},\
        {3,2,1},\
        {4,2,2},\
        {2,2,3},\
        {0,2,4},\
        {5,3,1},\
        {6,3,2},\
        {8,3,3},\
        {10,3,4}};

struct PinMap kb_2_mappings[19] = { {0,0,9},\
        {29,0,8},\
        {23,0,7},\
        {21,0,6},\
        {22,0,5},\
        {17,1,9},\
        {18,1,8},\
        {19,1,7},\
        {14,1,6},\
        {10,1,5},\
        {8,2,9},\
        {6,2,8},\
        {5,2,7},\
        {7,2,6},\
        {9,2,5},\
        {4,3,8},\
        {3,3,7},\
        {1,3,6},\
        {30,3,5}};


*/

struct PinMap kb_1_mappings[19] = { {30,0,0},\
        {22,0,1},\
        {21,0,2},\
        {18,0,3},\
        {19,0,4},\
        {4,1,0},\
        {3,1,1},\
        {17,1,2},\
        {10,1,3},\
        {8,1,4},\
        {2,2,0},\
        {0,2,1},\
        {29,2,2},\
        {5,2,3},\
        {6,2,4},\
        {23,3,1},\
        {13,3,2},\
        {9,3,3},\
        {7,3,4}};

struct PinMap kb_2_mappings[19] = { {10,0,9},\
        {19,0,8},\
        {18,0,7},\
        {21,0,6},\
        {22,0,5},\
        {5,1,9},\
        {6,1,8},\
        {23,1,7},\
        {30,1,6},\
        {1,1,5},\
        {7,2,9},\
        {9,2,8},\
        {13,2,7},\
        {4,2,6},\
        {3,2,5},\
        {17,3,8},\
        {29,3,7},\
        {0,3,6},\
        {2,3,5}};
        




/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];


__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

inline
uint8_t matrix_rows(void) {
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void) {
    return MATRIX_COLS;
}

void mypause(uint16_t t){
    uint16_t key_timer = timer_read();
    while(timer_elapsed(key_timer) < t){}
}

void matrix_init(void) {
    debug_enable = true;
    debug_matrix = true;
    debug_mouse = true;
    matrix_init_quantum();
}


uint8_t c;

uint8_t matrix_scan(void)
{

    //the s character requests the RF slave to send the matrix
    SERIAL_UART_INIT();

    uint32_t timeout = 0;

    //the s character requests the RF slave to send the matrix
    SERIAL_UART_DATA = 's';

    //trust the external keystates entirely, erase the last data
    uint8_t uart_data[18] = {0};


    for (uint8_t i = 0; i < 11; i++) {
        //wait for the serial data, timeout if it's been too long
        //this only happened in testing with a loose wire, but does no
        //harm to leave it in here

        while(!SERIAL_UART_RXD_PRESENT){
            timeout++;
            if (timeout > 1000000){
                //xprintf("Timeout has occured with i = %d\n", i);
                break;
            }
        }
        uart_data[i] = SERIAL_UART_DATA;
        //xprintf("Loop %d with uart data %d \n", i, uart_data[i]);
    }

    // print("HELLO:  \n");
    // for (int k = 0; k < 11; k++) {
    //     xprintf("%d    %d \n", k, uart_data[k]);
    // }

    //xprintf("Final piece of data: %d \n", uart_data[10]);

    if(uart_data[10] != 0xE0){
        //print("UNSUCCESSFULL");
        for (int j = 0; j < MATRIX_ROWS; j++) {
            matrix[j] = 0;
        }
    }

    //check for the end packet, the key state bytes use the LSBs, so 0xE0
    //will only show up here if the correct bytes were recieved
    if (uart_data[10] == 0xE0)
    {
        //clear matrix
        for (int j = 0; j < MATRIX_ROWS; j++) {
            matrix[j] = 0;
        }


        uint32_t keys_1 = ( (uint32_t) uart_data[1] << 24)  | \
                        ( (uint32_t) uart_data[2] << 16)  | \
                        ( (uint32_t) uart_data[3] << 8)   | \
                        ( (uint32_t) uart_data[4] << 0) ;

        uint32_t keys_2 = ( (uint32_t) uart_data[6] << 24)  | \
                        ( (uint32_t) uart_data[7] << 16)  | \
                        ( (uint32_t) uart_data[8] << 8)   | \
                        ( (uint32_t) uart_data[9] << 0) ;

        // print("SUCCESS TRANSFER\n");
        // print("01234567012345670123456701234567\n");
        // xprintf(BYTE_TO_BINARY_PATTERN32, BYTE_TO_BINARY32(keys_1));
        // xprintf(BYTE_TO_BINARY_PATTERN32, BYTE_TO_BINARY32(keys_2));
        // print("\n");
        //shifting and transferring the keystates to the QMK matrix variable
        for(int i = 0; i < 19; i++){
            struct PinMap temp = kb_1_mappings[i];
            //xprintf("Dealing with: pin %d, row %d, col %d. \n", temp.pin, temp.row, temp.col);
            //xprintf("%d\n", (keys >> temp.pin) & 1);
            if( (keys_1 >> temp.pin) & 1){
                // xprintf("Success and changing row to: \n");
                // print("0123456789ABCDEF\n");
                // xprintf(BYTE_TO_BINARY_PATTERN16, BYTE_TO_BINARY16((1L << temp.col)) );
                // print("\n");
                matrix[temp.row] |= (1L << temp.col);
                //xprintf("%d", matrix[temp.row]);
            }
        }

        for(int i = 0; i < 19; i++){
            struct PinMap temp = kb_2_mappings[i];
            //xprintf("Dealing with: pin %d, row %d, col %d. \n", temp.pin, temp.row, temp.col);
            //xprintf("%d\n", (keys >> temp.pin) & 1);
            if( (keys_2 >> temp.pin) & 1){
                // xprintf("Success and changing row to: \n");
                // print("0123456789ABCDEF\n");
                // xprintf(BYTE_TO_BINARY_PATTERN16, BYTE_TO_BINARY16((1L << temp.col)) );
                // print("\n");
                matrix[temp.row] |= (1L << temp.col);
                //xprintf("%d", matrix[temp.row]);
            }
        }

    }

    // print("THIS IS MATRIX \n");
    // matrix_print();

    matrix_scan_quantum();
    return 1;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        print_matrix_row(row);
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += matrix_bitpop(i);
    }
    return count;
}
