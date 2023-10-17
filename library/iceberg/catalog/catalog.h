#pragma once

#include "table_identifier.h"

#include <memory>
#include <vector>

namespace iceberg {

class Table;

/**
 * A Catalog API for table create, drop, and load operations.
 */
class Catalog {
public:
    virtual ~Catalog() = default;

    /**
     * Return all the identifiers under this namespace.
     *
     * @return a list of identifiers for tables
     */
    virtual std::vector<TableIdentifier> ListTables(const std::string& ns) const = 0;

    /**
     * Load a table.
     */
    virtual std::shared_ptr<Table> LoadTable(const TableIdentifier& identifier) const = 0;
};

} // namespace iceberg
