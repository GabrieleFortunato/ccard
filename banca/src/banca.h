/*
 * banca.h
 *
 * Created on: 29 giugno 2024
 *      Author: Luigi Bignami
 */

#ifndef CCARD_H_
#define CCARD_H_

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/**
 * Verifica la validita' di una carta di credito.
 * Una carta di credito e' valida se soddisfa il criterio stabilito dall'algoritmo di Luhn.
 *
 * Il controllo di un numero basato sull'algoritmo di Luhn si basa su tre passi:
 *
 * -Partendo da destra e spostandosi verso sinistra, moltiplicare per 2 ogni cifra posta in posizione pari
 * -Laddove la moltiplicazione ha dato un risultato a due cifre, sommare le due cifre per ottenerne una sola (es. 18 -> 1+8)
 * -Sommare tutte le cifre, sia quelle che si trovano in posizione pari, sia quelle che si trovano in posizione dispari
 * -Se la somma complessiva e' divisibile per 10 (la divisione non ha resto) la carta e' valida.
 *
 * Ad esempio, supponendo di avere il seguente numero di carta: 4716-4359-1733-0099 (quindi, da destra a sinistra, la sequenza di
 * cifre e': 9900337195346174), allora:
 * 9+9+0+0+3+6+7+2+9+1+3+8+6+2+7+8=80
 * 80/10 = 8 -> risultato intero -> carta valida
 *
 * @warning l'argomento ccard e' una stringa che puo' contenere trattini. Questi vanno ignorati nella verifica di validita' del numero
 *
 * @pre ccard e' una stringa, non NULL, contenente solo caratteri numerici (0-9) o trattini '-'
 * @pre il numero di cifre contenute in ccard e' sempre uguale a 16
 *
 *
 * @param ccard il numero di carta di credito
 * @return TRUE se e solo se ccard contiene un numero di carta di credito valido
 */
bool chk_creditcard(const char* ccard) ;

#endif /* CCARD_H_ */
