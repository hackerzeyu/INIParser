#pragma once

#include <ostream>
#include <sstream>
#include <string>
using std::string;


namespace zeyu
{
    namespace utility
    {
        class Value
        {
        public:
            enum Type
            {
                V_NULL = 0,
                V_BOOL,
                V_INT,
                V_FLOAT,
                V_DOUBLE,
                V_STRING
            };

            Value();
            Value(bool value);
            Value(int value);
            Value(unsigned int value);
            Value(float value);
            Value(double value);
            Value(const char * value);
            Value(const string & value);
            ~Value() = default;

            Type type() const;
            bool is_null() const;
            bool is_bool() const;
            bool is_int() const;
            bool is_float() const;
            bool is_double() const;
            bool is_string() const;

            Value & operator = (bool value);
            Value & operator = (int value);
            Value & operator = (unsigned int value);
            Value & operator = (float value);
            Value & operator = (double value);
            Value & operator = (const char * value);
            Value & operator = (const string & value);
            Value & operator = (const Value & value);

            bool operator == (const Value & other);
            bool operator != (const Value & other);

            operator bool();
            operator bool() const;

            operator int();
            operator int() const;

            operator unsigned int();
            operator unsigned int() const;

            operator float();
            operator float() const;

            operator double();
            operator double() const;

            operator string();
            operator string() const;

            friend std::ostream & operator << (std::ostream & os, const Value & value)
            {
                os << value.m_value;
                return os;
            }

        private:
            Type m_type;
            string m_value;
        };
    }
}