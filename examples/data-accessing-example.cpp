#include <json.hpp>
#include <iostream>

int main() {
    /**
     * In this example, it's shown how to access JSON values, with different forms.
    */

    JsonObject obj{
        JsonPair("random values", JsonArray{
            JsonValue("a"),
            JsonValue(32),
            JsonValue(45.76),
            JsonValue(true),
            JsonValue(null)
        }),
        JsonPair("payload", "8478-9283-2938-B"),
        JsonPair("ack", false),
        JsonPair("specs", JsonObject{
            JsonPair("name", "ABFJDF-4"),
            JsonPair("speed", 34.65),
            JsonPair("iters", 100)
        })
    };

    /**
     * First type of accessing: get directly a __JsonValue
    */

    // Gets __JsonValue inside __JsonPair with key "random values" of obj
    __JsonValue random_values = get(obj, "random values");

    // If you get a __JsonValue, then you check its type
    std::cout << "type of \"random values\" element: " << getName(getType(random_values)) << std::endl;

    // Check type of __JsonValue and, if is a JsonArray, call to getArray function,
    // which returns a JsonArray object inside a __JsonValue
    JsonArray arr;
    if (getType(random_values) == JsonType::ARRAY) {
        arr = getArray(random_values);
    }

    // Also, you get directly value without checking __JsonValue type
    JsonArray arr1 = getArray(obj, "random values");

    // But you must be careful, because, if you ask for wrong type,
    // raises an IllegalJsonCastingError
    try {
        bool b = getBoolean(obj, "random values");

    } catch (IllegalJsonCastingError &e) {
        std::cout << "getBoolean raises an excepcion, beacuse is not possible casting a JsonArray as a bool" << std::endl;
    }

    // There are functions to access JsonArray values too
    std::cout << "array values: " 
    << getString(arr, 0) << ", "
    << getInteger(arr, 1) << ", "
    << getDouble(arr, 2) << ", "
    << (getBoolean(arr, 3) ? "true" : "false") << ", " // In C++, bool values are printed as an binary one-digit number, 1 (true), 0 (false)
    << (getNull(arr, 4) == null ? "null" : "") << std::endl; // In C++, nullptr_t values couldn't be printed

    // Is important write key correctly, because, if key of a JSON element not exists, any access function raises an IllegalJsonAccessError
    try {
        JsonArray a = getArray(obj, "random-values");

    } catch (IllegalJsonAccessError &e) {
        std::cout << "getArray raises an excepcion, beacuse \"random-values\" key not exists" << std::endl;
    }

    // This excepcion also is raised when try to access to illegal position in JsonArray
    try {
        std::string f = getString(arr, 5);

    } catch (IllegalJsonAccessError &e) {
        std::cout << "getArray raises an excepcion, beacuse position not exists" << std::endl;
    }


    // Finally, this is an example to access directly to all values of current JSON in this example:
    JsonArray _random_values = getArray(obj, "random values");
    std::string _random_values_0 = getString(_random_values, 0);
    int _random_values_1 = getInteger(_random_values, 1);
    double _random_values_2 = getDouble(_random_values, 2);
    bool _random_values_3 = getBoolean(_random_values, 3);
    std::nullptr_t _random_values_4 = getNull(_random_values, 4);

    std::string payload = getString(obj, "payload");

    bool ack = getBoolean(obj, "ack");

    JsonObject specs = getObject(obj, "specs");
    std::string name = getString(specs, "name");
    double speed = getDouble(specs, "speed");
    int iters = getInteger(specs, "iters");


    return 0;
}