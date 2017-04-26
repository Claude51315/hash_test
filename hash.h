#ifndef HASH_H
#define HASH_H

int crc32_hash (char *in_buf, int in_len, char *out_buf, int out_len);
int md5_hash (char *in_buf, int in_len, char *out_buf, int out_len);
int adler_hash(char *in_buf, int in_len, char *out_buf, int out_len);
int sha1_hash(char *in_buf, int in_len, char *out_buf, int out_len);

#endif
