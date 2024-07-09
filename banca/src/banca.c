/*
 * banca.c
 *
 * Created on: 29 giugno 2024
 *      Author: Luigi Bignami
 */

#include "banca.h"

static const int INT_VALID_DIGITS_NUMBER = 16;
static const int INT_TEN = 10;
static const int INT_TWO = 2;
static const int INT_ONE = 1;
static const int INT_ZERO = 0;
static const char CHAR_ZERO = '0';
const char* VALID_CCARD_CHARS = "1234567890-" ;

static int get_digits_sum(int ch) {

	return ch < INT_TEN ? ch : fmod(ch, INT_TEN) + get_digits_sum(ch / INT_TEN);

}

static int get_incr(int ch , int digits) {

	return fmod(digits, INT_TWO) == INT_ZERO ? ch : get_digits_sum(INT_TWO * ch);

}

static int get_sum(const char* ccard) {

	int ind_ccard = INT_ZERO, sum = ind_ccard, digits = sum;

	while (ind_ccard < strlen(ccard))
		sum += isdigit(ccard[ind_ccard++]) ?
				get_incr(ccard[ind_ccard - INT_ONE] - CHAR_ZERO, digits++) :
				INT_ZERO;

	return sum ;

}

static bool is_in(const char* text , char ch) {

	bool found = false ;
	int ind_text = INT_ZERO;

	while (ind_text < strlen(text) && ! found)
		found = (ch == text[ind_text++]) ;

	return found ;

}

static bool are_valid_ccard_chars(const char* ccard) {

	bool is_valid = true ;
	int ind_ccard = INT_ZERO;

	while(ind_ccard < strlen(ccard) && is_valid)
		is_valid = is_in(VALID_CCARD_CHARS , ccard[ind_ccard++]) ;

	return is_valid ;

}

static bool is_valid_ccard(const char* ccard) {

	return ccard != NULL && are_valid_ccard_chars(ccard) ;

}

static bool is_valid_digits_number(const char* ccard) {

	int ind_ccard = INT_ZERO , digits = ind_ccard ;

	while (ind_ccard < strlen(ccard))
		digits += isdigit(ccard[ind_ccard++]) ;

	return digits == INT_VALID_DIGITS_NUMBER;

}

static void pre_assert(const char* ccard) {

	assert(is_valid_ccard(ccard)) ;
	assert(is_valid_digits_number(ccard)) ;

}

bool chk_creditcard(const char* ccard) {

	pre_assert(ccard) ;

	return fmod(get_sum(ccard), INT_TEN) == INT_ZERO;

}
