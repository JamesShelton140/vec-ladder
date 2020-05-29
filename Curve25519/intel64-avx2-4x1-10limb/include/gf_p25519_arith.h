/*
+-----------------------------------------------------------------------------+
| This code corresponds to the the paper "Efficient 4-way Vectorizations of   |
| the Montgomery Ladder" authored by   			       	       	      |
| Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and            |
| Palash Sarkar, Indian Statistical Institute, Kolkata, India.	              |
+-----------------------------------------------------------------------------+
| Copyright (c) 2020, Kaushik Nath and Palash Sarkar.                         |
|                                                                             |
| Permission to use this code is granted.                          	      |
|                                                                             |
| Redistribution and use in source and binary forms, with or without          |
| modification, are permitted provided that the following conditions are      |
| met:                                                                        |
|                                                                             |
| * Redistributions of source code must retain the above copyright notice,    |
|   this list of conditions and the following disclaimer.                     |
|                                                                             |
| * Redistributions in binary form must reproduce the above copyright         |
|   notice, this list of conditions and the following disclaimer in the       |
|   documentation and/or other materials provided with the distribution.      |
|                                                                             |
| * The names of the contributors may not be used to endorse or promote       |
|   products derived from this software without specific prior written        |
|   permission.                                                               |
+-----------------------------------------------------------------------------+
| THIS SOFTWARE IS PROVIDED BY THE AUTHORS ""AS IS"" AND ANY EXPRESS OR       |
| IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES   |
| OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.     |
| IN NO EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,      |
| INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT    |
| NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   |
| DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY       |
| THEORY LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING |
| NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,| 
| EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          |
+-----------------------------------------------------------------------------+
*/

#ifndef __P25519_ARITH_H__
#define __P25519_ARITH_H__

#include "basic_types.h"
#include "gf_p25519_type.h"

#define gfp25519sqr(x,y)  gfp25519nsqr(x,y,1)
#define gfp25519sqrx(x,y) gfp25519nsqrx(x,y,1)

extern void gfp25519mulx(gfe_p25519_4L *, const gfe_p25519_4L *, const gfe_p25519_4L *);
extern void gfp25519nsqrx(gfe_p25519_4L *, const gfe_p25519_4L *, const uchar8);
extern void gfp25519reducex(gfe_p25519_4L *);
extern void gfp25519mul(gfe_p25519_5L *, const gfe_p25519_5L *, const gfe_p25519_5L *);
extern void gfp25519nsqr(gfe_p25519_5L *, const gfe_p25519_5L *, const uchar8);
extern void gfp25519reduce(gfe_p25519_5L *);
extern void gfp25519makeunique(gfe_p25519_4L *);

void gfp25519inv(gfe_p25519_5L *, const gfe_p25519_5L *);
void gfp25519invx(gfe_p25519_4L *, const gfe_p25519_4L *);

#endif
