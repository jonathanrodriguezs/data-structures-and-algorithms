// Separation of IEEE 754 Float 32 bits
// Author: Jonathan Rodriguez Sanchez
// - For the use of bitfields I have used the type "unsigned int" for compatibility. (shorturl.at/kstzN)
// - Exclusively for computers that uses LITTLE ENDIAN.

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Little endian: IEEE 754 32 bits float
union float_unmask_le {
  float single_float;
  struct {
    unsigned long mantissa: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
  }
  pack;
};

// Type definitions
typedef union float_unmask_le float_unmask_le;
// Function prototypes
float reverse_bytes_float(const float n);
void print_float_bytes(char * ptr);
bool is_little_endian(void);
void print_float_unmask(float_unmask_le s_float, char * formatter);
void print_header(char * header);
void print_results(float x, char * ptr);

int main(int argc, char * argv[]) {
  float x = 0.0;
  bool little_endian = is_little_endian();
  printf("Floating point number: ");
  scanf("%f", &x);
  
  char * ptr = (char * ) & x;

  if (little_endian) {
    print_results(x, ptr);
  } else {
    printf("Not compatible architecture");
    return 1;
  }

  return 0;
}

// Reverse the bytes of a single float in another buffer
float reverse_bytes_float(float n) {
  float reversed;
  char * float_ptr = (char * ) & n;
  char * reversed_ptr = (char * ) & reversed;

  // Swap the bytes into a temporary buffer
  reversed_ptr[0] = float_ptr[3];
  reversed_ptr[1] = float_ptr[2];
  reversed_ptr[2] = float_ptr[1];
  reversed_ptr[3] = float_ptr[0];

  return reversed;
}

// Print the four bytes in a single float in hex format
void print_float_bytes(char * ptr) {
  printf("%X ", (unsigned char) * ptr);
  printf("%X ", (unsigned char) * (ptr + 1));
  printf("%X ", (unsigned char) * (ptr + 2));
  printf("%X ", (unsigned char) * (ptr + 3));
}

// Print sign, exponent and mantissa of a 32 bits float
void print_float_unmask(float_unmask_le s_float, char * formatter) {
  printf("Sign: ");     printf(formatter, s_float.pack.sign);
  printf("Exponent: "); printf(formatter, s_float.pack.exponent);
  printf("Mantissa: ");  printf(formatter, s_float.pack.mantissa);
}

// Determine if the host uses little endian
bool is_little_endian(void) {
  int16_t i = 1;
  int8_t * p = (int8_t * ) & i;
  return (p[0] == 1);
}

// Cleaner prints
void print_header(char * header) {
  printf("\n\n* %s:\n", header);
}

// Print the results to stdout
void print_results(float x, char * ptr) {
  float reversed = reverse_bytes_float(x);
  char * ptr_r = (char * ) & reversed;
  float_unmask_le s_float = { .single_float = x };

  printf("Floating point number: %f", x);

  print_header("Bytes in physical order");
  print_float_bytes(ptr_r);

  print_header("Bytes in logical order");
  print_float_bytes(ptr);

  print_header("Float IEEE 754 32B (hex)");
  print_float_unmask(s_float, "%X \n");

  print_header("Float IEEE 754 32B (decimal)");
  print_float_unmask(s_float, "%d \n");
}
