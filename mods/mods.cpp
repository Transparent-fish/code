#define gc()                                                              \
  p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2) \
      ? EOF                                                               \
      : *p1++
char buf[1 << 20], *p1 = buf, *p2 = buf, sr[1 << 23], z[23], nc;
int C = -1, Z = 0;
template <typename T>
inline void read(T& x) {
  bool flag = false;
  while (nc = gc(), (nc < 48 || nc > 57) && nc != -1) flag |= (nc == 45);
  x = nc - 48;
  while (nc = gc(), 47 < nc && nc < 58) x = (x << 3) + (x << 1) + (nc ^ 48);
  if (flag) x = -x;
}
template <typename T, typename... Args_Arrays_Typename_KevinZ99>
void read(T& x, Args_Arrays_Typename_KevinZ99&... a) {
  read(x);
  read(a...);
}
inline void ot() {
  fwrite(sr, 1, C + 1, stdout);
  C = -1;
}
inline void flush() {
  if (C > 1 << 22) ot();
}
template <typename T>
inline void write(T x, char t) {
  int y = 0;
  if (x < 0) y = 1, x = -x;
  while (z[++Z] = x % 10 + 48, x /= 10);
  if (y) z[++Z] = '-';
  while (sr[++C] = z[Z], --Z);
  sr[++C] = t;
  flush();
}
