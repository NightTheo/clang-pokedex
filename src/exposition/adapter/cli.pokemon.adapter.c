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


/**
 *
 * @param pokemon
 * \Exemple
 * Salameche x3<br>
 *     Type Feu<br>
 *     Découvert la première fois le 28 mai 2022<br>
 *     Capturé la première fois le 28 mai 2022
 */
String adaptToCliPokemonResponse(Pokemon pokemon) {
    String type = pokemonTypeToString(getPokemonType(pokemon));
    String firstSeenDate = adaptFirstSeenDateForCliPokemonResponse(getFirstSeenDateInPokemonDatasheet(pokemon));
    String firstCaptureDate = adaptFirstCaptureDateForCliPokemonResponse(getFirstCaptureDateInPokemonDatasheet(pokemon));
    String formatted = newFormattedString(
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
    freeNString(3, type, firstSeenDate, firstCaptureDate);
    return formatted;
}

String adaptToCliPokemonNotFoundResponse(String name) {
    return newFormattedString("'%s' n'est pas dans le Pokedex.", stringValue(name));
}

String adaptFirstSeenDateForCliPokemonResponse(Date firstSeenDate) {
    if(NULL == firstSeenDate) return newString("Jamais découvert");

    String date = adaptDateForCliPokemonResponse(firstSeenDate);
    String formatted = newFormattedString("Découvert la première fois le %s", stringValue(date));

    freeString(date);
    return formatted;
}

String adaptFirstCaptureDateForCliPokemonResponse(Date firstCaptureDate) {
    if(NULL == firstCaptureDate) return newString("Jamais capturé");

    String date = adaptDateForCliPokemonResponse(firstCaptureDate);
    String formatted = newFormattedString("Capturé la première fois le %s", stringValue(date));

    freeString(date);
    return formatted;
}

/**
 * FRENCH {2022-09-28} => "28 septembre 2022"
 */
String adaptDateForCliPokemonResponse(Date date) {
    if(NULL == date) return newString("1 janvier 0000");

    String month = monthString(getMonthOf(date));
    String formatted = newFormattedString(
            "%d %s %d", // DD month YYYY : 28 septembre 2022
            getDayOf(date),
            stringValue(month),
            getYearOf(date)
            );

    freeString(month);
    return formatted;
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
