/// @brief Eigen wrappers for different CCD methods

#pragma once

#include <Eigen/Core>

namespace ccd {

/// Methods of continuous collision detection.
enum CCDMethod {
    /// Etienne Vouga's CCD using a root finder in floating points
    FLOAT = 0,
    /// Root parity method of Brochu et al. [2012]
    ROOT_PARITY,
    /// Teseo's reimplementation of Brochu et al. [2012] using rationals
    RATIONAL_ROOT_PARITY,
    /// Bernstein sign classification method of Tang et al. [2014]
    BSC,
    /// TightCCD method of Wang et al. [2015]
    TIGHT_CCD,
    /// Exact Rational Minimum Distance CCD of Wang et al. [2020]
    EXACT_RATIONAL_MIN_DISTANCE,
    /// Exact Double Minimum Distance CCD of Wang et al. [2020]
    EXACT_DOUBLE_MIN_DISTANCE,
    /// Floating-point root-finder minimum distance CCD of Lu et al. [2018]
    FLOAT_MIN_DISTANCE,
    /// WARNING: Not a method! Counts the number of methods.
    NUM_CCD_METHODS
};

static const char* method_names[CCDMethod::NUM_CCD_METHODS]
    = { "Float",
        "RootParity",
        "RationalRootParity",
        "BSC",
        "TightCCD",
        "ExactRationalMinDistance",
        "ExactDoubleMinDistance",
        "FloatMinDistance" };

/// Minimum distance used when looking for 0 distance collisions.
static const double DEFAULT_MIN_DISTANCE = 1e-30;

/**
 * @brief Detect collisions between a vertex and a triangular face.
 *
 * Looks for collisions between a point and triangle as they move linearily
 * with constant velocity. Returns true if the vertex and face collide.
 *
 * @param[in]  vertex_start        Start position of the vertex.
 * @param[in]  face_vertex0_start  Start position of the first vertex of the
 *                                 face.
 * @param[in]  face_vertex1_start  Start position of the second vertex of the
 *                                 face.
 * @param[in]  face_vertex2_start  Start position of the third vertex of the
 *                                 face.
 * @param[in]  vertex_end          End position of the vertex.
 * @param[in]  face_vertex0_end    End position of the first vertex of the
 *                                 face.
 * @param[in]  face_vertex1_end    End position of the second vertex of the
 *                                 face.
 * @param[in]  face_vertex2_end    End position of the third vertex of the
 *                                 face.
 * @param[in]  method              Method of exact CCD.
 *
 * @returns  True if the vertex and face collide.
 */
bool vertexFaceCCD(
    const Eigen::Vector3d& vertex_start,
    const Eigen::Vector3d& face_vertex0_start,
    const Eigen::Vector3d& face_vertex1_start,
    const Eigen::Vector3d& face_vertex2_start,
    const Eigen::Vector3d& vertex_end,
    const Eigen::Vector3d& face_vertex0_end,
    const Eigen::Vector3d& face_vertex1_end,
    const Eigen::Vector3d& face_vertex2_end,
    const CCDMethod method);

/**
 * @brief Detect collisions between two edges as they move.
 *
 * Looks for collisions between edges as they move linearly with constant
 * velocity. Returns true if the edges collide.
 *
 * @param[in]  edge0_vertex0_start  Start position of the first edge's first
 *                                  vertex.
 * @param[in]  edge0_vertex1_start  Start position of the first edge's second
 *                                  vertex.
 * @param[in]  edge1_vertex0_start  Start position of the second edge's first
 *                                  vertex.
 * @param[in]  edge1_vertex1_start  Start position of the second edge's second
 *                                  vertex.
 * @param[in]  edge0_vertex0_end    End position of the first edge's first
 *                                  vertex.
 * @param[in]  edge0_vertex1_end    End position of the first edge's second
 *                                  vertex.
 * @param[in]  edge1_vertex0_end    End position of the second edge's first
 *                                  vertex.
 * @param[in]  edge1_vertex1_end    End position of the second edge's second
 *                                  vertex.
 * @param[in]  method               Method of exact CCD.
 *
 * @returns True if the edges collide.
 */
bool edgeEdgeCCD(
    const Eigen::Vector3d& edge0_vertex0_start,
    const Eigen::Vector3d& edge0_vertex1_start,
    const Eigen::Vector3d& edge1_vertex0_start,
    const Eigen::Vector3d& edge1_vertex1_start,
    const Eigen::Vector3d& edge0_vertex0_end,
    const Eigen::Vector3d& edge0_vertex1_end,
    const Eigen::Vector3d& edge1_vertex0_end,
    const Eigen::Vector3d& edge1_vertex1_end,
    const CCDMethod method);

} // namespace ccd
