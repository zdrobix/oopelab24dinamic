#include <string.h>
#include "service.h"
#include "repo.h"
#include "cheltuiala.h"
#include <assert.h>

void test_creeazaVid() {

    ListaCheltuieli list;

    list = creazaVid();

    assert(list.lg == 0);

    assert(list.lg != 1);

    distrugeLista(&list);
}

void test_validare_ch() {

    Cheltuiala cht1 = { 5, 50.44, "Ch OK" };

    Cheltuiala cht2 = { 0, 50.44, "Zi Invalid" };

    Cheltuiala cht3 = { 1, -10, "Suma Invalid" };

    Cheltuiala cht4 = { 10, 1010, "" };


    assert(validareCh(cht1) == 1);

    assert(validareCh(cht2) == 0);

    assert(validareCh(cht3) == 0);

    assert(validareCh(cht4) == 0);


    eliminaCh(&cht1);

    eliminaCh(&cht2);

    eliminaCh(&cht3);

    eliminaCh(&cht4);
}

void test_creeaza_ch() {

    Cheltuiala cht = creeazaCh(10, 50, "Transport");


    assert(cht.zi == 10);

    assert(cht.suma == 50);

    assert(strcmp(cht.tip, "Transport") == 0);


    assert(cht.zi != 99999);

    assert(cht.suma != 99999);

    assert(strcmp(cht.tip, "Mancare") != 0);


    eliminaCh(&cht);
}

void test_adauga_sterge() {

    ListaCheltuieli list = creazaVid();


    assert(list.lg == 0);

    adaugaCh(&list, creeazaCh(1, 132, "d"));


    assert(list.lg == 1);

    adaugaCh(&list, creeazaCh(2, 231, "d"));


    assert(list.lg == 2);

    adaugaCh(&list, creeazaCh(3, 231, "d"));


    assert(list.lg == 3);

    adaugaCh(&list, creeazaCh(3, 231, "d"));


    assert(list.lg == 4);

    assert(list.lg != 0);

    sterge_cheltuiala(&list, 1);

    assert(list.lg  == 3);

    sterge_cheltuiala(&list, 1);

    assert(list.lg ==2);

    sterge_cheltuiala(&list, 1);

    assert(list.lg == 1);

    sterge_cheltuiala(&list, 1);

    assert(list.lg == 0);

    distrugeLista(&list);

}

void test_modificare_cheltuiala() {

    ListaCheltuieli lista = creazaVid();


    adaugaCh(&lista, creeazaCh(1, 50, "Mancare"));

    adaugaCh(&lista, creeazaCh(2, 301, "Transport"));

    adaugaCh(&lista, creeazaCh(3, 90, "Haine"));


    modificare_cheltuiala(&lista, 0, 5, 40, "Altele");

    modificare_cheltuiala(&lista, 1, 6, 70, "Divertisment");

    modificare_cheltuiala(&lista, 2, 7, 100, "Facturi");


    assert(lista.cht[0].zi == 5);

    assert(lista.cht[0].suma == 40);

    assert(strcmp(lista.cht[0].tip, "Altele") == 0);


    assert(lista.cht[1].zi == 6);

    assert(lista.cht[1].suma == 70);

    assert(strcmp(lista.cht[1].tip, "Divertisment") == 0);


    assert(lista.cht[2].zi == 7);

    assert(lista.cht[2].suma == 100);

    assert(strcmp(lista.cht[2].tip, "Facturi") == 0);

    distrugeLista(&lista);
}

void test_fitrare () {

    ListaCheltuieli lista = creazaVid();

    adaugaCh(&lista, creeazaCh(1, 50, "Mancare"));

    adaugaCh(&lista, creeazaCh(2, 301, "Transport"));

    adaugaCh(&lista, creeazaCh(3, 90, "Haine"));

    adaugaCh(&lista, creeazaCh(1, 301, "Transport"));

    adaugaCh(&lista, creeazaCh(2, 90, "Mancare"));

    adaugaCh(&lista, creeazaCh(3, 50, "Haine"));


    ListaCheltuieli lista_filtrata_tip = creazaVid();

    ListaCheltuieli lista_filtrata_suma = creazaVid();

    ListaCheltuieli lista_filtrata_zi = creazaVid();


    filtrareCh(&lista, &lista_filtrata_tip, -1, -1, "Mancare");

    assert(lista_filtrata_tip.lg == 2);

    assert(lista_filtrata_tip.cht[0].zi == 1);

    assert(lista_filtrata_tip.cht[1].zi == 2);


    filtrareCh(&lista, &lista_filtrata_suma, -1, 301, "");

    assert(lista_filtrata_suma.lg == 2);

    assert(lista_filtrata_suma.cht[0].zi == 2);

    assert(lista_filtrata_suma.cht[1].zi == 1);


    filtrareCh(&lista, &lista_filtrata_zi, 2, -1, "");

    assert(lista_filtrata_zi.lg == 2);

    assert(lista_filtrata_zi.cht[0].suma == 301);

    assert(lista_filtrata_zi.cht[1].suma == 90);


    distrugeLista(&lista_filtrata_suma);

    distrugeLista(&lista_filtrata_tip);

    distrugeLista(&lista_filtrata_zi);
}

void test_comparatie() {

    Cheltuiala ch1 = creeazaCh(10, 500, "tip1");

    Cheltuiala cht2 = creeazaCh(11, 900, "tip2");

    Cheltuiala cht3 = creeazaCh(20, 400, "tip3");


    assert(comparaCh(ch1, cht2, 1, 0) < 0);

    assert(comparaCh(cht2, ch1, 1, 0) > 0);

    assert(comparaCh(ch1, ch1, 1, 0) == 0);

    assert(comparaCh(ch1, cht2, 1, 0) == -1);

    assert(comparaCh(cht2, ch1, 1, 0) == 1);

    assert(comparaCh(ch1, cht3, 1, 0) < 0);

    assert(comparaCh(cht3, ch1, 1, 0) > 0);

    assert(comparaCh(ch1, cht3, 1, 0) == -10);

    assert(comparaCh(cht3, ch1, 1, 0) == 10);


    eliminaCh(&ch1);

    eliminaCh(&cht2);

    eliminaCh(&cht3);
}

void test_sortare() {

    ListaCheltuieli lista = creazaVid();

    adaugaCh(&lista, creeazaCh(3, 50, "Mancare"));

    adaugaCh(&lista, creeazaCh(1, 300, "Transport"));

    adaugaCh(&lista, creeazaCh(2, 90, "Haine"));


    sorteazaCh(&lista, -1, 1, 0); //zi cresc

    assert(lista.cht[0].zi == 1);

    assert(lista.cht[2].zi == 3);


    sorteazaCh(&lista, 1, 1, 0); //zi desc

    assert(lista.cht[0].zi == 3);

    assert(lista.cht[2].zi == 1);

    assert(lista.cht[0].zi != 1);

    assert(lista.cht[2].zi != 3);


    sorteazaCh(&lista, -1, 0, 1); //suma cresc

    assert(lista.cht[0].suma == 50);

    assert(lista.cht[2].suma == 300);


    sorteazaCh(&lista, 1, 0, 1); //suma desc

    assert(lista.cht[0].suma == 300);

    assert(lista.cht[2].suma == 50);

    assert(lista.cht[0].suma != 50);

    assert(lista.cht[2].suma != 300);
}

void test_distruge() {

    ListaCheltuieli lista = creazaVid();

    adaugaCh(&lista, creeazaCh(3, 50, "Mancare"));

    adaugaCh(&lista, creeazaCh(1, 300, "Transport"));

    adaugaCh(&lista, creeazaCh(2, 90, "Haine"));

    assert(lista.lg== 3);

    distrugeLista(&lista);

    assert(lista.cht == NULL);
}

void prestabilit_cheltuieli(ListaCheltuieli* list) {
    ///adaugarea unor cheltuieli prestabilite

    adaugaCh(list, creeazaCh(1, 20, "Mancare"));

    adaugaCh(list, creeazaCh(2, 30, "Divertisment"));

    adaugaCh(list, creeazaCh(3, 3, "Transport"));

    adaugaCh(list, creeazaCh(3, 200, "Benzinarie"));

    adaugaCh(list, creeazaCh(5, 9000, "Rata"));

    adaugaCh(list, creeazaCh(1, 234, "Rata"));

    adaugaCh(list, creeazaCh(6, 756, "Rata"));

    adaugaCh(list, creeazaCh(7, 132, "Rata"));

    adaugaCh(list, creeazaCh(6, 178, "Electronice"));

    adaugaCh(list, creeazaCh(2, 105, "Factura"));

    adaugaCh(list, creeazaCh(1, 760, "Factura"));

    adaugaCh(list, creeazaCh(3, 255, "Factura"));

    adaugaCh(list, creeazaCh(1, 90, "Factura"));

    adaugaCh(list, creeazaCh(6, 250, "Factura"));

    adaugaCh(list, creeazaCh(6, 100, "Factura"));
}