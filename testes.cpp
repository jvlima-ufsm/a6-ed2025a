/*
 * testes.cpp
 * Exercício sobre TAD lista.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2025 João Vicente, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* NÃO MUDAR ESSSE ARQUIVO!!!*/

#include "catch_amalgamated.hpp"

#include <cstring>
#include <cstdlib>

extern "C" {
    #include "abb.h"
}

TEST_CASE("Teste vazio") {
    abb_t* a;
    a= abb_cria();
    REQUIRE(abb_vazia(a) == 1);
    abb_destroi(a);
}

TEST_CASE("Caso 1") {
    abb_t* a;

    // entrada: {5, 3, 7}
    a = abb_cria();
    a = abb_insere(a, 5);
    a = abb_insere(a, 3);
    a = abb_insere(a, 7);
    REQUIRE(abb_vazia(a) != 1);

    // remove folha da esquerda
    REQUIRE(abb_busca(a, 3) == 1);
    a = abb_remove(a, 3);
    REQUIRE(abb_vazia(a) != 1);
    REQUIRE(abb_busca(a, 3) != 1);

    abb_destroi(a);
}

TEST_CASE("Caso 2") {
    abb_t* a;

    // entrada: {5, 3, 7}
    a = abb_cria();
    a = abb_insere(a, 5);
    a = abb_insere(a, 3);
    a = abb_insere(a, 7);
    REQUIRE(abb_vazia(a) != 1);

    // remove folha da direita
    REQUIRE(abb_busca(a, 7) == 1);
    a = abb_remove(a, 7);
    REQUIRE(abb_vazia(a) != 1);
    REQUIRE(abb_busca(a, 7) != 1);

    abb_destroi(a);
}

TEST_CASE("Caso 3") {
    abb_t* a;

    // entrada: {5, 3, 7}
    a = abb_cria();
    a = abb_insere(a, 5);
    a = abb_insere(a, 3);
    a = abb_insere(a, 7);
    REQUIRE(abb_vazia(a) != 1);

    // remove raiz
    REQUIRE(abb_busca(a, 5) == 1);
    a = abb_remove(a, 5);
    REQUIRE(abb_vazia(a) != 1);
    REQUIRE(abb_busca(a, 5) != 1);

    abb_destroi(a);
}



TEST_CASE("Caso 4") {
    abb_t* a;

    a = abb_cria();
    a = abb_insere(a, 6);
    a = abb_insere(a, 2);
    a = abb_insere(a, 8);
    a = abb_insere(a, 1);
    a = abb_insere(a, 4);
    a = abb_insere(a, 3);
    REQUIRE(abb_vazia(a) != 1);

    // caso 1 visto em aula
    REQUIRE(abb_busca(a, 3) == 1);
    a = abb_remove(a, 3);
    REQUIRE(abb_vazia(a) != 1);
    REQUIRE(abb_busca(a, 3) != 1);


    abb_destroi(a);
}

TEST_CASE("Caso 5") {
    abb_t* a;

    a = abb_cria();
    a = abb_insere(a, 6);
    a = abb_insere(a, 2);
    a = abb_insere(a, 8);
    a = abb_insere(a, 1);
    a = abb_insere(a, 4);
    a = abb_insere(a, 3);
    REQUIRE(abb_vazia(a) != 1);

    // caso 2 visto em aula
    REQUIRE(abb_busca(a, 4) == 1);
    a = abb_remove(a, 4);
    REQUIRE(abb_vazia(a) != 1);
    REQUIRE(abb_busca(a, 4) != 1);


    abb_destroi(a);
}

TEST_CASE("Caso 6") {
    abb_t* a;

    a = abb_cria();
    a = abb_insere(a, 6);
    a = abb_insere(a, 2);
    a = abb_insere(a, 8);
    a = abb_insere(a, 1);
    a = abb_insere(a, 4);
    a = abb_insere(a, 3);
    REQUIRE(abb_vazia(a) != 1);

    // caso 1 visto em aula
    REQUIRE(abb_busca(a, 6) == 1);
    a = abb_remove(a, 6);
    REQUIRE(abb_vazia(a) != 1);
    REQUIRE(abb_busca(a, 6) != 1);


    abb_destroi(a);
}

TEST_CASE("Caso 7") {
    abb_t* a;

    a = abb_cria();
    a = abb_insere(a, 20);
    a = abb_insere(a, 2);
    a = abb_insere(a, 1);
    a = abb_insere(a, 4);
    a = abb_insere(a, 3);
    a = abb_insere(a, 40);
    a = abb_insere(a, 30);
    a = abb_insere(a, 25);
    a = abb_insere(a, 35);
    a = abb_insere(a, 50);
    a = abb_insere(a, 45);
    a = abb_insere(a, 55);
    REQUIRE(abb_vazia(a) != 1);

    // variacao do ultimo slide da aula, remove 40
    REQUIRE(abb_busca(a, 40) == 1);
    a = abb_remove(a, 40);
    REQUIRE(abb_vazia(a) != 1);
    REQUIRE(abb_busca(a, 40) != 1);


    abb_destroi(a);
}

