/**
 * @file json.cpp
 * @author nicolasbrevalrodriguez@gmail.com
 * @date 11/04/2020
 * @brief Declaration of json.hpp functions 
*/
#include <json.hpp>

/////////////////////////////////////////////////////////////////////////
//                       ACCESS TYPE FUNCTIONS                         //
/////////////////////////////////////////////////////////////////////////

JsonType getType(__JsonValue value) {
    return value.first;
}

JsonType getType(JsonObject obj, std::string key) {
    return getType(get(obj, key));
}

JsonType getType(JsonObject obj, char *key) {
    return getType(get(obj, key));
}

JsonType getType(JsonObject obj, const char *key) {
    return getType(get(obj, key));
}

JsonType getType(JsonArray array, int pos) {
    return getType(array.at(pos));
}

std::string getName(JsonType type) {
    switch(type) {
        case JsonType::BOOLEAN:
            return "BOOLEAN";
            break;
        case JsonType::INTEGER:
            return "INTEGER";
            break;
        case JsonType::DOUBLE:
            return "DOUBLE";
            break;
        case JsonType::STRING:
            return "STRING";
            break;
        case JsonType::ARRAY:
            return "ARRAY";
            break;
        case JsonType::OBJECT:
            return "OBJECT";
            break;
        case JsonType::NONE:
            return "NONE";
            break;
        default:
            throw IllegalJsonCastingError("Value type is not recognized");
    }
}

/////////////////////////////////////////////////////////////////////////
//                  JSON VALUE CREATION FUNCTIONS                      //
/////////////////////////////////////////////////////////////////////////

__JsonValue JsonValue(bool value) {
    return __JsonValue(JsonType::BOOLEAN, value);
}

__JsonValue JsonValue(int value) {
    return __JsonValue(JsonType::INTEGER, value);
}

__JsonValue JsonValue(double value) {
    return __JsonValue(JsonType::DOUBLE, value);
}

__JsonValue JsonValue(std::string value) {
    return __JsonValue(JsonType::STRING, value);
}

__JsonValue JsonValue(char *value) {
    return __JsonValue(JsonType::STRING, std::string(value));
}

__JsonValue JsonValue(const char *value) {
    return __JsonValue(JsonType::STRING, std::string(value));
}

__JsonValue JsonValue(JsonArray value) {
    return __JsonValue(JsonType::ARRAY, value);
}

__JsonValue JsonValue(JsonObject value) {
    return __JsonValue(JsonType::OBJECT, value);
}

__JsonValue JsonValue(std::nullptr_t value) {
    return __JsonValue(JsonType::NONE, value);
}

/////////////////////////////////////////////////////////////////////////
//                 JSON KEY-VALUE CREATION FUNCTIONS                   //
/////////////////////////////////////////////////////////////////////////

__JsonPair JsonPair(std::string key, int value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(std::string key, double value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(std::string key, std::string value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(std::string key, char * value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(std::string key, const char * value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(std::string key, JsonArray value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(std::string key, JsonObject value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(std::string key, std::nullptr_t value) {
    return __JsonPair(key, JsonValue(value));
}

__JsonPair JsonPair(char *key, bool value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, int value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, double value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, std::string value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, char * value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, const char * value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, JsonArray value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, JsonObject value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(char *key, std::nullptr_t value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, bool value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, int value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, double value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, std::string value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, char * value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, const char * value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, JsonArray value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, JsonObject value) {
    return __JsonPair(std::string(key), JsonValue(value));
}

__JsonPair JsonPair(const char *key, std::nullptr_t value) {
    return __JsonPair(std::string(key), JsonValue(value));
}


/////////////////////////////////////////////////////////////////////////
//                   JSON KEY-VALUE ACCESS FUNCTIONS                   //
/////////////////////////////////////////////////////////////////////////

bool getBoolean(__JsonValue value) {
    if (value.first == JsonType::BOOLEAN) {
        return boost::any_cast<bool>(value.second);
    } else {
        throw IllegalJsonCastingError("Value of JsonValue object is not bool");
    }
}

int getInteger(__JsonValue value) {
    if (value.first == JsonType::INTEGER) {
        return boost::any_cast<int>(value.second);
    } else {
        throw IllegalJsonCastingError("Value of JsonValue object is not int");
    }
}

double getDouble(__JsonValue value) {
    if (value.first == JsonType::DOUBLE) {
        return boost::any_cast<double>(value.second);
    } else {
        throw IllegalJsonCastingError("Value of JsonValue object is not double");
    }
}

std::string getString(__JsonValue value) {
    if (value.first == JsonType::STRING) {
        return boost::any_cast<std::string>(value.second);
    } else {
        throw IllegalJsonCastingError("Value of JsonValue object is not string");
    }
}

JsonArray getArray(__JsonValue value) {
    if (value.first == JsonType::ARRAY) {
        return boost::any_cast<JsonArray>(value.second);
    } else {
        throw IllegalJsonCastingError("Value of JsonValue object is not JSON array");
    }
}

JsonObject getObject(__JsonValue value) {
    if (value.first == JsonType::OBJECT) {
        return boost::any_cast<JsonObject>(value.second);
    } else {
        throw IllegalJsonCastingError("Value of JsonValue object is not JSON object");
    }
}

std::nullptr_t getNull(__JsonValue value) {
    if (value.first == JsonType::NONE) {
        return boost::any_cast<std::nullptr_t>(value.second);
    } else {
        throw IllegalJsonCastingError("Value of JsonValue object is not null");
    }
}

__JsonValue get(JsonObject obj, std::string key) {
    __JsonValue value;
    
    for (int i = 0; i < obj.size(); i++) {
        if (obj.at(i).first == key) {
            value = obj.at(i).second; 
        }
    }

    if (value.second.empty()) {
        throw IllegalJsonAccessError("key '" + key  + "' not exists");
    }

    return value;
}

__JsonValue get(JsonObject obj, char *key) {
    return get(obj, std::string(key));
}

__JsonValue get(JsonObject obj, const char *key) {
    return get(obj, std::string(key));
}

bool getBoolean(JsonObject obj, std::string key) {
    return getBoolean(get(obj, key));
}

int getInteger(JsonObject obj, std::string key){
    return getInteger(get(obj, key));
}

double getDouble(JsonObject obj, std::string key){
    return getDouble(get(obj, key));
}

std::string getString(JsonObject obj, std::string key){
    return getString(get(obj, key));
}

JsonArray getArray(JsonObject obj, std::string key){
    return getArray(get(obj, key));
}

JsonObject getObject(JsonObject obj, std::string key){
    return getObject(get(obj, key));
}

std::nullptr_t getNull(JsonObject obj, std::string key){
    return getNull(get(obj, key));
}

bool getBoolean(JsonObject obj, char *key) {
    return getBoolean(obj, std::string(key));
}

int getInteger(JsonObject obj, char *key) {
    return getInteger(obj, std::string(key));
}

double getDouble(JsonObject obj, char *key) {
    return getDouble(obj, std::string(key));
}

std::string getString(JsonObject obj, char *key) {
    return getString(obj, std::string(key));
}

JsonArray getArray(JsonObject obj, char *key) {
    return getArray(obj, std::string(key));
}

JsonObject getObject(JsonObject obj, char *key) {
    return getObject(obj, std::string(key));
}

std::nullptr_t getNull(JsonObject obj, char *key) {
    return getNull(obj, std::string(key));
}

bool getBoolean(JsonObject obj, const char *key) {
    return getBoolean(obj, std::string(key));
}

int getInteger(JsonObject obj, const char *key) {
    return getInteger(obj, std::string(key));
}

double getDouble(JsonObject obj, const char *key) {
    return getDouble(obj, std::string(key));
}

std::string getString(JsonObject obj, const char *key) {
    return getString(obj, std::string(key));
}

JsonArray getArray(JsonObject obj, const char *key) {
    return getArray(obj, std::string(key));
}

JsonObject getObject(JsonObject obj, const char *key) {
    return getObject(obj, std::string(key));
}

std::nullptr_t getNull(JsonObject obj, const char *key) {
    return getNull(obj, std::string(key));
}

bool getBoolean(JsonArray array, int pos) {
    if (pos < 0 || pos >= array.size()) {
        throw IllegalJsonAccessError("Illegal position in array");
    }

    return getBoolean(array.at(pos));
}

int getInteger(JsonArray array, int pos) {
    if (pos < 0 || pos >= array.size()) {
        throw IllegalJsonAccessError("Illegal position in array");
    }

    return getInteger(array.at(pos));
}

double getDouble(JsonArray array, int pos) {
    if (pos < 0 || pos >= array.size()) {
        throw IllegalJsonAccessError("Illegal position in array");
    }

    return getDouble(array.at(pos));
}

std::string getString(JsonArray array, int pos) {
    if (pos < 0 || pos >= array.size()) {
        throw IllegalJsonAccessError("Illegal position in array");
    }

    return getString(array.at(pos));
}

JsonArray getArray(JsonArray array, int pos) {
    if (pos < 0 || pos >= array.size()) {
        throw IllegalJsonAccessError("Illegal position in array");
    }

    return getArray(array.at(pos));
}

JsonObject getObject(JsonArray array, int pos) {
    if (pos < 0 || pos >= array.size()) {
        throw IllegalJsonAccessError("Illegal position in array");
    }

    return getObject(array.at(pos));
}

std::nullptr_t getNull(JsonArray array, int pos) {
    if (pos < 0 || pos >= array.size()) {
        throw IllegalJsonAccessError("Illegal position in array");
    }

    return getNull(array.at(pos));
}

/////////////////////////////////////////////////////////////////////////
//                       JSON EASY ACCESS FUNCTIONS                    //
/////////////////////////////////////////////////////////////////////////

bool isNumber(std::string selector) {
    bool isNumber = true;
    
    try {
        std::stoi(selector);

    } catch (const std::invalid_argument&) {
        isNumber = false;
    }

    return isNumber;
}

__JsonValue easyGet(JsonObject obj, std::string selector) {

    char c;
    std::string buffer;
    __JsonValue value;

    for (int i = 0; i < selector.size(); i++) {
        c = selector[i];

        if (c == '>') {
            boost::trim(buffer);

            if (!isNumber(buffer)) {
                __JsonValue currentValue = get(obj, buffer);

                if (getType(currentValue) == JsonType::OBJECT) {
                    value = easyGet(getObject(currentValue), selector.substr(i + 1, selector.size() - (i + 1)));
                    break;

                } else if (getType(currentValue) == JsonType::ARRAY) {
                    value = easyGet(getArray(currentValue), selector.substr(i + 1, selector.size() - (i + 1)));
                    break;

                } else {
                    throw IllegalJsonAccessError("trying to access inside a simple value");
                }
            } else {
                throw IllegalJsonAccessError("trying to access a JsonObject with integer index");
            }
        } else if (i == selector.size() - 1) {
            buffer += c;
            boost::trim(buffer);

            if (!isNumber(buffer)) {
                value = get(obj, buffer);
                break;

            } else {
                throw IllegalJsonAccessError("trying to access a JsonObject with integer index");
            }
        } else {
            buffer += c;
        }
    }

    return value;
}

__JsonValue easyGet(JsonArray array, std::string selector) {

    char c;
    std::string buffer;
    __JsonValue value;

    for (int i = 0; i < selector.size(); i++) {
        c = selector[i];

        if (c == '>') {
            boost::trim(buffer);

            if (isNumber(buffer)) {
                __JsonValue currentValue = array.at(std::stoi(buffer));

                if (getType(currentValue) == JsonType::OBJECT) {
                    value = easyGet(getObject(currentValue), selector.substr(i + 1, selector.size() - (i + 1)));
                    break;

                } else if (getType(currentValue) == JsonType::ARRAY) {
                    value = easyGet(getArray(currentValue), selector.substr(i + 1, selector.size() - (i + 1)));
                    break;

                } else {
                    throw IllegalJsonAccessError("trying to access inside a simple value");
                }
            } else {
                throw IllegalJsonAccessError("trying to access a JsonArray with string key");
            }
        } else if (i == selector.size() - 1) {
            buffer += c;
            boost::trim(buffer);

            if (isNumber(buffer)) {
                value = array.at(std::stoi(buffer));
                break;

            } else {
                throw IllegalJsonAccessError("trying to access a JsonArray with string key");
            }
        } else {
            buffer += c;
        }
    }

    return value;
}

__JsonValue easyGet(JsonObject obj, char *selector) {
    return easyGet(obj, std::string(selector));
}

__JsonValue easyGet(JsonObject obj, const char *selector) {
    return easyGet(obj, std::string(selector));
}

__JsonValue easyGet(JsonArray array, char *selector) {
    return easyGet(array, std::string(selector));
}

__JsonValue easyGet(JsonArray array, const char *selector) {
    return easyGet(array, std::string(selector));
}


bool easyGetBoolean(JsonObject obj, std::string selector){
    return getBoolean(easyGet(obj, selector));
}

bool easyGetBoolean(JsonObject obj, char * selector){
    return getBoolean(easyGet(obj, selector));
}

bool easyGetBoolean(JsonObject obj, const char * selector){
    return getBoolean(easyGet(obj, selector));
}

bool easyGetBoolean(JsonArray array, std::string selector){
    return getBoolean(easyGet(array, selector));
}

bool easyGetBoolean(JsonArray array, char * selector){
    return getBoolean(easyGet(array, selector));
}

bool easyGetBoolean(JsonArray array, const char * selector){
    return getBoolean(easyGet(array, selector));
}

int easyGetInteger(JsonObject obj, std::string selector){
    return getInteger(easyGet(obj, selector));
}

int easyGetInteger(JsonObject obj, char * selector){
    return getInteger(easyGet(obj, selector));
}

int easyGetInteger(JsonObject obj, const char * selector){
    return getInteger(easyGet(obj, selector));
}

int easyGetInteger(JsonArray array, std::string selector){
    return getInteger(easyGet(array, selector));
}

int easyGetInteger(JsonArray array, char * selector){
    return getInteger(easyGet(array, selector));
}

int easyGetInteger(JsonArray array, const char * selector){
    return getInteger(easyGet(array, selector));
}

double easyGetDouble(JsonObject obj, std::string selector){
    return getDouble(easyGet(obj, selector));
}

double easyGetDouble(JsonObject obj, char * selector){
    return getDouble(easyGet(obj, selector));
}

double easyGetDouble(JsonObject obj, const char * selector){
    return getDouble(easyGet(obj, selector));
}

double easyGetDouble(JsonArray array, std::string selector){
    return getDouble(easyGet(array, selector));
}

double easyGetDouble(JsonArray array, char * selector){
    return getDouble(easyGet(array, selector));
}

double easyGetDouble(JsonArray array, const char * selector){
    return getDouble(easyGet(array, selector));
}

std::string easyGetString(JsonObject obj, std::string selector){
    return getString(easyGet(obj, selector));
}

std::string easyGetString(JsonObject obj, char * selector){
    return getString(easyGet(obj, selector));
}

std::string easyGetString(JsonObject obj, const char * selector){
    return getString(easyGet(obj, selector));
}

std::string easyGetString(JsonArray array, std::string selector){
    return getString(easyGet(array, selector));
}

std::string easyGetString(JsonArray array, char * selector){
    return getString(easyGet(array, selector));
}

std::string easyGetString(JsonArray array, const char * selector){
    return getString(easyGet(array, selector));
}


JsonArray easyGetArray(JsonObject obj, std::string selector){
    return getArray(easyGet(obj, selector));
}

JsonArray easyGetArray(JsonObject obj, char * selector){
    return getArray(easyGet(obj, selector));
}

JsonArray easyGetArray(JsonObject obj, const char * selector){
    return getArray(easyGet(obj, selector));
}

JsonArray easyGetArray(JsonArray array, std::string selector){
    return getArray(easyGet(array, selector));
}

JsonArray easyGetArray(JsonArray array, char * selector){
    return getArray(easyGet(array, selector));
}

JsonArray easyGetArray(JsonArray array, const char * selector){
    return getArray(easyGet(array, selector));
}

JsonObject easyGetObject(JsonObject obj, std::string selector){
    return getObject(easyGet(obj, selector));
}

JsonObject easyGetObject(JsonObject obj, char * selector){
    return getObject(easyGet(obj, selector));
}

JsonObject easyGetObject(JsonObject obj, const char * selector){
    return getObject(easyGet(obj, selector));
}

JsonObject easyGetObject(JsonArray array, std::string selector){
    return getObject(easyGet(array, selector));
}

JsonObject easyGetObject(JsonArray array, char * selector){
    return getObject(easyGet(array, selector));
}

JsonObject easyGetObject(JsonArray array, const char * selector){
    return getObject(easyGet(array, selector));
}

nullptr_t easyGetNull(JsonObject obj, std::string selector){
    return getNull(easyGet(obj, selector));
}

nullptr_t easyGetNull(JsonObject obj, char * selector){
    return getNull(easyGet(obj, selector));
}

nullptr_t easyGetNull(JsonObject obj, const char * selector){
    return getNull(easyGet(obj, selector));
}

nullptr_t easyGetNull(JsonArray array, std::string selector){
    return getNull(easyGet(array, selector));
}

nullptr_t easyGetNull(JsonArray array, char * selector){
    return getNull(easyGet(array, selector));
}

nullptr_t easyGetNull(JsonArray array, const char * selector){
    return getNull(easyGet(array, selector));
}

__JsonPair JsonPair(std::string key, bool value) {
    return __JsonPair(key, JsonValue(value));
}

/////////////////////////////////////////////////////////////////////////
//                         DUMP JSON FUNCTIONS                         //
/////////////////////////////////////////////////////////////////////////

std::string dump(__JsonValue value) {
    std::string dumped;
    std::ostringstream buffer;
    
    double d;

    switch (value.first) {
        case JsonType::BOOLEAN:
            buffer << (getBoolean(value) ? "true" : "false");
            break;
        case JsonType::INTEGER:
            buffer << getInteger(value);
            break;
        case JsonType::DOUBLE:
            d = getDouble(value);
            buffer << d << ((d == (int)d) ? ".0" : "");
            break;
        case JsonType::STRING:
            buffer << "\"" << getString(value) << "\"";
            break;
        case JsonType::ARRAY:
            buffer << dump(getArray(value));
            break;
        case JsonType::OBJECT:
            buffer << dump(getObject(value));
            break;
        case JsonType::NONE:
            buffer << "null";
            break;
    }

    return buffer.str();
}

std::string dump(__JsonPair value) {
    std::ostringstream buffer;

    buffer << "\"" << value.first << "\"";
    buffer << ": ";
    buffer << dump(value.second);

    return buffer.str();
}

std::string dump(JsonArray value) {
    std::ostringstream buffer;

    buffer << "[";

    for (int i = 0; i < value.size(); i++) {
        buffer << dump(value.at(i));

        if (i < value.size() - 1)
            buffer << ", ";
    }

    buffer << "]";

    return buffer.str();
}

std::string dump(JsonObject value) {
    std::ostringstream buffer;

    buffer << "{";

    for (int i = 0; i < value.size(); i++) {
        buffer << dump(value.at(i));

        if (i < value.size() - 1)
            buffer << ", ";
    }

    buffer << "}";

    return buffer.str();
}

std::string dumpPretty(JsonArray array) {
    return dumpPretty(array, 4, 0);
}

std::string dumpPretty(JsonObject object) {
    return dumpPretty(object, 4, 0);
}

std::string dumpPretty(__JsonValue value, int indent, int depth) {
    std::string dumped;
    std::ostringstream buffer;
    
    double d;

    switch (value.first) {
        case JsonType::BOOLEAN:
            buffer << (getBoolean(value) ? "true" : "false");
            break;
        case JsonType::INTEGER:
            buffer << getInteger(value);
            break;
        case JsonType::DOUBLE:
            d = getDouble(value);
            buffer << d << ((d == (int)d) ? ".0" : "");
            break;
        case JsonType::STRING:
            buffer << "\"" << getString(value) << "\"";
            break;
        case JsonType::ARRAY:
            buffer << dumpPretty(getArray(value), indent, depth + 1);
            break;
        case JsonType::OBJECT:
            buffer << dumpPretty(getObject(value), indent, depth + 1);
            break;
        case JsonType::NONE:
            buffer << "null";
            break;
    }

    return buffer.str();
}

std::string dumpPretty(__JsonPair pair, int indent, int depth) {
    std::ostringstream buffer;

    buffer << "\"" << pair.first << "\"";
    buffer << ": ";
    buffer << dumpPretty(pair.second, indent, depth);

    return buffer.str();
}

std::string dumpPretty(JsonArray array, int indent, int depth) {
    std::ostringstream buffer;

    buffer << "[\n";

    for (int i = 0; i < array.size(); i++) {

        for (int i = 0; i < depth + 1; i++) {
            for (int j = 0; j < indent; j++) {
                buffer << " ";
            }
        }

        buffer << dumpPretty(array.at(i), indent, depth);

        if (i < array.size() - 1)
            buffer << ", ";
        
        buffer << "\n";
    }

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < indent; j++) {
            buffer << " ";
        }
    }

    buffer << "]";

    return buffer.str();
}

std::string dumpPretty(JsonObject obj, int indent, int depth) {
    std::ostringstream buffer;

    buffer << "{\n";

    for (int i = 0; i < obj.size(); i++) {
        
        for (int i = 0; i < depth + 1; i++) {
            for (int j = 0; j < indent; j++) {
                buffer << " ";
            }
        }

        buffer << dumpPretty(obj.at(i), indent, depth);

        if (i < obj.size() - 1)
            buffer << ", ";
        
        buffer << "\n";
    }

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < indent; j++) {
            buffer << " ";
        }
    }

    buffer << "}";

    return buffer.str();
}

void dumpFile(JsonObject object, std::string fileName) {
    std::string dumped = dump(object);
    std::fstream file;

    file.open(fileName, std::fstream::out);

    if (file.is_open()) {
        file << dumped;
    }

    file.close();
}

void dumpFile(JsonObject object, char *fileName) {
    dumpFile(object, std::string(fileName));
}

void dumpFile(JsonObject object, const char *fileName) {
    dumpFile(object, std::string(fileName));
}

void dumpPrettyFile(JsonObject object, std::string fileName) {
    std::string dumped = dumpPretty(object);
    std::fstream file;

    file.open(fileName, std::fstream::out);

    if (file.is_open()) {
        file << dumped;
    }

    file.close();
}

void dumpPrettyFile(JsonObject object, char *fileName) {
    dumpPrettyFile(object, std::string(fileName));
}

void dumpPrettyFile(JsonObject object, const char *fileName) {
    dumpPrettyFile(object, std::string(fileName));
}

/////////////////////////////////////////////////////////////////////////
//                         LOAD JSON FUNCTIONS                         //
/////////////////////////////////////////////////////////////////////////

__JsonValue loadValue(std::string str) {
    __JsonValue value;

    try {
        if (str[0] == '{') {
            if (str[str.size() - 1] != '}')
                throw InvalidJsonFormatError("JSON object must be surrounded by braces ({})");

            JsonObject object;

            std::string cStr = boost::trim_copy(str);
            cStr = cStr.substr(1, cStr.size() - 2);
            __load(cStr, object);
            value = JsonValue(object);

        } else if (str[0] == '[') {
            if (str[str.size() - 1] != ']')
                throw InvalidJsonFormatError("JSON object must be surrounded by brackets ([])");

            JsonArray array;

            std::string cStr = boost::trim_copy(str);
            cStr = cStr.substr(1, cStr.size() - 2);
            __loadArray(cStr, array);
            value = JsonValue(array);

        } else if (str == "null") {
            value = JsonValue(null);

        } else if (str == "true") {
            value = JsonValue(true);

        } else if (str == "false") {
            value = JsonValue(false);

        } else if (str.find("\"") != std::string::npos) {
            if (str[0] == '\"' && str[str.size() - 1] == '\"') {
                value = JsonValue(str.substr(1, str.size() - 2));
            } else {
                throw InvalidJsonFormatError("String value must starts and ends with \"");
            }

        } else if (str.find(".") != std::string::npos){
            value = JsonValue(std::stod(str));

        } else {
            value = JsonValue(std::stoi(str));

        }
    } catch (const std::invalid_argument&) {
        throw InvalidJsonFormatError("Incorrect number format");
    }

    return value;
}

__JsonPair loadPair(std::string str) {
    __JsonPair pair;

    std::string cStr = std::string(str);

    if (str.find(":") != std::string::npos) {
        std::string strKey = boost::trim_copy(cStr.substr(0, cStr.find(":")));
        std::string strValue = boost::trim_copy(cStr.substr(cStr.find(":") + 1, cStr.size() - (cStr.find(":") + 1)));
        
        if (strKey[0] != '\"' || strKey[strKey.size() - 1] != '\"') {
            throw InvalidJsonFormatError("Incorrect key format (must be surrounded by '\"')");
        }

        pair = __JsonPair(strKey.substr(1, strKey.size() - 2), loadValue(strValue));

    } else {
        throw InvalidJsonFormatError("Incorrect key-value format (must be separated by ':')");
    }

    return pair;
}

void __loadArray(std::string content, JsonArray &parent) {
    char c;
    std::string buffer;

    int objects = 0, arrays = 0;
    bool insideKeyOrString = false;

    for (int i = 0; i < content.size(); i++) {
        c = content[i];

        if (c == ',' && objects == 0 && arrays == 0 && !insideKeyOrString) {
            boost::trim(buffer);
            parent.push_back(loadValue(buffer));
            buffer.clear();

        } else if (c == '{') {
            objects++;  
            buffer += c;

        } else if (c == '}') {
            objects--;
            buffer += c;

        } else if (c == '[') {
            arrays++;
            buffer += c;

        } else if (c == ']') {
            arrays--;
            buffer += c;

        } else if (c == '\"') {
            insideKeyOrString = !insideKeyOrString;
            buffer += c;

        } else if (i == content.size() - 1) {
            buffer += c;
            boost::trim(buffer);
            parent.push_back(loadValue(buffer));

        } else {
            buffer += c;
        }
    }
}

void __load(std::string content, JsonObject &parent) {
    char c;
    std::string buffer;

    int objects = 0, arrays = 0;
    bool insideKeyOrString = false;

    for (int i = 0; i < content.size(); i++) {
        c = content[i];

        if (c == ',' && objects == 0 && arrays == 0 && !insideKeyOrString) {
            boost::trim(buffer);
            parent.push_back(loadPair(buffer));
            buffer.clear();

        } else if (c == '{') {
            objects++;  
            buffer += c;

        } else if (c == '}') {
            objects--;
            buffer += c;

        } else if (c == '[') {
            arrays++;
            buffer += c;

        } else if (c == ']') {
            arrays--;
            buffer += c;

        } else if (c == '\"') {
            insideKeyOrString = !insideKeyOrString;
            buffer += c;

        } else if (i == content.size() - 1) {
            buffer += c;
            boost::trim(buffer);
            parent.push_back(loadPair(buffer));
        } else {
            buffer += c;
        }
    }
}

JsonObject load(std::string content) {
    JsonObject object;

    std::string trimmedContent = boost::trim_copy(content);
    trimmedContent = trimmedContent.substr(1, trimmedContent.size() - 2);

    __load(trimmedContent, object);

    return object;
}

JsonObject loadFile(std::string fileName) {
    std::ifstream file(fileName);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    return load(content);
}