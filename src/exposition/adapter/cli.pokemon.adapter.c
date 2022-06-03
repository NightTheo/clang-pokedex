#include "cli.pokemon.adapter.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//___ private methods
String pokemonTypeToString(PokemonType type);
String adaptDateForCliPokemonResponse(Date pDate);
String monthString(Month month);
String adaptFirstSeenDateForCliPokemonResponse(Date firstSeenDate);
String adaptFirstCaptureDateForCliPokemonResponse(Date firstCaptureDate);
//___


String adaptToCliPokemonResponse(Pokemon pokemon) {
    String type = pokemonTypeToString(getPokemonType(pokemon));
    String firstSeenDate = adaptFirstSeenDateForCliPokemonResponse(getFirstSeenDateInPokemonDatasheet(pokemon));
    String firstCaptureDate = adaptFirstCaptureDateForCliPokemonResponse(getFirstCaptureDateInPokemonDatasheet(pokemon));
    string responseValue = malloc(sizeof(char) * 200);
    sprintf(responseValue,
            "%s x%d\n"
            "    Type %s\n"
            "    %s\n"
            "    %s\n",
            stringValue(getPokemonName(pokemon)),
            getNumberOfPokemonCapturedInPokemonDatasheet(pokemon),
            stringValue(type),
            stringValue(firstSeenDate),
            stringValue(firstCaptureDate)

    );
    String res =  newString(responseValue);
    free(responseValue);
    freeString(type);
    freeString(firstSeenDate);
    freeString(firstCaptureDate);
    return res;
}

String adaptFirstSeenDateForCliPokemonResponse(Date firstSeenDate) {
    if(NULL == firstSeenDate) return newString("Jamais découvert");

    String formatted = adaptDateForCliPokemonResponse(firstSeenDate);
    string adaptedValue = malloc(sizeof(char) * 50);

    sprintf(adaptedValue, "Découvert la première fois le %s", stringValue(formatted));

    freeString(formatted);
    String adapted = newString(adaptedValue);
    free(adaptedValue);
    return adapted;
}

String adaptFirstCaptureDateForCliPokemonResponse(Date firstCaptureDate) {
    if(NULL == firstCaptureDate) return newString("Jamais capturé");

    String formatted = adaptDateForCliPokemonResponse(firstCaptureDate);
    string resultValue = malloc(sizeof(char) * 50);

    sprintf(resultValue, "Capturé la première fois le %s", stringValue(formatted));

    freeString(formatted);
    String result = newString(resultValue);
    free(resultValue);
    return result;
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
    String result = newString(formatted);
    free(formatted);
    return result;
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
