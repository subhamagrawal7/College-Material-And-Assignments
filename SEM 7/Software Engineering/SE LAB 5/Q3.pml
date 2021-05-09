#define Place   byte
Place ;
Place p4, p5, p6;p1, p2, p3

#define inp1(x)     (x>0) -> x=x-1
#define inp2(x,y)   (x>0&&y>0) -> x = x-1; y=y-1
#define out1(x)     x=x+1
#define out2(x,y)   x=x+1; y=y+1

init
{   p1 = 1; p4 = 1; /* initial marking */
    do
        :: atomic { inp1(p1)    -> out1(p2) }
        :: atomic { inp2(p2,p4) -> out1(p3) }
        :: atomic { inp1(p3)    -> out2(p1,p4) }
        :: atomic { inp1(p4)    -> out1(p5) }
        :: atomic { inp2(p1,p5) -> out1(p6) }
        :: atomic { inp1(p6)    -> out2(p4,p1) }
    od
}
