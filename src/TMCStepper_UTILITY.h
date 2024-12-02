#ifndef TMCStepper_UTILITY_h
#define TMCStepper_UTILITY_h

void print_HEX(uint32_t data) {
  for(uint8_t B=24; B>=4; B-=8){
    printf("%X%X:", (data >> (B + 4)) & 0xF, (data >> B) & 0xF);
  }
  printf("%X%X\n", (data >> 4) & 0xF, data & 0xF);
}

void print_BIN(uint32_t data) {
  int b = 31;
  for(; b>=24; b--){
    printf("%d", (data >> b) & 0b1);
  }
  printf(".");
  for(; b>=16; b--){
    printf("%d", (data >> b) & 0b1);
  }
  printf(".");
  for(; b>=8; b--){
    printf("%d", (data >> b) & 0b1);
  }
  printf(".");
  for(; b>=0; b--){
    printf("%d", (data >> b) & 0b1);
  }
  printf("\n");
}

#endif
