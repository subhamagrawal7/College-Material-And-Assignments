#define MaxSeq  3   /* window size */
#define Wrong(x)    x = (x+1) % (MaxSeq)
#define Right(x)    x = (x+1) % (MaxSeq + 1)
#define inc(x)      Right(x)
    /* file ex.9 */
chan q[2] = [MaxSeq] of { byte, byte }; /* message passing channel */

active [2] proctype p5()    /* starts two copies of proctype p5 */
{   byte    NextFrame, AckExp, FrameExp, r, s, nbuf, i;
    chan    in, out;
    in  = q[_pid];
    out = q[1-_pid];
    xr in; xs out;      /* partial order reduction claims */

    do
    :: nbuf < MaxSeq -> /* outgoing messages */
        nbuf++;
        out!NextFrame , (FrameExp + MaxSeq) % (MaxSeq + 1);
        inc(NextFrame)

    :: q[_pid]?r,s ->   /* incoming messages */
        if
        :: r == FrameExp ->
            printf("MSC: accept %d\n", r);
            inc(FrameExp)
        :: else /* ignore message */
        fi;
        do
        :: ((AckExp <= s) && (s <  NextFrame)) || ((AckExp <= s) && (NextFrame <  AckExp)) || ((s <  NextFrame) && (NextFrame <  AckExp)) ->
            nbuf--;
            inc(AckExp)
        :: else -> break
        od

    :: timeout ->       /* retransmission timeout */
        NextFrame = AckExp;
        printf("MSC: timeout\n");
        i = 1;
        do
        :: i <= nbuf ->
            out!NextFrame , (FrameExp + MaxSeq) % (MaxSeq + 1);
            inc(NextFrame);
            i++
        :: else -> break
        od
    od
}
