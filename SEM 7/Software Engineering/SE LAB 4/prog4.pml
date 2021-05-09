#define SIZE 5
chan c = [6] of {byte};
chan d = [true] of {bool};
byte fullness = 0;
active proctype producer() {
    byte data;
    do
    :: fullness < SIZE -> fullness = fullness + 1; 
                          c ! data; 
                          data++;
                          printf("item produced\n")
    :: d ? true;
    od
}
active proctype consumer() {
    byte data;
    do
    :: c?data; fullness = fullness - 1; d != true; printf("item consumed\n")
    od
}
active proctype monitor() {
    assert (fullness <= SIZE);
}