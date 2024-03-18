#include "repo.h"
#include "cheltuiala.h"
#include "service.h"
#include <string.h>

int adaugare_cheltuiala(ListaCheltuieli* list, int zi, float suma, const char* tip) {

    Cheltuiala* cht = creeazaCh(zi, suma, tip);

    if (cht == NULL || list == NULL)

        return 0;

    if (validareCh(*cht) == 0 ) {

        eliminaCh(cht);

        return 0;
    }
    adaugaCh(list, cht);

    return 1;
}

int modificare_cheltuiala(ListaCheltuieli* list, int pozitie, int zi, float suma, const char* tip) {

    if (pozitie < 0 || pozitie >= list->lg)

        return 0;

    Cheltuiala* cht = creeazaCh(zi, suma, tip);

    if (validareCh(*cht) == 0 ) {

        eliminaCh(cht);

        return 0;
    }
    modificareCh(list, pozitie, zi, suma, tip);

    return 1;
}

int sterge_cheltuiala(ListaCheltuieli* list, int pozitie) {

    if (pozitie < 0 || pozitie >= list->lg || list == NULL)

        return 0;

    stergeCh(list, pozitie);

    return 1;
}

ListaCheltuieli* filtrareCh( ListaCheltuieli* list, ListaCheltuieli* lista_filtrata , int zi, float suma, const char* tip) {

    int i;

    ///filtrare dupa tip
    if ( zi == -1 && suma == -1 )

        for ( i = 0; i < list->lg ; i ++ )

            if ( strcmp(list->cht[i].tip, tip) == 0)

                adaugaCh(lista_filtrata, &(list->cht[i]));


    ///filtrare dupa suma
    if ( zi == -1 && strcmp(tip, "") == 0 )

        for ( i = 0; i < list->lg ; i ++ )

            if ( suma == list->cht[i].suma)

                adaugaCh(lista_filtrata, &(list->cht[i]));

    ///filtrare dupa zi
    if ( suma == -1 && strcmp(tip, "") == 0 )

        for ( i = 0; i < list->lg ; i ++ )

            if ( zi== list->cht[i].zi)

                adaugaCh(lista_filtrata, &(list->cht[i]));

    return lista_filtrata;
}

float comparaCh(Cheltuiala cht1,Cheltuiala cht2, int zi) {

      if (zi == 1)

        return cht1.zi - cht2.zi;

    return cht1.suma - cht2.suma;
}

void sorteazaCh(ListaCheltuieli* list, int directie, int zi) {

    int i, j;

    for ( i = 0 ; i < list->lg - 1; i ++ )

        for ( j = i + 1; j < list->lg ; j ++)
        {
            Cheltuiala cht1 = list->cht[i];

            Cheltuiala cht2 = list->cht[j];

            if ( (-1.0) * directie * comparaCh(cht1, cht2, zi) > 0 )
            {
                Cheltuiala aux = list->cht[i];

                list->cht[i] = list->cht[j];

                list->cht[j] = aux;
            }

        }
}