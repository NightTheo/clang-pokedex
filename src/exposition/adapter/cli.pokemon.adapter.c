#include "cli.pokemon.adapter.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


String pokemonTypeToString(PokemonType type);
String adaptDateForCliPokemonResponse(Date pDate);
String monthString(Month month);

String adaptFirstSeenDateForCliPokemonResponse(Date firstSeenDate);

String adaptToCliPokemonResponse(Pokemon pokemon) {
    String type = pokemonTypeToString(getPokemonType(pokemon));
    String firstSeenDate = adaptFirstSeenDateForCliPokemonResponse(getFirstSeenDateInPokemonDatasheet(pokemon));
    string responseValue = malloc(sizeof(char) * 200);
    sprintf(responseValue,
            "%s x%d\n"
            "Type %s\n"
            "%s\n"
            "Jamais capturé",
            stringValue(getPokemonName(pokemon)),
            getNumberOfPokemonCapturedInPokemonDatasheet(pokemon),
            stringValue(type),
            stringValue(firstSeenDate)

    );
    String res =  newString(responseValue);
    free(responseValue);
    freeString(type);
    return res;
}

String adaptFirstSeenDateForCliPokemonResponse(Date firstSeenDate) {
    if(NULL == firstSeenDate) return newString("Jamais découvert");

    String formatted = adaptDateForCliPokemonResponse(firstSeenDate);
    string result = malloc(sizeof(char) * 50);

    sprintf(result, "Découvert la première fois le %s", stringValue(formatted));

    freeString(formatted);
    return newString(result);
}

/**
 * FRENCH {2022-09-28} => "28 septembre 2022"
 */
String adaptDateForCliPokemonResponse(Date date) {
    if(NULL == date) return newString("DD month YYYY");

    int maxDateLength = 20;
    string formatted = malloc(sizeof(char) * maxDateLength);
    String month = monthString(getMonthOf(date));

    sprintf(formatted, "%d %s %d", // DD month YYYY : 28 septembre 2022
            getDayOf(date),
            stringValue(month),
            getYearOf(date));

    freeString(month);
    return newString(formatted);
}

String monthString(Month month) {
    switch (month) {
        case JANUARY: return newString("janvier");
        case FEBRUARY: return newString("fevrier");
        case MARCH: return newString("mars");
        case APRIL: return newString("avril");
        case MAY: return newString("mai");
        case JUNE: return newString("juin");
        case JULY: return newString("juillet");
        case AUGUST: return newString("aout");
        case SEPTEMBER: return newString("septembre");
        case OCTOBER: return newString("octobre");
        case NOVEMBER: return newString("novembre");
        case DECEMBER: return newString("decembre");
        default: return newString("[Error]");
    }
}

String pokemonTypeToString(PokemonType type) {
    switch (type) {
        case Fire: return newString("Feu");
        case Electric: return newString("Electrique");
        default: return newString("Inconnu");
    }
}
