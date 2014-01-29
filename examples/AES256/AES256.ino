#include "aes256.h" //Include library files
#define DUMP(str, i, buf, sz) { Serial.println(str); \
                               for(i=0; i<(sz); ++i) { if(buf[i]<0x10) Serial.print('0'); Serial.print(char(buf[i]), HEX); } \
                               Serial.println(); } //Help function for printing the Output

aes256_context ctxt;

void setup() {
  int i;
  Serial.begin(19200);
  
  Serial.println("Initializing AES256... ");
  uint8_t key[] = { //
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
  };
  DUMP("Key: ", i, key, sizeof(key));
  aes256_init(&ctxt, key);
  
  uint8_t data[] = { //"asdfasdfasdfasdf"
    0x61, 0x73, 0x64, 0x66, 0x61, 0x73, 0x64, 0x66,
    0x61, 0x73, 0x64, 0x66, 0x61, 0x73, 0x64, 0x66
  };
  DUMP("Unencrypted data: ", i, data, sizeof(data));
  
  aes256_encrypt_ecb(&ctxt, data);
  DUMP("Encrypted data: ", i, data, sizeof(data));
  
  aes256_decrypt_ecb(&ctxt, data);
  DUMP("Back decrypted data: ", i, data, sizeof(data));
  
  aes256_done(&ctxt);
}

void loop() {
}
