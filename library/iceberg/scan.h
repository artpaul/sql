#pragma once

#include "expressions/expression.h"
#include "schema.h"

namespace iceberg {

/**
 * Scan objects are immutable ad can be shared between threads.
 */
class Scan {
public:
    /// Returns this scan's filter {@link Expression}.
    void filter() const;

    /// Returns this scan's projection {@link Schema}.
    Schema schema() const;

public:
    /// Create a new scan from the results of this filtered by the {@link Expression}.
    ///
    /// \param expr a filter expression
    void Filter(Expression expr) const;

    /// Create a new scan from this woth the schema as its projection.
    void Project() const;
};

} // namespace iceberg
