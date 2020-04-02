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

#include <stdio.h>
#include <math.h>
#include "curve448.h"
#include "basic_types.h"
#include "gf_p4482241_type.h"
#include "measure.h"

#define change_input(x,y,z)  {x[0] = y[0]^z[0];}
#define FILE stdout

int main() {

	uchar8 i;

	uchar8 n[CRYPTO_BYTES] = {102, 66, 236, 240, 6, 149, 92, 7, 43, 107, 163, 255, 64, 145, 5, 203, 230, 54, 147, 234, 197, 5, 215, 214, 124, 189, 226, 219, 235, 71, 20, 20,102, 66, 236, 240, 6, 149, 92, 7, 43, 107, 163, 255, 64, 145, 5, 203, 230, 54, 147, 234, 197, 5, 215, 255};
	uchar8 p[CRYPTO_BYTES] = {0}; p[0] = 2;
	uchar8 np[CRYPTO_BYTES];

	// clamping
        n[CRYPTO_BYTES-1] = n[CRYPTO_BYTES-1] | 0x80;
	n[0] = n[0] & 0xFC;

	curve448_shared_secret(np,p,n);

	fprintf(FILE,"\n");
	for(i=0;i<CRYPTO_BYTES;++i) fprintf(FILE,"%4d", p[i]); fprintf(FILE,"\n\n");
	for(i=0;i<CRYPTO_BYTES;++i) fprintf(FILE,"%4d",np[i]); fprintf(FILE,"\n\n");

	fprintf(FILE,"Computing CPU-cycles. It will take some time. Please wait!\n\n");
	MEASURE_TIME({curve448_shared_secret(np,p,n);change_input(p,np,p);});
	fprintf(FILE,"CPU-cycles for shared secret computation of curve448 is %6.0lf.\n\n", ceil(((get_median())/(double)(N))));
	
	return 0;
}