/*
 * Copyright (C) 2022 Simon Josefsson
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appears in all copies and
 * that both that copyright notice and this permission notice appear in
 * supporting documentation, and that the name of OpenVision not be used
 * in advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission. OpenVision makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 * OPENVISION DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL OPENVISION BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
 * USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include <gssapi/gssapi.h>

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    gss_uint32      maj_stat,
                    min_stat,
                    msgctx;
    gss_buffer_desc bufdesc,
                    bufdesc2;
    gss_name_t      service;
    gss_OID_set     oids;
    int             n;
    int             errs = 0;

    /*
     * OID set tests
     */
    oids = GSS_C_NO_OID_SET;
    maj_stat = gss_create_empty_oid_set(&min_stat, &oids);
    if (maj_stat == GSS_S_COMPLETE)
	printf("PASS: gss_create_empty_oid_set\n");
    else
	errs++, printf("FAIL: gss_create_empty_oid_set (%u,%u)\n",
		       maj_stat, min_stat);

    /*
     * Test empty set
     */
    maj_stat = gss_test_oid_set_member(&min_stat, GSS_C_NT_USER_NAME,
				       oids, &n);
    if (maj_stat == GSS_S_COMPLETE)
	printf("PASS: gss_test_oid_set_member\n");
    else
	errs++, printf("FAIL: gss_test_oid_set_member (%u,%u)\n",
		       maj_stat, min_stat);

    if (n == 0)
	printf("PASS: gss_test_oid_set_member n==0\n");
    else
	errs++, printf("FAIL: gss_test_oid_set_member n=%d!=0", n);

    return errs == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
