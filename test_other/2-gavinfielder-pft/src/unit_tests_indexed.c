/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/06/21 17:34:47 by gfielder         ###   ########.fr       */
/*   Updated: 2019/05/27 19:43:41 by phtruong         ###   ########.fr       */
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
// multiple flags diff order same width and precision
 int	s_undefbehav_4_flags_diff_order_1(void){return ft_printf("%+- 06.06s", s_hidden);}
 int	s_undefbehav_4_flags_diff_order_2(void){return ft_printf("% 0+-6.06s", s_hidden);}
 int	s_undefbehav_4_flags_diff_order_3(void){return ft_printf("%0 +-6.06s", s_hidden);}
 int	s_undefbehav_4_flags_diff_order_4(void){return ft_printf("%+-0 6.06s", s_hidden);}
 int	s_undefbehav_4_flags_diff_order_5(void){return ft_printf("%-+ 06.06s", s_hidden);}
 int	s_undefbehav_4_flags_diff_order_6(void){return ft_printf("% -+06.06s", s_hidden);}
// multiple flags diff order width > precision
 int	s_undefbehav_4_flags_sp_padded_diff_order_1(void){return ft_printf("%+- 07.06s", s_hidden);}
 int	s_undefbehav_4_flags_sp_padded_diff_order_2(void){return ft_printf("% 0+-8.06s", s_hidden);}
 int	s_undefbehav_4_flags_sp_padded_diff_order_3(void){return ft_printf("%0 +-9.06s", s_hidden);}
 int	s_undefbehav_4_flags_sp_padded_diff_order_4(void){return ft_printf("%+-0 10.06s", s_hidden);}
 int	s_undefbehav_4_flags_sp_padded_diff_order_5(void){return ft_printf("%-+ 011.06s", s_hidden);}
 int	s_undefbehav_4_flags_sp_padded_diff_order_6(void){return ft_printf("% -+012.06s", s_hidden);}
// multiple flags diff order width > precision, truncated string
 int	s_undefbehav_4_flags_as_lj_sp_zero_trunc(void){return ft_printf("%+- 06.04s", s_hidden);}
 int	s_undefbehav_4_flags_sp_zero_as_lj_trunc(void){return ft_printf("% 0+-6.04s", s_hidden);}
 int	s_undefbehav_4_flags_zero_sp_as_lj_trunc(void){return ft_printf("%0 +-6.04s", s_hidden);}
 int	s_undefbehav_4_flags_as_lj_zero_sp_trunc(void){return ft_printf("%+-0 6.04s", s_hidden);}
 int	s_undefbehav_4_flags_lj_as_sp_zero_trunc(void){return ft_printf("%-+ 06.04s", s_hidden);}
 int	s_undefbehav_4_flags_sp_zero_lj_as_trunc(void){return ft_printf("% 0-+6.04s", s_hidden);}
// multiple flags diff order width < precision, excess precision
 int	s_undefbehav_4_flags_as_lj_sp_zero__pads(void){return ft_printf("%+- 06.09s", s_hidden);}
 int	s_undefbehav_4_flags_sp_zero_as_lj__pads(void){return ft_printf("% 0+-6.09s", s_hidden);}
 int	s_undefbehav_4_flags_zero_sp_as_lj__pads(void){return ft_printf("%0 +-6.09s", s_hidden);}
 int	s_undefbehav_4_flags_as_lj_zero_sp__pads(void){return ft_printf("%+-0 6.09s", s_hidden);}
 int	s_undefbehav_4_flags_lj_as_sp_zero__pads(void){return ft_printf("%-+ 06.09s", s_hidden);}
 int	s_undefbehav_4_flags_sp_zero_lj_as__pads(void){return ft_printf("% 0-+6.09s", s_hidden);}
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
// as and zero flags  width
 int	s_undefbehav_as_0_width_3(void){return ft_printf("%+03s", s_hidden);}
 int	s_undefbehav_as_0_width_9(void){return ft_printf("%+09s", s_hidden);}
// flag cancelling
 int	s_undefbehav_lj_0_width_3(void){return ft_printf("%-03s", s_hidden);}
 int	s_undefbehav_lj_0_width_9(void){return ft_printf("%-09s", s_hidden);}
 int	s_undefbehav_as_sp_width_3(void){return ft_printf("%+ 3s", s_hidden);}
 int	s_undefbehav_as_sp_width_6(void){return ft_printf("%+ 6s", s_hidden);}

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
//Signed integers  allsign ('+')
int		i_as_pos(void){return ft_printf("%+i", 5);}
int		i_as_neg(void){return ft_printf("%+i", -7);}
int		i_intmax_as(void){return ft_printf("%+i", 2147483647);}
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
//signed integers  field width and allsign
int		i_width_as_pos(void){return ft_printf("%+5i", 35);}
int		i_width_as_zero(void){return ft_printf("%+7i", 0);}
int		i_width_intmax_as(void){return ft_printf("%+24i", 2147483647);}
//signed integers with precision
int		i_prec_fits_pos(void){return ft_printf("%.5i", 2);}
int		i_prec_fits_neg(void){return ft_printf("%.6i", -3);}
int		i_prec_fits_zero(void){return ft_printf("%.3i", 0);}
int		i_prec_exactfit_pos(void){return ft_printf("%.4i", 5263);}
int		i_prec_exactfit_neg(void){return ft_printf("%.4i", -2372);}
int		i_prec_nofit_pos(void){return ft_printf("%.3i", 13862);}
int		i_prec_nofit_neg(void){return ft_printf("%.3i",-23646);}
int		i_prec_as_pos(void){return ft_printf("%+.7i", 234);}
int		i_prec_as_neg(void){return ft_printf("%+.7i", -446);}
int		i_prec_as_pos_nofit(void){return ft_printf("%+.3i", 3723);}
//Signed integers with zero field width padding
int		i_zp_pos_fits(void){return ft_printf("%05i", 43);}
int		i_zp_neg_fits(void){return ft_printf("%07i", -54);}
int		i_zp_zero_fits(void){return ft_printf("%03i", 0);}
int		i_zp_pos_exactfit(void){return ft_printf("%03i", 634);}
int		i_zp_neg_exactfit(void){return ft_printf("%04i", -532);}
int		i_zp_neg_minus1fit(void){return ft_printf("%04i", -4825);}
int		i_zp_as_fits(void){return ft_printf("%+05i", 432);}
int		i_zp_as_zero(void){return ft_printf("%+04i", 0);}
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
//Signed integers with field width and precision with allsign
int		i_prec_width_fit_fit_pos_as(void){return ft_printf("%+8.5i", 34);}
int		i_prec_width_fit_fit_neg_as(void){return ft_printf("%+10.5i", -216);}
int		i_prec_width_fit_fit_zero_as(void){return ft_printf("%+8.5i", 0);}
int		i_prec_width_nofit_fit_pos_as(void){return ft_printf("%+8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_as(void){return ft_printf("%+8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_as(void){return ft_printf("%+3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_as(void){return ft_printf("%+3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_as(void){return ft_printf("%+3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_as(void){return ft_printf("%+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int		i_prec_width_fit_fit_pos_ljas(void){return ft_printf("%+-8.5i", 34);}
int		i_prec_width_fit_fit_neg_ljas(void){return ft_printf("%+-10.5i", -216);}
int		i_prec_width_fit_fit_zero_ljas(void){return ft_printf("%+-8.5i", 0);}
int		i_prec_width_nofit_fit_pos_ljas(void){return ft_printf("%+-8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_ljas(void){return ft_printf("%+-8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_ljas(void){return ft_printf("%+-3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_ljas(void){return ft_printf("%+-3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_ljas(void){return ft_printf("%+-3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_ljas(void){return ft_printf("%+-3.3i", -8462);}
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
//Signed integers with field width and precision with allsign with zeropadding
int		i_prec_width_ff_pos_aszp(void){return ft_printf("%0+8.5i", 34);}
int		i_prec_width_ff_neg_aszp(void){return ft_printf("%0+10.5i", -216);}
int		i_prec_width_ff_zero_aszp(void){return ft_printf("%0+8.5i", 0);}
int		i_prec_width_nf_pos_aszp(void){return ft_printf("%0+8.3i", 8375);}
int		i_prec_width_nf_neg_aszp(void){return ft_printf("%0+8.3i", -8473);}
int		i_prec_width_fn_pos_aszp(void){return ft_printf("%0+3.7i", 3267);}
int		i_prec_width_fn_neg_aszp(void){return ft_printf("%0+3.7i", -2375);}
int		i_prec_width_nn_pos_aszp(void){return ft_printf("%0+3.3i", 6983);}
int		i_prec_width_nn_neg_aszp(void){return ft_printf("%0+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int		i_prec_width_ff_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-8.5i", 34);}
int		i_prec_width_ff_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-10.5i", -216);}
int		i_prec_width_ff_zero_ljaszp_ignoreflag(void){return ft_printf("%0+-8.5i", 0);}
int		i_prec_width_nf_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-8.3i", 8375);}
int		i_prec_width_nf_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-8.3i", -8473);}
int		i_prec_width_fn_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-3.7i", 3267);}
int		i_prec_width_fn_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-3.7i", -2375);}
int		i_prec_width_nn_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-3.3i", 6983);}
int		i_prec_width_nn_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-3.3i", -8462);}
//Signed integers of varying size modifiers
static char 		ch_pos_1 = 100, ch_neg_1 = -87;
static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
static int			i_pos_1 = 878023;
static long		l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
static long		lmax	= 9223372036854775807;
static long		lmin	= -9223372036854775807;
static long long llmax = 9223372036854775807;
static long long	llmin = -9223372036854775807ll;
int		i_size_hh_pos_casted(void){return ft_printf("%hhi", (char)45);}
int		i_size_hh_neg_casted(void){return ft_printf("%hhi", (char)-45);}
int		i_size_h_pos_casted(void){return ft_printf("%hi", (short)385);}
int		i_size_h_neg_casted(void){return ft_printf("%hi", (short)-385);}
int		i_size_l_pos_casted(void){return ft_printf("%li", (long)32);}
int		i_size_l_neg_casted(void){return ft_printf("%li", (long)-32);}
int		i_size_ll_pos_casted(void){return ft_printf("%lli", (long long)43);}
int		i_size_ll_neg_casted(void){return ft_printf("%lli", (long long)-43);}
int		i_size_hh_pos_ref(void){return ft_printf("%hhi", ch_pos_1);}
int		i_size_hh_neg_ref(void){return ft_printf("%hhi", ch_neg_1);}
int		i_size_h_pos_ref(void){return ft_printf("%hi", sh_pos_1);}
int		i_size_h_neg_ref(void){return ft_printf("%hi", sh_neg_1);}
int		i_size_l_pos_ref(void){return ft_printf("%li", l_pos_1);}
int		i_size_l_pos_ref_lmax(void){return ft_printf("%li", lmax);}
int		i_size_ll_pos_ref_llmax(void){return ft_printf("%lli", llmax);}
int		i_size_l_neg_ref(void){return ft_printf("%li", l_neg_1);}
int		i_size_ll_pos_ref(void){return ft_printf("%lli", ll_pos_1);}
int		i_size_ll_neg_ref(void){return ft_printf("%lli", ll_neg_1);}
int		i_size_l_pos_big(void){return ft_printf("%li", 22337203685477);}
int		i_size_l_neg_big(void){return ft_printf("%li", -22337203685477);}
int		i_size_ll_pos_big(void){return ft_printf("%lli", 522337203685470ll);}
int		i_size_ll_neg_big(void){return ft_printf("%lli", -522337203685470ll);}
int		i_llmax(void){return ft_printf("%lli", 9223372036854775807ll);}
int		i_llmin(void){return ft_printf("%lli", llmin);}
int		i_lmax(void){return ft_printf("%li", 9223372036854775807l);}
int		i_lmin(void){return ft_printf("%li", lmin);}
int		i_hmax(void){return ft_printf("%hi", (short)32767);}
int		i_hmin(void){return ft_printf("%hi", (short)(-32768));}
int		i_hhmax(void){return ft_printf("%hhi", (char)127);}
int		i_hhmin(void){return ft_printf("%hhi", (char)(-128));}

//Signed integers of varying size modifiers with some other modifiers
int		i_size_l_pos_big_zp(void){return ft_printf("%037li", 22337203685477l);}
int		i_size_l_neg_big_prec(void){return ft_printf("%.37li", -22337203685477l);}
int		i_size_ll_pos_big_width(void){return ft_printf("%37lli", 522337203685470ll);}
int		i_size_ll_neg_big_lj(void){return ft_printf("%-37lli", -522337203685470ll);}
int		i_size_l_pos_big_as(void){return ft_printf("%+li", 22337203685477l);}
//Multiple signed integers in a row of varying sizes
int		i_size_follows_i_i(void){return ft_printf("[%i] [%i]", i_pos_1, i_pos_1);}
int		i_size_follows_i_l(void){return ft_printf("[%i] [%li]", i_pos_1, l_pos_1);}
int		i_size_follows_i_ll(void){return ft_printf("[%i] [%lli]", i_pos_1, ll_pos_1);}
int		i_size_follows_i_h(void){return ft_printf("[%i] [%hi]", i_pos_1, sh_pos_1);}
int		i_size_follows_i_hh(void){return ft_printf("[%i] [%hhi]", i_pos_1, ch_pos_1);}
int		i_size_ll_hh_ll(void){return ft_printf("%lli%hhi%lli", ll_pos_1, ch_neg_1, ll_neg_1);}
int		i_size_h_l_hh(void){return ft_printf("%hi%li%hhi", sh_pos_1, l_neg_1, ch_neg_1);}
int		i_size_l_hh_h(void){return ft_printf("%li%hhi%hi", l_neg_1, ch_pos_1, sh_pos_1);}
int		i_size_n_ll_hh(void){return ft_printf("%i%lli%hhi", i_pos_1, ll_neg_1, ch_pos_1);}
int		i_size_ll_n_l(void){return ft_printf("%lli%i%li", ll_neg_1, i_pos_1, l_pos_1);}
//Signed integers - space - no modifers
int		i_basic_i_pos_sp(void){return ft_printf("this % i number", 17);}
int		i_basic_i_neg_sp(void){return ft_printf("this % i number", -267);}
int		i_basic_i_zero_sp(void){return ft_printf("this % i number", 0);}
int		i_basic_i_onlypos_sp(void){return ft_printf("% i", 3);}
int		i_basic_i_onlyneg_sp(void){return ft_printf("% i", -1);}
int		i_basic_i_onlyzero_sp(void){return ft_printf("% i", 0);}
int		i_basic_i_pos_d_sp(void){return ft_printf("this % d number", 17);}
int		i_basic_i_neg_d_sp(void){return ft_printf("this % d number", -267);}
int		i_basic_i_zero_d_sp(void){return ft_printf("this % d number", 0);}
int		i_intmax_sp(void){return ft_printf("% i", 2147483647);}
int		i_intmin_sp(void){return ft_printf("% i", (int)(-2147483678));}
//Signed integers - space with allsign ('+')
int		i_assp_pos_ignoreflag(void){return ft_printf("% +i", 5);}
int		i_assp_neg_ignoreflag(void){return ft_printf("% +i", -7);}
int		i_intmax_assp_ignoreflag(void){return ft_printf("% +i", 2147483647);}
//Signed integers - space with field width
int		i_width_pos_fits_sp(void){return ft_printf("% 7i", 33);}
int		i_width_neg_fits_sp(void){return ft_printf("% 7i", -14);}
int		i_width_zero_fits_sp(void){return ft_printf("% 3i", 0);}
int		i_width_pos_exactfit_sp(void){return ft_printf("% 5i", 52625);}
int		i_width_neg_exactfit_sp(void){return ft_printf("% 5i", -2562);}
int		i_width_pos_nofit_sp(void){return ft_printf("% 4i", 94827);}
int		i_width_neg_nofit_sp(void){return ft_printf("% 4i", -2464);}
int		i_width_pos_fits_lj_sp(void){return ft_printf("% -7i", 33);}
int		i_width_neg_fits_lj_sp(void){return ft_printf("% -7i", -14);}
int		i_width_zero_fits_lj_sp(void){return ft_printf("% -3i", 0);}
int		i_width_pos_exactfit_lj_sp(void){return ft_printf("% -5i", 52625);}
int		i_width_neg_exactfit_lj_sp(void){return ft_printf("% -5i", -2562);}
int		i_width_pos_nofit_lj_sp(void){return ft_printf("% -4i", 94827);}
int		i_width_neg_nofit_lj_sp(void){return ft_printf("% -4i", -2464);}
//signed integers with field width and allsign
int		i_width_assp_pos_ignoreflag(void){return ft_printf("% +5i", 35);}
int		i_width_assp_zero_ignoreflag(void){return ft_printf("% +7i", 0);}
int		i_width_intmax_assp_ignoreflag(void){return ft_printf("% +24i", 2147483647);}
//signed integers with precision
int		i_prec_fits_pos_sp(void){return ft_printf("% .5i", 2);}
int		i_prec_fits_neg_sp(void){return ft_printf("% .6i", -3);}
int		i_prec_fits_zero_sp(void){return ft_printf("% .3i", 0);}
int		i_prec_exactfit_pos_sp(void){return ft_printf("% .4i", 5263);}
int		i_prec_exactfit_neg_sp(void){return ft_printf("% .4i", -2372);}
int		i_prec_nofit_pos_sp(void){return ft_printf("% .3i", 13862);}
int		i_prec_nofit_neg_sp(void){return ft_printf("% .3i",-23646);}
int		i_prec_assp_pos_ignoreflag(void){return ft_printf("% +.7i", 234);}
int		i_prec_assp_neg_ignoreflag(void){return ft_printf("% +.7i", -446);}
int		i_prec_assp_pos_nofit_ignoreflag(void){return ft_printf("% +.3i", 3723);}
//Signed integers - space with zero field width padding
int		i_zpsp_pos_fits(void){return ft_printf("% 05i", 43);}
int		i_zpsp_neg_fits(void){return ft_printf("% 07i", -54);}
int		i_zpsp_zero_fits(void){return ft_printf("% 03i", 0);}
int		i_zpsp_pos_exactfit(void){return ft_printf("% 03i", 634);}
int		i_zpsp_neg_exactfit(void){return ft_printf("% 04i", -532);}
int		i_zpsp_neg_minus1fit(void){return ft_printf("% 04i", -4825);}
int		i_zpassp_as_fits_ignoreflag(void){return ft_printf("% +05i", 432);}
int		i_zpassp_zero_ignoreflag(void){return ft_printf("% +04i", 0);}
//Signed integers - space with field width and precision
int		i_prec_width_fit_fit_pos_sp(void){return ft_printf("% 8.5i", 34);}
int		i_prec_width_fit_fit_neg_sp(void){return ft_printf("% 10.5i", -216);}
int		i_prec_width_fit_fit_zero_sp(void){return ft_printf("% 8.5i", 0);}
int		i_prec_width_nofit_fit_pos_sp(void){return ft_printf("% 8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_sp(void){return ft_printf("% 8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_sp(void){return ft_printf("% 3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_sp(void){return ft_printf("% 3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_sp(void){return ft_printf("% 3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_sp(void){return ft_printf("% 3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified
int		i_prec_width_fit_fit_pos_lj_sp(void){return ft_printf("% -8.5i", 34);}
int		i_prec_width_fit_fit_neg_lj_sp(void){return ft_printf("% -10.5i", -216);}
int		i_prec_width_fit_fit_zero_lj_sp(void){return ft_printf("% -8.5i", 0);}
int		i_prec_width_nofit_fit_pos_lj_sp(void){return ft_printf("% -8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_lj_sp(void){return ft_printf("% -8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_lj_sp(void){return ft_printf("% -3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_lj_sp(void){return ft_printf("% -3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_lj_sp(void){return ft_printf("% -3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_lj_sp(void){return ft_printf("% -3.3i", -8462);}
//Signed integers - space with field width and precision with allsign
int		i_prec_width_fit_fit_pos_assp_ignoreflag(void){return ft_printf("% +8.5i", 34);}
int		i_prec_width_fit_fit_neg_assp_ignoreflag(void){return ft_printf("% +10.5i", -216);}
int		i_prec_width_fit_fit_zero_assp_ignoreflag(void){return ft_printf("% +8.5i", 0);}
int		i_prec_width_nofit_fit_pos_assp_ignoreflag(void){return ft_printf("% +8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_assp_ignoreflag(void){return ft_printf("% +8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_assp_ignoreflag(void){return ft_printf("% +3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_assp_ignoreflag(void){return ft_printf("% +3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_assp_ignoreflag(void){return ft_printf("% +3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_assp_ignoreflag(void){return ft_printf("% +3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign
int		i_prec_width_fit_fit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-8.5i", 34);}
int		i_prec_width_fit_fit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-10.5i", -216);}
int		i_prec_width_fit_fit_zero_lj_assp_ignoreflag(void){return ft_printf("% +-8.5i", 0);}
int		i_prec_width_nofit_fit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-3.3i", -8462);}
//Signed integers - space with field width and precision with zeropadding
int		i_prec_width_ff_pos_zp_sp(void){return ft_printf("% 08.5i", 34);}
int		i_prec_width_ff_neg_zp_sp(void){return ft_printf("% 010.5i", -216);}
int		i_prec_width_ff_zero_zp_sp(void){return ft_printf("% 08.5i", 0);}
int		i_prec_width_nf_pos_zp_sp(void){return ft_printf("% 08.3i", 8375);}
int		i_prec_width_nf_neg_zp_sp(void){return ft_printf("% 08.3i", -8473);}
int		i_prec_width_fn_pos_zp_sp(void){return ft_printf("% 03.7i", 3267);}
int		i_prec_width_fn_neg_zp_sp(void){return ft_printf("% 03.7i", -2375);}
int		i_prec_width_nn_pos_zp_sp(void){return ft_printf("% 03.3i", 6983);}
int		i_prec_width_nn_neg_zp_sp(void){return ft_printf("% 03.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with zeropadding
int		i_prec_width_ff_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.5i", 34);}
int		i_prec_width_ff_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-10.5i", -216);}
int		i_prec_width_ff_zero_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.5i", 0);}
int		i_prec_width_nf_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.3i", 8375);}
int		i_prec_width_nf_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.3i", -8473);}
int		i_prec_width_fn_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.7i", 3267);}
int		i_prec_width_fn_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.7i", -2375);}
int		i_prec_width_nn_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.3i", 6983);}
int		i_prec_width_nn_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.3i", -8462);}
//Signed integers - space with field width and precision with allsign with zeropadding
int		i_prec_width_ff_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+8.5i", 34);}
int		i_prec_width_ff_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+10.5i", -216);}
int		i_prec_width_ff_zero_aszpsp_ignoreflag(void){return ft_printf("% 0+8.5i", 0);}
int		i_prec_width_nf_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+8.3i", 8375);}
int		i_prec_width_nf_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+8.3i", -8473);}
int		i_prec_width_fn_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+3.7i", 3267);}
int		i_prec_width_fn_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+3.7i", -2375);}
int		i_prec_width_nn_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+3.3i", 6983);}
int		i_prec_width_nn_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign with zeropadding
int		i_prec_width_ff_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.5i", 34);}
int		i_prec_width_ff_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-10.5i", -216);}
int		i_prec_width_ff_zero_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.5i", 0);}
int		i_prec_width_nf_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.3i", 8375);}
int		i_prec_width_nf_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.3i", -8473);}
int		i_prec_width_fn_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.7i", 3267);}
int		i_prec_width_fn_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.7i", -2375);}
int		i_prec_width_nn_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.3i", 6983);}
int		i_prec_width_nn_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.3i", -8462);}
//Signed integers - space of varying size modifiers
int		i_size_hh_pos_casted_sp(void){return ft_printf("% hhi", (char)45);}
int		i_size_hh_neg_casted_sp(void){return ft_printf("% hhi", (char)-45);}
int		i_size_h_pos_casted_sp(void){return ft_printf("% hi", (short)385);}
int		i_size_h_neg_casted_sp(void){return ft_printf("% hi", (short)-385);}
int		i_size_l_pos_casted_sp(void){return ft_printf("% li", (long)32);}
int		i_size_l_neg_casted_sp(void){return ft_printf("% li", (long)-32);}
int		i_size_ll_pos_casted_sp(void){return ft_printf("% lli", (long long)43);}
int		i_size_ll_neg_casted_sp(void){return ft_printf("% lli", (long long)-43);}
int		i_size_hh_pos_ref_sp(void){return ft_printf("% hhi", ch_pos_1);}
int		i_size_hh_neg_ref_sp(void){return ft_printf("% hhi", ch_neg_1);}
int		i_size_h_pos_ref_sp(void){return ft_printf("% hi", sh_pos_1);}
int		i_size_h_neg_ref_sp(void){return ft_printf("% hi", sh_neg_1);}
int		i_size_l_pos_ref_sp(void){return ft_printf("% li", l_pos_1);}
int		i_size_l_neg_ref_sp(void){return ft_printf("% li", l_neg_1);}
int		i_size_ll_pos_ref_sp(void){return ft_printf("% lli", ll_pos_1);}
int		i_size_ll_neg_ref_sp(void){return ft_printf("% lli", ll_neg_1);}
int		i_size_l_pos_big_sp(void){return ft_printf("% li", 22337203685477l);}
int		i_size_l_neg_big_sp(void){return ft_printf("% li", -22337203685477l);}
int		i_size_ll_pos_big_sp(void){return ft_printf("% lli", 522337203685470ll);}
int		i_size_ll_neg_big_sp(void){return ft_printf("% lli", -522337203685470ll);}
int		i_llmax_sp(void){return ft_printf("% lli", 9223372036854775807ll);}
int		i_llmin_sp(void){return ft_printf("% lli", llmin);}
int		i_lmax_sp(void){return ft_printf("% li", 9223372036854775807l);}
int		i_lmin_sp(void){return ft_printf("% li", lmin);}
int		i_hmax_sp(void){return ft_printf("% hi", (short)32767);}
int		i_hmin_sp(void){return ft_printf("% hi", (short)(-32768));}
int		i_hhmax_sp(void){return ft_printf("% hhi", (char)(127));}
int		i_hhmin_sp(void){return ft_printf("% hhi", (char)(-128));}
 //Signed integers - zero precision zero value
int i_prec0val0_basic(void){return ft_printf("%.0i", 0);}
int i_prec0val0_implicit(void){return ft_printf("%.i", 0);}
int i_prec0val0_w(void){return ft_printf("%5.0i", 0);}
int i_prec0val0_w_impl(void){return ft_printf("%5.i", 0);}
int i_prec0val0_wlj(void){return ft_printf("%-5.0i", 0);}
int i_prec0val0_wlj_impl(void){return ft_printf("%-5.i", 0);}
int i_prec0val0_as(void){return ft_printf("%+.0i", 0);}
int i_prec0val0_as_impl(void){return ft_printf("%+.i", 0);}
int i_prec0val0_was(void){return ft_printf("%+5.0i", 0);}
int i_prec0val0_was_impl(void){return ft_printf("%+5.i", 0);}
int i_prec0val0_waslj(void){return ft_printf("%+-5.0i", 0);}
int i_prec0val0_waslj_impl(void){return ft_printf("%+-5.i", 0);}
//Signed integers - some out of range h, hh tests from filechecker
 int i_ftfc_hhdoutofrange1_might_be_undefbehav(void){return ft_printf("%hhi", -129);}
 int i_ftfc_hhdoutofrange2_might_be_undefbehav(void){return ft_printf("%hhi", 128);}
 int i_ftfc_hdoutofrange1_might_be_undefbehav(void){return ft_printf("%hi", 32768);}
 int i_ftfc_hdoutofrange2_might_be_undefbehav(void){return ft_printf("%hi", -32769);}


//Signed integers - no modifers
int	 d_basic_i_pos(void){return ft_printf("this %d number", 17);}
int	 d_basic_i_neg(void){return ft_printf("this %d number", -267);}
int	 d_basic_i_zero(void){return ft_printf("this %d number", 0);}
int	 d_basic_i_onlypos(void){return ft_printf("%d", 3);}
int	 d_basic_i_onlyneg(void){return ft_printf("%d", -1);}
int	 d_basic_i_onlyzero(void){return ft_printf("%d", 0);}
int	 d_intmax(void){return ft_printf("%d",  2147483647);}
int	 d_intmin(void){return ft_printf("%d", (int)(-2147483678));}
//Signed integers with allsign ('+')
int	 d_as_pos(void){return ft_printf("%+d", 5);}
int	 d_as_neg(void){return ft_printf("%+d", -7);}
int	 d_intmax_as(void){return ft_printf("%+d", 2147483647);}
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
//signed integers with field width and allsign
int	 d_width_as_pos(void){return ft_printf("%+5d", 35);}
int	 d_width_as_zero(void){return ft_printf("%+7d", 0);}
int	 d_width_intmax_as(void){return ft_printf("%+24d", 2147483647);}
//signed integers with precision
int	 d_prec_fits_pos(void){return ft_printf("%.5d", 2);}
int	 d_prec_fits_neg(void){return ft_printf("%.6d", -3);}
int	 d_prec_fits_zero(void){return ft_printf("%.3d", 0);}
int	 d_prec_exactfit_pos(void){return ft_printf("%.4d", 5263);}
int	 d_prec_exactfit_neg(void){return ft_printf("%.4d", -2372);}
int	 d_prec_nofit_pos(void){return ft_printf("%.3d", 13862);}
int	 d_prec_nofit_neg(void){return ft_printf("%.3d",-23646);}
int	 d_prec_as_pos(void){return ft_printf("%+.7d", 234);}
int	 d_prec_as_neg(void){return ft_printf("%+.7d", -446);}
int	 d_prec_as_pos_nofit(void){return ft_printf("%+.3d", 3723);}
//Signed integers with zero field width padding
int	 d_zp_pos_fits(void){return ft_printf("%05d", 43);}
int	 d_zp_neg_fits(void){return ft_printf("%07d", -54);}
int	 d_zp_zero_fits(void){return ft_printf("%03d", 0);}
int	 d_zp_pos_exactfit(void){return ft_printf("%03d", 634);}
int	 d_zp_neg_exactfit(void){return ft_printf("%04d", -532);}
int	 d_zp_neg_minus1fit(void){return ft_printf("%04d", -4825);}
int	 d_zp_as_fits(void){return ft_printf("%+05d", 432);}
int	 d_zp_as_zero(void){return ft_printf("%+04d", 0);}
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
//Signed integers with field width and precision with allsign
int	 d_prec_width_fit_fit_pos_as(void){return ft_printf("%+8.5d", 34);}
int	 d_prec_width_fit_fit_neg_as(void){return ft_printf("%+10.5d", -216);}
int	 d_prec_width_fit_fit_zero_as(void){return ft_printf("%+8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_as(void){return ft_printf("%+8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_as(void){return ft_printf("%+8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_as(void){return ft_printf("%+3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_as(void){return ft_printf("%+3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_as(void){return ft_printf("%+3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_as(void){return ft_printf("%+3.3d", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int	 d_prec_width_fit_fit_pos_ljas(void){return ft_printf("%+-8.5d", 34);}
int	 d_prec_width_fit_fit_neg_ljas(void){return ft_printf("%+-10.5d", -216);}
int	 d_prec_width_fit_fit_zero_ljas(void){return ft_printf("%+-8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_ljas(void){return ft_printf("%+-8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_ljas(void){return ft_printf("%+-8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_ljas(void){return ft_printf("%+-3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_ljas(void){return ft_printf("%+-3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_ljas(void){return ft_printf("%+-3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_ljas(void){return ft_printf("%+-3.3d", -8462);}
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
//Signed integers with field width and precision with allsign with zeropadding
int	 d_prec_width_ff_pos_aszp(void){return ft_printf("%0+8.5d", 34);}
int	 d_prec_width_ff_neg_aszp(void){return ft_printf("%0+10.5d", -216);}
int	 d_prec_width_ff_zero_aszp(void){return ft_printf("%0+8.5d", 0);}
int	 d_prec_width_nf_pos_aszp(void){return ft_printf("%0+8.3d", 8375);}
int	 d_prec_width_nf_neg_aszp(void){return ft_printf("%0+8.3d", -8473);}
int	 d_prec_width_fn_pos_aszp(void){return ft_printf("%0+3.7d", 3267);}
int	 d_prec_width_fn_neg_aszp(void){return ft_printf("%0+3.7d", -2375);}
int	 d_prec_width_nn_pos_aszp(void){return ft_printf("%0+3.3d", 6983);}
int	 d_prec_width_nn_neg_aszp(void){return ft_printf("%0+3.3d", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int	 d_prec_width_ff_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-8.5d", 34);}
int	 d_prec_width_ff_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-10.5d", -216);}
int	 d_prec_width_ff_zero_ljaszp_ignoreflag(void){return ft_printf("%0+-8.5d", 0);}
int	 d_prec_width_nf_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljaszp_ignoreflag(void){return ft_printf("%0+-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljaszp_ignoreflag(void){return ft_printf("%0+-3.3d", -8462);}
//Signed integers of varying size modifiers
int	 d_size_hh_pos_casted(void){return ft_printf("%hhd", (char)45);}
int	 d_size_hh_neg_casted(void){return ft_printf("%hhd", (char)-45);}
int	 d_size_h_pos_casted(void){return ft_printf("%hd", (short)385);}
int	 d_size_h_neg_casted(void){return ft_printf("%hd", (short)-385);}
int	 d_size_l_pos_casted(void){return ft_printf("%ld", (long)32);}
int	 d_size_l_neg_casted(void){return ft_printf("%ld", (long)-32);}
int	 d_size_ll_pos_casted(void){return ft_printf("%lld", (long long)43);}
int	 d_size_ll_neg_casted(void){return ft_printf("%lld", (long long)-43);}
int	 d_size_hh_pos_ref(void){return ft_printf("%hhd", ch_pos_1);}
int	 d_size_hh_neg_ref(void){return ft_printf("%hhd", ch_neg_1);}
int	 d_size_h_pos_ref(void){return ft_printf("%hd", sh_pos_1);}
int	 d_size_h_neg_ref(void){return ft_printf("%hd", sh_neg_1);}
int	 d_size_l_pos_ref(void){return ft_printf("%ld", l_pos_1);}
int	 d_size_l_pos_ref_lmax(void){return ft_printf("%ld", lmax);}
int	 d_size_ll_pos_ref_llmax(void){return ft_printf("%lld", llmax);}
int	 d_size_l_neg_ref(void){return ft_printf("%ld", l_neg_1);}
int	 d_size_ll_pos_ref(void){return ft_printf("%lld", ll_pos_1);}
int	 d_size_ll_neg_ref(void){return ft_printf("%lld", ll_neg_1);}
int	 d_size_l_pos_big(void){return ft_printf("%ld", 22337203685477);}
int	 d_size_l_neg_big(void){return ft_printf("%ld", -22337203685477);}
int	 d_size_ll_pos_big(void){return ft_printf("%lld", 522337203685470ll);}
int	 d_size_ll_neg_big(void){return ft_printf("%lld", -522337203685470ll);}
int	 d_llmax(void){return ft_printf("%lld", 9223372036854775807ll);}
int	 d_llmin(void){return ft_printf("%lld", llmin);}
int	 d_lmax(void){return ft_printf("%ld", 9223372036854775807l);}
int	 d_lmin(void){return ft_printf("%ld", lmin);}
int	 d_hmax(void){return ft_printf("%hd", (short)32767);}
int	 d_hmin(void){return ft_printf("%hd", (short)(-32768));}
int	 d_hhmax(void){return ft_printf("%hhd", (char)127);}
int	 d_hhmin(void){return ft_printf("%hhd", (char)(-128));}

//Signed integers of varying size modifiers with some other modifiers
int	 d_size_l_pos_big_zp(void){return ft_printf("%037ld", 22337203685477l);}
int	 d_size_l_neg_big_prec(void){return ft_printf("%.37ld", -22337203685477l);}
int	 d_size_ll_pos_big_width(void){return ft_printf("%37lld", 522337203685470ll);}
int	 d_size_ll_neg_big_lj(void){return ft_printf("%-37lld", -522337203685470ll);}
int	 d_size_l_pos_big_as(void){return ft_printf("%+ld", 22337203685477l);}
//Multiple signed integers in a row of varying sizes
int	 d_size_follows_i_i(void){return ft_printf("[%d] [%d]", i_pos_1, i_pos_1);}
int	 d_size_follows_i_l(void){return ft_printf("[%d] [%ld]", i_pos_1, l_pos_1);}
int	 d_size_follows_i_ll(void){return ft_printf("[%d] [%lld]", i_pos_1, ll_pos_1);}
int	 d_size_follows_i_h(void){return ft_printf("[%d] [%hd]", i_pos_1, sh_pos_1);}
int	 d_size_follows_i_hh(void){return ft_printf("[%d] [%hhd]", i_pos_1, ch_pos_1);}
int	 d_size_ll_hh_ll(void){return ft_printf("%lld%hhd%lld", ll_pos_1, ch_neg_1, ll_neg_1);}
int	 d_size_h_l_hh(void){return ft_printf("%hd%ld%hhd", sh_pos_1, l_neg_1, ch_neg_1);}
int	 d_size_l_hh_h(void){return ft_printf("%ld%hhd%hd", l_neg_1, ch_pos_1, sh_pos_1);}
int	 d_size_n_ll_hh(void){return ft_printf("%d%lld%hhd", i_pos_1, ll_neg_1, ch_pos_1);}
int	 d_size_ll_n_l(void){return ft_printf("%lli%d%ld", ll_neg_1, i_pos_1, l_pos_1);}
//Signed integers - space - no modifers
int	 d_basic_i_pos_sp(void){return ft_printf("this % d number", 17);}
int	 d_basic_i_neg_sp(void){return ft_printf("this % d number", -267);}
int	 d_basic_i_zero_sp(void){return ft_printf("this % d number", 0);}
int	 d_basic_i_onlypos_sp(void){return ft_printf("% d", 3);}
int	 d_basic_i_onlyneg_sp(void){return ft_printf("% d", -1);}
int	 d_basic_i_onlyzero_sp(void){return ft_printf("% d", 0);}
int	 d_basic_i_pos_d_sp(void){return ft_printf("this % d number", 17);}
int	 d_basic_i_neg_d_sp(void){return ft_printf("this % d number", -267);}
int	 d_basic_i_zero_d_sp(void){return ft_printf("this % d number", 0);}
int	 d_intmax_sp(void){return ft_printf("% d", 2147483647);}
int	 d_intmin_sp(void){return ft_printf("% d", (int)(-2147483678));}
//Signed integers - space with allsign ('+')
int	 d_assp_pos_ignoreflag(void){return ft_printf("% +d", 5);}
int	 d_assp_neg_ignoreflag(void){return ft_printf("% +d", -7);}
int	 d_intmax_assp_ignoreflag(void){return ft_printf("% +d", 2147483647);}
//Signed integers - space with field width
int	 d_width_pos_fits_sp(void){return ft_printf("% 7d", 33);}
int	 d_width_neg_fits_sp(void){return ft_printf("% 7d", -14);}
int	 d_width_zero_fits_sp(void){return ft_printf("% 3d", 0);}
int	 d_width_pos_exactfit_sp(void){return ft_printf("% 5d", 52625);}
int	 d_width_neg_exactfit_sp(void){return ft_printf("% 5d", -2562);}
int	 d_width_pos_nofit_sp(void){return ft_printf("% 4d", 94827);}
int	 d_width_neg_nofit_sp(void){return ft_printf("% 4d", -2464);}
int	 d_width_pos_fits_lj_sp(void){return ft_printf("% -7d", 33);}
int	 d_width_neg_fits_lj_sp(void){return ft_printf("% -7d", -14);}
int	 d_width_zero_fits_lj_sp(void){return ft_printf("% -3d", 0);}
int	 d_width_pos_exactfit_lj_sp(void){return ft_printf("% -5d", 52625);}
int	 d_width_neg_exactfit_lj_sp(void){return ft_printf("% -5d", -2562);}
int	 d_width_pos_nofit_lj_sp(void){return ft_printf("% -4d", 94827);}
int	 d_width_neg_nofit_lj_sp(void){return ft_printf("% -4d", -2464);}
//signed integers with field width and allsign
int	 d_width_assp_pos_ignoreflag(void){return ft_printf("% +5d", 35);}
int	 d_width_assp_zero_ignoreflag(void){return ft_printf("% +7d", 0);}
int	 d_width_intmax_assp_ignoreflag(void){return ft_printf("% +24d", 2147483647);}
//signed integers with precision
int	 d_prec_fits_pos_sp(void){return ft_printf("% .5d", 2);}
int	 d_prec_fits_neg_sp(void){return ft_printf("% .6d", -3);}
int	 d_prec_fits_zero_sp(void){return ft_printf("% .3d", 0);}
int	 d_prec_exactfit_pos_sp(void){return ft_printf("% .4d", 5263);}
int	 d_prec_exactfit_neg_sp(void){return ft_printf("% .4d", -2372);}
int	 d_prec_nofit_pos_sp(void){return ft_printf("% .3d", 13862);}
int	 d_prec_nofit_neg_sp(void){return ft_printf("% .3d",-23646);}
int	 d_prec_assp_pos_ignoreflag(void){return ft_printf("% +.7d", 234);}
int	 d_prec_assp_neg_ignoreflag(void){return ft_printf("% +.7d", -446);}
int	 d_prec_assp_pos_nofit_ignoreflag(void){return ft_printf("% +.3d", 3723);}
//Signed integers - space with zero field width padding
int	 d_zpsp_pos_fits(void){return ft_printf("% 05d", 43);}
int	 d_zpsp_neg_fits(void){return ft_printf("% 07d", -54);}
int	 d_zpsp_zero_fits(void){return ft_printf("% 03d", 0);}
int	 d_zpsp_pos_exactfit(void){return ft_printf("% 03d", 634);}
int	 d_zpsp_neg_exactfit(void){return ft_printf("% 04d", -532);}
int	 d_zpsp_neg_minus1fit(void){return ft_printf("% 04d", -4825);}
int	 d_zpassp_as_fits_ignoreflag(void){return ft_printf("% +05d", 432);}
int	 d_zpassp_zero_ignoreflag(void){return ft_printf("% +04d", 0);}
//Signed integers - space with field width and precision
int	 d_prec_width_fit_fit_pos_sp(void){return ft_printf("% 8.5d", 34);}
int	 d_prec_width_fit_fit_neg_sp(void){return ft_printf("% 10.5d", -216);}
int	 d_prec_width_fit_fit_zero_sp(void){return ft_printf("% 8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_sp(void){return ft_printf("% 8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_sp(void){return ft_printf("% 8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_sp(void){return ft_printf("% 3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_sp(void){return ft_printf("% 3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_sp(void){return ft_printf("% 3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_sp(void){return ft_printf("% 3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified
int	 d_prec_width_fit_fit_pos_lj_sp(void){return ft_printf("% -8.5d", 34);}
int	 d_prec_width_fit_fit_neg_lj_sp(void){return ft_printf("% -10.5d", -216);}
int	 d_prec_width_fit_fit_zero_lj_sp(void){return ft_printf("% -8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_lj_sp(void){return ft_printf("% -8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_lj_sp(void){return ft_printf("% -8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_lj_sp(void){return ft_printf("% -3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_lj_sp(void){return ft_printf("% -3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_lj_sp(void){return ft_printf("% -3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_lj_sp(void){return ft_printf("% -3.3d", -8462);}
//Signed integers - space with field width and precision with allsign
int	 d_prec_width_fit_fit_pos_assp_ignoreflag(void){return ft_printf("% +8.5d", 34);}
int	 d_prec_width_fit_fit_neg_assp_ignoreflag(void){return ft_printf("% +10.5d", -216);}
int	 d_prec_width_fit_fit_zero_assp_ignoreflag(void){return ft_printf("% +8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_assp_ignoreflag(void){return ft_printf("% +8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_assp_ignoreflag(void){return ft_printf("% +8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_assp_ignoreflag(void){return ft_printf("% +3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_assp_ignoreflag(void){return ft_printf("% +3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_assp_ignoreflag(void){return ft_printf("% +3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_assp_ignoreflag(void){return ft_printf("% +3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign
int	 d_prec_width_fit_fit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-8.5d", 34);}
int	 d_prec_width_fit_fit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-10.5d", -216);}
int	 d_prec_width_fit_fit_zero_lj_assp_ignoreflag(void){return ft_printf("% +-8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_lj_assp_ignoreflag(void){return ft_printf("% +-3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_lj_assp_ignoreflag(void){return ft_printf("% +-3.3d", -8462);}
//Signed integers - space with field width and precision with zeropadding
int	 d_prec_width_ff_pos_zp_sp(void){return ft_printf("% 08.5d", 34);}
int	 d_prec_width_ff_neg_zp_sp(void){return ft_printf("% 010.5d", -216);}
int	 d_prec_width_ff_zero_zp_sp(void){return ft_printf("% 08.5d", 0);}
int	 d_prec_width_nf_pos_zp_sp(void){return ft_printf("% 08.3d", 8375);}
int	 d_prec_width_nf_neg_zp_sp(void){return ft_printf("% 08.3d", -8473);}
int	 d_prec_width_fn_pos_zp_sp(void){return ft_printf("% 03.7d", 3267);}
int	 d_prec_width_fn_neg_zp_sp(void){return ft_printf("% 03.7d", -2375);}
int	 d_prec_width_nn_pos_zp_sp(void){return ft_printf("% 03.3d", 6983);}
int	 d_prec_width_nn_neg_zp_sp(void){return ft_printf("% 03.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with zeropadding
int	 d_prec_width_ff_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.5d", 34);}
int	 d_prec_width_ff_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-10.5d", -216);}
int	 d_prec_width_ff_zero_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.5d", 0);}
int	 d_prec_width_nf_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljzpsp_ignoreflag(void){return ft_printf("% 0-3.3d", -8462);}
//Signed integers - space with field width and precision with allsign with zeropadding
int	 d_prec_width_ff_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+8.5d", 34);}
int	 d_prec_width_ff_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+10.5d", -216);}
int	 d_prec_width_ff_zero_aszpsp_ignoreflag(void){return ft_printf("% 0+8.5d", 0);}
int	 d_prec_width_nf_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+8.3d", 8375);}
int	 d_prec_width_nf_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+8.3d", -8473);}
int	 d_prec_width_fn_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+3.7d", 3267);}
int	 d_prec_width_fn_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+3.7d", -2375);}
int	 d_prec_width_nn_pos_aszpsp_ignoreflag(void){return ft_printf("% 0+3.3d", 6983);}
int	 d_prec_width_nn_neg_aszpsp_ignoreflag(void){return ft_printf("% 0+3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign with zeropadding
int	 d_prec_width_ff_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.5d", 34);}
int	 d_prec_width_ff_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-10.5d", -216);}
int	 d_prec_width_ff_zero_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.5d", 0);}
int	 d_prec_width_nf_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljaszpsp_ignoreflag(void){return ft_printf("% 0+-3.3d", -8462);}
//Signed integers - space of varying size modifiers
int	 d_size_hh_pos_casted_sp(void){return ft_printf("% hhd", (char)45);}
int	 d_size_hh_neg_casted_sp(void){return ft_printf("% hhd", (char)-45);}
int	 d_size_h_pos_casted_sp(void){return ft_printf("% hd", (short)385);}
int	 d_size_h_neg_casted_sp(void){return ft_printf("% hd", (short)-385);}
int	 d_size_l_pos_casted_sp(void){return ft_printf("% ld", (long)32);}
int	 d_size_l_neg_casted_sp(void){return ft_printf("% ld", (long)-32);}
int	 d_size_ll_pos_casted_sp(void){return ft_printf("% lld", (long long)43);}
int	 d_size_ll_neg_casted_sp(void){return ft_printf("% lld", (long long)-43);}
int	 d_size_hh_pos_ref_sp(void){return ft_printf("% hhd", ch_pos_1);}
int	 d_size_hh_neg_ref_sp(void){return ft_printf("% hhd", ch_neg_1);}
int	 d_size_h_pos_ref_sp(void){return ft_printf("% hd", sh_pos_1);}
int	 d_size_h_neg_ref_sp(void){return ft_printf("% hd", sh_neg_1);}
int	 d_size_l_pos_ref_sp(void){return ft_printf("% ld", l_pos_1);}
int	 d_size_l_neg_ref_sp(void){return ft_printf("% ld", l_neg_1);}
int	 d_size_ll_pos_ref_sp(void){return ft_printf("% lld", ll_pos_1);}
int	 d_size_ll_neg_ref_sp(void){return ft_printf("% lld", ll_neg_1);}
int	 d_size_l_pos_big_sp(void){return ft_printf("% ld", 22337203685477l);}
int	 d_size_l_neg_big_sp(void){return ft_printf("% ld", -22337203685477l);}
int	 d_size_ll_pos_big_sp(void){return ft_printf("% lld", 522337203685470ll);}
int	 d_size_ll_neg_big_sp(void){return ft_printf("% lld", -522337203685470ll);}
int	 d_llmax_sp(void){return ft_printf("% lld", 9223372036854775807ll);}
int	 d_llmin_sp(void){return ft_printf("% lld", llmin);}
int	 d_lmax_sp(void){return ft_printf("% ld", 9223372036854775807l);}
int	 d_lmin_sp(void){return ft_printf("% ld", lmin);}
int	 d_hmax_sp(void){return ft_printf("% hd", (short)32767);}
int	 d_hmin_sp(void){return ft_printf("% hd", (short)(-32768));}
int	 d_hhmax_sp(void){return ft_printf("% hhd", (char)(127));}
int	 d_hhmin_sp(void){return ft_printf("% hhd", (char)(-128));}
 //Signed integers - zero precision zero value
int d_prec0val0_basic(void){return ft_printf("%.0d", 0);}
int d_prec0val0_implicit(void){return ft_printf("%.d", 0);}
int d_prec0val0_w(void){return ft_printf("%5.0d", 0);}
int d_prec0val0_w_impl(void){return ft_printf("%5.d", 0);}
int d_prec0val0_wlj(void){return ft_printf("%-5.0d", 0);}
int d_prec0val0_wlj_impl(void){return ft_printf("%-5.d", 0);}
int d_prec0val0_as(void){return ft_printf("%+.0d", 0);}
int d_prec0val0_as_impl(void){return ft_printf("%+.d", 0);}
int d_prec0val0_was(void){return ft_printf("%+5.0d", 0);}
int d_prec0val0_was_impl(void){return ft_printf("%+5.d", 0);}
int d_prec0val0_waslj(void){return ft_printf("%+-5.0d", 0);}
int d_prec0val0_waslj_impl(void){return ft_printf("%+-5.d", 0);}

//Switching between string and signed integers of various sizes
static char	str_1[] = "hello world", str_2[] = "panda", str_3[] = "this is a longer string";
static char	str_empty[] = "";
int		mix_hhi_str_lli_str(void){return ft_printf("%hhi%s%lli%s", ch_pos_1, str_3, ll_neg_1, str_2);}
int		mix_str_hi_str_li(void){return ft_printf("%s%hi%s%li", str_1, sh_neg_1, str_3, l_neg_1);}
int		mix_str_hi_str_li_emptystr(void){return ft_printf("%s%hi%s%li", str_empty, sh_neg_1, str_3, l_neg_1);}

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
//Unsigned integers of varying size modifiers
static unsigned char 		uch_pos_1 = 100;
static unsigned short		ush_pos_1 = 3047;
static unsigned int		ui_pos_1 = 878023;
static unsigned long		ul_pos_1 = 22337203685477;
static unsigned long long	ull_pos_1 = 22337203685477;
static unsigned long long  ullmax = 9223372036854775807;
static unsigned long  		ulmax = 9223372036854775807;
int u_size_hh_pos_casted(void){return ft_printf("%hhu", (unsigned char)45);}
int u_size_h_pos_casted(void){return ft_printf("%hu", (unsigned short)385);}
int u_size_l_pos_casted(void){return ft_printf("%lu", (unsigned long)32);}
int u_size_ll_pos_casted(void){return ft_printf("%llu", (unsigned long long)43);}
int u_size_hh_pos_ref(void){return ft_printf("%hhu", uch_pos_1);}
int u_size_h_pos_ref(void){return ft_printf("%hu", ush_pos_1);}
int u_size_l_pos_ref(void){return ft_printf("%lu", ul_pos_1);}
int u_size_ll_pos_ref(void){return ft_printf("%llu", ull_pos_1);}
int u_size_l_pos_big(void){return ft_printf("%lu", 22337203685477ul);}
int u_size_ll_pos_big(void){return ft_printf("%llu", 522337203685470ull);}
int u_ullmax(void){return ft_printf("%llu", ullmax);}
int u_ulmax(void){return ft_printf("%lu", ulmax);}
int u_uhmax(void){return ft_printf("%hu", (unsigned short)65535);}
int u_uhhmax(void){return ft_printf("%hhu", (unsigned char)255);}
//Unsigned integers of varying size modifiers with some other modifiers
int u_size_l_pos_big_zp(void){return ft_printf("%037lu", 22337203685477ul);}
int u_size_ll_pos_big_width(void){return ft_printf("%37llu", 522337203685470ull);}
//Multiple unsigned integers in a row of varying sizes
int u_size_ll_hh_ll(void){return ft_printf("%llu%hhu%llu", ull_pos_1, uch_pos_1, ull_pos_1);}
int u_size_h_l_hh(void){return ft_printf("%hu%lu%hhu", ush_pos_1, ul_pos_1, uch_pos_1);}
int u_size_l_hh_h(void){return ft_printf("%lu%hhu%hu", ul_pos_1, uch_pos_1, ush_pos_1);}
int u_size_n_ll_hh(void){return ft_printf("%u%llu%hhu", ui_pos_1, ull_pos_1, uch_pos_1);}
int u_size_ll_n_l(void){return ft_printf("%llu%u%lu", ull_pos_1, ui_pos_1, ul_pos_1);}
//Unsigned integers - zero precision zero value
int u_prec0val0_basic(void){return ft_printf("%.0u", 0);}
int u_prec0val0_implicit(void){return ft_printf("%.u", 0);}
int u_prec0val0_w(void){return ft_printf("%5.0u", 0);}
int u_prec0val0_w_impl(void){return ft_printf("%5.u", 0);}
int u_prec0val0_wlj(void){return ft_printf("%-5.0u", 0);}
int u_prec0val0_wlj_impl(void){return ft_printf("%-5.u", 0);}

//Switching between string and unsigned integers of various sizes
int		mix_hhu_str_llu_str(void){return ft_printf("%hhu%s%llu%s", uch_pos_1, str_3, ull_pos_1, str_2);}
int		mix_str_hu_str_lu(void){return ft_printf("%s%hu%s%lu", str_1, ush_pos_1, str_3, ul_pos_1);}

//Mixing everything from all the tests so far
int		mixed_test_0001(void){return ft_printf(
		"%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li","abc",sh_neg_1,
		ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);}

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
//Hexadecimal lowers of varying size modifiers
int x_size_hh_pos_casted(void){return ft_printf("%hhx", (unsigned char)45);}
int x_size_h_pos_casted(void){return ft_printf("%hx", (unsigned short)385);}
int x_size_l_pos_casted(void){return ft_printf("%lx", (unsigned long)32);}
int x_size_ll_pos_casted(void){return ft_printf("%llx", (long long)43);}
int x_size_hh_pos_ref(void){return ft_printf("%hhx", uch_pos_1);}
int x_size_h_pos_ref(void){return ft_printf("%hx", ush_pos_1);}
int x_size_l_pos_ref(void){return ft_printf("%lx", ul_pos_1);}
int x_size_ll_pos_ref(void){return ft_printf("%llx", ull_pos_1);}
int x_size_l_pos_big(void){return ft_printf("%lx", 22337203685477ul);}
int x_size_ll_pos_big(void){return ft_printf("%llx", 522337203685470ull);}
int x_ullmax(void){return ft_printf("%llx", ullmax);}
int x_ulmax(void){return ft_printf("%lx", ulmax);}
int x_uhmax(void){return ft_printf("%hx", (unsigned short)65535);}
int x_uhhmax(void){return ft_printf("%hhx", (unsigned char)255);}
//Hexadecimal lowers of varying size modifiers with some other modifiers
int x_size_l_pos_big_zp(void){return ft_printf("%037lx", 22337203685477ul);}
int x_size_ll_pos_big_width(void){return ft_printf("%37llx", 522337203685470ull);}
//Multiple Hexadecimal lowers in a row of varying sizes
int x_size_ll_hh_ll(void){return ft_printf("%llu%hhu%llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int x_size_h_l_hh(void){return ft_printf("%hu%lu%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int x_size_l_hh_h(void){return ft_printf("%lu%hhu%hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int x_size_n_ll_hh(void){return ft_printf("%u%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int x_size_ll_n_l(void){return ft_printf("%llu%u%lx", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hexadecimal lower (altform) - no modifers
int		x_basic_pos_af(void){return ft_printf("this %#x number", 17);}
int		x_basic_zero_af(void){return ft_printf("this %#x number", 0);}
int		x_basic_onlypos_af(void){return ft_printf("%#x", 3);}
int x_hexlmax_af(void){return ft_printf("%#x", 4294967295u);}
//Hexadecimal lower (altform) with field width
int x_width_pos_fits_af(void){return ft_printf("%#7x", 33);}
int x_width_zero_fits_af(void){return ft_printf("%#3x", 0);}
int x_width_pos_exactfit_af(void){return ft_printf("%#5x", 52625);}
int x_width_pos_nofit_af(void){return ft_printf("%#2x", 94827);}
int x_width_pos_fits_lj_af(void){return ft_printf("%#-7x", 33);}
int x_width_zero_fits_lj_af(void){return ft_printf("%#-3x", 0);}
int x_width_pos_exactfit_lj_af(void){return ft_printf("%#-5x", 52625);}
int x_width_pos_nofit_lj_af(void){return ft_printf("%#-4x", 9648627);}
//Hexadecimal lower (altform) with precision
int x_prec_fits_pos_af(void){return ft_printf("%#.5x", 21);}
int x_prec_fits_zero_af(void){return ft_printf("%#.3x", 0);}
int x_prec_exactfit_pos_af(void){return ft_printf("%#.4x", 5263);}
int x_prec_nofit_pos_af(void){return ft_printf("%#.3x", 938862);}
//Hexadecimal lower (altform) with zero field width padding
int x_zp_pos_fits_af(void){return ft_printf("%#05x", 43);}
int x_zp_zero_fits_af(void){return ft_printf("%#03x", 0);}
int x_zp_pos_exactfit_af(void){return ft_printf("%#03x", 698334);}
//Hexadecimal lower (altform) with field width and precision
int x_prec_width_fit_fit_pos_af(void){return ft_printf("%#8.5x", 34);}
int x_prec_width_fit_fit_zero_af(void){return ft_printf("%#8.5x", 0);}
int x_prec_width_nofit_fit_pos_af(void){return ft_printf("%#8.3x", 8375);}
int x_prec_width_fit_nofit_pos_af(void){return ft_printf("%#2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_af(void){return ft_printf("%#3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified
int x_prec_width_fit_fit_pos_lj_af(void){return ft_printf("%#-8.5x", 34);}
int x_prec_width_fit_fit_zero_lj_af(void){return ft_printf("%#-8.5x", 0);}
int x_prec_width_nofit_fit_pos_lj_af(void){return ft_printf("%#-8.3x", 8375);}
int x_prec_width_fit_nofit_pos_lj_af(void){return ft_printf("%#-2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_lj_af(void){return ft_printf("%#-3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision with zeropadding
int x_prec_width_ff_pos_zp_af(void){return ft_printf("%#08.5x", 34);}
int x_prec_width_ff_zero_zp_af(void){return ft_printf("%#08.5x", 0);}
int x_prec_width_nf_pos_zp_af(void){return ft_printf("%#08.3x", 8375);}
int x_prec_width_fn_pos_zp_af(void){return ft_printf("%#02.7x", 3267);}
int x_prec_width_nn_pos_zp_af(void){return ft_printf("%#03.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified with zeropadding
int x_prec_width_ff_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.5x", 34);}
int x_prec_width_ff_zero_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.5x", 0);}
int x_prec_width_nf_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.3x", 8375);}
int x_prec_width_fn_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-2.7x", 3267);}
int x_prec_width_nn_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-3.3x", 6983);}
//Hexadecimal lower (altform) of varying size modifiers
int x_size_hh_pos_casted_af(void){return ft_printf("%#hhx", (unsigned char)45);}
int x_size_h_pos_casted_af(void){return ft_printf("%#hx", (unsigned short)385);}
int x_size_l_pos_casted_af(void){return ft_printf("%#lx", (unsigned long)32);}
int x_size_ll_pos_casted_af(void){return ft_printf("%#llx", (long long)43);}
int x_size_hh_pos_ref_af(void){return ft_printf("%#hhx", uch_pos_1);}
int x_size_h_pos_ref_af(void){return ft_printf("%#hx", ush_pos_1);}
int x_size_l_pos_ref_af(void){return ft_printf("%#lx", ul_pos_1);}
int x_size_ll_pos_ref_af(void){return ft_printf("%#llx", ull_pos_1);}
int x_size_l_pos_big_af(void){return ft_printf("%#lx", 22337203685477lu);}
int x_size_ll_pos_big_af(void){return ft_printf("%#llx", 522337203685470llu);}
int x_ullmax_af(void){return ft_printf("%#llx", ullmax);}
int x_ulmax_af(void){return ft_printf("%#lx", ulmax);}
int x_uhmax_af(void){return ft_printf("%#hx", (unsigned short)65535);}
int x_uhhmax_af(void){return ft_printf("%#hhx", (unsigned char)255);}
//Hexadecimal lower (altform) of varying size modifiers with some other modifiers
int x_size_l_pos_big_zp_af(void){return ft_printf("%#037lx", 22337203685477ul);}
int x_size_ll_pos_big_width_af(void){return ft_printf("%#37llx", 522337203685470ull);}
//Multiple Hexadecimal lower (altform) in a row of varying sizes
int x_size_ll_hh_ll_af(void){return ft_printf("%llu%hhu%#llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int x_size_h_l_hh_af(void){return ft_printf("%hu%#lx%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int x_size_l_hh_h_af(void){return ft_printf("%lu%hhu%#hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int x_size_n_ll_hh_af(void){return ft_printf("%#x%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int x_size_ll_n_l_af(void){return ft_printf("%llu%u%#lx", ull_pos_1, ui_pos_1, ul_pos_1);}
 //Hexadecimal lower - zero precision zero value
int x_prec0val0_basic(void){return ft_printf("%.0x", 0);}
int x_prec0val0_implicit(void){return ft_printf("%.x", 0);}
int x_prec0val0_w(void){return ft_printf("%5.0x", 0);}
int x_prec0val0_w_impl(void){return ft_printf("%5.x", 0);}
int x_prec0val0_wlj(void){return ft_printf("%-5.0x", 0);}
int x_prec0val0_wlj_impl(void){return ft_printf("%-5.x", 0);}
int x_prec0val0_af(void){return ft_printf("%#.0x", 0);}
int x_prec0val0_af_impl(void){return ft_printf("%#.x", 0);}
int x_prec0val0_waf(void){return ft_printf("%#5.0x", 0);}
int x_prec0val0_waf_impl(void){return ft_printf("%#5.x", 0);}
int x_prec0val0_waflj(void){return ft_printf("%#-5.0x", 0);}
int x_prec0val0_waflj_impl(void){return ft_printf("%#-5.x", 0);}


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
//Hexadecimal uppers of varying size modifiers
int X_size_hh_pos_casted(void){return ft_printf("%hhX", (unsigned char)45);}
int X_size_h_pos_casted(void){return ft_printf("%hX", (unsigned short)385);}
int X_size_l_pos_casted(void){return ft_printf("%lX", (unsigned long)32);}
int X_size_ll_pos_casted(void){return ft_printf("%llX", (long long)43);}
int X_size_hh_pos_ref(void){return ft_printf("%hhX", uch_pos_1);}
int X_size_h_pos_ref(void){return ft_printf("%hX", ush_pos_1);}
int X_size_l_pos_ref(void){return ft_printf("%lX", ul_pos_1);}
int X_size_ll_pos_ref(void){return ft_printf("%llX", ull_pos_1);}
int X_size_l_pos_big(void){return ft_printf("%lX", 22337203685477ul);}
int X_size_ll_pos_big(void){return ft_printf("%llX", 522337203685470ull);}
int X_ullmax(void){return ft_printf("%llX", ullmax);}
int X_ulmax(void){return ft_printf("%lX", ulmax);}
int X_uhmax(void){return ft_printf("%hX", (unsigned short)65535);}
int X_uhhmax(void){return ft_printf("%hhX", (unsigned char)255);}
//Hexadecimal uppers of varying size modifiers with some other modifiers
int X_size_l_pos_big_zp(void){return ft_printf("%037lX", 22337203685477ul);}
int X_size_ll_pos_big_width(void){return ft_printf("%37llX", 522337203685470ull);}
//Multiple Hexadecimal uppers in a row of varying sizes
int X_size_ll_hh_ll(void){return ft_printf("%llu%hhu%llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int X_size_h_l_hh(void){return ft_printf("%hu%lu%hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int X_size_l_hh_h(void){return ft_printf("%lu%hhu%hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int X_size_n_ll_hh(void){return ft_printf("%u%llu%hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int X_size_ll_n_l(void){return ft_printf("%llu%u%lX", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hex uppers (altform) - no modifers
int X_basic_hexu_pos_af(void){return ft_printf("this %#X number", 17);}
int X_basic_hexu_zero_af(void){return ft_printf("this %#X number", 0);}
int X_basic_hexu_onlypos_af(void){return ft_printf("%#X", 3);}
int X_hexumax_af(void){return ft_printf("%#X", 4294967295u);}
//Hex uppers (altform) with field width
int X_width_pos_fits_af(void){return ft_printf("%#7X", 33);}
int X_width_zero_fits_af(void){return ft_printf("%#3X", 0);}
int X_width_pos_exactfit_af(void){return ft_printf("%#7X", 52625);}
int X_width_pos_nofit_af(void){return ft_printf("%#2X", 94827);}
int X_width_pos_fits_lj_af(void){return ft_printf("%#-7X", 33);}
int X_width_zero_fits_lj_af(void){return ft_printf("%#-3X", 0);}
int X_width_pos_exactfit_lj_af(void){return ft_printf("%#-7X", 52625);}
int X_width_pos_nofit_lj_af(void){return ft_printf("%#-4X", 9648627);}
//Hex uppers (altform) with precision
int X_prec_fits_pos_af(void){return ft_printf("%#.5X", 21);}
int X_prec_fits_zero_af(void){return ft_printf("%#.3X", 0);}
int X_prec_exactfit_pos_af(void){return ft_printf("%#.4X", 5263);}
int X_prec_nofit_pos_af(void){return ft_printf("%#.3X", 938862);}
//Hex uppers (altform) with zero field width padding
int X_zp_pos_fits_af(void){return ft_printf("%#05X", 43);}
int X_zp_zero_fits_af(void){return ft_printf("%#03X", 0);}
int X_zp_pos_exactfit_af(void){return ft_printf("%#03X", 698334);}
//Hex uppers (altform) with field width and precision
int X_prec_width_fit_fit_pos_af(void){return ft_printf("%#8.5X", 34);}
int X_prec_width_fit_fit_zero_af(void){return ft_printf("%#8.5X", 0);}
int X_prec_width_nofit_fit_pos_af(void){return ft_printf("%#8.3X", 8375);}
int X_prec_width_fit_nofit_pos_af(void){return ft_printf("%#2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_af(void){return ft_printf("%#3.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified
int X_prec_width_fit_fit_pos_lj_af(void){return ft_printf("%#-8.5X", 34);}
int X_prec_width_fit_fit_zero_lj_af(void){return ft_printf("%#-8.5X", 0);}
int X_prec_width_nofit_fit_pos_lj_af(void){return ft_printf("%#-8.3X", 8375);}
int X_prec_width_fit_nofit_pos_lj_af(void){return ft_printf("%#-2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_lj_af(void){return ft_printf("%#-3.3X", 6983);}
//Hex uppers (altform) with field width and precision with zeropadding
int X_prec_width_ff_pos_zp_af(void){return ft_printf("%#08.5X", 34);}
int X_prec_width_ff_zero_zp_af(void){return ft_printf("%#08.5X", 0);}
int X_prec_width_nf_pos_zp_af(void){return ft_printf("%#08.3X", 8375);}
int X_prec_width_fn_pos_zp_af(void){return ft_printf("%#02.7X", 3267);}
int X_prec_width_nn_pos_zp_af(void){return ft_printf("%#03.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified with zeropadding
int X_prec_width_ff_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.5X", 34);}
int X_prec_width_ff_zero_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.5X", 0);}
int X_prec_width_nf_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.3X", 8375);}
int X_prec_width_fn_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-2.7X", 3267);}
int X_prec_width_nn_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-3.3X", 6983);}
//Hex uppers (altform) of varying size modifiers
int X_size_hh_pos_casted_af(void){return ft_printf("%#hhX", (unsigned char)45);}
int X_size_h_pos_casted_af(void){return ft_printf("%#hX", (unsigned short)385);}
int X_size_l_pos_casted_af(void){return ft_printf("%#lX", (unsigned long)32);}
int X_size_ll_pos_casted_af(void){return ft_printf("%#llX", (long long)43);}
int X_size_hh_pos_ref_af(void){return ft_printf("%#hhX", uch_pos_1);}
int X_size_h_pos_ref_af(void){return ft_printf("%#hX", ush_pos_1);}
int X_size_l_pos_ref_af(void){return ft_printf("%#lX", ul_pos_1);}
int X_size_ll_pos_ref_af(void){return ft_printf("%#llX", ull_pos_1);}
int X_size_l_pos_big_af(void){return ft_printf("%#lX", 22337203685477ul);}
int X_size_ll_pos_big_af(void){return ft_printf("%#llX", 522337203685470ull);}
int X_ullmax_af(void){return ft_printf("%#llX", ullmax);}
int X_ulmax_af(void){return ft_printf("%#lX", ulmax);}
int X_uhmax_af(void){return ft_printf("%#hX", (unsigned short)65535);}
int X_uhhmax_af(void){return ft_printf("%#hhX", (unsigned char)255);}
//Hex uppers (altform) of varying size modifiers with some other modifiers
int X_size_l_pos_big_zp_af(void){return ft_printf("%#037lX", 22337203685477ul);}
int X_size_ll_pos_big_width_af(void){return ft_printf("%#37llX", 522337203685470ull);}
//Multiple Hex uppers (altform) in a row of varying sizes
int X_size_ll_hh_ll_af(void){return ft_printf("%llu%hhu%#llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int X_size_h_l_hh_af(void){return ft_printf("%#hx%lu%#hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int X_size_l_hh_h_af(void){return ft_printf("%lu%hhu%#hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int X_size_n_ll_hh_af(void){return ft_printf("%#x%llu%#hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int X_size_ll_n_l_af(void){return ft_printf("%#llx%u%#lX", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hexadecimal uppers - zero precision zero value
int X_prec0val0_basic(void){return ft_printf("%.0X", 0);}
int X_prec0val0_implicit(void){return ft_printf("%.X", 0);}
int X_prec0val0_w(void){return ft_printf("%5.0X", 0);}
int X_prec0val0_w_impl(void){return ft_printf("%5.X", 0);}
int X_prec0val0_wlj(void){return ft_printf("%-5.0X", 0);}
int X_prec0val0_wlj_impl(void){return ft_printf("%-5.X", 0);}
int X_prec0val0_af(void){return ft_printf("%#.0X", 0);}
int X_prec0val0_af_impl(void){return ft_printf("%#.X", 0);}
int X_prec0val0_waf(void){return ft_printf("%#5.0X", 0);}
int X_prec0val0_waf_impl(void){return ft_printf("%#5.X", 0);}
int X_prec0val0_waflj(void){return ft_printf("%#-5.0X", 0);}
int X_prec0val0_waflj_impl(void){return ft_printf("%#-5.X", 0);}


//Octals - no modifers
int o_basic_octl_pos(void){return ft_printf("this %o number", 17);}
int o_basic_octl_zero(void){return ft_printf("this %o number", 0);}
int o_basic_octl_onlypos(void){return ft_printf("%o", 3);}
int o_octlmax(void){return ft_printf("%o", 4294967295u);}
//Octals with field width
int o_width_pos_fits(void){return ft_printf("%7o", 33);}
int o_width_zero_fits(void){return ft_printf("%3o", 0);}
int o_width_pos_exactfit(void){return ft_printf("%6o", 52625);}
int o_width_pos_nofit(void){return ft_printf("%2o", 94827);}
int o_width_pos_fits_lj(void){return ft_printf("%-7o", 33);}
int o_width_zero_fits_lj(void){return ft_printf("%-3o", 0);}
int o_width_pos_exactfit_lj(void){return ft_printf("%-6o", 52625);}
int o_width_pos_nofit_lj(void){return ft_printf("%-4o", 9648627);}
//Octals with precision
int o_prec_fits_pos(void){return ft_printf("%.5o", 21);}
int o_prec_fits_zero(void){return ft_printf("%.3o", 0);}
int o_prec_exactfit_pos(void){return ft_printf("%.5o", 5263);}
int o_prec_nofit_pos(void){return ft_printf("%.3o", 938862);}
//Octals with zero field width padding
int o_zp_pos_fits(void){return ft_printf("%05o", 43);}
int o_zp_zero_fits(void){return ft_printf("%03o", 0);}
int o_zp_pos_exactfit(void){return ft_printf("%07o", 698334);}
//Octals with field width and precision
int o_prec_width_fit_fit_pos(void){return ft_printf("%8.5o", 34);}
int o_prec_width_fit_fit_zero(void){return ft_printf("%8.5o", 0);}
int o_prec_width_nofit_fit_pos(void){return ft_printf("%8.3o", 8375);}
int o_prec_width_fit_nofit_pos(void){return ft_printf("%2.7o", 3267);}
int o_prec_width_nofit_nofit_pos(void){return ft_printf("%3.3o", 6983);}
//Octals with field width and precision, left-justified
int o_prec_width_fit_fit_pos_lj(void){return ft_printf("%-8.5o", 34);}
int o_prec_width_fit_fit_zero_lj(void){return ft_printf("%-8.5o", 0);}
int o_prec_width_nofit_fit_pos_lj(void){return ft_printf("%-8.3o", 8375);}
int o_prec_width_fit_nofit_pos_lj(void){return ft_printf("%-2.7o", 3267);}
int o_prec_width_nofit_nofit_pos_lj(void){return ft_printf("%-3.3o", 6983);}
//Octals with field width and precision with zeropadding
int o_prec_width_ff_pos_zp(void){return ft_printf("%08.5o", 34);}
int o_prec_width_ff_zero_zp(void){return ft_printf("%08.5o", 0);}
int o_prec_width_nf_pos_zp(void){return ft_printf("%08.3o", 8375);}
int o_prec_width_fn_pos_zp(void){return ft_printf("%02.7o", 3267);}
int o_prec_width_nn_pos_zp(void){return ft_printf("%03.3o", 6983);}
//Octals with field width and precision, left-justified with zeropadding
int o_prec_width_ff_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.5o", 34);}
int o_prec_width_ff_zero_ljzp_ignoreflag(void){return ft_printf("%0-8.5o", 0);}
int o_prec_width_nf_pos_ljzp_ignoreflag(void){return ft_printf("%0-8.3o", 8375);}
int o_prec_width_fn_pos_ljzp_ignoreflag(void){return ft_printf("%0-2.7o", 3267);}
int o_prec_width_nn_pos_ljzp_ignoreflag(void){return ft_printf("%0-3.3o", 6983);}
//Octals of varying size modifiers
int o_size_hh_pos_casted(void){return ft_printf("%hho", (unsigned char)45);}
int o_size_h_pos_casted(void){return ft_printf("%ho", (unsigned short)385);}
int o_size_l_pos_casted(void){return ft_printf("%lo", (unsigned long)32);}
int o_size_ll_pos_casted(void){return ft_printf("%llo", (long long)43);}
int o_size_hh_pos_ref(void){return ft_printf("%hho", uch_pos_1);}
int o_size_h_pos_ref(void){return ft_printf("%ho", ush_pos_1);}
int o_size_l_pos_ref(void){return ft_printf("%lo", ul_pos_1);}
int o_size_ll_pos_ref(void){return ft_printf("%llo", ull_pos_1);}
int o_size_l_pos_big(void){return ft_printf("%lo", 22337203685477ul);}
int o_size_ll_pos_big(void){return ft_printf("%llo", 522337203685470ull);}
int o_ullmax(void){return ft_printf("%llo", ullmax);}
int o_ulmax(void){return ft_printf("%lo", ulmax);}
int o_uhmax(void){return ft_printf("%ho", (unsigned short)65535);}
int o_uhhmax(void){return ft_printf("%hho", (unsigned char)255);}
//Octals of varying size modifiers with some other modifiers
int o_size_l_pos_big_zp(void){return ft_printf("%037lo", 22337203685477ul);}
int o_size_ll_pos_big_width(void){return ft_printf("%37llo", 522337203685470ull);}
//Multiple Octals in a row of varying sizes
int o_size_ll_hh_ll(void){return ft_printf("%llu%hhu%llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int o_size_h_l_hh(void){return ft_printf("%hu%lu%hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int o_size_l_hh_h(void){return ft_printf("%lu%hhu%ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int o_size_n_ll_hh(void){return ft_printf("%u%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int o_size_ll_n_l(void){return ft_printf("%llu%u%lo", ull_pos_1, ui_pos_1, ul_pos_1);}
//Octal (Altform)s - no modifers
int o_basic_octl_pos_af(void){return ft_printf("this %#o number", 17);}
int o_basic_octl_zero_af(void){return ft_printf("this %#o number", 0);}
int o_basic_octl_onlypos_af(void){return ft_printf("%#o", 3);}
int o_octlmax_af(void){return ft_printf("%#o", 4294967295u);}
//Octal (Altform)s with field width
int o_width_pos_fits_af(void){return ft_printf("%#7o", 33);}
int o_width_zero_fits_af(void){return ft_printf("%#3o", 0);}
int o_width_pos_exactfit_af(void){return ft_printf("%#6o", 52625);}
int o_width_pos_nofit_af(void){return ft_printf("%#2o", 94827);}
int o_width_pos_fits_lj_af(void){return ft_printf("%#-7o", 33);}
int o_width_zero_fits_lj_af(void){return ft_printf("%#-3o", 0);}
int o_width_pos_exactfit_lj_af(void){return ft_printf("%#-6o", 52625);}
int o_width_pos_nofit_lj_af(void){return ft_printf("%#-4o", 9648627);}
//Octal (Altform)s with precision
int o_prec_fits_pos_af(void){return ft_printf("%#.5o", 21);}
int o_prec_fits_zero_af(void){return ft_printf("%#.3o", 0);}
int o_prec_exactfit_pos_af(void){return ft_printf("%#.5o", 5263);}
int o_prec_nofit_pos_af(void){return ft_printf("%#.3o", 938862);}
//Octal (Altform)s with zero field width padding
int o_zp_pos_fits_af(void){return ft_printf("%#05o", 43);}
int o_zp_zero_fits_af(void){return ft_printf("%#03o", 0);}
int o_zp_pos_exactfit_af(void){return ft_printf("%#07o", 698334);}
//Octal (Altform)s with field width and precision
int o_prec_width_fit_fit_pos_af(void){return ft_printf("%#8.5o", 34);}
int o_prec_width_fit_fit_zero_af(void){return ft_printf("%#8.5o", 0);}
int o_prec_width_nofit_fit_pos_af(void){return ft_printf("%#8.3o", 8375);}
int o_prec_width_fit_nofit_pos_af(void){return ft_printf("%#2.7o", 3267);}
int o_prec_width_nofit_nofit_pos_af(void){return ft_printf("%#3.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified
int o_prec_width_fit_fit_pos_lj_af(void){return ft_printf("%#-8.5o", 34);}
int o_prec_width_fit_fit_zero_lj_af(void){return ft_printf("%#-8.5o", 0);}
int o_prec_width_nofit_fit_pos_lj_af(void){return ft_printf("%#-8.3o", 8375);}
int o_prec_width_fit_nofit_pos_lj_af(void){return ft_printf("%#-2.7o", 3267);}
int o_prec_width_nofit_nofit_pos_lj_af(void){return ft_printf("%#-3.3o", 6983);}
//Octal (Altform)s with field width and precision with zeropadding
int o_prec_width_ff_pos_zp_af(void){return ft_printf("%#08.5o", 34);}
int o_prec_width_ff_zero_zp_af(void){return ft_printf("%#08.5o", 0);}
int o_prec_width_nf_pos_zp_af(void){return ft_printf("%#08.3o", 8375);}
int o_prec_width_fn_pos_zp_af(void){return ft_printf("%#02.7o", 3267);}
int o_prec_width_nn_pos_zp_af(void){return ft_printf("%#03.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified with zeropadding
int o_prec_width_ff_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.5o", 34);}
int o_prec_width_ff_zero_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.5o", 0);}
int o_prec_width_nf_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-8.3o", 8375);}
int o_prec_width_fn_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-2.7o", 3267);}
int o_prec_width_nn_pos_ljzpaf_ignoreflag(void){return ft_printf("%#0-3.3o", 6983);}
//Octal (Altform)s of varying size modifiers
int o_size_hh_pos_casted_af(void){return ft_printf("%#hho", (unsigned char)45);}
int o_size_h_pos_casted_af(void){return ft_printf("%#ho", (unsigned short)385);}
int o_size_l_pos_casted_af(void){return ft_printf("%#lo", (unsigned long)32);}
int o_size_ll_pos_casted_af(void){return ft_printf("%#llo", (long long)43);}
int o_size_hh_pos_ref_af(void){return ft_printf("%#hho", uch_pos_1);}
int o_size_h_pos_ref_af(void){return ft_printf("%#ho", ush_pos_1);}
int o_size_l_pos_ref_af(void){return ft_printf("%#lo", ul_pos_1);}
int o_size_ll_pos_ref_af(void){return ft_printf("%#llo", ull_pos_1);}
int o_size_l_pos_big_af(void){return ft_printf("%#lo", 22337203685477ul);}
int o_size_ll_pos_big_af(void){return ft_printf("%#llo", 522337203685470ull);}
int o_ullmax_af(void){return ft_printf("%#llo", ullmax);}
int o_ulmax_af(void){return ft_printf("%#lo", ulmax);}
int o_uhmax_af(void){return ft_printf("%#ho", (unsigned short)65535);}
int o_uhhmax_af(void){return ft_printf("%#hho", (unsigned char)255);}
//Octal (Altform)s of varying size modifiers with some other modifiers
int o_size_l_pos_big_zp_af(void){return ft_printf("%#037lo", 22337203685477ul);}
int o_size_ll_pos_big_width_af(void){return ft_printf("%#37llo", 522337203685470ull);}
//Multiple Octal (Altform)s in a row of varying sizes
int o_size_ll_hh_ll_af(void){return ft_printf("%llu%hhu%#llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int o_size_h_l_hh_af(void){return ft_printf("%hu%lu%#hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int o_size_l_hh_h_af(void){return ft_printf("%#lo%hhu%#ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int o_size_n_ll_hh_af(void){return ft_printf("%#o%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int o_size_ll_n_l_af(void){return ft_printf("%#llo%u%#lo", ull_pos_1, ui_pos_1, ul_pos_1);}
//Octals - zero precision zero value
int o_prec0val0_basic(void){return ft_printf("%.0o", 0);}
int o_prec0val0_implicit(void){return ft_printf("%.o", 0);}
int o_prec0val0_w(void){return ft_printf("%5.0o", 0);}
int o_prec0val0_w_impl(void){return ft_printf("%5.o", 0);}
int o_prec0val0_wlj(void){return ft_printf("%-5.0o", 0);}
int o_prec0val0_wlj_impl(void){return ft_printf("%-5.o", 0);}
int o_prec0val0_af(void){return ft_printf("%#.0o", 0);}
int o_prec0val0_af_impl(void){return ft_printf("%#.o", 0);}
int o_prec0val0_waf(void){return ft_printf("%#5.0o", 0);}
int o_prec0val0_waf_impl(void){return ft_printf("%#5.o", 0);}
int o_prec0val0_waflj(void){return ft_printf("%#-5.0o", 0);}
int o_prec0val0_waflj_impl(void){return ft_printf("%#-5.o", 0);}


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








//Floats - Basic
int f_basic_1(void){return ft_printf("this %f float", 1.5);}
int f_basic_fltonly(void){return ft_printf("%f", 7.5);}
int f_basic_whole(void){return ft_printf("%f", 1.0);}
int f_basic_negative(void){return ft_printf("%f", -3.85);}
int f_basic_positive_3_3(void){return ft_printf("%f", 573.924);}
int f_basic_negative_3_3(void){return ft_printf("%f", -958.125);}
int f_basic_positive_smallfpart(void){return ft_printf("%f", 23.00041);}
int f_basic_positive_allsmall(void){return ft_printf("%f", 0.000039);}
int f_basic_negative_smallfpart(void){return ft_printf("%f", -7.00036);}
int f_basic_negative_allsmall(void){return ft_printf("%f", -0.00032);}
int f_basic_limits_allsmall_pos(void){return ft_printf("%f", 0.000001);}
int f_basic_limits_allsmall_neg(void){return ft_printf("%f", -0.000001);}
int f_basic_limits_smallfpart_pos(void){return ft_printf("%f", 9873.000001);}
int f_basic_limits_smallfpart_neg(void){return ft_printf("%f", -875.000001);}
int f_basic_limits_allbig_pos(void){return ft_printf("%f", 999.999999);}
int f_basic_limits_allbig_neg(void){return ft_printf("%f", -99.999999);}
int f_basic_limits_bigfpart_pos(void){return ft_printf("%f", 0.999999);}
int f_basic_limits_bigfpart_neg(void){return ft_printf("%f", -0.999999);}
//Floats - Rounding with default precision
int f_rndd_pos(void){return ft_printf("%f", 23.375094499);}
int f_rndd_neg(void){return ft_printf("%f", -985.765426499);}
int f_rndu_pos(void){return ft_printf("%f", 0.0894255);}
int f_rndu_neg(void){return ft_printf("%f", -56.2012685);}
int f_rndu_multidigit_pos(void){return ft_printf("%f", 43.4399999);}
int f_rndu_multidigit_neg(void){return ft_printf("%f", -5.0299999);}
int f_rndd_multidigit_pos(void){return ft_printf("%f", 43.43999949);}
int f_rndd_multidigit_neg(void){return ft_printf("%f", -5.02999949);}
int f_rndd_wholnobump_pos(void){return ft_printf("%f", 1.99999949);}
int f_rndd_wholnobump_neg(void){return ft_printf("%f", -0.99999949);}
int f_rndu_bumpwhole_pos(void){return ft_printf("%f", 3.9999999);}
int f_rndu_bumpwhole_neg(void){return ft_printf("%f", -5.9999999);}
//Floats Prec 0
int f_prec0_1(void){return ft_printf("this %.0f float", 1.6);}
int f_prec0_fltonly(void){return ft_printf("%.0f", 7.4);}
int f_prec0_whole(void){return ft_printf("%.0f", 1.0);}
int f_prec0_negative(void){return ft_printf("%.0f", -3.85);}
int f_prec0_positive_3_3(void){return ft_printf("%.0f", 573.924);}
int f_prec0_negative_3_3(void){return ft_printf("%.0f", -958.125);}
int f_prec0_positive_smallfpart(void){return ft_printf("%.0f", 23.00041);}
int f_prec0_positive_allsmall(void){return ft_printf("%.0f", 0.000039);}
int f_prec0_negative_smallfpart(void){return ft_printf("%.0f", -7.00036);}
int f_prec0_negative_allsmall(void){return ft_printf("%.0f", -0.00032);}
//Floats Prec 1
int f_prec1_1(void){return ft_printf("this %.1f float", 1.5);}
int f_prec1_fltonly(void){return ft_printf("%.1f", 7.5);}
int f_prec1_whole(void){return ft_printf("%.1f", 1.0);}
int f_prec1_negative(void){return ft_printf("%.1f", -3.85);}
int f_prec1_positive_3_3(void){return ft_printf("%.1f", 573.924);}
int f_prec1_negative_3_3(void){return ft_printf("%.1f", -958.125);}
int f_prec1_positive_smallfpart(void){return ft_printf("%.1f", 23.00041);}
int f_prec1_positive_allsmall(void){return ft_printf("%.1f", 0.000039);}
int f_prec1_negative_smallfpart(void){return ft_printf("%.1f", -7.00036);}
int f_prec1_negative_allsmall(void){return ft_printf("%.1f", -0.00032);}
//Floats Prec 3
int f_prec3_1(void){return ft_printf("this %.3f float", 1.5);}
int f_prec3_fltonly(void){return ft_printf("%.3f", 7.5);}
int f_prec3_whole(void){return ft_printf("%.3f", 1.0);}
int f_prec3_negative(void){return ft_printf("%.3f", -3.85);}
int f_prec3_positive_3_3(void){return ft_printf("%.3f", 573.924);}
int f_prec3_negative_3_3(void){return ft_printf("%.3f", -958.125);}
int f_prec3_positive_smallfpart(void){return ft_printf("%.3f", 23.00041);}
int f_prec3_positive_allsmall(void){return ft_printf("%.3f", 0.000039);}
int f_prec3_negative_smallfpart(void){return ft_printf("%.3f", -7.00036);}
int f_prec3_negative_allsmall(void){return ft_printf("%.3f", -0.00032);}
//Floats - Prec 7
int f_prec7_1(void){return ft_printf("this %.7f float", 1.5);}
int f_prec7_fltonly(void){return ft_printf("%.7f", 7.5);}
int f_prec7_whole(void){return ft_printf("%.7f", 1.0);}
int f_prec7_negative(void){return ft_printf("%.7f", -3.85);}
int f_prec7_positive_3_3(void){return ft_printf("%.7f", 573.924);}
int f_prec7_negative_3_3(void){return ft_printf("%.7f", -958.125);}
int f_prec7_positive_smallfpart(void){return ft_printf("%.7f", 23.00041);}
int f_prec7_positive_allsmall(void){return ft_printf("%.7f", 0.0000039);}
int f_prec7_negative_smallfpart(void){return ft_printf("%.7f", -7.00036);}
int f_prec7_negative_allsmall(void){return ft_printf("%.7f", -0.000032);}
int f_prec7_limits_allsmall_pos(void){return ft_printf("%.7f", 0.0000001);}
int f_prec7_limits_allsmall_neg(void){return ft_printf("%.7f", -0.0000001);}
int f_prec7_limits_smallfpart_pos(void){return ft_printf("%.7f", 9873.000001);}
int f_prec7_limits_smallfpart_neg(void){return ft_printf("%.7f", -875.000001);}
int f_prec7_limits_allbig_pos(void){return ft_printf("%.7f", 999.9999999);}
int f_prec7_limits_allbig_neg(void){return ft_printf("%.7f", -99.9999999);}
int f_prec7_limits_bigfpart_pos(void){return ft_printf("%.7f", 0.999999);}
int f_prec7_limits_bigfpart_neg(void){return ft_printf("%.7f", -0.999999);}
//Floats - Prec 7 Rounding
int f_rnd_prec7_rndd_pos(void){return ft_printf("%.7f", 23.375094499);}
int f_rnd_prec7_rndd_neg(void){return ft_printf("%.7f", -985.765426499);}
int f_rnd_prec7_rndu_pos(void){return ft_printf("%.7f", 0.0894255);}
int f_rnd_prec7_rndu_neg(void){return ft_printf("%.7f", -56.2012685);}
int f_rnd_prec7_rndu_multidigit_pos(void){return ft_printf("%.7f", 43.4399999);}
int f_rnd_prec7_rndu_multidigit_neg(void){return ft_printf("%.7f", -5.0299999);}
int f_rnd_prec7_rndd_multidigit_pos(void){return ft_printf("%.7f", 43.43999949);}
int f_rnd_prec7_rndd_multidigit_neg(void){return ft_printf("%.7f", -5.02999949);}
int f_rnd_prec7_rndd_wholnobump_pos(void){return ft_printf("%.7f", 1.99999949);}
int f_rnd_prec7_rndd_wholnobump_neg(void){return ft_printf("%.7f", -0.99999949);}
int f_rnd_prec7_rndu_bumpwhole_pos(void){return ft_printf("%.7f", 3.9999999);}
//Floats - Prec 8
int f_prec8_1(void){return ft_printf("this %.8f float", 1.5);}
int f_prec8_fltonly(void){return ft_printf("%.8f", 7.5);}
int f_prec8_whole(void){return ft_printf("%.8f", 1.0);}
int f_prec8_negative(void){return ft_printf("%.8f", -3.85);}
int f_prec8_positive_3_3(void){return ft_printf("%.8f", 573.924);}
int f_prec8_negative_3_3(void){return ft_printf("%.8f", -958.125);}
int f_prec8_positive_smallfpart(void){return ft_printf("%.8f", 23.00041);}
int f_prec8_positive_allsmall(void){return ft_printf("%.8f", 0.00000039);}
int f_prec8_negative_smallfpart(void){return ft_printf("%.8f", -7.00036);}
int f_prec8_negative_allsmall(void){return ft_printf("%.8f", -0.0000032);}
int f_prec8_limits_allsmall_pos(void){return ft_printf("%.8f", 0.00000001);}
int f_prec8_limits_allsmall_neg(void){return ft_printf("%.8f", -0.00000001);}
int f_prec8_limits_smallfpart_pos(void){return ft_printf("%.8f", 9873.000001);}
int f_prec8_limits_smallfpart_neg(void){return ft_printf("%.8f", -875.000001);}
int f_prec8_limits_allbig_pos(void){return ft_printf("%.8f", 999.9999999);}
int f_prec8_limits_allbig_neg(void){return ft_printf("%.8f", -99.99999999);}
int f_prec8_limits_bigfpart_pos(void){return ft_printf("%.8f", 0.999999);}
int f_prec8_limits_bigfpart_neg(void){return ft_printf("%.8f", -0.999999);}
//Floats - Prec 8 Rounding
int f_rnd_prec8_rndd_pos(void){return ft_printf("%.8f", 23.375094499);}
int f_rnd_prec8_rndd_neg(void){return ft_printf("%.8f", -985.765426499);}
int f_rnd_prec8_rndu_pos(void){return ft_printf("%.8f", 0.0894255);}
int f_rnd_prec8_rndu_neg(void){return ft_printf("%.8f", -56.2012685);}
int f_rnd_prec8_rndu_multidigit_pos(void){return ft_printf("%.8f", 43.4399999);}
int f_rnd_prec8_rndu_multidigit_neg(void){return ft_printf("%.8f", -5.0299999);}
int f_rnd_prec8_rndd_multidigit_pos(void){return ft_printf("%.8f", 43.43999949);}
int f_rnd_prec8_rndd_multidigit_neg(void){return ft_printf("%.8f", -5.02999949);}
int f_rnd_prec8_rndd_wholnobump_pos(void){return ft_printf("%.8f", 1.99999949);}
int f_rnd_prec8_rndd_wholnobump_neg(void){return ft_printf("%.8f", -0.99999949);}
int f_rnd_prec8_rndu_bumpwhole_pos(void){return ft_printf("%.8f", 3.9999999);}
//Floats - Prec 9
int f_stress_prec9_1(void){return ft_printf("this %.9f float", 1.5);}
int f_stress_prec9_fltonly(void){return ft_printf("%.9f", 7.5);}
int f_stress_prec9_whole(void){return ft_printf("%.9f", 1.0);}
int f_stress_prec9_negative(void){return ft_printf("%.9f", -3.85);}
int f_stress_prec9_positive_3_3(void){return ft_printf("%.9f", 573.924);}
int f_stress_prec9_negative_3_3(void){return ft_printf("%.9f", -958.125);}
int f_stress_prec9_positive_smallfpart(void){return ft_printf("%.9f", 23.00041);}
int f_stress_prec9_positive_allsmall(void){return ft_printf("%.9f", 0.00000039);}
int f_stress_prec9_negative_smallfpart(void){return ft_printf("%.9f", -7.00036);}
int f_stress_prec9_negative_allsmall(void){return ft_printf("%.9f", -0.0000032);}
int f_stress_prec9_limits_allsmall_pos(void){return ft_printf("%.9f", 0.00000001);}
int f_stress_prec9_limits_allsmall_neg(void){return ft_printf("%.9f", -0.00000001);}
int f_stress_prec9_limits_smallfpart_pos(void){return ft_printf("%.9f", 9873.000001);}
int f_stress_prec9_limits_smallfpart_neg(void){return ft_printf("%.9f", -875.000001);}
int f_stress_prec9_limits_allbig_pos(void){return ft_printf("%.9f", 999.99999999);}
int f_stress_prec9_limits_allbig_neg(void){return ft_printf("%.9f", -99.99999999);}
int f_stress_prec9_limits_bigfpart_pos(void){return ft_printf("%.9f", 0.999999);}
int f_stress_prec9_limits_bigfpart_neg(void){return ft_printf("%.9f", -0.999999);}
//Floats - Prec 9 Rounding
int f_stress_prec9_rndd_pos(void){return ft_printf("%.9f", 23.375094499);}
int f_stress_prec9_rndd_neg(void){return ft_printf("%.9f", -985.765426499);}
int f_stress_prec9_rndu_pos(void){return ft_printf("%.9f", 0.0894255);}
int f_stress_prec9_rndu_neg(void){return ft_printf("%.9f", -56.2012685);}
int f_stress_prec9_rndu_multidigit_pos(void){return ft_printf("%.9f", 43.4399999);}
int f_stress_prec9_rndu_multidigit_neg(void){return ft_printf("%.9f", -5.0299999);}
int f_stress_prec9_rndd_multidigit_pos(void){return ft_printf("%.9f", 43.43999949);}
int f_stress_prec9_rndd_multidigit_neg(void){return ft_printf("%.9f", -5.02999949);}
int f_stress_prec9_rndd_wholnobump_pos(void){return ft_printf("%.9f", 1.99999949);}
int f_stress_prec9_rndd_wholnobump_neg(void){return ft_printf("%.9f", -0.99999949);}
int f_stress_prec9_rndu_bumpwhole_pos(void){return ft_printf("%.9f", 3.9999999);}
//Floats - Prec 10
int f_stress_prec10_1(void){return ft_printf("this %.10f float", 1.5);}
int f_stress_prec10_fltonly(void){return ft_printf("%.10f", 7.5);}
int f_stress_prec10_whole(void){return ft_printf("%.10f", 1.0);}
int f_stress_prec10_negative(void){return ft_printf("%.10f", -3.85);}
int f_stress_prec10_positive_3_10(void){return ft_printf("%.10f", 573.924);}
int f_stress_prec10_negative_3_10(void){return ft_printf("%.10f", -958.125);}
int f_stress_prec10_pos(void){return ft_printf("%.10f", 23.8341375094);}
int f_stress_prec10_neg(void){return ft_printf("%.10f", -985.2459765426);}
int f_stress_prec10_rndd_pos(void){return ft_printf("%.10f", 23.8341375094499);}
int f_stress_prec10_rndd_neg(void){return ft_printf("%.10f", -985.2459765426499);}
int f_stress_prec10_rndu_pos(void){return ft_printf("%.10f", 0.87650894255);}
int f_stress_prec10_rndu_neg(void){return ft_printf("%.10f", -56.47852012685);}
int f_stress_prec10_positive_smallfpart(void){return ft_printf("%.10f", 23.000000041);}
int f_stress_prec10_positive_allsmall(void){return ft_printf("%.10f", 0.0000000039);}
int f_stress_prec10_negative_smallfpart(void){return ft_printf("%.10f", -7.000000036);}
int f_stress_prec10_negative_allsmall(void){return ft_printf("%.10f", -0.000000032);}
int f_stress_prec10_limits_allsmall_pos(void){return ft_printf("%.10f", 0.0000000001);}
int f_stress_prec10_limits_allsmall_neg(void){return ft_printf("%.10f", -0.0000000001);}
int f_stress_prec10_limits_smallfpart_pos(void){return ft_printf("%.10f", 9873.0000000001);}
int f_stress_prec10_limits_smallfpart_neg(void){return ft_printf("%.10f", -875.0000000001);}
int f_stress_prec10_limits_allbig_pos(void){return ft_printf("%.10f", 999.9999999999);}
int f_stress_prec10_limits_allbig_neg(void){return ft_printf("%.10f", -99.9999999999);}
int f_stress_prec10_limits_bigfpart_pos(void){return ft_printf("%.10f", 0.9999999999);}
int f_stress_prec10_limits_bigfpart_neg(void){return ft_printf("%.10f", -0.9999999999);}
//Floats - Prec 11
int f_stress_prec11_rndu(void){return ft_printf("%.11f",        1.025978541236587568);}
int f_stress_prec11_rndd(void){return ft_printf("%.11f",        1.025978548534310421);}
int f_stress_prec11_limits_tiny(void){return ft_printf("%.11f", 0.000000000010000000);}
int f_stress_prec11_limits_big(void){return ft_printf("%.11f", 99.999999999990000000);}
//Floats - Prec 12
int f_stress_prec12_rndu(void){return ft_printf("%.12f",        1.025978541236587568);}
int f_stress_prec12_rndd(void){return ft_printf("%.12f",        1.025978548534310421);}
int f_stress_prec12_limits_tiny(void){return ft_printf("%.12f", 0.000000000001000000);}
int f_stress_prec12_limits_big(void){return ft_printf("%.12f", 99.999999999999000000);}
//Floats - Prec 13
int f_stress_prec13_rndu(void){return ft_printf("%.13f",        1.025978541136587568);}
int f_stress_prec13_rndd(void){return ft_printf("%.13f",        1.025978548534310421);}
int f_stress_prec13_limits_tiny(void){return ft_printf("%.13f", 0.000000000000100000);}
int f_stress_prec13_limits_big(void){return ft_printf("%.13f", 99.999999999999900000);}
//Floats - Prec 14
int f_stress_prec14_rndu(void){return ft_printf("%.14f",        1.025978541436587568);}
int f_stress_prec14_rndd(void){return ft_printf("%.14f",        1.025978548534310421);}
int f_stress_prec14_limits_tiny(void){return ft_printf("%.14f", 0.000000000000010000);}
int f_stress_prec14_limits_big(void){return ft_printf("%.14f",  9.999999999999990000);}
//Floats - Prec 15
int f_stress_prec15_rndu(void){return ft_printf("%.15f",        1.025978542436587568);}
int f_stress_prec15_rndd(void){return ft_printf("%.15f",        1.025978548534310421);}
int f_stress_prec15_limits_tiny(void){return ft_printf("%.15f", 0.000000000000001000);}
int f_stress_prec15_limits_big(void){return ft_printf("%.15f",  0.999999999999999000);}
//Floats - Prec 16
int f_stress_prec16_rndu(void){return ft_printf("%.16f",        1.025978542436587568);}
int f_stress_prec16_rndd(void){return ft_printf("%.16f",        1.025978548534310421);}
int f_stress_prec16_limits_tiny(void){return ft_printf("%.16f", 0.000000000000000100);}
int f_stress_prec16_limits_big(void){return ft_printf("%.16f",  0.999999999999999900);}
//Floats - Prec 17
int f_stress_prec17_rndu(void){return ft_printf("%.17f",        1.025978542436587568);}
int f_stress_prec17_rndd(void){return ft_printf("%.17f",        1.025978548534310421);}
int f_stress_prec17_limits_tiny(void){return ft_printf("%.17f", 0.000000000000000010);}
int f_stress_prec17_limits_big(void){return ft_printf("%.17f",  0.999999999999999990);}
//Floats - Prec 18
int f_stress_prec18_rndu(void){return ft_printf("%.18f",        0.125978542436587568);}
int f_stress_prec18_rndd(void){return ft_printf("%.18f",        0.125978548534310421);}
//Floats with altform,~
int		f_af_prec0p(void){return ft_printf("%#.0f", 7.4);}
int		f_af_prec1p(void){return ft_printf("%#.1f", 7.3);}
int		f_af_prec0n(void){return ft_printf("%#.0f", -7.4);}
int		f_af_prec1n(void){return ft_printf("%#.1f", -7.3);}
//Floats with allsign,~
int		f_as_prec0p_as(void){return ft_printf("%+.0f", 7.4);}
int		f_as_prec3p_as(void){return ft_printf("%+.3f", 7.3);}
int		f_as_prec0n_as(void){return ft_printf("%+.0f", -7.4);}
int		f_as_prec3n_as(void){return ft_printf("%+.3f", -7.3);}
//Floats with field width,~
int f_wprec0p(void){return ft_printf("%5.0f", 7.3);}
int f_wprec1p(void){return ft_printf("%5.1f", 7.3);}
int f_wprec3p(void){return ft_printf("%5.3f", 7.3);}
int f_wprec6p(void){return ft_printf("%5.6f", 7.3);}
int f_wprec0n(void){return ft_printf("%5.0f", -7.3);}
int f_wprec1n(void){return ft_printf("%5.1f", -7.3);}
int f_wprec3n(void){return ft_printf("%5.3f", -7.3);}
int f_wprec6n(void){return ft_printf("%5.6f", -7.3);}
//Floats with field width and zero padding,~
int f_wzp_prec0p(void){return ft_printf("%05.0f", 7.3);}
int f_wzp_prec1p(void){return ft_printf("%05.1f", 7.3);}
int f_wzp_prec3p(void){return ft_printf("%05.3f", 7.3);}
int f_wzp_prec6p(void){return ft_printf("%05.6f", 7.3);}
int f_wzp_prec0n(void){return ft_printf("%05.0f", -7.3);}
int f_wzp_prec1n(void){return ft_printf("%05.1f", -7.3);}
int f_wzp_prec3n(void){return ft_printf("%05.3f", -7.3);}
int f_wzp_prec6n(void){return ft_printf("%05.6f", -7.3);}
//Floats with field width and left justify,~
int f_wlj_prec0p(void){return ft_printf("%-5.0f", 7.3);}
int f_wlj_prec1p(void){return ft_printf("%-5.1f", 7.3);}
int f_wlj_prec3p(void){return ft_printf("%-5.3f", 7.3);}
int f_wlj_prec6p(void){return ft_printf("%-5.6f", 7.3);}
int f_wlj_prec0n(void){return ft_printf("%-5.0f", -7.3);}
int f_wlj_prec1n(void){return ft_printf("%-5.1f", -7.3);}
int f_wlj_prec3n(void){return ft_printf("%-5.3f", -7.3);}
int f_wlj_prec6n(void){return ft_printf("%-5.6f", -7.3);}
//Floats with field width and zero padding and left justify,~
int f_wzplj_prec0p_ignoreflag(void){return ft_printf("%-05.0f", 7.3);}
int f_wzplj_prec1p_ignoreflag(void){return ft_printf("%-05.1f", 7.3);}
int f_wzplj_prec3p_ignoreflag(void){return ft_printf("%-05.3f", 7.3);}
int f_wzplj_prec6p_ignoreflag(void){return ft_printf("%-05.6f", 7.3);}
int f_wzplj_prec0n_ignoreflag(void){return ft_printf("%-05.0f", -7.3);}
int f_wzplj_prec1n_ignoreflag(void){return ft_printf("%-05.1f", -7.3);}
int f_wzplj_prec3n_ignoreflag(void){return ft_printf("%-05.3f", -7.3);}
int f_wzplj_prec6n_ignoreflag(void){return ft_printf("%-05.6f", -7.3);}
//Floats with field width and zero padding and left justify, rev f order,~
int f_wzpljr_prec0p_ignoreflag(void){return ft_printf("%0-5.0f", 7.3);}
int f_wzpljr_prec1p_ignoreflag(void){return ft_printf("%0-5.1f", 7.3);}
int f_wzpljr_prec3p_ignoreflag(void){return ft_printf("%0-5.3f", 7.3);}
int f_wzpljr_prec6p_ignoreflag(void){return ft_printf("%0-5.6f", 7.3);}
int f_wzpljr_prec0n_ignoreflag(void){return ft_printf("%0-5.0f", -7.3);}
int f_wzpljr_prec1n_ignoreflag(void){return ft_printf("%0-5.1f", -7.3);}
int f_wzpljr_prec3n_ignoreflag(void){return ft_printf("%0-5.3f", -7.3);}
int f_wzpljr_prec6n_ignoreflag(void){return ft_printf("%0-5.6f", -7.3);}
//Floats with field width and left justify and altform,~
int f_wzpljaf_prec0p(void){return ft_printf("%#-5.0f", 7.3);}
int f_wzpljaf_prec1p(void){return ft_printf("%#-5.1f", 7.3);}
int f_wzpljaf_prec3p(void){return ft_printf("%#-5.3f", 7.3);}
int f_wzpljaf_prec6p(void){return ft_printf("%#-5.6f", 7.3);}
int f_wzpljaf_prec0n(void){return ft_printf("%#-5.0f", -7.3);}
int f_wzpljaf_prec1n(void){return ft_printf("%#-5.1f", -7.3);}
int f_wzpljaf_prec3n(void){return ft_printf("%#-5.3f", -7.3);}
int f_wzpljaf_prec6n(void){return ft_printf("%#-5.6f", -7.3);}
//Floats with field width and allsign,~
int f_was_prec0p(void){return ft_printf("%+5.0f", 7.3);}
int f_was_prec1p(void){return ft_printf("%+5.1f", 7.3);}
int f_was_prec3p(void){return ft_printf("%+5.3f", 7.3);}
int f_was_prec6p(void){return ft_printf("%+5.6f", 7.3);}
int f_was_prec0n(void){return ft_printf("%+5.0f", -7.3);}
int f_was_prec1n(void){return ft_printf("%+5.1f", -7.3);}
int f_was_prec3n(void){return ft_printf("%+5.3f", -7.3);}
int f_was_prec6n(void){return ft_printf("%+5.6f", -7.3);}
//Floats with field width and zero padding and allsign,~
int f_wzpas_prec0p(void){return ft_printf("%+05.0f", 7.3);}
int f_wzpas_prec1p(void){return ft_printf("%+05.1f", 7.3);}
int f_wzpas_prec3p(void){return ft_printf("%+05.3f", 7.3);}
int f_wzpas_prec6p(void){return ft_printf("%+05.6f", 7.3);}
int f_wzpas_prec0n(void){return ft_printf("%+05.0f", -7.3);}
int f_wzpas_prec1n(void){return ft_printf("%+05.1f", -7.3);}
int f_wzpas_prec3n(void){return ft_printf("%+05.3f", -7.3);}
int f_wzpas_prec6n(void){return ft_printf("%+05.6f", -7.3);}
//Floats with field width and left justify and allsign,~
int f_wljas_prec0p(void){return ft_printf("%+-5.0f", 7.3);}
int f_wljas_prec1p(void){return ft_printf("%+-5.1f", 7.3);}
int f_wljas_prec3p(void){return ft_printf("%+-5.3f", 7.3);}
int f_wljas_prec6p(void){return ft_printf("%+-5.6f", 7.3);}
int f_wljas_prec0n(void){return ft_printf("%+-5.0f", -7.3);}
int f_wljas_prec1n(void){return ft_printf("%+-5.1f", -7.3);}
int f_wljas_prec3n(void){return ft_printf("%+-5.3f", -7.3);}
int f_wljas_prec6n(void){return ft_printf("%+-5.6f", -7.3);}
//Floats with field width and zero padding and left justify and allsign,~
int f_wzpljas_prec0p_ignoreflag(void){return ft_printf("%+-05.0f", 7.3);}
int f_wzpljas_prec1p_ignoreflag(void){return ft_printf("%+-05.1f", 7.3);}
int f_wzpljas_prec3p_ignoreflag(void){return ft_printf("%+-05.3f", 7.3);}
int f_wzpljas_prec6p_ignoreflag(void){return ft_printf("%+-05.6f", 7.3);}
int f_wzpljas_prec0n_ignoreflag(void){return ft_printf("%+-05.0f", -7.3);}
int f_wzpljas_prec1n_ignoreflag(void){return ft_printf("%+-05.1f", -7.3);}
int f_wzpljas_prec3n_ignoreflag(void){return ft_printf("%+-05.3f", -7.3);}
int f_wzpljas_prec6n_ignoreflag(void){return ft_printf("%+-05.6f", -7.3);}
//Floats with field width left justify, rev f order and allsign,~
int f_wzpljras_prec0p(void){return ft_printf("%-+5.0f", 7.3);}
int f_wzpljras_prec1p(void){return ft_printf("%-+5.1f", 7.3);}
int f_wzpljras_prec3p(void){return ft_printf("%-+5.3f", 7.3);}
int f_wzpljras_prec6p(void){return ft_printf("%-+5.6f", 7.3);}
int f_wzpljras_prec0n(void){return ft_printf("%-+5.0f", -7.3);}
int f_wzpljras_prec1n(void){return ft_printf("%-+5.1f", -7.3);}
int f_wzpljras_prec3n(void){return ft_printf("%-+5.3f", -7.3);}
int f_wzpljras_prec6n(void){return ft_printf("%-+5.6f", -7.3);}
//Floats with field width and left justify and altform and allsign,~
int f_wzpljafas_prec0p(void){return ft_printf("%+#-5.0f", 7.3);}
int f_wzpljafas_prec1p(void){return ft_printf("%+#-5.1f", 7.3);}
int f_wzpljafas_prec3p(void){return ft_printf("%+#-5.3f", 7.3);}
int f_wzpljafas_prec6p(void){return ft_printf("%+#-5.6f", 7.3);}
int f_wzpljafas_prec0n(void){return ft_printf("%+#-5.0f", -7.3);}
int f_wzpljafas_prec1n(void){return ft_printf("%+#-5.1f", -7.3);}
int f_wzpljafas_prec3n(void){return ft_printf("%+#-5.3f", -7.3);}
int f_wzpljafas_prec6n(void){return ft_printf("%+#-5.6f", -7.3);}
//Floats with field width and sp,~
int f_wsp_prec0p(void){return ft_printf("% 5.0f", 7.3);}
int f_wsp_prec1p(void){return ft_printf("% 5.1f", 7.3);}
int f_wsp_prec3p(void){return ft_printf("% 5.3f", 7.3);}
int f_wsp_prec6p(void){return ft_printf("% 5.6f", 7.3);}
int f_wsp_prec0n(void){return ft_printf("% 5.0f", -7.3);}
int f_wsp_prec1n(void){return ft_printf("% 5.1f", -7.3);}
int f_wsp_prec3n(void){return ft_printf("% 5.3f", -7.3);}
int f_wsp_prec6n(void){return ft_printf("% 5.6f", -7.3);}
//Floats with field width and zero padding and sp,~
int f_wzpsp_prec0p(void){return ft_printf("% 05.0f", 7.3);}
int f_wzpsp_prec1p(void){return ft_printf("% 05.1f", 7.3);}
int f_wzpsp_prec3p(void){return ft_printf("% 05.3f", 7.3);}
int f_wzpsp_prec6p(void){return ft_printf("% 05.6f", 7.3);}
int f_wzpsp_prec0n(void){return ft_printf("% 05.0f", -7.3);}
int f_wzpsp_prec1n(void){return ft_printf("% 05.1f", -7.3);}
int f_wzpsp_prec3n(void){return ft_printf("% 05.3f", -7.3);}
int f_wzpsp_prec6n(void){return ft_printf("% 05.6f", -7.3);}
//Floats with field width and left justify and sp,~
int f_wljsp_prec0p(void){return ft_printf("% -5.0f", 7.3);}
int f_wljsp_prec1p(void){return ft_printf("% -5.1f", 7.3);}
int f_wljsp_prec3p(void){return ft_printf("% -5.3f", 7.3);}
int f_wljsp_prec6p(void){return ft_printf("% -5.6f", 7.3);}
int f_wljsp_prec0n(void){return ft_printf("% -5.0f", -7.3);}
int f_wljsp_prec1n(void){return ft_printf("% -5.1f", -7.3);}
int f_wljsp_prec3n(void){return ft_printf("% -5.3f", -7.3);}
int f_wljsp_prec6n(void){return ft_printf("% -5.6f", -7.3);}
//Floats with field width and zero padding and left justify and sp,~
int f_wzpljsp_prec0p_ignoreflag(void){return ft_printf("% -05.0f", 7.3);}
int f_wzpljsp_prec1p_ignoreflag(void){return ft_printf("% -05.1f", 7.3);}
int f_wzpljsp_prec3p_ignoreflag(void){return ft_printf("% -05.3f", 7.3);}
int f_wzpljsp_prec6p_ignoreflag(void){return ft_printf("% -05.6f", 7.3);}
int f_wzpljsp_prec0n_ignoreflag(void){return ft_printf("% -05.0f", -7.3);}
int f_wzpljsp_prec1n_ignoreflag(void){return ft_printf("% -05.1f", -7.3);}
int f_wzpljsp_prec3n_ignoreflag(void){return ft_printf("% -05.3f", -7.3);}
int f_wzpljsp_prec6n_ignoreflag(void){return ft_printf("% -05.6f", -7.3);}
//Floats with field width left justify, rev f order and sp,~
int f_wzpljrsp_prec0p(void){return ft_printf("%- 5.0f", 7.3);}
int f_wzpljrsp_prec1p(void){return ft_printf("%- 5.1f", 7.3);}
int f_wzpljrsp_prec3p(void){return ft_printf("%- 5.3f", 7.3);}
int f_wzpljrsp_prec6p(void){return ft_printf("%- 5.6f", 7.3);}
int f_wzpljrsp_prec0n(void){return ft_printf("%- 5.0f", -7.3);}
int f_wzpljrsp_prec1n(void){return ft_printf("%- 5.1f", -7.3);}
int f_wzpljrsp_prec3n(void){return ft_printf("%- 5.3f", -7.3);}
int f_wzpljrsp_prec6n(void){return ft_printf("%- 5.6f", -7.3);}
//Floats with field width and left justify and altform and sp,~
int f_wzpljafsp_prec0p(void){return ft_printf("% #-5.0f", 7.3);}
int f_wzpljafsp_prec1p(void){return ft_printf("% #-5.1f", 7.3);}
int f_wzpljafsp_prec3p(void){return ft_printf("% #-5.3f", 7.3);}
int f_wzpljafsp_prec6p(void){return ft_printf("% #-5.6f", 7.3);}
int f_wzpljafsp_prec0n(void){return ft_printf("% #-5.0f", -7.3);}
int f_wzpljafsp_prec1n(void){return ft_printf("% #-5.1f", -7.3);}
int f_wzpljafsp_prec3n(void){return ft_printf("% #-5.3f", -7.3);}
int f_wzpljafsp_prec6n(void){return ft_printf("% #-5.6f", -7.3);}
//Floats with allsign and sp,~
int f_assp_prec0p_ignoreflag(void){return ft_printf("%+ .0f", 7.3);}
int f_assp_prec1p_ignoreflag(void){return ft_printf("%+ .1f", 7.3);}
int f_assp_prec3p_ignoreflag(void){return ft_printf("%+ .3f", 7.3);}
int f_assp_prec6p_ignoreflag(void){return ft_printf("%+ .6f", 7.3);}
int f_assp_prec0n_ignoreflag(void){return ft_printf("%+ .0f", -7.3);}
int f_assp_prec1n_ignoreflag(void){return ft_printf("%+ .1f", -7.3);}
int f_assp_prec3n_ignoreflag(void){return ft_printf("%+ .3f", -7.3);}
int f_assp_prec6n_ignoreflag(void){return ft_printf("%+ .6f", -7.3);}
//Floats with allsign and sp and rev flag order,~
int f_asspr_prec0p_ignoreflag(void){return ft_printf("% +.0f", 7.3);}
int f_asspr_prec1p_ignoreflag(void){return ft_printf("% +.1f", 7.3);}
int f_asspr_prec3p_ignoreflag(void){return ft_printf("% +.3f", 7.3);}
int f_asspr_prec6p_ignoreflag(void){return ft_printf("% +.6f", 7.3);}
int f_asspr_prec0n_ignoreflag(void){return ft_printf("% +.0f", -7.3);}
int f_asspr_prec1n_ignoreflag(void){return ft_printf("% +.1f", -7.3);}
int f_asspr_prec3n_ignoreflag(void){return ft_printf("% +.3f", -7.3);}
int f_asspr_prec6n_ignoreflag(void){return ft_printf("% +.6f", -7.3);}
//Floats whose precision exceeds their compiled literal precision
 int f_overprec_might_be_undefbehav_100(void){return ft_printf("%.100f", 0.237);}
 int f_overprec_might_be_undefbehav_32(void){return ft_printf("%.32f", 0.237);}
 int f_overprec_might_be_undefbehav_4(void){return ft_printf("%.4f", 0.237);}
 int f_overprec_might_be_undefbehav_1000(void){return ft_printf("%.4f", -0.106577568068517810765107851705167);}
 int f_overprec_might_be_undefbehav_10_from_0(void){return ft_printf("%.10f", 0.0);}
 int f_overprec_might_be_undefbehav_2000(void){return ft_printf("%.2000f", 623.28376510723481);}
 int f_overprec_might_be_undefbehav_dblmin(void){return ft_printf("%.2000f", DBL_MIN);}
 int f_overprec_might_be_undefbehav_ndblmin(void){return ft_printf("%.2000f", -DBL_MIN);}
//Floats at double max, double min
 int f_limits_dblmax_prec0_notmandatory(void){return ft_printf("%.0f", DBL_MAX);}
 int f_limits_dblmax_prec3_notmandatory(void){return ft_printf("%.3f", DBL_MAX);}
 int f_limits_dblmax_precd_notmandatory(void){return ft_printf("%f", DBL_MAX);}
 int f_limits_dblmax_prec8_notmandatory(void){return ft_printf("%.8f", DBL_MAX);}
 int f_stress_limits_dblmax_prec12_notmandatory(void){return ft_printf("%.12f", DBL_MAX);}
 int f_stress_limits_dblmax_prec16_notmandatory(void){return ft_printf("%.16f", DBL_MAX);}
 int f_stress_limits_dblmax_prec18_notmandatory(void){return ft_printf("%.18f", DBL_MAX);}
 int f_limits_ndblmax_prec0_notmandatory(void){return ft_printf("%.0f", -DBL_MAX);}
 int f_limits_ndblmax_prec3_notmandatory(void){return ft_printf("%.3f", -DBL_MAX);}
 int f_limits_ndblmax_precd_notmandatory(void){return ft_printf("%f", -DBL_MAX);}
 int f_limits_ndblmax_prec8_notmandatory(void){return ft_printf("%.8f", -DBL_MAX);}
 int f_stress_limits_ndblmax_prec12_notmandatory(void){return ft_printf("%.12f", -DBL_MAX);}
 int f_stress_limits_ndblmax_prec16_notmandatory(void){return ft_printf("%.16f", -DBL_MAX);}
 int f_stress_limits_ndblmax_prec18_notmandatory(void){return ft_printf("%.18f", -DBL_MAX);}
int f_limits_dblmin_prec0(void){return ft_printf("%.0f", DBL_MIN);}
int f_limits_dblmin_prec3(void){return ft_printf("%.3f", DBL_MIN);}
int f_limits_dblmin_precd(void){return ft_printf("%f", DBL_MIN);}
int f_limits_dblmin_prec8(void){return ft_printf("%.8f", DBL_MIN);}
int f_stress_limits_dblmin_prec12(void){return ft_printf("%.12f", DBL_MIN);}
int f_stress_limits_dblmin_prec16(void){return ft_printf("%.16f", DBL_MIN);}
int f_stress_limits_dblmin_prec18(void){return ft_printf("%.18f", DBL_MIN);}
int f_limits_ndblmin_prec0(void){return ft_printf("%.0f", -DBL_MIN);}
int f_limits_ndblmin_prec3(void){return ft_printf("%.3f", -DBL_MIN);}
int f_limits_ndblmin_precd(void){return ft_printf("%f", -DBL_MIN);}
int f_limits_ndblmin_prec8(void){return ft_printf("%.8f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec12(void){return ft_printf("%.12f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec16(void){return ft_printf("%.16f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec18(void){return ft_printf("%.18f", -DBL_MIN);}

//Floats of special values
 int f_reserved_values_inf(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("%f", special);}
 int f_reserved_values_ninf(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("%f", special);}
 int f_reserved_values_nan(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("%f", special);}
 int f_reserved_values_pzero(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("%f", special);}
 int f_reserved_values_nzero(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("%f", special);}
 int f_reserved_values_inf_6w(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("%6f", special);}
 int f_reserved_values_ninf_6w(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("%6f", special);}
 int f_reserved_values_nan_6w(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("%6f", special);}
 int f_reserved_values_pzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("%6f", special);}
 int f_reserved_values_nzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("%6f", special);}
 int f_reserved_values_inf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("%-6f", special);}
 int f_reserved_values_ninf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("%-6f", special);}
 int f_reserved_values_nan_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("%-6f", special);}
 int f_reserved_values_pzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("%-6f", special);}
 int f_reserved_values_nzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("%-6f", special);}
 int f_reserved_values_inf_6was(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("%+6f", special);}
 int f_reserved_values_ninf_6was(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("%+6f", special);}
 int f_reserved_values_nan_6was(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("%+6f", special);}
 int f_reserved_values_pzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("%+6f", special);}
 int f_reserved_values_nzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("%+6f", special);}
 int f_reserved_values_inf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("%10.7f", special);}
 int f_reserved_values_ninf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("%10.7f", special);}
 int f_reserved_values_nan_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("%10.7f", special);}
 int f_reserved_values_pzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("%10.7f", special);}
 int f_reserved_values_nzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("%10.7f", special);}
 int f_reserved_values_inf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("% .7f", special);}
 int f_reserved_values_ninf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("% .7f", special);}
 int f_reserved_values_nan_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("% .7f", special);}
 int f_reserved_values_pzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("% .7f", special);}
 int f_reserved_values_nzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("% .7f", special);}
 int f_reserved_values_inf_sp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("% f", special);}
 int f_reserved_values_ninf_sp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("% f", special);}
 int f_reserved_values_nan_sp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("% f", special);}
 int f_reserved_values_pzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("% f", special);}
 int f_reserved_values_nzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("% f", special);}
 int f_reserved_values_inf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return ft_printf("%06f", special);}
 int f_reserved_values_ninf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return ft_printf("%06f", special);}
 int f_reserved_values_nan_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return ft_printf("%06f", special);}
 int f_reserved_values_pzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return ft_printf("%06f", special);}
 int f_reserved_values_nzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return ft_printf("%06f", special);}

//Long Doubles - Basic
int f_L_basic_1(void){return ft_printf("this %Lf float", 1.5l);}
int f_L_basic_fltonly(void){return ft_printf("%Lf", 7.5l);}
int f_L_basic_whole(void){return ft_printf("%Lf", 1.0l);}
int f_L_basic_negative(void){return ft_printf("%Lf", -3.85l);}
int f_L_basic_positive_3_3(void){return ft_printf("%Lf", 573.924l);}
int f_L_basic_negative_3_3(void){return ft_printf("%Lf", -958.125l);}
int f_L_basic_positive_smallfpart(void){return ft_printf("%Lf", 23.00041l);}
int f_L_basic_positive_allsmall(void){return ft_printf("%Lf", 0.000039l);}
int f_L_basic_negative_smallfpart(void){return ft_printf("%Lf", -7.00036l);}
int f_L_basic_negative_allsmall(void){return ft_printf("%Lf", -0.00032l);}
int f_L_basic_limits_allsmall_pos(void){return ft_printf("%Lf", 0.000001l);}
int f_L_basic_limits_allsmall_neg(void){return ft_printf("%Lf", -0.000001l);}
int f_L_basic_limits_smallfpart_pos(void){return ft_printf("%Lf", 9873.000001l);}
int f_L_basic_limits_smallfpart_neg(void){return ft_printf("%Lf", -875.000001l);}
int f_L_basic_limits_allbig_pos(void){return ft_printf("%Lf", 999.999999l);}
int f_L_basic_limits_allbig_neg(void){return ft_printf("%Lf", -99.999999l);}
int f_L_basic_limits_bigfpart_pos(void){return ft_printf("%Lf", 0.999999l);}
int f_L_basic_limits_bigfpart_neg(void){return ft_printf("%Lf", -0.999999l);}
//Long Doubles - Rounding with default precision
int f_L_rndd_pos(void){return ft_printf("%Lf", 23.375094499l);}
int f_L_rndd_neg(void){return ft_printf("%Lf", -985.765426499l);}
int f_L_rndu_pos(void){return ft_printf("%Lf", 0.08942555l);}
int f_L_rndu_neg(void){return ft_printf("%Lf", -56.2012685l);}
int f_L_rndu_multidigit_pos(void){return ft_printf("%Lf", 43.4399999l);}
int f_L_rndu_multidigit_neg(void){return ft_printf("%Lf", -5.0299999l);}
int f_L_rndd_multidigit_pos(void){return ft_printf("%Lf", 43.43999949l);}
int f_L_rndd_multidigit_neg(void){return ft_printf("%Lf", -5.02999949l);}
int f_L_rndd_wholnobump_pos(void){return ft_printf("%Lf", 1.99999949l);}
int f_L_rndd_wholnobump_neg(void){return ft_printf("%Lf", -0.99999949l);}
int f_L_rndu_bumpwhole_pos(void){return ft_printf("%Lf", 3.9999999l);}
int f_L_rndu_bumpwhole_neg(void){return ft_printf("%Lf", -5.9999999l);}
//Long Doubles - Prec 7
int f_L_prec7_1(void){return ft_printf("this %.7Lf float", 1.5l);}
int f_L_prec7_fltonly(void){return ft_printf("%.7Lf", 7.5l);}
int f_L_prec7_whole(void){return ft_printf("%.7Lf", 1.0l);}
int f_L_prec7_negative(void){return ft_printf("%.7Lf", -3.85l);}
int f_L_prec7_positive_3_3(void){return ft_printf("%.7Lf", 573.924l);}
int f_L_prec7_negative_3_3(void){return ft_printf("%.7Lf", -958.125l);}
int f_L_prec7_positive_smallfpart(void){return ft_printf("%.7Lf", 23.00041l);}
int f_L_prec7_positive_allsmall(void){return ft_printf("%.7Lf", 0.0000039l);}
int f_L_prec7_negative_smallfpart(void){return ft_printf("%.7Lf", -7.00036l);}
int f_L_prec7_negative_allsmall(void){return ft_printf("%.7Lf", -0.000032l);}
int f_L_prec7_limits_allsmall_pos(void){return ft_printf("%.7Lf", 0.0000001l);}
int f_L_prec7_limits_allsmall_neg(void){return ft_printf("%.7Lf", -0.0000001l);}
int f_L_prec7_limits_smallfpart_pos(void){return ft_printf("%.7Lf", 9873.000001l);}
int f_L_prec7_limits_smallfpart_neg(void){return ft_printf("%.7Lf", -875.000001l);}
int f_L_prec7_limits_allbig_pos(void){return ft_printf("%.7Lf", 999.9999999l);}
int f_L_prec7_limits_allbig_neg(void){return ft_printf("%.7Lf", -99.9999999l);}
int f_L_prec7_limits_bigfpart_pos(void){return ft_printf("%.7Lf", 0.999999l);}
int f_L_prec7_limits_bigfpart_neg(void){return ft_printf("%.7Lf", -0.999999l);}
//Long Doubles - Prec 7 Rounding
int f_L_rnd_prec7_rndd_pos(void){return ft_printf("%.7Lf", 23.375094499l);}
int f_L_rnd_prec7_rndd_neg(void){return ft_printf("%.7Lf", -985.765426499l);}
int f_L_rnd_prec7_rndu_pos(void){return ft_printf("%.7Lf", 0.0894255l);}
int f_L_rnd_prec7_rndu_neg(void){return ft_printf("%.7Lf", -56.2012685l);}
int f_L_rnd_prec7_rndu_multidigit_pos(void){return ft_printf("%.7Lf", 43.4399999l);}
int f_L_rnd_prec7_rndu_multidigit_neg(void){return ft_printf("%.7Lf", -5.0299999l);}
int f_L_rnd_prec7_rndd_multidigit_pos(void){return ft_printf("%.7Lf", 43.43999949l);}
int f_L_rnd_prec7_rndd_multidigit_neg(void){return ft_printf("%.7Lf", -5.02999949l);}
int f_L_rnd_prec7_rndd_wholnobump_pos(void){return ft_printf("%.7Lf", 1.99999949l);}
int f_L_rnd_prec7_rndd_wholnobump_neg(void){return ft_printf("%.7Lf", -0.99999949l);}
int f_L_rnd_prec7_rndu_bumpwhole_pos(void){return ft_printf("%.7Lf", 3.9999999l);}
//Long Doubles - Prec 8
int f_L_prec8_1(void){return ft_printf("this %.8Lf float", 1.5l);}
int f_L_prec8_fltonly(void){return ft_printf("%.8Lf", 7.5l);}
int f_L_prec8_whole(void){return ft_printf("%.8Lf", 1.0l);}
int f_L_prec8_negative(void){return ft_printf("%.8Lf", -3.85l);}
int f_L_prec8_positive_3_3(void){return ft_printf("%.8Lf", 573.924l);}
int f_L_prec8_negative_3_3(void){return ft_printf("%.8Lf", -958.125l);}
int f_L_prec8_positive_smallfpart(void){return ft_printf("%.8Lf", 23.00041l);}
int f_L_prec8_positive_allsmall(void){return ft_printf("%.8Lf", 0.00000039l);}
int f_L_prec8_negative_smallfpart(void){return ft_printf("%.8Lf", -7.00036l);}
int f_L_prec8_negative_allsmall(void){return ft_printf("%.8Lf", -0.0000032l);}
int f_L_prec8_limits_allsmall_pos(void){return ft_printf("%.8Lf", 0.00000001l);}
int f_L_prec8_limits_allsmall_neg(void){return ft_printf("%.8Lf", -0.00000001l);}
int f_L_prec8_limits_smallfpart_pos(void){return ft_printf("%.8Lf", 9873.000001l);}
int f_L_prec8_limits_smallfpart_neg(void){return ft_printf("%.8Lf", -875.000001l);}
int f_L_prec8_limits_allbig_pos(void){return ft_printf("%.8Lf", 999.9999999l);}
int f_L_prec8_limits_allbig_neg(void){return ft_printf("%.8Lf", -99.99999999l);}
int f_L_prec8_limits_bigfpart_pos(void){return ft_printf("%.8Lf", 0.999999l);}
int f_L_prec8_limits_bigfpart_neg(void){return ft_printf("%.8Lf", -0.999999l);}
//Long Doubles - Prec 8 Rounding
int f_L_rnd_prec8_rndd_pos(void){return ft_printf("%.8Lf", 23.375094499l);}
int f_L_rnd_prec8_rndd_neg(void){return ft_printf("%.8Lf", -985.765426499l);}
int f_L_rnd_prec8_rndu_pos(void){return ft_printf("%.8Lf", 0.0894255l);}
int f_L_rnd_prec8_rndu_neg(void){return ft_printf("%.8Lf", -56.2012685l);}
int f_L_rnd_prec8_rndu_multidigit_pos(void){return ft_printf("%.8Lf", 43.4399999l);}
int f_L_rnd_prec8_rndu_multidigit_neg(void){return ft_printf("%.8Lf", -5.0299999l);}
int f_L_rnd_prec8_rndd_multidigit_pos(void){return ft_printf("%.8Lf", 43.43999949l);}
int f_L_rnd_prec8_rndd_multidigit_neg(void){return ft_printf("%.8Lf", -5.02999949l);}
int f_L_rnd_prec8_rndd_wholnobump_pos(void){return ft_printf("%.8Lf", 1.99999949l);}
int f_L_rnd_prec8_rndd_wholnobump_neg(void){return ft_printf("%.8Lf", -0.99999949l);}
int f_L_rnd_prec8_rndu_bumpwhole_pos(void){return ft_printf("%.8Lf", 3.9999999l);}
//Long Doubles - Prec 9
int f_L_prec9_1(void){return ft_printf("this %.9Lf float", 1.5l);}
int f_L_prec9_fltonly(void){return ft_printf("%.9Lf", 7.5l);}
int f_L_prec9_whole(void){return ft_printf("%.9Lf", 1.0l);}
int f_L_prec9_negative(void){return ft_printf("%.9Lf", -3.85l);}
int f_L_prec9_positive_3_3(void){return ft_printf("%.9Lf", 573.924l);}
int f_L_prec9_negative_3_3(void){return ft_printf("%.9Lf", -958.125l);}
int f_L_prec9_positive_smallfpart(void){return ft_printf("%.9Lf", 23.00041l);}
int f_L_prec9_positive_allsmall(void){return ft_printf("%.9Lf", 0.00000039l);}
int f_L_prec9_negative_smallfpart(void){return ft_printf("%.9Lf", -7.00036l);}
int f_L_prec9_negative_allsmall(void){return ft_printf("%.9Lf", -0.0000032l);}
int f_L_prec9_limits_allsmall_pos(void){return ft_printf("%.9Lf", 0.00000001l);}
int f_L_prec9_limits_allsmall_neg(void){return ft_printf("%.9Lf", -0.00000001l);}
int f_L_prec9_limits_smallfpart_pos(void){return ft_printf("%.9Lf", 9873.000001l);}
int f_L_prec9_limits_smallfpart_neg(void){return ft_printf("%.9Lf", -875.000001l);}
int f_L_prec9_limits_allbig_pos(void){return ft_printf("%.9Lf", 999.99999999l);}
int f_L_prec9_limits_allbig_neg(void){return ft_printf("%.9Lf", -99.99999999l);}
int f_L_prec9_limits_bigfpart_pos(void){return ft_printf("%.9Lf", 0.999999l);}
int f_L_prec9_limits_bigfpart_neg(void){return ft_printf("%.9Lf", -0.999999l);}
//Long Doubles - Prec 9 Rounding
int f_L_rnd_prec9_rndd_pos(void){return ft_printf("%.9Lf", 23.375094499l);}
int f_L_rnd_prec9_rndd_neg(void){return ft_printf("%.9Lf", -985.765426499l);}
int f_L_rnd_prec9_rndu_pos(void){return ft_printf("%.9Lf", 0.0894255l);}
int f_L_rnd_prec9_rndu_neg(void){return ft_printf("%.9Lf", -56.2012685l);}
int f_L_rnd_prec9_rndu_multidigit_pos(void){return ft_printf("%.9Lf", 43.4399999l);}
int f_L_rnd_prec9_rndu_multidigit_neg(void){return ft_printf("%.9Lf", -5.0299999l);}
int f_L_rnd_prec9_rndd_multidigit_pos(void){return ft_printf("%.9Lf", 43.43999949l);}
int f_L_rnd_prec9_rndd_multidigit_neg(void){return ft_printf("%.9Lf", -5.02999949l);}
int f_L_rnd_prec9_rndd_wholnobump_pos(void){return ft_printf("%.9Lf", 1.99999949l);}
int f_L_rnd_prec9_rndd_wholnobump_neg(void){return ft_printf("%.9Lf", -0.99999949l);}
int f_L_rnd_prec9_rndu_bumpwhole_pos(void){return ft_printf("%.9Lf", 3.9999999l);}
//Long Doubles - Prec 10
int f_L_stress_prec10_1(void){return ft_printf("this %.10Lf float", 1.5l);}
int f_L_stress_prec10_fltonly(void){return ft_printf("%.10Lf", 7.5l);}
int f_L_stress_prec10_whole(void){return ft_printf("%.10Lf", 1.0l);}
int f_L_stress_prec10_negative(void){return ft_printf("%.10Lf", -3.85l);}
int f_L_stress_prec10_positive_3_10(void){return ft_printf("%.10Lf", 573.924l);}
int f_L_stress_prec10_negative_3_10(void){return ft_printf("%.10Lf", -958.125l);}
int f_L_stress_prec10_pos(void){return ft_printf("%.10Lf", 23.8341375094l);}
int f_L_stress_prec10_neg(void){return ft_printf("%.10Lf", -985.2459765426l);}
int f_L_stress_prec10_rndd_pos(void){return ft_printf("%.10Lf", 23.8341375094499l);}
int f_L_stress_prec10_rndd_neg(void){return ft_printf("%.10Lf", -985.2459765426499l);}
int f_L_stress_prec10_rndu_pos(void){return ft_printf("%.10Lf", 0.87650894255l);}
int f_L_stress_prec10_rndu_neg(void){return ft_printf("%.10Lf", -56.47852012685l);}
int f_L_stress_prec10_positive_smallfpart(void){return ft_printf("%.10Lf", 23.000000041l);}
int f_L_stress_prec10_positive_allsmall(void){return ft_printf("%.10Lf", 0.0000000039l);}
int f_L_stress_prec10_negative_smallfpart(void){return ft_printf("%.10Lf", -7.000000036l);}
int f_L_stress_prec10_negative_allsmall(void){return ft_printf("%.10Lf", -0.000000032l);}
int f_L_stress_prec10_limits_allsmall_pos(void){return ft_printf("%.10Lf", 0.0000000001l);}
int f_L_stress_prec10_limits_allsmall_neg(void){return ft_printf("%.10Lf", -0.0000000001l);}
int f_L_stress_prec10_limits_smallfpart_pos(void){return ft_printf("%.10Lf", 9873.0000000001l);}
int f_L_stress_prec10_limits_smallfpart_neg(void){return ft_printf("%.10Lf", -875.0000000001l);}
int f_L_stress_prec10_limits_allbig_pos(void){return ft_printf("%.10Lf", 999.9999999999l);}
int f_L_stress_prec10_limits_allbig_neg(void){return ft_printf("%.10Lf", -99.9999999999l);}
int f_L_stress_prec10_limits_bigfpart_pos(void){return ft_printf("%.10Lf", 0.9999999999l);}
int f_L_stress_prec10_limits_bigfpart_neg(void){return ft_printf("%.10Lf", -0.9999999999l);}
//Long Doubles - Prec 12
int f_L_stress_prec12_rndu(void){return ft_printf("%.12f",        1.025978542436587568678);}
int f_L_stress_prec12_rndd(void){return ft_printf("%.12f",        1.025978548534310421434);}
int f_L_stress_prec12_limits_tiny(void){return ft_printf("%.12f", 0.000000000001000000000);}
int f_L_stress_prec12_limits_big(void){return ft_printf("%.12f",  0.999999999999000000000);}
//Long Doubles - Prec 14
int f_L_stress_prec14_rndu(void){return ft_printf("%.14f",        1.025978542436587568678);}
int f_L_stress_prec14_rndd(void){return ft_printf("%.14f",        1.025978548534310421434);}
int f_L_stress_prec14_limits_tiny(void){return ft_printf("%.14f", 0.000000000000010000000);}
int f_L_stress_prec14_limits_big(void){return ft_printf("%.14f",  0.999999999999990000000);}
//Long Doubles - Prec 16
int f_L_stress_prec16_rndu(void){return ft_printf("%.16f",        1.025978542436587568678);}
int f_L_stress_prec16_rndd(void){return ft_printf("%.16f",        1.025978548534310421634);}
int f_L_stress_prec16_limits_tiny(void){return ft_printf("%.16f", 0.000000000000000100000);}
int f_L_stress_prec16_limits_big(void){return ft_printf("%.16f",  0.999999999999999900000);}
//Long Doubles - Prec 17
int f_L_stress_prec17_rndu(void){return ft_printf("%.17f",        1.025978542436587568678);}
int f_L_stress_prec17_rndd(void){return ft_printf("%.17f",        1.025978548534310421734);}
int f_L_stress_prec17_limits_tiny(void){return ft_printf("%.17f", 0.000000000000000010000);}
int f_L_stress_prec17_limits_big(void){return ft_printf("%.17f",  0.999999999999999990000);}
//Long Doubles - Prec 18
int f_L_stress_prec18_rndu(void){return ft_printf("%.18f",        1.025978542436587568678);}
int f_L_stress_prec18_rndd(void){return ft_printf("%.18f",        1.025978548534310421834);}
int f_L_stress_prec18_limits_tiny(void){return ft_printf("%.18f", 0.000000000000000001000);}
int f_L_stress_prec18_limits_big(void){return ft_printf("%.18f",  0.999999999999999999000);}
//Long Doubles - Prec 19
int f_L_stress_prec19_rndu(void){return ft_printf("%.19f",        1.025978542436587568678);}
int f_L_stress_prec19_rndd(void){return ft_printf("%.19f",        1.025978548534310421934);}
int f_L_stress_prec19_limits_tiny(void){return ft_printf("%.19f", 0.000000000000000000100);}
int f_L_stress_prec19_limits_big(void){return ft_printf("%.19f",  0.999999999999999999900);}
//Long Doubles - Prec 20
int f_L_stress_prec20_rndu(void){return ft_printf("%.20f",        1.025978542436587568678);}
int f_L_stress_prec20_rndd(void){return ft_printf("%.20f",        1.025978548534310422034);}
int f_L_stress_prec20_limits_tiny(void){return ft_printf("%.20f", 0.000000000000000000010);}
int f_L_stress_prec20_limits_big(void){return ft_printf("%.20f",  0.999999999999999999990);}
//Long Doubles of special values
 int f_L_reserved_values_inf(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("%Lf", special);}
 int f_L_reserved_values_ninf(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%Lf", special);}
 int f_L_reserved_values_nan(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%Lf", special);}
 int f_L_reserved_values_pzero(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%Lf", special);}
 int f_L_reserved_values_nzero(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%Lf", special);}
 int f_L_reserved_values_inf_6w(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("%6Lf", special);}
 int f_L_reserved_values_ninf_6w(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%6Lf", special);}
 int f_L_reserved_values_nan_6w(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%6Lf", special);}
 int f_L_reserved_values_pzero_6w(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%6Lf", special);}
 int f_L_reserved_values_nzero_6w(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%6Lf", special);}
 int f_L_reserved_values_inf_6wlj(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("%-6Lf", special);}
 int f_L_reserved_values_ninf_6wlj(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%-6Lf", special);}
 int f_L_reserved_values_nan_6wlj(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%-6Lf", special);}
 int f_L_reserved_values_pzero_6wlj(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%-6Lf", special);}
 int f_L_reserved_values_nzero_6wlj(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%-6Lf", special);}
 int f_L_reserved_values_inf_6was(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("%+6Lf", special);}
 int f_L_reserved_values_ninf_6was(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%+6Lf", special);}
 int f_L_reserved_values_nan_6was(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%+6Lf", special);}
 int f_L_reserved_values_pzero_6was(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%+6Lf", special);}
 int f_L_reserved_values_nzero_6was(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%+6Lf", special);}
 int f_L_reserved_values_inf_10w_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("%10.7Lf", special);}
 int f_L_reserved_values_ninf_10w_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%10.7Lf", special);}
 int f_L_reserved_values_nan_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%10.7Lf", special);}
 int f_L_reserved_values_pzero_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%10.7Lf", special);}
 int f_L_reserved_values_nzero_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%10.7Lf", special);}
 int f_L_reserved_values_inf_sp_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("% .7Lf", special);}
 int f_L_reserved_values_ninf_sp_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("% .7Lf", special);}
 int f_L_reserved_values_nan_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("% .7Lf", special);}
 int f_L_reserved_values_pzero_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("% .7Lf", special);}
 int f_L_reserved_values_nzero_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("% .7Lf", special);}
 int f_L_reserved_values_inf_sp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("% Lf", special);}
 int f_L_reserved_values_ninf_sp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("% Lf", special);}
 int f_L_reserved_values_nan_sp(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("% Lf", special);}
 int f_L_reserved_values_pzero_sp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("% Lf", special);}
 int f_L_reserved_values_nzero_sp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("% Lf", special);}
 int f_L_reserved_values_inf_6wzp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return ft_printf("%06Lf", special);}
 int f_L_reserved_values_ninf_6wzp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%06Lf", special);}
 int f_L_reserved_values_nan_6wzp(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return ft_printf("%06Lf", special);}
 int f_L_reserved_values_pzero_6wzp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%06Lf", special);}
 int f_L_reserved_values_nzero_6wzp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return ft_printf("%06Lf", special);}
///Long double Floats whose precision exceeds their compiled literal precision
 int f_L_overprec_might_be_undefbehav_100(void){return ft_printf("%.100Lf", 0.237l);}
 int f_L_overprec_might_be_undefbehav_32(void){return ft_printf("%.32Lf", 0.237l);}
 int f_L_overprec_might_be_undefbehav_4(void){return ft_printf("%.4Lf", 0.237l);}
 int f_L_overprec_might_be_undefbehav_1000(void){return ft_printf("%.4Lf", -0.106577568068517810765107851705167l);}
 int f_L_overprec_might_be_undefbehav_10_from_0(void){return ft_printf("%.10Lf", 0.0l);}
 int f_L_overprec_might_be_undefbehav_2000(void){return ft_printf("%.2000Lf", 623.28376510723481l);}
 int f_L_overprec_might_be_undefbehav_dblmin(void){return ft_printf("%.2000Lf", LDBL_MIN);}
 int f_L_overprec_might_be_undefbehav_ndblmin(void){return ft_printf("%.2000Lf", -LDBL_MIN);}
//Long double floats at double max, double min
 int f_L_limits_dblmax_prec0_notmandatory(void){return ft_printf("%.0Lf", LDBL_MAX);}
 int f_L_limits_dblmax_prec3_notmandatory(void){return ft_printf("%.3Lf", LDBL_MAX);}
 int f_L_limits_dblmax_precd_notmandatory(void){return ft_printf("%Lf", LDBL_MAX);}
 int f_L_limits_dblmax_prec8_notmandatory(void){return ft_printf("%.8Lf", LDBL_MAX);}
 int f_L_stress_limits_dblmax_prec12_notmandatory(void){return ft_printf("%.12Lf", LDBL_MAX);}
 int f_L_stress_limits_dblmax_prec16_notmandatory(void){return ft_printf("%.16Lf", LDBL_MAX);}
 int f_L_stress_limits_dblmax_prec18_notmandatory(void){return ft_printf("%.18Lf", LDBL_MAX);}
 int f_L_limits_ndblmax_prec0_notmandatory(void){return ft_printf("%.0Lf", -LDBL_MAX);}
 int f_L_limits_ndblmax_prec3_notmandatory(void){return ft_printf("%.3Lf", -LDBL_MAX);}
 int f_L_limits_ndblmax_precd_notmandatory(void){return ft_printf("%Lf", -LDBL_MAX);}
 int f_L_limits_ndblmax_prec8_notmandatory(void){return ft_printf("%.8Lf", -LDBL_MAX);}
 int f_L_stress_limits_ndblmax_prec12_notmandatory(void){return ft_printf("%.12Lf", -LDBL_MAX);}
 int f_L_stress_limits_ndblmax_prec16_notmandatory(void){return ft_printf("%.16Lf", -LDBL_MAX);}
 int f_L_stress_limits_ndblmax_prec18_notmandatory(void){return ft_printf("%.18Lf", -LDBL_MAX);}
int f_L_limits_dblmin_prec0(void){return ft_printf("%.0Lf", LDBL_MIN);}
int f_L_limits_dblmin_prec3(void){return ft_printf("%.3Lf", LDBL_MIN);}
int f_L_limits_dblmin_precd(void){return ft_printf("%Lf", LDBL_MIN);}
int f_L_limits_dblmin_prec8(void){return ft_printf("%.8Lf", LDBL_MIN);}
int f_L_stress_limits_dblmin_prec12(void){return ft_printf("%.12Lf", LDBL_MIN);}
int f_L_stress_limits_dblmin_prec16(void){return ft_printf("%.16Lf", LDBL_MIN);}
int f_L_stress_limits_dblmin_prec18(void){return ft_printf("%.18Lf", LDBL_MIN);}
int f_L_limits_ndblmin_prec0(void){return ft_printf("%.0Lf", -LDBL_MIN);}
int f_L_limits_ndblmin_prec3(void){return ft_printf("%.3Lf", -LDBL_MIN);}
int f_L_limits_ndblmin_precd(void){return ft_printf("%Lf", -LDBL_MIN);}
int f_L_limits_ndblmin_prec8(void){return ft_printf("%.8Lf", -LDBL_MIN);}
int f_L_stress_limits_ndblmin_prec12(void){return ft_printf("%.12Lf", -LDBL_MIN);}
int f_L_stress_limits_ndblmin_prec16(void){return ft_printf("%.16Lf", -LDBL_MIN);}
int f_L_stress_limits_ndblmin_prec18(void){return ft_printf("%.18Lf", -LDBL_MIN);}

//Arbitrary argument numbers

 int		argnum_simple_swap(void){return ft_printf("%2$s, %1$s!", "world", "hello");} //CAN-SEGFAULT
 int		argnum_swap_around_pct(void){return ft_printf("%2$s %% %1$s!", "world", "hello");} //CAN-SEGFAULT
 int		argnum_swap_strfloat(void){return ft_printf("%2$f, %1$s!", "world", 5.75);} //CAN-SEGFAULT
 int		argnum_swap_floatstr(void){return ft_printf("%2$s, %1$f!", 5.75, "abc");} //CAN-SEGFAULT
 int		argnum_swap_ldblstr(void){return ft_printf("%2$s, %1$Lf!", 5.75L, "abc");} //CAN-SEGFAULT
 int		argnum_swap_strldbl(void){return ft_printf("%2$Lf, %1$s!", "world", 5.75L);} //CAN-SEGFAULT
 int		argnum_swap_ldblchar(void){return ft_printf("%2$c, %1$Lf!", 5.75L, 'c');} //CAN-SEGFAULT
 int		argnum_swap_charldbl(void){return ft_printf("%2$Lf, %1$c!", 'c', 5.75L);} //CAN-SEGFAULT
 int		argnum_swap_floatstr_around_pct(void){return ft_printf("%2$s %% %1$f!", 5.75, "abc");} //CAN-SEGFAULT
 int		argnum_swap_strfloat_around_pct(void){return ft_printf("%2$f %% %1$s!", "world", 5.75);} //CAN-SEGFAULT
 int		argnum_loopback_throwswarning(void){return ft_printf("%i %i %1$i %i %i", 1, 2, 3);} //CAN-SEGFAULT
 int		argnum_onlyone(void){return ft_printf("%1$s %1$s %1$s %1$s %1$s %1$s %1$s %1$s.", "buffalo");} //CAN-SEGFAULT
 int		argnum_start2thentofloatthen1_throwswarning(void){return ft_printf("%2$s %f %1$i", 5, "abc", 5.75f);} //CAN-SEGFAULT
 int		argnum_ultimate_1_throwswarning(void){return ft_printf("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);} //CAN-SEGFAULT
 int		argnum_ultimate_2_throwswarning(void){return ft_printf("%4$.5s %.4i %lli %1$Lf %c %7$20.6s %5$i %2$c %1$.2Lf %c %i", //CAN-SEGFAULT
			5.75l, 'c', -17, "Atlanta, GA", 54, 9879879879879ll, "baby shark");}
 int		argnum_ultimate_2_with_pct_throwswarning(void){return ft_printf("%% %4$.5s %.4i %lli %% %1$Lf %c %7$20.6s %5$i %% %2$c %1$.2Lf %c %i", //CAN-SEGFAULT
			5.75l, 'c', -17, "Atlanta, GA", 54, 9879879879879ll, "baby shark");}

//Mix tests
static unsigned int		mx_u = 235;
static long double			mx_Lf = 0.375l;
static double				mx_f = 0.625;
static long				mx_li =  4223372036854775800;
static long long			mx_lli = 3223372036654775200;
static char				mx_c = 'G';
static short				mx_hi = -3244;
static char				mx_hhi = 'F';
static char			   *mx_s = "Hello, World!";
static int					mx_i = 42;

int		mix_test_0(void){return ft_printf(
			"  %o    %u    %li    %s    %X    %lli  ",
			mx_u, mx_u, mx_li, mx_s, mx_u, mx_lli);}
int		mix_test_1(void){return ft_printf(
			"  %li    %u    %s    %X    %x    %Lf  ",
			mx_li, mx_u, mx_s, mx_u, mx_u, mx_Lf);}
int		mix_test_2(void){return ft_printf(
			"  %Lf    %p    %i    %li    %lli    %s  ",
			mx_Lf, &mx_i, mx_i, mx_li, mx_lli, mx_s);}
int		mix_test_3(void){return ft_printf(
			"  %x    %s    %i    %p    %X    %Lf  ",
			mx_u, mx_s, mx_i, &mx_i, mx_u, mx_Lf);}
int		mix_test_4(void){return ft_printf(
			"  %li    %hhi    %p    %o    %%    %Lf  ",
			mx_li, mx_c, &mx_i, mx_u, mx_Lf);}
int		mix_test_5(void){return ft_printf(
			"  %hi    %u    %x    %s    %i    %X  ",
			mx_hi, mx_u, mx_u, mx_s, mx_i, mx_u);}
int		mix_test_6(void){return ft_printf(
			"  %f    %li    %i    %p    %u    %hi  ",
			mx_f, mx_li, mx_i, &mx_i, mx_u, mx_hi);}
int		mix_test_7(void){return ft_printf(
			"  %u    %hhi    %p    %li    %Lf    %X  ",
			mx_u, mx_c, &mx_i, mx_li, mx_Lf, mx_u);}
int		mix_test_8(void){return ft_printf(
			"  %o    %Lf    %u    %li    %lli    %x  ",
			mx_u, mx_Lf, mx_u, mx_li, mx_lli, mx_u);}
int		mix_test_9(void){return ft_printf(
			"  %Lf    %li    %s    %p    %x    %o  ",
			mx_Lf, mx_li, mx_s, &mx_i, mx_u, mx_u);}
int		mix_test_10(void){return ft_printf(
			"  %hhi    %x    %s    %u    %i    %li  ",
			mx_c, mx_u, mx_s, mx_u, mx_i, mx_li);}
int		mix_test_11(void){return ft_printf(
			"  %X    %li    %o    %s    %f    %u  ",
			mx_u, mx_li, mx_u, mx_s, mx_f, mx_u);}
int		mix_test_12(void){return ft_printf(
			"  %o    %x    %i    %c    %hi    %Lf  ",
			mx_u, mx_u, mx_i, mx_c, mx_hi, mx_Lf);}
int		mix_test_13(void){return ft_printf(
			"  %c    %i    %hi    %o    %x    %u  ",
			mx_c, mx_i, mx_hi, mx_u, mx_u, mx_u);}
int		mix_test_14(void){return ft_printf(
			"  %i    %f    %li    %Lf    %X    %hhi  ",
			mx_i, mx_f, mx_li, mx_Lf, mx_u, mx_c);}
int		mix_test_15(void){return ft_printf(
			"  %s    %u    %lli    %Lf    %f    %o  ",
			mx_s, mx_u, mx_lli, mx_Lf, mx_f, mx_u);}
int		mix_test_16(void){return ft_printf(
			"  %hhi    %X    %u    %p    %x    %o  ",
			mx_c, mx_u, mx_u, &mx_i, mx_u, mx_u);}
int		mix_test_17(void){return ft_printf(
			"  %X    %i    %c    %lli    %o    %p  ",
			mx_u, mx_i, mx_c, mx_lli, mx_u, &mx_i);}
int		mix_test_18(void){return ft_printf(
			"  %X    %c    %x    %i    %hi    %s  ",
			mx_u, mx_c, mx_u, mx_i, mx_hi, mx_s);}
int		mix_test_19(void){return ft_printf(
			"  %hhi    %li    %x    %hi    %lli    %s  ",
			mx_c, mx_li, mx_u, mx_hi, mx_lli, mx_s);}
int		mix_test_20(void){return ft_printf(
			"  %Lf    %p    %lli    %hhi    %c    %f  ",
			mx_Lf, &mx_i, mx_lli, mx_c, mx_c, mx_f);}
int		mix_test_21(void){return ft_printf(
			"  %hi    %s    %hhi    %p    %lli    %u  ",
			mx_hi, mx_s, mx_c, &mx_i, mx_lli, mx_u);}
int		mix_test_22(void){return ft_printf(
			"  %p    %lli    %s    %X    %u    %hhi  ",
			&mx_i, mx_lli, mx_s, mx_u, mx_u, mx_c);}
int		mix_test_23(void){return ft_printf(
			"  %hhi    %f    %x    %o    %i    %X  ",
			mx_c, mx_f, mx_u, mx_u, mx_i, mx_u);}
int		mix_test_24(void){return ft_printf(
			"  %lli    %hhi    %hi    %i    %c    %o  ",
			mx_lli, mx_c, mx_hi, mx_i, mx_c, mx_u);}
int		mix_test_25(void){return ft_printf(
			"  %s    %Lf    %p    %c    %X    %x  ",
			mx_s, mx_Lf, &mx_i, mx_c, mx_u, mx_u);}
int		mix_test_26(void){return ft_printf(
			"  %lli    %i    %u    %p    %o    %c  ",
			mx_lli, mx_i, mx_u, &mx_i, mx_u, mx_c);}
int		mix_test_27(void){return ft_printf(
			"  %i    %p    %hhi    %X    %Lf    %lli  ",
			mx_i, &mx_i, mx_c, mx_u, mx_Lf, mx_lli);}
int		mix_test_28(void){return ft_printf(
			"  %f    %i    %p    %li    %o    %x  ",
			mx_f, mx_i, &mx_i, mx_li, mx_u, mx_u);}
int		mix_test_29(void){return ft_printf(
			"  %li    %lli    %f    %X    %o    %s  ",
			mx_li, mx_lli, mx_f, mx_u, mx_u, mx_s);}
int		mix_test_30(void){return ft_printf(
			"  %f    %hi    %p    %hhi    %li    %u  ",
			mx_f, mx_hi, &mx_i, mx_c, mx_li, mx_u);}
int		mix_test_31(void){return ft_printf(
			"  %s    %x    %u    %li    %o    %hi  ",
			mx_s, mx_u, mx_u, mx_li, mx_u, mx_hi);}
int		mix_test_32(void){return ft_printf(
			"  %u    %lli    %X    %i    %o    %f  ",
			mx_u, mx_lli, mx_u, mx_i, mx_u, mx_f);}
int		mix_test_33(void){return ft_printf(
			"  %o    %X    %u    %c    %lli    %hi  ",
			mx_u, mx_u, mx_u, mx_c, mx_lli, mx_hi);}
int		mix_test_34(void){return ft_printf(
			"  %hi    %X    %Lf    %s    %o    %x  ",
			mx_hi, mx_u, mx_Lf, mx_s, mx_u, mx_u);}
int		mix_test_35(void){return ft_printf(
			"  %X    %p    %o    %hi    %s    %lli  ",
			mx_u, &mx_i, mx_u, mx_hi, mx_s, mx_lli);}
int		mix_test_36(void){return ft_printf(
			"  %li    %p    %f    %Lf    %x    %lli  ",
			mx_li, &mx_i, mx_f, mx_Lf, mx_u, mx_lli);}
int		mix_test_37(void){return ft_printf(
			"  %i    %li    %X    %p    %hi    %o  ",
			mx_i, mx_li, mx_u, &mx_i, mx_hi, mx_u);}
int		mix_test_38(void){return ft_printf(
			"  %f    %u    %p    %hi    %hhi    %s  ",
			mx_f, mx_u, &mx_i, mx_hi, mx_c, mx_s);}
int		mix_test_39(void){return ft_printf(
			"  %o    %c    %li    %p    %hi    %f  ",
			mx_u, mx_c, mx_li, &mx_i, mx_hi, mx_f);}
int		mix_test_40(void){return ft_printf(
			"  %u    %X    %f    %hhi    %s    %o  ",
			mx_u, mx_u, mx_f, mx_c, mx_s, mx_u);}
int		mix_test_41(void){return ft_printf(
			"  %li    %x    %hhi    %X    %s    %lli  ",
			mx_li, mx_u, mx_c, mx_u, mx_s, mx_lli);}
int		mix_test_42(void){return ft_printf(
			"  %hi    %x    %i    %c    %hhi    %li  ",
			mx_hi, mx_u, mx_i, mx_c, mx_c, mx_li);}
int		mix_test_43(void){return ft_printf(
			"  %x    %X    %o    %s    %lli    %hhi  ",
			mx_u, mx_u, mx_u, mx_s, mx_lli, mx_c);}
int		mix_test_44(void){return ft_printf(
			"  %f    %x    %o    %hi    %li    %u  ",
			mx_f, mx_u, mx_u, mx_hi, mx_li, mx_u);}
int		mix_test_45(void){return ft_printf(
			"  %f    %hhi    %c    %X    %lli    %s  ",
			mx_f, mx_c, mx_c, mx_u, mx_lli, mx_s);}
int		mix_test_46(void){return ft_printf(
			"  %lli    %i    %hhi    %hi    %li    %Lf  ",
			mx_lli, mx_i, mx_c, mx_hi, mx_li, mx_Lf);}
int		mix_test_47(void){return ft_printf(
			"  %f    %c    %lli    %s    %hhi    %p  ",
			mx_f, mx_c, mx_lli, mx_s, mx_c, &mx_i);}
int		mix_test_48(void){return ft_printf(
			"  %f    %hhi    %li    %lli    %x    %p  ",
			mx_f, mx_c, mx_li, mx_lli, mx_u, &mx_i);}
int		mix_test_49(void){return ft_printf(
			"  %o    %lli    %hi    %f    %X    %hhi  ",
			mx_u, mx_lli, mx_hi, mx_f, mx_u, mx_c);}
int		mix_test_50(void){return ft_printf(
			"  %o    %u    %f    %i    %x    %hhi  ",
			mx_u, mx_u, mx_f, mx_i, mx_u, mx_c);}
int		mix_test_51(void){return ft_printf(
			"  %x    %u    %Lf    %hi    %o    %X  ",
			mx_u, mx_u, mx_Lf, mx_hi, mx_u, mx_u);}
int		mix_test_52(void){return ft_printf(
			"  %u    %Lf    %hi    %li    %X    %hhi  ",
			mx_u, mx_Lf, mx_hi, mx_li, mx_u, mx_c);}
int		mix_test_53(void){return ft_printf(
			"  %o    %c    %Lf    %hi    %s    %p  ",
			mx_u, mx_c, mx_Lf, mx_hi, mx_s, &mx_i);}
int		mix_test_54(void){return ft_printf(
			"  %s    %hhi    %X    %lli    %x    %u  ",
			mx_s, mx_c, mx_u, mx_lli, mx_u, mx_u);}
int		mix_test_55(void){return ft_printf(
			"  %x    %X    %o    %lli    %c    %u  ",
			mx_u, mx_u, mx_u, mx_lli, mx_c, mx_u);}
int		mix_test_56(void){return ft_printf(
			"  %hi    %u    %i    %x    %c    %s  ",
			mx_hi, mx_u, mx_i, mx_u, mx_c, mx_s);}
int		mix_test_57(void){return ft_printf(
			"  %hi    %s    %i    %X    %u    %li  ",
			mx_hi, mx_s, mx_i, mx_u, mx_u, mx_li);}
int		mix_test_58(void){return ft_printf(
			"  %c    %X    %li    %hi    %Lf    %p  ",
			mx_c, mx_u, mx_li, mx_hi, mx_Lf, &mx_i);}
int		mix_test_59(void){return ft_printf(
			"  %Lf    %hi    %c    %u    %hhi    %li  ",
			mx_Lf, mx_hi, mx_c, mx_u, mx_c, mx_li);}
int		mix_test_60(void){return ft_printf(
			"  %li    %p    %s    %hi    %u    %lli  ",
			mx_li, &mx_i, mx_s, mx_hi, mx_u, mx_lli);}
int		mix_test_61(void){return ft_printf(
			"  %li    %X    %Lf    %s    %c    %lli  ",
			mx_li, mx_u, mx_Lf, mx_s, mx_c, mx_lli);}
int		mix_test_62(void){return ft_printf(
			"  %lli    %hhi    %f    %o    %s    %X  ",
			mx_lli, mx_c, mx_f, mx_u, mx_s, mx_u);}
int		mix_test_63(void){return ft_printf(
			"  %x    %X    %u    %s    %li    %f  ",
			mx_u, mx_u, mx_u, mx_s, mx_li, mx_f);}
int		mix_test_64(void){return ft_printf(
			"  %hhi    %X    %u    %o    %Lf    %s  ",
			mx_c, mx_u, mx_u, mx_u, mx_Lf, mx_s);}
int		mix_test_65(void){return ft_printf(
			"  %li    %u    %x    %o    %lli    %s  ",
			mx_li, mx_u, mx_u, mx_u, mx_lli, mx_s);}
int		mix_test_66(void){return ft_printf(
			"  %hi    %f    %hhi    %u    %i    %p  ",
			mx_hi, mx_f, mx_c, mx_u, mx_i, &mx_i);}
int		mix_test_67(void){return ft_printf(
			"  %i    %c    %f    %hi    %s    %o  ",
			mx_i, mx_c, mx_f, mx_hi, mx_s, mx_u);}
int		mix_test_68(void){return ft_printf(
			"  %li    %s    %p    %f    %Lf    %X  ",
			mx_li, mx_s, &mx_i, mx_f, mx_Lf, mx_u);}
int		mix_test_69(void){return ft_printf(
			"  %s    %p    %Lf    %lli    %x    %o  ",
			mx_s, &mx_i, mx_Lf, mx_lli, mx_u, mx_u);}
int		mix_test_70(void){return ft_printf(
			"  %hhi    %hi    %Lf    %c    %x    %lli  ",
			mx_c, mx_hi, mx_Lf, mx_c, mx_u, mx_lli);}
int		mix_test_71(void){return ft_printf(
			"  %p    %u    %lli    %c    %Lf    %X  ",
			&mx_i, mx_u, mx_lli, mx_c, mx_Lf, mx_u);}
int		mix_test_72(void){return ft_printf(
			"  %X    %p    %f    %c    %o    %li  ",
			mx_u, &mx_i, mx_f, mx_c, mx_u, mx_li);}
int		mix_test_73(void){return ft_printf(
			"  %p    %c    %li    %lli    %x    %f  ",
			&mx_i, mx_c, mx_li, mx_lli, mx_u, mx_f);}
int		mix_test_74(void){return ft_printf(
			"  %u    %c    %li    %p    %o    %s  ",
			mx_u, mx_c, mx_li, &mx_i, mx_u, mx_s);}
int		mix_test_75(void){return ft_printf(
			"  %hhi    %lli    %s    %li    %hi    %c  ",
			mx_c, mx_lli, mx_s, mx_li, mx_hi, mx_c);}
int		mix_test_76(void){return ft_printf(
			"  %u    %x    %lli    %hi    %i    %hhi  ",
			mx_u, mx_u, mx_lli, mx_hi, mx_i, mx_c);}
int		mix_test_77(void){return ft_printf(
			"  %li    %hi    %Lf    %c    %o    %lli  ",
			mx_li, mx_hi, mx_Lf, mx_c, mx_u, mx_lli);}
int		mix_test_78(void){return ft_printf(
			"  %u    %i    %c    %p    %o    %f  ",
			mx_u, mx_i, mx_c, &mx_i, mx_u, mx_f);}
int		mix_test_79(void){return ft_printf(
			"  %Lf    %X    %p    %hhi    %c    %s  ",
			mx_Lf, mx_u, &mx_i, mx_c, mx_c, mx_s);}
int		mix_test_80(void){return ft_printf(
			"  %c    %hi    %u    %i    %f    %X  ",
			mx_c, mx_hi, mx_u, mx_i, mx_f, mx_u);}
int		mix_test_81(void){return ft_printf(
			"  %s    %p    %u    %Lf    %hhi    %li  ",
			mx_s, &mx_i, mx_u, mx_Lf, mx_c, mx_li);}
int		mix_test_82(void){return ft_printf(
			"  %X    %x    %i    %c    %Lf    %li  ",
			mx_u, mx_u, mx_i, mx_c, mx_Lf, mx_li);}
int		mix_test_83(void){return ft_printf(
			"  %X    %hi    %x    %u    %c    %o  ",
			mx_u, mx_hi, mx_u, mx_u, mx_c, mx_u);}
int		mix_test_84(void){return ft_printf(
			"  %hi    %Lf    %hhi    %li    %s    %lli  ",
			mx_hi, mx_Lf, mx_c, mx_li, mx_s, mx_lli);}
int		mix_test_85(void){return ft_printf(
			"  %Lf    %o    %f    %u    %X    %li  ",
			mx_Lf, mx_u, mx_f, mx_u, mx_u, mx_li);}
int		mix_test_86(void){return ft_printf(
			"  %f    %i    %lli    %hi    %u    %o  ",
			mx_f, mx_i, mx_lli, mx_hi, mx_u, mx_u);}
int		mix_test_87(void){return ft_printf(
			"  %i    %x    %lli    %c    %hi    %f  ",
			mx_i, mx_u, mx_lli, mx_c, mx_hi, mx_f);}
int		mix_test_88(void){return ft_printf(
			"  %u    %c    %x    %f    %p    %X  ",
			mx_u, mx_c, mx_u, mx_f, &mx_i, mx_u);}
int		mix_test_89(void){return ft_printf(
			"  %li    %c    %o    %f    %u    %lli  ",
			mx_li, mx_c, mx_u, mx_f, mx_u, mx_lli);}
int		mix_test_90(void){return ft_printf(
			"  %Lf    %o    %f    %li    %p    %s  ",
			mx_Lf, mx_u, mx_f, mx_li, &mx_i, mx_s);}
int		mix_test_91(void){return ft_printf(
			"  %X    %c    %p    %s    %i    %f  ",
			mx_u, mx_c, &mx_i, mx_s, mx_i, mx_f);}
int		mix_test_92(void){return ft_printf(
			"  %c    %hhi    %o    %X    %s    %lli  ",
			mx_c, mx_c, mx_u, mx_u, mx_s, mx_lli);}
int		mix_test_93(void){return ft_printf(
			"  %Lf    %hi    %c    %hhi    %s    %f  ",
			mx_Lf, mx_hi, mx_c, mx_c, mx_s, mx_f);}
int		mix_test_94(void){return ft_printf(
			"  %c    %u    %x    %lli    %hi    %s  ",
			mx_c, mx_u, mx_u, mx_lli, mx_hi, mx_s);}
int		mix_test_95(void){return ft_printf(
			"  %f    %u    %c    %x    %lli    %li  ",
			mx_f, mx_u, mx_c, mx_u, mx_lli, mx_li);}
int		mix_test_96(void){return ft_printf(
			"  %f    %hi    %li    %c    %x    %X  ",
			mx_f, mx_hi, mx_li, mx_c, mx_u, mx_u);}
int		mix_test_97(void){return ft_printf(
			"  %u    %Lf    %i    %f    %hhi    %hi  ",
			mx_u, mx_Lf, mx_i, mx_f, mx_c, mx_hi);}
int		mix_test_98(void){return ft_printf(
			"  %Lf    %s    %hi    %i    %f    %x  ",
			mx_Lf, mx_s, mx_hi, mx_i, mx_f, mx_u);}
int		mix_test_99(void){return ft_printf(
			"  %u    %f    %X    %c    %lli    %p  ",
			mx_u, mx_f, mx_u, mx_c, mx_lli, &mx_i);}
int		mix_test_100(void){return ft_printf(
			"  %X    %li    %f    %s    %hhi    %x  ",
			mx_u, mx_li, mx_f, mx_s, mx_c, mx_u);}
int		mix_test_101(void){return ft_printf(
			"  %o    %p    %s    %f    %X    %x  ",
			mx_u, &mx_i, mx_s, mx_f, mx_u, mx_u);}
int		mix_test_102(void){return ft_printf(
			"  %hhi    %c    %f    %x    %hi    %li  ",
			mx_c, mx_c, mx_f, mx_u, mx_hi, mx_li);}
int		mix_test_103(void){return ft_printf(
			"  %p    %Lf    %x    %X    %f    %s  ",
			&mx_i, mx_Lf, mx_u, mx_u, mx_f, mx_s);}
int		mix_test_104(void){return ft_printf(
			"  %s    %x    %lli    %i    %o    %p  ",
			mx_s, mx_u, mx_lli, mx_i, mx_u, &mx_i);}
int		mix_test_105(void){return ft_printf(
			"  %X    %s    %Lf    %p    %lli    %x  ",
			mx_u, mx_s, mx_Lf, &mx_i, mx_lli, mx_u);}
int		mix_test_106(void){return ft_printf(
			"  %c    %hhi    %hi    %x    %u    %li  ",
			mx_c, mx_c, mx_hi, mx_u, mx_u, mx_li);}
int		mix_test_107(void){return ft_printf(
			"  %li    %X    %s    %Lf    %f    %hhi  ",
			mx_li, mx_u, mx_s, mx_Lf, mx_f, mx_c);}
int		mix_test_108(void){return ft_printf(
			"  %u    %hhi    %s    %c    %p    %f  ",
			mx_u, mx_c, mx_s, mx_c, &mx_i, mx_f);}
int		mix_test_109(void){return ft_printf(
			"  %Lf    %s    %u    %f    %i    %X  ",
			mx_Lf, mx_s, mx_u, mx_f, mx_i, mx_u);}
int		mix_test_110(void){return ft_printf(
			"  %i    %p    %hi    %c    %f    %s  ",
			mx_i, &mx_i, mx_hi, mx_c, mx_f, mx_s);}
int		mix_test_111(void){return ft_printf(
			"  %p    %X    %lli    %hi    %Lf    %f  ",
			&mx_i, mx_u, mx_lli, mx_hi, mx_Lf, mx_f);}
int		mix_test_112(void){return ft_printf(
			"  %u    %c    %Lf    %lli    %o    %hhi  ",
			mx_u, mx_c, mx_Lf, mx_lli, mx_u, mx_c);}
int		mix_test_113(void){return ft_printf(
			"  %X    %i    %x    %c    %p    %s  ",
			mx_u, mx_i, mx_u, mx_c, &mx_i, mx_s);}
int		mix_test_114(void){return ft_printf(
			"  %x    %p    %f    %u    %hi    %o  ",
			mx_u, &mx_i, mx_f, mx_u, mx_hi, mx_u);}
int		mix_test_115(void){return ft_printf(
			"  %X    %hhi    %lli    %p    %li    %hi  ",
			mx_u, mx_c, mx_lli, &mx_i, mx_li, mx_hi);}
int		mix_test_116(void){return ft_printf(
			"  %lli    %c    %li    %o    %Lf    %x  ",
			mx_lli, mx_c, mx_li, mx_u, mx_Lf, mx_u);}
int		mix_test_117(void){return ft_printf(
			"  %lli    %s    %i    %Lf    %hhi    %x  ",
			mx_lli, mx_s, mx_i, mx_Lf, mx_c, mx_u);}
int		mix_test_118(void){return ft_printf(
			"  %o    %f    %Lf    %x    %p    %hhi  ",
			mx_u, mx_f, mx_Lf, mx_u, &mx_i, mx_c);}
int		mix_test_119(void){return ft_printf(
			"  %hhi    %p    %i    %hi    %o    %c  ",
			mx_c, &mx_i, mx_i, mx_hi, mx_u, mx_c);}
int		mix_test_120(void){return ft_printf(
			"  %X    %lli    %o    %li    %x    %p  ",
			mx_u, mx_lli, mx_u, mx_li, mx_u, &mx_i);}
int		mix_test_121(void){return ft_printf(
			"  %X    %s    %hi    %li    %c    %x  ",
			mx_u, mx_s, mx_hi, mx_li, mx_c, mx_u);}
int		mix_test_122(void){return ft_printf(
			"  %lli    %s    %f    %i    %Lf    %u  ",
			mx_lli, mx_s, mx_f, mx_i, mx_Lf, mx_u);}
int		mix_test_123(void){return ft_printf(
			"  %f    %lli    %x    %Lf    %o    %p  ",
			mx_f, mx_lli, mx_u, mx_Lf, mx_u, &mx_i);}
int		mix_test_124(void){return ft_printf(
			"  %hhi    %u    %lli    %x    %hi    %Lf  ",
			mx_c, mx_u, mx_lli, mx_u, mx_hi, mx_Lf);}
int		mix_test_125(void){return ft_printf(
			"  %c    %x    %hhi    %i    %Lf    %p  ",
			mx_c, mx_u, mx_c, mx_i, mx_Lf, &mx_i);}
int		mix_test_126(void){return ft_printf(
			"  %c    %Lf    %X    %x    %u    %i  ",
			mx_c, mx_Lf, mx_u, mx_u, mx_u, mx_i);}
int		mix_test_127(void){return ft_printf(
			"  %i    %p    %f    %o    %li    %Lf  ",
			mx_i, &mx_i, mx_f, mx_u, mx_li, mx_Lf);}
int		mix_test_128(void){return ft_printf(
			"  %hi    %o    %i    %Lf    %lli    %p  ",
			mx_hi, mx_u, mx_i, mx_Lf, mx_lli, &mx_i);}
int		mix_test_129(void){return ft_printf(
			"  %u    %c    %s    %lli    %X    %x  ",
			mx_u, mx_c, mx_s, mx_lli, mx_u, mx_u);}
int		mix_test_130(void){return ft_printf(
			"  %li    %f    %p    %hhi    %i    %u  ",
			mx_li, mx_f, &mx_i, mx_c, mx_i, mx_u);}
int		mix_test_131(void){return ft_printf(
			"  %u    %c    %p    %o    %hhi    %f  ",
			mx_u, mx_c, &mx_i, mx_u, mx_c, mx_f);}
int		mix_test_132(void){return ft_printf(
			"  %u    %Lf    %lli    %i    %f    %hi  ",
			mx_u, mx_Lf, mx_lli, mx_i, mx_f, mx_hi);}
int		mix_test_133(void){return ft_printf(
			"  %x    %s    %i    %hhi    %Lf    %li  ",
			mx_u, mx_s, mx_i, mx_c, mx_Lf, mx_li);}
int		mix_test_134(void){return ft_printf(
			"  %f    %p    %o    %hi    %x    %li  ",
			mx_f, &mx_i, mx_u, mx_hi, mx_u, mx_li);}
int		mix_test_135(void){return ft_printf(
			"  %p    %X    %s    %li    %u    %c  ",
			&mx_i, mx_u, mx_s, mx_li, mx_u, mx_c);}
int		mix_test_136(void){return ft_printf(
			"  %hhi    %o    %X    %p    %s    %li  ",
			mx_c, mx_u, mx_u, &mx_i, mx_s, mx_li);}
int		mix_test_137(void){return ft_printf(
			"  %p    %hhi    %i    %x    %X    %f  ",
			&mx_i, mx_c, mx_i, mx_u, mx_u, mx_f);}
int		mix_test_138(void){return ft_printf(
			"  %s    %li    %i    %x    %p    %o  ",
			mx_s, mx_li, mx_i, mx_u, &mx_i, mx_u);}
int		mix_test_139(void){return ft_printf(
			"  %i    %X    %lli    %u    %s    %hhi  ",
			mx_i, mx_u, mx_lli, mx_u, mx_s, mx_c);}
int		mix_test_140(void){return ft_printf(
			"  %p    %c    %x    %hi    %lli    %u  ",
			&mx_i, mx_c, mx_u, mx_hi, mx_lli, mx_u);}
int		mix_test_141(void){return ft_printf(
			"  %lli    %li    %x    %Lf    %s    %u  ",
			mx_lli, mx_li, mx_u, mx_Lf, mx_s, mx_u);}
int		mix_test_142(void){return ft_printf(
			"  %hhi    %o    %hi    %c    %s    %li  ",
			mx_c, mx_u, mx_hi, mx_c, mx_s, mx_li);}
int		mix_test_143(void){return ft_printf(
			"  %p    %hhi    %lli    %s    %c    %u  ",
			&mx_i, mx_c, mx_lli, mx_s, mx_c, mx_u);}
int		mix_test_144(void){return ft_printf(
			"  %x    %p    %i    %Lf    %u    %s  ",
			mx_u, &mx_i, mx_i, mx_Lf, mx_u, mx_s);}
int		mix_test_145(void){return ft_printf(
			"  %li    %hhi    %u    %i    %X    %o  ",
			mx_li, mx_c, mx_u, mx_i, mx_u, mx_u);}
int		mix_test_146(void){return ft_printf(
			"  %u    %c    %p    %hhi    %X    %f  ",
			mx_u, mx_c, &mx_i, mx_c, mx_u, mx_f);}
int		mix_test_147(void){return ft_printf(
			"  %hhi    %li    %p    %s    %Lf    %o  ",
			mx_c, mx_li, &mx_i, mx_s, mx_Lf, mx_u);}
int		mix_test_148(void){return ft_printf(
			"  %lli    %s    %X    %i    %hi    %c  ",
			mx_lli, mx_s, mx_u, mx_i, mx_hi, mx_c);}
int		mix_test_149(void){return ft_printf(
			"  %c    %p    %li    %X    %s    %lli  ",
			mx_c, &mx_i, mx_li, mx_u, mx_s, mx_lli);}
int		mix_test_150(void){return ft_printf(
			"  %X    %lli    %c    %i    %f    %u  ",
			mx_u, mx_lli, mx_c, mx_i, mx_f, mx_u);}
int		mix_test_151(void){return ft_printf(
			"  %Lf    %c    %hhi    %u    %hi    %x  ",
			mx_Lf, mx_c, mx_c, mx_u, mx_hi, mx_u);}
int		mix_test_152(void){return ft_printf(
			"  %li    %hi    %o    %s    %lli    %hhi  ",
			mx_li, mx_hi, mx_u, mx_s, mx_lli, mx_c);}
int		mix_test_153(void){return ft_printf(
			"  %Lf    %li    %hhi    %s    %p    %c  ",
			mx_Lf, mx_li, mx_c, mx_s, &mx_i, mx_c);}
int		mix_test_154(void){return ft_printf(
			"  %p    %X    %o    %u    %lli    %li  ",
			&mx_i, mx_u, mx_u, mx_u, mx_lli, mx_li);}
int		mix_test_155(void){return ft_printf(
			"  %li    %X    %u    %i    %f    %hi  ",
			mx_li, mx_u, mx_u, mx_i, mx_f, mx_hi);}
int		mix_test_156(void){return ft_printf(
			"  %Lf    %i    %X    %c    %hhi    %f  ",
			mx_Lf, mx_i, mx_u, mx_c, mx_c, mx_f);}
int		mix_test_157(void){return ft_printf(
			"  %p    %i    %Lf    %c    %li    %X  ",
			&mx_i, mx_i, mx_Lf, mx_c, mx_li, mx_u);}
int		mix_test_158(void){return ft_printf(
			"  %i    %p    %c    %f    %x    %li  ",
			mx_i, &mx_i, mx_c, mx_f, mx_u, mx_li);}
int		mix_test_159(void){return ft_printf(
			"  %li    %X    %f    %o    %s    %Lf  ",
			mx_li, mx_u, mx_f, mx_u, mx_s, mx_Lf);}
int		mix_test_160(void){return ft_printf(
			"  %li    %hi    %hhi    %lli    %Lf    %p  ",
			mx_li, mx_hi, mx_c, mx_lli, mx_Lf, &mx_i);}
int		mix_test_161(void){return ft_printf(
			"  %Lf    %hhi    %li    %c    %X    %hi  ",
			mx_Lf, mx_c, mx_li, mx_c, mx_u, mx_hi);}
int		mix_test_162(void){return ft_printf(
			"  %lli    %c    %o    %li    %u    %i  ",
			mx_lli, mx_c, mx_u, mx_li, mx_u, mx_i);}
int		mix_test_163(void){return ft_printf(
			"  %Lf    %li    %i    %lli    %hi    %c  ",
			mx_Lf, mx_li, mx_i, mx_lli, mx_hi, mx_c);}
int		mix_test_164(void){return ft_printf(
			"  %p    %lli    %hi    %x    %li    %Lf  ",
			&mx_i, mx_lli, mx_hi, mx_u, mx_li, mx_Lf);}
int		mix_test_165(void){return ft_printf(
			"  %u    %hhi    %p    %lli    %hi    %x  ",
			mx_u, mx_c, &mx_i, mx_lli, mx_hi, mx_u);}
int		mix_test_166(void){return ft_printf(
			"  %p    %hhi    %s    %li    %Lf    %hi  ",
			&mx_i, mx_c, mx_s, mx_li, mx_Lf, mx_hi);}
int		mix_test_167(void){return ft_printf(
			"  %s    %lli    %p    %i    %u    %hhi  ",
			mx_s, mx_lli, &mx_i, mx_i, mx_u, mx_c);}
int		mix_test_168(void){return ft_printf(
			"  %p    %o    %Lf    %X    %c    %u  ",
			&mx_i, mx_u, mx_Lf, mx_u, mx_c, mx_u);}
int		mix_test_169(void){return ft_printf(
			"  %p    %i    %X    %lli    %c    %hhi  ",
			&mx_i, mx_i, mx_u, mx_lli, mx_c, mx_c);}
int		mix_test_170(void){return ft_printf(
			"  %i    %lli    %p    %o    %X    %f  ",
			mx_i, mx_lli, &mx_i, mx_u, mx_u, mx_f);}
int		mix_test_171(void){return ft_printf(
			"  %f    %p    %c    %hi    %li    %i  ",
			mx_f, &mx_i, mx_c, mx_hi, mx_li, mx_i);}
int		mix_test_172(void){return ft_printf(
			"  %lli    %o    %i    %hhi    %c    %X  ",
			mx_lli, mx_u, mx_i, mx_c, mx_c, mx_u);}
int		mix_test_173(void){return ft_printf(
			"  %p    %hi    %lli    %X    %x    %o  ",
			&mx_i, mx_hi, mx_lli, mx_u, mx_u, mx_u);}
int		mix_test_174(void){return ft_printf(
			"  %hhi    %X    %u    %p    %x    %lli  ",
			mx_c, mx_u, mx_u, &mx_i, mx_u, mx_lli);}
int		mix_test_175(void){return ft_printf(
			"  %s    %Lf    %f    %hhi    %x    %o  ",
			mx_s, mx_Lf, mx_f, mx_c, mx_u, mx_u);}
int		mix_test_176(void){return ft_printf(
			"  %X    %f    %x    %o    %hi    %u  ",
			mx_u, mx_f, mx_u, mx_u, mx_hi, mx_u);}
int		mix_test_177(void){return ft_printf(
			"  %u    %hhi    %p    %o    %X    %x  ",
			mx_u, mx_c, &mx_i, mx_u, mx_u, mx_u);}
int		mix_test_178(void){return ft_printf(
			"  %f    %i    %lli    %o    %X    %c  ",
			mx_f, mx_i, mx_lli, mx_u, mx_u, mx_c);}
int		mix_test_179(void){return ft_printf(
			"  %lli    %o    %li    %X    %p    %c  ",
			mx_lli, mx_u, mx_li, mx_u, &mx_i, mx_c);}
int		mix_test_180(void){return ft_printf(
			"  %hi    %x    %i    %o    %c    %hhi  ",
			mx_hi, mx_u, mx_i, mx_u, mx_c, mx_c);}
int		mix_test_181(void){return ft_printf(
			"  %hi    %X    %hhi    %s    %lli    %c  ",
			mx_hi, mx_u, mx_c, mx_s, mx_lli, mx_c);}
int		mix_test_182(void){return ft_printf(
			"  %hhi    %c    %f    %Lf    %li    %i  ",
			mx_c, mx_c, mx_f, mx_Lf, mx_li, mx_i);}
int		mix_test_183(void){return ft_printf(
			"  %lli    %x    %hi    %c    %hhi    %i  ",
			mx_lli, mx_u, mx_hi, mx_c, mx_c, mx_i);}
int		mix_test_184(void){return ft_printf(
			"  %s    %X    %f    %x    %hi    %i  ",
			mx_s, mx_u, mx_f, mx_u, mx_hi, mx_i);}
int		mix_test_185(void){return ft_printf(
			"  %li    %hhi    %f    %Lf    %c    %o  ",
			mx_li, mx_c, mx_f, mx_Lf, mx_c, mx_u);}
int		mix_test_186(void){return ft_printf(
			"  %Lf    %i    %li    %u    %X    %hhi  ",
			mx_Lf, mx_i, mx_li, mx_u, mx_u, mx_c);}
int		mix_test_187(void){return ft_printf(
			"  %hi    %Lf    %f    %o    %s    %hhi  ",
			mx_hi, mx_Lf, mx_f, mx_u, mx_s, mx_c);}
int		mix_test_188(void){return ft_printf(
			"  %u    %x    %hi    %Lf    %lli    %X  ",
			mx_u, mx_u, mx_hi, mx_Lf, mx_lli, mx_u);}
int		mix_test_189(void){return ft_printf(
			"  %o    %u    %X    %s    %i    %hi  ",
			mx_u, mx_u, mx_u, mx_s, mx_i, mx_hi);}
int		mix_test_190(void){return ft_printf(
			"  %X    %s    %hhi    %u    %o    %lli  ",
			mx_u, mx_s, mx_c, mx_u, mx_u, mx_lli);}
int		mix_test_191(void){return ft_printf(
			"  %c    %f    %x    %lli    %u    %o  ",
			mx_c, mx_f, mx_u, mx_lli, mx_u, mx_u);}
int		mix_test_192(void){return ft_printf(
			"  %f    %u    %li    %x    %c    %hhi  ",
			mx_f, mx_u, mx_li, mx_u, mx_c, mx_c);}
int		mix_test_193(void){return ft_printf(
			"  %o    %i    %hi    %x    %hhi    %li  ",
			mx_u, mx_i, mx_hi, mx_u, mx_c, mx_li);}
int		mix_test_194(void){return ft_printf(
			"  %Lf    %s    %i    %c    %X    %li  ",
			mx_Lf, mx_s, mx_i, mx_c, mx_u, mx_li);}
int		mix_test_195(void){return ft_printf(
			"  %li    %s    %X    %o    %lli    %f  ",
			mx_li, mx_s, mx_u, mx_u, mx_lli, mx_f);}
int		mix_test_196(void){return ft_printf(
			"  %c    %o    %f    %Lf    %lli    %X  ",
			mx_c, mx_u, mx_f, mx_Lf, mx_lli, mx_u);}
int		mix_test_197(void){return ft_printf(
			"  %hi    %o    %i    %Lf    %li    %x  ",
			mx_hi, mx_u, mx_i, mx_Lf, mx_li, mx_u);}
int		mix_test_198(void){return ft_printf(
			"  %p    %i    %x    %Lf    %u    %o  ",
			&mx_i, mx_i, mx_u, mx_Lf, mx_u, mx_u);}
int		mix_test_199(void){return ft_printf(
			"  %f    %Lf    %c    %hi    %hhi    %li  ",
			mx_f, mx_Lf, mx_c, mx_hi, mx_c, mx_li);}


int		mix_test_extra_1(void){return ft_printf(
			"  %o    %f    %i    %%    %hhi    %Lf  ",
			mx_u, mx_f, mx_i, mx_c, mx_Lf);}
int		mix_test_extra_2(void){return ft_printf(
			"  %li    %Lf    %f    %i    %lli    %c  ",
			mx_li, mx_Lf, mx_f, mx_i, mx_lli, mx_c);}
int		mix_test_extra_3(void){return ft_printf(
			"  %li    %%    %f    %i    %lli    %c  ",
			mx_li, mx_f, mx_i, mx_lli, mx_c);}
int		mix_test_extra_4(void){return ft_printf(
			"  %%    %Lf    %f    %i    %%    %c  ",
			mx_Lf, mx_f, mx_i, mx_c);}
int		mix_test_extra_5(void){return ft_printf(
			"  %li    %Lf    %f    %%    %lli    %%  ",
			mx_li, mx_Lf, mx_f, mx_lli);}
int		mix_test_extra_6(void){return ft_printf(
			"  %li    %Lf    %f    %i    %lli    %c  ",
			mx_li, mx_Lf, mx_f, mx_i, mx_lli, mx_c);}
int		mix_test_extra_7(void){return ft_printf(
			"  %%    %Lf    %%    %i    %lli    %c  ",
			mx_Lf, mx_i, mx_lli, mx_c);}
int		mix_test_extra_8(void){return ft_printf(
			"  %%    %u    %hhi    %li    %hi    %x  ",
			mx_u, mx_c, mx_li, mx_hi, mx_u);}
int		mix_test_extra_9(void){return ft_printf(
			"  %c    %u    %hhi    %%    %hi    %x  ",
			mx_c, mx_u, mx_c, mx_hi, mx_u);}
int		mix_test_extra_10(void){return ft_printf(
			"  %c    %%    %hhi    %p    %hi    %x  ",
			mx_c, mx_hhi, &mx_c, mx_hi, mx_u);}

int		mix_successive_0(void){return ( ft_printf("%c", mx_c) + ft_printf("%u", mx_u));}
int		mix_successive_1(void){return ( ft_printf("%o", mx_u) + ft_printf("%%"));}
int		mix_successive_2(void){return ( ft_printf("%s", mx_s) + ft_printf("%Lf", mx_Lf));}
int		mix_successive_3(void){return ( ft_printf("%Lf", mx_Lf) + ft_printf("%hhi", mx_c));}
int		mix_successive_4(void){return ( ft_printf("%x", mx_u) + ft_printf("%i", mx_i));}
int		mix_successive_5(void){return ( ft_printf("%x", mx_u) + ft_printf("%o", mx_u));}
int		mix_successive_6(void){return ( ft_printf("%s", mx_s) + ft_printf("%c", mx_c));}
int		mix_successive_7(void){return ( ft_printf("%p", &mx_i) + ft_printf("%hi", mx_hi));}
int		mix_successive_8(void){return ( ft_printf("%f", mx_f) + ft_printf("%p", &mx_i));}
int		mix_successive_9(void){return ( ft_printf("%hi", mx_hi) + ft_printf("%u", mx_u));}
int		mix_successive_10(void){return ( ft_printf("%u", mx_u) + ft_printf("%s", mx_s));}
int		mix_successive_11(void){return ( ft_printf("%Lf", mx_Lf) + ft_printf("%p", &mx_i));}
int		mix_successive_12(void){return ( ft_printf("%f", mx_f) + ft_printf("%hhi", mx_c));}
int		mix_successive_13(void){return ( ft_printf("%X", mx_u) + ft_printf("%hhi", mx_c));}
int		mix_successive_14(void){return ( ft_printf("%X", mx_u) + ft_printf("%f", mx_f));}
int		mix_successive_15(void){return ( ft_printf("%hhi", mx_c) + ft_printf("%X", mx_u));}
int		mix_successive_16(void){return ( ft_printf("%s", mx_s) + ft_printf("%x", mx_u));}
int		mix_successive_17(void){return ( ft_printf("%lli", mx_lli) + ft_printf("%i", mx_i));}
int		mix_successive_18(void){return ( ft_printf("%s", mx_s) + ft_printf("%o", mx_u));}
int		mix_successive_19(void){return ( ft_printf("%hhi", mx_c) + ft_printf("%X", mx_u));}
int		mix_successive_20(void){return ( ft_printf("%p", &mx_i) + ft_printf("%s", mx_s));}
int		mix_successive_21(void){return ( ft_printf("%X", mx_u) + ft_printf("%x", mx_u));}
int		mix_successive_22(void){return ( ft_printf("%p", &mx_i) + ft_printf("%lli", mx_lli));}
int		mix_successive_23(void){return ( ft_printf("%s", mx_s) + ft_printf("%f", mx_f));}
int		mix_successive_24(void){return ( ft_printf("%c", mx_c) + ft_printf("%hhi", mx_c));}
int		mix_successive_25(void){return ( ft_printf("%x", mx_u) + ft_printf("%f", mx_f));}
int		mix_successive_26(void){return ( ft_printf("%s", mx_s) + ft_printf("%li", mx_li));}
int		mix_successive_27(void){return ( ft_printf("%f", mx_f) + ft_printf("%Lf", mx_Lf));}
int		mix_successive_28(void){return ( ft_printf("%i", mx_i) + ft_printf("%u", mx_u));}
int		mix_successive_29(void){return ( ft_printf("%o", mx_u) + ft_printf("%li", mx_li));}
int		mix_successive_30(void){return ( ft_printf("%s", mx_s) + ft_printf("%u", mx_u));}
int		mix_successive_31(void){return ( ft_printf("%X", mx_u) + ft_printf("%c", mx_c));}
int		mix_successive_32(void){return ( ft_printf("%x", mx_u) + ft_printf("%u", mx_u));}
int		mix_successive_33(void){return ( ft_printf("%Lf", mx_Lf) + ft_printf("%s", mx_s));}
int		mix_successive_34(void){return ( ft_printf("%hhi", mx_c) + ft_printf("%u", mx_u));}
int		mix_successive_35(void){return ( ft_printf("%p", &mx_i) + ft_printf("%f", mx_f));}
int		mix_successive_36(void){return ( ft_printf("%li", mx_li) + ft_printf("%o", mx_u));}
int		mix_successive_37(void){return ( ft_printf("%s", mx_s) + ft_printf("%li", mx_li));}
int		mix_successive_38(void){return ( ft_printf("%o", mx_u) + ft_printf("%lli", mx_lli));}
int		mix_successive_39(void){return ( ft_printf("%i", mx_i) + ft_printf("%c", mx_c));}
int		mix_successive_40(void){return ( ft_printf("%c", mx_c) + ft_printf("%x", mx_u));}
int		mix_successive_41(void){return ( ft_printf("%hhi", mx_c) + ft_printf("%x", mx_u));}
int		mix_successive_42(void){return ( ft_printf("%x", mx_u) + ft_printf("%s", mx_s));}
int		mix_successive_43(void){return ( ft_printf("%u", mx_u) + ft_printf("%x", mx_u));}
int		mix_successive_44(void){return ( ft_printf("%i", mx_i) + ft_printf("%f", mx_f));}
int		mix_successive_45(void){return ( ft_printf("%s", mx_s) + ft_printf("%c", mx_c));}
int		mix_successive_46(void){return ( ft_printf("%i", mx_i) + ft_printf("%s", mx_s));}
int		mix_successive_47(void){return ( ft_printf("%u", mx_u) + ft_printf("%hhi", mx_c));}
int		mix_successive_48(void){return ( ft_printf("%hi", mx_hi) + ft_printf("%o", mx_u));}
int		mix_successive_49(void){return ( ft_printf("%i", mx_i) + ft_printf("%hi", mx_hi));}
int		mix_successive_50(void){return ( ft_printf("%o", mx_u) + ft_printf("%Lf", mx_Lf));}
int		mix_successive_51(void){return ( ft_printf("%li", mx_li) + ft_printf("%hhi", mx_c));}
int		mix_successive_52(void){return ( ft_printf("%hi", mx_hi) + ft_printf("%hhi", mx_c));}
int		mix_successive_53(void){return ( ft_printf("%Lf", mx_Lf) + ft_printf("%x", mx_u));}
int		mix_successive_54(void){return ( ft_printf("%c", mx_c) + ft_printf("%hi", mx_hi));}
int		mix_successive_55(void){return ( ft_printf("%hi", mx_hi) + ft_printf("%s", mx_s));}
int		mix_successive_56(void){return ( ft_printf("%i", mx_i) + ft_printf("%lli", mx_lli));}
int		mix_successive_57(void){return ( ft_printf("%c", mx_c) + ft_printf("%Lf", mx_Lf));}
int		mix_successive_58(void){return ( ft_printf("%f", mx_f) + ft_printf("%x", mx_u));}
int		mix_successive_59(void){return ( ft_printf("%s", mx_s) + ft_printf("%li", mx_li));}
int		mix_successive_60(void){return ( ft_printf("%hhi", mx_c) + ft_printf("%s", mx_s));}
int		mix_successive_61(void){return ( ft_printf("%p", &mx_i) + ft_printf("%c", mx_c));}
int		mix_successive_62(void){return ( ft_printf("%lli", mx_lli) + ft_printf("%u", mx_u));}
int		mix_successive_63(void){return ( ft_printf("%x", mx_u) + ft_printf("%o", mx_u));}
int		mix_successive_64(void){return ( ft_printf("%s", mx_s) + ft_printf("%c", mx_c));}
int		mix_successive_65(void){return ( ft_printf("%i", mx_i) + ft_printf("%lli", mx_lli));}
int		mix_successive_66(void){return ( ft_printf("%li", mx_li) + ft_printf("%Lf", mx_Lf));}
int		mix_successive_67(void){return ( ft_printf("%hi", mx_hi) + ft_printf("%x", mx_u));}
int		mix_successive_68(void){return ( ft_printf("%i", mx_i) + ft_printf("%hi", mx_hi));}
int		mix_successive_69(void){return ( ft_printf("%Lf", mx_Lf) + ft_printf("%li", mx_li));}
int		mix_successive_70(void){return ( ft_printf("%o", mx_u) + ft_printf("%li", mx_li));}



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
int nocrash_mandatory_wformat_undefbehav_08(void){return ft_printf("%+u", 5);}
int nocrash_mandatory_wformat_undefbehav_09(void){return ft_printf("%+u", 5);}
int nocrash_mandatory_wformat_undefbehav_10(void){return ft_printf("%+u", 4294967295);}
int nocrash_mandatory_wformat_undefbehav_11(void){return ft_printf("%+5u", 35);}
int nocrash_mandatory_wformat_undefbehav_12(void){return ft_printf("%+7u", 0);}
int nocrash_mandatory_wformat_undefbehav_13(void){return ft_printf("%+24u", 4294967295);}
int nocrash_mandatory_wformat_undefbehav_14(void){return ft_printf("%+.7u", 234);}
int nocrash_mandatory_wformat_undefbehav_15(void){return ft_printf("%+.3u", 3723);}
int nocrash_mandatory_wformat_undefbehav_16(void){return ft_printf("%+05u", 432);}
int nocrash_mandatory_wformat_undefbehav_17(void){return ft_printf("%+04u", 0);}
int nocrash_mandatory_wformat_undefbehav_18(void){return ft_printf("%+8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_19(void){return ft_printf("%+8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_20(void){return ft_printf("%+8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_21(void){return ft_printf("%+3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_22(void){return ft_printf("%+3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_23(void){return ft_printf("%+-8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_24(void){return ft_printf("%+-8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_25(void){return ft_printf("%+-8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_26(void){return ft_printf("%+-3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_27(void){return ft_printf("%+-3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_28(void){return ft_printf("%0+8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_29(void){return ft_printf("%0+8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_30(void){return ft_printf("%0+8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_31(void){return ft_printf("%0+3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_32(void){return ft_printf("%0+3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_33(void){return ft_printf("%0+-8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_34(void){return ft_printf("%0+-8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_35(void){return ft_printf("%0+-8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_36(void){return ft_printf("%0+-3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_37(void){return ft_printf("%0+-3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_38(void){return ft_printf("%05c", '\0');}
int nocrash_mandatory_wformat_undefbehav_39(void){return ft_printf("%-05c", '\0');}
int nocrash_mandatory_wformat_undefbehav_40(void){return ft_printf("%+lu", 22337203685477);}

//nocrash tests adapted from tests contributed by phtruong
int nocrash_mandatory_dupflag_d_asas(void){return ft_printf("%++d", 42);}
int nocrash_mandatory_dupflag_d_spsp(void){return ft_printf("%  d", 42);}
int nocrash_mandatory_dupflag_d_spassp(void){return ft_printf("% + d", 42);}
int nocrash_mandatory_dupflag_d_ljljw(void){return ft_printf("%--5d", 42);}
int nocrash_mandatory_dupflag_d_ljasljw(void){return ft_printf("%-+-5d", 42);}
int nocrash_mandatory_dupflag_x_afaf(void){return ft_printf("%##x", 42);}
int nocrash_mandatory_dupflag_x_afasasafljw(void){return ft_printf("%#++#-5x", 42);}

//nocrash tests that came about as part of the minimal specification
int nocrash_mandatory_c_prec_1(void){return ft_printf("%.4c", 'a');}
int nocrash_mandatory_c_prec_2(void){return ft_printf("%.c", 'a');}
int nocrash_mandatory_c_af(void){return ft_printf("%#c", 'a');}
int nocrash_mandatory_c_zp_1(void){return ft_printf("%05c", 'a');}
int nocrash_mandatory_c_zp_2(void){return ft_printf("%0c", 'a');}
int nocrash_mandatory_c_as_1(void){return ft_printf("%+c", 'a');}
int nocrash_mandatory_c_as_2(void){return ft_printf("%+c", -42);}
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
int nocrash_mandatory_s_as_1(void){return ft_printf("%+s", "hello");}
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
int nocrash_mandatory_p_as_1(void){return ft_printf("%+p", &ncm_p);}
int nocrash_mandatory_p_as_2(void){return ft_printf("%+p", &ncm_p);}
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

int nocrash_mandatory_o_as(void){return ft_printf("%+o", 42);}
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
int nocrash_mandatory_u_as(void){return ft_printf("%+u", 42);}
int nocrash_mandatory_u_sp(void){return ft_printf("% u", 42);}
int nocrash_mandatory_u_size_hhh(void){return ft_printf("%hhhu", 42);}
int nocrash_mandatory_u_size_hhhh(void){return ft_printf("%hhhhu", 42);}
int nocrash_mandatory_u_size_hhl(void){return ft_printf("%hhlu", 42);}
int nocrash_mandatory_u_size_hhll(void){return ft_printf("%hhllu", 42);}
int nocrash_mandatory_u_size_llh(void){return ft_printf("%llhu", 42);}
int nocrash_mandatory_u_size_lll(void){return ft_printf("%lllu", 42);}
int nocrash_mandatory_u_lj_nowidth(void){return ft_printf("%-u", 42);}

int nocrash_mandatory_x_size_L(void){return ft_printf("%Lx", 42);}
int nocrash_mandatory_x_as(void){return ft_printf("%+x", 42);}
int nocrash_mandatory_x_sp(void){return ft_printf("% x", 42);}
int nocrash_mandatory_x_size_hhh(void){return ft_printf("%hhhx", 42);}
int nocrash_mandatory_x_size_hhhh(void){return ft_printf("%hhhhx", 42);}
int nocrash_mandatory_x_size_hhl(void){return ft_printf("%hhlx", 42);}
int nocrash_mandatory_x_size_hhll(void){return ft_printf("%hhllx", 42);}
int nocrash_mandatory_x_size_llh(void){return ft_printf("%llhx", 42);}
int nocrash_mandatory_x_size_lll(void){return ft_printf("%lllx", 42);}
int nocrash_mandatory_X_size_L(void){return ft_printf("%LX", 42);}
int nocrash_mandatory_X_as(void){return ft_printf("%+X", 42);}
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

int moul_ld_1_throwswarning(void){return ft_printf("%ld", 42);}
int moul_ld_2_throwswarning(void){return ft_printf("Kashim a %ld histoires à raconter", 1001);}
int moul_ld_3_throwswarning(void){return ft_printf("Il fait au moins %ld\n", -8000);}
int moul_ld_4_throwswarning(void){return ft_printf("%ld", -0);}
int moul_ld_5_throwswarning(void){return ft_printf("%ld", 0);}
int moul_ld_6_throwswarning(void){return ft_printf("%ld", INT_MAX);}
int moul_ld_7_throwswarning(void){return ft_printf("%ld", INT_MIN);}
int moul_ld_8_throwswarning(void){return ft_printf("%ld", INT_MIN - 1);}
int moul_ld_9_throwswarning(void){return ft_printf("%ld", INT_MAX + 1);}
int moul_ld_10_throwswarning(void){return ft_printf("%%ld 0000042 == |%ld|\n", 0000042);}
int moul_ld_11_throwswarning(void){return ft_printf("%%ld \t == |%ld|\n", '\t');}
int moul_ld_12_throwswarning(void){return ft_printf("%%ld Lydie == |%ld|\n", 'L'+'y'+'d'+'i'+'e');}

 int moul_D_1_notmandatory(void){return ft_printf("%D", 42);}
 int moul_D_2_notmandatory(void){return ft_printf("Kashim a %D histoires à raconter", 1001);}
 int moul_D_3_notmandatory(void){return ft_printf("Il fait au moins %D\n", -8000);}
 int moul_D_4_notmandatory(void){return ft_printf("%D", -0);}
 int moul_D_5_notmandatory(void){return ft_printf("%D", 0);}
 int moul_D_6_notmandatory(void){return ft_printf("%D", INT_MAX);}
 int moul_D_7_notmandatory(void){return ft_printf("%D", INT_MIN);}
 int moul_D_8_notmandatory(void){return ft_printf("%D", INT_MIN - 1);}
 int moul_D_9_notmandatory(void){return ft_printf("%D", INT_MAX + 1);}
 int moul_D_10_notmandatory(void){return ft_printf("%%D 0000042 == |%D|\n", 0000042);}
 int moul_D_11_notmandatory(void){return ft_printf("%%D \t == |%D|\n", '\t');}
 int moul_D_12_notmandatory(void){return ft_printf("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');}

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

int moul_f_1(void){return ft_printf("%f", (double)42);}
int moul_f_2(void){return ft_printf("Kashim a %f histoires à raconter", (double)1001);}
int moul_f_3(void){return ft_printf("Il fait au moins %f\n", (double)-8000);}
int moul_f_4(void){return ft_printf("%f", (double)-0);}
int moul_f_5(void){return ft_printf("%f", (double)0);}
int moul_f_6(void){return ft_printf("%f", (double)INT_MAX);}
int moul_f_7(void){return ft_printf("%f", (double)INT_MIN);}
int moul_f_7b(void){return ft_printf("%f", (double)INT_MIN - 1);}
int moul_f_8(void){return ft_printf("%f", (double)INT_MAX + 1);}
int moul_f_9(void){return ft_printf("%%f 0000042 == |%f|\n", (double)0000042);}
int moul_f_10(void){return ft_printf("%%f \t == |%f|\n", (double)'\t');}
int moul_f_11(void){return ft_printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_f_12(void){return ft_printf("%%f 42.42 == |%f|\n", 42.42);}
 int moul_F_1_notmandatory(void){return ft_printf("%F", (double)42);}
 int moul_F_2_notmandatory(void){return ft_printf("Kashim a %F histoires à raconter", (double)1001);}
 int moul_F_3_notmandatory(void){return ft_printf("Il fait au moins %F\n", (double)-8000);}
 int moul_F_4_notmandatory(void){return ft_printf("%F", (double)-0);}
 int moul_F_5_notmandatory(void){return ft_printf("%F", (double)0);}
 int moul_F_6_notmandatory(void){return ft_printf("%F", (double)INT_MAX);}
 int moul_F_7_notmandatory(void){return ft_printf("%F", (double)INT_MIN);}
 int moul_F_8_notmandatory(void){return ft_printf("%F", (double)INT_MIN - 1);}
 int moul_F_9_notmandatory(void){return ft_printf("%F", (double)INT_MAX + 1);}
 int moul_F_10_notmandatory(void){return ft_printf("%%F 0000042 == |%F|\n", (double)0000042);}
 int moul_F_11_notmandatory(void){return ft_printf("%%F \t == |%F|\n", (double)'\t');}
 int moul_F_12_notmandatory(void){return ft_printf("%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');}
 int moul_F_13_notmandatory(void){return ft_printf("%%F 42.42 == |%F|\n", 42.42);}
 int moul_F_14_notmandatory(void){return ft_printf("%%F 42.42 == |%.2F|\n", 42.42);}

int moul_o_1(void){return ft_printf("%o", 42);}
int moul_o_2(void){return ft_printf("Kashim a %o histoires à raconter", 1001);}
int moul_o_3(void){return ft_printf("Il fait au moins %o\n", -8000);}
int moul_o_4(void){return ft_printf("%o", -0);}
int moul_o_5(void){return ft_printf("%o", 0);}
int moul_o_6(void){return ft_printf("%o", INT_MAX);}
int moul_o_7(void){return ft_printf("%o", INT_MIN);}
int moul_o_8(void){return ft_printf("%o", INT_MIN - 1);}
int moul_o_9(void){return ft_printf("%o", INT_MAX + 1);}
int moul_o_10(void){return ft_printf("%%o 0000042 == |%o|\n", 0000042);}
int moul_o_11(void){return ft_printf("%%o \t == |%o|\n", '\t');}
int moul_o_12(void){return ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');}

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

int moul_hash_1(void){return ft_printf("%%#X 42 ==  %#X\n", 42);}
int moul_hash_2(void){return ft_printf("%%X 42 ==  %X\n", 42);}
int moul_hash_3(void){return ft_printf("%%#o 0 ==  %#o\n", 0);}
int moul_hash_4(void){return ft_printf("%%o 0 ==  %o\n", 0);}
int moul_hash_5(void){return ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);}
int moul_hash_6(void){return ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);}
int moul_hash_7(void){return ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);}
int moul_hash_8(void){return ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);}
int moul_hash_9(void){return ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);}
int moul_hash_10(void){return ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);}
int moul_hash_11(void){return ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);}
int moul_hash_12(void){return ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);}

int moul_prec_1(void){return ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");}
int moul_prec_2(void){return ft_printf("%% 4.5i 42 == |% 4.5i|\n", 42);}
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

int moul_as_1(void){return ft_printf("%%+i 42 == %+i\n", 42);}
int moul_as_2(void){return ft_printf("%%+d 42 == %+d\n", INT_MAX);}
int moul_as_3(void){return ft_printf("%%+i -42 == %+i\n", -42);}
int moul_as_4(void){return ft_printf("%%+04d 42 == %0+04d\n", 42);}

int moul_sp_1(void){return ft_printf("%%      i 42 == |%      i|\n", 42);}
int moul_sp_2(void){return ft_printf("%% i -42 == |% i|\n", -42);}
int moul_sp_3(void){return ft_printf("%% 4i 42 == |% 4i|\n", 42);}

 int moul_notmandatory_e_1(void){return ft_printf("%e", (double)42);}
 int moul_notmandatory_e_2(void){return ft_printf("Kashim a %e histoires à raconter", (double)1001);}
 int moul_notmandatory_e_3(void){return ft_printf("Il fait au moins %e\n", (double)-8000);}
 int moul_notmandatory_e_4(void){return ft_printf("%e", (double)-0);}
 int moul_notmandatory_e_5(void){return ft_printf("%e", (double)0);}
 int moul_notmandatory_e_6(void){return ft_printf("%e", (double)INT_MAX);}
 int moul_notmandatory_e_7(void){return ft_printf("%e", (double)INT_MIN);}
 int moul_notmandatory_e_8(void){return ft_printf("%e", (double)INT_MIN - 1);}
 int moul_notmandatory_e_9(void){return ft_printf("%e", (double)INT_MAX + 1);}
 int moul_notmandatory_e_10(void){return ft_printf("%%e 0000042 == |%e|\n", (double)0000042);}
 int moul_notmandatory_e_11(void){return ft_printf("%%e \t == |%e|\n", (double)'\t');}
 int moul_notmandatory_e_12(void){return ft_printf("%%e Lydie == |%e|\n", (double)'L'+'y'+'d'+'i'+'e');}
 int moul_notmandatory_e_13(void){return ft_printf("%%e 42.42 == |%e|\n", 42.42);}
 int moul_notmandatory_e_14(void){return ft_printf("%E", (double)42);}
 int moul_notmandatory_e_15(void){return ft_printf("Kashim a %E histoires à raconter", (double)1001);}
 int moul_notmandatory_e_16(void){return ft_printf("Il fait au moins %E\n", (double)-8000);}
 int moul_notmandatory_e_17(void){return ft_printf("%E", (double)-0);}
 int moul_notmandatory_e_18(void){return ft_printf("%E", (double)0);}
 int moul_notmandatory_e_19(void){return ft_printf("%E", (double)INT_MAX);}
 int moul_notmandatory_e_20(void){return ft_printf("%E", (double)INT_MIN);}
 int moul_notmandatory_e_21(void){return ft_printf("%E", (double)INT_MIN - 1);}
 int moul_notmandatory_e_22(void){return ft_printf("%E", (double)INT_MAX + 1);}
 int moul_notmandatory_e_23(void){return ft_printf("%%E 0000042 == |%E|\n", (double)0000042);}
 int moul_notmandatory_e_24(void){return ft_printf("%%E \t == |%E|\n", (double)'\t');}
 int moul_notmandatory_e_25(void){return ft_printf("%%E Lydie == |%E|\n", (double)'L'+'y'+'d'+'i'+'e');}
 int moul_notmandatory_e_26(void){return ft_printf("%%E 42.42 == |%E|\n", 42.42);}
 int moul_notmandatory_e_27(void){return ft_printf("%%E 42.42 == |%.2E|\n", 42.42);}

 int moul_notmandatory_g_1(void){return ft_printf("%g", (double)42);}
 int moul_notmandatory_g_2(void){return ft_printf("Kashim a %g histoires à raconter", (double)1001);}
 int moul_notmandatory_g_3(void){return ft_printf("Il fait au moins %g\n", (double)-8000);}
 int moul_notmandatory_g_4(void){return ft_printf("%g", (double)-0);}
 int moul_notmandatory_g_5(void){return ft_printf("%g", (double)0);}
 int moul_notmandatory_g_5b(void){return ft_printf("%g", (double)INT_MAX);}
 int moul_notmandatory_g_6(void){return ft_printf("%g", (double)INT_MIN);}
 int moul_notmandatory_g_7(void){return ft_printf("%g", (double)INT_MIN - 1);}
 int moul_notmandatory_g_8(void){return ft_printf("%g", (double)INT_MAX + 1);}
 int moul_notmandatory_g_9(void){return ft_printf("%%g 0000042 == |%g|\n", (double)0000042);}
 int moul_notmandatory_g_10(void){return ft_printf("%%g \t == |%g|\n", (double)'\t');}
 int moul_notmandatory_g_11(void){return ft_printf("%%g Lydie == |%g|\n", (double)'L'+'y'+'d'+'i'+'e');}
 int moul_notmandatory_g_12(void){return ft_printf("%%g 42.42 == |%g|\n", 42.42);}
 int moul_notmandatory_g_13(void){return ft_printf("%G", (double)42);}
 int moul_notmandatory_g_14(void){return ft_printf("Kashim a %G histoires à raconter", (double)1001);}
 int moul_notmandatory_g_15(void){return ft_printf("Il fait au moins %G\n", (double)-8000);}
 int moul_notmandatory_g_16(void){return ft_printf("%G", (double)-0);}
 int moul_notmandatory_g_17(void){return ft_printf("%G", (double)0);}
 int moul_notmandatory_g_18(void){return ft_printf("%G", (double)INT_MAX);}
 int moul_notmandatory_g_19(void){return ft_printf("%G", (double)INT_MIN);}
 int moul_notmandatory_g_20(void){return ft_printf("%G", (double)INT_MIN - 1);}
 int moul_notmandatory_g_21(void){return ft_printf("%G", (double)INT_MAX + 1);}
 int moul_notmandatory_g_22(void){return ft_printf("%%G 0000042 == |%G|\n", (double)0000042);}
 int moul_notmandatory_g_23(void){return ft_printf("%%G \t == |%G|\n", (double)'\t');}
 int moul_notmandatory_g_24(void){return ft_printf("%%G Lydie == |%G|\n", (double)'L'+'y'+'d'+'i'+'e');}
 int moul_notmandatory_g_25(void){return ft_printf("%%G 42.42 == |%G|\n", 42.42);}
 int moul_notmandatory_g_26(void){return ft_printf("%%G 42.42 == |%.2G|\n", 42.42);}

 int moul_notmandatory_a_1(void){return ft_printf("%a", (double)42);}
 int moul_notmandatory_a_2(void){return ft_printf("Kashim a %a histoires à raconter", (double)1001);}
 int moul_notmandatory_a_3(void){return ft_printf("Il fait au moins %a\n", (double)-8000);}
 int moul_notmandatory_a_4(void){return ft_printf("%a", (double)-0);}
 int moul_notmandatory_a_5(void){return ft_printf("%a", (double)0);}
 int moul_notmandatory_a_6(void){return ft_printf("%a", (double)INT_MAX);}
 int moul_notmandatory_a_7(void){return ft_printf("%a", (double)INT_MIN);}
 int moul_notmandatory_a_8(void){return ft_printf("%a", (double)INT_MIN - 1);}
 int moul_notmandatory_a_9(void){return ft_printf("%a", (double)INT_MAX + 1);}
 int moul_notmandatory_a_11(void){return ft_printf("%%a 0000042 == |%a|\n", (double)0000042);}
 int moul_notmandatory_a_12(void){return ft_printf("%%a \t == |%a|\n", (double)'\t');}
 int moul_notmandatory_a_13(void){return ft_printf("%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');}
 int moul_notmandatory_a_14(void){return ft_printf("%%a 42.42 == |%a|\n", 42.42);}
 int moul_notmandatory_a_15(void){return ft_printf("%A", (double)42);}
 int moul_notmandatory_a_16(void){return ft_printf("Kashim a %A histoires à raconter", (double)1001);}
 int moul_notmandatory_a_17(void){return ft_printf("Il fait au moins %A\n", (double)-8000);}
 int moul_notmandatory_a_18(void){return ft_printf("%A", (double)-0);}
 int moul_notmandatory_a_19(void){return ft_printf("%A", (double)0);}
 int moul_notmandatory_a_20(void){return ft_printf("%A", (double)INT_MAX);}
 int moul_notmandatory_a_21(void){return ft_printf("%A", (double)INT_MIN);}
 int moul_notmandatory_a_22(void){return ft_printf("%A", (double)INT_MIN - 1);}
 int moul_notmandatory_a_23(void){return ft_printf("%A", (double)INT_MAX + 1);}
 int moul_notmandatory_a_24(void){return ft_printf("%%A 0000042 == |%A|\n", (double)0000042);}
 int moul_notmandatory_a_25(void){return ft_printf("%%A \t == |%A|\n", (double)'\t');}
 int moul_notmandatory_a_26(void){return ft_printf("%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');}
 int moul_notmandatory_a_27(void){return ft_printf("%%A 42.42 == |%A|\n", 42.42);}
 int moul_notmandatory_a_28(void){return ft_printf("%%A 42.42 == |%.2A|\n", 42.42);}

 int moul_notmandatory_star_1(void){return ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");}
 int moul_notmandatory_star_2(void){return ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);}
 int moul_notmandatory_star_3(void){return ft_printf("%%*i 42 == |%*i|\n", 5, 42);}
 int moul_notmandatory_star_4(void){return ft_printf("%%*i 42 == |%*i|\n", 3, 42);}
 int moul_notmandatory_star_5(void){return ft_printf("%%*i 42 == |%*i|\n", 2, 42);}

 int moul_notmandatory_widechar_mix2_throwswarning(void){return ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");}
 int moul_notmandatory_widechar_basic1(void){wchar_t c = L'\x82'; return ft_printf("%C\n", c);}
 int moul_notmandatory_widechar_basic2(void){return ft_printf("%C\n", L'ø');}
 int moul_notmandatory_widestr_basic2(void){wchar_t wz[3] = L"@@"; return ft_printf("%ls", wz);}






#pragma clang diagnostic pop
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/06/21 17:34:47 by gfielder         ###   ########.fr       */
/*   Updated: 2019/05/27 19:43:41 by phtruong         ###   ########.fr       */
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
// multiple flags diff order same width and precision
int	s_undefbehav_4_flags_diff_order_1_bench(void){return printf("%+- 06.06s", s_hidden);}
int	s_undefbehav_4_flags_diff_order_2_bench(void){return printf("% 0+-6.06s", s_hidden);}
int	s_undefbehav_4_flags_diff_order_3_bench(void){return printf("%0 +-6.06s", s_hidden);}
int	s_undefbehav_4_flags_diff_order_4_bench(void){return printf("%+-0 6.06s", s_hidden);}
int	s_undefbehav_4_flags_diff_order_5_bench(void){return printf("%-+ 06.06s", s_hidden);}
int	s_undefbehav_4_flags_diff_order_6_bench(void){return printf("% -+06.06s", s_hidden);}
// multiple flags diff order width > precision
int	s_undefbehav_4_flags_sp_padded_diff_order_1_bench(void){return printf("%+- 07.06s", s_hidden);}
int	s_undefbehav_4_flags_sp_padded_diff_order_2_bench(void){return printf("% 0+-8.06s", s_hidden);}
int	s_undefbehav_4_flags_sp_padded_diff_order_3_bench(void){return printf("%0 +-9.06s", s_hidden);}
int	s_undefbehav_4_flags_sp_padded_diff_order_4_bench(void){return printf("%+-0 10.06s", s_hidden);}
int	s_undefbehav_4_flags_sp_padded_diff_order_5_bench(void){return printf("%-+ 011.06s", s_hidden);}
int	s_undefbehav_4_flags_sp_padded_diff_order_6_bench(void){return printf("% -+012.06s", s_hidden);}
// multiple flags diff order width > precision, truncated string
int	s_undefbehav_4_flags_as_lj_sp_zero_trunc_bench(void){return printf("%+- 06.04s", s_hidden);}
int	s_undefbehav_4_flags_sp_zero_as_lj_trunc_bench(void){return printf("% 0+-6.04s", s_hidden);}
int	s_undefbehav_4_flags_zero_sp_as_lj_trunc_bench(void){return printf("%0 +-6.04s", s_hidden);}
int	s_undefbehav_4_flags_as_lj_zero_sp_trunc_bench(void){return printf("%+-0 6.04s", s_hidden);}
int	s_undefbehav_4_flags_lj_as_sp_zero_trunc_bench(void){return printf("%-+ 06.04s", s_hidden);}
int	s_undefbehav_4_flags_sp_zero_lj_as_trunc_bench(void){return printf("% 0-+6.04s", s_hidden);}
// multiple flags diff order width < precision, excess precision
int	s_undefbehav_4_flags_as_lj_sp_zero__pads_bench(void){return printf("%+- 06.09s", s_hidden);}
int	s_undefbehav_4_flags_sp_zero_as_lj__pads_bench(void){return printf("% 0+-6.09s", s_hidden);}
int	s_undefbehav_4_flags_zero_sp_as_lj__pads_bench(void){return printf("%0 +-6.09s", s_hidden);}
int	s_undefbehav_4_flags_as_lj_zero_sp__pads_bench(void){return printf("%+-0 6.09s", s_hidden);}
int	s_undefbehav_4_flags_lj_as_sp_zero__pads_bench(void){return printf("%-+ 06.09s", s_hidden);}
int	s_undefbehav_4_flags_sp_zero_lj_as__pads_bench(void){return printf("% 0-+6.09s", s_hidden);}
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
// as and zero flags  width
int	s_undefbehav_as_0_width_3_bench(void){return printf("%+03s", s_hidden);}
int	s_undefbehav_as_0_width_9_bench(void){return printf("%+09s", s_hidden);}
// flag cancelling
int	s_undefbehav_lj_0_width_3_bench(void){return printf("%-03s", s_hidden);}
int	s_undefbehav_lj_0_width_9_bench(void){return printf("%-09s", s_hidden);}
int	s_undefbehav_as_sp_width_3_bench(void){return printf("%+ 3s", s_hidden);}
int	s_undefbehav_as_sp_width_6_bench(void){return printf("%+ 6s", s_hidden);}

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
//Signed integers  allsign ('+')
int		i_as_pos_bench(void){return printf("%+i", 5);}
int		i_as_neg_bench(void){return printf("%+i", -7);}
int		i_intmax_as_bench(void){return printf("%+i", 2147483647);}
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
//signed integers  field width and allsign
int		i_width_as_pos_bench(void){return printf("%+5i", 35);}
int		i_width_as_zero_bench(void){return printf("%+7i", 0);}
int		i_width_intmax_as_bench(void){return printf("%+24i", 2147483647);}
//signed integers with precision
int		i_prec_fits_pos_bench(void){return printf("%.5i", 2);}
int		i_prec_fits_neg_bench(void){return printf("%.6i", -3);}
int		i_prec_fits_zero_bench(void){return printf("%.3i", 0);}
int		i_prec_exactfit_pos_bench(void){return printf("%.4i", 5263);}
int		i_prec_exactfit_neg_bench(void){return printf("%.4i", -2372);}
int		i_prec_nofit_pos_bench(void){return printf("%.3i", 13862);}
int		i_prec_nofit_neg_bench(void){return printf("%.3i",-23646);}
int		i_prec_as_pos_bench(void){return printf("%+.7i", 234);}
int		i_prec_as_neg_bench(void){return printf("%+.7i", -446);}
int		i_prec_as_pos_nofit_bench(void){return printf("%+.3i", 3723);}
//Signed integers with zero field width padding
int		i_zp_pos_fits_bench(void){return printf("%05i", 43);}
int		i_zp_neg_fits_bench(void){return printf("%07i", -54);}
int		i_zp_zero_fits_bench(void){return printf("%03i", 0);}
int		i_zp_pos_exactfit_bench(void){return printf("%03i", 634);}
int		i_zp_neg_exactfit_bench(void){return printf("%04i", -532);}
int		i_zp_neg_minus1fit_bench(void){return printf("%04i", -4825);}
int		i_zp_as_fits_bench(void){return printf("%+05i", 432);}
int		i_zp_as_zero_bench(void){return printf("%+04i", 0);}
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
//Signed integers with field width and precision with allsign
int		i_prec_width_fit_fit_pos_as_bench(void){return printf("%+8.5i", 34);}
int		i_prec_width_fit_fit_neg_as_bench(void){return printf("%+10.5i", -216);}
int		i_prec_width_fit_fit_zero_as_bench(void){return printf("%+8.5i", 0);}
int		i_prec_width_nofit_fit_pos_as_bench(void){return printf("%+8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_as_bench(void){return printf("%+8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_as_bench(void){return printf("%+3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_as_bench(void){return printf("%+3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_as_bench(void){return printf("%+3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_as_bench(void){return printf("%+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int		i_prec_width_fit_fit_pos_ljas_bench(void){return printf("%+-8.5i", 34);}
int		i_prec_width_fit_fit_neg_ljas_bench(void){return printf("%+-10.5i", -216);}
int		i_prec_width_fit_fit_zero_ljas_bench(void){return printf("%+-8.5i", 0);}
int		i_prec_width_nofit_fit_pos_ljas_bench(void){return printf("%+-8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_ljas_bench(void){return printf("%+-8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_ljas_bench(void){return printf("%+-3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_ljas_bench(void){return printf("%+-3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_ljas_bench(void){return printf("%+-3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_ljas_bench(void){return printf("%+-3.3i", -8462);}
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
//Signed integers with field width and precision with allsign with zeropadding
int		i_prec_width_ff_pos_aszp_bench(void){return printf("%0+8.5i", 34);}
int		i_prec_width_ff_neg_aszp_bench(void){return printf("%0+10.5i", -216);}
int		i_prec_width_ff_zero_aszp_bench(void){return printf("%0+8.5i", 0);}
int		i_prec_width_nf_pos_aszp_bench(void){return printf("%0+8.3i", 8375);}
int		i_prec_width_nf_neg_aszp_bench(void){return printf("%0+8.3i", -8473);}
int		i_prec_width_fn_pos_aszp_bench(void){return printf("%0+3.7i", 3267);}
int		i_prec_width_fn_neg_aszp_bench(void){return printf("%0+3.7i", -2375);}
int		i_prec_width_nn_pos_aszp_bench(void){return printf("%0+3.3i", 6983);}
int		i_prec_width_nn_neg_aszp_bench(void){return printf("%0+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int		i_prec_width_ff_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-8.5i", 34);}
int		i_prec_width_ff_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-10.5i", -216);}
int		i_prec_width_ff_zero_ljaszp_ignoreflag_bench(void){return printf("%0+-8.5i", 0);}
int		i_prec_width_nf_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-8.3i", 8375);}
int		i_prec_width_nf_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-8.3i", -8473);}
int		i_prec_width_fn_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-3.7i", 3267);}
int		i_prec_width_fn_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-3.7i", -2375);}
int		i_prec_width_nn_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-3.3i", 6983);}
int		i_prec_width_nn_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-3.3i", -8462);}
//Signed integers of varying size modifiers









int		i_size_hh_pos_casted_bench(void){return printf("%hhi", (char)45);}
int		i_size_hh_neg_casted_bench(void){return printf("%hhi", (char)-45);}
int		i_size_h_pos_casted_bench(void){return printf("%hi", (short)385);}
int		i_size_h_neg_casted_bench(void){return printf("%hi", (short)-385);}
int		i_size_l_pos_casted_bench(void){return printf("%li", (long)32);}
int		i_size_l_neg_casted_bench(void){return printf("%li", (long)-32);}
int		i_size_ll_pos_casted_bench(void){return printf("%lli", (long long)43);}
int		i_size_ll_neg_casted_bench(void){return printf("%lli", (long long)-43);}
int		i_size_hh_pos_ref_bench(void){return printf("%hhi", ch_pos_1);}
int		i_size_hh_neg_ref_bench(void){return printf("%hhi", ch_neg_1);}
int		i_size_h_pos_ref_bench(void){return printf("%hi", sh_pos_1);}
int		i_size_h_neg_ref_bench(void){return printf("%hi", sh_neg_1);}
int		i_size_l_pos_ref_bench(void){return printf("%li", l_pos_1);}
int		i_size_l_pos_ref_lmax_bench(void){return printf("%li", lmax);}
int		i_size_ll_pos_ref_llmax_bench(void){return printf("%lli", llmax);}
int		i_size_l_neg_ref_bench(void){return printf("%li", l_neg_1);}
int		i_size_ll_pos_ref_bench(void){return printf("%lli", ll_pos_1);}
int		i_size_ll_neg_ref_bench(void){return printf("%lli", ll_neg_1);}
int		i_size_l_pos_big_bench(void){return printf("%li", 22337203685477);}
int		i_size_l_neg_big_bench(void){return printf("%li", -22337203685477);}
int		i_size_ll_pos_big_bench(void){return printf("%lli", 522337203685470ll);}
int		i_size_ll_neg_big_bench(void){return printf("%lli", -522337203685470ll);}
int		i_llmax_bench(void){return printf("%lli", 9223372036854775807ll);}
int		i_llmin_bench(void){return printf("%lli", llmin);}
int		i_lmax_bench(void){return printf("%li", 9223372036854775807l);}
int		i_lmin_bench(void){return printf("%li", lmin);}
int		i_hmax_bench(void){return printf("%hi", (short)32767);}
int		i_hmin_bench(void){return printf("%hi", (short)(-32768));}
int		i_hhmax_bench(void){return printf("%hhi", (char)127);}
int		i_hhmin_bench(void){return printf("%hhi", (char)(-128));}

//Signed integers of varying size modifiers with some other modifiers
int		i_size_l_pos_big_zp_bench(void){return printf("%037li", 22337203685477l);}
int		i_size_l_neg_big_prec_bench(void){return printf("%.37li", -22337203685477l);}
int		i_size_ll_pos_big_width_bench(void){return printf("%37lli", 522337203685470ll);}
int		i_size_ll_neg_big_lj_bench(void){return printf("%-37lli", -522337203685470ll);}
int		i_size_l_pos_big_as_bench(void){return printf("%+li", 22337203685477l);}
//Multiple signed integers in a row of varying sizes
int		i_size_follows_i_i_bench(void){return printf("[%i] [%i]", i_pos_1, i_pos_1);}
int		i_size_follows_i_l_bench(void){return printf("[%i] [%li]", i_pos_1, l_pos_1);}
int		i_size_follows_i_ll_bench(void){return printf("[%i] [%lli]", i_pos_1, ll_pos_1);}
int		i_size_follows_i_h_bench(void){return printf("[%i] [%hi]", i_pos_1, sh_pos_1);}
int		i_size_follows_i_hh_bench(void){return printf("[%i] [%hhi]", i_pos_1, ch_pos_1);}
int		i_size_ll_hh_ll_bench(void){return printf("%lli%hhi%lli", ll_pos_1, ch_neg_1, ll_neg_1);}
int		i_size_h_l_hh_bench(void){return printf("%hi%li%hhi", sh_pos_1, l_neg_1, ch_neg_1);}
int		i_size_l_hh_h_bench(void){return printf("%li%hhi%hi", l_neg_1, ch_pos_1, sh_pos_1);}
int		i_size_n_ll_hh_bench(void){return printf("%i%lli%hhi", i_pos_1, ll_neg_1, ch_pos_1);}
int		i_size_ll_n_l_bench(void){return printf("%lli%i%li", ll_neg_1, i_pos_1, l_pos_1);}
//Signed integers - space - no modifers
int		i_basic_i_pos_sp_bench(void){return printf("this % i number", 17);}
int		i_basic_i_neg_sp_bench(void){return printf("this % i number", -267);}
int		i_basic_i_zero_sp_bench(void){return printf("this % i number", 0);}
int		i_basic_i_onlypos_sp_bench(void){return printf("% i", 3);}
int		i_basic_i_onlyneg_sp_bench(void){return printf("% i", -1);}
int		i_basic_i_onlyzero_sp_bench(void){return printf("% i", 0);}
int		i_basic_i_pos_d_sp_bench(void){return printf("this % d number", 17);}
int		i_basic_i_neg_d_sp_bench(void){return printf("this % d number", -267);}
int		i_basic_i_zero_d_sp_bench(void){return printf("this % d number", 0);}
int		i_intmax_sp_bench(void){return printf("% i", 2147483647);}
int		i_intmin_sp_bench(void){return printf("% i", (int)(-2147483678));}
//Signed integers - space with allsign ('+')
int		i_assp_pos_ignoreflag_bench(void){return printf("% +i", 5);}
int		i_assp_neg_ignoreflag_bench(void){return printf("% +i", -7);}
int		i_intmax_assp_ignoreflag_bench(void){return printf("% +i", 2147483647);}
//Signed integers - space with field width
int		i_width_pos_fits_sp_bench(void){return printf("% 7i", 33);}
int		i_width_neg_fits_sp_bench(void){return printf("% 7i", -14);}
int		i_width_zero_fits_sp_bench(void){return printf("% 3i", 0);}
int		i_width_pos_exactfit_sp_bench(void){return printf("% 5i", 52625);}
int		i_width_neg_exactfit_sp_bench(void){return printf("% 5i", -2562);}
int		i_width_pos_nofit_sp_bench(void){return printf("% 4i", 94827);}
int		i_width_neg_nofit_sp_bench(void){return printf("% 4i", -2464);}
int		i_width_pos_fits_lj_sp_bench(void){return printf("% -7i", 33);}
int		i_width_neg_fits_lj_sp_bench(void){return printf("% -7i", -14);}
int		i_width_zero_fits_lj_sp_bench(void){return printf("% -3i", 0);}
int		i_width_pos_exactfit_lj_sp_bench(void){return printf("% -5i", 52625);}
int		i_width_neg_exactfit_lj_sp_bench(void){return printf("% -5i", -2562);}
int		i_width_pos_nofit_lj_sp_bench(void){return printf("% -4i", 94827);}
int		i_width_neg_nofit_lj_sp_bench(void){return printf("% -4i", -2464);}
//signed integers with field width and allsign
int		i_width_assp_pos_ignoreflag_bench(void){return printf("% +5i", 35);}
int		i_width_assp_zero_ignoreflag_bench(void){return printf("% +7i", 0);}
int		i_width_intmax_assp_ignoreflag_bench(void){return printf("% +24i", 2147483647);}
//signed integers with precision
int		i_prec_fits_pos_sp_bench(void){return printf("% .5i", 2);}
int		i_prec_fits_neg_sp_bench(void){return printf("% .6i", -3);}
int		i_prec_fits_zero_sp_bench(void){return printf("% .3i", 0);}
int		i_prec_exactfit_pos_sp_bench(void){return printf("% .4i", 5263);}
int		i_prec_exactfit_neg_sp_bench(void){return printf("% .4i", -2372);}
int		i_prec_nofit_pos_sp_bench(void){return printf("% .3i", 13862);}
int		i_prec_nofit_neg_sp_bench(void){return printf("% .3i",-23646);}
int		i_prec_assp_pos_ignoreflag_bench(void){return printf("% +.7i", 234);}
int		i_prec_assp_neg_ignoreflag_bench(void){return printf("% +.7i", -446);}
int		i_prec_assp_pos_nofit_ignoreflag_bench(void){return printf("% +.3i", 3723);}
//Signed integers - space with zero field width padding
int		i_zpsp_pos_fits_bench(void){return printf("% 05i", 43);}
int		i_zpsp_neg_fits_bench(void){return printf("% 07i", -54);}
int		i_zpsp_zero_fits_bench(void){return printf("% 03i", 0);}
int		i_zpsp_pos_exactfit_bench(void){return printf("% 03i", 634);}
int		i_zpsp_neg_exactfit_bench(void){return printf("% 04i", -532);}
int		i_zpsp_neg_minus1fit_bench(void){return printf("% 04i", -4825);}
int		i_zpassp_as_fits_ignoreflag_bench(void){return printf("% +05i", 432);}
int		i_zpassp_zero_ignoreflag_bench(void){return printf("% +04i", 0);}
//Signed integers - space with field width and precision
int		i_prec_width_fit_fit_pos_sp_bench(void){return printf("% 8.5i", 34);}
int		i_prec_width_fit_fit_neg_sp_bench(void){return printf("% 10.5i", -216);}
int		i_prec_width_fit_fit_zero_sp_bench(void){return printf("% 8.5i", 0);}
int		i_prec_width_nofit_fit_pos_sp_bench(void){return printf("% 8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_sp_bench(void){return printf("% 8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_sp_bench(void){return printf("% 3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_sp_bench(void){return printf("% 3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_sp_bench(void){return printf("% 3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_sp_bench(void){return printf("% 3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified
int		i_prec_width_fit_fit_pos_lj_sp_bench(void){return printf("% -8.5i", 34);}
int		i_prec_width_fit_fit_neg_lj_sp_bench(void){return printf("% -10.5i", -216);}
int		i_prec_width_fit_fit_zero_lj_sp_bench(void){return printf("% -8.5i", 0);}
int		i_prec_width_nofit_fit_pos_lj_sp_bench(void){return printf("% -8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_lj_sp_bench(void){return printf("% -8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_lj_sp_bench(void){return printf("% -3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_lj_sp_bench(void){return printf("% -3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_lj_sp_bench(void){return printf("% -3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_lj_sp_bench(void){return printf("% -3.3i", -8462);}
//Signed integers - space with field width and precision with allsign
int		i_prec_width_fit_fit_pos_assp_ignoreflag_bench(void){return printf("% +8.5i", 34);}
int		i_prec_width_fit_fit_neg_assp_ignoreflag_bench(void){return printf("% +10.5i", -216);}
int		i_prec_width_fit_fit_zero_assp_ignoreflag_bench(void){return printf("% +8.5i", 0);}
int		i_prec_width_nofit_fit_pos_assp_ignoreflag_bench(void){return printf("% +8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_assp_ignoreflag_bench(void){return printf("% +8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_assp_ignoreflag_bench(void){return printf("% +3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_assp_ignoreflag_bench(void){return printf("% +3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_assp_ignoreflag_bench(void){return printf("% +3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_assp_ignoreflag_bench(void){return printf("% +3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign
int		i_prec_width_fit_fit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-8.5i", 34);}
int		i_prec_width_fit_fit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-10.5i", -216);}
int		i_prec_width_fit_fit_zero_lj_assp_ignoreflag_bench(void){return printf("% +-8.5i", 0);}
int		i_prec_width_nofit_fit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-8.3i", 8375);}
int		i_prec_width_nofit_fit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-8.3i", -8473);}
int		i_prec_width_fit_nofit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-3.7i", 3267);}
int		i_prec_width_fit_nofit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-3.7i", -2375);}
int		i_prec_width_nofit_nofit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-3.3i", 6983);}
int		i_prec_width_nofit_nofit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-3.3i", -8462);}
//Signed integers - space with field width and precision with zeropadding
int		i_prec_width_ff_pos_zp_sp_bench(void){return printf("% 08.5i", 34);}
int		i_prec_width_ff_neg_zp_sp_bench(void){return printf("% 010.5i", -216);}
int		i_prec_width_ff_zero_zp_sp_bench(void){return printf("% 08.5i", 0);}
int		i_prec_width_nf_pos_zp_sp_bench(void){return printf("% 08.3i", 8375);}
int		i_prec_width_nf_neg_zp_sp_bench(void){return printf("% 08.3i", -8473);}
int		i_prec_width_fn_pos_zp_sp_bench(void){return printf("% 03.7i", 3267);}
int		i_prec_width_fn_neg_zp_sp_bench(void){return printf("% 03.7i", -2375);}
int		i_prec_width_nn_pos_zp_sp_bench(void){return printf("% 03.3i", 6983);}
int		i_prec_width_nn_neg_zp_sp_bench(void){return printf("% 03.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with zeropadding
int		i_prec_width_ff_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.5i", 34);}
int		i_prec_width_ff_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-10.5i", -216);}
int		i_prec_width_ff_zero_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.5i", 0);}
int		i_prec_width_nf_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.3i", 8375);}
int		i_prec_width_nf_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.3i", -8473);}
int		i_prec_width_fn_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.7i", 3267);}
int		i_prec_width_fn_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.7i", -2375);}
int		i_prec_width_nn_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.3i", 6983);}
int		i_prec_width_nn_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.3i", -8462);}
//Signed integers - space with field width and precision with allsign with zeropadding
int		i_prec_width_ff_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+8.5i", 34);}
int		i_prec_width_ff_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+10.5i", -216);}
int		i_prec_width_ff_zero_aszpsp_ignoreflag_bench(void){return printf("% 0+8.5i", 0);}
int		i_prec_width_nf_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+8.3i", 8375);}
int		i_prec_width_nf_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+8.3i", -8473);}
int		i_prec_width_fn_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+3.7i", 3267);}
int		i_prec_width_fn_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+3.7i", -2375);}
int		i_prec_width_nn_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+3.3i", 6983);}
int		i_prec_width_nn_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign with zeropadding
int		i_prec_width_ff_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.5i", 34);}
int		i_prec_width_ff_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-10.5i", -216);}
int		i_prec_width_ff_zero_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.5i", 0);}
int		i_prec_width_nf_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.3i", 8375);}
int		i_prec_width_nf_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.3i", -8473);}
int		i_prec_width_fn_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.7i", 3267);}
int		i_prec_width_fn_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.7i", -2375);}
int		i_prec_width_nn_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.3i", 6983);}
int		i_prec_width_nn_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.3i", -8462);}
//Signed integers - space of varying size modifiers
int		i_size_hh_pos_casted_sp_bench(void){return printf("% hhi", (char)45);}
int		i_size_hh_neg_casted_sp_bench(void){return printf("% hhi", (char)-45);}
int		i_size_h_pos_casted_sp_bench(void){return printf("% hi", (short)385);}
int		i_size_h_neg_casted_sp_bench(void){return printf("% hi", (short)-385);}
int		i_size_l_pos_casted_sp_bench(void){return printf("% li", (long)32);}
int		i_size_l_neg_casted_sp_bench(void){return printf("% li", (long)-32);}
int		i_size_ll_pos_casted_sp_bench(void){return printf("% lli", (long long)43);}
int		i_size_ll_neg_casted_sp_bench(void){return printf("% lli", (long long)-43);}
int		i_size_hh_pos_ref_sp_bench(void){return printf("% hhi", ch_pos_1);}
int		i_size_hh_neg_ref_sp_bench(void){return printf("% hhi", ch_neg_1);}
int		i_size_h_pos_ref_sp_bench(void){return printf("% hi", sh_pos_1);}
int		i_size_h_neg_ref_sp_bench(void){return printf("% hi", sh_neg_1);}
int		i_size_l_pos_ref_sp_bench(void){return printf("% li", l_pos_1);}
int		i_size_l_neg_ref_sp_bench(void){return printf("% li", l_neg_1);}
int		i_size_ll_pos_ref_sp_bench(void){return printf("% lli", ll_pos_1);}
int		i_size_ll_neg_ref_sp_bench(void){return printf("% lli", ll_neg_1);}
int		i_size_l_pos_big_sp_bench(void){return printf("% li", 22337203685477l);}
int		i_size_l_neg_big_sp_bench(void){return printf("% li", -22337203685477l);}
int		i_size_ll_pos_big_sp_bench(void){return printf("% lli", 522337203685470ll);}
int		i_size_ll_neg_big_sp_bench(void){return printf("% lli", -522337203685470ll);}
int		i_llmax_sp_bench(void){return printf("% lli", 9223372036854775807ll);}
int		i_llmin_sp_bench(void){return printf("% lli", llmin);}
int		i_lmax_sp_bench(void){return printf("% li", 9223372036854775807l);}
int		i_lmin_sp_bench(void){return printf("% li", lmin);}
int		i_hmax_sp_bench(void){return printf("% hi", (short)32767);}
int		i_hmin_sp_bench(void){return printf("% hi", (short)(-32768));}
int		i_hhmax_sp_bench(void){return printf("% hhi", (char)(127));}
int		i_hhmin_sp_bench(void){return printf("% hhi", (char)(-128));}
 //Signed integers - zero precision zero value
int i_prec0val0_basic_bench(void){return printf("%.0i", 0);}
int i_prec0val0_implicit_bench(void){return printf("%.i", 0);}
int i_prec0val0_w_bench(void){return printf("%5.0i", 0);}
int i_prec0val0_w_impl_bench(void){return printf("%5.i", 0);}
int i_prec0val0_wlj_bench(void){return printf("%-5.0i", 0);}
int i_prec0val0_wlj_impl_bench(void){return printf("%-5.i", 0);}
int i_prec0val0_as_bench(void){return printf("%+.0i", 0);}
int i_prec0val0_as_impl_bench(void){return printf("%+.i", 0);}
int i_prec0val0_was_bench(void){return printf("%+5.0i", 0);}
int i_prec0val0_was_impl_bench(void){return printf("%+5.i", 0);}
int i_prec0val0_waslj_bench(void){return printf("%+-5.0i", 0);}
int i_prec0val0_waslj_impl_bench(void){return printf("%+-5.i", 0);}
//Signed integers - some out of range h, hh tests from filechecker
int i_ftfc_hhdoutofrange1_might_be_undefbehav_bench(void){return printf("%hhi", -129);}
int i_ftfc_hhdoutofrange2_might_be_undefbehav_bench(void){return printf("%hhi", 128);}
int i_ftfc_hdoutofrange1_might_be_undefbehav_bench(void){return printf("%hi", 32768);}
int i_ftfc_hdoutofrange2_might_be_undefbehav_bench(void){return printf("%hi", -32769);}


//Signed integers - no modifers
int	 d_basic_i_pos_bench(void){return printf("this %d number", 17);}
int	 d_basic_i_neg_bench(void){return printf("this %d number", -267);}
int	 d_basic_i_zero_bench(void){return printf("this %d number", 0);}
int	 d_basic_i_onlypos_bench(void){return printf("%d", 3);}
int	 d_basic_i_onlyneg_bench(void){return printf("%d", -1);}
int	 d_basic_i_onlyzero_bench(void){return printf("%d", 0);}
int	 d_intmax_bench(void){return printf("%d",  2147483647);}
int	 d_intmin_bench(void){return printf("%d", (int)(-2147483678));}
//Signed integers with allsign ('+')
int	 d_as_pos_bench(void){return printf("%+d", 5);}
int	 d_as_neg_bench(void){return printf("%+d", -7);}
int	 d_intmax_as_bench(void){return printf("%+d", 2147483647);}
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
//signed integers with field width and allsign
int	 d_width_as_pos_bench(void){return printf("%+5d", 35);}
int	 d_width_as_zero_bench(void){return printf("%+7d", 0);}
int	 d_width_intmax_as_bench(void){return printf("%+24d", 2147483647);}
//signed integers with precision
int	 d_prec_fits_pos_bench(void){return printf("%.5d", 2);}
int	 d_prec_fits_neg_bench(void){return printf("%.6d", -3);}
int	 d_prec_fits_zero_bench(void){return printf("%.3d", 0);}
int	 d_prec_exactfit_pos_bench(void){return printf("%.4d", 5263);}
int	 d_prec_exactfit_neg_bench(void){return printf("%.4d", -2372);}
int	 d_prec_nofit_pos_bench(void){return printf("%.3d", 13862);}
int	 d_prec_nofit_neg_bench(void){return printf("%.3d",-23646);}
int	 d_prec_as_pos_bench(void){return printf("%+.7d", 234);}
int	 d_prec_as_neg_bench(void){return printf("%+.7d", -446);}
int	 d_prec_as_pos_nofit_bench(void){return printf("%+.3d", 3723);}
//Signed integers with zero field width padding
int	 d_zp_pos_fits_bench(void){return printf("%05d", 43);}
int	 d_zp_neg_fits_bench(void){return printf("%07d", -54);}
int	 d_zp_zero_fits_bench(void){return printf("%03d", 0);}
int	 d_zp_pos_exactfit_bench(void){return printf("%03d", 634);}
int	 d_zp_neg_exactfit_bench(void){return printf("%04d", -532);}
int	 d_zp_neg_minus1fit_bench(void){return printf("%04d", -4825);}
int	 d_zp_as_fits_bench(void){return printf("%+05d", 432);}
int	 d_zp_as_zero_bench(void){return printf("%+04d", 0);}
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
//Signed integers with field width and precision with allsign
int	 d_prec_width_fit_fit_pos_as_bench(void){return printf("%+8.5d", 34);}
int	 d_prec_width_fit_fit_neg_as_bench(void){return printf("%+10.5d", -216);}
int	 d_prec_width_fit_fit_zero_as_bench(void){return printf("%+8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_as_bench(void){return printf("%+8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_as_bench(void){return printf("%+8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_as_bench(void){return printf("%+3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_as_bench(void){return printf("%+3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_as_bench(void){return printf("%+3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_as_bench(void){return printf("%+3.3d", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int	 d_prec_width_fit_fit_pos_ljas_bench(void){return printf("%+-8.5d", 34);}
int	 d_prec_width_fit_fit_neg_ljas_bench(void){return printf("%+-10.5d", -216);}
int	 d_prec_width_fit_fit_zero_ljas_bench(void){return printf("%+-8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_ljas_bench(void){return printf("%+-8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_ljas_bench(void){return printf("%+-8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_ljas_bench(void){return printf("%+-3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_ljas_bench(void){return printf("%+-3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_ljas_bench(void){return printf("%+-3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_ljas_bench(void){return printf("%+-3.3d", -8462);}
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
//Signed integers with field width and precision with allsign with zeropadding
int	 d_prec_width_ff_pos_aszp_bench(void){return printf("%0+8.5d", 34);}
int	 d_prec_width_ff_neg_aszp_bench(void){return printf("%0+10.5d", -216);}
int	 d_prec_width_ff_zero_aszp_bench(void){return printf("%0+8.5d", 0);}
int	 d_prec_width_nf_pos_aszp_bench(void){return printf("%0+8.3d", 8375);}
int	 d_prec_width_nf_neg_aszp_bench(void){return printf("%0+8.3d", -8473);}
int	 d_prec_width_fn_pos_aszp_bench(void){return printf("%0+3.7d", 3267);}
int	 d_prec_width_fn_neg_aszp_bench(void){return printf("%0+3.7d", -2375);}
int	 d_prec_width_nn_pos_aszp_bench(void){return printf("%0+3.3d", 6983);}
int	 d_prec_width_nn_neg_aszp_bench(void){return printf("%0+3.3d", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int	 d_prec_width_ff_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-8.5d", 34);}
int	 d_prec_width_ff_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-10.5d", -216);}
int	 d_prec_width_ff_zero_ljaszp_ignoreflag_bench(void){return printf("%0+-8.5d", 0);}
int	 d_prec_width_nf_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljaszp_ignoreflag_bench(void){return printf("%0+-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljaszp_ignoreflag_bench(void){return printf("%0+-3.3d", -8462);}
//Signed integers of varying size modifiers
int	 d_size_hh_pos_casted_bench(void){return printf("%hhd", (char)45);}
int	 d_size_hh_neg_casted_bench(void){return printf("%hhd", (char)-45);}
int	 d_size_h_pos_casted_bench(void){return printf("%hd", (short)385);}
int	 d_size_h_neg_casted_bench(void){return printf("%hd", (short)-385);}
int	 d_size_l_pos_casted_bench(void){return printf("%ld", (long)32);}
int	 d_size_l_neg_casted_bench(void){return printf("%ld", (long)-32);}
int	 d_size_ll_pos_casted_bench(void){return printf("%lld", (long long)43);}
int	 d_size_ll_neg_casted_bench(void){return printf("%lld", (long long)-43);}
int	 d_size_hh_pos_ref_bench(void){return printf("%hhd", ch_pos_1);}
int	 d_size_hh_neg_ref_bench(void){return printf("%hhd", ch_neg_1);}
int	 d_size_h_pos_ref_bench(void){return printf("%hd", sh_pos_1);}
int	 d_size_h_neg_ref_bench(void){return printf("%hd", sh_neg_1);}
int	 d_size_l_pos_ref_bench(void){return printf("%ld", l_pos_1);}
int	 d_size_l_pos_ref_lmax_bench(void){return printf("%ld", lmax);}
int	 d_size_ll_pos_ref_llmax_bench(void){return printf("%lld", llmax);}
int	 d_size_l_neg_ref_bench(void){return printf("%ld", l_neg_1);}
int	 d_size_ll_pos_ref_bench(void){return printf("%lld", ll_pos_1);}
int	 d_size_ll_neg_ref_bench(void){return printf("%lld", ll_neg_1);}
int	 d_size_l_pos_big_bench(void){return printf("%ld", 22337203685477);}
int	 d_size_l_neg_big_bench(void){return printf("%ld", -22337203685477);}
int	 d_size_ll_pos_big_bench(void){return printf("%lld", 522337203685470ll);}
int	 d_size_ll_neg_big_bench(void){return printf("%lld", -522337203685470ll);}
int	 d_llmax_bench(void){return printf("%lld", 9223372036854775807ll);}
int	 d_llmin_bench(void){return printf("%lld", llmin);}
int	 d_lmax_bench(void){return printf("%ld", 9223372036854775807l);}
int	 d_lmin_bench(void){return printf("%ld", lmin);}
int	 d_hmax_bench(void){return printf("%hd", (short)32767);}
int	 d_hmin_bench(void){return printf("%hd", (short)(-32768));}
int	 d_hhmax_bench(void){return printf("%hhd", (char)127);}
int	 d_hhmin_bench(void){return printf("%hhd", (char)(-128));}

//Signed integers of varying size modifiers with some other modifiers
int	 d_size_l_pos_big_zp_bench(void){return printf("%037ld", 22337203685477l);}
int	 d_size_l_neg_big_prec_bench(void){return printf("%.37ld", -22337203685477l);}
int	 d_size_ll_pos_big_width_bench(void){return printf("%37lld", 522337203685470ll);}
int	 d_size_ll_neg_big_lj_bench(void){return printf("%-37lld", -522337203685470ll);}
int	 d_size_l_pos_big_as_bench(void){return printf("%+ld", 22337203685477l);}
//Multiple signed integers in a row of varying sizes
int	 d_size_follows_i_i_bench(void){return printf("[%d] [%d]", i_pos_1, i_pos_1);}
int	 d_size_follows_i_l_bench(void){return printf("[%d] [%ld]", i_pos_1, l_pos_1);}
int	 d_size_follows_i_ll_bench(void){return printf("[%d] [%lld]", i_pos_1, ll_pos_1);}
int	 d_size_follows_i_h_bench(void){return printf("[%d] [%hd]", i_pos_1, sh_pos_1);}
int	 d_size_follows_i_hh_bench(void){return printf("[%d] [%hhd]", i_pos_1, ch_pos_1);}
int	 d_size_ll_hh_ll_bench(void){return printf("%lld%hhd%lld", ll_pos_1, ch_neg_1, ll_neg_1);}
int	 d_size_h_l_hh_bench(void){return printf("%hd%ld%hhd", sh_pos_1, l_neg_1, ch_neg_1);}
int	 d_size_l_hh_h_bench(void){return printf("%ld%hhd%hd", l_neg_1, ch_pos_1, sh_pos_1);}
int	 d_size_n_ll_hh_bench(void){return printf("%d%lld%hhd", i_pos_1, ll_neg_1, ch_pos_1);}
int	 d_size_ll_n_l_bench(void){return printf("%lli%d%ld", ll_neg_1, i_pos_1, l_pos_1);}
//Signed integers - space - no modifers
int	 d_basic_i_pos_sp_bench(void){return printf("this % d number", 17);}
int	 d_basic_i_neg_sp_bench(void){return printf("this % d number", -267);}
int	 d_basic_i_zero_sp_bench(void){return printf("this % d number", 0);}
int	 d_basic_i_onlypos_sp_bench(void){return printf("% d", 3);}
int	 d_basic_i_onlyneg_sp_bench(void){return printf("% d", -1);}
int	 d_basic_i_onlyzero_sp_bench(void){return printf("% d", 0);}
int	 d_basic_i_pos_d_sp_bench(void){return printf("this % d number", 17);}
int	 d_basic_i_neg_d_sp_bench(void){return printf("this % d number", -267);}
int	 d_basic_i_zero_d_sp_bench(void){return printf("this % d number", 0);}
int	 d_intmax_sp_bench(void){return printf("% d", 2147483647);}
int	 d_intmin_sp_bench(void){return printf("% d", (int)(-2147483678));}
//Signed integers - space with allsign ('+')
int	 d_assp_pos_ignoreflag_bench(void){return printf("% +d", 5);}
int	 d_assp_neg_ignoreflag_bench(void){return printf("% +d", -7);}
int	 d_intmax_assp_ignoreflag_bench(void){return printf("% +d", 2147483647);}
//Signed integers - space with field width
int	 d_width_pos_fits_sp_bench(void){return printf("% 7d", 33);}
int	 d_width_neg_fits_sp_bench(void){return printf("% 7d", -14);}
int	 d_width_zero_fits_sp_bench(void){return printf("% 3d", 0);}
int	 d_width_pos_exactfit_sp_bench(void){return printf("% 5d", 52625);}
int	 d_width_neg_exactfit_sp_bench(void){return printf("% 5d", -2562);}
int	 d_width_pos_nofit_sp_bench(void){return printf("% 4d", 94827);}
int	 d_width_neg_nofit_sp_bench(void){return printf("% 4d", -2464);}
int	 d_width_pos_fits_lj_sp_bench(void){return printf("% -7d", 33);}
int	 d_width_neg_fits_lj_sp_bench(void){return printf("% -7d", -14);}
int	 d_width_zero_fits_lj_sp_bench(void){return printf("% -3d", 0);}
int	 d_width_pos_exactfit_lj_sp_bench(void){return printf("% -5d", 52625);}
int	 d_width_neg_exactfit_lj_sp_bench(void){return printf("% -5d", -2562);}
int	 d_width_pos_nofit_lj_sp_bench(void){return printf("% -4d", 94827);}
int	 d_width_neg_nofit_lj_sp_bench(void){return printf("% -4d", -2464);}
//signed integers with field width and allsign
int	 d_width_assp_pos_ignoreflag_bench(void){return printf("% +5d", 35);}
int	 d_width_assp_zero_ignoreflag_bench(void){return printf("% +7d", 0);}
int	 d_width_intmax_assp_ignoreflag_bench(void){return printf("% +24d", 2147483647);}
//signed integers with precision
int	 d_prec_fits_pos_sp_bench(void){return printf("% .5d", 2);}
int	 d_prec_fits_neg_sp_bench(void){return printf("% .6d", -3);}
int	 d_prec_fits_zero_sp_bench(void){return printf("% .3d", 0);}
int	 d_prec_exactfit_pos_sp_bench(void){return printf("% .4d", 5263);}
int	 d_prec_exactfit_neg_sp_bench(void){return printf("% .4d", -2372);}
int	 d_prec_nofit_pos_sp_bench(void){return printf("% .3d", 13862);}
int	 d_prec_nofit_neg_sp_bench(void){return printf("% .3d",-23646);}
int	 d_prec_assp_pos_ignoreflag_bench(void){return printf("% +.7d", 234);}
int	 d_prec_assp_neg_ignoreflag_bench(void){return printf("% +.7d", -446);}
int	 d_prec_assp_pos_nofit_ignoreflag_bench(void){return printf("% +.3d", 3723);}
//Signed integers - space with zero field width padding
int	 d_zpsp_pos_fits_bench(void){return printf("% 05d", 43);}
int	 d_zpsp_neg_fits_bench(void){return printf("% 07d", -54);}
int	 d_zpsp_zero_fits_bench(void){return printf("% 03d", 0);}
int	 d_zpsp_pos_exactfit_bench(void){return printf("% 03d", 634);}
int	 d_zpsp_neg_exactfit_bench(void){return printf("% 04d", -532);}
int	 d_zpsp_neg_minus1fit_bench(void){return printf("% 04d", -4825);}
int	 d_zpassp_as_fits_ignoreflag_bench(void){return printf("% +05d", 432);}
int	 d_zpassp_zero_ignoreflag_bench(void){return printf("% +04d", 0);}
//Signed integers - space with field width and precision
int	 d_prec_width_fit_fit_pos_sp_bench(void){return printf("% 8.5d", 34);}
int	 d_prec_width_fit_fit_neg_sp_bench(void){return printf("% 10.5d", -216);}
int	 d_prec_width_fit_fit_zero_sp_bench(void){return printf("% 8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_sp_bench(void){return printf("% 8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_sp_bench(void){return printf("% 8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_sp_bench(void){return printf("% 3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_sp_bench(void){return printf("% 3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_sp_bench(void){return printf("% 3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_sp_bench(void){return printf("% 3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified
int	 d_prec_width_fit_fit_pos_lj_sp_bench(void){return printf("% -8.5d", 34);}
int	 d_prec_width_fit_fit_neg_lj_sp_bench(void){return printf("% -10.5d", -216);}
int	 d_prec_width_fit_fit_zero_lj_sp_bench(void){return printf("% -8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_lj_sp_bench(void){return printf("% -8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_lj_sp_bench(void){return printf("% -8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_lj_sp_bench(void){return printf("% -3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_lj_sp_bench(void){return printf("% -3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_lj_sp_bench(void){return printf("% -3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_lj_sp_bench(void){return printf("% -3.3d", -8462);}
//Signed integers - space with field width and precision with allsign
int	 d_prec_width_fit_fit_pos_assp_ignoreflag_bench(void){return printf("% +8.5d", 34);}
int	 d_prec_width_fit_fit_neg_assp_ignoreflag_bench(void){return printf("% +10.5d", -216);}
int	 d_prec_width_fit_fit_zero_assp_ignoreflag_bench(void){return printf("% +8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_assp_ignoreflag_bench(void){return printf("% +8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_assp_ignoreflag_bench(void){return printf("% +8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_assp_ignoreflag_bench(void){return printf("% +3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_assp_ignoreflag_bench(void){return printf("% +3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_assp_ignoreflag_bench(void){return printf("% +3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_assp_ignoreflag_bench(void){return printf("% +3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign
int	 d_prec_width_fit_fit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-8.5d", 34);}
int	 d_prec_width_fit_fit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-10.5d", -216);}
int	 d_prec_width_fit_fit_zero_lj_assp_ignoreflag_bench(void){return printf("% +-8.5d", 0);}
int	 d_prec_width_nofit_fit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-8.3d", 8375);}
int	 d_prec_width_nofit_fit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-8.3d", -8473);}
int	 d_prec_width_fit_nofit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-3.7d", 3267);}
int	 d_prec_width_fit_nofit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-3.7d", -2375);}
int	 d_prec_width_nofit_nofit_pos_lj_assp_ignoreflag_bench(void){return printf("% +-3.3d", 6983);}
int	 d_prec_width_nofit_nofit_neg_lj_assp_ignoreflag_bench(void){return printf("% +-3.3d", -8462);}
//Signed integers - space with field width and precision with zeropadding
int	 d_prec_width_ff_pos_zp_sp_bench(void){return printf("% 08.5d", 34);}
int	 d_prec_width_ff_neg_zp_sp_bench(void){return printf("% 010.5d", -216);}
int	 d_prec_width_ff_zero_zp_sp_bench(void){return printf("% 08.5d", 0);}
int	 d_prec_width_nf_pos_zp_sp_bench(void){return printf("% 08.3d", 8375);}
int	 d_prec_width_nf_neg_zp_sp_bench(void){return printf("% 08.3d", -8473);}
int	 d_prec_width_fn_pos_zp_sp_bench(void){return printf("% 03.7d", 3267);}
int	 d_prec_width_fn_neg_zp_sp_bench(void){return printf("% 03.7d", -2375);}
int	 d_prec_width_nn_pos_zp_sp_bench(void){return printf("% 03.3d", 6983);}
int	 d_prec_width_nn_neg_zp_sp_bench(void){return printf("% 03.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with zeropadding
int	 d_prec_width_ff_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.5d", 34);}
int	 d_prec_width_ff_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-10.5d", -216);}
int	 d_prec_width_ff_zero_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.5d", 0);}
int	 d_prec_width_nf_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljzpsp_ignoreflag_bench(void){return printf("% 0-3.3d", -8462);}
//Signed integers - space with field width and precision with allsign with zeropadding
int	 d_prec_width_ff_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+8.5d", 34);}
int	 d_prec_width_ff_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+10.5d", -216);}
int	 d_prec_width_ff_zero_aszpsp_ignoreflag_bench(void){return printf("% 0+8.5d", 0);}
int	 d_prec_width_nf_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+8.3d", 8375);}
int	 d_prec_width_nf_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+8.3d", -8473);}
int	 d_prec_width_fn_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+3.7d", 3267);}
int	 d_prec_width_fn_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+3.7d", -2375);}
int	 d_prec_width_nn_pos_aszpsp_ignoreflag_bench(void){return printf("% 0+3.3d", 6983);}
int	 d_prec_width_nn_neg_aszpsp_ignoreflag_bench(void){return printf("% 0+3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign with zeropadding
int	 d_prec_width_ff_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.5d", 34);}
int	 d_prec_width_ff_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-10.5d", -216);}
int	 d_prec_width_ff_zero_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.5d", 0);}
int	 d_prec_width_nf_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.3d", 8375);}
int	 d_prec_width_nf_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-8.3d", -8473);}
int	 d_prec_width_fn_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.7d", 3267);}
int	 d_prec_width_fn_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.7d", -2375);}
int	 d_prec_width_nn_pos_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.3d", 6983);}
int	 d_prec_width_nn_neg_ljaszpsp_ignoreflag_bench(void){return printf("% 0+-3.3d", -8462);}
//Signed integers - space of varying size modifiers
int	 d_size_hh_pos_casted_sp_bench(void){return printf("% hhd", (char)45);}
int	 d_size_hh_neg_casted_sp_bench(void){return printf("% hhd", (char)-45);}
int	 d_size_h_pos_casted_sp_bench(void){return printf("% hd", (short)385);}
int	 d_size_h_neg_casted_sp_bench(void){return printf("% hd", (short)-385);}
int	 d_size_l_pos_casted_sp_bench(void){return printf("% ld", (long)32);}
int	 d_size_l_neg_casted_sp_bench(void){return printf("% ld", (long)-32);}
int	 d_size_ll_pos_casted_sp_bench(void){return printf("% lld", (long long)43);}
int	 d_size_ll_neg_casted_sp_bench(void){return printf("% lld", (long long)-43);}
int	 d_size_hh_pos_ref_sp_bench(void){return printf("% hhd", ch_pos_1);}
int	 d_size_hh_neg_ref_sp_bench(void){return printf("% hhd", ch_neg_1);}
int	 d_size_h_pos_ref_sp_bench(void){return printf("% hd", sh_pos_1);}
int	 d_size_h_neg_ref_sp_bench(void){return printf("% hd", sh_neg_1);}
int	 d_size_l_pos_ref_sp_bench(void){return printf("% ld", l_pos_1);}
int	 d_size_l_neg_ref_sp_bench(void){return printf("% ld", l_neg_1);}
int	 d_size_ll_pos_ref_sp_bench(void){return printf("% lld", ll_pos_1);}
int	 d_size_ll_neg_ref_sp_bench(void){return printf("% lld", ll_neg_1);}
int	 d_size_l_pos_big_sp_bench(void){return printf("% ld", 22337203685477l);}
int	 d_size_l_neg_big_sp_bench(void){return printf("% ld", -22337203685477l);}
int	 d_size_ll_pos_big_sp_bench(void){return printf("% lld", 522337203685470ll);}
int	 d_size_ll_neg_big_sp_bench(void){return printf("% lld", -522337203685470ll);}
int	 d_llmax_sp_bench(void){return printf("% lld", 9223372036854775807ll);}
int	 d_llmin_sp_bench(void){return printf("% lld", llmin);}
int	 d_lmax_sp_bench(void){return printf("% ld", 9223372036854775807l);}
int	 d_lmin_sp_bench(void){return printf("% ld", lmin);}
int	 d_hmax_sp_bench(void){return printf("% hd", (short)32767);}
int	 d_hmin_sp_bench(void){return printf("% hd", (short)(-32768));}
int	 d_hhmax_sp_bench(void){return printf("% hhd", (char)(127));}
int	 d_hhmin_sp_bench(void){return printf("% hhd", (char)(-128));}
 //Signed integers - zero precision zero value
int d_prec0val0_basic_bench(void){return printf("%.0d", 0);}
int d_prec0val0_implicit_bench(void){return printf("%.d", 0);}
int d_prec0val0_w_bench(void){return printf("%5.0d", 0);}
int d_prec0val0_w_impl_bench(void){return printf("%5.d", 0);}
int d_prec0val0_wlj_bench(void){return printf("%-5.0d", 0);}
int d_prec0val0_wlj_impl_bench(void){return printf("%-5.d", 0);}
int d_prec0val0_as_bench(void){return printf("%+.0d", 0);}
int d_prec0val0_as_impl_bench(void){return printf("%+.d", 0);}
int d_prec0val0_was_bench(void){return printf("%+5.0d", 0);}
int d_prec0val0_was_impl_bench(void){return printf("%+5.d", 0);}
int d_prec0val0_waslj_bench(void){return printf("%+-5.0d", 0);}
int d_prec0val0_waslj_impl_bench(void){return printf("%+-5.d", 0);}

//Switching between string and signed integers of various sizes


int		mix_hhi_str_lli_str_bench(void){return printf("%hhi%s%lli%s", ch_pos_1, str_3, ll_neg_1, str_2);}
int		mix_str_hi_str_li_bench(void){return printf("%s%hi%s%li", str_1, sh_neg_1, str_3, l_neg_1);}
int		mix_str_hi_str_li_emptystr_bench(void){return printf("%s%hi%s%li", str_empty, sh_neg_1, str_3, l_neg_1);}

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
//Unsigned integers of varying size modifiers







int u_size_hh_pos_casted_bench(void){return printf("%hhu", (unsigned char)45);}
int u_size_h_pos_casted_bench(void){return printf("%hu", (unsigned short)385);}
int u_size_l_pos_casted_bench(void){return printf("%lu", (unsigned long)32);}
int u_size_ll_pos_casted_bench(void){return printf("%llu", (unsigned long long)43);}
int u_size_hh_pos_ref_bench(void){return printf("%hhu", uch_pos_1);}
int u_size_h_pos_ref_bench(void){return printf("%hu", ush_pos_1);}
int u_size_l_pos_ref_bench(void){return printf("%lu", ul_pos_1);}
int u_size_ll_pos_ref_bench(void){return printf("%llu", ull_pos_1);}
int u_size_l_pos_big_bench(void){return printf("%lu", 22337203685477ul);}
int u_size_ll_pos_big_bench(void){return printf("%llu", 522337203685470ull);}
int u_ullmax_bench(void){return printf("%llu", ullmax);}
int u_ulmax_bench(void){return printf("%lu", ulmax);}
int u_uhmax_bench(void){return printf("%hu", (unsigned short)65535);}
int u_uhhmax_bench(void){return printf("%hhu", (unsigned char)255);}
//Unsigned integers of varying size modifiers with some other modifiers
int u_size_l_pos_big_zp_bench(void){return printf("%037lu", 22337203685477ul);}
int u_size_ll_pos_big_width_bench(void){return printf("%37llu", 522337203685470ull);}
//Multiple unsigned integers in a row of varying sizes
int u_size_ll_hh_ll_bench(void){return printf("%llu%hhu%llu", ull_pos_1, uch_pos_1, ull_pos_1);}
int u_size_h_l_hh_bench(void){return printf("%hu%lu%hhu", ush_pos_1, ul_pos_1, uch_pos_1);}
int u_size_l_hh_h_bench(void){return printf("%lu%hhu%hu", ul_pos_1, uch_pos_1, ush_pos_1);}
int u_size_n_ll_hh_bench(void){return printf("%u%llu%hhu", ui_pos_1, ull_pos_1, uch_pos_1);}
int u_size_ll_n_l_bench(void){return printf("%llu%u%lu", ull_pos_1, ui_pos_1, ul_pos_1);}
//Unsigned integers - zero precision zero value
int u_prec0val0_basic_bench(void){return printf("%.0u", 0);}
int u_prec0val0_implicit_bench(void){return printf("%.u", 0);}
int u_prec0val0_w_bench(void){return printf("%5.0u", 0);}
int u_prec0val0_w_impl_bench(void){return printf("%5.u", 0);}
int u_prec0val0_wlj_bench(void){return printf("%-5.0u", 0);}
int u_prec0val0_wlj_impl_bench(void){return printf("%-5.u", 0);}

//Switching between string and unsigned integers of various sizes
int		mix_hhu_str_llu_str_bench(void){return printf("%hhu%s%llu%s", uch_pos_1, str_3, ull_pos_1, str_2);}
int		mix_str_hu_str_lu_bench(void){return printf("%s%hu%s%lu", str_1, ush_pos_1, str_3, ul_pos_1);}

//Mixing everything from all the tests so far
int		mixed_test_0001_bench(void){return printf(
		"%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li","abc",sh_neg_1,
		ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);}

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
//Hexadecimal lowers of varying size modifiers
int x_size_hh_pos_casted_bench(void){return printf("%hhx", (unsigned char)45);}
int x_size_h_pos_casted_bench(void){return printf("%hx", (unsigned short)385);}
int x_size_l_pos_casted_bench(void){return printf("%lx", (unsigned long)32);}
int x_size_ll_pos_casted_bench(void){return printf("%llx", (long long)43);}
int x_size_hh_pos_ref_bench(void){return printf("%hhx", uch_pos_1);}
int x_size_h_pos_ref_bench(void){return printf("%hx", ush_pos_1);}
int x_size_l_pos_ref_bench(void){return printf("%lx", ul_pos_1);}
int x_size_ll_pos_ref_bench(void){return printf("%llx", ull_pos_1);}
int x_size_l_pos_big_bench(void){return printf("%lx", 22337203685477ul);}
int x_size_ll_pos_big_bench(void){return printf("%llx", 522337203685470ull);}
int x_ullmax_bench(void){return printf("%llx", ullmax);}
int x_ulmax_bench(void){return printf("%lx", ulmax);}
int x_uhmax_bench(void){return printf("%hx", (unsigned short)65535);}
int x_uhhmax_bench(void){return printf("%hhx", (unsigned char)255);}
//Hexadecimal lowers of varying size modifiers with some other modifiers
int x_size_l_pos_big_zp_bench(void){return printf("%037lx", 22337203685477ul);}
int x_size_ll_pos_big_width_bench(void){return printf("%37llx", 522337203685470ull);}
//Multiple Hexadecimal lowers in a row of varying sizes
int x_size_ll_hh_ll_bench(void){return printf("%llu%hhu%llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int x_size_h_l_hh_bench(void){return printf("%hu%lu%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int x_size_l_hh_h_bench(void){return printf("%lu%hhu%hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int x_size_n_ll_hh_bench(void){return printf("%u%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int x_size_ll_n_l_bench(void){return printf("%llu%u%lx", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hexadecimal lower (altform) - no modifers
int		x_basic_pos_af_bench(void){return printf("this %#x number", 17);}
int		x_basic_zero_af_bench(void){return printf("this %#x number", 0);}
int		x_basic_onlypos_af_bench(void){return printf("%#x", 3);}
int x_hexlmax_af_bench(void){return printf("%#x", 4294967295u);}
//Hexadecimal lower (altform) with field width
int x_width_pos_fits_af_bench(void){return printf("%#7x", 33);}
int x_width_zero_fits_af_bench(void){return printf("%#3x", 0);}
int x_width_pos_exactfit_af_bench(void){return printf("%#5x", 52625);}
int x_width_pos_nofit_af_bench(void){return printf("%#2x", 94827);}
int x_width_pos_fits_lj_af_bench(void){return printf("%#-7x", 33);}
int x_width_zero_fits_lj_af_bench(void){return printf("%#-3x", 0);}
int x_width_pos_exactfit_lj_af_bench(void){return printf("%#-5x", 52625);}
int x_width_pos_nofit_lj_af_bench(void){return printf("%#-4x", 9648627);}
//Hexadecimal lower (altform) with precision
int x_prec_fits_pos_af_bench(void){return printf("%#.5x", 21);}
int x_prec_fits_zero_af_bench(void){return printf("%#.3x", 0);}
int x_prec_exactfit_pos_af_bench(void){return printf("%#.4x", 5263);}
int x_prec_nofit_pos_af_bench(void){return printf("%#.3x", 938862);}
//Hexadecimal lower (altform) with zero field width padding
int x_zp_pos_fits_af_bench(void){return printf("%#05x", 43);}
int x_zp_zero_fits_af_bench(void){return printf("%#03x", 0);}
int x_zp_pos_exactfit_af_bench(void){return printf("%#03x", 698334);}
//Hexadecimal lower (altform) with field width and precision
int x_prec_width_fit_fit_pos_af_bench(void){return printf("%#8.5x", 34);}
int x_prec_width_fit_fit_zero_af_bench(void){return printf("%#8.5x", 0);}
int x_prec_width_nofit_fit_pos_af_bench(void){return printf("%#8.3x", 8375);}
int x_prec_width_fit_nofit_pos_af_bench(void){return printf("%#2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_af_bench(void){return printf("%#3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified
int x_prec_width_fit_fit_pos_lj_af_bench(void){return printf("%#-8.5x", 34);}
int x_prec_width_fit_fit_zero_lj_af_bench(void){return printf("%#-8.5x", 0);}
int x_prec_width_nofit_fit_pos_lj_af_bench(void){return printf("%#-8.3x", 8375);}
int x_prec_width_fit_nofit_pos_lj_af_bench(void){return printf("%#-2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_lj_af_bench(void){return printf("%#-3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision with zeropadding
int x_prec_width_ff_pos_zp_af_bench(void){return printf("%#08.5x", 34);}
int x_prec_width_ff_zero_zp_af_bench(void){return printf("%#08.5x", 0);}
int x_prec_width_nf_pos_zp_af_bench(void){return printf("%#08.3x", 8375);}
int x_prec_width_fn_pos_zp_af_bench(void){return printf("%#02.7x", 3267);}
int x_prec_width_nn_pos_zp_af_bench(void){return printf("%#03.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified with zeropadding
int x_prec_width_ff_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.5x", 34);}
int x_prec_width_ff_zero_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.5x", 0);}
int x_prec_width_nf_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.3x", 8375);}
int x_prec_width_fn_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-2.7x", 3267);}
int x_prec_width_nn_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-3.3x", 6983);}
//Hexadecimal lower (altform) of varying size modifiers
int x_size_hh_pos_casted_af_bench(void){return printf("%#hhx", (unsigned char)45);}
int x_size_h_pos_casted_af_bench(void){return printf("%#hx", (unsigned short)385);}
int x_size_l_pos_casted_af_bench(void){return printf("%#lx", (unsigned long)32);}
int x_size_ll_pos_casted_af_bench(void){return printf("%#llx", (long long)43);}
int x_size_hh_pos_ref_af_bench(void){return printf("%#hhx", uch_pos_1);}
int x_size_h_pos_ref_af_bench(void){return printf("%#hx", ush_pos_1);}
int x_size_l_pos_ref_af_bench(void){return printf("%#lx", ul_pos_1);}
int x_size_ll_pos_ref_af_bench(void){return printf("%#llx", ull_pos_1);}
int x_size_l_pos_big_af_bench(void){return printf("%#lx", 22337203685477lu);}
int x_size_ll_pos_big_af_bench(void){return printf("%#llx", 522337203685470llu);}
int x_ullmax_af_bench(void){return printf("%#llx", ullmax);}
int x_ulmax_af_bench(void){return printf("%#lx", ulmax);}
int x_uhmax_af_bench(void){return printf("%#hx", (unsigned short)65535);}
int x_uhhmax_af_bench(void){return printf("%#hhx", (unsigned char)255);}
//Hexadecimal lower (altform) of varying size modifiers with some other modifiers
int x_size_l_pos_big_zp_af_bench(void){return printf("%#037lx", 22337203685477ul);}
int x_size_ll_pos_big_width_af_bench(void){return printf("%#37llx", 522337203685470ull);}
//Multiple Hexadecimal lower (altform) in a row of varying sizes
int x_size_ll_hh_ll_af_bench(void){return printf("%llu%hhu%#llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int x_size_h_l_hh_af_bench(void){return printf("%hu%#lx%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int x_size_l_hh_h_af_bench(void){return printf("%lu%hhu%#hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int x_size_n_ll_hh_af_bench(void){return printf("%#x%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int x_size_ll_n_l_af_bench(void){return printf("%llu%u%#lx", ull_pos_1, ui_pos_1, ul_pos_1);}
 //Hexadecimal lower - zero precision zero value
int x_prec0val0_basic_bench(void){return printf("%.0x", 0);}
int x_prec0val0_implicit_bench(void){return printf("%.x", 0);}
int x_prec0val0_w_bench(void){return printf("%5.0x", 0);}
int x_prec0val0_w_impl_bench(void){return printf("%5.x", 0);}
int x_prec0val0_wlj_bench(void){return printf("%-5.0x", 0);}
int x_prec0val0_wlj_impl_bench(void){return printf("%-5.x", 0);}
int x_prec0val0_af_bench(void){return printf("%#.0x", 0);}
int x_prec0val0_af_impl_bench(void){return printf("%#.x", 0);}
int x_prec0val0_waf_bench(void){return printf("%#5.0x", 0);}
int x_prec0val0_waf_impl_bench(void){return printf("%#5.x", 0);}
int x_prec0val0_waflj_bench(void){return printf("%#-5.0x", 0);}
int x_prec0val0_waflj_impl_bench(void){return printf("%#-5.x", 0);}


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
//Hexadecimal uppers of varying size modifiers
int X_size_hh_pos_casted_bench(void){return printf("%hhX", (unsigned char)45);}
int X_size_h_pos_casted_bench(void){return printf("%hX", (unsigned short)385);}
int X_size_l_pos_casted_bench(void){return printf("%lX", (unsigned long)32);}
int X_size_ll_pos_casted_bench(void){return printf("%llX", (long long)43);}
int X_size_hh_pos_ref_bench(void){return printf("%hhX", uch_pos_1);}
int X_size_h_pos_ref_bench(void){return printf("%hX", ush_pos_1);}
int X_size_l_pos_ref_bench(void){return printf("%lX", ul_pos_1);}
int X_size_ll_pos_ref_bench(void){return printf("%llX", ull_pos_1);}
int X_size_l_pos_big_bench(void){return printf("%lX", 22337203685477ul);}
int X_size_ll_pos_big_bench(void){return printf("%llX", 522337203685470ull);}
int X_ullmax_bench(void){return printf("%llX", ullmax);}
int X_ulmax_bench(void){return printf("%lX", ulmax);}
int X_uhmax_bench(void){return printf("%hX", (unsigned short)65535);}
int X_uhhmax_bench(void){return printf("%hhX", (unsigned char)255);}
//Hexadecimal uppers of varying size modifiers with some other modifiers
int X_size_l_pos_big_zp_bench(void){return printf("%037lX", 22337203685477ul);}
int X_size_ll_pos_big_width_bench(void){return printf("%37llX", 522337203685470ull);}
//Multiple Hexadecimal uppers in a row of varying sizes
int X_size_ll_hh_ll_bench(void){return printf("%llu%hhu%llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int X_size_h_l_hh_bench(void){return printf("%hu%lu%hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int X_size_l_hh_h_bench(void){return printf("%lu%hhu%hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int X_size_n_ll_hh_bench(void){return printf("%u%llu%hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int X_size_ll_n_l_bench(void){return printf("%llu%u%lX", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hex uppers (altform) - no modifers
int X_basic_hexu_pos_af_bench(void){return printf("this %#X number", 17);}
int X_basic_hexu_zero_af_bench(void){return printf("this %#X number", 0);}
int X_basic_hexu_onlypos_af_bench(void){return printf("%#X", 3);}
int X_hexumax_af_bench(void){return printf("%#X", 4294967295u);}
//Hex uppers (altform) with field width
int X_width_pos_fits_af_bench(void){return printf("%#7X", 33);}
int X_width_zero_fits_af_bench(void){return printf("%#3X", 0);}
int X_width_pos_exactfit_af_bench(void){return printf("%#7X", 52625);}
int X_width_pos_nofit_af_bench(void){return printf("%#2X", 94827);}
int X_width_pos_fits_lj_af_bench(void){return printf("%#-7X", 33);}
int X_width_zero_fits_lj_af_bench(void){return printf("%#-3X", 0);}
int X_width_pos_exactfit_lj_af_bench(void){return printf("%#-7X", 52625);}
int X_width_pos_nofit_lj_af_bench(void){return printf("%#-4X", 9648627);}
//Hex uppers (altform) with precision
int X_prec_fits_pos_af_bench(void){return printf("%#.5X", 21);}
int X_prec_fits_zero_af_bench(void){return printf("%#.3X", 0);}
int X_prec_exactfit_pos_af_bench(void){return printf("%#.4X", 5263);}
int X_prec_nofit_pos_af_bench(void){return printf("%#.3X", 938862);}
//Hex uppers (altform) with zero field width padding
int X_zp_pos_fits_af_bench(void){return printf("%#05X", 43);}
int X_zp_zero_fits_af_bench(void){return printf("%#03X", 0);}
int X_zp_pos_exactfit_af_bench(void){return printf("%#03X", 698334);}
//Hex uppers (altform) with field width and precision
int X_prec_width_fit_fit_pos_af_bench(void){return printf("%#8.5X", 34);}
int X_prec_width_fit_fit_zero_af_bench(void){return printf("%#8.5X", 0);}
int X_prec_width_nofit_fit_pos_af_bench(void){return printf("%#8.3X", 8375);}
int X_prec_width_fit_nofit_pos_af_bench(void){return printf("%#2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_af_bench(void){return printf("%#3.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified
int X_prec_width_fit_fit_pos_lj_af_bench(void){return printf("%#-8.5X", 34);}
int X_prec_width_fit_fit_zero_lj_af_bench(void){return printf("%#-8.5X", 0);}
int X_prec_width_nofit_fit_pos_lj_af_bench(void){return printf("%#-8.3X", 8375);}
int X_prec_width_fit_nofit_pos_lj_af_bench(void){return printf("%#-2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_lj_af_bench(void){return printf("%#-3.3X", 6983);}
//Hex uppers (altform) with field width and precision with zeropadding
int X_prec_width_ff_pos_zp_af_bench(void){return printf("%#08.5X", 34);}
int X_prec_width_ff_zero_zp_af_bench(void){return printf("%#08.5X", 0);}
int X_prec_width_nf_pos_zp_af_bench(void){return printf("%#08.3X", 8375);}
int X_prec_width_fn_pos_zp_af_bench(void){return printf("%#02.7X", 3267);}
int X_prec_width_nn_pos_zp_af_bench(void){return printf("%#03.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified with zeropadding
int X_prec_width_ff_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.5X", 34);}
int X_prec_width_ff_zero_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.5X", 0);}
int X_prec_width_nf_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.3X", 8375);}
int X_prec_width_fn_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-2.7X", 3267);}
int X_prec_width_nn_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-3.3X", 6983);}
//Hex uppers (altform) of varying size modifiers
int X_size_hh_pos_casted_af_bench(void){return printf("%#hhX", (unsigned char)45);}
int X_size_h_pos_casted_af_bench(void){return printf("%#hX", (unsigned short)385);}
int X_size_l_pos_casted_af_bench(void){return printf("%#lX", (unsigned long)32);}
int X_size_ll_pos_casted_af_bench(void){return printf("%#llX", (long long)43);}
int X_size_hh_pos_ref_af_bench(void){return printf("%#hhX", uch_pos_1);}
int X_size_h_pos_ref_af_bench(void){return printf("%#hX", ush_pos_1);}
int X_size_l_pos_ref_af_bench(void){return printf("%#lX", ul_pos_1);}
int X_size_ll_pos_ref_af_bench(void){return printf("%#llX", ull_pos_1);}
int X_size_l_pos_big_af_bench(void){return printf("%#lX", 22337203685477ul);}
int X_size_ll_pos_big_af_bench(void){return printf("%#llX", 522337203685470ull);}
int X_ullmax_af_bench(void){return printf("%#llX", ullmax);}
int X_ulmax_af_bench(void){return printf("%#lX", ulmax);}
int X_uhmax_af_bench(void){return printf("%#hX", (unsigned short)65535);}
int X_uhhmax_af_bench(void){return printf("%#hhX", (unsigned char)255);}
//Hex uppers (altform) of varying size modifiers with some other modifiers
int X_size_l_pos_big_zp_af_bench(void){return printf("%#037lX", 22337203685477ul);}
int X_size_ll_pos_big_width_af_bench(void){return printf("%#37llX", 522337203685470ull);}
//Multiple Hex uppers (altform) in a row of varying sizes
int X_size_ll_hh_ll_af_bench(void){return printf("%llu%hhu%#llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int X_size_h_l_hh_af_bench(void){return printf("%#hx%lu%#hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int X_size_l_hh_h_af_bench(void){return printf("%lu%hhu%#hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int X_size_n_ll_hh_af_bench(void){return printf("%#x%llu%#hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int X_size_ll_n_l_af_bench(void){return printf("%#llx%u%#lX", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hexadecimal uppers - zero precision zero value
int X_prec0val0_basic_bench(void){return printf("%.0X", 0);}
int X_prec0val0_implicit_bench(void){return printf("%.X", 0);}
int X_prec0val0_w_bench(void){return printf("%5.0X", 0);}
int X_prec0val0_w_impl_bench(void){return printf("%5.X", 0);}
int X_prec0val0_wlj_bench(void){return printf("%-5.0X", 0);}
int X_prec0val0_wlj_impl_bench(void){return printf("%-5.X", 0);}
int X_prec0val0_af_bench(void){return printf("%#.0X", 0);}
int X_prec0val0_af_impl_bench(void){return printf("%#.X", 0);}
int X_prec0val0_waf_bench(void){return printf("%#5.0X", 0);}
int X_prec0val0_waf_impl_bench(void){return printf("%#5.X", 0);}
int X_prec0val0_waflj_bench(void){return printf("%#-5.0X", 0);}
int X_prec0val0_waflj_impl_bench(void){return printf("%#-5.X", 0);}


//Octals - no modifers
int o_basic_octl_pos_bench(void){return printf("this %o number", 17);}
int o_basic_octl_zero_bench(void){return printf("this %o number", 0);}
int o_basic_octl_onlypos_bench(void){return printf("%o", 3);}
int o_octlmax_bench(void){return printf("%o", 4294967295u);}
//Octals with field width
int o_width_pos_fits_bench(void){return printf("%7o", 33);}
int o_width_zero_fits_bench(void){return printf("%3o", 0);}
int o_width_pos_exactfit_bench(void){return printf("%6o", 52625);}
int o_width_pos_nofit_bench(void){return printf("%2o", 94827);}
int o_width_pos_fits_lj_bench(void){return printf("%-7o", 33);}
int o_width_zero_fits_lj_bench(void){return printf("%-3o", 0);}
int o_width_pos_exactfit_lj_bench(void){return printf("%-6o", 52625);}
int o_width_pos_nofit_lj_bench(void){return printf("%-4o", 9648627);}
//Octals with precision
int o_prec_fits_pos_bench(void){return printf("%.5o", 21);}
int o_prec_fits_zero_bench(void){return printf("%.3o", 0);}
int o_prec_exactfit_pos_bench(void){return printf("%.5o", 5263);}
int o_prec_nofit_pos_bench(void){return printf("%.3o", 938862);}
//Octals with zero field width padding
int o_zp_pos_fits_bench(void){return printf("%05o", 43);}
int o_zp_zero_fits_bench(void){return printf("%03o", 0);}
int o_zp_pos_exactfit_bench(void){return printf("%07o", 698334);}
//Octals with field width and precision
int o_prec_width_fit_fit_pos_bench(void){return printf("%8.5o", 34);}
int o_prec_width_fit_fit_zero_bench(void){return printf("%8.5o", 0);}
int o_prec_width_nofit_fit_pos_bench(void){return printf("%8.3o", 8375);}
int o_prec_width_fit_nofit_pos_bench(void){return printf("%2.7o", 3267);}
int o_prec_width_nofit_nofit_pos_bench(void){return printf("%3.3o", 6983);}
//Octals with field width and precision, left-justified
int o_prec_width_fit_fit_pos_lj_bench(void){return printf("%-8.5o", 34);}
int o_prec_width_fit_fit_zero_lj_bench(void){return printf("%-8.5o", 0);}
int o_prec_width_nofit_fit_pos_lj_bench(void){return printf("%-8.3o", 8375);}
int o_prec_width_fit_nofit_pos_lj_bench(void){return printf("%-2.7o", 3267);}
int o_prec_width_nofit_nofit_pos_lj_bench(void){return printf("%-3.3o", 6983);}
//Octals with field width and precision with zeropadding
int o_prec_width_ff_pos_zp_bench(void){return printf("%08.5o", 34);}
int o_prec_width_ff_zero_zp_bench(void){return printf("%08.5o", 0);}
int o_prec_width_nf_pos_zp_bench(void){return printf("%08.3o", 8375);}
int o_prec_width_fn_pos_zp_bench(void){return printf("%02.7o", 3267);}
int o_prec_width_nn_pos_zp_bench(void){return printf("%03.3o", 6983);}
//Octals with field width and precision, left-justified with zeropadding
int o_prec_width_ff_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.5o", 34);}
int o_prec_width_ff_zero_ljzp_ignoreflag_bench(void){return printf("%0-8.5o", 0);}
int o_prec_width_nf_pos_ljzp_ignoreflag_bench(void){return printf("%0-8.3o", 8375);}
int o_prec_width_fn_pos_ljzp_ignoreflag_bench(void){return printf("%0-2.7o", 3267);}
int o_prec_width_nn_pos_ljzp_ignoreflag_bench(void){return printf("%0-3.3o", 6983);}
//Octals of varying size modifiers
int o_size_hh_pos_casted_bench(void){return printf("%hho", (unsigned char)45);}
int o_size_h_pos_casted_bench(void){return printf("%ho", (unsigned short)385);}
int o_size_l_pos_casted_bench(void){return printf("%lo", (unsigned long)32);}
int o_size_ll_pos_casted_bench(void){return printf("%llo", (long long)43);}
int o_size_hh_pos_ref_bench(void){return printf("%hho", uch_pos_1);}
int o_size_h_pos_ref_bench(void){return printf("%ho", ush_pos_1);}
int o_size_l_pos_ref_bench(void){return printf("%lo", ul_pos_1);}
int o_size_ll_pos_ref_bench(void){return printf("%llo", ull_pos_1);}
int o_size_l_pos_big_bench(void){return printf("%lo", 22337203685477ul);}
int o_size_ll_pos_big_bench(void){return printf("%llo", 522337203685470ull);}
int o_ullmax_bench(void){return printf("%llo", ullmax);}
int o_ulmax_bench(void){return printf("%lo", ulmax);}
int o_uhmax_bench(void){return printf("%ho", (unsigned short)65535);}
int o_uhhmax_bench(void){return printf("%hho", (unsigned char)255);}
//Octals of varying size modifiers with some other modifiers
int o_size_l_pos_big_zp_bench(void){return printf("%037lo", 22337203685477ul);}
int o_size_ll_pos_big_width_bench(void){return printf("%37llo", 522337203685470ull);}
//Multiple Octals in a row of varying sizes
int o_size_ll_hh_ll_bench(void){return printf("%llu%hhu%llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int o_size_h_l_hh_bench(void){return printf("%hu%lu%hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int o_size_l_hh_h_bench(void){return printf("%lu%hhu%ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int o_size_n_ll_hh_bench(void){return printf("%u%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int o_size_ll_n_l_bench(void){return printf("%llu%u%lo", ull_pos_1, ui_pos_1, ul_pos_1);}
//Octal (Altform)s - no modifers
int o_basic_octl_pos_af_bench(void){return printf("this %#o number", 17);}
int o_basic_octl_zero_af_bench(void){return printf("this %#o number", 0);}
int o_basic_octl_onlypos_af_bench(void){return printf("%#o", 3);}
int o_octlmax_af_bench(void){return printf("%#o", 4294967295u);}
//Octal (Altform)s with field width
int o_width_pos_fits_af_bench(void){return printf("%#7o", 33);}
int o_width_zero_fits_af_bench(void){return printf("%#3o", 0);}
int o_width_pos_exactfit_af_bench(void){return printf("%#6o", 52625);}
int o_width_pos_nofit_af_bench(void){return printf("%#2o", 94827);}
int o_width_pos_fits_lj_af_bench(void){return printf("%#-7o", 33);}
int o_width_zero_fits_lj_af_bench(void){return printf("%#-3o", 0);}
int o_width_pos_exactfit_lj_af_bench(void){return printf("%#-6o", 52625);}
int o_width_pos_nofit_lj_af_bench(void){return printf("%#-4o", 9648627);}
//Octal (Altform)s with precision
int o_prec_fits_pos_af_bench(void){return printf("%#.5o", 21);}
int o_prec_fits_zero_af_bench(void){return printf("%#.3o", 0);}
int o_prec_exactfit_pos_af_bench(void){return printf("%#.5o", 5263);}
int o_prec_nofit_pos_af_bench(void){return printf("%#.3o", 938862);}
//Octal (Altform)s with zero field width padding
int o_zp_pos_fits_af_bench(void){return printf("%#05o", 43);}
int o_zp_zero_fits_af_bench(void){return printf("%#03o", 0);}
int o_zp_pos_exactfit_af_bench(void){return printf("%#07o", 698334);}
//Octal (Altform)s with field width and precision
int o_prec_width_fit_fit_pos_af_bench(void){return printf("%#8.5o", 34);}
int o_prec_width_fit_fit_zero_af_bench(void){return printf("%#8.5o", 0);}
int o_prec_width_nofit_fit_pos_af_bench(void){return printf("%#8.3o", 8375);}
int o_prec_width_fit_nofit_pos_af_bench(void){return printf("%#2.7o", 3267);}
int o_prec_width_nofit_nofit_pos_af_bench(void){return printf("%#3.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified
int o_prec_width_fit_fit_pos_lj_af_bench(void){return printf("%#-8.5o", 34);}
int o_prec_width_fit_fit_zero_lj_af_bench(void){return printf("%#-8.5o", 0);}
int o_prec_width_nofit_fit_pos_lj_af_bench(void){return printf("%#-8.3o", 8375);}
int o_prec_width_fit_nofit_pos_lj_af_bench(void){return printf("%#-2.7o", 3267);}
int o_prec_width_nofit_nofit_pos_lj_af_bench(void){return printf("%#-3.3o", 6983);}
//Octal (Altform)s with field width and precision with zeropadding
int o_prec_width_ff_pos_zp_af_bench(void){return printf("%#08.5o", 34);}
int o_prec_width_ff_zero_zp_af_bench(void){return printf("%#08.5o", 0);}
int o_prec_width_nf_pos_zp_af_bench(void){return printf("%#08.3o", 8375);}
int o_prec_width_fn_pos_zp_af_bench(void){return printf("%#02.7o", 3267);}
int o_prec_width_nn_pos_zp_af_bench(void){return printf("%#03.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified with zeropadding
int o_prec_width_ff_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.5o", 34);}
int o_prec_width_ff_zero_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.5o", 0);}
int o_prec_width_nf_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-8.3o", 8375);}
int o_prec_width_fn_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-2.7o", 3267);}
int o_prec_width_nn_pos_ljzpaf_ignoreflag_bench(void){return printf("%#0-3.3o", 6983);}
//Octal (Altform)s of varying size modifiers
int o_size_hh_pos_casted_af_bench(void){return printf("%#hho", (unsigned char)45);}
int o_size_h_pos_casted_af_bench(void){return printf("%#ho", (unsigned short)385);}
int o_size_l_pos_casted_af_bench(void){return printf("%#lo", (unsigned long)32);}
int o_size_ll_pos_casted_af_bench(void){return printf("%#llo", (long long)43);}
int o_size_hh_pos_ref_af_bench(void){return printf("%#hho", uch_pos_1);}
int o_size_h_pos_ref_af_bench(void){return printf("%#ho", ush_pos_1);}
int o_size_l_pos_ref_af_bench(void){return printf("%#lo", ul_pos_1);}
int o_size_ll_pos_ref_af_bench(void){return printf("%#llo", ull_pos_1);}
int o_size_l_pos_big_af_bench(void){return printf("%#lo", 22337203685477ul);}
int o_size_ll_pos_big_af_bench(void){return printf("%#llo", 522337203685470ull);}
int o_ullmax_af_bench(void){return printf("%#llo", ullmax);}
int o_ulmax_af_bench(void){return printf("%#lo", ulmax);}
int o_uhmax_af_bench(void){return printf("%#ho", (unsigned short)65535);}
int o_uhhmax_af_bench(void){return printf("%#hho", (unsigned char)255);}
//Octal (Altform)s of varying size modifiers with some other modifiers
int o_size_l_pos_big_zp_af_bench(void){return printf("%#037lo", 22337203685477ul);}
int o_size_ll_pos_big_width_af_bench(void){return printf("%#37llo", 522337203685470ull);}
//Multiple Octal (Altform)s in a row of varying sizes
int o_size_ll_hh_ll_af_bench(void){return printf("%llu%hhu%#llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int o_size_h_l_hh_af_bench(void){return printf("%hu%lu%#hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int o_size_l_hh_h_af_bench(void){return printf("%#lo%hhu%#ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int o_size_n_ll_hh_af_bench(void){return printf("%#o%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int o_size_ll_n_l_af_bench(void){return printf("%#llo%u%#lo", ull_pos_1, ui_pos_1, ul_pos_1);}
//Octals - zero precision zero value
int o_prec0val0_basic_bench(void){return printf("%.0o", 0);}
int o_prec0val0_implicit_bench(void){return printf("%.o", 0);}
int o_prec0val0_w_bench(void){return printf("%5.0o", 0);}
int o_prec0val0_w_impl_bench(void){return printf("%5.o", 0);}
int o_prec0val0_wlj_bench(void){return printf("%-5.0o", 0);}
int o_prec0val0_wlj_impl_bench(void){return printf("%-5.o", 0);}
int o_prec0val0_af_bench(void){return printf("%#.0o", 0);}
int o_prec0val0_af_impl_bench(void){return printf("%#.o", 0);}
int o_prec0val0_waf_bench(void){return printf("%#5.0o", 0);}
int o_prec0val0_waf_impl_bench(void){return printf("%#5.o", 0);}
int o_prec0val0_waflj_bench(void){return printf("%#-5.0o", 0);}
int o_prec0val0_waflj_impl_bench(void){return printf("%#-5.o", 0);}


//Pointers - Basic












int p_null_bench(void){return printf("%p", NULL);}
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








//Floats - Basic
int f_basic_1_bench(void){return printf("this %f float", 1.5);}
int f_basic_fltonly_bench(void){return printf("%f", 7.5);}
int f_basic_whole_bench(void){return printf("%f", 1.0);}
int f_basic_negative_bench(void){return printf("%f", -3.85);}
int f_basic_positive_3_3_bench(void){return printf("%f", 573.924);}
int f_basic_negative_3_3_bench(void){return printf("%f", -958.125);}
int f_basic_positive_smallfpart_bench(void){return printf("%f", 23.00041);}
int f_basic_positive_allsmall_bench(void){return printf("%f", 0.000039);}
int f_basic_negative_smallfpart_bench(void){return printf("%f", -7.00036);}
int f_basic_negative_allsmall_bench(void){return printf("%f", -0.00032);}
int f_basic_limits_allsmall_pos_bench(void){return printf("%f", 0.000001);}
int f_basic_limits_allsmall_neg_bench(void){return printf("%f", -0.000001);}
int f_basic_limits_smallfpart_pos_bench(void){return printf("%f", 9873.000001);}
int f_basic_limits_smallfpart_neg_bench(void){return printf("%f", -875.000001);}
int f_basic_limits_allbig_pos_bench(void){return printf("%f", 999.999999);}
int f_basic_limits_allbig_neg_bench(void){return printf("%f", -99.999999);}
int f_basic_limits_bigfpart_pos_bench(void){return printf("%f", 0.999999);}
int f_basic_limits_bigfpart_neg_bench(void){return printf("%f", -0.999999);}
//Floats - Rounding with default precision
int f_rndd_pos_bench(void){return printf("%f", 23.375094499);}
int f_rndd_neg_bench(void){return printf("%f", -985.765426499);}
int f_rndu_pos_bench(void){return printf("%f", 0.0894255);}
int f_rndu_neg_bench(void){return printf("%f", -56.2012685);}
int f_rndu_multidigit_pos_bench(void){return printf("%f", 43.4399999);}
int f_rndu_multidigit_neg_bench(void){return printf("%f", -5.0299999);}
int f_rndd_multidigit_pos_bench(void){return printf("%f", 43.43999949);}
int f_rndd_multidigit_neg_bench(void){return printf("%f", -5.02999949);}
int f_rndd_wholnobump_pos_bench(void){return printf("%f", 1.99999949);}
int f_rndd_wholnobump_neg_bench(void){return printf("%f", -0.99999949);}
int f_rndu_bumpwhole_pos_bench(void){return printf("%f", 3.9999999);}
int f_rndu_bumpwhole_neg_bench(void){return printf("%f", -5.9999999);}
//Floats Prec 0
int f_prec0_1_bench(void){return printf("this %.0f float", 1.6);}
int f_prec0_fltonly_bench(void){return printf("%.0f", 7.4);}
int f_prec0_whole_bench(void){return printf("%.0f", 1.0);}
int f_prec0_negative_bench(void){return printf("%.0f", -3.85);}
int f_prec0_positive_3_3_bench(void){return printf("%.0f", 573.924);}
int f_prec0_negative_3_3_bench(void){return printf("%.0f", -958.125);}
int f_prec0_positive_smallfpart_bench(void){return printf("%.0f", 23.00041);}
int f_prec0_positive_allsmall_bench(void){return printf("%.0f", 0.000039);}
int f_prec0_negative_smallfpart_bench(void){return printf("%.0f", -7.00036);}
int f_prec0_negative_allsmall_bench(void){return printf("%.0f", -0.00032);}
//Floats Prec 1
int f_prec1_1_bench(void){return printf("this %.1f float", 1.5);}
int f_prec1_fltonly_bench(void){return printf("%.1f", 7.5);}
int f_prec1_whole_bench(void){return printf("%.1f", 1.0);}
int f_prec1_negative_bench(void){return printf("%.1f", -3.85);}
int f_prec1_positive_3_3_bench(void){return printf("%.1f", 573.924);}
int f_prec1_negative_3_3_bench(void){return printf("%.1f", -958.125);}
int f_prec1_positive_smallfpart_bench(void){return printf("%.1f", 23.00041);}
int f_prec1_positive_allsmall_bench(void){return printf("%.1f", 0.000039);}
int f_prec1_negative_smallfpart_bench(void){return printf("%.1f", -7.00036);}
int f_prec1_negative_allsmall_bench(void){return printf("%.1f", -0.00032);}
//Floats Prec 3
int f_prec3_1_bench(void){return printf("this %.3f float", 1.5);}
int f_prec3_fltonly_bench(void){return printf("%.3f", 7.5);}
int f_prec3_whole_bench(void){return printf("%.3f", 1.0);}
int f_prec3_negative_bench(void){return printf("%.3f", -3.85);}
int f_prec3_positive_3_3_bench(void){return printf("%.3f", 573.924);}
int f_prec3_negative_3_3_bench(void){return printf("%.3f", -958.125);}
int f_prec3_positive_smallfpart_bench(void){return printf("%.3f", 23.00041);}
int f_prec3_positive_allsmall_bench(void){return printf("%.3f", 0.000039);}
int f_prec3_negative_smallfpart_bench(void){return printf("%.3f", -7.00036);}
int f_prec3_negative_allsmall_bench(void){return printf("%.3f", -0.00032);}
//Floats - Prec 7
int f_prec7_1_bench(void){return printf("this %.7f float", 1.5);}
int f_prec7_fltonly_bench(void){return printf("%.7f", 7.5);}
int f_prec7_whole_bench(void){return printf("%.7f", 1.0);}
int f_prec7_negative_bench(void){return printf("%.7f", -3.85);}
int f_prec7_positive_3_3_bench(void){return printf("%.7f", 573.924);}
int f_prec7_negative_3_3_bench(void){return printf("%.7f", -958.125);}
int f_prec7_positive_smallfpart_bench(void){return printf("%.7f", 23.00041);}
int f_prec7_positive_allsmall_bench(void){return printf("%.7f", 0.0000039);}
int f_prec7_negative_smallfpart_bench(void){return printf("%.7f", -7.00036);}
int f_prec7_negative_allsmall_bench(void){return printf("%.7f", -0.000032);}
int f_prec7_limits_allsmall_pos_bench(void){return printf("%.7f", 0.0000001);}
int f_prec7_limits_allsmall_neg_bench(void){return printf("%.7f", -0.0000001);}
int f_prec7_limits_smallfpart_pos_bench(void){return printf("%.7f", 9873.000001);}
int f_prec7_limits_smallfpart_neg_bench(void){return printf("%.7f", -875.000001);}
int f_prec7_limits_allbig_pos_bench(void){return printf("%.7f", 999.9999999);}
int f_prec7_limits_allbig_neg_bench(void){return printf("%.7f", -99.9999999);}
int f_prec7_limits_bigfpart_pos_bench(void){return printf("%.7f", 0.999999);}
int f_prec7_limits_bigfpart_neg_bench(void){return printf("%.7f", -0.999999);}
//Floats - Prec 7 Rounding
int f_rnd_prec7_rndd_pos_bench(void){return printf("%.7f", 23.375094499);}
int f_rnd_prec7_rndd_neg_bench(void){return printf("%.7f", -985.765426499);}
int f_rnd_prec7_rndu_pos_bench(void){return printf("%.7f", 0.0894255);}
int f_rnd_prec7_rndu_neg_bench(void){return printf("%.7f", -56.2012685);}
int f_rnd_prec7_rndu_multidigit_pos_bench(void){return printf("%.7f", 43.4399999);}
int f_rnd_prec7_rndu_multidigit_neg_bench(void){return printf("%.7f", -5.0299999);}
int f_rnd_prec7_rndd_multidigit_pos_bench(void){return printf("%.7f", 43.43999949);}
int f_rnd_prec7_rndd_multidigit_neg_bench(void){return printf("%.7f", -5.02999949);}
int f_rnd_prec7_rndd_wholnobump_pos_bench(void){return printf("%.7f", 1.99999949);}
int f_rnd_prec7_rndd_wholnobump_neg_bench(void){return printf("%.7f", -0.99999949);}
int f_rnd_prec7_rndu_bumpwhole_pos_bench(void){return printf("%.7f", 3.9999999);}
//Floats - Prec 8
int f_prec8_1_bench(void){return printf("this %.8f float", 1.5);}
int f_prec8_fltonly_bench(void){return printf("%.8f", 7.5);}
int f_prec8_whole_bench(void){return printf("%.8f", 1.0);}
int f_prec8_negative_bench(void){return printf("%.8f", -3.85);}
int f_prec8_positive_3_3_bench(void){return printf("%.8f", 573.924);}
int f_prec8_negative_3_3_bench(void){return printf("%.8f", -958.125);}
int f_prec8_positive_smallfpart_bench(void){return printf("%.8f", 23.00041);}
int f_prec8_positive_allsmall_bench(void){return printf("%.8f", 0.00000039);}
int f_prec8_negative_smallfpart_bench(void){return printf("%.8f", -7.00036);}
int f_prec8_negative_allsmall_bench(void){return printf("%.8f", -0.0000032);}
int f_prec8_limits_allsmall_pos_bench(void){return printf("%.8f", 0.00000001);}
int f_prec8_limits_allsmall_neg_bench(void){return printf("%.8f", -0.00000001);}
int f_prec8_limits_smallfpart_pos_bench(void){return printf("%.8f", 9873.000001);}
int f_prec8_limits_smallfpart_neg_bench(void){return printf("%.8f", -875.000001);}
int f_prec8_limits_allbig_pos_bench(void){return printf("%.8f", 999.9999999);}
int f_prec8_limits_allbig_neg_bench(void){return printf("%.8f", -99.99999999);}
int f_prec8_limits_bigfpart_pos_bench(void){return printf("%.8f", 0.999999);}
int f_prec8_limits_bigfpart_neg_bench(void){return printf("%.8f", -0.999999);}
//Floats - Prec 8 Rounding
int f_rnd_prec8_rndd_pos_bench(void){return printf("%.8f", 23.375094499);}
int f_rnd_prec8_rndd_neg_bench(void){return printf("%.8f", -985.765426499);}
int f_rnd_prec8_rndu_pos_bench(void){return printf("%.8f", 0.0894255);}
int f_rnd_prec8_rndu_neg_bench(void){return printf("%.8f", -56.2012685);}
int f_rnd_prec8_rndu_multidigit_pos_bench(void){return printf("%.8f", 43.4399999);}
int f_rnd_prec8_rndu_multidigit_neg_bench(void){return printf("%.8f", -5.0299999);}
int f_rnd_prec8_rndd_multidigit_pos_bench(void){return printf("%.8f", 43.43999949);}
int f_rnd_prec8_rndd_multidigit_neg_bench(void){return printf("%.8f", -5.02999949);}
int f_rnd_prec8_rndd_wholnobump_pos_bench(void){return printf("%.8f", 1.99999949);}
int f_rnd_prec8_rndd_wholnobump_neg_bench(void){return printf("%.8f", -0.99999949);}
int f_rnd_prec8_rndu_bumpwhole_pos_bench(void){return printf("%.8f", 3.9999999);}
//Floats - Prec 9
int f_stress_prec9_1_bench(void){return printf("this %.9f float", 1.5);}
int f_stress_prec9_fltonly_bench(void){return printf("%.9f", 7.5);}
int f_stress_prec9_whole_bench(void){return printf("%.9f", 1.0);}
int f_stress_prec9_negative_bench(void){return printf("%.9f", -3.85);}
int f_stress_prec9_positive_3_3_bench(void){return printf("%.9f", 573.924);}
int f_stress_prec9_negative_3_3_bench(void){return printf("%.9f", -958.125);}
int f_stress_prec9_positive_smallfpart_bench(void){return printf("%.9f", 23.00041);}
int f_stress_prec9_positive_allsmall_bench(void){return printf("%.9f", 0.00000039);}
int f_stress_prec9_negative_smallfpart_bench(void){return printf("%.9f", -7.00036);}
int f_stress_prec9_negative_allsmall_bench(void){return printf("%.9f", -0.0000032);}
int f_stress_prec9_limits_allsmall_pos_bench(void){return printf("%.9f", 0.00000001);}
int f_stress_prec9_limits_allsmall_neg_bench(void){return printf("%.9f", -0.00000001);}
int f_stress_prec9_limits_smallfpart_pos_bench(void){return printf("%.9f", 9873.000001);}
int f_stress_prec9_limits_smallfpart_neg_bench(void){return printf("%.9f", -875.000001);}
int f_stress_prec9_limits_allbig_pos_bench(void){return printf("%.9f", 999.99999999);}
int f_stress_prec9_limits_allbig_neg_bench(void){return printf("%.9f", -99.99999999);}
int f_stress_prec9_limits_bigfpart_pos_bench(void){return printf("%.9f", 0.999999);}
int f_stress_prec9_limits_bigfpart_neg_bench(void){return printf("%.9f", -0.999999);}
//Floats - Prec 9 Rounding
int f_stress_prec9_rndd_pos_bench(void){return printf("%.9f", 23.375094499);}
int f_stress_prec9_rndd_neg_bench(void){return printf("%.9f", -985.765426499);}
int f_stress_prec9_rndu_pos_bench(void){return printf("%.9f", 0.0894255);}
int f_stress_prec9_rndu_neg_bench(void){return printf("%.9f", -56.2012685);}
int f_stress_prec9_rndu_multidigit_pos_bench(void){return printf("%.9f", 43.4399999);}
int f_stress_prec9_rndu_multidigit_neg_bench(void){return printf("%.9f", -5.0299999);}
int f_stress_prec9_rndd_multidigit_pos_bench(void){return printf("%.9f", 43.43999949);}
int f_stress_prec9_rndd_multidigit_neg_bench(void){return printf("%.9f", -5.02999949);}
int f_stress_prec9_rndd_wholnobump_pos_bench(void){return printf("%.9f", 1.99999949);}
int f_stress_prec9_rndd_wholnobump_neg_bench(void){return printf("%.9f", -0.99999949);}
int f_stress_prec9_rndu_bumpwhole_pos_bench(void){return printf("%.9f", 3.9999999);}
//Floats - Prec 10
int f_stress_prec10_1_bench(void){return printf("this %.10f float", 1.5);}
int f_stress_prec10_fltonly_bench(void){return printf("%.10f", 7.5);}
int f_stress_prec10_whole_bench(void){return printf("%.10f", 1.0);}
int f_stress_prec10_negative_bench(void){return printf("%.10f", -3.85);}
int f_stress_prec10_positive_3_10_bench(void){return printf("%.10f", 573.924);}
int f_stress_prec10_negative_3_10_bench(void){return printf("%.10f", -958.125);}
int f_stress_prec10_pos_bench(void){return printf("%.10f", 23.8341375094);}
int f_stress_prec10_neg_bench(void){return printf("%.10f", -985.2459765426);}
int f_stress_prec10_rndd_pos_bench(void){return printf("%.10f", 23.8341375094499);}
int f_stress_prec10_rndd_neg_bench(void){return printf("%.10f", -985.2459765426499);}
int f_stress_prec10_rndu_pos_bench(void){return printf("%.10f", 0.87650894255);}
int f_stress_prec10_rndu_neg_bench(void){return printf("%.10f", -56.47852012685);}
int f_stress_prec10_positive_smallfpart_bench(void){return printf("%.10f", 23.000000041);}
int f_stress_prec10_positive_allsmall_bench(void){return printf("%.10f", 0.0000000039);}
int f_stress_prec10_negative_smallfpart_bench(void){return printf("%.10f", -7.000000036);}
int f_stress_prec10_negative_allsmall_bench(void){return printf("%.10f", -0.000000032);}
int f_stress_prec10_limits_allsmall_pos_bench(void){return printf("%.10f", 0.0000000001);}
int f_stress_prec10_limits_allsmall_neg_bench(void){return printf("%.10f", -0.0000000001);}
int f_stress_prec10_limits_smallfpart_pos_bench(void){return printf("%.10f", 9873.0000000001);}
int f_stress_prec10_limits_smallfpart_neg_bench(void){return printf("%.10f", -875.0000000001);}
int f_stress_prec10_limits_allbig_pos_bench(void){return printf("%.10f", 999.9999999999);}
int f_stress_prec10_limits_allbig_neg_bench(void){return printf("%.10f", -99.9999999999);}
int f_stress_prec10_limits_bigfpart_pos_bench(void){return printf("%.10f", 0.9999999999);}
int f_stress_prec10_limits_bigfpart_neg_bench(void){return printf("%.10f", -0.9999999999);}
//Floats - Prec 11
int f_stress_prec11_rndu_bench(void){return printf("%.11f",        1.025978541236587568);}
int f_stress_prec11_rndd_bench(void){return printf("%.11f",        1.025978548534310421);}
int f_stress_prec11_limits_tiny_bench(void){return printf("%.11f", 0.000000000010000000);}
int f_stress_prec11_limits_big_bench(void){return printf("%.11f", 99.999999999990000000);}
//Floats - Prec 12
int f_stress_prec12_rndu_bench(void){return printf("%.12f",        1.025978541236587568);}
int f_stress_prec12_rndd_bench(void){return printf("%.12f",        1.025978548534310421);}
int f_stress_prec12_limits_tiny_bench(void){return printf("%.12f", 0.000000000001000000);}
int f_stress_prec12_limits_big_bench(void){return printf("%.12f", 99.999999999999000000);}
//Floats - Prec 13
int f_stress_prec13_rndu_bench(void){return printf("%.13f",        1.025978541136587568);}
int f_stress_prec13_rndd_bench(void){return printf("%.13f",        1.025978548534310421);}
int f_stress_prec13_limits_tiny_bench(void){return printf("%.13f", 0.000000000000100000);}
int f_stress_prec13_limits_big_bench(void){return printf("%.13f", 99.999999999999900000);}
//Floats - Prec 14
int f_stress_prec14_rndu_bench(void){return printf("%.14f",        1.025978541436587568);}
int f_stress_prec14_rndd_bench(void){return printf("%.14f",        1.025978548534310421);}
int f_stress_prec14_limits_tiny_bench(void){return printf("%.14f", 0.000000000000010000);}
int f_stress_prec14_limits_big_bench(void){return printf("%.14f",  9.999999999999990000);}
//Floats - Prec 15
int f_stress_prec15_rndu_bench(void){return printf("%.15f",        1.025978542436587568);}
int f_stress_prec15_rndd_bench(void){return printf("%.15f",        1.025978548534310421);}
int f_stress_prec15_limits_tiny_bench(void){return printf("%.15f", 0.000000000000001000);}
int f_stress_prec15_limits_big_bench(void){return printf("%.15f",  0.999999999999999000);}
//Floats - Prec 16
int f_stress_prec16_rndu_bench(void){return printf("%.16f",        1.025978542436587568);}
int f_stress_prec16_rndd_bench(void){return printf("%.16f",        1.025978548534310421);}
int f_stress_prec16_limits_tiny_bench(void){return printf("%.16f", 0.000000000000000100);}
int f_stress_prec16_limits_big_bench(void){return printf("%.16f",  0.999999999999999900);}
//Floats - Prec 17
int f_stress_prec17_rndu_bench(void){return printf("%.17f",        1.025978542436587568);}
int f_stress_prec17_rndd_bench(void){return printf("%.17f",        1.025978548534310421);}
int f_stress_prec17_limits_tiny_bench(void){return printf("%.17f", 0.000000000000000010);}
int f_stress_prec17_limits_big_bench(void){return printf("%.17f",  0.999999999999999990);}
//Floats - Prec 18
int f_stress_prec18_rndu_bench(void){return printf("%.18f",        0.125978542436587568);}
int f_stress_prec18_rndd_bench(void){return printf("%.18f",        0.125978548534310421);}
//Floats with altform,~
int		f_af_prec0p_bench(void){return printf("%#.0f", 7.4);}
int		f_af_prec1p_bench(void){return printf("%#.1f", 7.3);}
int		f_af_prec0n_bench(void){return printf("%#.0f", -7.4);}
int		f_af_prec1n_bench(void){return printf("%#.1f", -7.3);}
//Floats with allsign,~
int		f_as_prec0p_as_bench(void){return printf("%+.0f", 7.4);}
int		f_as_prec3p_as_bench(void){return printf("%+.3f", 7.3);}
int		f_as_prec0n_as_bench(void){return printf("%+.0f", -7.4);}
int		f_as_prec3n_as_bench(void){return printf("%+.3f", -7.3);}
//Floats with field width,~
int f_wprec0p_bench(void){return printf("%5.0f", 7.3);}
int f_wprec1p_bench(void){return printf("%5.1f", 7.3);}
int f_wprec3p_bench(void){return printf("%5.3f", 7.3);}
int f_wprec6p_bench(void){return printf("%5.6f", 7.3);}
int f_wprec0n_bench(void){return printf("%5.0f", -7.3);}
int f_wprec1n_bench(void){return printf("%5.1f", -7.3);}
int f_wprec3n_bench(void){return printf("%5.3f", -7.3);}
int f_wprec6n_bench(void){return printf("%5.6f", -7.3);}
//Floats with field width and zero padding,~
int f_wzp_prec0p_bench(void){return printf("%05.0f", 7.3);}
int f_wzp_prec1p_bench(void){return printf("%05.1f", 7.3);}
int f_wzp_prec3p_bench(void){return printf("%05.3f", 7.3);}
int f_wzp_prec6p_bench(void){return printf("%05.6f", 7.3);}
int f_wzp_prec0n_bench(void){return printf("%05.0f", -7.3);}
int f_wzp_prec1n_bench(void){return printf("%05.1f", -7.3);}
int f_wzp_prec3n_bench(void){return printf("%05.3f", -7.3);}
int f_wzp_prec6n_bench(void){return printf("%05.6f", -7.3);}
//Floats with field width and left justify,~
int f_wlj_prec0p_bench(void){return printf("%-5.0f", 7.3);}
int f_wlj_prec1p_bench(void){return printf("%-5.1f", 7.3);}
int f_wlj_prec3p_bench(void){return printf("%-5.3f", 7.3);}
int f_wlj_prec6p_bench(void){return printf("%-5.6f", 7.3);}
int f_wlj_prec0n_bench(void){return printf("%-5.0f", -7.3);}
int f_wlj_prec1n_bench(void){return printf("%-5.1f", -7.3);}
int f_wlj_prec3n_bench(void){return printf("%-5.3f", -7.3);}
int f_wlj_prec6n_bench(void){return printf("%-5.6f", -7.3);}
//Floats with field width and zero padding and left justify,~
int f_wzplj_prec0p_ignoreflag_bench(void){return printf("%-05.0f", 7.3);}
int f_wzplj_prec1p_ignoreflag_bench(void){return printf("%-05.1f", 7.3);}
int f_wzplj_prec3p_ignoreflag_bench(void){return printf("%-05.3f", 7.3);}
int f_wzplj_prec6p_ignoreflag_bench(void){return printf("%-05.6f", 7.3);}
int f_wzplj_prec0n_ignoreflag_bench(void){return printf("%-05.0f", -7.3);}
int f_wzplj_prec1n_ignoreflag_bench(void){return printf("%-05.1f", -7.3);}
int f_wzplj_prec3n_ignoreflag_bench(void){return printf("%-05.3f", -7.3);}
int f_wzplj_prec6n_ignoreflag_bench(void){return printf("%-05.6f", -7.3);}
//Floats with field width and zero padding and left justify, rev f order,~
int f_wzpljr_prec0p_ignoreflag_bench(void){return printf("%0-5.0f", 7.3);}
int f_wzpljr_prec1p_ignoreflag_bench(void){return printf("%0-5.1f", 7.3);}
int f_wzpljr_prec3p_ignoreflag_bench(void){return printf("%0-5.3f", 7.3);}
int f_wzpljr_prec6p_ignoreflag_bench(void){return printf("%0-5.6f", 7.3);}
int f_wzpljr_prec0n_ignoreflag_bench(void){return printf("%0-5.0f", -7.3);}
int f_wzpljr_prec1n_ignoreflag_bench(void){return printf("%0-5.1f", -7.3);}
int f_wzpljr_prec3n_ignoreflag_bench(void){return printf("%0-5.3f", -7.3);}
int f_wzpljr_prec6n_ignoreflag_bench(void){return printf("%0-5.6f", -7.3);}
//Floats with field width and left justify and altform,~
int f_wzpljaf_prec0p_bench(void){return printf("%#-5.0f", 7.3);}
int f_wzpljaf_prec1p_bench(void){return printf("%#-5.1f", 7.3);}
int f_wzpljaf_prec3p_bench(void){return printf("%#-5.3f", 7.3);}
int f_wzpljaf_prec6p_bench(void){return printf("%#-5.6f", 7.3);}
int f_wzpljaf_prec0n_bench(void){return printf("%#-5.0f", -7.3);}
int f_wzpljaf_prec1n_bench(void){return printf("%#-5.1f", -7.3);}
int f_wzpljaf_prec3n_bench(void){return printf("%#-5.3f", -7.3);}
int f_wzpljaf_prec6n_bench(void){return printf("%#-5.6f", -7.3);}
//Floats with field width and allsign,~
int f_was_prec0p_bench(void){return printf("%+5.0f", 7.3);}
int f_was_prec1p_bench(void){return printf("%+5.1f", 7.3);}
int f_was_prec3p_bench(void){return printf("%+5.3f", 7.3);}
int f_was_prec6p_bench(void){return printf("%+5.6f", 7.3);}
int f_was_prec0n_bench(void){return printf("%+5.0f", -7.3);}
int f_was_prec1n_bench(void){return printf("%+5.1f", -7.3);}
int f_was_prec3n_bench(void){return printf("%+5.3f", -7.3);}
int f_was_prec6n_bench(void){return printf("%+5.6f", -7.3);}
//Floats with field width and zero padding and allsign,~
int f_wzpas_prec0p_bench(void){return printf("%+05.0f", 7.3);}
int f_wzpas_prec1p_bench(void){return printf("%+05.1f", 7.3);}
int f_wzpas_prec3p_bench(void){return printf("%+05.3f", 7.3);}
int f_wzpas_prec6p_bench(void){return printf("%+05.6f", 7.3);}
int f_wzpas_prec0n_bench(void){return printf("%+05.0f", -7.3);}
int f_wzpas_prec1n_bench(void){return printf("%+05.1f", -7.3);}
int f_wzpas_prec3n_bench(void){return printf("%+05.3f", -7.3);}
int f_wzpas_prec6n_bench(void){return printf("%+05.6f", -7.3);}
//Floats with field width and left justify and allsign,~
int f_wljas_prec0p_bench(void){return printf("%+-5.0f", 7.3);}
int f_wljas_prec1p_bench(void){return printf("%+-5.1f", 7.3);}
int f_wljas_prec3p_bench(void){return printf("%+-5.3f", 7.3);}
int f_wljas_prec6p_bench(void){return printf("%+-5.6f", 7.3);}
int f_wljas_prec0n_bench(void){return printf("%+-5.0f", -7.3);}
int f_wljas_prec1n_bench(void){return printf("%+-5.1f", -7.3);}
int f_wljas_prec3n_bench(void){return printf("%+-5.3f", -7.3);}
int f_wljas_prec6n_bench(void){return printf("%+-5.6f", -7.3);}
//Floats with field width and zero padding and left justify and allsign,~
int f_wzpljas_prec0p_ignoreflag_bench(void){return printf("%+-05.0f", 7.3);}
int f_wzpljas_prec1p_ignoreflag_bench(void){return printf("%+-05.1f", 7.3);}
int f_wzpljas_prec3p_ignoreflag_bench(void){return printf("%+-05.3f", 7.3);}
int f_wzpljas_prec6p_ignoreflag_bench(void){return printf("%+-05.6f", 7.3);}
int f_wzpljas_prec0n_ignoreflag_bench(void){return printf("%+-05.0f", -7.3);}
int f_wzpljas_prec1n_ignoreflag_bench(void){return printf("%+-05.1f", -7.3);}
int f_wzpljas_prec3n_ignoreflag_bench(void){return printf("%+-05.3f", -7.3);}
int f_wzpljas_prec6n_ignoreflag_bench(void){return printf("%+-05.6f", -7.3);}
//Floats with field width left justify, rev f order and allsign,~
int f_wzpljras_prec0p_bench(void){return printf("%-+5.0f", 7.3);}
int f_wzpljras_prec1p_bench(void){return printf("%-+5.1f", 7.3);}
int f_wzpljras_prec3p_bench(void){return printf("%-+5.3f", 7.3);}
int f_wzpljras_prec6p_bench(void){return printf("%-+5.6f", 7.3);}
int f_wzpljras_prec0n_bench(void){return printf("%-+5.0f", -7.3);}
int f_wzpljras_prec1n_bench(void){return printf("%-+5.1f", -7.3);}
int f_wzpljras_prec3n_bench(void){return printf("%-+5.3f", -7.3);}
int f_wzpljras_prec6n_bench(void){return printf("%-+5.6f", -7.3);}
//Floats with field width and left justify and altform and allsign,~
int f_wzpljafas_prec0p_bench(void){return printf("%+#-5.0f", 7.3);}
int f_wzpljafas_prec1p_bench(void){return printf("%+#-5.1f", 7.3);}
int f_wzpljafas_prec3p_bench(void){return printf("%+#-5.3f", 7.3);}
int f_wzpljafas_prec6p_bench(void){return printf("%+#-5.6f", 7.3);}
int f_wzpljafas_prec0n_bench(void){return printf("%+#-5.0f", -7.3);}
int f_wzpljafas_prec1n_bench(void){return printf("%+#-5.1f", -7.3);}
int f_wzpljafas_prec3n_bench(void){return printf("%+#-5.3f", -7.3);}
int f_wzpljafas_prec6n_bench(void){return printf("%+#-5.6f", -7.3);}
//Floats with field width and sp,~
int f_wsp_prec0p_bench(void){return printf("% 5.0f", 7.3);}
int f_wsp_prec1p_bench(void){return printf("% 5.1f", 7.3);}
int f_wsp_prec3p_bench(void){return printf("% 5.3f", 7.3);}
int f_wsp_prec6p_bench(void){return printf("% 5.6f", 7.3);}
int f_wsp_prec0n_bench(void){return printf("% 5.0f", -7.3);}
int f_wsp_prec1n_bench(void){return printf("% 5.1f", -7.3);}
int f_wsp_prec3n_bench(void){return printf("% 5.3f", -7.3);}
int f_wsp_prec6n_bench(void){return printf("% 5.6f", -7.3);}
//Floats with field width and zero padding and sp,~
int f_wzpsp_prec0p_bench(void){return printf("% 05.0f", 7.3);}
int f_wzpsp_prec1p_bench(void){return printf("% 05.1f", 7.3);}
int f_wzpsp_prec3p_bench(void){return printf("% 05.3f", 7.3);}
int f_wzpsp_prec6p_bench(void){return printf("% 05.6f", 7.3);}
int f_wzpsp_prec0n_bench(void){return printf("% 05.0f", -7.3);}
int f_wzpsp_prec1n_bench(void){return printf("% 05.1f", -7.3);}
int f_wzpsp_prec3n_bench(void){return printf("% 05.3f", -7.3);}
int f_wzpsp_prec6n_bench(void){return printf("% 05.6f", -7.3);}
//Floats with field width and left justify and sp,~
int f_wljsp_prec0p_bench(void){return printf("% -5.0f", 7.3);}
int f_wljsp_prec1p_bench(void){return printf("% -5.1f", 7.3);}
int f_wljsp_prec3p_bench(void){return printf("% -5.3f", 7.3);}
int f_wljsp_prec6p_bench(void){return printf("% -5.6f", 7.3);}
int f_wljsp_prec0n_bench(void){return printf("% -5.0f", -7.3);}
int f_wljsp_prec1n_bench(void){return printf("% -5.1f", -7.3);}
int f_wljsp_prec3n_bench(void){return printf("% -5.3f", -7.3);}
int f_wljsp_prec6n_bench(void){return printf("% -5.6f", -7.3);}
//Floats with field width and zero padding and left justify and sp,~
int f_wzpljsp_prec0p_ignoreflag_bench(void){return printf("% -05.0f", 7.3);}
int f_wzpljsp_prec1p_ignoreflag_bench(void){return printf("% -05.1f", 7.3);}
int f_wzpljsp_prec3p_ignoreflag_bench(void){return printf("% -05.3f", 7.3);}
int f_wzpljsp_prec6p_ignoreflag_bench(void){return printf("% -05.6f", 7.3);}
int f_wzpljsp_prec0n_ignoreflag_bench(void){return printf("% -05.0f", -7.3);}
int f_wzpljsp_prec1n_ignoreflag_bench(void){return printf("% -05.1f", -7.3);}
int f_wzpljsp_prec3n_ignoreflag_bench(void){return printf("% -05.3f", -7.3);}
int f_wzpljsp_prec6n_ignoreflag_bench(void){return printf("% -05.6f", -7.3);}
//Floats with field width left justify, rev f order and sp,~
int f_wzpljrsp_prec0p_bench(void){return printf("%- 5.0f", 7.3);}
int f_wzpljrsp_prec1p_bench(void){return printf("%- 5.1f", 7.3);}
int f_wzpljrsp_prec3p_bench(void){return printf("%- 5.3f", 7.3);}
int f_wzpljrsp_prec6p_bench(void){return printf("%- 5.6f", 7.3);}
int f_wzpljrsp_prec0n_bench(void){return printf("%- 5.0f", -7.3);}
int f_wzpljrsp_prec1n_bench(void){return printf("%- 5.1f", -7.3);}
int f_wzpljrsp_prec3n_bench(void){return printf("%- 5.3f", -7.3);}
int f_wzpljrsp_prec6n_bench(void){return printf("%- 5.6f", -7.3);}
//Floats with field width and left justify and altform and sp,~
int f_wzpljafsp_prec0p_bench(void){return printf("% #-5.0f", 7.3);}
int f_wzpljafsp_prec1p_bench(void){return printf("% #-5.1f", 7.3);}
int f_wzpljafsp_prec3p_bench(void){return printf("% #-5.3f", 7.3);}
int f_wzpljafsp_prec6p_bench(void){return printf("% #-5.6f", 7.3);}
int f_wzpljafsp_prec0n_bench(void){return printf("% #-5.0f", -7.3);}
int f_wzpljafsp_prec1n_bench(void){return printf("% #-5.1f", -7.3);}
int f_wzpljafsp_prec3n_bench(void){return printf("% #-5.3f", -7.3);}
int f_wzpljafsp_prec6n_bench(void){return printf("% #-5.6f", -7.3);}
//Floats with allsign and sp,~
int f_assp_prec0p_ignoreflag_bench(void){return printf("%+ .0f", 7.3);}
int f_assp_prec1p_ignoreflag_bench(void){return printf("%+ .1f", 7.3);}
int f_assp_prec3p_ignoreflag_bench(void){return printf("%+ .3f", 7.3);}
int f_assp_prec6p_ignoreflag_bench(void){return printf("%+ .6f", 7.3);}
int f_assp_prec0n_ignoreflag_bench(void){return printf("%+ .0f", -7.3);}
int f_assp_prec1n_ignoreflag_bench(void){return printf("%+ .1f", -7.3);}
int f_assp_prec3n_ignoreflag_bench(void){return printf("%+ .3f", -7.3);}
int f_assp_prec6n_ignoreflag_bench(void){return printf("%+ .6f", -7.3);}
//Floats with allsign and sp and rev flag order,~
int f_asspr_prec0p_ignoreflag_bench(void){return printf("% +.0f", 7.3);}
int f_asspr_prec1p_ignoreflag_bench(void){return printf("% +.1f", 7.3);}
int f_asspr_prec3p_ignoreflag_bench(void){return printf("% +.3f", 7.3);}
int f_asspr_prec6p_ignoreflag_bench(void){return printf("% +.6f", 7.3);}
int f_asspr_prec0n_ignoreflag_bench(void){return printf("% +.0f", -7.3);}
int f_asspr_prec1n_ignoreflag_bench(void){return printf("% +.1f", -7.3);}
int f_asspr_prec3n_ignoreflag_bench(void){return printf("% +.3f", -7.3);}
int f_asspr_prec6n_ignoreflag_bench(void){return printf("% +.6f", -7.3);}
//Floats whose precision exceeds their compiled literal precision
int f_overprec_might_be_undefbehav_100_bench(void){return printf("%.100f", 0.237);}
int f_overprec_might_be_undefbehav_32_bench(void){return printf("%.32f", 0.237);}
int f_overprec_might_be_undefbehav_4_bench(void){return printf("%.4f", 0.237);}
int f_overprec_might_be_undefbehav_1000_bench(void){return printf("%.4f", -0.106577568068517810765107851705167);}
int f_overprec_might_be_undefbehav_10_from_0_bench(void){return printf("%.10f", 0.0);}
int f_overprec_might_be_undefbehav_2000_bench(void){return printf("%.2000f", 623.28376510723481);}
int f_overprec_might_be_undefbehav_dblmin_bench(void){return printf("%.2000f", DBL_MIN);}
int f_overprec_might_be_undefbehav_ndblmin_bench(void){return printf("%.2000f", -DBL_MIN);}
//Floats at double max, double min
int f_limits_dblmax_prec0_notmandatory_bench(void){return printf("%.0f", DBL_MAX);}
int f_limits_dblmax_prec3_notmandatory_bench(void){return printf("%.3f", DBL_MAX);}
int f_limits_dblmax_precd_notmandatory_bench(void){return printf("%f", DBL_MAX);}
int f_limits_dblmax_prec8_notmandatory_bench(void){return printf("%.8f", DBL_MAX);}
int f_stress_limits_dblmax_prec12_notmandatory_bench(void){return printf("%.12f", DBL_MAX);}
int f_stress_limits_dblmax_prec16_notmandatory_bench(void){return printf("%.16f", DBL_MAX);}
int f_stress_limits_dblmax_prec18_notmandatory_bench(void){return printf("%.18f", DBL_MAX);}
int f_limits_ndblmax_prec0_notmandatory_bench(void){return printf("%.0f", -DBL_MAX);}
int f_limits_ndblmax_prec3_notmandatory_bench(void){return printf("%.3f", -DBL_MAX);}
int f_limits_ndblmax_precd_notmandatory_bench(void){return printf("%f", -DBL_MAX);}
int f_limits_ndblmax_prec8_notmandatory_bench(void){return printf("%.8f", -DBL_MAX);}
int f_stress_limits_ndblmax_prec12_notmandatory_bench(void){return printf("%.12f", -DBL_MAX);}
int f_stress_limits_ndblmax_prec16_notmandatory_bench(void){return printf("%.16f", -DBL_MAX);}
int f_stress_limits_ndblmax_prec18_notmandatory_bench(void){return printf("%.18f", -DBL_MAX);}
int f_limits_dblmin_prec0_bench(void){return printf("%.0f", DBL_MIN);}
int f_limits_dblmin_prec3_bench(void){return printf("%.3f", DBL_MIN);}
int f_limits_dblmin_precd_bench(void){return printf("%f", DBL_MIN);}
int f_limits_dblmin_prec8_bench(void){return printf("%.8f", DBL_MIN);}
int f_stress_limits_dblmin_prec12_bench(void){return printf("%.12f", DBL_MIN);}
int f_stress_limits_dblmin_prec16_bench(void){return printf("%.16f", DBL_MIN);}
int f_stress_limits_dblmin_prec18_bench(void){return printf("%.18f", DBL_MIN);}
int f_limits_ndblmin_prec0_bench(void){return printf("%.0f", -DBL_MIN);}
int f_limits_ndblmin_prec3_bench(void){return printf("%.3f", -DBL_MIN);}
int f_limits_ndblmin_precd_bench(void){return printf("%f", -DBL_MIN);}
int f_limits_ndblmin_prec8_bench(void){return printf("%.8f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec12_bench(void){return printf("%.12f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec16_bench(void){return printf("%.16f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec18_bench(void){return printf("%.18f", -DBL_MIN);}

//Floats of special values
int f_reserved_values_inf_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("%f", special);}
int f_reserved_values_ninf_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("%f", special);}
int f_reserved_values_nan_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("%f", special);}
int f_reserved_values_pzero_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("%f", special);}
int f_reserved_values_nzero_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("%f", special);}
int f_reserved_values_inf_6w_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("%6f", special);}
int f_reserved_values_ninf_6w_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("%6f", special);}
int f_reserved_values_nan_6w_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("%6f", special);}
int f_reserved_values_pzero_6w_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("%6f", special);}
int f_reserved_values_nzero_6w_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("%6f", special);}
int f_reserved_values_inf_6wlj_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("%-6f", special);}
int f_reserved_values_ninf_6wlj_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("%-6f", special);}
int f_reserved_values_nan_6wlj_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("%-6f", special);}
int f_reserved_values_pzero_6wlj_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("%-6f", special);}
int f_reserved_values_nzero_6wlj_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("%-6f", special);}
int f_reserved_values_inf_6was_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("%+6f", special);}
int f_reserved_values_ninf_6was_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("%+6f", special);}
int f_reserved_values_nan_6was_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("%+6f", special);}
int f_reserved_values_pzero_6was_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("%+6f", special);}
int f_reserved_values_nzero_6was_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("%+6f", special);}
int f_reserved_values_inf_10w_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("%10.7f", special);}
int f_reserved_values_ninf_10w_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("%10.7f", special);}
int f_reserved_values_nan_10w_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("%10.7f", special);}
int f_reserved_values_pzero_10w_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("%10.7f", special);}
int f_reserved_values_nzero_10w_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("%10.7f", special);}
int f_reserved_values_inf_sp_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("% .7f", special);}
int f_reserved_values_ninf_sp_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("% .7f", special);}
int f_reserved_values_nan_sp_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("% .7f", special);}
int f_reserved_values_pzero_sp_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("% .7f", special);}
int f_reserved_values_nzero_sp_prec7_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("% .7f", special);}
int f_reserved_values_inf_sp_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("% f", special);}
int f_reserved_values_ninf_sp_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("% f", special);}
int f_reserved_values_nan_sp_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("% f", special);}
int f_reserved_values_pzero_sp_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("% f", special);}
int f_reserved_values_nzero_sp_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("% f", special);}
int f_reserved_values_inf_6wzp_bench(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return printf("%06f", special);}
int f_reserved_values_ninf_6wzp_bench(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return printf("%06f", special);}
int f_reserved_values_nan_6wzp_bench(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return printf("%06f", special);}
int f_reserved_values_pzero_6wzp_bench(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return printf("%06f", special);}
int f_reserved_values_nzero_6wzp_bench(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return printf("%06f", special);}

//Long Doubles - Basic
int f_L_basic_1_bench(void){return printf("this %Lf float", 1.5l);}
int f_L_basic_fltonly_bench(void){return printf("%Lf", 7.5l);}
int f_L_basic_whole_bench(void){return printf("%Lf", 1.0l);}
int f_L_basic_negative_bench(void){return printf("%Lf", -3.85l);}
int f_L_basic_positive_3_3_bench(void){return printf("%Lf", 573.924l);}
int f_L_basic_negative_3_3_bench(void){return printf("%Lf", -958.125l);}
int f_L_basic_positive_smallfpart_bench(void){return printf("%Lf", 23.00041l);}
int f_L_basic_positive_allsmall_bench(void){return printf("%Lf", 0.000039l);}
int f_L_basic_negative_smallfpart_bench(void){return printf("%Lf", -7.00036l);}
int f_L_basic_negative_allsmall_bench(void){return printf("%Lf", -0.00032l);}
int f_L_basic_limits_allsmall_pos_bench(void){return printf("%Lf", 0.000001l);}
int f_L_basic_limits_allsmall_neg_bench(void){return printf("%Lf", -0.000001l);}
int f_L_basic_limits_smallfpart_pos_bench(void){return printf("%Lf", 9873.000001l);}
int f_L_basic_limits_smallfpart_neg_bench(void){return printf("%Lf", -875.000001l);}
int f_L_basic_limits_allbig_pos_bench(void){return printf("%Lf", 999.999999l);}
int f_L_basic_limits_allbig_neg_bench(void){return printf("%Lf", -99.999999l);}
int f_L_basic_limits_bigfpart_pos_bench(void){return printf("%Lf", 0.999999l);}
int f_L_basic_limits_bigfpart_neg_bench(void){return printf("%Lf", -0.999999l);}
//Long Doubles - Rounding with default precision
int f_L_rndd_pos_bench(void){return printf("%Lf", 23.375094499l);}
int f_L_rndd_neg_bench(void){return printf("%Lf", -985.765426499l);}
int f_L_rndu_pos_bench(void){return printf("%Lf", 0.08942555l);}
int f_L_rndu_neg_bench(void){return printf("%Lf", -56.2012685l);}
int f_L_rndu_multidigit_pos_bench(void){return printf("%Lf", 43.4399999l);}
int f_L_rndu_multidigit_neg_bench(void){return printf("%Lf", -5.0299999l);}
int f_L_rndd_multidigit_pos_bench(void){return printf("%Lf", 43.43999949l);}
int f_L_rndd_multidigit_neg_bench(void){return printf("%Lf", -5.02999949l);}
int f_L_rndd_wholnobump_pos_bench(void){return printf("%Lf", 1.99999949l);}
int f_L_rndd_wholnobump_neg_bench(void){return printf("%Lf", -0.99999949l);}
int f_L_rndu_bumpwhole_pos_bench(void){return printf("%Lf", 3.9999999l);}
int f_L_rndu_bumpwhole_neg_bench(void){return printf("%Lf", -5.9999999l);}
//Long Doubles - Prec 7
int f_L_prec7_1_bench(void){return printf("this %.7Lf float", 1.5l);}
int f_L_prec7_fltonly_bench(void){return printf("%.7Lf", 7.5l);}
int f_L_prec7_whole_bench(void){return printf("%.7Lf", 1.0l);}
int f_L_prec7_negative_bench(void){return printf("%.7Lf", -3.85l);}
int f_L_prec7_positive_3_3_bench(void){return printf("%.7Lf", 573.924l);}
int f_L_prec7_negative_3_3_bench(void){return printf("%.7Lf", -958.125l);}
int f_L_prec7_positive_smallfpart_bench(void){return printf("%.7Lf", 23.00041l);}
int f_L_prec7_positive_allsmall_bench(void){return printf("%.7Lf", 0.0000039l);}
int f_L_prec7_negative_smallfpart_bench(void){return printf("%.7Lf", -7.00036l);}
int f_L_prec7_negative_allsmall_bench(void){return printf("%.7Lf", -0.000032l);}
int f_L_prec7_limits_allsmall_pos_bench(void){return printf("%.7Lf", 0.0000001l);}
int f_L_prec7_limits_allsmall_neg_bench(void){return printf("%.7Lf", -0.0000001l);}
int f_L_prec7_limits_smallfpart_pos_bench(void){return printf("%.7Lf", 9873.000001l);}
int f_L_prec7_limits_smallfpart_neg_bench(void){return printf("%.7Lf", -875.000001l);}
int f_L_prec7_limits_allbig_pos_bench(void){return printf("%.7Lf", 999.9999999l);}
int f_L_prec7_limits_allbig_neg_bench(void){return printf("%.7Lf", -99.9999999l);}
int f_L_prec7_limits_bigfpart_pos_bench(void){return printf("%.7Lf", 0.999999l);}
int f_L_prec7_limits_bigfpart_neg_bench(void){return printf("%.7Lf", -0.999999l);}
//Long Doubles - Prec 7 Rounding
int f_L_rnd_prec7_rndd_pos_bench(void){return printf("%.7Lf", 23.375094499l);}
int f_L_rnd_prec7_rndd_neg_bench(void){return printf("%.7Lf", -985.765426499l);}
int f_L_rnd_prec7_rndu_pos_bench(void){return printf("%.7Lf", 0.0894255l);}
int f_L_rnd_prec7_rndu_neg_bench(void){return printf("%.7Lf", -56.2012685l);}
int f_L_rnd_prec7_rndu_multidigit_pos_bench(void){return printf("%.7Lf", 43.4399999l);}
int f_L_rnd_prec7_rndu_multidigit_neg_bench(void){return printf("%.7Lf", -5.0299999l);}
int f_L_rnd_prec7_rndd_multidigit_pos_bench(void){return printf("%.7Lf", 43.43999949l);}
int f_L_rnd_prec7_rndd_multidigit_neg_bench(void){return printf("%.7Lf", -5.02999949l);}
int f_L_rnd_prec7_rndd_wholnobump_pos_bench(void){return printf("%.7Lf", 1.99999949l);}
int f_L_rnd_prec7_rndd_wholnobump_neg_bench(void){return printf("%.7Lf", -0.99999949l);}
int f_L_rnd_prec7_rndu_bumpwhole_pos_bench(void){return printf("%.7Lf", 3.9999999l);}
//Long Doubles - Prec 8
int f_L_prec8_1_bench(void){return printf("this %.8Lf float", 1.5l);}
int f_L_prec8_fltonly_bench(void){return printf("%.8Lf", 7.5l);}
int f_L_prec8_whole_bench(void){return printf("%.8Lf", 1.0l);}
int f_L_prec8_negative_bench(void){return printf("%.8Lf", -3.85l);}
int f_L_prec8_positive_3_3_bench(void){return printf("%.8Lf", 573.924l);}
int f_L_prec8_negative_3_3_bench(void){return printf("%.8Lf", -958.125l);}
int f_L_prec8_positive_smallfpart_bench(void){return printf("%.8Lf", 23.00041l);}
int f_L_prec8_positive_allsmall_bench(void){return printf("%.8Lf", 0.00000039l);}
int f_L_prec8_negative_smallfpart_bench(void){return printf("%.8Lf", -7.00036l);}
int f_L_prec8_negative_allsmall_bench(void){return printf("%.8Lf", -0.0000032l);}
int f_L_prec8_limits_allsmall_pos_bench(void){return printf("%.8Lf", 0.00000001l);}
int f_L_prec8_limits_allsmall_neg_bench(void){return printf("%.8Lf", -0.00000001l);}
int f_L_prec8_limits_smallfpart_pos_bench(void){return printf("%.8Lf", 9873.000001l);}
int f_L_prec8_limits_smallfpart_neg_bench(void){return printf("%.8Lf", -875.000001l);}
int f_L_prec8_limits_allbig_pos_bench(void){return printf("%.8Lf", 999.9999999l);}
int f_L_prec8_limits_allbig_neg_bench(void){return printf("%.8Lf", -99.99999999l);}
int f_L_prec8_limits_bigfpart_pos_bench(void){return printf("%.8Lf", 0.999999l);}
int f_L_prec8_limits_bigfpart_neg_bench(void){return printf("%.8Lf", -0.999999l);}
//Long Doubles - Prec 8 Rounding
int f_L_rnd_prec8_rndd_pos_bench(void){return printf("%.8Lf", 23.375094499l);}
int f_L_rnd_prec8_rndd_neg_bench(void){return printf("%.8Lf", -985.765426499l);}
int f_L_rnd_prec8_rndu_pos_bench(void){return printf("%.8Lf", 0.0894255l);}
int f_L_rnd_prec8_rndu_neg_bench(void){return printf("%.8Lf", -56.2012685l);}
int f_L_rnd_prec8_rndu_multidigit_pos_bench(void){return printf("%.8Lf", 43.4399999l);}
int f_L_rnd_prec8_rndu_multidigit_neg_bench(void){return printf("%.8Lf", -5.0299999l);}
int f_L_rnd_prec8_rndd_multidigit_pos_bench(void){return printf("%.8Lf", 43.43999949l);}
int f_L_rnd_prec8_rndd_multidigit_neg_bench(void){return printf("%.8Lf", -5.02999949l);}
int f_L_rnd_prec8_rndd_wholnobump_pos_bench(void){return printf("%.8Lf", 1.99999949l);}
int f_L_rnd_prec8_rndd_wholnobump_neg_bench(void){return printf("%.8Lf", -0.99999949l);}
int f_L_rnd_prec8_rndu_bumpwhole_pos_bench(void){return printf("%.8Lf", 3.9999999l);}
//Long Doubles - Prec 9
int f_L_prec9_1_bench(void){return printf("this %.9Lf float", 1.5l);}
int f_L_prec9_fltonly_bench(void){return printf("%.9Lf", 7.5l);}
int f_L_prec9_whole_bench(void){return printf("%.9Lf", 1.0l);}
int f_L_prec9_negative_bench(void){return printf("%.9Lf", -3.85l);}
int f_L_prec9_positive_3_3_bench(void){return printf("%.9Lf", 573.924l);}
int f_L_prec9_negative_3_3_bench(void){return printf("%.9Lf", -958.125l);}
int f_L_prec9_positive_smallfpart_bench(void){return printf("%.9Lf", 23.00041l);}
int f_L_prec9_positive_allsmall_bench(void){return printf("%.9Lf", 0.00000039l);}
int f_L_prec9_negative_smallfpart_bench(void){return printf("%.9Lf", -7.00036l);}
int f_L_prec9_negative_allsmall_bench(void){return printf("%.9Lf", -0.0000032l);}
int f_L_prec9_limits_allsmall_pos_bench(void){return printf("%.9Lf", 0.00000001l);}
int f_L_prec9_limits_allsmall_neg_bench(void){return printf("%.9Lf", -0.00000001l);}
int f_L_prec9_limits_smallfpart_pos_bench(void){return printf("%.9Lf", 9873.000001l);}
int f_L_prec9_limits_smallfpart_neg_bench(void){return printf("%.9Lf", -875.000001l);}
int f_L_prec9_limits_allbig_pos_bench(void){return printf("%.9Lf", 999.99999999l);}
int f_L_prec9_limits_allbig_neg_bench(void){return printf("%.9Lf", -99.99999999l);}
int f_L_prec9_limits_bigfpart_pos_bench(void){return printf("%.9Lf", 0.999999l);}
int f_L_prec9_limits_bigfpart_neg_bench(void){return printf("%.9Lf", -0.999999l);}
//Long Doubles - Prec 9 Rounding
int f_L_rnd_prec9_rndd_pos_bench(void){return printf("%.9Lf", 23.375094499l);}
int f_L_rnd_prec9_rndd_neg_bench(void){return printf("%.9Lf", -985.765426499l);}
int f_L_rnd_prec9_rndu_pos_bench(void){return printf("%.9Lf", 0.0894255l);}
int f_L_rnd_prec9_rndu_neg_bench(void){return printf("%.9Lf", -56.2012685l);}
int f_L_rnd_prec9_rndu_multidigit_pos_bench(void){return printf("%.9Lf", 43.4399999l);}
int f_L_rnd_prec9_rndu_multidigit_neg_bench(void){return printf("%.9Lf", -5.0299999l);}
int f_L_rnd_prec9_rndd_multidigit_pos_bench(void){return printf("%.9Lf", 43.43999949l);}
int f_L_rnd_prec9_rndd_multidigit_neg_bench(void){return printf("%.9Lf", -5.02999949l);}
int f_L_rnd_prec9_rndd_wholnobump_pos_bench(void){return printf("%.9Lf", 1.99999949l);}
int f_L_rnd_prec9_rndd_wholnobump_neg_bench(void){return printf("%.9Lf", -0.99999949l);}
int f_L_rnd_prec9_rndu_bumpwhole_pos_bench(void){return printf("%.9Lf", 3.9999999l);}
//Long Doubles - Prec 10
int f_L_stress_prec10_1_bench(void){return printf("this %.10Lf float", 1.5l);}
int f_L_stress_prec10_fltonly_bench(void){return printf("%.10Lf", 7.5l);}
int f_L_stress_prec10_whole_bench(void){return printf("%.10Lf", 1.0l);}
int f_L_stress_prec10_negative_bench(void){return printf("%.10Lf", -3.85l);}
int f_L_stress_prec10_positive_3_10_bench(void){return printf("%.10Lf", 573.924l);}
int f_L_stress_prec10_negative_3_10_bench(void){return printf("%.10Lf", -958.125l);}
int f_L_stress_prec10_pos_bench(void){return printf("%.10Lf", 23.8341375094l);}
int f_L_stress_prec10_neg_bench(void){return printf("%.10Lf", -985.2459765426l);}
int f_L_stress_prec10_rndd_pos_bench(void){return printf("%.10Lf", 23.8341375094499l);}
int f_L_stress_prec10_rndd_neg_bench(void){return printf("%.10Lf", -985.2459765426499l);}
int f_L_stress_prec10_rndu_pos_bench(void){return printf("%.10Lf", 0.87650894255l);}
int f_L_stress_prec10_rndu_neg_bench(void){return printf("%.10Lf", -56.47852012685l);}
int f_L_stress_prec10_positive_smallfpart_bench(void){return printf("%.10Lf", 23.000000041l);}
int f_L_stress_prec10_positive_allsmall_bench(void){return printf("%.10Lf", 0.0000000039l);}
int f_L_stress_prec10_negative_smallfpart_bench(void){return printf("%.10Lf", -7.000000036l);}
int f_L_stress_prec10_negative_allsmall_bench(void){return printf("%.10Lf", -0.000000032l);}
int f_L_stress_prec10_limits_allsmall_pos_bench(void){return printf("%.10Lf", 0.0000000001l);}
int f_L_stress_prec10_limits_allsmall_neg_bench(void){return printf("%.10Lf", -0.0000000001l);}
int f_L_stress_prec10_limits_smallfpart_pos_bench(void){return printf("%.10Lf", 9873.0000000001l);}
int f_L_stress_prec10_limits_smallfpart_neg_bench(void){return printf("%.10Lf", -875.0000000001l);}
int f_L_stress_prec10_limits_allbig_pos_bench(void){return printf("%.10Lf", 999.9999999999l);}
int f_L_stress_prec10_limits_allbig_neg_bench(void){return printf("%.10Lf", -99.9999999999l);}
int f_L_stress_prec10_limits_bigfpart_pos_bench(void){return printf("%.10Lf", 0.9999999999l);}
int f_L_stress_prec10_limits_bigfpart_neg_bench(void){return printf("%.10Lf", -0.9999999999l);}
//Long Doubles - Prec 12
int f_L_stress_prec12_rndu_bench(void){return printf("%.12f",        1.025978542436587568678);}
int f_L_stress_prec12_rndd_bench(void){return printf("%.12f",        1.025978548534310421434);}
int f_L_stress_prec12_limits_tiny_bench(void){return printf("%.12f", 0.000000000001000000000);}
int f_L_stress_prec12_limits_big_bench(void){return printf("%.12f",  0.999999999999000000000);}
//Long Doubles - Prec 14
int f_L_stress_prec14_rndu_bench(void){return printf("%.14f",        1.025978542436587568678);}
int f_L_stress_prec14_rndd_bench(void){return printf("%.14f",        1.025978548534310421434);}
int f_L_stress_prec14_limits_tiny_bench(void){return printf("%.14f", 0.000000000000010000000);}
int f_L_stress_prec14_limits_big_bench(void){return printf("%.14f",  0.999999999999990000000);}
//Long Doubles - Prec 16
int f_L_stress_prec16_rndu_bench(void){return printf("%.16f",        1.025978542436587568678);}
int f_L_stress_prec16_rndd_bench(void){return printf("%.16f",        1.025978548534310421634);}
int f_L_stress_prec16_limits_tiny_bench(void){return printf("%.16f", 0.000000000000000100000);}
int f_L_stress_prec16_limits_big_bench(void){return printf("%.16f",  0.999999999999999900000);}
//Long Doubles - Prec 17
int f_L_stress_prec17_rndu_bench(void){return printf("%.17f",        1.025978542436587568678);}
int f_L_stress_prec17_rndd_bench(void){return printf("%.17f",        1.025978548534310421734);}
int f_L_stress_prec17_limits_tiny_bench(void){return printf("%.17f", 0.000000000000000010000);}
int f_L_stress_prec17_limits_big_bench(void){return printf("%.17f",  0.999999999999999990000);}
//Long Doubles - Prec 18
int f_L_stress_prec18_rndu_bench(void){return printf("%.18f",        1.025978542436587568678);}
int f_L_stress_prec18_rndd_bench(void){return printf("%.18f",        1.025978548534310421834);}
int f_L_stress_prec18_limits_tiny_bench(void){return printf("%.18f", 0.000000000000000001000);}
int f_L_stress_prec18_limits_big_bench(void){return printf("%.18f",  0.999999999999999999000);}
//Long Doubles - Prec 19
int f_L_stress_prec19_rndu_bench(void){return printf("%.19f",        1.025978542436587568678);}
int f_L_stress_prec19_rndd_bench(void){return printf("%.19f",        1.025978548534310421934);}
int f_L_stress_prec19_limits_tiny_bench(void){return printf("%.19f", 0.000000000000000000100);}
int f_L_stress_prec19_limits_big_bench(void){return printf("%.19f",  0.999999999999999999900);}
//Long Doubles - Prec 20
int f_L_stress_prec20_rndu_bench(void){return printf("%.20f",        1.025978542436587568678);}
int f_L_stress_prec20_rndd_bench(void){return printf("%.20f",        1.025978548534310422034);}
int f_L_stress_prec20_limits_tiny_bench(void){return printf("%.20f", 0.000000000000000000010);}
int f_L_stress_prec20_limits_big_bench(void){return printf("%.20f",  0.999999999999999999990);}
//Long Doubles of special values
int f_L_reserved_values_inf_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("%Lf", special);}
int f_L_reserved_values_ninf_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%Lf", special);}
int f_L_reserved_values_nan_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%Lf", special);}
int f_L_reserved_values_pzero_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%Lf", special);}
int f_L_reserved_values_nzero_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%Lf", special);}
int f_L_reserved_values_inf_6w_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("%6Lf", special);}
int f_L_reserved_values_ninf_6w_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%6Lf", special);}
int f_L_reserved_values_nan_6w_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%6Lf", special);}
int f_L_reserved_values_pzero_6w_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%6Lf", special);}
int f_L_reserved_values_nzero_6w_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%6Lf", special);}
int f_L_reserved_values_inf_6wlj_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("%-6Lf", special);}
int f_L_reserved_values_ninf_6wlj_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%-6Lf", special);}
int f_L_reserved_values_nan_6wlj_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%-6Lf", special);}
int f_L_reserved_values_pzero_6wlj_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%-6Lf", special);}
int f_L_reserved_values_nzero_6wlj_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%-6Lf", special);}
int f_L_reserved_values_inf_6was_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("%+6Lf", special);}
int f_L_reserved_values_ninf_6was_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%+6Lf", special);}
int f_L_reserved_values_nan_6was_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%+6Lf", special);}
int f_L_reserved_values_pzero_6was_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%+6Lf", special);}
int f_L_reserved_values_nzero_6was_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%+6Lf", special);}
int f_L_reserved_values_inf_10w_prec7_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("%10.7Lf", special);}
int f_L_reserved_values_ninf_10w_prec7_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%10.7Lf", special);}
int f_L_reserved_values_nan_10w_prec7_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%10.7Lf", special);}
int f_L_reserved_values_pzero_10w_prec7_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%10.7Lf", special);}
int f_L_reserved_values_nzero_10w_prec7_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%10.7Lf", special);}
int f_L_reserved_values_inf_sp_prec7_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("% .7Lf", special);}
int f_L_reserved_values_ninf_sp_prec7_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("% .7Lf", special);}
int f_L_reserved_values_nan_sp_prec7_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("% .7Lf", special);}
int f_L_reserved_values_pzero_sp_prec7_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("% .7Lf", special);}
int f_L_reserved_values_nzero_sp_prec7_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("% .7Lf", special);}
int f_L_reserved_values_inf_sp_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("% Lf", special);}
int f_L_reserved_values_ninf_sp_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("% Lf", special);}
int f_L_reserved_values_nan_sp_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("% Lf", special);}
int f_L_reserved_values_pzero_sp_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("% Lf", special);}
int f_L_reserved_values_nzero_sp_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("% Lf", special);}
int f_L_reserved_values_inf_6wzp_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return printf("%06Lf", special);}
int f_L_reserved_values_ninf_6wzp_bench(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%06Lf", special);}
int f_L_reserved_values_nan_6wzp_bench(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return printf("%06Lf", special);}
int f_L_reserved_values_pzero_6wzp_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%06Lf", special);}
int f_L_reserved_values_nzero_6wzp_bench(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return printf("%06Lf", special);}
///Long double Floats whose precision exceeds their compiled literal precision
int f_L_overprec_might_be_undefbehav_100_bench(void){return printf("%.100Lf", 0.237l);}
int f_L_overprec_might_be_undefbehav_32_bench(void){return printf("%.32Lf", 0.237l);}
int f_L_overprec_might_be_undefbehav_4_bench(void){return printf("%.4Lf", 0.237l);}
int f_L_overprec_might_be_undefbehav_1000_bench(void){return printf("%.4Lf", -0.106577568068517810765107851705167l);}
int f_L_overprec_might_be_undefbehav_10_from_0_bench(void){return printf("%.10Lf", 0.0l);}
int f_L_overprec_might_be_undefbehav_2000_bench(void){return printf("%.2000Lf", 623.28376510723481l);}
int f_L_overprec_might_be_undefbehav_dblmin_bench(void){return printf("%.2000Lf", LDBL_MIN);}
int f_L_overprec_might_be_undefbehav_ndblmin_bench(void){return printf("%.2000Lf", -LDBL_MIN);}
//Long double floats at double max, double min
int f_L_limits_dblmax_prec0_notmandatory_bench(void){return printf("%.0Lf", LDBL_MAX);}
int f_L_limits_dblmax_prec3_notmandatory_bench(void){return printf("%.3Lf", LDBL_MAX);}
int f_L_limits_dblmax_precd_notmandatory_bench(void){return printf("%Lf", LDBL_MAX);}
int f_L_limits_dblmax_prec8_notmandatory_bench(void){return printf("%.8Lf", LDBL_MAX);}
int f_L_stress_limits_dblmax_prec12_notmandatory_bench(void){return printf("%.12Lf", LDBL_MAX);}
int f_L_stress_limits_dblmax_prec16_notmandatory_bench(void){return printf("%.16Lf", LDBL_MAX);}
int f_L_stress_limits_dblmax_prec18_notmandatory_bench(void){return printf("%.18Lf", LDBL_MAX);}
int f_L_limits_ndblmax_prec0_notmandatory_bench(void){return printf("%.0Lf", -LDBL_MAX);}
int f_L_limits_ndblmax_prec3_notmandatory_bench(void){return printf("%.3Lf", -LDBL_MAX);}
int f_L_limits_ndblmax_precd_notmandatory_bench(void){return printf("%Lf", -LDBL_MAX);}
int f_L_limits_ndblmax_prec8_notmandatory_bench(void){return printf("%.8Lf", -LDBL_MAX);}
int f_L_stress_limits_ndblmax_prec12_notmandatory_bench(void){return printf("%.12Lf", -LDBL_MAX);}
int f_L_stress_limits_ndblmax_prec16_notmandatory_bench(void){return printf("%.16Lf", -LDBL_MAX);}
int f_L_stress_limits_ndblmax_prec18_notmandatory_bench(void){return printf("%.18Lf", -LDBL_MAX);}
int f_L_limits_dblmin_prec0_bench(void){return printf("%.0Lf", LDBL_MIN);}
int f_L_limits_dblmin_prec3_bench(void){return printf("%.3Lf", LDBL_MIN);}
int f_L_limits_dblmin_precd_bench(void){return printf("%Lf", LDBL_MIN);}
int f_L_limits_dblmin_prec8_bench(void){return printf("%.8Lf", LDBL_MIN);}
int f_L_stress_limits_dblmin_prec12_bench(void){return printf("%.12Lf", LDBL_MIN);}
int f_L_stress_limits_dblmin_prec16_bench(void){return printf("%.16Lf", LDBL_MIN);}
int f_L_stress_limits_dblmin_prec18_bench(void){return printf("%.18Lf", LDBL_MIN);}
int f_L_limits_ndblmin_prec0_bench(void){return printf("%.0Lf", -LDBL_MIN);}
int f_L_limits_ndblmin_prec3_bench(void){return printf("%.3Lf", -LDBL_MIN);}
int f_L_limits_ndblmin_precd_bench(void){return printf("%Lf", -LDBL_MIN);}
int f_L_limits_ndblmin_prec8_bench(void){return printf("%.8Lf", -LDBL_MIN);}
int f_L_stress_limits_ndblmin_prec12_bench(void){return printf("%.12Lf", -LDBL_MIN);}
int f_L_stress_limits_ndblmin_prec16_bench(void){return printf("%.16Lf", -LDBL_MIN);}
int f_L_stress_limits_ndblmin_prec18_bench(void){return printf("%.18Lf", -LDBL_MIN);}

//Arbitrary argument numbers
int		argnum_simple_swap_bench(void){return printf("%2$s, %1$s!", "world", "hello");} //CAN-SEGFAULT
int		argnum_swap_around_pct_bench(void){return printf("%2$s %% %1$s!", "world", "hello");} //CAN-SEGFAULT
int		argnum_swap_strfloat_bench(void){return printf("%2$f, %1$s!", "world", 5.75);} //CAN-SEGFAULT
int		argnum_swap_floatstr_bench(void){return printf("%2$s, %1$f!", 5.75, "abc");} //CAN-SEGFAULT
int		argnum_swap_ldblstr_bench(void){return printf("%2$s, %1$Lf!", 5.75L, "abc");} //CAN-SEGFAULT
int		argnum_swap_strldbl_bench(void){return printf("%2$Lf, %1$s!", "world", 5.75L);} //CAN-SEGFAULT
int		argnum_swap_ldblchar_bench(void){return printf("%2$c, %1$Lf!", 5.75L, 'c');} //CAN-SEGFAULT
int		argnum_swap_charldbl_bench(void){return printf("%2$Lf, %1$c!", 'c', 5.75L);} //CAN-SEGFAULT
int		argnum_swap_floatstr_around_pct_bench(void){return printf("%2$s %% %1$f!", 5.75, "abc");} //CAN-SEGFAULT
int		argnum_swap_strfloat_around_pct_bench(void){return printf("%2$f %% %1$s!", "world", 5.75);} //CAN-SEGFAULT
int		argnum_loopback_throwswarning_bench(void){return printf("%i %i %1$i %i %i", 1, 2, 3);} //CAN-SEGFAULT
int		argnum_onlyone_bench(void){return printf("%1$s %1$s %1$s %1$s %1$s %1$s %1$s %1$s.", "buffalo");} //CAN-SEGFAULT
int		argnum_start2thentofloatthen1_throwswarning_bench(void){return printf("%2$s %f %1$i", 5, "abc", 5.75f);} //CAN-SEGFAULT
int		argnum_ultimate_1_throwswarning_bench(void){return printf("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);} //CAN-SEGFAULT
int		argnum_ultimate_2_throwswarning_bench(void){return printf("%4$.5s %.4i %lli %1$Lf %c %7$20.6s %5$i %2$c %1$.2Lf %c %i", //CAN-SEGFAULT
			5.75l, 'c', -17, "Atlanta, GA", 54, 9879879879879ll, "baby shark");}
int		argnum_ultimate_2_with_pct_throwswarning_bench(void){return printf("%% %4$.5s %.4i %lli %% %1$Lf %c %7$20.6s %5$i %% %2$c %1$.2Lf %c %i", //CAN-SEGFAULT
			5.75l, 'c', -17, "Atlanta, GA", 54, 9879879879879ll, "baby shark");}

//Mix tests










int		mix_test_0_bench(void){return printf(
			"  %o    %u    %li    %s    %X    %lli  ",
			mx_u, mx_u, mx_li, mx_s, mx_u, mx_lli);}
int		mix_test_1_bench(void){return printf(
			"  %li    %u    %s    %X    %x    %Lf  ",
			mx_li, mx_u, mx_s, mx_u, mx_u, mx_Lf);}
int		mix_test_2_bench(void){return printf(
			"  %Lf    %p    %i    %li    %lli    %s  ",
			mx_Lf, &mx_i, mx_i, mx_li, mx_lli, mx_s);}
int		mix_test_3_bench(void){return printf(
			"  %x    %s    %i    %p    %X    %Lf  ",
			mx_u, mx_s, mx_i, &mx_i, mx_u, mx_Lf);}
int		mix_test_4_bench(void){return printf(
			"  %li    %hhi    %p    %o    %%    %Lf  ",
			mx_li, mx_c, &mx_i, mx_u, mx_Lf);}
int		mix_test_5_bench(void){return printf(
			"  %hi    %u    %x    %s    %i    %X  ",
			mx_hi, mx_u, mx_u, mx_s, mx_i, mx_u);}
int		mix_test_6_bench(void){return printf(
			"  %f    %li    %i    %p    %u    %hi  ",
			mx_f, mx_li, mx_i, &mx_i, mx_u, mx_hi);}
int		mix_test_7_bench(void){return printf(
			"  %u    %hhi    %p    %li    %Lf    %X  ",
			mx_u, mx_c, &mx_i, mx_li, mx_Lf, mx_u);}
int		mix_test_8_bench(void){return printf(
			"  %o    %Lf    %u    %li    %lli    %x  ",
			mx_u, mx_Lf, mx_u, mx_li, mx_lli, mx_u);}
int		mix_test_9_bench(void){return printf(
			"  %Lf    %li    %s    %p    %x    %o  ",
			mx_Lf, mx_li, mx_s, &mx_i, mx_u, mx_u);}
int		mix_test_10_bench(void){return printf(
			"  %hhi    %x    %s    %u    %i    %li  ",
			mx_c, mx_u, mx_s, mx_u, mx_i, mx_li);}
int		mix_test_11_bench(void){return printf(
			"  %X    %li    %o    %s    %f    %u  ",
			mx_u, mx_li, mx_u, mx_s, mx_f, mx_u);}
int		mix_test_12_bench(void){return printf(
			"  %o    %x    %i    %c    %hi    %Lf  ",
			mx_u, mx_u, mx_i, mx_c, mx_hi, mx_Lf);}
int		mix_test_13_bench(void){return printf(
			"  %c    %i    %hi    %o    %x    %u  ",
			mx_c, mx_i, mx_hi, mx_u, mx_u, mx_u);}
int		mix_test_14_bench(void){return printf(
			"  %i    %f    %li    %Lf    %X    %hhi  ",
			mx_i, mx_f, mx_li, mx_Lf, mx_u, mx_c);}
int		mix_test_15_bench(void){return printf(
			"  %s    %u    %lli    %Lf    %f    %o  ",
			mx_s, mx_u, mx_lli, mx_Lf, mx_f, mx_u);}
int		mix_test_16_bench(void){return printf(
			"  %hhi    %X    %u    %p    %x    %o  ",
			mx_c, mx_u, mx_u, &mx_i, mx_u, mx_u);}
int		mix_test_17_bench(void){return printf(
			"  %X    %i    %c    %lli    %o    %p  ",
			mx_u, mx_i, mx_c, mx_lli, mx_u, &mx_i);}
int		mix_test_18_bench(void){return printf(
			"  %X    %c    %x    %i    %hi    %s  ",
			mx_u, mx_c, mx_u, mx_i, mx_hi, mx_s);}
int		mix_test_19_bench(void){return printf(
			"  %hhi    %li    %x    %hi    %lli    %s  ",
			mx_c, mx_li, mx_u, mx_hi, mx_lli, mx_s);}
int		mix_test_20_bench(void){return printf(
			"  %Lf    %p    %lli    %hhi    %c    %f  ",
			mx_Lf, &mx_i, mx_lli, mx_c, mx_c, mx_f);}
int		mix_test_21_bench(void){return printf(
			"  %hi    %s    %hhi    %p    %lli    %u  ",
			mx_hi, mx_s, mx_c, &mx_i, mx_lli, mx_u);}
int		mix_test_22_bench(void){return printf(
			"  %p    %lli    %s    %X    %u    %hhi  ",
			&mx_i, mx_lli, mx_s, mx_u, mx_u, mx_c);}
int		mix_test_23_bench(void){return printf(
			"  %hhi    %f    %x    %o    %i    %X  ",
			mx_c, mx_f, mx_u, mx_u, mx_i, mx_u);}
int		mix_test_24_bench(void){return printf(
			"  %lli    %hhi    %hi    %i    %c    %o  ",
			mx_lli, mx_c, mx_hi, mx_i, mx_c, mx_u);}
int		mix_test_25_bench(void){return printf(
			"  %s    %Lf    %p    %c    %X    %x  ",
			mx_s, mx_Lf, &mx_i, mx_c, mx_u, mx_u);}
int		mix_test_26_bench(void){return printf(
			"  %lli    %i    %u    %p    %o    %c  ",
			mx_lli, mx_i, mx_u, &mx_i, mx_u, mx_c);}
int		mix_test_27_bench(void){return printf(
			"  %i    %p    %hhi    %X    %Lf    %lli  ",
			mx_i, &mx_i, mx_c, mx_u, mx_Lf, mx_lli);}
int		mix_test_28_bench(void){return printf(
			"  %f    %i    %p    %li    %o    %x  ",
			mx_f, mx_i, &mx_i, mx_li, mx_u, mx_u);}
int		mix_test_29_bench(void){return printf(
			"  %li    %lli    %f    %X    %o    %s  ",
			mx_li, mx_lli, mx_f, mx_u, mx_u, mx_s);}
int		mix_test_30_bench(void){return printf(
			"  %f    %hi    %p    %hhi    %li    %u  ",
			mx_f, mx_hi, &mx_i, mx_c, mx_li, mx_u);}
int		mix_test_31_bench(void){return printf(
			"  %s    %x    %u    %li    %o    %hi  ",
			mx_s, mx_u, mx_u, mx_li, mx_u, mx_hi);}
int		mix_test_32_bench(void){return printf(
			"  %u    %lli    %X    %i    %o    %f  ",
			mx_u, mx_lli, mx_u, mx_i, mx_u, mx_f);}
int		mix_test_33_bench(void){return printf(
			"  %o    %X    %u    %c    %lli    %hi  ",
			mx_u, mx_u, mx_u, mx_c, mx_lli, mx_hi);}
int		mix_test_34_bench(void){return printf(
			"  %hi    %X    %Lf    %s    %o    %x  ",
			mx_hi, mx_u, mx_Lf, mx_s, mx_u, mx_u);}
int		mix_test_35_bench(void){return printf(
			"  %X    %p    %o    %hi    %s    %lli  ",
			mx_u, &mx_i, mx_u, mx_hi, mx_s, mx_lli);}
int		mix_test_36_bench(void){return printf(
			"  %li    %p    %f    %Lf    %x    %lli  ",
			mx_li, &mx_i, mx_f, mx_Lf, mx_u, mx_lli);}
int		mix_test_37_bench(void){return printf(
			"  %i    %li    %X    %p    %hi    %o  ",
			mx_i, mx_li, mx_u, &mx_i, mx_hi, mx_u);}
int		mix_test_38_bench(void){return printf(
			"  %f    %u    %p    %hi    %hhi    %s  ",
			mx_f, mx_u, &mx_i, mx_hi, mx_c, mx_s);}
int		mix_test_39_bench(void){return printf(
			"  %o    %c    %li    %p    %hi    %f  ",
			mx_u, mx_c, mx_li, &mx_i, mx_hi, mx_f);}
int		mix_test_40_bench(void){return printf(
			"  %u    %X    %f    %hhi    %s    %o  ",
			mx_u, mx_u, mx_f, mx_c, mx_s, mx_u);}
int		mix_test_41_bench(void){return printf(
			"  %li    %x    %hhi    %X    %s    %lli  ",
			mx_li, mx_u, mx_c, mx_u, mx_s, mx_lli);}
int		mix_test_42_bench(void){return printf(
			"  %hi    %x    %i    %c    %hhi    %li  ",
			mx_hi, mx_u, mx_i, mx_c, mx_c, mx_li);}
int		mix_test_43_bench(void){return printf(
			"  %x    %X    %o    %s    %lli    %hhi  ",
			mx_u, mx_u, mx_u, mx_s, mx_lli, mx_c);}
int		mix_test_44_bench(void){return printf(
			"  %f    %x    %o    %hi    %li    %u  ",
			mx_f, mx_u, mx_u, mx_hi, mx_li, mx_u);}
int		mix_test_45_bench(void){return printf(
			"  %f    %hhi    %c    %X    %lli    %s  ",
			mx_f, mx_c, mx_c, mx_u, mx_lli, mx_s);}
int		mix_test_46_bench(void){return printf(
			"  %lli    %i    %hhi    %hi    %li    %Lf  ",
			mx_lli, mx_i, mx_c, mx_hi, mx_li, mx_Lf);}
int		mix_test_47_bench(void){return printf(
			"  %f    %c    %lli    %s    %hhi    %p  ",
			mx_f, mx_c, mx_lli, mx_s, mx_c, &mx_i);}
int		mix_test_48_bench(void){return printf(
			"  %f    %hhi    %li    %lli    %x    %p  ",
			mx_f, mx_c, mx_li, mx_lli, mx_u, &mx_i);}
int		mix_test_49_bench(void){return printf(
			"  %o    %lli    %hi    %f    %X    %hhi  ",
			mx_u, mx_lli, mx_hi, mx_f, mx_u, mx_c);}
int		mix_test_50_bench(void){return printf(
			"  %o    %u    %f    %i    %x    %hhi  ",
			mx_u, mx_u, mx_f, mx_i, mx_u, mx_c);}
int		mix_test_51_bench(void){return printf(
			"  %x    %u    %Lf    %hi    %o    %X  ",
			mx_u, mx_u, mx_Lf, mx_hi, mx_u, mx_u);}
int		mix_test_52_bench(void){return printf(
			"  %u    %Lf    %hi    %li    %X    %hhi  ",
			mx_u, mx_Lf, mx_hi, mx_li, mx_u, mx_c);}
int		mix_test_53_bench(void){return printf(
			"  %o    %c    %Lf    %hi    %s    %p  ",
			mx_u, mx_c, mx_Lf, mx_hi, mx_s, &mx_i);}
int		mix_test_54_bench(void){return printf(
			"  %s    %hhi    %X    %lli    %x    %u  ",
			mx_s, mx_c, mx_u, mx_lli, mx_u, mx_u);}
int		mix_test_55_bench(void){return printf(
			"  %x    %X    %o    %lli    %c    %u  ",
			mx_u, mx_u, mx_u, mx_lli, mx_c, mx_u);}
int		mix_test_56_bench(void){return printf(
			"  %hi    %u    %i    %x    %c    %s  ",
			mx_hi, mx_u, mx_i, mx_u, mx_c, mx_s);}
int		mix_test_57_bench(void){return printf(
			"  %hi    %s    %i    %X    %u    %li  ",
			mx_hi, mx_s, mx_i, mx_u, mx_u, mx_li);}
int		mix_test_58_bench(void){return printf(
			"  %c    %X    %li    %hi    %Lf    %p  ",
			mx_c, mx_u, mx_li, mx_hi, mx_Lf, &mx_i);}
int		mix_test_59_bench(void){return printf(
			"  %Lf    %hi    %c    %u    %hhi    %li  ",
			mx_Lf, mx_hi, mx_c, mx_u, mx_c, mx_li);}
int		mix_test_60_bench(void){return printf(
			"  %li    %p    %s    %hi    %u    %lli  ",
			mx_li, &mx_i, mx_s, mx_hi, mx_u, mx_lli);}
int		mix_test_61_bench(void){return printf(
			"  %li    %X    %Lf    %s    %c    %lli  ",
			mx_li, mx_u, mx_Lf, mx_s, mx_c, mx_lli);}
int		mix_test_62_bench(void){return printf(
			"  %lli    %hhi    %f    %o    %s    %X  ",
			mx_lli, mx_c, mx_f, mx_u, mx_s, mx_u);}
int		mix_test_63_bench(void){return printf(
			"  %x    %X    %u    %s    %li    %f  ",
			mx_u, mx_u, mx_u, mx_s, mx_li, mx_f);}
int		mix_test_64_bench(void){return printf(
			"  %hhi    %X    %u    %o    %Lf    %s  ",
			mx_c, mx_u, mx_u, mx_u, mx_Lf, mx_s);}
int		mix_test_65_bench(void){return printf(
			"  %li    %u    %x    %o    %lli    %s  ",
			mx_li, mx_u, mx_u, mx_u, mx_lli, mx_s);}
int		mix_test_66_bench(void){return printf(
			"  %hi    %f    %hhi    %u    %i    %p  ",
			mx_hi, mx_f, mx_c, mx_u, mx_i, &mx_i);}
int		mix_test_67_bench(void){return printf(
			"  %i    %c    %f    %hi    %s    %o  ",
			mx_i, mx_c, mx_f, mx_hi, mx_s, mx_u);}
int		mix_test_68_bench(void){return printf(
			"  %li    %s    %p    %f    %Lf    %X  ",
			mx_li, mx_s, &mx_i, mx_f, mx_Lf, mx_u);}
int		mix_test_69_bench(void){return printf(
			"  %s    %p    %Lf    %lli    %x    %o  ",
			mx_s, &mx_i, mx_Lf, mx_lli, mx_u, mx_u);}
int		mix_test_70_bench(void){return printf(
			"  %hhi    %hi    %Lf    %c    %x    %lli  ",
			mx_c, mx_hi, mx_Lf, mx_c, mx_u, mx_lli);}
int		mix_test_71_bench(void){return printf(
			"  %p    %u    %lli    %c    %Lf    %X  ",
			&mx_i, mx_u, mx_lli, mx_c, mx_Lf, mx_u);}
int		mix_test_72_bench(void){return printf(
			"  %X    %p    %f    %c    %o    %li  ",
			mx_u, &mx_i, mx_f, mx_c, mx_u, mx_li);}
int		mix_test_73_bench(void){return printf(
			"  %p    %c    %li    %lli    %x    %f  ",
			&mx_i, mx_c, mx_li, mx_lli, mx_u, mx_f);}
int		mix_test_74_bench(void){return printf(
			"  %u    %c    %li    %p    %o    %s  ",
			mx_u, mx_c, mx_li, &mx_i, mx_u, mx_s);}
int		mix_test_75_bench(void){return printf(
			"  %hhi    %lli    %s    %li    %hi    %c  ",
			mx_c, mx_lli, mx_s, mx_li, mx_hi, mx_c);}
int		mix_test_76_bench(void){return printf(
			"  %u    %x    %lli    %hi    %i    %hhi  ",
			mx_u, mx_u, mx_lli, mx_hi, mx_i, mx_c);}
int		mix_test_77_bench(void){return printf(
			"  %li    %hi    %Lf    %c    %o    %lli  ",
			mx_li, mx_hi, mx_Lf, mx_c, mx_u, mx_lli);}
int		mix_test_78_bench(void){return printf(
			"  %u    %i    %c    %p    %o    %f  ",
			mx_u, mx_i, mx_c, &mx_i, mx_u, mx_f);}
int		mix_test_79_bench(void){return printf(
			"  %Lf    %X    %p    %hhi    %c    %s  ",
			mx_Lf, mx_u, &mx_i, mx_c, mx_c, mx_s);}
int		mix_test_80_bench(void){return printf(
			"  %c    %hi    %u    %i    %f    %X  ",
			mx_c, mx_hi, mx_u, mx_i, mx_f, mx_u);}
int		mix_test_81_bench(void){return printf(
			"  %s    %p    %u    %Lf    %hhi    %li  ",
			mx_s, &mx_i, mx_u, mx_Lf, mx_c, mx_li);}
int		mix_test_82_bench(void){return printf(
			"  %X    %x    %i    %c    %Lf    %li  ",
			mx_u, mx_u, mx_i, mx_c, mx_Lf, mx_li);}
int		mix_test_83_bench(void){return printf(
			"  %X    %hi    %x    %u    %c    %o  ",
			mx_u, mx_hi, mx_u, mx_u, mx_c, mx_u);}
int		mix_test_84_bench(void){return printf(
			"  %hi    %Lf    %hhi    %li    %s    %lli  ",
			mx_hi, mx_Lf, mx_c, mx_li, mx_s, mx_lli);}
int		mix_test_85_bench(void){return printf(
			"  %Lf    %o    %f    %u    %X    %li  ",
			mx_Lf, mx_u, mx_f, mx_u, mx_u, mx_li);}
int		mix_test_86_bench(void){return printf(
			"  %f    %i    %lli    %hi    %u    %o  ",
			mx_f, mx_i, mx_lli, mx_hi, mx_u, mx_u);}
int		mix_test_87_bench(void){return printf(
			"  %i    %x    %lli    %c    %hi    %f  ",
			mx_i, mx_u, mx_lli, mx_c, mx_hi, mx_f);}
int		mix_test_88_bench(void){return printf(
			"  %u    %c    %x    %f    %p    %X  ",
			mx_u, mx_c, mx_u, mx_f, &mx_i, mx_u);}
int		mix_test_89_bench(void){return printf(
			"  %li    %c    %o    %f    %u    %lli  ",
			mx_li, mx_c, mx_u, mx_f, mx_u, mx_lli);}
int		mix_test_90_bench(void){return printf(
			"  %Lf    %o    %f    %li    %p    %s  ",
			mx_Lf, mx_u, mx_f, mx_li, &mx_i, mx_s);}
int		mix_test_91_bench(void){return printf(
			"  %X    %c    %p    %s    %i    %f  ",
			mx_u, mx_c, &mx_i, mx_s, mx_i, mx_f);}
int		mix_test_92_bench(void){return printf(
			"  %c    %hhi    %o    %X    %s    %lli  ",
			mx_c, mx_c, mx_u, mx_u, mx_s, mx_lli);}
int		mix_test_93_bench(void){return printf(
			"  %Lf    %hi    %c    %hhi    %s    %f  ",
			mx_Lf, mx_hi, mx_c, mx_c, mx_s, mx_f);}
int		mix_test_94_bench(void){return printf(
			"  %c    %u    %x    %lli    %hi    %s  ",
			mx_c, mx_u, mx_u, mx_lli, mx_hi, mx_s);}
int		mix_test_95_bench(void){return printf(
			"  %f    %u    %c    %x    %lli    %li  ",
			mx_f, mx_u, mx_c, mx_u, mx_lli, mx_li);}
int		mix_test_96_bench(void){return printf(
			"  %f    %hi    %li    %c    %x    %X  ",
			mx_f, mx_hi, mx_li, mx_c, mx_u, mx_u);}
int		mix_test_97_bench(void){return printf(
			"  %u    %Lf    %i    %f    %hhi    %hi  ",
			mx_u, mx_Lf, mx_i, mx_f, mx_c, mx_hi);}
int		mix_test_98_bench(void){return printf(
			"  %Lf    %s    %hi    %i    %f    %x  ",
			mx_Lf, mx_s, mx_hi, mx_i, mx_f, mx_u);}
int		mix_test_99_bench(void){return printf(
			"  %u    %f    %X    %c    %lli    %p  ",
			mx_u, mx_f, mx_u, mx_c, mx_lli, &mx_i);}
int		mix_test_100_bench(void){return printf(
			"  %X    %li    %f    %s    %hhi    %x  ",
			mx_u, mx_li, mx_f, mx_s, mx_c, mx_u);}
int		mix_test_101_bench(void){return printf(
			"  %o    %p    %s    %f    %X    %x  ",
			mx_u, &mx_i, mx_s, mx_f, mx_u, mx_u);}
int		mix_test_102_bench(void){return printf(
			"  %hhi    %c    %f    %x    %hi    %li  ",
			mx_c, mx_c, mx_f, mx_u, mx_hi, mx_li);}
int		mix_test_103_bench(void){return printf(
			"  %p    %Lf    %x    %X    %f    %s  ",
			&mx_i, mx_Lf, mx_u, mx_u, mx_f, mx_s);}
int		mix_test_104_bench(void){return printf(
			"  %s    %x    %lli    %i    %o    %p  ",
			mx_s, mx_u, mx_lli, mx_i, mx_u, &mx_i);}
int		mix_test_105_bench(void){return printf(
			"  %X    %s    %Lf    %p    %lli    %x  ",
			mx_u, mx_s, mx_Lf, &mx_i, mx_lli, mx_u);}
int		mix_test_106_bench(void){return printf(
			"  %c    %hhi    %hi    %x    %u    %li  ",
			mx_c, mx_c, mx_hi, mx_u, mx_u, mx_li);}
int		mix_test_107_bench(void){return printf(
			"  %li    %X    %s    %Lf    %f    %hhi  ",
			mx_li, mx_u, mx_s, mx_Lf, mx_f, mx_c);}
int		mix_test_108_bench(void){return printf(
			"  %u    %hhi    %s    %c    %p    %f  ",
			mx_u, mx_c, mx_s, mx_c, &mx_i, mx_f);}
int		mix_test_109_bench(void){return printf(
			"  %Lf    %s    %u    %f    %i    %X  ",
			mx_Lf, mx_s, mx_u, mx_f, mx_i, mx_u);}
int		mix_test_110_bench(void){return printf(
			"  %i    %p    %hi    %c    %f    %s  ",
			mx_i, &mx_i, mx_hi, mx_c, mx_f, mx_s);}
int		mix_test_111_bench(void){return printf(
			"  %p    %X    %lli    %hi    %Lf    %f  ",
			&mx_i, mx_u, mx_lli, mx_hi, mx_Lf, mx_f);}
int		mix_test_112_bench(void){return printf(
			"  %u    %c    %Lf    %lli    %o    %hhi  ",
			mx_u, mx_c, mx_Lf, mx_lli, mx_u, mx_c);}
int		mix_test_113_bench(void){return printf(
			"  %X    %i    %x    %c    %p    %s  ",
			mx_u, mx_i, mx_u, mx_c, &mx_i, mx_s);}
int		mix_test_114_bench(void){return printf(
			"  %x    %p    %f    %u    %hi    %o  ",
			mx_u, &mx_i, mx_f, mx_u, mx_hi, mx_u);}
int		mix_test_115_bench(void){return printf(
			"  %X    %hhi    %lli    %p    %li    %hi  ",
			mx_u, mx_c, mx_lli, &mx_i, mx_li, mx_hi);}
int		mix_test_116_bench(void){return printf(
			"  %lli    %c    %li    %o    %Lf    %x  ",
			mx_lli, mx_c, mx_li, mx_u, mx_Lf, mx_u);}
int		mix_test_117_bench(void){return printf(
			"  %lli    %s    %i    %Lf    %hhi    %x  ",
			mx_lli, mx_s, mx_i, mx_Lf, mx_c, mx_u);}
int		mix_test_118_bench(void){return printf(
			"  %o    %f    %Lf    %x    %p    %hhi  ",
			mx_u, mx_f, mx_Lf, mx_u, &mx_i, mx_c);}
int		mix_test_119_bench(void){return printf(
			"  %hhi    %p    %i    %hi    %o    %c  ",
			mx_c, &mx_i, mx_i, mx_hi, mx_u, mx_c);}
int		mix_test_120_bench(void){return printf(
			"  %X    %lli    %o    %li    %x    %p  ",
			mx_u, mx_lli, mx_u, mx_li, mx_u, &mx_i);}
int		mix_test_121_bench(void){return printf(
			"  %X    %s    %hi    %li    %c    %x  ",
			mx_u, mx_s, mx_hi, mx_li, mx_c, mx_u);}
int		mix_test_122_bench(void){return printf(
			"  %lli    %s    %f    %i    %Lf    %u  ",
			mx_lli, mx_s, mx_f, mx_i, mx_Lf, mx_u);}
int		mix_test_123_bench(void){return printf(
			"  %f    %lli    %x    %Lf    %o    %p  ",
			mx_f, mx_lli, mx_u, mx_Lf, mx_u, &mx_i);}
int		mix_test_124_bench(void){return printf(
			"  %hhi    %u    %lli    %x    %hi    %Lf  ",
			mx_c, mx_u, mx_lli, mx_u, mx_hi, mx_Lf);}
int		mix_test_125_bench(void){return printf(
			"  %c    %x    %hhi    %i    %Lf    %p  ",
			mx_c, mx_u, mx_c, mx_i, mx_Lf, &mx_i);}
int		mix_test_126_bench(void){return printf(
			"  %c    %Lf    %X    %x    %u    %i  ",
			mx_c, mx_Lf, mx_u, mx_u, mx_u, mx_i);}
int		mix_test_127_bench(void){return printf(
			"  %i    %p    %f    %o    %li    %Lf  ",
			mx_i, &mx_i, mx_f, mx_u, mx_li, mx_Lf);}
int		mix_test_128_bench(void){return printf(
			"  %hi    %o    %i    %Lf    %lli    %p  ",
			mx_hi, mx_u, mx_i, mx_Lf, mx_lli, &mx_i);}
int		mix_test_129_bench(void){return printf(
			"  %u    %c    %s    %lli    %X    %x  ",
			mx_u, mx_c, mx_s, mx_lli, mx_u, mx_u);}
int		mix_test_130_bench(void){return printf(
			"  %li    %f    %p    %hhi    %i    %u  ",
			mx_li, mx_f, &mx_i, mx_c, mx_i, mx_u);}
int		mix_test_131_bench(void){return printf(
			"  %u    %c    %p    %o    %hhi    %f  ",
			mx_u, mx_c, &mx_i, mx_u, mx_c, mx_f);}
int		mix_test_132_bench(void){return printf(
			"  %u    %Lf    %lli    %i    %f    %hi  ",
			mx_u, mx_Lf, mx_lli, mx_i, mx_f, mx_hi);}
int		mix_test_133_bench(void){return printf(
			"  %x    %s    %i    %hhi    %Lf    %li  ",
			mx_u, mx_s, mx_i, mx_c, mx_Lf, mx_li);}
int		mix_test_134_bench(void){return printf(
			"  %f    %p    %o    %hi    %x    %li  ",
			mx_f, &mx_i, mx_u, mx_hi, mx_u, mx_li);}
int		mix_test_135_bench(void){return printf(
			"  %p    %X    %s    %li    %u    %c  ",
			&mx_i, mx_u, mx_s, mx_li, mx_u, mx_c);}
int		mix_test_136_bench(void){return printf(
			"  %hhi    %o    %X    %p    %s    %li  ",
			mx_c, mx_u, mx_u, &mx_i, mx_s, mx_li);}
int		mix_test_137_bench(void){return printf(
			"  %p    %hhi    %i    %x    %X    %f  ",
			&mx_i, mx_c, mx_i, mx_u, mx_u, mx_f);}
int		mix_test_138_bench(void){return printf(
			"  %s    %li    %i    %x    %p    %o  ",
			mx_s, mx_li, mx_i, mx_u, &mx_i, mx_u);}
int		mix_test_139_bench(void){return printf(
			"  %i    %X    %lli    %u    %s    %hhi  ",
			mx_i, mx_u, mx_lli, mx_u, mx_s, mx_c);}
int		mix_test_140_bench(void){return printf(
			"  %p    %c    %x    %hi    %lli    %u  ",
			&mx_i, mx_c, mx_u, mx_hi, mx_lli, mx_u);}
int		mix_test_141_bench(void){return printf(
			"  %lli    %li    %x    %Lf    %s    %u  ",
			mx_lli, mx_li, mx_u, mx_Lf, mx_s, mx_u);}
int		mix_test_142_bench(void){return printf(
			"  %hhi    %o    %hi    %c    %s    %li  ",
			mx_c, mx_u, mx_hi, mx_c, mx_s, mx_li);}
int		mix_test_143_bench(void){return printf(
			"  %p    %hhi    %lli    %s    %c    %u  ",
			&mx_i, mx_c, mx_lli, mx_s, mx_c, mx_u);}
int		mix_test_144_bench(void){return printf(
			"  %x    %p    %i    %Lf    %u    %s  ",
			mx_u, &mx_i, mx_i, mx_Lf, mx_u, mx_s);}
int		mix_test_145_bench(void){return printf(
			"  %li    %hhi    %u    %i    %X    %o  ",
			mx_li, mx_c, mx_u, mx_i, mx_u, mx_u);}
int		mix_test_146_bench(void){return printf(
			"  %u    %c    %p    %hhi    %X    %f  ",
			mx_u, mx_c, &mx_i, mx_c, mx_u, mx_f);}
int		mix_test_147_bench(void){return printf(
			"  %hhi    %li    %p    %s    %Lf    %o  ",
			mx_c, mx_li, &mx_i, mx_s, mx_Lf, mx_u);}
int		mix_test_148_bench(void){return printf(
			"  %lli    %s    %X    %i    %hi    %c  ",
			mx_lli, mx_s, mx_u, mx_i, mx_hi, mx_c);}
int		mix_test_149_bench(void){return printf(
			"  %c    %p    %li    %X    %s    %lli  ",
			mx_c, &mx_i, mx_li, mx_u, mx_s, mx_lli);}
int		mix_test_150_bench(void){return printf(
			"  %X    %lli    %c    %i    %f    %u  ",
			mx_u, mx_lli, mx_c, mx_i, mx_f, mx_u);}
int		mix_test_151_bench(void){return printf(
			"  %Lf    %c    %hhi    %u    %hi    %x  ",
			mx_Lf, mx_c, mx_c, mx_u, mx_hi, mx_u);}
int		mix_test_152_bench(void){return printf(
			"  %li    %hi    %o    %s    %lli    %hhi  ",
			mx_li, mx_hi, mx_u, mx_s, mx_lli, mx_c);}
int		mix_test_153_bench(void){return printf(
			"  %Lf    %li    %hhi    %s    %p    %c  ",
			mx_Lf, mx_li, mx_c, mx_s, &mx_i, mx_c);}
int		mix_test_154_bench(void){return printf(
			"  %p    %X    %o    %u    %lli    %li  ",
			&mx_i, mx_u, mx_u, mx_u, mx_lli, mx_li);}
int		mix_test_155_bench(void){return printf(
			"  %li    %X    %u    %i    %f    %hi  ",
			mx_li, mx_u, mx_u, mx_i, mx_f, mx_hi);}
int		mix_test_156_bench(void){return printf(
			"  %Lf    %i    %X    %c    %hhi    %f  ",
			mx_Lf, mx_i, mx_u, mx_c, mx_c, mx_f);}
int		mix_test_157_bench(void){return printf(
			"  %p    %i    %Lf    %c    %li    %X  ",
			&mx_i, mx_i, mx_Lf, mx_c, mx_li, mx_u);}
int		mix_test_158_bench(void){return printf(
			"  %i    %p    %c    %f    %x    %li  ",
			mx_i, &mx_i, mx_c, mx_f, mx_u, mx_li);}
int		mix_test_159_bench(void){return printf(
			"  %li    %X    %f    %o    %s    %Lf  ",
			mx_li, mx_u, mx_f, mx_u, mx_s, mx_Lf);}
int		mix_test_160_bench(void){return printf(
			"  %li    %hi    %hhi    %lli    %Lf    %p  ",
			mx_li, mx_hi, mx_c, mx_lli, mx_Lf, &mx_i);}
int		mix_test_161_bench(void){return printf(
			"  %Lf    %hhi    %li    %c    %X    %hi  ",
			mx_Lf, mx_c, mx_li, mx_c, mx_u, mx_hi);}
int		mix_test_162_bench(void){return printf(
			"  %lli    %c    %o    %li    %u    %i  ",
			mx_lli, mx_c, mx_u, mx_li, mx_u, mx_i);}
int		mix_test_163_bench(void){return printf(
			"  %Lf    %li    %i    %lli    %hi    %c  ",
			mx_Lf, mx_li, mx_i, mx_lli, mx_hi, mx_c);}
int		mix_test_164_bench(void){return printf(
			"  %p    %lli    %hi    %x    %li    %Lf  ",
			&mx_i, mx_lli, mx_hi, mx_u, mx_li, mx_Lf);}
int		mix_test_165_bench(void){return printf(
			"  %u    %hhi    %p    %lli    %hi    %x  ",
			mx_u, mx_c, &mx_i, mx_lli, mx_hi, mx_u);}
int		mix_test_166_bench(void){return printf(
			"  %p    %hhi    %s    %li    %Lf    %hi  ",
			&mx_i, mx_c, mx_s, mx_li, mx_Lf, mx_hi);}
int		mix_test_167_bench(void){return printf(
			"  %s    %lli    %p    %i    %u    %hhi  ",
			mx_s, mx_lli, &mx_i, mx_i, mx_u, mx_c);}
int		mix_test_168_bench(void){return printf(
			"  %p    %o    %Lf    %X    %c    %u  ",
			&mx_i, mx_u, mx_Lf, mx_u, mx_c, mx_u);}
int		mix_test_169_bench(void){return printf(
			"  %p    %i    %X    %lli    %c    %hhi  ",
			&mx_i, mx_i, mx_u, mx_lli, mx_c, mx_c);}
int		mix_test_170_bench(void){return printf(
			"  %i    %lli    %p    %o    %X    %f  ",
			mx_i, mx_lli, &mx_i, mx_u, mx_u, mx_f);}
int		mix_test_171_bench(void){return printf(
			"  %f    %p    %c    %hi    %li    %i  ",
			mx_f, &mx_i, mx_c, mx_hi, mx_li, mx_i);}
int		mix_test_172_bench(void){return printf(
			"  %lli    %o    %i    %hhi    %c    %X  ",
			mx_lli, mx_u, mx_i, mx_c, mx_c, mx_u);}
int		mix_test_173_bench(void){return printf(
			"  %p    %hi    %lli    %X    %x    %o  ",
			&mx_i, mx_hi, mx_lli, mx_u, mx_u, mx_u);}
int		mix_test_174_bench(void){return printf(
			"  %hhi    %X    %u    %p    %x    %lli  ",
			mx_c, mx_u, mx_u, &mx_i, mx_u, mx_lli);}
int		mix_test_175_bench(void){return printf(
			"  %s    %Lf    %f    %hhi    %x    %o  ",
			mx_s, mx_Lf, mx_f, mx_c, mx_u, mx_u);}
int		mix_test_176_bench(void){return printf(
			"  %X    %f    %x    %o    %hi    %u  ",
			mx_u, mx_f, mx_u, mx_u, mx_hi, mx_u);}
int		mix_test_177_bench(void){return printf(
			"  %u    %hhi    %p    %o    %X    %x  ",
			mx_u, mx_c, &mx_i, mx_u, mx_u, mx_u);}
int		mix_test_178_bench(void){return printf(
			"  %f    %i    %lli    %o    %X    %c  ",
			mx_f, mx_i, mx_lli, mx_u, mx_u, mx_c);}
int		mix_test_179_bench(void){return printf(
			"  %lli    %o    %li    %X    %p    %c  ",
			mx_lli, mx_u, mx_li, mx_u, &mx_i, mx_c);}
int		mix_test_180_bench(void){return printf(
			"  %hi    %x    %i    %o    %c    %hhi  ",
			mx_hi, mx_u, mx_i, mx_u, mx_c, mx_c);}
int		mix_test_181_bench(void){return printf(
			"  %hi    %X    %hhi    %s    %lli    %c  ",
			mx_hi, mx_u, mx_c, mx_s, mx_lli, mx_c);}
int		mix_test_182_bench(void){return printf(
			"  %hhi    %c    %f    %Lf    %li    %i  ",
			mx_c, mx_c, mx_f, mx_Lf, mx_li, mx_i);}
int		mix_test_183_bench(void){return printf(
			"  %lli    %x    %hi    %c    %hhi    %i  ",
			mx_lli, mx_u, mx_hi, mx_c, mx_c, mx_i);}
int		mix_test_184_bench(void){return printf(
			"  %s    %X    %f    %x    %hi    %i  ",
			mx_s, mx_u, mx_f, mx_u, mx_hi, mx_i);}
int		mix_test_185_bench(void){return printf(
			"  %li    %hhi    %f    %Lf    %c    %o  ",
			mx_li, mx_c, mx_f, mx_Lf, mx_c, mx_u);}
int		mix_test_186_bench(void){return printf(
			"  %Lf    %i    %li    %u    %X    %hhi  ",
			mx_Lf, mx_i, mx_li, mx_u, mx_u, mx_c);}
int		mix_test_187_bench(void){return printf(
			"  %hi    %Lf    %f    %o    %s    %hhi  ",
			mx_hi, mx_Lf, mx_f, mx_u, mx_s, mx_c);}
int		mix_test_188_bench(void){return printf(
			"  %u    %x    %hi    %Lf    %lli    %X  ",
			mx_u, mx_u, mx_hi, mx_Lf, mx_lli, mx_u);}
int		mix_test_189_bench(void){return printf(
			"  %o    %u    %X    %s    %i    %hi  ",
			mx_u, mx_u, mx_u, mx_s, mx_i, mx_hi);}
int		mix_test_190_bench(void){return printf(
			"  %X    %s    %hhi    %u    %o    %lli  ",
			mx_u, mx_s, mx_c, mx_u, mx_u, mx_lli);}
int		mix_test_191_bench(void){return printf(
			"  %c    %f    %x    %lli    %u    %o  ",
			mx_c, mx_f, mx_u, mx_lli, mx_u, mx_u);}
int		mix_test_192_bench(void){return printf(
			"  %f    %u    %li    %x    %c    %hhi  ",
			mx_f, mx_u, mx_li, mx_u, mx_c, mx_c);}
int		mix_test_193_bench(void){return printf(
			"  %o    %i    %hi    %x    %hhi    %li  ",
			mx_u, mx_i, mx_hi, mx_u, mx_c, mx_li);}
int		mix_test_194_bench(void){return printf(
			"  %Lf    %s    %i    %c    %X    %li  ",
			mx_Lf, mx_s, mx_i, mx_c, mx_u, mx_li);}
int		mix_test_195_bench(void){return printf(
			"  %li    %s    %X    %o    %lli    %f  ",
			mx_li, mx_s, mx_u, mx_u, mx_lli, mx_f);}
int		mix_test_196_bench(void){return printf(
			"  %c    %o    %f    %Lf    %lli    %X  ",
			mx_c, mx_u, mx_f, mx_Lf, mx_lli, mx_u);}
int		mix_test_197_bench(void){return printf(
			"  %hi    %o    %i    %Lf    %li    %x  ",
			mx_hi, mx_u, mx_i, mx_Lf, mx_li, mx_u);}
int		mix_test_198_bench(void){return printf(
			"  %p    %i    %x    %Lf    %u    %o  ",
			&mx_i, mx_i, mx_u, mx_Lf, mx_u, mx_u);}
int		mix_test_199_bench(void){return printf(
			"  %f    %Lf    %c    %hi    %hhi    %li  ",
			mx_f, mx_Lf, mx_c, mx_hi, mx_c, mx_li);}
int		mix_test_extra_1_bench(void){return printf(
			"  %o    %f    %i    %%    %hhi    %Lf  ",
			mx_u, mx_f, mx_i, mx_c, mx_Lf);}
int		mix_test_extra_2_bench(void){return printf(
			"  %li    %Lf    %f    %i    %lli    %c  ",
			mx_li, mx_Lf, mx_f, mx_i, mx_lli, mx_c);}
int		mix_test_extra_3_bench(void){return printf(
			"  %li    %%    %f    %i    %lli    %c  ",
			mx_li, mx_f, mx_i, mx_lli, mx_c);}
int		mix_test_extra_4_bench(void){return printf(
			"  %%    %Lf    %f    %i    %%    %c  ",
			mx_Lf, mx_f, mx_i, mx_c);}
int		mix_test_extra_5_bench(void){return printf(
			"  %li    %Lf    %f    %%    %lli    %%  ",
			mx_li, mx_Lf, mx_f, mx_lli);}
int		mix_test_extra_6_bench(void){return printf(
			"  %li    %Lf    %f    %i    %lli    %c  ",
			mx_li, mx_Lf, mx_f, mx_i, mx_lli, mx_c);}
int		mix_test_extra_7_bench(void){return printf(
			"  %%    %Lf    %%    %i    %lli    %c  ",
			mx_Lf, mx_i, mx_lli, mx_c);}
int		mix_test_extra_8_bench(void){return printf(
			"  %%    %u    %hhi    %li    %hi    %x  ",
			mx_u, mx_c, mx_li, mx_hi, mx_u);}
int		mix_test_extra_9_bench(void){return printf(
			"  %c    %u    %hhi    %%    %hi    %x  ",
			mx_c, mx_u, mx_c, mx_hi, mx_u);}
int		mix_test_extra_10_bench(void){return printf(
			"  %c    %%    %hhi    %p    %hi    %x  ",
			mx_c, mx_hhi, &mx_c, mx_hi, mx_u);}
int		mix_successive_0_bench(void){return ( printf("%c", mx_c) + printf("%u", mx_u));}
int		mix_successive_1_bench(void){return ( printf("%o", mx_u) + printf("%%"));}
int		mix_successive_2_bench(void){return ( printf("%s", mx_s) + printf("%Lf", mx_Lf));}
int		mix_successive_3_bench(void){return ( printf("%Lf", mx_Lf) + printf("%hhi", mx_c));}
int		mix_successive_4_bench(void){return ( printf("%x", mx_u) + printf("%i", mx_i));}
int		mix_successive_5_bench(void){return ( printf("%x", mx_u) + printf("%o", mx_u));}
int		mix_successive_6_bench(void){return ( printf("%s", mx_s) + printf("%c", mx_c));}
int		mix_successive_7_bench(void){return ( printf("%p", &mx_i) + printf("%hi", mx_hi));}
int		mix_successive_8_bench(void){return ( printf("%f", mx_f) + printf("%p", &mx_i));}
int		mix_successive_9_bench(void){return ( printf("%hi", mx_hi) + printf("%u", mx_u));}
int		mix_successive_10_bench(void){return ( printf("%u", mx_u) + printf("%s", mx_s));}
int		mix_successive_11_bench(void){return ( printf("%Lf", mx_Lf) + printf("%p", &mx_i));}
int		mix_successive_12_bench(void){return ( printf("%f", mx_f) + printf("%hhi", mx_c));}
int		mix_successive_13_bench(void){return ( printf("%X", mx_u) + printf("%hhi", mx_c));}
int		mix_successive_14_bench(void){return ( printf("%X", mx_u) + printf("%f", mx_f));}
int		mix_successive_15_bench(void){return ( printf("%hhi", mx_c) + printf("%X", mx_u));}
int		mix_successive_16_bench(void){return ( printf("%s", mx_s) + printf("%x", mx_u));}
int		mix_successive_17_bench(void){return ( printf("%lli", mx_lli) + printf("%i", mx_i));}
int		mix_successive_18_bench(void){return ( printf("%s", mx_s) + printf("%o", mx_u));}
int		mix_successive_19_bench(void){return ( printf("%hhi", mx_c) + printf("%X", mx_u));}
int		mix_successive_20_bench(void){return ( printf("%p", &mx_i) + printf("%s", mx_s));}
int		mix_successive_21_bench(void){return ( printf("%X", mx_u) + printf("%x", mx_u));}
int		mix_successive_22_bench(void){return ( printf("%p", &mx_i) + printf("%lli", mx_lli));}
int		mix_successive_23_bench(void){return ( printf("%s", mx_s) + printf("%f", mx_f));}
int		mix_successive_24_bench(void){return ( printf("%c", mx_c) + printf("%hhi", mx_c));}
int		mix_successive_25_bench(void){return ( printf("%x", mx_u) + printf("%f", mx_f));}
int		mix_successive_26_bench(void){return ( printf("%s", mx_s) + printf("%li", mx_li));}
int		mix_successive_27_bench(void){return ( printf("%f", mx_f) + printf("%Lf", mx_Lf));}
int		mix_successive_28_bench(void){return ( printf("%i", mx_i) + printf("%u", mx_u));}
int		mix_successive_29_bench(void){return ( printf("%o", mx_u) + printf("%li", mx_li));}
int		mix_successive_30_bench(void){return ( printf("%s", mx_s) + printf("%u", mx_u));}
int		mix_successive_31_bench(void){return ( printf("%X", mx_u) + printf("%c", mx_c));}
int		mix_successive_32_bench(void){return ( printf("%x", mx_u) + printf("%u", mx_u));}
int		mix_successive_33_bench(void){return ( printf("%Lf", mx_Lf) + printf("%s", mx_s));}
int		mix_successive_34_bench(void){return ( printf("%hhi", mx_c) + printf("%u", mx_u));}
int		mix_successive_35_bench(void){return ( printf("%p", &mx_i) + printf("%f", mx_f));}
int		mix_successive_36_bench(void){return ( printf("%li", mx_li) + printf("%o", mx_u));}
int		mix_successive_37_bench(void){return ( printf("%s", mx_s) + printf("%li", mx_li));}
int		mix_successive_38_bench(void){return ( printf("%o", mx_u) + printf("%lli", mx_lli));}
int		mix_successive_39_bench(void){return ( printf("%i", mx_i) + printf("%c", mx_c));}
int		mix_successive_40_bench(void){return ( printf("%c", mx_c) + printf("%x", mx_u));}
int		mix_successive_41_bench(void){return ( printf("%hhi", mx_c) + printf("%x", mx_u));}
int		mix_successive_42_bench(void){return ( printf("%x", mx_u) + printf("%s", mx_s));}
int		mix_successive_43_bench(void){return ( printf("%u", mx_u) + printf("%x", mx_u));}
int		mix_successive_44_bench(void){return ( printf("%i", mx_i) + printf("%f", mx_f));}
int		mix_successive_45_bench(void){return ( printf("%s", mx_s) + printf("%c", mx_c));}
int		mix_successive_46_bench(void){return ( printf("%i", mx_i) + printf("%s", mx_s));}
int		mix_successive_47_bench(void){return ( printf("%u", mx_u) + printf("%hhi", mx_c));}
int		mix_successive_48_bench(void){return ( printf("%hi", mx_hi) + printf("%o", mx_u));}
int		mix_successive_49_bench(void){return ( printf("%i", mx_i) + printf("%hi", mx_hi));}
int		mix_successive_50_bench(void){return ( printf("%o", mx_u) + printf("%Lf", mx_Lf));}
int		mix_successive_51_bench(void){return ( printf("%li", mx_li) + printf("%hhi", mx_c));}
int		mix_successive_52_bench(void){return ( printf("%hi", mx_hi) + printf("%hhi", mx_c));}
int		mix_successive_53_bench(void){return ( printf("%Lf", mx_Lf) + printf("%x", mx_u));}
int		mix_successive_54_bench(void){return ( printf("%c", mx_c) + printf("%hi", mx_hi));}
int		mix_successive_55_bench(void){return ( printf("%hi", mx_hi) + printf("%s", mx_s));}
int		mix_successive_56_bench(void){return ( printf("%i", mx_i) + printf("%lli", mx_lli));}
int		mix_successive_57_bench(void){return ( printf("%c", mx_c) + printf("%Lf", mx_Lf));}
int		mix_successive_58_bench(void){return ( printf("%f", mx_f) + printf("%x", mx_u));}
int		mix_successive_59_bench(void){return ( printf("%s", mx_s) + printf("%li", mx_li));}
int		mix_successive_60_bench(void){return ( printf("%hhi", mx_c) + printf("%s", mx_s));}
int		mix_successive_61_bench(void){return ( printf("%p", &mx_i) + printf("%c", mx_c));}
int		mix_successive_62_bench(void){return ( printf("%lli", mx_lli) + printf("%u", mx_u));}
int		mix_successive_63_bench(void){return ( printf("%x", mx_u) + printf("%o", mx_u));}
int		mix_successive_64_bench(void){return ( printf("%s", mx_s) + printf("%c", mx_c));}
int		mix_successive_65_bench(void){return ( printf("%i", mx_i) + printf("%lli", mx_lli));}
int		mix_successive_66_bench(void){return ( printf("%li", mx_li) + printf("%Lf", mx_Lf));}
int		mix_successive_67_bench(void){return ( printf("%hi", mx_hi) + printf("%x", mx_u));}
int		mix_successive_68_bench(void){return ( printf("%i", mx_i) + printf("%hi", mx_hi));}
int		mix_successive_69_bench(void){return ( printf("%Lf", mx_Lf) + printf("%li", mx_li));}
int		mix_successive_70_bench(void){return ( printf("%o", mx_u) + printf("%li", mx_li));}



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
int nocrash_mandatory_wformat_undefbehav_08_bench(void){return printf("%+u", 5);}
int nocrash_mandatory_wformat_undefbehav_09_bench(void){return printf("%+u", 5);}
int nocrash_mandatory_wformat_undefbehav_10_bench(void){return printf("%+u", 4294967295);}
int nocrash_mandatory_wformat_undefbehav_11_bench(void){return printf("%+5u", 35);}
int nocrash_mandatory_wformat_undefbehav_12_bench(void){return printf("%+7u", 0);}
int nocrash_mandatory_wformat_undefbehav_13_bench(void){return printf("%+24u", 4294967295);}
int nocrash_mandatory_wformat_undefbehav_14_bench(void){return printf("%+.7u", 234);}
int nocrash_mandatory_wformat_undefbehav_15_bench(void){return printf("%+.3u", 3723);}
int nocrash_mandatory_wformat_undefbehav_16_bench(void){return printf("%+05u", 432);}
int nocrash_mandatory_wformat_undefbehav_17_bench(void){return printf("%+04u", 0);}
int nocrash_mandatory_wformat_undefbehav_18_bench(void){return printf("%+8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_19_bench(void){return printf("%+8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_20_bench(void){return printf("%+8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_21_bench(void){return printf("%+3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_22_bench(void){return printf("%+3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_23_bench(void){return printf("%+-8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_24_bench(void){return printf("%+-8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_25_bench(void){return printf("%+-8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_26_bench(void){return printf("%+-3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_27_bench(void){return printf("%+-3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_28_bench(void){return printf("%0+8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_29_bench(void){return printf("%0+8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_30_bench(void){return printf("%0+8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_31_bench(void){return printf("%0+3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_32_bench(void){return printf("%0+3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_33_bench(void){return printf("%0+-8.5u", 34);}
int nocrash_mandatory_wformat_undefbehav_34_bench(void){return printf("%0+-8.5u", 0);}
int nocrash_mandatory_wformat_undefbehav_35_bench(void){return printf("%0+-8.3u", 8375);}
int nocrash_mandatory_wformat_undefbehav_36_bench(void){return printf("%0+-3.7u", 3267);}
int nocrash_mandatory_wformat_undefbehav_37_bench(void){return printf("%0+-3.3u", 6983);}
int nocrash_mandatory_wformat_undefbehav_38_bench(void){return printf("%05c", '\0');}
int nocrash_mandatory_wformat_undefbehav_39_bench(void){return printf("%-05c", '\0');}
int nocrash_mandatory_wformat_undefbehav_40_bench(void){return printf("%+lu", 22337203685477);}

//nocrash tests adapted from tests contributed by phtruong
int nocrash_mandatory_dupflag_d_asas_bench(void){return printf("%++d", 42);}
int nocrash_mandatory_dupflag_d_spsp_bench(void){return printf("%  d", 42);}
int nocrash_mandatory_dupflag_d_spassp_bench(void){return printf("% + d", 42);}
int nocrash_mandatory_dupflag_d_ljljw_bench(void){return printf("%--5d", 42);}
int nocrash_mandatory_dupflag_d_ljasljw_bench(void){return printf("%-+-5d", 42);}
int nocrash_mandatory_dupflag_x_afaf_bench(void){return printf("%##x", 42);}
int nocrash_mandatory_dupflag_x_afasasafljw_bench(void){return printf("%#++#-5x", 42);}

//nocrash tests that came about as part of the minimal specification
int nocrash_mandatory_c_prec_1_bench(void){return printf("%.4c", 'a');}
int nocrash_mandatory_c_prec_2_bench(void){return printf("%.c", 'a');}
int nocrash_mandatory_c_af_bench(void){return printf("%#c", 'a');}
int nocrash_mandatory_c_zp_1_bench(void){return printf("%05c", 'a');}
int nocrash_mandatory_c_zp_2_bench(void){return printf("%0c", 'a');}
int nocrash_mandatory_c_as_1_bench(void){return printf("%+c", 'a');}
int nocrash_mandatory_c_as_2_bench(void){return printf("%+c", -42);}
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
int nocrash_mandatory_s_as_1_bench(void){return printf("%+s", "hello");}
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
int nocrash_mandatory_p_as_1_bench(void){return printf("%+p", &ncm_p);}
int nocrash_mandatory_p_as_2_bench(void){return printf("%+p", &ncm_p);}
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
int nocrash_mandatory_o_as_bench(void){return printf("%+o", 42);}
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
int nocrash_mandatory_u_as_bench(void){return printf("%+u", 42);}
int nocrash_mandatory_u_sp_bench(void){return printf("% u", 42);}
int nocrash_mandatory_u_size_hhh_bench(void){return printf("%hhhu", 42);}
int nocrash_mandatory_u_size_hhhh_bench(void){return printf("%hhhhu", 42);}
int nocrash_mandatory_u_size_hhl_bench(void){return printf("%hhlu", 42);}
int nocrash_mandatory_u_size_hhll_bench(void){return printf("%hhllu", 42);}
int nocrash_mandatory_u_size_llh_bench(void){return printf("%llhu", 42);}
int nocrash_mandatory_u_size_lll_bench(void){return printf("%lllu", 42);}
int nocrash_mandatory_u_lj_nowidth_bench(void){return printf("%-u", 42);}
int nocrash_mandatory_x_size_L_bench(void){return printf("%Lx", 42);}
int nocrash_mandatory_x_as_bench(void){return printf("%+x", 42);}
int nocrash_mandatory_x_sp_bench(void){return printf("% x", 42);}
int nocrash_mandatory_x_size_hhh_bench(void){return printf("%hhhx", 42);}
int nocrash_mandatory_x_size_hhhh_bench(void){return printf("%hhhhx", 42);}
int nocrash_mandatory_x_size_hhl_bench(void){return printf("%hhlx", 42);}
int nocrash_mandatory_x_size_hhll_bench(void){return printf("%hhllx", 42);}
int nocrash_mandatory_x_size_llh_bench(void){return printf("%llhx", 42);}
int nocrash_mandatory_x_size_lll_bench(void){return printf("%lllx", 42);}
int nocrash_mandatory_X_size_L_bench(void){return printf("%LX", 42);}
int nocrash_mandatory_X_as_bench(void){return printf("%+X", 42);}
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
int moul_ld_1_throwswarning_bench(void){return printf("%ld", 42);}
int moul_ld_2_throwswarning_bench(void){return printf("Kashim a %ld histoires à raconter", 1001);}
int moul_ld_3_throwswarning_bench(void){return printf("Il fait au moins %ld\n", -8000);}
int moul_ld_4_throwswarning_bench(void){return printf("%ld", -0);}
int moul_ld_5_throwswarning_bench(void){return printf("%ld", 0);}
int moul_ld_6_throwswarning_bench(void){return printf("%ld", INT_MAX);}
int moul_ld_7_throwswarning_bench(void){return printf("%ld", INT_MIN);}
int moul_ld_8_throwswarning_bench(void){return printf("%ld", INT_MIN - 1);}
int moul_ld_9_throwswarning_bench(void){return printf("%ld", INT_MAX + 1);}
int moul_ld_10_throwswarning_bench(void){return printf("%%ld 0000042 == |%ld|\n", 0000042);}
int moul_ld_11_throwswarning_bench(void){return printf("%%ld \t == |%ld|\n", '\t');}
int moul_ld_12_throwswarning_bench(void){return printf("%%ld Lydie == |%ld|\n", 'L'+'y'+'d'+'i'+'e');}
int moul_D_1_notmandatory_bench(void){return printf("%D", 42);}
int moul_D_2_notmandatory_bench(void){return printf("Kashim a %D histoires à raconter", 1001);}
int moul_D_3_notmandatory_bench(void){return printf("Il fait au moins %D\n", -8000);}
int moul_D_4_notmandatory_bench(void){return printf("%D", -0);}
int moul_D_5_notmandatory_bench(void){return printf("%D", 0);}
int moul_D_6_notmandatory_bench(void){return printf("%D", INT_MAX);}
int moul_D_7_notmandatory_bench(void){return printf("%D", INT_MIN);}
int moul_D_8_notmandatory_bench(void){return printf("%D", INT_MIN - 1);}
int moul_D_9_notmandatory_bench(void){return printf("%D", INT_MAX + 1);}
int moul_D_10_notmandatory_bench(void){return printf("%%D 0000042 == |%D|\n", 0000042);}
int moul_D_11_notmandatory_bench(void){return printf("%%D \t == |%D|\n", '\t');}
int moul_D_12_notmandatory_bench(void){return printf("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');}
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
int moul_f_1_bench(void){return printf("%f", (double)42);}
int moul_f_2_bench(void){return printf("Kashim a %f histoires à raconter", (double)1001);}
int moul_f_3_bench(void){return printf("Il fait au moins %f\n", (double)-8000);}
int moul_f_4_bench(void){return printf("%f", (double)-0);}
int moul_f_5_bench(void){return printf("%f", (double)0);}
int moul_f_6_bench(void){return printf("%f", (double)INT_MAX);}
int moul_f_7_bench(void){return printf("%f", (double)INT_MIN);}
int moul_f_7b_bench(void){return printf("%f", (double)INT_MIN - 1);}
int moul_f_8_bench(void){return printf("%f", (double)INT_MAX + 1);}
int moul_f_9_bench(void){return printf("%%f 0000042 == |%f|\n", (double)0000042);}
int moul_f_10_bench(void){return printf("%%f \t == |%f|\n", (double)'\t');}
int moul_f_11_bench(void){return printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_f_12_bench(void){return printf("%%f 42.42 == |%f|\n", 42.42);}
int moul_F_1_notmandatory_bench(void){return printf("%F", (double)42);}
int moul_F_2_notmandatory_bench(void){return printf("Kashim a %F histoires à raconter", (double)1001);}
int moul_F_3_notmandatory_bench(void){return printf("Il fait au moins %F\n", (double)-8000);}
int moul_F_4_notmandatory_bench(void){return printf("%F", (double)-0);}
int moul_F_5_notmandatory_bench(void){return printf("%F", (double)0);}
int moul_F_6_notmandatory_bench(void){return printf("%F", (double)INT_MAX);}
int moul_F_7_notmandatory_bench(void){return printf("%F", (double)INT_MIN);}
int moul_F_8_notmandatory_bench(void){return printf("%F", (double)INT_MIN - 1);}
int moul_F_9_notmandatory_bench(void){return printf("%F", (double)INT_MAX + 1);}
int moul_F_10_notmandatory_bench(void){return printf("%%F 0000042 == |%F|\n", (double)0000042);}
int moul_F_11_notmandatory_bench(void){return printf("%%F \t == |%F|\n", (double)'\t');}
int moul_F_12_notmandatory_bench(void){return printf("%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_F_13_notmandatory_bench(void){return printf("%%F 42.42 == |%F|\n", 42.42);}
int moul_F_14_notmandatory_bench(void){return printf("%%F 42.42 == |%.2F|\n", 42.42);}
int moul_o_1_bench(void){return printf("%o", 42);}
int moul_o_2_bench(void){return printf("Kashim a %o histoires à raconter", 1001);}
int moul_o_3_bench(void){return printf("Il fait au moins %o\n", -8000);}
int moul_o_4_bench(void){return printf("%o", -0);}
int moul_o_5_bench(void){return printf("%o", 0);}
int moul_o_6_bench(void){return printf("%o", INT_MAX);}
int moul_o_7_bench(void){return printf("%o", INT_MIN);}
int moul_o_8_bench(void){return printf("%o", INT_MIN - 1);}
int moul_o_9_bench(void){return printf("%o", INT_MAX + 1);}
int moul_o_10_bench(void){return printf("%%o 0000042 == |%o|\n", 0000042);}
int moul_o_11_bench(void){return printf("%%o \t == |%o|\n", '\t');}
int moul_o_12_bench(void){return printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');}
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
int moul_hash_1_bench(void){return printf("%%#X 42 ==  %#X\n", 42);}
int moul_hash_2_bench(void){return printf("%%X 42 ==  %X\n", 42);}
int moul_hash_3_bench(void){return printf("%%#o 0 ==  %#o\n", 0);}
int moul_hash_4_bench(void){return printf("%%o 0 ==  %o\n", 0);}
int moul_hash_5_bench(void){return printf("%%#o INT_MAX ==  %#o\n", INT_MAX);}
int moul_hash_6_bench(void){return printf("%%o INT_MAX ==  %o\n", INT_MAX);}
int moul_hash_7_bench(void){return printf("%%#o INT_MIN ==  %#o\n", INT_MIN);}
int moul_hash_8_bench(void){return printf("%%o INT_MIN ==  %o\n", INT_MIN);}
int moul_hash_9_bench(void){return printf("%%#X INT_MIN ==  %#X\n", INT_MIN);}
int moul_hash_10_bench(void){return printf("%%X INT_MIN ==  %X\n", INT_MIN);}
int moul_hash_11_bench(void){return printf("%%#X INT_MAX ==  %#X\n", INT_MAX);}
int moul_hash_12_bench(void){return printf("%%X INT_MAX ==  %X\n", INT_MAX);}
int moul_prec_1_bench(void){return printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");}
int moul_prec_2_bench(void){return printf("%% 4.5i 42 == |% 4.5i|\n", 42);}
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
int moul_as_1_bench(void){return printf("%%+i 42 == %+i\n", 42);}
int moul_as_2_bench(void){return printf("%%+d 42 == %+d\n", INT_MAX);}
int moul_as_3_bench(void){return printf("%%+i -42 == %+i\n", -42);}
int moul_as_4_bench(void){return printf("%%+04d 42 == %0+04d\n", 42);}
int moul_sp_1_bench(void){return printf("%%      i 42 == |%      i|\n", 42);}
int moul_sp_2_bench(void){return printf("%% i -42 == |% i|\n", -42);}
int moul_sp_3_bench(void){return printf("%% 4i 42 == |% 4i|\n", 42);}
int moul_notmandatory_e_1_bench(void){return printf("%e", (double)42);}
int moul_notmandatory_e_2_bench(void){return printf("Kashim a %e histoires à raconter", (double)1001);}
int moul_notmandatory_e_3_bench(void){return printf("Il fait au moins %e\n", (double)-8000);}
int moul_notmandatory_e_4_bench(void){return printf("%e", (double)-0);}
int moul_notmandatory_e_5_bench(void){return printf("%e", (double)0);}
int moul_notmandatory_e_6_bench(void){return printf("%e", (double)INT_MAX);}
int moul_notmandatory_e_7_bench(void){return printf("%e", (double)INT_MIN);}
int moul_notmandatory_e_8_bench(void){return printf("%e", (double)INT_MIN - 1);}
int moul_notmandatory_e_9_bench(void){return printf("%e", (double)INT_MAX + 1);}
int moul_notmandatory_e_10_bench(void){return printf("%%e 0000042 == |%e|\n", (double)0000042);}
int moul_notmandatory_e_11_bench(void){return printf("%%e \t == |%e|\n", (double)'\t');}
int moul_notmandatory_e_12_bench(void){return printf("%%e Lydie == |%e|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_notmandatory_e_13_bench(void){return printf("%%e 42.42 == |%e|\n", 42.42);}
int moul_notmandatory_e_14_bench(void){return printf("%E", (double)42);}
int moul_notmandatory_e_15_bench(void){return printf("Kashim a %E histoires à raconter", (double)1001);}
int moul_notmandatory_e_16_bench(void){return printf("Il fait au moins %E\n", (double)-8000);}
int moul_notmandatory_e_17_bench(void){return printf("%E", (double)-0);}
int moul_notmandatory_e_18_bench(void){return printf("%E", (double)0);}
int moul_notmandatory_e_19_bench(void){return printf("%E", (double)INT_MAX);}
int moul_notmandatory_e_20_bench(void){return printf("%E", (double)INT_MIN);}
int moul_notmandatory_e_21_bench(void){return printf("%E", (double)INT_MIN - 1);}
int moul_notmandatory_e_22_bench(void){return printf("%E", (double)INT_MAX + 1);}
int moul_notmandatory_e_23_bench(void){return printf("%%E 0000042 == |%E|\n", (double)0000042);}
int moul_notmandatory_e_24_bench(void){return printf("%%E \t == |%E|\n", (double)'\t');}
int moul_notmandatory_e_25_bench(void){return printf("%%E Lydie == |%E|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_notmandatory_e_26_bench(void){return printf("%%E 42.42 == |%E|\n", 42.42);}
int moul_notmandatory_e_27_bench(void){return printf("%%E 42.42 == |%.2E|\n", 42.42);}
int moul_notmandatory_g_1_bench(void){return printf("%g", (double)42);}
int moul_notmandatory_g_2_bench(void){return printf("Kashim a %g histoires à raconter", (double)1001);}
int moul_notmandatory_g_3_bench(void){return printf("Il fait au moins %g\n", (double)-8000);}
int moul_notmandatory_g_4_bench(void){return printf("%g", (double)-0);}
int moul_notmandatory_g_5_bench(void){return printf("%g", (double)0);}
int moul_notmandatory_g_5b_bench(void){return printf("%g", (double)INT_MAX);}
int moul_notmandatory_g_6_bench(void){return printf("%g", (double)INT_MIN);}
int moul_notmandatory_g_7_bench(void){return printf("%g", (double)INT_MIN - 1);}
int moul_notmandatory_g_8_bench(void){return printf("%g", (double)INT_MAX + 1);}
int moul_notmandatory_g_9_bench(void){return printf("%%g 0000042 == |%g|\n", (double)0000042);}
int moul_notmandatory_g_10_bench(void){return printf("%%g \t == |%g|\n", (double)'\t');}
int moul_notmandatory_g_11_bench(void){return printf("%%g Lydie == |%g|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_notmandatory_g_12_bench(void){return printf("%%g 42.42 == |%g|\n", 42.42);}
int moul_notmandatory_g_13_bench(void){return printf("%G", (double)42);}
int moul_notmandatory_g_14_bench(void){return printf("Kashim a %G histoires à raconter", (double)1001);}
int moul_notmandatory_g_15_bench(void){return printf("Il fait au moins %G\n", (double)-8000);}
int moul_notmandatory_g_16_bench(void){return printf("%G", (double)-0);}
int moul_notmandatory_g_17_bench(void){return printf("%G", (double)0);}
int moul_notmandatory_g_18_bench(void){return printf("%G", (double)INT_MAX);}
int moul_notmandatory_g_19_bench(void){return printf("%G", (double)INT_MIN);}
int moul_notmandatory_g_20_bench(void){return printf("%G", (double)INT_MIN - 1);}
int moul_notmandatory_g_21_bench(void){return printf("%G", (double)INT_MAX + 1);}
int moul_notmandatory_g_22_bench(void){return printf("%%G 0000042 == |%G|\n", (double)0000042);}
int moul_notmandatory_g_23_bench(void){return printf("%%G \t == |%G|\n", (double)'\t');}
int moul_notmandatory_g_24_bench(void){return printf("%%G Lydie == |%G|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_notmandatory_g_25_bench(void){return printf("%%G 42.42 == |%G|\n", 42.42);}
int moul_notmandatory_g_26_bench(void){return printf("%%G 42.42 == |%.2G|\n", 42.42);}
int moul_notmandatory_a_1_bench(void){return printf("%a", (double)42);}
int moul_notmandatory_a_2_bench(void){return printf("Kashim a %a histoires à raconter", (double)1001);}
int moul_notmandatory_a_3_bench(void){return printf("Il fait au moins %a\n", (double)-8000);}
int moul_notmandatory_a_4_bench(void){return printf("%a", (double)-0);}
int moul_notmandatory_a_5_bench(void){return printf("%a", (double)0);}
int moul_notmandatory_a_6_bench(void){return printf("%a", (double)INT_MAX);}
int moul_notmandatory_a_7_bench(void){return printf("%a", (double)INT_MIN);}
int moul_notmandatory_a_8_bench(void){return printf("%a", (double)INT_MIN - 1);}
int moul_notmandatory_a_9_bench(void){return printf("%a", (double)INT_MAX + 1);}
int moul_notmandatory_a_11_bench(void){return printf("%%a 0000042 == |%a|\n", (double)0000042);}
int moul_notmandatory_a_12_bench(void){return printf("%%a \t == |%a|\n", (double)'\t');}
int moul_notmandatory_a_13_bench(void){return printf("%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_notmandatory_a_14_bench(void){return printf("%%a 42.42 == |%a|\n", 42.42);}
int moul_notmandatory_a_15_bench(void){return printf("%A", (double)42);}
int moul_notmandatory_a_16_bench(void){return printf("Kashim a %A histoires à raconter", (double)1001);}
int moul_notmandatory_a_17_bench(void){return printf("Il fait au moins %A\n", (double)-8000);}
int moul_notmandatory_a_18_bench(void){return printf("%A", (double)-0);}
int moul_notmandatory_a_19_bench(void){return printf("%A", (double)0);}
int moul_notmandatory_a_20_bench(void){return printf("%A", (double)INT_MAX);}
int moul_notmandatory_a_21_bench(void){return printf("%A", (double)INT_MIN);}
int moul_notmandatory_a_22_bench(void){return printf("%A", (double)INT_MIN - 1);}
int moul_notmandatory_a_23_bench(void){return printf("%A", (double)INT_MAX + 1);}
int moul_notmandatory_a_24_bench(void){return printf("%%A 0000042 == |%A|\n", (double)0000042);}
int moul_notmandatory_a_25_bench(void){return printf("%%A \t == |%A|\n", (double)'\t');}
int moul_notmandatory_a_26_bench(void){return printf("%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');}
int moul_notmandatory_a_27_bench(void){return printf("%%A 42.42 == |%A|\n", 42.42);}
int moul_notmandatory_a_28_bench(void){return printf("%%A 42.42 == |%.2A|\n", 42.42);}
int moul_notmandatory_star_1_bench(void){return printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");}
int moul_notmandatory_star_2_bench(void){return printf("%% *.5i 42 == |% *.5i|\n", 4, 42);}
int moul_notmandatory_star_3_bench(void){return printf("%%*i 42 == |%*i|\n", 5, 42);}
int moul_notmandatory_star_4_bench(void){return printf("%%*i 42 == |%*i|\n", 3, 42);}
int moul_notmandatory_star_5_bench(void){return printf("%%*i 42 == |%*i|\n", 2, 42);}
int moul_notmandatory_widechar_mix2_throwswarning_bench(void){return printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");}
int moul_notmandatory_widechar_basic1_bench(void){wchar_t c = L'\x82'; return printf("%C\n", c);}
int moul_notmandatory_widechar_basic2_bench(void){return printf("%C\n", L'ø');}
int moul_notmandatory_widestr_basic2_bench(void){wchar_t wz[3] = L"@@"; return printf("%ls", wz);}






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
	{0, 123, "s_undefbehav_4_flags_diff_order_1", s_undefbehav_4_flags_diff_order_1, s_undefbehav_4_flags_diff_order_1_bench, "{return test(\"%+- 06.06s\", s_hidden);}"},
	{0, 124, "s_undefbehav_4_flags_diff_order_2", s_undefbehav_4_flags_diff_order_2, s_undefbehav_4_flags_diff_order_2_bench, "{return test(\"% 0+-6.06s\", s_hidden);}"},
	{0, 125, "s_undefbehav_4_flags_diff_order_3", s_undefbehav_4_flags_diff_order_3, s_undefbehav_4_flags_diff_order_3_bench, "{return test(\"%0 +-6.06s\", s_hidden);}"},
	{0, 126, "s_undefbehav_4_flags_diff_order_4", s_undefbehav_4_flags_diff_order_4, s_undefbehav_4_flags_diff_order_4_bench, "{return test(\"%+-0 6.06s\", s_hidden);}"},
	{0, 127, "s_undefbehav_4_flags_diff_order_5", s_undefbehav_4_flags_diff_order_5, s_undefbehav_4_flags_diff_order_5_bench, "{return test(\"%-+ 06.06s\", s_hidden);}"},
	{0, 128, "s_undefbehav_4_flags_diff_order_6", s_undefbehav_4_flags_diff_order_6, s_undefbehav_4_flags_diff_order_6_bench, "{return test(\"% -+06.06s\", s_hidden);}"},
	{0, 129, "s_undefbehav_4_flags_sp_padded_diff_order_1", s_undefbehav_4_flags_sp_padded_diff_order_1, s_undefbehav_4_flags_sp_padded_diff_order_1_bench, "{return test(\"%+- 07.06s\", s_hidden);}"},
	{0, 130, "s_undefbehav_4_flags_sp_padded_diff_order_2", s_undefbehav_4_flags_sp_padded_diff_order_2, s_undefbehav_4_flags_sp_padded_diff_order_2_bench, "{return test(\"% 0+-8.06s\", s_hidden);}"},
	{0, 131, "s_undefbehav_4_flags_sp_padded_diff_order_3", s_undefbehav_4_flags_sp_padded_diff_order_3, s_undefbehav_4_flags_sp_padded_diff_order_3_bench, "{return test(\"%0 +-9.06s\", s_hidden);}"},
	{0, 132, "s_undefbehav_4_flags_sp_padded_diff_order_4", s_undefbehav_4_flags_sp_padded_diff_order_4, s_undefbehav_4_flags_sp_padded_diff_order_4_bench, "{return test(\"%+-0 10.06s\", s_hidden);}"},
	{0, 133, "s_undefbehav_4_flags_sp_padded_diff_order_5", s_undefbehav_4_flags_sp_padded_diff_order_5, s_undefbehav_4_flags_sp_padded_diff_order_5_bench, "{return test(\"%-+ 011.06s\", s_hidden);}"},
	{0, 134, "s_undefbehav_4_flags_sp_padded_diff_order_6", s_undefbehav_4_flags_sp_padded_diff_order_6, s_undefbehav_4_flags_sp_padded_diff_order_6_bench, "{return test(\"% -+012.06s\", s_hidden);}"},
	{0, 135, "s_undefbehav_4_flags_as_lj_sp_zero_trunc", s_undefbehav_4_flags_as_lj_sp_zero_trunc, s_undefbehav_4_flags_as_lj_sp_zero_trunc_bench, "{return test(\"%+- 06.04s\", s_hidden);}"},
	{0, 136, "s_undefbehav_4_flags_sp_zero_as_lj_trunc", s_undefbehav_4_flags_sp_zero_as_lj_trunc, s_undefbehav_4_flags_sp_zero_as_lj_trunc_bench, "{return test(\"% 0+-6.04s\", s_hidden);}"},
	{0, 137, "s_undefbehav_4_flags_zero_sp_as_lj_trunc", s_undefbehav_4_flags_zero_sp_as_lj_trunc, s_undefbehav_4_flags_zero_sp_as_lj_trunc_bench, "{return test(\"%0 +-6.04s\", s_hidden);}"},
	{0, 138, "s_undefbehav_4_flags_as_lj_zero_sp_trunc", s_undefbehav_4_flags_as_lj_zero_sp_trunc, s_undefbehav_4_flags_as_lj_zero_sp_trunc_bench, "{return test(\"%+-0 6.04s\", s_hidden);}"},
	{0, 139, "s_undefbehav_4_flags_lj_as_sp_zero_trunc", s_undefbehav_4_flags_lj_as_sp_zero_trunc, s_undefbehav_4_flags_lj_as_sp_zero_trunc_bench, "{return test(\"%-+ 06.04s\", s_hidden);}"},
	{0, 140, "s_undefbehav_4_flags_sp_zero_lj_as_trunc", s_undefbehav_4_flags_sp_zero_lj_as_trunc, s_undefbehav_4_flags_sp_zero_lj_as_trunc_bench, "{return test(\"% 0-+6.04s\", s_hidden);}"},
	{0, 141, "s_undefbehav_4_flags_as_lj_sp_zero__pads", s_undefbehav_4_flags_as_lj_sp_zero__pads, s_undefbehav_4_flags_as_lj_sp_zero__pads_bench, "{return test(\"%+- 06.09s\", s_hidden);}"},
	{0, 142, "s_undefbehav_4_flags_sp_zero_as_lj__pads", s_undefbehav_4_flags_sp_zero_as_lj__pads, s_undefbehav_4_flags_sp_zero_as_lj__pads_bench, "{return test(\"% 0+-6.09s\", s_hidden);}"},
	{0, 143, "s_undefbehav_4_flags_zero_sp_as_lj__pads", s_undefbehav_4_flags_zero_sp_as_lj__pads, s_undefbehav_4_flags_zero_sp_as_lj__pads_bench, "{return test(\"%0 +-6.09s\", s_hidden);}"},
	{0, 144, "s_undefbehav_4_flags_as_lj_zero_sp__pads", s_undefbehav_4_flags_as_lj_zero_sp__pads, s_undefbehav_4_flags_as_lj_zero_sp__pads_bench, "{return test(\"%+-0 6.09s\", s_hidden);}"},
	{0, 145, "s_undefbehav_4_flags_lj_as_sp_zero__pads", s_undefbehav_4_flags_lj_as_sp_zero__pads, s_undefbehav_4_flags_lj_as_sp_zero__pads_bench, "{return test(\"%-+ 06.09s\", s_hidden);}"},
	{0, 146, "s_undefbehav_4_flags_sp_zero_lj_as__pads", s_undefbehav_4_flags_sp_zero_lj_as__pads, s_undefbehav_4_flags_sp_zero_lj_as__pads_bench, "{return test(\"% 0-+6.09s\", s_hidden);}"},
	{0, 147, "s_undefbehav_0_2zero", s_undefbehav_0_2zero, s_undefbehav_0_2zero_bench, "{return test(\"%00s\", s_hidden);}"},
	{0, 148, "s_undefbehav_0_3zero", s_undefbehav_0_3zero, s_undefbehav_0_3zero_bench, "{return test(\"%000s\", s_hidden);}"},
	{0, 149, "s_undefbehav_0_4zero", s_undefbehav_0_4zero, s_undefbehav_0_4zero_bench, "{return test(\"%0000s\", s_hidden);}"},
	{0, 150, "s_undefbehav_0_lj_2zero", s_undefbehav_0_lj_2zero, s_undefbehav_0_lj_2zero_bench, "{return test(\"%-00s\", s_hidden);}"},
	{0, 151, "s_undefbehav_0_zero_lj_zero", s_undefbehav_0_zero_lj_zero, s_undefbehav_0_zero_lj_zero_bench, "{return test(\"%0-0s\", s_hidden);}"},
	{0, 152, "s_undefbehav_0_2zero_lj", s_undefbehav_0_2zero_lj, s_undefbehav_0_2zero_lj_bench, "{return test(\"%00-s\", s_hidden);}"},
	{0, 153, "s_undefbehav_0_width_3", s_undefbehav_0_width_3, s_undefbehav_0_width_3_bench, "{return test(\"%03s\", s_hidden);}"},
	{0, 154, "s_undefbehav_0_width_9", s_undefbehav_0_width_9, s_undefbehav_0_width_9_bench, "{return test(\"%09s\", s_hidden);}"},
	{0, 155, "s_undefbehav_as_0_width_3", s_undefbehav_as_0_width_3, s_undefbehav_as_0_width_3_bench, "{return test(\"%+03s\", s_hidden);}"},
	{0, 156, "s_undefbehav_as_0_width_9", s_undefbehav_as_0_width_9, s_undefbehav_as_0_width_9_bench, "{return test(\"%+09s\", s_hidden);}"},
	{0, 157, "s_undefbehav_lj_0_width_3", s_undefbehav_lj_0_width_3, s_undefbehav_lj_0_width_3_bench, "{return test(\"%-03s\", s_hidden);}"},
	{0, 158, "s_undefbehav_lj_0_width_9", s_undefbehav_lj_0_width_9, s_undefbehav_lj_0_width_9_bench, "{return test(\"%-09s\", s_hidden);}"},
	{0, 159, "s_undefbehav_as_sp_width_3", s_undefbehav_as_sp_width_3, s_undefbehav_as_sp_width_3_bench, "{return test(\"%+ 3s\", s_hidden);}"},
	{0, 160, "s_undefbehav_as_sp_width_6", s_undefbehav_as_sp_width_6, s_undefbehav_as_sp_width_6_bench, "{return test(\"%+ 6s\", s_hidden);}"},
	{1, 161, "i_basic_i_pos", i_basic_i_pos, i_basic_i_pos_bench, "{return test(\"this %i number\", 17);}"},
	{1, 162, "i_basic_i_neg", i_basic_i_neg, i_basic_i_neg_bench, "{return test(\"this %i number\", -267);}"},
	{1, 163, "i_basic_i_zero", i_basic_i_zero, i_basic_i_zero_bench, "{return test(\"this %i number\", 0);}"},
	{1, 164, "i_basic_i_onlypos", i_basic_i_onlypos, i_basic_i_onlypos_bench, "{return test(\"%i\", 3);}"},
	{1, 165, "i_basic_i_onlyneg", i_basic_i_onlyneg, i_basic_i_onlyneg_bench, "{return test(\"%i\", -1);}"},
	{1, 166, "i_basic_i_onlyzero", i_basic_i_onlyzero, i_basic_i_onlyzero_bench, "{return test(\"%i\", 0);}"},
	{1, 167, "d_basic_pos", d_basic_pos, d_basic_pos_bench, "{return test(\"this %d number\", 17);}"},
	{1, 168, "d_basic_neg", d_basic_neg, d_basic_neg_bench, "{return test(\"this %d number\", -267);}"},
	{1, 169, "d_basic_zero", d_basic_zero, d_basic_zero_bench, "{return test(\"this %d number\", 0);}"},
	{1, 170, "i_intmax", i_intmax, i_intmax_bench, "{return test(\"%i\",  2147483647);}"},
	{1, 171, "i_intmin", i_intmin, i_intmin_bench, "{return test(\"%i\", (int)(-2147483678));}"},
	{1, 172, "i_as_pos", i_as_pos, i_as_pos_bench, "{return test(\"%+i\", 5);}"},
	{1, 173, "i_as_neg", i_as_neg, i_as_neg_bench, "{return test(\"%+i\", -7);}"},
	{1, 174, "i_intmax_as", i_intmax_as, i_intmax_as_bench, "{return test(\"%+i\", 2147483647);}"},
	{1, 175, "i_width_pos_fits", i_width_pos_fits, i_width_pos_fits_bench, "{return test(\"%7i\", 33);}"},
	{1, 176, "i_width_neg_fits", i_width_neg_fits, i_width_neg_fits_bench, "{return test(\"%7i\", -14);}"},
	{1, 177, "i_width_zero_fits", i_width_zero_fits, i_width_zero_fits_bench, "{return test(\"%3i\", 0);}"},
	{1, 178, "i_width_pos_exactfit", i_width_pos_exactfit, i_width_pos_exactfit_bench, "{return test(\"%5i\", 52625);}"},
	{1, 179, "i_width_neg_exactfit", i_width_neg_exactfit, i_width_neg_exactfit_bench, "{return test(\"%5i\", -2562);}"},
	{1, 180, "i_width_pos_nofit", i_width_pos_nofit, i_width_pos_nofit_bench, "{return test(\"%4i\", 94827);}"},
	{1, 181, "i_width_neg_nofit", i_width_neg_nofit, i_width_neg_nofit_bench, "{return test(\"%4i\", -2464);}"},
	{1, 182, "i_width_pos_fits_lj", i_width_pos_fits_lj, i_width_pos_fits_lj_bench, "{return test(\"%-7i\", 33);}"},
	{1, 183, "i_width_neg_fits_lj", i_width_neg_fits_lj, i_width_neg_fits_lj_bench, "{return test(\"%-7i\", -14);}"},
	{1, 184, "i_width_zero_fits_lj", i_width_zero_fits_lj, i_width_zero_fits_lj_bench, "{return test(\"%-3i\", 0);}"},
	{1, 185, "i_width_pos_exactfit_lj", i_width_pos_exactfit_lj, i_width_pos_exactfit_lj_bench, "{return test(\"%-5i\", 52625);}"},
	{1, 186, "i_width_neg_exactfit_lj", i_width_neg_exactfit_lj, i_width_neg_exactfit_lj_bench, "{return test(\"%-5i\", -2562);}"},
	{1, 187, "i_width_pos_nofit_lj", i_width_pos_nofit_lj, i_width_pos_nofit_lj_bench, "{return test(\"%-4i\", 94827);}"},
	{1, 188, "i_width_neg_nofit_lj", i_width_neg_nofit_lj, i_width_neg_nofit_lj_bench, "{return test(\"%-4i\", -2464);}"},
	{1, 189, "i_width_as_pos", i_width_as_pos, i_width_as_pos_bench, "{return test(\"%+5i\", 35);}"},
	{1, 190, "i_width_as_zero", i_width_as_zero, i_width_as_zero_bench, "{return test(\"%+7i\", 0);}"},
	{1, 191, "i_width_intmax_as", i_width_intmax_as, i_width_intmax_as_bench, "{return test(\"%+24i\", 2147483647);}"},
	{1, 192, "i_prec_fits_pos", i_prec_fits_pos, i_prec_fits_pos_bench, "{return test(\"%.5i\", 2);}"},
	{1, 193, "i_prec_fits_neg", i_prec_fits_neg, i_prec_fits_neg_bench, "{return test(\"%.6i\", -3);}"},
	{1, 194, "i_prec_fits_zero", i_prec_fits_zero, i_prec_fits_zero_bench, "{return test(\"%.3i\", 0);}"},
	{1, 195, "i_prec_exactfit_pos", i_prec_exactfit_pos, i_prec_exactfit_pos_bench, "{return test(\"%.4i\", 5263);}"},
	{1, 196, "i_prec_exactfit_neg", i_prec_exactfit_neg, i_prec_exactfit_neg_bench, "{return test(\"%.4i\", -2372);}"},
	{1, 197, "i_prec_nofit_pos", i_prec_nofit_pos, i_prec_nofit_pos_bench, "{return test(\"%.3i\", 13862);}"},
	{1, 198, "i_prec_nofit_neg", i_prec_nofit_neg, i_prec_nofit_neg_bench, "{return test(\"%.3i\",-23646);}"},
	{1, 199, "i_prec_as_pos", i_prec_as_pos, i_prec_as_pos_bench, "{return test(\"%+.7i\", 234);}"},
	{1, 200, "i_prec_as_neg", i_prec_as_neg, i_prec_as_neg_bench, "{return test(\"%+.7i\", -446);}"},
	{1, 201, "i_prec_as_pos_nofit", i_prec_as_pos_nofit, i_prec_as_pos_nofit_bench, "{return test(\"%+.3i\", 3723);}"},
	{1, 202, "i_zp_pos_fits", i_zp_pos_fits, i_zp_pos_fits_bench, "{return test(\"%05i\", 43);}"},
	{1, 203, "i_zp_neg_fits", i_zp_neg_fits, i_zp_neg_fits_bench, "{return test(\"%07i\", -54);}"},
	{1, 204, "i_zp_zero_fits", i_zp_zero_fits, i_zp_zero_fits_bench, "{return test(\"%03i\", 0);}"},
	{1, 205, "i_zp_pos_exactfit", i_zp_pos_exactfit, i_zp_pos_exactfit_bench, "{return test(\"%03i\", 634);}"},
	{1, 206, "i_zp_neg_exactfit", i_zp_neg_exactfit, i_zp_neg_exactfit_bench, "{return test(\"%04i\", -532);}"},
	{1, 207, "i_zp_neg_minus1fit", i_zp_neg_minus1fit, i_zp_neg_minus1fit_bench, "{return test(\"%04i\", -4825);}"},
	{1, 208, "i_zp_as_fits", i_zp_as_fits, i_zp_as_fits_bench, "{return test(\"%+05i\", 432);}"},
	{1, 209, "i_zp_as_zero", i_zp_as_zero, i_zp_as_zero_bench, "{return test(\"%+04i\", 0);}"},
	{1, 210, "i_prec_width_fit_fit_pos", i_prec_width_fit_fit_pos, i_prec_width_fit_fit_pos_bench, "{return test(\"%8.5i\", 34);}"},
	{1, 211, "i_prec_width_fit_fit_neg", i_prec_width_fit_fit_neg, i_prec_width_fit_fit_neg_bench, "{return test(\"%10.5i\", -216);}"},
	{1, 212, "i_prec_width_fit_fit_zero", i_prec_width_fit_fit_zero, i_prec_width_fit_fit_zero_bench, "{return test(\"%8.5i\", 0);}"},
	{1, 213, "i_prec_width_nofit_fit_pos", i_prec_width_nofit_fit_pos, i_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3i\", 8375);}"},
	{1, 214, "i_prec_width_nofit_fit_neg", i_prec_width_nofit_fit_neg, i_prec_width_nofit_fit_neg_bench, "{return test(\"%8.3i\", -8473);}"},
	{1, 215, "i_prec_width_fit_nofit_pos", i_prec_width_fit_nofit_pos, i_prec_width_fit_nofit_pos_bench, "{return test(\"%3.7i\", 3267);}"},
	{1, 216, "i_prec_width_fit_nofit_neg", i_prec_width_fit_nofit_neg, i_prec_width_fit_nofit_neg_bench, "{return test(\"%3.7i\", -2375);}"},
	{1, 217, "i_prec_width_nofit_nofit_pos", i_prec_width_nofit_nofit_pos, i_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3i\", 6983);}"},
	{1, 218, "i_prec_width_nofit_nofit_neg", i_prec_width_nofit_nofit_neg, i_prec_width_nofit_nofit_neg_bench, "{return test(\"%3.3i\", -8462);}"},
	{1, 219, "i_prec_width_fit_fit_pos_lj", i_prec_width_fit_fit_pos_lj, i_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5i\", 34);}"},
	{1, 220, "i_prec_width_fit_fit_neg_lj", i_prec_width_fit_fit_neg_lj, i_prec_width_fit_fit_neg_lj_bench, "{return test(\"%-10.5i\", -216);}"},
	{1, 221, "i_prec_width_fit_fit_zero_lj", i_prec_width_fit_fit_zero_lj, i_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5i\", 0);}"},
	{1, 222, "i_prec_width_nofit_fit_pos_lj", i_prec_width_nofit_fit_pos_lj, i_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3i\", 8375);}"},
	{1, 223, "i_prec_width_nofit_fit_neg_lj", i_prec_width_nofit_fit_neg_lj, i_prec_width_nofit_fit_neg_lj_bench, "{return test(\"%-8.3i\", -8473);}"},
	{1, 224, "i_prec_width_fit_nofit_pos_lj", i_prec_width_fit_nofit_pos_lj, i_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-3.7i\", 3267);}"},
	{1, 225, "i_prec_width_fit_nofit_neg_lj", i_prec_width_fit_nofit_neg_lj, i_prec_width_fit_nofit_neg_lj_bench, "{return test(\"%-3.7i\", -2375);}"},
	{1, 226, "i_prec_width_nofit_nofit_pos_lj", i_prec_width_nofit_nofit_pos_lj, i_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3i\", 6983);}"},
	{1, 227, "i_prec_width_nofit_nofit_neg_lj", i_prec_width_nofit_nofit_neg_lj, i_prec_width_nofit_nofit_neg_lj_bench, "{return test(\"%-3.3i\", -8462);}"},
	{1, 228, "i_prec_width_fit_fit_pos_as", i_prec_width_fit_fit_pos_as, i_prec_width_fit_fit_pos_as_bench, "{return test(\"%+8.5i\", 34);}"},
	{1, 229, "i_prec_width_fit_fit_neg_as", i_prec_width_fit_fit_neg_as, i_prec_width_fit_fit_neg_as_bench, "{return test(\"%+10.5i\", -216);}"},
	{1, 230, "i_prec_width_fit_fit_zero_as", i_prec_width_fit_fit_zero_as, i_prec_width_fit_fit_zero_as_bench, "{return test(\"%+8.5i\", 0);}"},
	{1, 231, "i_prec_width_nofit_fit_pos_as", i_prec_width_nofit_fit_pos_as, i_prec_width_nofit_fit_pos_as_bench, "{return test(\"%+8.3i\", 8375);}"},
	{1, 232, "i_prec_width_nofit_fit_neg_as", i_prec_width_nofit_fit_neg_as, i_prec_width_nofit_fit_neg_as_bench, "{return test(\"%+8.3i\", -8473);}"},
	{1, 233, "i_prec_width_fit_nofit_pos_as", i_prec_width_fit_nofit_pos_as, i_prec_width_fit_nofit_pos_as_bench, "{return test(\"%+3.7i\", 3267);}"},
	{1, 234, "i_prec_width_fit_nofit_neg_as", i_prec_width_fit_nofit_neg_as, i_prec_width_fit_nofit_neg_as_bench, "{return test(\"%+3.7i\", -2375);}"},
	{1, 235, "i_prec_width_nofit_nofit_pos_as", i_prec_width_nofit_nofit_pos_as, i_prec_width_nofit_nofit_pos_as_bench, "{return test(\"%+3.3i\", 6983);}"},
	{1, 236, "i_prec_width_nofit_nofit_neg_as", i_prec_width_nofit_nofit_neg_as, i_prec_width_nofit_nofit_neg_as_bench, "{return test(\"%+3.3i\", -8462);}"},
	{1, 237, "i_prec_width_fit_fit_pos_ljas", i_prec_width_fit_fit_pos_ljas, i_prec_width_fit_fit_pos_ljas_bench, "{return test(\"%+-8.5i\", 34);}"},
	{1, 238, "i_prec_width_fit_fit_neg_ljas", i_prec_width_fit_fit_neg_ljas, i_prec_width_fit_fit_neg_ljas_bench, "{return test(\"%+-10.5i\", -216);}"},
	{1, 239, "i_prec_width_fit_fit_zero_ljas", i_prec_width_fit_fit_zero_ljas, i_prec_width_fit_fit_zero_ljas_bench, "{return test(\"%+-8.5i\", 0);}"},
	{1, 240, "i_prec_width_nofit_fit_pos_ljas", i_prec_width_nofit_fit_pos_ljas, i_prec_width_nofit_fit_pos_ljas_bench, "{return test(\"%+-8.3i\", 8375);}"},
	{1, 241, "i_prec_width_nofit_fit_neg_ljas", i_prec_width_nofit_fit_neg_ljas, i_prec_width_nofit_fit_neg_ljas_bench, "{return test(\"%+-8.3i\", -8473);}"},
	{1, 242, "i_prec_width_fit_nofit_pos_ljas", i_prec_width_fit_nofit_pos_ljas, i_prec_width_fit_nofit_pos_ljas_bench, "{return test(\"%+-3.7i\", 3267);}"},
	{1, 243, "i_prec_width_fit_nofit_neg_ljas", i_prec_width_fit_nofit_neg_ljas, i_prec_width_fit_nofit_neg_ljas_bench, "{return test(\"%+-3.7i\", -2375);}"},
	{1, 244, "i_prec_width_nofit_nofit_pos_ljas", i_prec_width_nofit_nofit_pos_ljas, i_prec_width_nofit_nofit_pos_ljas_bench, "{return test(\"%+-3.3i\", 6983);}"},
	{1, 245, "i_prec_width_nofit_nofit_neg_ljas", i_prec_width_nofit_nofit_neg_ljas, i_prec_width_nofit_nofit_neg_ljas_bench, "{return test(\"%+-3.3i\", -8462);}"},
	{1, 246, "i_prec_width_ff_pos_zp", i_prec_width_ff_pos_zp, i_prec_width_ff_pos_zp_bench, "{return test(\"%08.5i\", 34);}"},
	{1, 247, "i_prec_width_ff_neg_zp", i_prec_width_ff_neg_zp, i_prec_width_ff_neg_zp_bench, "{return test(\"%010.5i\", -216);}"},
	{1, 248, "i_prec_width_ff_zero_zp", i_prec_width_ff_zero_zp, i_prec_width_ff_zero_zp_bench, "{return test(\"%08.5i\", 0);}"},
	{1, 249, "i_prec_width_nf_pos_zp", i_prec_width_nf_pos_zp, i_prec_width_nf_pos_zp_bench, "{return test(\"%08.3i\", 8375);}"},
	{1, 250, "i_prec_width_nf_neg_zp", i_prec_width_nf_neg_zp, i_prec_width_nf_neg_zp_bench, "{return test(\"%08.3i\", -8473);}"},
	{1, 251, "i_prec_width_fn_pos_zp", i_prec_width_fn_pos_zp, i_prec_width_fn_pos_zp_bench, "{return test(\"%03.7i\", 3267);}"},
	{1, 252, "i_prec_width_fn_neg_zp", i_prec_width_fn_neg_zp, i_prec_width_fn_neg_zp_bench, "{return test(\"%03.7i\", -2375);}"},
	{1, 253, "i_prec_width_nn_pos_zp", i_prec_width_nn_pos_zp, i_prec_width_nn_pos_zp_bench, "{return test(\"%03.3i\", 6983);}"},
	{1, 254, "i_prec_width_nn_neg_zp", i_prec_width_nn_neg_zp, i_prec_width_nn_neg_zp_bench, "{return test(\"%03.3i\", -8462);}"},
	{1, 255, "i_prec_width_ff_pos_lj_zp_ignoreflag", i_prec_width_ff_pos_lj_zp_ignoreflag, i_prec_width_ff_pos_lj_zp_ignoreflag_bench, "{return test(\"%0-8.5i\", 34);}"},
	{1, 256, "i_prec_width_ff_neg_ljzp_ignoreflag", i_prec_width_ff_neg_ljzp_ignoreflag, i_prec_width_ff_neg_ljzp_ignoreflag_bench, "{return test(\"%0-10.5i\", -216);}"},
	{1, 257, "i_prec_width_ff_zero_ljzp_ignoreflag", i_prec_width_ff_zero_ljzp_ignoreflag, i_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5i\", 0);}"},
	{1, 258, "i_prec_width_nf_pos_ljzp_ignoreflag", i_prec_width_nf_pos_ljzp_ignoreflag, i_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3i\", 8375);}"},
	{1, 259, "i_prec_width_nf_neg_ljzp_ignoreflag", i_prec_width_nf_neg_ljzp_ignoreflag, i_prec_width_nf_neg_ljzp_ignoreflag_bench, "{return test(\"%0-8.3i\", -8473);}"},
	{1, 260, "i_prec_width_fn_pos_ljzp_ignoreflag", i_prec_width_fn_pos_ljzp_ignoreflag, i_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.7i\", 3267);}"},
	{1, 261, "i_prec_width_fn_neg_ljzp_ignoreflag", i_prec_width_fn_neg_ljzp_ignoreflag, i_prec_width_fn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.7i\", -2375);}"},
	{1, 262, "i_prec_width_nn_pos_ljzp_ignoreflag", i_prec_width_nn_pos_ljzp_ignoreflag, i_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3i\", 6983);}"},
	{1, 263, "i_prec_width_nn_neg_ljzp_ignoreflag", i_prec_width_nn_neg_ljzp_ignoreflag, i_prec_width_nn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.3i\", -8462);}"},
	{1, 264, "i_prec_width_ff_pos_aszp", i_prec_width_ff_pos_aszp, i_prec_width_ff_pos_aszp_bench, "{return test(\"%0+8.5i\", 34);}"},
	{1, 265, "i_prec_width_ff_neg_aszp", i_prec_width_ff_neg_aszp, i_prec_width_ff_neg_aszp_bench, "{return test(\"%0+10.5i\", -216);}"},
	{1, 266, "i_prec_width_ff_zero_aszp", i_prec_width_ff_zero_aszp, i_prec_width_ff_zero_aszp_bench, "{return test(\"%0+8.5i\", 0);}"},
	{1, 267, "i_prec_width_nf_pos_aszp", i_prec_width_nf_pos_aszp, i_prec_width_nf_pos_aszp_bench, "{return test(\"%0+8.3i\", 8375);}"},
	{1, 268, "i_prec_width_nf_neg_aszp", i_prec_width_nf_neg_aszp, i_prec_width_nf_neg_aszp_bench, "{return test(\"%0+8.3i\", -8473);}"},
	{1, 269, "i_prec_width_fn_pos_aszp", i_prec_width_fn_pos_aszp, i_prec_width_fn_pos_aszp_bench, "{return test(\"%0+3.7i\", 3267);}"},
	{1, 270, "i_prec_width_fn_neg_aszp", i_prec_width_fn_neg_aszp, i_prec_width_fn_neg_aszp_bench, "{return test(\"%0+3.7i\", -2375);}"},
	{1, 271, "i_prec_width_nn_pos_aszp", i_prec_width_nn_pos_aszp, i_prec_width_nn_pos_aszp_bench, "{return test(\"%0+3.3i\", 6983);}"},
	{1, 272, "i_prec_width_nn_neg_aszp", i_prec_width_nn_neg_aszp, i_prec_width_nn_neg_aszp_bench, "{return test(\"%0+3.3i\", -8462);}"},
	{1, 273, "i_prec_width_ff_pos_ljaszp_ignoreflag", i_prec_width_ff_pos_ljaszp_ignoreflag, i_prec_width_ff_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.5i\", 34);}"},
	{1, 274, "i_prec_width_ff_neg_ljaszp_ignoreflag", i_prec_width_ff_neg_ljaszp_ignoreflag, i_prec_width_ff_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-10.5i\", -216);}"},
	{1, 275, "i_prec_width_ff_zero_ljaszp_ignoreflag", i_prec_width_ff_zero_ljaszp_ignoreflag, i_prec_width_ff_zero_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.5i\", 0);}"},
	{1, 276, "i_prec_width_nf_pos_ljaszp_ignoreflag", i_prec_width_nf_pos_ljaszp_ignoreflag, i_prec_width_nf_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.3i\", 8375);}"},
	{1, 277, "i_prec_width_nf_neg_ljaszp_ignoreflag", i_prec_width_nf_neg_ljaszp_ignoreflag, i_prec_width_nf_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.3i\", -8473);}"},
	{1, 278, "i_prec_width_fn_pos_ljaszp_ignoreflag", i_prec_width_fn_pos_ljaszp_ignoreflag, i_prec_width_fn_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.7i\", 3267);}"},
	{1, 279, "i_prec_width_fn_neg_ljaszp_ignoreflag", i_prec_width_fn_neg_ljaszp_ignoreflag, i_prec_width_fn_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.7i\", -2375);}"},
	{1, 280, "i_prec_width_nn_pos_ljaszp_ignoreflag", i_prec_width_nn_pos_ljaszp_ignoreflag, i_prec_width_nn_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.3i\", 6983);}"},
	{1, 281, "i_prec_width_nn_neg_ljaszp_ignoreflag", i_prec_width_nn_neg_ljaszp_ignoreflag, i_prec_width_nn_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.3i\", -8462);}"},
	{1, 282, "i_size_hh_pos_casted", i_size_hh_pos_casted, i_size_hh_pos_casted_bench, "{return test(\"%hhi\", (char)45);}"},
	{1, 283, "i_size_hh_neg_casted", i_size_hh_neg_casted, i_size_hh_neg_casted_bench, "{return test(\"%hhi\", (char)-45);}"},
	{1, 284, "i_size_h_pos_casted", i_size_h_pos_casted, i_size_h_pos_casted_bench, "{return test(\"%hi\", (short)385);}"},
	{1, 285, "i_size_h_neg_casted", i_size_h_neg_casted, i_size_h_neg_casted_bench, "{return test(\"%hi\", (short)-385);}"},
	{1, 286, "i_size_l_pos_casted", i_size_l_pos_casted, i_size_l_pos_casted_bench, "{return test(\"%li\", (long)32);}"},
	{1, 287, "i_size_l_neg_casted", i_size_l_neg_casted, i_size_l_neg_casted_bench, "{return test(\"%li\", (long)-32);}"},
	{1, 288, "i_size_ll_pos_casted", i_size_ll_pos_casted, i_size_ll_pos_casted_bench, "{return test(\"%lli\", (long long)43);}"},
	{1, 289, "i_size_ll_neg_casted", i_size_ll_neg_casted, i_size_ll_neg_casted_bench, "{return test(\"%lli\", (long long)-43);}"},
	{1, 290, "i_size_hh_pos_ref", i_size_hh_pos_ref, i_size_hh_pos_ref_bench, "{return test(\"%hhi\", ch_pos_1);}"},
	{1, 291, "i_size_hh_neg_ref", i_size_hh_neg_ref, i_size_hh_neg_ref_bench, "{return test(\"%hhi\", ch_neg_1);}"},
	{1, 292, "i_size_h_pos_ref", i_size_h_pos_ref, i_size_h_pos_ref_bench, "{return test(\"%hi\", sh_pos_1);}"},
	{1, 293, "i_size_h_neg_ref", i_size_h_neg_ref, i_size_h_neg_ref_bench, "{return test(\"%hi\", sh_neg_1);}"},
	{1, 294, "i_size_l_pos_ref", i_size_l_pos_ref, i_size_l_pos_ref_bench, "{return test(\"%li\", l_pos_1);}"},
	{1, 295, "i_size_l_pos_ref_lmax", i_size_l_pos_ref_lmax, i_size_l_pos_ref_lmax_bench, "{return test(\"%li\", lmax);}"},
	{1, 296, "i_size_ll_pos_ref_llmax", i_size_ll_pos_ref_llmax, i_size_ll_pos_ref_llmax_bench, "{return test(\"%lli\", llmax);}"},
	{1, 297, "i_size_l_neg_ref", i_size_l_neg_ref, i_size_l_neg_ref_bench, "{return test(\"%li\", l_neg_1);}"},
	{1, 298, "i_size_ll_pos_ref", i_size_ll_pos_ref, i_size_ll_pos_ref_bench, "{return test(\"%lli\", ll_pos_1);}"},
	{1, 299, "i_size_ll_neg_ref", i_size_ll_neg_ref, i_size_ll_neg_ref_bench, "{return test(\"%lli\", ll_neg_1);}"},
	{1, 300, "i_size_l_pos_big", i_size_l_pos_big, i_size_l_pos_big_bench, "{return test(\"%li\", 22337203685477);}"},
	{1, 301, "i_size_l_neg_big", i_size_l_neg_big, i_size_l_neg_big_bench, "{return test(\"%li\", -22337203685477);}"},
	{1, 302, "i_size_ll_pos_big", i_size_ll_pos_big, i_size_ll_pos_big_bench, "{return test(\"%lli\", 522337203685470ll);}"},
	{1, 303, "i_size_ll_neg_big", i_size_ll_neg_big, i_size_ll_neg_big_bench, "{return test(\"%lli\", -522337203685470ll);}"},
	{1, 304, "i_llmax", i_llmax, i_llmax_bench, "{return test(\"%lli\", 9223372036854775807ll);}"},
	{1, 305, "i_llmin", i_llmin, i_llmin_bench, "{return test(\"%lli\", llmin);}"},
	{1, 306, "i_lmax", i_lmax, i_lmax_bench, "{return test(\"%li\", 9223372036854775807l);}"},
	{1, 307, "i_lmin", i_lmin, i_lmin_bench, "{return test(\"%li\", lmin);}"},
	{1, 308, "i_hmax", i_hmax, i_hmax_bench, "{return test(\"%hi\", (short)32767);}"},
	{1, 309, "i_hmin", i_hmin, i_hmin_bench, "{return test(\"%hi\", (short)(-32768));}"},
	{1, 310, "i_hhmax", i_hhmax, i_hhmax_bench, "{return test(\"%hhi\", (char)127);}"},
	{1, 311, "i_hhmin", i_hhmin, i_hhmin_bench, "{return test(\"%hhi\", (char)(-128));}"},
	{1, 312, "i_size_l_pos_big_zp", i_size_l_pos_big_zp, i_size_l_pos_big_zp_bench, "{return test(\"%037li\", 22337203685477l);}"},
	{1, 313, "i_size_l_neg_big_prec", i_size_l_neg_big_prec, i_size_l_neg_big_prec_bench, "{return test(\"%.37li\", -22337203685477l);}"},
	{1, 314, "i_size_ll_pos_big_width", i_size_ll_pos_big_width, i_size_ll_pos_big_width_bench, "{return test(\"%37lli\", 522337203685470ll);}"},
	{1, 315, "i_size_ll_neg_big_lj", i_size_ll_neg_big_lj, i_size_ll_neg_big_lj_bench, "{return test(\"%-37lli\", -522337203685470ll);}"},
	{1, 316, "i_size_l_pos_big_as", i_size_l_pos_big_as, i_size_l_pos_big_as_bench, "{return test(\"%+li\", 22337203685477l);}"},
	{1, 317, "i_size_follows_i_i", i_size_follows_i_i, i_size_follows_i_i_bench, "{return test(\"[%i] [%i]\", i_pos_1, i_pos_1);}"},
	{1, 318, "i_size_follows_i_l", i_size_follows_i_l, i_size_follows_i_l_bench, "{return test(\"[%i] [%li]\", i_pos_1, l_pos_1);}"},
	{1, 319, "i_size_follows_i_ll", i_size_follows_i_ll, i_size_follows_i_ll_bench, "{return test(\"[%i] [%lli]\", i_pos_1, ll_pos_1);}"},
	{1, 320, "i_size_follows_i_h", i_size_follows_i_h, i_size_follows_i_h_bench, "{return test(\"[%i] [%hi]\", i_pos_1, sh_pos_1);}"},
	{1, 321, "i_size_follows_i_hh", i_size_follows_i_hh, i_size_follows_i_hh_bench, "{return test(\"[%i] [%hhi]\", i_pos_1, ch_pos_1);}"},
	{1, 322, "i_size_ll_hh_ll", i_size_ll_hh_ll, i_size_ll_hh_ll_bench, "{return test(\"%lli%hhi%lli\", ll_pos_1, ch_neg_1, ll_neg_1);}"},
	{1, 323, "i_size_h_l_hh", i_size_h_l_hh, i_size_h_l_hh_bench, "{return test(\"%hi%li%hhi\", sh_pos_1, l_neg_1, ch_neg_1);}"},
	{1, 324, "i_size_l_hh_h", i_size_l_hh_h, i_size_l_hh_h_bench, "{return test(\"%li%hhi%hi\", l_neg_1, ch_pos_1, sh_pos_1);}"},
	{1, 325, "i_size_n_ll_hh", i_size_n_ll_hh, i_size_n_ll_hh_bench, "{return test(\"%i%lli%hhi\", i_pos_1, ll_neg_1, ch_pos_1);}"},
	{1, 326, "i_size_ll_n_l", i_size_ll_n_l, i_size_ll_n_l_bench, "{return test(\"%lli%i%li\", ll_neg_1, i_pos_1, l_pos_1);}"},
	{1, 327, "i_basic_i_pos_sp", i_basic_i_pos_sp, i_basic_i_pos_sp_bench, "{return test(\"this % i number\", 17);}"},
	{1, 328, "i_basic_i_neg_sp", i_basic_i_neg_sp, i_basic_i_neg_sp_bench, "{return test(\"this % i number\", -267);}"},
	{1, 329, "i_basic_i_zero_sp", i_basic_i_zero_sp, i_basic_i_zero_sp_bench, "{return test(\"this % i number\", 0);}"},
	{1, 330, "i_basic_i_onlypos_sp", i_basic_i_onlypos_sp, i_basic_i_onlypos_sp_bench, "{return test(\"% i\", 3);}"},
	{1, 331, "i_basic_i_onlyneg_sp", i_basic_i_onlyneg_sp, i_basic_i_onlyneg_sp_bench, "{return test(\"% i\", -1);}"},
	{1, 332, "i_basic_i_onlyzero_sp", i_basic_i_onlyzero_sp, i_basic_i_onlyzero_sp_bench, "{return test(\"% i\", 0);}"},
	{1, 333, "i_basic_i_pos_d_sp", i_basic_i_pos_d_sp, i_basic_i_pos_d_sp_bench, "{return test(\"this % d number\", 17);}"},
	{1, 334, "i_basic_i_neg_d_sp", i_basic_i_neg_d_sp, i_basic_i_neg_d_sp_bench, "{return test(\"this % d number\", -267);}"},
	{1, 335, "i_basic_i_zero_d_sp", i_basic_i_zero_d_sp, i_basic_i_zero_d_sp_bench, "{return test(\"this % d number\", 0);}"},
	{1, 336, "i_intmax_sp", i_intmax_sp, i_intmax_sp_bench, "{return test(\"% i\", 2147483647);}"},
	{1, 337, "i_intmin_sp", i_intmin_sp, i_intmin_sp_bench, "{return test(\"% i\", (int)(-2147483678));}"},
	{1, 338, "i_assp_pos_ignoreflag", i_assp_pos_ignoreflag, i_assp_pos_ignoreflag_bench, "{return test(\"% +i\", 5);}"},
	{1, 339, "i_assp_neg_ignoreflag", i_assp_neg_ignoreflag, i_assp_neg_ignoreflag_bench, "{return test(\"% +i\", -7);}"},
	{1, 340, "i_intmax_assp_ignoreflag", i_intmax_assp_ignoreflag, i_intmax_assp_ignoreflag_bench, "{return test(\"% +i\", 2147483647);}"},
	{1, 341, "i_width_pos_fits_sp", i_width_pos_fits_sp, i_width_pos_fits_sp_bench, "{return test(\"% 7i\", 33);}"},
	{1, 342, "i_width_neg_fits_sp", i_width_neg_fits_sp, i_width_neg_fits_sp_bench, "{return test(\"% 7i\", -14);}"},
	{1, 343, "i_width_zero_fits_sp", i_width_zero_fits_sp, i_width_zero_fits_sp_bench, "{return test(\"% 3i\", 0);}"},
	{1, 344, "i_width_pos_exactfit_sp", i_width_pos_exactfit_sp, i_width_pos_exactfit_sp_bench, "{return test(\"% 5i\", 52625);}"},
	{1, 345, "i_width_neg_exactfit_sp", i_width_neg_exactfit_sp, i_width_neg_exactfit_sp_bench, "{return test(\"% 5i\", -2562);}"},
	{1, 346, "i_width_pos_nofit_sp", i_width_pos_nofit_sp, i_width_pos_nofit_sp_bench, "{return test(\"% 4i\", 94827);}"},
	{1, 347, "i_width_neg_nofit_sp", i_width_neg_nofit_sp, i_width_neg_nofit_sp_bench, "{return test(\"% 4i\", -2464);}"},
	{1, 348, "i_width_pos_fits_lj_sp", i_width_pos_fits_lj_sp, i_width_pos_fits_lj_sp_bench, "{return test(\"% -7i\", 33);}"},
	{1, 349, "i_width_neg_fits_lj_sp", i_width_neg_fits_lj_sp, i_width_neg_fits_lj_sp_bench, "{return test(\"% -7i\", -14);}"},
	{1, 350, "i_width_zero_fits_lj_sp", i_width_zero_fits_lj_sp, i_width_zero_fits_lj_sp_bench, "{return test(\"% -3i\", 0);}"},
	{1, 351, "i_width_pos_exactfit_lj_sp", i_width_pos_exactfit_lj_sp, i_width_pos_exactfit_lj_sp_bench, "{return test(\"% -5i\", 52625);}"},
	{1, 352, "i_width_neg_exactfit_lj_sp", i_width_neg_exactfit_lj_sp, i_width_neg_exactfit_lj_sp_bench, "{return test(\"% -5i\", -2562);}"},
	{1, 353, "i_width_pos_nofit_lj_sp", i_width_pos_nofit_lj_sp, i_width_pos_nofit_lj_sp_bench, "{return test(\"% -4i\", 94827);}"},
	{1, 354, "i_width_neg_nofit_lj_sp", i_width_neg_nofit_lj_sp, i_width_neg_nofit_lj_sp_bench, "{return test(\"% -4i\", -2464);}"},
	{1, 355, "i_width_assp_pos_ignoreflag", i_width_assp_pos_ignoreflag, i_width_assp_pos_ignoreflag_bench, "{return test(\"% +5i\", 35);}"},
	{1, 356, "i_width_assp_zero_ignoreflag", i_width_assp_zero_ignoreflag, i_width_assp_zero_ignoreflag_bench, "{return test(\"% +7i\", 0);}"},
	{1, 357, "i_width_intmax_assp_ignoreflag", i_width_intmax_assp_ignoreflag, i_width_intmax_assp_ignoreflag_bench, "{return test(\"% +24i\", 2147483647);}"},
	{1, 358, "i_prec_fits_pos_sp", i_prec_fits_pos_sp, i_prec_fits_pos_sp_bench, "{return test(\"% .5i\", 2);}"},
	{1, 359, "i_prec_fits_neg_sp", i_prec_fits_neg_sp, i_prec_fits_neg_sp_bench, "{return test(\"% .6i\", -3);}"},
	{1, 360, "i_prec_fits_zero_sp", i_prec_fits_zero_sp, i_prec_fits_zero_sp_bench, "{return test(\"% .3i\", 0);}"},
	{1, 361, "i_prec_exactfit_pos_sp", i_prec_exactfit_pos_sp, i_prec_exactfit_pos_sp_bench, "{return test(\"% .4i\", 5263);}"},
	{1, 362, "i_prec_exactfit_neg_sp", i_prec_exactfit_neg_sp, i_prec_exactfit_neg_sp_bench, "{return test(\"% .4i\", -2372);}"},
	{1, 363, "i_prec_nofit_pos_sp", i_prec_nofit_pos_sp, i_prec_nofit_pos_sp_bench, "{return test(\"% .3i\", 13862);}"},
	{1, 364, "i_prec_nofit_neg_sp", i_prec_nofit_neg_sp, i_prec_nofit_neg_sp_bench, "{return test(\"% .3i\",-23646);}"},
	{1, 365, "i_prec_assp_pos_ignoreflag", i_prec_assp_pos_ignoreflag, i_prec_assp_pos_ignoreflag_bench, "{return test(\"% +.7i\", 234);}"},
	{1, 366, "i_prec_assp_neg_ignoreflag", i_prec_assp_neg_ignoreflag, i_prec_assp_neg_ignoreflag_bench, "{return test(\"% +.7i\", -446);}"},
	{1, 367, "i_prec_assp_pos_nofit_ignoreflag", i_prec_assp_pos_nofit_ignoreflag, i_prec_assp_pos_nofit_ignoreflag_bench, "{return test(\"% +.3i\", 3723);}"},
	{1, 368, "i_zpsp_pos_fits", i_zpsp_pos_fits, i_zpsp_pos_fits_bench, "{return test(\"% 05i\", 43);}"},
	{1, 369, "i_zpsp_neg_fits", i_zpsp_neg_fits, i_zpsp_neg_fits_bench, "{return test(\"% 07i\", -54);}"},
	{1, 370, "i_zpsp_zero_fits", i_zpsp_zero_fits, i_zpsp_zero_fits_bench, "{return test(\"% 03i\", 0);}"},
	{1, 371, "i_zpsp_pos_exactfit", i_zpsp_pos_exactfit, i_zpsp_pos_exactfit_bench, "{return test(\"% 03i\", 634);}"},
	{1, 372, "i_zpsp_neg_exactfit", i_zpsp_neg_exactfit, i_zpsp_neg_exactfit_bench, "{return test(\"% 04i\", -532);}"},
	{1, 373, "i_zpsp_neg_minus1fit", i_zpsp_neg_minus1fit, i_zpsp_neg_minus1fit_bench, "{return test(\"% 04i\", -4825);}"},
	{1, 374, "i_zpassp_as_fits_ignoreflag", i_zpassp_as_fits_ignoreflag, i_zpassp_as_fits_ignoreflag_bench, "{return test(\"% +05i\", 432);}"},
	{1, 375, "i_zpassp_zero_ignoreflag", i_zpassp_zero_ignoreflag, i_zpassp_zero_ignoreflag_bench, "{return test(\"% +04i\", 0);}"},
	{1, 376, "i_prec_width_fit_fit_pos_sp", i_prec_width_fit_fit_pos_sp, i_prec_width_fit_fit_pos_sp_bench, "{return test(\"% 8.5i\", 34);}"},
	{1, 377, "i_prec_width_fit_fit_neg_sp", i_prec_width_fit_fit_neg_sp, i_prec_width_fit_fit_neg_sp_bench, "{return test(\"% 10.5i\", -216);}"},
	{1, 378, "i_prec_width_fit_fit_zero_sp", i_prec_width_fit_fit_zero_sp, i_prec_width_fit_fit_zero_sp_bench, "{return test(\"% 8.5i\", 0);}"},
	{1, 379, "i_prec_width_nofit_fit_pos_sp", i_prec_width_nofit_fit_pos_sp, i_prec_width_nofit_fit_pos_sp_bench, "{return test(\"% 8.3i\", 8375);}"},
	{1, 380, "i_prec_width_nofit_fit_neg_sp", i_prec_width_nofit_fit_neg_sp, i_prec_width_nofit_fit_neg_sp_bench, "{return test(\"% 8.3i\", -8473);}"},
	{1, 381, "i_prec_width_fit_nofit_pos_sp", i_prec_width_fit_nofit_pos_sp, i_prec_width_fit_nofit_pos_sp_bench, "{return test(\"% 3.7i\", 3267);}"},
	{1, 382, "i_prec_width_fit_nofit_neg_sp", i_prec_width_fit_nofit_neg_sp, i_prec_width_fit_nofit_neg_sp_bench, "{return test(\"% 3.7i\", -2375);}"},
	{1, 383, "i_prec_width_nofit_nofit_pos_sp", i_prec_width_nofit_nofit_pos_sp, i_prec_width_nofit_nofit_pos_sp_bench, "{return test(\"% 3.3i\", 6983);}"},
	{1, 384, "i_prec_width_nofit_nofit_neg_sp", i_prec_width_nofit_nofit_neg_sp, i_prec_width_nofit_nofit_neg_sp_bench, "{return test(\"% 3.3i\", -8462);}"},
	{1, 385, "i_prec_width_fit_fit_pos_lj_sp", i_prec_width_fit_fit_pos_lj_sp, i_prec_width_fit_fit_pos_lj_sp_bench, "{return test(\"% -8.5i\", 34);}"},
	{1, 386, "i_prec_width_fit_fit_neg_lj_sp", i_prec_width_fit_fit_neg_lj_sp, i_prec_width_fit_fit_neg_lj_sp_bench, "{return test(\"% -10.5i\", -216);}"},
	{1, 387, "i_prec_width_fit_fit_zero_lj_sp", i_prec_width_fit_fit_zero_lj_sp, i_prec_width_fit_fit_zero_lj_sp_bench, "{return test(\"% -8.5i\", 0);}"},
	{1, 388, "i_prec_width_nofit_fit_pos_lj_sp", i_prec_width_nofit_fit_pos_lj_sp, i_prec_width_nofit_fit_pos_lj_sp_bench, "{return test(\"% -8.3i\", 8375);}"},
	{1, 389, "i_prec_width_nofit_fit_neg_lj_sp", i_prec_width_nofit_fit_neg_lj_sp, i_prec_width_nofit_fit_neg_lj_sp_bench, "{return test(\"% -8.3i\", -8473);}"},
	{1, 390, "i_prec_width_fit_nofit_pos_lj_sp", i_prec_width_fit_nofit_pos_lj_sp, i_prec_width_fit_nofit_pos_lj_sp_bench, "{return test(\"% -3.7i\", 3267);}"},
	{1, 391, "i_prec_width_fit_nofit_neg_lj_sp", i_prec_width_fit_nofit_neg_lj_sp, i_prec_width_fit_nofit_neg_lj_sp_bench, "{return test(\"% -3.7i\", -2375);}"},
	{1, 392, "i_prec_width_nofit_nofit_pos_lj_sp", i_prec_width_nofit_nofit_pos_lj_sp, i_prec_width_nofit_nofit_pos_lj_sp_bench, "{return test(\"% -3.3i\", 6983);}"},
	{1, 393, "i_prec_width_nofit_nofit_neg_lj_sp", i_prec_width_nofit_nofit_neg_lj_sp, i_prec_width_nofit_nofit_neg_lj_sp_bench, "{return test(\"% -3.3i\", -8462);}"},
	{1, 394, "i_prec_width_fit_fit_pos_assp_ignoreflag", i_prec_width_fit_fit_pos_assp_ignoreflag, i_prec_width_fit_fit_pos_assp_ignoreflag_bench, "{return test(\"% +8.5i\", 34);}"},
	{1, 395, "i_prec_width_fit_fit_neg_assp_ignoreflag", i_prec_width_fit_fit_neg_assp_ignoreflag, i_prec_width_fit_fit_neg_assp_ignoreflag_bench, "{return test(\"% +10.5i\", -216);}"},
	{1, 396, "i_prec_width_fit_fit_zero_assp_ignoreflag", i_prec_width_fit_fit_zero_assp_ignoreflag, i_prec_width_fit_fit_zero_assp_ignoreflag_bench, "{return test(\"% +8.5i\", 0);}"},
	{1, 397, "i_prec_width_nofit_fit_pos_assp_ignoreflag", i_prec_width_nofit_fit_pos_assp_ignoreflag, i_prec_width_nofit_fit_pos_assp_ignoreflag_bench, "{return test(\"% +8.3i\", 8375);}"},
	{1, 398, "i_prec_width_nofit_fit_neg_assp_ignoreflag", i_prec_width_nofit_fit_neg_assp_ignoreflag, i_prec_width_nofit_fit_neg_assp_ignoreflag_bench, "{return test(\"% +8.3i\", -8473);}"},
	{1, 399, "i_prec_width_fit_nofit_pos_assp_ignoreflag", i_prec_width_fit_nofit_pos_assp_ignoreflag, i_prec_width_fit_nofit_pos_assp_ignoreflag_bench, "{return test(\"% +3.7i\", 3267);}"},
	{1, 400, "i_prec_width_fit_nofit_neg_assp_ignoreflag", i_prec_width_fit_nofit_neg_assp_ignoreflag, i_prec_width_fit_nofit_neg_assp_ignoreflag_bench, "{return test(\"% +3.7i\", -2375);}"},
	{1, 401, "i_prec_width_nofit_nofit_pos_assp_ignoreflag", i_prec_width_nofit_nofit_pos_assp_ignoreflag, i_prec_width_nofit_nofit_pos_assp_ignoreflag_bench, "{return test(\"% +3.3i\", 6983);}"},
	{1, 402, "i_prec_width_nofit_nofit_neg_assp_ignoreflag", i_prec_width_nofit_nofit_neg_assp_ignoreflag, i_prec_width_nofit_nofit_neg_assp_ignoreflag_bench, "{return test(\"% +3.3i\", -8462);}"},
	{1, 403, "i_prec_width_fit_fit_pos_lj_assp_ignoreflag", i_prec_width_fit_fit_pos_lj_assp_ignoreflag, i_prec_width_fit_fit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-8.5i\", 34);}"},
	{1, 404, "i_prec_width_fit_fit_neg_lj_assp_ignoreflag", i_prec_width_fit_fit_neg_lj_assp_ignoreflag, i_prec_width_fit_fit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-10.5i\", -216);}"},
	{1, 405, "i_prec_width_fit_fit_zero_lj_assp_ignoreflag", i_prec_width_fit_fit_zero_lj_assp_ignoreflag, i_prec_width_fit_fit_zero_lj_assp_ignoreflag_bench, "{return test(\"% +-8.5i\", 0);}"},
	{1, 406, "i_prec_width_nofit_fit_pos_lj_assp_ignoreflag", i_prec_width_nofit_fit_pos_lj_assp_ignoreflag, i_prec_width_nofit_fit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-8.3i\", 8375);}"},
	{1, 407, "i_prec_width_nofit_fit_neg_lj_assp_ignoreflag", i_prec_width_nofit_fit_neg_lj_assp_ignoreflag, i_prec_width_nofit_fit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-8.3i\", -8473);}"},
	{1, 408, "i_prec_width_fit_nofit_pos_lj_assp_ignoreflag", i_prec_width_fit_nofit_pos_lj_assp_ignoreflag, i_prec_width_fit_nofit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-3.7i\", 3267);}"},
	{1, 409, "i_prec_width_fit_nofit_neg_lj_assp_ignoreflag", i_prec_width_fit_nofit_neg_lj_assp_ignoreflag, i_prec_width_fit_nofit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-3.7i\", -2375);}"},
	{1, 410, "i_prec_width_nofit_nofit_pos_lj_assp_ignoreflag", i_prec_width_nofit_nofit_pos_lj_assp_ignoreflag, i_prec_width_nofit_nofit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-3.3i\", 6983);}"},
	{1, 411, "i_prec_width_nofit_nofit_neg_lj_assp_ignoreflag", i_prec_width_nofit_nofit_neg_lj_assp_ignoreflag, i_prec_width_nofit_nofit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-3.3i\", -8462);}"},
	{1, 412, "i_prec_width_ff_pos_zp_sp", i_prec_width_ff_pos_zp_sp, i_prec_width_ff_pos_zp_sp_bench, "{return test(\"% 08.5i\", 34);}"},
	{1, 413, "i_prec_width_ff_neg_zp_sp", i_prec_width_ff_neg_zp_sp, i_prec_width_ff_neg_zp_sp_bench, "{return test(\"% 010.5i\", -216);}"},
	{1, 414, "i_prec_width_ff_zero_zp_sp", i_prec_width_ff_zero_zp_sp, i_prec_width_ff_zero_zp_sp_bench, "{return test(\"% 08.5i\", 0);}"},
	{1, 415, "i_prec_width_nf_pos_zp_sp", i_prec_width_nf_pos_zp_sp, i_prec_width_nf_pos_zp_sp_bench, "{return test(\"% 08.3i\", 8375);}"},
	{1, 416, "i_prec_width_nf_neg_zp_sp", i_prec_width_nf_neg_zp_sp, i_prec_width_nf_neg_zp_sp_bench, "{return test(\"% 08.3i\", -8473);}"},
	{1, 417, "i_prec_width_fn_pos_zp_sp", i_prec_width_fn_pos_zp_sp, i_prec_width_fn_pos_zp_sp_bench, "{return test(\"% 03.7i\", 3267);}"},
	{1, 418, "i_prec_width_fn_neg_zp_sp", i_prec_width_fn_neg_zp_sp, i_prec_width_fn_neg_zp_sp_bench, "{return test(\"% 03.7i\", -2375);}"},
	{1, 419, "i_prec_width_nn_pos_zp_sp", i_prec_width_nn_pos_zp_sp, i_prec_width_nn_pos_zp_sp_bench, "{return test(\"% 03.3i\", 6983);}"},
	{1, 420, "i_prec_width_nn_neg_zp_sp", i_prec_width_nn_neg_zp_sp, i_prec_width_nn_neg_zp_sp_bench, "{return test(\"% 03.3i\", -8462);}"},
	{1, 421, "i_prec_width_ff_pos_ljzpsp_ignoreflag", i_prec_width_ff_pos_ljzpsp_ignoreflag, i_prec_width_ff_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.5i\", 34);}"},
	{1, 422, "i_prec_width_ff_neg_ljzpsp_ignoreflag", i_prec_width_ff_neg_ljzpsp_ignoreflag, i_prec_width_ff_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-10.5i\", -216);}"},
	{1, 423, "i_prec_width_ff_zero_ljzpsp_ignoreflag", i_prec_width_ff_zero_ljzpsp_ignoreflag, i_prec_width_ff_zero_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.5i\", 0);}"},
	{1, 424, "i_prec_width_nf_pos_ljzpsp_ignoreflag", i_prec_width_nf_pos_ljzpsp_ignoreflag, i_prec_width_nf_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.3i\", 8375);}"},
	{1, 425, "i_prec_width_nf_neg_ljzpsp_ignoreflag", i_prec_width_nf_neg_ljzpsp_ignoreflag, i_prec_width_nf_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.3i\", -8473);}"},
	{1, 426, "i_prec_width_fn_pos_ljzpsp_ignoreflag", i_prec_width_fn_pos_ljzpsp_ignoreflag, i_prec_width_fn_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.7i\", 3267);}"},
	{1, 427, "i_prec_width_fn_neg_ljzpsp_ignoreflag", i_prec_width_fn_neg_ljzpsp_ignoreflag, i_prec_width_fn_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.7i\", -2375);}"},
	{1, 428, "i_prec_width_nn_pos_ljzpsp_ignoreflag", i_prec_width_nn_pos_ljzpsp_ignoreflag, i_prec_width_nn_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.3i\", 6983);}"},
	{1, 429, "i_prec_width_nn_neg_ljzpsp_ignoreflag", i_prec_width_nn_neg_ljzpsp_ignoreflag, i_prec_width_nn_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.3i\", -8462);}"},
	{1, 430, "i_prec_width_ff_pos_aszpsp_ignoreflag", i_prec_width_ff_pos_aszpsp_ignoreflag, i_prec_width_ff_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.5i\", 34);}"},
	{1, 431, "i_prec_width_ff_neg_aszpsp_ignoreflag", i_prec_width_ff_neg_aszpsp_ignoreflag, i_prec_width_ff_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+10.5i\", -216);}"},
	{1, 432, "i_prec_width_ff_zero_aszpsp_ignoreflag", i_prec_width_ff_zero_aszpsp_ignoreflag, i_prec_width_ff_zero_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.5i\", 0);}"},
	{1, 433, "i_prec_width_nf_pos_aszpsp_ignoreflag", i_prec_width_nf_pos_aszpsp_ignoreflag, i_prec_width_nf_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.3i\", 8375);}"},
	{1, 434, "i_prec_width_nf_neg_aszpsp_ignoreflag", i_prec_width_nf_neg_aszpsp_ignoreflag, i_prec_width_nf_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.3i\", -8473);}"},
	{1, 435, "i_prec_width_fn_pos_aszpsp_ignoreflag", i_prec_width_fn_pos_aszpsp_ignoreflag, i_prec_width_fn_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.7i\", 3267);}"},
	{1, 436, "i_prec_width_fn_neg_aszpsp_ignoreflag", i_prec_width_fn_neg_aszpsp_ignoreflag, i_prec_width_fn_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.7i\", -2375);}"},
	{1, 437, "i_prec_width_nn_pos_aszpsp_ignoreflag", i_prec_width_nn_pos_aszpsp_ignoreflag, i_prec_width_nn_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.3i\", 6983);}"},
	{1, 438, "i_prec_width_nn_neg_aszpsp_ignoreflag", i_prec_width_nn_neg_aszpsp_ignoreflag, i_prec_width_nn_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.3i\", -8462);}"},
	{1, 439, "i_prec_width_ff_pos_ljaszpsp_ignoreflag", i_prec_width_ff_pos_ljaszpsp_ignoreflag, i_prec_width_ff_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.5i\", 34);}"},
	{1, 440, "i_prec_width_ff_neg_ljaszpsp_ignoreflag", i_prec_width_ff_neg_ljaszpsp_ignoreflag, i_prec_width_ff_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-10.5i\", -216);}"},
	{1, 441, "i_prec_width_ff_zero_ljaszpsp_ignoreflag", i_prec_width_ff_zero_ljaszpsp_ignoreflag, i_prec_width_ff_zero_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.5i\", 0);}"},
	{1, 442, "i_prec_width_nf_pos_ljaszpsp_ignoreflag", i_prec_width_nf_pos_ljaszpsp_ignoreflag, i_prec_width_nf_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.3i\", 8375);}"},
	{1, 443, "i_prec_width_nf_neg_ljaszpsp_ignoreflag", i_prec_width_nf_neg_ljaszpsp_ignoreflag, i_prec_width_nf_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.3i\", -8473);}"},
	{1, 444, "i_prec_width_fn_pos_ljaszpsp_ignoreflag", i_prec_width_fn_pos_ljaszpsp_ignoreflag, i_prec_width_fn_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.7i\", 3267);}"},
	{1, 445, "i_prec_width_fn_neg_ljaszpsp_ignoreflag", i_prec_width_fn_neg_ljaszpsp_ignoreflag, i_prec_width_fn_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.7i\", -2375);}"},
	{1, 446, "i_prec_width_nn_pos_ljaszpsp_ignoreflag", i_prec_width_nn_pos_ljaszpsp_ignoreflag, i_prec_width_nn_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.3i\", 6983);}"},
	{1, 447, "i_prec_width_nn_neg_ljaszpsp_ignoreflag", i_prec_width_nn_neg_ljaszpsp_ignoreflag, i_prec_width_nn_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.3i\", -8462);}"},
	{1, 448, "i_size_hh_pos_casted_sp", i_size_hh_pos_casted_sp, i_size_hh_pos_casted_sp_bench, "{return test(\"% hhi\", (char)45);}"},
	{1, 449, "i_size_hh_neg_casted_sp", i_size_hh_neg_casted_sp, i_size_hh_neg_casted_sp_bench, "{return test(\"% hhi\", (char)-45);}"},
	{1, 450, "i_size_h_pos_casted_sp", i_size_h_pos_casted_sp, i_size_h_pos_casted_sp_bench, "{return test(\"% hi\", (short)385);}"},
	{1, 451, "i_size_h_neg_casted_sp", i_size_h_neg_casted_sp, i_size_h_neg_casted_sp_bench, "{return test(\"% hi\", (short)-385);}"},
	{1, 452, "i_size_l_pos_casted_sp", i_size_l_pos_casted_sp, i_size_l_pos_casted_sp_bench, "{return test(\"% li\", (long)32);}"},
	{1, 453, "i_size_l_neg_casted_sp", i_size_l_neg_casted_sp, i_size_l_neg_casted_sp_bench, "{return test(\"% li\", (long)-32);}"},
	{1, 454, "i_size_ll_pos_casted_sp", i_size_ll_pos_casted_sp, i_size_ll_pos_casted_sp_bench, "{return test(\"% lli\", (long long)43);}"},
	{1, 455, "i_size_ll_neg_casted_sp", i_size_ll_neg_casted_sp, i_size_ll_neg_casted_sp_bench, "{return test(\"% lli\", (long long)-43);}"},
	{1, 456, "i_size_hh_pos_ref_sp", i_size_hh_pos_ref_sp, i_size_hh_pos_ref_sp_bench, "{return test(\"% hhi\", ch_pos_1);}"},
	{1, 457, "i_size_hh_neg_ref_sp", i_size_hh_neg_ref_sp, i_size_hh_neg_ref_sp_bench, "{return test(\"% hhi\", ch_neg_1);}"},
	{1, 458, "i_size_h_pos_ref_sp", i_size_h_pos_ref_sp, i_size_h_pos_ref_sp_bench, "{return test(\"% hi\", sh_pos_1);}"},
	{1, 459, "i_size_h_neg_ref_sp", i_size_h_neg_ref_sp, i_size_h_neg_ref_sp_bench, "{return test(\"% hi\", sh_neg_1);}"},
	{1, 460, "i_size_l_pos_ref_sp", i_size_l_pos_ref_sp, i_size_l_pos_ref_sp_bench, "{return test(\"% li\", l_pos_1);}"},
	{1, 461, "i_size_l_neg_ref_sp", i_size_l_neg_ref_sp, i_size_l_neg_ref_sp_bench, "{return test(\"% li\", l_neg_1);}"},
	{1, 462, "i_size_ll_pos_ref_sp", i_size_ll_pos_ref_sp, i_size_ll_pos_ref_sp_bench, "{return test(\"% lli\", ll_pos_1);}"},
	{1, 463, "i_size_ll_neg_ref_sp", i_size_ll_neg_ref_sp, i_size_ll_neg_ref_sp_bench, "{return test(\"% lli\", ll_neg_1);}"},
	{1, 464, "i_size_l_pos_big_sp", i_size_l_pos_big_sp, i_size_l_pos_big_sp_bench, "{return test(\"% li\", 22337203685477l);}"},
	{1, 465, "i_size_l_neg_big_sp", i_size_l_neg_big_sp, i_size_l_neg_big_sp_bench, "{return test(\"% li\", -22337203685477l);}"},
	{1, 466, "i_size_ll_pos_big_sp", i_size_ll_pos_big_sp, i_size_ll_pos_big_sp_bench, "{return test(\"% lli\", 522337203685470ll);}"},
	{1, 467, "i_size_ll_neg_big_sp", i_size_ll_neg_big_sp, i_size_ll_neg_big_sp_bench, "{return test(\"% lli\", -522337203685470ll);}"},
	{1, 468, "i_llmax_sp", i_llmax_sp, i_llmax_sp_bench, "{return test(\"% lli\", 9223372036854775807ll);}"},
	{1, 469, "i_llmin_sp", i_llmin_sp, i_llmin_sp_bench, "{return test(\"% lli\", llmin);}"},
	{1, 470, "i_lmax_sp", i_lmax_sp, i_lmax_sp_bench, "{return test(\"% li\", 9223372036854775807l);}"},
	{1, 471, "i_lmin_sp", i_lmin_sp, i_lmin_sp_bench, "{return test(\"% li\", lmin);}"},
	{1, 472, "i_hmax_sp", i_hmax_sp, i_hmax_sp_bench, "{return test(\"% hi\", (short)32767);}"},
	{1, 473, "i_hmin_sp", i_hmin_sp, i_hmin_sp_bench, "{return test(\"% hi\", (short)(-32768));}"},
	{1, 474, "i_hhmax_sp", i_hhmax_sp, i_hhmax_sp_bench, "{return test(\"% hhi\", (char)(127));}"},
	{1, 475, "i_hhmin_sp", i_hhmin_sp, i_hhmin_sp_bench, "{return test(\"% hhi\", (char)(-128));}"},
	{1, 476, "i_prec0val0_basic", i_prec0val0_basic, i_prec0val0_basic_bench, "{return test(\"%.0i\", 0);}"},
	{1, 477, "i_prec0val0_implicit", i_prec0val0_implicit, i_prec0val0_implicit_bench, "{return test(\"%.i\", 0);}"},
	{1, 478, "i_prec0val0_w", i_prec0val0_w, i_prec0val0_w_bench, "{return test(\"%5.0i\", 0);}"},
	{1, 479, "i_prec0val0_w_impl", i_prec0val0_w_impl, i_prec0val0_w_impl_bench, "{return test(\"%5.i\", 0);}"},
	{1, 480, "i_prec0val0_wlj", i_prec0val0_wlj, i_prec0val0_wlj_bench, "{return test(\"%-5.0i\", 0);}"},
	{1, 481, "i_prec0val0_wlj_impl", i_prec0val0_wlj_impl, i_prec0val0_wlj_impl_bench, "{return test(\"%-5.i\", 0);}"},
	{1, 482, "i_prec0val0_as", i_prec0val0_as, i_prec0val0_as_bench, "{return test(\"%+.0i\", 0);}"},
	{1, 483, "i_prec0val0_as_impl", i_prec0val0_as_impl, i_prec0val0_as_impl_bench, "{return test(\"%+.i\", 0);}"},
	{1, 484, "i_prec0val0_was", i_prec0val0_was, i_prec0val0_was_bench, "{return test(\"%+5.0i\", 0);}"},
	{1, 485, "i_prec0val0_was_impl", i_prec0val0_was_impl, i_prec0val0_was_impl_bench, "{return test(\"%+5.i\", 0);}"},
	{1, 486, "i_prec0val0_waslj", i_prec0val0_waslj, i_prec0val0_waslj_bench, "{return test(\"%+-5.0i\", 0);}"},
	{1, 487, "i_prec0val0_waslj_impl", i_prec0val0_waslj_impl, i_prec0val0_waslj_impl_bench, "{return test(\"%+-5.i\", 0);}"},
	{0, 488, "i_ftfc_hhdoutofrange1_might_be_undefbehav", i_ftfc_hhdoutofrange1_might_be_undefbehav, i_ftfc_hhdoutofrange1_might_be_undefbehav_bench, "{return test(\"%hhi\", -129);}"},
	{0, 489, "i_ftfc_hhdoutofrange2_might_be_undefbehav", i_ftfc_hhdoutofrange2_might_be_undefbehav, i_ftfc_hhdoutofrange2_might_be_undefbehav_bench, "{return test(\"%hhi\", 128);}"},
	{0, 490, "i_ftfc_hdoutofrange1_might_be_undefbehav", i_ftfc_hdoutofrange1_might_be_undefbehav, i_ftfc_hdoutofrange1_might_be_undefbehav_bench, "{return test(\"%hi\", 32768);}"},
	{0, 491, "i_ftfc_hdoutofrange2_might_be_undefbehav", i_ftfc_hdoutofrange2_might_be_undefbehav, i_ftfc_hdoutofrange2_might_be_undefbehav_bench, "{return test(\"%hi\", -32769);}"},
	{1, 492, "d_basic_i_pos", d_basic_i_pos, d_basic_i_pos_bench, "{return test(\"this %d number\", 17);}"},
	{1, 493, "d_basic_i_neg", d_basic_i_neg, d_basic_i_neg_bench, "{return test(\"this %d number\", -267);}"},
	{1, 494, "d_basic_i_zero", d_basic_i_zero, d_basic_i_zero_bench, "{return test(\"this %d number\", 0);}"},
	{1, 495, "d_basic_i_onlypos", d_basic_i_onlypos, d_basic_i_onlypos_bench, "{return test(\"%d\", 3);}"},
	{1, 496, "d_basic_i_onlyneg", d_basic_i_onlyneg, d_basic_i_onlyneg_bench, "{return test(\"%d\", -1);}"},
	{1, 497, "d_basic_i_onlyzero", d_basic_i_onlyzero, d_basic_i_onlyzero_bench, "{return test(\"%d\", 0);}"},
	{1, 498, "d_intmax", d_intmax, d_intmax_bench, "{return test(\"%d\",  2147483647);}"},
	{1, 499, "d_intmin", d_intmin, d_intmin_bench, "{return test(\"%d\", (int)(-2147483678));}"},
	{1, 500, "d_as_pos", d_as_pos, d_as_pos_bench, "{return test(\"%+d\", 5);}"},
	{1, 501, "d_as_neg", d_as_neg, d_as_neg_bench, "{return test(\"%+d\", -7);}"},
	{1, 502, "d_intmax_as", d_intmax_as, d_intmax_as_bench, "{return test(\"%+d\", 2147483647);}"},
	{1, 503, "d_width_pos_fits", d_width_pos_fits, d_width_pos_fits_bench, "{return test(\"%7d\", 33);}"},
	{1, 504, "d_width_neg_fits", d_width_neg_fits, d_width_neg_fits_bench, "{return test(\"%7d\", -14);}"},
	{1, 505, "d_width_zero_fits", d_width_zero_fits, d_width_zero_fits_bench, "{return test(\"%3d\", 0);}"},
	{1, 506, "d_width_pos_exactfit", d_width_pos_exactfit, d_width_pos_exactfit_bench, "{return test(\"%5d\", 52625);}"},
	{1, 507, "d_width_neg_exactfit", d_width_neg_exactfit, d_width_neg_exactfit_bench, "{return test(\"%5d\", -2562);}"},
	{1, 508, "d_width_pos_nofit", d_width_pos_nofit, d_width_pos_nofit_bench, "{return test(\"%4d\", 94827);}"},
	{1, 509, "d_width_neg_nofit", d_width_neg_nofit, d_width_neg_nofit_bench, "{return test(\"%4d\", -2464);}"},
	{1, 510, "d_width_pos_fits_lj", d_width_pos_fits_lj, d_width_pos_fits_lj_bench, "{return test(\"%-7d\", 33);}"},
	{1, 511, "d_width_neg_fits_lj", d_width_neg_fits_lj, d_width_neg_fits_lj_bench, "{return test(\"%-7d\", -14);}"},
	{1, 512, "d_width_zero_fits_lj", d_width_zero_fits_lj, d_width_zero_fits_lj_bench, "{return test(\"%-3d\", 0);}"},
	{1, 513, "d_width_pos_exactfit_lj", d_width_pos_exactfit_lj, d_width_pos_exactfit_lj_bench, "{return test(\"%-5d\", 52625);}"},
	{1, 514, "d_width_neg_exactfit_lj", d_width_neg_exactfit_lj, d_width_neg_exactfit_lj_bench, "{return test(\"%-5d\", -2562);}"},
	{1, 515, "d_width_pos_nofit_lj", d_width_pos_nofit_lj, d_width_pos_nofit_lj_bench, "{return test(\"%-4d\", 94827);}"},
	{1, 516, "d_width_neg_nofit_lj", d_width_neg_nofit_lj, d_width_neg_nofit_lj_bench, "{return test(\"%-4d\", -2464);}"},
	{1, 517, "d_width_as_pos", d_width_as_pos, d_width_as_pos_bench, "{return test(\"%+5d\", 35);}"},
	{1, 518, "d_width_as_zero", d_width_as_zero, d_width_as_zero_bench, "{return test(\"%+7d\", 0);}"},
	{1, 519, "d_width_intmax_as", d_width_intmax_as, d_width_intmax_as_bench, "{return test(\"%+24d\", 2147483647);}"},
	{1, 520, "d_prec_fits_pos", d_prec_fits_pos, d_prec_fits_pos_bench, "{return test(\"%.5d\", 2);}"},
	{1, 521, "d_prec_fits_neg", d_prec_fits_neg, d_prec_fits_neg_bench, "{return test(\"%.6d\", -3);}"},
	{1, 522, "d_prec_fits_zero", d_prec_fits_zero, d_prec_fits_zero_bench, "{return test(\"%.3d\", 0);}"},
	{1, 523, "d_prec_exactfit_pos", d_prec_exactfit_pos, d_prec_exactfit_pos_bench, "{return test(\"%.4d\", 5263);}"},
	{1, 524, "d_prec_exactfit_neg", d_prec_exactfit_neg, d_prec_exactfit_neg_bench, "{return test(\"%.4d\", -2372);}"},
	{1, 525, "d_prec_nofit_pos", d_prec_nofit_pos, d_prec_nofit_pos_bench, "{return test(\"%.3d\", 13862);}"},
	{1, 526, "d_prec_nofit_neg", d_prec_nofit_neg, d_prec_nofit_neg_bench, "{return test(\"%.3d\",-23646);}"},
	{1, 527, "d_prec_as_pos", d_prec_as_pos, d_prec_as_pos_bench, "{return test(\"%+.7d\", 234);}"},
	{1, 528, "d_prec_as_neg", d_prec_as_neg, d_prec_as_neg_bench, "{return test(\"%+.7d\", -446);}"},
	{1, 529, "d_prec_as_pos_nofit", d_prec_as_pos_nofit, d_prec_as_pos_nofit_bench, "{return test(\"%+.3d\", 3723);}"},
	{1, 530, "d_zp_pos_fits", d_zp_pos_fits, d_zp_pos_fits_bench, "{return test(\"%05d\", 43);}"},
	{1, 531, "d_zp_neg_fits", d_zp_neg_fits, d_zp_neg_fits_bench, "{return test(\"%07d\", -54);}"},
	{1, 532, "d_zp_zero_fits", d_zp_zero_fits, d_zp_zero_fits_bench, "{return test(\"%03d\", 0);}"},
	{1, 533, "d_zp_pos_exactfit", d_zp_pos_exactfit, d_zp_pos_exactfit_bench, "{return test(\"%03d\", 634);}"},
	{1, 534, "d_zp_neg_exactfit", d_zp_neg_exactfit, d_zp_neg_exactfit_bench, "{return test(\"%04d\", -532);}"},
	{1, 535, "d_zp_neg_minus1fit", d_zp_neg_minus1fit, d_zp_neg_minus1fit_bench, "{return test(\"%04d\", -4825);}"},
	{1, 536, "d_zp_as_fits", d_zp_as_fits, d_zp_as_fits_bench, "{return test(\"%+05d\", 432);}"},
	{1, 537, "d_zp_as_zero", d_zp_as_zero, d_zp_as_zero_bench, "{return test(\"%+04d\", 0);}"},
	{1, 538, "d_prec_width_fit_fit_pos", d_prec_width_fit_fit_pos, d_prec_width_fit_fit_pos_bench, "{return test(\"%8.5d\", 34);}"},
	{1, 539, "d_prec_width_fit_fit_neg", d_prec_width_fit_fit_neg, d_prec_width_fit_fit_neg_bench, "{return test(\"%10.5d\", -216);}"},
	{1, 540, "d_prec_width_fit_fit_zero", d_prec_width_fit_fit_zero, d_prec_width_fit_fit_zero_bench, "{return test(\"%8.5d\", 0);}"},
	{1, 541, "d_prec_width_nofit_fit_pos", d_prec_width_nofit_fit_pos, d_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3d\", 8375);}"},
	{1, 542, "d_prec_width_nofit_fit_neg", d_prec_width_nofit_fit_neg, d_prec_width_nofit_fit_neg_bench, "{return test(\"%8.3d\", -8473);}"},
	{1, 543, "d_prec_width_fit_nofit_pos", d_prec_width_fit_nofit_pos, d_prec_width_fit_nofit_pos_bench, "{return test(\"%3.7d\", 3267);}"},
	{1, 544, "d_prec_width_fit_nofit_neg", d_prec_width_fit_nofit_neg, d_prec_width_fit_nofit_neg_bench, "{return test(\"%3.7d\", -2375);}"},
	{1, 545, "d_prec_width_nofit_nofit_pos", d_prec_width_nofit_nofit_pos, d_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3d\", 6983);}"},
	{1, 546, "d_prec_width_nofit_nofit_neg", d_prec_width_nofit_nofit_neg, d_prec_width_nofit_nofit_neg_bench, "{return test(\"%3.3d\", -8462);}"},
	{1, 547, "d_prec_width_fit_fit_pos_lj", d_prec_width_fit_fit_pos_lj, d_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5d\", 34);}"},
	{1, 548, "d_prec_width_fit_fit_neg_lj", d_prec_width_fit_fit_neg_lj, d_prec_width_fit_fit_neg_lj_bench, "{return test(\"%-10.5d\", -216);}"},
	{1, 549, "d_prec_width_fit_fit_zero_lj", d_prec_width_fit_fit_zero_lj, d_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5d\", 0);}"},
	{1, 550, "d_prec_width_nofit_fit_pos_lj", d_prec_width_nofit_fit_pos_lj, d_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3d\", 8375);}"},
	{1, 551, "d_prec_width_nofit_fit_neg_lj", d_prec_width_nofit_fit_neg_lj, d_prec_width_nofit_fit_neg_lj_bench, "{return test(\"%-8.3d\", -8473);}"},
	{1, 552, "d_prec_width_fit_nofit_pos_lj", d_prec_width_fit_nofit_pos_lj, d_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-3.7d\", 3267);}"},
	{1, 553, "d_prec_width_fit_nofit_neg_lj", d_prec_width_fit_nofit_neg_lj, d_prec_width_fit_nofit_neg_lj_bench, "{return test(\"%-3.7d\", -2375);}"},
	{1, 554, "d_prec_width_nofit_nofit_pos_lj", d_prec_width_nofit_nofit_pos_lj, d_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3d\", 6983);}"},
	{1, 555, "d_prec_width_nofit_nofit_neg_lj", d_prec_width_nofit_nofit_neg_lj, d_prec_width_nofit_nofit_neg_lj_bench, "{return test(\"%-3.3d\", -8462);}"},
	{1, 556, "d_prec_width_fit_fit_pos_as", d_prec_width_fit_fit_pos_as, d_prec_width_fit_fit_pos_as_bench, "{return test(\"%+8.5d\", 34);}"},
	{1, 557, "d_prec_width_fit_fit_neg_as", d_prec_width_fit_fit_neg_as, d_prec_width_fit_fit_neg_as_bench, "{return test(\"%+10.5d\", -216);}"},
	{1, 558, "d_prec_width_fit_fit_zero_as", d_prec_width_fit_fit_zero_as, d_prec_width_fit_fit_zero_as_bench, "{return test(\"%+8.5d\", 0);}"},
	{1, 559, "d_prec_width_nofit_fit_pos_as", d_prec_width_nofit_fit_pos_as, d_prec_width_nofit_fit_pos_as_bench, "{return test(\"%+8.3d\", 8375);}"},
	{1, 560, "d_prec_width_nofit_fit_neg_as", d_prec_width_nofit_fit_neg_as, d_prec_width_nofit_fit_neg_as_bench, "{return test(\"%+8.3d\", -8473);}"},
	{1, 561, "d_prec_width_fit_nofit_pos_as", d_prec_width_fit_nofit_pos_as, d_prec_width_fit_nofit_pos_as_bench, "{return test(\"%+3.7d\", 3267);}"},
	{1, 562, "d_prec_width_fit_nofit_neg_as", d_prec_width_fit_nofit_neg_as, d_prec_width_fit_nofit_neg_as_bench, "{return test(\"%+3.7d\", -2375);}"},
	{1, 563, "d_prec_width_nofit_nofit_pos_as", d_prec_width_nofit_nofit_pos_as, d_prec_width_nofit_nofit_pos_as_bench, "{return test(\"%+3.3d\", 6983);}"},
	{1, 564, "d_prec_width_nofit_nofit_neg_as", d_prec_width_nofit_nofit_neg_as, d_prec_width_nofit_nofit_neg_as_bench, "{return test(\"%+3.3d\", -8462);}"},
	{1, 565, "d_prec_width_fit_fit_pos_ljas", d_prec_width_fit_fit_pos_ljas, d_prec_width_fit_fit_pos_ljas_bench, "{return test(\"%+-8.5d\", 34);}"},
	{1, 566, "d_prec_width_fit_fit_neg_ljas", d_prec_width_fit_fit_neg_ljas, d_prec_width_fit_fit_neg_ljas_bench, "{return test(\"%+-10.5d\", -216);}"},
	{1, 567, "d_prec_width_fit_fit_zero_ljas", d_prec_width_fit_fit_zero_ljas, d_prec_width_fit_fit_zero_ljas_bench, "{return test(\"%+-8.5d\", 0);}"},
	{1, 568, "d_prec_width_nofit_fit_pos_ljas", d_prec_width_nofit_fit_pos_ljas, d_prec_width_nofit_fit_pos_ljas_bench, "{return test(\"%+-8.3d\", 8375);}"},
	{1, 569, "d_prec_width_nofit_fit_neg_ljas", d_prec_width_nofit_fit_neg_ljas, d_prec_width_nofit_fit_neg_ljas_bench, "{return test(\"%+-8.3d\", -8473);}"},
	{1, 570, "d_prec_width_fit_nofit_pos_ljas", d_prec_width_fit_nofit_pos_ljas, d_prec_width_fit_nofit_pos_ljas_bench, "{return test(\"%+-3.7d\", 3267);}"},
	{1, 571, "d_prec_width_fit_nofit_neg_ljas", d_prec_width_fit_nofit_neg_ljas, d_prec_width_fit_nofit_neg_ljas_bench, "{return test(\"%+-3.7d\", -2375);}"},
	{1, 572, "d_prec_width_nofit_nofit_pos_ljas", d_prec_width_nofit_nofit_pos_ljas, d_prec_width_nofit_nofit_pos_ljas_bench, "{return test(\"%+-3.3d\", 6983);}"},
	{1, 573, "d_prec_width_nofit_nofit_neg_ljas", d_prec_width_nofit_nofit_neg_ljas, d_prec_width_nofit_nofit_neg_ljas_bench, "{return test(\"%+-3.3d\", -8462);}"},
	{1, 574, "d_prec_width_ff_pos_zp", d_prec_width_ff_pos_zp, d_prec_width_ff_pos_zp_bench, "{return test(\"%08.5d\", 34);}"},
	{1, 575, "d_prec_width_ff_neg_zp", d_prec_width_ff_neg_zp, d_prec_width_ff_neg_zp_bench, "{return test(\"%010.5d\", -216);}"},
	{1, 576, "d_prec_width_ff_zero_zp", d_prec_width_ff_zero_zp, d_prec_width_ff_zero_zp_bench, "{return test(\"%08.5d\", 0);}"},
	{1, 577, "d_prec_width_nf_pos_zp", d_prec_width_nf_pos_zp, d_prec_width_nf_pos_zp_bench, "{return test(\"%08.3d\", 8375);}"},
	{1, 578, "d_prec_width_nf_neg_zp", d_prec_width_nf_neg_zp, d_prec_width_nf_neg_zp_bench, "{return test(\"%08.3d\", -8473);}"},
	{1, 579, "d_prec_width_fn_pos_zp", d_prec_width_fn_pos_zp, d_prec_width_fn_pos_zp_bench, "{return test(\"%03.7d\", 3267);}"},
	{1, 580, "d_prec_width_fn_neg_zp", d_prec_width_fn_neg_zp, d_prec_width_fn_neg_zp_bench, "{return test(\"%03.7d\", -2375);}"},
	{1, 581, "d_prec_width_nn_pos_zp", d_prec_width_nn_pos_zp, d_prec_width_nn_pos_zp_bench, "{return test(\"%03.3d\", 6983);}"},
	{1, 582, "d_prec_width_nn_neg_zp", d_prec_width_nn_neg_zp, d_prec_width_nn_neg_zp_bench, "{return test(\"%03.3d\", -8462);}"},
	{1, 583, "d_prec_width_ff_pos_lj_zp_ignoreflag", d_prec_width_ff_pos_lj_zp_ignoreflag, d_prec_width_ff_pos_lj_zp_ignoreflag_bench, "{return test(\"%0-8.5d\", 34);}"},
	{1, 584, "d_prec_width_ff_neg_ljzp_ignoreflag", d_prec_width_ff_neg_ljzp_ignoreflag, d_prec_width_ff_neg_ljzp_ignoreflag_bench, "{return test(\"%0-10.5d\", -216);}"},
	{1, 585, "d_prec_width_ff_zero_ljzp_ignoreflag", d_prec_width_ff_zero_ljzp_ignoreflag, d_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5d\", 0);}"},
	{1, 586, "d_prec_width_nf_pos_ljzp_ignoreflag", d_prec_width_nf_pos_ljzp_ignoreflag, d_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3d\", 8375);}"},
	{1, 587, "d_prec_width_nf_neg_ljzp_ignoreflag", d_prec_width_nf_neg_ljzp_ignoreflag, d_prec_width_nf_neg_ljzp_ignoreflag_bench, "{return test(\"%0-8.3d\", -8473);}"},
	{1, 588, "d_prec_width_fn_pos_ljzp_ignoreflag", d_prec_width_fn_pos_ljzp_ignoreflag, d_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.7d\", 3267);}"},
	{1, 589, "d_prec_width_fn_neg_ljzp_ignoreflag", d_prec_width_fn_neg_ljzp_ignoreflag, d_prec_width_fn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.7d\", -2375);}"},
	{1, 590, "d_prec_width_nn_pos_ljzp_ignoreflag", d_prec_width_nn_pos_ljzp_ignoreflag, d_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3d\", 6983);}"},
	{1, 591, "d_prec_width_nn_neg_ljzp_ignoreflag", d_prec_width_nn_neg_ljzp_ignoreflag, d_prec_width_nn_neg_ljzp_ignoreflag_bench, "{return test(\"%0-3.3d\", -8462);}"},
	{1, 592, "d_prec_width_ff_pos_aszp", d_prec_width_ff_pos_aszp, d_prec_width_ff_pos_aszp_bench, "{return test(\"%0+8.5d\", 34);}"},
	{1, 593, "d_prec_width_ff_neg_aszp", d_prec_width_ff_neg_aszp, d_prec_width_ff_neg_aszp_bench, "{return test(\"%0+10.5d\", -216);}"},
	{1, 594, "d_prec_width_ff_zero_aszp", d_prec_width_ff_zero_aszp, d_prec_width_ff_zero_aszp_bench, "{return test(\"%0+8.5d\", 0);}"},
	{1, 595, "d_prec_width_nf_pos_aszp", d_prec_width_nf_pos_aszp, d_prec_width_nf_pos_aszp_bench, "{return test(\"%0+8.3d\", 8375);}"},
	{1, 596, "d_prec_width_nf_neg_aszp", d_prec_width_nf_neg_aszp, d_prec_width_nf_neg_aszp_bench, "{return test(\"%0+8.3d\", -8473);}"},
	{1, 597, "d_prec_width_fn_pos_aszp", d_prec_width_fn_pos_aszp, d_prec_width_fn_pos_aszp_bench, "{return test(\"%0+3.7d\", 3267);}"},
	{1, 598, "d_prec_width_fn_neg_aszp", d_prec_width_fn_neg_aszp, d_prec_width_fn_neg_aszp_bench, "{return test(\"%0+3.7d\", -2375);}"},
	{1, 599, "d_prec_width_nn_pos_aszp", d_prec_width_nn_pos_aszp, d_prec_width_nn_pos_aszp_bench, "{return test(\"%0+3.3d\", 6983);}"},
	{1, 600, "d_prec_width_nn_neg_aszp", d_prec_width_nn_neg_aszp, d_prec_width_nn_neg_aszp_bench, "{return test(\"%0+3.3d\", -8462);}"},
	{1, 601, "d_prec_width_ff_pos_ljaszp_ignoreflag", d_prec_width_ff_pos_ljaszp_ignoreflag, d_prec_width_ff_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.5d\", 34);}"},
	{1, 602, "d_prec_width_ff_neg_ljaszp_ignoreflag", d_prec_width_ff_neg_ljaszp_ignoreflag, d_prec_width_ff_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-10.5d\", -216);}"},
	{1, 603, "d_prec_width_ff_zero_ljaszp_ignoreflag", d_prec_width_ff_zero_ljaszp_ignoreflag, d_prec_width_ff_zero_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.5d\", 0);}"},
	{1, 604, "d_prec_width_nf_pos_ljaszp_ignoreflag", d_prec_width_nf_pos_ljaszp_ignoreflag, d_prec_width_nf_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.3d\", 8375);}"},
	{1, 605, "d_prec_width_nf_neg_ljaszp_ignoreflag", d_prec_width_nf_neg_ljaszp_ignoreflag, d_prec_width_nf_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-8.3d\", -8473);}"},
	{1, 606, "d_prec_width_fn_pos_ljaszp_ignoreflag", d_prec_width_fn_pos_ljaszp_ignoreflag, d_prec_width_fn_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.7d\", 3267);}"},
	{1, 607, "d_prec_width_fn_neg_ljaszp_ignoreflag", d_prec_width_fn_neg_ljaszp_ignoreflag, d_prec_width_fn_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.7d\", -2375);}"},
	{1, 608, "d_prec_width_nn_pos_ljaszp_ignoreflag", d_prec_width_nn_pos_ljaszp_ignoreflag, d_prec_width_nn_pos_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.3d\", 6983);}"},
	{1, 609, "d_prec_width_nn_neg_ljaszp_ignoreflag", d_prec_width_nn_neg_ljaszp_ignoreflag, d_prec_width_nn_neg_ljaszp_ignoreflag_bench, "{return test(\"%0+-3.3d\", -8462);}"},
	{1, 610, "d_size_hh_pos_casted", d_size_hh_pos_casted, d_size_hh_pos_casted_bench, "{return test(\"%hhd\", (char)45);}"},
	{1, 611, "d_size_hh_neg_casted", d_size_hh_neg_casted, d_size_hh_neg_casted_bench, "{return test(\"%hhd\", (char)-45);}"},
	{1, 612, "d_size_h_pos_casted", d_size_h_pos_casted, d_size_h_pos_casted_bench, "{return test(\"%hd\", (short)385);}"},
	{1, 613, "d_size_h_neg_casted", d_size_h_neg_casted, d_size_h_neg_casted_bench, "{return test(\"%hd\", (short)-385);}"},
	{1, 614, "d_size_l_pos_casted", d_size_l_pos_casted, d_size_l_pos_casted_bench, "{return test(\"%ld\", (long)32);}"},
	{1, 615, "d_size_l_neg_casted", d_size_l_neg_casted, d_size_l_neg_casted_bench, "{return test(\"%ld\", (long)-32);}"},
	{1, 616, "d_size_ll_pos_casted", d_size_ll_pos_casted, d_size_ll_pos_casted_bench, "{return test(\"%lld\", (long long)43);}"},
	{1, 617, "d_size_ll_neg_casted", d_size_ll_neg_casted, d_size_ll_neg_casted_bench, "{return test(\"%lld\", (long long)-43);}"},
	{1, 618, "d_size_hh_pos_ref", d_size_hh_pos_ref, d_size_hh_pos_ref_bench, "{return test(\"%hhd\", ch_pos_1);}"},
	{1, 619, "d_size_hh_neg_ref", d_size_hh_neg_ref, d_size_hh_neg_ref_bench, "{return test(\"%hhd\", ch_neg_1);}"},
	{1, 620, "d_size_h_pos_ref", d_size_h_pos_ref, d_size_h_pos_ref_bench, "{return test(\"%hd\", sh_pos_1);}"},
	{1, 621, "d_size_h_neg_ref", d_size_h_neg_ref, d_size_h_neg_ref_bench, "{return test(\"%hd\", sh_neg_1);}"},
	{1, 622, "d_size_l_pos_ref", d_size_l_pos_ref, d_size_l_pos_ref_bench, "{return test(\"%ld\", l_pos_1);}"},
	{1, 623, "d_size_l_pos_ref_lmax", d_size_l_pos_ref_lmax, d_size_l_pos_ref_lmax_bench, "{return test(\"%ld\", lmax);}"},
	{1, 624, "d_size_ll_pos_ref_llmax", d_size_ll_pos_ref_llmax, d_size_ll_pos_ref_llmax_bench, "{return test(\"%lld\", llmax);}"},
	{1, 625, "d_size_l_neg_ref", d_size_l_neg_ref, d_size_l_neg_ref_bench, "{return test(\"%ld\", l_neg_1);}"},
	{1, 626, "d_size_ll_pos_ref", d_size_ll_pos_ref, d_size_ll_pos_ref_bench, "{return test(\"%lld\", ll_pos_1);}"},
	{1, 627, "d_size_ll_neg_ref", d_size_ll_neg_ref, d_size_ll_neg_ref_bench, "{return test(\"%lld\", ll_neg_1);}"},
	{1, 628, "d_size_l_pos_big", d_size_l_pos_big, d_size_l_pos_big_bench, "{return test(\"%ld\", 22337203685477);}"},
	{1, 629, "d_size_l_neg_big", d_size_l_neg_big, d_size_l_neg_big_bench, "{return test(\"%ld\", -22337203685477);}"},
	{1, 630, "d_size_ll_pos_big", d_size_ll_pos_big, d_size_ll_pos_big_bench, "{return test(\"%lld\", 522337203685470ll);}"},
	{1, 631, "d_size_ll_neg_big", d_size_ll_neg_big, d_size_ll_neg_big_bench, "{return test(\"%lld\", -522337203685470ll);}"},
	{1, 632, "d_llmax", d_llmax, d_llmax_bench, "{return test(\"%lld\", 9223372036854775807ll);}"},
	{1, 633, "d_llmin", d_llmin, d_llmin_bench, "{return test(\"%lld\", llmin);}"},
	{1, 634, "d_lmax", d_lmax, d_lmax_bench, "{return test(\"%ld\", 9223372036854775807l);}"},
	{1, 635, "d_lmin", d_lmin, d_lmin_bench, "{return test(\"%ld\", lmin);}"},
	{1, 636, "d_hmax", d_hmax, d_hmax_bench, "{return test(\"%hd\", (short)32767);}"},
	{1, 637, "d_hmin", d_hmin, d_hmin_bench, "{return test(\"%hd\", (short)(-32768));}"},
	{1, 638, "d_hhmax", d_hhmax, d_hhmax_bench, "{return test(\"%hhd\", (char)127);}"},
	{1, 639, "d_hhmin", d_hhmin, d_hhmin_bench, "{return test(\"%hhd\", (char)(-128));}"},
	{1, 640, "d_size_l_pos_big_zp", d_size_l_pos_big_zp, d_size_l_pos_big_zp_bench, "{return test(\"%037ld\", 22337203685477l);}"},
	{1, 641, "d_size_l_neg_big_prec", d_size_l_neg_big_prec, d_size_l_neg_big_prec_bench, "{return test(\"%.37ld\", -22337203685477l);}"},
	{1, 642, "d_size_ll_pos_big_width", d_size_ll_pos_big_width, d_size_ll_pos_big_width_bench, "{return test(\"%37lld\", 522337203685470ll);}"},
	{1, 643, "d_size_ll_neg_big_lj", d_size_ll_neg_big_lj, d_size_ll_neg_big_lj_bench, "{return test(\"%-37lld\", -522337203685470ll);}"},
	{1, 644, "d_size_l_pos_big_as", d_size_l_pos_big_as, d_size_l_pos_big_as_bench, "{return test(\"%+ld\", 22337203685477l);}"},
	{1, 645, "d_size_follows_i_i", d_size_follows_i_i, d_size_follows_i_i_bench, "{return test(\"[%d] [%d]\", i_pos_1, i_pos_1);}"},
	{1, 646, "d_size_follows_i_l", d_size_follows_i_l, d_size_follows_i_l_bench, "{return test(\"[%d] [%ld]\", i_pos_1, l_pos_1);}"},
	{1, 647, "d_size_follows_i_ll", d_size_follows_i_ll, d_size_follows_i_ll_bench, "{return test(\"[%d] [%lld]\", i_pos_1, ll_pos_1);}"},
	{1, 648, "d_size_follows_i_h", d_size_follows_i_h, d_size_follows_i_h_bench, "{return test(\"[%d] [%hd]\", i_pos_1, sh_pos_1);}"},
	{1, 649, "d_size_follows_i_hh", d_size_follows_i_hh, d_size_follows_i_hh_bench, "{return test(\"[%d] [%hhd]\", i_pos_1, ch_pos_1);}"},
	{1, 650, "d_size_ll_hh_ll", d_size_ll_hh_ll, d_size_ll_hh_ll_bench, "{return test(\"%lld%hhd%lld\", ll_pos_1, ch_neg_1, ll_neg_1);}"},
	{1, 651, "d_size_h_l_hh", d_size_h_l_hh, d_size_h_l_hh_bench, "{return test(\"%hd%ld%hhd\", sh_pos_1, l_neg_1, ch_neg_1);}"},
	{1, 652, "d_size_l_hh_h", d_size_l_hh_h, d_size_l_hh_h_bench, "{return test(\"%ld%hhd%hd\", l_neg_1, ch_pos_1, sh_pos_1);}"},
	{1, 653, "d_size_n_ll_hh", d_size_n_ll_hh, d_size_n_ll_hh_bench, "{return test(\"%d%lld%hhd\", i_pos_1, ll_neg_1, ch_pos_1);}"},
	{1, 654, "d_size_ll_n_l", d_size_ll_n_l, d_size_ll_n_l_bench, "{return test(\"%lli%d%ld\", ll_neg_1, i_pos_1, l_pos_1);}"},
	{1, 655, "d_basic_i_pos_sp", d_basic_i_pos_sp, d_basic_i_pos_sp_bench, "{return test(\"this % d number\", 17);}"},
	{1, 656, "d_basic_i_neg_sp", d_basic_i_neg_sp, d_basic_i_neg_sp_bench, "{return test(\"this % d number\", -267);}"},
	{1, 657, "d_basic_i_zero_sp", d_basic_i_zero_sp, d_basic_i_zero_sp_bench, "{return test(\"this % d number\", 0);}"},
	{1, 658, "d_basic_i_onlypos_sp", d_basic_i_onlypos_sp, d_basic_i_onlypos_sp_bench, "{return test(\"% d\", 3);}"},
	{1, 659, "d_basic_i_onlyneg_sp", d_basic_i_onlyneg_sp, d_basic_i_onlyneg_sp_bench, "{return test(\"% d\", -1);}"},
	{1, 660, "d_basic_i_onlyzero_sp", d_basic_i_onlyzero_sp, d_basic_i_onlyzero_sp_bench, "{return test(\"% d\", 0);}"},
	{1, 661, "d_basic_i_pos_d_sp", d_basic_i_pos_d_sp, d_basic_i_pos_d_sp_bench, "{return test(\"this % d number\", 17);}"},
	{1, 662, "d_basic_i_neg_d_sp", d_basic_i_neg_d_sp, d_basic_i_neg_d_sp_bench, "{return test(\"this % d number\", -267);}"},
	{1, 663, "d_basic_i_zero_d_sp", d_basic_i_zero_d_sp, d_basic_i_zero_d_sp_bench, "{return test(\"this % d number\", 0);}"},
	{1, 664, "d_intmax_sp", d_intmax_sp, d_intmax_sp_bench, "{return test(\"% d\", 2147483647);}"},
	{1, 665, "d_intmin_sp", d_intmin_sp, d_intmin_sp_bench, "{return test(\"% d\", (int)(-2147483678));}"},
	{1, 666, "d_assp_pos_ignoreflag", d_assp_pos_ignoreflag, d_assp_pos_ignoreflag_bench, "{return test(\"% +d\", 5);}"},
	{1, 667, "d_assp_neg_ignoreflag", d_assp_neg_ignoreflag, d_assp_neg_ignoreflag_bench, "{return test(\"% +d\", -7);}"},
	{1, 668, "d_intmax_assp_ignoreflag", d_intmax_assp_ignoreflag, d_intmax_assp_ignoreflag_bench, "{return test(\"% +d\", 2147483647);}"},
	{1, 669, "d_width_pos_fits_sp", d_width_pos_fits_sp, d_width_pos_fits_sp_bench, "{return test(\"% 7d\", 33);}"},
	{1, 670, "d_width_neg_fits_sp", d_width_neg_fits_sp, d_width_neg_fits_sp_bench, "{return test(\"% 7d\", -14);}"},
	{1, 671, "d_width_zero_fits_sp", d_width_zero_fits_sp, d_width_zero_fits_sp_bench, "{return test(\"% 3d\", 0);}"},
	{1, 672, "d_width_pos_exactfit_sp", d_width_pos_exactfit_sp, d_width_pos_exactfit_sp_bench, "{return test(\"% 5d\", 52625);}"},
	{1, 673, "d_width_neg_exactfit_sp", d_width_neg_exactfit_sp, d_width_neg_exactfit_sp_bench, "{return test(\"% 5d\", -2562);}"},
	{1, 674, "d_width_pos_nofit_sp", d_width_pos_nofit_sp, d_width_pos_nofit_sp_bench, "{return test(\"% 4d\", 94827);}"},
	{1, 675, "d_width_neg_nofit_sp", d_width_neg_nofit_sp, d_width_neg_nofit_sp_bench, "{return test(\"% 4d\", -2464);}"},
	{1, 676, "d_width_pos_fits_lj_sp", d_width_pos_fits_lj_sp, d_width_pos_fits_lj_sp_bench, "{return test(\"% -7d\", 33);}"},
	{1, 677, "d_width_neg_fits_lj_sp", d_width_neg_fits_lj_sp, d_width_neg_fits_lj_sp_bench, "{return test(\"% -7d\", -14);}"},
	{1, 678, "d_width_zero_fits_lj_sp", d_width_zero_fits_lj_sp, d_width_zero_fits_lj_sp_bench, "{return test(\"% -3d\", 0);}"},
	{1, 679, "d_width_pos_exactfit_lj_sp", d_width_pos_exactfit_lj_sp, d_width_pos_exactfit_lj_sp_bench, "{return test(\"% -5d\", 52625);}"},
	{1, 680, "d_width_neg_exactfit_lj_sp", d_width_neg_exactfit_lj_sp, d_width_neg_exactfit_lj_sp_bench, "{return test(\"% -5d\", -2562);}"},
	{1, 681, "d_width_pos_nofit_lj_sp", d_width_pos_nofit_lj_sp, d_width_pos_nofit_lj_sp_bench, "{return test(\"% -4d\", 94827);}"},
	{1, 682, "d_width_neg_nofit_lj_sp", d_width_neg_nofit_lj_sp, d_width_neg_nofit_lj_sp_bench, "{return test(\"% -4d\", -2464);}"},
	{1, 683, "d_width_assp_pos_ignoreflag", d_width_assp_pos_ignoreflag, d_width_assp_pos_ignoreflag_bench, "{return test(\"% +5d\", 35);}"},
	{1, 684, "d_width_assp_zero_ignoreflag", d_width_assp_zero_ignoreflag, d_width_assp_zero_ignoreflag_bench, "{return test(\"% +7d\", 0);}"},
	{1, 685, "d_width_intmax_assp_ignoreflag", d_width_intmax_assp_ignoreflag, d_width_intmax_assp_ignoreflag_bench, "{return test(\"% +24d\", 2147483647);}"},
	{1, 686, "d_prec_fits_pos_sp", d_prec_fits_pos_sp, d_prec_fits_pos_sp_bench, "{return test(\"% .5d\", 2);}"},
	{1, 687, "d_prec_fits_neg_sp", d_prec_fits_neg_sp, d_prec_fits_neg_sp_bench, "{return test(\"% .6d\", -3);}"},
	{1, 688, "d_prec_fits_zero_sp", d_prec_fits_zero_sp, d_prec_fits_zero_sp_bench, "{return test(\"% .3d\", 0);}"},
	{1, 689, "d_prec_exactfit_pos_sp", d_prec_exactfit_pos_sp, d_prec_exactfit_pos_sp_bench, "{return test(\"% .4d\", 5263);}"},
	{1, 690, "d_prec_exactfit_neg_sp", d_prec_exactfit_neg_sp, d_prec_exactfit_neg_sp_bench, "{return test(\"% .4d\", -2372);}"},
	{1, 691, "d_prec_nofit_pos_sp", d_prec_nofit_pos_sp, d_prec_nofit_pos_sp_bench, "{return test(\"% .3d\", 13862);}"},
	{1, 692, "d_prec_nofit_neg_sp", d_prec_nofit_neg_sp, d_prec_nofit_neg_sp_bench, "{return test(\"% .3d\",-23646);}"},
	{1, 693, "d_prec_assp_pos_ignoreflag", d_prec_assp_pos_ignoreflag, d_prec_assp_pos_ignoreflag_bench, "{return test(\"% +.7d\", 234);}"},
	{1, 694, "d_prec_assp_neg_ignoreflag", d_prec_assp_neg_ignoreflag, d_prec_assp_neg_ignoreflag_bench, "{return test(\"% +.7d\", -446);}"},
	{1, 695, "d_prec_assp_pos_nofit_ignoreflag", d_prec_assp_pos_nofit_ignoreflag, d_prec_assp_pos_nofit_ignoreflag_bench, "{return test(\"% +.3d\", 3723);}"},
	{1, 696, "d_zpsp_pos_fits", d_zpsp_pos_fits, d_zpsp_pos_fits_bench, "{return test(\"% 05d\", 43);}"},
	{1, 697, "d_zpsp_neg_fits", d_zpsp_neg_fits, d_zpsp_neg_fits_bench, "{return test(\"% 07d\", -54);}"},
	{1, 698, "d_zpsp_zero_fits", d_zpsp_zero_fits, d_zpsp_zero_fits_bench, "{return test(\"% 03d\", 0);}"},
	{1, 699, "d_zpsp_pos_exactfit", d_zpsp_pos_exactfit, d_zpsp_pos_exactfit_bench, "{return test(\"% 03d\", 634);}"},
	{1, 700, "d_zpsp_neg_exactfit", d_zpsp_neg_exactfit, d_zpsp_neg_exactfit_bench, "{return test(\"% 04d\", -532);}"},
	{1, 701, "d_zpsp_neg_minus1fit", d_zpsp_neg_minus1fit, d_zpsp_neg_minus1fit_bench, "{return test(\"% 04d\", -4825);}"},
	{1, 702, "d_zpassp_as_fits_ignoreflag", d_zpassp_as_fits_ignoreflag, d_zpassp_as_fits_ignoreflag_bench, "{return test(\"% +05d\", 432);}"},
	{1, 703, "d_zpassp_zero_ignoreflag", d_zpassp_zero_ignoreflag, d_zpassp_zero_ignoreflag_bench, "{return test(\"% +04d\", 0);}"},
	{1, 704, "d_prec_width_fit_fit_pos_sp", d_prec_width_fit_fit_pos_sp, d_prec_width_fit_fit_pos_sp_bench, "{return test(\"% 8.5d\", 34);}"},
	{1, 705, "d_prec_width_fit_fit_neg_sp", d_prec_width_fit_fit_neg_sp, d_prec_width_fit_fit_neg_sp_bench, "{return test(\"% 10.5d\", -216);}"},
	{1, 706, "d_prec_width_fit_fit_zero_sp", d_prec_width_fit_fit_zero_sp, d_prec_width_fit_fit_zero_sp_bench, "{return test(\"% 8.5d\", 0);}"},
	{1, 707, "d_prec_width_nofit_fit_pos_sp", d_prec_width_nofit_fit_pos_sp, d_prec_width_nofit_fit_pos_sp_bench, "{return test(\"% 8.3d\", 8375);}"},
	{1, 708, "d_prec_width_nofit_fit_neg_sp", d_prec_width_nofit_fit_neg_sp, d_prec_width_nofit_fit_neg_sp_bench, "{return test(\"% 8.3d\", -8473);}"},
	{1, 709, "d_prec_width_fit_nofit_pos_sp", d_prec_width_fit_nofit_pos_sp, d_prec_width_fit_nofit_pos_sp_bench, "{return test(\"% 3.7d\", 3267);}"},
	{1, 710, "d_prec_width_fit_nofit_neg_sp", d_prec_width_fit_nofit_neg_sp, d_prec_width_fit_nofit_neg_sp_bench, "{return test(\"% 3.7d\", -2375);}"},
	{1, 711, "d_prec_width_nofit_nofit_pos_sp", d_prec_width_nofit_nofit_pos_sp, d_prec_width_nofit_nofit_pos_sp_bench, "{return test(\"% 3.3d\", 6983);}"},
	{1, 712, "d_prec_width_nofit_nofit_neg_sp", d_prec_width_nofit_nofit_neg_sp, d_prec_width_nofit_nofit_neg_sp_bench, "{return test(\"% 3.3d\", -8462);}"},
	{1, 713, "d_prec_width_fit_fit_pos_lj_sp", d_prec_width_fit_fit_pos_lj_sp, d_prec_width_fit_fit_pos_lj_sp_bench, "{return test(\"% -8.5d\", 34);}"},
	{1, 714, "d_prec_width_fit_fit_neg_lj_sp", d_prec_width_fit_fit_neg_lj_sp, d_prec_width_fit_fit_neg_lj_sp_bench, "{return test(\"% -10.5d\", -216);}"},
	{1, 715, "d_prec_width_fit_fit_zero_lj_sp", d_prec_width_fit_fit_zero_lj_sp, d_prec_width_fit_fit_zero_lj_sp_bench, "{return test(\"% -8.5d\", 0);}"},
	{1, 716, "d_prec_width_nofit_fit_pos_lj_sp", d_prec_width_nofit_fit_pos_lj_sp, d_prec_width_nofit_fit_pos_lj_sp_bench, "{return test(\"% -8.3d\", 8375);}"},
	{1, 717, "d_prec_width_nofit_fit_neg_lj_sp", d_prec_width_nofit_fit_neg_lj_sp, d_prec_width_nofit_fit_neg_lj_sp_bench, "{return test(\"% -8.3d\", -8473);}"},
	{1, 718, "d_prec_width_fit_nofit_pos_lj_sp", d_prec_width_fit_nofit_pos_lj_sp, d_prec_width_fit_nofit_pos_lj_sp_bench, "{return test(\"% -3.7d\", 3267);}"},
	{1, 719, "d_prec_width_fit_nofit_neg_lj_sp", d_prec_width_fit_nofit_neg_lj_sp, d_prec_width_fit_nofit_neg_lj_sp_bench, "{return test(\"% -3.7d\", -2375);}"},
	{1, 720, "d_prec_width_nofit_nofit_pos_lj_sp", d_prec_width_nofit_nofit_pos_lj_sp, d_prec_width_nofit_nofit_pos_lj_sp_bench, "{return test(\"% -3.3d\", 6983);}"},
	{1, 721, "d_prec_width_nofit_nofit_neg_lj_sp", d_prec_width_nofit_nofit_neg_lj_sp, d_prec_width_nofit_nofit_neg_lj_sp_bench, "{return test(\"% -3.3d\", -8462);}"},
	{1, 722, "d_prec_width_fit_fit_pos_assp_ignoreflag", d_prec_width_fit_fit_pos_assp_ignoreflag, d_prec_width_fit_fit_pos_assp_ignoreflag_bench, "{return test(\"% +8.5d\", 34);}"},
	{1, 723, "d_prec_width_fit_fit_neg_assp_ignoreflag", d_prec_width_fit_fit_neg_assp_ignoreflag, d_prec_width_fit_fit_neg_assp_ignoreflag_bench, "{return test(\"% +10.5d\", -216);}"},
	{1, 724, "d_prec_width_fit_fit_zero_assp_ignoreflag", d_prec_width_fit_fit_zero_assp_ignoreflag, d_prec_width_fit_fit_zero_assp_ignoreflag_bench, "{return test(\"% +8.5d\", 0);}"},
	{1, 725, "d_prec_width_nofit_fit_pos_assp_ignoreflag", d_prec_width_nofit_fit_pos_assp_ignoreflag, d_prec_width_nofit_fit_pos_assp_ignoreflag_bench, "{return test(\"% +8.3d\", 8375);}"},
	{1, 726, "d_prec_width_nofit_fit_neg_assp_ignoreflag", d_prec_width_nofit_fit_neg_assp_ignoreflag, d_prec_width_nofit_fit_neg_assp_ignoreflag_bench, "{return test(\"% +8.3d\", -8473);}"},
	{1, 727, "d_prec_width_fit_nofit_pos_assp_ignoreflag", d_prec_width_fit_nofit_pos_assp_ignoreflag, d_prec_width_fit_nofit_pos_assp_ignoreflag_bench, "{return test(\"% +3.7d\", 3267);}"},
	{1, 728, "d_prec_width_fit_nofit_neg_assp_ignoreflag", d_prec_width_fit_nofit_neg_assp_ignoreflag, d_prec_width_fit_nofit_neg_assp_ignoreflag_bench, "{return test(\"% +3.7d\", -2375);}"},
	{1, 729, "d_prec_width_nofit_nofit_pos_assp_ignoreflag", d_prec_width_nofit_nofit_pos_assp_ignoreflag, d_prec_width_nofit_nofit_pos_assp_ignoreflag_bench, "{return test(\"% +3.3d\", 6983);}"},
	{1, 730, "d_prec_width_nofit_nofit_neg_assp_ignoreflag", d_prec_width_nofit_nofit_neg_assp_ignoreflag, d_prec_width_nofit_nofit_neg_assp_ignoreflag_bench, "{return test(\"% +3.3d\", -8462);}"},
	{1, 731, "d_prec_width_fit_fit_pos_lj_assp_ignoreflag", d_prec_width_fit_fit_pos_lj_assp_ignoreflag, d_prec_width_fit_fit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-8.5d\", 34);}"},
	{1, 732, "d_prec_width_fit_fit_neg_lj_assp_ignoreflag", d_prec_width_fit_fit_neg_lj_assp_ignoreflag, d_prec_width_fit_fit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-10.5d\", -216);}"},
	{1, 733, "d_prec_width_fit_fit_zero_lj_assp_ignoreflag", d_prec_width_fit_fit_zero_lj_assp_ignoreflag, d_prec_width_fit_fit_zero_lj_assp_ignoreflag_bench, "{return test(\"% +-8.5d\", 0);}"},
	{1, 734, "d_prec_width_nofit_fit_pos_lj_assp_ignoreflag", d_prec_width_nofit_fit_pos_lj_assp_ignoreflag, d_prec_width_nofit_fit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-8.3d\", 8375);}"},
	{1, 735, "d_prec_width_nofit_fit_neg_lj_assp_ignoreflag", d_prec_width_nofit_fit_neg_lj_assp_ignoreflag, d_prec_width_nofit_fit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-8.3d\", -8473);}"},
	{1, 736, "d_prec_width_fit_nofit_pos_lj_assp_ignoreflag", d_prec_width_fit_nofit_pos_lj_assp_ignoreflag, d_prec_width_fit_nofit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-3.7d\", 3267);}"},
	{1, 737, "d_prec_width_fit_nofit_neg_lj_assp_ignoreflag", d_prec_width_fit_nofit_neg_lj_assp_ignoreflag, d_prec_width_fit_nofit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-3.7d\", -2375);}"},
	{1, 738, "d_prec_width_nofit_nofit_pos_lj_assp_ignoreflag", d_prec_width_nofit_nofit_pos_lj_assp_ignoreflag, d_prec_width_nofit_nofit_pos_lj_assp_ignoreflag_bench, "{return test(\"% +-3.3d\", 6983);}"},
	{1, 739, "d_prec_width_nofit_nofit_neg_lj_assp_ignoreflag", d_prec_width_nofit_nofit_neg_lj_assp_ignoreflag, d_prec_width_nofit_nofit_neg_lj_assp_ignoreflag_bench, "{return test(\"% +-3.3d\", -8462);}"},
	{1, 740, "d_prec_width_ff_pos_zp_sp", d_prec_width_ff_pos_zp_sp, d_prec_width_ff_pos_zp_sp_bench, "{return test(\"% 08.5d\", 34);}"},
	{1, 741, "d_prec_width_ff_neg_zp_sp", d_prec_width_ff_neg_zp_sp, d_prec_width_ff_neg_zp_sp_bench, "{return test(\"% 010.5d\", -216);}"},
	{1, 742, "d_prec_width_ff_zero_zp_sp", d_prec_width_ff_zero_zp_sp, d_prec_width_ff_zero_zp_sp_bench, "{return test(\"% 08.5d\", 0);}"},
	{1, 743, "d_prec_width_nf_pos_zp_sp", d_prec_width_nf_pos_zp_sp, d_prec_width_nf_pos_zp_sp_bench, "{return test(\"% 08.3d\", 8375);}"},
	{1, 744, "d_prec_width_nf_neg_zp_sp", d_prec_width_nf_neg_zp_sp, d_prec_width_nf_neg_zp_sp_bench, "{return test(\"% 08.3d\", -8473);}"},
	{1, 745, "d_prec_width_fn_pos_zp_sp", d_prec_width_fn_pos_zp_sp, d_prec_width_fn_pos_zp_sp_bench, "{return test(\"% 03.7d\", 3267);}"},
	{1, 746, "d_prec_width_fn_neg_zp_sp", d_prec_width_fn_neg_zp_sp, d_prec_width_fn_neg_zp_sp_bench, "{return test(\"% 03.7d\", -2375);}"},
	{1, 747, "d_prec_width_nn_pos_zp_sp", d_prec_width_nn_pos_zp_sp, d_prec_width_nn_pos_zp_sp_bench, "{return test(\"% 03.3d\", 6983);}"},
	{1, 748, "d_prec_width_nn_neg_zp_sp", d_prec_width_nn_neg_zp_sp, d_prec_width_nn_neg_zp_sp_bench, "{return test(\"% 03.3d\", -8462);}"},
	{1, 749, "d_prec_width_ff_pos_ljzpsp_ignoreflag", d_prec_width_ff_pos_ljzpsp_ignoreflag, d_prec_width_ff_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.5d\", 34);}"},
	{1, 750, "d_prec_width_ff_neg_ljzpsp_ignoreflag", d_prec_width_ff_neg_ljzpsp_ignoreflag, d_prec_width_ff_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-10.5d\", -216);}"},
	{1, 751, "d_prec_width_ff_zero_ljzpsp_ignoreflag", d_prec_width_ff_zero_ljzpsp_ignoreflag, d_prec_width_ff_zero_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.5d\", 0);}"},
	{1, 752, "d_prec_width_nf_pos_ljzpsp_ignoreflag", d_prec_width_nf_pos_ljzpsp_ignoreflag, d_prec_width_nf_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.3d\", 8375);}"},
	{1, 753, "d_prec_width_nf_neg_ljzpsp_ignoreflag", d_prec_width_nf_neg_ljzpsp_ignoreflag, d_prec_width_nf_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-8.3d\", -8473);}"},
	{1, 754, "d_prec_width_fn_pos_ljzpsp_ignoreflag", d_prec_width_fn_pos_ljzpsp_ignoreflag, d_prec_width_fn_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.7d\", 3267);}"},
	{1, 755, "d_prec_width_fn_neg_ljzpsp_ignoreflag", d_prec_width_fn_neg_ljzpsp_ignoreflag, d_prec_width_fn_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.7d\", -2375);}"},
	{1, 756, "d_prec_width_nn_pos_ljzpsp_ignoreflag", d_prec_width_nn_pos_ljzpsp_ignoreflag, d_prec_width_nn_pos_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.3d\", 6983);}"},
	{1, 757, "d_prec_width_nn_neg_ljzpsp_ignoreflag", d_prec_width_nn_neg_ljzpsp_ignoreflag, d_prec_width_nn_neg_ljzpsp_ignoreflag_bench, "{return test(\"% 0-3.3d\", -8462);}"},
	{1, 758, "d_prec_width_ff_pos_aszpsp_ignoreflag", d_prec_width_ff_pos_aszpsp_ignoreflag, d_prec_width_ff_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.5d\", 34);}"},
	{1, 759, "d_prec_width_ff_neg_aszpsp_ignoreflag", d_prec_width_ff_neg_aszpsp_ignoreflag, d_prec_width_ff_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+10.5d\", -216);}"},
	{1, 760, "d_prec_width_ff_zero_aszpsp_ignoreflag", d_prec_width_ff_zero_aszpsp_ignoreflag, d_prec_width_ff_zero_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.5d\", 0);}"},
	{1, 761, "d_prec_width_nf_pos_aszpsp_ignoreflag", d_prec_width_nf_pos_aszpsp_ignoreflag, d_prec_width_nf_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.3d\", 8375);}"},
	{1, 762, "d_prec_width_nf_neg_aszpsp_ignoreflag", d_prec_width_nf_neg_aszpsp_ignoreflag, d_prec_width_nf_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+8.3d\", -8473);}"},
	{1, 763, "d_prec_width_fn_pos_aszpsp_ignoreflag", d_prec_width_fn_pos_aszpsp_ignoreflag, d_prec_width_fn_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.7d\", 3267);}"},
	{1, 764, "d_prec_width_fn_neg_aszpsp_ignoreflag", d_prec_width_fn_neg_aszpsp_ignoreflag, d_prec_width_fn_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.7d\", -2375);}"},
	{1, 765, "d_prec_width_nn_pos_aszpsp_ignoreflag", d_prec_width_nn_pos_aszpsp_ignoreflag, d_prec_width_nn_pos_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.3d\", 6983);}"},
	{1, 766, "d_prec_width_nn_neg_aszpsp_ignoreflag", d_prec_width_nn_neg_aszpsp_ignoreflag, d_prec_width_nn_neg_aszpsp_ignoreflag_bench, "{return test(\"% 0+3.3d\", -8462);}"},
	{1, 767, "d_prec_width_ff_pos_ljaszpsp_ignoreflag", d_prec_width_ff_pos_ljaszpsp_ignoreflag, d_prec_width_ff_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.5d\", 34);}"},
	{1, 768, "d_prec_width_ff_neg_ljaszpsp_ignoreflag", d_prec_width_ff_neg_ljaszpsp_ignoreflag, d_prec_width_ff_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-10.5d\", -216);}"},
	{1, 769, "d_prec_width_ff_zero_ljaszpsp_ignoreflag", d_prec_width_ff_zero_ljaszpsp_ignoreflag, d_prec_width_ff_zero_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.5d\", 0);}"},
	{1, 770, "d_prec_width_nf_pos_ljaszpsp_ignoreflag", d_prec_width_nf_pos_ljaszpsp_ignoreflag, d_prec_width_nf_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.3d\", 8375);}"},
	{1, 771, "d_prec_width_nf_neg_ljaszpsp_ignoreflag", d_prec_width_nf_neg_ljaszpsp_ignoreflag, d_prec_width_nf_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-8.3d\", -8473);}"},
	{1, 772, "d_prec_width_fn_pos_ljaszpsp_ignoreflag", d_prec_width_fn_pos_ljaszpsp_ignoreflag, d_prec_width_fn_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.7d\", 3267);}"},
	{1, 773, "d_prec_width_fn_neg_ljaszpsp_ignoreflag", d_prec_width_fn_neg_ljaszpsp_ignoreflag, d_prec_width_fn_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.7d\", -2375);}"},
	{1, 774, "d_prec_width_nn_pos_ljaszpsp_ignoreflag", d_prec_width_nn_pos_ljaszpsp_ignoreflag, d_prec_width_nn_pos_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.3d\", 6983);}"},
	{1, 775, "d_prec_width_nn_neg_ljaszpsp_ignoreflag", d_prec_width_nn_neg_ljaszpsp_ignoreflag, d_prec_width_nn_neg_ljaszpsp_ignoreflag_bench, "{return test(\"% 0+-3.3d\", -8462);}"},
	{1, 776, "d_size_hh_pos_casted_sp", d_size_hh_pos_casted_sp, d_size_hh_pos_casted_sp_bench, "{return test(\"% hhd\", (char)45);}"},
	{1, 777, "d_size_hh_neg_casted_sp", d_size_hh_neg_casted_sp, d_size_hh_neg_casted_sp_bench, "{return test(\"% hhd\", (char)-45);}"},
	{1, 778, "d_size_h_pos_casted_sp", d_size_h_pos_casted_sp, d_size_h_pos_casted_sp_bench, "{return test(\"% hd\", (short)385);}"},
	{1, 779, "d_size_h_neg_casted_sp", d_size_h_neg_casted_sp, d_size_h_neg_casted_sp_bench, "{return test(\"% hd\", (short)-385);}"},
	{1, 780, "d_size_l_pos_casted_sp", d_size_l_pos_casted_sp, d_size_l_pos_casted_sp_bench, "{return test(\"% ld\", (long)32);}"},
	{1, 781, "d_size_l_neg_casted_sp", d_size_l_neg_casted_sp, d_size_l_neg_casted_sp_bench, "{return test(\"% ld\", (long)-32);}"},
	{1, 782, "d_size_ll_pos_casted_sp", d_size_ll_pos_casted_sp, d_size_ll_pos_casted_sp_bench, "{return test(\"% lld\", (long long)43);}"},
	{1, 783, "d_size_ll_neg_casted_sp", d_size_ll_neg_casted_sp, d_size_ll_neg_casted_sp_bench, "{return test(\"% lld\", (long long)-43);}"},
	{1, 784, "d_size_hh_pos_ref_sp", d_size_hh_pos_ref_sp, d_size_hh_pos_ref_sp_bench, "{return test(\"% hhd\", ch_pos_1);}"},
	{1, 785, "d_size_hh_neg_ref_sp", d_size_hh_neg_ref_sp, d_size_hh_neg_ref_sp_bench, "{return test(\"% hhd\", ch_neg_1);}"},
	{1, 786, "d_size_h_pos_ref_sp", d_size_h_pos_ref_sp, d_size_h_pos_ref_sp_bench, "{return test(\"% hd\", sh_pos_1);}"},
	{1, 787, "d_size_h_neg_ref_sp", d_size_h_neg_ref_sp, d_size_h_neg_ref_sp_bench, "{return test(\"% hd\", sh_neg_1);}"},
	{1, 788, "d_size_l_pos_ref_sp", d_size_l_pos_ref_sp, d_size_l_pos_ref_sp_bench, "{return test(\"% ld\", l_pos_1);}"},
	{1, 789, "d_size_l_neg_ref_sp", d_size_l_neg_ref_sp, d_size_l_neg_ref_sp_bench, "{return test(\"% ld\", l_neg_1);}"},
	{1, 790, "d_size_ll_pos_ref_sp", d_size_ll_pos_ref_sp, d_size_ll_pos_ref_sp_bench, "{return test(\"% lld\", ll_pos_1);}"},
	{1, 791, "d_size_ll_neg_ref_sp", d_size_ll_neg_ref_sp, d_size_ll_neg_ref_sp_bench, "{return test(\"% lld\", ll_neg_1);}"},
	{1, 792, "d_size_l_pos_big_sp", d_size_l_pos_big_sp, d_size_l_pos_big_sp_bench, "{return test(\"% ld\", 22337203685477l);}"},
	{1, 793, "d_size_l_neg_big_sp", d_size_l_neg_big_sp, d_size_l_neg_big_sp_bench, "{return test(\"% ld\", -22337203685477l);}"},
	{1, 794, "d_size_ll_pos_big_sp", d_size_ll_pos_big_sp, d_size_ll_pos_big_sp_bench, "{return test(\"% lld\", 522337203685470ll);}"},
	{1, 795, "d_size_ll_neg_big_sp", d_size_ll_neg_big_sp, d_size_ll_neg_big_sp_bench, "{return test(\"% lld\", -522337203685470ll);}"},
	{1, 796, "d_llmax_sp", d_llmax_sp, d_llmax_sp_bench, "{return test(\"% lld\", 9223372036854775807ll);}"},
	{1, 797, "d_llmin_sp", d_llmin_sp, d_llmin_sp_bench, "{return test(\"% lld\", llmin);}"},
	{1, 798, "d_lmax_sp", d_lmax_sp, d_lmax_sp_bench, "{return test(\"% ld\", 9223372036854775807l);}"},
	{1, 799, "d_lmin_sp", d_lmin_sp, d_lmin_sp_bench, "{return test(\"% ld\", lmin);}"},
	{1, 800, "d_hmax_sp", d_hmax_sp, d_hmax_sp_bench, "{return test(\"% hd\", (short)32767);}"},
	{1, 801, "d_hmin_sp", d_hmin_sp, d_hmin_sp_bench, "{return test(\"% hd\", (short)(-32768));}"},
	{1, 802, "d_hhmax_sp", d_hhmax_sp, d_hhmax_sp_bench, "{return test(\"% hhd\", (char)(127));}"},
	{1, 803, "d_hhmin_sp", d_hhmin_sp, d_hhmin_sp_bench, "{return test(\"% hhd\", (char)(-128));}"},
	{1, 804, "d_prec0val0_basic", d_prec0val0_basic, d_prec0val0_basic_bench, "{return test(\"%.0d\", 0);}"},
	{1, 805, "d_prec0val0_implicit", d_prec0val0_implicit, d_prec0val0_implicit_bench, "{return test(\"%.d\", 0);}"},
	{1, 806, "d_prec0val0_w", d_prec0val0_w, d_prec0val0_w_bench, "{return test(\"%5.0d\", 0);}"},
	{1, 807, "d_prec0val0_w_impl", d_prec0val0_w_impl, d_prec0val0_w_impl_bench, "{return test(\"%5.d\", 0);}"},
	{1, 808, "d_prec0val0_wlj", d_prec0val0_wlj, d_prec0val0_wlj_bench, "{return test(\"%-5.0d\", 0);}"},
	{1, 809, "d_prec0val0_wlj_impl", d_prec0val0_wlj_impl, d_prec0val0_wlj_impl_bench, "{return test(\"%-5.d\", 0);}"},
	{1, 810, "d_prec0val0_as", d_prec0val0_as, d_prec0val0_as_bench, "{return test(\"%+.0d\", 0);}"},
	{1, 811, "d_prec0val0_as_impl", d_prec0val0_as_impl, d_prec0val0_as_impl_bench, "{return test(\"%+.d\", 0);}"},
	{1, 812, "d_prec0val0_was", d_prec0val0_was, d_prec0val0_was_bench, "{return test(\"%+5.0d\", 0);}"},
	{1, 813, "d_prec0val0_was_impl", d_prec0val0_was_impl, d_prec0val0_was_impl_bench, "{return test(\"%+5.d\", 0);}"},
	{1, 814, "d_prec0val0_waslj", d_prec0val0_waslj, d_prec0val0_waslj_bench, "{return test(\"%+-5.0d\", 0);}"},
	{1, 815, "d_prec0val0_waslj_impl", d_prec0val0_waslj_impl, d_prec0val0_waslj_impl_bench, "{return test(\"%+-5.d\", 0);}"},
	{1, 816, "mix_hhi_str_lli_str", mix_hhi_str_lli_str, mix_hhi_str_lli_str_bench, "{return test(\"%hhi%s%lli%s\", ch_pos_1, str_3, ll_neg_1, str_2);}"},
	{1, 817, "mix_str_hi_str_li", mix_str_hi_str_li, mix_str_hi_str_li_bench, "{return test(\"%s%hi%s%li\", str_1, sh_neg_1, str_3, l_neg_1);}"},
	{1, 818, "mix_str_hi_str_li_emptystr", mix_str_hi_str_li_emptystr, mix_str_hi_str_li_emptystr_bench, "{return test(\"%s%hi%s%li\", str_empty, sh_neg_1, str_3, l_neg_1);}"},
	{1, 819, "u_basic_u_pos", u_basic_u_pos, u_basic_u_pos_bench, "{return test(\"this %u number\", 17);}"},
	{1, 820, "u_basic_u_zero", u_basic_u_zero, u_basic_u_zero_bench, "{return test(\"this %u number\", 0);}"},
	{1, 821, "u_basic_u_onlypos", u_basic_u_onlypos, u_basic_u_onlypos_bench, "{return test(\"%u\", 3);}"},
	{1, 822, "u_uintmax", u_uintmax, u_uintmax_bench, "{return test(\"%u\", 4294967295u);}"},
	{1, 823, "u_width_pos_fits", u_width_pos_fits, u_width_pos_fits_bench, "{return test(\"%7u\", 33);}"},
	{1, 824, "u_width_zero_fits", u_width_zero_fits, u_width_zero_fits_bench, "{return test(\"%3u\", 0);}"},
	{1, 825, "u_width_pos_exactfit", u_width_pos_exactfit, u_width_pos_exactfit_bench, "{return test(\"%5u\", 52625);}"},
	{1, 826, "u_width_pos_nofit", u_width_pos_nofit, u_width_pos_nofit_bench, "{return test(\"%4u\", 94827);}"},
	{1, 827, "u_width_pos_fits_lj", u_width_pos_fits_lj, u_width_pos_fits_lj_bench, "{return test(\"%-7u\", 33);}"},
	{1, 828, "u_width_zero_fits_lj", u_width_zero_fits_lj, u_width_zero_fits_lj_bench, "{return test(\"%-3u\", 0);}"},
	{1, 829, "u_width_pos_exactfit_lj", u_width_pos_exactfit_lj, u_width_pos_exactfit_lj_bench, "{return test(\"%-5u\", 52625);}"},
	{1, 830, "u_width_pos_nofit_lj", u_width_pos_nofit_lj, u_width_pos_nofit_lj_bench, "{return test(\"%-4u\", 94827);}"},
	{1, 831, "u_prec_fits_pos", u_prec_fits_pos, u_prec_fits_pos_bench, "{return test(\"%.5u\", 2);}"},
	{1, 832, "u_prec_fits_zero", u_prec_fits_zero, u_prec_fits_zero_bench, "{return test(\"%.3u\", 0);}"},
	{1, 833, "u_prec_exactfit_pos", u_prec_exactfit_pos, u_prec_exactfit_pos_bench, "{return test(\"%.4u\", 5263);}"},
	{1, 834, "u_prec_nofit_pos", u_prec_nofit_pos, u_prec_nofit_pos_bench, "{return test(\"%.3u\", 13862);}"},
	{1, 835, "u_zp_pos_fits", u_zp_pos_fits, u_zp_pos_fits_bench, "{return test(\"%05u\", 43);}"},
	{1, 836, "u_zp_zero_fits", u_zp_zero_fits, u_zp_zero_fits_bench, "{return test(\"%03u\", 0);}"},
	{1, 837, "u_zp_pos_exactfit", u_zp_pos_exactfit, u_zp_pos_exactfit_bench, "{return test(\"%03u\", 634);}"},
	{1, 838, "u_prec_width_fit_fit_pos", u_prec_width_fit_fit_pos, u_prec_width_fit_fit_pos_bench, "{return test(\"%8.5u\", 34);}"},
	{1, 839, "u_prec_width_fit_fit_zero", u_prec_width_fit_fit_zero, u_prec_width_fit_fit_zero_bench, "{return test(\"%8.5u\", 0);}"},
	{1, 840, "u_prec_width_nofit_fit_pos", u_prec_width_nofit_fit_pos, u_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3u\", 8375);}"},
	{1, 841, "u_prec_width_fit_nofit_pos", u_prec_width_fit_nofit_pos, u_prec_width_fit_nofit_pos_bench, "{return test(\"%3.7u\", 3267);}"},
	{1, 842, "u_prec_width_nofit_nofit_pos", u_prec_width_nofit_nofit_pos, u_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3u\", 6983);}"},
	{1, 843, "u_prec_width_fit_fit_pos_lj", u_prec_width_fit_fit_pos_lj, u_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5u\", 34);}"},
	{1, 844, "u_prec_width_fit_fit_zero_lj", u_prec_width_fit_fit_zero_lj, u_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5u\", 0);}"},
	{1, 845, "u_prec_width_nofit_fit_pos_lj", u_prec_width_nofit_fit_pos_lj, u_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3u\", 8375);}"},
	{1, 846, "u_prec_width_fit_nofit_pos_lj", u_prec_width_fit_nofit_pos_lj, u_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-3.7u\", 3267);}"},
	{1, 847, "u_prec_width_nofit_nofit_pos_lj", u_prec_width_nofit_nofit_pos_lj, u_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3u\", 6983);}"},
	{1, 848, "u_prec_width_ff_pos_zp", u_prec_width_ff_pos_zp, u_prec_width_ff_pos_zp_bench, "{return test(\"%08.5u\", 34);}"},
	{1, 849, "u_prec_width_ff_zero_zp", u_prec_width_ff_zero_zp, u_prec_width_ff_zero_zp_bench, "{return test(\"%08.5u\", 0);}"},
	{1, 850, "u_prec_width_nf_pos_zp", u_prec_width_nf_pos_zp, u_prec_width_nf_pos_zp_bench, "{return test(\"%08.3u\", 8375);}"},
	{1, 851, "u_prec_width_fn_pos_zp", u_prec_width_fn_pos_zp, u_prec_width_fn_pos_zp_bench, "{return test(\"%03.7u\", 3267);}"},
	{1, 852, "u_prec_width_nn_pos_zp", u_prec_width_nn_pos_zp, u_prec_width_nn_pos_zp_bench, "{return test(\"%03.3u\", 6983);}"},
	{1, 853, "u_prec_width_ff_pos_ljzp_ignoreflag", u_prec_width_ff_pos_ljzp_ignoreflag, u_prec_width_ff_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.5u\", 34);}"},
	{1, 854, "u_prec_width_ff_zero_ljzp_ignoreflag", u_prec_width_ff_zero_ljzp_ignoreflag, u_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5u\", 0);}"},
	{1, 855, "u_prec_width_nf_pos_ljzp_ignoreflag", u_prec_width_nf_pos_ljzp_ignoreflag, u_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3u\", 8375);}"},
	{1, 856, "u_prec_width_fn_pos_ljzp_ignoreflag", u_prec_width_fn_pos_ljzp_ignoreflag, u_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.7u\", 3267);}"},
	{1, 857, "u_prec_width_nn_pos_ljzp_ignoreflag", u_prec_width_nn_pos_ljzp_ignoreflag, u_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3u\", 6983);}"},
	{1, 858, "u_size_hh_pos_casted", u_size_hh_pos_casted, u_size_hh_pos_casted_bench, "{return test(\"%hhu\", (unsigned char)45);}"},
	{1, 859, "u_size_h_pos_casted", u_size_h_pos_casted, u_size_h_pos_casted_bench, "{return test(\"%hu\", (unsigned short)385);}"},
	{1, 860, "u_size_l_pos_casted", u_size_l_pos_casted, u_size_l_pos_casted_bench, "{return test(\"%lu\", (unsigned long)32);}"},
	{1, 861, "u_size_ll_pos_casted", u_size_ll_pos_casted, u_size_ll_pos_casted_bench, "{return test(\"%llu\", (unsigned long long)43);}"},
	{1, 862, "u_size_hh_pos_ref", u_size_hh_pos_ref, u_size_hh_pos_ref_bench, "{return test(\"%hhu\", uch_pos_1);}"},
	{1, 863, "u_size_h_pos_ref", u_size_h_pos_ref, u_size_h_pos_ref_bench, "{return test(\"%hu\", ush_pos_1);}"},
	{1, 864, "u_size_l_pos_ref", u_size_l_pos_ref, u_size_l_pos_ref_bench, "{return test(\"%lu\", ul_pos_1);}"},
	{1, 865, "u_size_ll_pos_ref", u_size_ll_pos_ref, u_size_ll_pos_ref_bench, "{return test(\"%llu\", ull_pos_1);}"},
	{1, 866, "u_size_l_pos_big", u_size_l_pos_big, u_size_l_pos_big_bench, "{return test(\"%lu\", 22337203685477ul);}"},
	{1, 867, "u_size_ll_pos_big", u_size_ll_pos_big, u_size_ll_pos_big_bench, "{return test(\"%llu\", 522337203685470ull);}"},
	{1, 868, "u_ullmax", u_ullmax, u_ullmax_bench, "{return test(\"%llu\", ullmax);}"},
	{1, 869, "u_ulmax", u_ulmax, u_ulmax_bench, "{return test(\"%lu\", ulmax);}"},
	{1, 870, "u_uhmax", u_uhmax, u_uhmax_bench, "{return test(\"%hu\", (unsigned short)65535);}"},
	{1, 871, "u_uhhmax", u_uhhmax, u_uhhmax_bench, "{return test(\"%hhu\", (unsigned char)255);}"},
	{1, 872, "u_size_l_pos_big_zp", u_size_l_pos_big_zp, u_size_l_pos_big_zp_bench, "{return test(\"%037lu\", 22337203685477ul);}"},
	{1, 873, "u_size_ll_pos_big_width", u_size_ll_pos_big_width, u_size_ll_pos_big_width_bench, "{return test(\"%37llu\", 522337203685470ull);}"},
	{1, 874, "u_size_ll_hh_ll", u_size_ll_hh_ll, u_size_ll_hh_ll_bench, "{return test(\"%llu%hhu%llu\", ull_pos_1, uch_pos_1, ull_pos_1);}"},
	{1, 875, "u_size_h_l_hh", u_size_h_l_hh, u_size_h_l_hh_bench, "{return test(\"%hu%lu%hhu\", ush_pos_1, ul_pos_1, uch_pos_1);}"},
	{1, 876, "u_size_l_hh_h", u_size_l_hh_h, u_size_l_hh_h_bench, "{return test(\"%lu%hhu%hu\", ul_pos_1, uch_pos_1, ush_pos_1);}"},
	{1, 877, "u_size_n_ll_hh", u_size_n_ll_hh, u_size_n_ll_hh_bench, "{return test(\"%u%llu%hhu\", ui_pos_1, ull_pos_1, uch_pos_1);}"},
	{1, 878, "u_size_ll_n_l", u_size_ll_n_l, u_size_ll_n_l_bench, "{return test(\"%llu%u%lu\", ull_pos_1, ui_pos_1, ul_pos_1);}"},
	{1, 879, "u_prec0val0_basic", u_prec0val0_basic, u_prec0val0_basic_bench, "{return test(\"%.0u\", 0);}"},
	{1, 880, "u_prec0val0_implicit", u_prec0val0_implicit, u_prec0val0_implicit_bench, "{return test(\"%.u\", 0);}"},
	{1, 881, "u_prec0val0_w", u_prec0val0_w, u_prec0val0_w_bench, "{return test(\"%5.0u\", 0);}"},
	{1, 882, "u_prec0val0_w_impl", u_prec0val0_w_impl, u_prec0val0_w_impl_bench, "{return test(\"%5.u\", 0);}"},
	{1, 883, "u_prec0val0_wlj", u_prec0val0_wlj, u_prec0val0_wlj_bench, "{return test(\"%-5.0u\", 0);}"},
	{1, 884, "u_prec0val0_wlj_impl", u_prec0val0_wlj_impl, u_prec0val0_wlj_impl_bench, "{return test(\"%-5.u\", 0);}"},
	{1, 885, "mix_hhu_str_llu_str", mix_hhu_str_llu_str, mix_hhu_str_llu_str_bench, "{return test(\"%hhu%s%llu%s\", uch_pos_1, str_3, ull_pos_1, str_2);}"},
	{1, 886, "mix_str_hu_str_lu", mix_str_hu_str_lu, mix_str_hu_str_lu_bench, "{return test(\"%s%hu%s%lu\", str_1, ush_pos_1, str_3, ul_pos_1);}"},
	{1, 887, "mixed_test_0001", mixed_test_0001, mixed_test_0001_bench, "{return test("},
	{1, 888, "x_basic_pos", x_basic_pos, x_basic_pos_bench, "{return test(\"this %x number\", 17);}"},
	{1, 889, "x_basic_zero", x_basic_zero, x_basic_zero_bench, "{return test(\"this %x number\", 0);}"},
	{1, 890, "x_basic_onlypos", x_basic_onlypos, x_basic_onlypos_bench, "{return test(\"%x\", 3);}"},
	{1, 891, "x_hexlmax", x_hexlmax, x_hexlmax_bench, "{return test(\"%x\", 4294967295u);}"},
	{1, 892, "x_width_pos_fits", x_width_pos_fits, x_width_pos_fits_bench, "{return test(\"%7x\", 33);}"},
	{1, 893, "x_width_zero_fits", x_width_zero_fits, x_width_zero_fits_bench, "{return test(\"%3x\", 0);}"},
	{1, 894, "x_width_pos_exactfit", x_width_pos_exactfit, x_width_pos_exactfit_bench, "{return test(\"%5x\", 52625);}"},
	{1, 895, "x_width_pos_nofit", x_width_pos_nofit, x_width_pos_nofit_bench, "{return test(\"%2x\", 94827);}"},
	{1, 896, "x_width_pos_fits_lj", x_width_pos_fits_lj, x_width_pos_fits_lj_bench, "{return test(\"%-7x\", 33);}"},
	{1, 897, "x_width_zero_fits_lj", x_width_zero_fits_lj, x_width_zero_fits_lj_bench, "{return test(\"%-3x\", 0);}"},
	{1, 898, "x_width_pos_exactfit_lj", x_width_pos_exactfit_lj, x_width_pos_exactfit_lj_bench, "{return test(\"%-5x\", 52625);}"},
	{1, 899, "x_width_pos_nofit_lj", x_width_pos_nofit_lj, x_width_pos_nofit_lj_bench, "{return test(\"%-4x\", 9648627);}"},
	{1, 900, "x_prec_fits_pos", x_prec_fits_pos, x_prec_fits_pos_bench, "{return test(\"%.5x\", 21);}"},
	{1, 901, "x_prec_fits_zero", x_prec_fits_zero, x_prec_fits_zero_bench, "{return test(\"%.3x\", 0);}"},
	{1, 902, "x_prec_exactfit_pos", x_prec_exactfit_pos, x_prec_exactfit_pos_bench, "{return test(\"%.4x\", 5263);}"},
	{1, 903, "x_prec_nofit_pos", x_prec_nofit_pos, x_prec_nofit_pos_bench, "{return test(\"%.3x\", 938862);}"},
	{1, 904, "x_zp_pos_fits", x_zp_pos_fits, x_zp_pos_fits_bench, "{return test(\"%05x\", 43);}"},
	{1, 905, "x_zp_zero_fits", x_zp_zero_fits, x_zp_zero_fits_bench, "{return test(\"%03x\", 0);}"},
	{1, 906, "x_zp_pos_exactfit", x_zp_pos_exactfit, x_zp_pos_exactfit_bench, "{return test(\"%03x\", 698334);}"},
	{1, 907, "x_prec_width_fit_fit_pos", x_prec_width_fit_fit_pos, x_prec_width_fit_fit_pos_bench, "{return test(\"%8.5x\", 34);}"},
	{1, 908, "x_prec_width_fit_fit_zero", x_prec_width_fit_fit_zero, x_prec_width_fit_fit_zero_bench, "{return test(\"%8.5x\", 0);}"},
	{1, 909, "x_prec_width_nofit_fit_pos", x_prec_width_nofit_fit_pos, x_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3x\", 8375);}"},
	{1, 910, "x_prec_width_fit_nofit_pos", x_prec_width_fit_nofit_pos, x_prec_width_fit_nofit_pos_bench, "{return test(\"%2.7x\", 3267);}"},
	{1, 911, "x_prec_width_nofit_nofit_pos", x_prec_width_nofit_nofit_pos, x_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3x\", 6983);}"},
	{1, 912, "x_prec_width_fit_fit_pos_lj", x_prec_width_fit_fit_pos_lj, x_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5x\", 34);}"},
	{1, 913, "x_prec_width_fit_fit_zero_lj", x_prec_width_fit_fit_zero_lj, x_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5x\", 0);}"},
	{1, 914, "x_prec_width_nofit_fit_pos_lj", x_prec_width_nofit_fit_pos_lj, x_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3x\", 8375);}"},
	{1, 915, "x_prec_width_fit_nofit_pos_lj", x_prec_width_fit_nofit_pos_lj, x_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-2.7x\", 3267);}"},
	{1, 916, "x_prec_width_nofit_nofit_pos_lj", x_prec_width_nofit_nofit_pos_lj, x_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3x\", 6983);}"},
	{1, 917, "x_prec_width_ff_pos_zp", x_prec_width_ff_pos_zp, x_prec_width_ff_pos_zp_bench, "{return test(\"%08.5x\", 34);}"},
	{1, 918, "x_prec_width_ff_zero_zp", x_prec_width_ff_zero_zp, x_prec_width_ff_zero_zp_bench, "{return test(\"%08.5x\", 0);}"},
	{1, 919, "x_prec_width_nf_pos_zp", x_prec_width_nf_pos_zp, x_prec_width_nf_pos_zp_bench, "{return test(\"%08.3x\", 8375);}"},
	{1, 920, "x_prec_width_fn_pos_zp", x_prec_width_fn_pos_zp, x_prec_width_fn_pos_zp_bench, "{return test(\"%02.7x\", 3267);}"},
	{1, 921, "x_prec_width_nn_pos_zp", x_prec_width_nn_pos_zp, x_prec_width_nn_pos_zp_bench, "{return test(\"%03.3x\", 6983);}"},
	{1, 922, "x_prec_width_ff_pos_ljzp_ignoreflag", x_prec_width_ff_pos_ljzp_ignoreflag, x_prec_width_ff_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.5x\", 34);}"},
	{1, 923, "x_prec_width_ff_zero_ljzp_ignoreflag", x_prec_width_ff_zero_ljzp_ignoreflag, x_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5x\", 0);}"},
	{1, 924, "x_prec_width_nf_pos_ljzp_ignoreflag", x_prec_width_nf_pos_ljzp_ignoreflag, x_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3x\", 8375);}"},
	{1, 925, "x_prec_width_fn_pos_ljzp_ignoreflag", x_prec_width_fn_pos_ljzp_ignoreflag, x_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-2.7x\", 3267);}"},
	{1, 926, "x_prec_width_nn_pos_ljzp_ignoreflag", x_prec_width_nn_pos_ljzp_ignoreflag, x_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3x\", 6983);}"},
	{1, 927, "x_size_hh_pos_casted", x_size_hh_pos_casted, x_size_hh_pos_casted_bench, "{return test(\"%hhx\", (unsigned char)45);}"},
	{1, 928, "x_size_h_pos_casted", x_size_h_pos_casted, x_size_h_pos_casted_bench, "{return test(\"%hx\", (unsigned short)385);}"},
	{1, 929, "x_size_l_pos_casted", x_size_l_pos_casted, x_size_l_pos_casted_bench, "{return test(\"%lx\", (unsigned long)32);}"},
	{1, 930, "x_size_ll_pos_casted", x_size_ll_pos_casted, x_size_ll_pos_casted_bench, "{return test(\"%llx\", (long long)43);}"},
	{1, 931, "x_size_hh_pos_ref", x_size_hh_pos_ref, x_size_hh_pos_ref_bench, "{return test(\"%hhx\", uch_pos_1);}"},
	{1, 932, "x_size_h_pos_ref", x_size_h_pos_ref, x_size_h_pos_ref_bench, "{return test(\"%hx\", ush_pos_1);}"},
	{1, 933, "x_size_l_pos_ref", x_size_l_pos_ref, x_size_l_pos_ref_bench, "{return test(\"%lx\", ul_pos_1);}"},
	{1, 934, "x_size_ll_pos_ref", x_size_ll_pos_ref, x_size_ll_pos_ref_bench, "{return test(\"%llx\", ull_pos_1);}"},
	{1, 935, "x_size_l_pos_big", x_size_l_pos_big, x_size_l_pos_big_bench, "{return test(\"%lx\", 22337203685477ul);}"},
	{1, 936, "x_size_ll_pos_big", x_size_ll_pos_big, x_size_ll_pos_big_bench, "{return test(\"%llx\", 522337203685470ull);}"},
	{1, 937, "x_ullmax", x_ullmax, x_ullmax_bench, "{return test(\"%llx\", ullmax);}"},
	{1, 938, "x_ulmax", x_ulmax, x_ulmax_bench, "{return test(\"%lx\", ulmax);}"},
	{1, 939, "x_uhmax", x_uhmax, x_uhmax_bench, "{return test(\"%hx\", (unsigned short)65535);}"},
	{1, 940, "x_uhhmax", x_uhhmax, x_uhhmax_bench, "{return test(\"%hhx\", (unsigned char)255);}"},
	{1, 941, "x_size_l_pos_big_zp", x_size_l_pos_big_zp, x_size_l_pos_big_zp_bench, "{return test(\"%037lx\", 22337203685477ul);}"},
	{1, 942, "x_size_ll_pos_big_width", x_size_ll_pos_big_width, x_size_ll_pos_big_width_bench, "{return test(\"%37llx\", 522337203685470ull);}"},
	{1, 943, "x_size_ll_hh_ll", x_size_ll_hh_ll, x_size_ll_hh_ll_bench, "{return test(\"%llu%hhu%llx\", ull_pos_1, uch_pos_1, ull_pos_1);}"},
	{1, 944, "x_size_h_l_hh", x_size_h_l_hh, x_size_h_l_hh_bench, "{return test(\"%hu%lu%hhx\", ush_pos_1, ul_pos_1, uch_pos_1);}"},
	{1, 945, "x_size_l_hh_h", x_size_l_hh_h, x_size_l_hh_h_bench, "{return test(\"%lu%hhu%hx\", ul_pos_1, uch_pos_1, ush_pos_1);}"},
	{1, 946, "x_size_n_ll_hh", x_size_n_ll_hh, x_size_n_ll_hh_bench, "{return test(\"%u%llu%hhx\", ui_pos_1, ull_pos_1, uch_pos_1);}"},
	{1, 947, "x_size_ll_n_l", x_size_ll_n_l, x_size_ll_n_l_bench, "{return test(\"%llu%u%lx\", ull_pos_1, ui_pos_1, ul_pos_1);}"},
	{1, 948, "x_basic_pos_af", x_basic_pos_af, x_basic_pos_af_bench, "{return test(\"this %#x number\", 17);}"},
	{1, 949, "x_basic_zero_af", x_basic_zero_af, x_basic_zero_af_bench, "{return test(\"this %#x number\", 0);}"},
	{1, 950, "x_basic_onlypos_af", x_basic_onlypos_af, x_basic_onlypos_af_bench, "{return test(\"%#x\", 3);}"},
	{1, 951, "x_hexlmax_af", x_hexlmax_af, x_hexlmax_af_bench, "{return test(\"%#x\", 4294967295u);}"},
	{1, 952, "x_width_pos_fits_af", x_width_pos_fits_af, x_width_pos_fits_af_bench, "{return test(\"%#7x\", 33);}"},
	{1, 953, "x_width_zero_fits_af", x_width_zero_fits_af, x_width_zero_fits_af_bench, "{return test(\"%#3x\", 0);}"},
	{1, 954, "x_width_pos_exactfit_af", x_width_pos_exactfit_af, x_width_pos_exactfit_af_bench, "{return test(\"%#5x\", 52625);}"},
	{1, 955, "x_width_pos_nofit_af", x_width_pos_nofit_af, x_width_pos_nofit_af_bench, "{return test(\"%#2x\", 94827);}"},
	{1, 956, "x_width_pos_fits_lj_af", x_width_pos_fits_lj_af, x_width_pos_fits_lj_af_bench, "{return test(\"%#-7x\", 33);}"},
	{1, 957, "x_width_zero_fits_lj_af", x_width_zero_fits_lj_af, x_width_zero_fits_lj_af_bench, "{return test(\"%#-3x\", 0);}"},
	{1, 958, "x_width_pos_exactfit_lj_af", x_width_pos_exactfit_lj_af, x_width_pos_exactfit_lj_af_bench, "{return test(\"%#-5x\", 52625);}"},
	{1, 959, "x_width_pos_nofit_lj_af", x_width_pos_nofit_lj_af, x_width_pos_nofit_lj_af_bench, "{return test(\"%#-4x\", 9648627);}"},
	{1, 960, "x_prec_fits_pos_af", x_prec_fits_pos_af, x_prec_fits_pos_af_bench, "{return test(\"%#.5x\", 21);}"},
	{1, 961, "x_prec_fits_zero_af", x_prec_fits_zero_af, x_prec_fits_zero_af_bench, "{return test(\"%#.3x\", 0);}"},
	{1, 962, "x_prec_exactfit_pos_af", x_prec_exactfit_pos_af, x_prec_exactfit_pos_af_bench, "{return test(\"%#.4x\", 5263);}"},
	{1, 963, "x_prec_nofit_pos_af", x_prec_nofit_pos_af, x_prec_nofit_pos_af_bench, "{return test(\"%#.3x\", 938862);}"},
	{1, 964, "x_zp_pos_fits_af", x_zp_pos_fits_af, x_zp_pos_fits_af_bench, "{return test(\"%#05x\", 43);}"},
	{1, 965, "x_zp_zero_fits_af", x_zp_zero_fits_af, x_zp_zero_fits_af_bench, "{return test(\"%#03x\", 0);}"},
	{1, 966, "x_zp_pos_exactfit_af", x_zp_pos_exactfit_af, x_zp_pos_exactfit_af_bench, "{return test(\"%#03x\", 698334);}"},
	{1, 967, "x_prec_width_fit_fit_pos_af", x_prec_width_fit_fit_pos_af, x_prec_width_fit_fit_pos_af_bench, "{return test(\"%#8.5x\", 34);}"},
	{1, 968, "x_prec_width_fit_fit_zero_af", x_prec_width_fit_fit_zero_af, x_prec_width_fit_fit_zero_af_bench, "{return test(\"%#8.5x\", 0);}"},
	{1, 969, "x_prec_width_nofit_fit_pos_af", x_prec_width_nofit_fit_pos_af, x_prec_width_nofit_fit_pos_af_bench, "{return test(\"%#8.3x\", 8375);}"},
	{1, 970, "x_prec_width_fit_nofit_pos_af", x_prec_width_fit_nofit_pos_af, x_prec_width_fit_nofit_pos_af_bench, "{return test(\"%#2.7x\", 3267);}"},
	{1, 971, "x_prec_width_nofit_nofit_pos_af", x_prec_width_nofit_nofit_pos_af, x_prec_width_nofit_nofit_pos_af_bench, "{return test(\"%#3.3x\", 6983);}"},
	{1, 972, "x_prec_width_fit_fit_pos_lj_af", x_prec_width_fit_fit_pos_lj_af, x_prec_width_fit_fit_pos_lj_af_bench, "{return test(\"%#-8.5x\", 34);}"},
	{1, 973, "x_prec_width_fit_fit_zero_lj_af", x_prec_width_fit_fit_zero_lj_af, x_prec_width_fit_fit_zero_lj_af_bench, "{return test(\"%#-8.5x\", 0);}"},
	{1, 974, "x_prec_width_nofit_fit_pos_lj_af", x_prec_width_nofit_fit_pos_lj_af, x_prec_width_nofit_fit_pos_lj_af_bench, "{return test(\"%#-8.3x\", 8375);}"},
	{1, 975, "x_prec_width_fit_nofit_pos_lj_af", x_prec_width_fit_nofit_pos_lj_af, x_prec_width_fit_nofit_pos_lj_af_bench, "{return test(\"%#-2.7x\", 3267);}"},
	{1, 976, "x_prec_width_nofit_nofit_pos_lj_af", x_prec_width_nofit_nofit_pos_lj_af, x_prec_width_nofit_nofit_pos_lj_af_bench, "{return test(\"%#-3.3x\", 6983);}"},
	{1, 977, "x_prec_width_ff_pos_zp_af", x_prec_width_ff_pos_zp_af, x_prec_width_ff_pos_zp_af_bench, "{return test(\"%#08.5x\", 34);}"},
	{1, 978, "x_prec_width_ff_zero_zp_af", x_prec_width_ff_zero_zp_af, x_prec_width_ff_zero_zp_af_bench, "{return test(\"%#08.5x\", 0);}"},
	{1, 979, "x_prec_width_nf_pos_zp_af", x_prec_width_nf_pos_zp_af, x_prec_width_nf_pos_zp_af_bench, "{return test(\"%#08.3x\", 8375);}"},
	{1, 980, "x_prec_width_fn_pos_zp_af", x_prec_width_fn_pos_zp_af, x_prec_width_fn_pos_zp_af_bench, "{return test(\"%#02.7x\", 3267);}"},
	{1, 981, "x_prec_width_nn_pos_zp_af", x_prec_width_nn_pos_zp_af, x_prec_width_nn_pos_zp_af_bench, "{return test(\"%#03.3x\", 6983);}"},
	{1, 982, "x_prec_width_ff_pos_ljzpaf_ignoreflag", x_prec_width_ff_pos_ljzpaf_ignoreflag, x_prec_width_ff_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.5x\", 34);}"},
	{1, 983, "x_prec_width_ff_zero_ljzpaf_ignoreflag", x_prec_width_ff_zero_ljzpaf_ignoreflag, x_prec_width_ff_zero_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.5x\", 0);}"},
	{1, 984, "x_prec_width_nf_pos_ljzpaf_ignoreflag", x_prec_width_nf_pos_ljzpaf_ignoreflag, x_prec_width_nf_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.3x\", 8375);}"},
	{1, 985, "x_prec_width_fn_pos_ljzpaf_ignoreflag", x_prec_width_fn_pos_ljzpaf_ignoreflag, x_prec_width_fn_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-2.7x\", 3267);}"},
	{1, 986, "x_prec_width_nn_pos_ljzpaf_ignoreflag", x_prec_width_nn_pos_ljzpaf_ignoreflag, x_prec_width_nn_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-3.3x\", 6983);}"},
	{1, 987, "x_size_hh_pos_casted_af", x_size_hh_pos_casted_af, x_size_hh_pos_casted_af_bench, "{return test(\"%#hhx\", (unsigned char)45);}"},
	{1, 988, "x_size_h_pos_casted_af", x_size_h_pos_casted_af, x_size_h_pos_casted_af_bench, "{return test(\"%#hx\", (unsigned short)385);}"},
	{1, 989, "x_size_l_pos_casted_af", x_size_l_pos_casted_af, x_size_l_pos_casted_af_bench, "{return test(\"%#lx\", (unsigned long)32);}"},
	{1, 990, "x_size_ll_pos_casted_af", x_size_ll_pos_casted_af, x_size_ll_pos_casted_af_bench, "{return test(\"%#llx\", (long long)43);}"},
	{1, 991, "x_size_hh_pos_ref_af", x_size_hh_pos_ref_af, x_size_hh_pos_ref_af_bench, "{return test(\"%#hhx\", uch_pos_1);}"},
	{1, 992, "x_size_h_pos_ref_af", x_size_h_pos_ref_af, x_size_h_pos_ref_af_bench, "{return test(\"%#hx\", ush_pos_1);}"},
	{1, 993, "x_size_l_pos_ref_af", x_size_l_pos_ref_af, x_size_l_pos_ref_af_bench, "{return test(\"%#lx\", ul_pos_1);}"},
	{1, 994, "x_size_ll_pos_ref_af", x_size_ll_pos_ref_af, x_size_ll_pos_ref_af_bench, "{return test(\"%#llx\", ull_pos_1);}"},
	{1, 995, "x_size_l_pos_big_af", x_size_l_pos_big_af, x_size_l_pos_big_af_bench, "{return test(\"%#lx\", 22337203685477lu);}"},
	{1, 996, "x_size_ll_pos_big_af", x_size_ll_pos_big_af, x_size_ll_pos_big_af_bench, "{return test(\"%#llx\", 522337203685470llu);}"},
	{1, 997, "x_ullmax_af", x_ullmax_af, x_ullmax_af_bench, "{return test(\"%#llx\", ullmax);}"},
	{1, 998, "x_ulmax_af", x_ulmax_af, x_ulmax_af_bench, "{return test(\"%#lx\", ulmax);}"},
	{1, 999, "x_uhmax_af", x_uhmax_af, x_uhmax_af_bench, "{return test(\"%#hx\", (unsigned short)65535);}"},
	{1, 1000, "x_uhhmax_af", x_uhhmax_af, x_uhhmax_af_bench, "{return test(\"%#hhx\", (unsigned char)255);}"},
	{1, 1001, "x_size_l_pos_big_zp_af", x_size_l_pos_big_zp_af, x_size_l_pos_big_zp_af_bench, "{return test(\"%#037lx\", 22337203685477ul);}"},
	{1, 1002, "x_size_ll_pos_big_width_af", x_size_ll_pos_big_width_af, x_size_ll_pos_big_width_af_bench, "{return test(\"%#37llx\", 522337203685470ull);}"},
	{1, 1003, "x_size_ll_hh_ll_af", x_size_ll_hh_ll_af, x_size_ll_hh_ll_af_bench, "{return test(\"%llu%hhu%#llx\", ull_pos_1, uch_pos_1, ull_pos_1);}"},
	{1, 1004, "x_size_h_l_hh_af", x_size_h_l_hh_af, x_size_h_l_hh_af_bench, "{return test(\"%hu%#lx%hhx\", ush_pos_1, ul_pos_1, uch_pos_1);}"},
	{1, 1005, "x_size_l_hh_h_af", x_size_l_hh_h_af, x_size_l_hh_h_af_bench, "{return test(\"%lu%hhu%#hx\", ul_pos_1, uch_pos_1, ush_pos_1);}"},
	{1, 1006, "x_size_n_ll_hh_af", x_size_n_ll_hh_af, x_size_n_ll_hh_af_bench, "{return test(\"%#x%llu%hhx\", ui_pos_1, ull_pos_1, uch_pos_1);}"},
	{1, 1007, "x_size_ll_n_l_af", x_size_ll_n_l_af, x_size_ll_n_l_af_bench, "{return test(\"%llu%u%#lx\", ull_pos_1, ui_pos_1, ul_pos_1);}"},
	{1, 1008, "x_prec0val0_basic", x_prec0val0_basic, x_prec0val0_basic_bench, "{return test(\"%.0x\", 0);}"},
	{1, 1009, "x_prec0val0_implicit", x_prec0val0_implicit, x_prec0val0_implicit_bench, "{return test(\"%.x\", 0);}"},
	{1, 1010, "x_prec0val0_w", x_prec0val0_w, x_prec0val0_w_bench, "{return test(\"%5.0x\", 0);}"},
	{1, 1011, "x_prec0val0_w_impl", x_prec0val0_w_impl, x_prec0val0_w_impl_bench, "{return test(\"%5.x\", 0);}"},
	{1, 1012, "x_prec0val0_wlj", x_prec0val0_wlj, x_prec0val0_wlj_bench, "{return test(\"%-5.0x\", 0);}"},
	{1, 1013, "x_prec0val0_wlj_impl", x_prec0val0_wlj_impl, x_prec0val0_wlj_impl_bench, "{return test(\"%-5.x\", 0);}"},
	{1, 1014, "x_prec0val0_af", x_prec0val0_af, x_prec0val0_af_bench, "{return test(\"%#.0x\", 0);}"},
	{1, 1015, "x_prec0val0_af_impl", x_prec0val0_af_impl, x_prec0val0_af_impl_bench, "{return test(\"%#.x\", 0);}"},
	{1, 1016, "x_prec0val0_waf", x_prec0val0_waf, x_prec0val0_waf_bench, "{return test(\"%#5.0x\", 0);}"},
	{1, 1017, "x_prec0val0_waf_impl", x_prec0val0_waf_impl, x_prec0val0_waf_impl_bench, "{return test(\"%#5.x\", 0);}"},
	{1, 1018, "x_prec0val0_waflj", x_prec0val0_waflj, x_prec0val0_waflj_bench, "{return test(\"%#-5.0x\", 0);}"},
	{1, 1019, "x_prec0val0_waflj_impl", x_prec0val0_waflj_impl, x_prec0val0_waflj_impl_bench, "{return test(\"%#-5.x\", 0);}"},
	{1, 1020, "X_basic_hexu_pos", X_basic_hexu_pos, X_basic_hexu_pos_bench, "{return test(\"this %X number\", 17);}"},
	{1, 1021, "X_basic_hexu_zero", X_basic_hexu_zero, X_basic_hexu_zero_bench, "{return test(\"this %X number\", 0);}"},
	{1, 1022, "X_basic_hexu_onlypos", X_basic_hexu_onlypos, X_basic_hexu_onlypos_bench, "{return test(\"%X\", 3);}"},
	{1, 1023, "X_hexumax", X_hexumax, X_hexumax_bench, "{return test(\"%X\", 4294967295u);}"},
	{1, 1024, "X_width_pos_fits", X_width_pos_fits, X_width_pos_fits_bench, "{return test(\"%7X\", 33);}"},
	{1, 1025, "X_width_zero_fits", X_width_zero_fits, X_width_zero_fits_bench, "{return test(\"%3X\", 0);}"},
	{1, 1026, "X_width_pos_exactfit", X_width_pos_exactfit, X_width_pos_exactfit_bench, "{return test(\"%5X\", 52625);}"},
	{1, 1027, "X_width_pos_nofit", X_width_pos_nofit, X_width_pos_nofit_bench, "{return test(\"%2X\", 94827);}"},
	{1, 1028, "X_width_pos_fits_lj", X_width_pos_fits_lj, X_width_pos_fits_lj_bench, "{return test(\"%-7X\", 33);}"},
	{1, 1029, "X_width_zero_fits_lj", X_width_zero_fits_lj, X_width_zero_fits_lj_bench, "{return test(\"%-3X\", 0);}"},
	{1, 1030, "X_width_pos_exactfit_lj", X_width_pos_exactfit_lj, X_width_pos_exactfit_lj_bench, "{return test(\"%-5X\", 52625);}"},
	{1, 1031, "X_width_pos_nofit_lj", X_width_pos_nofit_lj, X_width_pos_nofit_lj_bench, "{return test(\"%-4X\", 9648627);}"},
	{1, 1032, "X_prec_fits_pos", X_prec_fits_pos, X_prec_fits_pos_bench, "{return test(\"%.5X\", 21);}"},
	{1, 1033, "X_prec_fits_zero", X_prec_fits_zero, X_prec_fits_zero_bench, "{return test(\"%.3X\", 0);}"},
	{1, 1034, "X_prec_exactfit_pos", X_prec_exactfit_pos, X_prec_exactfit_pos_bench, "{return test(\"%.4X\", 5263);}"},
	{1, 1035, "X_prec_nofit_pos", X_prec_nofit_pos, X_prec_nofit_pos_bench, "{return test(\"%.3X\", 938862);}"},
	{1, 1036, "X_zp_pos_fits", X_zp_pos_fits, X_zp_pos_fits_bench, "{return test(\"%05X\", 43);}"},
	{1, 1037, "X_zp_zero_fits", X_zp_zero_fits, X_zp_zero_fits_bench, "{return test(\"%03X\", 0);}"},
	{1, 1038, "X_zp_pos_exactfit", X_zp_pos_exactfit, X_zp_pos_exactfit_bench, "{return test(\"%03X\", 698334);}"},
	{1, 1039, "X_prec_width_fit_fit_pos", X_prec_width_fit_fit_pos, X_prec_width_fit_fit_pos_bench, "{return test(\"%8.5X\", 34);}"},
	{1, 1040, "X_prec_width_fit_fit_zero", X_prec_width_fit_fit_zero, X_prec_width_fit_fit_zero_bench, "{return test(\"%8.5X\", 0);}"},
	{1, 1041, "X_prec_width_nofit_fit_pos", X_prec_width_nofit_fit_pos, X_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3X\", 8375);}"},
	{1, 1042, "X_prec_width_fit_nofit_pos", X_prec_width_fit_nofit_pos, X_prec_width_fit_nofit_pos_bench, "{return test(\"%2.7X\", 3267);}"},
	{1, 1043, "X_prec_width_nofit_nofit_pos", X_prec_width_nofit_nofit_pos, X_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3X\", 6983);}"},
	{1, 1044, "X_prec_width_fit_fit_pos_lj", X_prec_width_fit_fit_pos_lj, X_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5X\", 34);}"},
	{1, 1045, "X_prec_width_fit_fit_zero_lj", X_prec_width_fit_fit_zero_lj, X_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5X\", 0);}"},
	{1, 1046, "X_prec_width_nofit_fit_pos_lj", X_prec_width_nofit_fit_pos_lj, X_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3X\", 8375);}"},
	{1, 1047, "X_prec_width_fit_nofit_pos_lj", X_prec_width_fit_nofit_pos_lj, X_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-2.7X\", 3267);}"},
	{1, 1048, "X_prec_width_nofit_nofit_pos_lj", X_prec_width_nofit_nofit_pos_lj, X_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3X\", 6983);}"},
	{1, 1049, "X_prec_width_ff_pos_zp", X_prec_width_ff_pos_zp, X_prec_width_ff_pos_zp_bench, "{return test(\"%08.5X\", 34);}"},
	{1, 1050, "X_prec_width_ff_zero_zp", X_prec_width_ff_zero_zp, X_prec_width_ff_zero_zp_bench, "{return test(\"%08.5X\", 0);}"},
	{1, 1051, "X_prec_width_nf_pos_zp", X_prec_width_nf_pos_zp, X_prec_width_nf_pos_zp_bench, "{return test(\"%08.3X\", 8375);}"},
	{1, 1052, "X_prec_width_fn_pos_zp", X_prec_width_fn_pos_zp, X_prec_width_fn_pos_zp_bench, "{return test(\"%02.7X\", 3267);}"},
	{1, 1053, "X_prec_width_nn_pos_zp", X_prec_width_nn_pos_zp, X_prec_width_nn_pos_zp_bench, "{return test(\"%03.3X\", 6983);}"},
	{1, 1054, "X_prec_width_ff_pos_ljzp_ignoreflag", X_prec_width_ff_pos_ljzp_ignoreflag, X_prec_width_ff_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.5X\", 34);}"},
	{1, 1055, "X_prec_width_ff_zero_ljzp_ignoreflag", X_prec_width_ff_zero_ljzp_ignoreflag, X_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5X\", 0);}"},
	{1, 1056, "X_prec_width_nf_pos_ljzp_ignoreflag", X_prec_width_nf_pos_ljzp_ignoreflag, X_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3X\", 8375);}"},
	{1, 1057, "X_prec_width_fn_pos_ljzp_ignoreflag", X_prec_width_fn_pos_ljzp_ignoreflag, X_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-2.7X\", 3267);}"},
	{1, 1058, "X_prec_width_nn_pos_ljzp_ignoreflag", X_prec_width_nn_pos_ljzp_ignoreflag, X_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3X\", 6983);}"},
	{1, 1059, "X_size_hh_pos_casted", X_size_hh_pos_casted, X_size_hh_pos_casted_bench, "{return test(\"%hhX\", (unsigned char)45);}"},
	{1, 1060, "X_size_h_pos_casted", X_size_h_pos_casted, X_size_h_pos_casted_bench, "{return test(\"%hX\", (unsigned short)385);}"},
	{1, 1061, "X_size_l_pos_casted", X_size_l_pos_casted, X_size_l_pos_casted_bench, "{return test(\"%lX\", (unsigned long)32);}"},
	{1, 1062, "X_size_ll_pos_casted", X_size_ll_pos_casted, X_size_ll_pos_casted_bench, "{return test(\"%llX\", (long long)43);}"},
	{1, 1063, "X_size_hh_pos_ref", X_size_hh_pos_ref, X_size_hh_pos_ref_bench, "{return test(\"%hhX\", uch_pos_1);}"},
	{1, 1064, "X_size_h_pos_ref", X_size_h_pos_ref, X_size_h_pos_ref_bench, "{return test(\"%hX\", ush_pos_1);}"},
	{1, 1065, "X_size_l_pos_ref", X_size_l_pos_ref, X_size_l_pos_ref_bench, "{return test(\"%lX\", ul_pos_1);}"},
	{1, 1066, "X_size_ll_pos_ref", X_size_ll_pos_ref, X_size_ll_pos_ref_bench, "{return test(\"%llX\", ull_pos_1);}"},
	{1, 1067, "X_size_l_pos_big", X_size_l_pos_big, X_size_l_pos_big_bench, "{return test(\"%lX\", 22337203685477ul);}"},
	{1, 1068, "X_size_ll_pos_big", X_size_ll_pos_big, X_size_ll_pos_big_bench, "{return test(\"%llX\", 522337203685470ull);}"},
	{1, 1069, "X_ullmax", X_ullmax, X_ullmax_bench, "{return test(\"%llX\", ullmax);}"},
	{1, 1070, "X_ulmax", X_ulmax, X_ulmax_bench, "{return test(\"%lX\", ulmax);}"},
	{1, 1071, "X_uhmax", X_uhmax, X_uhmax_bench, "{return test(\"%hX\", (unsigned short)65535);}"},
	{1, 1072, "X_uhhmax", X_uhhmax, X_uhhmax_bench, "{return test(\"%hhX\", (unsigned char)255);}"},
	{1, 1073, "X_size_l_pos_big_zp", X_size_l_pos_big_zp, X_size_l_pos_big_zp_bench, "{return test(\"%037lX\", 22337203685477ul);}"},
	{1, 1074, "X_size_ll_pos_big_width", X_size_ll_pos_big_width, X_size_ll_pos_big_width_bench, "{return test(\"%37llX\", 522337203685470ull);}"},
	{1, 1075, "X_size_ll_hh_ll", X_size_ll_hh_ll, X_size_ll_hh_ll_bench, "{return test(\"%llu%hhu%llX\", ull_pos_1, uch_pos_1, ull_pos_1);}"},
	{1, 1076, "X_size_h_l_hh", X_size_h_l_hh, X_size_h_l_hh_bench, "{return test(\"%hu%lu%hhX\", ush_pos_1, ul_pos_1, uch_pos_1);}"},
	{1, 1077, "X_size_l_hh_h", X_size_l_hh_h, X_size_l_hh_h_bench, "{return test(\"%lu%hhu%hX\", ul_pos_1, uch_pos_1, ush_pos_1);}"},
	{1, 1078, "X_size_n_ll_hh", X_size_n_ll_hh, X_size_n_ll_hh_bench, "{return test(\"%u%llu%hhX\", ui_pos_1, ull_pos_1, uch_pos_1);}"},
	{1, 1079, "X_size_ll_n_l", X_size_ll_n_l, X_size_ll_n_l_bench, "{return test(\"%llu%u%lX\", ull_pos_1, ui_pos_1, ul_pos_1);}"},
	{1, 1080, "X_basic_hexu_pos_af", X_basic_hexu_pos_af, X_basic_hexu_pos_af_bench, "{return test(\"this %#X number\", 17);}"},
	{1, 1081, "X_basic_hexu_zero_af", X_basic_hexu_zero_af, X_basic_hexu_zero_af_bench, "{return test(\"this %#X number\", 0);}"},
	{1, 1082, "X_basic_hexu_onlypos_af", X_basic_hexu_onlypos_af, X_basic_hexu_onlypos_af_bench, "{return test(\"%#X\", 3);}"},
	{1, 1083, "X_hexumax_af", X_hexumax_af, X_hexumax_af_bench, "{return test(\"%#X\", 4294967295u);}"},
	{1, 1084, "X_width_pos_fits_af", X_width_pos_fits_af, X_width_pos_fits_af_bench, "{return test(\"%#7X\", 33);}"},
	{1, 1085, "X_width_zero_fits_af", X_width_zero_fits_af, X_width_zero_fits_af_bench, "{return test(\"%#3X\", 0);}"},
	{1, 1086, "X_width_pos_exactfit_af", X_width_pos_exactfit_af, X_width_pos_exactfit_af_bench, "{return test(\"%#7X\", 52625);}"},
	{1, 1087, "X_width_pos_nofit_af", X_width_pos_nofit_af, X_width_pos_nofit_af_bench, "{return test(\"%#2X\", 94827);}"},
	{1, 1088, "X_width_pos_fits_lj_af", X_width_pos_fits_lj_af, X_width_pos_fits_lj_af_bench, "{return test(\"%#-7X\", 33);}"},
	{1, 1089, "X_width_zero_fits_lj_af", X_width_zero_fits_lj_af, X_width_zero_fits_lj_af_bench, "{return test(\"%#-3X\", 0);}"},
	{1, 1090, "X_width_pos_exactfit_lj_af", X_width_pos_exactfit_lj_af, X_width_pos_exactfit_lj_af_bench, "{return test(\"%#-7X\", 52625);}"},
	{1, 1091, "X_width_pos_nofit_lj_af", X_width_pos_nofit_lj_af, X_width_pos_nofit_lj_af_bench, "{return test(\"%#-4X\", 9648627);}"},
	{1, 1092, "X_prec_fits_pos_af", X_prec_fits_pos_af, X_prec_fits_pos_af_bench, "{return test(\"%#.5X\", 21);}"},
	{1, 1093, "X_prec_fits_zero_af", X_prec_fits_zero_af, X_prec_fits_zero_af_bench, "{return test(\"%#.3X\", 0);}"},
	{1, 1094, "X_prec_exactfit_pos_af", X_prec_exactfit_pos_af, X_prec_exactfit_pos_af_bench, "{return test(\"%#.4X\", 5263);}"},
	{1, 1095, "X_prec_nofit_pos_af", X_prec_nofit_pos_af, X_prec_nofit_pos_af_bench, "{return test(\"%#.3X\", 938862);}"},
	{1, 1096, "X_zp_pos_fits_af", X_zp_pos_fits_af, X_zp_pos_fits_af_bench, "{return test(\"%#05X\", 43);}"},
	{1, 1097, "X_zp_zero_fits_af", X_zp_zero_fits_af, X_zp_zero_fits_af_bench, "{return test(\"%#03X\", 0);}"},
	{1, 1098, "X_zp_pos_exactfit_af", X_zp_pos_exactfit_af, X_zp_pos_exactfit_af_bench, "{return test(\"%#03X\", 698334);}"},
	{1, 1099, "X_prec_width_fit_fit_pos_af", X_prec_width_fit_fit_pos_af, X_prec_width_fit_fit_pos_af_bench, "{return test(\"%#8.5X\", 34);}"},
	{1, 1100, "X_prec_width_fit_fit_zero_af", X_prec_width_fit_fit_zero_af, X_prec_width_fit_fit_zero_af_bench, "{return test(\"%#8.5X\", 0);}"},
	{1, 1101, "X_prec_width_nofit_fit_pos_af", X_prec_width_nofit_fit_pos_af, X_prec_width_nofit_fit_pos_af_bench, "{return test(\"%#8.3X\", 8375);}"},
	{1, 1102, "X_prec_width_fit_nofit_pos_af", X_prec_width_fit_nofit_pos_af, X_prec_width_fit_nofit_pos_af_bench, "{return test(\"%#2.7X\", 3267);}"},
	{1, 1103, "X_prec_width_nofit_nofit_pos_af", X_prec_width_nofit_nofit_pos_af, X_prec_width_nofit_nofit_pos_af_bench, "{return test(\"%#3.3X\", 6983);}"},
	{1, 1104, "X_prec_width_fit_fit_pos_lj_af", X_prec_width_fit_fit_pos_lj_af, X_prec_width_fit_fit_pos_lj_af_bench, "{return test(\"%#-8.5X\", 34);}"},
	{1, 1105, "X_prec_width_fit_fit_zero_lj_af", X_prec_width_fit_fit_zero_lj_af, X_prec_width_fit_fit_zero_lj_af_bench, "{return test(\"%#-8.5X\", 0);}"},
	{1, 1106, "X_prec_width_nofit_fit_pos_lj_af", X_prec_width_nofit_fit_pos_lj_af, X_prec_width_nofit_fit_pos_lj_af_bench, "{return test(\"%#-8.3X\", 8375);}"},
	{1, 1107, "X_prec_width_fit_nofit_pos_lj_af", X_prec_width_fit_nofit_pos_lj_af, X_prec_width_fit_nofit_pos_lj_af_bench, "{return test(\"%#-2.7X\", 3267);}"},
	{1, 1108, "X_prec_width_nofit_nofit_pos_lj_af", X_prec_width_nofit_nofit_pos_lj_af, X_prec_width_nofit_nofit_pos_lj_af_bench, "{return test(\"%#-3.3X\", 6983);}"},
	{1, 1109, "X_prec_width_ff_pos_zp_af", X_prec_width_ff_pos_zp_af, X_prec_width_ff_pos_zp_af_bench, "{return test(\"%#08.5X\", 34);}"},
	{1, 1110, "X_prec_width_ff_zero_zp_af", X_prec_width_ff_zero_zp_af, X_prec_width_ff_zero_zp_af_bench, "{return test(\"%#08.5X\", 0);}"},
	{1, 1111, "X_prec_width_nf_pos_zp_af", X_prec_width_nf_pos_zp_af, X_prec_width_nf_pos_zp_af_bench, "{return test(\"%#08.3X\", 8375);}"},
	{1, 1112, "X_prec_width_fn_pos_zp_af", X_prec_width_fn_pos_zp_af, X_prec_width_fn_pos_zp_af_bench, "{return test(\"%#02.7X\", 3267);}"},
	{1, 1113, "X_prec_width_nn_pos_zp_af", X_prec_width_nn_pos_zp_af, X_prec_width_nn_pos_zp_af_bench, "{return test(\"%#03.3X\", 6983);}"},
	{1, 1114, "X_prec_width_ff_pos_ljzpaf_ignoreflag", X_prec_width_ff_pos_ljzpaf_ignoreflag, X_prec_width_ff_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.5X\", 34);}"},
	{1, 1115, "X_prec_width_ff_zero_ljzpaf_ignoreflag", X_prec_width_ff_zero_ljzpaf_ignoreflag, X_prec_width_ff_zero_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.5X\", 0);}"},
	{1, 1116, "X_prec_width_nf_pos_ljzpaf_ignoreflag", X_prec_width_nf_pos_ljzpaf_ignoreflag, X_prec_width_nf_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.3X\", 8375);}"},
	{1, 1117, "X_prec_width_fn_pos_ljzpaf_ignoreflag", X_prec_width_fn_pos_ljzpaf_ignoreflag, X_prec_width_fn_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-2.7X\", 3267);}"},
	{1, 1118, "X_prec_width_nn_pos_ljzpaf_ignoreflag", X_prec_width_nn_pos_ljzpaf_ignoreflag, X_prec_width_nn_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-3.3X\", 6983);}"},
	{1, 1119, "X_size_hh_pos_casted_af", X_size_hh_pos_casted_af, X_size_hh_pos_casted_af_bench, "{return test(\"%#hhX\", (unsigned char)45);}"},
	{1, 1120, "X_size_h_pos_casted_af", X_size_h_pos_casted_af, X_size_h_pos_casted_af_bench, "{return test(\"%#hX\", (unsigned short)385);}"},
	{1, 1121, "X_size_l_pos_casted_af", X_size_l_pos_casted_af, X_size_l_pos_casted_af_bench, "{return test(\"%#lX\", (unsigned long)32);}"},
	{1, 1122, "X_size_ll_pos_casted_af", X_size_ll_pos_casted_af, X_size_ll_pos_casted_af_bench, "{return test(\"%#llX\", (long long)43);}"},
	{1, 1123, "X_size_hh_pos_ref_af", X_size_hh_pos_ref_af, X_size_hh_pos_ref_af_bench, "{return test(\"%#hhX\", uch_pos_1);}"},
	{1, 1124, "X_size_h_pos_ref_af", X_size_h_pos_ref_af, X_size_h_pos_ref_af_bench, "{return test(\"%#hX\", ush_pos_1);}"},
	{1, 1125, "X_size_l_pos_ref_af", X_size_l_pos_ref_af, X_size_l_pos_ref_af_bench, "{return test(\"%#lX\", ul_pos_1);}"},
	{1, 1126, "X_size_ll_pos_ref_af", X_size_ll_pos_ref_af, X_size_ll_pos_ref_af_bench, "{return test(\"%#llX\", ull_pos_1);}"},
	{1, 1127, "X_size_l_pos_big_af", X_size_l_pos_big_af, X_size_l_pos_big_af_bench, "{return test(\"%#lX\", 22337203685477ul);}"},
	{1, 1128, "X_size_ll_pos_big_af", X_size_ll_pos_big_af, X_size_ll_pos_big_af_bench, "{return test(\"%#llX\", 522337203685470ull);}"},
	{1, 1129, "X_ullmax_af", X_ullmax_af, X_ullmax_af_bench, "{return test(\"%#llX\", ullmax);}"},
	{1, 1130, "X_ulmax_af", X_ulmax_af, X_ulmax_af_bench, "{return test(\"%#lX\", ulmax);}"},
	{1, 1131, "X_uhmax_af", X_uhmax_af, X_uhmax_af_bench, "{return test(\"%#hX\", (unsigned short)65535);}"},
	{1, 1132, "X_uhhmax_af", X_uhhmax_af, X_uhhmax_af_bench, "{return test(\"%#hhX\", (unsigned char)255);}"},
	{1, 1133, "X_size_l_pos_big_zp_af", X_size_l_pos_big_zp_af, X_size_l_pos_big_zp_af_bench, "{return test(\"%#037lX\", 22337203685477ul);}"},
	{1, 1134, "X_size_ll_pos_big_width_af", X_size_ll_pos_big_width_af, X_size_ll_pos_big_width_af_bench, "{return test(\"%#37llX\", 522337203685470ull);}"},
	{1, 1135, "X_size_ll_hh_ll_af", X_size_ll_hh_ll_af, X_size_ll_hh_ll_af_bench, "{return test(\"%llu%hhu%#llX\", ull_pos_1, uch_pos_1, ull_pos_1);}"},
	{1, 1136, "X_size_h_l_hh_af", X_size_h_l_hh_af, X_size_h_l_hh_af_bench, "{return test(\"%#hx%lu%#hhX\", ush_pos_1, ul_pos_1, uch_pos_1);}"},
	{1, 1137, "X_size_l_hh_h_af", X_size_l_hh_h_af, X_size_l_hh_h_af_bench, "{return test(\"%lu%hhu%#hX\", ul_pos_1, uch_pos_1, ush_pos_1);}"},
	{1, 1138, "X_size_n_ll_hh_af", X_size_n_ll_hh_af, X_size_n_ll_hh_af_bench, "{return test(\"%#x%llu%#hhX\", ui_pos_1, ull_pos_1, uch_pos_1);}"},
	{1, 1139, "X_size_ll_n_l_af", X_size_ll_n_l_af, X_size_ll_n_l_af_bench, "{return test(\"%#llx%u%#lX\", ull_pos_1, ui_pos_1, ul_pos_1);}"},
	{1, 1140, "X_prec0val0_basic", X_prec0val0_basic, X_prec0val0_basic_bench, "{return test(\"%.0X\", 0);}"},
	{1, 1141, "X_prec0val0_implicit", X_prec0val0_implicit, X_prec0val0_implicit_bench, "{return test(\"%.X\", 0);}"},
	{1, 1142, "X_prec0val0_w", X_prec0val0_w, X_prec0val0_w_bench, "{return test(\"%5.0X\", 0);}"},
	{1, 1143, "X_prec0val0_w_impl", X_prec0val0_w_impl, X_prec0val0_w_impl_bench, "{return test(\"%5.X\", 0);}"},
	{1, 1144, "X_prec0val0_wlj", X_prec0val0_wlj, X_prec0val0_wlj_bench, "{return test(\"%-5.0X\", 0);}"},
	{1, 1145, "X_prec0val0_wlj_impl", X_prec0val0_wlj_impl, X_prec0val0_wlj_impl_bench, "{return test(\"%-5.X\", 0);}"},
	{1, 1146, "X_prec0val0_af", X_prec0val0_af, X_prec0val0_af_bench, "{return test(\"%#.0X\", 0);}"},
	{1, 1147, "X_prec0val0_af_impl", X_prec0val0_af_impl, X_prec0val0_af_impl_bench, "{return test(\"%#.X\", 0);}"},
	{1, 1148, "X_prec0val0_waf", X_prec0val0_waf, X_prec0val0_waf_bench, "{return test(\"%#5.0X\", 0);}"},
	{1, 1149, "X_prec0val0_waf_impl", X_prec0val0_waf_impl, X_prec0val0_waf_impl_bench, "{return test(\"%#5.X\", 0);}"},
	{1, 1150, "X_prec0val0_waflj", X_prec0val0_waflj, X_prec0val0_waflj_bench, "{return test(\"%#-5.0X\", 0);}"},
	{1, 1151, "X_prec0val0_waflj_impl", X_prec0val0_waflj_impl, X_prec0val0_waflj_impl_bench, "{return test(\"%#-5.X\", 0);}"},
	{1, 1152, "o_basic_octl_pos", o_basic_octl_pos, o_basic_octl_pos_bench, "{return test(\"this %o number\", 17);}"},
	{1, 1153, "o_basic_octl_zero", o_basic_octl_zero, o_basic_octl_zero_bench, "{return test(\"this %o number\", 0);}"},
	{1, 1154, "o_basic_octl_onlypos", o_basic_octl_onlypos, o_basic_octl_onlypos_bench, "{return test(\"%o\", 3);}"},
	{1, 1155, "o_octlmax", o_octlmax, o_octlmax_bench, "{return test(\"%o\", 4294967295u);}"},
	{1, 1156, "o_width_pos_fits", o_width_pos_fits, o_width_pos_fits_bench, "{return test(\"%7o\", 33);}"},
	{1, 1157, "o_width_zero_fits", o_width_zero_fits, o_width_zero_fits_bench, "{return test(\"%3o\", 0);}"},
	{1, 1158, "o_width_pos_exactfit", o_width_pos_exactfit, o_width_pos_exactfit_bench, "{return test(\"%6o\", 52625);}"},
	{1, 1159, "o_width_pos_nofit", o_width_pos_nofit, o_width_pos_nofit_bench, "{return test(\"%2o\", 94827);}"},
	{1, 1160, "o_width_pos_fits_lj", o_width_pos_fits_lj, o_width_pos_fits_lj_bench, "{return test(\"%-7o\", 33);}"},
	{1, 1161, "o_width_zero_fits_lj", o_width_zero_fits_lj, o_width_zero_fits_lj_bench, "{return test(\"%-3o\", 0);}"},
	{1, 1162, "o_width_pos_exactfit_lj", o_width_pos_exactfit_lj, o_width_pos_exactfit_lj_bench, "{return test(\"%-6o\", 52625);}"},
	{1, 1163, "o_width_pos_nofit_lj", o_width_pos_nofit_lj, o_width_pos_nofit_lj_bench, "{return test(\"%-4o\", 9648627);}"},
	{1, 1164, "o_prec_fits_pos", o_prec_fits_pos, o_prec_fits_pos_bench, "{return test(\"%.5o\", 21);}"},
	{1, 1165, "o_prec_fits_zero", o_prec_fits_zero, o_prec_fits_zero_bench, "{return test(\"%.3o\", 0);}"},
	{1, 1166, "o_prec_exactfit_pos", o_prec_exactfit_pos, o_prec_exactfit_pos_bench, "{return test(\"%.5o\", 5263);}"},
	{1, 1167, "o_prec_nofit_pos", o_prec_nofit_pos, o_prec_nofit_pos_bench, "{return test(\"%.3o\", 938862);}"},
	{1, 1168, "o_zp_pos_fits", o_zp_pos_fits, o_zp_pos_fits_bench, "{return test(\"%05o\", 43);}"},
	{1, 1169, "o_zp_zero_fits", o_zp_zero_fits, o_zp_zero_fits_bench, "{return test(\"%03o\", 0);}"},
	{1, 1170, "o_zp_pos_exactfit", o_zp_pos_exactfit, o_zp_pos_exactfit_bench, "{return test(\"%07o\", 698334);}"},
	{1, 1171, "o_prec_width_fit_fit_pos", o_prec_width_fit_fit_pos, o_prec_width_fit_fit_pos_bench, "{return test(\"%8.5o\", 34);}"},
	{1, 1172, "o_prec_width_fit_fit_zero", o_prec_width_fit_fit_zero, o_prec_width_fit_fit_zero_bench, "{return test(\"%8.5o\", 0);}"},
	{1, 1173, "o_prec_width_nofit_fit_pos", o_prec_width_nofit_fit_pos, o_prec_width_nofit_fit_pos_bench, "{return test(\"%8.3o\", 8375);}"},
	{1, 1174, "o_prec_width_fit_nofit_pos", o_prec_width_fit_nofit_pos, o_prec_width_fit_nofit_pos_bench, "{return test(\"%2.7o\", 3267);}"},
	{1, 1175, "o_prec_width_nofit_nofit_pos", o_prec_width_nofit_nofit_pos, o_prec_width_nofit_nofit_pos_bench, "{return test(\"%3.3o\", 6983);}"},
	{1, 1176, "o_prec_width_fit_fit_pos_lj", o_prec_width_fit_fit_pos_lj, o_prec_width_fit_fit_pos_lj_bench, "{return test(\"%-8.5o\", 34);}"},
	{1, 1177, "o_prec_width_fit_fit_zero_lj", o_prec_width_fit_fit_zero_lj, o_prec_width_fit_fit_zero_lj_bench, "{return test(\"%-8.5o\", 0);}"},
	{1, 1178, "o_prec_width_nofit_fit_pos_lj", o_prec_width_nofit_fit_pos_lj, o_prec_width_nofit_fit_pos_lj_bench, "{return test(\"%-8.3o\", 8375);}"},
	{1, 1179, "o_prec_width_fit_nofit_pos_lj", o_prec_width_fit_nofit_pos_lj, o_prec_width_fit_nofit_pos_lj_bench, "{return test(\"%-2.7o\", 3267);}"},
	{1, 1180, "o_prec_width_nofit_nofit_pos_lj", o_prec_width_nofit_nofit_pos_lj, o_prec_width_nofit_nofit_pos_lj_bench, "{return test(\"%-3.3o\", 6983);}"},
	{1, 1181, "o_prec_width_ff_pos_zp", o_prec_width_ff_pos_zp, o_prec_width_ff_pos_zp_bench, "{return test(\"%08.5o\", 34);}"},
	{1, 1182, "o_prec_width_ff_zero_zp", o_prec_width_ff_zero_zp, o_prec_width_ff_zero_zp_bench, "{return test(\"%08.5o\", 0);}"},
	{1, 1183, "o_prec_width_nf_pos_zp", o_prec_width_nf_pos_zp, o_prec_width_nf_pos_zp_bench, "{return test(\"%08.3o\", 8375);}"},
	{1, 1184, "o_prec_width_fn_pos_zp", o_prec_width_fn_pos_zp, o_prec_width_fn_pos_zp_bench, "{return test(\"%02.7o\", 3267);}"},
	{1, 1185, "o_prec_width_nn_pos_zp", o_prec_width_nn_pos_zp, o_prec_width_nn_pos_zp_bench, "{return test(\"%03.3o\", 6983);}"},
	{1, 1186, "o_prec_width_ff_pos_ljzp_ignoreflag", o_prec_width_ff_pos_ljzp_ignoreflag, o_prec_width_ff_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.5o\", 34);}"},
	{1, 1187, "o_prec_width_ff_zero_ljzp_ignoreflag", o_prec_width_ff_zero_ljzp_ignoreflag, o_prec_width_ff_zero_ljzp_ignoreflag_bench, "{return test(\"%0-8.5o\", 0);}"},
	{1, 1188, "o_prec_width_nf_pos_ljzp_ignoreflag", o_prec_width_nf_pos_ljzp_ignoreflag, o_prec_width_nf_pos_ljzp_ignoreflag_bench, "{return test(\"%0-8.3o\", 8375);}"},
	{1, 1189, "o_prec_width_fn_pos_ljzp_ignoreflag", o_prec_width_fn_pos_ljzp_ignoreflag, o_prec_width_fn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-2.7o\", 3267);}"},
	{1, 1190, "o_prec_width_nn_pos_ljzp_ignoreflag", o_prec_width_nn_pos_ljzp_ignoreflag, o_prec_width_nn_pos_ljzp_ignoreflag_bench, "{return test(\"%0-3.3o\", 6983);}"},
	{1, 1191, "o_size_hh_pos_casted", o_size_hh_pos_casted, o_size_hh_pos_casted_bench, "{return test(\"%hho\", (unsigned char)45);}"},
	{1, 1192, "o_size_h_pos_casted", o_size_h_pos_casted, o_size_h_pos_casted_bench, "{return test(\"%ho\", (unsigned short)385);}"},
	{1, 1193, "o_size_l_pos_casted", o_size_l_pos_casted, o_size_l_pos_casted_bench, "{return test(\"%lo\", (unsigned long)32);}"},
	{1, 1194, "o_size_ll_pos_casted", o_size_ll_pos_casted, o_size_ll_pos_casted_bench, "{return test(\"%llo\", (long long)43);}"},
	{1, 1195, "o_size_hh_pos_ref", o_size_hh_pos_ref, o_size_hh_pos_ref_bench, "{return test(\"%hho\", uch_pos_1);}"},
	{1, 1196, "o_size_h_pos_ref", o_size_h_pos_ref, o_size_h_pos_ref_bench, "{return test(\"%ho\", ush_pos_1);}"},
	{1, 1197, "o_size_l_pos_ref", o_size_l_pos_ref, o_size_l_pos_ref_bench, "{return test(\"%lo\", ul_pos_1);}"},
	{1, 1198, "o_size_ll_pos_ref", o_size_ll_pos_ref, o_size_ll_pos_ref_bench, "{return test(\"%llo\", ull_pos_1);}"},
	{1, 1199, "o_size_l_pos_big", o_size_l_pos_big, o_size_l_pos_big_bench, "{return test(\"%lo\", 22337203685477ul);}"},
	{1, 1200, "o_size_ll_pos_big", o_size_ll_pos_big, o_size_ll_pos_big_bench, "{return test(\"%llo\", 522337203685470ull);}"},
	{1, 1201, "o_ullmax", o_ullmax, o_ullmax_bench, "{return test(\"%llo\", ullmax);}"},
	{1, 1202, "o_ulmax", o_ulmax, o_ulmax_bench, "{return test(\"%lo\", ulmax);}"},
	{1, 1203, "o_uhmax", o_uhmax, o_uhmax_bench, "{return test(\"%ho\", (unsigned short)65535);}"},
	{1, 1204, "o_uhhmax", o_uhhmax, o_uhhmax_bench, "{return test(\"%hho\", (unsigned char)255);}"},
	{1, 1205, "o_size_l_pos_big_zp", o_size_l_pos_big_zp, o_size_l_pos_big_zp_bench, "{return test(\"%037lo\", 22337203685477ul);}"},
	{1, 1206, "o_size_ll_pos_big_width", o_size_ll_pos_big_width, o_size_ll_pos_big_width_bench, "{return test(\"%37llo\", 522337203685470ull);}"},
	{1, 1207, "o_size_ll_hh_ll", o_size_ll_hh_ll, o_size_ll_hh_ll_bench, "{return test(\"%llu%hhu%llo\", ull_pos_1, uch_pos_1, ull_pos_1);}"},
	{1, 1208, "o_size_h_l_hh", o_size_h_l_hh, o_size_h_l_hh_bench, "{return test(\"%hu%lu%hho\", ush_pos_1, ul_pos_1, uch_pos_1);}"},
	{1, 1209, "o_size_l_hh_h", o_size_l_hh_h, o_size_l_hh_h_bench, "{return test(\"%lu%hhu%ho\", ul_pos_1, uch_pos_1, ush_pos_1);}"},
	{1, 1210, "o_size_n_ll_hh", o_size_n_ll_hh, o_size_n_ll_hh_bench, "{return test(\"%u%llu%hho\", ui_pos_1, ull_pos_1, uch_pos_1);}"},
	{1, 1211, "o_size_ll_n_l", o_size_ll_n_l, o_size_ll_n_l_bench, "{return test(\"%llu%u%lo\", ull_pos_1, ui_pos_1, ul_pos_1);}"},
	{1, 1212, "o_basic_octl_pos_af", o_basic_octl_pos_af, o_basic_octl_pos_af_bench, "{return test(\"this %#o number\", 17);}"},
	{1, 1213, "o_basic_octl_zero_af", o_basic_octl_zero_af, o_basic_octl_zero_af_bench, "{return test(\"this %#o number\", 0);}"},
	{1, 1214, "o_basic_octl_onlypos_af", o_basic_octl_onlypos_af, o_basic_octl_onlypos_af_bench, "{return test(\"%#o\", 3);}"},
	{1, 1215, "o_octlmax_af", o_octlmax_af, o_octlmax_af_bench, "{return test(\"%#o\", 4294967295u);}"},
	{1, 1216, "o_width_pos_fits_af", o_width_pos_fits_af, o_width_pos_fits_af_bench, "{return test(\"%#7o\", 33);}"},
	{1, 1217, "o_width_zero_fits_af", o_width_zero_fits_af, o_width_zero_fits_af_bench, "{return test(\"%#3o\", 0);}"},
	{1, 1218, "o_width_pos_exactfit_af", o_width_pos_exactfit_af, o_width_pos_exactfit_af_bench, "{return test(\"%#6o\", 52625);}"},
	{1, 1219, "o_width_pos_nofit_af", o_width_pos_nofit_af, o_width_pos_nofit_af_bench, "{return test(\"%#2o\", 94827);}"},
	{1, 1220, "o_width_pos_fits_lj_af", o_width_pos_fits_lj_af, o_width_pos_fits_lj_af_bench, "{return test(\"%#-7o\", 33);}"},
	{1, 1221, "o_width_zero_fits_lj_af", o_width_zero_fits_lj_af, o_width_zero_fits_lj_af_bench, "{return test(\"%#-3o\", 0);}"},
	{1, 1222, "o_width_pos_exactfit_lj_af", o_width_pos_exactfit_lj_af, o_width_pos_exactfit_lj_af_bench, "{return test(\"%#-6o\", 52625);}"},
	{1, 1223, "o_width_pos_nofit_lj_af", o_width_pos_nofit_lj_af, o_width_pos_nofit_lj_af_bench, "{return test(\"%#-4o\", 9648627);}"},
	{1, 1224, "o_prec_fits_pos_af", o_prec_fits_pos_af, o_prec_fits_pos_af_bench, "{return test(\"%#.5o\", 21);}"},
	{1, 1225, "o_prec_fits_zero_af", o_prec_fits_zero_af, o_prec_fits_zero_af_bench, "{return test(\"%#.3o\", 0);}"},
	{1, 1226, "o_prec_exactfit_pos_af", o_prec_exactfit_pos_af, o_prec_exactfit_pos_af_bench, "{return test(\"%#.5o\", 5263);}"},
	{1, 1227, "o_prec_nofit_pos_af", o_prec_nofit_pos_af, o_prec_nofit_pos_af_bench, "{return test(\"%#.3o\", 938862);}"},
	{1, 1228, "o_zp_pos_fits_af", o_zp_pos_fits_af, o_zp_pos_fits_af_bench, "{return test(\"%#05o\", 43);}"},
	{1, 1229, "o_zp_zero_fits_af", o_zp_zero_fits_af, o_zp_zero_fits_af_bench, "{return test(\"%#03o\", 0);}"},
	{1, 1230, "o_zp_pos_exactfit_af", o_zp_pos_exactfit_af, o_zp_pos_exactfit_af_bench, "{return test(\"%#07o\", 698334);}"},
	{1, 1231, "o_prec_width_fit_fit_pos_af", o_prec_width_fit_fit_pos_af, o_prec_width_fit_fit_pos_af_bench, "{return test(\"%#8.5o\", 34);}"},
	{1, 1232, "o_prec_width_fit_fit_zero_af", o_prec_width_fit_fit_zero_af, o_prec_width_fit_fit_zero_af_bench, "{return test(\"%#8.5o\", 0);}"},
	{1, 1233, "o_prec_width_nofit_fit_pos_af", o_prec_width_nofit_fit_pos_af, o_prec_width_nofit_fit_pos_af_bench, "{return test(\"%#8.3o\", 8375);}"},
	{1, 1234, "o_prec_width_fit_nofit_pos_af", o_prec_width_fit_nofit_pos_af, o_prec_width_fit_nofit_pos_af_bench, "{return test(\"%#2.7o\", 3267);}"},
	{1, 1235, "o_prec_width_nofit_nofit_pos_af", o_prec_width_nofit_nofit_pos_af, o_prec_width_nofit_nofit_pos_af_bench, "{return test(\"%#3.3o\", 6983);}"},
	{1, 1236, "o_prec_width_fit_fit_pos_lj_af", o_prec_width_fit_fit_pos_lj_af, o_prec_width_fit_fit_pos_lj_af_bench, "{return test(\"%#-8.5o\", 34);}"},
	{1, 1237, "o_prec_width_fit_fit_zero_lj_af", o_prec_width_fit_fit_zero_lj_af, o_prec_width_fit_fit_zero_lj_af_bench, "{return test(\"%#-8.5o\", 0);}"},
	{1, 1238, "o_prec_width_nofit_fit_pos_lj_af", o_prec_width_nofit_fit_pos_lj_af, o_prec_width_nofit_fit_pos_lj_af_bench, "{return test(\"%#-8.3o\", 8375);}"},
	{1, 1239, "o_prec_width_fit_nofit_pos_lj_af", o_prec_width_fit_nofit_pos_lj_af, o_prec_width_fit_nofit_pos_lj_af_bench, "{return test(\"%#-2.7o\", 3267);}"},
	{1, 1240, "o_prec_width_nofit_nofit_pos_lj_af", o_prec_width_nofit_nofit_pos_lj_af, o_prec_width_nofit_nofit_pos_lj_af_bench, "{return test(\"%#-3.3o\", 6983);}"},
	{1, 1241, "o_prec_width_ff_pos_zp_af", o_prec_width_ff_pos_zp_af, o_prec_width_ff_pos_zp_af_bench, "{return test(\"%#08.5o\", 34);}"},
	{1, 1242, "o_prec_width_ff_zero_zp_af", o_prec_width_ff_zero_zp_af, o_prec_width_ff_zero_zp_af_bench, "{return test(\"%#08.5o\", 0);}"},
	{1, 1243, "o_prec_width_nf_pos_zp_af", o_prec_width_nf_pos_zp_af, o_prec_width_nf_pos_zp_af_bench, "{return test(\"%#08.3o\", 8375);}"},
	{1, 1244, "o_prec_width_fn_pos_zp_af", o_prec_width_fn_pos_zp_af, o_prec_width_fn_pos_zp_af_bench, "{return test(\"%#02.7o\", 3267);}"},
	{1, 1245, "o_prec_width_nn_pos_zp_af", o_prec_width_nn_pos_zp_af, o_prec_width_nn_pos_zp_af_bench, "{return test(\"%#03.3o\", 6983);}"},
	{1, 1246, "o_prec_width_ff_pos_ljzpaf_ignoreflag", o_prec_width_ff_pos_ljzpaf_ignoreflag, o_prec_width_ff_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.5o\", 34);}"},
	{1, 1247, "o_prec_width_ff_zero_ljzpaf_ignoreflag", o_prec_width_ff_zero_ljzpaf_ignoreflag, o_prec_width_ff_zero_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.5o\", 0);}"},
	{1, 1248, "o_prec_width_nf_pos_ljzpaf_ignoreflag", o_prec_width_nf_pos_ljzpaf_ignoreflag, o_prec_width_nf_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-8.3o\", 8375);}"},
	{1, 1249, "o_prec_width_fn_pos_ljzpaf_ignoreflag", o_prec_width_fn_pos_ljzpaf_ignoreflag, o_prec_width_fn_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-2.7o\", 3267);}"},
	{1, 1250, "o_prec_width_nn_pos_ljzpaf_ignoreflag", o_prec_width_nn_pos_ljzpaf_ignoreflag, o_prec_width_nn_pos_ljzpaf_ignoreflag_bench, "{return test(\"%#0-3.3o\", 6983);}"},
	{1, 1251, "o_size_hh_pos_casted_af", o_size_hh_pos_casted_af, o_size_hh_pos_casted_af_bench, "{return test(\"%#hho\", (unsigned char)45);}"},
	{1, 1252, "o_size_h_pos_casted_af", o_size_h_pos_casted_af, o_size_h_pos_casted_af_bench, "{return test(\"%#ho\", (unsigned short)385);}"},
	{1, 1253, "o_size_l_pos_casted_af", o_size_l_pos_casted_af, o_size_l_pos_casted_af_bench, "{return test(\"%#lo\", (unsigned long)32);}"},
	{1, 1254, "o_size_ll_pos_casted_af", o_size_ll_pos_casted_af, o_size_ll_pos_casted_af_bench, "{return test(\"%#llo\", (long long)43);}"},
	{1, 1255, "o_size_hh_pos_ref_af", o_size_hh_pos_ref_af, o_size_hh_pos_ref_af_bench, "{return test(\"%#hho\", uch_pos_1);}"},
	{1, 1256, "o_size_h_pos_ref_af", o_size_h_pos_ref_af, o_size_h_pos_ref_af_bench, "{return test(\"%#ho\", ush_pos_1);}"},
	{1, 1257, "o_size_l_pos_ref_af", o_size_l_pos_ref_af, o_size_l_pos_ref_af_bench, "{return test(\"%#lo\", ul_pos_1);}"},
	{1, 1258, "o_size_ll_pos_ref_af", o_size_ll_pos_ref_af, o_size_ll_pos_ref_af_bench, "{return test(\"%#llo\", ull_pos_1);}"},
	{1, 1259, "o_size_l_pos_big_af", o_size_l_pos_big_af, o_size_l_pos_big_af_bench, "{return test(\"%#lo\", 22337203685477ul);}"},
	{1, 1260, "o_size_ll_pos_big_af", o_size_ll_pos_big_af, o_size_ll_pos_big_af_bench, "{return test(\"%#llo\", 522337203685470ull);}"},
	{1, 1261, "o_ullmax_af", o_ullmax_af, o_ullmax_af_bench, "{return test(\"%#llo\", ullmax);}"},
	{1, 1262, "o_ulmax_af", o_ulmax_af, o_ulmax_af_bench, "{return test(\"%#lo\", ulmax);}"},
	{1, 1263, "o_uhmax_af", o_uhmax_af, o_uhmax_af_bench, "{return test(\"%#ho\", (unsigned short)65535);}"},
	{1, 1264, "o_uhhmax_af", o_uhhmax_af, o_uhhmax_af_bench, "{return test(\"%#hho\", (unsigned char)255);}"},
	{1, 1265, "o_size_l_pos_big_zp_af", o_size_l_pos_big_zp_af, o_size_l_pos_big_zp_af_bench, "{return test(\"%#037lo\", 22337203685477ul);}"},
	{1, 1266, "o_size_ll_pos_big_width_af", o_size_ll_pos_big_width_af, o_size_ll_pos_big_width_af_bench, "{return test(\"%#37llo\", 522337203685470ull);}"},
	{1, 1267, "o_size_ll_hh_ll_af", o_size_ll_hh_ll_af, o_size_ll_hh_ll_af_bench, "{return test(\"%llu%hhu%#llo\", ull_pos_1, uch_pos_1, ull_pos_1);}"},
	{1, 1268, "o_size_h_l_hh_af", o_size_h_l_hh_af, o_size_h_l_hh_af_bench, "{return test(\"%hu%lu%#hho\", ush_pos_1, ul_pos_1, uch_pos_1);}"},
	{1, 1269, "o_size_l_hh_h_af", o_size_l_hh_h_af, o_size_l_hh_h_af_bench, "{return test(\"%#lo%hhu%#ho\", ul_pos_1, uch_pos_1, ush_pos_1);}"},
	{1, 1270, "o_size_n_ll_hh_af", o_size_n_ll_hh_af, o_size_n_ll_hh_af_bench, "{return test(\"%#o%llu%hho\", ui_pos_1, ull_pos_1, uch_pos_1);}"},
	{1, 1271, "o_size_ll_n_l_af", o_size_ll_n_l_af, o_size_ll_n_l_af_bench, "{return test(\"%#llo%u%#lo\", ull_pos_1, ui_pos_1, ul_pos_1);}"},
	{1, 1272, "o_prec0val0_basic", o_prec0val0_basic, o_prec0val0_basic_bench, "{return test(\"%.0o\", 0);}"},
	{1, 1273, "o_prec0val0_implicit", o_prec0val0_implicit, o_prec0val0_implicit_bench, "{return test(\"%.o\", 0);}"},
	{1, 1274, "o_prec0val0_w", o_prec0val0_w, o_prec0val0_w_bench, "{return test(\"%5.0o\", 0);}"},
	{1, 1275, "o_prec0val0_w_impl", o_prec0val0_w_impl, o_prec0val0_w_impl_bench, "{return test(\"%5.o\", 0);}"},
	{1, 1276, "o_prec0val0_wlj", o_prec0val0_wlj, o_prec0val0_wlj_bench, "{return test(\"%-5.0o\", 0);}"},
	{1, 1277, "o_prec0val0_wlj_impl", o_prec0val0_wlj_impl, o_prec0val0_wlj_impl_bench, "{return test(\"%-5.o\", 0);}"},
	{1, 1278, "o_prec0val0_af", o_prec0val0_af, o_prec0val0_af_bench, "{return test(\"%#.0o\", 0);}"},
	{1, 1279, "o_prec0val0_af_impl", o_prec0val0_af_impl, o_prec0val0_af_impl_bench, "{return test(\"%#.o\", 0);}"},
	{1, 1280, "o_prec0val0_waf", o_prec0val0_waf, o_prec0val0_waf_bench, "{return test(\"%#5.0o\", 0);}"},
	{1, 1281, "o_prec0val0_waf_impl", o_prec0val0_waf_impl, o_prec0val0_waf_impl_bench, "{return test(\"%#5.o\", 0);}"},
	{1, 1282, "o_prec0val0_waflj", o_prec0val0_waflj, o_prec0val0_waflj_bench, "{return test(\"%#-5.0o\", 0);}"},
	{1, 1283, "o_prec0val0_waflj_impl", o_prec0val0_waflj_impl, o_prec0val0_waflj_impl_bench, "{return test(\"%#-5.o\", 0);}"},
	{1, 1284, "p_null", p_null, p_null_bench, "{return test(\"%p\", NULL);}"},
	{0, 1285, "p_ftfc_literal_9w_prec2_undefbehav", p_ftfc_literal_9w_prec2_undefbehav, p_ftfc_literal_9w_prec2_undefbehav_bench, "{return test(\"%9.2p\n\", 1234);}"},
	{0, 1286, "p_ftfc_literal_2w_prec9_undefbehav", p_ftfc_literal_2w_prec9_undefbehav, p_ftfc_literal_2w_prec9_undefbehav_bench, "{return test(\"%2.9p\n\", 1234);}"},
	{0, 1287, "p_ftfc_zero_prec5_undefbehav", p_ftfc_zero_prec5_undefbehav, p_ftfc_zero_prec5_undefbehav_bench, "{return test(\"%.5p\", 0);}"},
	{0, 1288, "p_ftfc_zero_prec0_undefbehav", p_ftfc_zero_prec0_undefbehav, p_ftfc_zero_prec0_undefbehav_bench, "{return test(\"%.0p\", 0);}"},
	{1, 1289, "p_ftfc_5w_throwswarning", p_ftfc_5w_throwswarning, p_ftfc_5w_throwswarning_bench, "{return test(\"%5p\", 0);}"},
	{1, 1290, "p_basic", p_basic, p_basic_bench, "{return test(\"%p%p%p%p%p%p%p%p%p%p%p%p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1291, "p_width_fit", p_width_fit, p_width_fit_bench, "{return test(\"%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1292, "p_width_nofit", p_width_nofit, p_width_nofit_bench, "{return test(\"%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1293, "p_width_16", p_width_16, p_width_16_bench, "{return test(\"%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1294, "p_width_8", p_width_8, p_width_8_bench, "{return test(\"%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1295, "p_width_32", p_width_32, p_width_32_bench, "{return test(\"%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1296, "p_width_fit_lj", p_width_fit_lj, p_width_fit_lj_bench, "{return test(\"%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1297, "p_width_nofit_lj", p_width_nofit_lj, p_width_nofit_lj_bench, "{return test(\"%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1298, "p_width_16_lj", p_width_16_lj, p_width_16_lj_bench, "{return test(\"%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1299, "p_width_8_lj", p_width_8_lj, p_width_8_lj_bench, "{return test(\"%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1300, "p_width_32_lj", p_width_32_lj, p_width_32_lj_bench, "{return test(\"%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p\",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}"},
	{1, 1301, "c_allprintable_combined", c_allprintable_combined, c_allprintable_combined_bench, "{return test(\"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\",' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}"},
	{1, 1302, "c_1_31_combined", c_1_31_combined, c_1_31_combined_bench, "{return test(\"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}"},
	{1, 1303, "c_128_255_combined", c_128_255_combined, c_128_255_combined_bench, "{return test(\"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}"},
	{1, 1304, "c_allprintable_width", c_allprintable_width, c_allprintable_width_bench, "{return test(\"%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\",' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}"},
	{1, 1305, "c_1_31_width", c_1_31_width, c_1_31_width_bench, "{return test(\"%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}"},
	{1, 1306, "c_128_255_width", c_128_255_width, c_128_255_width_bench, "{return test(\"%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}"},
	{1, 1307, "c_allprintable_width_lj", c_allprintable_width_lj, c_allprintable_width_lj_bench, "{return test(\"%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c\",' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}"},
	{1, 1308, "c_1_31_width_lj", c_1_31_width_lj, c_1_31_width_lj_bench, "{return test(\"%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}"},
	{1, 1309, "c_128_255_width_lj", c_128_255_width_lj, c_128_255_width_lj_bench, "{return test(\"%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}"},
	{1, 1310, "c_nullterm_basic", c_nullterm_basic, c_nullterm_basic_bench, "{return test(\"%c\", '\0');}"},
	{1, 1311, "c_nullterm_5w", c_nullterm_5w, c_nullterm_5w_bench, "{return test(\"%5c\", '\0');}"},
	{1, 1312, "c_nullterm_5wlj", c_nullterm_5wlj, c_nullterm_5wlj_bench, "{return test(\"%-5c\", '\0');}"},
	{1, 1313, "f_basic_1", f_basic_1, f_basic_1_bench, "{return test(\"this %f float\", 1.5);}"},
	{1, 1314, "f_basic_fltonly", f_basic_fltonly, f_basic_fltonly_bench, "{return test(\"%f\", 7.5);}"},
	{1, 1315, "f_basic_whole", f_basic_whole, f_basic_whole_bench, "{return test(\"%f\", 1.0);}"},
	{1, 1316, "f_basic_negative", f_basic_negative, f_basic_negative_bench, "{return test(\"%f\", -3.85);}"},
	{1, 1317, "f_basic_positive_3_3", f_basic_positive_3_3, f_basic_positive_3_3_bench, "{return test(\"%f\", 573.924);}"},
	{1, 1318, "f_basic_negative_3_3", f_basic_negative_3_3, f_basic_negative_3_3_bench, "{return test(\"%f\", -958.125);}"},
	{1, 1319, "f_basic_positive_smallfpart", f_basic_positive_smallfpart, f_basic_positive_smallfpart_bench, "{return test(\"%f\", 23.00041);}"},
	{1, 1320, "f_basic_positive_allsmall", f_basic_positive_allsmall, f_basic_positive_allsmall_bench, "{return test(\"%f\", 0.000039);}"},
	{1, 1321, "f_basic_negative_smallfpart", f_basic_negative_smallfpart, f_basic_negative_smallfpart_bench, "{return test(\"%f\", -7.00036);}"},
	{1, 1322, "f_basic_negative_allsmall", f_basic_negative_allsmall, f_basic_negative_allsmall_bench, "{return test(\"%f\", -0.00032);}"},
	{1, 1323, "f_basic_limits_allsmall_pos", f_basic_limits_allsmall_pos, f_basic_limits_allsmall_pos_bench, "{return test(\"%f\", 0.000001);}"},
	{1, 1324, "f_basic_limits_allsmall_neg", f_basic_limits_allsmall_neg, f_basic_limits_allsmall_neg_bench, "{return test(\"%f\", -0.000001);}"},
	{1, 1325, "f_basic_limits_smallfpart_pos", f_basic_limits_smallfpart_pos, f_basic_limits_smallfpart_pos_bench, "{return test(\"%f\", 9873.000001);}"},
	{1, 1326, "f_basic_limits_smallfpart_neg", f_basic_limits_smallfpart_neg, f_basic_limits_smallfpart_neg_bench, "{return test(\"%f\", -875.000001);}"},
	{1, 1327, "f_basic_limits_allbig_pos", f_basic_limits_allbig_pos, f_basic_limits_allbig_pos_bench, "{return test(\"%f\", 999.999999);}"},
	{1, 1328, "f_basic_limits_allbig_neg", f_basic_limits_allbig_neg, f_basic_limits_allbig_neg_bench, "{return test(\"%f\", -99.999999);}"},
	{1, 1329, "f_basic_limits_bigfpart_pos", f_basic_limits_bigfpart_pos, f_basic_limits_bigfpart_pos_bench, "{return test(\"%f\", 0.999999);}"},
	{1, 1330, "f_basic_limits_bigfpart_neg", f_basic_limits_bigfpart_neg, f_basic_limits_bigfpart_neg_bench, "{return test(\"%f\", -0.999999);}"},
	{1, 1331, "f_rndd_pos", f_rndd_pos, f_rndd_pos_bench, "{return test(\"%f\", 23.375094499);}"},
	{1, 1332, "f_rndd_neg", f_rndd_neg, f_rndd_neg_bench, "{return test(\"%f\", -985.765426499);}"},
	{1, 1333, "f_rndu_pos", f_rndu_pos, f_rndu_pos_bench, "{return test(\"%f\", 0.0894255);}"},
	{1, 1334, "f_rndu_neg", f_rndu_neg, f_rndu_neg_bench, "{return test(\"%f\", -56.2012685);}"},
	{1, 1335, "f_rndu_multidigit_pos", f_rndu_multidigit_pos, f_rndu_multidigit_pos_bench, "{return test(\"%f\", 43.4399999);}"},
	{1, 1336, "f_rndu_multidigit_neg", f_rndu_multidigit_neg, f_rndu_multidigit_neg_bench, "{return test(\"%f\", -5.0299999);}"},
	{1, 1337, "f_rndd_multidigit_pos", f_rndd_multidigit_pos, f_rndd_multidigit_pos_bench, "{return test(\"%f\", 43.43999949);}"},
	{1, 1338, "f_rndd_multidigit_neg", f_rndd_multidigit_neg, f_rndd_multidigit_neg_bench, "{return test(\"%f\", -5.02999949);}"},
	{1, 1339, "f_rndd_wholnobump_pos", f_rndd_wholnobump_pos, f_rndd_wholnobump_pos_bench, "{return test(\"%f\", 1.99999949);}"},
	{1, 1340, "f_rndd_wholnobump_neg", f_rndd_wholnobump_neg, f_rndd_wholnobump_neg_bench, "{return test(\"%f\", -0.99999949);}"},
	{1, 1341, "f_rndu_bumpwhole_pos", f_rndu_bumpwhole_pos, f_rndu_bumpwhole_pos_bench, "{return test(\"%f\", 3.9999999);}"},
	{1, 1342, "f_rndu_bumpwhole_neg", f_rndu_bumpwhole_neg, f_rndu_bumpwhole_neg_bench, "{return test(\"%f\", -5.9999999);}"},
	{1, 1343, "f_prec0_1", f_prec0_1, f_prec0_1_bench, "{return test(\"this %.0f float\", 1.6);}"},
	{1, 1344, "f_prec0_fltonly", f_prec0_fltonly, f_prec0_fltonly_bench, "{return test(\"%.0f\", 7.4);}"},
	{1, 1345, "f_prec0_whole", f_prec0_whole, f_prec0_whole_bench, "{return test(\"%.0f\", 1.0);}"},
	{1, 1346, "f_prec0_negative", f_prec0_negative, f_prec0_negative_bench, "{return test(\"%.0f\", -3.85);}"},
	{1, 1347, "f_prec0_positive_3_3", f_prec0_positive_3_3, f_prec0_positive_3_3_bench, "{return test(\"%.0f\", 573.924);}"},
	{1, 1348, "f_prec0_negative_3_3", f_prec0_negative_3_3, f_prec0_negative_3_3_bench, "{return test(\"%.0f\", -958.125);}"},
	{1, 1349, "f_prec0_positive_smallfpart", f_prec0_positive_smallfpart, f_prec0_positive_smallfpart_bench, "{return test(\"%.0f\", 23.00041);}"},
	{1, 1350, "f_prec0_positive_allsmall", f_prec0_positive_allsmall, f_prec0_positive_allsmall_bench, "{return test(\"%.0f\", 0.000039);}"},
	{1, 1351, "f_prec0_negative_smallfpart", f_prec0_negative_smallfpart, f_prec0_negative_smallfpart_bench, "{return test(\"%.0f\", -7.00036);}"},
	{1, 1352, "f_prec0_negative_allsmall", f_prec0_negative_allsmall, f_prec0_negative_allsmall_bench, "{return test(\"%.0f\", -0.00032);}"},
	{1, 1353, "f_prec1_1", f_prec1_1, f_prec1_1_bench, "{return test(\"this %.1f float\", 1.5);}"},
	{1, 1354, "f_prec1_fltonly", f_prec1_fltonly, f_prec1_fltonly_bench, "{return test(\"%.1f\", 7.5);}"},
	{1, 1355, "f_prec1_whole", f_prec1_whole, f_prec1_whole_bench, "{return test(\"%.1f\", 1.0);}"},
	{1, 1356, "f_prec1_negative", f_prec1_negative, f_prec1_negative_bench, "{return test(\"%.1f\", -3.85);}"},
	{1, 1357, "f_prec1_positive_3_3", f_prec1_positive_3_3, f_prec1_positive_3_3_bench, "{return test(\"%.1f\", 573.924);}"},
	{1, 1358, "f_prec1_negative_3_3", f_prec1_negative_3_3, f_prec1_negative_3_3_bench, "{return test(\"%.1f\", -958.125);}"},
	{1, 1359, "f_prec1_positive_smallfpart", f_prec1_positive_smallfpart, f_prec1_positive_smallfpart_bench, "{return test(\"%.1f\", 23.00041);}"},
	{1, 1360, "f_prec1_positive_allsmall", f_prec1_positive_allsmall, f_prec1_positive_allsmall_bench, "{return test(\"%.1f\", 0.000039);}"},
	{1, 1361, "f_prec1_negative_smallfpart", f_prec1_negative_smallfpart, f_prec1_negative_smallfpart_bench, "{return test(\"%.1f\", -7.00036);}"},
	{1, 1362, "f_prec1_negative_allsmall", f_prec1_negative_allsmall, f_prec1_negative_allsmall_bench, "{return test(\"%.1f\", -0.00032);}"},
	{1, 1363, "f_prec3_1", f_prec3_1, f_prec3_1_bench, "{return test(\"this %.3f float\", 1.5);}"},
	{1, 1364, "f_prec3_fltonly", f_prec3_fltonly, f_prec3_fltonly_bench, "{return test(\"%.3f\", 7.5);}"},
	{1, 1365, "f_prec3_whole", f_prec3_whole, f_prec3_whole_bench, "{return test(\"%.3f\", 1.0);}"},
	{1, 1366, "f_prec3_negative", f_prec3_negative, f_prec3_negative_bench, "{return test(\"%.3f\", -3.85);}"},
	{1, 1367, "f_prec3_positive_3_3", f_prec3_positive_3_3, f_prec3_positive_3_3_bench, "{return test(\"%.3f\", 573.924);}"},
	{1, 1368, "f_prec3_negative_3_3", f_prec3_negative_3_3, f_prec3_negative_3_3_bench, "{return test(\"%.3f\", -958.125);}"},
	{1, 1369, "f_prec3_positive_smallfpart", f_prec3_positive_smallfpart, f_prec3_positive_smallfpart_bench, "{return test(\"%.3f\", 23.00041);}"},
	{1, 1370, "f_prec3_positive_allsmall", f_prec3_positive_allsmall, f_prec3_positive_allsmall_bench, "{return test(\"%.3f\", 0.000039);}"},
	{1, 1371, "f_prec3_negative_smallfpart", f_prec3_negative_smallfpart, f_prec3_negative_smallfpart_bench, "{return test(\"%.3f\", -7.00036);}"},
	{1, 1372, "f_prec3_negative_allsmall", f_prec3_negative_allsmall, f_prec3_negative_allsmall_bench, "{return test(\"%.3f\", -0.00032);}"},
	{1, 1373, "f_prec7_1", f_prec7_1, f_prec7_1_bench, "{return test(\"this %.7f float\", 1.5);}"},
	{1, 1374, "f_prec7_fltonly", f_prec7_fltonly, f_prec7_fltonly_bench, "{return test(\"%.7f\", 7.5);}"},
	{1, 1375, "f_prec7_whole", f_prec7_whole, f_prec7_whole_bench, "{return test(\"%.7f\", 1.0);}"},
	{1, 1376, "f_prec7_negative", f_prec7_negative, f_prec7_negative_bench, "{return test(\"%.7f\", -3.85);}"},
	{1, 1377, "f_prec7_positive_3_3", f_prec7_positive_3_3, f_prec7_positive_3_3_bench, "{return test(\"%.7f\", 573.924);}"},
	{1, 1378, "f_prec7_negative_3_3", f_prec7_negative_3_3, f_prec7_negative_3_3_bench, "{return test(\"%.7f\", -958.125);}"},
	{1, 1379, "f_prec7_positive_smallfpart", f_prec7_positive_smallfpart, f_prec7_positive_smallfpart_bench, "{return test(\"%.7f\", 23.00041);}"},
	{1, 1380, "f_prec7_positive_allsmall", f_prec7_positive_allsmall, f_prec7_positive_allsmall_bench, "{return test(\"%.7f\", 0.0000039);}"},
	{1, 1381, "f_prec7_negative_smallfpart", f_prec7_negative_smallfpart, f_prec7_negative_smallfpart_bench, "{return test(\"%.7f\", -7.00036);}"},
	{1, 1382, "f_prec7_negative_allsmall", f_prec7_negative_allsmall, f_prec7_negative_allsmall_bench, "{return test(\"%.7f\", -0.000032);}"},
	{1, 1383, "f_prec7_limits_allsmall_pos", f_prec7_limits_allsmall_pos, f_prec7_limits_allsmall_pos_bench, "{return test(\"%.7f\", 0.0000001);}"},
	{1, 1384, "f_prec7_limits_allsmall_neg", f_prec7_limits_allsmall_neg, f_prec7_limits_allsmall_neg_bench, "{return test(\"%.7f\", -0.0000001);}"},
	{1, 1385, "f_prec7_limits_smallfpart_pos", f_prec7_limits_smallfpart_pos, f_prec7_limits_smallfpart_pos_bench, "{return test(\"%.7f\", 9873.000001);}"},
	{1, 1386, "f_prec7_limits_smallfpart_neg", f_prec7_limits_smallfpart_neg, f_prec7_limits_smallfpart_neg_bench, "{return test(\"%.7f\", -875.000001);}"},
	{1, 1387, "f_prec7_limits_allbig_pos", f_prec7_limits_allbig_pos, f_prec7_limits_allbig_pos_bench, "{return test(\"%.7f\", 999.9999999);}"},
	{1, 1388, "f_prec7_limits_allbig_neg", f_prec7_limits_allbig_neg, f_prec7_limits_allbig_neg_bench, "{return test(\"%.7f\", -99.9999999);}"},
	{1, 1389, "f_prec7_limits_bigfpart_pos", f_prec7_limits_bigfpart_pos, f_prec7_limits_bigfpart_pos_bench, "{return test(\"%.7f\", 0.999999);}"},
	{1, 1390, "f_prec7_limits_bigfpart_neg", f_prec7_limits_bigfpart_neg, f_prec7_limits_bigfpart_neg_bench, "{return test(\"%.7f\", -0.999999);}"},
	{1, 1391, "f_rnd_prec7_rndd_pos", f_rnd_prec7_rndd_pos, f_rnd_prec7_rndd_pos_bench, "{return test(\"%.7f\", 23.375094499);}"},
	{1, 1392, "f_rnd_prec7_rndd_neg", f_rnd_prec7_rndd_neg, f_rnd_prec7_rndd_neg_bench, "{return test(\"%.7f\", -985.765426499);}"},
	{1, 1393, "f_rnd_prec7_rndu_pos", f_rnd_prec7_rndu_pos, f_rnd_prec7_rndu_pos_bench, "{return test(\"%.7f\", 0.0894255);}"},
	{1, 1394, "f_rnd_prec7_rndu_neg", f_rnd_prec7_rndu_neg, f_rnd_prec7_rndu_neg_bench, "{return test(\"%.7f\", -56.2012685);}"},
	{1, 1395, "f_rnd_prec7_rndu_multidigit_pos", f_rnd_prec7_rndu_multidigit_pos, f_rnd_prec7_rndu_multidigit_pos_bench, "{return test(\"%.7f\", 43.4399999);}"},
	{1, 1396, "f_rnd_prec7_rndu_multidigit_neg", f_rnd_prec7_rndu_multidigit_neg, f_rnd_prec7_rndu_multidigit_neg_bench, "{return test(\"%.7f\", -5.0299999);}"},
	{1, 1397, "f_rnd_prec7_rndd_multidigit_pos", f_rnd_prec7_rndd_multidigit_pos, f_rnd_prec7_rndd_multidigit_pos_bench, "{return test(\"%.7f\", 43.43999949);}"},
	{1, 1398, "f_rnd_prec7_rndd_multidigit_neg", f_rnd_prec7_rndd_multidigit_neg, f_rnd_prec7_rndd_multidigit_neg_bench, "{return test(\"%.7f\", -5.02999949);}"},
	{1, 1399, "f_rnd_prec7_rndd_wholnobump_pos", f_rnd_prec7_rndd_wholnobump_pos, f_rnd_prec7_rndd_wholnobump_pos_bench, "{return test(\"%.7f\", 1.99999949);}"},
	{1, 1400, "f_rnd_prec7_rndd_wholnobump_neg", f_rnd_prec7_rndd_wholnobump_neg, f_rnd_prec7_rndd_wholnobump_neg_bench, "{return test(\"%.7f\", -0.99999949);}"},
	{1, 1401, "f_rnd_prec7_rndu_bumpwhole_pos", f_rnd_prec7_rndu_bumpwhole_pos, f_rnd_prec7_rndu_bumpwhole_pos_bench, "{return test(\"%.7f\", 3.9999999);}"},
	{1, 1402, "f_prec8_1", f_prec8_1, f_prec8_1_bench, "{return test(\"this %.8f float\", 1.5);}"},
	{1, 1403, "f_prec8_fltonly", f_prec8_fltonly, f_prec8_fltonly_bench, "{return test(\"%.8f\", 7.5);}"},
	{1, 1404, "f_prec8_whole", f_prec8_whole, f_prec8_whole_bench, "{return test(\"%.8f\", 1.0);}"},
	{1, 1405, "f_prec8_negative", f_prec8_negative, f_prec8_negative_bench, "{return test(\"%.8f\", -3.85);}"},
	{1, 1406, "f_prec8_positive_3_3", f_prec8_positive_3_3, f_prec8_positive_3_3_bench, "{return test(\"%.8f\", 573.924);}"},
	{1, 1407, "f_prec8_negative_3_3", f_prec8_negative_3_3, f_prec8_negative_3_3_bench, "{return test(\"%.8f\", -958.125);}"},
	{1, 1408, "f_prec8_positive_smallfpart", f_prec8_positive_smallfpart, f_prec8_positive_smallfpart_bench, "{return test(\"%.8f\", 23.00041);}"},
	{1, 1409, "f_prec8_positive_allsmall", f_prec8_positive_allsmall, f_prec8_positive_allsmall_bench, "{return test(\"%.8f\", 0.00000039);}"},
	{1, 1410, "f_prec8_negative_smallfpart", f_prec8_negative_smallfpart, f_prec8_negative_smallfpart_bench, "{return test(\"%.8f\", -7.00036);}"},
	{1, 1411, "f_prec8_negative_allsmall", f_prec8_negative_allsmall, f_prec8_negative_allsmall_bench, "{return test(\"%.8f\", -0.0000032);}"},
	{1, 1412, "f_prec8_limits_allsmall_pos", f_prec8_limits_allsmall_pos, f_prec8_limits_allsmall_pos_bench, "{return test(\"%.8f\", 0.00000001);}"},
	{1, 1413, "f_prec8_limits_allsmall_neg", f_prec8_limits_allsmall_neg, f_prec8_limits_allsmall_neg_bench, "{return test(\"%.8f\", -0.00000001);}"},
	{1, 1414, "f_prec8_limits_smallfpart_pos", f_prec8_limits_smallfpart_pos, f_prec8_limits_smallfpart_pos_bench, "{return test(\"%.8f\", 9873.000001);}"},
	{1, 1415, "f_prec8_limits_smallfpart_neg", f_prec8_limits_smallfpart_neg, f_prec8_limits_smallfpart_neg_bench, "{return test(\"%.8f\", -875.000001);}"},
	{1, 1416, "f_prec8_limits_allbig_pos", f_prec8_limits_allbig_pos, f_prec8_limits_allbig_pos_bench, "{return test(\"%.8f\", 999.9999999);}"},
	{1, 1417, "f_prec8_limits_allbig_neg", f_prec8_limits_allbig_neg, f_prec8_limits_allbig_neg_bench, "{return test(\"%.8f\", -99.99999999);}"},
	{1, 1418, "f_prec8_limits_bigfpart_pos", f_prec8_limits_bigfpart_pos, f_prec8_limits_bigfpart_pos_bench, "{return test(\"%.8f\", 0.999999);}"},
	{1, 1419, "f_prec8_limits_bigfpart_neg", f_prec8_limits_bigfpart_neg, f_prec8_limits_bigfpart_neg_bench, "{return test(\"%.8f\", -0.999999);}"},
	{1, 1420, "f_rnd_prec8_rndd_pos", f_rnd_prec8_rndd_pos, f_rnd_prec8_rndd_pos_bench, "{return test(\"%.8f\", 23.375094499);}"},
	{1, 1421, "f_rnd_prec8_rndd_neg", f_rnd_prec8_rndd_neg, f_rnd_prec8_rndd_neg_bench, "{return test(\"%.8f\", -985.765426499);}"},
	{1, 1422, "f_rnd_prec8_rndu_pos", f_rnd_prec8_rndu_pos, f_rnd_prec8_rndu_pos_bench, "{return test(\"%.8f\", 0.0894255);}"},
	{1, 1423, "f_rnd_prec8_rndu_neg", f_rnd_prec8_rndu_neg, f_rnd_prec8_rndu_neg_bench, "{return test(\"%.8f\", -56.2012685);}"},
	{1, 1424, "f_rnd_prec8_rndu_multidigit_pos", f_rnd_prec8_rndu_multidigit_pos, f_rnd_prec8_rndu_multidigit_pos_bench, "{return test(\"%.8f\", 43.4399999);}"},
	{1, 1425, "f_rnd_prec8_rndu_multidigit_neg", f_rnd_prec8_rndu_multidigit_neg, f_rnd_prec8_rndu_multidigit_neg_bench, "{return test(\"%.8f\", -5.0299999);}"},
	{1, 1426, "f_rnd_prec8_rndd_multidigit_pos", f_rnd_prec8_rndd_multidigit_pos, f_rnd_prec8_rndd_multidigit_pos_bench, "{return test(\"%.8f\", 43.43999949);}"},
	{1, 1427, "f_rnd_prec8_rndd_multidigit_neg", f_rnd_prec8_rndd_multidigit_neg, f_rnd_prec8_rndd_multidigit_neg_bench, "{return test(\"%.8f\", -5.02999949);}"},
	{1, 1428, "f_rnd_prec8_rndd_wholnobump_pos", f_rnd_prec8_rndd_wholnobump_pos, f_rnd_prec8_rndd_wholnobump_pos_bench, "{return test(\"%.8f\", 1.99999949);}"},
	{1, 1429, "f_rnd_prec8_rndd_wholnobump_neg", f_rnd_prec8_rndd_wholnobump_neg, f_rnd_prec8_rndd_wholnobump_neg_bench, "{return test(\"%.8f\", -0.99999949);}"},
	{1, 1430, "f_rnd_prec8_rndu_bumpwhole_pos", f_rnd_prec8_rndu_bumpwhole_pos, f_rnd_prec8_rndu_bumpwhole_pos_bench, "{return test(\"%.8f\", 3.9999999);}"},
	{1, 1431, "f_stress_prec9_1", f_stress_prec9_1, f_stress_prec9_1_bench, "{return test(\"this %.9f float\", 1.5);}"},
	{1, 1432, "f_stress_prec9_fltonly", f_stress_prec9_fltonly, f_stress_prec9_fltonly_bench, "{return test(\"%.9f\", 7.5);}"},
	{1, 1433, "f_stress_prec9_whole", f_stress_prec9_whole, f_stress_prec9_whole_bench, "{return test(\"%.9f\", 1.0);}"},
	{1, 1434, "f_stress_prec9_negative", f_stress_prec9_negative, f_stress_prec9_negative_bench, "{return test(\"%.9f\", -3.85);}"},
	{1, 1435, "f_stress_prec9_positive_3_3", f_stress_prec9_positive_3_3, f_stress_prec9_positive_3_3_bench, "{return test(\"%.9f\", 573.924);}"},
	{1, 1436, "f_stress_prec9_negative_3_3", f_stress_prec9_negative_3_3, f_stress_prec9_negative_3_3_bench, "{return test(\"%.9f\", -958.125);}"},
	{1, 1437, "f_stress_prec9_positive_smallfpart", f_stress_prec9_positive_smallfpart, f_stress_prec9_positive_smallfpart_bench, "{return test(\"%.9f\", 23.00041);}"},
	{1, 1438, "f_stress_prec9_positive_allsmall", f_stress_prec9_positive_allsmall, f_stress_prec9_positive_allsmall_bench, "{return test(\"%.9f\", 0.00000039);}"},
	{1, 1439, "f_stress_prec9_negative_smallfpart", f_stress_prec9_negative_smallfpart, f_stress_prec9_negative_smallfpart_bench, "{return test(\"%.9f\", -7.00036);}"},
	{1, 1440, "f_stress_prec9_negative_allsmall", f_stress_prec9_negative_allsmall, f_stress_prec9_negative_allsmall_bench, "{return test(\"%.9f\", -0.0000032);}"},
	{1, 1441, "f_stress_prec9_limits_allsmall_pos", f_stress_prec9_limits_allsmall_pos, f_stress_prec9_limits_allsmall_pos_bench, "{return test(\"%.9f\", 0.00000001);}"},
	{1, 1442, "f_stress_prec9_limits_allsmall_neg", f_stress_prec9_limits_allsmall_neg, f_stress_prec9_limits_allsmall_neg_bench, "{return test(\"%.9f\", -0.00000001);}"},
	{1, 1443, "f_stress_prec9_limits_smallfpart_pos", f_stress_prec9_limits_smallfpart_pos, f_stress_prec9_limits_smallfpart_pos_bench, "{return test(\"%.9f\", 9873.000001);}"},
	{1, 1444, "f_stress_prec9_limits_smallfpart_neg", f_stress_prec9_limits_smallfpart_neg, f_stress_prec9_limits_smallfpart_neg_bench, "{return test(\"%.9f\", -875.000001);}"},
	{1, 1445, "f_stress_prec9_limits_allbig_pos", f_stress_prec9_limits_allbig_pos, f_stress_prec9_limits_allbig_pos_bench, "{return test(\"%.9f\", 999.99999999);}"},
	{1, 1446, "f_stress_prec9_limits_allbig_neg", f_stress_prec9_limits_allbig_neg, f_stress_prec9_limits_allbig_neg_bench, "{return test(\"%.9f\", -99.99999999);}"},
	{1, 1447, "f_stress_prec9_limits_bigfpart_pos", f_stress_prec9_limits_bigfpart_pos, f_stress_prec9_limits_bigfpart_pos_bench, "{return test(\"%.9f\", 0.999999);}"},
	{1, 1448, "f_stress_prec9_limits_bigfpart_neg", f_stress_prec9_limits_bigfpart_neg, f_stress_prec9_limits_bigfpart_neg_bench, "{return test(\"%.9f\", -0.999999);}"},
	{1, 1449, "f_stress_prec9_rndd_pos", f_stress_prec9_rndd_pos, f_stress_prec9_rndd_pos_bench, "{return test(\"%.9f\", 23.375094499);}"},
	{1, 1450, "f_stress_prec9_rndd_neg", f_stress_prec9_rndd_neg, f_stress_prec9_rndd_neg_bench, "{return test(\"%.9f\", -985.765426499);}"},
	{1, 1451, "f_stress_prec9_rndu_pos", f_stress_prec9_rndu_pos, f_stress_prec9_rndu_pos_bench, "{return test(\"%.9f\", 0.0894255);}"},
	{1, 1452, "f_stress_prec9_rndu_neg", f_stress_prec9_rndu_neg, f_stress_prec9_rndu_neg_bench, "{return test(\"%.9f\", -56.2012685);}"},
	{1, 1453, "f_stress_prec9_rndu_multidigit_pos", f_stress_prec9_rndu_multidigit_pos, f_stress_prec9_rndu_multidigit_pos_bench, "{return test(\"%.9f\", 43.4399999);}"},
	{1, 1454, "f_stress_prec9_rndu_multidigit_neg", f_stress_prec9_rndu_multidigit_neg, f_stress_prec9_rndu_multidigit_neg_bench, "{return test(\"%.9f\", -5.0299999);}"},
	{1, 1455, "f_stress_prec9_rndd_multidigit_pos", f_stress_prec9_rndd_multidigit_pos, f_stress_prec9_rndd_multidigit_pos_bench, "{return test(\"%.9f\", 43.43999949);}"},
	{1, 1456, "f_stress_prec9_rndd_multidigit_neg", f_stress_prec9_rndd_multidigit_neg, f_stress_prec9_rndd_multidigit_neg_bench, "{return test(\"%.9f\", -5.02999949);}"},
	{1, 1457, "f_stress_prec9_rndd_wholnobump_pos", f_stress_prec9_rndd_wholnobump_pos, f_stress_prec9_rndd_wholnobump_pos_bench, "{return test(\"%.9f\", 1.99999949);}"},
	{1, 1458, "f_stress_prec9_rndd_wholnobump_neg", f_stress_prec9_rndd_wholnobump_neg, f_stress_prec9_rndd_wholnobump_neg_bench, "{return test(\"%.9f\", -0.99999949);}"},
	{1, 1459, "f_stress_prec9_rndu_bumpwhole_pos", f_stress_prec9_rndu_bumpwhole_pos, f_stress_prec9_rndu_bumpwhole_pos_bench, "{return test(\"%.9f\", 3.9999999);}"},
	{1, 1460, "f_stress_prec10_1", f_stress_prec10_1, f_stress_prec10_1_bench, "{return test(\"this %.10f float\", 1.5);}"},
	{1, 1461, "f_stress_prec10_fltonly", f_stress_prec10_fltonly, f_stress_prec10_fltonly_bench, "{return test(\"%.10f\", 7.5);}"},
	{1, 1462, "f_stress_prec10_whole", f_stress_prec10_whole, f_stress_prec10_whole_bench, "{return test(\"%.10f\", 1.0);}"},
	{1, 1463, "f_stress_prec10_negative", f_stress_prec10_negative, f_stress_prec10_negative_bench, "{return test(\"%.10f\", -3.85);}"},
	{1, 1464, "f_stress_prec10_positive_3_10", f_stress_prec10_positive_3_10, f_stress_prec10_positive_3_10_bench, "{return test(\"%.10f\", 573.924);}"},
	{1, 1465, "f_stress_prec10_negative_3_10", f_stress_prec10_negative_3_10, f_stress_prec10_negative_3_10_bench, "{return test(\"%.10f\", -958.125);}"},
	{1, 1466, "f_stress_prec10_pos", f_stress_prec10_pos, f_stress_prec10_pos_bench, "{return test(\"%.10f\", 23.8341375094);}"},
	{1, 1467, "f_stress_prec10_neg", f_stress_prec10_neg, f_stress_prec10_neg_bench, "{return test(\"%.10f\", -985.2459765426);}"},
	{1, 1468, "f_stress_prec10_rndd_pos", f_stress_prec10_rndd_pos, f_stress_prec10_rndd_pos_bench, "{return test(\"%.10f\", 23.8341375094499);}"},
	{1, 1469, "f_stress_prec10_rndd_neg", f_stress_prec10_rndd_neg, f_stress_prec10_rndd_neg_bench, "{return test(\"%.10f\", -985.2459765426499);}"},
	{1, 1470, "f_stress_prec10_rndu_pos", f_stress_prec10_rndu_pos, f_stress_prec10_rndu_pos_bench, "{return test(\"%.10f\", 0.87650894255);}"},
	{1, 1471, "f_stress_prec10_rndu_neg", f_stress_prec10_rndu_neg, f_stress_prec10_rndu_neg_bench, "{return test(\"%.10f\", -56.47852012685);}"},
	{1, 1472, "f_stress_prec10_positive_smallfpart", f_stress_prec10_positive_smallfpart, f_stress_prec10_positive_smallfpart_bench, "{return test(\"%.10f\", 23.000000041);}"},
	{1, 1473, "f_stress_prec10_positive_allsmall", f_stress_prec10_positive_allsmall, f_stress_prec10_positive_allsmall_bench, "{return test(\"%.10f\", 0.0000000039);}"},
	{1, 1474, "f_stress_prec10_negative_smallfpart", f_stress_prec10_negative_smallfpart, f_stress_prec10_negative_smallfpart_bench, "{return test(\"%.10f\", -7.000000036);}"},
	{1, 1475, "f_stress_prec10_negative_allsmall", f_stress_prec10_negative_allsmall, f_stress_prec10_negative_allsmall_bench, "{return test(\"%.10f\", -0.000000032);}"},
	{1, 1476, "f_stress_prec10_limits_allsmall_pos", f_stress_prec10_limits_allsmall_pos, f_stress_prec10_limits_allsmall_pos_bench, "{return test(\"%.10f\", 0.0000000001);}"},
	{1, 1477, "f_stress_prec10_limits_allsmall_neg", f_stress_prec10_limits_allsmall_neg, f_stress_prec10_limits_allsmall_neg_bench, "{return test(\"%.10f\", -0.0000000001);}"},
	{1, 1478, "f_stress_prec10_limits_smallfpart_pos", f_stress_prec10_limits_smallfpart_pos, f_stress_prec10_limits_smallfpart_pos_bench, "{return test(\"%.10f\", 9873.0000000001);}"},
	{1, 1479, "f_stress_prec10_limits_smallfpart_neg", f_stress_prec10_limits_smallfpart_neg, f_stress_prec10_limits_smallfpart_neg_bench, "{return test(\"%.10f\", -875.0000000001);}"},
	{1, 1480, "f_stress_prec10_limits_allbig_pos", f_stress_prec10_limits_allbig_pos, f_stress_prec10_limits_allbig_pos_bench, "{return test(\"%.10f\", 999.9999999999);}"},
	{1, 1481, "f_stress_prec10_limits_allbig_neg", f_stress_prec10_limits_allbig_neg, f_stress_prec10_limits_allbig_neg_bench, "{return test(\"%.10f\", -99.9999999999);}"},
	{1, 1482, "f_stress_prec10_limits_bigfpart_pos", f_stress_prec10_limits_bigfpart_pos, f_stress_prec10_limits_bigfpart_pos_bench, "{return test(\"%.10f\", 0.9999999999);}"},
	{1, 1483, "f_stress_prec10_limits_bigfpart_neg", f_stress_prec10_limits_bigfpart_neg, f_stress_prec10_limits_bigfpart_neg_bench, "{return test(\"%.10f\", -0.9999999999);}"},
	{1, 1484, "f_stress_prec11_rndu", f_stress_prec11_rndu, f_stress_prec11_rndu_bench, "{return test(\"%.11f\",        1.025978541236587568);}"},
	{1, 1485, "f_stress_prec11_rndd", f_stress_prec11_rndd, f_stress_prec11_rndd_bench, "{return test(\"%.11f\",        1.025978548534310421);}"},
	{1, 1486, "f_stress_prec11_limits_tiny", f_stress_prec11_limits_tiny, f_stress_prec11_limits_tiny_bench, "{return test(\"%.11f\", 0.000000000010000000);}"},
	{1, 1487, "f_stress_prec11_limits_big", f_stress_prec11_limits_big, f_stress_prec11_limits_big_bench, "{return test(\"%.11f\", 99.999999999990000000);}"},
	{1, 1488, "f_stress_prec12_rndu", f_stress_prec12_rndu, f_stress_prec12_rndu_bench, "{return test(\"%.12f\",        1.025978541236587568);}"},
	{1, 1489, "f_stress_prec12_rndd", f_stress_prec12_rndd, f_stress_prec12_rndd_bench, "{return test(\"%.12f\",        1.025978548534310421);}"},
	{1, 1490, "f_stress_prec12_limits_tiny", f_stress_prec12_limits_tiny, f_stress_prec12_limits_tiny_bench, "{return test(\"%.12f\", 0.000000000001000000);}"},
	{1, 1491, "f_stress_prec12_limits_big", f_stress_prec12_limits_big, f_stress_prec12_limits_big_bench, "{return test(\"%.12f\", 99.999999999999000000);}"},
	{1, 1492, "f_stress_prec13_rndu", f_stress_prec13_rndu, f_stress_prec13_rndu_bench, "{return test(\"%.13f\",        1.025978541136587568);}"},
	{1, 1493, "f_stress_prec13_rndd", f_stress_prec13_rndd, f_stress_prec13_rndd_bench, "{return test(\"%.13f\",        1.025978548534310421);}"},
	{1, 1494, "f_stress_prec13_limits_tiny", f_stress_prec13_limits_tiny, f_stress_prec13_limits_tiny_bench, "{return test(\"%.13f\", 0.000000000000100000);}"},
	{1, 1495, "f_stress_prec13_limits_big", f_stress_prec13_limits_big, f_stress_prec13_limits_big_bench, "{return test(\"%.13f\", 99.999999999999900000);}"},
	{1, 1496, "f_stress_prec14_rndu", f_stress_prec14_rndu, f_stress_prec14_rndu_bench, "{return test(\"%.14f\",        1.025978541436587568);}"},
	{1, 1497, "f_stress_prec14_rndd", f_stress_prec14_rndd, f_stress_prec14_rndd_bench, "{return test(\"%.14f\",        1.025978548534310421);}"},
	{1, 1498, "f_stress_prec14_limits_tiny", f_stress_prec14_limits_tiny, f_stress_prec14_limits_tiny_bench, "{return test(\"%.14f\", 0.000000000000010000);}"},
	{1, 1499, "f_stress_prec14_limits_big", f_stress_prec14_limits_big, f_stress_prec14_limits_big_bench, "{return test(\"%.14f\",  9.999999999999990000);}"},
	{1, 1500, "f_stress_prec15_rndu", f_stress_prec15_rndu, f_stress_prec15_rndu_bench, "{return test(\"%.15f\",        1.025978542436587568);}"},
	{1, 1501, "f_stress_prec15_rndd", f_stress_prec15_rndd, f_stress_prec15_rndd_bench, "{return test(\"%.15f\",        1.025978548534310421);}"},
	{1, 1502, "f_stress_prec15_limits_tiny", f_stress_prec15_limits_tiny, f_stress_prec15_limits_tiny_bench, "{return test(\"%.15f\", 0.000000000000001000);}"},
	{1, 1503, "f_stress_prec15_limits_big", f_stress_prec15_limits_big, f_stress_prec15_limits_big_bench, "{return test(\"%.15f\",  0.999999999999999000);}"},
	{1, 1504, "f_stress_prec16_rndu", f_stress_prec16_rndu, f_stress_prec16_rndu_bench, "{return test(\"%.16f\",        1.025978542436587568);}"},
	{1, 1505, "f_stress_prec16_rndd", f_stress_prec16_rndd, f_stress_prec16_rndd_bench, "{return test(\"%.16f\",        1.025978548534310421);}"},
	{1, 1506, "f_stress_prec16_limits_tiny", f_stress_prec16_limits_tiny, f_stress_prec16_limits_tiny_bench, "{return test(\"%.16f\", 0.000000000000000100);}"},
	{1, 1507, "f_stress_prec16_limits_big", f_stress_prec16_limits_big, f_stress_prec16_limits_big_bench, "{return test(\"%.16f\",  0.999999999999999900);}"},
	{1, 1508, "f_stress_prec17_rndu", f_stress_prec17_rndu, f_stress_prec17_rndu_bench, "{return test(\"%.17f\",        1.025978542436587568);}"},
	{1, 1509, "f_stress_prec17_rndd", f_stress_prec17_rndd, f_stress_prec17_rndd_bench, "{return test(\"%.17f\",        1.025978548534310421);}"},
	{1, 1510, "f_stress_prec17_limits_tiny", f_stress_prec17_limits_tiny, f_stress_prec17_limits_tiny_bench, "{return test(\"%.17f\", 0.000000000000000010);}"},
	{1, 1511, "f_stress_prec17_limits_big", f_stress_prec17_limits_big, f_stress_prec17_limits_big_bench, "{return test(\"%.17f\",  0.999999999999999990);}"},
	{1, 1512, "f_stress_prec18_rndu", f_stress_prec18_rndu, f_stress_prec18_rndu_bench, "{return test(\"%.18f\",        0.125978542436587568);}"},
	{1, 1513, "f_stress_prec18_rndd", f_stress_prec18_rndd, f_stress_prec18_rndd_bench, "{return test(\"%.18f\",        0.125978548534310421);}"},
	{1, 1514, "f_af_prec0p", f_af_prec0p, f_af_prec0p_bench, "{return test(\"%#.0f\", 7.4);}"},
	{1, 1515, "f_af_prec1p", f_af_prec1p, f_af_prec1p_bench, "{return test(\"%#.1f\", 7.3);}"},
	{1, 1516, "f_af_prec0n", f_af_prec0n, f_af_prec0n_bench, "{return test(\"%#.0f\", -7.4);}"},
	{1, 1517, "f_af_prec1n", f_af_prec1n, f_af_prec1n_bench, "{return test(\"%#.1f\", -7.3);}"},
	{1, 1518, "f_as_prec0p_as", f_as_prec0p_as, f_as_prec0p_as_bench, "{return test(\"%+.0f\", 7.4);}"},
	{1, 1519, "f_as_prec3p_as", f_as_prec3p_as, f_as_prec3p_as_bench, "{return test(\"%+.3f\", 7.3);}"},
	{1, 1520, "f_as_prec0n_as", f_as_prec0n_as, f_as_prec0n_as_bench, "{return test(\"%+.0f\", -7.4);}"},
	{1, 1521, "f_as_prec3n_as", f_as_prec3n_as, f_as_prec3n_as_bench, "{return test(\"%+.3f\", -7.3);}"},
	{1, 1522, "f_wprec0p", f_wprec0p, f_wprec0p_bench, "{return test(\"%5.0f\", 7.3);}"},
	{1, 1523, "f_wprec1p", f_wprec1p, f_wprec1p_bench, "{return test(\"%5.1f\", 7.3);}"},
	{1, 1524, "f_wprec3p", f_wprec3p, f_wprec3p_bench, "{return test(\"%5.3f\", 7.3);}"},
	{1, 1525, "f_wprec6p", f_wprec6p, f_wprec6p_bench, "{return test(\"%5.6f\", 7.3);}"},
	{1, 1526, "f_wprec0n", f_wprec0n, f_wprec0n_bench, "{return test(\"%5.0f\", -7.3);}"},
	{1, 1527, "f_wprec1n", f_wprec1n, f_wprec1n_bench, "{return test(\"%5.1f\", -7.3);}"},
	{1, 1528, "f_wprec3n", f_wprec3n, f_wprec3n_bench, "{return test(\"%5.3f\", -7.3);}"},
	{1, 1529, "f_wprec6n", f_wprec6n, f_wprec6n_bench, "{return test(\"%5.6f\", -7.3);}"},
	{1, 1530, "f_wzp_prec0p", f_wzp_prec0p, f_wzp_prec0p_bench, "{return test(\"%05.0f\", 7.3);}"},
	{1, 1531, "f_wzp_prec1p", f_wzp_prec1p, f_wzp_prec1p_bench, "{return test(\"%05.1f\", 7.3);}"},
	{1, 1532, "f_wzp_prec3p", f_wzp_prec3p, f_wzp_prec3p_bench, "{return test(\"%05.3f\", 7.3);}"},
	{1, 1533, "f_wzp_prec6p", f_wzp_prec6p, f_wzp_prec6p_bench, "{return test(\"%05.6f\", 7.3);}"},
	{1, 1534, "f_wzp_prec0n", f_wzp_prec0n, f_wzp_prec0n_bench, "{return test(\"%05.0f\", -7.3);}"},
	{1, 1535, "f_wzp_prec1n", f_wzp_prec1n, f_wzp_prec1n_bench, "{return test(\"%05.1f\", -7.3);}"},
	{1, 1536, "f_wzp_prec3n", f_wzp_prec3n, f_wzp_prec3n_bench, "{return test(\"%05.3f\", -7.3);}"},
	{1, 1537, "f_wzp_prec6n", f_wzp_prec6n, f_wzp_prec6n_bench, "{return test(\"%05.6f\", -7.3);}"},
	{1, 1538, "f_wlj_prec0p", f_wlj_prec0p, f_wlj_prec0p_bench, "{return test(\"%-5.0f\", 7.3);}"},
	{1, 1539, "f_wlj_prec1p", f_wlj_prec1p, f_wlj_prec1p_bench, "{return test(\"%-5.1f\", 7.3);}"},
	{1, 1540, "f_wlj_prec3p", f_wlj_prec3p, f_wlj_prec3p_bench, "{return test(\"%-5.3f\", 7.3);}"},
	{1, 1541, "f_wlj_prec6p", f_wlj_prec6p, f_wlj_prec6p_bench, "{return test(\"%-5.6f\", 7.3);}"},
	{1, 1542, "f_wlj_prec0n", f_wlj_prec0n, f_wlj_prec0n_bench, "{return test(\"%-5.0f\", -7.3);}"},
	{1, 1543, "f_wlj_prec1n", f_wlj_prec1n, f_wlj_prec1n_bench, "{return test(\"%-5.1f\", -7.3);}"},
	{1, 1544, "f_wlj_prec3n", f_wlj_prec3n, f_wlj_prec3n_bench, "{return test(\"%-5.3f\", -7.3);}"},
	{1, 1545, "f_wlj_prec6n", f_wlj_prec6n, f_wlj_prec6n_bench, "{return test(\"%-5.6f\", -7.3);}"},
	{1, 1546, "f_wzplj_prec0p_ignoreflag", f_wzplj_prec0p_ignoreflag, f_wzplj_prec0p_ignoreflag_bench, "{return test(\"%-05.0f\", 7.3);}"},
	{1, 1547, "f_wzplj_prec1p_ignoreflag", f_wzplj_prec1p_ignoreflag, f_wzplj_prec1p_ignoreflag_bench, "{return test(\"%-05.1f\", 7.3);}"},
	{1, 1548, "f_wzplj_prec3p_ignoreflag", f_wzplj_prec3p_ignoreflag, f_wzplj_prec3p_ignoreflag_bench, "{return test(\"%-05.3f\", 7.3);}"},
	{1, 1549, "f_wzplj_prec6p_ignoreflag", f_wzplj_prec6p_ignoreflag, f_wzplj_prec6p_ignoreflag_bench, "{return test(\"%-05.6f\", 7.3);}"},
	{1, 1550, "f_wzplj_prec0n_ignoreflag", f_wzplj_prec0n_ignoreflag, f_wzplj_prec0n_ignoreflag_bench, "{return test(\"%-05.0f\", -7.3);}"},
	{1, 1551, "f_wzplj_prec1n_ignoreflag", f_wzplj_prec1n_ignoreflag, f_wzplj_prec1n_ignoreflag_bench, "{return test(\"%-05.1f\", -7.3);}"},
	{1, 1552, "f_wzplj_prec3n_ignoreflag", f_wzplj_prec3n_ignoreflag, f_wzplj_prec3n_ignoreflag_bench, "{return test(\"%-05.3f\", -7.3);}"},
	{1, 1553, "f_wzplj_prec6n_ignoreflag", f_wzplj_prec6n_ignoreflag, f_wzplj_prec6n_ignoreflag_bench, "{return test(\"%-05.6f\", -7.3);}"},
	{1, 1554, "f_wzpljr_prec0p_ignoreflag", f_wzpljr_prec0p_ignoreflag, f_wzpljr_prec0p_ignoreflag_bench, "{return test(\"%0-5.0f\", 7.3);}"},
	{1, 1555, "f_wzpljr_prec1p_ignoreflag", f_wzpljr_prec1p_ignoreflag, f_wzpljr_prec1p_ignoreflag_bench, "{return test(\"%0-5.1f\", 7.3);}"},
	{1, 1556, "f_wzpljr_prec3p_ignoreflag", f_wzpljr_prec3p_ignoreflag, f_wzpljr_prec3p_ignoreflag_bench, "{return test(\"%0-5.3f\", 7.3);}"},
	{1, 1557, "f_wzpljr_prec6p_ignoreflag", f_wzpljr_prec6p_ignoreflag, f_wzpljr_prec6p_ignoreflag_bench, "{return test(\"%0-5.6f\", 7.3);}"},
	{1, 1558, "f_wzpljr_prec0n_ignoreflag", f_wzpljr_prec0n_ignoreflag, f_wzpljr_prec0n_ignoreflag_bench, "{return test(\"%0-5.0f\", -7.3);}"},
	{1, 1559, "f_wzpljr_prec1n_ignoreflag", f_wzpljr_prec1n_ignoreflag, f_wzpljr_prec1n_ignoreflag_bench, "{return test(\"%0-5.1f\", -7.3);}"},
	{1, 1560, "f_wzpljr_prec3n_ignoreflag", f_wzpljr_prec3n_ignoreflag, f_wzpljr_prec3n_ignoreflag_bench, "{return test(\"%0-5.3f\", -7.3);}"},
	{1, 1561, "f_wzpljr_prec6n_ignoreflag", f_wzpljr_prec6n_ignoreflag, f_wzpljr_prec6n_ignoreflag_bench, "{return test(\"%0-5.6f\", -7.3);}"},
	{1, 1562, "f_wzpljaf_prec0p", f_wzpljaf_prec0p, f_wzpljaf_prec0p_bench, "{return test(\"%#-5.0f\", 7.3);}"},
	{1, 1563, "f_wzpljaf_prec1p", f_wzpljaf_prec1p, f_wzpljaf_prec1p_bench, "{return test(\"%#-5.1f\", 7.3);}"},
	{1, 1564, "f_wzpljaf_prec3p", f_wzpljaf_prec3p, f_wzpljaf_prec3p_bench, "{return test(\"%#-5.3f\", 7.3);}"},
	{1, 1565, "f_wzpljaf_prec6p", f_wzpljaf_prec6p, f_wzpljaf_prec6p_bench, "{return test(\"%#-5.6f\", 7.3);}"},
	{1, 1566, "f_wzpljaf_prec0n", f_wzpljaf_prec0n, f_wzpljaf_prec0n_bench, "{return test(\"%#-5.0f\", -7.3);}"},
	{1, 1567, "f_wzpljaf_prec1n", f_wzpljaf_prec1n, f_wzpljaf_prec1n_bench, "{return test(\"%#-5.1f\", -7.3);}"},
	{1, 1568, "f_wzpljaf_prec3n", f_wzpljaf_prec3n, f_wzpljaf_prec3n_bench, "{return test(\"%#-5.3f\", -7.3);}"},
	{1, 1569, "f_wzpljaf_prec6n", f_wzpljaf_prec6n, f_wzpljaf_prec6n_bench, "{return test(\"%#-5.6f\", -7.3);}"},
	{1, 1570, "f_was_prec0p", f_was_prec0p, f_was_prec0p_bench, "{return test(\"%+5.0f\", 7.3);}"},
	{1, 1571, "f_was_prec1p", f_was_prec1p, f_was_prec1p_bench, "{return test(\"%+5.1f\", 7.3);}"},
	{1, 1572, "f_was_prec3p", f_was_prec3p, f_was_prec3p_bench, "{return test(\"%+5.3f\", 7.3);}"},
	{1, 1573, "f_was_prec6p", f_was_prec6p, f_was_prec6p_bench, "{return test(\"%+5.6f\", 7.3);}"},
	{1, 1574, "f_was_prec0n", f_was_prec0n, f_was_prec0n_bench, "{return test(\"%+5.0f\", -7.3);}"},
	{1, 1575, "f_was_prec1n", f_was_prec1n, f_was_prec1n_bench, "{return test(\"%+5.1f\", -7.3);}"},
	{1, 1576, "f_was_prec3n", f_was_prec3n, f_was_prec3n_bench, "{return test(\"%+5.3f\", -7.3);}"},
	{1, 1577, "f_was_prec6n", f_was_prec6n, f_was_prec6n_bench, "{return test(\"%+5.6f\", -7.3);}"},
	{1, 1578, "f_wzpas_prec0p", f_wzpas_prec0p, f_wzpas_prec0p_bench, "{return test(\"%+05.0f\", 7.3);}"},
	{1, 1579, "f_wzpas_prec1p", f_wzpas_prec1p, f_wzpas_prec1p_bench, "{return test(\"%+05.1f\", 7.3);}"},
	{1, 1580, "f_wzpas_prec3p", f_wzpas_prec3p, f_wzpas_prec3p_bench, "{return test(\"%+05.3f\", 7.3);}"},
	{1, 1581, "f_wzpas_prec6p", f_wzpas_prec6p, f_wzpas_prec6p_bench, "{return test(\"%+05.6f\", 7.3);}"},
	{1, 1582, "f_wzpas_prec0n", f_wzpas_prec0n, f_wzpas_prec0n_bench, "{return test(\"%+05.0f\", -7.3);}"},
	{1, 1583, "f_wzpas_prec1n", f_wzpas_prec1n, f_wzpas_prec1n_bench, "{return test(\"%+05.1f\", -7.3);}"},
	{1, 1584, "f_wzpas_prec3n", f_wzpas_prec3n, f_wzpas_prec3n_bench, "{return test(\"%+05.3f\", -7.3);}"},
	{1, 1585, "f_wzpas_prec6n", f_wzpas_prec6n, f_wzpas_prec6n_bench, "{return test(\"%+05.6f\", -7.3);}"},
	{1, 1586, "f_wljas_prec0p", f_wljas_prec0p, f_wljas_prec0p_bench, "{return test(\"%+-5.0f\", 7.3);}"},
	{1, 1587, "f_wljas_prec1p", f_wljas_prec1p, f_wljas_prec1p_bench, "{return test(\"%+-5.1f\", 7.3);}"},
	{1, 1588, "f_wljas_prec3p", f_wljas_prec3p, f_wljas_prec3p_bench, "{return test(\"%+-5.3f\", 7.3);}"},
	{1, 1589, "f_wljas_prec6p", f_wljas_prec6p, f_wljas_prec6p_bench, "{return test(\"%+-5.6f\", 7.3);}"},
	{1, 1590, "f_wljas_prec0n", f_wljas_prec0n, f_wljas_prec0n_bench, "{return test(\"%+-5.0f\", -7.3);}"},
	{1, 1591, "f_wljas_prec1n", f_wljas_prec1n, f_wljas_prec1n_bench, "{return test(\"%+-5.1f\", -7.3);}"},
	{1, 1592, "f_wljas_prec3n", f_wljas_prec3n, f_wljas_prec3n_bench, "{return test(\"%+-5.3f\", -7.3);}"},
	{1, 1593, "f_wljas_prec6n", f_wljas_prec6n, f_wljas_prec6n_bench, "{return test(\"%+-5.6f\", -7.3);}"},
	{1, 1594, "f_wzpljas_prec0p_ignoreflag", f_wzpljas_prec0p_ignoreflag, f_wzpljas_prec0p_ignoreflag_bench, "{return test(\"%+-05.0f\", 7.3);}"},
	{1, 1595, "f_wzpljas_prec1p_ignoreflag", f_wzpljas_prec1p_ignoreflag, f_wzpljas_prec1p_ignoreflag_bench, "{return test(\"%+-05.1f\", 7.3);}"},
	{1, 1596, "f_wzpljas_prec3p_ignoreflag", f_wzpljas_prec3p_ignoreflag, f_wzpljas_prec3p_ignoreflag_bench, "{return test(\"%+-05.3f\", 7.3);}"},
	{1, 1597, "f_wzpljas_prec6p_ignoreflag", f_wzpljas_prec6p_ignoreflag, f_wzpljas_prec6p_ignoreflag_bench, "{return test(\"%+-05.6f\", 7.3);}"},
	{1, 1598, "f_wzpljas_prec0n_ignoreflag", f_wzpljas_prec0n_ignoreflag, f_wzpljas_prec0n_ignoreflag_bench, "{return test(\"%+-05.0f\", -7.3);}"},
	{1, 1599, "f_wzpljas_prec1n_ignoreflag", f_wzpljas_prec1n_ignoreflag, f_wzpljas_prec1n_ignoreflag_bench, "{return test(\"%+-05.1f\", -7.3);}"},
	{1, 1600, "f_wzpljas_prec3n_ignoreflag", f_wzpljas_prec3n_ignoreflag, f_wzpljas_prec3n_ignoreflag_bench, "{return test(\"%+-05.3f\", -7.3);}"},
	{1, 1601, "f_wzpljas_prec6n_ignoreflag", f_wzpljas_prec6n_ignoreflag, f_wzpljas_prec6n_ignoreflag_bench, "{return test(\"%+-05.6f\", -7.3);}"},
	{1, 1602, "f_wzpljras_prec0p", f_wzpljras_prec0p, f_wzpljras_prec0p_bench, "{return test(\"%-+5.0f\", 7.3);}"},
	{1, 1603, "f_wzpljras_prec1p", f_wzpljras_prec1p, f_wzpljras_prec1p_bench, "{return test(\"%-+5.1f\", 7.3);}"},
	{1, 1604, "f_wzpljras_prec3p", f_wzpljras_prec3p, f_wzpljras_prec3p_bench, "{return test(\"%-+5.3f\", 7.3);}"},
	{1, 1605, "f_wzpljras_prec6p", f_wzpljras_prec6p, f_wzpljras_prec6p_bench, "{return test(\"%-+5.6f\", 7.3);}"},
	{1, 1606, "f_wzpljras_prec0n", f_wzpljras_prec0n, f_wzpljras_prec0n_bench, "{return test(\"%-+5.0f\", -7.3);}"},
	{1, 1607, "f_wzpljras_prec1n", f_wzpljras_prec1n, f_wzpljras_prec1n_bench, "{return test(\"%-+5.1f\", -7.3);}"},
	{1, 1608, "f_wzpljras_prec3n", f_wzpljras_prec3n, f_wzpljras_prec3n_bench, "{return test(\"%-+5.3f\", -7.3);}"},
	{1, 1609, "f_wzpljras_prec6n", f_wzpljras_prec6n, f_wzpljras_prec6n_bench, "{return test(\"%-+5.6f\", -7.3);}"},
	{1, 1610, "f_wzpljafas_prec0p", f_wzpljafas_prec0p, f_wzpljafas_prec0p_bench, "{return test(\"%+#-5.0f\", 7.3);}"},
	{1, 1611, "f_wzpljafas_prec1p", f_wzpljafas_prec1p, f_wzpljafas_prec1p_bench, "{return test(\"%+#-5.1f\", 7.3);}"},
	{1, 1612, "f_wzpljafas_prec3p", f_wzpljafas_prec3p, f_wzpljafas_prec3p_bench, "{return test(\"%+#-5.3f\", 7.3);}"},
	{1, 1613, "f_wzpljafas_prec6p", f_wzpljafas_prec6p, f_wzpljafas_prec6p_bench, "{return test(\"%+#-5.6f\", 7.3);}"},
	{1, 1614, "f_wzpljafas_prec0n", f_wzpljafas_prec0n, f_wzpljafas_prec0n_bench, "{return test(\"%+#-5.0f\", -7.3);}"},
	{1, 1615, "f_wzpljafas_prec1n", f_wzpljafas_prec1n, f_wzpljafas_prec1n_bench, "{return test(\"%+#-5.1f\", -7.3);}"},
	{1, 1616, "f_wzpljafas_prec3n", f_wzpljafas_prec3n, f_wzpljafas_prec3n_bench, "{return test(\"%+#-5.3f\", -7.3);}"},
	{1, 1617, "f_wzpljafas_prec6n", f_wzpljafas_prec6n, f_wzpljafas_prec6n_bench, "{return test(\"%+#-5.6f\", -7.3);}"},
	{1, 1618, "f_wsp_prec0p", f_wsp_prec0p, f_wsp_prec0p_bench, "{return test(\"% 5.0f\", 7.3);}"},
	{1, 1619, "f_wsp_prec1p", f_wsp_prec1p, f_wsp_prec1p_bench, "{return test(\"% 5.1f\", 7.3);}"},
	{1, 1620, "f_wsp_prec3p", f_wsp_prec3p, f_wsp_prec3p_bench, "{return test(\"% 5.3f\", 7.3);}"},
	{1, 1621, "f_wsp_prec6p", f_wsp_prec6p, f_wsp_prec6p_bench, "{return test(\"% 5.6f\", 7.3);}"},
	{1, 1622, "f_wsp_prec0n", f_wsp_prec0n, f_wsp_prec0n_bench, "{return test(\"% 5.0f\", -7.3);}"},
	{1, 1623, "f_wsp_prec1n", f_wsp_prec1n, f_wsp_prec1n_bench, "{return test(\"% 5.1f\", -7.3);}"},
	{1, 1624, "f_wsp_prec3n", f_wsp_prec3n, f_wsp_prec3n_bench, "{return test(\"% 5.3f\", -7.3);}"},
	{1, 1625, "f_wsp_prec6n", f_wsp_prec6n, f_wsp_prec6n_bench, "{return test(\"% 5.6f\", -7.3);}"},
	{1, 1626, "f_wzpsp_prec0p", f_wzpsp_prec0p, f_wzpsp_prec0p_bench, "{return test(\"% 05.0f\", 7.3);}"},
	{1, 1627, "f_wzpsp_prec1p", f_wzpsp_prec1p, f_wzpsp_prec1p_bench, "{return test(\"% 05.1f\", 7.3);}"},
	{1, 1628, "f_wzpsp_prec3p", f_wzpsp_prec3p, f_wzpsp_prec3p_bench, "{return test(\"% 05.3f\", 7.3);}"},
	{1, 1629, "f_wzpsp_prec6p", f_wzpsp_prec6p, f_wzpsp_prec6p_bench, "{return test(\"% 05.6f\", 7.3);}"},
	{1, 1630, "f_wzpsp_prec0n", f_wzpsp_prec0n, f_wzpsp_prec0n_bench, "{return test(\"% 05.0f\", -7.3);}"},
	{1, 1631, "f_wzpsp_prec1n", f_wzpsp_prec1n, f_wzpsp_prec1n_bench, "{return test(\"% 05.1f\", -7.3);}"},
	{1, 1632, "f_wzpsp_prec3n", f_wzpsp_prec3n, f_wzpsp_prec3n_bench, "{return test(\"% 05.3f\", -7.3);}"},
	{1, 1633, "f_wzpsp_prec6n", f_wzpsp_prec6n, f_wzpsp_prec6n_bench, "{return test(\"% 05.6f\", -7.3);}"},
	{1, 1634, "f_wljsp_prec0p", f_wljsp_prec0p, f_wljsp_prec0p_bench, "{return test(\"% -5.0f\", 7.3);}"},
	{1, 1635, "f_wljsp_prec1p", f_wljsp_prec1p, f_wljsp_prec1p_bench, "{return test(\"% -5.1f\", 7.3);}"},
	{1, 1636, "f_wljsp_prec3p", f_wljsp_prec3p, f_wljsp_prec3p_bench, "{return test(\"% -5.3f\", 7.3);}"},
	{1, 1637, "f_wljsp_prec6p", f_wljsp_prec6p, f_wljsp_prec6p_bench, "{return test(\"% -5.6f\", 7.3);}"},
	{1, 1638, "f_wljsp_prec0n", f_wljsp_prec0n, f_wljsp_prec0n_bench, "{return test(\"% -5.0f\", -7.3);}"},
	{1, 1639, "f_wljsp_prec1n", f_wljsp_prec1n, f_wljsp_prec1n_bench, "{return test(\"% -5.1f\", -7.3);}"},
	{1, 1640, "f_wljsp_prec3n", f_wljsp_prec3n, f_wljsp_prec3n_bench, "{return test(\"% -5.3f\", -7.3);}"},
	{1, 1641, "f_wljsp_prec6n", f_wljsp_prec6n, f_wljsp_prec6n_bench, "{return test(\"% -5.6f\", -7.3);}"},
	{1, 1642, "f_wzpljsp_prec0p_ignoreflag", f_wzpljsp_prec0p_ignoreflag, f_wzpljsp_prec0p_ignoreflag_bench, "{return test(\"% -05.0f\", 7.3);}"},
	{1, 1643, "f_wzpljsp_prec1p_ignoreflag", f_wzpljsp_prec1p_ignoreflag, f_wzpljsp_prec1p_ignoreflag_bench, "{return test(\"% -05.1f\", 7.3);}"},
	{1, 1644, "f_wzpljsp_prec3p_ignoreflag", f_wzpljsp_prec3p_ignoreflag, f_wzpljsp_prec3p_ignoreflag_bench, "{return test(\"% -05.3f\", 7.3);}"},
	{1, 1645, "f_wzpljsp_prec6p_ignoreflag", f_wzpljsp_prec6p_ignoreflag, f_wzpljsp_prec6p_ignoreflag_bench, "{return test(\"% -05.6f\", 7.3);}"},
	{1, 1646, "f_wzpljsp_prec0n_ignoreflag", f_wzpljsp_prec0n_ignoreflag, f_wzpljsp_prec0n_ignoreflag_bench, "{return test(\"% -05.0f\", -7.3);}"},
	{1, 1647, "f_wzpljsp_prec1n_ignoreflag", f_wzpljsp_prec1n_ignoreflag, f_wzpljsp_prec1n_ignoreflag_bench, "{return test(\"% -05.1f\", -7.3);}"},
	{1, 1648, "f_wzpljsp_prec3n_ignoreflag", f_wzpljsp_prec3n_ignoreflag, f_wzpljsp_prec3n_ignoreflag_bench, "{return test(\"% -05.3f\", -7.3);}"},
	{1, 1649, "f_wzpljsp_prec6n_ignoreflag", f_wzpljsp_prec6n_ignoreflag, f_wzpljsp_prec6n_ignoreflag_bench, "{return test(\"% -05.6f\", -7.3);}"},
	{1, 1650, "f_wzpljrsp_prec0p", f_wzpljrsp_prec0p, f_wzpljrsp_prec0p_bench, "{return test(\"%- 5.0f\", 7.3);}"},
	{1, 1651, "f_wzpljrsp_prec1p", f_wzpljrsp_prec1p, f_wzpljrsp_prec1p_bench, "{return test(\"%- 5.1f\", 7.3);}"},
	{1, 1652, "f_wzpljrsp_prec3p", f_wzpljrsp_prec3p, f_wzpljrsp_prec3p_bench, "{return test(\"%- 5.3f\", 7.3);}"},
	{1, 1653, "f_wzpljrsp_prec6p", f_wzpljrsp_prec6p, f_wzpljrsp_prec6p_bench, "{return test(\"%- 5.6f\", 7.3);}"},
	{1, 1654, "f_wzpljrsp_prec0n", f_wzpljrsp_prec0n, f_wzpljrsp_prec0n_bench, "{return test(\"%- 5.0f\", -7.3);}"},
	{1, 1655, "f_wzpljrsp_prec1n", f_wzpljrsp_prec1n, f_wzpljrsp_prec1n_bench, "{return test(\"%- 5.1f\", -7.3);}"},
	{1, 1656, "f_wzpljrsp_prec3n", f_wzpljrsp_prec3n, f_wzpljrsp_prec3n_bench, "{return test(\"%- 5.3f\", -7.3);}"},
	{1, 1657, "f_wzpljrsp_prec6n", f_wzpljrsp_prec6n, f_wzpljrsp_prec6n_bench, "{return test(\"%- 5.6f\", -7.3);}"},
	{1, 1658, "f_wzpljafsp_prec0p", f_wzpljafsp_prec0p, f_wzpljafsp_prec0p_bench, "{return test(\"% #-5.0f\", 7.3);}"},
	{1, 1659, "f_wzpljafsp_prec1p", f_wzpljafsp_prec1p, f_wzpljafsp_prec1p_bench, "{return test(\"% #-5.1f\", 7.3);}"},
	{1, 1660, "f_wzpljafsp_prec3p", f_wzpljafsp_prec3p, f_wzpljafsp_prec3p_bench, "{return test(\"% #-5.3f\", 7.3);}"},
	{1, 1661, "f_wzpljafsp_prec6p", f_wzpljafsp_prec6p, f_wzpljafsp_prec6p_bench, "{return test(\"% #-5.6f\", 7.3);}"},
	{1, 1662, "f_wzpljafsp_prec0n", f_wzpljafsp_prec0n, f_wzpljafsp_prec0n_bench, "{return test(\"% #-5.0f\", -7.3);}"},
	{1, 1663, "f_wzpljafsp_prec1n", f_wzpljafsp_prec1n, f_wzpljafsp_prec1n_bench, "{return test(\"% #-5.1f\", -7.3);}"},
	{1, 1664, "f_wzpljafsp_prec3n", f_wzpljafsp_prec3n, f_wzpljafsp_prec3n_bench, "{return test(\"% #-5.3f\", -7.3);}"},
	{1, 1665, "f_wzpljafsp_prec6n", f_wzpljafsp_prec6n, f_wzpljafsp_prec6n_bench, "{return test(\"% #-5.6f\", -7.3);}"},
	{1, 1666, "f_assp_prec0p_ignoreflag", f_assp_prec0p_ignoreflag, f_assp_prec0p_ignoreflag_bench, "{return test(\"%+ .0f\", 7.3);}"},
	{1, 1667, "f_assp_prec1p_ignoreflag", f_assp_prec1p_ignoreflag, f_assp_prec1p_ignoreflag_bench, "{return test(\"%+ .1f\", 7.3);}"},
	{1, 1668, "f_assp_prec3p_ignoreflag", f_assp_prec3p_ignoreflag, f_assp_prec3p_ignoreflag_bench, "{return test(\"%+ .3f\", 7.3);}"},
	{1, 1669, "f_assp_prec6p_ignoreflag", f_assp_prec6p_ignoreflag, f_assp_prec6p_ignoreflag_bench, "{return test(\"%+ .6f\", 7.3);}"},
	{1, 1670, "f_assp_prec0n_ignoreflag", f_assp_prec0n_ignoreflag, f_assp_prec0n_ignoreflag_bench, "{return test(\"%+ .0f\", -7.3);}"},
	{1, 1671, "f_assp_prec1n_ignoreflag", f_assp_prec1n_ignoreflag, f_assp_prec1n_ignoreflag_bench, "{return test(\"%+ .1f\", -7.3);}"},
	{1, 1672, "f_assp_prec3n_ignoreflag", f_assp_prec3n_ignoreflag, f_assp_prec3n_ignoreflag_bench, "{return test(\"%+ .3f\", -7.3);}"},
	{1, 1673, "f_assp_prec6n_ignoreflag", f_assp_prec6n_ignoreflag, f_assp_prec6n_ignoreflag_bench, "{return test(\"%+ .6f\", -7.3);}"},
	{1, 1674, "f_asspr_prec0p_ignoreflag", f_asspr_prec0p_ignoreflag, f_asspr_prec0p_ignoreflag_bench, "{return test(\"% +.0f\", 7.3);}"},
	{1, 1675, "f_asspr_prec1p_ignoreflag", f_asspr_prec1p_ignoreflag, f_asspr_prec1p_ignoreflag_bench, "{return test(\"% +.1f\", 7.3);}"},
	{1, 1676, "f_asspr_prec3p_ignoreflag", f_asspr_prec3p_ignoreflag, f_asspr_prec3p_ignoreflag_bench, "{return test(\"% +.3f\", 7.3);}"},
	{1, 1677, "f_asspr_prec6p_ignoreflag", f_asspr_prec6p_ignoreflag, f_asspr_prec6p_ignoreflag_bench, "{return test(\"% +.6f\", 7.3);}"},
	{1, 1678, "f_asspr_prec0n_ignoreflag", f_asspr_prec0n_ignoreflag, f_asspr_prec0n_ignoreflag_bench, "{return test(\"% +.0f\", -7.3);}"},
	{1, 1679, "f_asspr_prec1n_ignoreflag", f_asspr_prec1n_ignoreflag, f_asspr_prec1n_ignoreflag_bench, "{return test(\"% +.1f\", -7.3);}"},
	{1, 1680, "f_asspr_prec3n_ignoreflag", f_asspr_prec3n_ignoreflag, f_asspr_prec3n_ignoreflag_bench, "{return test(\"% +.3f\", -7.3);}"},
	{1, 1681, "f_asspr_prec6n_ignoreflag", f_asspr_prec6n_ignoreflag, f_asspr_prec6n_ignoreflag_bench, "{return test(\"% +.6f\", -7.3);}"},
	{0, 1682, "f_overprec_might_be_undefbehav_100", f_overprec_might_be_undefbehav_100, f_overprec_might_be_undefbehav_100_bench, "{return test(\"%.100f\", 0.237);}"},
	{0, 1683, "f_overprec_might_be_undefbehav_32", f_overprec_might_be_undefbehav_32, f_overprec_might_be_undefbehav_32_bench, "{return test(\"%.32f\", 0.237);}"},
	{0, 1684, "f_overprec_might_be_undefbehav_4", f_overprec_might_be_undefbehav_4, f_overprec_might_be_undefbehav_4_bench, "{return test(\"%.4f\", 0.237);}"},
	{0, 1685, "f_overprec_might_be_undefbehav_1000", f_overprec_might_be_undefbehav_1000, f_overprec_might_be_undefbehav_1000_bench, "{return test(\"%.4f\", -0.106577568068517810765107851705167);}"},
	{0, 1686, "f_overprec_might_be_undefbehav_10_from_0", f_overprec_might_be_undefbehav_10_from_0, f_overprec_might_be_undefbehav_10_from_0_bench, "{return test(\"%.10f\", 0.0);}"},
	{0, 1687, "f_overprec_might_be_undefbehav_2000", f_overprec_might_be_undefbehav_2000, f_overprec_might_be_undefbehav_2000_bench, "{return test(\"%.2000f\", 623.28376510723481);}"},
	{0, 1688, "f_overprec_might_be_undefbehav_dblmin", f_overprec_might_be_undefbehav_dblmin, f_overprec_might_be_undefbehav_dblmin_bench, "{return test(\"%.2000f\", DBL_MIN);}"},
	{0, 1689, "f_overprec_might_be_undefbehav_ndblmin", f_overprec_might_be_undefbehav_ndblmin, f_overprec_might_be_undefbehav_ndblmin_bench, "{return test(\"%.2000f\", -DBL_MIN);}"},
	{0, 1690, "f_limits_dblmax_prec0_notmandatory", f_limits_dblmax_prec0_notmandatory, f_limits_dblmax_prec0_notmandatory_bench, "{return test(\"%.0f\", DBL_MAX);}"},
	{0, 1691, "f_limits_dblmax_prec3_notmandatory", f_limits_dblmax_prec3_notmandatory, f_limits_dblmax_prec3_notmandatory_bench, "{return test(\"%.3f\", DBL_MAX);}"},
	{0, 1692, "f_limits_dblmax_precd_notmandatory", f_limits_dblmax_precd_notmandatory, f_limits_dblmax_precd_notmandatory_bench, "{return test(\"%f\", DBL_MAX);}"},
	{0, 1693, "f_limits_dblmax_prec8_notmandatory", f_limits_dblmax_prec8_notmandatory, f_limits_dblmax_prec8_notmandatory_bench, "{return test(\"%.8f\", DBL_MAX);}"},
	{0, 1694, "f_stress_limits_dblmax_prec12_notmandatory", f_stress_limits_dblmax_prec12_notmandatory, f_stress_limits_dblmax_prec12_notmandatory_bench, "{return test(\"%.12f\", DBL_MAX);}"},
	{0, 1695, "f_stress_limits_dblmax_prec16_notmandatory", f_stress_limits_dblmax_prec16_notmandatory, f_stress_limits_dblmax_prec16_notmandatory_bench, "{return test(\"%.16f\", DBL_MAX);}"},
	{0, 1696, "f_stress_limits_dblmax_prec18_notmandatory", f_stress_limits_dblmax_prec18_notmandatory, f_stress_limits_dblmax_prec18_notmandatory_bench, "{return test(\"%.18f\", DBL_MAX);}"},
	{0, 1697, "f_limits_ndblmax_prec0_notmandatory", f_limits_ndblmax_prec0_notmandatory, f_limits_ndblmax_prec0_notmandatory_bench, "{return test(\"%.0f\", -DBL_MAX);}"},
	{0, 1698, "f_limits_ndblmax_prec3_notmandatory", f_limits_ndblmax_prec3_notmandatory, f_limits_ndblmax_prec3_notmandatory_bench, "{return test(\"%.3f\", -DBL_MAX);}"},
	{0, 1699, "f_limits_ndblmax_precd_notmandatory", f_limits_ndblmax_precd_notmandatory, f_limits_ndblmax_precd_notmandatory_bench, "{return test(\"%f\", -DBL_MAX);}"},
	{0, 1700, "f_limits_ndblmax_prec8_notmandatory", f_limits_ndblmax_prec8_notmandatory, f_limits_ndblmax_prec8_notmandatory_bench, "{return test(\"%.8f\", -DBL_MAX);}"},
	{0, 1701, "f_stress_limits_ndblmax_prec12_notmandatory", f_stress_limits_ndblmax_prec12_notmandatory, f_stress_limits_ndblmax_prec12_notmandatory_bench, "{return test(\"%.12f\", -DBL_MAX);}"},
	{0, 1702, "f_stress_limits_ndblmax_prec16_notmandatory", f_stress_limits_ndblmax_prec16_notmandatory, f_stress_limits_ndblmax_prec16_notmandatory_bench, "{return test(\"%.16f\", -DBL_MAX);}"},
	{0, 1703, "f_stress_limits_ndblmax_prec18_notmandatory", f_stress_limits_ndblmax_prec18_notmandatory, f_stress_limits_ndblmax_prec18_notmandatory_bench, "{return test(\"%.18f\", -DBL_MAX);}"},
	{1, 1704, "f_limits_dblmin_prec0", f_limits_dblmin_prec0, f_limits_dblmin_prec0_bench, "{return test(\"%.0f\", DBL_MIN);}"},
	{1, 1705, "f_limits_dblmin_prec3", f_limits_dblmin_prec3, f_limits_dblmin_prec3_bench, "{return test(\"%.3f\", DBL_MIN);}"},
	{1, 1706, "f_limits_dblmin_precd", f_limits_dblmin_precd, f_limits_dblmin_precd_bench, "{return test(\"%f\", DBL_MIN);}"},
	{1, 1707, "f_limits_dblmin_prec8", f_limits_dblmin_prec8, f_limits_dblmin_prec8_bench, "{return test(\"%.8f\", DBL_MIN);}"},
	{1, 1708, "f_stress_limits_dblmin_prec12", f_stress_limits_dblmin_prec12, f_stress_limits_dblmin_prec12_bench, "{return test(\"%.12f\", DBL_MIN);}"},
	{1, 1709, "f_stress_limits_dblmin_prec16", f_stress_limits_dblmin_prec16, f_stress_limits_dblmin_prec16_bench, "{return test(\"%.16f\", DBL_MIN);}"},
	{1, 1710, "f_stress_limits_dblmin_prec18", f_stress_limits_dblmin_prec18, f_stress_limits_dblmin_prec18_bench, "{return test(\"%.18f\", DBL_MIN);}"},
	{1, 1711, "f_limits_ndblmin_prec0", f_limits_ndblmin_prec0, f_limits_ndblmin_prec0_bench, "{return test(\"%.0f\", -DBL_MIN);}"},
	{1, 1712, "f_limits_ndblmin_prec3", f_limits_ndblmin_prec3, f_limits_ndblmin_prec3_bench, "{return test(\"%.3f\", -DBL_MIN);}"},
	{1, 1713, "f_limits_ndblmin_precd", f_limits_ndblmin_precd, f_limits_ndblmin_precd_bench, "{return test(\"%f\", -DBL_MIN);}"},
	{1, 1714, "f_limits_ndblmin_prec8", f_limits_ndblmin_prec8, f_limits_ndblmin_prec8_bench, "{return test(\"%.8f\", -DBL_MIN);}"},
	{1, 1715, "f_stress_limits_ndblmin_prec12", f_stress_limits_ndblmin_prec12, f_stress_limits_ndblmin_prec12_bench, "{return test(\"%.12f\", -DBL_MIN);}"},
	{1, 1716, "f_stress_limits_ndblmin_prec16", f_stress_limits_ndblmin_prec16, f_stress_limits_ndblmin_prec16_bench, "{return test(\"%.16f\", -DBL_MIN);}"},
	{1, 1717, "f_stress_limits_ndblmin_prec18", f_stress_limits_ndblmin_prec18, f_stress_limits_ndblmin_prec18_bench, "{return test(\"%.18f\", -DBL_MIN);}"},
	{0, 1718, "f_reserved_values_inf", f_reserved_values_inf, f_reserved_values_inf_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1719, "f_reserved_values_ninf", f_reserved_values_ninf, f_reserved_values_ninf_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1720, "f_reserved_values_nan", f_reserved_values_nan, f_reserved_values_nan_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1721, "f_reserved_values_pzero", f_reserved_values_pzero, f_reserved_values_pzero_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1722, "f_reserved_values_nzero", f_reserved_values_nzero, f_reserved_values_nzero_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{0, 1723, "f_reserved_values_inf_6w", f_reserved_values_inf_6w, f_reserved_values_inf_6w_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1724, "f_reserved_values_ninf_6w", f_reserved_values_ninf_6w, f_reserved_values_ninf_6w_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1725, "f_reserved_values_nan_6w", f_reserved_values_nan_6w, f_reserved_values_nan_6w_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1726, "f_reserved_values_pzero_6w", f_reserved_values_pzero_6w, f_reserved_values_pzero_6w_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1727, "f_reserved_values_nzero_6w", f_reserved_values_nzero_6w, f_reserved_values_nzero_6w_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{0, 1728, "f_reserved_values_inf_6wlj", f_reserved_values_inf_6wlj, f_reserved_values_inf_6wlj_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1729, "f_reserved_values_ninf_6wlj", f_reserved_values_ninf_6wlj, f_reserved_values_ninf_6wlj_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1730, "f_reserved_values_nan_6wlj", f_reserved_values_nan_6wlj, f_reserved_values_nan_6wlj_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1731, "f_reserved_values_pzero_6wlj", f_reserved_values_pzero_6wlj, f_reserved_values_pzero_6wlj_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1732, "f_reserved_values_nzero_6wlj", f_reserved_values_nzero_6wlj, f_reserved_values_nzero_6wlj_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{0, 1733, "f_reserved_values_inf_6was", f_reserved_values_inf_6was, f_reserved_values_inf_6was_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1734, "f_reserved_values_ninf_6was", f_reserved_values_ninf_6was, f_reserved_values_ninf_6was_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1735, "f_reserved_values_nan_6was", f_reserved_values_nan_6was, f_reserved_values_nan_6was_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1736, "f_reserved_values_pzero_6was", f_reserved_values_pzero_6was, f_reserved_values_pzero_6was_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1737, "f_reserved_values_nzero_6was", f_reserved_values_nzero_6was, f_reserved_values_nzero_6was_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{0, 1738, "f_reserved_values_inf_10w_prec7", f_reserved_values_inf_10w_prec7, f_reserved_values_inf_10w_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1739, "f_reserved_values_ninf_10w_prec7", f_reserved_values_ninf_10w_prec7, f_reserved_values_ninf_10w_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1740, "f_reserved_values_nan_10w_prec7", f_reserved_values_nan_10w_prec7, f_reserved_values_nan_10w_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1741, "f_reserved_values_pzero_10w_prec7", f_reserved_values_pzero_10w_prec7, f_reserved_values_pzero_10w_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1742, "f_reserved_values_nzero_10w_prec7", f_reserved_values_nzero_10w_prec7, f_reserved_values_nzero_10w_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{0, 1743, "f_reserved_values_inf_sp_prec7", f_reserved_values_inf_sp_prec7, f_reserved_values_inf_sp_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1744, "f_reserved_values_ninf_sp_prec7", f_reserved_values_ninf_sp_prec7, f_reserved_values_ninf_sp_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1745, "f_reserved_values_nan_sp_prec7", f_reserved_values_nan_sp_prec7, f_reserved_values_nan_sp_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1746, "f_reserved_values_pzero_sp_prec7", f_reserved_values_pzero_sp_prec7, f_reserved_values_pzero_sp_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1747, "f_reserved_values_nzero_sp_prec7", f_reserved_values_nzero_sp_prec7, f_reserved_values_nzero_sp_prec7_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{0, 1748, "f_reserved_values_inf_sp", f_reserved_values_inf_sp, f_reserved_values_inf_sp_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1749, "f_reserved_values_ninf_sp", f_reserved_values_ninf_sp, f_reserved_values_ninf_sp_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1750, "f_reserved_values_nan_sp", f_reserved_values_nan_sp, f_reserved_values_nan_sp_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1751, "f_reserved_values_pzero_sp", f_reserved_values_pzero_sp, f_reserved_values_pzero_sp_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1752, "f_reserved_values_nzero_sp", f_reserved_values_nzero_sp, f_reserved_values_nzero_sp_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{0, 1753, "f_reserved_values_inf_6wzp", f_reserved_values_inf_6wzp, f_reserved_values_inf_6wzp_bench, "{double special; *((unsigned long *)(&special)) = DBL_INF;"},
	{0, 1754, "f_reserved_values_ninf_6wzp", f_reserved_values_ninf_6wzp, f_reserved_values_ninf_6wzp_bench, "{double special; *((unsigned long *)(&special)) = DBL_NINF;"},
	{0, 1755, "f_reserved_values_nan_6wzp", f_reserved_values_nan_6wzp, f_reserved_values_nan_6wzp_bench, "{double special; *((unsigned long *)(&special)) = DBL_NAN;"},
	{0, 1756, "f_reserved_values_pzero_6wzp", f_reserved_values_pzero_6wzp, f_reserved_values_pzero_6wzp_bench, "{double special; *((unsigned long *)(&special)) = DBL_PZERO;"},
	{0, 1757, "f_reserved_values_nzero_6wzp", f_reserved_values_nzero_6wzp, f_reserved_values_nzero_6wzp_bench, "{double special; *((unsigned long *)(&special)) = DBL_NZERO;"},
	{1, 1758, "f_L_basic_1", f_L_basic_1, f_L_basic_1_bench, "{return test(\"this %Lf float\", 1.5l);}"},
	{1, 1759, "f_L_basic_fltonly", f_L_basic_fltonly, f_L_basic_fltonly_bench, "{return test(\"%Lf\", 7.5l);}"},
	{1, 1760, "f_L_basic_whole", f_L_basic_whole, f_L_basic_whole_bench, "{return test(\"%Lf\", 1.0l);}"},
	{1, 1761, "f_L_basic_negative", f_L_basic_negative, f_L_basic_negative_bench, "{return test(\"%Lf\", -3.85l);}"},
	{1, 1762, "f_L_basic_positive_3_3", f_L_basic_positive_3_3, f_L_basic_positive_3_3_bench, "{return test(\"%Lf\", 573.924l);}"},
	{1, 1763, "f_L_basic_negative_3_3", f_L_basic_negative_3_3, f_L_basic_negative_3_3_bench, "{return test(\"%Lf\", -958.125l);}"},
	{1, 1764, "f_L_basic_positive_smallfpart", f_L_basic_positive_smallfpart, f_L_basic_positive_smallfpart_bench, "{return test(\"%Lf\", 23.00041l);}"},
	{1, 1765, "f_L_basic_positive_allsmall", f_L_basic_positive_allsmall, f_L_basic_positive_allsmall_bench, "{return test(\"%Lf\", 0.000039l);}"},
	{1, 1766, "f_L_basic_negative_smallfpart", f_L_basic_negative_smallfpart, f_L_basic_negative_smallfpart_bench, "{return test(\"%Lf\", -7.00036l);}"},
	{1, 1767, "f_L_basic_negative_allsmall", f_L_basic_negative_allsmall, f_L_basic_negative_allsmall_bench, "{return test(\"%Lf\", -0.00032l);}"},
	{1, 1768, "f_L_basic_limits_allsmall_pos", f_L_basic_limits_allsmall_pos, f_L_basic_limits_allsmall_pos_bench, "{return test(\"%Lf\", 0.000001l);}"},
	{1, 1769, "f_L_basic_limits_allsmall_neg", f_L_basic_limits_allsmall_neg, f_L_basic_limits_allsmall_neg_bench, "{return test(\"%Lf\", -0.000001l);}"},
	{1, 1770, "f_L_basic_limits_smallfpart_pos", f_L_basic_limits_smallfpart_pos, f_L_basic_limits_smallfpart_pos_bench, "{return test(\"%Lf\", 9873.000001l);}"},
	{1, 1771, "f_L_basic_limits_smallfpart_neg", f_L_basic_limits_smallfpart_neg, f_L_basic_limits_smallfpart_neg_bench, "{return test(\"%Lf\", -875.000001l);}"},
	{1, 1772, "f_L_basic_limits_allbig_pos", f_L_basic_limits_allbig_pos, f_L_basic_limits_allbig_pos_bench, "{return test(\"%Lf\", 999.999999l);}"},
	{1, 1773, "f_L_basic_limits_allbig_neg", f_L_basic_limits_allbig_neg, f_L_basic_limits_allbig_neg_bench, "{return test(\"%Lf\", -99.999999l);}"},
	{1, 1774, "f_L_basic_limits_bigfpart_pos", f_L_basic_limits_bigfpart_pos, f_L_basic_limits_bigfpart_pos_bench, "{return test(\"%Lf\", 0.999999l);}"},
	{1, 1775, "f_L_basic_limits_bigfpart_neg", f_L_basic_limits_bigfpart_neg, f_L_basic_limits_bigfpart_neg_bench, "{return test(\"%Lf\", -0.999999l);}"},
	{1, 1776, "f_L_rndd_pos", f_L_rndd_pos, f_L_rndd_pos_bench, "{return test(\"%Lf\", 23.375094499l);}"},
	{1, 1777, "f_L_rndd_neg", f_L_rndd_neg, f_L_rndd_neg_bench, "{return test(\"%Lf\", -985.765426499l);}"},
	{1, 1778, "f_L_rndu_pos", f_L_rndu_pos, f_L_rndu_pos_bench, "{return test(\"%Lf\", 0.08942555l);}"},
	{1, 1779, "f_L_rndu_neg", f_L_rndu_neg, f_L_rndu_neg_bench, "{return test(\"%Lf\", -56.2012685l);}"},
	{1, 1780, "f_L_rndu_multidigit_pos", f_L_rndu_multidigit_pos, f_L_rndu_multidigit_pos_bench, "{return test(\"%Lf\", 43.4399999l);}"},
	{1, 1781, "f_L_rndu_multidigit_neg", f_L_rndu_multidigit_neg, f_L_rndu_multidigit_neg_bench, "{return test(\"%Lf\", -5.0299999l);}"},
	{1, 1782, "f_L_rndd_multidigit_pos", f_L_rndd_multidigit_pos, f_L_rndd_multidigit_pos_bench, "{return test(\"%Lf\", 43.43999949l);}"},
	{1, 1783, "f_L_rndd_multidigit_neg", f_L_rndd_multidigit_neg, f_L_rndd_multidigit_neg_bench, "{return test(\"%Lf\", -5.02999949l);}"},
	{1, 1784, "f_L_rndd_wholnobump_pos", f_L_rndd_wholnobump_pos, f_L_rndd_wholnobump_pos_bench, "{return test(\"%Lf\", 1.99999949l);}"},
	{1, 1785, "f_L_rndd_wholnobump_neg", f_L_rndd_wholnobump_neg, f_L_rndd_wholnobump_neg_bench, "{return test(\"%Lf\", -0.99999949l);}"},
	{1, 1786, "f_L_rndu_bumpwhole_pos", f_L_rndu_bumpwhole_pos, f_L_rndu_bumpwhole_pos_bench, "{return test(\"%Lf\", 3.9999999l);}"},
	{1, 1787, "f_L_rndu_bumpwhole_neg", f_L_rndu_bumpwhole_neg, f_L_rndu_bumpwhole_neg_bench, "{return test(\"%Lf\", -5.9999999l);}"},
	{1, 1788, "f_L_prec7_1", f_L_prec7_1, f_L_prec7_1_bench, "{return test(\"this %.7Lf float\", 1.5l);}"},
	{1, 1789, "f_L_prec7_fltonly", f_L_prec7_fltonly, f_L_prec7_fltonly_bench, "{return test(\"%.7Lf\", 7.5l);}"},
	{1, 1790, "f_L_prec7_whole", f_L_prec7_whole, f_L_prec7_whole_bench, "{return test(\"%.7Lf\", 1.0l);}"},
	{1, 1791, "f_L_prec7_negative", f_L_prec7_negative, f_L_prec7_negative_bench, "{return test(\"%.7Lf\", -3.85l);}"},
	{1, 1792, "f_L_prec7_positive_3_3", f_L_prec7_positive_3_3, f_L_prec7_positive_3_3_bench, "{return test(\"%.7Lf\", 573.924l);}"},
	{1, 1793, "f_L_prec7_negative_3_3", f_L_prec7_negative_3_3, f_L_prec7_negative_3_3_bench, "{return test(\"%.7Lf\", -958.125l);}"},
	{1, 1794, "f_L_prec7_positive_smallfpart", f_L_prec7_positive_smallfpart, f_L_prec7_positive_smallfpart_bench, "{return test(\"%.7Lf\", 23.00041l);}"},
	{1, 1795, "f_L_prec7_positive_allsmall", f_L_prec7_positive_allsmall, f_L_prec7_positive_allsmall_bench, "{return test(\"%.7Lf\", 0.0000039l);}"},
	{1, 1796, "f_L_prec7_negative_smallfpart", f_L_prec7_negative_smallfpart, f_L_prec7_negative_smallfpart_bench, "{return test(\"%.7Lf\", -7.00036l);}"},
	{1, 1797, "f_L_prec7_negative_allsmall", f_L_prec7_negative_allsmall, f_L_prec7_negative_allsmall_bench, "{return test(\"%.7Lf\", -0.000032l);}"},
	{1, 1798, "f_L_prec7_limits_allsmall_pos", f_L_prec7_limits_allsmall_pos, f_L_prec7_limits_allsmall_pos_bench, "{return test(\"%.7Lf\", 0.0000001l);}"},
	{1, 1799, "f_L_prec7_limits_allsmall_neg", f_L_prec7_limits_allsmall_neg, f_L_prec7_limits_allsmall_neg_bench, "{return test(\"%.7Lf\", -0.0000001l);}"},
	{1, 1800, "f_L_prec7_limits_smallfpart_pos", f_L_prec7_limits_smallfpart_pos, f_L_prec7_limits_smallfpart_pos_bench, "{return test(\"%.7Lf\", 9873.000001l);}"},
	{1, 1801, "f_L_prec7_limits_smallfpart_neg", f_L_prec7_limits_smallfpart_neg, f_L_prec7_limits_smallfpart_neg_bench, "{return test(\"%.7Lf\", -875.000001l);}"},
	{1, 1802, "f_L_prec7_limits_allbig_pos", f_L_prec7_limits_allbig_pos, f_L_prec7_limits_allbig_pos_bench, "{return test(\"%.7Lf\", 999.9999999l);}"},
	{1, 1803, "f_L_prec7_limits_allbig_neg", f_L_prec7_limits_allbig_neg, f_L_prec7_limits_allbig_neg_bench, "{return test(\"%.7Lf\", -99.9999999l);}"},
	{1, 1804, "f_L_prec7_limits_bigfpart_pos", f_L_prec7_limits_bigfpart_pos, f_L_prec7_limits_bigfpart_pos_bench, "{return test(\"%.7Lf\", 0.999999l);}"},
	{1, 1805, "f_L_prec7_limits_bigfpart_neg", f_L_prec7_limits_bigfpart_neg, f_L_prec7_limits_bigfpart_neg_bench, "{return test(\"%.7Lf\", -0.999999l);}"},
	{1, 1806, "f_L_rnd_prec7_rndd_pos", f_L_rnd_prec7_rndd_pos, f_L_rnd_prec7_rndd_pos_bench, "{return test(\"%.7Lf\", 23.375094499l);}"},
	{1, 1807, "f_L_rnd_prec7_rndd_neg", f_L_rnd_prec7_rndd_neg, f_L_rnd_prec7_rndd_neg_bench, "{return test(\"%.7Lf\", -985.765426499l);}"},
	{1, 1808, "f_L_rnd_prec7_rndu_pos", f_L_rnd_prec7_rndu_pos, f_L_rnd_prec7_rndu_pos_bench, "{return test(\"%.7Lf\", 0.0894255l);}"},
	{1, 1809, "f_L_rnd_prec7_rndu_neg", f_L_rnd_prec7_rndu_neg, f_L_rnd_prec7_rndu_neg_bench, "{return test(\"%.7Lf\", -56.2012685l);}"},
	{1, 1810, "f_L_rnd_prec7_rndu_multidigit_pos", f_L_rnd_prec7_rndu_multidigit_pos, f_L_rnd_prec7_rndu_multidigit_pos_bench, "{return test(\"%.7Lf\", 43.4399999l);}"},
	{1, 1811, "f_L_rnd_prec7_rndu_multidigit_neg", f_L_rnd_prec7_rndu_multidigit_neg, f_L_rnd_prec7_rndu_multidigit_neg_bench, "{return test(\"%.7Lf\", -5.0299999l);}"},
	{1, 1812, "f_L_rnd_prec7_rndd_multidigit_pos", f_L_rnd_prec7_rndd_multidigit_pos, f_L_rnd_prec7_rndd_multidigit_pos_bench, "{return test(\"%.7Lf\", 43.43999949l);}"},
	{1, 1813, "f_L_rnd_prec7_rndd_multidigit_neg", f_L_rnd_prec7_rndd_multidigit_neg, f_L_rnd_prec7_rndd_multidigit_neg_bench, "{return test(\"%.7Lf\", -5.02999949l);}"},
	{1, 1814, "f_L_rnd_prec7_rndd_wholnobump_pos", f_L_rnd_prec7_rndd_wholnobump_pos, f_L_rnd_prec7_rndd_wholnobump_pos_bench, "{return test(\"%.7Lf\", 1.99999949l);}"},
	{1, 1815, "f_L_rnd_prec7_rndd_wholnobump_neg", f_L_rnd_prec7_rndd_wholnobump_neg, f_L_rnd_prec7_rndd_wholnobump_neg_bench, "{return test(\"%.7Lf\", -0.99999949l);}"},
	{1, 1816, "f_L_rnd_prec7_rndu_bumpwhole_pos", f_L_rnd_prec7_rndu_bumpwhole_pos, f_L_rnd_prec7_rndu_bumpwhole_pos_bench, "{return test(\"%.7Lf\", 3.9999999l);}"},
	{1, 1817, "f_L_prec8_1", f_L_prec8_1, f_L_prec8_1_bench, "{return test(\"this %.8Lf float\", 1.5l);}"},
	{1, 1818, "f_L_prec8_fltonly", f_L_prec8_fltonly, f_L_prec8_fltonly_bench, "{return test(\"%.8Lf\", 7.5l);}"},
	{1, 1819, "f_L_prec8_whole", f_L_prec8_whole, f_L_prec8_whole_bench, "{return test(\"%.8Lf\", 1.0l);}"},
	{1, 1820, "f_L_prec8_negative", f_L_prec8_negative, f_L_prec8_negative_bench, "{return test(\"%.8Lf\", -3.85l);}"},
	{1, 1821, "f_L_prec8_positive_3_3", f_L_prec8_positive_3_3, f_L_prec8_positive_3_3_bench, "{return test(\"%.8Lf\", 573.924l);}"},
	{1, 1822, "f_L_prec8_negative_3_3", f_L_prec8_negative_3_3, f_L_prec8_negative_3_3_bench, "{return test(\"%.8Lf\", -958.125l);}"},
	{1, 1823, "f_L_prec8_positive_smallfpart", f_L_prec8_positive_smallfpart, f_L_prec8_positive_smallfpart_bench, "{return test(\"%.8Lf\", 23.00041l);}"},
	{1, 1824, "f_L_prec8_positive_allsmall", f_L_prec8_positive_allsmall, f_L_prec8_positive_allsmall_bench, "{return test(\"%.8Lf\", 0.00000039l);}"},
	{1, 1825, "f_L_prec8_negative_smallfpart", f_L_prec8_negative_smallfpart, f_L_prec8_negative_smallfpart_bench, "{return test(\"%.8Lf\", -7.00036l);}"},
	{1, 1826, "f_L_prec8_negative_allsmall", f_L_prec8_negative_allsmall, f_L_prec8_negative_allsmall_bench, "{return test(\"%.8Lf\", -0.0000032l);}"},
	{1, 1827, "f_L_prec8_limits_allsmall_pos", f_L_prec8_limits_allsmall_pos, f_L_prec8_limits_allsmall_pos_bench, "{return test(\"%.8Lf\", 0.00000001l);}"},
	{1, 1828, "f_L_prec8_limits_allsmall_neg", f_L_prec8_limits_allsmall_neg, f_L_prec8_limits_allsmall_neg_bench, "{return test(\"%.8Lf\", -0.00000001l);}"},
	{1, 1829, "f_L_prec8_limits_smallfpart_pos", f_L_prec8_limits_smallfpart_pos, f_L_prec8_limits_smallfpart_pos_bench, "{return test(\"%.8Lf\", 9873.000001l);}"},
	{1, 1830, "f_L_prec8_limits_smallfpart_neg", f_L_prec8_limits_smallfpart_neg, f_L_prec8_limits_smallfpart_neg_bench, "{return test(\"%.8Lf\", -875.000001l);}"},
	{1, 1831, "f_L_prec8_limits_allbig_pos", f_L_prec8_limits_allbig_pos, f_L_prec8_limits_allbig_pos_bench, "{return test(\"%.8Lf\", 999.9999999l);}"},
	{1, 1832, "f_L_prec8_limits_allbig_neg", f_L_prec8_limits_allbig_neg, f_L_prec8_limits_allbig_neg_bench, "{return test(\"%.8Lf\", -99.99999999l);}"},
	{1, 1833, "f_L_prec8_limits_bigfpart_pos", f_L_prec8_limits_bigfpart_pos, f_L_prec8_limits_bigfpart_pos_bench, "{return test(\"%.8Lf\", 0.999999l);}"},
	{1, 1834, "f_L_prec8_limits_bigfpart_neg", f_L_prec8_limits_bigfpart_neg, f_L_prec8_limits_bigfpart_neg_bench, "{return test(\"%.8Lf\", -0.999999l);}"},
	{1, 1835, "f_L_rnd_prec8_rndd_pos", f_L_rnd_prec8_rndd_pos, f_L_rnd_prec8_rndd_pos_bench, "{return test(\"%.8Lf\", 23.375094499l);}"},
	{1, 1836, "f_L_rnd_prec8_rndd_neg", f_L_rnd_prec8_rndd_neg, f_L_rnd_prec8_rndd_neg_bench, "{return test(\"%.8Lf\", -985.765426499l);}"},
	{1, 1837, "f_L_rnd_prec8_rndu_pos", f_L_rnd_prec8_rndu_pos, f_L_rnd_prec8_rndu_pos_bench, "{return test(\"%.8Lf\", 0.0894255l);}"},
	{1, 1838, "f_L_rnd_prec8_rndu_neg", f_L_rnd_prec8_rndu_neg, f_L_rnd_prec8_rndu_neg_bench, "{return test(\"%.8Lf\", -56.2012685l);}"},
	{1, 1839, "f_L_rnd_prec8_rndu_multidigit_pos", f_L_rnd_prec8_rndu_multidigit_pos, f_L_rnd_prec8_rndu_multidigit_pos_bench, "{return test(\"%.8Lf\", 43.4399999l);}"},
	{1, 1840, "f_L_rnd_prec8_rndu_multidigit_neg", f_L_rnd_prec8_rndu_multidigit_neg, f_L_rnd_prec8_rndu_multidigit_neg_bench, "{return test(\"%.8Lf\", -5.0299999l);}"},
	{1, 1841, "f_L_rnd_prec8_rndd_multidigit_pos", f_L_rnd_prec8_rndd_multidigit_pos, f_L_rnd_prec8_rndd_multidigit_pos_bench, "{return test(\"%.8Lf\", 43.43999949l);}"},
	{1, 1842, "f_L_rnd_prec8_rndd_multidigit_neg", f_L_rnd_prec8_rndd_multidigit_neg, f_L_rnd_prec8_rndd_multidigit_neg_bench, "{return test(\"%.8Lf\", -5.02999949l);}"},
	{1, 1843, "f_L_rnd_prec8_rndd_wholnobump_pos", f_L_rnd_prec8_rndd_wholnobump_pos, f_L_rnd_prec8_rndd_wholnobump_pos_bench, "{return test(\"%.8Lf\", 1.99999949l);}"},
	{1, 1844, "f_L_rnd_prec8_rndd_wholnobump_neg", f_L_rnd_prec8_rndd_wholnobump_neg, f_L_rnd_prec8_rndd_wholnobump_neg_bench, "{return test(\"%.8Lf\", -0.99999949l);}"},
	{1, 1845, "f_L_rnd_prec8_rndu_bumpwhole_pos", f_L_rnd_prec8_rndu_bumpwhole_pos, f_L_rnd_prec8_rndu_bumpwhole_pos_bench, "{return test(\"%.8Lf\", 3.9999999l);}"},
	{1, 1846, "f_L_prec9_1", f_L_prec9_1, f_L_prec9_1_bench, "{return test(\"this %.9Lf float\", 1.5l);}"},
	{1, 1847, "f_L_prec9_fltonly", f_L_prec9_fltonly, f_L_prec9_fltonly_bench, "{return test(\"%.9Lf\", 7.5l);}"},
	{1, 1848, "f_L_prec9_whole", f_L_prec9_whole, f_L_prec9_whole_bench, "{return test(\"%.9Lf\", 1.0l);}"},
	{1, 1849, "f_L_prec9_negative", f_L_prec9_negative, f_L_prec9_negative_bench, "{return test(\"%.9Lf\", -3.85l);}"},
	{1, 1850, "f_L_prec9_positive_3_3", f_L_prec9_positive_3_3, f_L_prec9_positive_3_3_bench, "{return test(\"%.9Lf\", 573.924l);}"},
	{1, 1851, "f_L_prec9_negative_3_3", f_L_prec9_negative_3_3, f_L_prec9_negative_3_3_bench, "{return test(\"%.9Lf\", -958.125l);}"},
	{1, 1852, "f_L_prec9_positive_smallfpart", f_L_prec9_positive_smallfpart, f_L_prec9_positive_smallfpart_bench, "{return test(\"%.9Lf\", 23.00041l);}"},
	{1, 1853, "f_L_prec9_positive_allsmall", f_L_prec9_positive_allsmall, f_L_prec9_positive_allsmall_bench, "{return test(\"%.9Lf\", 0.00000039l);}"},
	{1, 1854, "f_L_prec9_negative_smallfpart", f_L_prec9_negative_smallfpart, f_L_prec9_negative_smallfpart_bench, "{return test(\"%.9Lf\", -7.00036l);}"},
	{1, 1855, "f_L_prec9_negative_allsmall", f_L_prec9_negative_allsmall, f_L_prec9_negative_allsmall_bench, "{return test(\"%.9Lf\", -0.0000032l);}"},
	{1, 1856, "f_L_prec9_limits_allsmall_pos", f_L_prec9_limits_allsmall_pos, f_L_prec9_limits_allsmall_pos_bench, "{return test(\"%.9Lf\", 0.00000001l);}"},
	{1, 1857, "f_L_prec9_limits_allsmall_neg", f_L_prec9_limits_allsmall_neg, f_L_prec9_limits_allsmall_neg_bench, "{return test(\"%.9Lf\", -0.00000001l);}"},
	{1, 1858, "f_L_prec9_limits_smallfpart_pos", f_L_prec9_limits_smallfpart_pos, f_L_prec9_limits_smallfpart_pos_bench, "{return test(\"%.9Lf\", 9873.000001l);}"},
	{1, 1859, "f_L_prec9_limits_smallfpart_neg", f_L_prec9_limits_smallfpart_neg, f_L_prec9_limits_smallfpart_neg_bench, "{return test(\"%.9Lf\", -875.000001l);}"},
	{1, 1860, "f_L_prec9_limits_allbig_pos", f_L_prec9_limits_allbig_pos, f_L_prec9_limits_allbig_pos_bench, "{return test(\"%.9Lf\", 999.99999999l);}"},
	{1, 1861, "f_L_prec9_limits_allbig_neg", f_L_prec9_limits_allbig_neg, f_L_prec9_limits_allbig_neg_bench, "{return test(\"%.9Lf\", -99.99999999l);}"},
	{1, 1862, "f_L_prec9_limits_bigfpart_pos", f_L_prec9_limits_bigfpart_pos, f_L_prec9_limits_bigfpart_pos_bench, "{return test(\"%.9Lf\", 0.999999l);}"},
	{1, 1863, "f_L_prec9_limits_bigfpart_neg", f_L_prec9_limits_bigfpart_neg, f_L_prec9_limits_bigfpart_neg_bench, "{return test(\"%.9Lf\", -0.999999l);}"},
	{1, 1864, "f_L_rnd_prec9_rndd_pos", f_L_rnd_prec9_rndd_pos, f_L_rnd_prec9_rndd_pos_bench, "{return test(\"%.9Lf\", 23.375094499l);}"},
	{1, 1865, "f_L_rnd_prec9_rndd_neg", f_L_rnd_prec9_rndd_neg, f_L_rnd_prec9_rndd_neg_bench, "{return test(\"%.9Lf\", -985.765426499l);}"},
	{1, 1866, "f_L_rnd_prec9_rndu_pos", f_L_rnd_prec9_rndu_pos, f_L_rnd_prec9_rndu_pos_bench, "{return test(\"%.9Lf\", 0.0894255l);}"},
	{1, 1867, "f_L_rnd_prec9_rndu_neg", f_L_rnd_prec9_rndu_neg, f_L_rnd_prec9_rndu_neg_bench, "{return test(\"%.9Lf\", -56.2012685l);}"},
	{1, 1868, "f_L_rnd_prec9_rndu_multidigit_pos", f_L_rnd_prec9_rndu_multidigit_pos, f_L_rnd_prec9_rndu_multidigit_pos_bench, "{return test(\"%.9Lf\", 43.4399999l);}"},
	{1, 1869, "f_L_rnd_prec9_rndu_multidigit_neg", f_L_rnd_prec9_rndu_multidigit_neg, f_L_rnd_prec9_rndu_multidigit_neg_bench, "{return test(\"%.9Lf\", -5.0299999l);}"},
	{1, 1870, "f_L_rnd_prec9_rndd_multidigit_pos", f_L_rnd_prec9_rndd_multidigit_pos, f_L_rnd_prec9_rndd_multidigit_pos_bench, "{return test(\"%.9Lf\", 43.43999949l);}"},
	{1, 1871, "f_L_rnd_prec9_rndd_multidigit_neg", f_L_rnd_prec9_rndd_multidigit_neg, f_L_rnd_prec9_rndd_multidigit_neg_bench, "{return test(\"%.9Lf\", -5.02999949l);}"},
	{1, 1872, "f_L_rnd_prec9_rndd_wholnobump_pos", f_L_rnd_prec9_rndd_wholnobump_pos, f_L_rnd_prec9_rndd_wholnobump_pos_bench, "{return test(\"%.9Lf\", 1.99999949l);}"},
	{1, 1873, "f_L_rnd_prec9_rndd_wholnobump_neg", f_L_rnd_prec9_rndd_wholnobump_neg, f_L_rnd_prec9_rndd_wholnobump_neg_bench, "{return test(\"%.9Lf\", -0.99999949l);}"},
	{1, 1874, "f_L_rnd_prec9_rndu_bumpwhole_pos", f_L_rnd_prec9_rndu_bumpwhole_pos, f_L_rnd_prec9_rndu_bumpwhole_pos_bench, "{return test(\"%.9Lf\", 3.9999999l);}"},
	{1, 1875, "f_L_stress_prec10_1", f_L_stress_prec10_1, f_L_stress_prec10_1_bench, "{return test(\"this %.10Lf float\", 1.5l);}"},
	{1, 1876, "f_L_stress_prec10_fltonly", f_L_stress_prec10_fltonly, f_L_stress_prec10_fltonly_bench, "{return test(\"%.10Lf\", 7.5l);}"},
	{1, 1877, "f_L_stress_prec10_whole", f_L_stress_prec10_whole, f_L_stress_prec10_whole_bench, "{return test(\"%.10Lf\", 1.0l);}"},
	{1, 1878, "f_L_stress_prec10_negative", f_L_stress_prec10_negative, f_L_stress_prec10_negative_bench, "{return test(\"%.10Lf\", -3.85l);}"},
	{1, 1879, "f_L_stress_prec10_positive_3_10", f_L_stress_prec10_positive_3_10, f_L_stress_prec10_positive_3_10_bench, "{return test(\"%.10Lf\", 573.924l);}"},
	{1, 1880, "f_L_stress_prec10_negative_3_10", f_L_stress_prec10_negative_3_10, f_L_stress_prec10_negative_3_10_bench, "{return test(\"%.10Lf\", -958.125l);}"},
	{1, 1881, "f_L_stress_prec10_pos", f_L_stress_prec10_pos, f_L_stress_prec10_pos_bench, "{return test(\"%.10Lf\", 23.8341375094l);}"},
	{1, 1882, "f_L_stress_prec10_neg", f_L_stress_prec10_neg, f_L_stress_prec10_neg_bench, "{return test(\"%.10Lf\", -985.2459765426l);}"},
	{1, 1883, "f_L_stress_prec10_rndd_pos", f_L_stress_prec10_rndd_pos, f_L_stress_prec10_rndd_pos_bench, "{return test(\"%.10Lf\", 23.8341375094499l);}"},
	{1, 1884, "f_L_stress_prec10_rndd_neg", f_L_stress_prec10_rndd_neg, f_L_stress_prec10_rndd_neg_bench, "{return test(\"%.10Lf\", -985.2459765426499l);}"},
	{1, 1885, "f_L_stress_prec10_rndu_pos", f_L_stress_prec10_rndu_pos, f_L_stress_prec10_rndu_pos_bench, "{return test(\"%.10Lf\", 0.87650894255l);}"},
	{1, 1886, "f_L_stress_prec10_rndu_neg", f_L_stress_prec10_rndu_neg, f_L_stress_prec10_rndu_neg_bench, "{return test(\"%.10Lf\", -56.47852012685l);}"},
	{1, 1887, "f_L_stress_prec10_positive_smallfpart", f_L_stress_prec10_positive_smallfpart, f_L_stress_prec10_positive_smallfpart_bench, "{return test(\"%.10Lf\", 23.000000041l);}"},
	{1, 1888, "f_L_stress_prec10_positive_allsmall", f_L_stress_prec10_positive_allsmall, f_L_stress_prec10_positive_allsmall_bench, "{return test(\"%.10Lf\", 0.0000000039l);}"},
	{1, 1889, "f_L_stress_prec10_negative_smallfpart", f_L_stress_prec10_negative_smallfpart, f_L_stress_prec10_negative_smallfpart_bench, "{return test(\"%.10Lf\", -7.000000036l);}"},
	{1, 1890, "f_L_stress_prec10_negative_allsmall", f_L_stress_prec10_negative_allsmall, f_L_stress_prec10_negative_allsmall_bench, "{return test(\"%.10Lf\", -0.000000032l);}"},
	{1, 1891, "f_L_stress_prec10_limits_allsmall_pos", f_L_stress_prec10_limits_allsmall_pos, f_L_stress_prec10_limits_allsmall_pos_bench, "{return test(\"%.10Lf\", 0.0000000001l);}"},
	{1, 1892, "f_L_stress_prec10_limits_allsmall_neg", f_L_stress_prec10_limits_allsmall_neg, f_L_stress_prec10_limits_allsmall_neg_bench, "{return test(\"%.10Lf\", -0.0000000001l);}"},
	{1, 1893, "f_L_stress_prec10_limits_smallfpart_pos", f_L_stress_prec10_limits_smallfpart_pos, f_L_stress_prec10_limits_smallfpart_pos_bench, "{return test(\"%.10Lf\", 9873.0000000001l);}"},
	{1, 1894, "f_L_stress_prec10_limits_smallfpart_neg", f_L_stress_prec10_limits_smallfpart_neg, f_L_stress_prec10_limits_smallfpart_neg_bench, "{return test(\"%.10Lf\", -875.0000000001l);}"},
	{1, 1895, "f_L_stress_prec10_limits_allbig_pos", f_L_stress_prec10_limits_allbig_pos, f_L_stress_prec10_limits_allbig_pos_bench, "{return test(\"%.10Lf\", 999.9999999999l);}"},
	{1, 1896, "f_L_stress_prec10_limits_allbig_neg", f_L_stress_prec10_limits_allbig_neg, f_L_stress_prec10_limits_allbig_neg_bench, "{return test(\"%.10Lf\", -99.9999999999l);}"},
	{1, 1897, "f_L_stress_prec10_limits_bigfpart_pos", f_L_stress_prec10_limits_bigfpart_pos, f_L_stress_prec10_limits_bigfpart_pos_bench, "{return test(\"%.10Lf\", 0.9999999999l);}"},
	{1, 1898, "f_L_stress_prec10_limits_bigfpart_neg", f_L_stress_prec10_limits_bigfpart_neg, f_L_stress_prec10_limits_bigfpart_neg_bench, "{return test(\"%.10Lf\", -0.9999999999l);}"},
	{1, 1899, "f_L_stress_prec12_rndu", f_L_stress_prec12_rndu, f_L_stress_prec12_rndu_bench, "{return test(\"%.12f\",        1.025978542436587568678);}"},
	{1, 1900, "f_L_stress_prec12_rndd", f_L_stress_prec12_rndd, f_L_stress_prec12_rndd_bench, "{return test(\"%.12f\",        1.025978548534310421434);}"},
	{1, 1901, "f_L_stress_prec12_limits_tiny", f_L_stress_prec12_limits_tiny, f_L_stress_prec12_limits_tiny_bench, "{return test(\"%.12f\", 0.000000000001000000000);}"},
	{1, 1902, "f_L_stress_prec12_limits_big", f_L_stress_prec12_limits_big, f_L_stress_prec12_limits_big_bench, "{return test(\"%.12f\",  0.999999999999000000000);}"},
	{1, 1903, "f_L_stress_prec14_rndu", f_L_stress_prec14_rndu, f_L_stress_prec14_rndu_bench, "{return test(\"%.14f\",        1.025978542436587568678);}"},
	{1, 1904, "f_L_stress_prec14_rndd", f_L_stress_prec14_rndd, f_L_stress_prec14_rndd_bench, "{return test(\"%.14f\",        1.025978548534310421434);}"},
	{1, 1905, "f_L_stress_prec14_limits_tiny", f_L_stress_prec14_limits_tiny, f_L_stress_prec14_limits_tiny_bench, "{return test(\"%.14f\", 0.000000000000010000000);}"},
	{1, 1906, "f_L_stress_prec14_limits_big", f_L_stress_prec14_limits_big, f_L_stress_prec14_limits_big_bench, "{return test(\"%.14f\",  0.999999999999990000000);}"},
	{1, 1907, "f_L_stress_prec16_rndu", f_L_stress_prec16_rndu, f_L_stress_prec16_rndu_bench, "{return test(\"%.16f\",        1.025978542436587568678);}"},
	{1, 1908, "f_L_stress_prec16_rndd", f_L_stress_prec16_rndd, f_L_stress_prec16_rndd_bench, "{return test(\"%.16f\",        1.025978548534310421634);}"},
	{1, 1909, "f_L_stress_prec16_limits_tiny", f_L_stress_prec16_limits_tiny, f_L_stress_prec16_limits_tiny_bench, "{return test(\"%.16f\", 0.000000000000000100000);}"},
	{1, 1910, "f_L_stress_prec16_limits_big", f_L_stress_prec16_limits_big, f_L_stress_prec16_limits_big_bench, "{return test(\"%.16f\",  0.999999999999999900000);}"},
	{1, 1911, "f_L_stress_prec17_rndu", f_L_stress_prec17_rndu, f_L_stress_prec17_rndu_bench, "{return test(\"%.17f\",        1.025978542436587568678);}"},
	{1, 1912, "f_L_stress_prec17_rndd", f_L_stress_prec17_rndd, f_L_stress_prec17_rndd_bench, "{return test(\"%.17f\",        1.025978548534310421734);}"},
	{1, 1913, "f_L_stress_prec17_limits_tiny", f_L_stress_prec17_limits_tiny, f_L_stress_prec17_limits_tiny_bench, "{return test(\"%.17f\", 0.000000000000000010000);}"},
	{1, 1914, "f_L_stress_prec17_limits_big", f_L_stress_prec17_limits_big, f_L_stress_prec17_limits_big_bench, "{return test(\"%.17f\",  0.999999999999999990000);}"},
	{1, 1915, "f_L_stress_prec18_rndu", f_L_stress_prec18_rndu, f_L_stress_prec18_rndu_bench, "{return test(\"%.18f\",        1.025978542436587568678);}"},
	{1, 1916, "f_L_stress_prec18_rndd", f_L_stress_prec18_rndd, f_L_stress_prec18_rndd_bench, "{return test(\"%.18f\",        1.025978548534310421834);}"},
	{1, 1917, "f_L_stress_prec18_limits_tiny", f_L_stress_prec18_limits_tiny, f_L_stress_prec18_limits_tiny_bench, "{return test(\"%.18f\", 0.000000000000000001000);}"},
	{1, 1918, "f_L_stress_prec18_limits_big", f_L_stress_prec18_limits_big, f_L_stress_prec18_limits_big_bench, "{return test(\"%.18f\",  0.999999999999999999000);}"},
	{1, 1919, "f_L_stress_prec19_rndu", f_L_stress_prec19_rndu, f_L_stress_prec19_rndu_bench, "{return test(\"%.19f\",        1.025978542436587568678);}"},
	{1, 1920, "f_L_stress_prec19_rndd", f_L_stress_prec19_rndd, f_L_stress_prec19_rndd_bench, "{return test(\"%.19f\",        1.025978548534310421934);}"},
	{1, 1921, "f_L_stress_prec19_limits_tiny", f_L_stress_prec19_limits_tiny, f_L_stress_prec19_limits_tiny_bench, "{return test(\"%.19f\", 0.000000000000000000100);}"},
	{1, 1922, "f_L_stress_prec19_limits_big", f_L_stress_prec19_limits_big, f_L_stress_prec19_limits_big_bench, "{return test(\"%.19f\",  0.999999999999999999900);}"},
	{1, 1923, "f_L_stress_prec20_rndu", f_L_stress_prec20_rndu, f_L_stress_prec20_rndu_bench, "{return test(\"%.20f\",        1.025978542436587568678);}"},
	{1, 1924, "f_L_stress_prec20_rndd", f_L_stress_prec20_rndd, f_L_stress_prec20_rndd_bench, "{return test(\"%.20f\",        1.025978548534310422034);}"},
	{1, 1925, "f_L_stress_prec20_limits_tiny", f_L_stress_prec20_limits_tiny, f_L_stress_prec20_limits_tiny_bench, "{return test(\"%.20f\", 0.000000000000000000010);}"},
	{1, 1926, "f_L_stress_prec20_limits_big", f_L_stress_prec20_limits_big, f_L_stress_prec20_limits_big_bench, "{return test(\"%.20f\",  0.999999999999999999990);}"},
	{0, 1927, "f_L_reserved_values_inf", f_L_reserved_values_inf, f_L_reserved_values_inf_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1928, "f_L_reserved_values_ninf", f_L_reserved_values_ninf, f_L_reserved_values_ninf_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1929, "f_L_reserved_values_nan", f_L_reserved_values_nan, f_L_reserved_values_nan_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1930, "f_L_reserved_values_pzero", f_L_reserved_values_pzero, f_L_reserved_values_pzero_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1931, "f_L_reserved_values_nzero", f_L_reserved_values_nzero, f_L_reserved_values_nzero_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1932, "f_L_reserved_values_inf_6w", f_L_reserved_values_inf_6w, f_L_reserved_values_inf_6w_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1933, "f_L_reserved_values_ninf_6w", f_L_reserved_values_ninf_6w, f_L_reserved_values_ninf_6w_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1934, "f_L_reserved_values_nan_6w", f_L_reserved_values_nan_6w, f_L_reserved_values_nan_6w_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1935, "f_L_reserved_values_pzero_6w", f_L_reserved_values_pzero_6w, f_L_reserved_values_pzero_6w_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1936, "f_L_reserved_values_nzero_6w", f_L_reserved_values_nzero_6w, f_L_reserved_values_nzero_6w_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1937, "f_L_reserved_values_inf_6wlj", f_L_reserved_values_inf_6wlj, f_L_reserved_values_inf_6wlj_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1938, "f_L_reserved_values_ninf_6wlj", f_L_reserved_values_ninf_6wlj, f_L_reserved_values_ninf_6wlj_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1939, "f_L_reserved_values_nan_6wlj", f_L_reserved_values_nan_6wlj, f_L_reserved_values_nan_6wlj_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1940, "f_L_reserved_values_pzero_6wlj", f_L_reserved_values_pzero_6wlj, f_L_reserved_values_pzero_6wlj_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1941, "f_L_reserved_values_nzero_6wlj", f_L_reserved_values_nzero_6wlj, f_L_reserved_values_nzero_6wlj_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1942, "f_L_reserved_values_inf_6was", f_L_reserved_values_inf_6was, f_L_reserved_values_inf_6was_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1943, "f_L_reserved_values_ninf_6was", f_L_reserved_values_ninf_6was, f_L_reserved_values_ninf_6was_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1944, "f_L_reserved_values_nan_6was", f_L_reserved_values_nan_6was, f_L_reserved_values_nan_6was_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1945, "f_L_reserved_values_pzero_6was", f_L_reserved_values_pzero_6was, f_L_reserved_values_pzero_6was_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1946, "f_L_reserved_values_nzero_6was", f_L_reserved_values_nzero_6was, f_L_reserved_values_nzero_6was_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1947, "f_L_reserved_values_inf_10w_prec7", f_L_reserved_values_inf_10w_prec7, f_L_reserved_values_inf_10w_prec7_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1948, "f_L_reserved_values_ninf_10w_prec7", f_L_reserved_values_ninf_10w_prec7, f_L_reserved_values_ninf_10w_prec7_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1949, "f_L_reserved_values_nan_10w_prec7", f_L_reserved_values_nan_10w_prec7, f_L_reserved_values_nan_10w_prec7_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1950, "f_L_reserved_values_pzero_10w_prec7", f_L_reserved_values_pzero_10w_prec7, f_L_reserved_values_pzero_10w_prec7_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1951, "f_L_reserved_values_nzero_10w_prec7", f_L_reserved_values_nzero_10w_prec7, f_L_reserved_values_nzero_10w_prec7_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1952, "f_L_reserved_values_inf_sp_prec7", f_L_reserved_values_inf_sp_prec7, f_L_reserved_values_inf_sp_prec7_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1953, "f_L_reserved_values_ninf_sp_prec7", f_L_reserved_values_ninf_sp_prec7, f_L_reserved_values_ninf_sp_prec7_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1954, "f_L_reserved_values_nan_sp_prec7", f_L_reserved_values_nan_sp_prec7, f_L_reserved_values_nan_sp_prec7_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1955, "f_L_reserved_values_pzero_sp_prec7", f_L_reserved_values_pzero_sp_prec7, f_L_reserved_values_pzero_sp_prec7_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1956, "f_L_reserved_values_nzero_sp_prec7", f_L_reserved_values_nzero_sp_prec7, f_L_reserved_values_nzero_sp_prec7_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1957, "f_L_reserved_values_inf_sp", f_L_reserved_values_inf_sp, f_L_reserved_values_inf_sp_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1958, "f_L_reserved_values_ninf_sp", f_L_reserved_values_ninf_sp, f_L_reserved_values_ninf_sp_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1959, "f_L_reserved_values_nan_sp", f_L_reserved_values_nan_sp, f_L_reserved_values_nan_sp_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1960, "f_L_reserved_values_pzero_sp", f_L_reserved_values_pzero_sp, f_L_reserved_values_pzero_sp_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1961, "f_L_reserved_values_nzero_sp", f_L_reserved_values_nzero_sp, f_L_reserved_values_nzero_sp_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1962, "f_L_reserved_values_inf_6wzp", f_L_reserved_values_inf_6wzp, f_L_reserved_values_inf_6wzp_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;"},
	{0, 1963, "f_L_reserved_values_ninf_6wzp", f_L_reserved_values_ninf_6wzp, f_L_reserved_values_ninf_6wzp_bench, "{long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1964, "f_L_reserved_values_nan_6wzp", f_L_reserved_values_nan_6wzp, f_L_reserved_values_nan_6wzp_bench, "{long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;"},
	{0, 1965, "f_L_reserved_values_pzero_6wzp", f_L_reserved_values_pzero_6wzp, f_L_reserved_values_pzero_6wzp_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1966, "f_L_reserved_values_nzero_6wzp", f_L_reserved_values_nzero_6wzp, f_L_reserved_values_nzero_6wzp_bench, "{long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;"},
	{0, 1967, "f_L_overprec_might_be_undefbehav_100", f_L_overprec_might_be_undefbehav_100, f_L_overprec_might_be_undefbehav_100_bench, "{return test(\"%.100Lf\", 0.237l);}"},
	{0, 1968, "f_L_overprec_might_be_undefbehav_32", f_L_overprec_might_be_undefbehav_32, f_L_overprec_might_be_undefbehav_32_bench, "{return test(\"%.32Lf\", 0.237l);}"},
	{0, 1969, "f_L_overprec_might_be_undefbehav_4", f_L_overprec_might_be_undefbehav_4, f_L_overprec_might_be_undefbehav_4_bench, "{return test(\"%.4Lf\", 0.237l);}"},
	{0, 1970, "f_L_overprec_might_be_undefbehav_1000", f_L_overprec_might_be_undefbehav_1000, f_L_overprec_might_be_undefbehav_1000_bench, "{return test(\"%.4Lf\", -0.106577568068517810765107851705167l);}"},
	{0, 1971, "f_L_overprec_might_be_undefbehav_10_from_0", f_L_overprec_might_be_undefbehav_10_from_0, f_L_overprec_might_be_undefbehav_10_from_0_bench, "{return test(\"%.10Lf\", 0.0l);}"},
	{0, 1972, "f_L_overprec_might_be_undefbehav_2000", f_L_overprec_might_be_undefbehav_2000, f_L_overprec_might_be_undefbehav_2000_bench, "{return test(\"%.2000Lf\", 623.28376510723481l);}"},
	{0, 1973, "f_L_overprec_might_be_undefbehav_dblmin", f_L_overprec_might_be_undefbehav_dblmin, f_L_overprec_might_be_undefbehav_dblmin_bench, "{return test(\"%.2000Lf\", LDBL_MIN);}"},
	{0, 1974, "f_L_overprec_might_be_undefbehav_ndblmin", f_L_overprec_might_be_undefbehav_ndblmin, f_L_overprec_might_be_undefbehav_ndblmin_bench, "{return test(\"%.2000Lf\", -LDBL_MIN);}"},
	{0, 1975, "f_L_limits_dblmax_prec0_notmandatory", f_L_limits_dblmax_prec0_notmandatory, f_L_limits_dblmax_prec0_notmandatory_bench, "{return test(\"%.0Lf\", LDBL_MAX);}"},
	{0, 1976, "f_L_limits_dblmax_prec3_notmandatory", f_L_limits_dblmax_prec3_notmandatory, f_L_limits_dblmax_prec3_notmandatory_bench, "{return test(\"%.3Lf\", LDBL_MAX);}"},
	{0, 1977, "f_L_limits_dblmax_precd_notmandatory", f_L_limits_dblmax_precd_notmandatory, f_L_limits_dblmax_precd_notmandatory_bench, "{return test(\"%Lf\", LDBL_MAX);}"},
	{0, 1978, "f_L_limits_dblmax_prec8_notmandatory", f_L_limits_dblmax_prec8_notmandatory, f_L_limits_dblmax_prec8_notmandatory_bench, "{return test(\"%.8Lf\", LDBL_MAX);}"},
	{0, 1979, "f_L_stress_limits_dblmax_prec12_notmandatory", f_L_stress_limits_dblmax_prec12_notmandatory, f_L_stress_limits_dblmax_prec12_notmandatory_bench, "{return test(\"%.12Lf\", LDBL_MAX);}"},
	{0, 1980, "f_L_stress_limits_dblmax_prec16_notmandatory", f_L_stress_limits_dblmax_prec16_notmandatory, f_L_stress_limits_dblmax_prec16_notmandatory_bench, "{return test(\"%.16Lf\", LDBL_MAX);}"},
	{0, 1981, "f_L_stress_limits_dblmax_prec18_notmandatory", f_L_stress_limits_dblmax_prec18_notmandatory, f_L_stress_limits_dblmax_prec18_notmandatory_bench, "{return test(\"%.18Lf\", LDBL_MAX);}"},
	{0, 1982, "f_L_limits_ndblmax_prec0_notmandatory", f_L_limits_ndblmax_prec0_notmandatory, f_L_limits_ndblmax_prec0_notmandatory_bench, "{return test(\"%.0Lf\", -LDBL_MAX);}"},
	{0, 1983, "f_L_limits_ndblmax_prec3_notmandatory", f_L_limits_ndblmax_prec3_notmandatory, f_L_limits_ndblmax_prec3_notmandatory_bench, "{return test(\"%.3Lf\", -LDBL_MAX);}"},
	{0, 1984, "f_L_limits_ndblmax_precd_notmandatory", f_L_limits_ndblmax_precd_notmandatory, f_L_limits_ndblmax_precd_notmandatory_bench, "{return test(\"%Lf\", -LDBL_MAX);}"},
	{0, 1985, "f_L_limits_ndblmax_prec8_notmandatory", f_L_limits_ndblmax_prec8_notmandatory, f_L_limits_ndblmax_prec8_notmandatory_bench, "{return test(\"%.8Lf\", -LDBL_MAX);}"},
	{0, 1986, "f_L_stress_limits_ndblmax_prec12_notmandatory", f_L_stress_limits_ndblmax_prec12_notmandatory, f_L_stress_limits_ndblmax_prec12_notmandatory_bench, "{return test(\"%.12Lf\", -LDBL_MAX);}"},
	{0, 1987, "f_L_stress_limits_ndblmax_prec16_notmandatory", f_L_stress_limits_ndblmax_prec16_notmandatory, f_L_stress_limits_ndblmax_prec16_notmandatory_bench, "{return test(\"%.16Lf\", -LDBL_MAX);}"},
	{0, 1988, "f_L_stress_limits_ndblmax_prec18_notmandatory", f_L_stress_limits_ndblmax_prec18_notmandatory, f_L_stress_limits_ndblmax_prec18_notmandatory_bench, "{return test(\"%.18Lf\", -LDBL_MAX);}"},
	{1, 1989, "f_L_limits_dblmin_prec0", f_L_limits_dblmin_prec0, f_L_limits_dblmin_prec0_bench, "{return test(\"%.0Lf\", LDBL_MIN);}"},
	{1, 1990, "f_L_limits_dblmin_prec3", f_L_limits_dblmin_prec3, f_L_limits_dblmin_prec3_bench, "{return test(\"%.3Lf\", LDBL_MIN);}"},
	{1, 1991, "f_L_limits_dblmin_precd", f_L_limits_dblmin_precd, f_L_limits_dblmin_precd_bench, "{return test(\"%Lf\", LDBL_MIN);}"},
	{1, 1992, "f_L_limits_dblmin_prec8", f_L_limits_dblmin_prec8, f_L_limits_dblmin_prec8_bench, "{return test(\"%.8Lf\", LDBL_MIN);}"},
	{1, 1993, "f_L_stress_limits_dblmin_prec12", f_L_stress_limits_dblmin_prec12, f_L_stress_limits_dblmin_prec12_bench, "{return test(\"%.12Lf\", LDBL_MIN);}"},
	{1, 1994, "f_L_stress_limits_dblmin_prec16", f_L_stress_limits_dblmin_prec16, f_L_stress_limits_dblmin_prec16_bench, "{return test(\"%.16Lf\", LDBL_MIN);}"},
	{1, 1995, "f_L_stress_limits_dblmin_prec18", f_L_stress_limits_dblmin_prec18, f_L_stress_limits_dblmin_prec18_bench, "{return test(\"%.18Lf\", LDBL_MIN);}"},
	{1, 1996, "f_L_limits_ndblmin_prec0", f_L_limits_ndblmin_prec0, f_L_limits_ndblmin_prec0_bench, "{return test(\"%.0Lf\", -LDBL_MIN);}"},
	{1, 1997, "f_L_limits_ndblmin_prec3", f_L_limits_ndblmin_prec3, f_L_limits_ndblmin_prec3_bench, "{return test(\"%.3Lf\", -LDBL_MIN);}"},
	{1, 1998, "f_L_limits_ndblmin_precd", f_L_limits_ndblmin_precd, f_L_limits_ndblmin_precd_bench, "{return test(\"%Lf\", -LDBL_MIN);}"},
	{1, 1999, "f_L_limits_ndblmin_prec8", f_L_limits_ndblmin_prec8, f_L_limits_ndblmin_prec8_bench, "{return test(\"%.8Lf\", -LDBL_MIN);}"},
	{1, 2000, "f_L_stress_limits_ndblmin_prec12", f_L_stress_limits_ndblmin_prec12, f_L_stress_limits_ndblmin_prec12_bench, "{return test(\"%.12Lf\", -LDBL_MIN);}"},
	{1, 2001, "f_L_stress_limits_ndblmin_prec16", f_L_stress_limits_ndblmin_prec16, f_L_stress_limits_ndblmin_prec16_bench, "{return test(\"%.16Lf\", -LDBL_MIN);}"},
	{1, 2002, "f_L_stress_limits_ndblmin_prec18", f_L_stress_limits_ndblmin_prec18, f_L_stress_limits_ndblmin_prec18_bench, "{return test(\"%.18Lf\", -LDBL_MIN);}"},
	{0, 2003, "argnum_simple_swap", argnum_simple_swap, argnum_simple_swap_bench, "{return test(\"%2$s, %1$s!\", \"world\", \"hello\");} //CAN-SEGFAULT"},
	{0, 2004, "argnum_swap_around_pct", argnum_swap_around_pct, argnum_swap_around_pct_bench, "{return test(\"%2$s %% %1$s!\", \"world\", \"hello\");} //CAN-SEGFAULT"},
	{0, 2005, "argnum_swap_strfloat", argnum_swap_strfloat, argnum_swap_strfloat_bench, "{return test(\"%2$f, %1$s!\", \"world\", 5.75);} //CAN-SEGFAULT"},
	{0, 2006, "argnum_swap_floatstr", argnum_swap_floatstr, argnum_swap_floatstr_bench, "{return test(\"%2$s, %1$f!\", 5.75, \"abc\");} //CAN-SEGFAULT"},
	{0, 2007, "argnum_swap_ldblstr", argnum_swap_ldblstr, argnum_swap_ldblstr_bench, "{return test(\"%2$s, %1$Lf!\", 5.75L, \"abc\");} //CAN-SEGFAULT"},
	{0, 2008, "argnum_swap_strldbl", argnum_swap_strldbl, argnum_swap_strldbl_bench, "{return test(\"%2$Lf, %1$s!\", \"world\", 5.75L);} //CAN-SEGFAULT"},
	{0, 2009, "argnum_swap_ldblchar", argnum_swap_ldblchar, argnum_swap_ldblchar_bench, "{return test(\"%2$c, %1$Lf!\", 5.75L, 'c');} //CAN-SEGFAULT"},
	{0, 2010, "argnum_swap_charldbl", argnum_swap_charldbl, argnum_swap_charldbl_bench, "{return test(\"%2$Lf, %1$c!\", 'c', 5.75L);} //CAN-SEGFAULT"},
	{0, 2011, "argnum_swap_floatstr_around_pct", argnum_swap_floatstr_around_pct, argnum_swap_floatstr_around_pct_bench, "{return test(\"%2$s %% %1$f!\", 5.75, \"abc\");} //CAN-SEGFAULT"},
	{0, 2012, "argnum_swap_strfloat_around_pct", argnum_swap_strfloat_around_pct, argnum_swap_strfloat_around_pct_bench, "{return test(\"%2$f %% %1$s!\", \"world\", 5.75);} //CAN-SEGFAULT"},
	{0, 2013, "argnum_loopback_throwswarning", argnum_loopback_throwswarning, argnum_loopback_throwswarning_bench, "{return test(\"%i %i %1$i %i %i\", 1, 2, 3);} //CAN-SEGFAULT"},
	{0, 2014, "argnum_onlyone", argnum_onlyone, argnum_onlyone_bench, "{return test(\"%1$s %1$s %1$s %1$s %1$s %1$s %1$s %1$s.\", \"buffalo\");} //CAN-SEGFAULT"},
	{0, 2015, "argnum_start2thentofloatthen1_throwswarning", argnum_start2thentofloatthen1_throwswarning, argnum_start2thentofloatthen1_throwswarning_bench, "{return test(\"%2$s %f %1$i\", 5, \"abc\", 5.75f);} //CAN-SEGFAULT"},
	{0, 2016, "argnum_ultimate_1_throwswarning", argnum_ultimate_1_throwswarning, argnum_ultimate_1_throwswarning_bench, "{return test(\"%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s\", 5, \"abc\", 5.75);} //CAN-SEGFAULT"},
	{0, 2017, "argnum_ultimate_2_throwswarning", argnum_ultimate_2_throwswarning, argnum_ultimate_2_throwswarning_bench, "{return test(\"%4$.5s %.4i %lli %1$Lf %c %7$20.6s %5$i %2$c %1$.2Lf %c %i\", //CAN-SEGFAULT"},
	{0, 2018, "argnum_ultimate_2_with_pct_throwswarning", argnum_ultimate_2_with_pct_throwswarning, argnum_ultimate_2_with_pct_throwswarning_bench, "{return test(\"%% %4$.5s %.4i %lli %% %1$Lf %c %7$20.6s %5$i %% %2$c %1$.2Lf %c %i\", //CAN-SEGFAULT"},
	{1, 2019, "mix_test_0", mix_test_0, mix_test_0_bench, "{return test("},
	{1, 2020, "mix_test_1", mix_test_1, mix_test_1_bench, "{return test("},
	{1, 2021, "mix_test_2", mix_test_2, mix_test_2_bench, "{return test("},
	{1, 2022, "mix_test_3", mix_test_3, mix_test_3_bench, "{return test("},
	{1, 2023, "mix_test_4", mix_test_4, mix_test_4_bench, "{return test("},
	{1, 2024, "mix_test_5", mix_test_5, mix_test_5_bench, "{return test("},
	{1, 2025, "mix_test_6", mix_test_6, mix_test_6_bench, "{return test("},
	{1, 2026, "mix_test_7", mix_test_7, mix_test_7_bench, "{return test("},
	{1, 2027, "mix_test_8", mix_test_8, mix_test_8_bench, "{return test("},
	{1, 2028, "mix_test_9", mix_test_9, mix_test_9_bench, "{return test("},
	{1, 2029, "mix_test_10", mix_test_10, mix_test_10_bench, "{return test("},
	{1, 2030, "mix_test_11", mix_test_11, mix_test_11_bench, "{return test("},
	{1, 2031, "mix_test_12", mix_test_12, mix_test_12_bench, "{return test("},
	{1, 2032, "mix_test_13", mix_test_13, mix_test_13_bench, "{return test("},
	{1, 2033, "mix_test_14", mix_test_14, mix_test_14_bench, "{return test("},
	{1, 2034, "mix_test_15", mix_test_15, mix_test_15_bench, "{return test("},
	{1, 2035, "mix_test_16", mix_test_16, mix_test_16_bench, "{return test("},
	{1, 2036, "mix_test_17", mix_test_17, mix_test_17_bench, "{return test("},
	{1, 2037, "mix_test_18", mix_test_18, mix_test_18_bench, "{return test("},
	{1, 2038, "mix_test_19", mix_test_19, mix_test_19_bench, "{return test("},
	{1, 2039, "mix_test_20", mix_test_20, mix_test_20_bench, "{return test("},
	{1, 2040, "mix_test_21", mix_test_21, mix_test_21_bench, "{return test("},
	{1, 2041, "mix_test_22", mix_test_22, mix_test_22_bench, "{return test("},
	{1, 2042, "mix_test_23", mix_test_23, mix_test_23_bench, "{return test("},
	{1, 2043, "mix_test_24", mix_test_24, mix_test_24_bench, "{return test("},
	{1, 2044, "mix_test_25", mix_test_25, mix_test_25_bench, "{return test("},
	{1, 2045, "mix_test_26", mix_test_26, mix_test_26_bench, "{return test("},
	{1, 2046, "mix_test_27", mix_test_27, mix_test_27_bench, "{return test("},
	{1, 2047, "mix_test_28", mix_test_28, mix_test_28_bench, "{return test("},
	{1, 2048, "mix_test_29", mix_test_29, mix_test_29_bench, "{return test("},
	{1, 2049, "mix_test_30", mix_test_30, mix_test_30_bench, "{return test("},
	{1, 2050, "mix_test_31", mix_test_31, mix_test_31_bench, "{return test("},
	{1, 2051, "mix_test_32", mix_test_32, mix_test_32_bench, "{return test("},
	{1, 2052, "mix_test_33", mix_test_33, mix_test_33_bench, "{return test("},
	{1, 2053, "mix_test_34", mix_test_34, mix_test_34_bench, "{return test("},
	{1, 2054, "mix_test_35", mix_test_35, mix_test_35_bench, "{return test("},
	{1, 2055, "mix_test_36", mix_test_36, mix_test_36_bench, "{return test("},
	{1, 2056, "mix_test_37", mix_test_37, mix_test_37_bench, "{return test("},
	{1, 2057, "mix_test_38", mix_test_38, mix_test_38_bench, "{return test("},
	{1, 2058, "mix_test_39", mix_test_39, mix_test_39_bench, "{return test("},
	{1, 2059, "mix_test_40", mix_test_40, mix_test_40_bench, "{return test("},
	{1, 2060, "mix_test_41", mix_test_41, mix_test_41_bench, "{return test("},
	{1, 2061, "mix_test_42", mix_test_42, mix_test_42_bench, "{return test("},
	{1, 2062, "mix_test_43", mix_test_43, mix_test_43_bench, "{return test("},
	{1, 2063, "mix_test_44", mix_test_44, mix_test_44_bench, "{return test("},
	{1, 2064, "mix_test_45", mix_test_45, mix_test_45_bench, "{return test("},
	{1, 2065, "mix_test_46", mix_test_46, mix_test_46_bench, "{return test("},
	{1, 2066, "mix_test_47", mix_test_47, mix_test_47_bench, "{return test("},
	{1, 2067, "mix_test_48", mix_test_48, mix_test_48_bench, "{return test("},
	{1, 2068, "mix_test_49", mix_test_49, mix_test_49_bench, "{return test("},
	{1, 2069, "mix_test_50", mix_test_50, mix_test_50_bench, "{return test("},
	{1, 2070, "mix_test_51", mix_test_51, mix_test_51_bench, "{return test("},
	{1, 2071, "mix_test_52", mix_test_52, mix_test_52_bench, "{return test("},
	{1, 2072, "mix_test_53", mix_test_53, mix_test_53_bench, "{return test("},
	{1, 2073, "mix_test_54", mix_test_54, mix_test_54_bench, "{return test("},
	{1, 2074, "mix_test_55", mix_test_55, mix_test_55_bench, "{return test("},
	{1, 2075, "mix_test_56", mix_test_56, mix_test_56_bench, "{return test("},
	{1, 2076, "mix_test_57", mix_test_57, mix_test_57_bench, "{return test("},
	{1, 2077, "mix_test_58", mix_test_58, mix_test_58_bench, "{return test("},
	{1, 2078, "mix_test_59", mix_test_59, mix_test_59_bench, "{return test("},
	{1, 2079, "mix_test_60", mix_test_60, mix_test_60_bench, "{return test("},
	{1, 2080, "mix_test_61", mix_test_61, mix_test_61_bench, "{return test("},
	{1, 2081, "mix_test_62", mix_test_62, mix_test_62_bench, "{return test("},
	{1, 2082, "mix_test_63", mix_test_63, mix_test_63_bench, "{return test("},
	{1, 2083, "mix_test_64", mix_test_64, mix_test_64_bench, "{return test("},
	{1, 2084, "mix_test_65", mix_test_65, mix_test_65_bench, "{return test("},
	{1, 2085, "mix_test_66", mix_test_66, mix_test_66_bench, "{return test("},
	{1, 2086, "mix_test_67", mix_test_67, mix_test_67_bench, "{return test("},
	{1, 2087, "mix_test_68", mix_test_68, mix_test_68_bench, "{return test("},
	{1, 2088, "mix_test_69", mix_test_69, mix_test_69_bench, "{return test("},
	{1, 2089, "mix_test_70", mix_test_70, mix_test_70_bench, "{return test("},
	{1, 2090, "mix_test_71", mix_test_71, mix_test_71_bench, "{return test("},
	{1, 2091, "mix_test_72", mix_test_72, mix_test_72_bench, "{return test("},
	{1, 2092, "mix_test_73", mix_test_73, mix_test_73_bench, "{return test("},
	{1, 2093, "mix_test_74", mix_test_74, mix_test_74_bench, "{return test("},
	{1, 2094, "mix_test_75", mix_test_75, mix_test_75_bench, "{return test("},
	{1, 2095, "mix_test_76", mix_test_76, mix_test_76_bench, "{return test("},
	{1, 2096, "mix_test_77", mix_test_77, mix_test_77_bench, "{return test("},
	{1, 2097, "mix_test_78", mix_test_78, mix_test_78_bench, "{return test("},
	{1, 2098, "mix_test_79", mix_test_79, mix_test_79_bench, "{return test("},
	{1, 2099, "mix_test_80", mix_test_80, mix_test_80_bench, "{return test("},
	{1, 2100, "mix_test_81", mix_test_81, mix_test_81_bench, "{return test("},
	{1, 2101, "mix_test_82", mix_test_82, mix_test_82_bench, "{return test("},
	{1, 2102, "mix_test_83", mix_test_83, mix_test_83_bench, "{return test("},
	{1, 2103, "mix_test_84", mix_test_84, mix_test_84_bench, "{return test("},
	{1, 2104, "mix_test_85", mix_test_85, mix_test_85_bench, "{return test("},
	{1, 2105, "mix_test_86", mix_test_86, mix_test_86_bench, "{return test("},
	{1, 2106, "mix_test_87", mix_test_87, mix_test_87_bench, "{return test("},
	{1, 2107, "mix_test_88", mix_test_88, mix_test_88_bench, "{return test("},
	{1, 2108, "mix_test_89", mix_test_89, mix_test_89_bench, "{return test("},
	{1, 2109, "mix_test_90", mix_test_90, mix_test_90_bench, "{return test("},
	{1, 2110, "mix_test_91", mix_test_91, mix_test_91_bench, "{return test("},
	{1, 2111, "mix_test_92", mix_test_92, mix_test_92_bench, "{return test("},
	{1, 2112, "mix_test_93", mix_test_93, mix_test_93_bench, "{return test("},
	{1, 2113, "mix_test_94", mix_test_94, mix_test_94_bench, "{return test("},
	{1, 2114, "mix_test_95", mix_test_95, mix_test_95_bench, "{return test("},
	{1, 2115, "mix_test_96", mix_test_96, mix_test_96_bench, "{return test("},
	{1, 2116, "mix_test_97", mix_test_97, mix_test_97_bench, "{return test("},
	{1, 2117, "mix_test_98", mix_test_98, mix_test_98_bench, "{return test("},
	{1, 2118, "mix_test_99", mix_test_99, mix_test_99_bench, "{return test("},
	{1, 2119, "mix_test_100", mix_test_100, mix_test_100_bench, "{return test("},
	{1, 2120, "mix_test_101", mix_test_101, mix_test_101_bench, "{return test("},
	{1, 2121, "mix_test_102", mix_test_102, mix_test_102_bench, "{return test("},
	{1, 2122, "mix_test_103", mix_test_103, mix_test_103_bench, "{return test("},
	{1, 2123, "mix_test_104", mix_test_104, mix_test_104_bench, "{return test("},
	{1, 2124, "mix_test_105", mix_test_105, mix_test_105_bench, "{return test("},
	{1, 2125, "mix_test_106", mix_test_106, mix_test_106_bench, "{return test("},
	{1, 2126, "mix_test_107", mix_test_107, mix_test_107_bench, "{return test("},
	{1, 2127, "mix_test_108", mix_test_108, mix_test_108_bench, "{return test("},
	{1, 2128, "mix_test_109", mix_test_109, mix_test_109_bench, "{return test("},
	{1, 2129, "mix_test_110", mix_test_110, mix_test_110_bench, "{return test("},
	{1, 2130, "mix_test_111", mix_test_111, mix_test_111_bench, "{return test("},
	{1, 2131, "mix_test_112", mix_test_112, mix_test_112_bench, "{return test("},
	{1, 2132, "mix_test_113", mix_test_113, mix_test_113_bench, "{return test("},
	{1, 2133, "mix_test_114", mix_test_114, mix_test_114_bench, "{return test("},
	{1, 2134, "mix_test_115", mix_test_115, mix_test_115_bench, "{return test("},
	{1, 2135, "mix_test_116", mix_test_116, mix_test_116_bench, "{return test("},
	{1, 2136, "mix_test_117", mix_test_117, mix_test_117_bench, "{return test("},
	{1, 2137, "mix_test_118", mix_test_118, mix_test_118_bench, "{return test("},
	{1, 2138, "mix_test_119", mix_test_119, mix_test_119_bench, "{return test("},
	{1, 2139, "mix_test_120", mix_test_120, mix_test_120_bench, "{return test("},
	{1, 2140, "mix_test_121", mix_test_121, mix_test_121_bench, "{return test("},
	{1, 2141, "mix_test_122", mix_test_122, mix_test_122_bench, "{return test("},
	{1, 2142, "mix_test_123", mix_test_123, mix_test_123_bench, "{return test("},
	{1, 2143, "mix_test_124", mix_test_124, mix_test_124_bench, "{return test("},
	{1, 2144, "mix_test_125", mix_test_125, mix_test_125_bench, "{return test("},
	{1, 2145, "mix_test_126", mix_test_126, mix_test_126_bench, "{return test("},
	{1, 2146, "mix_test_127", mix_test_127, mix_test_127_bench, "{return test("},
	{1, 2147, "mix_test_128", mix_test_128, mix_test_128_bench, "{return test("},
	{1, 2148, "mix_test_129", mix_test_129, mix_test_129_bench, "{return test("},
	{1, 2149, "mix_test_130", mix_test_130, mix_test_130_bench, "{return test("},
	{1, 2150, "mix_test_131", mix_test_131, mix_test_131_bench, "{return test("},
	{1, 2151, "mix_test_132", mix_test_132, mix_test_132_bench, "{return test("},
	{1, 2152, "mix_test_133", mix_test_133, mix_test_133_bench, "{return test("},
	{1, 2153, "mix_test_134", mix_test_134, mix_test_134_bench, "{return test("},
	{1, 2154, "mix_test_135", mix_test_135, mix_test_135_bench, "{return test("},
	{1, 2155, "mix_test_136", mix_test_136, mix_test_136_bench, "{return test("},
	{1, 2156, "mix_test_137", mix_test_137, mix_test_137_bench, "{return test("},
	{1, 2157, "mix_test_138", mix_test_138, mix_test_138_bench, "{return test("},
	{1, 2158, "mix_test_139", mix_test_139, mix_test_139_bench, "{return test("},
	{1, 2159, "mix_test_140", mix_test_140, mix_test_140_bench, "{return test("},
	{1, 2160, "mix_test_141", mix_test_141, mix_test_141_bench, "{return test("},
	{1, 2161, "mix_test_142", mix_test_142, mix_test_142_bench, "{return test("},
	{1, 2162, "mix_test_143", mix_test_143, mix_test_143_bench, "{return test("},
	{1, 2163, "mix_test_144", mix_test_144, mix_test_144_bench, "{return test("},
	{1, 2164, "mix_test_145", mix_test_145, mix_test_145_bench, "{return test("},
	{1, 2165, "mix_test_146", mix_test_146, mix_test_146_bench, "{return test("},
	{1, 2166, "mix_test_147", mix_test_147, mix_test_147_bench, "{return test("},
	{1, 2167, "mix_test_148", mix_test_148, mix_test_148_bench, "{return test("},
	{1, 2168, "mix_test_149", mix_test_149, mix_test_149_bench, "{return test("},
	{1, 2169, "mix_test_150", mix_test_150, mix_test_150_bench, "{return test("},
	{1, 2170, "mix_test_151", mix_test_151, mix_test_151_bench, "{return test("},
	{1, 2171, "mix_test_152", mix_test_152, mix_test_152_bench, "{return test("},
	{1, 2172, "mix_test_153", mix_test_153, mix_test_153_bench, "{return test("},
	{1, 2173, "mix_test_154", mix_test_154, mix_test_154_bench, "{return test("},
	{1, 2174, "mix_test_155", mix_test_155, mix_test_155_bench, "{return test("},
	{1, 2175, "mix_test_156", mix_test_156, mix_test_156_bench, "{return test("},
	{1, 2176, "mix_test_157", mix_test_157, mix_test_157_bench, "{return test("},
	{1, 2177, "mix_test_158", mix_test_158, mix_test_158_bench, "{return test("},
	{1, 2178, "mix_test_159", mix_test_159, mix_test_159_bench, "{return test("},
	{1, 2179, "mix_test_160", mix_test_160, mix_test_160_bench, "{return test("},
	{1, 2180, "mix_test_161", mix_test_161, mix_test_161_bench, "{return test("},
	{1, 2181, "mix_test_162", mix_test_162, mix_test_162_bench, "{return test("},
	{1, 2182, "mix_test_163", mix_test_163, mix_test_163_bench, "{return test("},
	{1, 2183, "mix_test_164", mix_test_164, mix_test_164_bench, "{return test("},
	{1, 2184, "mix_test_165", mix_test_165, mix_test_165_bench, "{return test("},
	{1, 2185, "mix_test_166", mix_test_166, mix_test_166_bench, "{return test("},
	{1, 2186, "mix_test_167", mix_test_167, mix_test_167_bench, "{return test("},
	{1, 2187, "mix_test_168", mix_test_168, mix_test_168_bench, "{return test("},
	{1, 2188, "mix_test_169", mix_test_169, mix_test_169_bench, "{return test("},
	{1, 2189, "mix_test_170", mix_test_170, mix_test_170_bench, "{return test("},
	{1, 2190, "mix_test_171", mix_test_171, mix_test_171_bench, "{return test("},
	{1, 2191, "mix_test_172", mix_test_172, mix_test_172_bench, "{return test("},
	{1, 2192, "mix_test_173", mix_test_173, mix_test_173_bench, "{return test("},
	{1, 2193, "mix_test_174", mix_test_174, mix_test_174_bench, "{return test("},
	{1, 2194, "mix_test_175", mix_test_175, mix_test_175_bench, "{return test("},
	{1, 2195, "mix_test_176", mix_test_176, mix_test_176_bench, "{return test("},
	{1, 2196, "mix_test_177", mix_test_177, mix_test_177_bench, "{return test("},
	{1, 2197, "mix_test_178", mix_test_178, mix_test_178_bench, "{return test("},
	{1, 2198, "mix_test_179", mix_test_179, mix_test_179_bench, "{return test("},
	{1, 2199, "mix_test_180", mix_test_180, mix_test_180_bench, "{return test("},
	{1, 2200, "mix_test_181", mix_test_181, mix_test_181_bench, "{return test("},
	{1, 2201, "mix_test_182", mix_test_182, mix_test_182_bench, "{return test("},
	{1, 2202, "mix_test_183", mix_test_183, mix_test_183_bench, "{return test("},
	{1, 2203, "mix_test_184", mix_test_184, mix_test_184_bench, "{return test("},
	{1, 2204, "mix_test_185", mix_test_185, mix_test_185_bench, "{return test("},
	{1, 2205, "mix_test_186", mix_test_186, mix_test_186_bench, "{return test("},
	{1, 2206, "mix_test_187", mix_test_187, mix_test_187_bench, "{return test("},
	{1, 2207, "mix_test_188", mix_test_188, mix_test_188_bench, "{return test("},
	{1, 2208, "mix_test_189", mix_test_189, mix_test_189_bench, "{return test("},
	{1, 2209, "mix_test_190", mix_test_190, mix_test_190_bench, "{return test("},
	{1, 2210, "mix_test_191", mix_test_191, mix_test_191_bench, "{return test("},
	{1, 2211, "mix_test_192", mix_test_192, mix_test_192_bench, "{return test("},
	{1, 2212, "mix_test_193", mix_test_193, mix_test_193_bench, "{return test("},
	{1, 2213, "mix_test_194", mix_test_194, mix_test_194_bench, "{return test("},
	{1, 2214, "mix_test_195", mix_test_195, mix_test_195_bench, "{return test("},
	{1, 2215, "mix_test_196", mix_test_196, mix_test_196_bench, "{return test("},
	{1, 2216, "mix_test_197", mix_test_197, mix_test_197_bench, "{return test("},
	{1, 2217, "mix_test_198", mix_test_198, mix_test_198_bench, "{return test("},
	{1, 2218, "mix_test_199", mix_test_199, mix_test_199_bench, "{return test("},
	{1, 2219, "mix_test_extra_1", mix_test_extra_1, mix_test_extra_1_bench, "{return test("},
	{1, 2220, "mix_test_extra_2", mix_test_extra_2, mix_test_extra_2_bench, "{return test("},
	{1, 2221, "mix_test_extra_3", mix_test_extra_3, mix_test_extra_3_bench, "{return test("},
	{1, 2222, "mix_test_extra_4", mix_test_extra_4, mix_test_extra_4_bench, "{return test("},
	{1, 2223, "mix_test_extra_5", mix_test_extra_5, mix_test_extra_5_bench, "{return test("},
	{1, 2224, "mix_test_extra_6", mix_test_extra_6, mix_test_extra_6_bench, "{return test("},
	{1, 2225, "mix_test_extra_7", mix_test_extra_7, mix_test_extra_7_bench, "{return test("},
	{1, 2226, "mix_test_extra_8", mix_test_extra_8, mix_test_extra_8_bench, "{return test("},
	{1, 2227, "mix_test_extra_9", mix_test_extra_9, mix_test_extra_9_bench, "{return test("},
	{1, 2228, "mix_test_extra_10", mix_test_extra_10, mix_test_extra_10_bench, "{return test("},
	{1, 2229, "mix_successive_0", mix_successive_0, mix_successive_0_bench, "{return ( test(\"%c\", mx_c) + test(\"%u\", mx_u));}"},
	{1, 2230, "mix_successive_1", mix_successive_1, mix_successive_1_bench, "{return ( test(\"%o\", mx_u) + test(\"%%\"));}"},
	{1, 2231, "mix_successive_2", mix_successive_2, mix_successive_2_bench, "{return ( test(\"%s\", mx_s) + test(\"%Lf\", mx_Lf));}"},
	{1, 2232, "mix_successive_3", mix_successive_3, mix_successive_3_bench, "{return ( test(\"%Lf\", mx_Lf) + test(\"%hhi\", mx_c));}"},
	{1, 2233, "mix_successive_4", mix_successive_4, mix_successive_4_bench, "{return ( test(\"%x\", mx_u) + test(\"%i\", mx_i));}"},
	{1, 2234, "mix_successive_5", mix_successive_5, mix_successive_5_bench, "{return ( test(\"%x\", mx_u) + test(\"%o\", mx_u));}"},
	{1, 2235, "mix_successive_6", mix_successive_6, mix_successive_6_bench, "{return ( test(\"%s\", mx_s) + test(\"%c\", mx_c));}"},
	{1, 2236, "mix_successive_7", mix_successive_7, mix_successive_7_bench, "{return ( test(\"%p\", &mx_i) + test(\"%hi\", mx_hi));}"},
	{1, 2237, "mix_successive_8", mix_successive_8, mix_successive_8_bench, "{return ( test(\"%f\", mx_f) + test(\"%p\", &mx_i));}"},
	{1, 2238, "mix_successive_9", mix_successive_9, mix_successive_9_bench, "{return ( test(\"%hi\", mx_hi) + test(\"%u\", mx_u));}"},
	{1, 2239, "mix_successive_10", mix_successive_10, mix_successive_10_bench, "{return ( test(\"%u\", mx_u) + test(\"%s\", mx_s));}"},
	{1, 2240, "mix_successive_11", mix_successive_11, mix_successive_11_bench, "{return ( test(\"%Lf\", mx_Lf) + test(\"%p\", &mx_i));}"},
	{1, 2241, "mix_successive_12", mix_successive_12, mix_successive_12_bench, "{return ( test(\"%f\", mx_f) + test(\"%hhi\", mx_c));}"},
	{1, 2242, "mix_successive_13", mix_successive_13, mix_successive_13_bench, "{return ( test(\"%X\", mx_u) + test(\"%hhi\", mx_c));}"},
	{1, 2243, "mix_successive_14", mix_successive_14, mix_successive_14_bench, "{return ( test(\"%X\", mx_u) + test(\"%f\", mx_f));}"},
	{1, 2244, "mix_successive_15", mix_successive_15, mix_successive_15_bench, "{return ( test(\"%hhi\", mx_c) + test(\"%X\", mx_u));}"},
	{1, 2245, "mix_successive_16", mix_successive_16, mix_successive_16_bench, "{return ( test(\"%s\", mx_s) + test(\"%x\", mx_u));}"},
	{1, 2246, "mix_successive_17", mix_successive_17, mix_successive_17_bench, "{return ( test(\"%lli\", mx_lli) + test(\"%i\", mx_i));}"},
	{1, 2247, "mix_successive_18", mix_successive_18, mix_successive_18_bench, "{return ( test(\"%s\", mx_s) + test(\"%o\", mx_u));}"},
	{1, 2248, "mix_successive_19", mix_successive_19, mix_successive_19_bench, "{return ( test(\"%hhi\", mx_c) + test(\"%X\", mx_u));}"},
	{1, 2249, "mix_successive_20", mix_successive_20, mix_successive_20_bench, "{return ( test(\"%p\", &mx_i) + test(\"%s\", mx_s));}"},
	{1, 2250, "mix_successive_21", mix_successive_21, mix_successive_21_bench, "{return ( test(\"%X\", mx_u) + test(\"%x\", mx_u));}"},
	{1, 2251, "mix_successive_22", mix_successive_22, mix_successive_22_bench, "{return ( test(\"%p\", &mx_i) + test(\"%lli\", mx_lli));}"},
	{1, 2252, "mix_successive_23", mix_successive_23, mix_successive_23_bench, "{return ( test(\"%s\", mx_s) + test(\"%f\", mx_f));}"},
	{1, 2253, "mix_successive_24", mix_successive_24, mix_successive_24_bench, "{return ( test(\"%c\", mx_c) + test(\"%hhi\", mx_c));}"},
	{1, 2254, "mix_successive_25", mix_successive_25, mix_successive_25_bench, "{return ( test(\"%x\", mx_u) + test(\"%f\", mx_f));}"},
	{1, 2255, "mix_successive_26", mix_successive_26, mix_successive_26_bench, "{return ( test(\"%s\", mx_s) + test(\"%li\", mx_li));}"},
	{1, 2256, "mix_successive_27", mix_successive_27, mix_successive_27_bench, "{return ( test(\"%f\", mx_f) + test(\"%Lf\", mx_Lf));}"},
	{1, 2257, "mix_successive_28", mix_successive_28, mix_successive_28_bench, "{return ( test(\"%i\", mx_i) + test(\"%u\", mx_u));}"},
	{1, 2258, "mix_successive_29", mix_successive_29, mix_successive_29_bench, "{return ( test(\"%o\", mx_u) + test(\"%li\", mx_li));}"},
	{1, 2259, "mix_successive_30", mix_successive_30, mix_successive_30_bench, "{return ( test(\"%s\", mx_s) + test(\"%u\", mx_u));}"},
	{1, 2260, "mix_successive_31", mix_successive_31, mix_successive_31_bench, "{return ( test(\"%X\", mx_u) + test(\"%c\", mx_c));}"},
	{1, 2261, "mix_successive_32", mix_successive_32, mix_successive_32_bench, "{return ( test(\"%x\", mx_u) + test(\"%u\", mx_u));}"},
	{1, 2262, "mix_successive_33", mix_successive_33, mix_successive_33_bench, "{return ( test(\"%Lf\", mx_Lf) + test(\"%s\", mx_s));}"},
	{1, 2263, "mix_successive_34", mix_successive_34, mix_successive_34_bench, "{return ( test(\"%hhi\", mx_c) + test(\"%u\", mx_u));}"},
	{1, 2264, "mix_successive_35", mix_successive_35, mix_successive_35_bench, "{return ( test(\"%p\", &mx_i) + test(\"%f\", mx_f));}"},
	{1, 2265, "mix_successive_36", mix_successive_36, mix_successive_36_bench, "{return ( test(\"%li\", mx_li) + test(\"%o\", mx_u));}"},
	{1, 2266, "mix_successive_37", mix_successive_37, mix_successive_37_bench, "{return ( test(\"%s\", mx_s) + test(\"%li\", mx_li));}"},
	{1, 2267, "mix_successive_38", mix_successive_38, mix_successive_38_bench, "{return ( test(\"%o\", mx_u) + test(\"%lli\", mx_lli));}"},
	{1, 2268, "mix_successive_39", mix_successive_39, mix_successive_39_bench, "{return ( test(\"%i\", mx_i) + test(\"%c\", mx_c));}"},
	{1, 2269, "mix_successive_40", mix_successive_40, mix_successive_40_bench, "{return ( test(\"%c\", mx_c) + test(\"%x\", mx_u));}"},
	{1, 2270, "mix_successive_41", mix_successive_41, mix_successive_41_bench, "{return ( test(\"%hhi\", mx_c) + test(\"%x\", mx_u));}"},
	{1, 2271, "mix_successive_42", mix_successive_42, mix_successive_42_bench, "{return ( test(\"%x\", mx_u) + test(\"%s\", mx_s));}"},
	{1, 2272, "mix_successive_43", mix_successive_43, mix_successive_43_bench, "{return ( test(\"%u\", mx_u) + test(\"%x\", mx_u));}"},
	{1, 2273, "mix_successive_44", mix_successive_44, mix_successive_44_bench, "{return ( test(\"%i\", mx_i) + test(\"%f\", mx_f));}"},
	{1, 2274, "mix_successive_45", mix_successive_45, mix_successive_45_bench, "{return ( test(\"%s\", mx_s) + test(\"%c\", mx_c));}"},
	{1, 2275, "mix_successive_46", mix_successive_46, mix_successive_46_bench, "{return ( test(\"%i\", mx_i) + test(\"%s\", mx_s));}"},
	{1, 2276, "mix_successive_47", mix_successive_47, mix_successive_47_bench, "{return ( test(\"%u\", mx_u) + test(\"%hhi\", mx_c));}"},
	{1, 2277, "mix_successive_48", mix_successive_48, mix_successive_48_bench, "{return ( test(\"%hi\", mx_hi) + test(\"%o\", mx_u));}"},
	{1, 2278, "mix_successive_49", mix_successive_49, mix_successive_49_bench, "{return ( test(\"%i\", mx_i) + test(\"%hi\", mx_hi));}"},
	{1, 2279, "mix_successive_50", mix_successive_50, mix_successive_50_bench, "{return ( test(\"%o\", mx_u) + test(\"%Lf\", mx_Lf));}"},
	{1, 2280, "mix_successive_51", mix_successive_51, mix_successive_51_bench, "{return ( test(\"%li\", mx_li) + test(\"%hhi\", mx_c));}"},
	{1, 2281, "mix_successive_52", mix_successive_52, mix_successive_52_bench, "{return ( test(\"%hi\", mx_hi) + test(\"%hhi\", mx_c));}"},
	{1, 2282, "mix_successive_53", mix_successive_53, mix_successive_53_bench, "{return ( test(\"%Lf\", mx_Lf) + test(\"%x\", mx_u));}"},
	{1, 2283, "mix_successive_54", mix_successive_54, mix_successive_54_bench, "{return ( test(\"%c\", mx_c) + test(\"%hi\", mx_hi));}"},
	{1, 2284, "mix_successive_55", mix_successive_55, mix_successive_55_bench, "{return ( test(\"%hi\", mx_hi) + test(\"%s\", mx_s));}"},
	{1, 2285, "mix_successive_56", mix_successive_56, mix_successive_56_bench, "{return ( test(\"%i\", mx_i) + test(\"%lli\", mx_lli));}"},
	{1, 2286, "mix_successive_57", mix_successive_57, mix_successive_57_bench, "{return ( test(\"%c\", mx_c) + test(\"%Lf\", mx_Lf));}"},
	{1, 2287, "mix_successive_58", mix_successive_58, mix_successive_58_bench, "{return ( test(\"%f\", mx_f) + test(\"%x\", mx_u));}"},
	{1, 2288, "mix_successive_59", mix_successive_59, mix_successive_59_bench, "{return ( test(\"%s\", mx_s) + test(\"%li\", mx_li));}"},
	{1, 2289, "mix_successive_60", mix_successive_60, mix_successive_60_bench, "{return ( test(\"%hhi\", mx_c) + test(\"%s\", mx_s));}"},
	{1, 2290, "mix_successive_61", mix_successive_61, mix_successive_61_bench, "{return ( test(\"%p\", &mx_i) + test(\"%c\", mx_c));}"},
	{1, 2291, "mix_successive_62", mix_successive_62, mix_successive_62_bench, "{return ( test(\"%lli\", mx_lli) + test(\"%u\", mx_u));}"},
	{1, 2292, "mix_successive_63", mix_successive_63, mix_successive_63_bench, "{return ( test(\"%x\", mx_u) + test(\"%o\", mx_u));}"},
	{1, 2293, "mix_successive_64", mix_successive_64, mix_successive_64_bench, "{return ( test(\"%s\", mx_s) + test(\"%c\", mx_c));}"},
	{1, 2294, "mix_successive_65", mix_successive_65, mix_successive_65_bench, "{return ( test(\"%i\", mx_i) + test(\"%lli\", mx_lli));}"},
	{1, 2295, "mix_successive_66", mix_successive_66, mix_successive_66_bench, "{return ( test(\"%li\", mx_li) + test(\"%Lf\", mx_Lf));}"},
	{1, 2296, "mix_successive_67", mix_successive_67, mix_successive_67_bench, "{return ( test(\"%hi\", mx_hi) + test(\"%x\", mx_u));}"},
	{1, 2297, "mix_successive_68", mix_successive_68, mix_successive_68_bench, "{return ( test(\"%i\", mx_i) + test(\"%hi\", mx_hi));}"},
	{1, 2298, "mix_successive_69", mix_successive_69, mix_successive_69_bench, "{return ( test(\"%Lf\", mx_Lf) + test(\"%li\", mx_li));}"},
	{1, 2299, "mix_successive_70", mix_successive_70, mix_successive_70_bench, "{return ( test(\"%o\", mx_u) + test(\"%li\", mx_li));}"},
	{0, 2300, "nocrash_noarg_1_notmandatory", nocrash_noarg_1_notmandatory, nocrash_noarg_1_notmandatory_bench, "{return test(\"%1$\"); }"},
	{0, 2301, "nocrash_noarg_2_notmandatory", nocrash_noarg_2_notmandatory, nocrash_noarg_2_notmandatory_bench, "{return test(\"%0\"); }"},
	{0, 2302, "nocrash_noarg_3_notmandatory", nocrash_noarg_3_notmandatory, nocrash_noarg_3_notmandatory_bench, "{return test(\"% \"); }"},
	{0, 2303, "nocrash_noarg_4_notmandatory", nocrash_noarg_4_notmandatory, nocrash_noarg_4_notmandatory_bench, "{return test(\"%#\"); }"},
	{0, 2304, "nocrash_noarg_5_notmandatory", nocrash_noarg_5_notmandatory, nocrash_noarg_5_notmandatory_bench, "{return test(\"%-\"); }"},
	{0, 2305, "nocrash_noarg_6_notmandatory", nocrash_noarg_6_notmandatory, nocrash_noarg_6_notmandatory_bench, "{return test(\"%+\"); }"},
	{0, 2306, "nocrash_noarg_9_notmandatory", nocrash_noarg_9_notmandatory, nocrash_noarg_9_notmandatory_bench, "{return test(\"%23\"); }"},
	{0, 2307, "nocrash_noarg_10_notmandatory", nocrash_noarg_10_notmandatory, nocrash_noarg_10_notmandatory_bench, "{return test(\"%.\"); }"},
	{0, 2308, "nocrash_noarg_11_notmandatory", nocrash_noarg_11_notmandatory, nocrash_noarg_11_notmandatory_bench, "{return test(\"%hh\"); }"},
	{0, 2309, "nocrash_noarg_12_notmandatory", nocrash_noarg_12_notmandatory, nocrash_noarg_12_notmandatory_bench, "{return test(\"%h\"); }"},
	{0, 2310, "nocrash_noarg_13_notmandatory", nocrash_noarg_13_notmandatory, nocrash_noarg_13_notmandatory_bench, "{return test(\"%ll\"); }"},
	{0, 2311, "nocrash_noarg_14_notmandatory", nocrash_noarg_14_notmandatory, nocrash_noarg_14_notmandatory_bench, "{return test(\"%l\"); }"},
	{0, 2312, "nocrash_noarg_15_notmandatory", nocrash_noarg_15_notmandatory, nocrash_noarg_15_notmandatory_bench, "{return test(\"%L\"); }"},
	{0, 2313, "nocrash_noarg_16_notmandatory", nocrash_noarg_16_notmandatory, nocrash_noarg_16_notmandatory_bench, "{return test(\"%p\"); }"},
	{0, 2314, "nocrash_noarg_17_notmandatory", nocrash_noarg_17_notmandatory, nocrash_noarg_17_notmandatory_bench, "{return test(\"%d\"); }"},
	{0, 2315, "nocrash_noarg_19_notmandatory", nocrash_noarg_19_notmandatory, nocrash_noarg_19_notmandatory_bench, "{return test(\"%u\"); }"},
	{0, 2316, "nocrash_noarg_20_notmandatory", nocrash_noarg_20_notmandatory, nocrash_noarg_20_notmandatory_bench, "{return test(\"%x\"); }"},
	{0, 2317, "nocrash_noarg_21_notmandatory", nocrash_noarg_21_notmandatory, nocrash_noarg_21_notmandatory_bench, "{return test(\"%X\"); }"},
	{0, 2318, "nocrash_noarg_22_notmandatory", nocrash_noarg_22_notmandatory, nocrash_noarg_22_notmandatory_bench, "{return test(\"%f\"); }"},
	{0, 2319, "nocrash_noarg_24_notmandatory", nocrash_noarg_24_notmandatory, nocrash_noarg_24_notmandatory_bench, "{return test(\"%c\"); }"},
	{0, 2320, "nocrash_noarg_25_notmandatory", nocrash_noarg_25_notmandatory, nocrash_noarg_25_notmandatory_bench, "{return test(\"%o\"); }"},
	{1, 2321, "nocrash_nullarg_1", nocrash_nullarg_1, nocrash_nullarg_1_bench, "{return test(\"%1$s\", NULL); }"},
	{1, 2322, "nocrash_nullarg_2", nocrash_nullarg_2, nocrash_nullarg_2_bench, "{return test(\"%0s\", NULL); }"},
	{1, 2323, "nocrash_nullarg_3", nocrash_nullarg_3, nocrash_nullarg_3_bench, "{return test(\"% s\", NULL); }"},
	{1, 2324, "nocrash_nullarg_4", nocrash_nullarg_4, nocrash_nullarg_4_bench, "{return test(\"%#s\", NULL); }"},
	{1, 2325, "nocrash_nullarg_5", nocrash_nullarg_5, nocrash_nullarg_5_bench, "{return test(\"%-s\", NULL); }"},
	{1, 2326, "nocrash_nullarg_6", nocrash_nullarg_6, nocrash_nullarg_6_bench, "{return test(\"%+s\", NULL); }"},
	{1, 2327, "nocrash_nullarg_9", nocrash_nullarg_9, nocrash_nullarg_9_bench, "{return test(\"%23s\", NULL); }"},
	{1, 2328, "nocrash_nullarg_10", nocrash_nullarg_10, nocrash_nullarg_10_bench, "{return test(\"%.s\", NULL); }"},
	{1, 2329, "nocrash_nullarg_11", nocrash_nullarg_11, nocrash_nullarg_11_bench, "{return test(\"%hhs\", NULL); }"},
	{1, 2330, "nocrash_nullarg_12", nocrash_nullarg_12, nocrash_nullarg_12_bench, "{return test(\"%hs\", NULL); }"},
	{1, 2331, "nocrash_nullarg_13", nocrash_nullarg_13, nocrash_nullarg_13_bench, "{return test(\"%lls\", NULL); }"},
	{1, 2332, "nocrash_nullarg_14", nocrash_nullarg_14, nocrash_nullarg_14_bench, "{return test(\"%ls\", NULL); }"},
	{1, 2333, "nocrash_nullarg_15", nocrash_nullarg_15, nocrash_nullarg_15_bench, "{return test(\"%Ls\", NULL); }"},
	{1, 2334, "nocrash_nullarg_16", nocrash_nullarg_16, nocrash_nullarg_16_bench, "{return test(\"%p\", NULL); }"},
	{1, 2335, "nocrash_nullarg_17", nocrash_nullarg_17, nocrash_nullarg_17_bench, "{return test(\"%d\", NULL); }"},
	{1, 2336, "nocrash_nullarg_18", nocrash_nullarg_18, nocrash_nullarg_18_bench, "{return test(\"%b\", NULL); }"},
	{1, 2337, "nocrash_nullarg_19", nocrash_nullarg_19, nocrash_nullarg_19_bench, "{return test(\"%u\", NULL); }"},
	{1, 2338, "nocrash_nullarg_20", nocrash_nullarg_20, nocrash_nullarg_20_bench, "{return test(\"%x\", NULL); }"},
	{1, 2339, "nocrash_nullarg_21", nocrash_nullarg_21, nocrash_nullarg_21_bench, "{return test(\"%X\", NULL); }"},
	{1, 2340, "nocrash_nullarg_22", nocrash_nullarg_22, nocrash_nullarg_22_bench, "{return test(\"%f\", NULL); }"},
	{1, 2341, "nocrash_nullarg_23", nocrash_nullarg_23, nocrash_nullarg_23_bench, "{return test(\"%s\", NULL); }"},
	{1, 2342, "nocrash_nullarg_24", nocrash_nullarg_24, nocrash_nullarg_24_bench, "{return test(\"%c\", NULL); }"},
	{1, 2343, "nocrash_nullarg_25", nocrash_nullarg_25, nocrash_nullarg_25_bench, "{return test(\"%o\", NULL); }"},
	{1, 2344, "nocrash_mandatory_wformat_undefbehav_01", nocrash_mandatory_wformat_undefbehav_01, nocrash_mandatory_wformat_undefbehav_01_bench, "{return test(\"%-021s\", \"abc\");}"},
	{1, 2345, "nocrash_mandatory_wformat_undefbehav_02", nocrash_mandatory_wformat_undefbehav_02, nocrash_mandatory_wformat_undefbehav_02_bench, "{return test(\"%-05s\", \"goes over\");}"},
	{1, 2346, "nocrash_mandatory_wformat_undefbehav_03", nocrash_mandatory_wformat_undefbehav_03, nocrash_mandatory_wformat_undefbehav_03_bench, "{return test(\"%04.3s%-7.4s\", \"hello\", \"world\");}"},
	{1, 2347, "nocrash_mandatory_wformat_undefbehav_04", nocrash_mandatory_wformat_undefbehav_04, nocrash_mandatory_wformat_undefbehav_04_bench, "{return test(\"%021s\", NULL);}"},
	{1, 2348, "nocrash_mandatory_wformat_undefbehav_05", nocrash_mandatory_wformat_undefbehav_05, nocrash_mandatory_wformat_undefbehav_05_bench, "{return test(\"%02s\", NULL);}"},
	{1, 2349, "nocrash_mandatory_wformat_undefbehav_06", nocrash_mandatory_wformat_undefbehav_06, nocrash_mandatory_wformat_undefbehav_06_bench, "{return test(\"%-021s\", NULL);}"},
	{1, 2350, "nocrash_mandatory_wformat_undefbehav_07", nocrash_mandatory_wformat_undefbehav_07, nocrash_mandatory_wformat_undefbehav_07_bench, "{return test(\"%-03s\", NULL);}"},
	{1, 2351, "nocrash_mandatory_wformat_undefbehav_08", nocrash_mandatory_wformat_undefbehav_08, nocrash_mandatory_wformat_undefbehav_08_bench, "{return test(\"%+u\", 5);}"},
	{1, 2352, "nocrash_mandatory_wformat_undefbehav_09", nocrash_mandatory_wformat_undefbehav_09, nocrash_mandatory_wformat_undefbehav_09_bench, "{return test(\"%+u\", 5);}"},
	{1, 2353, "nocrash_mandatory_wformat_undefbehav_10", nocrash_mandatory_wformat_undefbehav_10, nocrash_mandatory_wformat_undefbehav_10_bench, "{return test(\"%+u\", 4294967295);}"},
	{1, 2354, "nocrash_mandatory_wformat_undefbehav_11", nocrash_mandatory_wformat_undefbehav_11, nocrash_mandatory_wformat_undefbehav_11_bench, "{return test(\"%+5u\", 35);}"},
	{1, 2355, "nocrash_mandatory_wformat_undefbehav_12", nocrash_mandatory_wformat_undefbehav_12, nocrash_mandatory_wformat_undefbehav_12_bench, "{return test(\"%+7u\", 0);}"},
	{1, 2356, "nocrash_mandatory_wformat_undefbehav_13", nocrash_mandatory_wformat_undefbehav_13, nocrash_mandatory_wformat_undefbehav_13_bench, "{return test(\"%+24u\", 4294967295);}"},
	{1, 2357, "nocrash_mandatory_wformat_undefbehav_14", nocrash_mandatory_wformat_undefbehav_14, nocrash_mandatory_wformat_undefbehav_14_bench, "{return test(\"%+.7u\", 234);}"},
	{1, 2358, "nocrash_mandatory_wformat_undefbehav_15", nocrash_mandatory_wformat_undefbehav_15, nocrash_mandatory_wformat_undefbehav_15_bench, "{return test(\"%+.3u\", 3723);}"},
	{1, 2359, "nocrash_mandatory_wformat_undefbehav_16", nocrash_mandatory_wformat_undefbehav_16, nocrash_mandatory_wformat_undefbehav_16_bench, "{return test(\"%+05u\", 432);}"},
	{1, 2360, "nocrash_mandatory_wformat_undefbehav_17", nocrash_mandatory_wformat_undefbehav_17, nocrash_mandatory_wformat_undefbehav_17_bench, "{return test(\"%+04u\", 0);}"},
	{1, 2361, "nocrash_mandatory_wformat_undefbehav_18", nocrash_mandatory_wformat_undefbehav_18, nocrash_mandatory_wformat_undefbehav_18_bench, "{return test(\"%+8.5u\", 34);}"},
	{1, 2362, "nocrash_mandatory_wformat_undefbehav_19", nocrash_mandatory_wformat_undefbehav_19, nocrash_mandatory_wformat_undefbehav_19_bench, "{return test(\"%+8.5u\", 0);}"},
	{1, 2363, "nocrash_mandatory_wformat_undefbehav_20", nocrash_mandatory_wformat_undefbehav_20, nocrash_mandatory_wformat_undefbehav_20_bench, "{return test(\"%+8.3u\", 8375);}"},
	{1, 2364, "nocrash_mandatory_wformat_undefbehav_21", nocrash_mandatory_wformat_undefbehav_21, nocrash_mandatory_wformat_undefbehav_21_bench, "{return test(\"%+3.7u\", 3267);}"},
	{1, 2365, "nocrash_mandatory_wformat_undefbehav_22", nocrash_mandatory_wformat_undefbehav_22, nocrash_mandatory_wformat_undefbehav_22_bench, "{return test(\"%+3.3u\", 6983);}"},
	{1, 2366, "nocrash_mandatory_wformat_undefbehav_23", nocrash_mandatory_wformat_undefbehav_23, nocrash_mandatory_wformat_undefbehav_23_bench, "{return test(\"%+-8.5u\", 34);}"},
	{1, 2367, "nocrash_mandatory_wformat_undefbehav_24", nocrash_mandatory_wformat_undefbehav_24, nocrash_mandatory_wformat_undefbehav_24_bench, "{return test(\"%+-8.5u\", 0);}"},
	{1, 2368, "nocrash_mandatory_wformat_undefbehav_25", nocrash_mandatory_wformat_undefbehav_25, nocrash_mandatory_wformat_undefbehav_25_bench, "{return test(\"%+-8.3u\", 8375);}"},
	{1, 2369, "nocrash_mandatory_wformat_undefbehav_26", nocrash_mandatory_wformat_undefbehav_26, nocrash_mandatory_wformat_undefbehav_26_bench, "{return test(\"%+-3.7u\", 3267);}"},
	{1, 2370, "nocrash_mandatory_wformat_undefbehav_27", nocrash_mandatory_wformat_undefbehav_27, nocrash_mandatory_wformat_undefbehav_27_bench, "{return test(\"%+-3.3u\", 6983);}"},
	{1, 2371, "nocrash_mandatory_wformat_undefbehav_28", nocrash_mandatory_wformat_undefbehav_28, nocrash_mandatory_wformat_undefbehav_28_bench, "{return test(\"%0+8.5u\", 34);}"},
	{1, 2372, "nocrash_mandatory_wformat_undefbehav_29", nocrash_mandatory_wformat_undefbehav_29, nocrash_mandatory_wformat_undefbehav_29_bench, "{return test(\"%0+8.5u\", 0);}"},
	{1, 2373, "nocrash_mandatory_wformat_undefbehav_30", nocrash_mandatory_wformat_undefbehav_30, nocrash_mandatory_wformat_undefbehav_30_bench, "{return test(\"%0+8.3u\", 8375);}"},
	{1, 2374, "nocrash_mandatory_wformat_undefbehav_31", nocrash_mandatory_wformat_undefbehav_31, nocrash_mandatory_wformat_undefbehav_31_bench, "{return test(\"%0+3.7u\", 3267);}"},
	{1, 2375, "nocrash_mandatory_wformat_undefbehav_32", nocrash_mandatory_wformat_undefbehav_32, nocrash_mandatory_wformat_undefbehav_32_bench, "{return test(\"%0+3.3u\", 6983);}"},
	{1, 2376, "nocrash_mandatory_wformat_undefbehav_33", nocrash_mandatory_wformat_undefbehav_33, nocrash_mandatory_wformat_undefbehav_33_bench, "{return test(\"%0+-8.5u\", 34);}"},
	{1, 2377, "nocrash_mandatory_wformat_undefbehav_34", nocrash_mandatory_wformat_undefbehav_34, nocrash_mandatory_wformat_undefbehav_34_bench, "{return test(\"%0+-8.5u\", 0);}"},
	{1, 2378, "nocrash_mandatory_wformat_undefbehav_35", nocrash_mandatory_wformat_undefbehav_35, nocrash_mandatory_wformat_undefbehav_35_bench, "{return test(\"%0+-8.3u\", 8375);}"},
	{1, 2379, "nocrash_mandatory_wformat_undefbehav_36", nocrash_mandatory_wformat_undefbehav_36, nocrash_mandatory_wformat_undefbehav_36_bench, "{return test(\"%0+-3.7u\", 3267);}"},
	{1, 2380, "nocrash_mandatory_wformat_undefbehav_37", nocrash_mandatory_wformat_undefbehav_37, nocrash_mandatory_wformat_undefbehav_37_bench, "{return test(\"%0+-3.3u\", 6983);}"},
	{1, 2381, "nocrash_mandatory_wformat_undefbehav_38", nocrash_mandatory_wformat_undefbehav_38, nocrash_mandatory_wformat_undefbehav_38_bench, "{return test(\"%05c\", '\0');}"},
	{1, 2382, "nocrash_mandatory_wformat_undefbehav_39", nocrash_mandatory_wformat_undefbehav_39, nocrash_mandatory_wformat_undefbehav_39_bench, "{return test(\"%-05c\", '\0');}"},
	{1, 2383, "nocrash_mandatory_wformat_undefbehav_40", nocrash_mandatory_wformat_undefbehav_40, nocrash_mandatory_wformat_undefbehav_40_bench, "{return test(\"%+lu\", 22337203685477);}"},
	{1, 2384, "nocrash_mandatory_dupflag_d_asas", nocrash_mandatory_dupflag_d_asas, nocrash_mandatory_dupflag_d_asas_bench, "{return test(\"%++d\", 42);}"},
	{1, 2385, "nocrash_mandatory_dupflag_d_spsp", nocrash_mandatory_dupflag_d_spsp, nocrash_mandatory_dupflag_d_spsp_bench, "{return test(\"%  d\", 42);}"},
	{1, 2386, "nocrash_mandatory_dupflag_d_spassp", nocrash_mandatory_dupflag_d_spassp, nocrash_mandatory_dupflag_d_spassp_bench, "{return test(\"% + d\", 42);}"},
	{1, 2387, "nocrash_mandatory_dupflag_d_ljljw", nocrash_mandatory_dupflag_d_ljljw, nocrash_mandatory_dupflag_d_ljljw_bench, "{return test(\"%--5d\", 42);}"},
	{1, 2388, "nocrash_mandatory_dupflag_d_ljasljw", nocrash_mandatory_dupflag_d_ljasljw, nocrash_mandatory_dupflag_d_ljasljw_bench, "{return test(\"%-+-5d\", 42);}"},
	{1, 2389, "nocrash_mandatory_dupflag_x_afaf", nocrash_mandatory_dupflag_x_afaf, nocrash_mandatory_dupflag_x_afaf_bench, "{return test(\"%##x\", 42);}"},
	{1, 2390, "nocrash_mandatory_dupflag_x_afasasafljw", nocrash_mandatory_dupflag_x_afasasafljw, nocrash_mandatory_dupflag_x_afasasafljw_bench, "{return test(\"%#++#-5x\", 42);}"},
	{1, 2391, "nocrash_mandatory_c_prec_1", nocrash_mandatory_c_prec_1, nocrash_mandatory_c_prec_1_bench, "{return test(\"%.4c\", 'a');}"},
	{1, 2392, "nocrash_mandatory_c_prec_2", nocrash_mandatory_c_prec_2, nocrash_mandatory_c_prec_2_bench, "{return test(\"%.c\", 'a');}"},
	{1, 2393, "nocrash_mandatory_c_af", nocrash_mandatory_c_af, nocrash_mandatory_c_af_bench, "{return test(\"%#c\", 'a');}"},
	{1, 2394, "nocrash_mandatory_c_zp_1", nocrash_mandatory_c_zp_1, nocrash_mandatory_c_zp_1_bench, "{return test(\"%05c\", 'a');}"},
	{1, 2395, "nocrash_mandatory_c_zp_2", nocrash_mandatory_c_zp_2, nocrash_mandatory_c_zp_2_bench, "{return test(\"%0c\", 'a');}"},
	{1, 2396, "nocrash_mandatory_c_as_1", nocrash_mandatory_c_as_1, nocrash_mandatory_c_as_1_bench, "{return test(\"%+c\", 'a');}"},
	{1, 2397, "nocrash_mandatory_c_as_2", nocrash_mandatory_c_as_2, nocrash_mandatory_c_as_2_bench, "{return test(\"%+c\", -42);}"},
	{1, 2398, "nocrash_mandatory_c_sp_1", nocrash_mandatory_c_sp_1, nocrash_mandatory_c_sp_1_bench, "{return test(\"% c\", 'a');}"},
	{1, 2399, "nocrash_mandatory_c_sp_2", nocrash_mandatory_c_sp_2, nocrash_mandatory_c_sp_2_bench, "{return test(\"% c\", -42);}"},
	{1, 2400, "nocrash_mandatory_c_size_hh", nocrash_mandatory_c_size_hh, nocrash_mandatory_c_size_hh_bench, "{return test(\"%hhc\", 'a');}"},
	{1, 2401, "nocrash_mandatory_c_size_h", nocrash_mandatory_c_size_h, nocrash_mandatory_c_size_h_bench, "{return test(\"%hc\", 'a');}"},
	{1, 2402, "nocrash_mandatory_c_size_l", nocrash_mandatory_c_size_l, nocrash_mandatory_c_size_l_bench, "{return test(\"%lc\", L'a');}"},
	{1, 2403, "nocrash_mandatory_c_size_ll", nocrash_mandatory_c_size_ll, nocrash_mandatory_c_size_ll_bench, "{return test(\"%llc\", L'a');}"},
	{1, 2404, "nocrash_mandatory_c_size_L", nocrash_mandatory_c_size_L, nocrash_mandatory_c_size_L_bench, "{return test(\"%Lc\", L'a');}"},
	{1, 2405, "nocrash_mandatory_c_lj_nowidth", nocrash_mandatory_c_lj_nowidth, nocrash_mandatory_c_lj_nowidth_bench, "{return test(\"%-c\", 'a');}"},
	{1, 2406, "nocrash_mandatory_s_af", nocrash_mandatory_s_af, nocrash_mandatory_s_af_bench, "{return test(\"%#s\", \"hello\");}"},
	{1, 2407, "nocrash_mandatory_s_zp_1", nocrash_mandatory_s_zp_1, nocrash_mandatory_s_zp_1_bench, "{return test(\"%05s\", \"hello\");}"},
	{1, 2408, "nocrash_mandatory_s_zp_2", nocrash_mandatory_s_zp_2, nocrash_mandatory_s_zp_2_bench, "{return test(\"%0s\", \"hello\");}"},
	{1, 2409, "nocrash_mandatory_s_as_1", nocrash_mandatory_s_as_1, nocrash_mandatory_s_as_1_bench, "{return test(\"%+s\", \"hello\");}"},
	{1, 2410, "nocrash_mandatory_s_sp_1", nocrash_mandatory_s_sp_1, nocrash_mandatory_s_sp_1_bench, "{return test(\"% s\", \"hello\");}"},
	{1, 2411, "nocrash_mandatory_s_size_hh", nocrash_mandatory_s_size_hh, nocrash_mandatory_s_size_hh_bench, "{return test(\"%hhs\", \"hello\");}"},
	{1, 2412, "nocrash_mandatory_s_size_h", nocrash_mandatory_s_size_h, nocrash_mandatory_s_size_h_bench, "{return test(\"%hs\", \"hello\");}"},
	{1, 2413, "nocrash_mandatory_s_size_l", nocrash_mandatory_s_size_l, nocrash_mandatory_s_size_l_bench, "{return test(\"%ls\", L\"hello\");}"},
	{1, 2414, "nocrash_mandatory_s_size_ll", nocrash_mandatory_s_size_ll, nocrash_mandatory_s_size_ll_bench, "{return test(\"%lls\", L\"hello\");}"},
	{1, 2415, "nocrash_mandatory_s_size_L", nocrash_mandatory_s_size_L, nocrash_mandatory_s_size_L_bench, "{return test(\"%Ls\", L\"hello\");}"},
	{1, 2416, "nocrash_mandatory_s_lj_nowidth", nocrash_mandatory_s_lj_nowidth, nocrash_mandatory_s_lj_nowidth_bench, "{return test(\"%-s\", \"hello\");}"},
	{1, 2417, "nocrash_mandatory_p_prec_1", nocrash_mandatory_p_prec_1, nocrash_mandatory_p_prec_1_bench, "{return test(\"%.4p\", &ncm_p);}"},
	{1, 2418, "nocrash_mandatory_p_prec_2", nocrash_mandatory_p_prec_2, nocrash_mandatory_p_prec_2_bench, "{return test(\"%.p\", &ncm_p);}"},
	{1, 2419, "nocrash_mandatory_p_af", nocrash_mandatory_p_af, nocrash_mandatory_p_af_bench, "{return test(\"%#p\", &ncm_p);}"},
	{1, 2420, "nocrash_mandatory_p_zp_1", nocrash_mandatory_p_zp_1, nocrash_mandatory_p_zp_1_bench, "{return test(\"%05p\", &ncm_p);}"},
	{1, 2421, "nocrash_mandatory_p_zp_2", nocrash_mandatory_p_zp_2, nocrash_mandatory_p_zp_2_bench, "{return test(\"%0p\", &ncm_p);}"},
	{1, 2422, "nocrash_mandatory_p_as_1", nocrash_mandatory_p_as_1, nocrash_mandatory_p_as_1_bench, "{return test(\"%+p\", &ncm_p);}"},
	{1, 2423, "nocrash_mandatory_p_as_2", nocrash_mandatory_p_as_2, nocrash_mandatory_p_as_2_bench, "{return test(\"%+p\", &ncm_p);}"},
	{1, 2424, "nocrash_mandatory_p_sp_1", nocrash_mandatory_p_sp_1, nocrash_mandatory_p_sp_1_bench, "{return test(\"% p\", &ncm_p);}"},
	{1, 2425, "nocrash_mandatory_p_sp_2", nocrash_mandatory_p_sp_2, nocrash_mandatory_p_sp_2_bench, "{return test(\"% p\", &ncm_p);}"},
	{1, 2426, "nocrash_mandatory_p_size_hh", nocrash_mandatory_p_size_hh, nocrash_mandatory_p_size_hh_bench, "{return test(\"%hhp\", &ncm_p);}"},
	{1, 2427, "nocrash_mandatory_p_size_h", nocrash_mandatory_p_size_h, nocrash_mandatory_p_size_h_bench, "{return test(\"%hp\", &ncm_p);}"},
	{1, 2428, "nocrash_mandatory_p_size_l", nocrash_mandatory_p_size_l, nocrash_mandatory_p_size_l_bench, "{return test(\"%lp\", &ncm_p);}"},
	{1, 2429, "nocrash_mandatory_p_size_ll", nocrash_mandatory_p_size_ll, nocrash_mandatory_p_size_ll_bench, "{return test(\"%llp\", &ncm_p);}"},
	{1, 2430, "nocrash_mandatory_p_size_L", nocrash_mandatory_p_size_L, nocrash_mandatory_p_size_L_bench, "{return test(\"%Lp\", &ncm_p);}"},
	{1, 2431, "nocrash_mandatory_p_lj_nowidth", nocrash_mandatory_p_lj_nowidth, nocrash_mandatory_p_lj_nowidth_bench, "{return test(\"%-p\", &ncm_p);}"},
	{1, 2432, "nocrash_mandatory_d_size_L", nocrash_mandatory_d_size_L, nocrash_mandatory_d_size_L_bench, "{return test(\"%Ld\", 42);}"},
	{1, 2433, "nocrash_mandatory_d_af", nocrash_mandatory_d_af, nocrash_mandatory_d_af_bench, "{return test(\"%#d\", 42);}"},
	{1, 2434, "nocrash_mandatory_d_size_hhh", nocrash_mandatory_d_size_hhh, nocrash_mandatory_d_size_hhh_bench, "{return test(\"%hhhd\", 42);}"},
	{1, 2435, "nocrash_mandatory_d_size_hhhh", nocrash_mandatory_d_size_hhhh, nocrash_mandatory_d_size_hhhh_bench, "{return test(\"%hhhhd\", 42);}"},
	{1, 2436, "nocrash_mandatory_d_size_hhl", nocrash_mandatory_d_size_hhl, nocrash_mandatory_d_size_hhl_bench, "{return test(\"%hhld\", 42);}"},
	{1, 2437, "nocrash_mandatory_d_size_hhll", nocrash_mandatory_d_size_hhll, nocrash_mandatory_d_size_hhll_bench, "{return test(\"%hhlld\", 42);}"},
	{1, 2438, "nocrash_mandatory_d_size_llh", nocrash_mandatory_d_size_llh, nocrash_mandatory_d_size_llh_bench, "{return test(\"%llhd\", 42);}"},
	{1, 2439, "nocrash_mandatory_d_size_lll", nocrash_mandatory_d_size_lll, nocrash_mandatory_d_size_lll_bench, "{return test(\"%llld\", 42);}"},
	{1, 2440, "nocrash_mandatory_i_size_L", nocrash_mandatory_i_size_L, nocrash_mandatory_i_size_L_bench, "{return test(\"%Li\", 42);}"},
	{1, 2441, "nocrash_mandatory_i_af", nocrash_mandatory_i_af, nocrash_mandatory_i_af_bench, "{return test(\"%#i\", 42);}"},
	{1, 2442, "nocrash_mandatory_i_size_hhh", nocrash_mandatory_i_size_hhh, nocrash_mandatory_i_size_hhh_bench, "{return test(\"%hhhi\", 42);}"},
	{1, 2443, "nocrash_mandatory_i_lj_nowidth", nocrash_mandatory_i_lj_nowidth, nocrash_mandatory_i_lj_nowidth_bench, "{return test(\"%-i\", 42);}"},
	{1, 2444, "nocrash_mandatory_o_as", nocrash_mandatory_o_as, nocrash_mandatory_o_as_bench, "{return test(\"%+o\", 42);}"},
	{1, 2445, "nocrash_mandatory_o_sp", nocrash_mandatory_o_sp, nocrash_mandatory_o_sp_bench, "{return test(\"% o\", 42);}"},
	{1, 2446, "nocrash_mandatory_o_size_L", nocrash_mandatory_o_size_L, nocrash_mandatory_o_size_L_bench, "{return test(\"%Lo\", 42);}"},
	{1, 2447, "nocrash_mandatory_o_size_hhh", nocrash_mandatory_o_size_hhh, nocrash_mandatory_o_size_hhh_bench, "{return test(\"%hhho\", 42);}"},
	{1, 2448, "nocrash_mandatory_o_size_hhhh", nocrash_mandatory_o_size_hhhh, nocrash_mandatory_o_size_hhhh_bench, "{return test(\"%hhhho\", 42);}"},
	{1, 2449, "nocrash_mandatory_o_size_hhl", nocrash_mandatory_o_size_hhl, nocrash_mandatory_o_size_hhl_bench, "{return test(\"%hhlo\", 42);}"},
	{1, 2450, "nocrash_mandatory_o_size_hhll", nocrash_mandatory_o_size_hhll, nocrash_mandatory_o_size_hhll_bench, "{return test(\"%hhllo\", 42);}"},
	{1, 2451, "nocrash_mandatory_o_size_llh", nocrash_mandatory_o_size_llh, nocrash_mandatory_o_size_llh_bench, "{return test(\"%llho\", 42);}"},
	{1, 2452, "nocrash_mandatory_o_size_lll", nocrash_mandatory_o_size_lll, nocrash_mandatory_o_size_lll_bench, "{return test(\"%lllo\", 42);}"},
	{1, 2453, "nocrash_mandatory_o_lj_nowidth", nocrash_mandatory_o_lj_nowidth, nocrash_mandatory_o_lj_nowidth_bench, "{return test(\"%-o\", 42);}"},
	{1, 2454, "nocrash_mandatory_u_size_L", nocrash_mandatory_u_size_L, nocrash_mandatory_u_size_L_bench, "{return test(\"%Lu\", 42);}"},
	{1, 2455, "nocrash_mandatory_u_af", nocrash_mandatory_u_af, nocrash_mandatory_u_af_bench, "{return test(\"%#u\", 42);}"},
	{1, 2456, "nocrash_mandatory_u_as", nocrash_mandatory_u_as, nocrash_mandatory_u_as_bench, "{return test(\"%+u\", 42);}"},
	{1, 2457, "nocrash_mandatory_u_sp", nocrash_mandatory_u_sp, nocrash_mandatory_u_sp_bench, "{return test(\"% u\", 42);}"},
	{1, 2458, "nocrash_mandatory_u_size_hhh", nocrash_mandatory_u_size_hhh, nocrash_mandatory_u_size_hhh_bench, "{return test(\"%hhhu\", 42);}"},
	{1, 2459, "nocrash_mandatory_u_size_hhhh", nocrash_mandatory_u_size_hhhh, nocrash_mandatory_u_size_hhhh_bench, "{return test(\"%hhhhu\", 42);}"},
	{1, 2460, "nocrash_mandatory_u_size_hhl", nocrash_mandatory_u_size_hhl, nocrash_mandatory_u_size_hhl_bench, "{return test(\"%hhlu\", 42);}"},
	{1, 2461, "nocrash_mandatory_u_size_hhll", nocrash_mandatory_u_size_hhll, nocrash_mandatory_u_size_hhll_bench, "{return test(\"%hhllu\", 42);}"},
	{1, 2462, "nocrash_mandatory_u_size_llh", nocrash_mandatory_u_size_llh, nocrash_mandatory_u_size_llh_bench, "{return test(\"%llhu\", 42);}"},
	{1, 2463, "nocrash_mandatory_u_size_lll", nocrash_mandatory_u_size_lll, nocrash_mandatory_u_size_lll_bench, "{return test(\"%lllu\", 42);}"},
	{1, 2464, "nocrash_mandatory_u_lj_nowidth", nocrash_mandatory_u_lj_nowidth, nocrash_mandatory_u_lj_nowidth_bench, "{return test(\"%-u\", 42);}"},
	{1, 2465, "nocrash_mandatory_x_size_L", nocrash_mandatory_x_size_L, nocrash_mandatory_x_size_L_bench, "{return test(\"%Lx\", 42);}"},
	{1, 2466, "nocrash_mandatory_x_as", nocrash_mandatory_x_as, nocrash_mandatory_x_as_bench, "{return test(\"%+x\", 42);}"},
	{1, 2467, "nocrash_mandatory_x_sp", nocrash_mandatory_x_sp, nocrash_mandatory_x_sp_bench, "{return test(\"% x\", 42);}"},
	{1, 2468, "nocrash_mandatory_x_size_hhh", nocrash_mandatory_x_size_hhh, nocrash_mandatory_x_size_hhh_bench, "{return test(\"%hhhx\", 42);}"},
	{1, 2469, "nocrash_mandatory_x_size_hhhh", nocrash_mandatory_x_size_hhhh, nocrash_mandatory_x_size_hhhh_bench, "{return test(\"%hhhhx\", 42);}"},
	{1, 2470, "nocrash_mandatory_x_size_hhl", nocrash_mandatory_x_size_hhl, nocrash_mandatory_x_size_hhl_bench, "{return test(\"%hhlx\", 42);}"},
	{1, 2471, "nocrash_mandatory_x_size_hhll", nocrash_mandatory_x_size_hhll, nocrash_mandatory_x_size_hhll_bench, "{return test(\"%hhllx\", 42);}"},
	{1, 2472, "nocrash_mandatory_x_size_llh", nocrash_mandatory_x_size_llh, nocrash_mandatory_x_size_llh_bench, "{return test(\"%llhx\", 42);}"},
	{1, 2473, "nocrash_mandatory_x_size_lll", nocrash_mandatory_x_size_lll, nocrash_mandatory_x_size_lll_bench, "{return test(\"%lllx\", 42);}"},
	{1, 2474, "nocrash_mandatory_X_size_L", nocrash_mandatory_X_size_L, nocrash_mandatory_X_size_L_bench, "{return test(\"%LX\", 42);}"},
	{1, 2475, "nocrash_mandatory_X_as", nocrash_mandatory_X_as, nocrash_mandatory_X_as_bench, "{return test(\"%+X\", 42);}"},
	{1, 2476, "nocrash_mandatory_X_sp", nocrash_mandatory_X_sp, nocrash_mandatory_X_sp_bench, "{return test(\"% X\", 42);}"},
	{1, 2477, "nocrash_mandatory_X_size_hhh", nocrash_mandatory_X_size_hhh, nocrash_mandatory_X_size_hhh_bench, "{return test(\"%hhhX\", 42);}"},
	{1, 2478, "nocrash_mandatory_X_size_llh", nocrash_mandatory_X_size_llh, nocrash_mandatory_X_size_llh_bench, "{return test(\"%llhX\", 42);}"},
	{1, 2479, "nocrash_mandatory_x_lj_nowidth", nocrash_mandatory_x_lj_nowidth, nocrash_mandatory_x_lj_nowidth_bench, "{return test(\"%-x\", 42);}"},
	{1, 2480, "nocrash_mandatory_f_size_hh", nocrash_mandatory_f_size_hh, nocrash_mandatory_f_size_hh_bench, "{return test(\"%hhf\", 42.5);}"},
	{1, 2481, "nocrash_mandatory_f_size_h", nocrash_mandatory_f_size_h, nocrash_mandatory_f_size_h_bench, "{return test(\"%hf\", 42.5);}"},
	{1, 2482, "nocrash_mandatory_f_size_ll", nocrash_mandatory_f_size_ll, nocrash_mandatory_f_size_ll_bench, "{return test(\"%llf\", 42.5);}"},
	{1, 2483, "nocrash_mandatory_f_size_lll", nocrash_mandatory_f_size_lll, nocrash_mandatory_f_size_lll_bench, "{return test(\"%lllf\", 42.5);}"},
	{1, 2484, "nocrash_mandatory_f_size_llll", nocrash_mandatory_f_size_llll, nocrash_mandatory_f_size_llll_bench, "{return test(\"%llllf\", 42.5);}"},
	{1, 2485, "nocrash_mandatory_f_size_LL", nocrash_mandatory_f_size_LL, nocrash_mandatory_f_size_LL_bench, "{return test(\"%LLf\", 42.5);}"},
	{1, 2486, "nocrash_mandatory_f_size_Ll", nocrash_mandatory_f_size_Ll, nocrash_mandatory_f_size_Ll_bench, "{return test(\"%Llf\", 42.5);}"},
	{1, 2487, "nocrash_mandatory_f_size_lL", nocrash_mandatory_f_size_lL, nocrash_mandatory_f_size_lL_bench, "{return test(\"%lLf\", 42.5);}"},
	{1, 2488, "nocrash_mandatory_f_lj_nowidth", nocrash_mandatory_f_lj_nowidth, nocrash_mandatory_f_lj_nowidth_bench, "{return test(\"%-f\", 42.5);}"},
	{1, 2489, "moul_s_1", moul_s_1, moul_s_1_bench, "{return test(\" pouet %s !!\", \"camembert\");}"},
	{1, 2490, "moul_s_2", moul_s_2, moul_s_2_bench, "{return test(\"%s !\", \"Ceci n'est pas un \0 exercice !\");}"},
	{1, 2491, "moul_s_3", moul_s_3, moul_s_3_bench, "{return test(\"%s!\", \"Ceci n'est toujours pas un exercice !\");}"},
	{1, 2492, "moul_s_4", moul_s_4, moul_s_4_bench, "{char *str = NULL; return test(\"%s!\", str);}"},
	{1, 2493, "moul_s_5_this_ones_a_doozy", moul_s_5_this_ones_a_doozy, moul_s_5_this_ones_a_doozy_bench, "{return test(\"%s\", "},
	{1, 2494, "moul_d_1", moul_d_1, moul_d_1_bench, "{return test(\"%d\", 42);}"},
	{1, 2495, "moul_d_2", moul_d_2, moul_d_2_bench, "{return test(\"Kashim a %d histoires à raconter\", 1001);}"},
	{1, 2496, "moul_d_3", moul_d_3, moul_d_3_bench, "{return test(\"Il fait au moins %d\n\", -8000);}"},
	{1, 2497, "moul_d_4", moul_d_4, moul_d_4_bench, "{return test(\"%d\", -0);}"},
	{1, 2498, "moul_d_5", moul_d_5, moul_d_5_bench, "{return test(\"%d\", 0);}"},
	{1, 2499, "moul_d_6", moul_d_6, moul_d_6_bench, "{return test(\"%d\", INT_MAX);}"},
	{1, 2500, "moul_d_7", moul_d_7, moul_d_7_bench, "{return test(\"%d\", INT_MIN);}"},
	{1, 2501, "moul_d_8", moul_d_8, moul_d_8_bench, "{return test(\"%d\", INT_MIN - 1);}"},
	{1, 2502, "moul_d_9", moul_d_9, moul_d_9_bench, "{return test(\"%d\", INT_MAX + 1);}"},
	{1, 2503, "moul_d_10", moul_d_10, moul_d_10_bench, "{return test(\"%%d 0000042 == |%d|\n\", 0000042);}"},
	{1, 2504, "moul_d_11", moul_d_11, moul_d_11_bench, "{return test(\"%%d \t == |%d|\n\", '\t');}"},
	{1, 2505, "moul_d_12", moul_d_12, moul_d_12_bench, "{return test(\"%%d Lydie == |%d|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 2506, "moul_mix_1", moul_mix_1, moul_mix_1_bench, "{int r00 = 0; return test(\"Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p\", 100, \"Ly\", &r00);}"},
	{1, 2507, "moul_c_1", moul_c_1, moul_c_1_bench, "{return test(\"%c\", 42);}"},
	{1, 2508, "moul_c_2", moul_c_2, moul_c_2_bench, "{return test(\"Kashim a %c histoires à raconter\", 1001);}"},
	{1, 2509, "moul_c_3", moul_c_3, moul_c_3_bench, "{return test(\"Il fait au moins %c\n\", -8000);}"},
	{1, 2510, "moul_c_4", moul_c_4, moul_c_4_bench, "{return test(\"%c\", -0);}"},
	{1, 2511, "moul_c_5", moul_c_5, moul_c_5_bench, "{return test(\"%c\", 0);}"},
	{1, 2512, "moul_c_5b", moul_c_5b, moul_c_5b_bench, "{return test(\"%c\n\", INT_MAX);}"},
	{1, 2513, "moul_c_6", moul_c_6, moul_c_6_bench, "{return test(\"%c\n\", 'c');}"},
	{1, 2514, "moul_c_7", moul_c_7, moul_c_7_bench, "{return test(\"%c\n\", '\n');}"},
	{1, 2515, "moul_c_8", moul_c_8, moul_c_8_bench, "{return test(\"%c\", 'l');}"},
	{1, 2516, "moul_c_9", moul_c_9, moul_c_9_bench, "{return test(\"%c\", 'y');}"},
	{1, 2517, "moul_c_10", moul_c_10, moul_c_10_bench, "{return test(\"%c\", ' ');}"},
	{1, 2518, "moul_c_11", moul_c_11, moul_c_11_bench, "{return test(\"%c\", 'e');}"},
	{1, 2519, "moul_c_12", moul_c_12, moul_c_12_bench, "{return test(\"%c\", 's');}"},
	{1, 2520, "moul_c_13", moul_c_13, moul_c_13_bench, "{return test(\"%c\", 't');}"},
	{1, 2521, "moul_c_14", moul_c_14, moul_c_14_bench, "{return test(\"%c\", ' ');}"},
	{1, 2522, "moul_c_15", moul_c_15, moul_c_15_bench, "{return test(\"%c\", 'f');}"},
	{1, 2523, "moul_c_16", moul_c_16, moul_c_16_bench, "{return test(\"%c\", 'a');}"},
	{1, 2524, "moul_c_17", moul_c_17, moul_c_17_bench, "{return test(\"%c\", 'n');}"},
	{1, 2525, "moul_c_18", moul_c_18, moul_c_18_bench, "{return test(\"%c\", 't');}"},
	{1, 2526, "moul_c_19", moul_c_19, moul_c_19_bench, "{return test(\"%c\", 'a');}"},
	{1, 2527, "moul_c_20", moul_c_20, moul_c_20_bench, "{return test(\"%c\", 's');}"},
	{1, 2528, "moul_c_21", moul_c_21, moul_c_21_bench, "{return test(\"%c\", 't');}"},
	{1, 2529, "moul_c_22", moul_c_22, moul_c_22_bench, "{return test(\"%c\", 'i');}"},
	{1, 2530, "moul_c_23", moul_c_23, moul_c_23_bench, "{return test(\"%c\", 'q');}"},
	{1, 2531, "moul_c_24", moul_c_24, moul_c_24_bench, "{return test(\"%c\", 'u');}"},
	{1, 2532, "moul_c_25", moul_c_25, moul_c_25_bench, "{return test(\"%c\", 'e');}"},
	{1, 2533, "moul_c_26", moul_c_26, moul_c_26_bench, "{return test(\"%c\n\", '!');}"},
	{1, 2534, "moul_c_27", moul_c_27, moul_c_27_bench, "{return test(\"%c\n\", '\r');}"},
	{1, 2535, "moul_c_28", moul_c_28, moul_c_28_bench, "{return test(\"%c\n\", '\t');}"},
	{1, 2536, "moul_ld_1_throwswarning", moul_ld_1_throwswarning, moul_ld_1_throwswarning_bench, "{return test(\"%ld\", 42);}"},
	{1, 2537, "moul_ld_2_throwswarning", moul_ld_2_throwswarning, moul_ld_2_throwswarning_bench, "{return test(\"Kashim a %ld histoires à raconter\", 1001);}"},
	{1, 2538, "moul_ld_3_throwswarning", moul_ld_3_throwswarning, moul_ld_3_throwswarning_bench, "{return test(\"Il fait au moins %ld\n\", -8000);}"},
	{1, 2539, "moul_ld_4_throwswarning", moul_ld_4_throwswarning, moul_ld_4_throwswarning_bench, "{return test(\"%ld\", -0);}"},
	{1, 2540, "moul_ld_5_throwswarning", moul_ld_5_throwswarning, moul_ld_5_throwswarning_bench, "{return test(\"%ld\", 0);}"},
	{1, 2541, "moul_ld_6_throwswarning", moul_ld_6_throwswarning, moul_ld_6_throwswarning_bench, "{return test(\"%ld\", INT_MAX);}"},
	{1, 2542, "moul_ld_7_throwswarning", moul_ld_7_throwswarning, moul_ld_7_throwswarning_bench, "{return test(\"%ld\", INT_MIN);}"},
	{1, 2543, "moul_ld_8_throwswarning", moul_ld_8_throwswarning, moul_ld_8_throwswarning_bench, "{return test(\"%ld\", INT_MIN - 1);}"},
	{1, 2544, "moul_ld_9_throwswarning", moul_ld_9_throwswarning, moul_ld_9_throwswarning_bench, "{return test(\"%ld\", INT_MAX + 1);}"},
	{1, 2545, "moul_ld_10_throwswarning", moul_ld_10_throwswarning, moul_ld_10_throwswarning_bench, "{return test(\"%%ld 0000042 == |%ld|\n\", 0000042);}"},
	{1, 2546, "moul_ld_11_throwswarning", moul_ld_11_throwswarning, moul_ld_11_throwswarning_bench, "{return test(\"%%ld \t == |%ld|\n\", '\t');}"},
	{1, 2547, "moul_ld_12_throwswarning", moul_ld_12_throwswarning, moul_ld_12_throwswarning_bench, "{return test(\"%%ld Lydie == |%ld|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{0, 2548, "moul_D_1_notmandatory", moul_D_1_notmandatory, moul_D_1_notmandatory_bench, "{return test(\"%D\", 42);}"},
	{0, 2549, "moul_D_2_notmandatory", moul_D_2_notmandatory, moul_D_2_notmandatory_bench, "{return test(\"Kashim a %D histoires à raconter\", 1001);}"},
	{0, 2550, "moul_D_3_notmandatory", moul_D_3_notmandatory, moul_D_3_notmandatory_bench, "{return test(\"Il fait au moins %D\n\", -8000);}"},
	{0, 2551, "moul_D_4_notmandatory", moul_D_4_notmandatory, moul_D_4_notmandatory_bench, "{return test(\"%D\", -0);}"},
	{0, 2552, "moul_D_5_notmandatory", moul_D_5_notmandatory, moul_D_5_notmandatory_bench, "{return test(\"%D\", 0);}"},
	{0, 2553, "moul_D_6_notmandatory", moul_D_6_notmandatory, moul_D_6_notmandatory_bench, "{return test(\"%D\", INT_MAX);}"},
	{0, 2554, "moul_D_7_notmandatory", moul_D_7_notmandatory, moul_D_7_notmandatory_bench, "{return test(\"%D\", INT_MIN);}"},
	{0, 2555, "moul_D_8_notmandatory", moul_D_8_notmandatory, moul_D_8_notmandatory_bench, "{return test(\"%D\", INT_MIN - 1);}"},
	{0, 2556, "moul_D_9_notmandatory", moul_D_9_notmandatory, moul_D_9_notmandatory_bench, "{return test(\"%D\", INT_MAX + 1);}"},
	{0, 2557, "moul_D_10_notmandatory", moul_D_10_notmandatory, moul_D_10_notmandatory_bench, "{return test(\"%%D 0000042 == |%D|\n\", 0000042);}"},
	{0, 2558, "moul_D_11_notmandatory", moul_D_11_notmandatory, moul_D_11_notmandatory_bench, "{return test(\"%%D \t == |%D|\n\", '\t');}"},
	{0, 2559, "moul_D_12_notmandatory", moul_D_12_notmandatory, moul_D_12_notmandatory_bench, "{return test(\"%%D Lydie == |%D|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 2560, "moul_i_1", moul_i_1, moul_i_1_bench, "{return test(\"%i\", 42);}"},
	{1, 2561, "moul_i_2", moul_i_2, moul_i_2_bench, "{return test(\"Kashim a %i histoires à raconter\", 1001);}"},
	{1, 2562, "moul_i_3", moul_i_3, moul_i_3_bench, "{return test(\"Il fait au moins %i\n\", -8000);}"},
	{1, 2563, "moul_i_4", moul_i_4, moul_i_4_bench, "{return test(\"%i\", -0);}"},
	{1, 2564, "moul_i_5", moul_i_5, moul_i_5_bench, "{return test(\"%i\", 0);}"},
	{1, 2565, "moul_i_6", moul_i_6, moul_i_6_bench, "{return test(\"%i\", INT_MAX);}"},
	{1, 2566, "moul_i_7", moul_i_7, moul_i_7_bench, "{return test(\"%i\", INT_MIN);}"},
	{1, 2567, "moul_i_8", moul_i_8, moul_i_8_bench, "{return test(\"%i\", INT_MIN - 1);}"},
	{1, 2568, "moul_i_9", moul_i_9, moul_i_9_bench, "{return test(\"%i\", INT_MAX + 1);}"},
	{1, 2569, "moul_i_10", moul_i_10, moul_i_10_bench, "{return test(\"%%i 0000042 == |%i|\n\", 0000042);}"},
	{1, 2570, "moul_i_11", moul_i_11, moul_i_11_bench, "{return test(\"%%i \t == |%i|\n\", '\t');}"},
	{1, 2571, "moul_i_12", moul_i_12, moul_i_12_bench, "{return test(\"%%i Lydie == |%i|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 2572, "moul_f_1", moul_f_1, moul_f_1_bench, "{return test(\"%f\", (double)42);}"},
	{1, 2573, "moul_f_2", moul_f_2, moul_f_2_bench, "{return test(\"Kashim a %f histoires à raconter\", (double)1001);}"},
	{1, 2574, "moul_f_3", moul_f_3, moul_f_3_bench, "{return test(\"Il fait au moins %f\n\", (double)-8000);}"},
	{1, 2575, "moul_f_4", moul_f_4, moul_f_4_bench, "{return test(\"%f\", (double)-0);}"},
	{1, 2576, "moul_f_5", moul_f_5, moul_f_5_bench, "{return test(\"%f\", (double)0);}"},
	{1, 2577, "moul_f_6", moul_f_6, moul_f_6_bench, "{return test(\"%f\", (double)INT_MAX);}"},
	{1, 2578, "moul_f_7", moul_f_7, moul_f_7_bench, "{return test(\"%f\", (double)INT_MIN);}"},
	{1, 2579, "moul_f_7b", moul_f_7b, moul_f_7b_bench, "{return test(\"%f\", (double)INT_MIN - 1);}"},
	{1, 2580, "moul_f_8", moul_f_8, moul_f_8_bench, "{return test(\"%f\", (double)INT_MAX + 1);}"},
	{1, 2581, "moul_f_9", moul_f_9, moul_f_9_bench, "{return test(\"%%f 0000042 == |%f|\n\", (double)0000042);}"},
	{1, 2582, "moul_f_10", moul_f_10, moul_f_10_bench, "{return test(\"%%f \t == |%f|\n\", (double)'\t');}"},
	{1, 2583, "moul_f_11", moul_f_11, moul_f_11_bench, "{return test(\"%%f Lydie == |%f|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{1, 2584, "moul_f_12", moul_f_12, moul_f_12_bench, "{return test(\"%%f 42.42 == |%f|\n\", 42.42);}"},
	{0, 2585, "moul_F_1_notmandatory", moul_F_1_notmandatory, moul_F_1_notmandatory_bench, "{return test(\"%F\", (double)42);}"},
	{0, 2586, "moul_F_2_notmandatory", moul_F_2_notmandatory, moul_F_2_notmandatory_bench, "{return test(\"Kashim a %F histoires à raconter\", (double)1001);}"},
	{0, 2587, "moul_F_3_notmandatory", moul_F_3_notmandatory, moul_F_3_notmandatory_bench, "{return test(\"Il fait au moins %F\n\", (double)-8000);}"},
	{0, 2588, "moul_F_4_notmandatory", moul_F_4_notmandatory, moul_F_4_notmandatory_bench, "{return test(\"%F\", (double)-0);}"},
	{0, 2589, "moul_F_5_notmandatory", moul_F_5_notmandatory, moul_F_5_notmandatory_bench, "{return test(\"%F\", (double)0);}"},
	{0, 2590, "moul_F_6_notmandatory", moul_F_6_notmandatory, moul_F_6_notmandatory_bench, "{return test(\"%F\", (double)INT_MAX);}"},
	{0, 2591, "moul_F_7_notmandatory", moul_F_7_notmandatory, moul_F_7_notmandatory_bench, "{return test(\"%F\", (double)INT_MIN);}"},
	{0, 2592, "moul_F_8_notmandatory", moul_F_8_notmandatory, moul_F_8_notmandatory_bench, "{return test(\"%F\", (double)INT_MIN - 1);}"},
	{0, 2593, "moul_F_9_notmandatory", moul_F_9_notmandatory, moul_F_9_notmandatory_bench, "{return test(\"%F\", (double)INT_MAX + 1);}"},
	{0, 2594, "moul_F_10_notmandatory", moul_F_10_notmandatory, moul_F_10_notmandatory_bench, "{return test(\"%%F 0000042 == |%F|\n\", (double)0000042);}"},
	{0, 2595, "moul_F_11_notmandatory", moul_F_11_notmandatory, moul_F_11_notmandatory_bench, "{return test(\"%%F \t == |%F|\n\", (double)'\t');}"},
	{0, 2596, "moul_F_12_notmandatory", moul_F_12_notmandatory, moul_F_12_notmandatory_bench, "{return test(\"%%F Lydie == |%F|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{0, 2597, "moul_F_13_notmandatory", moul_F_13_notmandatory, moul_F_13_notmandatory_bench, "{return test(\"%%F 42.42 == |%F|\n\", 42.42);}"},
	{0, 2598, "moul_F_14_notmandatory", moul_F_14_notmandatory, moul_F_14_notmandatory_bench, "{return test(\"%%F 42.42 == |%.2F|\n\", 42.42);}"},
	{1, 2599, "moul_o_1", moul_o_1, moul_o_1_bench, "{return test(\"%o\", 42);}"},
	{1, 2600, "moul_o_2", moul_o_2, moul_o_2_bench, "{return test(\"Kashim a %o histoires à raconter\", 1001);}"},
	{1, 2601, "moul_o_3", moul_o_3, moul_o_3_bench, "{return test(\"Il fait au moins %o\n\", -8000);}"},
	{1, 2602, "moul_o_4", moul_o_4, moul_o_4_bench, "{return test(\"%o\", -0);}"},
	{1, 2603, "moul_o_5", moul_o_5, moul_o_5_bench, "{return test(\"%o\", 0);}"},
	{1, 2604, "moul_o_6", moul_o_6, moul_o_6_bench, "{return test(\"%o\", INT_MAX);}"},
	{1, 2605, "moul_o_7", moul_o_7, moul_o_7_bench, "{return test(\"%o\", INT_MIN);}"},
	{1, 2606, "moul_o_8", moul_o_8, moul_o_8_bench, "{return test(\"%o\", INT_MIN - 1);}"},
	{1, 2607, "moul_o_9", moul_o_9, moul_o_9_bench, "{return test(\"%o\", INT_MAX + 1);}"},
	{1, 2608, "moul_o_10", moul_o_10, moul_o_10_bench, "{return test(\"%%o 0000042 == |%o|\n\", 0000042);}"},
	{1, 2609, "moul_o_11", moul_o_11, moul_o_11_bench, "{return test(\"%%o \t == |%o|\n\", '\t');}"},
	{1, 2610, "moul_o_12", moul_o_12, moul_o_12_bench, "{return test(\"%%o Lydie == |%o|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 2611, "moul_u_1", moul_u_1, moul_u_1_bench, "{return test(\"%u\", 42);}"},
	{1, 2612, "moul_u_2", moul_u_2, moul_u_2_bench, "{return test(\"Kashim a %u histoires à raconter\", 1001);}"},
	{1, 2613, "moul_u_3", moul_u_3, moul_u_3_bench, "{return test(\"Il fait au moins %u\n\", -8000);}"},
	{1, 2614, "moul_u_4", moul_u_4, moul_u_4_bench, "{return test(\"%u\", -0);}"},
	{1, 2615, "moul_u_5", moul_u_5, moul_u_5_bench, "{return test(\"%u\", 0);}"},
	{1, 2616, "moul_u_6", moul_u_6, moul_u_6_bench, "{return test(\"%u\", INT_MAX);}"},
	{1, 2617, "moul_u_7", moul_u_7, moul_u_7_bench, "{return test(\"%u\", INT_MIN);}"},
	{1, 2618, "moul_u_8", moul_u_8, moul_u_8_bench, "{return test(\"%u\", INT_MIN - 1);}"},
	{1, 2619, "moul_u_9", moul_u_9, moul_u_9_bench, "{return test(\"%u\", INT_MAX + 1);}"},
	{1, 2620, "moul_u_10", moul_u_10, moul_u_10_bench, "{return test(\"%%u 0000042 == |%u|\n\", 0000042);}"},
	{1, 2621, "moul_u_11", moul_u_11, moul_u_11_bench, "{return test(\"%%u \t == |%u|\n\", '\t');}"},
	{1, 2622, "moul_u_12", moul_u_12, moul_u_12_bench, "{return test(\"%%u Lydie == |%u|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 2623, "moul_x_1", moul_x_1, moul_x_1_bench, "{return test(\"%x\", 42);}"},
	{1, 2624, "moul_x_2", moul_x_2, moul_x_2_bench, "{return test(\"Kashim a %x histoires à raconter\", 1001);}"},
	{1, 2625, "moul_x_3", moul_x_3, moul_x_3_bench, "{return test(\"Il fait au moins %x\n\", -8000);}"},
	{1, 2626, "moul_x_4", moul_x_4, moul_x_4_bench, "{return test(\"%x\", -0);}"},
	{1, 2627, "moul_x_5", moul_x_5, moul_x_5_bench, "{return test(\"%x\", 0);}"},
	{1, 2628, "moul_x_6", moul_x_6, moul_x_6_bench, "{return test(\"%x\", INT_MAX);}"},
	{1, 2629, "moul_x_7", moul_x_7, moul_x_7_bench, "{return test(\"%x\", INT_MIN);}"},
	{1, 2630, "moul_x_8", moul_x_8, moul_x_8_bench, "{return test(\"%x\", INT_MIN - 1);}"},
	{1, 2631, "moul_x_9", moul_x_9, moul_x_9_bench, "{return test(\"%x\", INT_MAX + 1);}"},
	{1, 2632, "moul_x_10", moul_x_10, moul_x_10_bench, "{return test(\"%%x 0000042 == |%x|\n\", 0000042);}"},
	{1, 2633, "moul_x_11", moul_x_11, moul_x_11_bench, "{return test(\"%%x \t == |%x|\n\", '\t');}"},
	{1, 2634, "moul_x_12", moul_x_12, moul_x_12_bench, "{return test(\"%%x Lydie == |%x|\n\", 'L'+'y'+'d'+'i'+'e');}"},
	{1, 2635, "moul_hash_1", moul_hash_1, moul_hash_1_bench, "{return test(\"%%#X 42 ==  %#X\n\", 42);}"},
	{1, 2636, "moul_hash_2", moul_hash_2, moul_hash_2_bench, "{return test(\"%%X 42 ==  %X\n\", 42);}"},
	{1, 2637, "moul_hash_3", moul_hash_3, moul_hash_3_bench, "{return test(\"%%#o 0 ==  %#o\n\", 0);}"},
	{1, 2638, "moul_hash_4", moul_hash_4, moul_hash_4_bench, "{return test(\"%%o 0 ==  %o\n\", 0);}"},
	{1, 2639, "moul_hash_5", moul_hash_5, moul_hash_5_bench, "{return test(\"%%#o INT_MAX ==  %#o\n\", INT_MAX);}"},
	{1, 2640, "moul_hash_6", moul_hash_6, moul_hash_6_bench, "{return test(\"%%o INT_MAX ==  %o\n\", INT_MAX);}"},
	{1, 2641, "moul_hash_7", moul_hash_7, moul_hash_7_bench, "{return test(\"%%#o INT_MIN ==  %#o\n\", INT_MIN);}"},
	{1, 2642, "moul_hash_8", moul_hash_8, moul_hash_8_bench, "{return test(\"%%o INT_MIN ==  %o\n\", INT_MIN);}"},
	{1, 2643, "moul_hash_9", moul_hash_9, moul_hash_9_bench, "{return test(\"%%#X INT_MIN ==  %#X\n\", INT_MIN);}"},
	{1, 2644, "moul_hash_10", moul_hash_10, moul_hash_10_bench, "{return test(\"%%X INT_MIN ==  %X\n\", INT_MIN);}"},
	{1, 2645, "moul_hash_11", moul_hash_11, moul_hash_11_bench, "{return test(\"%%#X INT_MAX ==  %#X\n\", INT_MAX);}"},
	{1, 2646, "moul_hash_12", moul_hash_12, moul_hash_12_bench, "{return test(\"%%X INT_MAX ==  %X\n\", INT_MAX);}"},
	{1, 2647, "moul_prec_1", moul_prec_1, moul_prec_1_bench, "{return test(\"%%-5.3s LYDI == |%-5.3s|\n\", \"LYDI\");}"},
	{1, 2648, "moul_prec_2", moul_prec_2, moul_prec_2_bench, "{return test(\"%% 4.5i 42 == |% 4.5i|\n\", 42);}"},
	{1, 2649, "moul_prec_3", moul_prec_3, moul_prec_3_bench, "{return test(\"%%04.5i 42 == |%04.5i|\n\", 42);}"},
	{1, 2650, "moul_prec_4", moul_prec_4, moul_prec_4_bench, "{return test(\"%%04.3i 42 == |%04.3i|\n\", 42);}"},
	{1, 2651, "moul_prec_5", moul_prec_5, moul_prec_5_bench, "{return test(\"%%04.2i 42 == |%04.2i|\n\", 42);}"},
	{1, 2652, "moul_zeropad_1", moul_zeropad_1, moul_zeropad_1_bench, "{return test(\"%%04i 42 == |%04i|\n\", 42);}"},
	{1, 2653, "moul_zeropad_2", moul_zeropad_2, moul_zeropad_2_bench, "{return test(\"%%05i 42 == |%05i|\n\", 42);}"},
	{1, 2654, "moul_zeropad_3", moul_zeropad_3, moul_zeropad_3_bench, "{return test(\"%%0i 42 == |%0i|\n\", 42);}"},
	{1, 2655, "moul_zeropad_4", moul_zeropad_4, moul_zeropad_4_bench, "{return test(\"%%0d 0000042 == |%0d|\n\", 0000042);}"},
	{1, 2656, "moul_leftjusty_1", moul_leftjusty_1, moul_leftjusty_1_bench, "{return test(\"%%-i 42 == %-i\n\", 42);}"},
	{1, 2657, "moul_leftjusty_2", moul_leftjusty_2, moul_leftjusty_2_bench, "{return test(\"%%-d 42 == %-d\n\", INT_MIN);}"},
	{1, 2658, "moul_leftjusty_3", moul_leftjusty_3, moul_leftjusty_3_bench, "{return test(\"%%-i -42 == %-i\n\", -42);}"},
	{1, 2659, "moul_leftjusty_4", moul_leftjusty_4, moul_leftjusty_4_bench, "{return test(\"%%-4d 42 == |%-4d|\n\", 42);}"},
	{1, 2660, "moul_leftjusty_5", moul_leftjusty_5, moul_leftjusty_5_bench, "{return test(\"%%-5d -42 == |%-5d|\n\", -42);}"},
	{1, 2661, "moul_leftjusty_6", moul_leftjusty_6, moul_leftjusty_6_bench, "{return test(\"|%3i|%-3i|\n\", 42, 42);}"},
	{1, 2662, "moul_leftjusty_7", moul_leftjusty_7, moul_leftjusty_7_bench, "{return test(\"%%-4i 42 == |%-4i|\n\", 42);}"},
	{1, 2663, "moul_as_1", moul_as_1, moul_as_1_bench, "{return test(\"%%+i 42 == %+i\n\", 42);}"},
	{1, 2664, "moul_as_2", moul_as_2, moul_as_2_bench, "{return test(\"%%+d 42 == %+d\n\", INT_MAX);}"},
	{1, 2665, "moul_as_3", moul_as_3, moul_as_3_bench, "{return test(\"%%+i -42 == %+i\n\", -42);}"},
	{1, 2666, "moul_as_4", moul_as_4, moul_as_4_bench, "{return test(\"%%+04d 42 == %0+04d\n\", 42);}"},
	{1, 2667, "moul_sp_1", moul_sp_1, moul_sp_1_bench, "{return test(\"%%      i 42 == |%      i|\n\", 42);}"},
	{1, 2668, "moul_sp_2", moul_sp_2, moul_sp_2_bench, "{return test(\"%% i -42 == |% i|\n\", -42);}"},
	{1, 2669, "moul_sp_3", moul_sp_3, moul_sp_3_bench, "{return test(\"%% 4i 42 == |% 4i|\n\", 42);}"},
	{0, 2670, "moul_notmandatory_e_1", moul_notmandatory_e_1, moul_notmandatory_e_1_bench, "{return test(\"%e\", (double)42);}"},
	{0, 2671, "moul_notmandatory_e_2", moul_notmandatory_e_2, moul_notmandatory_e_2_bench, "{return test(\"Kashim a %e histoires à raconter\", (double)1001);}"},
	{0, 2672, "moul_notmandatory_e_3", moul_notmandatory_e_3, moul_notmandatory_e_3_bench, "{return test(\"Il fait au moins %e\n\", (double)-8000);}"},
	{0, 2673, "moul_notmandatory_e_4", moul_notmandatory_e_4, moul_notmandatory_e_4_bench, "{return test(\"%e\", (double)-0);}"},
	{0, 2674, "moul_notmandatory_e_5", moul_notmandatory_e_5, moul_notmandatory_e_5_bench, "{return test(\"%e\", (double)0);}"},
	{0, 2675, "moul_notmandatory_e_6", moul_notmandatory_e_6, moul_notmandatory_e_6_bench, "{return test(\"%e\", (double)INT_MAX);}"},
	{0, 2676, "moul_notmandatory_e_7", moul_notmandatory_e_7, moul_notmandatory_e_7_bench, "{return test(\"%e\", (double)INT_MIN);}"},
	{0, 2677, "moul_notmandatory_e_8", moul_notmandatory_e_8, moul_notmandatory_e_8_bench, "{return test(\"%e\", (double)INT_MIN - 1);}"},
	{0, 2678, "moul_notmandatory_e_9", moul_notmandatory_e_9, moul_notmandatory_e_9_bench, "{return test(\"%e\", (double)INT_MAX + 1);}"},
	{0, 2679, "moul_notmandatory_e_10", moul_notmandatory_e_10, moul_notmandatory_e_10_bench, "{return test(\"%%e 0000042 == |%e|\n\", (double)0000042);}"},
	{0, 2680, "moul_notmandatory_e_11", moul_notmandatory_e_11, moul_notmandatory_e_11_bench, "{return test(\"%%e \t == |%e|\n\", (double)'\t');}"},
	{0, 2681, "moul_notmandatory_e_12", moul_notmandatory_e_12, moul_notmandatory_e_12_bench, "{return test(\"%%e Lydie == |%e|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{0, 2682, "moul_notmandatory_e_13", moul_notmandatory_e_13, moul_notmandatory_e_13_bench, "{return test(\"%%e 42.42 == |%e|\n\", 42.42);}"},
	{0, 2683, "moul_notmandatory_e_14", moul_notmandatory_e_14, moul_notmandatory_e_14_bench, "{return test(\"%E\", (double)42);}"},
	{0, 2684, "moul_notmandatory_e_15", moul_notmandatory_e_15, moul_notmandatory_e_15_bench, "{return test(\"Kashim a %E histoires à raconter\", (double)1001);}"},
	{0, 2685, "moul_notmandatory_e_16", moul_notmandatory_e_16, moul_notmandatory_e_16_bench, "{return test(\"Il fait au moins %E\n\", (double)-8000);}"},
	{0, 2686, "moul_notmandatory_e_17", moul_notmandatory_e_17, moul_notmandatory_e_17_bench, "{return test(\"%E\", (double)-0);}"},
	{0, 2687, "moul_notmandatory_e_18", moul_notmandatory_e_18, moul_notmandatory_e_18_bench, "{return test(\"%E\", (double)0);}"},
	{0, 2688, "moul_notmandatory_e_19", moul_notmandatory_e_19, moul_notmandatory_e_19_bench, "{return test(\"%E\", (double)INT_MAX);}"},
	{0, 2689, "moul_notmandatory_e_20", moul_notmandatory_e_20, moul_notmandatory_e_20_bench, "{return test(\"%E\", (double)INT_MIN);}"},
	{0, 2690, "moul_notmandatory_e_21", moul_notmandatory_e_21, moul_notmandatory_e_21_bench, "{return test(\"%E\", (double)INT_MIN - 1);}"},
	{0, 2691, "moul_notmandatory_e_22", moul_notmandatory_e_22, moul_notmandatory_e_22_bench, "{return test(\"%E\", (double)INT_MAX + 1);}"},
	{0, 2692, "moul_notmandatory_e_23", moul_notmandatory_e_23, moul_notmandatory_e_23_bench, "{return test(\"%%E 0000042 == |%E|\n\", (double)0000042);}"},
	{0, 2693, "moul_notmandatory_e_24", moul_notmandatory_e_24, moul_notmandatory_e_24_bench, "{return test(\"%%E \t == |%E|\n\", (double)'\t');}"},
	{0, 2694, "moul_notmandatory_e_25", moul_notmandatory_e_25, moul_notmandatory_e_25_bench, "{return test(\"%%E Lydie == |%E|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{0, 2695, "moul_notmandatory_e_26", moul_notmandatory_e_26, moul_notmandatory_e_26_bench, "{return test(\"%%E 42.42 == |%E|\n\", 42.42);}"},
	{0, 2696, "moul_notmandatory_e_27", moul_notmandatory_e_27, moul_notmandatory_e_27_bench, "{return test(\"%%E 42.42 == |%.2E|\n\", 42.42);}"},
	{0, 2697, "moul_notmandatory_g_1", moul_notmandatory_g_1, moul_notmandatory_g_1_bench, "{return test(\"%g\", (double)42);}"},
	{0, 2698, "moul_notmandatory_g_2", moul_notmandatory_g_2, moul_notmandatory_g_2_bench, "{return test(\"Kashim a %g histoires à raconter\", (double)1001);}"},
	{0, 2699, "moul_notmandatory_g_3", moul_notmandatory_g_3, moul_notmandatory_g_3_bench, "{return test(\"Il fait au moins %g\n\", (double)-8000);}"},
	{0, 2700, "moul_notmandatory_g_4", moul_notmandatory_g_4, moul_notmandatory_g_4_bench, "{return test(\"%g\", (double)-0);}"},
	{0, 2701, "moul_notmandatory_g_5", moul_notmandatory_g_5, moul_notmandatory_g_5_bench, "{return test(\"%g\", (double)0);}"},
	{0, 2702, "moul_notmandatory_g_5b", moul_notmandatory_g_5b, moul_notmandatory_g_5b_bench, "{return test(\"%g\", (double)INT_MAX);}"},
	{0, 2703, "moul_notmandatory_g_6", moul_notmandatory_g_6, moul_notmandatory_g_6_bench, "{return test(\"%g\", (double)INT_MIN);}"},
	{0, 2704, "moul_notmandatory_g_7", moul_notmandatory_g_7, moul_notmandatory_g_7_bench, "{return test(\"%g\", (double)INT_MIN - 1);}"},
	{0, 2705, "moul_notmandatory_g_8", moul_notmandatory_g_8, moul_notmandatory_g_8_bench, "{return test(\"%g\", (double)INT_MAX + 1);}"},
	{0, 2706, "moul_notmandatory_g_9", moul_notmandatory_g_9, moul_notmandatory_g_9_bench, "{return test(\"%%g 0000042 == |%g|\n\", (double)0000042);}"},
	{0, 2707, "moul_notmandatory_g_10", moul_notmandatory_g_10, moul_notmandatory_g_10_bench, "{return test(\"%%g \t == |%g|\n\", (double)'\t');}"},
	{0, 2708, "moul_notmandatory_g_11", moul_notmandatory_g_11, moul_notmandatory_g_11_bench, "{return test(\"%%g Lydie == |%g|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{0, 2709, "moul_notmandatory_g_12", moul_notmandatory_g_12, moul_notmandatory_g_12_bench, "{return test(\"%%g 42.42 == |%g|\n\", 42.42);}"},
	{0, 2710, "moul_notmandatory_g_13", moul_notmandatory_g_13, moul_notmandatory_g_13_bench, "{return test(\"%G\", (double)42);}"},
	{0, 2711, "moul_notmandatory_g_14", moul_notmandatory_g_14, moul_notmandatory_g_14_bench, "{return test(\"Kashim a %G histoires à raconter\", (double)1001);}"},
	{0, 2712, "moul_notmandatory_g_15", moul_notmandatory_g_15, moul_notmandatory_g_15_bench, "{return test(\"Il fait au moins %G\n\", (double)-8000);}"},
	{0, 2713, "moul_notmandatory_g_16", moul_notmandatory_g_16, moul_notmandatory_g_16_bench, "{return test(\"%G\", (double)-0);}"},
	{0, 2714, "moul_notmandatory_g_17", moul_notmandatory_g_17, moul_notmandatory_g_17_bench, "{return test(\"%G\", (double)0);}"},
	{0, 2715, "moul_notmandatory_g_18", moul_notmandatory_g_18, moul_notmandatory_g_18_bench, "{return test(\"%G\", (double)INT_MAX);}"},
	{0, 2716, "moul_notmandatory_g_19", moul_notmandatory_g_19, moul_notmandatory_g_19_bench, "{return test(\"%G\", (double)INT_MIN);}"},
	{0, 2717, "moul_notmandatory_g_20", moul_notmandatory_g_20, moul_notmandatory_g_20_bench, "{return test(\"%G\", (double)INT_MIN - 1);}"},
	{0, 2718, "moul_notmandatory_g_21", moul_notmandatory_g_21, moul_notmandatory_g_21_bench, "{return test(\"%G\", (double)INT_MAX + 1);}"},
	{0, 2719, "moul_notmandatory_g_22", moul_notmandatory_g_22, moul_notmandatory_g_22_bench, "{return test(\"%%G 0000042 == |%G|\n\", (double)0000042);}"},
	{0, 2720, "moul_notmandatory_g_23", moul_notmandatory_g_23, moul_notmandatory_g_23_bench, "{return test(\"%%G \t == |%G|\n\", (double)'\t');}"},
	{0, 2721, "moul_notmandatory_g_24", moul_notmandatory_g_24, moul_notmandatory_g_24_bench, "{return test(\"%%G Lydie == |%G|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{0, 2722, "moul_notmandatory_g_25", moul_notmandatory_g_25, moul_notmandatory_g_25_bench, "{return test(\"%%G 42.42 == |%G|\n\", 42.42);}"},
	{0, 2723, "moul_notmandatory_g_26", moul_notmandatory_g_26, moul_notmandatory_g_26_bench, "{return test(\"%%G 42.42 == |%.2G|\n\", 42.42);}"},
	{0, 2724, "moul_notmandatory_a_1", moul_notmandatory_a_1, moul_notmandatory_a_1_bench, "{return test(\"%a\", (double)42);}"},
	{0, 2725, "moul_notmandatory_a_2", moul_notmandatory_a_2, moul_notmandatory_a_2_bench, "{return test(\"Kashim a %a histoires à raconter\", (double)1001);}"},
	{0, 2726, "moul_notmandatory_a_3", moul_notmandatory_a_3, moul_notmandatory_a_3_bench, "{return test(\"Il fait au moins %a\n\", (double)-8000);}"},
	{0, 2727, "moul_notmandatory_a_4", moul_notmandatory_a_4, moul_notmandatory_a_4_bench, "{return test(\"%a\", (double)-0);}"},
	{0, 2728, "moul_notmandatory_a_5", moul_notmandatory_a_5, moul_notmandatory_a_5_bench, "{return test(\"%a\", (double)0);}"},
	{0, 2729, "moul_notmandatory_a_6", moul_notmandatory_a_6, moul_notmandatory_a_6_bench, "{return test(\"%a\", (double)INT_MAX);}"},
	{0, 2730, "moul_notmandatory_a_7", moul_notmandatory_a_7, moul_notmandatory_a_7_bench, "{return test(\"%a\", (double)INT_MIN);}"},
	{0, 2731, "moul_notmandatory_a_8", moul_notmandatory_a_8, moul_notmandatory_a_8_bench, "{return test(\"%a\", (double)INT_MIN - 1);}"},
	{0, 2732, "moul_notmandatory_a_9", moul_notmandatory_a_9, moul_notmandatory_a_9_bench, "{return test(\"%a\", (double)INT_MAX + 1);}"},
	{0, 2733, "moul_notmandatory_a_11", moul_notmandatory_a_11, moul_notmandatory_a_11_bench, "{return test(\"%%a 0000042 == |%a|\n\", (double)0000042);}"},
	{0, 2734, "moul_notmandatory_a_12", moul_notmandatory_a_12, moul_notmandatory_a_12_bench, "{return test(\"%%a \t == |%a|\n\", (double)'\t');}"},
	{0, 2735, "moul_notmandatory_a_13", moul_notmandatory_a_13, moul_notmandatory_a_13_bench, "{return test(\"%%a Lydie == |%a|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{0, 2736, "moul_notmandatory_a_14", moul_notmandatory_a_14, moul_notmandatory_a_14_bench, "{return test(\"%%a 42.42 == |%a|\n\", 42.42);}"},
	{0, 2737, "moul_notmandatory_a_15", moul_notmandatory_a_15, moul_notmandatory_a_15_bench, "{return test(\"%A\", (double)42);}"},
	{0, 2738, "moul_notmandatory_a_16", moul_notmandatory_a_16, moul_notmandatory_a_16_bench, "{return test(\"Kashim a %A histoires à raconter\", (double)1001);}"},
	{0, 2739, "moul_notmandatory_a_17", moul_notmandatory_a_17, moul_notmandatory_a_17_bench, "{return test(\"Il fait au moins %A\n\", (double)-8000);}"},
	{0, 2740, "moul_notmandatory_a_18", moul_notmandatory_a_18, moul_notmandatory_a_18_bench, "{return test(\"%A\", (double)-0);}"},
	{0, 2741, "moul_notmandatory_a_19", moul_notmandatory_a_19, moul_notmandatory_a_19_bench, "{return test(\"%A\", (double)0);}"},
	{0, 2742, "moul_notmandatory_a_20", moul_notmandatory_a_20, moul_notmandatory_a_20_bench, "{return test(\"%A\", (double)INT_MAX);}"},
	{0, 2743, "moul_notmandatory_a_21", moul_notmandatory_a_21, moul_notmandatory_a_21_bench, "{return test(\"%A\", (double)INT_MIN);}"},
	{0, 2744, "moul_notmandatory_a_22", moul_notmandatory_a_22, moul_notmandatory_a_22_bench, "{return test(\"%A\", (double)INT_MIN - 1);}"},
	{0, 2745, "moul_notmandatory_a_23", moul_notmandatory_a_23, moul_notmandatory_a_23_bench, "{return test(\"%A\", (double)INT_MAX + 1);}"},
	{0, 2746, "moul_notmandatory_a_24", moul_notmandatory_a_24, moul_notmandatory_a_24_bench, "{return test(\"%%A 0000042 == |%A|\n\", (double)0000042);}"},
	{0, 2747, "moul_notmandatory_a_25", moul_notmandatory_a_25, moul_notmandatory_a_25_bench, "{return test(\"%%A \t == |%A|\n\", (double)'\t');}"},
	{0, 2748, "moul_notmandatory_a_26", moul_notmandatory_a_26, moul_notmandatory_a_26_bench, "{return test(\"%%A Lydie == |%A|\n\", (double)'L'+'y'+'d'+'i'+'e');}"},
	{0, 2749, "moul_notmandatory_a_27", moul_notmandatory_a_27, moul_notmandatory_a_27_bench, "{return test(\"%%A 42.42 == |%A|\n\", 42.42);}"},
	{0, 2750, "moul_notmandatory_a_28", moul_notmandatory_a_28, moul_notmandatory_a_28_bench, "{return test(\"%%A 42.42 == |%.2A|\n\", 42.42);}"},
	{0, 2751, "moul_notmandatory_star_1", moul_notmandatory_star_1, moul_notmandatory_star_1_bench, "{return test(\"%%-*.3s LYDI == |%-*.3s|\n\", 5, \"LYDI\");}"},
	{0, 2752, "moul_notmandatory_star_2", moul_notmandatory_star_2, moul_notmandatory_star_2_bench, "{return test(\"%% *.5i 42 == |% *.5i|\n\", 4, 42);}"},
	{0, 2753, "moul_notmandatory_star_3", moul_notmandatory_star_3, moul_notmandatory_star_3_bench, "{return test(\"%%*i 42 == |%*i|\n\", 5, 42);}"},
	{0, 2754, "moul_notmandatory_star_4", moul_notmandatory_star_4, moul_notmandatory_star_4_bench, "{return test(\"%%*i 42 == |%*i|\n\", 3, 42);}"},
	{0, 2755, "moul_notmandatory_star_5", moul_notmandatory_star_5, moul_notmandatory_star_5_bench, "{return test(\"%%*i 42 == |%*i|\n\", 2, 42);}"},
	{0, 2756, "moul_notmandatory_widechar_mix2_throwswarning", moul_notmandatory_widechar_mix2_throwswarning, moul_notmandatory_widechar_mix2_throwswarning_bench, "{return test(\"Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c\", 100, L'à', \"Ly\", 2, 10, 10000, '\n', \"ôHohoho\");}"},
	{0, 2757, "moul_notmandatory_widechar_basic1", moul_notmandatory_widechar_basic1, moul_notmandatory_widechar_basic1_bench, "{wchar_t c = L'\x82'; return test(\"%C\n\", c);}"},
	{0, 2758, "moul_notmandatory_widechar_basic2", moul_notmandatory_widechar_basic2, moul_notmandatory_widechar_basic2_bench, "{return test(\"%C\n\", L'ø');}"},
	{0, 2759, "moul_notmandatory_widestr_basic2", moul_notmandatory_widestr_basic2, moul_notmandatory_widestr_basic2_bench, "{wchar_t wz[3] = L\"@@\"; return test(\"%ls\", wz);}"},
	{0, 2147483647, NULL, NULL, NULL, NULL}
};

