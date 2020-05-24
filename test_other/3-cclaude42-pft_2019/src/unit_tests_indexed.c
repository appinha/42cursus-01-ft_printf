/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <gfielder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/11/19 18:06:44 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winteger-overflow"
#pragma clang diagnostic ignored "-Wformat"

#include "test.h"

/* -----------------------------------------------------------------------------
** Add unit tests to this file
**
** A valid unit test is prototyped
**
**    int   foo(void)
**
** and includes a call to the function:
**
**    int    ft_printf(const char *fmt, ...)
**
** ---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
** unit tests that start with "nocrash_" will always pass
**     (provided it doesn't crash)
** ---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
** A unit test is ENABLED if it has no whitespace preceding it
** A unit test is DISABLED if it has whitespace preceding it
**
** scripts are provided to enable and disable tests by prefix
** ---------------------------------------------------------------------------*/


//Tests with no specifiers
int		nospec_no_specifier_test(void){return ft_printf("hello, world!");}
int		nospec_empty_string(void){return ft_printf("");}
int		nospec_some_escaped_chars(void){return ft_printf("\t\n\r\v\f\n");}

//Nospec tests with successive calls
int		nospec_successive_5_5(void){return ( ft_printf("hello") + ft_printf("world"));}
int		nospec_successive_2_9(void){return ( ft_printf("he") ^ ft_printf(" is alive"));}
int		nospec_successive_8_3(void){return ( ft_printf("is alive") - ft_printf(" he"));}

//%% Tests
int		pct_basic(void){return ft_printf("%%");}
int		pct_5w(void){return ft_printf("%5%");}
int		pct_5wlj(void){return ft_printf("%-5%");}
int		pct_5wzp(void){return ft_printf("%05%");}
int		pct_5wljzp(void){return ft_printf("%-05%");}

//Null specifier tests
int		nocrash_nullspec_basic(void){return ft_printf("%");}
int		nocrash_nullspec_5w(void){return ft_printf("%5");}
int		nocrash_nullspec_5wzp(void){return ft_printf("%05");}
int		nocrash_nullspec_5wzplj(void){return ft_printf("%-05");}
int		nocrash_nullspec_5wlj(void){return ft_printf("%-5");}

//String specifiers - no modifiers
int s_basic_string_expansion(void){return ft_printf("hello, %s.", "gavin");}
int s_only_string_expansion(void){return ft_printf("%s", "testing testing");}
int s_two_string_expansions(void){return ft_printf("%s%s", "hello", "world");}
int s_two_string_expansions2(void){return ft_printf("..%s stuff %s", "a", "b");}
int s_empty_string_expansion(void){return ft_printf("this %s is empty", "");}
int s_full_then_empty_string(void){return ft_printf("this %s is %s", "hello", "");}
int s_empty_then_full_string(void){return ft_printf("this %s is %s", "", "hello");}
int s_three_strings(void){return ft_printf("%s%s%s", "1", "2", "3's a charm");}
//String specifiers with field_width, space- or zero-padded
int s_space_padded_field_width(void){return ft_printf("%32s", "abc");}
int s_space_padded_field_width2(void){return ft_printf("%16s", "nark nark");}
int s_space_padded_over_field_width(void){return ft_printf("%5s", "goes over");}
//String specifiers with field_width, space- or zero-padded, left-justified
int s_space_padded_field_width_lj(void){return ft_printf("%-32s", "abc");}
int s_space_padded_field_width2_lj(void){return ft_printf("%-16s", "nark nark");}
int s_space_padded_over_field_width_lj(void){return ft_printf("%-5s", "goes over");}
//String specifiers with precision
int s_string_prec_notrunc(void){return ft_printf("%.7s", "hello");}
int s_string_prec_trunc(void){return ft_printf("%.3s", "hello");}
int s_string_prec_default(void){return ft_printf("%.s", "hello");}
int s_string_prec_zero(void){return ft_printf("%.0s", "hello");}
int s_two_strings_prec_2trunc(void){return ft_printf("%.3s%.2s", "holla", "bitch");}
int s_two_strings_prec_1trunc_a(void){return ft_printf("%.2s%.7s", "hello", "world");}
int s_two_strings_prec_1trunc_b(void){return ft_printf("%.7s%.2s", "hello", "world");}
int s_two_strings_prec_0trunc(void){return ft_printf("%.5s%7s", "yo", "boi");}
//String specifiers with both precision and field width
int s_string_prec_width_notrunc(void){return ft_printf("%7.5s", "yolo");}
int s_string_prec_width_trunc(void){return ft_printf("%7.5s", "bombastic");}
int s_string_prec_width_notrunc_lj(void){return ft_printf("%-7.5s", "yolo");}
int s_string_prec_width_trunc_lj(void){return ft_printf("%-7.5s", "tubular");}
int s_two_s_prec_width_2fit_0trunc(void){return ft_printf("%7.7s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_a_0trunc(void){return ft_printf("%3.7s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_b_0trunc(void){return ft_printf("%7.7s%3.7s", "hello", "world");}
int s_two_s_prec_width_0fit_0trunc(void){return ft_printf("%3.7s%3.7s", "hello", "world");}
int s_two_s_prec_width_2fit_1trunc_a(void){return ft_printf("%7.3s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_a_1trunc_a(void){return ft_printf("%3.3s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_b_1trunc_a(void){return ft_printf("%7.3s%3.7s", "hello", "world");}
int s_two_s_prec_width_0fit_1trunc_a(void){return ft_printf("%3.3s%3.7s", "hello", "world");}
int s_two_s_prec_width_2fit_1trunc_b(void){return ft_printf("%7.7s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_a_1trunc_b(void){return ft_printf("%3.7s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_b_1trunc_b(void){return ft_printf("%7.7s%3.3s", "hello", "world");}
int s_two_s_prec_width_0fit_1trunc_b(void){return ft_printf("%3.7s%3.3s", "hello", "world");}
int s_two_s_prec_width_2fit_2trunc(void){return ft_printf("%7.3s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_a_2trunc(void){return ft_printf("%3.3s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_b_2trunc(void){return ft_printf("%7.3s%3.3s", "hello", "world");}
int s_two_s_prec_width_0fit_2trunc(void){return ft_printf("%3.3s%3.3s", "hello", "world");}
int s_two_s_prec_width_2trunc(void){return ft_printf("%3s%3s", "hello", "world");}
//String specifiers, other tests
int s_two_strings_lj_and_rj(void){return ft_printf("%-7s%5s", "hello", "world");}
int s_two_strings_rj_and_lj(void){return ft_printf("%7s%-5s", "hello", "world");}
//String specifiers - NULL strings
int s_null_basic_string_expansion(void){return ft_printf("hello, %s.", NULL);}
int s_null_only_string_expansion(void){return ft_printf("%s", NULL);}
int s_null_space_padded_field_width(void){return ft_printf("%32s", NULL);}
int s_null_space_padded_over_field_width(void){return ft_printf("%2s", NULL);}
int s_null_space_padded_field_width_lj(void){return ft_printf("%-32s", NULL);}
int s_null_space_padded_field_width2_lj(void){return ft_printf("%-16s", NULL);}
int s_null_space_padded_over_field_width_lj(void){return ft_printf("%-3s", NULL);}
//String specifiers with precision
int s_null_string_prec_notrunc(void){return ft_printf("%.9s", "NULL");}
int s_null_string_prec_trunc(void){return ft_printf("%.3s", "NULL");}
int s_null_string_prec_default(void){return ft_printf("%.s", "NULL");}
int s_null_string_prec_zero(void){return ft_printf("%.0s", "NULL");}

static char *s_hidden = "hi low\0don't print me lol\0";

int s_basic_s_hidden(void){return ft_printf("%s", s_hidden);}
// width pad
int s_width_3_s_hidden(void){return ft_printf("%3s", s_hidden);}
int s_width_9_s_hidden(void){return ft_printf("%9s", s_hidden);}
// precision no width
int s_prec_no_width_s_hidden(void){return ft_printf("%.s", s_hidden);}
int s_prec_9_no_width_s_hidden(void){return ft_printf("%.9s", s_hidden);}
// precision  0 before number
int s_prec_03_no_width_s_hidden(void){return ft_printf("%.03s", s_hidden);}
int s_prec_09_no_width_s_hidden(void){return ft_printf("%.09s", s_hidden);}
int s_prec_03_no_width_s_null(void){return ft_printf("%.03s", NULL);}
int s_prec_09_no_width_s_null(void){return ft_printf("%.09s", NULL);}
int s_prec_00_no_width_s_nullchar(void){return ft_printf("%.00s", "\0");}
int s_prec_01_no_width_s_nullchar(void){return ft_printf("%.01s", "\0");}
int s_prec_03_no_width_s_nullchar(void){return ft_printf("%.03s", "\0");}
int s_prec_09_no_width_s_nullchar(void){return ft_printf("%.09s", "\0");}
// width  no precision
int s_prec_0_width_3_s_hidden(void){return ft_printf("%3.s", s_hidden);}
int s_prec_0_width_10_s_hidden(void){return ft_printf("%10.s", s_hidden);}
int s_prec_0_width_3_s_null(void){return ft_printf("%3.s", NULL);}
int s_prec_0_width_10_s_null(void){return ft_printf("%10.s", NULL);}
int s_prec_0_width_1_s_nullchar(void){return ft_printf("%1.s", "\0");}
int s_prec_0_width_2_s_nullchar(void){return ft_printf("%2.s", "\0");}
int s_prec_0_width_9_s_nullchar(void){return ft_printf("%9.s", "\0");}
// lj flag width  no precision
int s_prec_0_lj_width_3_s_hidden(void){return ft_printf("%-3.s", s_hidden);}
int s_prec_0_lj_width_8_s_hidden(void){return ft_printf("%-8.s", s_hidden);}
int s_prec_0_lj_width_3_s_null(void){return ft_printf("%-3.s", NULL);}
int s_prec_0_lj_width_8_s_null(void){return ft_printf("%-8.s", NULL);}
int s_prec_0_lj_width_1_s_nullchar(void){return ft_printf("%-1.s", "\0");}
int s_prec_0_lj_width_2_s_nullchar(void){return ft_printf("%-2.s", "\0");}
int s_prec_0_lj_width_6_s_nullchar(void){return ft_printf("%-6.s", "\0");}
// width  precision 1
int s_prec_1_width_3_s_hidden(void){return ft_printf("%3.1s", s_hidden);}
int s_prec_1_width_10_s_hidden(void){return ft_printf("%10.1s", s_hidden);}
int s_prec_1_width_3_s_null(void){return ft_printf("%3.1s", NULL);}
int s_prec_1_width_9_s_null(void){return ft_printf("%9.1s", NULL);}
// lj flag width  precision 1
int s_prec_1_lj_width_3_s_hidden(void){return ft_printf("%-3.1s", s_hidden);}
int s_prec_1_lj_width_10_s_hidden(void){return ft_printf("%-10.1s", s_hidden);}
int s_prec_1_lj_width_3_s_null(void){return ft_printf("%-3.1s", NULL);}
int s_prec_1_lj_width_9_s_null(void){return ft_printf("%-9.1s", NULL);}
int s_prec_1_lj_width_3_s_nullchar(void){return ft_printf("%-3.1s", "\0");}
int s_prec_1_lj_width_6_s_nullchar(void){return ft_printf("%-6.1s", "\0");}
// width  exact precision
int s_prec_perfect_width_3_s_hidden(void){return ft_printf("%3.6s", s_hidden);}
int s_prec_perfect_width_20_s_hidden(void){return ft_printf("%20.6s", s_hidden);}
int s_prec_perfect_width_3_s_null(void){return ft_printf("%3.6s", NULL);}
int s_prec_perfect_width_20_s_null(void){return ft_printf("%20.6s", NULL);}
int s_prec_perfect_width_3_s_nullchar(void){return ft_printf("%3.6s", "\0");}
int s_prec_perfect_width_6_s_nullchar(void){return ft_printf("%6.6s", "\0");}
// lj flag width exact precision
int s_prec_perfect_lj_width_3_s_hidden(void){return ft_printf("%-3.6s", s_hidden);}
int s_prec_perfect_lj_width_20_s_hidden(void){return ft_printf("%-20.6s", s_hidden);}
// lj flag width excess precision
int s_prec_8_lj_width_3_s_hidden(void){return ft_printf("%-3.8s", s_hidden);}
int s_prec_8_lj_width_10_s_hidden(void){return ft_printf("%-10.8s", s_hidden);}
int s_prec_8_lj_width_3_s_null(void){return ft_printf("%-3.8s", NULL);}
int s_prec_8_lj_width_10_s_null(void){return ft_printf("%-10.8s", NULL);}
// decoy lj flag
int s_prec_00_lj_s_hidden_trunc(void){return ft_printf("%-.00s", s_hidden);}
int s_prec_09_lj_s_hidden_notrunc(void){return ft_printf("%-.09s", s_hidden);}
// multi zeros
int	s_undefbehav_0_2zero(void){return ft_printf("%00s", s_hidden);}
int	s_undefbehav_0_3zero(void){return ft_printf("%000s", s_hidden);}
int	s_undefbehav_0_4zero(void){return ft_printf("%0000s", s_hidden);}
int	s_undefbehav_0_lj_2zero(void){return ft_printf("%-00s", s_hidden);}
int	s_undefbehav_0_zero_lj_zero(void){return ft_printf("%0-0s", s_hidden);}
int	s_undefbehav_0_2zero_lj(void){return ft_printf("%00-s", s_hidden);}
// zero and width
int	s_undefbehav_0_width_3(void){return ft_printf("%03s", s_hidden);}
int	s_undefbehav_0_width_9(void){return ft_printf("%09s", s_hidden);}
// flag cancelling
int	s_undefbehav_lj_0_width_3(void){return ft_printf("%-03s", s_hidden);}
int	s_undefbehav_lj_0_width_9(void){return ft_printf("%-09s", s_hidden);}

//Signed integers - no modifers
int		i_basic_i_pos(void){return ft_printf("this %i number", 17);}
int		i_basic_i_neg(void){return ft_printf("this %i number", -267);}
int		i_basic_i_zero(void){return ft_printf("this %i number", 0);}
int		i_basic_i_onlypos(void){return ft_printf("%i", 3);}
int		i_basic_i_onlyneg(void){return ft_printf("%i", -1);}
int		i_basic_i_onlyzero(void){return ft_printf("%i", 0);}
int		d_basic_pos(void){return ft_printf("this %d number", 17);}
int		d_basic_neg(void){return ft_printf("this %d number", -267);}
int		d_basic_zero(void){return ft_printf("this %d number", 0);}
int		i_intmax(void){return ft_printf("%i",  2147483647);}
int		i_intmin(void){return ft_printf("%i", (int)(-2147483678));}
//Signed integers  field width
int		i_width_pos_fits(void){return ft_printf("%7i", 33);}
int		i_width_neg_fits(void){return ft_printf("%7i", -14);}
int		i_width_zero_fits(void){return ft_printf("%3i", 0);}
int		i_width_pos_exactfit(void){return ft_printf("%5i", 52625);}
int		i_width_neg_exactfit(void){return ft_printf("%5i", -2562);}
int		i_width_pos_nofit(void){return ft_printf("%4i", 94827);}
int		i_width_neg_nofit(void){return ft_printf("%4i", -2464);}
int		i_width_pos_fits_lj(void){return ft_printf("%-7i", 33);}
int		i_width_neg_fits_lj(void){return ft_printf("%-7i", -14);}
int		i_width_zero_fits_lj(void){return ft_printf("%-3i", 0);}
int		i_width_pos_exactfit_lj(void){return ft_printf("%-5i", 52625);}
int		i_width_neg_exactfit_lj(void){return ft_printf("%-5i", -2562);}
int		i_width_pos_nofit_lj(void){return ft_printf("%-4i", 94827);}
int		i_width_neg_nofit_lj(void){return ft_printf("%-4i", -2464);}
//signed integers with precision
int		i_prec_fits_pos(void){return ft_printf("%.5i", 2);}
int		i_prec_fits_neg(void){return ft_printf("%.6i", -3);}
int		i_prec_fits_zero(void){return ft_printf("%.3i", 0);}
int		i_prec_exactfit_pos(void){return ft_printf("%.4i", 5263);}
int		i_prec_exactfit_neg(void){return ft_printf("%.4i", -2372);}
int		i_prec_nofit_pos(void){return ft_printf("%.3i", 13862);}
int		i_prec_nofit_neg(void){return ft_printf("%.3i",-23646);}
//Signed integers with zero field width padding
int		i_zp_pos_fits(void){return ft_printf("%05i", 43);}
int		i_zp_neg_fits(void){return ft_printf("%07i", -54);}
int		i_zp_zero_fits(void){return ft_printf("%03i", 0);}
int		i_zp_pos_exactfit(void){return ft_printf("%03i", 634);}
int		i_zp_neg_exactfit(void){return ft_printf("%04i", -532);}
int		i_zp_neg_minus1fit(void){return ft_printf("%04i", -4825);}
//Signed integers with field width and precision
int		i_prec_width_fit_fit_pos(void){return ft_printf("%8.5i", 34);}
int		i_prec_width_fit_fit_neg(void){return ft_printf("%10.5i", -216);}
int		i_prec_width_fit_fit_zero(void){return ft_printf("%8.5i", 0);}
int		i_prec_width_nofit_fit_pos(void){return ft_printf("%8.3i", 8375);}
int		i_prec_width_nofit_fit_neg(void){return ft_printf("%8.3i", -8473);}
int		i_prec_width_fit_nofit_pos(void){return ft_printf("%3.7i", 3267);}
int		i_prec_width_fit_nofit_neg(void){return ft_printf("%3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos(void){return ft_printf("%3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg(void){return ft_printf("%3.3i", -8462);}
//Signed integers with field width and precision, left-justified
int		i_prec_width_fit_fit_pos_lj(void){return ft_printf("%-8.5i", 34);}
int		i_prec_width_fit_fit_neg_lj(void){return ft_printf("%-10.5i", -216);}
int		i_prec_width_fit_fit_zero_lj(void){return ft_printf("%-8.5i", 0);}
int		i_prec_width_nofit_fit_pos_lj(void){return ft_printf("%-8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_lj(void){return ft_printf("%-8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_lj(void){return ft_printf("%-3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_lj(void){return ft_printf("%-3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_lj(void){return ft_printf("%-3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_lj(void){return ft_printf("%-3.3i", -8462);}
//Signed integers with field width and precision with zeropadding
int		i_prec_width_ff_pos_zp(void){return ft_printf("%08.5i", 34);}
int		i_prec_width_ff_neg_zp(void){return ft_printf("%010.5i", -216);}
int		i_prec_width_ff_zero_zp(void){return ft_printf("%08.5i", 0);}
int		i_prec_width_nf_pos_zp(void){return ft_printf("%08.3i", 8375);}
int		i_prec_width_nf_neg_zp(void){return ft_printf("%08.3i", -8473);}
int		i_prec_width_fn_pos_zp(void){return ft_printf("%03.7i", 3267);}
int		i_prec_width_fn_neg_zp(void){return ft_printf("%03.7i", -2375);}
int		i_prec_width_nn_pos_zp(void){return ft_printf("%03.3i", 6983);}
int		i_prec_width_nn_neg_zp(void){return ft_printf("%03.3i", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int		i_prec_width_ff_pos_lj_zp_ignoreflag(void){return ft_printf("%0-8.5i", 34);}
int		i_prec_width_ff_neg_ljzp_ignoreflag(void){return ft_printf("%0-10.5i", -216);}
int		i_prec_width_ff_zero_ljzp_ignoreflag(void){return ft_printf("%0-8.5i", 0);}
int		i_prec_width_nf_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.3i", 8375);}
int		i_prec_width_nf_neg_ljzp_ignoreflag(void){return ft_printf("%0-8.3i", -8473);}
int		i_prec_width_fn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.7i", 3267);}
int		i_prec_width_fn_neg_ljzp_ignoreflag(void){return ft_printf("%0-3.7i", -2375);}
int		i_prec_width_nn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.3i", 6983);}
int		i_prec_width_nn_neg_ljzp_ignoreflag(void){return ft_printf("%0-3.3i", -8462);}

static int			i_pos_1 = 878023;

//Signed integers of varying size modifiers with some other modifiers
int		i_size_follows_i_i(void){return ft_printf("[%i] [%i]", i_pos_1, i_pos_1);}
 //Signed integers - zero precision zero value
int i_prec0val0_basic(void){return ft_printf("%.0i", 0);}
int i_prec0val0_implicit(void){return ft_printf("%.i", 0);}
int i_prec0val0_w(void){return ft_printf("%5.0i", 0);}
int i_prec0val0_w_impl(void){return ft_printf("%5.i", 0);}
int i_prec0val0_wlj(void){return ft_printf("%-5.0i", 0);}
int i_prec0val0_wlj_impl(void){return ft_printf("%-5.i", 0);}

//Signed integers - no modifers
int	 d_basic_i_pos(void){return ft_printf("this %d number", 17);}
int	 d_basic_i_neg(void){return ft_printf("this %d number", -267);}
int	 d_basic_i_zero(void){return ft_printf("this %d number", 0);}
int	 d_basic_i_onlypos(void){return ft_printf("%d", 3);}
int	 d_basic_i_onlyneg(void){return ft_printf("%d", -1);}
int	 d_basic_i_onlyzero(void){return ft_printf("%d", 0);}
int	 d_intmax(void){return ft_printf("%d",  2147483647);}
int	 d_intmin(void){return ft_printf("%d", (int)(-2147483678));}
//Signed integers with field width
int	 d_width_pos_fits(void){return ft_printf("%7d", 33);}
int	 d_width_neg_fits(void){return ft_printf("%7d", -14);}
int	 d_width_zero_fits(void){return ft_printf("%3d", 0);}
int	 d_width_pos_exactfit(void){return ft_printf("%5d", 52625);}
int	 d_width_neg_exactfit(void){return ft_printf("%5d", -2562);}
int	 d_width_pos_nofit(void){return ft_printf("%4d", 94827);}
int	 d_width_neg_nofit(void){return ft_printf("%4d", -2464);}
int	 d_width_pos_fits_lj(void){return ft_printf("%-7d", 33);}
int	 d_width_neg_fits_lj(void){return ft_printf("%-7d", -14);}
int	 d_width_zero_fits_lj(void){return ft_printf("%-3d", 0);}
int	 d_width_pos_exactfit_lj(void){return ft_printf("%-5d", 52625);}
int	 d_width_neg_exactfit_lj(void){return ft_printf("%-5d", -2562);}
int	 d_width_pos_nofit_lj(void){return ft_printf("%-4d", 94827);}
int	 d_width_neg_nofit_lj(void){return ft_printf("%-4d", -2464);}
//signed integers with precision
int	 d_prec_fits_pos(void){return ft_printf("%.5d", 2);}
int	 d_prec_fits_neg(void){return ft_printf("%.6d", -3);}
int	 d_prec_fits_zero(void){return ft_printf("%.3d", 0);}
int	 d_prec_exactfit_pos(void){return ft_printf("%.4d", 5263);}
int	 d_prec_exactfit_neg(void){return ft_printf("%.4d", -2372);}
int	 d_prec_nofit_pos(void){return ft_printf("%.3d", 13862);}
int	 d_prec_nofit_neg(void){return ft_printf("%.3d",-23646);}
//Signed integers with zero field width padding
int	 d_zp_pos_fits(void){return ft_printf("%05d", 43);}
int	 d_zp_neg_fits(void){return ft_printf("%07d", -54);}
int	 d_zp_zero_fits(void){return ft_printf("%03d", 0);}
int	 d_zp_pos_exactfit(void){return ft_printf("%03d", 634);}
int	 d_zp_neg_exactfit(void){return ft_printf("%04d", -532);}
int	 d_zp_neg_minus1fit(void){return ft_printf("%04d", -4825);}
//Signed integers with field width and precision
int	 d_prec_width_fit_fit_pos(void){return ft_printf("%8.5d", 34);}
int	 d_prec_width_fit_fit_neg(void){return ft_printf("%10.5d", -216);}
int	 d_prec_width_fit_fit_zero(void){return ft_printf("%8.5d", 0);}
int	 d_prec_width_nofit_fit_pos(void){return ft_printf("%8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg(void){return ft_printf("%8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos(void){return ft_printf("%3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg(void){return ft_printf("%3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos(void){return ft_printf("%3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg(void){return ft_printf("%3.3d", -8462);}
//Signed integers with field width and precision, left-justified
int	 d_prec_width_fit_fit_pos_lj(void){return ft_printf("%-8.5d", 34);}
int	 d_prec_width_fit_fit_neg_lj(void){return ft_printf("%-10.5d", -216);}
int	 d_prec_width_fit_fit_zero_lj(void){return ft_printf("%-8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_lj(void){return ft_printf("%-8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_lj(void){return ft_printf("%-8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_lj(void){return ft_printf("%-3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_lj(void){return ft_printf("%-3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_lj(void){return ft_printf("%-3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_lj(void){return ft_printf("%-3.3d", -8462);}
//Signed integers with field width and precision with zeropadding
int	 d_prec_width_ff_pos_zp(void){return ft_printf("%08.5d", 34);}
int	 d_prec_width_ff_neg_zp(void){return ft_printf("%010.5d", -216);}
int	 d_prec_width_ff_zero_zp(void){return ft_printf("%08.5d", 0);}
int	 d_prec_width_nf_pos_zp(void){return ft_printf("%08.3d", 8375);}
int	 d_prec_width_nf_neg_zp(void){return ft_printf("%08.3d", -8473);}
int	 d_prec_width_fn_pos_zp(void){return ft_printf("%03.7d", 3267);}
int	 d_prec_width_fn_neg_zp(void){return ft_printf("%03.7d", -2375);}
int	 d_prec_width_nn_pos_zp(void){return ft_printf("%03.3d", 6983);}
int	 d_prec_width_nn_neg_zp(void){return ft_printf("%03.3d", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int	 d_prec_width_ff_pos_lj_zp_ignoreflag(void){return ft_printf("%0-8.5d", 34);}
int	 d_prec_width_ff_neg_ljzp_ignoreflag(void){return ft_printf("%0-10.5d", -216);}
int	 d_prec_width_ff_zero_ljzp_ignoreflag(void){return ft_printf("%0-8.5d", 0);}
int	 d_prec_width_nf_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljzp_ignoreflag(void){return ft_printf("%0-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljzp_ignoreflag(void){return ft_printf("%0-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljzp_ignoreflag(void){return ft_printf("%0-3.3d", -8462);}
 //Signed integers - zero precision zero value
int d_prec0val0_basic(void){return ft_printf("%.0d", 0);}
int d_prec0val0_implicit(void){return ft_printf("%.d", 0);}
int d_prec0val0_w(void){return ft_printf("%5.0d", 0);}
int d_prec0val0_w_impl(void){return ft_printf("%5.d", 0);}
int d_prec0val0_wlj(void){return ft_printf("%-5.0d", 0);}
int d_prec0val0_wlj_impl(void){return ft_printf("%-5.d", 0);}

//Unsigned integers - no modifers
int u_basic_u_pos(void){return ft_printf("this %u number", 17);}
int u_basic_u_zero(void){return ft_printf("this %u number", 0);}
int u_basic_u_onlypos(void){return ft_printf("%u", 3);}
int u_uintmax(void){return ft_printf("%u", 4294967295u);}
//Unsigned integers with field width
int u_width_pos_fits(void){return ft_printf("%7u", 33);}
int u_width_zero_fits(void){return ft_printf("%3u", 0);}
int u_width_pos_exactfit(void){return ft_printf("%5u", 52625);}
int u_width_pos_nofit(void){return ft_printf("%4u", 94827);}
int u_width_pos_fits_lj(void){return ft_printf("%-7u", 33);}
int u_width_zero_fits_lj(void){return ft_printf("%-3u", 0);}
int u_width_pos_exactfit_lj(void){return ft_printf("%-5u", 52625);}
int u_width_pos_nofit_lj(void){return ft_printf("%-4u", 94827);}
//unsigned integers with precision
int u_prec_fits_pos(void){return ft_printf("%.5u", 2);}
int u_prec_fits_zero(void){return ft_printf("%.3u", 0);}
int u_prec_exactfit_pos(void){return ft_printf("%.4u", 5263);}
int u_prec_nofit_pos(void){return ft_printf("%.3u", 13862);}
//Unsigned integers with zero field width padding
int u_zp_pos_fits(void){return ft_printf("%05u", 43);}
int u_zp_zero_fits(void){return ft_printf("%03u", 0);}
int u_zp_pos_exactfit(void){return ft_printf("%03u", 634);}
//Unsigned integers with field width and precision
int u_prec_width_fit_fit_pos(void){return ft_printf("%8.5u", 34);}
int u_prec_width_fit_fit_zero(void){return ft_printf("%8.5u", 0);}
int u_prec_width_nofit_fit_pos(void){return ft_printf("%8.3u", 8375);}
int u_prec_width_fit_nofit_pos(void){return ft_printf("%3.7u", 3267);}
int u_prec_width_nofit_nofit_pos(void){return ft_printf("%3.3u", 6983);}
//Unsigned integers with field width and precision, left-justified
int u_prec_width_fit_fit_pos_lj(void){return ft_printf("%-8.5u", 34);}
int u_prec_width_fit_fit_zero_lj(void){return ft_printf("%-8.5u", 0);}
int u_prec_width_nofit_fit_pos_lj(void){return ft_printf("%-8.3u", 8375);}
int u_prec_width_fit_nofit_pos_lj(void){return ft_printf("%-3.7u", 3267);}
int u_prec_width_nofit_nofit_pos_lj(void){return ft_printf("%-3.3u", 6983);}
//Unsigned integers with field width and precision with zeropadding
int u_prec_width_ff_pos_zp(void){return ft_printf("%08.5u", 34);}
int u_prec_width_ff_zero_zp(void){return ft_printf("%08.5u", 0);}
int u_prec_width_nf_pos_zp(void){return ft_printf("%08.3u", 8375);}
int u_prec_width_fn_pos_zp(void){return ft_printf("%03.7u", 3267);}
int u_prec_width_nn_pos_zp(void){return ft_printf("%03.3u", 6983);}
//Unsigned integers with field width and precision, left-justified with zeropadding
int u_prec_width_ff_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.5u", 34);}
int u_prec_width_ff_zero_ljzp_ignoreflag(void){return ft_printf("%0-8.5u", 0);}
int u_prec_width_nf_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.3u", 8375);}
int u_prec_width_fn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.7u", 3267);}
int u_prec_width_nn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.3u", 6983);}
//Unsigned integers - zero precision zero value
int u_prec0val0_basic(void){return ft_printf("%.0u", 0);}
int u_prec0val0_implicit(void){return ft_printf("%.u", 0);}
int u_prec0val0_w(void){return ft_printf("%5.0u", 0);}
int u_prec0val0_w_impl(void){return ft_printf("%5.u", 0);}
int u_prec0val0_wlj(void){return ft_printf("%-5.0u", 0);}
int u_prec0val0_wlj_impl(void){return ft_printf("%-5.u", 0);}

//Hexadecimal lowers - no modifers
int x_basic_pos(void){return ft_printf("this %x number", 17);}
int x_basic_zero(void){return ft_printf("this %x number", 0);}
int x_basic_onlypos(void){return ft_printf("%x", 3);}
int x_hexlmax(void){return ft_printf("%x", 4294967295u);}
//Hexadecimal lowers with field width
int x_width_pos_fits(void){return ft_printf("%7x", 33);}
int x_width_zero_fits(void){return ft_printf("%3x", 0);}
int x_width_pos_exactfit(void){return ft_printf("%5x", 52625);}
int x_width_pos_nofit(void){return ft_printf("%2x", 94827);}
int x_width_pos_fits_lj(void){return ft_printf("%-7x", 33);}
int x_width_zero_fits_lj(void){return ft_printf("%-3x", 0);}
int x_width_pos_exactfit_lj(void){return ft_printf("%-5x", 52625);}
int x_width_pos_nofit_lj(void){return ft_printf("%-4x", 9648627);}
//Hexadecimal lowers with precision
int x_prec_fits_pos(void){return ft_printf("%.5x", 21);}
int x_prec_fits_zero(void){return ft_printf("%.3x", 0);}
int x_prec_exactfit_pos(void){return ft_printf("%.4x", 5263);}
int x_prec_nofit_pos(void){return ft_printf("%.3x", 938862);}
//Hexadecimal lowers with zero field width padding
int x_zp_pos_fits(void){return ft_printf("%05x", 43);}
int x_zp_zero_fits(void){return ft_printf("%03x", 0);}
int x_zp_pos_exactfit(void){return ft_printf("%03x", 698334);}
//Hexadecimal lowers with field width and precision
int x_prec_width_fit_fit_pos(void){return ft_printf("%8.5x", 34);}
int x_prec_width_fit_fit_zero(void){return ft_printf("%8.5x", 0);}
int x_prec_width_nofit_fit_pos(void){return ft_printf("%8.3x", 8375);}
int x_prec_width_fit_nofit_pos(void){return ft_printf("%2.7x", 3267);}
int x_prec_width_nofit_nofit_pos(void){return ft_printf("%3.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified
int x_prec_width_fit_fit_pos_lj(void){return ft_printf("%-8.5x", 34);}
int x_prec_width_fit_fit_zero_lj(void){return ft_printf("%-8.5x", 0);}
int x_prec_width_nofit_fit_pos_lj(void){return ft_printf("%-8.3x", 8375);}
int x_prec_width_fit_nofit_pos_lj(void){return ft_printf("%-2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_lj(void){return ft_printf("%-3.3x", 6983);}
//Hexadecimal lowers with field width and precision with zeropadding
int x_prec_width_ff_pos_zp(void){return ft_printf("%08.5x", 34);}
int x_prec_width_ff_zero_zp(void){return ft_printf("%08.5x", 0);}
int x_prec_width_nf_pos_zp(void){return ft_printf("%08.3x", 8375);}
int x_prec_width_fn_pos_zp(void){return ft_printf("%02.7x", 3267);}
int x_prec_width_nn_pos_zp(void){return ft_printf("%03.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified with zeropadding
int x_prec_width_ff_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.5x", 34);}
int x_prec_width_ff_zero_ljzp_ignoreflag(void){return ft_printf("%0-8.5x", 0);}
int x_prec_width_nf_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.3x", 8375);}
int x_prec_width_fn_pos_ljzp_ignoreflag(void){return ft_printf("%0-2.7x", 3267);}
int x_prec_width_nn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.3x", 6983);}
 //Hexadecimal lower - zero precision zero value
int x_prec0val0_basic(void){return ft_printf("%.0x", 0);}
int x_prec0val0_implicit(void){return ft_printf("%.x", 0);}
int x_prec0val0_w(void){return ft_printf("%5.0x", 0);}
int x_prec0val0_w_impl(void){return ft_printf("%5.x", 0);}
int x_prec0val0_wlj(void){return ft_printf("%-5.0x", 0);}
int x_prec0val0_wlj_impl(void){return ft_printf("%-5.x", 0);}


//Hexadecimal uppers - no modifers
int X_basic_hexu_pos(void){return ft_printf("this %X number", 17);}
int X_basic_hexu_zero(void){return ft_printf("this %X number", 0);}
int X_basic_hexu_onlypos(void){return ft_printf("%X", 3);}
int X_hexumax(void){return ft_printf("%X", 4294967295u);}
//Hexadecimal uppers with field width
int X_width_pos_fits(void){return ft_printf("%7X", 33);}
int X_width_zero_fits(void){return ft_printf("%3X", 0);}
int X_width_pos_exactfit(void){return ft_printf("%5X", 52625);}
int X_width_pos_nofit(void){return ft_printf("%2X", 94827);}
int X_width_pos_fits_lj(void){return ft_printf("%-7X", 33);}
int X_width_zero_fits_lj(void){return ft_printf("%-3X", 0);}
int X_width_pos_exactfit_lj(void){return ft_printf("%-5X", 52625);}
int X_width_pos_nofit_lj(void){return ft_printf("%-4X", 9648627);}
//Hexadecimal uppers with precision
int X_prec_fits_pos(void){return ft_printf("%.5X", 21);}
int X_prec_fits_zero(void){return ft_printf("%.3X", 0);}
int X_prec_exactfit_pos(void){return ft_printf("%.4X", 5263);}
int X_prec_nofit_pos(void){return ft_printf("%.3X", 938862);}
//Hexadecimal uppers with zero field width padding
int X_zp_pos_fits(void){return ft_printf("%05X", 43);}
int X_zp_zero_fits(void){return ft_printf("%03X", 0);}
int X_zp_pos_exactfit(void){return ft_printf("%03X", 698334);}
//Hexadecimal uppers with field width and precision
int X_prec_width_fit_fit_pos(void){return ft_printf("%8.5X", 34);}
int X_prec_width_fit_fit_zero(void){return ft_printf("%8.5X", 0);}
int X_prec_width_nofit_fit_pos(void){return ft_printf("%8.3X", 8375);}
int X_prec_width_fit_nofit_pos(void){return ft_printf("%2.7X", 3267);}
int X_prec_width_nofit_nofit_pos(void){return ft_printf("%3.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified
int X_prec_width_fit_fit_pos_lj(void){return ft_printf("%-8.5X", 34);}
int X_prec_width_fit_fit_zero_lj(void){return ft_printf("%-8.5X", 0);}
int X_prec_width_nofit_fit_pos_lj(void){return ft_printf("%-8.3X", 8375);}
int X_prec_width_fit_nofit_pos_lj(void){return ft_printf("%-2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_lj(void){return ft_printf("%-3.3X", 6983);}
//Hexadecimal uppers with field width and precision with zeropadding
int X_prec_width_ff_pos_zp(void){return ft_printf("%08.5X", 34);}
int X_prec_width_ff_zero_zp(void){return ft_printf("%08.5X", 0);}
int X_prec_width_nf_pos_zp(void){return ft_printf("%08.3X", 8375);}
int X_prec_width_fn_pos_zp(void){return ft_printf("%02.7X", 3267);}
int X_prec_width_nn_pos_zp(void){return ft_printf("%03.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified with zeropadding
int X_prec_width_ff_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.5X", 34);}
int X_prec_width_ff_zero_ljzp_ignoreflag(void){return ft_printf("%0-8.5X", 0);}
int X_prec_width_nf_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.3X", 8375);}
int X_prec_width_fn_pos_ljzp_ignoreflag(void){return ft_printf("%0-2.7X", 3267);}
int X_prec_width_nn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.3X", 6983);}
//Hexadecimal uppers - zero precision zero value
int X_prec0val0_basic(void){return ft_printf("%.0X", 0);}
int X_prec0val0_implicit(void){return ft_printf("%.X", 0);}
int X_prec0val0_w(void){return ft_printf("%5.0X", 0);}
int X_prec0val0_w_impl(void){return ft_printf("%5.X", 0);}
int X_prec0val0_wlj(void){return ft_printf("%-5.0X", 0);}
int X_prec0val0_wlj_impl(void){return ft_printf("%-5.X", 0);}


//Pointers - Basic
static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

int p_null(void){return ft_printf("%p", NULL);}
int p_null_width_fit(void){return ft_printf("%5p", NULL);}
int p_null_width_nofit(void){return ft_printf("%2p", NULL);}

int p_void(void){return ft_printf("%.p", NULL);}
int p_void_width_fit(void){return ft_printf("%5.p", NULL);}
int p_void_width_nofit(void){return ft_printf("%2.p", NULL);}

int	p_ftfc_literal_9w_prec2_undefbehav(void){return ft_printf("%9.2p\n", 1234);}
int	p_ftfc_literal_2w_prec9_undefbehav(void){return ft_printf("%2.9p\n", 1234);}
int	p_ftfc_zero_prec5_undefbehav(void){return ft_printf("%.5p", 0);}
int	p_ftfc_zero_prec0_undefbehav(void){return ft_printf("%.0p", 0);}
int p_ftfc_5w_throwswarning(void){return ft_printf("%5p", 0);}

int p_basic(void){return ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_fit(void){return ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_nofit(void){return ft_printf("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_16(void){return ft_printf("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_8(void){return ft_printf("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_32(void){return ft_printf("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_fit_lj(void){return ft_printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_nofit_lj(void){return ft_printf("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_16_lj(void){return ft_printf("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_8_lj(void){return ft_printf("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int p_width_32_lj(void){return ft_printf("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


//Chars - Basic
int c_allprintable_combined(void){return ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int c_1_31_combined(void){return ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int c_128_255_combined(void){return ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int c_allprintable_width(void){return ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int c_1_31_width(void){return ft_printf("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int c_128_255_width(void){return ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int c_allprintable_width_lj(void){return ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int c_1_31_width_lj(void){return ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int c_128_255_width_lj(void){return ft_printf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}


int c_nullterm_basic(void){return ft_printf("%c", '\0');}
int c_nullterm_5w(void){return ft_printf("%5c", '\0');}
int c_nullterm_5wlj(void){return ft_printf("%-5c", '\0');}

// Mix tests
static unsigned int		mx_u = 235;
static char				mx_c = 'G';
static char			   *mx_s = "Hello, World!";
static int					mx_i = 42;

int		mix_successive_0(void){return ( ft_printf("%c", mx_c) + ft_printf("%u", mx_u));}
int		mix_successive_4(void){return ( ft_printf("%x", mx_u) + ft_printf("%i", mx_i));}
int		mix_successive_6(void){return ( ft_printf("%s", mx_s) + ft_printf("%c", mx_c));}
int		mix_successive_10(void){return ( ft_printf("%u", mx_u) + ft_printf("%s", mx_s));}
int		mix_successive_16(void){return ( ft_printf("%s", mx_s) + ft_printf("%x", mx_u));}
int		mix_successive_20(void){return ( ft_printf("%p", &mx_i) + ft_printf("%s", mx_s));}
int		mix_successive_21(void){return ( ft_printf("%X", mx_u) + ft_printf("%x", mx_u));}
int		mix_successive_28(void){return ( ft_printf("%i", mx_i) + ft_printf("%u", mx_u));}
int		mix_successive_30(void){return ( ft_printf("%s", mx_s) + ft_printf("%u", mx_u));}
int		mix_successive_31(void){return ( ft_printf("%X", mx_u) + ft_printf("%c", mx_c));}
int		mix_successive_32(void){return ( ft_printf("%x", mx_u) + ft_printf("%u", mx_u));}
int		mix_successive_39(void){return ( ft_printf("%i", mx_i) + ft_printf("%c", mx_c));}
int		mix_successive_40(void){return ( ft_printf("%c", mx_c) + ft_printf("%x", mx_u));}
int		mix_successive_42(void){return ( ft_printf("%x", mx_u) + ft_printf("%s", mx_s));}
int		mix_successive_43(void){return ( ft_printf("%u", mx_u) + ft_printf("%x", mx_u));}
int		mix_successive_45(void){return ( ft_printf("%s", mx_s) + ft_printf("%c", mx_c));}
int		mix_successive_46(void){return ( ft_printf("%i", mx_i) + ft_printf("%s", mx_s));}
int		mix_successive_61(void){return ( ft_printf("%p", &mx_i) + ft_printf("%c", mx_c));}
int		mix_successive_64(void){return ( ft_printf("%s", mx_s) + ft_printf("%c", mx_c));}


//No-crash-no-segfault test
int		nocrash_noarg_1_notmandatory(void){return ft_printf("%1$"); }
int		nocrash_noarg_2_notmandatory(void){return ft_printf("%0"); }
int		nocrash_noarg_3_notmandatory(void){return ft_printf("% "); }
int		nocrash_noarg_4_notmandatory(void){return ft_printf("%#"); }
int		nocrash_noarg_5_notmandatory(void){return ft_printf("%-"); }
int		nocrash_noarg_6_notmandatory(void){return ft_printf("%+"); }
int		nocrash_noarg_9_notmandatory(void){return ft_printf("%23"); }
int		nocrash_noarg_10_notmandatory(void){return ft_printf("%."); }
int		nocrash_noarg_11_notmandatory(void){return ft_printf("%hh"); }
int		nocrash_noarg_12_notmandatory(void){return ft_printf("%h"); }
int		nocrash_noarg_13_notmandatory(void){return ft_printf("%ll"); }
int		nocrash_noarg_14_notmandatory(void){return ft_printf("%l"); }
int		nocrash_noarg_15_notmandatory(void){return ft_printf("%L"); }
int		nocrash_noarg_16_notmandatory(void){return ft_printf("%p"); }
int		nocrash_noarg_17_notmandatory(void){return ft_printf("%d"); }
int		nocrash_noarg_19_notmandatory(void){return ft_printf("%u"); }
int		nocrash_noarg_20_notmandatory(void){return ft_printf("%x"); }
int		nocrash_noarg_21_notmandatory(void){return ft_printf("%X"); }
int		nocrash_noarg_22_notmandatory(void){return ft_printf("%f"); }
int		nocrash_noarg_24_notmandatory(void){return ft_printf("%c"); }
int		nocrash_noarg_25_notmandatory(void){return ft_printf("%o"); }

int		nocrash_nullarg_1(void){return ft_printf("%1$s", NULL); }
int		nocrash_nullarg_2(void){return ft_printf("%0s", NULL); }
int		nocrash_nullarg_3(void){return ft_printf("% s", NULL); }
int		nocrash_nullarg_4(void){return ft_printf("%#s", NULL); }
int		nocrash_nullarg_5(void){return ft_printf("%-s", NULL); }
int		nocrash_nullarg_6(void){return ft_printf("%+s", NULL); }
int		nocrash_nullarg_9(void){return ft_printf("%23s", NULL); }
int		nocrash_nullarg_10(void){return ft_printf("%.s", NULL); }
int		nocrash_nullarg_11(void){return ft_printf("%hhs", NULL); }
int		nocrash_nullarg_12(void){return ft_printf("%hs", NULL); }
int		nocrash_nullarg_13(void){return ft_printf("%lls", NULL); }
int		nocrash_nullarg_14(void){return ft_printf("%ls", NULL); }
int		nocrash_nullarg_15(void){return ft_printf("%Ls", NULL); }
int		nocrash_nullarg_16(void){return ft_printf("%p", NULL); }
int		nocrash_nullarg_17(void){return ft_printf("%d", NULL); }
int		nocrash_nullarg_18(void){return ft_printf("%b", NULL); }
int		nocrash_nullarg_19(void){return ft_printf("%u", NULL); }
int		nocrash_nullarg_20(void){return ft_printf("%x", NULL); }
int		nocrash_nullarg_21(void){return ft_printf("%X", NULL); }
int		nocrash_nullarg_22(void){return ft_printf("%f", NULL); }
int		nocrash_nullarg_23(void){return ft_printf("%s", NULL); }
int		nocrash_nullarg_24(void){return ft_printf("%c", NULL); }
int		nocrash_nullarg_25(void){return ft_printf("%o", NULL); }

//Tests that were deleted because turning off -Wformat=0 gives a warning about undefined behavior
int nocrash_mandatory_wformat_undefbehav_01(void){return ft_printf("%-021s", "abc");}
int nocrash_mandatory_wformat_undefbehav_02(void){return ft_printf("%-05s", "goes over");}
int nocrash_mandatory_wformat_undefbehav_03(void){return ft_printf("%04.3s%-7.4s", "hello", "world");}
int nocrash_mandatory_wformat_undefbehav_04(void){return ft_printf("%021s", NULL);}
int nocrash_mandatory_wformat_undefbehav_05(void){return ft_printf("%02s", NULL);}
int nocrash_mandatory_wformat_undefbehav_06(void){return ft_printf("%-021s", NULL);}
int nocrash_mandatory_wformat_undefbehav_07(void){return ft_printf("%-03s", NULL);}
int nocrash_mandatory_wformat_undefbehav_38(void){return ft_printf("%05c", '\0');}
int nocrash_mandatory_wformat_undefbehav_39(void){return ft_printf("%-05c", '\0');}

//nocrash tests adapted from tests contributed by phtruong
int nocrash_mandatory_dupflag_d_spsp(void){return ft_printf("%  d", 42);}
int nocrash_mandatory_dupflag_d_ljljw(void){return ft_printf("%--5d", 42);}
int nocrash_mandatory_dupflag_x_afaf(void){return ft_printf("%##x", 42);}

//nocrash tests that came about as part of the minimal specification
int nocrash_mandatory_c_prec_1(void){return ft_printf("%.4c", 'a');}
int nocrash_mandatory_c_prec_2(void){return ft_printf("%.c", 'a');}
int nocrash_mandatory_c_af(void){return ft_printf("%#c", 'a');}
int nocrash_mandatory_c_zp_1(void){return ft_printf("%05c", 'a');}
int nocrash_mandatory_c_zp_2(void){return ft_printf("%0c", 'a');}
int nocrash_mandatory_c_sp_1(void){return ft_printf("% c", 'a');}
int nocrash_mandatory_c_sp_2(void){return ft_printf("% c", -42);}
int nocrash_mandatory_c_size_hh(void){return ft_printf("%hhc", 'a');}
int nocrash_mandatory_c_size_h(void){return ft_printf("%hc", 'a');}
int nocrash_mandatory_c_size_l(void){return ft_printf("%lc", L'a');}
int nocrash_mandatory_c_size_ll(void){return ft_printf("%llc", L'a');}
int nocrash_mandatory_c_size_L(void){return ft_printf("%Lc", L'a');}
int nocrash_mandatory_c_lj_nowidth(void){return ft_printf("%-c", 'a');}

int nocrash_mandatory_s_af(void){return ft_printf("%#s", "hello");}
int nocrash_mandatory_s_zp_1(void){return ft_printf("%05s", "hello");}
int nocrash_mandatory_s_zp_2(void){return ft_printf("%0s", "hello");}
int nocrash_mandatory_s_sp_1(void){return ft_printf("% s", "hello");}
int nocrash_mandatory_s_size_hh(void){return ft_printf("%hhs", "hello");}
int nocrash_mandatory_s_size_h(void){return ft_printf("%hs", "hello");}
int nocrash_mandatory_s_size_l(void){return ft_printf("%ls", L"hello");}
int nocrash_mandatory_s_size_ll(void){return ft_printf("%lls", L"hello");}
int nocrash_mandatory_s_size_L(void){return ft_printf("%Ls", L"hello");}
int nocrash_mandatory_s_lj_nowidth(void){return ft_printf("%-s", "hello");}

static int ncm_p = 5;
int nocrash_mandatory_p_prec_1(void){return ft_printf("%.4p", &ncm_p);}
int nocrash_mandatory_p_prec_2(void){return ft_printf("%.p", &ncm_p);}
int nocrash_mandatory_p_af(void){return ft_printf("%#p", &ncm_p);}
int nocrash_mandatory_p_zp_1(void){return ft_printf("%05p", &ncm_p);}
int nocrash_mandatory_p_zp_2(void){return ft_printf("%0p", &ncm_p);}
int nocrash_mandatory_p_sp_1(void){return ft_printf("% p", &ncm_p);}
int nocrash_mandatory_p_sp_2(void){return ft_printf("% p", &ncm_p);}
int nocrash_mandatory_p_size_hh(void){return ft_printf("%hhp", &ncm_p);}
int nocrash_mandatory_p_size_h(void){return ft_printf("%hp", &ncm_p);}
int nocrash_mandatory_p_size_l(void){return ft_printf("%lp", &ncm_p);}
int nocrash_mandatory_p_size_ll(void){return ft_printf("%llp", &ncm_p);}
int nocrash_mandatory_p_size_L(void){return ft_printf("%Lp", &ncm_p);}
int nocrash_mandatory_p_lj_nowidth(void){return ft_printf("%-p", &ncm_p);}

int nocrash_mandatory_d_size_L(void){return ft_printf("%Ld", 42);}
int nocrash_mandatory_d_af(void){return ft_printf("%#d", 42);}
int nocrash_mandatory_d_size_hhh(void){return ft_printf("%hhhd", 42);}
int nocrash_mandatory_d_size_hhhh(void){return ft_printf("%hhhhd", 42);}
int nocrash_mandatory_d_size_hhl(void){return ft_printf("%hhld", 42);}
int nocrash_mandatory_d_size_hhll(void){return ft_printf("%hhlld", 42);}
int nocrash_mandatory_d_size_llh(void){return ft_printf("%llhd", 42);}
int nocrash_mandatory_d_size_lll(void){return ft_printf("%llld", 42);}
int nocrash_mandatory_i_size_L(void){return ft_printf("%Li", 42);}
int nocrash_mandatory_i_af(void){return ft_printf("%#i", 42);}
int nocrash_mandatory_i_size_hhh(void){return ft_printf("%hhhi", 42);}
int nocrash_mandatory_i_lj_nowidth(void){return ft_printf("%-i", 42);}

int nocrash_mandatory_o_sp(void){return ft_printf("% o", 42);}
int nocrash_mandatory_o_size_L(void){return ft_printf("%Lo", 42);}
int nocrash_mandatory_o_size_hhh(void){return ft_printf("%hhho", 42);}
int nocrash_mandatory_o_size_hhhh(void){return ft_printf("%hhhho", 42);}
int nocrash_mandatory_o_size_hhl(void){return ft_printf("%hhlo", 42);}
int nocrash_mandatory_o_size_hhll(void){return ft_printf("%hhllo", 42);}
int nocrash_mandatory_o_size_llh(void){return ft_printf("%llho", 42);}
int nocrash_mandatory_o_size_lll(void){return ft_printf("%lllo", 42);}
int nocrash_mandatory_o_lj_nowidth(void){return ft_printf("%-o", 42);}

int nocrash_mandatory_u_size_L(void){return ft_printf("%Lu", 42);}
int nocrash_mandatory_u_af(void){return ft_printf("%#u", 42);}
int nocrash_mandatory_u_sp(void){return ft_printf("% u", 42);}
int nocrash_mandatory_u_size_hhh(void){return ft_printf("%hhhu", 42);}
int nocrash_mandatory_u_size_hhhh(void){return ft_printf("%hhhhu", 42);}
int nocrash_mandatory_u_size_hhl(void){return ft_printf("%hhlu", 42);}
int nocrash_mandatory_u_size_hhll(void){return ft_printf("%hhllu", 42);}
int nocrash_mandatory_u_size_llh(void){return ft_printf("%llhu", 42);}
int nocrash_mandatory_u_size_lll(void){return ft_printf("%lllu", 42);}
int nocrash_mandatory_u_lj_nowidth(void){return ft_printf("%-u", 42);}

int nocrash_mandatory_x_size_L(void){return ft_printf("%Lx", 42);}
int nocrash_mandatory_x_sp(void){return ft_printf("% x", 42);}
int nocrash_mandatory_x_size_hhh(void){return ft_printf("%hhhx", 42);}
int nocrash_mandatory_x_size_hhhh(void){return ft_printf("%hhhhx", 42);}
int nocrash_mandatory_x_size_hhl(void){return ft_printf("%hhlx", 42);}
int nocrash_mandatory_x_size_hhll(void){return ft_printf("%hhllx", 42);}
int nocrash_mandatory_x_size_llh(void){return ft_printf("%llhx", 42);}
int nocrash_mandatory_x_size_lll(void){return ft_printf("%lllx", 42);}
int nocrash_mandatory_X_size_L(void){return ft_printf("%LX", 42);}
int nocrash_mandatory_X_sp(void){return ft_printf("% X", 42);}
int nocrash_mandatory_X_size_hhh(void){return ft_printf("%hhhX", 42);}
int nocrash_mandatory_X_size_llh(void){return ft_printf("%llhX", 42);}
int nocrash_mandatory_x_lj_nowidth(void){return ft_printf("%-x", 42);}

int nocrash_mandatory_f_size_hh(void){return ft_printf("%hhf", 42.5);}
int nocrash_mandatory_f_size_h(void){return ft_printf("%hf", 42.5);}
int nocrash_mandatory_f_size_ll(void){return ft_printf("%llf", 42.5);}
int nocrash_mandatory_f_size_lll(void){return ft_printf("%lllf", 42.5);}
int nocrash_mandatory_f_size_llll(void){return ft_printf("%llllf", 42.5);}
int nocrash_mandatory_f_size_LL(void){return ft_printf("%LLf", 42.5);}
int nocrash_mandatory_f_size_Ll(void){return ft_printf("%Llf", 42.5);}
int nocrash_mandatory_f_size_lL(void){return ft_printf("%lLf", 42.5);}
int nocrash_mandatory_f_lj_nowidth(void){return ft_printf("%-f", 42.5);}




//Moulinette tests

int		moul_s_1(void){return ft_printf(" pouet %s !!", "camembert");}

int		moul_s_2(void){return ft_printf("%s !", "Ceci n'est pas un \0 exercice !");}
int		moul_s_3(void){return ft_printf("%s!", "Ceci n'est toujours pas un exercice !");}
int		moul_s_4(void){char *str = NULL; return ft_printf("%s!", str);}

int		moul_s_5_this_ones_a_doozy(void){return ft_printf("%s",
		"Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");}

int moul_d_1(void){return ft_printf("%d", 42);}
int moul_d_2(void){return ft_printf("Kashim a %d histoires à raconter", 1001);}
int moul_d_3(void){return ft_printf("Il fait au moins %d\n", -8000);}
int moul_d_4(void){return ft_printf("%d", -0);}
int moul_d_5(void){return ft_printf("%d", 0);}
int moul_d_6(void){return ft_printf("%d", INT_MAX);}
int moul_d_7(void){return ft_printf("%d", INT_MIN);}
int moul_d_8(void){return ft_printf("%d", INT_MIN - 1);}
int moul_d_9(void){return ft_printf("%d", INT_MAX + 1);}
int moul_d_10(void){return ft_printf("%%d 0000042 == |%d|\n", 0000042);}
int moul_d_11(void){return ft_printf("%%d \t == |%d|\n", '\t');}
int moul_d_12(void){return ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_mix_1(void){int r00 = 0; return ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);}

int moul_c_1(void){return ft_printf("%c", 42);}
int moul_c_2(void){return ft_printf("Kashim a %c histoires à raconter", 1001);}
int moul_c_3(void){return ft_printf("Il fait au moins %c\n", -8000);}
int moul_c_4(void){return ft_printf("%c", -0);}
int moul_c_5(void){return ft_printf("%c", 0);}
int moul_c_5b(void){return ft_printf("%c\n", INT_MAX);}
int moul_c_6(void){return ft_printf("%c\n", 'c');}
int moul_c_7(void){return ft_printf("%c\n", '\n');}
int moul_c_8(void){return ft_printf("%c", 'l');}
int moul_c_9(void){return ft_printf("%c", 'y');}
int moul_c_10(void){return ft_printf("%c", ' ');}
int moul_c_11(void){return ft_printf("%c", 'e');}
int moul_c_12(void){return ft_printf("%c", 's');}
int moul_c_13(void){return ft_printf("%c", 't');}
int moul_c_14(void){return ft_printf("%c", ' ');}
int moul_c_15(void){return ft_printf("%c", 'f');}
int moul_c_16(void){return ft_printf("%c", 'a');}
int moul_c_17(void){return ft_printf("%c", 'n');}
int moul_c_18(void){return ft_printf("%c", 't');}
int moul_c_19(void){return ft_printf("%c", 'a');}
int moul_c_20(void){return ft_printf("%c", 's');}
int moul_c_21(void){return ft_printf("%c", 't');}
int moul_c_22(void){return ft_printf("%c", 'i');}
int moul_c_23(void){return ft_printf("%c", 'q');}
int moul_c_24(void){return ft_printf("%c", 'u');}
int moul_c_25(void){return ft_printf("%c", 'e');}
int moul_c_26(void){return ft_printf("%c\n", '!');}
int moul_c_27(void){return ft_printf("%c\n", '\r');}
int moul_c_28(void){return ft_printf("%c\n", '\t');}

int moul_i_1(void){return ft_printf("%i", 42);}
int moul_i_2(void){return ft_printf("Kashim a %i histoires à raconter", 1001);}
int moul_i_3(void){return ft_printf("Il fait au moins %i\n", -8000);}
int moul_i_4(void){return ft_printf("%i", -0);}
int moul_i_5(void){return ft_printf("%i", 0);}
int moul_i_6(void){return ft_printf("%i", INT_MAX);}
int moul_i_7(void){return ft_printf("%i", INT_MIN);}
int moul_i_8(void){return ft_printf("%i", INT_MIN - 1);}
int moul_i_9(void){return ft_printf("%i", INT_MAX + 1);}
int moul_i_10(void){return ft_printf("%%i 0000042 == |%i|\n", 0000042);}
int moul_i_11(void){return ft_printf("%%i \t == |%i|\n", '\t');}
int moul_i_12(void){return ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_u_1(void){return ft_printf("%u", 42);}
int moul_u_2(void){return ft_printf("Kashim a %u histoires à raconter", 1001);}
int moul_u_3(void){return ft_printf("Il fait au moins %u\n", -8000);}
int moul_u_4(void){return ft_printf("%u", -0);}
int moul_u_5(void){return ft_printf("%u", 0);}
int moul_u_6(void){return ft_printf("%u", INT_MAX);}
int moul_u_7(void){return ft_printf("%u", INT_MIN);}
int moul_u_8(void){return ft_printf("%u", INT_MIN - 1);}
int moul_u_9(void){return ft_printf("%u", INT_MAX + 1);}
int moul_u_10(void){return ft_printf("%%u 0000042 == |%u|\n", 0000042);}
int moul_u_11(void){return ft_printf("%%u \t == |%u|\n", '\t');}
int moul_u_12(void){return ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_x_1(void){return ft_printf("%x", 42);}
int moul_x_2(void){return ft_printf("Kashim a %x histoires à raconter", 1001);}
int moul_x_3(void){return ft_printf("Il fait au moins %x\n", -8000);}
int moul_x_4(void){return ft_printf("%x", -0);}
int moul_x_5(void){return ft_printf("%x", 0);}
int moul_x_6(void){return ft_printf("%x", INT_MAX);}
int moul_x_7(void){return ft_printf("%x", INT_MIN);}
int moul_x_8(void){return ft_printf("%x", INT_MIN - 1);}
int moul_x_9(void){return ft_printf("%x", INT_MAX + 1);}
int moul_x_10(void){return ft_printf("%%x 0000042 == |%x|\n", 0000042);}
int moul_x_11(void){return ft_printf("%%x \t == |%x|\n", '\t');}
int moul_x_12(void){return ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_prec_1(void){return ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");}
int moul_prec_3(void){return ft_printf("%%04.5i 42 == |%04.5i|\n", 42);}
int moul_prec_4(void){return ft_printf("%%04.3i 42 == |%04.3i|\n", 42);}
int moul_prec_5(void){return ft_printf("%%04.2i 42 == |%04.2i|\n", 42);}

int moul_zeropad_1(void){return ft_printf("%%04i 42 == |%04i|\n", 42);}
int moul_zeropad_2(void){return ft_printf("%%05i 42 == |%05i|\n", 42);}
int moul_zeropad_3(void){return ft_printf("%%0i 42 == |%0i|\n", 42);}
int moul_zeropad_4(void){return ft_printf("%%0d 0000042 == |%0d|\n", 0000042);}

int moul_leftjusty_1(void){return ft_printf("%%-i 42 == %-i\n", 42);}
int moul_leftjusty_2(void){return ft_printf("%%-d 42 == %-d\n", INT_MIN);}
int moul_leftjusty_3(void){return ft_printf("%%-i -42 == %-i\n", -42);}
int moul_leftjusty_4(void){return ft_printf("%%-4d 42 == |%-4d|\n", 42);}
int moul_leftjusty_5(void){return ft_printf("%%-5d -42 == |%-5d|\n", -42);}
int moul_leftjusty_6(void){return ft_printf("|%3i|%-3i|\n", 42, 42);}
int moul_leftjusty_7(void){return ft_printf("%%-4i 42 == |%-4i|\n", 42);}

int moul_notmandatory_star_1(void){return ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");}
int moul_notmandatory_star_3(void){return ft_printf("%%*i 42 == |%*i|\n", 5, 42);}
int moul_notmandatory_star_4(void){return ft_printf("%%*i 42 == |%*i|\n", 3, 42);}
int moul_notmandatory_star_5(void){return ft_printf("%%*i 42 == |%*i|\n", 2, 42);}



int new2019_star_1(void){return ft_printf("%*s", 32, "abc");}
int new2019_star_2(void){return ft_printf("%-*s", 32, "abc");}
int new2019_star_3(void){return ft_printf("%*s", 3, "hello");}
int new2019_star_4(void){return ft_printf("%.*s", 3, "hello");}
int new2019_star_5(void){return ft_printf("%.*s", 0, "hello");}
int new2019_star_6(void){return ft_printf("%-*.*s", 7, 3, "yolo");}
int new2019_star_7(void){return ft_printf("%*i", 4, 94827);}
int new2019_star_8(void){return ft_printf("%*i", 14, 94827);}
int new2019_star_9(void){return ft_printf("%.*i", 6, -3);}
int new2019_star_10(void){return ft_printf("%0*i", 7, -54);}
int new2019_negstar_1(void){return ft_printf("%*s", -32, "abc");}
int new2019_negstar_2(void){return ft_printf("%-*s", -32, "abc");}
int new2019_negstar_3(void){return ft_printf("%*s", -3, "hello");}
int new2019_negstar_4(void){return ft_printf("%.*s", -3, "hello");}
int new2019_negstar_5(void){return ft_printf("%-*.*s", -7, -3, "yolo");}
int new2019_negstar_6(void){return ft_printf("%*i", -4, 94827);}
int new2019_negstar_7(void){return ft_printf("%*i", -14, 94827);}
int new2019_negstar_8(void){return ft_printf("%.*i", -6, -3);}
int new2019_negstar_9(void){return ft_printf("%0*i", -7, -54);}

#pragma clang diagnostic pop
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <gfielder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/11/19 18:06:44 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winteger-overflow"
#pragma clang diagnostic ignored "-Wformat"

#include "test.h"

/* -----------------------------------------------------------------------------
** Add unit tests to this file
**
** A valid unit test is prototyped
**
**    int   foo(void)
**
** and includes a call to the function:
**
**    int    printf(const char *fmt, ...)
**
** ---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
** unit tests that start with "nocrash_" will always pass
**     (provided it doesn't crash)
** ---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
** A unit test is ENABLED if it has no whitespace preceding it
** A unit test is DISABLED if it has whitespace preceding it
**
** scripts are provided to enable and disable tests by prefix
** ---------------------------------------------------------------------------*/


//Tests with no specifiers
int		nospec_no_specifier_test_bench(void){return printf("hello, world!");}
int		nospec_empty_string_bench(void){return printf("");}
int		nospec_some_escaped_chars_bench(void){return printf("\t\n\r\v\f\n");}

//Nospec tests with successive calls
int		nospec_successive_5_5_bench(void){return ( printf("hello") + printf("world"));}
int		nospec_successive_2_9_bench(void){return ( printf("he") ^ printf(" is alive"));}
int		nospec_successive_8_3_bench(void){return ( printf("is alive") - printf(" he"));}

//%% Tests
int		pct_basic_bench(void){return printf("%%");}
int		pct_5w_bench(void){return printf("%5%");}
int		pct_5wlj_bench(void){return printf("%-5%");}
int		pct_5wzp_bench(void){return printf("%05%");}
int		pct_5wljzp_bench(void){return printf("%-05%");}

//Null specifier tests
int		nocrash_nullspec_basic_bench(void){return printf("%");}
int		nocrash_nullspec_5w_bench(void){return printf("%5");}
int		nocrash_nullspec_5wzp_bench(void){return printf("%05");}
int		nocrash_nullspec_5wzplj_bench(void){return printf("%-05");}
int		nocrash_nullspec_5wlj_bench(void){return printf("%-5");}

//String specifiers - no modifiers
int s_basic_string_expansion_bench(void){return printf("hello, %s.", "gavin");}
int s_only_string_expansion_bench(void){return printf("%s", "testing testing");}
int s_two_string_expansions_bench(void){return printf("%s%s", "hello", "world");}
int s_two_string_expansions2_bench(void){return printf("..%s stuff %s", "a", "b");}
int s_empty_string_expansion_bench(void){return printf("this %s is empty", "");}
int s_full_then_empty_string_bench(void){return printf("this %s is %s", "hello", "");}
int s_empty_then_full_string_bench(void){return printf("this %s is %s", "", "hello");}
int s_three_strings_bench(void){return printf("%s%s%s", "1", "2", "3's a charm");}
//String specifiers with field_width, space- or zero-padded
int s_space_padded_field_width_bench(void){return printf("%32s", "abc");}
int s_space_padded_field_width2_bench(void){return printf("%16s", "nark nark");}
int s_space_padded_over_field_width_bench(void){return printf("%5s", "goes over");}
//String specifiers with field_width, space- or zero-padded, left-justified
int s_space_padded_field_width_lj_bench(void){return printf("%-32s", "abc");}
int s_space_padded_field_width2_lj_bench(void){return printf("%-16s", "nark nark");}
int s_space_padded_over_field_width_lj_bench(void){return printf("%-5s", "goes over");}
//String specifiers with precision
int s_string_prec_notrunc_bench(void){return printf("%.7s", "hello");}
int s_string_prec_trunc_bench(void){return printf("%.3s", "hello");}
int s_string_prec_default_bench(void){return printf("%.s", "hello");}
int s_string_prec_zero_bench(void){return printf("%.0s", "hello");}
int s_two_strings_prec_2trunc_bench(void){return printf("%.3s%.2s", "holla", "bitch");}
int s_two_strings_prec_1trunc_a_bench(void){return printf("%.2s%.7s", "hello", "world");}
int s_two_strings_prec_1trunc_b_bench(void){return printf("%.7s%.2s", "hello", "world");}
int s_two_strings_prec_0trunc_bench(void){return printf("%.5s%7s", "yo", "boi");}
//String specifiers with both precision and field width
int s_string_prec_width_notrunc_bench(void){return printf("%7.5s", "yolo");}
int s_string_prec_width_trunc_bench(void){return printf("%7.5s", "bombastic");}
int s_string_prec_width_notrunc_lj_bench(void){return printf("%-7.5s", "yolo");}
int s_string_prec_width_trunc_lj_bench(void){return printf("%-7.5s", "tubular");}
int s_two_s_prec_width_2fit_0trunc_bench(void){return printf("%7.7s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_a_0trunc_bench(void){return printf("%3.7s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_b_0trunc_bench(void){return printf("%7.7s%3.7s", "hello", "world");}
int s_two_s_prec_width_0fit_0trunc_bench(void){return printf("%3.7s%3.7s", "hello", "world");}
int s_two_s_prec_width_2fit_1trunc_a_bench(void){return printf("%7.3s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_a_1trunc_a_bench(void){return printf("%3.3s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_b_1trunc_a_bench(void){return printf("%7.3s%3.7s", "hello", "world");}
int s_two_s_prec_width_0fit_1trunc_a_bench(void){return printf("%3.3s%3.7s", "hello", "world");}
int s_two_s_prec_width_2fit_1trunc_b_bench(void){return printf("%7.7s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_a_1trunc_b_bench(void){return printf("%3.7s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_b_1trunc_b_bench(void){return printf("%7.7s%3.3s", "hello", "world");}
int s_two_s_prec_width_0fit_1trunc_b_bench(void){return printf("%3.7s%3.3s", "hello", "world");}
int s_two_s_prec_width_2fit_2trunc_bench(void){return printf("%7.3s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_a_2trunc_bench(void){return printf("%3.3s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_b_2trunc_bench(void){return printf("%7.3s%3.3s", "hello", "world");}
int s_two_s_prec_width_0fit_2trunc_bench(void){return printf("%3.3s%3.3s", "hello", "world");}
int s_two_s_prec_width_2trunc_bench(void){return printf("%3s%3s", "hello", "world");}
//String specifiers, other tests
int s_two_strings_lj_and_rj_bench(void){return printf("%-7s%5s", "hello", "world");}
int s_two_strings_rj_and_lj_bench(void){return printf("%7s%-5s", "hello", "world");}
//String specifiers - NULL strings
int s_null_basic_string_expansion_bench(void){return printf("hello, %s.", NULL);}
int s_null_only_string_expansion_bench(void){return printf("%s", NULL);}
int s_null_space_padded_field_width_bench(void){return printf("%32s", NULL);}
int s_null_space_padded_over_field_width_bench(void){return printf("%2s", NULL);}
int s_null_space_padded_field_width_lj_bench(void){return printf("%-32s", NULL);}
int s_null_space_padded_field_width2_lj_bench(void){return printf("%-16s", NULL);}
int s_null_space_padded_over_field_width_lj_bench(void){return printf("%-3s", NULL);}
//String specifiers with precision
int s_null_string_prec_notrunc_bench(void){return printf("%.9s", "NULL");}
int s_null_string_prec_trunc_bench(void){return printf("%.3s", "NULL");}
int s_null_string_prec_default_bench(void){return printf("%.s", "NULL");}
int s_null_string_prec_zero_bench(void){return printf("%.0s", "NULL");}


int s_basic_s_hidden_bench(void){return printf("%s", s_hidden);}
// width pad
int s_width_3_s_hidden_bench(void){return printf("%3s", s_hidden);}
int s_width_9_s_hidden_bench(void){return printf("%9s", s_hidden);}
// precision no width
int s_prec_no_width_s_hidden_bench(void){return printf("%.s", s_hidden);}
int s_prec_9_no_width_s_hidden_bench(void){return printf("%.9s", s_hidden);}
// precision  0 before number
int s_prec_03_no_width_s_hidden_bench(void){return printf("%.03s", s_hidden);}
int s_prec_09_no_width_s_hidden_bench(void){return printf("%.09s", s_hidden);}
int s_prec_03_no_width_s_null_bench(void){return printf("%.03s", NULL);}
int s_prec_09_no_width_s_null_bench(void){return printf("%.09s", NULL);}
int s_prec_00_no_width_s_nullchar_bench(void){return printf("%.00s", "\0");}
int s_prec_01_no_width_s_nullchar_bench(void){return printf("%.01s", "\0");}
int s_prec_03_no_width_s_nullchar_bench(void){return printf("%.03s", "\0");}
int s_prec_09_no_width_s_nullchar_bench(void){return printf("%.09s", "\0");}
// width  no precision
int s_prec_0_width_3_s_hidden_bench(void){return printf("%3.s", s_hidden);}
int s_prec_0_width_10_s_hidden_bench(void){return printf("%10.s", s_hidden);}
int s_prec_0_width_3_s_null_bench(void){return printf("%3.s", NULL);}
int s_prec_0_width_10_s_null_bench(void){return printf("%10.s", NULL);}
int s_prec_0_width_1_s_nullchar_bench(void){return printf("%1.s", "\0");}
int s_prec_0_width_2_s_nullchar_bench(void){return printf("%2.s", "\0");}
int s_prec_0_width_9_s_nullchar_bench(void){return printf("%9.s", "\0");}
// lj flag width  no precision
int s_prec_0_lj_width_3_s_hidden_bench(void){return printf("%-3.s", s_hidden);}
int s_prec_0_lj_width_8_s_hidden_bench(void){return printf("%-8.s", s_hidden);}
int s_prec_0_lj_width_3_s_null_bench(void){return printf("%-3.s", NULL);}
int s_prec_0_lj_width_8_s_null_bench(void){return printf("%-8.s", NULL);}
int s_prec_0_lj_width_1_s_nullchar_bench(void){return printf("%-1.s", "\0");}
int s_prec_0_lj_width_2_s_nullchar_bench(void){return printf("%-2.s", "\0");}
int s_prec_0_lj_width_6_s_nullchar_bench(void){return printf("%-6.s", "\0");}
// width  precision 1
int s_prec_1_width_3_s_hidden_bench(void){return printf("%3.1s", s_hidden);}
int s_prec_1_width_10_s_hidden_bench(void){return printf("%10.1s", s_hidden);}
int s_prec_1_width_3_s_null_bench(void){return printf("%3.1s", NULL);}
int s_prec_1_width_9_s_null_bench(void){return printf("%9.1s", NULL);}
// lj flag width  precision 1
int s_prec_1_lj_width_3_s_hidden_bench(void){return printf("%-3.1s", s_hidden);}
int s_prec_1_lj_width_10_s_hidden_bench(void){return printf("%-10.1s", s_hidden);}
int s_prec_1_lj_width_3_s_null_bench(void){return printf("%-3.1s", NULL);}
int s_prec_1_lj_width_9_s_null_bench(void){return printf("%-9.1s", NULL);}
int s_prec_1_lj_width_3_s_nullchar_bench(void){return printf("%-3.1s", "\0");}
int s_prec_1_lj_width_6_s_nullchar_bench(void){return printf("%-6.1s", "\0");}
// width  exact precision
int s_prec_perfect_width_3_s_hidden_bench(void){return printf("%3.6s", s_hidden);}
int s_prec_perfect_width_20_s_hidden_bench(void){return printf("%20.6s", s_hidden);}
int s_prec_perfect_width_3_s_null_bench(void){return printf("%3.6s", NULL);}
int s_prec_perfect_width_20_s_null_bench(void){return printf("%20.6s", NULL);}
int s_prec_perfect_width_3_s_nullchar_bench(void){return printf("%3.6s", "\0");}
int s_prec_perfect_width_6_s_nullchar_bench(void){return printf("%6.6s", "\0");}
// lj flag width exact precision
int s_prec_perfect_lj_width_3_s_hidden_bench(void){return printf("%-3.6s", s_hidden);}
int s_prec_perfect_lj_width_20_s_hidden_bench(void){return printf("%-20.6s", s_hidden);}
// lj flag width excess precision
int s_prec_8_lj_width_3_s_hidden_bench(void){return printf("%-3.8s", s_hidden);}
int s_prec_8_lj_width_10_s_hidden_bench(void){return printf("%-10.8s", s_hidden);}
int s_prec_8_lj_width_3_s_null_bench(void){return printf("%-3.8s", NULL);}
int s_prec_8_lj_width_10_s_null_bench(void){return printf("%-10.8s", NULL);}
// decoy lj flag
int s_prec_00_lj_s_hidden_trunc_bench(void){return printf("%-.00s", s_hidden);}
int s_prec_09_lj_s_hidden_notrunc_bench(void){return printf("%-.09s", s_hidden);}
// multi zeros
int	s_undefbehav_0_2zero_bench(void){return printf("%00s", s_hidden);}
int	s_undefbehav_0_3zero_bench(void){return printf("%000s", s_hidden);}
int	s_undefbehav_0_4zero_bench(void){return printf("%0000s", s_hidden);}
int	s_undefbehav_0_lj_2zero_bench(void){return printf("%-00s", s_hidden);}
int	s_undefbehav_0_zero_lj_zero_bench(void){return printf("%0-0s", s_hidden);}
int	s_undefbehav_0_2zero_lj_bench(void){return printf("%00-s", s_hidden);}
// zero and width
int	s_undefbehav_0_width_3_bench(void){return printf("%03s", s_hidden);}
int	s_undefbehav_0_width_9_bench(void){return printf("%09s", s_hidden);}
// flag cancelling
int	s_undefbehav_lj_0_width_3_bench(void){return printf("%-03s", s_hidden);}
int	s_undefbehav_lj_0_width_9_bench(void){return printf("%-09s", s_hidden);}

//Signed integers - no modifers
int		i_basic_i_pos_bench(void){return printf("this %i number", 17);}
int		i_basic_i_neg_bench(void){return printf("this %i number", -267);}
int		i_basic_i_zero_bench(void){return printf("this %i number", 0);}
int		i_basic_i_onlypos_bench(void){return printf("%i", 3);}
int		i_basic_i_onlyneg_bench(void){return printf("%i", -1);}
int		i_basic_i_onlyzero_bench(void){return printf("%i", 0);}
int		d_basic_pos_bench(void){return printf("this %d number", 17);}
int		d_basic_neg_bench(void){return printf("this %d number", -267);}
int		d_basic_zero_bench(void){return printf("this %d number", 0);}
int		i_intmax_bench(void){return printf("%i",  2147483647);}
int		i_intmin_bench(void){return printf("%i", (int)(-2147483678));}
//Signed integers  field width
int		i_width_pos_fits_bench(void){return printf("%7i", 33);}
int		i_width_neg_fits_bench(void){return printf("%7i", -14);}
int		i_width_zero_fits_bench(void){return printf("%3i", 0);}
int		i_width_pos_exactfit_bench(void){return printf("%5i", 52625);}
int		i_width_neg_exactfit_bench(void){return printf("%5i", -2562);}
int		i_width_pos_nofit_bench(void){return printf("%4i", 94827);}
int		i_width_neg_nofit_bench(void){return printf("%4i", -2464);}
int		i_width_pos_fits_lj_bench(void){return printf("%-7i", 33);}
int		i_width_neg_fits_lj_bench(void){return printf("%-7i", -14);}
int		i_width_zero_fits_lj_bench(void){return printf("%-3i", 0);}
int		i_width_pos_exactfit_lj_bench(void){return printf("%-5i", 52625);}
int		i_width_neg_exactfit_lj_bench(void){return printf("%-5i", -2562);}
int		i_width_pos_nofit_lj_bench(void){return printf("%-4i", 94827);}
int		i_width_neg_nofit_lj_bench(void){return printf("%-4i", -2464);}
//signed integers with precision
int		i_prec_fits_pos_bench(void){return printf("%.5i", 2);}
int		i_prec_fits_neg_bench(void){return printf("%.6i", -3);}
int		i_prec_fits_zero_bench(void){return printf("%.3i", 0);}
int		i_prec_exactfit_pos_bench(void){return printf("%.4i", 5263);}
int		i_prec_exactfit_neg_bench(void){return printf("%.4i", -2372);}
int		i_prec_nofit_pos_bench(void){return printf("%.3i", 13862);}
int		i_prec_nofit_neg_bench(void){return printf("%.3i",-23646);}
//Signed integers with zero field width padding
int		i_zp_pos_fits_bench(void){return printf("%05i", 43);}
int		i_zp_neg_fits_bench(void){return printf("%07i", -54);}
int		i_zp_zero_fits_bench(void){return printf("%03i", 0);}
int		i_zp_pos_exactfit_bench(void){return printf("%03i", 634);}
int		i_zp_neg_exactfit_bench(void){return printf("%04i", -532);}
int		i_zp_neg_minus1fit_bench(void){return printf("%04i", -4825);}
//Signed integers with field width and precision
int		i_prec_width_fit_fit_pos_bench(void){return printf("%8.5i", 34);}
int		i_prec_width_fit_fit_neg_bench(void){return printf("%10.5i", -216);}
int		i_prec_width_fit_fit_zero_bench(void){return printf("%8.5i", 0);}
int		i_prec_width_nofit_fit_pos_bench(void){return printf("%8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_bench(void){return printf("%8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_bench(void){return printf("%3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_bench(void){return printf("%3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_bench(void){return printf("%3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_bench(void){return printf("%3.3i", -8462);}
//Signed integers with field width and precision, left-justified
int		i_prec_width_fit_fit_pos_lj_bench(void){return printf("%-8.5i", 34);}
int		i_prec_width_fit_fit_neg_lj_bench(void){return printf("%-10.5i", -216);}
int		i_prec_width_fit_fit_zero_lj_bench(void){return printf("%-8.5i", 0);}
int		i_prec_width_nofit_fit_pos_lj_bench(void){return printf("%-8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_lj_bench(void){return printf("%-8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_lj_bench(void){return printf("%-3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_lj_bench(void){return printf("%-3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_lj_bench(void){return printf("%-3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_lj_bench(void){return printf("%-3.3i", -8462);}
//Signed integers with field width and precision with zeropadding
int		i_prec_width_ff_pos_zp_bench(void){return printf("%08.5i", 34);}
int		i_prec_width_ff_neg_zp_bench(void){return printf("%010.5i", -216);}
int		i_prec_width_ff_zero_zp_bench(void){return printf("%08.5i", 0);}
int		i_prec_width_nf_pos_zp_bench(void){return printf("%08.3i", 8375);}
int		i_prec_width_nf_neg_zp_bench(void){return printf("%08.3i", -8473);}
int		i_prec_width_fn_pos_zp_bench(void){return printf("%03.7i", 3267);}
int		i_prec_width_fn_neg_zp_bench(void){return printf("%03.7i", -2375);}
int		i_prec_width_nn_pos_zp_bench(void){return printf("%03.3i", 6983);}
int		i_prec_width_nn_neg_zp_bench(void){return printf("%03.3i", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int		i_prec_width_ff_pos_lj_zp_ignoreflag_bench(void){return printf("%0-8.5i", 34);}
int		i_prec_width_ff_neg_ljzp_ignoreflag_bench(void){return printf("%0-10.5i", -216);}
int		i_prec_width_ff_zero_ljzp_ignoreflag_bench(void){return printf("%0-8.5i", 0);}
int		i_prec_width_nf_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.3i", 8375);}
int		i_prec_width_nf_neg_ljzp_ignoreflag_bench(void){return printf("%0-8.3i", -8473);}
int		i_prec_width_fn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.7i", 3267);}
int		i_prec_width_fn_neg_ljzp_ignoreflag_bench(void){return printf("%0-3.7i", -2375);}
int		i_prec_width_nn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.3i", 6983);}
int		i_prec_width_nn_neg_ljzp_ignoreflag_bench(void){return printf("%0-3.3i", -8462);}



//Signed integers of varying size modifiers with some other modifiers
int		i_size_follows_i_i_bench(void){return printf("[%i] [%i]", i_pos_1, i_pos_1);}
 //Signed integers - zero precision zero value
int i_prec0val0_basic_bench(void){return printf("%.0i", 0);}
int i_prec0val0_implicit_bench(void){return printf("%.i", 0);}
int i_prec0val0_w_bench(void){return printf("%5.0i", 0);}
int i_prec0val0_w_impl_bench(void){return printf("%5.i", 0);}
int i_prec0val0_wlj_bench(void){return printf("%-5.0i", 0);}
int i_prec0val0_wlj_impl_bench(void){return printf("%-5.i", 0);}

//Signed integers - no modifers
int	 d_basic_i_pos_bench(void){return printf("this %d number", 17);}
int	 d_basic_i_neg_bench(void){return printf("this %d number", -267);}
int	 d_basic_i_zero_bench(void){return printf("this %d number", 0);}
int	 d_basic_i_onlypos_bench(void){return printf("%d", 3);}
int	 d_basic_i_onlyneg_bench(void){return printf("%d", -1);}
int	 d_basic_i_onlyzero_bench(void){return printf("%d", 0);}
int	 d_intmax_bench(void){return printf("%d",  2147483647);}
int	 d_intmin_bench(void){return printf("%d", (int)(-2147483678));}
//Signed integers with field width
int	 d_width_pos_fits_bench(void){return printf("%7d", 33);}
int	 d_width_neg_fits_bench(void){return printf("%7d", -14);}
int	 d_width_zero_fits_bench(void){return printf("%3d", 0);}
int	 d_width_pos_exactfit_bench(void){return printf("%5d", 52625);}
int	 d_width_neg_exactfit_bench(void){return printf("%5d", -2562);}
int	 d_width_pos_nofit_bench(void){return printf("%4d", 94827);}
int	 d_width_neg_nofit_bench(void){return printf("%4d", -2464);}
int	 d_width_pos_fits_lj_bench(void){return printf("%-7d", 33);}
int	 d_width_neg_fits_lj_bench(void){return printf("%-7d", -14);}
int	 d_width_zero_fits_lj_bench(void){return printf("%-3d", 0);}
int	 d_width_pos_exactfit_lj_bench(void){return printf("%-5d", 52625);}
int	 d_width_neg_exactfit_lj_bench(void){return printf("%-5d", -2562);}
int	 d_width_pos_nofit_lj_bench(void){return printf("%-4d", 94827);}
int	 d_width_neg_nofit_lj_bench(void){return printf("%-4d", -2464);}
//signed integers with precision
int	 d_prec_fits_pos_bench(void){return printf("%.5d", 2);}
int	 d_prec_fits_neg_bench(void){return printf("%.6d", -3);}
int	 d_prec_fits_zero_bench(void){return printf("%.3d", 0);}
int	 d_prec_exactfit_pos_bench(void){return printf("%.4d", 5263);}
int	 d_prec_exactfit_neg_bench(void){return printf("%.4d", -2372);}
int	 d_prec_nofit_pos_bench(void){return printf("%.3d", 13862);}
int	 d_prec_nofit_neg_bench(void){return printf("%.3d",-23646);}
//Signed integers with zero field width padding
int	 d_zp_pos_fits_bench(void){return printf("%05d", 43);}
int	 d_zp_neg_fits_bench(void){return printf("%07d", -54);}
int	 d_zp_zero_fits_bench(void){return printf("%03d", 0);}
int	 d_zp_pos_exactfit_bench(void){return printf("%03d", 634);}
int	 d_zp_neg_exactfit_bench(void){return printf("%04d", -532);}
int	 d_zp_neg_minus1fit_bench(void){return printf("%04d", -4825);}
//Signed integers with field width and precision
int	 d_prec_width_fit_fit_pos_bench(void){return printf("%8.5d", 34);}
int	 d_prec_width_fit_fit_neg_bench(void){return printf("%10.5d", -216);}
int	 d_prec_width_fit_fit_zero_bench(void){return printf("%8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_bench(void){return printf("%8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_bench(void){return printf("%8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_bench(void){return printf("%3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_bench(void){return printf("%3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_bench(void){return printf("%3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_bench(void){return printf("%3.3d", -8462);}
//Signed integers with field width and precision, left-justified
int	 d_prec_width_fit_fit_pos_lj_bench(void){return printf("%-8.5d", 34);}
int	 d_prec_width_fit_fit_neg_lj_bench(void){return printf("%-10.5d", -216);}
int	 d_prec_width_fit_fit_zero_lj_bench(void){return printf("%-8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_lj_bench(void){return printf("%-8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_lj_bench(void){return printf("%-8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_lj_bench(void){return printf("%-3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_lj_bench(void){return printf("%-3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_lj_bench(void){return printf("%-3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_lj_bench(void){return printf("%-3.3d", -8462);}
//Signed integers with field width and precision with zeropadding
int	 d_prec_width_ff_pos_zp_bench(void){return printf("%08.5d", 34);}
int	 d_prec_width_ff_neg_zp_bench(void){return printf("%010.5d", -216);}
int	 d_prec_width_ff_zero_zp_bench(void){return printf("%08.5d", 0);}
int	 d_prec_width_nf_pos_zp_bench(void){return printf("%08.3d", 8375);}
int	 d_prec_width_nf_neg_zp_bench(void){return printf("%08.3d", -8473);}
int	 d_prec_width_fn_pos_zp_bench(void){return printf("%03.7d", 3267);}
int	 d_prec_width_fn_neg_zp_bench(void){return printf("%03.7d", -2375);}
int	 d_prec_width_nn_pos_zp_bench(void){return printf("%03.3d", 6983);}
int	 d_prec_width_nn_neg_zp_bench(void){return printf("%03.3d", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int	 d_prec_width_ff_pos_lj_zp_ignoreflag_bench(void){return printf("%0-8.5d", 34);}
int	 d_prec_width_ff_neg_ljzp_ignoreflag_bench(void){return printf("%0-10.5d", -216);}
int	 d_prec_width_ff_zero_ljzp_ignoreflag_bench(void){return printf("%0-8.5d", 0);}
int	 d_prec_width_nf_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljzp_ignoreflag_bench(void){return printf("%0-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljzp_ignoreflag_bench(void){return printf("%0-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljzp_ignoreflag_bench(void){return printf("%0-3.3d", -8462);}
 //Signed integers - zero precision zero value
int d_prec0val0_basic_bench(void){return printf("%.0d", 0);}
int d_prec0val0_implicit_bench(void){return printf("%.d", 0);}
int d_prec0val0_w_bench(void){return printf("%5.0d", 0);}
int d_prec0val0_w_impl_bench(void){return printf("%5.d", 0);}
int d_prec0val0_wlj_bench(void){return printf("%-5.0d", 0);}
int d_prec0val0_wlj_impl_bench(void){return printf("%-5.d", 0);}

//Unsigned integers - no modifers
int u_basic_u_pos_bench(void){return printf("this %u number", 17);}
int u_basic_u_zero_bench(void){return printf("this %u number", 0);}
int u_basic_u_onlypos_bench(void){return printf("%u", 3);}
int u_uintmax_bench(void){return printf("%u", 4294967295u);}
//Unsigned integers with field width
int u_width_pos_fits_bench(void){return printf("%7u", 33);}
int u_width_zero_fits_bench(void){return printf("%3u", 0);}
int u_width_pos_exactfit_bench(void){return printf("%5u", 52625);}
int u_width_pos_nofit_bench(void){return printf("%4u", 94827);}
int u_width_pos_fits_lj_bench(void){return printf("%-7u", 33);}
int u_width_zero_fits_lj_bench(void){return printf("%-3u", 0);}
int u_width_pos_exactfit_lj_bench(void){return printf("%-5u", 52625);}
int u_width_pos_nofit_lj_bench(void){return printf("%-4u", 94827);}
//unsigned integers with precision
int u_prec_fits_pos_bench(void){return printf("%.5u", 2);}
int u_prec_fits_zero_bench(void){return printf("%.3u", 0);}
int u_prec_exactfit_pos_bench(void){return printf("%.4u", 5263);}
int u_prec_nofit_pos_bench(void){return printf("%.3u", 13862);}
//Unsigned integers with zero field width padding
int u_zp_pos_fits_bench(void){return printf("%05u", 43);}
int u_zp_zero_fits_bench(void){return printf("%03u", 0);}
int u_zp_pos_exactfit_bench(void){return printf("%03u", 634);}
//Unsigned integers with field width and precision
int u_prec_width_fit_fit_pos_bench(void){return printf("%8.5u", 34);}
int u_prec_width_fit_fit_zero_bench(void){return printf("%8.5u", 0);}
int u_prec_width_nofit_fit_pos_bench(void){return printf("%8.3u", 8375);}
int u_prec_width_fit_nofit_pos_bench(void){return printf("%3.7u", 3267);}
int u_prec_width_nofit_nofit_pos_bench(void){return printf("%3.3u", 6983);}
//Unsigned integers with field width and precision, left-justified
int u_prec_width_fit_fit_pos_lj_bench(void){return printf("%-8.5u", 34);}
int u_prec_width_fit_fit_zero_lj_bench(void){return printf("%-8.5u", 0);}
int u_prec_width_nofit_fit_pos_lj_bench(void){return printf("%-8.3u", 8375);}
int u_prec_width_fit_nofit_pos_lj_bench(void){return printf("%-3.7u", 3267);}
int u_prec_width_nofit_nofit_pos_lj_bench(void){return printf("%-3.3u", 6983);}
//Unsigned integers with field width and precision with zeropadding
int u_prec_width_ff_pos_zp_bench(void){return printf("%08.5u", 34);}
int u_prec_width_ff_zero_zp_bench(void){return printf("%08.5u", 0);}
int u_prec_width_nf_pos_zp_bench(void){return printf("%08.3u", 8375);}
int u_prec_width_fn_pos_zp_bench(void){return printf("%03.7u", 3267);}
int u_prec_width_nn_pos_zp_bench(void){return printf("%03.3u", 6983);}
//Unsigned integers with field width and precision, left-justified with zeropadding
int u_prec_width_ff_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.5u", 34);}
int u_prec_width_ff_zero_ljzp_ignoreflag_bench(void){return printf("%0-8.5u", 0);}
int u_prec_width_nf_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.3u", 8375);}
int u_prec_width_fn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.7u", 3267);}
int u_prec_width_nn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.3u", 6983);}
//Unsigned integers - zero precision zero value
int u_prec0val0_basic_bench(void){return printf("%.0u", 0);}
int u_prec0val0_implicit_bench(void){return printf("%.u", 0);}
int u_prec0val0_w_bench(void){return printf("%5.0u", 0);}
int u_prec0val0_w_impl_bench(void){return printf("%5.u", 0);}
int u_prec0val0_wlj_bench(void){return printf("%-5.0u", 0);}
int u_prec0val0_wlj_impl_bench(void){return printf("%-5.u", 0);}

//Hexadecimal lowers - no modifers
int x_basic_pos_bench(void){return printf("this %x number", 17);}
int x_basic_zero_bench(void){return printf("this %x number", 0);}
int x_basic_onlypos_bench(void){return printf("%x", 3);}
int x_hexlmax_bench(void){return printf("%x", 4294967295u);}
//Hexadecimal lowers with field width
int x_width_pos_fits_bench(void){return printf("%7x", 33);}
int x_width_zero_fits_bench(void){return printf("%3x", 0);}
int x_width_pos_exactfit_bench(void){return printf("%5x", 52625);}
int x_width_pos_nofit_bench(void){return printf("%2x", 94827);}
int x_width_pos_fits_lj_bench(void){return printf("%-7x", 33);}
int x_width_zero_fits_lj_bench(void){return printf("%-3x", 0);}
int x_width_pos_exactfit_lj_bench(void){return printf("%-5x", 52625);}
int x_width_pos_nofit_lj_bench(void){return printf("%-4x", 9648627);}
//Hexadecimal lowers with precision
int x_prec_fits_pos_bench(void){return printf("%.5x", 21);}
int x_prec_fits_zero_bench(void){return printf("%.3x", 0);}
int x_prec_exactfit_pos_bench(void){return printf("%.4x", 5263);}
int x_prec_nofit_pos_bench(void){return printf("%.3x", 938862);}
//Hexadecimal lowers with zero field width padding
int x_zp_pos_fits_bench(void){return printf("%05x", 43);}
int x_zp_zero_fits_bench(void){return printf("%03x", 0);}
int x_zp_pos_exactfit_bench(void){return printf("%03x", 698334);}
//Hexadecimal lowers with field width and precision
int x_prec_width_fit_fit_pos_bench(void){return printf("%8.5x", 34);}
int x_prec_width_fit_fit_zero_bench(void){return printf("%8.5x", 0);}
int x_prec_width_nofit_fit_pos_bench(void){return printf("%8.3x", 8375);}
int x_prec_width_fit_nofit_pos_bench(void){return printf("%2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_bench(void){return printf("%3.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified
int x_prec_width_fit_fit_pos_lj_bench(void){return printf("%-8.5x", 34);}
int x_prec_width_fit_fit_zero_lj_bench(void){return printf("%-8.5x", 0);}
int x_prec_width_nofit_fit_pos_lj_bench(void){return printf("%-8.3x", 8375);}
int x_prec_width_fit_nofit_pos_lj_bench(void){return printf("%-2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_lj_bench(void){return printf("%-3.3x", 6983);}
//Hexadecimal lowers with field width and precision with zeropadding
int x_prec_width_ff_pos_zp_bench(void){return printf("%08.5x", 34);}
int x_prec_width_ff_zero_zp_bench(void){return printf("%08.5x", 0);}
int x_prec_width_nf_pos_zp_bench(void){return printf("%08.3x", 8375);}
int x_prec_width_fn_pos_zp_bench(void){return printf("%02.7x", 3267);}
int x_prec_width_nn_pos_zp_bench(void){return printf("%03.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified with zeropadding
int x_prec_width_ff_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.5x", 34);}
int x_prec_width_ff_zero_ljzp_ignoreflag_bench(void){return printf("%0-8.5x", 0);}
int x_prec_width_nf_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.3x", 8375);}
int x_prec_width_fn_pos_ljzp_ignoreflag_bench(void){return printf("%0-2.7x", 3267);}
int x_prec_width_nn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.3x", 6983);}
 //Hexadecimal lower - zero precision zero value
int x_prec0val0_basic_bench(void){return printf("%.0x", 0);}
int x_prec0val0_implicit_bench(void){return printf("%.x", 0);}
int x_prec0val0_w_bench(void){return printf("%5.0x", 0);}
int x_prec0val0_w_impl_bench(void){return printf("%5.x", 0);}
int x_prec0val0_wlj_bench(void){return printf("%-5.0x", 0);}
int x_prec0val0_wlj_impl_bench(void){return printf("%-5.x", 0);}


//Hexadecimal uppers - no modifers
int X_basic_hexu_pos_bench(void){return printf("this %X number", 17);}
int X_basic_hexu_zero_bench(void){return printf("this %X number", 0);}
int X_basic_hexu_onlypos_bench(void){return printf("%X", 3);}
int X_hexumax_bench(void){return printf("%X", 4294967295u);}
//Hexadecimal uppers with field width
int X_width_pos_fits_bench(void){return printf("%7X", 33);}
int X_width_zero_fits_bench(void){return printf("%3X", 0);}
int X_width_pos_exactfit_bench(void){return printf("%5X", 52625);}
int X_width_pos_nofit_bench(void){return printf("%2X", 94827);}
int X_width_pos_fits_lj_bench(void){return printf("%-7X", 33);}
int X_width_zero_fits_lj_bench(void){return printf("%-3X", 0);}
int X_width_pos_exactfit_lj_bench(void){return printf("%-5X", 52625);}
int X_width_pos_nofit_lj_bench(void){return printf("%-4X", 9648627);}
//Hexadecimal uppers with precision
int X_prec_fits_pos_bench(void){return printf("%.5X", 21);}
int X_prec_fits_zero_bench(void){return printf("%.3X", 0);}
int X_prec_exactfit_pos_bench(void){return printf("%.4X", 5263);}
int X_prec_nofit_pos_bench(void){return printf("%.3X", 938862);}
//Hexadecimal uppers with zero field width padding
int X_zp_pos_fits_bench(void){return printf("%05X", 43);}
int X_zp_zero_fits_bench(void){return printf("%03X", 0);}
int X_zp_pos_exactfit_bench(void){return printf("%03X", 698334);}
//Hexadecimal uppers with field width and precision
int X_prec_width_fit_fit_pos_bench(void){return printf("%8.5X", 34);}
int X_prec_width_fit_fit_zero_bench(void){return printf("%8.5X", 0);}
int X_prec_width_nofit_fit_pos_bench(void){return printf("%8.3X", 8375);}
int X_prec_width_fit_nofit_pos_bench(void){return printf("%2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_bench(void){return printf("%3.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified
int X_prec_width_fit_fit_pos_lj_bench(void){return printf("%-8.5X", 34);}
int X_prec_width_fit_fit_zero_lj_bench(void){return printf("%-8.5X", 0);}
int X_prec_width_nofit_fit_pos_lj_bench(void){return printf("%-8.3X", 8375);}
int X_prec_width_fit_nofit_pos_lj_bench(void){return printf("%-2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_lj_bench(void){return printf("%-3.3X", 6983);}
//Hexadecimal uppers with field width and precision with zeropadding
int X_prec_width_ff_pos_zp_bench(void){return printf("%08.5X", 34);}
int X_prec_width_ff_zero_zp_bench(void){return printf("%08.5X", 0);}
int X_prec_width_nf_pos_zp_bench(void){return printf("%08.3X", 8375);}
int X_prec_width_fn_pos_zp_bench(void){return printf("%02.7X", 3267);}
int X_prec_width_nn_pos_zp_bench(void){return printf("%03.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified with zeropadding
int X_prec_width_ff_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.5X", 34);}
int X_prec_width_ff_zero_ljzp_ignoreflag_bench(void){return printf("%0-8.5X", 0);}
int X_prec_width_nf_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.3X", 8375);}
int X_prec_width_fn_pos_ljzp_ignoreflag_bench(void){return printf("%0-2.7X", 3267);}
int X_prec_width_nn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.3X", 6983);}
//Hexadecimal uppers - zero precision zero value
int X_prec0val0_basic_bench(void){return printf("%.0X", 0);}
int X_prec0val0_implicit_bench(void){return printf("%.X", 0);}
int X_prec0val0_w_bench(void){return printf("%5.0X", 0);}
int X_prec0val0_w_impl_bench(void){return printf("%5.X", 0);}
int X_prec0val0_wlj_bench(void){return printf("%-5.0X", 0);}
int X_prec0val0_wlj_impl_bench(void){return printf("%-5.X", 0);}


//Pointers - Basic












int p_null_bench(void){return printf("%p", NULL);}
int p_null_width_fit_bench(void){return printf("%5p", NULL);}
int p_null_width_nofit_bench(void){return printf("%2p", NULL);}
int p_void_bench(void){return printf("%.p", NULL);}
int p_void_width_fit_bench(void){return printf("%5.p", NULL);}
int p_void_width_nofit_bench(void){return printf("%2.p", NULL);}
int	p_ftfc_literal_9w_prec2_undefbehav_bench(void){return printf("%9.2p\n", 1234);}
int	p_ftfc_literal_2w_prec9_undefbehav_bench(void){return printf("%2.9p\n", 1234);}
int	p_ftfc_zero_prec5_undefbehav_bench(void){return printf("%.5p", 0);}
int	p_ftfc_zero_prec0_undefbehav_bench(void){return printf("%.0p", 0);}
int p_ftfc_5w_throwswarning_bench(void){return printf("%5p", 0);}
int p_basic_bench(void){return printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_fit_bench(void){return printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_nofit_bench(void){return printf("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_16_bench(void){return printf("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_8_bench(void){return printf("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_32_bench(void){return printf("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_fit_lj_bench(void){return printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_nofit_lj_bench(void){return printf("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_16_lj_bench(void){return printf("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_8_lj_bench(void){return printf("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}
int p_width_32_lj_bench(void){return printf("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


//Chars - Basic
int c_allprintable_combined_bench(void){return printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}
int c_1_31_combined_bench(void){return printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}
int c_128_255_combined_bench(void){return printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}
int c_allprintable_width_bench(void){return printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}
int c_1_31_width_bench(void){return printf("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}
int c_128_255_width_bench(void){return printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}
int c_allprintable_width_lj_bench(void){return printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}
int c_1_31_width_lj_bench(void){return printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}
int c_128_255_width_lj_bench(void){return printf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}
int c_nullterm_basic_bench(void){return printf("%c", '\0');}
int c_nullterm_5w_bench(void){return printf("%5c", '\0');}
int c_nullterm_5wlj_bench(void){return printf("%-5c", '\0');}

// Mix tests




int		mix_successive_0_bench(void){return ( printf("%c", mx_c) + printf("%u", mx_u));}
int		mix_successive_4_bench(void){return ( printf("%x", mx_u) + printf("%i", mx_i));}
int		mix_successive_6_bench(void){return ( printf("%s", mx_s) + printf("%c", mx_c));}
int		mix_successive_10_bench(void){return ( printf("%u", mx_u) + printf("%s", mx_s));}
int		mix_successive_16_bench(void){return ( printf("%s", mx_s) + printf("%x", mx_u));}
int		mix_successive_20_bench(void){return ( printf("%p", &mx_i) + printf("%s", mx_s));}
int		mix_successive_21_bench(void){return ( printf("%X", mx_u) + printf("%x", mx_u));}
int		mix_successive_28_bench(void){return ( printf("%i", mx_i) + printf("%u", mx_u));}
int		mix_successive_30_bench(void){return ( printf("%s", mx_s) + printf("%u", mx_u));}
int		mix_successive_31_bench(void){return ( printf("%X", mx_u) + printf("%c", mx_c));}
int		mix_successive_32_bench(void){return ( printf("%x", mx_u) + printf("%u", mx_u));}
int		mix_successive_39_bench(void){return ( printf("%i", mx_i) + printf("%c", mx_c));}
int		mix_successive_40_bench(void){return ( printf("%c", mx_c) + printf("%x", mx_u));}
int		mix_successive_42_bench(void){return ( printf("%x", mx_u) + printf("%s", mx_s));}
int		mix_successive_43_bench(void){return ( printf("%u", mx_u) + printf("%x", mx_u));}
int		mix_successive_45_bench(void){return ( printf("%s", mx_s) + printf("%c", mx_c));}
int		mix_successive_46_bench(void){return ( printf("%i", mx_i) + printf("%s", mx_s));}
int		mix_successive_61_bench(void){return ( printf("%p", &mx_i) + printf("%c", mx_c));}
int		mix_successive_64_bench(void){return ( printf("%s", mx_s) + printf("%c", mx_c));}


//No-crash-no-segfault test
int		nocrash_noarg_1_notmandatory_bench(void){return printf("%1$"); }
int		nocrash_noarg_2_notmandatory_bench(void){return printf("%0"); }
int		nocrash_noarg_3_notmandatory_bench(void){return printf("% "); }
int		nocrash_noarg_4_notmandatory_bench(void){return printf("%#"); }
int		nocrash_noarg_5_notmandatory_bench(void){return printf("%-"); }
int		nocrash_noarg_6_notmandatory_bench(void){return printf("%+"); }
int		nocrash_noarg_9_notmandatory_bench(void){return printf("%23"); }
int		nocrash_noarg_10_notmandatory_bench(void){return printf("%."); }
int		nocrash_noarg_11_notmandatory_bench(void){return printf("%hh"); }
int		nocrash_noarg_12_notmandatory_bench(void){return printf("%h"); }
int		nocrash_noarg_13_notmandatory_bench(void){return printf("%ll"); }
int		nocrash_noarg_14_notmandatory_bench(void){return printf("%l"); }
int		nocrash_noarg_15_notmandatory_bench(void){return printf("%L"); }
int		nocrash_noarg_16_notmandatory_bench(void){return printf("%p"); }
int		nocrash_noarg_17_notmandatory_bench(void){return printf("%d"); }
int		nocrash_noarg_19_notmandatory_bench(void){return printf("%u"); }
int		nocrash_noarg_20_notmandatory_bench(void){return printf("%x"); }
int		nocrash_noarg_21_notmandatory_bench(void){return printf("%X"); }
int		nocrash_noarg_22_notmandatory_bench(void){return printf("%f"); }
int		nocrash_noarg_24_notmandatory_bench(void){return printf("%c"); }
int		nocrash_noarg_25_notmandatory_bench(void){return printf("%o"); }
int		nocrash_nullarg_1_bench(void){return printf("%1$s", NULL); }
int		nocrash_nullarg_2_bench(void){return printf("%0s", NULL); }
int		nocrash_nullarg_3_bench(void){return printf("% s", NULL); }
int		nocrash_nullarg_4_bench(void){return printf("%#s", NULL); }
int		nocrash_nullarg_5_bench(void){return printf("%-s", NULL); }
int		nocrash_nullarg_6_bench(void){return printf("%+s", NULL); }
int		nocrash_nullarg_9_bench(void){return printf("%23s", NULL); }
int		nocrash_nullarg_10_bench(void){return printf("%.s", NULL); }
int		nocrash_nullarg_11_bench(void){return printf("%hhs", NULL); }
int		nocrash_nullarg_12_bench(void){return printf("%hs", NULL); }
int		nocrash_nullarg_13_bench(void){return printf("%lls", NULL); }
int		nocrash_nullarg_14_bench(void){return printf("%ls", NULL); }
int		nocrash_nullarg_15_bench(void){return printf("%Ls", NULL); }
int		nocrash_nullarg_16_bench(void){return printf("%p", NULL); }
int		nocrash_nullarg_17_bench(void){return printf("%d", NULL); }
int		nocrash_nullarg_18_bench(void){return printf("%b", NULL); }
int		nocrash_nullarg_19_bench(void){return printf("%u", NULL); }
int		nocrash_nullarg_20_bench(void){return printf("%x", NULL); }
int		nocrash_nullarg_21_bench(void){return printf("%X", NULL); }
int		nocrash_nullarg_22_bench(void){return printf("%f", NULL); }
int		nocrash_nullarg_23_bench(void){return printf("%s", NULL); }
int		nocrash_nullarg_24_bench(void){return printf("%c", NULL); }
int		nocrash_nullarg_25_bench(void){return printf("%o", NULL); }

//Tests that were deleted because turning off -Wformat=0 gives a warning about undefined behavior
int nocrash_mandatory_wformat_undefbehav_01_bench(void){return printf("%-021s", "abc");}
int nocrash_mandatory_wformat_undefbehav_02_bench(void){return printf("%-05s", "goes over");}
int nocrash_mandatory_wformat_undefbehav_03_bench(void){return printf("%04.3s%-7.4s", "hello", "world");}
int nocrash_mandatory_wformat_undefbehav_04_bench(void){return printf("%021s", NULL);}
int nocrash_mandatory_wformat_undefbehav_05_bench(void){return printf("%02s", NULL);}
int nocrash_mandatory_wformat_undefbehav_06_bench(void){return printf("%-021s", NULL);}
int nocrash_mandatory_wformat_undefbehav_07_bench(void){return printf("%-03s", NULL);}
int nocrash_mandatory_wformat_undefbehav_38_bench(void){return printf("%05c", '\0');}
int nocrash_mandatory_wformat_undefbehav_39_bench(void){return printf("%-05c", '\0');}

//nocrash tests adapted from tests contributed by phtruong
int nocrash_mandatory_dupflag_d_spsp_bench(void){return printf("%  d", 42);}
int nocrash_mandatory_dupflag_d_ljljw_bench(void){return printf("%--5d", 42);}
int nocrash_mandatory_dupflag_x_afaf_bench(void){return printf("%##x", 42);}

//nocrash tests that came about as part of the minimal specification
int nocrash_mandatory_c_prec_1_bench(void){return printf("%.4c", 'a');}
int nocrash_mandatory_c_prec_2_bench(void){return printf("%.c", 'a');}
int nocrash_mandatory_c_af_bench(void){return printf("%#c", 'a');}
int nocrash_mandatory_c_zp_1_bench(void){return printf("%05c", 'a');}
int nocrash_mandatory_c_zp_2_bench(void){return printf("%0c", 'a');}
int nocrash_mandatory_c_sp_1_bench(void){return printf("% c", 'a');}
int nocrash_mandatory_c_sp_2_bench(void){return printf("% c", -42);}
int nocrash_mandatory_c_size_hh_bench(void){return printf("%hhc", 'a');}
int nocrash_mandatory_c_size_h_bench(void){return printf("%hc", 'a');}
int nocrash_mandatory_c_size_l_bench(void){return printf("%lc", L'a');}
int nocrash_mandatory_c_size_ll_bench(void){return printf("%llc", L'a');}
int nocrash_mandatory_c_size_L_bench(void){return printf("%Lc", L'a');}
int nocrash_mandatory_c_lj_nowidth_bench(void){return printf("%-c", 'a');}
int nocrash_mandatory_s_af_bench(void){return printf("%#s", "hello");}
int nocrash_mandatory_s_zp_1_bench(void){return printf("%05s", "hello");}
int nocrash_mandatory_s_zp_2_bench(void){return printf("%0s", "hello");}
int nocrash_mandatory_s_sp_1_bench(void){return printf("% s", "hello");}
int nocrash_mandatory_s_size_hh_bench(void){return printf("%hhs", "hello");}
int nocrash_mandatory_s_size_h_bench(void){return printf("%hs", "hello");}
int nocrash_mandatory_s_size_l_bench(void){return printf("%ls", L"hello");}
int nocrash_mandatory_s_size_ll_bench(void){return printf("%lls", L"hello");}
int nocrash_mandatory_s_size_L_bench(void){return printf("%Ls", L"hello");}
int nocrash_mandatory_s_lj_nowidth_bench(void){return printf("%-s", "hello");}


int nocrash_mandatory_p_prec_1_bench(void){return printf("%.4p", &ncm_p);}
int nocrash_mandatory_p_prec_2_bench(void){return printf("%.p", &ncm_p);}
int nocrash_mandatory_p_af_bench(void){return printf("%#p", &ncm_p);}
int nocrash_mandatory_p_zp_1_bench(void){return printf("%05p", &ncm_p);}
int nocrash_mandatory_p_zp_2_bench(void){return printf("%0p", &ncm_p);}
int nocrash_mandatory_p_sp_1_bench(void){return printf("% p", &ncm_p);}
int nocrash_mandatory_p_sp_2_bench(void){return printf("% p", &ncm_p);}
int nocrash_mandatory_p_size_hh_bench(void){return printf("%hhp", &ncm_p);}
int nocrash_mandatory_p_size_h_bench(void){return printf("%hp", &ncm_p);}
int nocrash_mandatory_p_size_l_bench(void){return printf("%lp", &ncm_p);}
int nocrash_mandatory_p_size_ll_bench(void){return printf("%llp", &ncm_p);}
int nocrash_mandatory_p_size_L_bench(void){return printf("%Lp", &ncm_p);}
int nocrash_mandatory_p_lj_nowidth_bench(void){return printf("%-p", &ncm_p);}
int nocrash_mandatory_d_size_L_bench(void){return printf("%Ld", 42);}
int nocrash_mandatory_d_af_bench(void){return printf("%#d", 42);}
int nocrash_mandatory_d_size_hhh_bench(void){return printf("%hhhd", 42);}
int nocrash_mandatory_d_size_hhhh_bench(void){return printf("%hhhhd", 42);}
int nocrash_mandatory_d_size_hhl_bench(void){return printf("%hhld", 42);}
int nocrash_mandatory_d_size_hhll_bench(void){return printf("%hhlld", 42);}
int nocrash_mandatory_d_size_llh_bench(void){return printf("%llhd", 42);}
int nocrash_mandatory_d_size_lll_bench(void){return printf("%llld", 42);}
int nocrash_mandatory_i_size_L_bench(void){return printf("%Li", 42);}
int nocrash_mandatory_i_af_bench(void){return printf("%#i", 42);}
int nocrash_mandatory_i_size_hhh_bench(void){return printf("%hhhi", 42);}
int nocrash_mandatory_i_lj_nowidth_bench(void){return printf("%-i", 42);}
int nocrash_mandatory_o_sp_bench(void){return printf("% o", 42);}
int nocrash_mandatory_o_size_L_bench(void){return printf("%Lo", 42);}
int nocrash_mandatory_o_size_hhh_bench(void){return printf("%hhho", 42);}
int nocrash_mandatory_o_size_hhhh_bench(void){return printf("%hhhho", 42);}
int nocrash_mandatory_o_size_hhl_bench(void){return printf("%hhlo", 42);}
int nocrash_mandatory_o_size_hhll_bench(void){return printf("%hhllo", 42);}
int nocrash_mandatory_o_size_llh_bench(void){return printf("%llho", 42);}
int nocrash_mandatory_o_size_lll_bench(void){return printf("%lllo", 42);}
int nocrash_mandatory_o_lj_nowidth_bench(void){return printf("%-o", 42);}
int nocrash_mandatory_u_size_L_bench(void){return printf("%Lu", 42);}
int nocrash_mandatory_u_af_bench(void){return printf("%#u", 42);}
int nocrash_mandatory_u_sp_bench(void){return printf("% u", 42);}
int nocrash_mandatory_u_size_hhh_bench(void){return printf("%hhhu", 42);}
int nocrash_mandatory_u_size_hhhh_bench(void){return printf("%hhhhu", 42);}
int nocrash_mandatory_u_size_hhl_bench(void){return printf("%hhlu", 42);}
int nocrash_mandatory_u_size_hhll_bench(void){return printf("%hhllu", 42);}
int nocrash_mandatory_u_size_llh_bench(void){return printf("%llhu", 42);}
int nocrash_mandatory_u_size_lll_bench(void){return printf("%lllu", 42);}
int nocrash_mandatory_u_lj_nowidth_bench(void){return printf("%-u", 42);}
int nocrash_mandatory_x_size_L_bench(void){return printf("%Lx", 42);}
int nocrash_mandatory_x_sp_bench(void){return printf("% x", 42);}
int nocrash_mandatory_x_size_hhh_bench(void){return printf("%hhhx", 42);}
int nocrash_mandatory_x_size_hhhh_bench(void){return printf("%hhhhx", 42);}
int nocrash_mandatory_x_size_hhl_bench(void){return printf("%hhlx", 42);}
int nocrash_mandatory_x_size_hhll_bench(void){return printf("%hhllx", 42);}
int nocrash_mandatory_x_size_llh_bench(void){return printf("%llhx", 42);}
int nocrash_mandatory_x_size_lll_bench(void){return printf("%lllx", 42);}
int nocrash_mandatory_X_size_L_bench(void){return printf("%LX", 42);}
int nocrash_mandatory_X_sp_bench(void){return printf("% X", 42);}
int nocrash_mandatory_X_size_hhh_bench(void){return printf("%hhhX", 42);}
int nocrash_mandatory_X_size_llh_bench(void){return printf("%llhX", 42);}
int nocrash_mandatory_x_lj_nowidth_bench(void){return printf("%-x", 42);}
int nocrash_mandatory_f_size_hh_bench(void){return printf("%hhf", 42.5);}
int nocrash_mandatory_f_size_h_bench(void){return printf("%hf", 42.5);}
int nocrash_mandatory_f_size_ll_bench(void){return printf("%llf", 42.5);}
int nocrash_mandatory_f_size_lll_bench(void){return printf("%lllf", 42.5);}
int nocrash_mandatory_f_size_llll_bench(void){return printf("%llllf", 42.5);}
int nocrash_mandatory_f_size_LL_bench(void){return printf("%LLf", 42.5);}
int nocrash_mandatory_f_size_Ll_bench(void){return printf("%Llf", 42.5);}
int nocrash_mandatory_f_size_lL_bench(void){return printf("%lLf", 42.5);}
int nocrash_mandatory_f_lj_nowidth_bench(void){return printf("%-f", 42.5);}




//Moulinette tests
int		moul_s_1_bench(void){return printf(" pouet %s !!", "camembert");}
int		moul_s_2_bench(void){return printf("%s !", "Ceci n'est pas un \0 exercice !");}
int		moul_s_3_bench(void){return printf("%s!", "Ceci n'est toujours pas un exercice !");}
int		moul_s_4_bench(void){char *str = NULL; return printf("%s!", str);}
int		moul_s_5_this_ones_a_doozy_bench(void){return printf("%s",
		"Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");}
int moul_d_1_bench(void){return printf("%d", 42);}
int moul_d_2_bench(void){return printf("Kashim a %d histoires à raconter", 1001);}
int moul_d_3_bench(void){return printf("Il fait au moins %d\n", -8000);}
int moul_d_4_bench(void){return printf("%d", -0);}
int moul_d_5_bench(void){return printf("%d", 0);}
int moul_d_6_bench(void){return printf("%d", INT_MAX);}
int moul_d_7_bench(void){return printf("%d", INT_MIN);}
int moul_d_8_bench(void){return printf("%d", INT_MIN - 1);}
int moul_d_9_bench(void){return printf("%d", INT_MAX + 1);}
int moul_d_10_bench(void){return printf("%%d 0000042 == |%d|\n", 0000042);}
int moul_d_11_bench(void){return printf("%%d \t == |%d|\n", '\t');}
int moul_d_12_bench(void){return printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');}
int moul_mix_1_bench(void){int r00 = 0; return printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);}
int moul_c_1_bench(void){return printf("%c", 42);}
int moul_c_2_bench(void){return printf("Kashim a %c histoires à raconter", 1001);}
int moul_c_3_bench(void){return printf("Il fait au moins %c\n", -8000);}
int moul_c_4_bench(void){return printf("%c", -0);}
int moul_c_5_bench(void){return printf("%c", 0);}
int moul_c_5b_bench(void){return printf("%c\n", INT_MAX);}
int moul_c_6_bench(void){return printf("%c\n", 'c');}
int moul_c_7_bench(void){return printf("%c\n", '\n');}
int moul_c_8_bench(void){return printf("%c", 'l');}
int moul_c_9_bench(void){return printf("%c", 'y');}
int moul_c_10_bench(void){return printf("%c", ' ');}
int moul_c_11_bench(void){return printf("%c", 'e');}
int moul_c_12_bench(void){return printf("%c", 's');}
int moul_c_13_bench(void){return printf("%c", 't');}
int moul_c_14_bench(void){return printf("%c", ' ');}
int moul_c_15_bench(void){return printf("%c", 'f');}
int moul_c_16_bench(void){return printf("%c", 'a');}
int moul_c_17_bench(void){return printf("%c", 'n');}
int moul_c_18_bench(void){return printf("%c", 't');}
int moul_c_19_bench(void){return printf("%c", 'a');}
int moul_c_20_bench(void){return printf("%c", 's');}
int moul_c_21_bench(void){return printf("%c", 't');}
int moul_c_22_bench(void){return printf("%c", 'i');}
int moul_c_23_bench(void){return printf("%c", 'q');}
int moul_c_24_bench(void){return printf("%c", 'u');}
int moul_c_25_bench(void){return printf("%c", 'e');}
int moul_c_26_bench(void){return printf("%c\n", '!');}
int moul_c_27_bench(void){return printf("%c\n", '\r');}
int moul_c_28_bench(void){return printf("%c\n", '\t');}
int moul_i_1_bench(void){return printf("%i", 42);}
int moul_i_2_bench(void){return printf("Kashim a %i histoires à raconter", 1001);}
int moul_i_3_bench(void){return printf("Il fait au moins %i\n", -8000);}
int moul_i_4_bench(void){return printf("%i", -0);}
int moul_i_5_bench(void){return printf("%i", 0);}
int moul_i_6_bench(void){return printf("%i", INT_MAX);}
int moul_i_7_bench(void){return printf("%i", INT_MIN);}
int moul_i_8_bench(void){return printf("%i", INT_MIN - 1);}
int moul_i_9_bench(void){return printf("%i", INT_MAX + 1);}
int moul_i_10_bench(void){return printf("%%i 0000042 == |%i|\n", 0000042);}
int moul_i_11_bench(void){return printf("%%i \t == |%i|\n", '\t');}
int moul_i_12_bench(void){return printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');}
int moul_u_1_bench(void){return printf("%u", 42);}
int moul_u_2_bench(void){return printf("Kashim a %u histoires à raconter", 1001);}
int moul_u_3_bench(void){return printf("Il fait au moins %u\n", -8000);}
int moul_u_4_bench(void){return printf("%u", -0);}
int moul_u_5_bench(void){return printf("%u", 0);}
int moul_u_6_bench(void){return printf("%u", INT_MAX);}
int moul_u_7_bench(void){return printf("%u", INT_MIN);}
int moul_u_8_bench(void){return printf("%u", INT_MIN - 1);}
int moul_u_9_bench(void){return printf("%u", INT_MAX + 1);}
int moul_u_10_bench(void){return printf("%%u 0000042 == |%u|\n", 0000042);}
int moul_u_11_bench(void){return printf("%%u \t == |%u|\n", '\t');}
int moul_u_12_bench(void){return printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');}
int moul_x_1_bench(void){return printf("%x", 42);}
int moul_x_2_bench(void){return printf("Kashim a %x histoires à raconter", 1001);}
int moul_x_3_bench(void){return printf("Il fait au moins %x\n", -8000);}
int moul_x_4_bench(void){return printf("%x", -0);}
int moul_x_5_bench(void){return printf("%x", 0);}
int moul_x_6_bench(void){return printf("%x", INT_MAX);}
int moul_x_7_bench(void){return printf("%x", INT_MIN);}
int moul_x_8_bench(void){return printf("%x", INT_MIN - 1);}
int moul_x_9_bench(void){return printf("%x", INT_MAX + 1);}
int moul_x_10_bench(void){return printf("%%x 0000042 == |%x|\n", 0000042);}
int moul_x_11_bench(void){return printf("%%x \t == |%x|\n", '\t');}
int moul_x_12_bench(void){return printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');}
int moul_prec_1_bench(void){return printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");}
int moul_prec_3_bench(void){return printf("%%04.5i 42 == |%04.5i|\n", 42);}
int moul_prec_4_bench(void){return printf("%%04.3i 42 == |%04.3i|\n", 42);}
int moul_prec_5_bench(void){return printf("%%04.2i 42 == |%04.2i|\n", 42);}
int moul_zeropad_1_bench(void){return printf("%%04i 42 == |%04i|\n", 42);}
int moul_zeropad_2_bench(void){return printf("%%05i 42 == |%05i|\n", 42);}
int moul_zeropad_3_bench(void){return printf("%%0i 42 == |%0i|\n", 42);}
int moul_zeropad_4_bench(void){return printf("%%0d 0000042 == |%0d|\n", 0000042);}
int moul_leftjusty_1_bench(void){return printf("%%-i 42 == %-i\n", 42);}
int moul_leftjusty_2_bench(void){return printf("%%-d 42 == %-d\n", INT_MIN);}
int moul_leftjusty_3_bench(void){return printf("%%-i -42 == %-i\n", -42);}
int moul_leftjusty_4_bench(void){return printf("%%-4d 42 == |%-4d|\n", 42);}
int moul_leftjusty_5_bench(void){return printf("%%-5d -42 == |%-5d|\n", -42);}
int moul_leftjusty_6_bench(void){return printf("|%3i|%-3i|\n", 42, 42);}
int moul_leftjusty_7_bench(void){return printf("%%-4i 42 == |%-4i|\n", 42);}
int moul_notmandatory_star_1_bench(void){return printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");}
int moul_notmandatory_star_3_bench(void){return printf("%%*i 42 == |%*i|\n", 5, 42);}
int moul_notmandatory_star_4_bench(void){return printf("%%*i 42 == |%*i|\n", 3, 42);}
int moul_notmandatory_star_5_bench(void){return printf("%%*i 42 == |%*i|\n", 2, 42);}
int new2019_star_1_bench(void){return printf("%*s", 32, "abc");}
int new2019_star_2_bench(void){return printf("%-*s", 32, "abc");}
int new2019_star_3_bench(void){return printf("%*s", 3, "hello");}
int new2019_star_4_bench(void){return printf("%.*s", 3, "hello");}
int new2019_star_5_bench(void){return printf("%.*s", 0, "hello");}
int new2019_star_6_bench(void){return printf("%-*.*s", 7, 3, "yolo");}
int new2019_star_7_bench(void){return printf("%*i", 4, 94827);}
int new2019_star_8_bench(void){return printf("%*i", 14, 94827);}
int new2019_star_9_bench(void){return printf("%.*i", 6, -3);}
int new2019_star_10_bench(void){return printf("%0*i", 7, -54);}
int new2019_negstar_1_bench(void){return printf("%*s", -32, "abc");}
int new2019_negstar_2_bench(void){return printf("%-*s", -32, "abc");}
int new2019_negstar_3_bench(void){return printf("%*s", -3, "hello");}
int new2019_negstar_4_bench(void){return printf("%.*s", -3, "hello");}
int new2019_negstar_5_bench(void){return printf("%-*.*s", -7, -3, "yolo");}
int new2019_negstar_6_bench(void){return printf("%*i", -4, 94827);}
int new2019_negstar_7_bench(void){return printf("%*i", -14, 94827);}
int new2019_negstar_8_bench(void){return printf("%.*i", -6, -3);}
int new2019_negstar_9_bench(void){return printf("%0*i", -7, -54);}

#pragma clang diagnostic pop
const t_test_entry g_unit_tests[] = {
	{1, 0, "nospec_no_specifier_test", nospec_no_specifier_test, nospec_no_specifier_test_bench, "{return test(\"hello, world!\");}"},
	{1, 1, "nospec_empty_string", nospec_empty_string, nospec_empty_string_bench, "{return test(\"\");}"},
	{1, 2, "nospec_some_escaped_chars", nospec_some_escaped_chars, nospec_some_escaped_chars_bench, "{return test(\"\t\n\r\v\f\n\");}"},
	{1, 3, "nospec_successive_5_5", nospec_successive_5_5, nospec_successive_5_5_bench, "{return ( test(\"hello\") + test(\"world\"));}"},
	{1, 4, "nospec_successive_2_9", nospec_successive_2_9, nospec_successive_2_9_bench, "{return ( test(\"he\") ^ test(\" is alive\"));}"},
	{1, 5, "nospec_successive_8_3", nospec_successive_8_3, nospec_successive_8_3_bench, "{return ( test(\"is alive\") - test(\" he\"));}"},
	{1, 6, "pct_basic", pct_basic, pct_basic_bench, "{return test(\"%%\");}"},
	{1, 7, "pct_5w", pct_5w, pct_5w_bench, "{return test(\"%5%\");}"},
	{1, 8, "pct_5wlj", pct_5wlj, pct_5wlj_bench, "{return test(\"%-5%\");}"},
	{1, 9, "pct_5wzp", pct_5wzp, pct_5wzp_bench, "{return test(\"%05%\");}"},
	{1, 10, "pct_5wljzp", pct_5wljzp, pct_5wljzp_bench, "{return test(\"%-05%\");}"},
	{1, 11, "nocrash_nullspec_basic", nocrash_nullspec_basic, nocrash_nullspec_basic_bench, "{return test(\"%\");}"},
	{1, 12, "nocrash_nullspec_5w", nocrash_nullspec_5w, nocrash_nullspec_5w_bench, "{return test(\"%5\");}"},
	{1, 13, "nocrash_nullspec_5wzp", nocrash_nullspec_5wzp, nocrash_nullspec_5wzp_bench, "{return test(\"%05\");}"},
	{1, 14, "nocrash_nullspec_5wzplj", nocrash_nullspec_5wzplj, nocrash_nullspec_5wzplj_bench, "{return test(\"%-05\");}"},
	{1, 15, "nocrash_nullspec_5wlj", nocrash_nullspec_5wlj, nocrash_nullspec_5wlj_bench, "{return test(\"%-5\");}"},
	{1, 16, "s_basic_string_expansion", s_basic_string_expansion, s_basic_string_expansion_bench, "{return test(\"hello, %s.\", \"gavin\");}"},
	{1, 17, "s_only_string_expansion", s_only_string_expansion, s_only_string_expansion_bench, "{return test(\"%s\", \"testing testing\");}"},
	{1, 18, "s_two_string_expansions", s_two_string_expansions, s_two_string_expansions_bench, "{return test(\"%s%s\", \"hello\", \"world\");}"},
	{1, 19, "s_two_string_expansions2", s_two_string_expansions2, s_two_string_expansions2_bench, "{return test(\"..%s stuff %s\", \"a\", \"b\");}"},
	{1, 20, "s_empty_string_expansion", s_empty_string_expansion, s_empty_string_expansion_bench, "{return test(\"this %s is empty\", \"\");}"},
	{1, 21, "s_full_then_empty_string", s_full_then_empty_string, s_full_then_empty_string_bench, "{return test(\"this %s is %s\", \"hello\", \"\");}"},
	{1, 22, "s_empty_then_full_string", s_empty_then_full_string, s_empty_then_full_string_bench, "{return test(\"this %s is %s\", \"\", \"hello\");}"},
	{1, 23, "s_three_strings", s_three_strings, s_three_strings_bench, "{return test(\"%s%s%s\", \"1\", \"2\", \"3's a charm\");}"},
	{1, 24, "s_space_padded_field_width", s_space_padded_field_width, s_space_padded_field_width_bench, "{return test(\"%32s\", \"abc\");}"},
	{1, 25, "s_space_padded_field_width2", s_space_padded_field_width2, s_space_padded_field_width2_bench, "{return test(\"%16s\", \"nark nark\");}"},
	{1, 26, "s_space_padded_over_field_width", s_space_padded_over_field_width, s_space_padded_over_field_width_bench, "{return test(\"%5s\", \"goes over\");}"},
	{1, 27, "s_space_padded_field_width_lj", s_space_padded_field_width_lj, s_space_padded_field_width_lj_bench, "{return test(\"%-32s\", \"abc\");}"},
	{1, 28, "s_space_padded_field_width2_lj", s_space_padded_field_width2_lj, s_space_padded_field_width2_lj_bench, "{return test(\"%-16s\", \"nark nark\");}"},
	{1, 29, "s_space_padded_over_field_width_lj", s_space_padded_over_field_width_lj, s_space_padded_over_field_width_lj_bench, "{return test(\"%-5s\", \"goes over\");}"},
	{1, 30, "s_string_prec_notrunc", s_string_prec_notrunc, s_string_prec_notrunc_bench, "{return test(\"%.7s\", \"hello\");}"},
	{1, 31, "s_string_prec_trunc", s_string_prec_trunc, s_string_prec_trunc_bench, "{return test(\"%.3s\", \"hello\");}"},
	{1, 32, "s_string_prec_default", s_string_prec_default, s_string_prec_default_bench, "{return test(\"%.s\", \"hello\");}"},
	{1, 33, "s_string_prec_zero", s_string_prec_zero, s_string_prec_zero_bench, "{return test(\"%.0s\", \"hello\");}"},
	{1, 34, "s_two_strings_prec_2trunc", s_two_strings_prec_2trunc, s_two_strings_prec_2trunc_bench, "{return test(\"%.3s%.2s\", \"holla\", \"bitch\");}"},
	{1, 35, "s_two_strings_prec_1trunc_a", s_two_strings_prec_1trunc_a, s_two_strings_prec_1trunc_a_bench, "{return test(\"%.2s%.7s\", \"hello\", \"world\");}"},
	{1, 36, "s_two_strings_prec_1trunc_b", s_two_strings_prec_1trunc_b, s_two_strings_prec_1trunc_b_bench, "{return test(\"%.7s%.2s\", \"hello\", \"world\");}"},
	{1, 37, "s_two_strings_prec_0trunc", s_two_strings_prec_0trunc, s_two_strings_prec_0trunc_bench, "{return test(\"%.5s%7s\", \"yo\", \"boi\");}"},
	{1, 38, "s_string_prec_width_notrunc", s_string_prec_width_notrunc, s_string_prec_width_notrunc_bench, "{return test(\"%7.5s\", \"yolo\");}"},
	{1, 39, "s_string_prec_width_trunc", s_string_prec_width_trunc, s_string_prec_width_trunc_bench, "{return test(\"%7.5s\", \"bombastic\");}"},
	{1, 40, "s_string_prec_width_notrunc_lj", s_string_prec_width_notrunc_lj, s_string_prec_width_notrunc_lj_bench, "{return test(\"%-7.5s\", \"yolo\");}"},
	{1, 41, "s_string_prec_width_trunc_lj", s_string_prec_width_trunc_lj, s_string_prec_width_trunc_lj_bench, "{return test(\"%-7.5s\", \"tubular\");}"},
	{1, 42, "s_two_s_prec_width_2fit_0trunc", s_two_s_prec_width_2fit_0trunc, s_two_s_prec_width_2fit_0trunc_bench, "{return test(\"%7.7s%7.7s\", \"hello\", \"world\");}"},
	{1, 43, "s_two_s_prec_width_1fit_a_0trunc", s_two_s_prec_width_1fit_a_0trunc, s_two_s_prec_width_1fit_a_0trunc_bench, "{return test(\"%3.7s%7.7s\", \"hello\", \"world\");}"},
	{1, 44, "s_two_s_prec_width_1fit_b_0trunc", s_two_s_prec_width_1fit_b_0trunc, s_two_s_prec_width_1fit_b_0trunc_bench, "{return test(\"%7.7s%3.7s\", \"hello\", \"world\");}"},
	{1, 45, "s_two_s_prec_width_0fit_0trunc", s_two_s_prec_width_0fit_0trunc, s_two_s_prec_width_0fit_0trunc_bench, "{return test(\"%3.7s%3.7s\", \"hello\", \"world\");}"},
	{1, 46, "s_two_s_prec_width_2fit_1trunc_a", s_two_s_prec_width_2fit_1trunc_a, s_two_s_prec_width_2fit_1trunc_a_bench, "{return test(\"%7.3s%7.7s\", \"hello\", \"world\");}"},
	{1, 47, "s_two_s_prec_width_1fit_a_1trunc_a", s_two_s_prec_width_1fit_a_1trunc_a, s_two_s_prec_width_1fit_a_1trunc_a_bench, "{return test(\"%3.3s%7.7s\", \"hello\", \"world\");}"},
	{1, 48, "s_two_s_prec_width_1fit_b_1trunc_a", s_two_s_prec_width_1fit_b_1trunc_a, s_two_s_prec_width_1fit_b_1trunc_a_bench, "{return test(\"%7.3s%3.7s\", \"hello\", \"world\");}"},
	{1, 49, "s_two_s_prec_width_0fit_1trunc_a", s_two_s_prec_width_0fit_1trunc_a, s_two_s_prec_width_0fit_1trunc_a_bench, "{return test(\"%3.3s%3.7s\", \"hello\", \"world\");}"},
	{1, 50, "s_two_s_prec_width_2fit_1trunc_b", s_two_s_prec_width_2fit_1trunc_b, s_two_s_prec_width_2fit_1trunc_b_bench, "{return test(\"%7.7s%7.3s\", \"hello\", \"world\");}"},
	{1, 51, "s_two_s_prec_width_1fit_a_1trunc_b", s_two_s_prec_width_1fit_a_1trunc_b, s_two_s_prec_width_1fit_a_1trunc_b_bench, "{return test(\"%3.7s%7.3s\", \"hello\", \"world\");}"},
	{1, 52, "s_two_s_prec_width_1fit_b_1trunc_b", s_two_s_prec_width_1fit_b_1trunc_b, s_two_s_prec_width_1fit_b_1trunc_b_bench, "{return test(\"%7.7s%3.3s\", \"hello\", \"world\");}"},
	{1, 53, "s_two_s_prec_width_0fit_1trunc_b", s_two_s_prec_width_0fit_1trunc_b, s_two_s_prec_width_0fit_1trunc_b_bench, "{return test(\"%3.7s%3.3s\", \"hello\", \"world\");}"},
	{1, 54, "s_two_s_prec_width_2fit_2trunc", s_two_s_prec_width_2fit_2trunc, s_two_s_prec_width_2fit_2trunc_bench, "{return test(\"%7.3s%7.3s\", \"hello\", \"world\");}"},
	{1, 55, "s_two_s_prec_width_1fit_a_2trunc", s_two_s_prec_width_1fit_a_2trunc, s_two_s_prec_width_1fit_a_2trunc_bench, "{return test(\"%3.3s%7.3s\", \"hello\", \"world\");}"},
	{1, 56, "s_two_s_prec_width_1fit_b_2trunc", s_two_s_prec_width_1fit_b_2trunc, s_two_s_prec_width_1fit_b_2trunc_bench, "{return test(\"%7.3s%3.3s\", \"hello\", \"world\");}"},
	{1, 57, "s_two_s_prec_width_0fit_2trunc", s_two_s_prec_width_0fit_2trunc, s_two_s_prec_width_0fit_2trunc_bench, "{return test(\"%3.3s%3.3s\", \"hello\", \"world\");}"},
	{1, 58, "s_two_s_prec_width_2trunc", s_two_s_prec_width_2trunc, s_two_s_prec_width_2trunc_bench, "{return test(\"%3s%3s\", \"hello\", \"world\");}"},
	{1, 59, "s_two_strings_lj_and_rj", s_two_strings_lj_and_rj, s_two_strings_lj_and_rj_bench, "{return test(\"%-7s%5s\", \"hello\", \"world\");}"},
	{1, 60, "s_two_strings_rj_and_lj", s_two_strings_rj_and_lj, s_two_strings_rj_and_lj_bench, "{return test(\"%7s%-5s\", \"hello\", \"world\");}"},
	{1, 61, "s_null_basic_string_expansion", s_null_basic_string_expansion, s_null_basic_string_expansion_bench, "{return test(\"hello, %s.\", NULL);}"},
	{1, 62, "s_null_only_string_expansion", s_null_only_string_expansion, s_null_only_string_expansion_bench, "{return test(\"%s\", NULL);}"},
	{1, 63, "s_null_space_padded_field_width", s_null_space_padded_field_width, s_null_space_padded_field_width_bench, "{return test(\"%32s\", NULL);}"},
	{1, 64, "s_null_space_padded_over_field_width", s_null_space_padded_over_field_width, s_null_space_padded_over_field_width_bench, "{return test(\"%2s\", NULL);}"},
	{1, 65, "s_null_space_padded_field_width_lj", s_null_space_padded_field_width_lj, s_null_space_padded_field_width_lj_bench, "{return test(\"%-32s\", NULL);}"},
	{1, 66, "s_null_space_padded_field_width2_lj", s_null_space_padded_field_width2_lj, s_null_space_padded_field_width2_lj_bench, "{return test(\"%-16s\", NULL);}"},
	{1, 67, "s_null_space_padded_over_field_width_lj", s_null_space_padded_over_field_width_lj, s_null_space_padded_over_field_width_lj_bench, "{return test(\"%-3s\", NULL);}"},
	{1, 68, "s_null_string_prec_notrunc", s_null_string_prec_notrunc, s_null_string_prec_notrunc_bench, "{return test(\"%.9s\", \"NULL\");}"},
	{1, 69, "s_null_string_prec_trunc", s_null_string_prec_trunc, s_null_string_prec_trunc_bench, "{return test(\"%.3s\", \"NULL\");}"},
	{1, 70, "s_null_string_prec_default", s_null_string_prec_default, s_null_string_prec_default_bench, "{return test(\"%.s\", \"NULL\");}"},
	{1, 71, "s_null_string_prec_zero", s_null_string_prec_zero, s_null_string_prec_zero_bench, "{return test(\"%.0s\", \"NULL\");}"},
	{1, 72, "s_basic_s_hidden", s_basic_s_hidden, s_basic_s_hidden_bench, "{return test(\"%s\", s_hidden);}"},
	{1, 73, "s_width_3_s_hidden", s_width_3_s_hidden, s_width_3_s_hidden_bench, "{return test(\"%3s\", s_hidden);}"},
	{1, 74, "s_width_9_s_hidden", s_width_9_s_hidden, s_width_9_s_hidden_bench, "{return test(\"%9s\", s_hidden);}"},
	{1, 75, "s_prec_no_width_s_hidden", s_prec_no_width_s_hidden, s_prec_no_width_s_hidden_bench, "{return test(\"%.s\", s_hidden);}"},
	{1, 76, "s_prec_9_no_width_s_hidden", s_prec_9_no_width_s_hidden, s_prec_9_no_width_s_hidden_bench, "{return test(\"%.9s\", s_hidden);}"},
	{1, 77, "s_prec_03_no_width_s_hidden", s_prec_03_no_width_s_hidden, s_prec_03_no_width_s_hidden_bench, "{return test(\"%.03s\", s_hidden);}"},
	{1, 78, "s_prec_09_no_width_s_hidden", s_prec_09_no_width_s_hidden, s_prec_09_no_width_s_hidden_bench, "{return test(\"%.09s\", s_hidden);}"},
	{1, 79, "s_prec_03_no_width_s_null", s_prec_03_no_width_s_null, s_prec_03_no_width_s_null_bench, "{return test(\"%.03s\", NULL);}"},
	{1, 80, "s_prec_09_no_width_s_null", s_prec_09_no_width_s_null, s_prec_09_no_width_s_null_bench, "{return test(\"%.09s\", NULL);}"},
	{1, 81, "s_prec_00_no_width_s_nullchar", s_prec_00_no_width_s_nullchar, s_prec_00_no_width_s_nullchar_bench, "{return test(\"%.00s\", \"\0\");}"},
	{1, 82, "s_prec_01_no_width_s_nullchar", s_prec_01_no_width_s_nullchar, s_prec_01_no_width_s_nullchar_bench, "{return test(\"%.01s\", \"\0\");}"},
	{1, 83, "s_prec_03_no_width_s_nullchar", s_prec_03_no_width_s_nullchar, s_prec_03_no_width_s_nullchar_bench, "{return test(\"%.03s\", \"\0\");}"},
	{1, 84, "s_prec_09_no_width_s_nullchar", s_prec_09_no_width_s_nullchar, s_prec_09_no_width_s_nullchar_bench, "{return test(\"%.09s\", \"\0\");}"},
	{1, 85, "s_prec_0_width_3_s_hidden", s_prec_0_width_3_s_hidden, s_prec_0_width_3_s_hidden_bench, "{return test(\"%3.s\", s_hidden);}"},
	{1, 86, "s_prec_0_width_10_s_hidden", s_prec_0_width_10_s_hidden, s_prec_0_width_10_s_hidden_bench, "{return test(\"%10.s\", s_hidden);}"},
	{1, 87, "s_prec_0_width_3_s_null", s_prec_0_width_3_s_null, s_prec_0_width_3_s_null_bench, "{return test(\"%3.s\", NULL);}"},
	{1, 88, "s_prec_0_width_10_s_null", s_prec_0_width_10_s_null, s_prec_0_width_10_s_null_bench, "{return test(\"%10.s\", NULL);}"},
	{1, 89, "s_prec_0_width_1_s_nullchar", s_prec_0_width_1_s_nullchar, s_prec_0_width_1_s_nullchar_bench, "{return test(\"%1.s\", \"\0\");}"},
	{1, 90, "s_prec_0_width_2_s_nullchar", s_prec_0_width_2_s_nullchar, s_prec_0_width_2_s_nullchar_bench, "{return test(\"%2.s\", \"\0\");}"},
	{1, 91, "s_prec_0_width_9_s_nullchar", s_prec_0_width_9_s_nullchar, s_prec_0_width_9_s_nullchar_bench, "{return test(\"%9.s\", \"\0\");}"},
	{1, 92, "s_prec_0_lj_width_3_s_hidden", s_prec_0_lj_width_3_s_hidden, s_prec_0_lj_width_3_s_hidden_bench, "{return test(\"%-3.s\", s_hidden);}"},
	{1, 93, "s_prec_0_lj_width_8_s_hidden", s_prec_0_lj_width_8_s_hidden, s_prec_0_lj_width_8_s_hidden_bench, "{return test(\"%-8.s\", s_hidden);}"},
	{1, 94, "s_prec_0_lj_width_3_s_null", s_prec_0_lj_width_3_s_null, s_prec_0_lj_width_3_s_null_bench, "{return test(\"%-3.s\", NULL);}"},
	{1, 95, "s_prec_0_lj_width_8_s_null", s_prec_0_lj_width_8_s_null, s_prec_0_lj_width_8_s_null_bench, "{return test(\"%-8.s\", NULL);}"},
	{1, 96, "s_prec_0_lj_width_1_s_nullchar", s_prec_0_lj_width_1_s_nullchar, s_prec_0_lj_width_1_s_nullchar_bench, "{return test(\"%-1.s\", \"\0\");}"},
	{1, 97, "s_prec_0_lj_width_2_s_nullchar", s_prec_0_lj_width_2_s_nullchar, s_prec_0_lj_width_2_s_nullchar_bench, "{return test(\"%-2.s\", \"\0\");}"},
	{1, 98, "s_prec_0_lj_width_6_s_nullchar", s_prec_0_lj_width_6_s_nullchar, s_prec_0_lj_width_6_s_nullchar_bench, "{return test(\"%-6.s\", \"\0\");}"},
	{1, 99, "s_prec_1_width_3_s_hidden", s_prec_1_width_3_s_hidden, s_prec_1_width_3_s_hidden_bench, "{return test(\"%3.1s\", s_hidden);}"},
	{1, 100, "s_prec_1_width_10_s_hidden", s_prec_1_width_10_s_hidden, s_prec_1_width_10_s_hidden_bench, "{return test(\"%10.1s\", s_hidden);}"},
	{1, 101, "s_prec_1_width_3_s_null", s_prec_1_width_3_s_null, s_prec_1_width_3_s_null_bench, "{return test(\"%3.1s\", NULL);}"},
	{1, 102, "s_prec_1_width_9_s_null", s_prec_1_width_9_s_null, s_prec_1_width_9_s_null_bench, "{return test(\"%9.1s\", NULL);}"},
	{1, 103, "s_prec_1_lj_width_3_s_hidden", s_prec_1_lj_width_3_s_hidden, s_prec_1_lj_width_3_s_hidden_bench, "{return test(\"%-3.1s\", s_hidden);}"},
	{1, 104, "s_prec_1_lj_width_10_s_hidden", s_prec_1_lj_width_10_s_hidden, s_prec_1_lj_width_10_s_hidden_bench, "{return test(\"%-10.1s\", s_hidden);}"},
	{1, 105, "s_prec_1_lj_width_3_s_null", s_prec_1_lj_width_3_s_null, s_prec_1_lj_width_3_s_null_bench, "{return test(\"%-3.1s\", NULL);}"},
	{1, 106, "s_prec_1_lj_width_9_s_null", s_prec_1_lj_width_9_s_null, s_prec_1_lj_width_9_s_null_bench, "{return test(\"%-9.1s\", NULL);}"},
	{1, 107, "s_prec_1_lj_width_3_s_nullchar", s_prec_1_lj_width_3_s_nullchar, s_prec_1_lj_width_3_s_nullchar_bench, "{return test(\"%-3.1s\", \"\0\");}"},
	{1, 108, "s_prec_1_lj_width_6_s_nullchar", s_prec_1_lj_width_6_s_nullchar, s_prec_1_lj_width_6_s_nullchar_bench, "{return test(\"%-6.1s\", \"\0\");}"},
	{1, 109, "s_prec_perfect_width_3_s_hidden", s_prec_perfect_width_3_s_hidden, s_prec_perfect_width_3_s_hidden_bench, "{return test(\"%3.6s\", s_hidden);}"},
	{1, 110, "s_prec_perfect_width_20_s_hidden", s_prec_perfect_width_20_s_hidden, s_prec_perfect_width_20_s_hidden_bench, "{return test(\"%20.6s\", s_hidden);}"},
	{1, 111, "s_prec_perfect_width_3_s_null", s_prec_perfect_width_3_s_null, s_prec_perfect_width_3_s_null_bench, "{return test(\"%3.6s\", NULL);}"},
	{1, 112, "s_prec_perfect_width_20_s_null", s_prec_perfect_width_20_s_null, s_prec_perfect_width_20_s_null_bench, "{return test(\"%20.6s\", NULL);}"},
	{1, 113, "s_prec_perfect_width_3_s_nullchar", s_prec_perfect_width_3_s_nullchar, s_prec_perfect_width_3_s_nullchar_bench, "{return test(\"%3.6s\", \"\0\");}"},
	{1, 114, "s_prec_perfect_width_6_s_nullchar", s_prec_perfect_width_6_s_nullchar, s_prec_perfect_width_6_s_nullchar_bench, "{return test(\"%6.6s\", \"\0\");}"},
	{1, 115, "s_prec_perfect_lj_width_3_s_hidden", s_prec_perfect_lj_width_3_s_hidden, s_prec_perfect_lj_width_3_s_hidden_bench, "{return test(\"%-3.6s\", s_hidden);}"},
	{1, 116, "s_prec_perfect_lj_width_20_s_hidden", s_prec_perfect_lj_width_20_s_hidden, s_prec_perfect_lj_width_20_s_hidden_bench, "{return test(\"%-20.6s\", s_hidden);}"},
	{1, 117, "s_prec_8_lj_width_3_s_hidden", s_prec_8_lj_width_3_s_hidden, s_prec_8_lj_width_3_s_hidden_bench, "{return test(\"%-3.8s\", s_hidden);}"},
	{1, 118, "s_prec_8_lj_width_10_s_hidden", s_prec_8_lj_width_10_s_hidden, s_prec_8_lj_width_10_s_hidden_bench, "{return test(\"%-10.8s\", s_hidden);}"},
	{1, 119, "s_prec_8_lj_width_3_s_null", s_prec_8_lj_width_3_s_null, s_prec_8_lj_width_3_s_null_bench, "{return test(\"%-3.8s\", NULL);}"},
	{1, 120, "s_prec_8_lj_width_10_s_null", s_prec_8_lj_width_10_s_null, s_prec_8_lj_width_10_s_null_bench, "{return test(\"%-10.8s\", NULL);}"},
	{1, 121, "s_prec_00_lj_s_hidden_trunc", s_prec_00_lj_s_hidden_trunc, s_prec_00_lj_s_hidden_trunc_bench, "{return test(\"%-.00s\", s_hidden);}"},
	{1, 122, "s_prec_09_lj_s_hidden_notrunc", s_prec_09_lj_s_hidden_notrunc, s_prec_09_lj_s_hidden_notrunc_bench, "{return test(\"%-.09s\", s_hidden);}"},
	{1, 123, "s_undefbehav_0_2zero", s_undefbehav_0_2zero, s_undefbehav_0_2zero_bench, "{return test(\"%00s\", s_hidden);}"},
	{1, 124, "s_undefbehav_0_3zero", s_undefbehav_0_3zero, s_undefbehav_0_3zero_bench, "{return test(\"%000s\", s_hidden);}"},
	{1, 125, "s_undefbehav_0_4zero", s_undefbehav_0_4zero, s_undefbehav_0_4zero_bench, "{return test(\"%0000s\", s_hidden);}"},
	{1, 126, "s_undefbehav_0_lj_2zero", s_undefbehav_0_lj_2zero, s_undefbehav_0_lj_2zero_bench, "{return test(\"%-00s\", s_hidden);}"},
	{1, 127, "s_undefbehav_0_zero_lj_zero", s_undefbehav_0_zero_lj_zero, s_undefbehav_0_zero_lj_zero_bench, "{return test(\"%0-0s\", s_hidden);}"},
	{1, 128, "s_undefbehav_0_2zero_lj", s_undefbehav_0_2zero_lj, s_undefbehav_0_2zero_lj_bench, "{return test(\"%00-s\", s_hidden);}"},
	{1, 129, "s_undefbehav_0_width_3", s_undefbehav_0_width_3, s_undefbehav_0_width_3_bench, "{return test(\"%03s\", s_hidden);}"},
	{1, 130, "s_undefbehav_0_width_9", s_undefbehav_0_width_9, s_undefbehav_0_width_9_bench, "{return test(\"%09s\", s_hidden);}"},
	{1, 131, "s_undefbehav_lj_0_width_3", s_undefbehav_lj_0_width_3, s_undefbehav_lj_0_width_3_bench, "{return test(\"%-03s\", s_hidden);}"},
	{1, 132, "s_undefbehav_lj_0_width_9", s_undefbehav_lj_0_width_9, s_undefbehav_lj_0_width_9_bench, "{return test(\"%-09s\", s_hidden);}"},
	{1, 133, "i_basic_i_pos", i_basic_i_pos, i_basic_i_pos_bench, "{return test(\"this %i number\", 17);}"},
	{1, 134, "i_basic_i_neg", i_basic_i_neg, i_basic_i_neg_bench, "{return test(\"this %i number\", -267);}"},
	{1, 135, "i_basic_i_zero", i_basic_i_zero, i_basic_i_zero_bench, "{return test(\"this %i number\", 0);}"},
	{1, 136, "i_basic_i_onlypos", i_basic_i_onlypos, i_basic_i_onlypos_bench, "{return test(\"%i\", 3);}"},
	{1, 137, "i_basic_i_onlyneg", i_basic_i_onlyneg, i_basic_i_onlyneg_bench, "{return test(\"%i\", -1);}"},
	{1, 138, "i_basic_i_onlyzero", i_basic_i_onlyzero, i_basic_i_onlyzero_bench, "{return test(\"%i\", 0);}"},
	{1, 139, "d_basic_pos", d_basic_pos, d_basic_pos_bench, "{return test(\"this %d number\", 17);}"},
	{1, 140, "d_basic_neg", d_basic_neg, d_basic_neg_bench, "{return test(\"this %d number\", -267);}"},
	{1, 141, "d_basic_zero", d_basic_zero, d_basic_zero_bench, "{return test(\"this %d number\", 0);}"},
	{1, 142, "i_intmax", i_intmax, i_intmax_bench, "{return test(\"%i\",  2147483647);}"},
	{1, 143, "i_intmin", i_intmin, i_intmin_bench, "{return test(\"%i\", (int)(-2147483678));}"},
	{1, 144, "i_width_pos_fits", i_width_pos_fits, i_width_pos_fits_bench, "{return test(\"%7i\", 33);}"},
	{1, 145, "i_width_neg_fits", i_width_neg_fits, i_width_neg_fits_bench, "{return test(\"%7i\", -14);}"},
	{1, 146, "i_width_zero_fits", i_width_zero_fits, i_width_zero_fits_bench, "{return test(\"%3i\", 0);}"},
	{1, 147, "i_width_pos_exactfit", i_width_pos_exactfit, i_width_pos_exactfit_bench, "{return test(\"%5i\", 52625);}"},
	{1, 148, "i_width_neg_exactfit", i_width_neg_exactfit, i_width_neg_exactfit_bench, "{return test(\"%5i\", -2562);}"},
	{1, 149, "i_width_pos_nofit", i_width_pos_nofit, i_width_pos_nofit_bench, "{return test(\"%4i\", 94827);}"},
	{1, 150, "i_width_neg_nofit", i_width_neg_nofit, i_width_neg_nofit_bench, "{return test(\"%4i\", -2464);}"},
	{1, 151, "i_width_pos_fits_lj", i_width_pos_fits_lj, i_width_pos_fits_lj_bench, "{return test(\"%-7i\", 33);}"},
	{1, 152, "i_width_neg_fits_lj", i_width_neg_fits_lj, i_width_neg_fits_lj_bench, "{return test(\"%-7i\", -14);}"},
	{1, 153, "i_width_zero_fits_lj", i_width_zero_fits_lj, i_width_zero_fits_lj_bench, "{return test(\"%-3i\", 0);}"},
	{1, 154, "i_width_pos_exactfit_lj", i_width_pos_exactfit_lj, i_width_pos_exactfit_lj_bench, "{return test(\"%-5i\", 52625);}"},
	{1, 155, "i_width_neg_exactfit_lj", i_width_neg_exactfit_lj, i_width_neg_exactfit_lj_bench, "{return test(\"%-5i\", -2562);}"},
	{1, 156, "i_width_pos_nofit_lj", i_width_pos_nofit_lj, i_width_pos_nofit_lj_bench, "{return test(\"%-4i\", 94827);}"},
	{1, 157, "i_width_neg_nofit_lj", i_width_neg_nofit_lj, i_width_neg_nofit_lj_bench, "{return test(\"%-4i\", -2464);}"},
	{1, 158, "i_prec_fits_pos", i_prec_fits_pos, i_prec_fits_pos_bench, "{return test(\"%.5i\", 2);}"},
	{1, 159, "i_prec_fits_neg", i_prec_fits_neg, i_prec_fits_neg_bench, "{return test(\"%.6i\", -3);}"},
	{1, 160, "i_prec_fits_zero", i_prec_fits_zero, i_prec_fits_zero_bench, "{return test(\"%.3i\", 0);}"},
	{1, 161, "i_prec_exactfit_pos", i_prec_exactfit_pos, i_prec_exactfit_pos_bench, "{return test(\"%.4i\", 5263);}"},
	{1, 162, "i_prec_exactfit_neg", i_prec_exactfit_neg, i_prec_exactfit_neg_bench, "{return test(\"%.4i\", -2372);}"},
	{1, 163, "i_prec_nofit_pos", i_prec_nofit_pos, i_prec_nofit_pos_bench, "{return test(\"%.3i\", 13862);}"},
	{1, 164, "i_prec_nofit_neg", i_prec_nofit_neg, i_prec_nofit_neg_bench, "{return test(\"%.3i\",-23646);}"},
	{1, 165, "i_zp_pos_fits", i_zp_pos_fits, i_zp_pos_fits_bench, "{return test(\"%05i\", 43);}"},
	{1, 166, "i_zp_neg_fits", i_zp_neg_fits, i_zp_neg_fits_bench, "{return test(\"%07i\", -54);}"},
	{1, 167, "i_zp_zero_fits", i_zp_zero_fits, i_zp_zero_fits_bench, "{return test(\"%03i\", 0);}"},
	{1, 168, "i_zp_pos_exactfit", i_zp_pos_exactfit, i_zp_pos_exactfit_bench, "{return test(\"%03i\", 634);}"},
	{1, 169, "i_zp_neg_exactfit", i_zp_neg_exactfit, i_zp_neg_exactfit_bench, "{return test(\"%04i\", -532);}"},
	{1, 170, "i_zp_neg_minus1fit", i_zp_neg_minus1fit, i_zp_neg_minus1fit_bench, "{return test(\"%04i\", -4825);}"},
	{1, 171, "i_prec_width_fit_fit_pos", i_prec_width_fit_fit_pos, i_prec_width_fit_fit_pos_bench, "{return test(\"%8.5i\", 34);}"},
	{1, 172, "i_prec_width_fit_fit_neg", i_prec_width_fit_fit_neg, i_prec_width_fit_fit_neg_bench, "{return test(\"%10.5i\", -216);}"},
	{1, 173, "i_prec_width_fit_fit_zero", i_prec_width_fit_fit_zero, i_prec_width_fit_fit_zero_bench, "{return test(\"%8.5i\", 0);}"},
	{1, 174, "i_prec_width_nofit_fit_pos", i_prec_width_nofit_fit_pos, i_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3i\", 8375);}"},
	{1, 175, "i_prec_width_nofit_fit_neg", i_prec_width_nofit_fit_neg, i_prec_width_nofit_fit_neg_bench, "{return test(\"%8.3i\", -8473);}"},
	{1, 176, "i_prec_width_fit_nofit_pos", i_prec_width_fit_nofit_pos, i_prec_width_fit_nofit_pos_bench, "{return test(\"%3.7i\", 3267);}"},
	{1, 177, "i_prec_width_fit_nofit_neg", i_prec_width_fit_nofit_neg, i_prec_width_fit_nofit_neg_bench, "{return test(\"%3.7i\", -2375);}"},
	{1, 178, "i_prec_width_nofit_nofit_pos", i_prec_width_nofit_nofit_pos, i_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3i\", 6983);}"},
	{1, 179, "i_prec_width_nofit_nofit_neg", i_prec_width_nofit_nofit_neg, i_prec_width_nofit_nofit_neg_bench, "{return test(\"%3.3i\", -8462);}"},
	{1, 180, "i_prec_width_fit_fit_pos_lj", i_prec_width_fit_fit_pos_lj, i_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5i\", 34);}"},
	{1, 181, "i_prec_width_fit_fit_neg_lj", i_prec_width_fit_fit_neg_lj, i_prec_width_fit_fit_neg_lj_bench, "{return test(\"%-10.5i\", -216);}"},
	{1, 182, "i_prec_width_fit_fit_zero_lj", i_prec_width_fit_fit_zero_lj, i_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5i\", 0);}"},
	{1, 183, "i_prec_width_nofit_fit_pos_lj", i_prec_width_nofit_fit_pos_lj, i_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3i\", 8375);}"},
	{1, 184, "i_prec_width_nofit_fit_neg_lj", i_prec_width_nofit_fit_neg_lj, i_prec_width_nofit_fit_neg_lj_bench, "{return test(\"%-8.3i\", -8473);}"},
	{1, 185, "i_prec_width_fit_nofit_pos_lj", i_prec_width_fit_nofit_pos_lj, i_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-3.7i\", 3267);}"},
	{1, 186, "i_prec_width_fit_nofit_neg_lj", i_prec_width_fit_nofit_neg_lj, i_prec_width_fit_nofit_neg_lj_bench, "{return test(\"%-3.7i\", -2375);}"},
	{1, 187, "i_prec_width_nofit_nofit_pos_lj", i_prec_width_nofit_nofit_pos_lj, i_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3i\", 6983);}"},
	{1, 188, "i_prec_width_nofit_nofit_neg_lj", i_prec_width_nofit_nofit_neg_lj, i_prec_width_nofit_nofit_neg_lj_bench, "{return test(\"%-3.3i\", -8462);}"},
	{1, 189, "i_prec_width_ff_pos_zp", i_prec_width_ff_pos_zp, i_prec_width_ff_pos_zp_bench, "{return test(\"%08.5i\", 34);}"},
	{1, 190, "i_prec_width_ff_neg_zp", i_prec_width_ff_neg_zp, i_prec_width_ff_neg_zp_bench, "{return test(\"%010.5i\", -216);}"},
	{1, 191, "i_prec_width_ff_zero_zp", i_prec_width_ff_zero_zp, i_prec_width_ff_zero_zp_bench, "{return test(\"%08.5i\", 0);}"},
	{1, 192, "i_prec_width_nf_pos_zp", i_prec_width_nf_pos_zp, i_prec_width_nf_pos_zp_bench, "{return test(\"%08.3i\", 8375);}"},
	{1, 193, "i_prec_width_nf_neg_zp", i_prec_width_nf_neg_zp, i_prec_width_nf_neg_zp_bench, "{return test(\"%08.3i\", -8473);}"},
	{1, 194, "i_prec_width_fn_pos_zp", i_prec_width_fn_pos_zp, i_prec_width_fn_pos_zp_bench, "{return test(\"%03.7i\", 3267);}"},
	{1, 195, "i_prec_width_fn_neg_zp", i_prec_width_fn_neg_zp, i_prec_width_fn_neg_zp_bench, "{return test(\"%03.7i\", -2375);}"},
	{1, 196, "i_prec_width_nn_pos_zp", i_prec_width_nn_pos_zp, i_prec_width_nn_pos_zp_bench, "{return test(\"%03.3i\", 6983);}"},
	{1, 197, "i_prec_width_nn_neg_zp", i_prec_width_nn_neg_zp, i_prec_width_nn_neg_zp_bench, "{return test(\"%03.3i\", -8462);}"},
	{1, 198, "i_prec_width_ff_pos_lj_zp_ignoreflag", i_prec_width_ff_pos_lj_zp_ignoreflag, i_prec_width_ff_pos_lj_zp_ignoreflag_bench, "{return test(\"%0-8.5i\", 34);}"},
	{1, 199, "i_prec_width_ff_neg_ljzp_ignoreflag", i_prec_width_ff_neg_ljzp_ignoreflag, i_prec_width_ff_neg_ljzp_ignoreflag_bench, "{return test(\"%0-10.5i\", -216);}"},
	{1, 200, "i_prec_width_ff_zero_ljzp_ignoreflag", i_prec_width_ff_zero_ljzp_ignoreflag, i_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5i\", 0);}"},
	{1, 201, "i_prec_width_nf_pos_ljzp_ignoreflag", i_prec_width_nf_pos_ljzp_ignoreflag, i_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3i\", 8375);}"},
	{1, 202, "i_prec_width_nf_neg_ljzp_ignoreflag", i_prec_width_nf_neg_ljzp_ignoreflag, i_prec_width_nf_neg_ljzp_ignoreflag_bench, "{return test(\"%0-8.3i\", -8473);}"},
	{1, 203, "i_prec_width_fn_pos_ljzp_ignoreflag", i_prec_width_fn_pos_ljzp_ignoreflag, i_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.7i\", 3267);}"},
	{1, 204, "i_prec_width_fn_neg_ljzp_ignoreflag", i_prec_width_fn_neg_ljzp_ignoreflag, i_prec_width_fn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.7i\", -2375);}"},
	{1, 205, "i_prec_width_nn_pos_ljzp_ignoreflag", i_prec_width_nn_pos_ljzp_ignoreflag, i_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3i\", 6983);}"},
	{1, 206, "i_prec_width_nn_neg_ljzp_ignoreflag", i_prec_width_nn_neg_ljzp_ignoreflag, i_prec_width_nn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.3i\", -8462);}"},
	{1, 207, "i_size_follows_i_i", i_size_follows_i_i, i_size_follows_i_i_bench, "{return test(\"[%i] [%i]\", i_pos_1, i_pos_1);}"},
	{1, 208, "i_prec0val0_basic", i_prec0val0_basic, i_prec0val0_basic_bench, "{return test(\"%.0i\", 0);}"},
	{1, 209, "i_prec0val0_implicit", i_prec0val0_implicit, i_prec0val0_implicit_bench, "{return test(\"%.i\", 0);}"},
	{1, 210, "i_prec0val0_w", i_prec0val0_w, i_prec0val0_w_bench, "{return test(\"%5.0i\", 0);}"},
	{1, 211, "i_prec0val0_w_impl", i_prec0val0_w_impl, i_prec0val0_w_impl_bench, "{return test(\"%5.i\", 0);}"},
	{1, 212, "i_prec0val0_wlj", i_prec0val0_wlj, i_prec0val0_wlj_bench, "{return test(\"%-5.0i\", 0);}"},
	{1, 213, "i_prec0val0_wlj_impl", i_prec0val0_wlj_impl, i_prec0val0_wlj_impl_bench, "{return test(\"%-5.i\", 0);}"},
	{1, 214, "d_basic_i_pos", d_basic_i_pos, d_basic_i_pos_bench, "{return test(\"this %d number\", 17);}"},
	{1, 215, "d_basic_i_neg", d_basic_i_neg, d_basic_i_neg_bench, "{return test(\"this %d number\", -267);}"},
	{1, 216, "d_basic_i_zero", d_basic_i_zero, d_basic_i_zero_bench, "{return test(\"this %d number\", 0);}"},
	{1, 217, "d_basic_i_onlypos", d_basic_i_onlypos, d_basic_i_onlypos_bench, "{return test(\"%d\", 3);}"},
	{1, 218, "d_basic_i_onlyneg", d_basic_i_onlyneg, d_basic_i_onlyneg_bench, "{return test(\"%d\", -1);}"},
	{1, 219, "d_basic_i_onlyzero", d_basic_i_onlyzero, d_basic_i_onlyzero_bench, "{return test(\"%d\", 0);}"},
	{1, 220, "d_intmax", d_intmax, d_intmax_bench, "{return test(\"%d\",  2147483647);}"},
	{1, 221, "d_intmin", d_intmin, d_intmin_bench, "{return test(\"%d\", (int)(-2147483678));}"},
	{1, 222, "d_width_pos_fits", d_width_pos_fits, d_width_pos_fits_bench, "{return test(\"%7d\", 33);}"},
	{1, 223, "d_width_neg_fits", d_width_neg_fits, d_width_neg_fits_bench, "{return test(\"%7d\", -14);}"},
	{1, 224, "d_width_zero_fits", d_width_zero_fits, d_width_zero_fits_bench, "{return test(\"%3d\", 0);}"},
	{1, 225, "d_width_pos_exactfit", d_width_pos_exactfit, d_width_pos_exactfit_bench, "{return test(\"%5d\", 52625);}"},
	{1, 226, "d_width_neg_exactfit", d_width_neg_exactfit, d_width_neg_exactfit_bench, "{return test(\"%5d\", -2562);}"},
	{1, 227, "d_width_pos_nofit", d_width_pos_nofit, d_width_pos_nofit_bench, "{return test(\"%4d\", 94827);}"},
	{1, 228, "d_width_neg_nofit", d_width_neg_nofit, d_width_neg_nofit_bench, "{return test(\"%4d\", -2464);}"},
	{1, 229, "d_width_pos_fits_lj", d_width_pos_fits_lj, d_width_pos_fits_lj_bench, "{return test(\"%-7d\", 33);}"},
	{1, 230, "d_width_neg_fits_lj", d_width_neg_fits_lj, d_width_neg_fits_lj_bench, "{return test(\"%-7d\", -14);}"},
	{1, 231, "d_width_zero_fits_lj", d_width_zero_fits_lj, d_width_zero_fits_lj_bench, "{return test(\"%-3d\", 0);}"},
	{1, 232, "d_width_pos_exactfit_lj", d_width_pos_exactfit_lj, d_width_pos_exactfit_lj_bench, "{return test(\"%-5d\", 52625);}"},
	{1, 233, "d_width_neg_exactfit_lj", d_width_neg_exactfit_lj, d_width_neg_exactfit_lj_bench, "{return test(\"%-5d\", -2562);}"},
	{1, 234, "d_width_pos_nofit_lj", d_width_pos_nofit_lj, d_width_pos_nofit_lj_bench, "{return test(\"%-4d\", 94827);}"},
	{1, 235, "d_width_neg_nofit_lj", d_width_neg_nofit_lj, d_width_neg_nofit_lj_bench, "{return test(\"%-4d\", -2464);}"},
	{1, 236, "d_prec_fits_pos", d_prec_fits_pos, d_prec_fits_pos_bench, "{return test(\"%.5d\", 2);}"},
	{1, 237, "d_prec_fits_neg", d_prec_fits_neg, d_prec_fits_neg_bench, "{return test(\"%.6d\", -3);}"},
	{1, 238, "d_prec_fits_zero", d_prec_fits_zero, d_prec_fits_zero_bench, "{return test(\"%.3d\", 0);}"},
	{1, 239, "d_prec_exactfit_pos", d_prec_exactfit_pos, d_prec_exactfit_pos_bench, "{return test(\"%.4d\", 5263);}"},
	{1, 240, "d_prec_exactfit_neg", d_prec_exactfit_neg, d_prec_exactfit_neg_bench, "{return test(\"%.4d\", -2372);}"},
	{1, 241, "d_prec_nofit_pos", d_prec_nofit_pos, d_prec_nofit_pos_bench, "{return test(\"%.3d\", 13862);}"},
	{1, 242, "d_prec_nofit_neg", d_prec_nofit_neg, d_prec_nofit_neg_bench, "{return test(\"%.3d\",-23646);}"},
	{1, 243, "d_zp_pos_fits", d_zp_pos_fits, d_zp_pos_fits_bench, "{return test(\"%05d\", 43);}"},
	{1, 244, "d_zp_neg_fits", d_zp_neg_fits, d_zp_neg_fits_bench, "{return test(\"%07d\", -54);}"},
	{1, 245, "d_zp_zero_fits", d_zp_zero_fits, d_zp_zero_fits_bench, "{return test(\"%03d\", 0);}"},
	{1, 246, "d_zp_pos_exactfit", d_zp_pos_exactfit, d_zp_pos_exactfit_bench, "{return test(\"%03d\", 634);}"},
	{1, 247, "d_zp_neg_exactfit", d_zp_neg_exactfit, d_zp_neg_exactfit_bench, "{return test(\"%04d\", -532);}"},
	{1, 248, "d_zp_neg_minus1fit", d_zp_neg_minus1fit, d_zp_neg_minus1fit_bench, "{return test(\"%04d\", -4825);}"},
	{1, 249, "d_prec_width_fit_fit_pos", d_prec_width_fit_fit_pos, d_prec_width_fit_fit_pos_bench, "{return test(\"%8.5d\", 34);}"},
	{1, 250, "d_prec_width_fit_fit_neg", d_prec_width_fit_fit_neg, d_prec_width_fit_fit_neg_bench, "{return test(\"%10.5d\", -216);}"},
	{1, 251, "d_prec_width_fit_fit_zero", d_prec_width_fit_fit_zero, d_prec_width_fit_fit_zero_bench, "{return test(\"%8.5d\", 0);}"},
	{1, 252, "d_prec_width_nofit_fit_pos", d_prec_width_nofit_fit_pos, d_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3d\", 8375);}"},
	{1, 253, "d_prec_width_nofit_fit_neg", d_prec_width_nofit_fit_neg, d_prec_width_nofit_fit_neg_bench, "{return test(\"%8.3d\", -8473);}"},
	{1, 254, "d_prec_width_fit_nofit_pos", d_prec_width_fit_nofit_pos, d_prec_width_fit_nofit_pos_bench, "{return test(\"%3.7d\", 3267);}"},
	{1, 255, "d_prec_width_fit_nofit_neg", d_prec_width_fit_nofit_neg, d_prec_width_fit_nofit_neg_bench, "{return test(\"%3.7d\", -2375);}"},
	{1, 256, "d_prec_width_nofit_nofit_pos", d_prec_width_nofit_nofit_pos, d_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3d\", 6983);}"},
	{1, 257, "d_prec_width_nofit_nofit_neg", d_prec_width_nofit_nofit_neg, d_prec_width_nofit_nofit_neg_bench, "{return test(\"%3.3d\", -8462);}"},
	{1, 258, "d_prec_width_fit_fit_pos_lj", d_prec_width_fit_fit_pos_lj, d_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5d\", 34);}"},
	{1, 259, "d_prec_width_fit_fit_neg_lj", d_prec_width_fit_fit_neg_lj, d_prec_width_fit_fit_neg_lj_bench, "{return test(\"%-10.5d\", -216);}"},
	{1, 260, "d_prec_width_fit_fit_zero_lj", d_prec_width_fit_fit_zero_lj, d_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5d\", 0);}"},
	{1, 261, "d_prec_width_nofit_fit_pos_lj", d_prec_width_nofit_fit_pos_lj, d_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3d\", 8375);}"},
	{1, 262, "d_prec_width_nofit_fit_neg_lj", d_prec_width_nofit_fit_neg_lj, d_prec_width_nofit_fit_neg_lj_bench, "{return test(\"%-8.3d\", -8473);}"},
	{1, 263, "d_prec_width_fit_nofit_pos_lj", d_prec_width_fit_nofit_pos_lj, d_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-3.7d\", 3267);}"},
	{1, 264, "d_prec_width_fit_nofit_neg_lj", d_prec_width_fit_nofit_neg_lj, d_prec_width_fit_nofit_neg_lj_bench, "{return test(\"%-3.7d\", -2375);}"},
	{1, 265, "d_prec_width_nofit_nofit_pos_lj", d_prec_width_nofit_nofit_pos_lj, d_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3d\", 6983);}"},
	{1, 266, "d_prec_width_nofit_nofit_neg_lj", d_prec_width_nofit_nofit_neg_lj, d_prec_width_nofit_nofit_neg_lj_bench, "{return test(\"%-3.3d\", -8462);}"},
	{1, 267, "d_prec_width_ff_pos_zp", d_prec_width_ff_pos_zp, d_prec_width_ff_pos_zp_bench, "{return test(\"%08.5d\", 34);}"},
	{1, 268, "d_prec_width_ff_neg_zp", d_prec_width_ff_neg_zp, d_prec_width_ff_neg_zp_bench, "{return test(\"%010.5d\", -216);}"},
	{1, 269, "d_prec_width_ff_zero_zp", d_prec_width_ff_zero_zp, d_prec_width_ff_zero_zp_bench, "{return test(\"%08.5d\", 0);}"},
	{1, 270, "d_prec_width_nf_pos_zp", d_prec_width_nf_pos_zp, d_prec_width_nf_pos_zp_bench, "{return test(\"%08.3d\", 8375);}"},
	{1, 271, "d_prec_width_nf_neg_zp", d_prec_width_nf_neg_zp, d_prec_width_nf_neg_zp_bench, "{return test(\"%08.3d\", -8473);}"},
	{1, 272, "d_prec_width_fn_pos_zp", d_prec_width_fn_pos_zp, d_prec_width_fn_pos_zp_bench, "{return test(\"%03.7d\", 3267);}"},
	{1, 273, "d_prec_width_fn_neg_zp", d_prec_width_fn_neg_zp, d_prec_width_fn_neg_zp_bench, "{return test(\"%03.7d\", -2375);}"},
	{1, 274, "d_prec_width_nn_pos_zp", d_prec_width_nn_pos_zp, d_prec_width_nn_pos_zp_bench, "{return test(\"%03.3d\", 6983);}"},
	{1, 275, "d_prec_width_nn_neg_zp", d_prec_width_nn_neg_zp, d_prec_width_nn_neg_zp_bench, "{return test(\"%03.3d\", -8462);}"},
	{1, 276, "d_prec_width_ff_pos_lj_zp_ignoreflag", d_prec_width_ff_pos_lj_zp_ignoreflag, d_prec_width_ff_pos_lj_zp_ignoreflag_bench, "{return test(\"%0-8.5d\", 34);}"},
	{1, 277, "d_prec_width_ff_neg_ljzp_ignoreflag", d_prec_width_ff_neg_ljzp_ignoreflag, d_prec_width_ff_neg_ljzp_ignoreflag_bench, "{return test(\"%0-10.5d\", -216);}"},
	{1, 278, "d_prec_width_ff_zero_ljzp_ignoreflag", d_prec_width_ff_zero_ljzp_ignoreflag, d_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5d\", 0);}"},
	{1, 279, "d_prec_width_nf_pos_ljzp_ignoreflag", d_prec_width_nf_pos_ljzp_ignoreflag, d_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3d\", 8375);}"},
	{1, 280, "d_prec_width_nf_neg_ljzp_ignoreflag", d_prec_width_nf_neg_ljzp_ignoreflag, d_prec_width_nf_neg_ljzp_ignoreflag_bench, "{return test(\"%0-8.3d\", -8473);}"},
	{1, 281, "d_prec_width_fn_pos_ljzp_ignoreflag", d_prec_width_fn_pos_ljzp_ignoreflag, d_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.7d\", 3267);}"},
	{1, 282, "d_prec_width_fn_neg_ljzp_ignoreflag", d_prec_width_fn_neg_ljzp_ignoreflag, d_prec_width_fn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.7d\", -2375);}"},
	{1, 283, "d_prec_width_nn_pos_ljzp_ignoreflag", d_prec_width_nn_pos_ljzp_ignoreflag, d_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3d\", 6983);}"},
	{1, 284, "d_prec_width_nn_neg_ljzp_ignoreflag", d_prec_width_nn_neg_ljzp_ignoreflag, d_prec_width_nn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.3d\", -8462);}"},
	{1, 285, "d_prec0val0_basic", d_prec0val0_basic, d_prec0val0_basic_bench, "{return test(\"%.0d\", 0);}"},
	{1, 286, "d_prec0val0_implicit", d_prec0val0_implicit, d_prec0val0_implicit_bench, "{return test(\"%.d\", 0);}"},
	{1, 287, "d_prec0val0_w", d_prec0val0_w, d_prec0val0_w_bench, "{return test(\"%5.0d\", 0);}"},
	{1, 288, "d_prec0val0_w_impl", d_prec0val0_w_impl, d_prec0val0_w_impl_bench, "{return test(\"%5.d\", 0);}"},
	{1, 289, "d_prec0val0_wlj", d_prec0val0_wlj, d_prec0val0_wlj_bench, "{return test(\"%-5.0d\", 0);}"},
	{1, 290, "d_prec0val0_wlj_impl", d_prec0val0_wlj_impl, d_prec0val0_wlj_impl_bench, "{return test(\"%-5.d\", 0);}"},
	{1, 291, "u_basic_u_pos", u_basic_u_pos, u_basic_u_pos_bench, "{return test(\"this %u number\", 17);}"},
	{1, 292, "u_basic_u_zero", u_basic_u_zero, u_basic_u_zero_bench, "{return test(\"this %u number\", 0);}"},
	{1, 293, "u_basic_u_onlypos", u_basic_u_onlypos, u_basic_u_onlypos_bench, "{return test(\"%u\", 3);}"},
	{1, 294, "u_uintmax", u_uintmax, u_uintmax_bench, "{return test(\"%u\", 4294967295u);}"},
	{1, 295, "u_width_pos_fits", u_width_pos_fits, u_width_pos_fits_bench, "{return test(\"%7u\", 33);}"},
	{1, 296, "u_width_zero_fits", u_width_zero_fits, u_width_zero_fits_bench, "{return test(\"%3u\", 0);}"},
	{1, 297, "u_width_pos_exactfit", u_width_pos_exactfit, u_width_pos_exactfit_bench, "{return test(\"%5u\", 52625);}"},
	{1, 298, "u_width_pos_nofit", u_width_pos_nofit, u_width_pos_nofit_bench, "{return test(\"%4u\", 94827);}"},
	{1, 299, "u_width_pos_fits_lj", u_width_pos_fits_lj, u_width_pos_fits_lj_bench, "{return test(\"%-7u\", 33);}"},
	{1, 300, "u_width_zero_fits_lj", u_width_zero_fits_lj, u_width_zero_fits_lj_bench, "{return test(\"%-3u\", 0);}"},
	{1, 301, "u_width_pos_exactfit_lj", u_width_pos_exactfit_lj, u_width_pos_exactfit_lj_bench, "{return test(\"%-5u\", 52625);}"},
	{1, 302, "u_width_pos_nofit_lj", u_width_pos_nofit_lj, u_width_pos_nofit_lj_bench, "{return test(\"%-4u\", 94827);}"},
	{1, 303, "u_prec_fits_pos", u_prec_fits_pos, u_prec_fits_pos_bench, "{return test(\"%.5u\", 2);}"},
	{1, 304, "u_prec_fits_zero", u_prec_fits_zero, u_prec_fits_zero_bench, "{return test(\"%.3u\", 0);}"},
	{1, 305, "u_prec_exactfit_pos", u_prec_exactfit_pos, u_prec_exactfit_pos_bench, "{return test(\"%.4u\", 5263);}"},
	{1, 306, "u_prec_nofit_pos", u_prec_nofit_pos, u_prec_nofit_pos_bench, "{return test(\"%.3u\", 13862);}"},
	{1, 307, "u_zp_pos_fits", u_zp_pos_fits, u_zp_pos_fits_bench, "{return test(\"%05u\", 43);}"},
	{1, 308, "u_zp_zero_fits", u_zp_zero_fits, u_zp_zero_fits_bench, "{return test(\"%03u\", 0);}"},
	{1, 309, "u_zp_pos_exactfit", u_zp_pos_exactfit, u_zp_pos_exactfit_bench, "{return test(\"%03u\", 634);}"},
	{1, 310, "u_prec_width_fit_fit_pos", u_prec_width_fit_fit_pos, u_prec_width_fit_fit_pos_bench, "{return test(\"%8.5u\", 34);}"},
	{1, 311, "u_prec_width_fit_fit_zero", u_prec_width_fit_fit_zero, u_prec_width_fit_fit_zero_bench, "{return test(\"%8.5u\", 0);}"},
	{1, 312, "u_prec_width_nofit_fit_pos", u_prec_width_nofit_fit_pos, u_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3u\", 8375);}"},
	{1, 313, "u_prec_width_fit_nofit_pos", u_prec_width_fit_nofit_pos, u_prec_width_fit_nofit_pos_bench, "{return test(\"%3.7u\", 3267);}"},
	{1, 314, "u_prec_width_nofit_nofit_pos", u_prec_width_nofit_nofit_pos, u_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3u\", 6983);}"},
	{1, 315, "u_prec_width_fit_fit_pos_lj", u_prec_width_fit_fit_pos_lj, u_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5u\", 34);}"},
	{1, 316, "u_prec_width_fit_fit_zero_lj", u_prec_width_fit_fit_zero_lj, u_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5u\", 0);}"},
	{1, 317, "u_prec_width_nofit_fit_pos_lj", u_prec_width_nofit_fit_pos_lj, u_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3u\", 8375);}"},
	{1, 318, "u_prec_width_fit_nofit_pos_lj", u_prec_width_fit_nofit_pos_lj, u_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-3.7u\", 3267);}"},
	{1, 319, "u_prec_width_nofit_nofit_pos_lj", u_prec_width_nofit_nofit_pos_lj, u_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3u\", 6983);}"},
	{1, 320, "u_prec_width_ff_pos_zp", u_prec_width_ff_pos_zp, u_prec_width_ff_pos_zp_bench, "{return test(\"%08.5u\", 34);}"},
	{1, 321, "u_prec_width_ff_zero_zp", u_prec_width_ff_zero_zp, u_prec_width_ff_zero_zp_bench, "{return test(\"%08.5u\", 0);}"},
	{1, 322, "u_prec_width_nf_pos_zp", u_prec_width_nf_pos_zp, u_prec_width_nf_pos_zp_bench, "{return test(\"%08.3u\", 8375);}"},
	{1, 323, "u_prec_width_fn_pos_zp", u_prec_width_fn_pos_zp, u_prec_width_fn_pos_zp_bench, "{return test(\"%03.7u\", 3267);}"},
	{1, 324, "u_prec_width_nn_pos_zp", u_prec_width_nn_pos_zp, u_prec_width_nn_pos_zp_bench, "{return test(\"%03.3u\", 6983);}"},
	{1, 325, "u_prec_width_ff_pos_ljzp_ignoreflag", u_prec_width_ff_pos_ljzp_ignoreflag, u_prec_width_ff_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.5u\", 34);}"},
	{1, 326, "u_prec_width_ff_zero_ljzp_ignoreflag", u_prec_width_ff_zero_ljzp_ignoreflag, u_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5u\", 0);}"},
	{1, 327, "u_prec_width_nf_pos_ljzp_ignoreflag", u_prec_width_nf_pos_ljzp_ignoreflag, u_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3u\", 8375);}"},
	{1, 328, "u_prec_width_fn_pos_ljzp_ignoreflag", u_prec_width_fn_pos_ljzp_ignoreflag, u_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.7u\", 3267);}"},
	{1, 329, "u_prec_width_nn_pos_ljzp_ignoreflag", u_prec_width_nn_pos_ljzp_ignoreflag, u_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3u\", 6983);}"},
	{1, 330, "u_prec0val0_basic", u_prec0val0_basic, u_prec0val0_basic_bench, "{return test(\"%.0u\", 0);}"},
	{1, 331, "u_prec0val0_implicit", u_prec0val0_implicit, u_prec0val0_implicit_bench, "{return test(\"%.u\", 0);}"},
	{1, 332, "u_prec0val0_w", u_prec0val0_w, u_prec0val0_w_bench, "{return test(\"%5.0u\", 0);}"},
	{1, 333, "u_prec0val0_w_impl", u_prec0val0_w_impl, u_prec0val0_w_impl_bench, "{return test(\"%5.u\", 0);}"},
	{1, 334, "u_prec0val0_wlj", u_prec0val0_wlj, u_prec0val0_wlj_bench, "{return test(\"%-5.0u\", 0);}"},
	{1, 335, "u_prec0val0_wlj_impl", u_prec0val0_wlj_impl, u_prec0val0_wlj_impl_bench, "{return test(\"%-5.u\", 0);}"},
	{1, 336, "x_basic_pos", x_basic_pos, x_basic_pos_bench, "{return test(\"this %x number\", 17);}"},
	{1, 337, "x_basic_zero", x_basic_zero, x_basic_zero_bench, "{return test(\"this %x number\", 0);}"},
	{1, 338, "x_basic_onlypos", x_basic_onlypos, x_basic_onlypos_bench, "{return test(\"%x\", 3);}"},
	{1, 339, "x_hexlmax", x_hexlmax, x_hexlmax_bench, "{return test(\"%x\", 4294967295u);}"},
	{1, 340, "x_width_pos_fits", x_width_pos_fits, x_width_pos_fits_bench, "{return test(\"%7x\", 33);}"},
	{1, 341, "x_width_zero_fits", x_width_zero_fits, x_width_zero_fits_bench, "{return test(\"%3x\", 0);}"},
	{1, 342, "x_width_pos_exactfit", x_width_pos_exactfit, x_width_pos_exactfit_bench, "{return test(\"%5x\", 52625);}"},
	{1, 343, "x_width_pos_nofit", x_width_pos_nofit, x_width_pos_nofit_bench, "{return test(\"%2x\", 94827);}"},
	{1, 344, "x_width_pos_fits_lj", x_width_pos_fits_lj, x_width_pos_fits_lj_bench, "{return test(\"%-7x\", 33);}"},
	{1, 345, "x_width_zero_fits_lj", x_width_zero_fits_lj, x_width_zero_fits_lj_bench, "{return test(\"%-3x\", 0);}"},
	{1, 346, "x_width_pos_exactfit_lj", x_width_pos_exactfit_lj, x_width_pos_exactfit_lj_bench, "{return test(\"%-5x\", 52625);}"},
	{1, 347, "x_width_pos_nofit_lj", x_width_pos_nofit_lj, x_width_pos_nofit_lj_bench, "{return test(\"%-4x\", 9648627);}"},
	{1, 348, "x_prec_fits_pos", x_prec_fits_pos, x_prec_fits_pos_bench, "{return test(\"%.5x\", 21);}"},
	{1, 349, "x_prec_fits_zero", x_prec_fits_zero, x_prec_fits_zero_bench, "{return test(\"%.3x\", 0);}"},
	{1, 350, "x_prec_exactfit_pos", x_prec_exactfit_pos, x_prec_exactfit_pos_bench, "{return test(\"%.4x\", 5263);}"},
	{1, 351, "x_prec_nofit_pos", x_prec_nofit_pos, x_prec_nofit_pos_bench, "{return test(\"%.3x\", 938862);}"},
	{1, 352, "x_zp_pos_fits", x_zp_pos_fits, x_zp_pos_fits_bench, "{return test(\"%05x\", 43);}"},
	{1, 353, "x_zp_zero_fits", x_zp_zero_fits, x_zp_zero_fits_bench, "{return test(\"%03x\", 0);}"},
	{1, 354, "x_zp_pos_exactfit", x_zp_pos_exactfit, x_zp_pos_exactfit_bench, "{return test(\"%03x\", 698334);}"},
	{1, 355, "x_prec_width_fit_fit_pos", x_prec_width_fit_fit_pos, x_prec_width_fit_fit_pos_bench, "{return test(\"%8.5x\", 34);}"},
	{1, 356, "x_prec_width_fit_fit_zero", x_prec_width_fit_fit_zero, x_prec_width_fit_fit_zero_bench, "{return test(\"%8.5x\", 0);}"},
	{1, 357, "x_prec_width_nofit_fit_pos", x_prec_width_nofit_fit_pos, x_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3x\", 8375);}"},
	{1, 358, "x_prec_width_fit_nofit_pos", x_prec_width_fit_nofit_pos, x_prec_width_fit_nofit_pos_bench, "{return test(\"%2.7x\", 3267);}"},
	{1, 359, "x_prec_width_nofit_nofit_pos", x_prec_width_nofit_nofit_pos, x_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3x\", 6983);}"},
	{1, 360, "x_prec_width_fit_fit_pos_lj", x_prec_width_fit_fit_pos_lj, x_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5x\", 34);}"},
	{1, 361, "x_prec_width_fit_fit_zero_lj", x_prec_width_fit_fit_zero_lj, x_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5x\", 0);}"},
	{1, 362, "x_prec_width_nofit_fit_pos_lj", x_prec_width_nofit_fit_pos_lj, x_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3x\", 8375);}"},
	{1, 363, "x_prec_width_fit_nofit_pos_lj", x_prec_width_fit_nofit_pos_lj, x_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-2.7x\", 3267);}"},
	{1, 364, "x_prec_width_nofit_nofit_pos_lj", x_prec_width_nofit_nofit_pos_lj, x_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3x\", 6983);}"},
	{1, 365, "x_prec_width_ff_pos_zp", x_prec_width_ff_pos_zp, x_prec_width_ff_pos_zp_bench, "{return test(\"%08.5x\", 34);}"},
	{1, 366, "x_prec_width_ff_zero_zp", x_prec_width_ff_zero_zp, x_prec_width_ff_zero_zp_bench, "{return test(\"%08.5x\", 0);}"},
	{1, 367, "x_prec_width_nf_pos_zp", x_prec_width_nf_pos_zp, x_prec_width_nf_pos_zp_bench, "{return test(\"%08.3x\", 8375);}"},
	{1, 368, "x_prec_width_fn_pos_zp", x_prec_width_fn_pos_zp, x_prec_width_fn_pos_zp_bench, "{return test(\"%02.7x\", 3267);}"},
	{1, 369, "x_prec_width_nn_pos_zp", x_prec_width_nn_pos_zp, x_prec_width_nn_pos_zp_bench, "{return test(\"%03.3x\", 6983);}"},
	{1, 370, "x_prec_width_ff_pos_ljzp_ignoreflag", x_prec_width_ff_pos_ljzp_ignoreflag, x_prec_width_ff_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.5x\", 34);}"},
	{1, 371, "x_prec_width_ff_zero_ljzp_ignoreflag", x_prec_width_ff_zero_ljzp_ignoreflag, x_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5x\", 0);}"},
	{1, 372, "x_prec_width_nf_pos_ljzp_ignoreflag", x_prec_width_nf_pos_ljzp_ignoreflag, x_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3x\", 8375);}"},
	{1, 373, "x_prec_width_fn_pos_ljzp_ignoreflag", x_prec_width_fn_pos_ljzp_ignoreflag, x_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-2.7x\", 3267);}"},
	{1, 374, "x_prec_width_nn_pos_ljzp_ignoreflag", x_prec_width_nn_pos_ljzp_ignoreflag, x_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3x\", 6983);}"},
	{1, 375, "x_prec0val0_basic", x_prec0val0_basic, x_prec0val0_basic_bench, "{return test(\"%.0x\", 0);}"},
	{1, 376, "x_prec0val0_implicit", x_prec0val0_implicit, x_prec0val0_implicit_bench, "{return test(\"%.x\", 0);}"},
	{1, 377, "x_prec0val0_w", x_prec0val0_w, x_prec0val0_w_bench, "{return test(\"%5.0x\", 0);}"},
	{1, 378, "x_prec0val0_w_impl", x_prec0val0_w_impl, x_prec0val0_w_impl_bench, "{return test(\"%5.x\", 0);}"},
	{1, 379, "x_prec0val0_wlj", x_prec0val0_wlj, x_prec0val0_wlj_bench, "{return test(\"%-5.0x\", 0);}"},
	{1, 380, "x_prec0val0_wlj_impl", x_prec0val0_wlj_impl, x_prec0val0_wlj_impl_bench, "{return test(\"%-5.x\", 0);}"},
	{1, 381, "X_basic_hexu_pos", X_basic_hexu_pos, X_basic_hexu_pos_bench, "{return test(\"this %X number\", 17);}"},
	{1, 382, "X_basic_hexu_zero", X_basic_hexu_zero, X_basic_hexu_zero_bench, "{return test(\"this %X number\", 0);}"},
	{1, 383, "X_basic_hexu_onlypos", X_basic_hexu_onlypos, X_basic_hexu_onlypos_bench, "{return test(\"%X\", 3);}"},
	{1, 384, "X_hexumax", X_hexumax, X_hexumax_bench, "{return test(\"%X\", 4294967295u);}"},
	{1, 385, "X_width_pos_fits", X_width_pos_fits, X_width_pos_fits_bench, "{return test(\"%7X\", 33);}"},
	{1, 386, "X_width_zero_fits", X_width_zero_fits, X_width_zero_fits_bench, "{return test(\"%3X\", 0);}"},
	{1, 387, "X_width_pos_exactfit", X_width_pos_exactfit, X_width_pos_exactfit_bench, "{return test(\"%5X\", 52625);}"},
	{1, 388, "X_width_pos_nofit", X_width_pos_nofit, X_width_pos_nofit_bench, "{return test(\"%2X\", 94827);}"},
	{1, 389, "X_width_pos_fits_lj", X_width_pos_fits_lj, X_width_pos_fits_lj_bench, "{return test(\"%-7X\", 33);}"},
	{1, 390, "X_width_zero_fits_lj", X_width_zero_fits_lj, X_width_zero_fits_lj_bench, "{return test(\"%-3X\", 0);}"},
	{1, 391, "X_width_pos_exactfit_lj", X_width_pos_exactfit_lj, X_width_pos_exactfit_lj_bench, "{return test(\"%-5X\", 52625);}"},
	{1, 392, "X_width_pos_nofit_lj", X_width_pos_nofit_lj, X_width_pos_nofit_lj_bench, "{return test(\"%-4X\", 9648627);}"},
	{1, 393, "X_prec_fits_pos", X_prec_fits_pos, X_prec_fits_pos_bench, "{return test(\"%.5X\", 21);}"},
	{1, 394, "X_prec_fits_zero", X_prec_fits_zero, X_prec_fits_zero_bench, "{return test(\"%.3X\", 0);}"},
	{1, 395, "X_prec_exactfit_pos", X_prec_exactfit_pos, X_prec_exactfit_pos_bench, "{return test(\"%.4X\", 5263);}"},
	{1, 396, "X_prec_nofit_pos", X_prec_nofit_pos, X_prec_nofit_pos_bench, "{return test(\"%.3X\", 938862);}"},
	{1, 397, "X_zp_pos_fits", X_zp_pos_fits, X_zp_pos_fits_bench, "{return test(\"%05X\", 43);}"},
	{1, 398, "X_zp_zero_fits", X_zp_zero_fits, X_zp_zero_fits_bench, "{return test(\"%03X\", 0);}"},
	{1, 399, "X_zp_pos_exactfit", X_zp_pos_exactfit, X_zp_pos_exactfit_bench, "{return test(\"%03X\", 698334);}"},
	{1, 400, "X_prec_width_fit_fit_pos", X_prec_width_fit_fit_pos, X_prec_width_fit_fit_pos_bench, "{return test(\"%8.5X\", 34);}"},
	{1, 401, "X_prec_width_fit_fit_zero", X_prec_width_fit_fit_zero, X_prec_width_fit_fit_zero_bench, "{return test(\"%8.5X\", 0);}"},
	{1, 402, "X_prec_width_nofit_fit_pos", X_prec_width_nofit_fit_pos, X_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3X\", 8375);}"},
	{1, 403, "X_prec_width_fit_nofit_pos", X_prec_width_fit_nofit_pos, X_prec_width_fit_nofit_pos_bench, "{return test(\"%2.7X\", 3267);}"},
	{1, 404, "X_prec_width_nofit_nofit_pos", X_prec_width_nofit_nofit_pos, X_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3X\", 6983);}"},
	{1, 405, "X_prec_width_fit_fit_pos_lj", X_prec_width_fit_fit_pos_lj, X_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5X\", 34);}"},
	{1, 406, "X_prec_width_fit_fit_zero_lj", X_prec_width_fit_fit_zero_lj, X_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5X\", 0);}"},
	{1, 407, "X_prec_width_nofit_fit_pos_lj", X_prec_width_nofit_fit_pos_lj, X_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3X\", 8375);}"},
	{1, 408, "X_prec_width_fit_nofit_pos_lj", X_prec_width_fit_nofit_pos_lj, X_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-2.7X\", 3267);}"},
	{1, 409, "X_prec_width_nofit_nofit_pos_lj", X_prec_width_nofit_nofit_pos_lj, X_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3X\", 6983);}"},
	{1, 410, "X_prec_width_ff_pos_zp", X_prec_width_ff_pos_zp, X_prec_width_ff_pos_zp_bench, "{return test(\"%08.5X\", 34);}"},
	{1, 411, "X_prec_width_ff_zero_zp", X_prec_width_ff_zero_zp, X_prec_width_ff_zero_zp_bench, "{return test(\"%08.5X\", 0);}"},
	{1, 412, "X_prec_width_nf_pos_zp", X_prec_width_nf_pos_zp, X_prec_width_nf_pos_zp_bench, "{return test(\"%08.3X\", 8375);}"},
	{1, 413, "X_prec_width_fn_pos_zp", X_prec_width_fn_pos_zp, X_prec_width_fn_pos_zp_bench, "{return test(\"%02.7X\", 3267);}"},
	{1, 414, "X_prec_width_nn_pos_zp", X_prec_width_nn_pos_zp, X_prec_width_nn_pos_zp_bench, "{return test(\"%03.3X\", 6983);}"},
	{1, 415, "X_prec_width_ff_pos_ljzp_ignoreflag", X_prec_width_ff_pos_ljzp_ignoreflag, X_prec_width_ff_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.5X\", 34);}"},
	{1, 416, "X_prec_width_ff_zero_ljzp_ignoreflag", X_prec_width_ff_zero_ljzp_ignoreflag, X_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5X\", 0);}"},
	{1, 417, "X_prec_width_nf_pos_ljzp_ignoreflag", X_prec_width_nf_pos_ljzp_ignoreflag, X_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3X\", 8375);}"},
	{1, 418, "X_prec_width_fn_pos_ljzp_ignoreflag", X_prec_width_fn_pos_ljzp_ignoreflag, X_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-2.7X\", 3267);}"},
	{1, 419, "X_prec_width_nn_pos_ljzp_ignoreflag", X_prec_width_nn_pos_ljzp_ignoreflag, X_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3X\", 6983);}"},
	{1, 420, "X_prec0val0_basic", X_prec0val0_basic, X_prec0val0_basic_bench, "{return test(\"%.0X\", 0);}"},
	{1, 421, "X_prec0val0_implicit", X_prec0val0_implicit, X_prec0val0_implicit_bench, "{return test(\"%.X\", 0);}"},
	{1, 422, "X_prec0val0_w", X_prec0val0_w, X_prec0val0_w_bench, "{return test(\"%5.0X\", 0);}"},
	{1, 423, "X_prec0val0_w_impl", X_prec0val0_w_impl, X_prec0val0_w_impl_bench, "{return test(\"%5.X\", 0);}"},
	{1, 424, "X_prec0val0_wlj", X_prec0val0_wlj, X_prec0val0_wlj_bench, "{return test(\"%-5.0X\", 0);}"},
	{1, 425, "X_prec0val0_wlj_impl", X_prec0val0_wlj_impl, X_prec0val0_wlj_impl_bench, "{return test(\"%-5.X\", 0);}"},
	{1, 426, "p_null", p_null, p_null_bench, "{return test(\"%p\", NULL);}"},
	{1, 427, "p_null_width_fit", p_null_width_fit, p_null_width_fit_bench, "{return test(\"%5p\", NULL);}"},
	{1, 428, "p_null_width_nofit", p_null_width_nofit, p_null_width_nofit_bench, "{return test(\"%2p\", NULL);}"},
	{1, 429, "p_void", p_void, p_void_bench, "{return test(\"%.p\", NULL);}"},
	{1, 430, "p_void_width_fit", p_void_width_fit, p_void_width_fit_bench, "{return test(\"%5.p\", NULL);}"},
	{1, 431, "p_void_width_nofit", p_void_width_nofit, p_void_width_nofit_bench, "{return test(\"%2.p\", NULL);}"},
	{1, 432, "p_ftfc_literal_9w_prec2_undefbehav", p_ftfc_literal_9w_prec2_undefbehav, p_ftfc_literal_9w_prec2_undefbehav_bench, "{return test(\"%9.2p\n\", 1234);}"},
	{1, 433, "p_ftfc_literal_2w_prec9_undefbehav", p_ftfc_literal_2w_prec9_undefbehav, p_ftfc_literal_2w_prec9_undefbehav_bench, "{return test(\"%2.9p\n\", 1234);}"},
	{1, 434, "p_ftfc_zero_prec5_undefbehav", p_ftfc_zero_prec5_undefbehav, p_ftfc_zero_prec5_undefbehav_bench, "{return test(\"%.5p\", 0);}"},
	{1, 435, "p_ftfc_zero_prec0_undefbehav", p_ftfc_zero_prec0_undefbehav, p_ftfc_zero_prec0_undefbehav_bench, "{return test(\"%.0p\", 0);}"},
	{1, 436, "p_ftfc_5w_throwswarning", p_ftfc_5w_throwswarning, p_ftfc_5w_throwswarning_bench, "{return test(\"%5p\", 0);}"},
	{1, 437, "p_basic", p_basic, p_basic_bench, "{return test(\"%p%p%p%p%p%p%p%p%p%p%p%p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 438, "p_width_fit", p_width_fit, p_width_fit_bench, "{return test(\"%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 439, "p_width_nofit", p_width_nofit, p_width_nofit_bench, "{return test(\"%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 440, "p_width_16", p_width_16, p_width_16_bench, "{return test(\"%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 441, "p_width_8", p_width_8, p_width_8_bench, "{return test(\"%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 442, "p_width_32", p_width_32, p_width_32_bench, "{return test(\"%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 443, "p_width_fit_lj", p_width_fit_lj, p_width_fit_lj_bench, "{return test(\"%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 444, "p_width_nofit_lj", p_width_nofit_lj, p_width_nofit_lj_bench, "{return test(\"%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 445, "p_width_16_lj", p_width_16_lj, p_width_16_lj_bench, "{return test(\"%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 446, "p_width_8_lj", p_width_8_lj, p_width_8_lj_bench, "{return test(\"%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 447, "p_width_32_lj", p_width_32_lj, p_width_32_lj_bench, "{return test(\"%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 448, "c_allprintable_combined", c_allprintable_combined, c_allprintable_combined_bench, "{return test(\"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\",' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}"},
	{1, 449, "c_1_31_combined", c_1_31_combined, c_1_31_combined_bench, "{return test(\"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}"},
	{1, 450, "c_128_255_combined", c_128_255_combined, c_128_255_combined_bench, "{return test(\"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}"},
	{1, 451, "c_allprintable_width", c_allprintable_width, c_allprintable_width_bench, "{return test(\"%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\",' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}"},
	{1, 452, "c_1_31_width", c_1_31_width, c_1_31_width_bench, "{return test(\"%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}"},
	{1, 453, "c_128_255_width", c_128_255_width, c_128_255_width_bench, "{return test(\"%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}"},
	{1, 454, "c_allprintable_width_lj", c_allprintable_width_lj, c_allprintable_width_lj_bench, "{return test(\"%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c\",' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}"},
	{1, 455, "c_1_31_width_lj", c_1_31_width_lj, c_1_31_width_lj_bench, "{return test(\"%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}"},
	{1, 456, "c_128_255_width_lj", c_128_255_width_lj, c_128_255_width_lj_bench, "{return test(\"%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}"},
	{1, 457, "c_nullterm_basic", c_nullterm_basic, c_nullterm_basic_bench, "{return test(\"%c\", '\0');}"},
	{1, 458, "c_nullterm_5w", c_nullterm_5w, c_nullterm_5w_bench, "{return test(\"%5c\", '\0');}"},
	{1, 459, "c_nullterm_5wlj", c_nullterm_5wlj, c_nullterm_5wlj_bench, "{return test(\"%-5c\", '\0');}"},
	{1, 460, "mix_successive_0", mix_successive_0, mix_successive_0_bench, "{return ( test(\"%c\", mx_c) + test(\"%u\", mx_u));}"},
	{1, 461, "mix_successive_4", mix_successive_4, mix_successive_4_bench, "{return ( test(\"%x\", mx_u) + test(\"%i\", mx_i));}"},
	{1, 462, "mix_successive_6", mix_successive_6, mix_successive_6_bench, "{return ( test(\"%s\", mx_s) + test(\"%c\", mx_c));}"},
	{1, 463, "mix_successive_10", mix_successive_10, mix_successive_10_bench, "{return ( test(\"%u\", mx_u) + test(\"%s\", mx_s));}"},
	{1, 464, "mix_successive_16", mix_successive_16, mix_successive_16_bench, "{return ( test(\"%s\", mx_s) + test(\"%x\", mx_u));}"},
	{1, 465, "mix_successive_20", mix_successive_20, mix_successive_20_bench, "{return ( test(\"%p\", &mx_i) + test(\"%s\", mx_s));}"},
	{1, 466, "mix_successive_21", mix_successive_21, mix_successive_21_bench, "{return ( test(\"%X\", mx_u) + test(\"%x\", mx_u));}"},
	{1, 467, "mix_successive_28", mix_successive_28, mix_successive_28_bench, "{return ( test(\"%i\", mx_i) + test(\"%u\", mx_u));}"},
	{1, 468, "mix_successive_30", mix_successive_30, mix_successive_30_bench, "{return ( test(\"%s\", mx_s) + test(\"%u\", mx_u));}"},
	{1, 469, "mix_successive_31", mix_successive_31, mix_successive_31_bench, "{return ( test(\"%X\", mx_u) + test(\"%c\", mx_c));}"},
	{1, 470, "mix_successive_32", mix_successive_32, mix_successive_32_bench, "{return ( test(\"%x\", mx_u) + test(\"%u\", mx_u));}"},
	{1, 471, "mix_successive_39", mix_successive_39, mix_successive_39_bench, "{return ( test(\"%i\", mx_i) + test(\"%c\", mx_c));}"},
	{1, 472, "mix_successive_40", mix_successive_40, mix_successive_40_bench, "{return ( test(\"%c\", mx_c) + test(\"%x\", mx_u));}"},
	{1, 473, "mix_successive_42", mix_successive_42, mix_successive_42_bench, "{return ( test(\"%x\", mx_u) + test(\"%s\", mx_s));}"},
	{1, 474, "mix_successive_43", mix_successive_43, mix_successive_43_bench, "{return ( test(\"%u\", mx_u) + test(\"%x\", mx_u));}"},
	{1, 475, "mix_successive_45", mix_successive_45, mix_successive_45_bench, "{return ( test(\"%s\", mx_s) + test(\"%c\", mx_c));}"},
	{1, 476, "mix_successive_46", mix_successive_46, mix_successive_46_bench, "{return ( test(\"%i\", mx_i) + test(\"%s\", mx_s));}"},
	{1, 477, "mix_successive_61", mix_successive_61, mix_successive_61_bench, "{return ( test(\"%p\", &mx_i) + test(\"%c\", mx_c));}"},
	{1, 478, "mix_successive_64", mix_successive_64, mix_successive_64_bench, "{return ( test(\"%s\", mx_s) + test(\"%c\", mx_c));}"},
	{1, 479, "nocrash_noarg_1_notmandatory", nocrash_noarg_1_notmandatory, nocrash_noarg_1_notmandatory_bench, "{return test(\"%1$\"); }"},
	{1, 480, "nocrash_noarg_2_notmandatory", nocrash_noarg_2_notmandatory, nocrash_noarg_2_notmandatory_bench, "{return test(\"%0\"); }"},
	{1, 481, "nocrash_noarg_3_notmandatory", nocrash_noarg_3_notmandatory, nocrash_noarg_3_notmandatory_bench, "{return test(\"% \"); }"},
	{1, 482, "nocrash_noarg_4_notmandatory", nocrash_noarg_4_notmandatory, nocrash_noarg_4_notmandatory_bench, "{return test(\"%#\"); }"},
	{1, 483, "nocrash_noarg_5_notmandatory", nocrash_noarg_5_notmandatory, nocrash_noarg_5_notmandatory_bench, "{return test(\"%-\"); }"},
	{1, 484, "nocrash_noarg_6_notmandatory", nocrash_noarg_6_notmandatory, nocrash_noarg_6_notmandatory_bench, "{return test(\"%+\"); }"},
	{1, 485, "nocrash_noarg_9_notmandatory", nocrash_noarg_9_notmandatory, nocrash_noarg_9_notmandatory_bench, "{return test(\"%23\"); }"},
	{1, 486, "nocrash_noarg_10_notmandatory", nocrash_noarg_10_notmandatory, nocrash_noarg_10_notmandatory_bench, "{return test(\"%.\"); }"},
	{1, 487, "nocrash_noarg_11_notmandatory", nocrash_noarg_11_notmandatory, nocrash_noarg_11_notmandatory_bench, "{return test(\"%hh\"); }"},
	{1, 488, "nocrash_noarg_12_notmandatory", nocrash_noarg_12_notmandatory, nocrash_noarg_12_notmandatory_bench, "{return test(\"%h\"); }"},
	{1, 489, "nocrash_noarg_13_notmandatory", nocrash_noarg_13_notmandatory, nocrash_noarg_13_notmandatory_bench, "{return test(\"%ll\"); }"},
	{1, 490, "nocrash_noarg_14_notmandatory", nocrash_noarg_14_notmandatory, nocrash_noarg_14_notmandatory_bench, "{return test(\"%l\"); }"},
	{1, 491, "nocrash_noarg_15_notmandatory", nocrash_noarg_15_notmandatory, nocrash_noarg_15_notmandatory_bench, "{return test(\"%L\"); }"},
	{1, 492, "nocrash_noarg_16_notmandatory", nocrash_noarg_16_notmandatory, nocrash_noarg_16_notmandatory_bench, "{return test(\"%p\"); }"},
	{1, 493, "nocrash_noarg_17_notmandatory", nocrash_noarg_17_notmandatory, nocrash_noarg_17_notmandatory_bench, "{return test(\"%d\"); }"},
	{1, 494, "nocrash_noarg_19_notmandatory", nocrash_noarg_19_notmandatory, nocrash_noarg_19_notmandatory_bench, "{return test(\"%u\"); }"},
	{1, 495, "nocrash_noarg_20_notmandatory", nocrash_noarg_20_notmandatory, nocrash_noarg_20_notmandatory_bench, "{return test(\"%x\"); }"},
	{1, 496, "nocrash_noarg_21_notmandatory", nocrash_noarg_21_notmandatory, nocrash_noarg_21_notmandatory_bench, "{return test(\"%X\"); }"},
	{1, 497, "nocrash_noarg_22_notmandatory", nocrash_noarg_22_notmandatory, nocrash_noarg_22_notmandatory_bench, "{return test(\"%f\"); }"},
	{1, 498, "nocrash_noarg_24_notmandatory", nocrash_noarg_24_notmandatory, nocrash_noarg_24_notmandatory_bench, "{return test(\"%c\"); }"},
	{1, 499, "nocrash_noarg_25_notmandatory", nocrash_noarg_25_notmandatory, nocrash_noarg_25_notmandatory_bench, "{return test(\"%o\"); }"},
	{1, 500, "nocrash_nullarg_1", nocrash_nullarg_1, nocrash_nullarg_1_bench, "{return test(\"%1$s\", NULL); }"},
	{1, 501, "nocrash_nullarg_2", nocrash_nullarg_2, nocrash_nullarg_2_bench, "{return test(\"%0s\", NULL); }"},
	{1, 502, "nocrash_nullarg_3", nocrash_nullarg_3, nocrash_nullarg_3_bench, "{return test(\"% s\", NULL); }"},
	{1, 503, "nocrash_nullarg_4", nocrash_nullarg_4, nocrash_nullarg_4_bench, "{return test(\"%#s\", NULL); }"},
	{1, 504, "nocrash_nullarg_5", nocrash_nullarg_5, nocrash_nullarg_5_bench, "{return test(\"%-s\", NULL); }"},
	{1, 505, "nocrash_nullarg_6", nocrash_nullarg_6, nocrash_nullarg_6_bench, "{return test(\"%+s\", NULL); }"},
	{1, 506, "nocrash_nullarg_9", nocrash_nullarg_9, nocrash_nullarg_9_bench, "{return test(\"%23s\", NULL); }"},
	{1, 507, "nocrash_nullarg_10", nocrash_nullarg_10, nocrash_nullarg_10_bench, "{return test(\"%.s\", NULL); }"},
	{1, 508, "nocrash_nullarg_11", nocrash_nullarg_11, nocrash_nullarg_11_bench, "{return test(\"%hhs\", NULL); }"},
	{1, 509, "nocrash_nullarg_12", nocrash_nullarg_12, nocrash_nullarg_12_bench, "{return test(\"%hs\", NULL); }"},
	{1, 510, "nocrash_nullarg_13", nocrash_nullarg_13, nocrash_nullarg_13_bench, "{return test(\"%lls\", NULL); }"},
	{1, 511, "nocrash_nullarg_14", nocrash_nullarg_14, nocrash_nullarg_14_bench, "{return test(\"%ls\", NULL); }"},
	{1, 512, "nocrash_nullarg_15", nocrash_nullarg_15, nocrash_nullarg_15_bench, "{return test(\"%Ls\", NULL); }"},
	{1, 513, "nocrash_nullarg_16", nocrash_nullarg_16, nocrash_nullarg_16_bench, "{return test(\"%p\", NULL); }"},
	{1, 514, "nocrash_nullarg_17", nocrash_nullarg_17, nocrash_nullarg_17_bench, "{return test(\"%d\", NULL); }"},
	{1, 515, "nocrash_nullarg_18", nocrash_nullarg_18, nocrash_nullarg_18_bench, "{return test(\"%b\", NULL); }"},
	{1, 516, "nocrash_nullarg_19", nocrash_nullarg_19, nocrash_nullarg_19_bench, "{return test(\"%u\", NULL); }"},
	{1, 517, "nocrash_nullarg_20", nocrash_nullarg_20, nocrash_nullarg_20_bench, "{return test(\"%x\", NULL); }"},
	{1, 518, "nocrash_nullarg_21", nocrash_nullarg_21, nocrash_nullarg_21_bench, "{return test(\"%X\", NULL); }"},
	{1, 519, "nocrash_nullarg_22", nocrash_nullarg_22, nocrash_nullarg_22_bench, "{return test(\"%f\", NULL); }"},
	{1, 520, "nocrash_nullarg_23", nocrash_nullarg_23, nocrash_nullarg_23_bench, "{return test(\"%s\", NULL); }"},
	{1, 521, "nocrash_nullarg_24", nocrash_nullarg_24, nocrash_nullarg_24_bench, "{return test(\"%c\", NULL); }"},
	{1, 522, "nocrash_nullarg_25", nocrash_nullarg_25, nocrash_nullarg_25_bench, "{return test(\"%o\", NULL); }"},
	{1, 523, "nocrash_mandatory_wformat_undefbehav_01", nocrash_mandatory_wformat_undefbehav_01, nocrash_mandatory_wformat_undefbehav_01_bench, "{return test(\"%-021s\", \"abc\");}"},
	{1, 524, "nocrash_mandatory_wformat_undefbehav_02", nocrash_mandatory_wformat_undefbehav_02, nocrash_mandatory_wformat_undefbehav_02_bench, "{return test(\"%-05s\", \"goes over\");}"},
	{1, 525, "nocrash_mandatory_wformat_undefbehav_03", nocrash_mandatory_wformat_undefbehav_03, nocrash_mandatory_wformat_undefbehav_03_bench, "{return test(\"%04.3s%-7.4s\", \"hello\", \"world\");}"},
	{1, 526, "nocrash_mandatory_wformat_undefbehav_04", nocrash_mandatory_wformat_undefbehav_04, nocrash_mandatory_wformat_undefbehav_04_bench, "{return test(\"%021s\", NULL);}"},
	{1, 527, "nocrash_mandatory_wformat_undefbehav_05", nocrash_mandatory_wformat_undefbehav_05, nocrash_mandatory_wformat_undefbehav_05_bench, "{return test(\"%02s\", NULL);}"},
	{1, 528, "nocrash_mandatory_wformat_undefbehav_06", nocrash_mandatory_wformat_undefbehav_06, nocrash_mandatory_wformat_undefbehav_06_bench, "{return test(\"%-021s\", NULL);}"},
	{1, 529, "nocrash_mandatory_wformat_undefbehav_07", nocrash_mandatory_wformat_undefbehav_07, nocrash_mandatory_wformat_undefbehav_07_bench, "{return test(\"%-03s\", NULL);}"},
	{1, 530, "nocrash_mandatory_wformat_undefbehav_38", nocrash_mandatory_wformat_undefbehav_38, nocrash_mandatory_wformat_undefbehav_38_bench, "{return test(\"%05c\", '\0');}"},
	{1, 531, "nocrash_mandatory_wformat_undefbehav_39", nocrash_mandatory_wformat_undefbehav_39, nocrash_mandatory_wformat_undefbehav_39_bench, "{return test(\"%-05c\", '\0');}"},
	{1, 532, "nocrash_mandatory_dupflag_d_spsp", nocrash_mandatory_dupflag_d_spsp, nocrash_mandatory_dupflag_d_spsp_bench, "{return test(\"%  d\", 42);}"},
	{1, 533, "nocrash_mandatory_dupflag_d_ljljw", nocrash_mandatory_dupflag_d_ljljw, nocrash_mandatory_dupflag_d_ljljw_bench, "{return test(\"%--5d\", 42);}"},
	{1, 534, "nocrash_mandatory_dupflag_x_afaf", nocrash_mandatory_dupflag_x_afaf, nocrash_mandatory_dupflag_x_afaf_bench, "{return test(\"%##x\", 42);}"},
	{1, 535, "nocrash_mandatory_c_prec_1", nocrash_mandatory_c_prec_1, nocrash_mandatory_c_prec_1_bench, "{return test(\"%.4c\", 'a');}"},
	{1, 536, "nocrash_mandatory_c_prec_2", nocrash_mandatory_c_prec_2, nocrash_mandatory_c_prec_2_bench, "{return test(\"%.c\", 'a');}"},
	{1, 537, "nocrash_mandatory_c_af", nocrash_mandatory_c_af, nocrash_mandatory_c_af_bench, "{return test(\"%#c\", 'a');}"},
	{1, 538, "nocrash_mandatory_c_zp_1", nocrash_mandatory_c_zp_1, nocrash_mandatory_c_zp_1_bench, "{return test(\"%05c\", 'a');}"},
	{1, 539, "nocrash_mandatory_c_zp_2", nocrash_mandatory_c_zp_2, nocrash_mandatory_c_zp_2_bench, "{return test(\"%0c\", 'a');}"},
	{1, 540, "nocrash_mandatory_c_sp_1", nocrash_mandatory_c_sp_1, nocrash_mandatory_c_sp_1_bench, "{return test(\"% c\", 'a');}"},
	{1, 541, "nocrash_mandatory_c_sp_2", nocrash_mandatory_c_sp_2, nocrash_mandatory_c_sp_2_bench, "{return test(\"% c\", -42);}"},
	{1, 542, "nocrash_mandatory_c_size_hh", nocrash_mandatory_c_size_hh, nocrash_mandatory_c_size_hh_bench, "{return test(\"%hhc\", 'a');}"},
	{1, 543, "nocrash_mandatory_c_size_h", nocrash_mandatory_c_size_h, nocrash_mandatory_c_size_h_bench, "{return test(\"%hc\", 'a');}"},
	{1, 544, "nocrash_mandatory_c_size_l", nocrash_mandatory_c_size_l, nocrash_mandatory_c_size_l_bench, "{return test(\"%lc\", L'a');}"},
	{1, 545, "nocrash_mandatory_c_size_ll", nocrash_mandatory_c_size_ll, nocrash_mandatory_c_size_ll_bench, "{return test(\"%llc\", L'a');}"},
	{1, 546, "nocrash_mandatory_c_size_L", nocrash_mandatory_c_size_L, nocrash_mandatory_c_size_L_bench, "{return test(\"%Lc\", L'a');}"},
	{1, 547, "nocrash_mandatory_c_lj_nowidth", nocrash_mandatory_c_lj_nowidth, nocrash_mandatory_c_lj_nowidth_bench, "{return test(\"%-c\", 'a');}"},
	{1, 548, "nocrash_mandatory_s_af", nocrash_mandatory_s_af, nocrash_mandatory_s_af_bench, "{return test(\"%#s\", \"hello\");}"},
	{1, 549, "nocrash_mandatory_s_zp_1", nocrash_mandatory_s_zp_1, nocrash_mandatory_s_zp_1_bench, "{return test(\"%05s\", \"hello\");}"},
	{1, 550, "nocrash_mandatory_s_zp_2", nocrash_mandatory_s_zp_2, nocrash_mandatory_s_zp_2_bench, "{return test(\"%0s\", \"hello\");}"},
	{1, 551, "nocrash_mandatory_s_sp_1", nocrash_mandatory_s_sp_1, nocrash_mandatory_s_sp_1_bench, "{return test(\"% s\", \"hello\");}"},
	{1, 552, "nocrash_mandatory_s_size_hh", nocrash_mandatory_s_size_hh, nocrash_mandatory_s_size_hh_bench, "{return test(\"%hhs\", \"hello\");}"},
	{1, 553, "nocrash_mandatory_s_size_h", nocrash_mandatory_s_size_h, nocrash_mandatory_s_size_h_bench, "{return test(\"%hs\", \"hello\");}"},
	{1, 554, "nocrash_mandatory_s_size_l", nocrash_mandatory_s_size_l, nocrash_mandatory_s_size_l_bench, "{return test(\"%ls\", L\"hello\");}"},
	{1, 555, "nocrash_mandatory_s_size_ll", nocrash_mandatory_s_size_ll, nocrash_mandatory_s_size_ll_bench, "{return test(\"%lls\", L\"hello\");}"},
	{1, 556, "nocrash_mandatory_s_size_L", nocrash_mandatory_s_size_L, nocrash_mandatory_s_size_L_bench, "{return test(\"%Ls\", L\"hello\");}"},
	{1, 557, "nocrash_mandatory_s_lj_nowidth", nocrash_mandatory_s_lj_nowidth, nocrash_mandatory_s_lj_nowidth_bench, "{return test(\"%-s\", \"hello\");}"},
	{1, 558, "nocrash_mandatory_p_prec_1", nocrash_mandatory_p_prec_1, nocrash_mandatory_p_prec_1_bench, "{return test(\"%.4p\", &ncm_p);}"},
	{1, 559, "nocrash_mandatory_p_prec_2", nocrash_mandatory_p_prec_2, nocrash_mandatory_p_prec_2_bench, "{return test(\"%.p\", &ncm_p);}"},
	{1, 560, "nocrash_mandatory_p_af", nocrash_mandatory_p_af, nocrash_mandatory_p_af_bench, "{return test(\"%#p\", &ncm_p);}"},
	{1, 561, "nocrash_mandatory_p_zp_1", nocrash_mandatory_p_zp_1, nocrash_mandatory_p_zp_1_bench, "{return test(\"%05p\", &ncm_p);}"},
	{1, 562, "nocrash_mandatory_p_zp_2", nocrash_mandatory_p_zp_2, nocrash_mandatory_p_zp_2_bench, "{return test(\"%0p\", &ncm_p);}"},
	{1, 563, "nocrash_mandatory_p_sp_1", nocrash_mandatory_p_sp_1, nocrash_mandatory_p_sp_1_bench, "{return test(\"% p\", &ncm_p);}"},
	{1, 564, "nocrash_mandatory_p_sp_2", nocrash_mandatory_p_sp_2, nocrash_mandatory_p_sp_2_bench, "{return test(\"% p\", &ncm_p);}"},
	{1, 565, "nocrash_mandatory_p_size_hh", nocrash_mandatory_p_size_hh, nocrash_mandatory_p_size_hh_bench, "{return test(\"%hhp\", &ncm_p);}"},
	{1, 566, "nocrash_mandatory_p_size_h", nocrash_mandatory_p_size_h, nocrash_mandatory_p_size_h_bench, "{return test(\"%hp\", &ncm_p);}"},
	{1, 567, "nocrash_mandatory_p_size_l", nocrash_mandatory_p_size_l, nocrash_mandatory_p_size_l_bench, "{return test(\"%lp\", &ncm_p);}"},
	{1, 568, "nocrash_mandatory_p_size_ll", nocrash_mandatory_p_size_ll, nocrash_mandatory_p_size_ll_bench, "{return test(\"%llp\", &ncm_p);}"},
	{1, 569, "nocrash_mandatory_p_size_L", nocrash_mandatory_p_size_L, nocrash_mandatory_p_size_L_bench, "{return test(\"%Lp\", &ncm_p);}"},
	{1, 570, "nocrash_mandatory_p_lj_nowidth", nocrash_mandatory_p_lj_nowidth, nocrash_mandatory_p_lj_nowidth_bench, "{return test(\"%-p\", &ncm_p);}"},
	{1, 571, "nocrash_mandatory_d_size_L", nocrash_mandatory_d_size_L, nocrash_mandatory_d_size_L_bench, "{return test(\"%Ld\", 42);}"},
	{1, 572, "nocrash_mandatory_d_af", nocrash_mandatory_d_af, nocrash_mandatory_d_af_bench, "{return test(\"%#d\", 42);}"},
	{1, 573, "nocrash_mandatory_d_size_hhh", nocrash_mandatory_d_size_hhh, nocrash_mandatory_d_size_hhh_bench, "{return test(\"%hhhd\", 42);}"},
	{1, 574, "nocrash_mandatory_d_size_hhhh", nocrash_mandatory_d_size_hhhh, nocrash_mandatory_d_size_hhhh_bench, "{return test(\"%hhhhd\", 42);}"},
	{1, 575, "nocrash_mandatory_d_size_hhl", nocrash_mandatory_d_size_hhl, nocrash_mandatory_d_size_hhl_bench, "{return test(\"%hhld\", 42);}"},
	{1, 576, "nocrash_mandatory_d_size_hhll", nocrash_mandatory_d_size_hhll, nocrash_mandatory_d_size_hhll_bench, "{return test(\"%hhlld\", 42);}"},
	{1, 577, "nocrash_mandatory_d_size_llh", nocrash_mandatory_d_size_llh, nocrash_mandatory_d_size_llh_bench, "{return test(\"%llhd\", 42);}"},
	{1, 578, "nocrash_mandatory_d_size_lll", nocrash_mandatory_d_size_lll, nocrash_mandatory_d_size_lll_bench, "{return test(\"%llld\", 42);}"},
	{1, 579, "nocrash_mandatory_i_size_L", nocrash_mandatory_i_size_L, nocrash_mandatory_i_size_L_bench, "{return test(\"%Li\", 42);}"},
	{1, 580, "nocrash_mandatory_i_af", nocrash_mandatory_i_af, nocrash_mandatory_i_af_bench, "{return test(\"%#i\", 42);}"},
	{1, 581, "nocrash_mandatory_i_size_hhh", nocrash_mandatory_i_size_hhh, nocrash_mandatory_i_size_hhh_bench, "{return test(\"%hhhi\", 42);}"},
	{1, 582, "nocrash_mandatory_i_lj_nowidth", nocrash_mandatory_i_lj_nowidth, nocrash_mandatory_i_lj_nowidth_bench, "{return test(\"%-i\", 42);}"},
	{1, 583, "nocrash_mandatory_o_sp", nocrash_mandatory_o_sp, nocrash_mandatory_o_sp_bench, "{return test(\"% o\", 42);}"},
	{1, 584, "nocrash_mandatory_o_size_L", nocrash_mandatory_o_size_L, nocrash_mandatory_o_size_L_bench, "{return test(\"%Lo\", 42);}"},
	{1, 585, "nocrash_mandatory_o_size_hhh", nocrash_mandatory_o_size_hhh, nocrash_mandatory_o_size_hhh_bench, "{return test(\"%hhho\", 42);}"},
	{1, 586, "nocrash_mandatory_o_size_hhhh", nocrash_mandatory_o_size_hhhh, nocrash_mandatory_o_size_hhhh_bench, "{return test(\"%hhhho\", 42);}"},
	{1, 587, "nocrash_mandatory_o_size_hhl", nocrash_mandatory_o_size_hhl, nocrash_mandatory_o_size_hhl_bench, "{return test(\"%hhlo\", 42);}"},
	{1, 588, "nocrash_mandatory_o_size_hhll", nocrash_mandatory_o_size_hhll, nocrash_mandatory_o_size_hhll_bench, "{return test(\"%hhllo\", 42);}"},
	{1, 589, "nocrash_mandatory_o_size_llh", nocrash_mandatory_o_size_llh, nocrash_mandatory_o_size_llh_bench, "{return test(\"%llho\", 42);}"},
	{1, 590, "nocrash_mandatory_o_size_lll", nocrash_mandatory_o_size_lll, nocrash_mandatory_o_size_lll_bench, "{return test(\"%lllo\", 42);}"},
	{1, 591, "nocrash_mandatory_o_lj_nowidth", nocrash_mandatory_o_lj_nowidth, nocrash_mandatory_o_lj_nowidth_bench, "{return test(\"%-o\", 42);}"},
	{1, 592, "nocrash_mandatory_u_size_L", nocrash_mandatory_u_size_L, nocrash_mandatory_u_size_L_bench, "{return test(\"%Lu\", 42);}"},
	{1, 593, "nocrash_mandatory_u_af", nocrash_mandatory_u_af, nocrash_mandatory_u_af_bench, "{return test(\"%#u\", 42);}"},
	{1, 594, "nocrash_mandatory_u_sp", nocrash_mandatory_u_sp, nocrash_mandatory_u_sp_bench, "{return test(\"% u\", 42);}"},
	{1, 595, "nocrash_mandatory_u_size_hhh", nocrash_mandatory_u_size_hhh, nocrash_mandatory_u_size_hhh_bench, "{return test(\"%hhhu\", 42);}"},
	{1, 596, "nocrash_mandatory_u_size_hhhh", nocrash_mandatory_u_size_hhhh, nocrash_mandatory_u_size_hhhh_bench, "{return test(\"%hhhhu\", 42);}"},
	{1, 597, "nocrash_mandatory_u_size_hhl", nocrash_mandatory_u_size_hhl, nocrash_mandatory_u_size_hhl_bench, "{return test(\"%hhlu\", 42);}"},
	{1, 598, "nocrash_mandatory_u_size_hhll", nocrash_mandatory_u_size_hhll, nocrash_mandatory_u_size_hhll_bench, "{return test(\"%hhllu\", 42);}"},
	{1, 599, "nocrash_mandatory_u_size_llh", nocrash_mandatory_u_size_llh, nocrash_mandatory_u_size_llh_bench, "{return test(\"%llhu\", 42);}"},
	{1, 600, "nocrash_mandatory_u_size_lll", nocrash_mandatory_u_size_lll, nocrash_mandatory_u_size_lll_bench, "{return test(\"%lllu\", 42);}"},
	{1, 601, "nocrash_mandatory_u_lj_nowidth", nocrash_mandatory_u_lj_nowidth, nocrash_mandatory_u_lj_nowidth_bench, "{return test(\"%-u\", 42);}"},
	{1, 602, "nocrash_mandatory_x_size_L", nocrash_mandatory_x_size_L, nocrash_mandatory_x_size_L_bench, "{return test(\"%Lx\", 42);}"},
	{1, 603, "nocrash_mandatory_x_sp", nocrash_mandatory_x_sp, nocrash_mandatory_x_sp_bench, "{return test(\"% x\", 42);}"},
	{1, 604, "nocrash_mandatory_x_size_hhh", nocrash_mandatory_x_size_hhh, nocrash_mandatory_x_size_hhh_bench, "{return test(\"%hhhx\", 42);}"},
	{1, 605, "nocrash_mandatory_x_size_hhhh", nocrash_mandatory_x_size_hhhh, nocrash_mandatory_x_size_hhhh_bench, "{return test(\"%hhhhx\", 42);}"},
	{1, 606, "nocrash_mandatory_x_size_hhl", nocrash_mandatory_x_size_hhl, nocrash_mandatory_x_size_hhl_bench, "{return test(\"%hhlx\", 42);}"},
	{1, 607, "nocrash_mandatory_x_size_hhll", nocrash_mandatory_x_size_hhll, nocrash_mandatory_x_size_hhll_bench, "{return test(\"%hhllx\", 42);}"},
	{1, 608, "nocrash_mandatory_x_size_llh", nocrash_mandatory_x_size_llh, nocrash_mandatory_x_size_llh_bench, "{return test(\"%llhx\", 42);}"},
	{1, 609, "nocrash_mandatory_x_size_lll", nocrash_mandatory_x_size_lll, nocrash_mandatory_x_size_lll_bench, "{return test(\"%lllx\", 42);}"},
	{1, 610, "nocrash_mandatory_X_size_L", nocrash_mandatory_X_size_L, nocrash_mandatory_X_size_L_bench, "{return test(\"%LX\", 42);}"},
	{1, 611, "nocrash_mandatory_X_sp", nocrash_mandatory_X_sp, nocrash_mandatory_X_sp_bench, "{return test(\"% X\", 42);}"},
	{1, 612, "nocrash_mandatory_X_size_hhh", nocrash_mandatory_X_size_hhh, nocrash_mandatory_X_size_hhh_bench, "{return test(\"%hhhX\", 42);}"},
	{1, 613, "nocrash_mandatory_X_size_llh", nocrash_mandatory_X_size_llh, nocrash_mandatory_X_size_llh_bench, "{return test(\"%llhX\", 42);}"},
	{1, 614, "nocrash_mandatory_x_lj_nowidth", nocrash_mandatory_x_lj_nowidth, nocrash_mandatory_x_lj_nowidth_bench, "{return test(\"%-x\", 42);}"},
	{1, 615, "nocrash_mandatory_f_size_hh", nocrash_mandatory_f_size_hh, nocrash_mandatory_f_size_hh_bench, "{return test(\"%hhf\", 42.5);}"},
	{1, 616, "nocrash_mandatory_f_size_h", nocrash_mandatory_f_size_h, nocrash_mandatory_f_size_h_bench, "{return test(\"%hf\", 42.5);}"},
	{1, 617, "nocrash_mandatory_f_size_ll", nocrash_mandatory_f_size_ll, nocrash_mandatory_f_size_ll_bench, "{return test(\"%llf\", 42.5);}"},
	{1, 618, "nocrash_mandatory_f_size_lll", nocrash_mandatory_f_size_lll, nocrash_mandatory_f_size_lll_bench, "{return test(\"%lllf\", 42.5);}"},
	{1, 619, "nocrash_mandatory_f_size_llll", nocrash_mandatory_f_size_llll, nocrash_mandatory_f_size_llll_bench, "{return test(\"%llllf\", 42.5);}"},
	{1, 620, "nocrash_mandatory_f_size_LL", nocrash_mandatory_f_size_LL, nocrash_mandatory_f_size_LL_bench, "{return test(\"%LLf\", 42.5);}"},
	{1, 621, "nocrash_mandatory_f_size_Ll", nocrash_mandatory_f_size_Ll, nocrash_mandatory_f_size_Ll_bench, "{return test(\"%Llf\", 42.5);}"},
	{1, 622, "nocrash_mandatory_f_size_lL", nocrash_mandatory_f_size_lL, nocrash_mandatory_f_size_lL_bench, "{return test(\"%lLf\", 42.5);}"},
	{1, 623, "nocrash_mandatory_f_lj_nowidth", nocrash_mandatory_f_lj_nowidth, nocrash_mandatory_f_lj_nowidth_bench, "{return test(\"%-f\", 42.5);}"},
	{1, 624, "moul_s_1", moul_s_1, moul_s_1_bench, "{return test(\" pouet %s !!\", \"camembert\");}"},
	{1, 625, "moul_s_2", moul_s_2, moul_s_2_bench, "{return test(\"%s !\", \"Ceci n'est pas un \0 exercice !\");}"},
	{1, 626, "moul_s_3", moul_s_3, moul_s_3_bench, "{return test(\"%s!\", \"Ceci n'est toujours pas un exercice !\");}"},
	{1, 627, "moul_s_4", moul_s_4, moul_s_4_bench, "{char *str = NULL; return test(\"%s!\", str);}"},
	{1, 628, "moul_s_5_this_ones_a_doozy", moul_s_5_this_ones_a_doozy, moul_s_5_this_ones_a_doozy_bench, "{return test(\"%s\","},
	{1, 629, "moul_d_1", moul_d_1, moul_d_1_bench, "{return test(\"%d\", 42);}"},
	{1, 630, "moul_d_2", moul_d_2, moul_d_2_bench, "{return test(\"Kashim a %d histoires à raconter\", 1001);}"},
	{1, 631, "moul_d_3", moul_d_3, moul_d_3_bench, "{return test(\"Il fait au moins %d\n\", -8000);}"},
	{1, 632, "moul_d_4", moul_d_4, moul_d_4_bench, "{return test(\"%d\", -0);}"},
	{1, 633, "moul_d_5", moul_d_5, moul_d_5_bench, "{return test(\"%d\", 0);}"},
	{1, 634, "moul_d_6", moul_d_6, moul_d_6_bench, "{return test(\"%d\", INT_MAX);}"},
	{1, 635, "moul_d_7", moul_d_7, moul_d_7_bench, "{return test(\"%d\", INT_MIN);}"},
	{1, 636, "moul_d_8", moul_d_8, moul_d_8_bench, "{return test(\"%d\", INT_MIN - 1);}"},
	{1, 637, "moul_d_9", moul_d_9, moul_d_9_bench, "{return test(\"%d\", INT_MAX + 1);}"},
	{1, 638, "moul_d_10", moul_d_10, moul_d_10_bench, "{return test(\"%%d 0000042 == |%d|\n\", 0000042);}"},
	{1, 639, "moul_d_11", moul_d_11, moul_d_11_bench, "{return test(\"%%d \t == |%d|\n\", '\t');}"},
	{1, 640, "moul_d_12", moul_d_12, moul_d_12_bench, "{return test(\"%%d Lydie == |%d|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 641, "moul_mix_1", moul_mix_1, moul_mix_1_bench, "{int r00 = 0; return test(\"Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p\", 100, \"Ly\", &r00);}"},
	{1, 642, "moul_c_1", moul_c_1, moul_c_1_bench, "{return test(\"%c\", 42);}"},
	{1, 643, "moul_c_2", moul_c_2, moul_c_2_bench, "{return test(\"Kashim a %c histoires à raconter\", 1001);}"},
	{1, 644, "moul_c_3", moul_c_3, moul_c_3_bench, "{return test(\"Il fait au moins %c\n\", -8000);}"},
	{1, 645, "moul_c_4", moul_c_4, moul_c_4_bench, "{return test(\"%c\", -0);}"},
	{1, 646, "moul_c_5", moul_c_5, moul_c_5_bench, "{return test(\"%c\", 0);}"},
	{1, 647, "moul_c_5b", moul_c_5b, moul_c_5b_bench, "{return test(\"%c\n\", INT_MAX);}"},
	{1, 648, "moul_c_6", moul_c_6, moul_c_6_bench, "{return test(\"%c\n\", 'c');}"},
	{1, 649, "moul_c_7", moul_c_7, moul_c_7_bench, "{return test(\"%c\n\", '\n');}"},
	{1, 650, "moul_c_8", moul_c_8, moul_c_8_bench, "{return test(\"%c\", 'l');}"},
	{1, 651, "moul_c_9", moul_c_9, moul_c_9_bench, "{return test(\"%c\", 'y');}"},
	{1, 652, "moul_c_10", moul_c_10, moul_c_10_bench, "{return test(\"%c\", ' ');}"},
	{1, 653, "moul_c_11", moul_c_11, moul_c_11_bench, "{return test(\"%c\", 'e');}"},
	{1, 654, "moul_c_12", moul_c_12, moul_c_12_bench, "{return test(\"%c\", 's');}"},
	{1, 655, "moul_c_13", moul_c_13, moul_c_13_bench, "{return test(\"%c\", 't');}"},
	{1, 656, "moul_c_14", moul_c_14, moul_c_14_bench, "{return test(\"%c\", ' ');}"},
	{1, 657, "moul_c_15", moul_c_15, moul_c_15_bench, "{return test(\"%c\", 'f');}"},
	{1, 658, "moul_c_16", moul_c_16, moul_c_16_bench, "{return test(\"%c\", 'a');}"},
	{1, 659, "moul_c_17", moul_c_17, moul_c_17_bench, "{return test(\"%c\", 'n');}"},
	{1, 660, "moul_c_18", moul_c_18, moul_c_18_bench, "{return test(\"%c\", 't');}"},
	{1, 661, "moul_c_19", moul_c_19, moul_c_19_bench, "{return test(\"%c\", 'a');}"},
	{1, 662, "moul_c_20", moul_c_20, moul_c_20_bench, "{return test(\"%c\", 's');}"},
	{1, 663, "moul_c_21", moul_c_21, moul_c_21_bench, "{return test(\"%c\", 't');}"},
	{1, 664, "moul_c_22", moul_c_22, moul_c_22_bench, "{return test(\"%c\", 'i');}"},
	{1, 665, "moul_c_23", moul_c_23, moul_c_23_bench, "{return test(\"%c\", 'q');}"},
	{1, 666, "moul_c_24", moul_c_24, moul_c_24_bench, "{return test(\"%c\", 'u');}"},
	{1, 667, "moul_c_25", moul_c_25, moul_c_25_bench, "{return test(\"%c\", 'e');}"},
	{1, 668, "moul_c_26", moul_c_26, moul_c_26_bench, "{return test(\"%c\n\", '!');}"},
	{1, 669, "moul_c_27", moul_c_27, moul_c_27_bench, "{return test(\"%c\n\", '\r');}"},
	{1, 670, "moul_c_28", moul_c_28, moul_c_28_bench, "{return test(\"%c\n\", '\t');}"},
	{1, 671, "moul_i_1", moul_i_1, moul_i_1_bench, "{return test(\"%i\", 42);}"},
	{1, 672, "moul_i_2", moul_i_2, moul_i_2_bench, "{return test(\"Kashim a %i histoires à raconter\", 1001);}"},
	{1, 673, "moul_i_3", moul_i_3, moul_i_3_bench, "{return test(\"Il fait au moins %i\n\", -8000);}"},
	{1, 674, "moul_i_4", moul_i_4, moul_i_4_bench, "{return test(\"%i\", -0);}"},
	{1, 675, "moul_i_5", moul_i_5, moul_i_5_bench, "{return test(\"%i\", 0);}"},
	{1, 676, "moul_i_6", moul_i_6, moul_i_6_bench, "{return test(\"%i\", INT_MAX);}"},
	{1, 677, "moul_i_7", moul_i_7, moul_i_7_bench, "{return test(\"%i\", INT_MIN);}"},
	{1, 678, "moul_i_8", moul_i_8, moul_i_8_bench, "{return test(\"%i\", INT_MIN - 1);}"},
	{1, 679, "moul_i_9", moul_i_9, moul_i_9_bench, "{return test(\"%i\", INT_MAX + 1);}"},
	{1, 680, "moul_i_10", moul_i_10, moul_i_10_bench, "{return test(\"%%i 0000042 == |%i|\n\", 0000042);}"},
	{1, 681, "moul_i_11", moul_i_11, moul_i_11_bench, "{return test(\"%%i \t == |%i|\n\", '\t');}"},
	{1, 682, "moul_i_12", moul_i_12, moul_i_12_bench, "{return test(\"%%i Lydie == |%i|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 683, "moul_u_1", moul_u_1, moul_u_1_bench, "{return test(\"%u\", 42);}"},
	{1, 684, "moul_u_2", moul_u_2, moul_u_2_bench, "{return test(\"Kashim a %u histoires à raconter\", 1001);}"},
	{1, 685, "moul_u_3", moul_u_3, moul_u_3_bench, "{return test(\"Il fait au moins %u\n\", -8000);}"},
	{1, 686, "moul_u_4", moul_u_4, moul_u_4_bench, "{return test(\"%u\", -0);}"},
	{1, 687, "moul_u_5", moul_u_5, moul_u_5_bench, "{return test(\"%u\", 0);}"},
	{1, 688, "moul_u_6", moul_u_6, moul_u_6_bench, "{return test(\"%u\", INT_MAX);}"},
	{1, 689, "moul_u_7", moul_u_7, moul_u_7_bench, "{return test(\"%u\", INT_MIN);}"},
	{1, 690, "moul_u_8", moul_u_8, moul_u_8_bench, "{return test(\"%u\", INT_MIN - 1);}"},
	{1, 691, "moul_u_9", moul_u_9, moul_u_9_bench, "{return test(\"%u\", INT_MAX + 1);}"},
	{1, 692, "moul_u_10", moul_u_10, moul_u_10_bench, "{return test(\"%%u 0000042 == |%u|\n\", 0000042);}"},
	{1, 693, "moul_u_11", moul_u_11, moul_u_11_bench, "{return test(\"%%u \t == |%u|\n\", '\t');}"},
	{1, 694, "moul_u_12", moul_u_12, moul_u_12_bench, "{return test(\"%%u Lydie == |%u|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 695, "moul_x_1", moul_x_1, moul_x_1_bench, "{return test(\"%x\", 42);}"},
	{1, 696, "moul_x_2", moul_x_2, moul_x_2_bench, "{return test(\"Kashim a %x histoires à raconter\", 1001);}"},
	{1, 697, "moul_x_3", moul_x_3, moul_x_3_bench, "{return test(\"Il fait au moins %x\n\", -8000);}"},
	{1, 698, "moul_x_4", moul_x_4, moul_x_4_bench, "{return test(\"%x\", -0);}"},
	{1, 699, "moul_x_5", moul_x_5, moul_x_5_bench, "{return test(\"%x\", 0);}"},
	{1, 700, "moul_x_6", moul_x_6, moul_x_6_bench, "{return test(\"%x\", INT_MAX);}"},
	{1, 701, "moul_x_7", moul_x_7, moul_x_7_bench, "{return test(\"%x\", INT_MIN);}"},
	{1, 702, "moul_x_8", moul_x_8, moul_x_8_bench, "{return test(\"%x\", INT_MIN - 1);}"},
	{1, 703, "moul_x_9", moul_x_9, moul_x_9_bench, "{return test(\"%x\", INT_MAX + 1);}"},
	{1, 704, "moul_x_10", moul_x_10, moul_x_10_bench, "{return test(\"%%x 0000042 == |%x|\n\", 0000042);}"},
	{1, 705, "moul_x_11", moul_x_11, moul_x_11_bench, "{return test(\"%%x \t == |%x|\n\", '\t');}"},
	{1, 706, "moul_x_12", moul_x_12, moul_x_12_bench, "{return test(\"%%x Lydie == |%x|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 707, "moul_prec_1", moul_prec_1, moul_prec_1_bench, "{return test(\"%%-5.3s LYDI == |%-5.3s|\n\", \"LYDI\");}"},
	{1, 708, "moul_prec_3", moul_prec_3, moul_prec_3_bench, "{return test(\"%%04.5i 42 == |%04.5i|\n\", 42);}"},
	{1, 709, "moul_prec_4", moul_prec_4, moul_prec_4_bench, "{return test(\"%%04.3i 42 == |%04.3i|\n\", 42);}"},
	{1, 710, "moul_prec_5", moul_prec_5, moul_prec_5_bench, "{return test(\"%%04.2i 42 == |%04.2i|\n\", 42);}"},
	{1, 711, "moul_zeropad_1", moul_zeropad_1, moul_zeropad_1_bench, "{return test(\"%%04i 42 == |%04i|\n\", 42);}"},
	{1, 712, "moul_zeropad_2", moul_zeropad_2, moul_zeropad_2_bench, "{return test(\"%%05i 42 == |%05i|\n\", 42);}"},
	{1, 713, "moul_zeropad_3", moul_zeropad_3, moul_zeropad_3_bench, "{return test(\"%%0i 42 == |%0i|\n\", 42);}"},
	{1, 714, "moul_zeropad_4", moul_zeropad_4, moul_zeropad_4_bench, "{return test(\"%%0d 0000042 == |%0d|\n\", 0000042);}"},
	{1, 715, "moul_leftjusty_1", moul_leftjusty_1, moul_leftjusty_1_bench, "{return test(\"%%-i 42 == %-i\n\", 42);}"},
	{1, 716, "moul_leftjusty_2", moul_leftjusty_2, moul_leftjusty_2_bench, "{return test(\"%%-d 42 == %-d\n\", INT_MIN);}"},
	{1, 717, "moul_leftjusty_3", moul_leftjusty_3, moul_leftjusty_3_bench, "{return test(\"%%-i -42 == %-i\n\", -42);}"},
	{1, 718, "moul_leftjusty_4", moul_leftjusty_4, moul_leftjusty_4_bench, "{return test(\"%%-4d 42 == |%-4d|\n\", 42);}"},
	{1, 719, "moul_leftjusty_5", moul_leftjusty_5, moul_leftjusty_5_bench, "{return test(\"%%-5d -42 == |%-5d|\n\", -42);}"},
	{1, 720, "moul_leftjusty_6", moul_leftjusty_6, moul_leftjusty_6_bench, "{return test(\"|%3i|%-3i|\n\", 42, 42);}"},
	{1, 721, "moul_leftjusty_7", moul_leftjusty_7, moul_leftjusty_7_bench, "{return test(\"%%-4i 42 == |%-4i|\n\", 42);}"},
	{1, 722, "moul_notmandatory_star_1", moul_notmandatory_star_1, moul_notmandatory_star_1_bench, "{return test(\"%%-*.3s LYDI == |%-*.3s|\n\", 5, \"LYDI\");}"},
	{1, 723, "moul_notmandatory_star_3", moul_notmandatory_star_3, moul_notmandatory_star_3_bench, "{return test(\"%%*i 42 == |%*i|\n\", 5, 42);}"},
	{1, 724, "moul_notmandatory_star_4", moul_notmandatory_star_4, moul_notmandatory_star_4_bench, "{return test(\"%%*i 42 == |%*i|\n\", 3, 42);}"},
	{1, 725, "moul_notmandatory_star_5", moul_notmandatory_star_5, moul_notmandatory_star_5_bench, "{return test(\"%%*i 42 == |%*i|\n\", 2, 42);}"},
	{1, 726, "new2019_star_1", new2019_star_1, new2019_star_1_bench, "{return test(\"%*s\", 32, \"abc\");}"},
	{1, 727, "new2019_star_2", new2019_star_2, new2019_star_2_bench, "{return test(\"%-*s\", 32, \"abc\");}"},
	{1, 728, "new2019_star_3", new2019_star_3, new2019_star_3_bench, "{return test(\"%*s\", 3, \"hello\");}"},
	{1, 729, "new2019_star_4", new2019_star_4, new2019_star_4_bench, "{return test(\"%.*s\", 3, \"hello\");}"},
	{1, 730, "new2019_star_5", new2019_star_5, new2019_star_5_bench, "{return test(\"%.*s\", 0, \"hello\");}"},
	{1, 731, "new2019_star_6", new2019_star_6, new2019_star_6_bench, "{return test(\"%-*.*s\", 7, 3, \"yolo\");}"},
	{1, 732, "new2019_star_7", new2019_star_7, new2019_star_7_bench, "{return test(\"%*i\", 4, 94827);}"},
	{1, 733, "new2019_star_8", new2019_star_8, new2019_star_8_bench, "{return test(\"%*i\", 14, 94827);}"},
	{1, 734, "new2019_star_9", new2019_star_9, new2019_star_9_bench, "{return test(\"%.*i\", 6, -3);}"},
	{1, 735, "new2019_star_10", new2019_star_10, new2019_star_10_bench, "{return test(\"%0*i\", 7, -54);}"},
	{1, 736, "new2019_negstar_1", new2019_negstar_1, new2019_negstar_1_bench, "{return test(\"%*s\", -32, \"abc\");}"},
	{1, 737, "new2019_negstar_2", new2019_negstar_2, new2019_negstar_2_bench, "{return test(\"%-*s\", -32, \"abc\");}"},
	{1, 738, "new2019_negstar_3", new2019_negstar_3, new2019_negstar_3_bench, "{return test(\"%*s\", -3, \"hello\");}"},
	{1, 739, "new2019_negstar_4", new2019_negstar_4, new2019_negstar_4_bench, "{return test(\"%.*s\", -3, \"hello\");}"},
	{1, 740, "new2019_negstar_5", new2019_negstar_5, new2019_negstar_5_bench, "{return test(\"%-*.*s\", -7, -3, \"yolo\");}"},
	{1, 741, "new2019_negstar_6", new2019_negstar_6, new2019_negstar_6_bench, "{return test(\"%*i\", -4, 94827);}"},
	{1, 742, "new2019_negstar_7", new2019_negstar_7, new2019_negstar_7_bench, "{return test(\"%*i\", -14, 94827);}"},
	{1, 743, "new2019_negstar_8", new2019_negstar_8, new2019_negstar_8_bench, "{return test(\"%.*i\", -6, -3);}"},
	{1, 744, "new2019_negstar_9", new2019_negstar_9, new2019_negstar_9_bench, "{return test(\"%0*i\", -7, -54);}"},
	{0, 2147483647, NULL, NULL, NULL, NULL}
};

