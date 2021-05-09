mtype = { msg, ack };

chan to_sndr = [2] of { mtype, bit };
chan to_rcvr = [2] of { mtype, bit };

active proctype Sender ()
{   bit seq_out=1, seq_in;

    do
    ::  to_rcvr!msg (seq_out) ->
        do
        :: to_sndr?ack (seq_in) ->
            if
            :: seq_in == seq_out ->
                seq_out = !seq_out
            :: else -> skip
            fi;
            break
        :: to_sndr?ack (seq_in) ->
            skip        /* Message loss */
        od
    od
}

active proctype Receiver ()
{   bit seq_in, lost;

    do
    :: to_rcvr?msg (seq_in) ->
        to_sndr!ack (seq_in)
    :: to_rcvr?msg (lost) ->
        skip            /* Message loss */
    :: timeout ->           /* Recover from message loss */
        to_sndr!ack (seq_in)
    od
}
