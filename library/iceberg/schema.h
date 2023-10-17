#pragma once

#include "types/types.h"

namespace iceberg {

class Schema {
public:
    /// Returns the schema ID for this schema
    int schema_id() const noexcept {
        return schema_id_;
    }

private:
    int schema_id_{0};
    // StructType struct_;
};

} // namespace iceberg
