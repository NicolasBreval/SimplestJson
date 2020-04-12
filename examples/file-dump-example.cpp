#include <json.hpp>
#include <iostream>

int main(int argc, char **argv) {

    /**
     * In this example, we create an interactive program, will allow us to
     * dump this JSON in a file:
     * 
     * {
     *     "consoles": [
     *         {
     *             "name": "Play Station 4",
     *             "release dates": [
     *                 {
     *                     "area": "NA",
     *                     "date": "15/11/2013"
     *                 },
     *                 {
     *                     "area": "EU",
     *                     "date": "29/11/2013"
     *                 },
     *                 {
     *                     "area": "AU",
     *                     "date": "29/11/2013"
     *                 },
     *                 {
     *                     "area": "JP",
     *                     "date": "22/02/2014"
     *                 },
     *                 {
     *                     "area": "SA",
     *                     "date": "29/11/2013"
     *                 }
     *             ],
     *             "basic storage": {
     *                 "type": "HDD",
     *                 "unit": "GB",
     *                 "capacity": 500.0,
     *                 "replaceable": true
     *             },
     *             "graphics": {
     *                 "manufacturer": "AMD",
     *                 "unit": "TFLOP",
     *                 "performance": 1.84
     *             }
     *         },
     *         {
     *             "name": "Xbox One",
     *             "release dates": [
     *                 {
     *                     "area": "US",
     *                     "date": "22/11/2013"
     *                 },
     *                 {
     *                     "area": "EU",
     *                     "date": "22/11/2013"
     *                 },
     *                 {
     *                     "area": "MX",
     *                     "date": "22/11/2013"
     *                 },
     *                 {
     *                     "area": "CA",
     *                     "date": "22/11/2013"
     *                 },
     *                 {
     *                     "area": "JP",
     *                     "date": "03/09/2014"
     *                 },
     *                 {
     *                     "area": "AR",
     *                     "date": "08/09/2014"
     *                 },
     *                 {
     *                     "area": "CL",
     *                     "date": "08/09/2014"
     *                 },
     *                 {
     *                     "area": "CO",
     *                     "date": "08/09/2014"
     *                 },
     *                 {
     *                     "area": "EC",
     *                     "date": "08/09/2014"
     *                 },
     *                 {
     *                     "area": "PE",
     *                     "date": "08/09/2014"
     *                 },
     *                 {
     *                     "area": "UY",
     *                     "date": "08/09/2014"
     *                 }
     *             ],
     *             "basic storage": {
     *                 "type": "HDD",
     *                 "unit": "GB",
     *                 "capacity": 500.0,
     *                 "replaceable": false
     *             },
     *             "graphics": {
     *                 "manufacturer": "AMD",
     *                 "unit": "TFLOP",
     *                 "performance": 1.31
     *             }
     *         },
     *         {
     *             "name": "Nintento Switch",
     *             "release dates": [
     *                 {
     *                     "area": "World-wide",
     *                     "date": "03/03/2017"
     *                 }
     *             ],
     *             "basic storage": {
     *                 "type": "Flash",
     *                 "unit": "GB",
     *                 "capacity": 32.0,
     *                 "replaceable": false
     *             },
     *             "graphics": {
     *                 "manufacturer": "Nvidia",
     *                 "unit": "TFLOP",
     *                 "performance": 1.0
     *             }
     *         }
     *     ]
     * }
     * 
     * To execute program, you must pass two arguments: frist, a file name where JSON object will be written;
     * second, a dump type, PRETTY or NON-PRETTY, if you want to dump object with indent or not
    */

    JsonObject obj{
        JsonPair("consoles", JsonArray{
            JsonValue(JsonObject{
                JsonPair("name", "Play Station 4"),
                JsonPair("releases dates", JsonArray{
                    JsonValue(JsonObject{
                        JsonPair("area", "NA"),
                        JsonPair("date", "15/11/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "EU"),
                        JsonPair("date", "29/11/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "AU"),
                        JsonPair("date", "29/11/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "JP"),
                        JsonPair("date", "22/02/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "SA"),
                        JsonPair("date", "29/11/2013")
                    })
                }),
                JsonPair("basic storage", JsonObject{
                    JsonPair("type", "HDD"),
                    JsonPair("unit", "GB"),
                    JsonPair("capacity", 500.0),
                    JsonPair("replaceable", true)
                }),
                JsonPair("graphics", JsonObject{
                    JsonPair("manufacturer", "AMD"),
                    JsonPair("unit", "TFLOP"),
                    JsonPair("performance", 1.84)
                })
            }),
            JsonValue(JsonObject{
                JsonPair("name", "Xbox One"),
                JsonPair("releases dates", JsonArray{
                    JsonValue(JsonObject{
                        JsonPair("area", "US"),
                        JsonPair("date", "22/11/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "EU"),
                        JsonPair("date", "22/11/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "MX"),
                        JsonPair("date", "22/11/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "CA"),
                        JsonPair("date", "22/11/2013")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "JP"),
                        JsonPair("date", "03/09/2014")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "AR"),
                        JsonPair("date", "08/09/2014")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "CL"),
                        JsonPair("date", "08/09/2014")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "CO"),
                        JsonPair("date", "08/09/2014")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "EC"),
                        JsonPair("date", "08/09/2014")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "PE"),
                        JsonPair("date", "08/09/2014")
                    }),
                    JsonValue(JsonObject{
                        JsonPair("area", "UY"),
                        JsonPair("date", "08/09/2014")
                    })
                }),
                JsonPair("basic storage", JsonObject{
                    JsonPair("type", "HDD"),
                    JsonPair("unit", "GB"),
                    JsonPair("capacity", 500.0),
                    JsonPair("replaceable", false)
                }),
                JsonPair("graphics", JsonObject{
                    JsonPair("manufacturer", "AMD"),
                    JsonPair("unit", "TFLOP"),
                    JsonPair("performance", 1.31)
                })
            }),
            JsonValue(JsonObject{
                JsonPair("name", "Nintendo Switch"),
                JsonPair("release dates", JsonArray{
                    JsonValue(JsonObject{
                        JsonPair("area", "World-wide"),
                        JsonPair("date", "03/03/2017")
                    })
                }),
                JsonPair("basic storage", JsonObject{
                    JsonPair("type", "Flash"),
                    JsonPair("unit", "GB"),
                    JsonPair("capacity", 32.0),
                    JsonPair("replaceable", false)
                }),
                JsonPair("graphics", JsonObject{
                    JsonPair("manufacturer", "Nvidia"),
                    JsonPair("unit", "TFLOP"),
                    JsonPair("performance", 1.0)
                })
            })
        })
    };

    if (argc != 3) {
        std::cout << "You must pass file path as first argument and PRETTY or NON-PRETTY as second argument" << std::endl;

    } else {
        std::string fileName = argv[1];

        if (std::string(argv[2]) == "PRETTY") {
            dumpPrettyFile(obj, fileName);
        } else if (std::string(argv[2]) == "NON-PRETTY") {
            dumpFile(obj, fileName);
        } else {
            std::cout << "Unrecognized option, you must pass PRETTY or NON-PRETTY as option after file name" << std::endl;
        }
    }

    return 0;
}