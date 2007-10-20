// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h
//
// This file was originally written by ZDimitor.

//----------------------------------------------------------------------
//  somefuncs.h -  part of the My3D Tools
//
//  This tool was created by Zhuck Dmitry (ZDimitor).
//  Everyone can use it as wants ( i'll be happy if it helps to someone :) ).
//----------------------------------------------------------------------

//**********************************************************************
//                      some useful functions
//**********************************************************************

#ifndef __C_MY3D_HELPER_H_INCLUDED__
#define __C_MY3D_HELPER_H_INCLUDED__

//--------------------------------------------------------------------------------
namespace irr
{
namespace core
{

//-----------------RLE stuff-----------------------------------------

int rle_encode (
    unsigned char *in_buf,  int in_buf_size,
    unsigned char *out_buf, int out_buf_size
    );
unsigned long process_comp(
    unsigned char *buf, int buf_size,
    unsigned char *out_buf, int out_buf_size
    );
void process_uncomp(
    unsigned char, unsigned char *out_buf, int out_buf_size
    );
void flush_outbuf(
    unsigned char *out_buf, int out_buf_size
    );
unsigned long get_byte (
    unsigned char *ch,
    unsigned char *in_buf, int in_buf_size,
    unsigned char *out_buf, int out_buf_size
    );
void put_byte(
    unsigned char  ch, unsigned char *out_buf, int out_buf_size
    );
//-----------------------------------------------------------
const unsigned long LIMIT = 1; // was #define LIMIT     1
const unsigned long NON_MATCH = 2; // was: #define NON_MATCH 2
const unsigned long EOD_FOUND = 3; // was: #define EOD_FOUND 3
const unsigned long EOD = 0x00454f44; // was: #define EOD       'EOD'
//-----------------------------------------------------------
// number of decoded bytes
int nDecodedBytes=0;
// number of coded bytes
int nCodedBytes=0;
// number of read bytes
int nReadedBytes=0;
// table used to look for sequences of repeating bytes
unsigned char tmpbuf[4];  // we use subscripts 1 - 3
int tmpbuf_cnt;
// output buffer for non-compressed output data
unsigned char outbuf[128];
int outbuf_cnt;


//-----------------------------------------------------------
int rle_encode (
    unsigned char *in_buf,  int in_buf_size,
    unsigned char *out_buf, int out_buf_size
    )
{
    unsigned long ret_code;

    unsigned char ch;

    nCodedBytes=0;
    nReadedBytes=0;

    tmpbuf_cnt = 0;  // no. of char's in tmpbuf
    outbuf_cnt = 0;  // no. of char's in outbuf
    while (1)
    {
        if (get_byte(&ch, in_buf, in_buf_size,
             out_buf, out_buf_size) == (int)EOD)  // read next byte into ch
           break;

        tmpbuf[++tmpbuf_cnt] = (unsigned char) ch;
        if (tmpbuf_cnt == 3)
        {
            // see if all 3 match each other
            if ((tmpbuf[1] == tmpbuf[2]) && (tmpbuf[2] == tmpbuf[3]))
            {
                // they do - add compression
                // this will process all bytes in input file until
                // a non-match occurs, or 128 bytes are processed,
                // or we find eod */
                ret_code = process_comp(in_buf, in_buf_size, out_buf, out_buf_size);
                if (ret_code == (int)EOD_FOUND)
                    break;        // stop compressing
                if (ret_code == (int)NON_MATCH)
                    tmpbuf_cnt=1; /* save the char that didn't match */
                else
                    // we just compressed the max. of 128 bytes
                    tmpbuf_cnt=0;    /* start over for next chunk */
            }
            else
            {
                // we know the first byte doesn't match 2 or more
                //  others, so just send it out as uncompressed. */
                process_uncomp(tmpbuf[1], out_buf, out_buf_size);

                // see if the last 2 bytes in the buffer match
                if (tmpbuf[2] == tmpbuf[3])
                {
                    // move byte 3 to position 1 and pretend we just
                    // have 2 bytes -- note that the first byte was
                    // already sent to output */
                    tmpbuf[1]=tmpbuf[3];
                    tmpbuf_cnt=2;
                }
                else
                {
                    // send byte 2 and keep byte 3 - it may match the
                    // next byte.  Move byte 3 to position 1 and set
                    // count to 1.  Note that the first byte was
                    // already sent to output
                    process_uncomp(tmpbuf[2], out_buf, out_buf_size);
                    tmpbuf[1]=tmpbuf[3];
                    tmpbuf_cnt=1;
                }
            }
        }
    }  // end while
    flush_outbuf(out_buf, out_buf_size);

    return nCodedBytes;
}


//------------------------------------------------------------------
// This flushes any non-compressed data not yet sent, then it processes
// repeating bytes until > 128, or EOD, or non-match.
//      return values: LIMIT, EOD_FOUND, NON_MATCH
// Prior to ANY return, it writes out the 2 byte compressed code.
// If a NON_MATCH was found, this returns with the non-matching char
// residing in tmpbuf[0].
//      Inputs: tmpbuf[0], input file
//      Outputs: tmpbuf[0] (sometimes), output file, and return code
//------------------------------------------------------------------
unsigned long process_comp(
    unsigned char *buf, int buf_size,
    unsigned char *out_buf, int out_buf_size)
{
     // we start out with 3 repeating bytes
     register int len = 3;

     unsigned char ch;

     // we're starting a repeating chunk - end the non-repeaters
     flush_outbuf(out_buf, out_buf_size);

     while (get_byte(&ch, buf, buf_size, out_buf, out_buf_size) != (int)EOD)
     {
        if (ch != tmpbuf[1])
        {
            // send no. of repeated bytes to be encoded
            put_byte((unsigned char)((--len) | 0x80), out_buf, out_buf_size);
            // send the byte's value being repeated
            put_byte((unsigned char)tmpbuf[1], out_buf, out_buf_size);
            /* save the non-matching character just read */
            tmpbuf[1]=(unsigned char) ch;
            return NON_MATCH;
        }
        /* we know the new byte is part of the repeating seq */
        len++;
        if (len == 128)
        {
            // send no. of repeated bytes to be encoded
            put_byte((unsigned char)((--len) | 0x80), out_buf, out_buf_size);
            // send the byte's value being repeated
            put_byte((unsigned char)tmpbuf[1], out_buf, out_buf_size);
            return LIMIT;
        }
    } // end while

    // if flow comes here, we just read an EOD
    // send no. of repeated bytes to be encoded
    put_byte((unsigned char)((--len) | 0x80), out_buf, out_buf_size);
    // send the byte's value being repeated
    put_byte((unsigned char)tmpbuf[1], out_buf, out_buf_size);
    return EOD_FOUND;
}


//----------------------------------------------------------------
// This adds 1 non-repeating byte to outbuf. If outbuf becomes full
// with 128 bytes, it flushes outbuf.
// There are no return codes and no bytes are read from the input.
//----------------------------------------------------------------
void process_uncomp(
    unsigned char char1, unsigned char *out_buf, int out_buf_size
    )
{
    outbuf[outbuf_cnt++] = char1;
    if (outbuf_cnt == 128)
       flush_outbuf(out_buf, out_buf_size);
}
//-----------------------------------------------------------
// This flushes any non-compressed data not yet sent.
// On exit, outbuf_cnt will equal zero.
//-----------------------------------------------------------
void flush_outbuf(unsigned char *out_buf, int out_buf_size)
{
    register int pos=0;

    if(!outbuf_cnt)
       return;        // nothing to do */

    // send no. of unencoded bytes to be sent
    put_byte((unsigned char)(outbuf_cnt - 1), out_buf, out_buf_size);

    for ( ; outbuf_cnt; outbuf_cnt--)
       put_byte((unsigned char)outbuf[pos++], out_buf, out_buf_size);
}
//---------------------------------------------------
void put_byte(unsigned char ch, unsigned char *out_buf, int out_buf_size)
{
    if (nCodedBytes<=(out_buf_size-1))
    {   out_buf[nCodedBytes++]=ch;
        out_buf[nCodedBytes]=0;
    }
}
//---------------------------------------------------
// This reads the next byte into ch.  It returns EOD
// at end-of-data
//---------------------------------------------------
unsigned long get_byte(
    unsigned char *ch,
    unsigned char *in_buf, int in_buf_size,
    unsigned char *out_buf, int out_buf_size
    )
{
    if (nReadedBytes>=in_buf_size)
    {
        // there are either 0, 1, or 2 char's to write before we quit
        if (tmpbuf_cnt == 1)
            process_uncomp(tmpbuf[1], out_buf, out_buf_size);
        else
        {
            if (tmpbuf_cnt == 2)
            {
                process_uncomp(tmpbuf[1], out_buf, out_buf_size);
                process_uncomp(tmpbuf[2], out_buf, out_buf_size);
            }
        }
        nReadedBytes =0;

        return EOD;
    }

    (*ch) = (unsigned char)in_buf[nReadedBytes++];

    return 0;
}
//-----------------------------------------------------------
int rle_decode (
    unsigned char *in_buf,  int in_buf_size,
    unsigned char *out_buf, int out_buf_size
    )
{
    nDecodedBytes=0;
    nReadedBytes=0;

    int ch, i;
    while (1)
    {

        if (nReadedBytes>=in_buf_size)
            break;
        else
            ch=in_buf[nReadedBytes];
        nReadedBytes++;

        if (ch > 127)
        {
            i = ch - 127;   // i is the number of repetitions
            // get the byte to be repeated
            if (nReadedBytes>=in_buf_size)
                break;
            else
                ch=in_buf[nReadedBytes];
            nReadedBytes++;

            // uncompress a chunk
            for ( ; i ; i--)
            {
                if (nDecodedBytes<out_buf_size)
                    out_buf[nDecodedBytes] = ch;
                nDecodedBytes++;
            }
        }
        else
        {
            // copy out some uncompressed bytes
            i = ch + 1;     // i is the no. of bytes
            // uncompress a chunk
            for ( ; i ; i--)
            {
                if (nReadedBytes>=in_buf_size)
                    break;
                else
                    ch=in_buf[nReadedBytes];
                nReadedBytes++;

                if (nDecodedBytes<out_buf_size)
                    out_buf[nDecodedBytes] = ch;
                nDecodedBytes++;
            }
        }
    } // end while

    return nDecodedBytes;
}

} //end namespace core
} //end namespace irr


#endif // __C_MY3D_HELPER_H_INCLUDED__

