#include "Value.h"
using namespace zeyu::utility;

Value::Value() : m_type(V_NULL)
{
}

Value::Value(bool value) : m_type(V_BOOL)
{
    m_value = value ? "true" : "false";
}

Value::Value(int value) : m_type(V_INT)
{
    m_value = std::to_string(value);
}

Value::Value(unsigned int value) : m_type(V_INT)
{
    m_value = std::to_string(value);
}

Value::Value(float value) : m_type(V_FLOAT)
{
    m_value = std::to_string(value);
}

Value::Value(double value) : m_type(V_DOUBLE)
{
    m_value = std::to_string(value);
}

Value::Value(const char * value) : m_type(V_STRING)
{
    m_value = value;
}

Value::Value(const string & value) : m_type(V_STRING)
{
    m_value = value;
}

Value::Type Value::type() const
{
    return m_type;
}

bool Value::is_null() const
{
    return m_type == V_NULL;
}

bool Value::is_bool() const
{
    return m_type == V_BOOL;
}

bool Value::is_int() const
{
    return m_type == V_INT;
}

bool Value::is_float() const
{
    return m_type == V_DOUBLE;
}

bool Value::is_double() const
{
    return m_type == V_DOUBLE;
}

bool Value::is_string() const
{
    return m_type == V_STRING;
}

Value & Value::operator = (bool value)
{
    m_type = V_BOOL;
    m_value = value ? "true" : "false";
    return *this;
}

Value & Value::operator = (int value)
{
    m_type = V_INT;
    m_value = std::to_string(value);
    return *this;
}

Value & Value::operator = (unsigned int value)
{
    m_type = V_INT;
    m_value = std::to_string(value);
    return *this;
}

Value & Value::operator = (float value)
{
    m_type = V_DOUBLE;
    m_value = std::to_string(value);
    return *this;
}

Value & Value::operator = (double value)
{
    m_type = V_DOUBLE;
    m_value = std::to_string(value);
    return *this;
}

Value & Value::operator = (const char * value)
{
    m_type = V_STRING;
    m_value = value;
    return *this;
}

Value & Value::operator = (const string & value)
{
    m_type = V_STRING;
    m_value = value;
    return *this;
}

Value & Value::operator = (const Value & value)
{
    if (this == &value)
    {
        return *this;
    }
    m_type = value.m_type;
    m_value = value.m_value;
    return *this;
}

bool Value::operator == (const Value & other)
{
    if (m_type != other.m_type)
    {
        return false;
    }
    return m_value == other.m_value;
}

bool Value::operator != (const Value & other)
{
    return !(m_value == other.m_value);
}

Value::operator bool()
{
    return m_value == "true";
}

Value::operator bool() const
{
    return m_value == "true";
}

Value::operator int()
{
    int value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator int() const
{
    int value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator unsigned int()
{
    unsigned int value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator unsigned int() const
{
    unsigned int value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator float()
{
    float value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator float() const
{
    float value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator double()
{
    double value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator double() const
{
    double value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

Value::operator string()
{
    return m_value;
}

Value::operator string() const
{
    return m_value;
}