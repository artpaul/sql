#pragma once

#include <cstdint>
#include <string>

namespace iceberg {

enum class Type : uint8_t {
    /// @brief Boolean true or false
    BOOLEAN = 1,

    /// @brief 32-bit signed integers
    INTEGER = 2,

    /// @brief 64-bit signed integers
    LONG = 3,

    /// @brief 32-bit IEEE 754 floating point
    FLOAT = 4,

    /// @brief 64-bit IEEE 754 floating point
    DOUBLE = 5,

    /// @brief Calendar date without timezone or time
    DATE = 6,

    /// @brief Time of day without date, timezone
    TIME = 7,

    /// @brief Timestamp
    TIMESTAMP = 8,

    /// @brief Arbitrary-length character sequences
    STRING = 9,

    UUID = 10,

    /// @brief Fixed-length byte array of length L
    FIXED = 11,

    /// @brief Arbitrary-length byte array
    BINARY = 12,

    /// @brief Fixed-point decimal; precision P, scale S
    DECIMAL = 13,

    /// @brief A record with named fields of any data type
    STRUCT = 14,

    /// @brief A list with elements of any data type
    LIST = 15,

    /// @brief A map with keys and values of any data type
    MAP = 16,
};

/**
 * Base class for all data types.
 */
class DataType {
public:
    explicit DataType(Type id) noexcept
        : id_(id) {
    }

    virtual ~DataType() = default;

    /// Return whether the type is nested
    virtual bool is_nested_type() const noexcept {
        return false;
    }

    /// Return whether the type is primitive
    virtual bool is_primitive_type() const noexcept {
        return false;
    }

    /// Return the type category
    Type id() const noexcept {
        return id_;
    }

    /// A string representation of the type, including any children
    virtual std::string ToString() const = 0;

protected:
    Type id_;
};

class PrimitiveType : public DataType {
public:
    using DataType::DataType;

    bool is_primitive_type() const noexcept final {
        return true;
    }
};

class NestedType : public DataType {
public:
    using DataType::DataType;

    virtual bool is_nested_type() const noexcept {
        return true;
    }
};

} // namespace iceberg
