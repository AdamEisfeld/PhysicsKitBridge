#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "btBulletCollisionCommon.h"
#import "btBulletDynamicsCommon.h"
#import "b3BroadphaseCallback.h"
#import "b3DynamicBvh.h"
#import "b3DynamicBvhBroadphase.h"
#import "b3OverlappingPair.h"
#import "b3OverlappingPairCache.h"
#import "b3Aabb.h"
#import "b3Config.h"
#import "b3Contact4.h"
#import "b3ConvexUtility.h"
#import "b3CpuNarrowPhase.h"
#import "b3RaycastInfo.h"
#import "b3RigidBodyCL.h"
#import "b3BvhSubtreeInfoData.h"
#import "b3BvhTraversal.h"
#import "b3ClipFaces.h"
#import "b3Collidable.h"
#import "b3Contact4Data.h"
#import "b3ContactConvexConvexSAT.h"
#import "b3ContactSphereSphere.h"
#import "b3ConvexPolyhedronData.h"
#import "b3FindConcaveSatAxis.h"
#import "b3FindSeparatingAxis.h"
#import "b3MprPenetration.h"
#import "b3NewContactReduction.h"
#import "b3QuantizedBvhNodeData.h"
#import "b3ReduceContacts.h"
#import "b3RigidBodyData.h"
#import "b3UpdateAabbs.h"
#import "b3AlignedAllocator.h"
#import "b3AlignedObjectArray.h"
#import "b3CommandLineArgs.h"
#import "b3FileUtils.h"
#import "b3HashMap.h"
#import "b3Logging.h"
#import "b3Matrix3x3.h"
#import "b3MinMax.h"
#import "b3PoolAllocator.h"
#import "b3QuadWord.h"
#import "b3Quaternion.h"
#import "b3Random.h"
#import "b3ResizablePool.h"
#import "b3Scalar.h"
#import "b3StackAlloc.h"
#import "b3Transform.h"
#import "b3TransformUtil.h"
#import "b3Vector3.h"
#import "b3Float4.h"
#import "b3Int2.h"
#import "b3Int4.h"
#import "b3Mat3x3.h"
#import "b3PlatformDefinitions.h"
#import "b3Quat.h"
#import "b3CpuRigidBodyPipeline.h"
#import "b3ContactSolverInfo.h"
#import "b3FixedConstraint.h"
#import "b3Generic6DofConstraint.h"
#import "b3JacobianEntry.h"
#import "b3PgsJacobiSolver.h"
#import "b3Point2PointConstraint.h"
#import "b3SolverBody.h"
#import "b3SolverConstraint.h"
#import "b3TypedConstraint.h"
#import "b3ContactConstraint4.h"
#import "b3ConvertConstraint4.h"
#import "b3Inertia.h"
#import "b3IntegrateTransforms.h"
#import "b3AabbUtil.h"
#import "b3ConvexHullComputer.h"
#import "b3GeometryUtil.h"
#import "b3GrahamScan2dConvexHull.h"
#import "bullet2.h"
#import "b3BulletFile.h"
#import "b3Chunk.h"
#import "b3Common.h"
#import "b3Defines.h"
#import "b3DNA.h"
#import "b3File.h"
#import "b3Serializer.h"
#import "btAxisSweep3.h"
#import "btAxisSweep3Internal.h"
#import "btBroadphaseInterface.h"
#import "btBroadphaseProxy.h"
#import "btCollisionAlgorithm.h"
#import "btDbvt.h"
#import "btDbvtBroadphase.h"
#import "btDispatcher.h"
#import "btOverlappingPairCache.h"
#import "btOverlappingPairCallback.h"
#import "btQuantizedBvh.h"
#import "btSimpleBroadphase.h"
#import "btActivatingCollisionAlgorithm.h"
#import "btBox2dBox2dCollisionAlgorithm.h"
#import "btBoxBoxCollisionAlgorithm.h"
#import "btBoxBoxDetector.h"
#import "btCollisionConfiguration.h"
#import "btCollisionCreateFunc.h"
#import "btCollisionDispatcher.h"
#import "btCollisionDispatcherMt.h"
#import "btCollisionObject.h"
#import "btCollisionObjectWrapper.h"
#import "btCollisionWorld.h"
#import "btCollisionWorldImporter.h"
#import "btCompoundCollisionAlgorithm.h"
#import "btCompoundCompoundCollisionAlgorithm.h"
#import "btConvex2dConvex2dAlgorithm.h"
#import "btConvexConcaveCollisionAlgorithm.h"
#import "btConvexConvexAlgorithm.h"
#import "btConvexPlaneCollisionAlgorithm.h"
#import "btDefaultCollisionConfiguration.h"
#import "btEmptyCollisionAlgorithm.h"
#import "btGhostObject.h"
#import "btHashedSimplePairCache.h"
#import "btInternalEdgeUtility.h"
#import "btManifoldResult.h"
#import "btSimulationIslandManager.h"
#import "btSphereBoxCollisionAlgorithm.h"
#import "btSphereSphereCollisionAlgorithm.h"
#import "btSphereTriangleCollisionAlgorithm.h"
#import "btUnionFind.h"
#import "SphereTriangleDetector.h"
#import "btBox2dShape.h"
#import "btBoxShape.h"
#import "btBvhTriangleMeshShape.h"
#import "btCapsuleShape.h"
#import "btCollisionMargin.h"
#import "btCollisionShape.h"
#import "btCompoundShape.h"
#import "btConcaveShape.h"
#import "btConeShape.h"
#import "btConvex2dShape.h"
#import "btConvexHullShape.h"
#import "btConvexInternalShape.h"
#import "btConvexPointCloudShape.h"
#import "btConvexPolyhedron.h"
#import "btConvexShape.h"
#import "btConvexTriangleMeshShape.h"
#import "btCylinderShape.h"
#import "btEmptyShape.h"
#import "btHeightfieldTerrainShape.h"
#import "btMaterial.h"
#import "btMiniSDF.h"
#import "btMinkowskiSumShape.h"
#import "btMultimaterialTriangleMeshShape.h"
#import "btMultiSphereShape.h"
#import "btOptimizedBvh.h"
#import "btPolyhedralConvexShape.h"
#import "btScaledBvhTriangleMeshShape.h"
#import "btSdfCollisionShape.h"
#import "btShapeHull.h"
#import "btSphereShape.h"
#import "btStaticPlaneShape.h"
#import "btStridingMeshInterface.h"
#import "btTetrahedronShape.h"
#import "btTriangleBuffer.h"
#import "btTriangleCallback.h"
#import "btTriangleIndexVertexArray.h"
#import "btTriangleIndexVertexMaterialArray.h"
#import "btTriangleInfoMap.h"
#import "btTriangleMesh.h"
#import "btTriangleMeshShape.h"
#import "btTriangleShape.h"
#import "btUniformScalingShape.h"
#import "btBoxCollision.h"
#import "btClipPolygon.h"
#import "btCompoundFromGimpact.h"
#import "btContactProcessing.h"
#import "btContactProcessingStructs.h"
#import "btGenericPoolAllocator.h"
#import "btGeometryOperations.h"
#import "btGImpactBvh.h"
#import "btGImpactBvhStructs.h"
#import "btGImpactCollisionAlgorithm.h"
#import "btGImpactMassUtil.h"
#import "btGImpactQuantizedBvh.h"
#import "btGImpactQuantizedBvhStructs.h"
#import "btGImpactShape.h"
#import "btQuantization.h"
#import "btTriangleShapeEx.h"
#import "gim_array.h"
#import "gim_basic_geometry_operations.h"
#import "gim_bitset.h"
#import "gim_box_collision.h"
#import "gim_box_set.h"
#import "gim_clip_polygon.h"
#import "gim_contact.h"
#import "gim_geometry.h"
#import "gim_geom_types.h"
#import "gim_hash_table.h"
#import "gim_linear_math.h"
#import "gim_math.h"
#import "gim_memory.h"
#import "gim_pair.h"
#import "gim_radixsort.h"
#import "gim_tri_collision.h"
#import "btComputeGjkEpaPenetration.h"
#import "btContinuousConvexCollision.h"
#import "btConvexCast.h"
#import "btConvexPenetrationDepthSolver.h"
#import "btDiscreteCollisionDetectorInterface.h"
#import "btGjkCollisionDescription.h"
#import "btGjkConvexCast.h"
#import "btGjkEpa2.h"
#import "btGjkEpa3.h"
#import "btGjkEpaPenetrationDepthSolver.h"
#import "btGjkPairDetector.h"
#import "btManifoldPoint.h"
#import "btMinkowskiPenetrationDepthSolver.h"
#import "btMprPenetration.h"
#import "btPersistentManifold.h"
#import "btPointCollector.h"
#import "btPolyhedralContactClipping.h"
#import "btRaycastCallback.h"
#import "btSimplexSolverInterface.h"
#import "btSubSimplexConvexCast.h"
#import "btVoronoiSimplexSolver.h"
#import "btCharacterControllerInterface.h"
#import "btKinematicCharacterController.h"
#import "btBatchedConstraints.h"
#import "btConeTwistConstraint.h"
#import "btConstraintSolver.h"
#import "btContactConstraint.h"
#import "btContactSolverInfo.h"
#import "btFixedConstraint.h"
#import "btGearConstraint.h"
#import "btGeneric6DofConstraint.h"
#import "btGeneric6DofSpring2Constraint.h"
#import "btGeneric6DofSpringConstraint.h"
#import "btHinge2Constraint.h"
#import "btHingeConstraint.h"
#import "btJacobianEntry.h"
#import "btNNCGConstraintSolver.h"
#import "btPoint2PointConstraint.h"
#import "btSequentialImpulseConstraintSolver.h"
#import "btSequentialImpulseConstraintSolverMt.h"
#import "btSliderConstraint.h"
#import "btSolve2LinearConstraint.h"
#import "btSolverBody.h"
#import "btSolverConstraint.h"
#import "btTypedConstraint.h"
#import "btUniversalConstraint.h"
#import "btActionInterface.h"
#import "btDiscreteDynamicsWorld.h"
#import "btDiscreteDynamicsWorldMt.h"
#import "btDynamicsWorld.h"
#import "btRigidBody.h"
#import "btSimpleDynamicsWorld.h"
#import "btSimulationIslandManagerMt.h"
#import "btMultiBody.h"
#import "btMultiBodyConstraint.h"
#import "btMultiBodyConstraintSolver.h"
#import "btMultiBodyDynamicsWorld.h"
#import "btMultiBodyFixedConstraint.h"
#import "btMultiBodyGearConstraint.h"
#import "btMultiBodyInplaceSolverIslandCallback.h"
#import "btMultiBodyJointFeedback.h"
#import "btMultiBodyJointLimitConstraint.h"
#import "btMultiBodyJointMotor.h"
#import "btMultiBodyLink.h"
#import "btMultiBodyLinkCollider.h"
#import "btMultiBodyMLCPConstraintSolver.h"
#import "btMultiBodyPoint2Point.h"
#import "btMultiBodySliderConstraint.h"
#import "btMultiBodySolverConstraint.h"
#import "btMultiBodySphericalJointMotor.h"
#import "btDantzigLCP.h"
#import "btDantzigSolver.h"
#import "btLemkeAlgorithm.h"
#import "btLemkeSolver.h"
#import "btMLCPSolver.h"
#import "btMLCPSolverInterface.h"
#import "btPATHSolver.h"
#import "btSolveProjectedGaussSeidel.h"
#import "btRaycastVehicle.h"
#import "btVehicleRaycaster.h"
#import "btWheelInfo.h"
#import "btCGProjection.h"
#import "btConjugateGradient.h"
#import "btConjugateResidual.h"
#import "btDefaultSoftBodySolver.h"
#import "btDeformableBackwardEulerObjective.h"
#import "btDeformableBodySolver.h"
#import "btDeformableContactConstraint.h"
#import "btDeformableContactProjection.h"
#import "btDeformableCorotatedForce.h"
#import "btDeformableGravityForce.h"
#import "btDeformableLagrangianForce.h"
#import "btDeformableLinearElasticityForce.h"
#import "btDeformableMassSpringForce.h"
#import "btDeformableMousePickingForce.h"
#import "btDeformableMultiBodyConstraintSolver.h"
#import "btDeformableMultiBodyDynamicsWorld.h"
#import "btDeformableNeoHookeanForce.h"
#import "btKrylovSolver.h"
#import "btPreconditioner.h"
#import "btSoftBody.h"
#import "btSoftBodyConcaveCollisionAlgorithm.h"
#import "btSoftBodyData.h"
#import "btSoftBodyHelpers.h"
#import "btSoftBodyInternals.h"
#import "btSoftBodyRigidBodyCollisionConfiguration.h"
#import "btSoftBodySolvers.h"
#import "btSoftBodySolverVertexBuffer.h"
#import "btSoftMultiBodyDynamicsWorld.h"
#import "btSoftRigidCollisionAlgorithm.h"
#import "btSoftRigidDynamicsWorld.h"
#import "btSoftSoftCollisionAlgorithm.h"
#import "btSparseSDF.h"
#import "DeformableBodyInplaceSolverIslandCallback.h"
#import "poly34.h"
#import "clew.h"
#import "btAabbUtil2.h"
#import "btAlignedAllocator.h"
#import "btAlignedObjectArray.h"
#import "btConvexHull.h"
#import "btConvexHullComputer.h"
#import "btCpuFeatureUtility.h"
#import "btDefaultMotionState.h"
#import "btGeometryUtil.h"
#import "btGrahamScan2dConvexHull.h"
#import "btHashMap.h"
#import "btIDebugDraw.h"
#import "btImplicitQRSVD.h"
#import "btList.h"
#import "btMatrix3x3.h"
#import "btMatrixX.h"
#import "btMinMax.h"
#import "btModifiedGramSchmidt.h"
#import "btMotionState.h"
#import "btPolarDecomposition.h"
#import "btPoolAllocator.h"
#import "btQuadWord.h"
#import "btQuaternion.h"
#import "btQuickprof.h"
#import "btRandom.h"
#import "btReducedVector.h"
#import "btScalar.h"
#import "btSerializer.h"
#import "btSpatialAlgebra.h"
#import "btStackAlloc.h"
#import "btThreads.h"
#import "btTransform.h"
#import "btTransformUtil.h"
#import "btVector3.h"
#import "btThreadSupportInterface.h"
#import "btBulletWorldImporter.h"
#import "btMultiBodyWorldImporter.h"
#import "btWorldImporter.h"
#import "bullet.h"
#import "bChunk.h"
#import "bCommon.h"
#import "bDefines.h"
#import "bDNA.h"
#import "bFile.h"
#import "btBulletFile.h"
#import "PKBCollisionShape+Internal.h"
#import "PKBCollisionShape.h"
#import "NSValue+PKBStructs.h"
#import "PKBStructs+Internal.h"
#import "PKBStructs.h"
#import "PKBGeometry+Internal.h"
#import "PKBGeometry.h"
#import "PKBMesh.h"
#import "PKBPolygon.h"
#import "PKBVertex.h"
#import "PKBRigidBody+Internal.h"
#import "PKBRigidBody.h"
#import "PKBPhysicsTrigger+Internal.h"
#import "PKBPhysicsTrigger.h"
#import "PKBDependencies.h"
#import "PKBPhysicsWorld.h"

FOUNDATION_EXPORT double PhysicsKitBridgeVersionNumber;
FOUNDATION_EXPORT const unsigned char PhysicsKitBridgeVersionString[];

