#include <json.hpp>
#include <iostream>

int main() {

    /**
     * In this this example, we will create a JSON with this structure:
     * 
     * {
     *     "fileName" : "object-definition-example.cpp",
     *     "lines" : 48,
     *     "executable" : true,
     *     "exampleNumber" : 1,
     *     "payload" : null,
     *     "usedValues" : [
     *         "object-definition-example.cpp",
     *         0,
     *         true,
     *         1,
     *         null
     *     ]
     * }
    */
    JsonObject obj{
        JsonPair("fileName", "object-definition-example.cpp"),
        JsonPair("lines", 48),
        JsonPair("executable", true),
        JsonPair("exampleNumber", 1),
        JsonPair("payload", null),
        JsonPair("usedValues", JsonArray{
            JsonValue("object-definition-example.cpp"),
            JsonValue(0),
            JsonValue(true),
            JsonValue(1),
            JsonValue(null)
        })
    };

    // print JSON in one line
    std::cout << dump(obj) << std::endl;

    std::cout << std::endl;

    // pretty print JSON
    std::cout << dumpPretty(obj) << std::endl;

    return 0;
}