#include <json.hpp>
#include <iostream>

int main() {

    /**
     * In this example, it's shown how to access JSON values, with an easy string selector.
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

    // First, access in basic form to name property, inside specs object
    JsonObject specs = getObject(obj, "specs");
    std::string name = getString(specs, "name");

    std::cout << "specs name: " << name << std::endl;
    
    // With this form, it's needed call an access function as many times as the value is deep
    // But, with easy form, only calls one time with an string selector:
    std::string easyName = easyGetString(obj, "specs > name");

    std::cout << "specs name with eastGet: " << easyName << std::endl;

    // Also, easyGet can return a value of an array
    double thirdArrayValue = easyGetDouble(obj, "random values > 2");

    std::cout << "Third array value captured with easy get: " << thirdArrayValue << std::endl;

    // You must be careful, because if selector string is not correctly made,
    // raises an IllegalJsonAccessError
    try {
        int secondValue = easyGetInteger(obj, "random values > third");
    } catch (IllegalJsonAccessError &e) {
        std::cout << "IllegalJsonAccessError captured because \"random values\" is a JsonArray and selector pass a string key" << std::endl;
    }

    // Finally, this is an example to access directly to all values of current JSON in this example with easyGet:
    JsonArray _random_values = easyGetArray(obj, "random values");
    std::string _random_values_0 = easyGetString(obj, "random values > 0");
    int _random_values_1 = easyGetInteger(obj, "random values > 1");
    double _random_values_2 = easyGetDouble(obj, "random values > 2");
    bool _random_values_3 = easyGetBoolean(obj, "random values > 3");
    std::nullptr_t _random_values_4 = easyGetNull(obj, "random values > 4");

    std::string payload = easyGetString(obj, "payload");

    bool ack = easyGetBoolean(obj, "ack");

    JsonObject _specs = easyGetObject(obj, "specs");
    std::string _name = easyGetString(obj, "specs > name");
    double _speed = easyGetDouble(obj, "specs > speed");
    int _iters = easyGetInteger(obj, "specs > iters");


    return 0;
}