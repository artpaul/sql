#pragma once

#include "scan.h"

#include <memory>

namespace iceberg {

/**
 * Represents a table.
 */
class Table {
    // schema returns the current table schema
    // spec returns the current table partition spec
    // properties returns a map of key-value properties
    // currentSnapshot returns the current table snapshot
    // snapshots returns all valid snapshots for the table
    // snapshot(id) returns a specific snapshot by ID
    // location returns the table’s base location

public:
    std::shared_ptr<Scan> MakeScan() const {
        return {};
    }
};

} // namespace iceberg
