/*
 ============================================================================
 Name        : banca_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include "CUnit/Basic.h"
#include "banca.h"

/* Funzione di inizializzazione. */
int init_suite1(void)
{
	return 0;	// nessuna inizializzazioe
}

/* Funzione di cleanup. */
int clean_suite1(void)
{
	return 0; // nessun cleanup
}


/* Test method */
void test_fun1() {

	CU_ASSERT(chk_creditcard("9900-3672-9138-6278")) ;
	CU_ASSERT(chk_creditcard("9009-3672-9138-6278")) ;
	CU_ASSERT(chk_creditcard("9900-3276-9138-6278")) ;
	CU_ASSERT(chk_creditcard("9009-3672-9138-6278")) ;
	CU_ASSERT(chk_creditcard("9900-3672-3198-6278")) ;
	CU_ASSERT(chk_creditcard("9009-3672-9138-6872")) ;
	CU_ASSERT(chk_creditcard("4716-4359-1733-0099")) ;
	CU_ASSERT(chk_creditcard("0000-0000-0000-0000")) ;
	CU_ASSERT(chk_creditcard("0000-5050-5050-5050")) ;
	CU_ASSERT(chk_creditcard("0000-0000-5050-5050")) ;
	CU_ASSERT(chk_creditcard("0000-0000-5050-5050")) ;
	CU_ASSERT(chk_creditcard("0000-0000-0000-5050")) ;

}


/* La funzione main() serve a strutturare ed eseguire i test.
 * Ritorna CUE_SUCCESS in caso di esecuzione con successo (tutti i test sono superati)
 * altrimenti restituisce un codice di errore come da documentazione CUnit.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test base", test_fun1)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }


   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
