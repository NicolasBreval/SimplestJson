/**
 * @file json.hpp
 * @author nicolasbrevalrodriguez@gmail.com
 * @date 11/04/2020
 * @brief Simple library to operate with JSON objects in C++. This file contains only function and types declarations.
 * 
 * This library is a little project maked from a junior programmer, so code may be inefficient, or lack it of best 
 * practices, for this reason I ask for patience and also Iask for constructive feedback. Also, I need comment that
 * boost library has been very important for this proyect, because their any library and their string utils libraries
 * have made my job easier.
 * 
 * Thank you, so much!
*/

#pragma once

#include <vector>
#include <cstring>
#include <boost/any.hpp>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <cstdarg>
#include <typeinfo>

#define null nullptr /**< Defines a null variable */

/////////////////////////////////////////////////////////////////////////
//                      EXCEPTIONS DEFINITION                          //
/////////////////////////////////////////////////////////////////////////

/**
 * Illegal casting error
 * 
 * This class defines an exception raised when puts a value into a JSON with a declared type
 * and content not corresponds to real value type
*/
class IllegalJsonCastingError : public std::exception
{
    public:
        std::string s;
        IllegalJsonCastingError(std::string ss) : s("Illegal JSON casting error: " + ss) {}
        ~IllegalJsonCastingError() throw () {}
        const char* what() const throw() { return s.c_str(); }
};

/**
 * Invalid format error
 * 
 * This class defines an exception raised when JSON parser finds an illegal structure in
 * JSON string definition
*/
class InvalidJsonFormatError : public std::exception
{
    public:
        std::string s;
        InvalidJsonFormatError(std::string ss) : s("Invalid JSON format: " + ss) {}
        ~InvalidJsonFormatError() throw () {}
        const char* what() const throw() { return s.c_str(); }
};

/**
 * Illegal access error
 * 
 * This class defines an excepcion raised when try to get a value from JSON and key not exists.
*/
class IllegalJsonAccessError : public std::exception
{
    public:
        std::string s;
        IllegalJsonAccessError(std::string ss) : s("Illegal JSON access error: " + ss) {}
        ~IllegalJsonAccessError() throw () {}
        const char* what() const throw() { return s.c_str(); }
};

/////////////////////////////////////////////////////////////////////////
//                   AVAILABLE TYPES DEFINITION                        //
/////////////////////////////////////////////////////////////////////////

/**
 * Available JSON types
*/
enum JsonType {
    BOOLEAN,
    INTEGER,
    DOUBLE,
    STRING,
    OBJECT,
    ARRAY,
    NONE
};

/////////////////////////////////////////////////////////////////////////
//                         OBJECT DEFINITION                           //
/////////////////////////////////////////////////////////////////////////

/**
 * Represents a JSON value:
 * 
 * {
 *   "key" : "value", <-- '"value"' is a __JsonValue type.
 * }
 * 
 * A JSON value is defined as pair of JsonType and boost::any;
 * boost::any is used to store any type of variable, and JsonType
 * is used to provide JSON deserializing
*/
typedef std::pair<JsonType, boost::any> __JsonValue;

/**
 * Represents a JSON key-value:
 * 
 * {
 *   "key" : "value", <-- '"key" : "value"' is a __JsonPair type.
 * }
 * 
 * A JSON key-value is defined as pair of std::string and __JsonValue.
*/
typedef std::pair<std::string, __JsonValue> __JsonPair;

/**
 * Represents a JSON array:
 * 
 * {
 *   "key" : "value",
 *   "data" : [1, 2, "3", true] <-- '[1, 2, "3", true]' is a JsonArray type.
 * }
 * 
 * A JSON array is defined as vector of __JsonValue
 * 
*/
typedef std::vector<__JsonValue> JsonArray;

/**
 * Represents a JSON object:
 * 
 * { <-- All JSON is a JsonObject
 *   "key" : "value",
 *   "data" : [1, 2, "3", true],
 *   "child" : { <-- This JSON inside JSON is also a JsonObject and is inside a __JsonValue, in turn inside a __JsonPair
 *     "key" : "value"
 *   }
 * }
 * 
 * A JSON object is defined as vector of __JsonPair
*/
typedef std::vector<__JsonPair> JsonObject;

/////////////////////////////////////////////////////////////////////////
//                       ACCESS TYPE FUNCTIONS                         //
/////////////////////////////////////////////////////////////////////////

/**
 * Returns number of a __JsonValue variable type inside JsonType enum.
 * 
 * Provides an easy method to get a __JsonValue object type
*/
JsonType getType(__JsonValue);

JsonType getType(JsonObject, std::string);
JsonType getType(JsonObject, char *);
JsonType getType(JsonObject, const char *);
JsonType getType(JsonArray, int);

/**
 * Returns name of a JsonType variable type.
 * 
 * Provides an easy method to get and print a __JsonValue object type
*/
std::string getName(JsonType);



/////////////////////////////////////////////////////////////////////////
//                  JSON VALUE CREATION FUNCTIONS                      //
/////////////////////////////////////////////////////////////////////////

/**
 * Creates a __JsonValue object of bool type
*/
__JsonValue JsonValue(bool);

/**
 * Creates a __JsonValue object of int type
*/
__JsonValue JsonValue(int);

/**
 * Creates a __JsonValue object of double type
*/
__JsonValue JsonValue(double);

/**
 * Creates a __JsonValue object of string type
*/
__JsonValue JsonValue(std::string);

/**
 * Creates a __JsonValue object of string type
*/
__JsonValue JsonValue(char *);

/**
 * Creates a __JsonValue object of string type
*/
__JsonValue JsonValue(const char *);

/**
 * Creates a __JsonValue object of JsonArray type
*/
__JsonValue JsonValue(JsonArray);

/**
 * Creates a __JsonValue object of JsonObject type
*/
__JsonValue JsonValue(JsonObject);

/**
 * Creates a __JsonValue object of nullptr_t type
*/
__JsonValue JsonValue(std::nullptr_t);



/////////////////////////////////////////////////////////////////////////
//                 JSON KEY-VALUE CREATION FUNCTIONS                   //
/////////////////////////////////////////////////////////////////////////

/**
 * Creates a __JsonPair object of bool type
*/
__JsonPair JsonPair(std::string, bool);

/**
 * Creates a __JsonPair object of int type
*/
__JsonPair JsonPair(std::string, int);

/**
 * Creates a __JsonPair object of double type
*/
__JsonPair JsonPair(std::string, double);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(std::string, std::string);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(std::string, char *);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(std::string, const char *);

/**
 * Creates a __JsonPair object of JsonArray type
*/
__JsonPair JsonPair(std::string, JsonArray);

/**
 * Creates a __JsonPair object of JsonObject type
*/
__JsonPair JsonPair(std::string, JsonObject);

/**
 * Creates a __JsonPair object of nullptr_t type
*/
__JsonPair JsonPair(std::string, std::nullptr_t);

/**
 * Creates a __JsonPair object of bool type
*/
__JsonPair JsonPair(char *, bool);

/**
 * Creates a __JsonPair object of int type
*/
__JsonPair JsonPair(char *, int);

/**
 * Creates a __JsonPair object of double type
*/
__JsonPair JsonPair(char *, double);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(char *, std::string);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(char *, char *);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(char *, const char *);

/**
 * Creates a __JsonPair object of JsonArray type
*/
__JsonPair JsonPair(char *, JsonArray);

/**
 * Creates a __JsonPair object of JsonObject type
*/
__JsonPair JsonPair(char *, JsonObject);

/**
 * Creates a __JsonPair object of nullptr_t type
*/
__JsonPair JsonPair(char *, std::nullptr_t);

/**
 * Creates a __JsonPair object of bool type
*/
__JsonPair JsonPair(const char *, bool);

/**
 * Creates a __JsonPair object of int type
*/
__JsonPair JsonPair(const char *, int);

/**
 * Creates a __JsonPair object of double type
*/
__JsonPair JsonPair(const char *, double);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(const char *, std::string);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(const char *, char *);

/**
 * Creates a __JsonPair object of string type
*/
__JsonPair JsonPair(const char *, const char *);

/**
 * Creates a __JsonPair object of JsonArray type
*/
__JsonPair JsonPair(const char *, JsonArray);

/**
 * Creates a __JsonPair object of JsonObject type
*/
__JsonPair JsonPair(const char *, JsonObject);

/**
 * Creates a __JsonPair object of nullptr_t type
*/
__JsonPair JsonPair(const char *, std::nullptr_t);

/////////////////////////////////////////////////////////////////////////
//                   JSON KEY-VALUE ACCESS FUNCTIONS                   //
/////////////////////////////////////////////////////////////////////////

/**
 * Returns a bool value from a __JsonValue object; raises an IllegalJsonCastingError
 * if __JsonValue object type is not bool
*/
bool getBoolean(__JsonValue);

/**
 * Returns a int value from a __JsonValue object; raises an IllegalJsonCastingError
 * if __JsonValue object type is not int
*/
int getInteger(__JsonValue);

/**
 * Returns a double value from a __JsonValue object; raises an IllegalJsonCastingError
 * if __JsonValue object type is not double
*/
double getDouble(__JsonValue);

/**
 * Returns a string value from a __JsonValue object; raises an IllegalJsonCastingError
 * if __JsonValue object type is not string
*/
std::string getString(__JsonValue);

/**
 * Returns a JsonArray value from a __JsonValue object; raises an IllegalJsonCastingError
 * if __JsonValue object type is not JsonArray
*/
JsonArray getArray(__JsonValue);

/**
 * Returns a JsonObject value from a __JsonValue object; raises an IllegalJsonCastingError
 * if __JsonValue object type is not JsonObject
*/
JsonObject getObject(__JsonValue);

/**
 * Returns a nullptr_t value from a __JsonValue object; raises an IllegalJsonCastingError
 * if __JsonValue object type is not nullptr_t
*/
std::nullptr_t getNull(__JsonValue);

/**
 * Find a __JsonPair inside a JsonObject with sepecified key and returns its __JsonValue. 
 * Raises a IllegalJsonAccessError if key not exists
*/
__JsonValue get(JsonObject, std::string);

/**
 * Find a __JsonPair inside a JsonObject with sepecified key and returns its __JsonValue. 
 * Raises a IllegalJsonAccessError if key not exists
*/
__JsonValue get(JsonObject, char *);

/**
 * Find a __JsonPair inside a JsonObject with sepecified key and returns its __JsonValue. 
 * Raises a IllegalJsonAccessError if key not exists
*/
__JsonValue get(JsonObject, const char *);

/**
 * Returns JsonObject's key bool value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
bool getBoolean(JsonObject, std::string);

/**
 * Returns JsonObject's key int value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
int getInteger(JsonObject, std::string);

/**
 * Returns JsonObject's key double value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
double getDouble(JsonObject, std::string);

/**
 * Returns JsonObject's key string value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::string getString(JsonObject, std::string);

/**
 * Returns JsonObject's key JsonArray value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonArray getArray(JsonObject, std::string);

/**
 * Returns JsonObject's key JsonObject value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonObject getObject(JsonObject, std::string);

/**
 * Returns JsonObject's key nullptr_t value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::nullptr_t getNull(JsonObject, std::string);

/**
 * Returns JsonObject's key bool value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
bool getBoolean(JsonObject, char *);

/**
 * Returns JsonObject's key int value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
int getInteger(JsonObject, char *);

/**
 * Returns JsonObject's key double value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
double getDouble(JsonObject, char *);

/**
 * Returns JsonObject's key string value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::string getString(JsonObject, char *);

/**
 * Returns JsonObject's key JsonArray value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonArray getArray(JsonObject, char *);

/**
 * Returns JsonObject's key JsonObject value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonObject getObject(JsonObject, char *);

/**
 * Returns JsonObject's key nullptr_t value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::nullptr_t getNull(JsonObject, char *);

/**
 * Returns JsonObject's key bool value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
bool getBoolean(JsonObject, const char *);

/**
 * Returns JsonObject's key int value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
int getInteger(JsonObject, const char *);

/**
 * Returns JsonObject's key double value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
double getDouble(JsonObject, const char *);

/**
 * Returns JsonObject's key string value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::string getString(JsonObject, const char *);

/**
 * Returns JsonObject's key JsonArray value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonArray getArray(JsonObject, const char *);

/**
 * Returns JsonObject's key JsonObject value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonObject getObject(JsonObject, const char *);

/**
 * Returns JsonObject's key nullptr_t value. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::nullptr_t getNull(JsonObject, const char *);

/**
 * Returns JsonArray's bool value at especified position. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
bool getBoolean(JsonArray, int);

/**
 * Returns JsonArray's int value at especified position. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
int getInteger(JsonArray, int);

/**
 * Returns JsonArray's double value at especified position. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
double getDouble(JsonArray, int);

/**
 * Returns JsonArray's string value at especified position. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::string getString(JsonArray, int);

/**
 * Returns JsonArray's JsonArray value at especified position. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonArray getArray(JsonArray, int);

/**
 * Returns JsonArray's JsonObject value at especified position. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
JsonObject getObject(JsonArray, int);

/**
 * Returns JsonArray's nullptr_t value at especified position. If original value of __JsonValue is different,
 * raises an IllegalJsonCastingError
*/
std::nullptr_t getNull(JsonArray, int);


/////////////////////////////////////////////////////////////////////////
//                       JSON EASY ACCESS FUNCTIONS                    //
/////////////////////////////////////////////////////////////////////////

/**
 * Check is a string is an integer or not. Used in easyGet functions
*/
bool isNumber(std::string);

/**
 * Easy selector function to access JsonObject values
*/
__JsonValue easyGet(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject values
*/
__JsonValue easyGet(JsonObject, char *);

/**
 * Easy selector function to access JsonObject values
*/
__JsonValue easyGet(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray values
*/
__JsonValue easyGet(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray values
*/
__JsonValue easyGet(JsonArray, char *);

/**
 * Easy selector function to access JsonArray values
*/
__JsonValue easyGet(JsonArray, const char *);

/**
 * Easy selector function to access JsonObject boolean values
*/
bool easyGetBoolean(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject boolean values
*/
bool easyGetBoolean(JsonObject, char *);

/**
 * Easy selector function to access JsonObject boolean values
*/
bool easyGetBoolean(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray boolean values
*/
bool easyGetBoolean(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray boolean values
*/
bool easyGetBoolean(JsonArray, char *);

/**
 * Easy selector function to access JsonArray boolean values
*/
bool easyGetBoolean(JsonArray, const char *);

/**
 * Easy selector function to access JsonObject integer values
*/
int easyGetInteger(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject integer values
*/
int easyGetInteger(JsonObject, char *);

/**
 * Easy selector function to access JsonObject integer values
*/
int easyGetInteger(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray integer values
*/
int easyGetInteger(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray integer values
*/
int easyGetInteger(JsonArray, char *);

/**
 * Easy selector function to access JsonArray integer values
*/
int easyGetInteger(JsonArray, const char *);

/**
 * Easy selector function to access JsonObject double values
*/
double easyGetDouble(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject double values
*/
double easyGetDouble(JsonObject, char *);

/**
 * Easy selector function to access JsonObject double values
*/
double easyGetDouble(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray double values
*/
double easyGetDouble(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray double values
*/
double easyGetDouble(JsonArray, char *);

/**
 * Easy selector function to access JsonArray double values
*/
double easyGetDouble(JsonArray, const char *);

/**
 * Easy selector function to access JsonObject string values
*/
std::string easyGetString(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject string values
*/
std::string easyGetString(JsonObject, char *);

/**
 * Easy selector function to access JsonObject string values
*/
std::string easyGetString(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray string values
*/
std::string easyGetString(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray string values
*/
std::string easyGetString(JsonArray, char *);

/**
 * Easy selector function to access JsonArray string values
*/
std::string easyGetString(JsonArray, const char *);

/**
 * Easy selector function to access JsonObject JsonArray values
*/
JsonArray easyGetArray(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject JsonArray values
*/
JsonArray easyGetArray(JsonObject, char *);

/**
 * Easy selector function to access JsonObject JsonArray values
*/
JsonArray easyGetArray(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray JsonArray values
*/
JsonArray easyGetArray(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray JsonArray values
*/
JsonArray easyGetArray(JsonArray, char *);

/**
 * Easy selector function to access JsonArray JsonArray values
*/
JsonArray easyGetArray(JsonArray, const char *);

/**
 * Easy selector function to access JsonObject JsonObject values
*/
JsonObject easyGetObject(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject JsonObject values
*/
JsonObject easyGetObject(JsonObject, char *);

/**
 * Easy selector function to access JsonObject JsonObject values
*/
JsonObject easyGetObject(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray JsonObject values
*/
JsonObject easyGetObject(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray JsonObject values
*/
JsonObject easyGetObject(JsonArray, char *);

/**
 * Easy selector function to access JsonArray JsonObject values
*/
JsonObject easyGetObject(JsonArray, const char *);

/**
 * Easy selector function to access JsonObject nullptr_t values
*/
nullptr_t easyGetNull(JsonObject, std::string);

/**
 * Easy selector function to access JsonObject nullptr_t values
*/
nullptr_t easyGetNull(JsonObject, char *);

/**
 * Easy selector function to access JsonObject nullptr_t values
*/
nullptr_t easyGetNull(JsonObject, const char *);

/**
 * Easy selector function to access JsonArray nullptr_t values
*/
nullptr_t easyGetNull(JsonArray, std::string);

/**
 * Easy selector function to access JsonArray nullptr_t values
*/
nullptr_t easyGetNull(JsonArray, char *);

/**
 * Easy selector function to access JsonArray nullptr_t values
*/
nullptr_t easyGetNull(JsonArray, const char *);


/////////////////////////////////////////////////////////////////////////
//                         DUMP JSON FUNCTIONS                         //
/////////////////////////////////////////////////////////////////////////

/**
 * Returns a one-line string __JsonValue representation
*/
std::string dump(__JsonValue);

/**
 * Returns a one-line string __JsonPair representation
*/
std::string dump(__JsonPair);

/**
 * Returns a one-line string JsonArray representation
*/
std::string dump(JsonArray);

/**
 * Returns a one-line string JsonObject representation
*/
std::string dump(JsonObject);

/**
 * Returns a string JsonArray representation with 4-space indent
*/
std::string dumpPretty(JsonArray);

/**
 * Returns a string JsonObject representation with 4-space indent
*/
std::string dumpPretty(JsonObject);

/**
 * Returns a string __JsonValue representation with passed indent
 * and depth
*/
std::string dumpPretty(__JsonValue, int, int);

/**
 * Returns a string __JsonPair representation with passed indent
 * and depth
*/
std::string dumpPretty(__JsonPair, int, int);

/**
 * Returns a string JsonArray representation with with passed indent
 * and depth
*/
std::string dumpPretty(JsonArray, int, int);

/**
 * Returns a string JsonArray representation with with passed indent
 * and depth
*/
std::string dumpPretty(JsonObject, int, int);

/**
 * Write a one-line string JsonObject representation into file
*/
void dumpFile(JsonObject, std::string);

/**
 * Write a one-line string JsonObject representation into file
*/
void dumpFile(JsonObject, char *);

/**
 * Write a one-line string JsonObject representation into file
*/
void dumpFile(JsonObject, const char *);

/**
 * Write a string JsonObject representation with 4-space indent
 * into file
*/
void dumpPrettyFile(JsonObject, std::string);

/**
 * Write a string JsonObject representation with 4-space indent
 * into file
*/
void dumpPrettyFile(JsonObject, char *);

/**
 * Write a string JsonObject representation with 4-space indent
 * into file
*/
void dumpPrettyFile(JsonObject, const char *);

/////////////////////////////////////////////////////////////////////////
//                         LOAD JSON FUNCTIONS                         //
/////////////////////////////////////////////////////////////////////////

/**
 * Creates a __JsonValue object from string
*/
__JsonValue loadValue(std::string);

/**
 * Creates a __JsonPair object from string
*/
__JsonPair loadPair(std::string);

/**
 * Put values into JsonArray from string JSON array definition
*/
void __loadArray(std::string, JsonArray &);

/**
 * Put values into JsonObject from string JSON object definition
*/
void __load(std::string, JsonObject &);

/**
 * Create a JSON object from a JSON string definition
*/
JsonObject load(std::string);

/**
 * Create a JSON object from file with a JSON string definition
*/
JsonObject loadFile(std::string);
