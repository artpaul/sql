#pragma once

#include <library/iceberg/types/type.h>

#include <string>
#include <vector>

namespace iceberg {

class StructType;

/**
 * A boolean true or false.
 */
class BooleanType : public PrimitiveType {
public:
    std::string ToString() const {
        return "boolean";
    }
};

class NestedField {
public:
    static NestedField MakeOptional(const int id, const Type type, std::string name) noexcept {
        return NestedField{id, type, true, std::move(name)};
    }

    static NestedField MakeRequired(const int id, const Type type, std::string name) noexcept {
        return NestedField{id, type, false, std::move(name)};
    }

public:
    int id() const noexcept {
        return id_;
    }

    Type type() const noexcept {
        return type_;
    }

    bool is_optional() const noexcept {
        return is_optional_;
    }

    const std::string& name() const noexcept {
        return name_;
    }

private:
    NestedField(const int id, const Type type, const bool is_optional, std::string name)
        : id_(id)
        , type_(type)
        , is_optional_(is_optional)
        , name_(std::move(name)) {
    }

private:
    int id_;
    Type type_;
    bool is_optional_;
    std::string name_;
};

class StructType : public NestedType {
public:
    explicit StructType(std::vector<NestedField> fields)
        : NestedType(Type::STRUCT)
        , fields_(std::move(fields)) {
    }

    std::string ToString() const final;

private:
    std::vector<NestedField> fields_;
};

} // namespace iceberg
